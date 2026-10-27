/**
  *
  * @file    g32r4xx_ddl_adc12.c
  * @brief   ADC DDL module driver
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
  ******************************************************************************
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_adc12.h"
#include "g32r4xx_ddl_rcm.h"

#ifdef  USE_FULL_ASSERT
  #include "g32_assert.h"
#else
  #define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (ADC3)

/** @addtogroup ADC_DDL ADC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup ADC_DDL_Private_Macros
  * @{
  */

/** @addtogroup ADC_LL_Private_Constants
  * @{
  */

/* Definitions of ADC hardware constraints delays */
/* Note: Only ADC peripheral HW delays are defined in ADC LL driver driver,   */
/*       not timeout values:                                                  */
/*       Timeout values for ADC operations are dependent to device clock      */
/*       configuration (system clock versus ADC clock),                       */
/*       and therefore must be defined in user application.                   */
/*       Refer to @ref ADC_LL_EC_HW_DELAYS for description of ADC timeout     */
/*       values definition.                                                   */
/* Note: ADC timeout values are defined here in CPU cycles to be independent  */
/*       of device clock setting.                                             */
/*       In user application, ADC timeout values should be defined with       */
/*       temporal values, in function of device clock settings.               */
/*       Highest ratio CPU clock frequency vs ADC clock frequency:            */
/*        - ADC clock from synchronous clock with AHB prescaler 512,          */
/*          ADC prescaler 4.                                                  */
/*           Ratio max = 512 *4 = 2048                                        */
/*        - ADC clock from asynchronous clock (PLLP) with prescaler 256.      */
/*          Highest CPU clock PLL (PLLR).                                     */
/*           Ratio max = PLLRmax /PPLPmin * 256 = (VCO/2) / (VCO/31) * 256    */
/*                     = 3968                                                 */
/* Unit: CPU cycles.                                                          */
#define ADC12_CLOCK_RATIO_VS_CPU_HIGHEST          (3968UL)
#define ADC12_TIMEOUT_DISABLE_CPU_CYCLES          (ADC12_CLOCK_RATIO_VS_CPU_HIGHEST * 1UL)
#define ADC12_TIMEOUT_STOP_CONVERSION_CPU_CYCLES  (ADC12_CLOCK_RATIO_VS_CPU_HIGHEST * 1UL)

#define IS_DDL_ADC12_REG_TRIG_SOURCE(__ADC12_INSTANCE__, __REG_TRIG_SOURCE__)       \
  (((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_SOFTWARE)                         \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR1_CC1)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR1_CC2)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR1_CC3)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR2_CC2)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR3_TRGO)                 \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_TMR4_CC4)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC12_REG_TRIG_EXT_EINT_LINE11)               \
   )

#define IS_DDL_ADC12_REG_SEQ_SCAN_LENGTH(__REG_SEQ_SCAN_LENGTH__)                 \
  (((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_DISABLE)                  \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_2RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_3RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_4RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_5RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_6RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_7RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_8RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_9RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_10RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_11RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_12RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_13RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC12_REG_SEQ_SCAN_ENABLE_14RANKS)        \
  )

#define IS_DDL_ADC12_REG_SEQ_SCAN_DISCONT_MODE(__REG_SEQ_DISCONT_MODE__)          \
  (((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_DISABLE)              \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_1RANK)             \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_2RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_3RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_4RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_5RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_6RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_7RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC12_REG_SEQ_DISCONT_8RANKS)            \
  )

#define IS_DDL_ADC12_REG_CONTINUOUS_MODE(__REG_CONTINUOUS_MODE__)                 \
  (((__REG_CONTINUOUS_MODE__) == DDL_ADC12_REG_CONV_SINGLE)                       \
   || ((__REG_CONTINUOUS_MODE__) == DDL_ADC12_REG_CONV_CONTINUOUS)                \
  )

#define IS_DDL_ADC12_REG_DMA_TRANSFER(__REG_DMA_TRANSFER__)                       \
  (((__REG_DMA_TRANSFER__) == DDL_ADC12_REG_DMA_TRANSFER_DISABLE)                    \
   || ((__REG_DMA_TRANSFER__) == DDL_ADC12_REG_DMA_TRANSFER_ENABLE)              \
  )

#define IS_DDL_ADC12_INJ_TRIG_SOURCE(__ADC12_INSTANCE__, __INJ_TRIG_SOURCE__)       \
  (((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_SOFTWARE)                         \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR1_TRGO)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR1_CC4)                \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR2_TRGO)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR2_CC1)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR3_CC4)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_TMR4_TRGO)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC12_INJ_TRIG_EXT_EINT_LINE15)                  \
  )

