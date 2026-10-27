/**
 *
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.1
 *
 * @date        2026-07-31
 *
 * @attention
 *
 *  Copyright (C) 2025 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 */

/* Includes ***************************************************************/
#include "main.h"

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void TMR_Init(void);

/* External variables *****************************************************/

/* External functions *****************************************************/


/**
 * @brief     Main program
 *
 * @param     None
 *
 * @retval    None
 *
 */
int main(void)
{
    /* Configure system clock */
    DDL_SysClkConfig();

    /* Initialize TMR2, TMR3, TMR4 */
    TMR_Init();

    while (1)
    {
    }
}

/**
 * @brief   System clock configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DDL_SysClkConfig(void)
{
    /* Unlock clock control registers */
    /* Wait until the registers are unlocked */
    DDL_RCM_Unlock();
    while ((RCM->KEY & RCM_KEY_KEYST) != RCM_KEY_KEYST) 
    { 
    }

    /* Enable HSE and wait for ready */
    /* Enable HSE input clock */
    DDL_RCM_HSE_Enable();
    /* Wait until HSE is ready */
    while (DDL_RCM_HSE_IsReady() != 1) 
    {
        /* wait for HSERDY */
    }

    /* Configure Flash wait states appropriate for 120 MHz */
    /* Set Flash wait period to accommodate higher frequency */
    DDL_FLASH_SetWaitPeriod(FLASH_DDL_WAIT_PERIOD_3);
    /* Set Flash erase time base to 120 MHz (use 119 to represent 120 MHz) */
    DDL_FLASH_SetEraseTimeBase(119);

    /* Configure PLL */
    /* Ensure PLL is disabled prior to configuration */
    DDL_RCM_PLL_Disable();

    /* Configure PLL settings: multiplier, prescaler, and clock source */
    /* PLL multiplier set to 15 (x15), prescaler no division, clock source from HSE */
    DDL_RCM_PLL_SetMultiplier(15);
    DDL_RCM_PLL_SetPrescaler(DDL_RCM_PLL_DIV1);
    DDL_RCM_PLL_SetClkSource(DDL_RCM_PLL_CLKSOURCE_HSE);

    /* Enable PLL and wait for ready */
    DDL_RCM_PLL_Enable();
    while (DDL_RCM_PLL_IsReady() != 1)
    {
        /* wait for PLL Ready */
    }

    /* Switch system clock to PLL output */
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_PLL);

    /* Enable clock switch and wait for completion */
    DDL_RCM_EnableSysClkSwitch();
    while (DDL_RCM_IsActiveFlag_SWDONE() != 1)
    {
    }

    /* Set AHB, APB prescalers */
    DDL_RCM_SetAHBPrescaler(DDL_RCM_AHB_DIV_1);
    DDL_RCM_SetAPBPrescaler(DDL_RCM_APB_DIV_1);
    
    /* Disable clock switch controls */
    DDL_RCM_DisableSysClkSwitch();
    
    /* Lock clock control registers */
    DDL_RCM_Lock();

    /* Update SystemCoreClock if used by the project */
    SystemCoreClockUpdate();
}

/**
 * @brief     TMR Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_TMR_InitTypeDef TMR_InitStruct = {0U};
    DDL_TMR_OC_InitTypeDef TMR_OC_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR2);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR3);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR4);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /* Configure TMR2(PC4), TMR3(PB2), TMR4(PC6) channel 1 GPIO */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_4 | DDL_GPIO_PIN_6;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_2;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Config TMR2 */
    /* TMR2 PWM Frequency Calculation: */
    /* Input clock frequency = 120 MHz */
    /* Prescaler = 0, Autoreload = 11 */
    /* PWM Frequency = 120 MHz / (Prescaler + 1) / (Autoreload + 1) */
    /*               = 120 MHz / 12 = 10 MHz */
    TMR_InitStruct.Prescaler         = 0;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 11;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR2, &TMR_InitStruct);

    /* Config TMR3 */
    /* TMR3 PWM Frequency Calculation: */
    /* Input clock frequency = TMR2 output frequency = 10 MHz */
    /* Prescaler = 0, Autoreload = 3 */
    /* PWM Frequency = 10 MHz / (Prescaler + 1) / (Autoreload + 1) */
    /*               = 10 MHz / 4 = 2.5 MHz */
    TMR_InitStruct.Autoreload        = 3;
    DDL_TMR_Init(TMR3, &TMR_InitStruct);

    /* Config TMR4 */
    /* TMR4 PWM Frequency Calculation: */
    /* Input clock frequency = TMR3 output frequency = 2.5 MHz */
    /* Prescaler = 0, Autoreload = 1 */
    /* PWM Frequency = 2.5 MHz / (Prescaler + 1) / (Autoreload + 1) */
    /*               = 2.5 MHz / 2 = 1.25 MHz */
    TMR_InitStruct.Autoreload        = 1;
    DDL_TMR_Init(TMR4, &TMR_InitStruct);

    DDL_TMR_OC_StructInit(&TMR_OC_InitStruct);
    /* Configure TMR2, TMR3, TMR4 channel 1 */
    TMR_OC_InitStruct.OCMode       = DDL_TMR_OCMODE_PWM1;
    TMR_OC_InitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OC_InitStruct.CompareValue = 8;
    TMR_OC_InitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_HIGH;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH1, &TMR_OC_InitStruct);

    TMR_OC_InitStruct.CompareValue = 2;
    DDL_TMR_OC_Init(TMR3, DDL_TMR_CHANNEL_CH1, &TMR_OC_InitStruct);

    TMR_OC_InitStruct.CompareValue = 1;
    DDL_TMR_OC_Init(TMR4, DDL_TMR_CHANNEL_CH1, &TMR_OC_InitStruct);

    /* Enable TMR2 the Master Slave Mode */
    DDL_TMR_EnableMasterSlaveMode(TMR2);
    DDL_TMR_SetTriggerOutput(TMR2, DDL_TMR_TRGO_UPDATE);

    /* Selects the Slave Mode and Input Trigger source */
    DDL_TMR_SetTriggerInput(TMR3, DDL_TMR_TS_ITR1);
    DDL_TMR_SetSlaveMode(TMR3, DDL_TMR_SLAVEMODE_GATED);

    /* Enable TMR3 the Master Slave Mode */
    DDL_TMR_EnableMasterSlaveMode(TMR3);
    DDL_TMR_SetTriggerOutput(TMR3, DDL_TMR_TRGO_UPDATE);

    /* Selects the Slave Mode and Input Trigger source */
    DDL_TMR_SetTriggerInput(TMR4, DDL_TMR_TS_ITR2);
    DDL_TMR_SetSlaveMode(TMR4, DDL_TMR_SLAVEMODE_GATED);
    
    /* Enable TMR3 the Master Slave Mode */
    DDL_TMR_EnableMasterSlaveMode(TMR4);
    DDL_TMR_SetTriggerOutput(TMR4, DDL_TMR_TRGO_UPDATE);

    /* Enable TMR2/3/4 */
    DDL_TMR_EnableCounter(TMR2);
    DDL_TMR_EnableCounter(TMR3);
    DDL_TMR_EnableCounter(TMR4);
}
