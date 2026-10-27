/**
  *
  * @file    g32r4xx_ddl_dac.h
  * @brief   Header file of DAC DDL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_DAC_H
#define G32R4xx_DDL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(DAC1) || defined(DAC2)

/** @defgroup DDL_DAC DAC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup DDL_DAC_Private_Constants DAC Private Constants
  * @{
  */

/** @defgroup DAC_enable       DAC enable
  * @{
  */
#define DDL_DAC_ENABLE   (DAC_CR_EN)
#define DDL_DAC_DISABLE  (0x00000000UL)
/**
  * @}
  */

/** @defgroup DDL_DAC_CHANNEL_TRIG_SOURCE     DAC channel trigger source
  * @{
  */
#define DDL_DAC_TRG1  (DAC_CR_TSEL_0)
#define DDL_DAC_TRG2  (DAC_CR_TSEL_1)
#define DDL_DAC_TRG3  (DAC_CR_TSEL_1 | DAC_CR_TSEL_0)
#define DDL_DAC_TRG4  (DAC_CR_TSEL_2)
#define DDL_DAC_TRG5  (DAC_CR_TSEL_2 | DAC_CR_TSEL_0)
#define DDL_DAC_TRG6  (DAC_CR_TSEL_2 | DAC_CR_TSEL_1)
#define DDL_DAC_TRG7  (DAC_CR_TSEL_2 | DAC_CR_TSEL_1 | DAC_CR_TSEL_0)

#define DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE     (0x00000000UL)
#define DDL_DAC_CHANNEL_TRIG_SOURCE_TMR1         DDL_DAC_TRG1
#define DDL_DAC_CHANNEL_TRIG_SOURCE_TMR2         DDL_DAC_TRG2
#define DDL_DAC_CHANNEL_TRIG_SOURCE_TMR3         DDL_DAC_TRG3
#define DDL_DAC_CHANNEL_TRIG_SOURCE_TMR4         DDL_DAC_TRG4
#define DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE0   DDL_DAC_TRG5
#define DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE2   DDL_DAC_TRG6
#define DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE11  DDL_DAC_TRG7
/**
  * @}
  */

/** @defgroup DDL_DAC_NONE_MASK_LFSR     Do not mask LSFR bit
  * @{
  */
#define DDL_DAC_NONE_MASK_LFSR_0_0  (0x00000000UL)
#define DDL_DAC_NONE_MASK_LFSR_1_0  (DAC_CR_MAMP_0)
#define DDL_DAC_NONE_MASK_LFSR_2_0  (DAC_CR_MAMP_1)
#define DDL_DAC_NONE_MASK_LFSR_3_0  (DAC_CR_MAMP_1 | DAC_CR_MAMP_0)
#define DDL_DAC_NONE_MASK_LFSR_4_0  (DAC_CR_MAMP_2)
#define DDL_DAC_NONE_MASK_LFSR_5_0  (DAC_CR_MAMP_2 | DAC_CR_MAMP_0)
#define DDL_DAC_NONE_MASK_LFSR_6_0  (DAC_CR_MAMP_2 | DAC_CR_MAMP_1)
#define DDL_DAC_NONE_MASK_LFSR_7_0  (DAC_CR_MAMP_2 | DAC_CR_MAMP_1 | DAC_CR_MAMP_0)
#define DDL_DAC_NONE_MASK_LFSR_8_0  (DAC_CR_MAMP_3)
#define DDL_DAC_NONE_MASK_LFSR_9_0  (DAC_CR_MAMP_3 | DAC_CR_MAMP_0)

/**
  * @}
  */

/** @defgroup DDL_DAC_TRI_WAVE_AMPLITUDE    Triangle wave amplitude
  * @{
  */
#define DDL_DAC_TRI_WAVE_AMPLITUDE_1     (0x00000000UL)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_3     (DAC_CR_MAMP_0)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_7     (DAC_CR_MAMP_1)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_15    (DAC_CR_MAMP_1 | DAC_CR_MAMP_0)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_31    (DAC_CR_MAMP_2)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_63    (DAC_CR_MAMP_2 | DAC_CR_MAMP_0)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_127   (DAC_CR_MAMP_2 | DAC_CR_MAMP_1)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_255   (DAC_CR_MAMP_2 | DAC_CR_MAMP_1 | DAC_CR_MAMP_0)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_511   (DAC_CR_MAMP_3)
#define DDL_DAC_TRI_WAVE_AMPLITUDE_1023  (DAC_CR_MAMP_3 | DAC_CR_MAMP_0)