#define IS_DDL_ADC12_INJ_TRIG_EXT_EDGE(__INJ_TRIG_EXT_EDGE__)                     \
  (((__INJ_TRIG_EXT_EDGE__) == DDL_ADC12_INJ_TRIG_EXT_RISING)                     \
   || ((__INJ_TRIG_EXT_EDGE__) == DDL_ADC12_INJ_TRIG_EXT_DISABLE)                 \
  )

#define IS_DDL_ADC12_INJ_TRIG_AUTO(__INJ_TRIG_AUTO__)                             \
  (((__INJ_TRIG_AUTO__) == DDL_ADC12_INJ_TRIG_INDEPENDENT)                        \
   || ((__INJ_TRIG_AUTO__) == DDL_ADC12_INJ_TRIG_FROM_GRP_REGULAR)                \
  )

#define IS_DDL_ADC12_INJ_SEQ_SCAN_LENGTH(__INJ_SEQ_SCAN_LENGTH__)                 \
  (((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC12_INJ_SEQ_SCAN_DISABLE)                  \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC12_INJ_SEQ_SCAN_ENABLE_2RANKS)         \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC12_INJ_SEQ_SCAN_ENABLE_3RANKS)         \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC12_INJ_SEQ_SCAN_ENABLE_4RANKS)         \
  )

#define IS_DDL_ADC12_INJ_SEQ_SCAN_DISCONT_MODE(__INJ_SEQ_DISCONT_MODE__)          \
  (((__INJ_SEQ_DISCONT_MODE__) == DDL_ADC12_INJ_SEQ_DISCONT_DISABLE)              \
   || ((__INJ_SEQ_DISCONT_MODE__) == DDL_ADC12_INJ_SEQ_DISCONT_1RANK)             \
  )

#define IS_DDL_ADC12_CHANNEL(__CHANNEL__)                 \
  (((__CHANNEL__) == DDL_ADC12_CHANNEL_0)              \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_1)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_2)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_3)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_4)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_5)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_6)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_7)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_8)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_9)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_10)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_11)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_12)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_13)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_14)             \
  || ((__CHANNEL__) == DDL_ADC12_CHANNEL_15)             \
  )

/**
  * @}
  */


