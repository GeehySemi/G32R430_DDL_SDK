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
#define BUFFER_SIZE              40

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
const uint32_t FLASH_Buffer[BUFFER_SIZE]=
{
    0x3A946304, 0x75E48BBD, 0xB039358D, 0x3850A3FA, 0x284BCDC7,
    0x43B33E68, 0x4EBD5D5F, 0x6D1B4980, 0xF5C3B9C3, 0x16466442,
    0xADF6A017, 0x7184EEA3, 0x66FEBAD3, 0x06AA73D0, 0x7710DFE6,
    0xCBD535E1, 0xA564CD4B, 0xBAF092D8, 0xEDF0A59B, 0x17445073,
    0x5C5FD295, 0x65014689, 0xB277C8ED, 0x7B00C9D5, 0x2D7A915B,
    0xBA61431E, 0x2FC28956, 0xEA9F166E, 0xBE7EACCA, 0x13454BDA,
    0x1E216947, 0x0D9248EB, 0x001CD302, 0xC46FAD04, 0xE18BBF7B,
    0xDEFD0706, 0xE27B3232, 0x74801A22, 0xA8D5B2BE, 0x738C7DED
};

SECTION_DTCM_DATA
uint32_t SRAM_Buffer[BUFFER_SIZE];

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength);
void DMA_Init(void);
void DMA1_STR0_IRQHandler(void);

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
    uint16_t i = 0;
    uint8_t flag = 0;

    /* Configure system clock */
    DDL_SysClkConfig();

    /* Configure interrupt group 4: 4-bit preemptive priority, 0-bit subpriority */
    DDL_NVIC_ConfigPriorityGroup(DDL_NVIC_PRIORITY_GROUP_4);

    /* SRAM Buffer Init */
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        SRAM_Buffer[i]=0;
    }

    /* DMA Init */
    DMA_Init();

    /* Check if the transferred data is correct */
    flag = Buffercmp(FLASH_Buffer, SRAM_Buffer, BUFFER_SIZE);

    /* If the comparison succeeds (flag == 1), it indicates that the data in both buffers matches */
    if (flag == 1)
    {
        /* Proceed with the next steps as the data verification is successful */
        while (1)
        {
        }
    }

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
 * @brief     DMA Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void DMA_Init(void)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_DMA);
    DDL_RCM_Lock();

    /* Configure the source address for the DMA transfer (FLASH_Buffer) */
    DMA_InitStruct.PeriphOrM2MSrcAddress  = (uint32_t)FLASH_Buffer;
    /* Configure the destination address for the DMA transfer (SRAM_Buffer) */
    DMA_InitStruct.MemoryOrM2MDstAddress  = (uint32_t)SRAM_Buffer;
    /* Set the DMA transfer direction: Memory-to-Memory */
    DMA_InitStruct.Direction              = DDL_DMA_DIRECTION_MEMORY_TO_MEMORY;
    /* Set the DMA mode to Normal (non-circular) */
    DMA_InitStruct.Mode                   = DDL_DMA_MODE_NORMAL;
    /* Enable address increment for the source (FLASH_Buffer) */
    DMA_InitStruct.PeriphOrM2MSrcIncMode  = DDL_DMA_PERIPH_INCREMENT;
    /* Enable address increment for the destination (SRAM_Buffer) */
    DMA_InitStruct.MemoryOrM2MDstIncMode  = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_WORD;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_WORD;
    /* Set the number of data items to transfer */
    DMA_InitStruct.NbData                 = BUFFER_SIZE;
    DMA_InitStruct.Channel                = DDL_DMA_CHANNEL_0;
    DMA_InitStruct.Priority               = DDL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode               = DDL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold          = DDL_DMA_FIFOTHRESHOLD_FULL;
    DMA_InitStruct.MemBurst               = DDL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst            = DDL_DMA_PBURST_SINGLE;
    DDL_DMA_Init(DMA1, DDL_DMA_STREAM_0, &DMA_InitStruct);

    DDL_DMA_EnableIT_TC(DMA1, DDL_DMA_STREAM_0);

    DDL_Interrupt_Register(DMA1_Stream0_IRQn,DMA1_STR0_IRQHandler);
    DDL_NVIC_EnableIRQRequest(DMA1_Stream0_IRQn, 0, 0);

    DDL_DMA_EnableStream(DMA1, DDL_DMA_STREAM_0);
}

/*!
 * @brief     Compares two buffers element by element.
 *
 * @param     pBuffer: Pointer to the first buffer to be compared.
 * @param     pBuffer1: Pointer to the second buffer to be compared.
 * @param     BufferLength: The number of elements to compare in the buffers.
 *
 * @retval    1: The two buffers are identical (all elements match).
 * @retval    0: The two buffers are different (at least one element does not match).
 */
uint8_t Buffercmp(const uint32_t* pBuffer, uint32_t* pBuffer1, uint16_t BufferLength)
{
    while (BufferLength--)
    {
        if (*pBuffer != *pBuffer1)
        {
            return 0;
        }

        pBuffer++;
        pBuffer1++;
    }

    return 1;
}

/**
 * @brief     This function handles SysTick request
 *
 * @param     None
 *
 * @retval    None
 *
 */
void DMA1_STR0_IRQHandler(void)
{
    if (DDL_DMA_IsActiveFlag_TC0(DMA1))
    {
        DDL_DMA_ClearFlag_TC0(DMA1);
    }
}
