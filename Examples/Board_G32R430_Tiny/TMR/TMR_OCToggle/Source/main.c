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
/* Enable TESE_TMR1 to test TMR1, otherwise test TMR2 */
//#define TESE_TMR1

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
/* TMRx Channel 1: */
/* - CC1_Val = 24000 */
/* - Frequency = 120 MHz / (2 * CC1_Val) = 120 MHz / (2 * 24000) = 2.5 kHz */
/* - Duty Cycle = 50% (Toggle Mode) */
/* TMRx Channel 2: */
/* - CC2_Val = 12000 */
/* - Frequency = 120 MHz / (2 * CC2_Val) = 120 MHz / (2 * 12000) = 5 kHz */
/* - Duty Cycle = 50% (Toggle Mode) */
/* TMRx Channel 3: */
/* - CC3_Val = 2400 */
/* - Frequency = 120 MHz / (2 * CC3_Val) = 120 MHz / (2 * 2400) = 25 kHz */
/* - Duty Cycle = 50% (Toggle Mode) */
/* TMRx Channel 4: */
/* - CC4_Val = 1200 */
/* - Frequency = 120 MHz / (2 * CC4_Val) = 120 MHz / (2 * 1200) = 50 kHz */
/* - Duty Cycle = 50% (Toggle Mode) */
uint16_t CC1_Val = (120000000/5000);   /* 120 MHz / 5000 = 24000 */
uint16_t CC2_Val = (120000000/10000);  /* 120 MHz / 10000 = 12000 */
uint16_t CC3_Val = (120000000/50000);  /* 120 MHz / 50000 = 2400 */
uint16_t CC4_Val = (120000000/100000); /* 120 MHz / 100000 = 1200 */

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void TMR1_Init(void);
void TMR2_Init(void);
void TMR1_Isr(void);
void TMR2_Isr(void);

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

#ifdef TESE_TMR1
    /* Initialize TMR1 */
    TMR1_Init();
#else
    /* Initialize TMR2 */
    TMR2_Init();
#endif

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
 * @brief     TMR1 Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR1_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_TMR_InitTypeDef TMR_InitStruct = {0U};
    DDL_TMR_OC_InitTypeDef TMR_OCInitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR1);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*TMR1 CH1, CH2, CH3, CH4 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_5|DDL_GPIO_PIN_9|DDL_GPIO_PIN_13;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Config TMR1 */
    TMR_InitStruct.Prescaler         = 0;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 0xFFFF;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR1, &TMR_InitStruct);

    TMR_OCInitStruct.OCMode       = DDL_TMR_OCMODE_TOGGLE;
    TMR_OCInitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.OCNState     = DDL_TMR_OCSTATE_DISABLE;
    TMR_OCInitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_LOW;
    TMR_OCInitStruct.OCNPolarity  = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCIdleState  = DDL_TMR_OCIDLESTATE_LOW;
    TMR_OCInitStruct.OCNIdleState = DDL_TMR_OCIDLESTATE_LOW;

    /* Configure channel1 */
    TMR_OCInitStruct.CompareValue = CC1_Val;
    
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH1, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR1, DDL_TMR_CHANNEL_CH1);

    /* Configure channel2 */
    TMR_OCInitStruct.CompareValue = CC2_Val;
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH2, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR1, DDL_TMR_CHANNEL_CH2);

    /* Configure channel3 */
    TMR_OCInitStruct.CompareValue = CC3_Val;
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH3, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR1, DDL_TMR_CHANNEL_CH3);

    /* Configure channel4 */
    TMR_OCInitStruct.CompareValue = CC4_Val;
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH4, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR1, DDL_TMR_CHANNEL_CH4);

    DDL_TMR_EnableIT_CC1(TMR1);
    DDL_TMR_EnableIT_CC2(TMR1);
    DDL_TMR_EnableIT_CC3(TMR1);
    DDL_TMR_EnableIT_CC4(TMR1);

    DDL_Interrupt_Register(TMR1_IRQn, TMR1_Isr);
    DDL_NVIC_EnableIRQRequest(TMR1_IRQn, 1, 0);

    /* Enable TMR1 */
    DDL_TMR_EnableCounter(TMR1);
    DDL_TMR_EnableAllOutputs(TMR1);
}

/*!
 * @brief       TMR1 Handler
 *
 * @param       None
 *
 * @retval      None
 */
