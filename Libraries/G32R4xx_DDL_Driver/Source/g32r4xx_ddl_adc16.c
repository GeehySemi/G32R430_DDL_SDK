/**
  *
  * @file    g32r4xx_ddl_adc16.c
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
#include "g32r4xx_ddl_adc16.h"
#include "g32r4xx_ddl_rcm.h"
#include "g32r4xx_ddl_flash.h"

#ifdef  USE_FULL_ASSERT
  #include "g32_assert.h"
#else
  #define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (ADC1) || defined (ADC2)

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
#define ADC_CLOCK_RATIO_VS_CPU_HIGHEST          (3968UL)
#define ADC_TIMEOUT_DISABLE_CPU_CYCLES          (ADC_CLOCK_RATIO_VS_CPU_HIGHEST * 1UL)
#define ADC_TIMEOUT_STOP_CONVERSION_CPU_CYCLES  (ADC_CLOCK_RATIO_VS_CPU_HIGHEST * 1UL)

#define IS_DDL_ADC16_LOW_POWER(__LOW_POWER__)                                     \
  (((__LOW_POWER__) == DDL_ADC16_LP_MODE_NONE)                                    \
   || ((__LOW_POWER__) == DDL_ADC16_LP_AUTOWAIT)                                  \
  )

#define IS_DDL_ADC16_REG_TRIG_SOURCE(__ADC_INSTANCE__, __REG_TRIG_SOURCE__)       \
  (((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_SOFTWARE)                         \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR1_CC1)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR1_CC2)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR1_CC3)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR2_CC2)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR3_TRGO)                 \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR4_CC4)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_EINT_LINE11)               \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR1_TRGO)                 \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO)                 \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR4_TRGO)                 \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_TMR3_CC4)                  \
   || ((__REG_TRIG_SOURCE__) == DDL_ADC16_REG_TRIG_EXT_LPTMROUT)                  \
   )

#define IS_DDL_ADC16_REG_SEQ_SCAN_LENGTH(__REG_SEQ_SCAN_LENGTH__)                 \
  (((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_DISABLE)                  \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_2RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_3RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_4RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_5RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_6RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_7RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_8RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_9RANKS)         \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_10RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_11RANKS)        \
   || ((__REG_SEQ_SCAN_LENGTH__) == DDL_ADC16_REG_SEQ_SCAN_ENABLE_12RANKS)        \
  )

#define IS_DDL_ADC16_REG_SEQ_SCAN_DISCONT_MODE(__REG_SEQ_DISCONT_MODE__)          \
  (((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_DISABLE)              \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_1RANK)             \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_2RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_3RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_4RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_5RANKS)            \
   || ((__REG_SEQ_DISCONT_MODE__) == DDL_ADC16_REG_SEQ_DISCONT_6RANKS)            \
  )

#define IS_DDL_ADC16_REG_CONTINUOUS_MODE(__REG_CONTINUOUS_MODE__)                 \
  (((__REG_CONTINUOUS_MODE__) == DDL_ADC16_REG_CONV_SINGLE)                       \
   || ((__REG_CONTINUOUS_MODE__) == DDL_ADC16_REG_CONV_CONTINUOUS)                \
  )

#define IS_DDL_ADC16_REG_DMA_TRANSFER(__REG_DMA_TRANSFER__)                       \
  (((__REG_DMA_TRANSFER__) == DDL_ADC16_REG_DMA_TRANSFER_NONE)                    \
   || ((__REG_DMA_TRANSFER__) == DDL_ADC16_REG_DMA_TRANSFER_LIMITED)              \
   || ((__REG_DMA_TRANSFER__) == DDL_ADC16_REG_DMA_TRANSFER_UNLIMITED)            \
  )

#define IS_DDL_ADC16_REG_OVR_DATA_BEHAVIOR(__REG_OVR_DATA_BEHAVIOR__)             \
  (((__REG_OVR_DATA_BEHAVIOR__) == DDL_ADC16_REG_OVR_DATA_PRESERVED)              \
   || ((__REG_OVR_DATA_BEHAVIOR__) == DDL_ADC16_REG_OVR_DATA_OVERWRITTEN)         \
  )

#define IS_DDL_ADC16_INJ_TRIG_SOURCE(__ADC_INSTANCE__, __INJ_TRIG_SOURCE__)       \
  (((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_SOFTWARE)                         \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR1_TRGO)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR1_CC4)                \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR2_TRGO)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR2_CC4)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR4_TRGO)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_EINT_LINE15)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR3_CC3)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR3_TRGO)                  \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_TMR3_CC1)                 \
   || ((__INJ_TRIG_SOURCE__) == DDL_ADC16_INJ_TRIG_EXT_LPTMROUT)                 \
  )

#define IS_DDL_ADC16_INJ_TRIG_EXT_EDGE(__INJ_TRIG_EXT_EDGE__)                     \
  (((__INJ_TRIG_EXT_EDGE__) == DDL_ADC16_INJ_TRIG_EXT_RISING)                     \
   || ((__INJ_TRIG_EXT_EDGE__) == DDL_ADC16_INJ_TRIG_EXT_FALLING)                 \
   || ((__INJ_TRIG_EXT_EDGE__) == DDL_ADC16_INJ_TRIG_EXT_RISINGFALLING)           \
  )

#define IS_DDL_ADC16_INJ_TRIG_AUTO(__INJ_TRIG_AUTO__)                             \
  (((__INJ_TRIG_AUTO__) == DDL_ADC16_INJ_TRIG_INDEPENDENT)                        \
   || ((__INJ_TRIG_AUTO__) == DDL_ADC16_INJ_TRIG_FROM_GRP_REGULAR)                \
  )

#define IS_DDL_ADC16_INJ_SEQ_SCAN_LENGTH(__INJ_SEQ_SCAN_LENGTH__)                 \
  (((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC16_INJ_SEQ_SCAN_DISABLE)                  \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC16_INJ_SEQ_SCAN_ENABLE_2RANKS)         \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC16_INJ_SEQ_SCAN_ENABLE_3RANKS)         \
   || ((__INJ_SEQ_SCAN_LENGTH__) == DDL_ADC16_INJ_SEQ_SCAN_ENABLE_4RANKS)         \
  )

#define IS_DDL_ADC16_INJ_SEQ_SCAN_DISCONT_MODE(__INJ_SEQ_DISCONT_MODE__)          \
  (((__INJ_SEQ_DISCONT_MODE__) == DDL_ADC16_INJ_SEQ_DISCONT_DISABLE)              \
   || ((__INJ_SEQ_DISCONT_MODE__) == DDL_ADC16_INJ_SEQ_DISCONT_1RANK)             \
  )

#define IS_DDL_ADC16_SINGLE_DIFFERENTIAL(__SINGLE_DIFFERENTIAL__)                 \
  (((__SINGLE_DIFFERENTIAL__) == DDL_ADC16_SINGLE_ENDED)              \
   || ((__SINGLE_DIFFERENTIAL__) == DDL_ADC16_DIFFERENTIAL_ENDED)             \
  )

#define IS_DDL_ADC16_CHANNEL(__CHANNEL__)                 \
  (((__CHANNEL__) == DDL_ADC16_CHANNEL_0)              \
  || ((__CHANNEL__) == DDL_ADC16_CHANNEL_1)             \
  || ((__CHANNEL__) == DDL_ADC16_CHANNEL_2)             \
  || ((__CHANNEL__) == DDL_ADC16_CHANNEL_3)             \
  || ((__CHANNEL__) == DDL_ADC16_CHANNEL_4)             \
  || ((__CHANNEL__) == DDL_ADC16_CHANNEL_5)             \
  )

/**
  * @}
  */


