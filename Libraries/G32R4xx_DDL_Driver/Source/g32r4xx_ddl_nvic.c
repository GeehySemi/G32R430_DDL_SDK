/**
  *
  * @file    g32r4xx_ddl_nvic.c
  * @brief   NVIC DDL module driver.
  *
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  * The original code has been modified by Geehy Semiconductor.
  *
  * Copyright (C) 2024-2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  *
  */

#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_nvic.h"
#include "g32r4xx_ddl_rcm.h"
#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

/** @defgroup NVIC_DDL NVIC
  * @{
  */

/** @addtogroup NVIC_DDL_Private_Macros
  * @{
  */

#define DDL_AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)
#define DDL_VECTOR_SIZE           39
/**
 * @}
 */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @addtogroup NVIC_DDL_Exported_Functions
  * @{
  */

/** @addtogroup NVIC_DDL_EF_Config
  * @{
  */

/**
  * @brief  Configures the priority grouping: pre-emption priority and subpriority.
  * @param  priorityGroup : specifies the priority grouping bits length.
 *              This parameter can be one of the following values:
 *              @arg DDL_NVIC_PRIORITY_GROUP_0 : 0 bits for pre-emption priority,4 bits for subpriority
 *              @arg DDL_NVIC_PRIORITY_GROUP_1 : 1 bits for pre-emption priority,3 bits for subpriority
 *              @arg DDL_NVIC_PRIORITY_GROUP_2 : 2 bits for pre-emption priority,2 bits for subpriority
 *              @arg DDL_NVIC_PRIORITY_GROUP_3 : 3 bits for pre-emption priority,1 bits for subpriority
 *              @arg DDL_NVIC_PRIORITY_GROUP_4 : 4 bits for pre-emption priority,0 bits for subpriority
  * @retval None
  */
void DDL_NVIC_ConfigPriorityGroup(uint32_t priorityGroup)
{
    SCB->AIRCR = DDL_AIRCR_VECTKEY_MASK | priorityGroup;
}

/**
 * @brief     Enable NVIC request
 *
 * @param     irq: the NVIC interrupt request, detailed in IRQn_Type
 *            For the complete G32 Devices IRQ Channels list,please refer to g32r4xx.h file
 *
 * @param     preemptionPriority: the pre-emption priority needed to set
 *
 * @param     subPriority: the subpriority needed to set
 *
 * @retval    None
 */
void DDL_NVIC_EnableIRQRequest(IRQn_Type irq, uint8_t preemptionPriority, uint8_t subPriority)
{
    uint32_t tempPriority, tempPrePri, tempSubPri;
    uint32_t priorityGrp;

    /* Get priority group */
    priorityGrp = (SCB->AIRCR) & (uint32_t)0x700U;

    /* get pre-emption priority and subpriority */
    switch(priorityGrp)
    {
        case DDL_NVIC_PRIORITY_GROUP_0:
            tempPrePri = 0;
            tempSubPri = 4;
            break;

        case DDL_NVIC_PRIORITY_GROUP_1:
            tempPrePri = 1;
            tempSubPri = 3;
            break;

        case DDL_NVIC_PRIORITY_GROUP_2:
            tempPrePri = 2;
            tempSubPri = 2;
            break;

        case DDL_NVIC_PRIORITY_GROUP_3:
            tempPrePri = 3;
            tempSubPri = 1;
            break;

        case DDL_NVIC_PRIORITY_GROUP_4:
            tempPrePri = 4;
            tempSubPri = 0;
            break;

        default:
            DDL_NVIC_ConfigPriorityGroup(DDL_NVIC_PRIORITY_GROUP_0);
            tempPrePri = 0;
            tempSubPri = 4;
            break;
    }

    tempPrePri = 4 - tempPrePri;
    tempSubPri = 4 - tempSubPri;
    tempPriority = preemptionPriority << tempPrePri;
    tempPriority |= subPriority & (0x0f >> tempSubPri);
    tempPriority <<= 4;
    NVIC->IPR[irq] = (uint8_t)tempPriority;

    /* enable the selected IRQ */
    NVIC->ISER[irq >> 0x05U] = (uint32_t)0x01U << (irq & (uint8_t)0x1FU);
}

/**
 * @brief     Disable NVIC request
 *
 * @param     irq: the NVIC interrupt request, detailed in IRQn_Type
 *
 * @retval    None
 */
void DDL_NVIC_DisableIRQRequest(IRQn_Type irq)
{
    /* disable the selected IRQ.*/
    NVIC->ICER[irq >> 0x05U] = (uint32_t)0x01U << (irq & (uint8_t)0x1FU);
}

/*!
 * @brief     Configs the vector table location and Offset.
 *
 * @param     vectTab: specifies if the vector table is in RAM or FLASH memory
 *                     This parameter can be one of the following values:
 *                     @arg NVIC_VECT_TAB_RAM   : NVIC vector table base address launch from RAM
 *                     @arg NVIC_VECT_TAB_FLASH : NVIC vector table base address launch from flash
 *
 * @param     Offset   Vector Table base offset field. This value must be a multiple of 0x200
 *
 * @retval    None
 */
void DDL_NVIC_ConfigVectorTable(uint32_t vectTab, uint32_t offset)
{
    SCB->VTOR = vectTab | (offset & (uint32_t)0x1FFFFF80);
}

/*!
 * @brief     Configures the SysTick clock source
 *
 * @param     clkSource: specifies the SysTick clock source
 *                       This parameter can be one of the following values:
 *                       @arg SYSTICK_CLK_SOURCE_HCLK_DIV8  : AHB clock divided by 8 selected as SysTick clock source.
 *                       @arg SYSTICK_CLK_SOURCE_HCLK       : AHB clock selected as SysTick clock source.
 *
 * @retval    None
 */
void DDL_SysTick_ConfigCLKSource(uint32_t clkSource)
{
    if (clkSource == DDL_SYSTICK_CLK_SOURCE_HCLK)
    {
        SysTick->CTRL |= (uint32_t)BIT2;
    }
    else
    {
        SysTick->CTRL &= (uint32_t)(~BIT2);
    }
}

#ifdef VECT_TAB_SRAM
/*!
 * @brief     User-defined interrupt service function
 *
 * @param     irqn Interrupt vector number
 *
 * @param     new_handler The new entry address of interrupt service function.
 *
 * @retval    An ErrorStatus enumeration value:
 *             - SUCCESS: The handler registration finished successfully
 *             - ERROR: The specified IRQn or vector table address is invalid
 *
 * @note      This function can only be used when VECT_TAB_SRAM is enabled.
 */
ErrorStatus DDL_Interrupt_Register(IRQn_Type irqn, Interrupt_Handler new_handler)
{
    uint32_t *vectors = (uint32_t *)SCB->VTOR;
    uint32_t vtor_addr = (uint32_t)SCB->VTOR;
    
    /* IRQ range check */
    if (irqn < -15 || irqn >= DDL_VECTOR_SIZE)
    {
        return ERROR;
    }
    
    /* VTOR region check */
    if (!((vtor_addr >= 0x20000000u && vtor_addr <= 0x20003FFFu) ||
          (vtor_addr <= 0x00007FFFu)))
    {
        return ERROR;
    }

    vectors[irqn+16] = (uint32_t)new_handler;
    __DSB();

    return SUCCESS;
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#endif
