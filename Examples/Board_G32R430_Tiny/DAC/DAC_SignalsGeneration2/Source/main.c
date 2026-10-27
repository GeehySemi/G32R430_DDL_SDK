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
void DAC_Init(void);

/* Delay */
void Delay(uint32_t count);

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

    /* Initialize DAC */
    DAC_Init();

    while (1)
    {
        /* Enable sawtooth wave software trigger */
        DDL_DAC_EnableSawtoothSoftwareTriggerB(DAC2);
        Delay(0x4FFFF);

        /* Check for overflow/underflow status */
        /* Note: Users can define specific overflow or underflow criteria based on */
        /*       the actual application scenario. */
        if((DDL_DAC_GetDORDataOverFlowStatus(DAC2) != 0)  \
        || (DDL_DAC_GetDORDataUnderFlowStatus(DAC2) != 0))
        {
            DDL_DAC_ClearDORDataOverFlowStatus(DAC2);
            DDL_DAC_ClearDORDataUnderFlowStatus(DAC2);

            Delay(0x4FFFF);

            /* Trigger DAC2 channel to reset the sawtooth wave */
            DDL_DAC_EnableSoftwareTrigger(DAC2);
        }
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
 * @brief       DAC Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void DAC_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_DAC_InitTypeDef DAC_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_DAC2);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /* Config PD5 for DAC2 */
    GPIO_InitStruct.Pin         = DDL_GPIO_PIN_5;
    GPIO_InitStruct.Mode        = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Speed       = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType  = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull        = DDL_GPIO_PULL_NO;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Set PD5 mode to analog 3.3V input/output */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_5, DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT); 

    /* Config DAC2 */
    DAC_InitStruct.TriggerSource            = DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE;
    DAC_InitStruct.WaveAutoGeneration       = DDL_DAC_WAVE_GENERATE_SAWTOOTH;
    DAC_InitStruct.WaveAutoGenerationConfig = DDL_DAC_NONE_MASK_LFSR_0_0;
    DAC_InitStruct.OutputBuffer             = DDL_DAC_OUTPUT_BUFFER_EXTERNAL;
    DDL_DAC_Init(DAC2, &DAC_InitStruct);

    DDL_DAC_SetSawtoothDirection(DAC2, DDL_DAC_SAWTOOTH_WAVE_DIRECTION_INCREASING);
    DDL_DAC_SetSawtoothResetValue(DAC2, 0);
    DDL_DAC_SetSawtoothIncrementValue(DAC2, 31);
    DDL_DAC_SetSawtoothIncrementTriggerSource(DAC2, DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_SOFTWARE);
    DDL_DAC_SetSawtoothResetTriggerSource(DAC2, DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_SOFTWARE);

    /* Enable DAC2 */
    DDL_DAC_Enable(DAC2);

    /* Config data left alignment */
    DDL_DAC_SetRightAlignmentData(DAC2, 0x3FF);

    /* Enable software trigger to generate first sawtooth wave */
    DDL_DAC_EnableSoftwareTrigger(DAC2);
}

/*!
 * @brief       Delay
 *
 * @param       count:  delay count
 *
 * @retval      None
 */
void Delay(uint32_t count)
{
    volatile uint32_t delay = count;
    while(delay--);
}