/**
  * @}
  */

/** @defgroup DDL_DAC_WAVE_GENERATE    Configure waveform generator
  * @{
  */
#define DDL_DAC_WAVE_GENERATE_NONE      (0x00000000UL)
#define DDL_DAC_WAVE_GENERATE_NOISE     (DAC_CR_WAVE_0)
#define DDL_DAC_WAVE_GENERATE_TRIANGLE  (DAC_CR_WAVE_1)
#define DDL_DAC_WAVE_GENERATE_SAWTOOTH  (DAC_CR_WAVE_1 | DAC_CR_WAVE_0)

/**
  * @}
  */

/** @defgroup DDL_DAC_OUTPUT_BUFFER    Output buffer
  * @{
  */
#define DDL_DAC_OUTPUT_BUFFER_INTERNAL  (0x00000000UL)
#define DDL_DAC_OUTPUT_BUFFER_EXTERNAL  (DAC_CR_EXT_SEL)

/**
  * @}
  */

/** @defgroup DDL_DAC_SAWTOOTH_WAVE_DIRECTION    Sawtooth wave direction
  * @{
  */
#define DDL_DAC_SAWTOOTH_WAVE_DIRECTION_INCREASING  (DAC_STR_STDIR)
#define DDL_DAC_SAWTOOTH_WAVE_DIRECTION_DECREASING  (0x00000000UL)

/**
  * @}
  */

