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
/* Buffer used for DMA transfer */
/* The timer clock frequency is determined by the prescaler: */
/* Timer Clock = System Clock / (Prescaler + 1) = System Clock / 120 */
/* The PWM frequency is determined by the autoreload value:*/
/* PWM Frequency = Timer Clock / (Autoreload + 1) */
/* Assuming System Clock = 12 MHz: */
/* Timer Clock = 12 MHz / 120 = 100 kHz */
/* PWM Frequency = 100 kHz / (9999 + 1) = 10 Hz */
/* The duty cycle is determined by the compare value: */
/* Duty Cycle = (Compare Value / (Autoreload + 1)) * 100% */
/* Duty Cycle = (50 / 10000) * 100% = 0.5% */
/* 100Hz (0.5%), 200Hz (1%), 400Hz (2%),800Hz (4%), 1.6kHz (8%), 3.2kHz (16%) */
SECTION_DTCM_DATA
uint16_t ConfigBuf[6] = {9999, 4999, 2499, 1249, 624, 311};

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void TMR_Init(void);
void DMA_Init(uint32_t* Buf);

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

    /* Initialize DMA */
    DMA_Init((uint32_t*)ConfigBuf);

    /* Initialize TMR1 */
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
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR1);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*Config PD1 for TMR1 CH1 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD2 for TMR1 CH1N */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_2;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD5 for TMR1 CH2 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_5;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD8 for TMR1 CH2N */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_8;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD9 for TMR1 CH3 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_9;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD10 for TMR1 CH3N */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_10;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD3 for TMR1 CH4 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_3;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Config TMR1 */
    TMR_InitStruct.Prescaler         = 119;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = ConfigBuf[0];
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0;
    DDL_TMR_Init(TMR1, &TMR_InitStruct);

    TMR_OCInitStruct.OCMode       = DDL_TMR_OCMODE_PWM1;
    TMR_OCInitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.OCNState     = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.CompareValue = 50;
    TMR_OCInitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCNPolarity  = DDL_TMR_OCPOLARITY_HIGH;
    TMR_OCInitStruct.OCIdleState  = DDL_TMR_OCIDLESTATE_LOW;
    TMR_OCInitStruct.OCNIdleState = DDL_TMR_OCIDLESTATE_LOW;

    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH1, &TMR_OCInitStruct);
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH2, &TMR_OCInitStruct);
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH3, &TMR_OCInitStruct);
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH4, &TMR_OCInitStruct);

    DDL_TMR_ConfigDMABurst(TMR1, DDL_TMR_DMABURST_BASEADDR_AUTORLD, DDL_TMR_DMABURST_LENGTH_6TRANSFERS);

    DDL_TMR_EnableDMAReq_UPDATE(TMR1);

    /* Enable preload */
    DDL_TMR_EnableCounter(TMR1);

    /* Enable outputs */
    DDL_TMR_EnableAllOutputs(TMR1);
}

/*!
 * @brief       DMA Init
 *
 * @param       None
 *
 * @retval      None
 */
void DMA_Init(uint32_t* Buf)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_DMA);
    DDL_RCM_Lock();

    DMA_InitStruct.Mode                   = DDL_DMA_MODE_CIRCULAR;
    DMA_InitStruct.PeriphOrM2MSrcIncMode  = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode  = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_HALFWORD;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_HALFWORD;
    DMA_InitStruct.NbData                 = 6;
    DMA_InitStruct.Priority               = DDL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode               = DDL_DMA_FIFOMODE_ENABLE;
    DMA_InitStruct.FIFOThreshold          = DDL_DMA_FIFOTHRESHOLD_FULL;
    DMA_InitStruct.MemBurst               = DDL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst            = DDL_DMA_PBURST_SINGLE;

    DMA_InitStruct.Channel                = DDL_DMA_CHANNEL_4;
    DMA_InitStruct.Direction              = DDL_DMA_DIRECTION_MEMORY_TO_PERIPH;
    DMA_InitStruct.MemoryOrM2MDstAddress  = (uint32_t)Buf;
    DMA_InitStruct.PeriphOrM2MSrcAddress  = (uint32_t)&TMR1->DMADDR;
    DDL_DMA_Init(DMA1, DDL_DMA_STREAM_0, &DMA_InitStruct);

    DDL_DMA_EnableStream(DMA1, DDL_DMA_STREAM_0);
}
