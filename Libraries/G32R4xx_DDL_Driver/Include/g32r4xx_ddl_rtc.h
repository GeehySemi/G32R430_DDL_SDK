/**
  *
  * @file    g32r4xx_ddl_rtc.h
  * @brief   Header file of RTC DDL module.
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
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4XX_DDL_RTC_H
#define G32R4XX_DDL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(RTC)

/** @defgroup RTC_DDL RTC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RTC_DDL_Private_Constants RTC Private Constants
  * @{
  */
/* Masks Definition */
#define RTC_INIT_MASK      RTC_CSTS_CFGMFLG
#define RTC_CSTS_INITEN    RTC_CSTS_CFGMFLG
#define RTC_RSF_MASK       ((uint32_t)~(RTC_CSTS_INITEN | RTC_CSTS_RSYNCFLG))

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RTC_DDL_Private_Macros RTC Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RTC_DDL_ES_INIT RTC Exported Init structure
  * @{
  */

/**
  * @brief  RTC Init structures definition
  */
typedef struct
{
    uint32_t Prescaler;    /*!< Specifies the RTC Predivider value.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7FFF

                              This feature can be modified afterwards using unitary function
                              @ref DDL_RTC_SetPrescaler(). */
} DDL_RTC_InitTypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
    uint32_t TimerCounter;    /*!< Specifies the RTC Timer counter.
                                 This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFFFFFFFF

                                 This feature can be modified afterwards using unitary function
                                 @ref DDL_RTC_SetTime(). */
} DDL_RTC_TimeTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct
{
    uint32_t AlarmTime;   /*!< Specifies the RTC Alarm Time members
                             This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFFFFFFFF

                             This feature can be modified afterwards using unitary function
                             @ref DDL_RTC_SetAlarm(). */
} DDL_RTC_AlarmTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTC_DDL_Exported_Constants RTC Exported Constants
  * @{
  */

#if defined(USE_FULL_DDL_DRIVER)

#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup RTC_DDL_EC_CALIB_OUTPUT  Calibration output
  * @{
  */
#define DDL_RTC_CALIB_OUTPUT_NONE  0x00000000U  /*!< Calibration output disabled */
/**
  * @}
  */

/** @defgroup RTC_EC_DDL_CLOCK_SOURCE Clock source
  * @{
  */
#define DDL_RTC_CLOCK_SOURCE_NONE        (0x00000000UL)                       /*!< RTC clock source not selected */
#define DDL_RTC_CLOCK_SOURCE_LSE         (PMU_CR_RTCSEL_0)                    /*!< LSE selected as RTC clock source */
#define DDL_RTC_CLOCK_SOURCE_LSI         (PMU_CR_RTCSEL_1)                    /*!< LSI selected as RTC clock source */
#define DDL_RTC_CLOCK_SOURCE_HSE_DIV_32  (PMU_CR_RTCSEL_1 | PMU_CR_RTCSEL_0)  /*!< HSE divided by 32 selected as RTC clock source */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RTC_DDL_Exported_Macros RTC Exported Macros
  * @{
  */

/** @defgroup RTC_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_RTC_WriteReg(__INSTANCE__,  __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_RTC_ReadReg(__INSTANCE__,  __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RTC_DDL_Exported_Functions RTC Exported Functions
  * @{
  */

/** @defgroup RTC_DDL_EF_Configuration Configuration
  * @{
  */
/**
  * @brief  Set prescaler factor
  * @param  RTCx RTC Instance
  * @param  Prescaler Value between Min_Data = 0 and Max_Data = 0xFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_SetPrescaler(RTC_TypeDef* RTCx, uint32_t Prescaler)
{
    MODIFY_REG(RTCx->PSCRLDH, RTC_PSCRLD_PSCRLDH, (Prescaler >> 16U));
    MODIFY_REG(RTCx->PSCRLDL, RTC_PSCRLD_PSCRLDL, (Prescaler & 0xFFFFU));
}

/**
  * @brief  Get the prescaler remainder value
  * @param  RTCx: RTC Instance
  * @retval The remainder value ranging from 0 to 0xFFFFF
  */
__STATIC_INLINE uint32_t RTC_GetPrescalerRemainderValue(RTC_TypeDef* RTCx)
{
    return (uint32_t)((READ_BIT(RTCx->DIVH, RTC_DIVH_DIVH) << 16U) + READ_BIT(RTCx->DIVL, RTC_DIVL_DIVL));
}

/**
  * @brief  Set RTC clock source
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_NONE
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_LSE
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_LSI
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_HSE_DIV_32
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_SetClkSource(uint32_t Source)
{
    MODIFY_REG(PMU->CR, PMU_CR_RTCSEL, Source);
}

/**
  * @brief  Get RTC clock source
  * @param  None
  * @retval Value can be one of the following values:
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_NONE
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_LSE
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_LSI
  *         @arg @ref DDL_RTC_CLOCK_SOURCE_HSE_DIV_32
  */
__STATIC_INLINE uint32_t DDL_RTC_GetClkSource(void)
{
    return (uint32_t)(READ_BIT(PMU->CR, PMU_CR_RTCSEL));
}

/**
  * @brief  Enable initialization mode
  * @note   Initialization mode is used to program time register (RTC_TIME)
  *         and alarm register (RTC_ALARM) and prescaler register (RTC_PSC).
  *         Counters are stopped and start counting from the new value when INIT is reset.
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_EnableInitMode(RTC_TypeDef* RTCx)
{
    /* Set the Initialization mode */
    MODIFY_REG(RTCx->CSTS, RTC_INIT_MASK, RTC_CSTS_INITEN);
}

/**
  * @brief  Disable initialization mode (Free running mode)
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_DisableInitMode(RTC_TypeDef* RTCx)
{
    /* Exit Initialization mode */
    MODIFY_REG(RTCx->CSTS, RTC_INIT_MASK, (uint32_t)~RTC_CSTS_INITEN);
}

/**
  * @brief  Enable RTC clock
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_EnableClk(void)
{
    SET_BIT(PMU->CR, PMU_CR_RTCEN);
}

/**
  * @brief  Disable RTC clock
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_DisableClk(void)
{
    CLEAR_BIT(PMU->CR, PMU_CR_RTCEN);
}

/**
  * @}
  */

/** @defgroup RTC_DDL_EF_Time Time
  * @{
  */

/**
  * @brief  Set time in Binary format
  * @note   It can be written in initialization mode only (@ref DDL_RTC_EnableInitMode function)
  * @param  RTCx RTC Instance
  * @param  TimerCounter Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_SetTime(RTC_TypeDef* RTCx, uint32_t TimerCounter)
{
    WRITE_REG(RTCx->CNTH, ((TimerCounter >> 16U) & 0xFFFFU));
    WRITE_REG(RTCx->CNTL, (TimerCounter & 0xFFFFU));
}

/**
  * @brief  Get time (all converted to seconds) in Binary format
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF.
  */
__STATIC_INLINE uint32_t DDL_RTC_GetTime(RTC_TypeDef* RTCx)
{
    uint16_t cnt_high;
    uint16_t cnt_low;

    cnt_high = READ_BIT(RTCx->CNTH, RTC_CNT_CNTH);
    cnt_low  = READ_BIT(RTCx->CNTL, RTC_CNT_CNTL);

    return ((uint32_t)cnt_high << 16U) | (uint32_t)cnt_low;
}

/**
  * @}
  */

/** @defgroup RTC_DDL_EF_ALARM ALARM
  * @{
  */

/**
  * @brief  Set ALARM time in Binary format
  * @param  RTCx RTC Instance
  * @param  Time Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_SetAlarm(RTC_TypeDef* RTCx, uint32_t Time)
{
    MODIFY_REG(RTCx->ALRH, RTC_ALRH_ALRH, ((Time >> 16U) & 0xFFFFU));
    MODIFY_REG(RTCx->ALRL, RTC_ALRL_ALRL, (Time & 0xFFFFU));
}

/**
  * @}
  */

/** @defgroup RTC_DDL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Second signal condition met flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_SEC(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_SECFLG) == (RTC_CSTS_SECFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Second signal condition met flag
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_ClearFlag_SEC(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CSTS, RTC_CSTS_SECFLG);
}

/**
  * @brief  Get Alarm flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_ALR(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_ALRFLG) == (RTC_CSTS_ALRFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Alarm flag
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_ClearFlag_ALR(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CSTS, RTC_CSTS_ALRFLG);
}

/**
  * @brief  Get Overflow occur flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_OVR(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_OVRFLG) == (RTC_CSTS_OVRFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Overflow occur flag
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_ClearFlag_OVR(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CSTS, RTC_CSTS_OVRFLG);
}

/**
  * @brief  Get Registers synchronization flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_RS(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_RSYNCFLG) == (RTC_CSTS_RSYNCFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Registers synchronization flag
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_ClearFlag_RS(RTC_TypeDef* RTCx)
{
    WRITE_REG(RTCx->CSTS, (~((RTC_CSTS_RSYNCFLG | RTC_CSTS_INITEN) & 0x0000FFFFU) | (RTCx->CSTS & RTC_CSTS_INITEN)));
}

/**
  * @brief  Get Initialization status flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_CFGM(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_CFGMFLG) == (RTC_CSTS_CFGMFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Get Alarm A write flag
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsActiveFlag_OCFLG(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CSTS, RTC_CSTS_OCFLG) == (RTC_CSTS_OCFLG)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup RTC_DDL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable Second interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_EnableIT_SEC(RTC_TypeDef* RTCx)
{
    SET_BIT(RTCx->CTRL, RTC_CTRL_SECIEN);
}

/**
  * @brief  Disable Second interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_DisableIT_SEC(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CTRL, RTC_CTRL_SECIEN);
}

/**
  * @brief  Check if Second interrupt is enabled or not
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsEnabledIT_SEC(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CTRL, RTC_CTRL_SECIEN) == (RTC_CTRL_SECIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Alarm interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_EnableIT_ALR(RTC_TypeDef* RTCx)
{
    SET_BIT(RTCx->CTRL, RTC_CTRL_ALRIEN);
}

/**
  * @brief  Disable Alarm interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_DisableIT_ALR(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CTRL, RTC_CTRL_ALRIEN);
}

/**
  * @brief  Check if Alarm interrupt is enabled or not
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsEnabledIT_ALR(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CTRL, RTC_CTRL_ALRIEN) == (RTC_CTRL_ALRIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Overflow interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_EnableIT_OVR(RTC_TypeDef* RTCx)
{
    SET_BIT(RTCx->CTRL, RTC_CTRL_OVRIEN);
}

/**
  * @brief  Disable Overflow interrupt
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_RTC_DisableIT_OVR(RTC_TypeDef* RTCx)
{
    CLEAR_BIT(RTCx->CTRL, RTC_CTRL_OVRIEN);
}

/**
  * @brief  Check if Overflow interrupt is enabled or not
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RTC_IsEnabledIT_OVR(RTC_TypeDef* RTCx)
{
    return ((READ_BIT(RTCx->CTRL, RTC_CTRL_OVRIEN) == (RTC_CTRL_OVRIEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RTC_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_RTC_DeInit(RTC_TypeDef* RTCx);
ErrorStatus DDL_RTC_Init(RTC_TypeDef* RTCx, DDL_RTC_InitTypeDef* RTC_InitStruct);
void        DDL_RTC_StructInit(DDL_RTC_InitTypeDef* RTC_InitStruct);
ErrorStatus DDL_RTC_TIME_Init(RTC_TypeDef* RTCx, DDL_RTC_TimeTypeDef* RTC_TimeStruct);
void        DDL_RTC_TIME_StructInit(DDL_RTC_TimeTypeDef* RTC_TimeStruct);
ErrorStatus DDL_RTC_ALM_Init(RTC_TypeDef* RTCx, DDL_RTC_AlarmTypeDef* RTC_AlarmStruct);
void        DDL_RTC_ALM_StructInit(DDL_RTC_AlarmTypeDef* RTC_AlarmStruct);
ErrorStatus DDL_RTC_EnterInitMode(RTC_TypeDef* RTCx);
ErrorStatus DDL_RTC_ExitInitMode(RTC_TypeDef* RTCx);
ErrorStatus DDL_RTC_WaitForSynchro(RTC_TypeDef* RTCx);
ErrorStatus DDL_RTC_WaitForOperationComplete(RTC_TypeDef* RTCx);

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

#endif /* defined(RTC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4XX_DDL_RTC_H */