/** @defgroup DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE    Sawtooth wave reset trigger selection
  * @{
  */
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_SOFTWARE  (0x00000000UL)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG1      (DAC_STMODR_STRSTTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG2      (DAC_STMODR_STRSTTRIGSEL_1)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG3      (DAC_STMODR_STRSTTRIGSEL_1 | DAC_STMODR_STRSTTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG4      (DAC_STMODR_STRSTTRIGSEL_2)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG5      (DAC_STMODR_STRSTTRIGSEL_2 | DAC_STMODR_STRSTTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG6      (DAC_STMODR_STRSTTRIGSEL_2 | DAC_STMODR_STRSTTRIGSEL_1)
#define DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG7      (DAC_STMODR_STRSTTRIGSEL_2 | DAC_STMODR_STRSTTRIGSEL_1 | DAC_STMODR_STRSTTRIGSEL_0)

/**
  * @}
  */

/** @defgroup DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE    Sawtooth wave increment trigger selection
  * @{
  */
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_SOFTWARE  (0x00000000UL)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG1      (DAC_STMODR_STINCTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG2      (DAC_STMODR_STINCTRIGSEL_1)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG3      (DAC_STMODR_STINCTRIGSEL_1 | DAC_STMODR_STINCTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG4      (DAC_STMODR_STINCTRIGSEL_2)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG5      (DAC_STMODR_STINCTRIGSEL_2 | DAC_STMODR_STINCTRIGSEL_0)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG6      (DAC_STMODR_STINCTRIGSEL_2 | DAC_STMODR_STINCTRIGSEL_1)
#define DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG7      (DAC_STMODR_STINCTRIGSEL_2 | DAC_STMODR_STINCTRIGSEL_1 | DAC_STMODR_STINCTRIGSEL_0)

/**
  * @}
  */

/** @defgroup DDL_DAC_DOR_DATA_OVERFLOW    DOR Data Overflow Flag
  * @{
  */
#define DDL_DAC_DOR_DATA_OVERFLOW_NOT_OCCURRED  (0x00000000UL)
#define DDL_DAC_DOR_DATA_OVERFLOW_OCCURRED      (DAC_SR_UP_OW_FLAG)

/**
  * @}
  */

/** @defgroup DDL_DAC_DOR_DATA_UNDERFLOW    DOR Data Underflow Flag
  * @{
  */
#define DDL_DAC_DOR_DATA_UNDERFLOW_NOT_OCCURRED  (0x00000000UL)
#define DDL_DAC_DOR_DATA_UNDERFLOW_OCCURRED      (DAC_SR_DOWN_OW_FLAG)

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup DDL_DAC_Private_Macros DAC Private Macros
  * @{
  */

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFFSET__ Offset to be applied (unit: number of registers).
  * @retval Pointer to register address
  */
#define __DAC_PTR_REG_OFFSET(__REG__,  __REG_OFFFSET__)                         \
  ((uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2UL))))

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup DDL_DAC_ES_INIT DAC Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of DAC instance.
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set the conversion trigger source for the selected DAC channel:
                                             internal (SW start) or from external peripheral
                                             (timer event, external interrupt line).
                                             This parameter can be a value of @ref DDL_DAC_CHANNEL_TRIG_SOURCE

                                             This feature can be modified afterwards using unitary
                                             function @ref DDL_DAC_SetChannelTriggerSource(). */

  uint32_t WaveAutoGeneration;          /*!< Set the waveform automatic generation mode for the selected DAC channel.
                                             This parameter can be a value of @ref DDL_DAC_EC_WAVE_AUTO_GENERATION_MODE

                                             This feature can be modified afterwards using unitary
                                             function @ref DDL_DAC_SetWaveAutoGeneration(). */

  uint32_t WaveAutoGenerationConfig;    /*!< Set the waveform automatic generation mode for the selected DAC channel.
                                             If waveform automatic generation mode is set to noise, this parameter
                                             can be a value of @ref DDL_DAC_EC_WAVE_NOISE_LFSR_UNMASK_BITS
                                             If waveform automatic generation mode is set to triangle,
                                             this parameter can be a value of @ref DDL_DAC_EC_WAVE_TRIANGLE_AMPLITUDE
                                             @note If waveform automatic generation mode is disabled,
                                              this parameter is discarded.

                                             This feature can be modified afterwards using unitary
                                             function @ref DDL_DAC_SetWaveNoiseLFSR(),
                                             @ref DDL_DAC_SetWaveTriangleAmplitude()
                                             depending on the wave automatic generation selected. */

  uint32_t OutputBuffer;                /*!< Set the output buffer for the selected DAC channel.
                                             This parameter can be a value of @ref DDL_DAC_EC_OUTPUT_BUFFER

                                             This feature can be modified afterwards using unitary
                                             function @ref DDL_DAC_SetOutputBuffer(). */
} DDL_DAC_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported functions --------------------------------------------------------*/
/** @defgroup DDL_DAC_Exported_Functions DAC Exported Functions
  * @{
  */

/** @defgroup DAC Basic Operations
  * @{
  */
/**
  * @brief  Enable DAC
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_Enable(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->CR, DAC_CR_EN, DDL_DAC_ENABLE);
}

/**
  * @brief  Disable DAC
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_Disable(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->CR, DAC_CR_EN, DDL_DAC_DISABLE);
}

/**
  * @brief  Get the status of whether DAC is enabled.
  * @param  DAC Instance
  * @retval 0 or 1.
  */
__STATIC_INLINE uint32_t DDL_DAC_IsEnabled(DAC_TypeDef *DACx)
{
  return (READ_BIT(DACx->CR, DAC_CR_EN) == DDL_DAC_ENABLE) ? 1UL : 0UL;
}

/**
  * @}
  */

/** @defgroup DAC channel operation function
  * @{
  */
/**
  * @brief  Set the trigger source for the channel.
  * @param  DAC Instance
  * @param  Trigger source
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR1
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR2
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR3
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR4
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE0
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE2
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE11
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetChannelTriggerSource(DAC_TypeDef *DACx, uint32_t Source)
{
  MODIFY_REG(DACx->CR, DAC_CR_TSEL, Source);
}

/**
  * @brief  Get the trigger source for the channel.
  * @param  DAC Instance
  * @retval Trigger source
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR1
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR2
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR3
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_TMR4
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE0
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE2
  *         @arg @ref DDL_DAC_CHANNEL_TRIG_SOURCE_EINT_LINE11
  */
__STATIC_INLINE uint32_t DDL_DAC_GetChannelTriggerSource(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->CR, DAC_CR_TSEL);
}

/**
  * @brief  Set the masking bits of the LFSR channel.
  * @param  DAC Instance
  * @param  Do not mask LSFR bit.
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_0_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_1_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_2_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_3_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_4_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_5_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_6_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_7_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_8_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_9_0
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_LFSR_SetNoneMask(DAC_TypeDef *DACx, uint32_t mask)
{
  MODIFY_REG(DACx->CR, DAC_CR_MAMP, mask);
}

/**
  * @brief  Get the masking bits of the LFSR channel.
  * @param  DAC Instance
  * @retval Do not mask LSFR bit.
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_0_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_1_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_2_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_3_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_4_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_5_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_6_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_7_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_8_0
  *         @arg @ref DDL_DAC_NONE_MASK_LFSR_9_0
  */
__STATIC_INLINE uint32_t DDL_DAC_LFSR_GetNoneMask(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->CR, DAC_CR_MAMP);
}

/**
  * @brief  Set the triangle wave amplitude selector.
  * @param  DAC Instance
  * @param  Triangle wave amplitude
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_1
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_3
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_7
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_15
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_31
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_63
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_127
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_255
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_511
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_1023
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetTriangleWaveAmplitude(DAC_TypeDef *DACx, uint32_t waveAmp)
{
  MODIFY_REG(DACx->CR, DAC_CR_MAMP, waveAmp);
}

/**
  * @brief  Get the triangle wave amplitude selector.
  * @param  DAC Instance
  * @retval Triangle wave amplitude
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_1
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_3
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_7
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_15
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_31
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_63
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_127
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_255
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_511
  *         @arg @ref DDL_DAC_TRI_WAVE_AMPLITUDE_1023
  */
__STATIC_INLINE uint32_t DDL_DAC_GetTriangleWaveAmplitude(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->CR, DAC_CR_MAMP);
}

