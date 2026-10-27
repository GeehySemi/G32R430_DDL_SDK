/**
  *
  * @file    g32r4xx_ddl_bkp.h
  * @brief   Header file of BKP DDL module.
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
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_BKP_H
#define G32R4xx_DDL_BKP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(BKP)

/** @defgroup BKP_DDL BKP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup BKP_DDL_Exported_Macros BKP Exported Macros
  * @{
  */

#define DDL_BKP_DR0   (0x00000000UL)
#define DDL_BKP_DR1   (0x00000001UL)
#define DDL_BKP_DR2   (0x00000002UL)
#define DDL_BKP_DR3   (0x00000003UL)
#define DDL_BKP_DR4   (0x00000004UL)
#define DDL_BKP_DR5   (0x00000005UL)
#define DDL_BKP_DR6   (0x00000006UL)
#define DDL_BKP_DR7   (0x00000007UL)
#define DDL_BKP_DR8   (0x00000008UL)
#define DDL_BKP_DR9   (0x00000009UL)
#define DDL_BKP_DR10  (0x0000000AUL)
#define DDL_BKP_DR11  (0x0000000BUL)
#define DDL_BKP_DR12  (0x0000000CUL)
#define DDL_BKP_DR13  (0x0000000DUL)
#define DDL_BKP_DR14  (0x0000000EUL)
#define DDL_BKP_DR15  (0x0000000FUL)

#define DDL_BKP_LocateDataReg(__BASEADDR__,  __REG__) ((__BASEADDR__) + (__REG__ << 2))

/** @defgroup BKP_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in BKP register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_BKP_WriteReg(__REG__,  __VALUE__) WRITE_REG(BKP->__REG__, (__VALUE__))

/**
  * @brief  Read a value in BKP register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_BKP_ReadReg(__REG__)  READ_REG(BKP->__REG__)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup BKP_DDL_Exported_Functions BKP Exported Functions
  * @{
  */

/** @defgroup BKP_DDL_EF_Backup Backup
  * @{
  */

/**
  * @brief  Enable reset the BKP register.
  * @retval None
  */
__STATIC_INLINE void DDL_BKP_EnableReset(void)
{
  SET_BIT(PMU->CR, PMU_CR_BDRST);
}

/**
  * @brief  Disable reset the BKP register.
  * @retval None
  */
__STATIC_INLINE void DDL_BKP_DisableReset(void)
{
  CLEAR_BIT(PMU->CR, PMU_CR_BDRST);
}

/**
  * @brief  Write backup data to designative register.
  * @param Reg this parameter can be one of the following values:
  *        @arg @ref DDL_BKP_DR0
  *        @arg @ref DDL_BKP_DR1
  *        @arg @ref DDL_BKP_DR2
  *        @arg @ref DDL_BKP_DR3
  *        @arg @ref DDL_BKP_DR4
  *        @arg @ref DDL_BKP_DR5
  *        @arg @ref DDL_BKP_DR6
  *        @arg @ref DDL_BKP_DR7
  *        @arg @ref DDL_BKP_DR8
  *        @arg @ref DDL_BKP_DR9
  *        @arg @ref DDL_BKP_DR10
  *        @arg @ref DDL_BKP_DR11
  *        @arg @ref DDL_BKP_DR12
  *        @arg @ref DDL_BKP_DR13
  *        @arg @ref DDL_BKP_DR14
  *        @arg @ref DDL_BKP_DR15
  * @param Data this parameter can between 0x0000 to 0xFFFF.
  * @retval None
  */
__STATIC_INLINE void DDL_BKP_SetDataBackUp(uint32_t Reg, uint32_t Data)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_BKP_LocateDataReg((uint32_t)(&BKP->DR0), Reg);
  MODIFY_REG((*reg), BKP_DR0_DATA, (Data & BKP_DR0_DATA));
}

/**
  * @brief  Read backup data from designative register.
  * @param Reg this parameter can be one of the following values:
  *        @arg @ref DDL_BKP_DR0
  *        @arg @ref DDL_BKP_DR1
  *        @arg @ref DDL_BKP_DR2
  *        @arg @ref DDL_BKP_DR3
  *        @arg @ref DDL_BKP_DR4
  *        @arg @ref DDL_BKP_DR5
  *        @arg @ref DDL_BKP_DR6
  *        @arg @ref DDL_BKP_DR7
  *        @arg @ref DDL_BKP_DR8
  *        @arg @ref DDL_BKP_DR9
  *        @arg @ref DDL_BKP_DR10
  *        @arg @ref DDL_BKP_DR11
  *        @arg @ref DDL_BKP_DR12
  *        @arg @ref DDL_BKP_DR13
  *        @arg @ref DDL_BKP_DR14
  *        @arg @ref DDL_BKP_DR15
  * @retval return values can between 0 to 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_BKP_GetDataBackUp(uint32_t Reg)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_BKP_LocateDataReg((uint32_t)(&BKP->DR0), Reg);
  return (uint32_t)(READ_BIT((*reg), BKP_DR0_DATA));
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(BKP) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_BKP_H */