/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_DDL_Exported_Functions
  * @{
  */

/** @addtogroup ADC_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize registers of the selected ADC instance
  *         to their default reset values.
  * @note   To reset all ADC instances quickly (perform a hard reset),
  *         use function @ref DDL_ADC16_CommonDeInit().
  * @param  ADCx ADC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are de-initialized
  *          - ERROR: ADC registers are not de-initialized
  */
ErrorStatus DDL_ADC16_DeInit(ADC16_TypeDef *ADCx)
{
  ErrorStatus status = SUCCESS;

  __IO uint32_t timeout_cpu_cycles = 0UL;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC16_ALL_INSTANCE(ADCx));

  /* Disable ADC instance if not already disabled.                            */
  if (DDL_ADC16_IsEnabled(ADCx) == 1UL)
  {
    /* Set ADC group regular trigger source to SW start to ensure to not      */
    /* have an external trigger event occurring during the conversion stop    */
    /* ADC disable process.                                                   */
    DDL_ADC16_REG_SetTriggerSource(ADCx, DDL_ADC16_REG_TRIG_SOFTWARE);

    /* Stop potential ADC conversion on going on ADC group regular.           */
    if (DDL_ADC16_REG_IsConversionOngoing(ADCx) != 0UL)
    {
      if (DDL_ADC16_REG_IsStopConversionOngoing(ADCx) == 0UL)
      {
        DDL_ADC16_REG_StopConversion(ADCx);
      }
    }

    /* Set ADC group injected trigger source to SW start to ensure to not     */
    /* have an external trigger event occurring during the conversion stop    */
    /* ADC disable process.                                                   */
    DDL_ADC16_INJ_SetTriggerSource(ADCx, DDL_ADC16_INJ_TRIG_SOFTWARE);

    /* Stop potential ADC conversion on going on ADC group injected.          */
    if (DDL_ADC16_INJ_IsConversionOngoing(ADCx) != 0UL)
    {
      if (DDL_ADC16_INJ_IsStopConversionOngoing(ADCx) == 0UL)
      {
        DDL_ADC16_INJ_StopConversion(ADCx);
      }
    }

    /* Wait for ADC conversions are effectively stopped                       */
    timeout_cpu_cycles = ADC_TIMEOUT_STOP_CONVERSION_CPU_CYCLES;
    while ((DDL_ADC16_REG_IsStopConversionOngoing(ADCx)
            | DDL_ADC16_INJ_IsStopConversionOngoing(ADCx)) == 1UL)
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
    DDL_ADC16_Disable(ADCx);

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
              (  DDL_ADC16_IT_EOC
               | DDL_ADC16_IT_EOS
               | DDL_ADC16_IT_OVR
               | DDL_ADC16_IT_EOSMP
               | DDL_ADC16_IT_JEOC
               | DDL_ADC16_IT_JEOS
               | DDL_ADC16_IT_JQOVF
               | DDL_ADC16_IT_AWD1
               | DDL_ADC16_IT_AWD2
               | DDL_ADC16_IT_AWD3
              )
             );

    /* Reset register ISR */
    SET_BIT(ADCx->ISR,
            (  DDL_ADC16_FLAG_EOC
             | DDL_ADC16_FLAG_EOS
             | DDL_ADC16_FLAG_OVR
             | DDL_ADC16_FLAG_EOSMP
             | DDL_ADC16_FLAG_JEOC
             | DDL_ADC16_FLAG_JEOS
             | DDL_ADC16_FLAG_JQOVF
             | DDL_ADC16_FLAG_AWD1
             | DDL_ADC16_FLAG_AWD2
             | DDL_ADC16_FLAG_AWD3
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
                | ADC_CFGR_AWD1EN  | ADC_CFGR_AWD1SGL | ADC_CFGR_JQM
                | ADC_CFGR_JDISCEN | ADC_CFGR_DISCNUM | ADC_CFGR_DISCEN
                | ADC_CFGR_AUTDLY  | ADC_CFGR_CONT    | ADC_CFGR_OVRMOD
                | ADC_CFGR_EXTEN   | ADC_CFGR_EXTSEL
                | ADC_CFGR_DMACFG  | ADC_CFGR_DMAEN),
               ADC_CFGR_JQDIS
              );

    /* Reset register CFGR2 */
    CLEAR_BIT(ADCx->CFGR2,
              (  ADC_CFGR2_DIFSEL | ADC_CFGR2_AWDFILT
               | ADC_CFGR2_ROVSM  | ADC_CFGR2_TROVS | ADC_CFGR2_OVSS
               | ADC_CFGR2_OVSR   | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSE)
             );

    /* Reset register SMPR1 */
    CLEAR_BIT(ADCx->SMPR1,
              (  ADC_SMPR1_SMP5 | ADC_SMPR1_SMP4 | ADC_SMPR1_SMP3
               | ADC_SMPR1_SMP2 | ADC_SMPR1_SMP1 | ADC_SMPR1_SMP0)
             );

    /* Reset register TR1 */
    MODIFY_REG(ADCx->TR1, ADC_TR1_HT1 | ADC_TR1_LT1, ADC_TR1_HT1);

    /* Reset register TR2 */
    MODIFY_REG(ADCx->TR2, ADC_TR2_HT2 | ADC_TR2_LT2, ADC_TR2_HT2);

    /* Reset register TR3 */
    MODIFY_REG(ADCx->TR3, ADC_TR3_HT3 | ADC_TR3_LT3, ADC_TR3_HT3);

    /* Reset register SQR1 */
    CLEAR_BIT(ADCx->SQR1,
              (  ADC_SQR1_SQ7 | ADC_SQR1_SQ6 | ADC_SQR1_SQ5
               | ADC_SQR1_SQ4 | ADC_SQR1_SQ3 | ADC_SQR1_SQ2
               | ADC_SQR1_SQ1 | ADC_SQR1_RL)
             );

    /* Reset register SQR2 */
    CLEAR_BIT(ADCx->SQR2,
              (  ADC_SQR2_SQ12 | ADC_SQR2_SQ11 | ADC_SQR2_SQ10
               | ADC_SQR2_SQ9 | ADC_SQR2_SQ8)
             );

    /* Reset register JSQR */
    CLEAR_BIT(ADCx->JSQR,
              (ADC_JSQR_JL
               | ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN
               | ADC_JSQR_JSQ4    | ADC_JSQR_JSQ3
               | ADC_JSQR_JSQ2    | ADC_JSQR_JSQ1)
             );

    /* Reset register DR */
    /* Note: bits in access mode read only, no direct reset applicable */

    /* Reset register OFFSET0 */
    CLEAR_BIT(ADCx->OFFSET0, ADC_OFFSET0_OFFSET0_EN  | ADC_OFFSET0_OFFSET0 | ADC_OFFSET0_OFFSETPOS);
    /* Reset register OFFSET1 */
    CLEAR_BIT(ADCx->OFFSET1, ADC_OFFSET1_OFFSET1_EN  | ADC_OFFSET1_OFFSET1 | ADC_OFFSET1_OFFSETPOS);
    /* Reset register OFFSET2 */
    CLEAR_BIT(ADCx->OFFSET2, ADC_OFFSET2_OFFSET2_EN  | ADC_OFFSET2_OFFSET2 | ADC_OFFSET2_OFFSETPOS);
    /* Reset register OFFSET3 */
    CLEAR_BIT(ADCx->OFFSET3, ADC_OFFSET3_OFFSET3_EN  | ADC_OFFSET3_OFFSET3 | ADC_OFFSET3_OFFSETPOS);
    /* Reset register OFFSET4 */
    CLEAR_BIT(ADCx->OFFSET4, ADC_OFFSET4_OFFSET4_EN  | ADC_OFFSET4_OFFSET4 | ADC_OFFSET4_OFFSETPOS);
    /* Reset register OFFSET5 */
    CLEAR_BIT(ADCx->OFFSET5, ADC_OFFSET5_OFFSET5_EN  | ADC_OFFSET5_OFFSET5 | ADC_OFFSET5_OFFSETPOS);

    /* Reset registers JDR1, JDR2, JDR3, JDR4 */
    /* Note: bits in access mode read only, no direct reset applicable */

    /* Reset register AWD2CR */
    CLEAR_BIT(ADCx->AWD2CR, ADC_AWD2CR_AWD2CH);

    /* Reset register AWD3CR */
    CLEAR_BIT(ADCx->AWD3CR, ADC_AWD3CR_AWD3CH);
    
    /* Reset register CAL */
    CLEAR_BIT( ADCx->CAL,ADC_CAL_REF_SEL);
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
  *         @ref ADC_DDL_EF_Configuration_ADC_Instance .
  * @note   The setting of these parameters by function @ref DDL_ADC16_Init()
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
  *            Refer to function @ref DDL_ADC16_REG_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC16_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_InitStruct Pointer to a @ref DDL_ADC16_REG_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC16_Init(ADC16_TypeDef *ADCx, DDL_ADC16_InitTypeDef *ADC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC16_ALL_INSTANCE(ADCx));

  ASSERT_PARAM(IS_DDL_ADC16_LOW_POWER(ADC_InitStruct->LowPowerMode));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC16_IsEnabled(ADCx) == 0UL)
  {
    /* Configuration of ADC hierarchical scope:                               */
    /*  - ADC instance                                                        */
    /*    - Set ADC low power mode                                            */
    MODIFY_REG(ADCx->CFGR, ADC_CFGR_AUTDLY, ADC_InitStruct->LowPowerMode);

  }
  else
  {
    /* Initialization error: ADC instance is not disabled. */
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Set each @ref DDL_ADC16_InitTypeDef field to default value.
  * @param  ADC_InitStruct Pointer to a @ref DDL_ADC16_InitTypeDef structure
  *                        whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC16_StructInit(DDL_ADC16_InitTypeDef *ADC_InitStruct)
{
  /* Set ADC_InitStruct fields to default values */
  /* Set fields of ADC instance */
  ADC_InitStruct->LowPowerMode  = DDL_ADC16_LP_MODE_NONE;
}

/**
  * @brief  Initialize some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref DDL_ADC16_Init()
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
  *            Refer to function @ref DDL_ADC16_REG_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC16_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_REG_InitStruct Pointer to a @ref DDL_ADC16_REG_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC16_REG_Init(ADC16_TypeDef *ADCx, DDL_ADC16_REG_InitTypeDef *ADC_REG_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC16_ALL_INSTANCE(ADCx));
  ASSERT_PARAM(IS_DDL_ADC16_REG_TRIG_SOURCE(ADCx, ADC_REG_InitStruct->TriggerSource));
  ASSERT_PARAM(IS_DDL_ADC16_REG_SEQ_SCAN_LENGTH(ADC_REG_InitStruct->SequencerLength));
  if (ADC_REG_InitStruct->SequencerLength != DDL_ADC16_REG_SEQ_SCAN_DISABLE)
  {
    ASSERT_PARAM(IS_DDL_ADC16_REG_SEQ_SCAN_DISCONT_MODE(ADC_REG_InitStruct->SequencerDiscont));

    /* ADC group regular continuous mode and discontinuous mode                 */
    /* can not be enabled simultenaeously                                       */
    ASSERT_PARAM((ADC_REG_InitStruct->ContinuousMode == DDL_ADC16_REG_CONV_SINGLE)
                 || (ADC_REG_InitStruct->SequencerDiscont == DDL_ADC16_REG_SEQ_DISCONT_DISABLE));
  }
  ASSERT_PARAM(IS_DDL_ADC16_REG_CONTINUOUS_MODE(ADC_REG_InitStruct->ContinuousMode));
  ASSERT_PARAM(IS_DDL_ADC16_REG_DMA_TRANSFER(ADC_REG_InitStruct->DMATransfer));
  ASSERT_PARAM(IS_DDL_ADC16_REG_OVR_DATA_BEHAVIOR(ADC_REG_InitStruct->Overrun));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC16_IsEnabled(ADCx) == 0UL)
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
    if (ADC_REG_InitStruct->SequencerLength != DDL_ADC16_REG_SEQ_SCAN_DISABLE)
    {
      MODIFY_REG(ADCx->CFGR,
                 ADC_CFGR_EXTSEL
                 | ADC_CFGR_EXTEN
                 | ADC_CFGR_DISCEN
                 | ADC_CFGR_DISCNUM
                 | ADC_CFGR_CONT
                 | ADC_CFGR_DMAEN
                 | ADC_CFGR_DMACFG
                 | ADC_CFGR_OVRMOD
                 ,
                 ADC_REG_InitStruct->TriggerSource
                 | ADC_REG_InitStruct->SequencerDiscont
                 | ADC_REG_InitStruct->ContinuousMode
                 | ADC_REG_InitStruct->DMATransfer
                 | ADC_REG_InitStruct->Overrun
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
                 | ADC_CFGR_DMACFG
                 | ADC_CFGR_OVRMOD
                 ,
                 ADC_REG_InitStruct->TriggerSource
                 | DDL_ADC16_REG_SEQ_DISCONT_DISABLE
                 | ADC_REG_InitStruct->ContinuousMode
                 | ADC_REG_InitStruct->DMATransfer
                 | ADC_REG_InitStruct->Overrun
                );
    }

    /* Set ADC group regular sequencer length and scan direction */
    DDL_ADC16_REG_SetSequencerLength(ADCx, ADC_REG_InitStruct->SequencerLength);
  }
  else
  {
    /* Initialization error: ADC instance is not disabled. */
    status = ERROR;
  }
  return status;
}