/**
  * @brief  Set the type of waveform generated.
  * @param  DAC Instance
  * @param  Wave type
  *         @arg @ref DDL_DAC_WAVE_GENERATE_NONE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_NOISE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_TRIANGLE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_SAWTOOTH
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetWaveGenerateType(DAC_TypeDef *DACx, uint32_t type)
{
  MODIFY_REG(DACx->CR, DAC_CR_WAVE, type);
}

/**
  * @brief  Get the type of waveform generated.
  * @param  DAC Instance
  * @retval Wave type
  *         @arg @ref DDL_DAC_WAVE_GENERATE_NONE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_NOISE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_TRIANGLE
  *         @arg @ref DDL_DAC_WAVE_GENERATE_SAWTOOTH
  */
__STATIC_INLINE uint32_t DDL_DAC_GetWaveGenerateType(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->CR, DAC_CR_WAVE);
}

/**
  * @brief  Enable the channel software triggers the generation of waveforms.
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_EnableSoftwareTrigger(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->SWTRGR, DAC_SWTRGR_SWTRIG, DAC_SWTRGR_SWTRIG);
}

/**
  * @}
  */

/** @defgroup DAC data input and output functions
  * @{
  */
/**
  * @brief  Enable DAC resistor string output signal to operational amplifier input.
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_EnableResistorStringOutputToOpAmplifier(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->CR, DAC_CR_EN_RDAC, 0x0000000);
}

/**
  * @brief  Disable DAC resistor string output signal to operational amplifier input.
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_DisableResistorStringOutputToOpAmplifier(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->CR, DAC_CR_EN_RDAC, DAC_CR_EN_RDAC);
}

/**
  * @brief  Set whether the BUFFER output is connected to the PAD.
  * @param  DAC Instance
  * @param  Wave type
  *         @arg @ref DDL_DAC_OUTPUT_BUFFER_INTERNAL
  *         @arg @ref DDL_DAC_OUTPUT_BUFFER_EXTERNAL
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetBufferOutputSource(DAC_TypeDef *DACx, uint32_t outputBufferSource)
{
  MODIFY_REG(DACx->CR, DAC_CR_EXT_SEL, outputBufferSource);
}

/**
  * @brief  Get whether the BUFFER output is connected to the PAD.
  * @param  DAC Instance
  * @retval Wave type
  *         @arg @ref DDL_DAC_OUTPUT_BUFFER_INTERNAL
  *         @arg @ref DDL_DAC_OUTPUT_BUFFER_EXTERNAL
  */
__STATIC_INLINE uint32_t DDL_DAC_GetBufferOutputSource(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->CR, DAC_CR_EXT_SEL);
}

