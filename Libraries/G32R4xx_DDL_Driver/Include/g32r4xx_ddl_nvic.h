/**
  *
  * @file    g32r4xx_ddl_nvic.h
  * @brief   Header file of I2C DDL module.
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
  */

#ifndef G32R4xx_DDL_NVIC_H
#define G32R4xx_DDL_NVIC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

/** @defgroup NVIC_DDL NVIC
  * @{
  */
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup NVIC_DDL_Exported_Constants NVIC Exported Constants
  * @{
  */

/** @defgroup NVIC_DDL_EC_VECT_TABLE NVIC Vect table
  @{
*/

#define DDL_NVIC_VECT_TAB_RAM    0x20000000UL
#define DDL_NVIC_VECT_TAB_FLASH  0x08000000UL
/**
  * @}
  */

/** @defgroup NVIC_DDL_EC_PRIORITY_GROUP NVIC priority group
  @{
*/

#define DDL_NVIC_PRIORITY_GROUP_0  0x700UL
#define DDL_NVIC_PRIORITY_GROUP_1  0x600UL
#define DDL_NVIC_PRIORITY_GROUP_2  0x500UL
#define DDL_NVIC_PRIORITY_GROUP_3  0x400UL
#define DDL_NVIC_PRIORITY_GROUP_4  0x300UL
/**
  * @}
  */

/** @defgroup NVIC_DDL_EC_SYSTICK_CLOCK_SOURCE SysTick Clock source
  @{
*/
#define DDL_SYSTICK_CLK_SOURCE_HCLK_DIV8  0x0UL
#define DDL_SYSTICK_CLK_SOURCE_HCLK       0x1UL
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup  NVIC_DDL_Exported_Functions NVIC Exported Functions
  * @{
  */
typedef void (*Interrupt_Handler)(void);

void DDL_NVIC_ConfigPriorityGroup(uint32_t priorityGroup);
void DDL_NVIC_EnableIRQRequest(IRQn_Type irq, uint8_t preemptionPriority, uint8_t subPriority);
void DDL_NVIC_DisableIRQRequest(IRQn_Type irq);

/* Vector Table */
void DDL_NVIC_ConfigVectorTable(uint32_t vectTab, uint32_t offset);

/* Systick */
void DDL_SysTick_ConfigCLKSource(uint32_t clkSource);

#ifdef VECT_TAB_SRAM
ErrorStatus DDL_Interrupt_Register(IRQn_Type irqn, Interrupt_Handler new_handler);
#endif

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
 * @}
 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