/**
  * @brief  Set each @ref DDL_ADC16_REG_InitTypeDef field to default value.
  * @param  ADC_REG_InitStruct Pointer to a @ref DDL_ADC16_REG_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC16_REG_StructInit(DDL_ADC16_REG_InitTypeDef *ADC_REG_InitStruct)
{
  /* Set ADC_REG_InitStruct fields to default values */
  /* Set fields of ADC group regular */
  /* Note: On this G32R4 series, ADC trigger edge is set to value 0x0 by      */
  /*       setting of trigger source to SW start.                             */
  ADC_REG_InitStruct->TriggerSource    = DDL_ADC16_REG_TRIG_SOFTWARE;
  ADC_REG_InitStruct->SequencerLength  = DDL_ADC16_REG_SEQ_SCAN_DISABLE;
  ADC_REG_InitStruct->SequencerDiscont = DDL_ADC16_REG_SEQ_DISCONT_DISABLE;
  ADC_REG_InitStruct->ContinuousMode   = DDL_ADC16_REG_CONV_SINGLE;
  ADC_REG_InitStruct->DMATransfer      = DDL_ADC16_REG_DMA_TRANSFER_NONE;
  ADC_REG_InitStruct->Overrun          = DDL_ADC16_REG_OVR_DATA_OVERWRITTEN;
}

