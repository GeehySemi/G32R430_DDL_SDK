/**
  *
  * @file    g32r4xx_ddl_dac.c
  * @brief   DAC DDL module driver
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
  *
  */

#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_dac.h"
#include "g32r4xx_ddl_rcm.h"

#if (USE_FULL_ASSERT == 1U)
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_)                         ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(DAC1) || defined(DAC2)

/** @addtogroup DDL_DAC DAC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup DDL_DAC_Private_Macros
  * @{
  */

#define IS_DDL_DAC_TRIGGER_SOURCE(__TRIGGER_SOURCE__)                                 \
  (   ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE )                 \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_TMR1)                      \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_TMR2)                      \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_TMR3)                      \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_TMR4)                      \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE0)                \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE2)                \
   || ((__TRIGGER_SOURCE__) == DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE11)               \
  )

#define IS_DDL_DAC_WAVE_AUTO_GENER_MODE(__WAVE_AUTO_GENERATION_MODE__)       \
  (   ((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_NONE)        \
      || ((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_NOISE)    \
      || ((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_TRIANGLE) \
      || ((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_SAWTOOTH) \
  )

#define IS_DDL_DAC_WAVE_AUTO_GENER_CONFIG(__WAVE_AUTO_GENERATION_MODE__, __WAVE_AUTO_GENERATION_CONFIG__)  \
  ( (((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_NOISE)                               \
     && (  ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_0_0)                           \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_1_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_2_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_3_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_4_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_5_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_6_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_7_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_8_0)                     \
           || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_NONE_MASK_LFSR_9_0))                   \
    )                                                                                                     \
    ||(((__WAVE_AUTO_GENERATION_MODE__) == DDL_DAC_WAVE_GENERATE_TRIANGLE)                          \
       && (  ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_1)                           \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_3)                        \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_7)                        \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_15)                       \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_31)                       \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_63)                       \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_127)                      \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_255)                      \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_511)                      \
             || ((__WAVE_AUTO_GENERATION_CONFIG__) == DDL_DAC_TRI_WAVE_AMPLITUDE_1023))                    \
      )                                                                                                   \
  )

#define IS_DDL_DAC_OUTPUT_BUFFER(__OUTPUT_BUFFER__)                             \
  (   ((__OUTPUT_BUFFER__) == DDL_DAC_OUTPUT_BUFFER_INTERNAL)                     \
      || ((__OUTPUT_BUFFER__) == DDL_DAC_OUTPUT_BUFFER_EXTERNAL)                 \
  )

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup DDL_DAC_Exported_Functions
  * @{
  */

/** @addtogroup DDL_DAC_EF_Init
  * @{
  */

/**
  * @brief  De-initialize registers of the selected DAC instance
  *         to their default reset values.
  * @param  DACx DAC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus DDL_DAC_DeInit(DAC_TypeDef *DACx)
{
  /* Check the parameters */
  ASSERT_PARAM(IS_DAC_ALL_INSTANCE(DACx));

  DDL_RCM_Unlock();

  if (DACx == DAC1)
  {
    /* Force reset of DAC clock */
    DDL_RCM_EnableAPBReset(DDL_RCM_APB_RESET_DAC1);

    /* Release reset of DAC clock */
    DDL_RCM_DisableAPBReset(DDL_RCM_APB_RESET_DAC1);
  }

  if (DACx == DAC2)
  {
    /* Force reset of DAC clock */
    DDL_RCM_EnableAPBReset(DDL_RCM_APB_RESET_DAC2);

    /* Release reset of DAC clock */
    DDL_RCM_DisableAPBReset(DDL_RCM_APB_RESET_DAC2);
  }

  return SUCCESS;
}

