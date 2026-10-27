/**
  *
  * @file    g32r4xx_ddl_pmu.h
  * @brief   Header file of PMU DDL module.
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
#ifndef G32R4xx_DDL_PMU_H
#define G32R4xx_DDL_PMU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(PMU)

/** @defgroup PMU_DDL PMU
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup PMU_DDL_Exported_Constants PMU Exported Constants
  * @{
  */

/** @defgroup PMU_DDL_EC_WAKEUP_PIN Wakeup pin
  * @{
  */
#define DDL_PMU_WAKEUP_PIN1  PMU_WKPCR_WKUPEN0  /* PC1-WUIO */
#define DDL_PMU_WAKEUP_PIN2  PMU_WKPCR_WKUPEN1  /* PC2-WUIO */
#define DDL_PMU_WAKEUP_PIN3  PMU_WKPCR_WKUPEN2  /* PD0-WUIO */
#define DDL_PMU_WAKEUP_PIN4  PMU_WKPCR_WKUPEN3  /* PD9-WUIO */

/**
  * @}
  */

/** @defgroup PMU_DDL_EC_WAKEUP_PIN_POLARITY Wakeup pin polarity
  * @{
  */
#define DDL_PMU_WAKEUP_PIN_POLARITY_RISING              (0x0U)
#define DDL_PMU_WAKEUP_PIN_POLARITY_FALLING             (0x1U)
#define DDL_PMU_WAKEUP_PIN_POLARITY_RISING_AND_FALLING  (0x2U)
/**
  * @}
  */

/** @defgroup PMU_DDL_EC_STANDBY_PIN_MODE Standby pin mode
  * @{
  */
#define DDL_PMU_STANDBY_PINMODE_ANALOG  (0x0U)
#define DDL_PMU_STANDBY_PINMODE_PU      (0x1U)
#define DDL_PMU_STANDBY_PINMODE_PD      (0x2U)
/**
  * @}
  */

/** @defgroup PMU_DDL_EC_EVS_PIN_FILTER EVS pin filter
  * @{
  */
