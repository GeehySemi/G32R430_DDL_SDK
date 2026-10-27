/**
  *
  * @file    g32r4xx_ddl_rtc.c
  * @brief   RTC DDL module driver.
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
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_rtc.h"
#include "g32r4xx_ddl_rcm.h"
#ifdef  USE_FULL_ASSERT
    #include "g32_assert.h"
#else
    #define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(RTC)

/** @addtogroup RTC_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup RTC_DDL_Private_Constants
  * @{
  */
/* Default values used for prescaler */
#define RTC_PRESC_DEFAULT      0x000000FFU

/* Values used for timeout */
#define RTC_INITMODE_TIMEOUT         1000U
#define RTC_SYNCHRO_TIMEOUT          1000U
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RTC_DDL_Private_Macros
  * @{
  */
#define IS_DDL_RTC_PREDIV(__VALUE__)    ((__VALUE__) <= 0xFFFFFU)

/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup RTC_DDL_Exported_Functions
  * @{
  */

/** @addtogroup RTC_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-Initializes the RTC registers to their default reset values.
  * @note   This function does not reset the RTC Clock source and RTC Backup Data
  *         registers.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are de-initialized
  *          - ERROR: RTC registers are not de-initialized
  */
ErrorStatus DDL_RTC_DeInit(RTC_TypeDef* RTCx)
{
    ErrorStatus status = ERROR;

    /* Check the parameter */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Set Initialization mode */
    if (DDL_RTC_EnterInitMode(RTCx) != ERROR)
    {
        /* Reset CNT and CTRL registers */
        DDL_RTC_WriteReg(RTCx, CTRL, 0x00000000U);
        DDL_RTC_WriteReg(RTCx, CSTS, 0x00000010U);

        DDL_RTC_WriteReg(RTCx, PSCRLDH, 0x00000000U);
        DDL_RTC_WriteReg(RTCx, PSCRLDL, (RTC_PSCRLD_PSCRLDL & 0x8000U));

        DDL_RTC_WriteReg(RTCx, CNTH, 0x00000000U);
        DDL_RTC_WriteReg(RTCx, CNTL, 0x00000000U);

        DDL_RTC_WriteReg(RTCx, ALRH, (RTC_ALRH_ALRH & 0xFFFFU));
        DDL_RTC_WriteReg(RTCx, ALRL, (RTC_ALRL_ALRL & 0xFFFFU));

        /* Exit Initialization mode */
        DDL_RTC_DisableInitMode(RTCx);

        /* Wait till the RTC OCF flag is set */
        status = DDL_RTC_WaitForOperationComplete(RTCx);
    }

    return status;
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in RTC_InitStruct.
  * @param  RTCx RTC Instance
  * @param  RTC_InitStruct pointer to a @ref DDL_RTC_InitTypeDef structure that contains
  *         the configuration information for the RTC peripheral.
  * @note   The RTC Prescaler register is write protected and can be written in
  *         initialization mode only.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus DDL_RTC_Init(RTC_TypeDef* RTCx, DDL_RTC_InitTypeDef* RTC_InitStruct)
{
    ErrorStatus status = ERROR;

    /* Check the parameters */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));
    ASSERT_PARAM(IS_DDL_RTC_PREDIV(RTC_InitStruct->Prescaler));

    /* Set Initialization mode */
    if (DDL_RTC_EnterInitMode(RTCx) != ERROR)
    {
        /* Configure prescaler factor */
        DDL_RTC_SetPrescaler(RTCx, RTC_InitStruct->Prescaler);

        /* Exit Initialization mode */
        DDL_RTC_DisableInitMode(RTCx);

        /* Wait till the RTC OCF flag is set */
        status = DDL_RTC_WaitForOperationComplete(RTCx);

        status = SUCCESS;
    }

    return status;
}

/**
  * @brief  Set each @ref DDL_RTC_InitTypeDef field to default value.
  * @param  RTC_InitStruct pointer to a @ref DDL_RTC_InitTypeDef structure which will be initialized.
  * @retval None
  */
void DDL_RTC_StructInit(DDL_RTC_InitTypeDef* RTC_InitStruct)
{
    /* Set RTC_InitStruct fields to default values */
    RTC_InitStruct->Prescaler = RTC_PRESC_DEFAULT;
}

/**
  * @brief  Set the RTC current time.
  * @param  RTCx RTC Instance
  * @param  RTC_TimeStruct pointer to a RTC_TimeTypeDef structure that contains
  *                        the time configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus DDL_RTC_TIME_Init(RTC_TypeDef* RTCx, DDL_RTC_TimeTypeDef* RTC_TimeStruct)
{
    ErrorStatus status = ERROR;

    /* Check the parameters */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Enter Initialization mode */
    if (DDL_RTC_EnterInitMode(RTCx) != ERROR)
    {
        DDL_RTC_SetTime(RTCx, RTC_TimeStruct->TimerCounter);

        /* Exit Initialization mode */
        DDL_RTC_ExitInitMode(RTCx);

        /* Wait till the RTC OCF flag is set */
        status = DDL_RTC_WaitForOperationComplete(RTCx);

        status = SUCCESS;
    }

    return status;
}

/**
  * @brief  Set each @ref DDL_RTC_TimeTypeDef field to default value (Time = 0sec).
  * @param  RTC_TimeStruct pointer to a @ref DDL_RTC_TimeTypeDef structure which will be initialized.
  * @retval None
  */
void DDL_RTC_TIME_StructInit(DDL_RTC_TimeTypeDef* RTC_TimeStruct)
{
    /* Time = 0sec */
    RTC_TimeStruct->TimerCounter = 0U;
}