/**
  * @brief  Initialize some features of DAC channel.
  *         or one of the supported autogenerated wave.
  * @note   This function allows configuration of:
  *          - Output mode
  *          - Trigger
  *          - Wave generation
  * @note   The setting of these parameters by function @ref DDL_DAC_Init()
  *         is conditioned to DAC state:
  *         DAC channel must be disabled.
  * @param  DACx DAC instance
  * @param  DAC_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_DAC_CHANNEL_1
  *
  * @param  DAC_InitStruct Pointer to a @ref DDL_DAC_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are initialized
  *          - ERROR: DAC registers are not initialized
  */
ErrorStatus DDL_DAC_Init(DAC_TypeDef *DACx, DDL_DAC_InitTypeDef *DAC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_DAC_ALL_INSTANCE(DACx));
  ASSERT_PARAM(IS_DDL_DAC_TRIGGER_SOURCE(DAC_InitStruct->TriggerSource));
  ASSERT_PARAM(IS_DDL_DAC_OUTPUT_BUFFER(DAC_InitStruct->OutputBuffer));
  ASSERT_PARAM(IS_DDL_DAC_WAVE_AUTO_GENER_MODE(DAC_InitStruct->WaveAutoGeneration));
  if (DAC_InitStruct->WaveAutoGeneration != DDL_DAC_WAVE_GENERATE_NONE)
  {
    ASSERT_PARAM(IS_DDL_DAC_WAVE_AUTO_GENER_CONFIG(DAC_InitStruct->WaveAutoGeneration,
                                                  DAC_InitStruct->WaveAutoGenerationConfig));
  }

  /* Note: Hardware constraint (refer to description of this function)        */
  /*       DAC instance must be disabled.                                     */
  if (DDL_DAC_IsEnabled(DACx) == 0UL)
  {
    /* Configuration of DAC channel:                                          */
    /*  - TriggerSource                                                       */
    /*  - WaveAutoGeneration                                                  */
    /*  - OutputBuffer                                                        */
    /*  - OutputMode                                                          */
    if (DAC_InitStruct->WaveAutoGeneration != DDL_DAC_WAVE_GENERATE_NONE)
    {
      MODIFY_REG(DACx->CR,
                 (DAC_CR_TSEL
                  | DAC_CR_WAVE
                  | DAC_CR_MAMP
                  | DAC_CR_EXT_SEL
                 )
                 ,
                 (DAC_InitStruct->TriggerSource
                  | DAC_InitStruct->WaveAutoGeneration
                  | DAC_InitStruct->WaveAutoGenerationConfig
                  | DAC_InitStruct->OutputBuffer
                 )
                );
    }
    else
    {
      MODIFY_REG(DACx->CR,
                 (DAC_CR_TSEL
                  | DAC_CR_WAVE
                  | DAC_CR_EXT_SEL
                 )
                 ,
                 (DAC_InitStruct->TriggerSource
                  | DDL_DAC_WAVE_GENERATE_NONE
                  | DAC_InitStruct->OutputBuffer
                 )
                );
    }
  }
  else
  {
    /* Initialization error: DAC instance is not disabled.                    */
    status = ERROR;
  }
  return status;
}

/**
  * @brief Set each @ref DDL_DAC_InitTypeDef field to default value.
  * @param DAC_InitStruct pointer to a @ref DDL_DAC_InitTypeDef structure
  *                       whose fields will be set to default values.
  * @retval None
  */
void DDL_DAC_StructInit(DDL_DAC_InitTypeDef *DAC_InitStruct)
{
  /* Set DAC_InitStruct fields to default values */
  DAC_InitStruct->TriggerSource            = DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE;
  DAC_InitStruct->WaveAutoGeneration       = DDL_DAC_WAVE_GENERATE_NONE;
  /* Note: Parameter discarded if wave auto generation is disabled,           */
  /*       set anyway to its default value.                                   */
  DAC_InitStruct->WaveAutoGenerationConfig = DDL_DAC_NONE_MASK_LFSR_0_0;
  DAC_InitStruct->OutputBuffer             = DDL_DAC_OUTPUT_BUFFER_EXTERNAL;
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

#endif /* DAC1 || DAC2 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

