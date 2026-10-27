/**
  *
  * @file    g32r4xx_ddl_ts.h
  * @brief   Header file of TS DDL module.
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
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_TS_H
#define G32R4xx_DDL_TS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (TS)

/** @defgroup TS_DDL TS
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup TS_DDL_Exported_Constants TS Exported Constants
  * @{
  */
#define DDL_TS_SAMPLING_RATE_128   (0x00000000UL)
#define DDL_TS_SAMPLING_RATE_256   (TS_CR_OSR_SEL_0)
#define DDL_TS_SAMPLING_RATE_512   (TS_CR_OSR_SEL_1)
#define DDL_TS_SAMPLING_RATE_1024  (TS_CR_OSR_SEL_0 | TS_CR_OSR_SEL_1)

#define DDL_TS_OVERFLOW_KEEP_OLD  (0x00000000UL)
#define DDL_TS_OVERFLOW_USE_NEW   (TS_CR_OVRMOD)

#define DDL_TS_FLAG_DATA_IS_RDY     (TS_SR_RDY)
#define DDL_TS_FLAG_DATA_IS_NOTRDY  (0x00000000UL)

#define DDL_TS_FLAG_DATA_IS_OVR     (TS_SR_OVR)
#define DDL_TS_FLAG_DATA_IS_NOTOVR  (0x00000000UL)

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @defgroup TS_DDL_Exported_Functions TS Exported Functions
  * @{
  */

/**
  * @brief  Enable Temperature Sensor.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_Enable(TS_TypeDef *TSx)
{
  SET_BIT(TSx->CR, TS_CR_TS_EN);
}

/**
  * @brief  Disable Temperature Sensor.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_Disable(TS_TypeDef *TSx)
{
  CLEAR_BIT(TSx->CR, TS_CR_TS_EN);
}

/**
  * @brief  Checks if Temperature Sensor is enabled
  * @param  TSx TS Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_TS_IsEnabled(TS_TypeDef *TSx)
{
  return ((READ_BIT(TSx->CR, TS_CR_TS_EN) == (TS_CR_TS_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set Temperature Sensor Sampling Rate.
  * @param  TSx TS Instance
  * @param  SamplingRate Sampling Rate
  *         @arg @ref DDL_TS_SAMPLING_RATE_128
  *         @arg @ref DDL_TS_SAMPLING_RATE_256
  *         @arg @ref DDL_TS_SAMPLING_RATE_512
  *         @arg @ref DDL_TS_SAMPLING_RATE_1024
  * @retval None
  */
__STATIC_INLINE void DDL_TS_SetSamplingRate(TS_TypeDef *TSx, uint32_t SamplingRate)
{
  MODIFY_REG(TSx->CR, TS_CR_OSR_SEL, SamplingRate);
}

/**
  * @brief  Get Temperature Sensor Sampling Rate.
  * @param  TSx TS Instance
  * @retval SamplingRate Sampling Rate
  *         @arg @ref DDL_TS_SAMPLING_RATE_128
  *         @arg @ref DDL_TS_SAMPLING_RATE_256
  *         @arg @ref DDL_TS_SAMPLING_RATE_512
  *         @arg @ref DDL_TS_SAMPLING_RATE_1024
  */
__STATIC_INLINE uint32_t DDL_TS_GetSamplingRate(TS_TypeDef *TSx)
{
  return (uint32_t)READ_BIT(TSx->CR, TS_CR_OSR_SEL);
}

/**
  * @brief  Set Data Overflow Control Bit
  * @param  TSx TS Instance
  * @param  SamplingRate Sampling Rate
  *         @arg @ref DDL_TS_OVERFLOW_KEEP_OLD
  *         @arg @ref DDL_TS_OVERFLOW_USE_NEW
  * @retval None
  */
__STATIC_INLINE void DDL_TS_SetDataOverFlowControlMode(TS_TypeDef *TSx, uint32_t mode)
{
  MODIFY_REG(TSx->CR, TS_CR_OVRMOD, mode);
}

/**
  * @brief  Get Data Overflow Control Bit
  * @param  TSx TS Instance
  * @retval  SamplingRate Sampling Rate
  *         @arg @ref DDL_TS_OVERFLOW_KEEP_OLD
  *         @arg @ref DDL_TS_OVERFLOW_USE_NEW
  */
__STATIC_INLINE uint32_t DDL_TS_GetDataOverFlowControlMode(TS_TypeDef *TSx)
{
  return (uint32_t)READ_BIT(TSx->CR, TS_CR_OVRMOD);
}

/**
  * @brief  Enable Temperature Sensor Interrupt.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_EnableIT(TS_TypeDef *TSx)
{
  SET_BIT(TSx->CR, TS_CR_TS_IE);
}

/**
  * @brief  Disable Temperature Sensor Interrupt.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_DisableIT(TS_TypeDef *TSx)
{
  CLEAR_BIT(TSx->CR, TS_CR_TS_IE);
}

/**
  * @brief  Checks if Temperature Sensor Interrupt is enabled
  * @param  TSx TS Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_TS_IsEnabledIT(TS_TypeDef *TSx)
{
  return ((READ_BIT(TSx->CR, TS_CR_TS_IE) == (TS_CR_TS_IE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Temperature Sensor DataOverflow Interrupt.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_EnableIT_OVR(TS_TypeDef *TSx)
{
  SET_BIT(TSx->CR, TS_CR_OVRIE);
}

/**
  * @brief  Disable Temperature Sensor DataOverflow Interrupt.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_DisableIT_OVR(TS_TypeDef *TSx)
{
  CLEAR_BIT(TSx->CR, TS_CR_OVRIE);
}

/**
  * @brief  Checks if Temperature Sensor DataOverflow Interrupt is enabled
  * @param  TSx TS Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_TS_IsEnabledIT_OVR(TS_TypeDef *TSx)
{
  return ((READ_BIT(TSx->CR, TS_CR_OVRIE) == (TS_CR_OVRIE)) ? 1UL : 0UL);
}

/**
  * @brief  Read TS Data.
  * @param  TSx TS Instance
  * @retval data , range is 0x0000 ~ 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_TS_ReadData(TS_TypeDef *TSx)
{
  return (uint32_t)READ_BIT(TSx->DR, TS_DR_DATA);
}

/**
  * @brief  Read the effective flag of the sampling data.
  * @param  TSx TS Instance
  * @retval Sampling Data Valid Flag
  *         @arg @ref DDL_TS_FLAG_DATA_IS_RDY
  *         @arg @ref DDL_TS_FLAG_DATA_IS_NOTRDY
  */
__STATIC_INLINE uint32_t DDL_TS_IsActiveFlag_RDY(TS_TypeDef *TSx)
{
  return (uint32_t)READ_BIT(TSx->SR, TS_SR_RDY);
}

/**
  * @brief  Clear the effective flag of the sampling data.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_ClearFlag_RDY(TS_TypeDef *TSx)
{
  WRITE_REG(TSx->SR, TS_SR_RDY);
}

/**
  * @brief  Read the effective flag of the sampling data.
  * @param  TSx TS Instance
  * @retval Sampling Data Overflow Flag
  *         @arg @ref DDL_TS_FLAG_DATA_IS_OVR
  *         @arg @ref DDL_TS_FLAG_DATA_IS_NOTOVR
  */
__STATIC_INLINE uint32_t DDL_TS_IsActiveFlag_OVR(TS_TypeDef *TSx)
{
  return (uint32_t)READ_BIT(TSx->SR, TS_SR_OVR);
}

/**
  * @brief  Clear the effective flag of the sampling data.
  * @param  TSx TS Instance
  * @retval None
  */
__STATIC_INLINE void DDL_TS_ClearFlag_OVR(TS_TypeDef *TSx)
{
  WRITE_REG(TSx->SR, TS_SR_OVR);
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* TS */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_TS_H */