/**
  * @brief  Set the RTC Alarm.
  * @note   The Alarm register can only be written when the corresponding Alarm
  *         is disabled (Use @ref DDL_RTC_ALM_Disable function).
  * @param  RTCx RTC Instance
  * @param  RTC_AlarmStruct pointer to a @ref DDL_RTC_AlarmTypeDef structure that
  *                         contains the alarm configuration parameters.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ALARMA registers are configured
  *          - ERROR: ALARMA registers are not configured
  */
ErrorStatus DDL_RTC_ALM_Init(RTC_TypeDef* RTCx, DDL_RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    ErrorStatus status = ERROR;

    /* Check the parameters */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Set Initialization mode */
    if (DDL_RTC_EnterInitMode(RTCx) != ERROR)
    {
        DDL_RTC_SetAlarm(RTCx, RTC_AlarmStruct->AlarmTime);

        /* Exit Initialization mode */
        DDL_RTC_ExitInitMode(RTCx);

        /* Wait till the RTC OCF flag is set */
        status = DDL_RTC_WaitForOperationComplete(RTCx);

        status = SUCCESS;
    }

    return status;
}

/**
  * @brief  Set each @ref DDL_RTC_AlarmTypeDef of ALARM field to default value (Time = 00h:00mn:00sec).
  * @param  RTC_AlarmStruct pointer to a @ref DDL_RTC_AlarmTypeDef structure which will be initialized.
  * @retval None
  */
void DDL_RTC_ALM_StructInit(DDL_RTC_AlarmTypeDef* RTC_AlarmStruct)
{
    /* Alarm Time Settings : Time = 0sec */
    RTC_AlarmStruct->AlarmTime = 0U;
}

/**
  * @brief  Enters the RTC Initialization mode.
  * @note   The RTC Initialization mode is write protected, use the
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC is in Init mode
  *          - ERROR: RTC is not in Init mode
  */
ErrorStatus DDL_RTC_EnterInitMode(RTC_TypeDef* RTCx)
{
    __IO uint32_t timeout = RTC_INITMODE_TIMEOUT;
    ErrorStatus status = SUCCESS;
    uint32_t tmp = 0U;

    /* Check the parameter */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Check if the Initialization mode is set */
    if (DDL_RTC_IsActiveFlag_CFGM(RTCx) == 0U)
    {
        /* Set the Initialization mode */
        DDL_RTC_EnableInitMode(RTCx);

        /* Wait till RTC is in INIT state and if Time out is reached exit */
        tmp = DDL_RTC_IsActiveFlag_CFGM(RTCx);
        while ((timeout != 0U) && (tmp != 1U))
        {
            timeout--;
            tmp = DDL_RTC_IsActiveFlag_CFGM(RTCx);
            if (timeout == 0U)
            {
                status = ERROR;
            }
        }
    }
    return status;
}

/**
  * @brief  Exit the RTC Initialization mode.
  * @note   When the initialization sequence is complete, the calendar restarts
  *         counting after 4 RTCCLK cycles.
  * @note   The RTC Initialization mode is write protected, use the
  *         @ref DDL_RTC_DisableWriteProtection before calling this function.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC exited from in Init mode
  *          - ERROR: Not applicable
  */
ErrorStatus DDL_RTC_ExitInitMode(RTC_TypeDef* RTCx)
{
    /* Check the parameter */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Disable initialization mode */
    DDL_RTC_DisableInitMode(RTCx);

    return SUCCESS;
}

/**
  * @brief  Waits until the RTC registers (RTC_CNT, RTC_ALR, RTC_PSCRLD) are
  *         synchronized with RTC APB clock.
  * @note   After APB clock reset or stop, this bit must be cleared by software
  *         and user program must wait until it is set by hardware before reading
  *         RTC_CNT, RTC_PSCRLD, RTC_ALR registers.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are synchronized
  *          - ERROR: Timeout occurred, RTC registers are not synchronized
  */
ErrorStatus DDL_RTC_WaitForSynchro(RTC_TypeDef* RTCx)
{
    __IO uint32_t timeout = RTC_SYNCHRO_TIMEOUT;
    ErrorStatus status = SUCCESS;
    uint32_t tmp = 0U;

    /* Check the parameter */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Clear RSF flag */
    DDL_RTC_ClearFlag_RS(RTCx);

    /* Wait the registers to be synchronised */
    tmp = DDL_RTC_IsActiveFlag_RS(RTCx);
    while ((timeout != 0U) && (tmp != 1U))
    {
        timeout--;
        tmp = DDL_RTC_IsActiveFlag_RS(RTCx);
        if (timeout == 0U)
        {
            status = ERROR;
        }
    }

    return (status);
}

/**
  * @brief  Waits until the RTC operation is completed.
  * @note   This function waits until the OCFLG (Operation Complete Flag) is set,
  *         which indicates that the previous write operation to RTC registers
  *         has been completed and a new write operation can be performed.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC operation is completed
  *          - ERROR: Timeout occurred, RTC operation is not completed
  */
ErrorStatus DDL_RTC_WaitForOperationComplete(RTC_TypeDef* RTCx)
{
    __IO uint32_t timeout = RTC_INITMODE_TIMEOUT;
    ErrorStatus status = SUCCESS;
    uint32_t tmp = 0U;

    /* Check the parameter */
    ASSERT_PARAM(IS_RTC_ALL_INSTANCE(RTCx));

    /* Clear RSF flag */
    DDL_RTC_ClearFlag_RS(RTCx);

    /* Wait for the operation to be completed */
    tmp = DDL_RTC_IsActiveFlag_OCFLG(RTCx);
    while ((timeout != 0U) && (tmp != 1U))
    {
        timeout--;
        tmp = DDL_RTC_IsActiveFlag_OCFLG(RTCx);
        if (timeout == 0U)
        {
            status = ERROR;
        }
    }

    return (status);
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

#endif /* defined(RTC) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
