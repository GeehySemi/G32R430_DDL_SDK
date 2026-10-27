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
#include <stdio.h>

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

    /* Initialize TMR */
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
    DDL_TMR_OC_InitTypeDef TMR_OCInitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR2);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*TMR2 CH1, CH2, CH3, CH4 */
    /* Note: J10 selects whether PA1/PA2 connect to LED1/LED2 or the external header. */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_0 | DDL_GPIO_PIN_1 | DDL_GPIO_PIN_2 | DDL_GPIO_PIN_3;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Config TMR2 */
    /* Prescaler = 119 */
    /* Timer clock frequency = System clock frequency / (Prescaler + 1) */
    /* Timer clock frequency = 120 MHz / (119 + 1) = 1 MHz */
    /* Autoreload = 999 */
    /* Timer counting frequency = Timer clock frequency / (Autoreload + 1) */
    /* Timer counting frequency = 1 MHz / (999 + 1) = 1 kHz */
    /* The timer will overflow every 1 ms (1 / 1 kHz) */
    TMR_InitStruct.Prescaler         = 119;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 999;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR2, &TMR_InitStruct);

    /* TMR2 OC channel configuration */
    TMR_OCInitStruct.OCMode       = DDL_TMR_OCMODE_ACTIVE;
    TMR_OCInitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.OCNState     = DDL_TMR_OCSTATE_DISABLE;
    TMR_OCInitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCNPolarity  = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCIdleState  = DDL_TMR_OCIDLESTATE_LOW;
    TMR_OCInitStruct.OCNIdleState = DDL_TMR_OCIDLESTATE_LOW;

    /* TMR2 CH1 delay = 800/1MHz = 800us */
    TMR_OCInitStruct.CompareValue = 800;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH1, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH1);

    /* TMR2 CH2 delay = 600/1MHz = 600us */
    TMR_OCInitStruct.CompareValue = 600;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH2, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH2);

    /* TMR2 CH3 delay = 400/1MHz = 400us */
    TMR_OCInitStruct.CompareValue = 400;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH3, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH3);

    /* TMR2 CH4 delay = 200/1MHz = 200us */
    TMR_OCInitStruct.CompareValue = 200;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH4, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH4);

    DDL_TMR_DisableARRPreload(TMR2);

    /* Enable TMR2 */
    DDL_TMR_EnableCounter(TMR2);
}