#define DDL_PMU_EVS_FILTER_NONE     (0x00000000UL)
#define DDL_PMU_EVS_FILTER_2LSICLK  (PMU_EVSCR_VDCPVDFILTER_0)
#define DDL_PMU_EVS_FILTER_4LSICLK  (PMU_EVSCR_VDCPVDFILTER_1)
#define DDL_PMU_EVS_FILTER_8LSICLK  (PMU_EVSCR_VDCPVDFILTER)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PMU_DDL_Exported_Macros PMU Exported Macros
  * @{
  */

/** @defgroup PMU_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PMU register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_PMU_WriteReg(__REG__,  __VALUE__) WRITE_REG(PMU->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PMU register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_PMU_ReadReg(__REG__)  READ_REG(PMU->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PMU_DDL_Exported_Functions PMU Exported Functions
  * @{
  */

/** @defgroup PMU_DDL_EF_WakeUp WakeUp
  * @{
  */

/**
  * @brief  Enable pin wake up.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_EnableWakeUpPin(uint32_t Pin)
{
  SET_BIT(PMU->WKPCR, Pin);
}

/**
  * @brief  Disable pin wake up.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_DisableWakeUpPin(uint32_t Pin)
{
  CLEAR_BIT(PMU->WKPCR, Pin);
}

/**
  * @brief  Set wake up pin polarity.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @param Polarity this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_RISING
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_FALLING
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_RISING_AND_FALLING
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_SetWakeUpPinPolarity(uint32_t Pin, uint32_t Polarity)
{
  MODIFY_REG(PMU->WKPCR, (PMU_WKPCR_WKUPPOL0 << ((POSITION_VAL(Pin) * 2))), (Polarity << (4 + POSITION_VAL(Pin) * 2)));
}

/**
  * @brief  Get wake up pin polarity.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_RISING
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_FALLING
  *        @arg @ref DDL_PMU_WAKEUP_PIN_POLARITY_RISING_AND_FALLING
  */
__STATIC_INLINE uint32_t DDL_PMU_GetWakeUpPinPolarity(uint32_t Pin)
{
  return (uint32_t)(READ_BIT(PMU->WKPCR, (PMU_WKPCR_WKUPPOL0 << (POSITION_VAL(Pin) * 2))) >> (4 + POSITION_VAL(Pin) * 2));
}
/**
  * @}
  */

/** @defgroup PMU_DDL_EF_StandbyMode Standby mode
  * @{
  */

/**
  * @brief  Set pin mode in standby mode.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @param Mode this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_ANALOG
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_PU
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_PD
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_SetPinModeInStandby(uint32_t Pin, uint32_t Mode)
{
  MODIFY_REG(PMU->WKPCR, PMU_WKPCR_APC, ((!!Mode) << PMU_WKPCR_APC_Pos));
  if(Mode == DDL_PMU_STANDBY_PINMODE_PU)
  {
    SET_BIT(PMU->PUCRA, Pin);
    CLEAR_BIT(PMU->PDCRA, Pin);
  }
  else if(Mode == DDL_PMU_STANDBY_PINMODE_PD)
  {
    CLEAR_BIT(PMU->PUCRA, Pin);
    SET_BIT(PMU->PDCRA, Pin);
  }
  else
  {
    CLEAR_BIT(PMU->PUCRA, Pin);
    CLEAR_BIT(PMU->PDCRA, Pin);
  }
}

/**
  * @brief  Get pin mode in standby mode.
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_ANALOG
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_PU
  *        @arg @ref DDL_PMU_STANDBY_PINMODE_PD
  */
__STATIC_INLINE uint32_t DDL_PMU_GetPinModeInStandby(uint32_t Pin)
{
  return (uint32_t)((READ_BIT(PMU->WKPCR, PMU_WKPCR_APC) ==  PMU_WKPCR_APC ? 1UL : 0UL) *
                    ((READ_BIT(PMU->PUCRA, Pin) > 0U ? DDL_PMU_STANDBY_PINMODE_PU : 0UL) |
                    (READ_BIT(PMU->PDCRA, Pin) > 0U ? DDL_PMU_STANDBY_PINMODE_PD : 0UL)));
}

/**
  * @brief  Check if pin wake up event occurred or not
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_PMU_IsActiveFlag_WakeUp(uint32_t Pin)
{
  return (uint32_t)(READ_BIT(PMU->SR, Pin));
}

/**
  * @brief  Clear pin wake up flag
  * @param Pin this parameter can be one of the following values:
  *        @arg @ref DDL_PMU_WAKEUP_PIN1
  *        @arg @ref DDL_PMU_WAKEUP_PIN2
  *        @arg @ref DDL_PMU_WAKEUP_PIN3
  *        @arg @ref DDL_PMU_WAKEUP_PIN4
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_ClearFlag_WakeUp(uint32_t Pin)
{
  WRITE_REG(PMU->SR, Pin);
}

/**
  * @brief  Check if standby event occurred or not
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_PMU_IsActiveFlag_Standby(void)
{
  return (uint32_t)(READ_BIT(PMU->SR, PMU_SR_SBF));
}

/**
  * @brief  Clear standby flag
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_ClearFlag_Standby(void)
{
  WRITE_REG(PMU->SR, PMU_SR_SBF);
}

/**
  * @}
  */

/** @defgroup PMU_DDL_EF_EVS EVS Pin
  * @{
  */

/**
  * @brief  Enable EVS pin to wake up in standby mode.
  * @param  None.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_EnableEVSWakeUp(void)
{
  SET_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDWKPEN);
}

/**
  * @brief  Disable EVS pin to wake up in standby mode.
  * @param  None.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_DisableEVSWakeUp(void)
{
  CLEAR_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDWKPEN);
}

/**
  * @brief  Enable EVS pin.
  * @param  None.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_EnableEVS(void)
{
  SET_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDEN);
}

/**
  * @brief  Disable EVS pin.
  * @param  None.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_DisableEVS(void)
{
  CLEAR_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDEN);
}

/**
  * @brief  Set EVS pin filter.
  * @param  Filter this parameter can be one of the following values:
  *         @arg @ref DDL_PMU_EVS_FILTER_NONE
  *         @arg @ref DDL_PMU_EVS_FILTER_2LSICLK
  *         @arg @ref DDL_PMU_EVS_FILTER_4LSICLK
  *         @arg @ref DDL_PMU_EVS_FILTER_8LSICLK
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_SetEVSFilter(uint32_t Filter)
{
  MODIFY_REG(PMU->EVSCR, PMU_EVSCR_VDCPVDFILTER, Filter);
}

/**
  * @brief  Get EVS pin filter.
  * @param  None
  * @retval return values can be one of the following values:
  *         @arg @ref DDL_PMU_EVS_FILTER_NONE
  *         @arg @ref DDL_PMU_EVS_FILTER_2LSICLK
  *         @arg @ref DDL_PMU_EVS_FILTER_4LSICLK
  *         @arg @ref DDL_PMU_EVS_FILTER_8LSICLK
  */
__STATIC_INLINE uint32_t DDL_PMU_GetEVSFilter(void)
{
  return (uint32_t)(READ_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDFILTER));
}