/**
  * @brief  Set right-aligned data register.
  * @param  DAC Instance
  * @param  data  0x000 ~ 0x3FF
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetRightAlignmentData(DAC_TypeDef *DACx, uint32_t data)
{
  MODIFY_REG(DACx->DHR10R, DAC_DHR10R_DHR10R, data & DAC_DHR10R_DHR10R_Msk);
}

/**
  * @brief  Get right-aligned data register.
  * @param  DAC Instance
  * @retval data  0x000 ~ 0x3FF
  */
__STATIC_INLINE uint32_t DDL_DAC_GetRightAlignmentData(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->DHR10R, DAC_DHR10R_DHR10R);
}

/**
  * @brief  Set left-aligned data register.
  * @param  DAC Instance
  * @param  data  0x000 ~ 0x3FF
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_SetLeftAlignmentData(DAC_TypeDef *DACx, uint32_t data)
{
  MODIFY_REG(DACx->DHR10L, DAC_DHR10L_DHR10L, (data << DAC_DHR10L_DHR10L_Pos) & DAC_DHR10L_DHR10L_Msk);
}

/**
  * @brief  Get left-aligned data register.
  * @param  DAC Instance
  * @retval data  0x000 ~ 0x3FF
  */
__STATIC_INLINE uint32_t DDL_DAC_GetLeftAlignmentData(DAC_TypeDef *DACx)
{
  return (uint32_t)(READ_BIT(DACx->DHR10L, DAC_DHR10L_DHR10L) >> DAC_DHR10L_DHR10L_Pos);
}

/**
  * @brief  Get data output data register.
  * @param  DAC Instance
  * @retval data  0x000 ~ 0x3FF
  */
__STATIC_INLINE uint32_t DDL_DAC_GetOutputData(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->DOR, DAC_DOR_DOR);
}

/**
  * @}
  */

/** @defgroup Sawtooth wave operation generates correlation functions.
  * @{
  */
/**
  * @brief  Enable channel software trigger to generate sawtooth wave incrementally.
  * @param  DAC Instance
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_EnableSawtoothSoftwareTriggerB(DAC_TypeDef *DACx)
{
  MODIFY_REG(DACx->SWTRGR, DAC_SWTRGR_SWTRIGB, DAC_SWTRGR_SWTRIGB);
}

/**
  * @brief  Set channel sawtooth reset value.
  * @param  DAC Instance
  * @param  value  0x000 ~ 0x3FF
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_SetSawtoothResetValue(DAC_TypeDef *DACx, uint32_t value)
{
  MODIFY_REG(DACx->STR, DAC_STR_STRSTDATA, value);
}

/**
  * @brief  Get channel sawtooth reset value.
  * @param  DAC Instance
  * @retval 0x000 ~ 0x3FF
  */
__STATIC_INLINE uint32_t DDL_DAC_GetSawtoothResetValue(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->STR, DAC_STR_STRSTDATA);
}

/**
  * @brief  Set DAC channel sawtooth wave direction.
  * @param  DAC Instance
  * @param  Direction
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_DIRECTION_INCREASING
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_DIRECTION_DECREASING
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_SetSawtoothDirection(DAC_TypeDef *DACx, uint32_t Direction)
{
  MODIFY_REG(DACx->STR, DAC_STR_STDIR, Direction);
}

/**
  * @brief  Get DAC channel sawtooth wave direction.
  * @param  DAC Instance
  * @retval Direction
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_DIRECTION_INCREASING
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_DIRECTION_DECREASING
  */
__STATIC_INLINE uint32_t DDL_DAC_GetSawtoothDirection(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->STR, DAC_STR_STDIR);
}

/**
  * @brief  Set the increment value of the DAC channel sawtooth wave.
  * @param  DAC Instance
  * @param  value  0x0000 ~ 0x3FF
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_SetSawtoothIncrementValue(DAC_TypeDef *DACx, uint32_t value)
{
  MODIFY_REG(DACx->STR, DAC_STR_STINCDATA, (value << DAC_STR_STINCDATA_Pos) & DAC_STR_STINCDATA_Msk);
}

/**
  * @brief  Get the increment value of the DAC channel sawtooth wave.
  * @param  DAC Instance
  * @retval 0x0000 ~ 0x3FF
  */