void TMR1_Isr(void)
{
    uint32_t capValue = 0;

    if (DDL_TMR_IsActiveFlag_CC1(TMR1))
    {
        /* Clear the TMR1 CC1 pending bit */
        DDL_TMR_ClearFlag_CC1(TMR1);
        capValue = DDL_TMR_OC_GetCompareCH1(TMR1);
        DDL_TMR_OC_SetCompareCH1(TMR1, capValue + CC1_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC2(TMR1))
    { 
        /* Clear the TMR1 CC2 pending bit */
        DDL_TMR_ClearFlag_CC2(TMR1);
        capValue = DDL_TMR_OC_GetCompareCH2(TMR1);
        DDL_TMR_OC_SetCompareCH2(TMR1, capValue + CC2_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC3(TMR1))
    {
        /* Clear the TMR1 CC3 pending bit */
        DDL_TMR_ClearFlag_CC3(TMR1);
        capValue = DDL_TMR_OC_GetCompareCH3(TMR1);
        DDL_TMR_OC_SetCompareCH3(TMR1, capValue + CC3_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC4(TMR1))
    {
        /* Clear the TMR1 CC4 pending bit */
        DDL_TMR_ClearFlag_CC4(TMR1);
        capValue = DDL_TMR_OC_GetCompareCH4(TMR1);
        DDL_TMR_OC_SetCompareCH4(TMR1, capValue + CC4_Val);
    }
}

/**
 * @brief     TMR2 Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR2_Init(void)
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
    TMR_InitStruct.Prescaler         = 0;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 0xFFFF;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR2, &TMR_InitStruct);

    TMR_OCInitStruct.OCMode       = DDL_TMR_OCMODE_TOGGLE;
    TMR_OCInitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.OCNState     = DDL_TMR_OCSTATE_DISABLE;
    TMR_OCInitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_LOW;
    TMR_OCInitStruct.OCNPolarity  = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCIdleState  = DDL_TMR_OCIDLESTATE_LOW;
    TMR_OCInitStruct.OCNIdleState = DDL_TMR_OCIDLESTATE_LOW;

    /* Configure channel1 */
    TMR_OCInitStruct.CompareValue = CC1_Val;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH1, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH1);

    /* Configure channel2 */
    TMR_OCInitStruct.CompareValue = CC2_Val;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH2, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH2);

    /* Configure channel3 */
    TMR_OCInitStruct.CompareValue = CC3_Val;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH3, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH3);

    /* Configure channel4 */
    TMR_OCInitStruct.CompareValue = CC4_Val;
    DDL_TMR_OC_Init(TMR2, DDL_TMR_CHANNEL_CH4, &TMR_OCInitStruct);
    DDL_TMR_OC_DisablePreload(TMR2, DDL_TMR_CHANNEL_CH4);

    DDL_TMR_EnableIT_CC1(TMR2);
    DDL_TMR_EnableIT_CC2(TMR2);
    DDL_TMR_EnableIT_CC3(TMR2);
    DDL_TMR_EnableIT_CC4(TMR2);

    DDL_Interrupt_Register(TMR2_IRQn, TMR2_Isr);
    DDL_NVIC_EnableIRQRequest(TMR2_IRQn, 1, 0);

    /* Enable TMR2 */
    DDL_TMR_EnableCounter(TMR2);
}

/*!
 * @brief       TMR2 Handler
 *
 * @param       None
 *
 * @retval      None
 */
void TMR2_Isr(void)
{
    uint32_t capValue = 0;

    if (DDL_TMR_IsActiveFlag_CC1(TMR2))
    {
        /* Clear the TMR2 CC1 pending bit */
        DDL_TMR_ClearFlag_CC1(TMR2);
        capValue = DDL_TMR_OC_GetCompareCH1(TMR2);
        DDL_TMR_OC_SetCompareCH1(TMR2, capValue + CC1_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC2(TMR2))
    {
        /* Clear the TMR2 CC2 pending bit */
        DDL_TMR_ClearFlag_CC2(TMR2);
        capValue = DDL_TMR_OC_GetCompareCH2(TMR2);
        DDL_TMR_OC_SetCompareCH2(TMR2, capValue + CC2_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC3(TMR2))
    {
        /* Clear the TMR2 CC3 pending bit */
        DDL_TMR_ClearFlag_CC3(TMR2);
        capValue = DDL_TMR_OC_GetCompareCH3(TMR2);
        DDL_TMR_OC_SetCompareCH3(TMR2, capValue + CC3_Val);
    }

    if (DDL_TMR_IsActiveFlag_CC4(TMR2))
    {
        /* Clear the TMR2 CC4 pending bit */
        DDL_TMR_ClearFlag_CC4(TMR2);
        capValue = DDL_TMR_OC_GetCompareCH4(TMR2);
        DDL_TMR_OC_SetCompareCH4(TMR2, capValue + CC4_Val);
    }
}