/**
  * @brief  Get EVS thresholds value.
  * @param  threshold this value can between 0x0 to 0x3.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_SetEVSThreshold(uint32_t threshold)
{
  MODIFY_REG(PMU->EVSCR, PMU_EVSCR_VDCPVDSEL, threshold << PMU_EVSCR_VDCPVDSEL_Pos);
}

/**
  * @brief  Get EVS thresholds value.
  * @param  None
  * @retval return values can between 0x0 to 0x3.
  */
__STATIC_INLINE uint32_t DDL_PMU_GetEVSThreshold(void)
{
  return (uint32_t)(READ_BIT(PMU->EVSCR, PMU_EVSCR_VDCPVDSEL) >> PMU_EVSCR_VDCPVDSEL_Pos);
}

/**
  * @brief  Check if EVS wakeup event occurred or not
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_PMU_IsActiveFlag_EVS(void)
{
  return (uint32_t)(READ_BIT(PMU->SR, PMU_SR_EVSWKF) == PMU_SR_EVSWKF ? 1UL : 0UL);
}

/**
  * @brief  Clear EVS wakeup event flag
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_ClearFlag_EVS(void)
{
  WRITE_REG(PMU->SR, PMU_SR_EVSWKF);
}

/**
  * @}
  */

/** @defgroup PMU_DDL_EF_PVD PVD
  * @{
  */

/**
  * @brief  Enable PVD.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_EnablePVD(void)
{
  SET_BIT(PMU->PVDCR, PMU_PVDCR_PVDEN);
}

/**
  * @brief  Disable PVD.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_DisablePVD(void)
{
  CLEAR_BIT(PMU->PVDCR, PMU_PVDCR_PVDEN);
}

/**
  * @brief  Set PVD threshold.
  * @param  Threshold this parameter can between 0x0 to 0x7.
  * @retval None
  */
__STATIC_INLINE void DDL_PMU_SetPVDThreshold(uint32_t Threshold)
{
  MODIFY_REG(PMU->PVDCR, PMU_PVDCR_PVDTHSEL, (Threshold << PMU_PVDCR_PVDTHSEL_Pos));
}

/**
  * @brief  Get PVD threshold.
  * @param  None
  * @retval return values can between 0x0 to 0x7.
  */
__STATIC_INLINE uint32_t DDL_PMU_GetPVDThreshold(void)
{
  return (uint32_t)(READ_BIT(PMU->PVDCR, PMU_PVDCR_PVDTHSEL) >> PMU_PVDCR_PVDTHSEL_Pos);
}

/**
  * @brief  Check if PVD output event occurred or not
  * @param  None
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_PMU_IsActiveFlag_PVDOutput(void)
{
  return (uint32_t)(READ_BIT(PMU->SR, PMU_SR_PVDO) == PMU_SR_PVDO ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup PMU_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
void DDL_PMU_EnterStandbyModeWFI(void);
void DDL_PMU_EnterStopModeWFI(void);
void DDL_PMU_EnterStandbyModeWFE(void);
void DDL_PMU_EnterStopModeWFE(void);
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

#endif /* PMU */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_PMU_H */