__STATIC_INLINE uint32_t DDL_DAC_GetSawtoothIncrementValue(DAC_TypeDef *DACx)
{
  return (uint32_t)(READ_BIT(DACx->STR, DAC_STR_STINCDATA) >> DAC_STR_STINCDATA_Pos);
}

/**
  * @brief  Set the sawtooth wave reset trigger source.
  * @param  DAC Instance
  * @param  trigger source
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG1
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG2
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG3
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG4
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG5
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG6
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG7
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_SetSawtoothResetTriggerSource(DAC_TypeDef *DACx, uint32_t source)
{
  MODIFY_REG(DACx->STMODR, DAC_STMODR_STRSTTRIGSEL, source);
}

/**
  * @brief  Get the sawtooth wave reset trigger source.
  * @param  DAC Instance
  * @retval trigger source
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG1
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG2
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG3
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG4
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG5
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG6
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_RESET_TRIG_SOURCE_TRG7
  */
__STATIC_INLINE uint32_t DDL_DAC_GetSawtoothResetTriggerSource(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->STMODR, DAC_STMODR_STRSTTRIGSEL);
}

/**
  * @brief  Set the sawtooth wave increment trigger source.
  * @param  DAC Instance
  * @param  trigger source
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG1
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG2
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG3
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG4
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG5
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG6
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG7
  * @retval None.
  */
__STATIC_INLINE void DDL_DAC_SetSawtoothIncrementTriggerSource(DAC_TypeDef *DACx, uint32_t source)
{
  MODIFY_REG(DACx->STMODR, DAC_STMODR_STINCTRIGSEL, source);
}

/**
  * @brief  Get the sawtooth wave increment trigger source.
  * @param  DAC Instance
  * @retval trigger source
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_SOFTWARE
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG1
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG2
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG3
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG4
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG5
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG6
  *         @arg @ref DDL_DAC_SAWTOOTH_WAVE_INCREMENT_TRIG_SOURCE_TRG7
  */
__STATIC_INLINE uint32_t DDL_DAC_GetSawtoothIncrementTriggerSource(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->STMODR, DAC_STMODR_STINCTRIGSEL);
}

/**
  * @brief  Get DOR data overflow status.
  * @param  DAC Instance
  * @retval DOR data overflow status.
  *         @arg @ref DDL_DAC_DOR_DATA_OVERFLOW_NOT_OCCURRED
  *         @arg @ref DDL_DAC_DOR_DATA_OVERFLOW_OCCURRED
  */
__STATIC_INLINE uint32_t DDL_DAC_GetDORDataOverFlowStatus(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->SR, DAC_SR_UP_OW_FLAG);
}

/**
  * @brief  Clear DOR data overflow status.
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_ClearDORDataOverFlowStatus(DAC_TypeDef *DACx)
{
  WRITE_REG(DACx->SR, DAC_SR_UP_OW_FLAG);
}

/**
  * @brief  Get DOR data underflow status.
  * @param  DAC Instance
  * @retval DOR data underflow status.
  *         @arg @ref DDL_DAC_DOR_DATA_UNDERFLOW_NOT_OCCURRED
  *         @arg @ref DDL_DAC_DOR_DATA_UNDERFLOW_OCCURRED
  */
__STATIC_INLINE uint32_t DDL_DAC_GetDORDataUnderFlowStatus(DAC_TypeDef *DACx)
{
  return (uint32_t)READ_BIT(DACx->SR, DAC_SR_DOWN_OW_FLAG);
}

/**
  * @brief  Clear DOR data underflow status.
  * @param  DAC Instance
  * @retval None
  */
__STATIC_INLINE void DDL_DAC_ClearDORDataUnderFlowStatus(DAC_TypeDef *DACx)
{
  WRITE_REG(DACx->SR, DAC_SR_DOWN_OW_FLAG);
}

/**
  * @}
  */

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup DDL_DAC_EF_Init  DAC Exported Init functions
  * @{
  */

/** 
  * @brief Initialization and de-initialization functions
  */
ErrorStatus DDL_DAC_DeInit(DAC_TypeDef *DACx);
ErrorStatus DDL_DAC_Init(DAC_TypeDef *DACx, DDL_DAC_InitTypeDef *DAC_InitStruct);
void        DDL_DAC_StructInit(DDL_DAC_InitTypeDef *DAC_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */

#endif /* DAC */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_DAC_H */