/**
  * @brief  Initialize some features of ADC group injected.
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "INJ").
  * @note   The setting of these parameters by function @ref DDL_ADC16_Init()
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
  *            Refer to function @ref DDL_ADC16_INJ_SetSequencerRanks().
  *          - Set ADC channel sampling time
  *            Refer to function DDL_ADC16_SetChannelSamplingTime();
  * @param  ADCx ADC instance
  * @param  ADC_INJ_InitStruct Pointer to a @ref DDL_ADC16_INJ_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus DDL_ADC16_INJ_Init(ADC16_TypeDef *ADCx, DDL_ADC16_INJ_InitTypeDef *ADC_INJ_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  ASSERT_PARAM(IS_ADC16_ALL_INSTANCE(ADCx));
  ASSERT_PARAM(IS_DDL_ADC16_INJ_TRIG_SOURCE(ADCx, ADC_INJ_InitStruct->TriggerSource));
  ASSERT_PARAM(IS_DDL_ADC16_INJ_SEQ_SCAN_LENGTH(ADC_INJ_InitStruct->SequencerLength));
  if (ADC_INJ_InitStruct->SequencerLength != DDL_ADC16_INJ_SEQ_SCAN_DISABLE)
  {
    ASSERT_PARAM(IS_DDL_ADC16_INJ_SEQ_SCAN_DISCONT_MODE(ADC_INJ_InitStruct->SequencerDiscont));
  }
  ASSERT_PARAM(IS_DDL_ADC16_INJ_TRIG_AUTO(ADC_INJ_InitStruct->TrigAuto));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       ADC instance must be disabled.                                     */
  if (DDL_ADC16_IsEnabled(ADCx) == 0UL)
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
    if (ADC_INJ_InitStruct->SequencerLength != DDL_ADC16_REG_SEQ_SCAN_DISABLE)
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
                 DDL_ADC16_REG_SEQ_DISCONT_DISABLE
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
  * @brief  Set each @ref DDL_ADC16_INJ_InitTypeDef field to default value.
  * @param  ADC_INJ_InitStruct Pointer to a @ref DDL_ADC16_INJ_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
void DDL_ADC16_INJ_StructInit(DDL_ADC16_INJ_InitTypeDef *ADC_INJ_InitStruct)
{
  /* Set ADC_INJ_InitStruct fields to default values */
  /* Set fields of ADC group injected */
  ADC_INJ_InitStruct->TriggerSource    = DDL_ADC16_INJ_TRIG_SOFTWARE;
  ADC_INJ_InitStruct->SequencerLength  = DDL_ADC16_INJ_SEQ_SCAN_DISABLE;
  ADC_INJ_InitStruct->SequencerDiscont = DDL_ADC16_INJ_SEQ_DISCONT_DISABLE;
  ADC_INJ_InitStruct->TrigAuto         = DDL_ADC16_INJ_TRIG_INDEPENDENT;
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

#endif /* ADC2 ADC3 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