/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC12_DDL_Exported_Functions
  * @{
  */

/** @addtogroup ADC12_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize registers of the selected ADC instance
  *         to their default reset values.
  * @note   To reset all ADC instances quickly (perform a hard reset),
  *         use function @ref DDL_ADC12_CommonDeInit().
  * @param  ADCx ADC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are de-initialized
  *          - ERROR: ADC registers are not de-initialized
  */
ErrorStatus DDL_ADC12_DeInit(ADC12_TypeDef *ADCx)
{
  ErrorStatus status = SUCCESS;

  __IO uint32_t timeout_cpu_cycles = 0UL;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC12_ALL_INSTANCE(ADCx));

  /* Disable ADC instance if not already disabled.                            */
  if (DDL_ADC12_IsEnabled(ADCx) == 1UL)
  {
    /* Set ADC group regular trigger source to SW start to ensure to not      */
    /* have an external trigger event occurring during the conversion stop    */
    /* ADC disable process.                                                   */
    DDL_ADC12_REG_SetTriggerSource(ADCx, DDL_ADC12_REG_TRIG_SOFTWARE);

    /* Stop potential ADC conversion on going on ADC group regular.           */
    if (DDL_ADC12_REG_IsConversionOngoing(ADCx) != 0UL)
    {
      if (DDL_ADC12_REG_IsStopConversionOngoing(ADCx) == 0UL)
      {
        DDL_ADC12_REG_StopConversion(ADCx);
      }
    }

    /* Set ADC group injected trigger source to SW start to ensure to not     */
    /* have an external trigger event occurring during the conversion stop    */
    /* ADC disable process.                                                   */
    DDL_ADC12_INJ_SetTriggerSource(ADCx, DDL_ADC12_INJ_TRIG_SOFTWARE);

    /* Stop potential ADC conversion on going on ADC group injected.          */
    if (DDL_ADC12_INJ_IsConversionOngoing(ADCx) != 0UL)
    {
      if (DDL_ADC12_INJ_IsStopConversionOngoing(ADCx) == 0UL)
      {
        DDL_ADC12_INJ_StopConversion(ADCx);
      }
    }

    /* Wait for ADC conversions are effectively stopped                       */
    timeout_cpu_cycles = ADC12_TIMEOUT_STOP_CONVERSION_CPU_CYCLES;
    while ((DDL_ADC12_REG_IsStopConversionOngoing(ADCx)
            | DDL_ADC12_INJ_IsStopConversionOngoing(ADCx)) == 1UL)
    {
      timeout_cpu_cycles--;
      if (timeout_cpu_cycles == 0UL)
      {
        /* Time-out error */
        status = ERROR;
        break;
      }
    }

    /* Disable the ADC instance */
    DDL_ADC12_Disable(ADCx);

  }

  /* Check whether ADC state is compliant with expected state */
  if (READ_BIT(ADCx->CR,
               (ADC_CR_JADSTP | ADC_CR_ADSTP | ADC_CR_JADSTART | ADC_CR_ADSTART
                | ADC_CR_ADEN)
              )
      == 0UL)
  {
    /* ========== Reset ADC registers ========== */
    /* Reset register IER */
    CLEAR_BIT(ADCx->IER,
              (  DDL_ADC12_IT_EOC
               | DDL_ADC12_IT_EOS
               | DDL_ADC12_IT_JEOC
               | DDL_ADC12_IT_JEOS
               | DDL_ADC12_IT_AWD1
              )
             );

    /* Reset register ISR */
    SET_BIT(ADCx->ISR,
            (  DDL_ADC12_FLAG_EOC
             | DDL_ADC12_FLAG_EOS
             | DDL_ADC12_FLAG_JEOC
             | DDL_ADC12_FLAG_JEOS
             | DDL_ADC12_FLAG_AWD1
            )
           );

    /* Reset register CR */
    /*  - Bits ADC_CR_JADSTP, ADC_CR_ADSTP, ADC_CR_JADSTART, ADC_CR_ADSTART,  */
    /*    ADC_CR_ADCAL, ADC_CR_ADDIS, ADC_CR_ADEN are in                      */
    /*    access mode "read-set": no direct reset applicable.                 */
    /*  - Reset Calibration mode to default setting (single ended).           */
    /*  - Disable ADC internal voltage regulator.                             */
    /*  - Enable ADC deep power down.                                         */
    /*    Note: ADC internal voltage regulator disable and ADC deep power     */
    /*          down enable are conditioned to ADC state disabled:            */
    /*          already done above.                                           */

    /* Reset register CFGR */
    MODIFY_REG(ADCx->CFGR,
               (  ADC_CFGR_AWD1CH  | ADC_CFGR_JAUTO   | ADC_CFGR_JAWD1EN
                | ADC_CFGR_AWD1EN  | ADC_CFGR_AWD1SGL
                | ADC_CFGR_JDISCEN | ADC_CFGR_DISCNUM | ADC_CFGR_DISCEN
                | ADC_CFGR_CONT
                | ADC_CFGR_EXTEN   | ADC_CFGR_EXTSEL  | ADC_CFGR_ALIGN
                | ADC_CFGR_DMAEN),
               0x00000000UL
              );

    /* Reset register SMPR1 */
    CLEAR_BIT(ADCx->SMPR1,
              (  ADC_SMPR1_SMP7 | ADC_SMPR1_SMP6
               | ADC_SMPR1_SMP5 | ADC_SMPR1_SMP4 | ADC_SMPR1_SMP3
               | ADC_SMPR1_SMP2 | ADC_SMPR1_SMP1 | ADC_SMPR1_SMP0)
             );

    /* Reset register SMPR2 */
    CLEAR_BIT(ADCx->SMPR2,
              (  ADC_SMPR2_SMP15 | ADC_SMPR2_SMP14
               | ADC_SMPR2_SMP13 | ADC_SMPR2_SMP12 | ADC_SMPR2_SMP11
               | ADC_SMPR2_SMP10 | ADC_SMPR2_SMP9 | ADC_SMPR2_SMP8)
             );

    /* Reset register TR1 */
    MODIFY_REG(ADCx->TR1, ADC_TR1_HT1 | ADC_TR1_LT1, ADC_TR1_HT1);

    /* Reset register SQR1 */
    CLEAR_BIT(ADCx->SQR1,
              (  ADC_SQR1_SQ7 | ADC_SQR1_SQ6 | ADC_SQR1_SQ5
               | ADC_SQR1_SQ4 | ADC_SQR1_SQ3 | ADC_SQR1_SQ2
               | ADC_SQR1_SQ1 | ADC_SQR1_RL)
             );

    /* Reset register SQR2 */
    CLEAR_BIT(ADCx->SQR2,
              (  ADC_SQR2_SQ14 | ADC_SQR2_SQ13
               | ADC_SQR2_SQ12 | ADC_SQR2_SQ11 | ADC_SQR2_SQ10
               | ADC_SQR2_SQ9 | ADC_SQR2_SQ8)
             );

    CLEAR_BIT(ADCx->SQR3,
              (  ADC_SQR3_SQ16 | ADC_SQR3_SQ15) );

    /* Reset register JSQR */
    CLEAR_BIT(ADCx->JSQR,
              (ADC_JSQR_JL
               | ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN
               | ADC_JSQR_JSQ4    | ADC_JSQR_JSQ3
               | ADC_JSQR_JSQ2    | ADC_JSQR_JSQ1)
             );

    /* Reset register DR */
    /* Note: bits in access mode read only, no direct reset applicable */

    /* Reset register OFR1 */
    CLEAR_BIT(ADCx->JOFFSET1, ADC_JOFFSET1_JOFFSET1);
    /* Reset register OFR2 */
    CLEAR_BIT(ADCx->JOFFSET2, ADC_JOFFSET2_JOFFSET2);
    /* Reset register OFR3 */
    CLEAR_BIT(ADCx->JOFFSET3, ADC_JOFFSET3_JOFFSET3);
    /* Reset register OFR4 */
    CLEAR_BIT(ADCx->JOFFSET4, ADC_JOFFSET4_JOFFSET4);

    /* Reset registers JDR1, JDR2, JDR3, JDR4 */
    /* Note: bits in access mode read only, no direct reset applicable */
  }
  else
  {
    /* ADC instance is in an unknown state */
    /* Need to performing a hard reset of ADC instance, using high level      */
    /* clock source RCM ADC reset.                                            */
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Initialize some features of ADC instance.
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on G32 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC12_DDL_EF_Configuration_ADC12_Instance .
  * @note   The setting of these parameters by function @ref DDL_ADC12_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  * @note   After using this function, some other features must be configured
  *         using DDL unitary functions.
  *         The minimum configuration remaining to be done is:
  *          - Set ADC group regular or group injected sequencer:
  *            map channel on the selected sequencer rank.
  *            Refer to function @ref DDL_ADC12_REG_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC12_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_InitStruct Pointer to a @ref DDL_ADC12_REG_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC12_Init(ADC12_TypeDef *ADCx, DDL_ADC12_InitTypeDef *ADC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC12_ALL_INSTANCE(ADCx));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC12_IsEnabled(ADCx) == 0UL)
  {
    /* Configuration of ADC hierarchical scope:                               */
    /*  - ADC instance                                                        */
    /*    - Set ADC low power mode                                            */
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_ALIGN, ADC_InitStruct->DataAlignment);

  }
  else
  {
    /* Initialization error: ADC instance is not disabled. */
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Set each @ref DDL_ADC12_InitTypeDef field to default value.
  * @param  ADC_InitStruct Pointer to a @ref DDL_ADC12_InitTypeDef structure
  *                        whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC12_StructInit(DDL_ADC12_InitTypeDef *ADC_InitStruct)
{
  /* Set ADC_InitStruct fields to default values */
  /* Set fields of ADC instance */
  ADC_InitStruct->DataAlignment = DDL_ADC12_ALIGNMENT_RIGHT;
}

/**
  * @brief  Initialize some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC12_DDL_EF_Configuration_ADC12_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref DDL_ADC12_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  * @note   After using this function, other features must be configured
  *         using DDL unitary functions.
  *         The minimum configuration remaining to be done is:
  *          - Set ADC group regular or group injected sequencer:
  *            map channel on the selected sequencer rank.
  *            Refer to function @ref DDL_ADC12_REG_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC12_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_REG_InitStruct Pointer to a @ref DDL_ADC12_REG_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC12_REG_Init(ADC12_TypeDef *ADCx, DDL_ADC12_REG_InitTypeDef *ADC_REG_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC12_ALL_INSTANCE(ADCx));
  ASSERT_PARAM(IS_DDL_ADC12_REG_TRIG_SOURCE(ADCx, ADC_REG_InitStruct->TriggerSource));
  ASSERT_PARAM(IS_DDL_ADC12_REG_SEQ_SCAN_LENGTH(ADC_REG_InitStruct->SequencerLength));
  if (ADC_REG_InitStruct->SequencerLength != DDL_ADC12_REG_SEQ_SCAN_DISABLE)
  {
    ASSERT_PARAM(IS_DDL_ADC12_REG_SEQ_SCAN_DISCONT_MODE(ADC_REG_InitStruct->SequencerDiscont));

    /* ADC group regular continuous mode and discontinuous mode                 */
    /* can not be enabled simultenaeously                                       */
    ASSERT_PARAM((ADC_REG_InitStruct->ContinuousMode == DDL_ADC12_REG_CONV_SINGLE)
                 || (ADC_REG_InitStruct->SequencerDiscont == DDL_ADC12_REG_SEQ_DISCONT_DISABLE));
  }
  ASSERT_PARAM(IS_DDL_ADC12_REG_CONTINUOUS_MODE(ADC_REG_InitStruct->ContinuousMode));
  ASSERT_PARAM(IS_DDL_ADC12_REG_DMA_TRANSFER(ADC_REG_InitStruct->DMATransfer));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC12_IsEnabled(ADCx) == 0UL)
  {
    /* Configuration of ADC hierarchical scope:                               */
    /*  - ADC group regular                                                   */
    /*    - Set ADC group regular trigger source                              */
    /*    - Set ADC group regular sequencer length                            */
    /*    - Set ADC group regular sequencer discontinuous mode                */
    /*    - Set ADC group regular continuous mode                             */
    /*    - Set ADC group regular conversion data transfer: no transfer or    */
    /*      transfer by DMA, and DMA requests mode                            */
    /*    - Set ADC group regular overrun behavior                            */
    /* Note: On this G32R4 series, ADC trigger edge is set to value 0x0 by    */
    /*       setting of trigger source to SW start.                           */
    if (ADC_REG_InitStruct->SequencerLength != DDL_ADC12_REG_SEQ_SCAN_DISABLE)
    {
      MODIFY_REG(ADCx->CFGR,
                 ADC_CFGR_EXTSEL
                 | ADC_CFGR_EXTEN
                 | ADC_CFGR_DISCEN
                 | ADC_CFGR_DISCNUM
                 | ADC_CFGR_CONT
                 | ADC_CFGR_DMAEN
                 ,
                 ADC_REG_InitStruct->TriggerSource
                 | ADC_REG_InitStruct->SequencerDiscont
                 | ADC_REG_InitStruct->ContinuousMode
                 | ADC_REG_InitStruct->DMATransfer
                );
    }
    else
    {
      MODIFY_REG(ADCx->CFGR,
                 ADC_CFGR_EXTSEL
                 | ADC_CFGR_EXTEN
                 | ADC_CFGR_DISCEN
                 | ADC_CFGR_DISCNUM
                 | ADC_CFGR_CONT
                 | ADC_CFGR_DMAEN
                 ,
                 ADC_REG_InitStruct->TriggerSource
                 | DDL_ADC12_REG_SEQ_DISCONT_DISABLE
                 | ADC_REG_InitStruct->ContinuousMode
                 | ADC_REG_InitStruct->DMATransfer
                );
    }

    /* Set ADC group regular sequencer length and scan direction */
    DDL_ADC12_REG_SetSequencerLength(ADCx, ADC_REG_InitStruct->SequencerLength);
  }
  else
  {
    /* Initialization error: ADC instance is not disabled. */
    status = ERROR;
  }
  return status;
}

/**
  * @brief  Set each @ref DDL_ADC12_REG_InitTypeDef field to default value.
  * @param  ADC_REG_InitStruct Pointer to a @ref DDL_ADC12_REG_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC12_REG_StructInit(DDL_ADC12_REG_InitTypeDef *ADC_REG_InitStruct)
{
  /* Set ADC_REG_InitStruct fields to default values */
  /* Set fields of ADC group regular */
  /* Note: On this G32R4 series, ADC trigger edge is set to value 0x0 by      */
  /*       setting of trigger source to SW start.                             */
  ADC_REG_InitStruct->TriggerSource    = DDL_ADC12_REG_TRIG_SOFTWARE;
  ADC_REG_InitStruct->SequencerLength  = DDL_ADC12_REG_SEQ_SCAN_DISABLE;
  ADC_REG_InitStruct->SequencerDiscont = DDL_ADC12_REG_SEQ_DISCONT_DISABLE;
  ADC_REG_InitStruct->ContinuousMode   = DDL_ADC12_REG_CONV_SINGLE;
  ADC_REG_InitStruct->DMATransfer      = DDL_ADC12_REG_DMA_TRANSFER_DISABLE;
}

/**
  * @brief  Initialize some features of ADC group injected.
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         Refer to corresponding unitary functions into
  *         @ref ADC12_DDL_EF_Configuration_ADC12_Group_Regular
  *         (functions with prefix "INJ").
  * @note   The setting of these parameters by function @ref DDL_ADC12_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  * @note   After using this function, other features must be configured
  *         using DDL unitary functions.
  *         The minimum configuration remaining to be done is:
  *          - Set ADC group injected sequencer:
  *            map channel on the selected sequencer rank.
  *            Refer to function @ref DDL_ADC12_INJ_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC12_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_INJ_InitStruct Pointer to a @ref DDL_ADC12_INJ_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC12_INJ_Init(ADC12_TypeDef *ADCx, DDL_ADC12_INJ_InitTypeDef *ADC_INJ_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC12_ALL_INSTANCE(ADCx));
  ASSERT_PARAM(IS_DDL_ADC12_INJ_TRIG_SOURCE(ADCx, ADC_INJ_InitStruct->TriggerSource));
  ASSERT_PARAM(IS_DDL_ADC12_INJ_SEQ_SCAN_LENGTH(ADC_INJ_InitStruct->SequencerLength));
  if (ADC_INJ_InitStruct->SequencerLength != DDL_ADC12_INJ_SEQ_SCAN_DISABLE)
  {
    ASSERT_PARAM(IS_DDL_ADC12_INJ_SEQ_SCAN_DISCONT_MODE(ADC_INJ_InitStruct->SequencerDiscont));
  }
  ASSERT_PARAM(IS_DDL_ADC12_INJ_TRIG_AUTO(ADC_INJ_InitStruct->TrigAuto));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC12_IsEnabled(ADCx) == 0UL)
  {
    /* Configuration of ADC hierarchical scope:                               */
    /*  - ADC group injected                                                  */
    /*    - Set ADC group injected trigger source                             */
    /*    - Set ADC group injected sequencer length                           */
    /*    - Set ADC group injected sequencer discontinuous mode               */
    /*    - Set ADC group injected conversion trigger: independent or         */
    /*      from ADC group regular                                            */
    /* Note: On this G32R4 series, ADC trigger edge is set to value 0x0 by    */
    /*       setting of trigger source to SW start.                           */
    if (ADC_INJ_InitStruct->SequencerLength != DDL_ADC12_REG_SEQ_SCAN_DISABLE)
    {
      MODIFY_REG(ADCx->CFGR,
                 ADC_CFGR_JDISCEN
                 | ADC_CFGR_JAUTO
                 ,
                 ADC_INJ_InitStruct->SequencerDiscont
                 | ADC_INJ_InitStruct->TrigAuto
                );
    }
    else
    {
      MODIFY_REG(ADCx->CFGR,
                 ADC_CFGR_JDISCEN
                 | ADC_CFGR_JAUTO
                 ,
                 DDL_ADC12_REG_SEQ_DISCONT_DISABLE
                 | ADC_INJ_InitStruct->TrigAuto
                );
    }

    MODIFY_REG(ADCx->JSQR,
               ADC_JSQR_JEXTSEL
               | ADC_JSQR_JEXTEN
               | ADC_JSQR_JL
               ,
               ADC_INJ_InitStruct->TriggerSource
               | ADC_INJ_InitStruct->SequencerLength
              );
  }
  else
  {
    /* Initialization error: ADC instance is not disabled. */
    status = ERROR;
  }
  return status;
}

/**
  * @brief  Set each @ref DDL_ADC12_INJ_InitTypeDef field to default value.
  * @param  ADC_INJ_InitStruct Pointer to a @ref DDL_ADC12_INJ_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC12_INJ_StructInit(DDL_ADC12_INJ_InitTypeDef *ADC_INJ_InitStruct)
{
  /* Set ADC_INJ_InitStruct fields to default values */
  /* Set fields of ADC group injected */
  ADC_INJ_InitStruct->TriggerSource    = DDL_ADC12_INJ_TRIG_SOFTWARE;
  ADC_INJ_InitStruct->SequencerLength  = DDL_ADC12_INJ_SEQ_SCAN_DISABLE;
  ADC_INJ_InitStruct->SequencerDiscont = DDL_ADC12_INJ_SEQ_DISCONT_DISABLE;
  ADC_INJ_InitStruct->TrigAuto         = DDL_ADC12_INJ_TRIG_INDEPENDENT;
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

#endif /* ADC3 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

