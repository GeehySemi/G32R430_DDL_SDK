/**
  *
  * @file    g32r4xx_ddl_adc12.h
  * @brief   Header file of ADC DDL module.
  ******************************************************************************
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
#ifndef G32R4xx_DDL_ADC12_H
#define G32R4xx_DDL_ADC12_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (ADC3)

/** @defgroup ADC_DDL ADC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup ADC12_DDL_Private_Constants ADC Private Constants
  * @{
  */

/* Internal mask for ADC group regular sequencer:                             */
/* To select into literal DDL_ADC12_REG_RANK_x the relevant bits for:            */
/* - sequencer register offset                                                */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group regular sequencer configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC12_SQR1_REGOFFSET                            (0x00000000UL)
#define ADC12_SQR2_REGOFFSET                            (0x00000100UL)
#define ADC12_SQR3_REGOFFSET                            (0x00000200UL)

#define ADC12_REG_SQRX_REGOFFSET_MASK                   (ADC12_SQR1_REGOFFSET | ADC12_SQR2_REGOFFSET | ADC12_SQR3_REGOFFSET)
#define ADC12_SQRX_REGOFFSET_POS                        (8UL) /* Position of bits ADC12_SQRx_REGOFFSET in ADC12_REG_SQRX_REGOFFSET_MASK */
#define ADC12_REG_RANK_ID_SQRX_MASK                     (0x1F)

/* Definition of ADC group regular sequencer bits information to be inserted  */
/* into ADC group regular sequencer ranks literals definition.                */
#define ADC12_REG_RANK_1_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ1_Pos)
#define ADC12_REG_RANK_2_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ2_Pos)
#define ADC12_REG_RANK_3_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ3_Pos)
#define ADC12_REG_RANK_4_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ4_Pos)
#define ADC12_REG_RANK_5_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ5_Pos)
#define ADC12_REG_RANK_6_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ6_Pos)
#define ADC12_REG_RANK_7_SQRX_BITOFFSET_POS             (ADC_SQR1_SQ7_Pos)
#define ADC12_REG_RANK_8_SQRX_BITOFFSET_POS             (ADC_SQR2_SQ8_Pos)
#define ADC12_REG_RANK_9_SQRX_BITOFFSET_POS             (ADC_SQR2_SQ9_Pos)
#define ADC12_REG_RANK_10_SQRX_BITOFFSET_POS            (ADC_SQR2_SQ10_Pos)
#define ADC12_REG_RANK_11_SQRX_BITOFFSET_POS            (ADC_SQR2_SQ11_Pos)
#define ADC12_REG_RANK_12_SQRX_BITOFFSET_POS            (ADC_SQR2_SQ12_Pos)
#define ADC12_REG_RANK_13_SQRX_BITOFFSET_POS            (ADC_SQR2_SQ13_Pos)
#define ADC12_REG_RANK_14_SQRX_BITOFFSET_POS            (ADC_SQR2_SQ14_Pos)
#define ADC12_REG_RANK_15_SQRX_BITOFFSET_POS            (ADC_SQR3_SQ15_Pos)
#define ADC12_REG_RANK_16_SQRX_BITOFFSET_POS            (ADC_SQR3_SQ16_Pos)

/* Internal mask for ADC group injected sequencer:                            */
/* To select into literal DDL_ADC12_INJ_RANK_x the relevant bits for:            */
/* - data register offset                                                     */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group injected data register */
/* (offset placed into a spare area of literal definition) */
#define ADC12_JDR1_REGOFFSET                            (0x00000000UL)
#define ADC12_JDR2_REGOFFSET                            (0x00000100UL)
#define ADC12_JDR3_REGOFFSET                            (0x00000200UL)
#define ADC12_JDR4_REGOFFSET                            (0x00000300UL)

#define ADC12_INJ_JDRX_REGOFFSET_MASK                   (ADC12_JDR1_REGOFFSET | ADC12_JDR2_REGOFFSET \
                                            | ADC12_JDR3_REGOFFSET | ADC12_JDR4_REGOFFSET)
#define ADC12_INJ_RANK_ID_JSQR_MASK                     (0x1F)
#define ADC12_JDRX_REGOFFSET_POS                        (8UL) /* Position of bits ADC12_JDRx_REGOFFSET in ADC12_INJ_JDRX_REGOFFSET_MASK */

/* Definition of ADC group injected sequencer bits information to be inserted */
/* into ADC group injected sequencer ranks literals definition.               */
#define ADC12_INJ_RANK_1_JSQR_BITOFFSET_POS             (ADC_JSQR_JSQ1_Pos)
#define ADC12_INJ_RANK_3_JSQR_BITOFFSET_POS             (ADC_JSQR_JSQ3_Pos)
#define ADC12_INJ_RANK_2_JSQR_BITOFFSET_POS             (ADC_JSQR_JSQ2_Pos)
#define ADC12_INJ_RANK_4_JSQR_BITOFFSET_POS             (ADC_JSQR_JSQ4_Pos)

/* Internal mask for ADC group regular trigger:                               */
/* To select into literal DDL_ADC12_REG_TRIG_x the relevant bits for:            */
/* - regular trigger source                                                   */
/* - regular trigger edge                                                     */
#define ADC12_REG_TRIG_EXT_EDGE_DEFAULT                 (ADC_CFGR_EXTEN_0) /* Trigger edge set to rising edge */

/* Mask containing trigger source masks for each of possible                  */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC12_REG_TRIG_SOURCE_MASK                      (((DDL_ADC12_REG_TRIG_SOFTWARE & ADC_CFGR_EXTSEL) << (4U * 0UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 1UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 2UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 3UL))  )

/* Mask containing trigger edge masks for each of possible                    */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC12_REG_TRIG_EDGE_MASK                        (((DDL_ADC12_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN) << (4U * 0UL)) | \
                                             ((ADC12_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 1UL)) | \
                                             ((ADC12_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 2UL)) | \
                                             ((ADC12_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 3UL))  )

/* Definition of ADC group regular trigger bits information.                  */
#define ADC12_REG_TRIG_EXTSEL_BITOFFSET_POS             (ADC_CFGR_EXTSEL_Pos)
#define ADC12_REG_TRIG_EXTEN_BITOFFSET_POS              (ADC_CFGR_EXTEN_Pos)

/* Internal mask for ADC group injected trigger:                              */
/* To select into literal DDL_ADC12_INJ_TRIG_x the relevant bits for:            */
/* - injected trigger source                                                  */
/* - injected trigger edge                                                    */
#define ADC12_INJ_TRIG_EXT_EDGE_DEFAULT                 (ADC_JSQR_JEXTEN_0) /* Trigger edge set to rising edge */

/* Mask containing trigger source masks for each of possible                  */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC12_INJ_TRIG_SOURCE_MASK                      (((DDL_ADC12_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTSEL)  << (4U * 0UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 1UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 2UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 3UL))  )

/* Mask containing trigger edge masks for each of possible                    */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC12_INJ_TRIG_EDGE_MASK                        (((DDL_ADC12_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN) << (4U * 0UL)) | \
                                             ((ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 1UL)) | \
                                             ((ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 2UL)) | \
                                             ((ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 3UL))  )

/* Definition of ADC group injected trigger bits information.                 */
#define ADC12_INJ_TRIG_EXTSEL_BITOFFSET_POS             (ADC_JSQR_JEXTSEL_Pos)
#define ADC12_INJ_TRIG_EXTEN_BITOFFSET_POS              (ADC_JSQR_JEXTEN_Pos)

/* Internal mask for ADC channel:                                             */
/* To select into literal DDL_ADC12_CHANNEL_x the relevant bits for:             */
/* - channel identifier defined by number                                     */
/* - channel identifier defined by bitfield                                   */
/* - channel differentiation between external channels (connected to          */
/*   GPIO pins) and internal channels (connected to internal paths)           */
/* - channel sampling time defined by SMPRx register offset                   */
/*   and SMPx bits positions into SMPRx register                              */
#define ADC12_CHANNEL_ID_NUMBER_MASK                    (ADC_CFGR_AWD1CH)
#define ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS           (ADC_CFGR_AWD1CH_Pos)
#define ADC12_CHANNEL_ID_MASK                           (ADC12_CHANNEL_ID_NUMBER_MASK  \
                                            | ADC12_CHANNEL_ID_INTERNAL_CH_MASK)
/* Equivalent mask of ADC12_CHANNEL_NUMBER_MASK aligned on register LSB (bit 0) */
#define ADC12_CHANNEL_ID_NUMBER_MASK_POSBIT0            (ADC_SQR2_SQ8) /* Equivalent to shift: (ADC12_CHANNEL_NUMBER_MASK >> [Position of bitfield "ADC12_CHANNEL_NUMBER_MASK" in register]) */

/* Channel differentiation between external and internal channels */
#define ADC12_CHANNEL_ID_INTERNAL_CH                    (0x80000000UL) /* Marker of internal channel */
#define ADC12_CHANNEL_ID_INTERNAL_CH_2                  (0x00080000UL) /* Marker of internal channel for other ADC instances, in case of different ADC internal channels mapped on same channel number on different ADC instances */
#define ADC12_CHANNEL_ID_INTERNAL_CH_MASK               (ADC12_CHANNEL_ID_INTERNAL_CH | ADC12_CHANNEL_ID_INTERNAL_CH_2)

/* Internal register offset for ADC channel sampling time configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC12_SMPR1_REGOFFSET                           (0x00000000UL)
#define ADC12_SMPR2_REGOFFSET                           (0x02000000UL)
#define ADC12_CHANNEL_SMPRX_REGOFFSET_MASK              (ADC12_SMPR1_REGOFFSET | ADC12_SMPR2_REGOFFSET)
#define ADC12_SMPRX_REGOFFSET_POS                       (25UL) /* Position of bits ADC12_SMPRx_REGOFFSET in ADC12_CHANNEL_SMPRX_REGOFFSET_MASK */

#define ADC12_CHANNEL_SMPx_BITOFFSET_MASK               (0x01F00000UL)
#define ADC12_CHANNEL_SMPx_BITOFFSET_POS                (20UL)           /* Value equivalent to bitfield "ADC12_CHANNEL_SMPx_BITOFFSET_MASK" position in register */

/* Definition of channels ID number information to be inserted into           */
/* channels literals definition.                                              */
#define ADC12_CHANNEL_0_NUMBER                          (0x00000000UL)
#define ADC12_CHANNEL_1_NUMBER                          (ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_2_NUMBER                          (ADC_CFGR_AWD1CH_1)
#define ADC12_CHANNEL_3_NUMBER                          (ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_4_NUMBER                          (ADC_CFGR_AWD1CH_2)
#define ADC12_CHANNEL_5_NUMBER                          (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_6_NUMBER                          (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1)
#define ADC12_CHANNEL_7_NUMBER                          (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_8_NUMBER                          (ADC_CFGR_AWD1CH_3)
#define ADC12_CHANNEL_9_NUMBER                          (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_10_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_1)
#define ADC12_CHANNEL_11_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_12_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2)
#define ADC12_CHANNEL_13_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_0)
#define ADC12_CHANNEL_14_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1)
#define ADC12_CHANNEL_15_NUMBER                         (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)

/* Definition of channels sampling time information to be inserted into       */
/* channels literals definition.                                              */
#define ADC12_CHANNEL_0_SMP                             (ADC12_SMPR1_REGOFFSET | (( 0UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP0" position in register */
#define ADC12_CHANNEL_1_SMP                             (ADC12_SMPR1_REGOFFSET | (( 4UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP1" position in register */
#define ADC12_CHANNEL_2_SMP                             (ADC12_SMPR1_REGOFFSET | (( 8UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP2" position in register */
#define ADC12_CHANNEL_3_SMP                             (ADC12_SMPR1_REGOFFSET | ((12UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP3" position in register */
#define ADC12_CHANNEL_4_SMP                             (ADC12_SMPR1_REGOFFSET | ((16UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP4" position in register */
#define ADC12_CHANNEL_5_SMP                             (ADC12_SMPR1_REGOFFSET | ((20UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP5" position in register */
#define ADC12_CHANNEL_6_SMP                             (ADC12_SMPR1_REGOFFSET | ((24UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP6" position in register */
#define ADC12_CHANNEL_7_SMP                             (ADC12_SMPR1_REGOFFSET | ((28UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP7" position in register */
#define ADC12_CHANNEL_8_SMP                             (ADC12_SMPR2_REGOFFSET | (( 0UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP8" position in register */
#define ADC12_CHANNEL_9_SMP                             (ADC12_SMPR2_REGOFFSET | (( 4UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP9" position in register */
#define ADC12_CHANNEL_10_SMP                            (ADC12_SMPR2_REGOFFSET | (( 8UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP10" position in register */
#define ADC12_CHANNEL_11_SMP                            (ADC12_SMPR2_REGOFFSET | ((12UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP11" position in register */
#define ADC12_CHANNEL_12_SMP                            (ADC12_SMPR2_REGOFFSET | ((16UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP12" position in register */
#define ADC12_CHANNEL_13_SMP                            (ADC12_SMPR2_REGOFFSET | ((20UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP13" position in register */
#define ADC12_CHANNEL_14_SMP                            (ADC12_SMPR2_REGOFFSET | ((24UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP14" position in register */
#define ADC12_CHANNEL_15_SMP                            (ADC12_SMPR2_REGOFFSET | ((28UL) << ADC12_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR2_SMP15" position in register */
/* Internal mask for ADC analog watchdog:                                     */
/* To select into literals DDL_ADC12_AWD_CHANNELx_xxx the relevant bits for:     */
/* (concatenation of multiple bits used in different analog watchdogs,        */
/* - analog watchdog 1: monitored channel defined by number,                  */
/*   selection of ADC group (ADC groups regular and-or injected).             */
/* - analog watchdog 2 and 3: monitored channel defined by bitfield, no       */
/*   selection on groups.                                                     */

/* Internal register offset for ADC analog watchdog channel configuration */
#define ADC12_AWD_CR1_REGOFFSET                         (0x00000000UL)
#define ADC12_AWD_CR2_REGOFFSET                         (0x00100000UL)
#define ADC12_AWD_CR3_REGOFFSET                         (0x00200000UL)

/* Register offset gap between AWD1 and AWD2-AWD3 configuration registers */
/* (Set separately as ADC12_AWD_CRX_REGOFFSET to spare 32 bits space */
#define ADC12_AWD_CR12_REGOFFSETGAP_MASK                (ADC_AWD2CR_AWD2CH_0)
#define ADC12_AWD_CR12_REGOFFSETGAP_VAL                 (0x00000010UL)

#define ADC12_AWD_CRX_REGOFFSET_MASK                    (ADC12_AWD_CR1_REGOFFSET | ADC12_AWD_CR2_REGOFFSET | ADC12_AWD_CR3_REGOFFSET)

#define ADC12_AWD_CR1_CHANNEL_MASK                      (ADC_CFGR_AWD1CH | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)
#define ADC12_AWD_CR23_CHANNEL_MASK                     (ADC_AWD2CR_AWD2CH)
#define ADC12_AWD_CR_ALL_CHANNEL_MASK                   (ADC12_AWD_CR1_CHANNEL_MASK | ADC12_AWD_CR23_CHANNEL_MASK)

#define ADC12_AWD_CRX_REGOFFSET_POS                     (20UL) /* Position of bits ADC12_AWD_CRx_REGOFFSET in ADC12_AWD_CRX_REGOFFSET_MASK */

/* Internal register offset for ADC analog watchdog threshold configuration */
#define ADC12_AWD_TR1_REGOFFSET                         (ADC12_AWD_CR1_REGOFFSET)
#define ADC12_AWD_TR2_REGOFFSET                         (ADC12_AWD_CR2_REGOFFSET)
#define ADC12_AWD_TR3_REGOFFSET                         (ADC12_AWD_CR3_REGOFFSET)
#define ADC12_AWD_TRX_REGOFFSET_MASK                    (ADC12_AWD_TR1_REGOFFSET | ADC12_AWD_TR2_REGOFFSET | ADC12_AWD_TR3_REGOFFSET)
#define ADC12_AWD_TRX_REGOFFSET_POS                     (ADC12_AWD_CRX_REGOFFSET_POS)     /* Position of bits ADC12_SQRx_REGOFFSET in ADC12_AWD_TRX_REGOFFSET_MASK */
#define ADC12_AWD_TRX_BIT_HIGH_MASK                     (0x00010000UL)                   /* Selection of 1 bit to discriminate threshold high: mask of bit */
#define ADC12_AWD_TRX_BIT_HIGH_POS                      (16UL)                           /* Selection of 1 bit to discriminate threshold high: position of bit */
#define ADC12_AWD_TRX_BIT_HIGH_SHIFT4                   (ADC12_AWD_TRX_BIT_HIGH_POS - 4UL) /* Shift of bit ADC12_AWD_TRX_BIT_HIGH to position to perform a shift of 4 ranks */

/* Internal mask for ADC offset:                                              */
/* Internal register offset for ADC offset number configuration */
#define ADC12_OFR0_REGOFFSET                            (0x00000000UL)
#define ADC12_OFR1_REGOFFSET                            (0x00000001UL)
#define ADC12_OFR2_REGOFFSET                            (0x00000002UL)
#define ADC12_OFR3_REGOFFSET                            (0x00000003UL)
#define ADC12_OFRx_REGOFFSET_MASK                       (ADC12_OFR0_REGOFFSET | ADC12_OFR1_REGOFFSET \
                                          | ADC12_OFR2_REGOFFSET | ADC12_OFR3_REGOFFSET)

/* ADC registers bits positions */
#define ADC12_CFGR_AWD1SGL_BITOFFSET_POS                (ADC_CFGR_AWD1SGL_Pos)
#define ADC12_CFGR_AWD1EN_BITOFFSET_POS                 (ADC_CFGR_AWD1EN_Pos)
#define ADC12_CFGR_JAWD1EN_BITOFFSET_POS                (ADC_CFGR_JAWD1EN_Pos)
#define ADC12_TR1_HT1_BITOFFSET_POS                     (ADC_TR1_HT1_Pos)

/* ADC registers bits groups */
#define ADC12_CR_BITS_PROPERTY_RS                       (ADC_CR_JADSTP | ADC_CR_ADSTP | ADC_CR_JADSTART | ADC_CR_ADSTART | ADC_CR_ADEN) /* ADC register CR bits with HW property "rs": Software can read as well as set this bit. Writing '0' has no effect on the bit value. */

/** @defgroup ADC12_DDL_EC_REG_TRIGGER_SOURCE  ADC group regular - Trigger source
  * @{
  */

#define DDL_ADC12_REG_TRIG_SOFTWARE         (0x00000000UL)                                                             /*!< ADC group regular conversion trigger internal: SW start. */
#define DDL_ADC12_REG_TRIG_EXT_TMR1_CC1     (ADC12_REG_TRIG_EXT_EDGE_DEFAULT)                                          /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC1. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_TMR1_CC2     (ADC_CFGR_EXTSEL_0 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC2. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_TMR1_CC3     (ADC_CFGR_EXTSEL_1 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC3. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_TMR2_CC2     (ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group regular conversion trigger from external peripheral: TMR2 CC2. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_TMR3_TRGO    (ADC_CFGR_EXTSEL_2 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR3 TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_TMR4_CC4     (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_0 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group regular conversion trigger from external peripheral: TMR4 CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_REG_TRIG_EXT_EINT_LINE11  (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_1 | ADC12_REG_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group regular conversion trigger from external peripheral: EINT Line 11. Trigger edge set to rising edge (default setting). */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_TRIGGER_EDGE  ADC group regular - Trigger edge
  * @{
  */
#define DDL_ADC12_REG_TRIG_EXT_RISING   (ADC_CFGR_EXTEN_0)  /*!< ADC group regular conversion trigger polarity set to rising edge */
#define DDL_ADC12_REG_TRIG_EXT_DISABLE  (0x00000000UL)      /*!< ADC group regular conversion trigger polarity set to falling edge */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_SEQ_SCAN_LENGTH  ADC group regular - Sequencer scan length
  * @{
  */
#define DDL_ADC12_REG_SEQ_SCAN_DISABLE         (0x00000000UL)                                                   /*!< ADC group regular sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_2RANKS   (                                             ADC_SQR1_RL_0)     /*!< ADC group regular sequencer enable with 2 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_3RANKS   (                              ADC_SQR1_RL_1               )     /*!< ADC group regular sequencer enable with 3 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_4RANKS   (                              ADC_SQR1_RL_1 | ADC_SQR1_RL_0)    /*!< ADC group regular sequencer enable with 4 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_5RANKS   (               ADC_SQR1_RL_2                              )     /*!< ADC group regular sequencer enable with 5 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_6RANKS   (               ADC_SQR1_RL_2                | ADC_SQR1_RL_0)    /*!< ADC group regular sequencer enable with 6 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_7RANKS   (               ADC_SQR1_RL_2 | ADC_SQR1_RL_1               )    /*!< ADC group regular sequencer enable with 7 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_8RANKS   (               ADC_SQR1_RL_2 | ADC_SQR1_RL_1 | ADC_SQR1_RL_0)   /*!< ADC group regular sequencer enable with 8 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_9RANKS   (ADC_SQR1_RL_3                                              )    /*!< ADC group regular sequencer enable with 9 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_10RANKS  (ADC_SQR1_RL_3                               | ADC_SQR1_RL_0)    /*!< ADC group regular sequencer enable with 10 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_11RANKS  (ADC_SQR1_RL_3                | ADC_SQR1_RL_1               )    /*!< ADC group regular sequencer enable with 11 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_12RANKS  (ADC_SQR1_RL_3                | ADC_SQR1_RL_1 | ADC_SQR1_RL_0)   /*!< ADC group regular sequencer enable with 12 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_13RANKS  (ADC_SQR1_RL_3 | ADC_SQR1_RL_2                              )    /*!< ADC group regular sequencer enable with 13 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_14RANKS  (ADC_SQR1_RL_3 | ADC_SQR1_RL_2               | ADC_SQR1_RL_0)    /*!< ADC group regular sequencer enable with 14 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_15RANKS  (ADC_SQR1_RL_3 | ADC_SQR1_RL_2               | ADC_SQR1_RL_1)    /*!< ADC group regular sequencer enable with 15 ranks in the sequence */
#define DDL_ADC12_REG_SEQ_SCAN_ENABLE_16RANKS  (ADC_SQR1_RL_3 | ADC_SQR1_RL_2 | ADC_SQR1_RL_1 | ADC_SQR1_RL_0)  /*!< ADC group regular sequencer enable with 16 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_SEQ_DISCONT_MODE  ADC group regular - Sequencer discontinuous mode
  * @{
  */
#define DDL_ADC12_REG_SEQ_DISCONT_DISABLE  (0x00000000UL)                                                                    /*!< ADC group regular sequencer discontinuous mode disable */
#define DDL_ADC12_REG_SEQ_DISCONT_1RANK    (                                                               ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every rank */
#define DDL_ADC12_REG_SEQ_DISCONT_2RANKS   (                                          ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enabled with sequence interruption every 2 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_3RANKS   (                     ADC_CFGR_DISCNUM_1                      | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 3 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_4RANKS   (                     ADC_CFGR_DISCNUM_1 | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 4 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_5RANKS   (ADC_CFGR_DISCNUM_2                                           | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 5 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_6RANKS   (ADC_CFGR_DISCNUM_2                      | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 6 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_7RANKS   (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCNUM_1                      | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 7 ranks */
#define DDL_ADC12_REG_SEQ_DISCONT_8RANKS   (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCNUM_1 | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 8 ranks */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_SEQ_RANKS  ADC group regular - Sequencer ranks
  * @{
  */
#define DDL_ADC12_REG_RANK_1   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_1_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 1 */
#define DDL_ADC12_REG_RANK_2   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_2_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 2 */
#define DDL_ADC12_REG_RANK_3   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_3_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 3 */
#define DDL_ADC12_REG_RANK_4   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_4_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 4 */
#define DDL_ADC12_REG_RANK_5   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_5_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 5 */
#define DDL_ADC12_REG_RANK_6   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_6_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 6 */
#define DDL_ADC12_REG_RANK_7   (ADC12_SQR1_REGOFFSET | ADC12_REG_RANK_7_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 7 */
#define DDL_ADC12_REG_RANK_8   (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_8_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 8 */
#define DDL_ADC12_REG_RANK_9   (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_9_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 9 */
#define DDL_ADC12_REG_RANK_10  (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_10_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 10 */
#define DDL_ADC12_REG_RANK_11  (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_11_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 11 */
#define DDL_ADC12_REG_RANK_12  (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_12_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 12 */
#define DDL_ADC12_REG_RANK_13  (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_13_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 13 */
#define DDL_ADC12_REG_RANK_14  (ADC12_SQR2_REGOFFSET | ADC12_REG_RANK_14_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 14 */
#define DDL_ADC12_REG_RANK_15  (ADC12_SQR3_REGOFFSET | ADC12_REG_RANK_15_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 15 */
#define DDL_ADC12_REG_RANK_16  (ADC12_SQR3_REGOFFSET | ADC12_REG_RANK_16_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 16 */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_SEQ_SCAN_LENGTH  ADC group injected - Sequencer scan length
  * @{
  */
#define DDL_ADC12_INJ_SEQ_SCAN_DISABLE        (0x00000000UL)                   /*!< ADC group injected sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define DDL_ADC12_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0)  /*!< ADC group injected sequencer enable with 2 ranks in the sequence */
#define DDL_ADC12_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                )  /*!< ADC group injected sequencer enable with 3 ranks in the sequence */
#define DDL_ADC12_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0)  /*!< ADC group injected sequencer enable with 4 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_SEQ_DISCONT_MODE  ADC group injected - Sequencer discontinuous mode
  * @{
  */
#define DDL_ADC12_INJ_SEQ_DISCONT_DISABLE  (0x00000000UL)      /*!< ADC group injected sequencer discontinuous mode disable */
#define DDL_ADC12_INJ_SEQ_DISCONT_1RANK    (ADC_CFGR_JDISCEN)  /*!< ADC group injected sequencer discontinuous mode enable with sequence interruption every rank */
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC12_DDL_ES_INIT ADC Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of ADC instance.
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on G32R4 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC12_DDL_EF_Configuration_ADC_Instance .
  * @note   The setting of these parameters by function @ref DDL_ADC12_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32R4 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t DataAlignment;  /*!< Set ADC conversion data alignment.*/

} DDL_ADC12_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref DDL_ADC12_REG_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32R4 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t TriggerSource;     /*!< Set ADC group regular conversion trigger source: internal (SW start) or from external peripheral (timer event, external interrupt line). */

  uint32_t SequencerLength;   /*!< Set ADC group regular sequencer length. */

  uint32_t SequencerDiscont;  /*!< Set ADC group regular sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks. */

  uint32_t ContinuousMode;    /*!< Set ADC continuous conversion mode on ADC group regular, whether ADC conversions are performed in single mode (one conversion per trigger) or in continuous mode (after the first trigger, following conversions launched successively automatically). */

  uint32_t DMATransfer;       /*!< Set ADC group regular conversion data transfer: no transfer or transfer by DMA, and DMA requests mode. */

} DDL_ADC12_REG_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group injected.
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "INJ").
  * @note   The setting of these parameters by function @ref DDL_ADC12_INJ_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all G32R4 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t TriggerSource;     /*!< Set ADC group injected conversion trigger source: internal (SW start) or from external peripheral (timer event, external interrupt line). */

  uint32_t SequencerLength;   /*!< Set ADC group injected sequencer length. */

  uint32_t SequencerDiscont;  /*!< Set ADC group injected sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks. */

  uint32_t TrigAuto;          /*!< Set ADC group injected conversion trigger: independent or from ADC group regular. */

} DDL_ADC12_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC12_DDL_Private_Macros ADC Private Macros
  * @{
  */
/** @defgroup ADC12_DDL_EC_REGISTERS  ADC registers compliant with specific purpose
  * @{
  */
/* List of ADC registers intended to be used (most commonly) with             */
/* DMA transfer.                                                              */
/* Refer to function @ref DDL_ADC12_DMA_GetRegAddr().                            */
#define DDL_ADC12_DMA_REG_REGULAR_DATA  (0x00000000UL) /* ADC group regular conversion data register (corresponding to register DR) to be used with ADC configured in independent mode. Without DMA transfer, register accessed by DDL function @ref DDL_ADC12_REG_ReadConversionData32() and other functions @ref DDL_ADC12_REG_ReadConversionDatax() */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_OFFSET_NB  ADC instance - Offset number
  * @{
  */
#define DDL_ADC12_JOFFSET_1  ADC12_OFR0_REGOFFSET  /*!< ADC offset number 0: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC12_JOFFSET_2  ADC12_OFR1_REGOFFSET  /*!< ADC offset number 1: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC12_JOFFSET_3  ADC12_OFR2_REGOFFSET  /*!< ADC offset number 2: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC12_JOFFSET_4  ADC12_OFR3_REGOFFSET  /*!< ADC offset number 3: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_CHANNEL  ADC instance - Channel number
  * @{
  */
#define DDL_ADC12_CHANNEL_0   (ADC12_CHANNEL_0_NUMBER  | ADC12_CHANNEL_0_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN0  */
#define DDL_ADC12_CHANNEL_1   (ADC12_CHANNEL_1_NUMBER  | ADC12_CHANNEL_1_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN1  */
#define DDL_ADC12_CHANNEL_2   (ADC12_CHANNEL_2_NUMBER  | ADC12_CHANNEL_2_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN2  */
#define DDL_ADC12_CHANNEL_3   (ADC12_CHANNEL_3_NUMBER  | ADC12_CHANNEL_3_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN3  */
#define DDL_ADC12_CHANNEL_4   (ADC12_CHANNEL_4_NUMBER  | ADC12_CHANNEL_4_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN4  */
#define DDL_ADC12_CHANNEL_5   (ADC12_CHANNEL_5_NUMBER  | ADC12_CHANNEL_5_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN5  */
#define DDL_ADC12_CHANNEL_6   (ADC12_CHANNEL_6_NUMBER  | ADC12_CHANNEL_6_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN6  */
#define DDL_ADC12_CHANNEL_7   (ADC12_CHANNEL_7_NUMBER  | ADC12_CHANNEL_7_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN7  */
#define DDL_ADC12_CHANNEL_8   (ADC12_CHANNEL_8_NUMBER  | ADC12_CHANNEL_8_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN8  */
#define DDL_ADC12_CHANNEL_9   (ADC12_CHANNEL_9_NUMBER  | ADC12_CHANNEL_9_SMP)   /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN9  */
#define DDL_ADC12_CHANNEL_10  (ADC12_CHANNEL_10_NUMBER | ADC12_CHANNEL_10_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN10  */
#define DDL_ADC12_CHANNEL_11  (ADC12_CHANNEL_11_NUMBER | ADC12_CHANNEL_11_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN11  */
#define DDL_ADC12_CHANNEL_12  (ADC12_CHANNEL_12_NUMBER | ADC12_CHANNEL_12_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN12  */
#define DDL_ADC12_CHANNEL_13  (ADC12_CHANNEL_13_NUMBER | ADC12_CHANNEL_13_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN13  */
#define DDL_ADC12_CHANNEL_14  (ADC12_CHANNEL_14_NUMBER | ADC12_CHANNEL_14_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN14  */
#define DDL_ADC12_CHANNEL_15  (ADC12_CHANNEL_15_NUMBER | ADC12_CHANNEL_15_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN14  */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_CONTINUOUS_MODE  ADC group regular - Continuous mode
  * @{
  */
#define DDL_ADC12_REG_CONV_SINGLE      (0x00000000UL)   /*!< ADC conversions are performed in single mode: one conversion per trigger */
#define DDL_ADC12_REG_CONV_CONTINUOUS  (ADC_CFGR_CONT)  /*!< ADC conversions are performed in continuous mode: after the first trigger, following conversions launched successively automatically */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_REG_DMA_TRANSFER  ADC group regular - DMA transfer of ADC conversion data
  * @{
  */
#define DDL_ADC12_REG_DMA_TRANSFER_DISABLE  (0x00000000UL)                      /*!< ADC conversions are not transferred by DMA */
#define DDL_ADC12_REG_DMA_TRANSFER_ENABLE   (                  ADC_CFGR_DMAEN)  /*!< ADC conversion data are transferred by DMA, in limited mode (one shot mode): DMA transfer requests are stopped when number of DMA data transfers (number of ADC conversions) is reached. This ADC mode is intended to be used with DMA mode non-circular. */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_TRIGGER_SOURCE  ADC group injected - Trigger source
  * @{
  */
#define DDL_ADC12_INJ_TRIG_SOFTWARE         (0x00000000UL)                                                               /*!< ADC group injected conversion trigger internal: SW start.. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR1_TRGO    (ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)                                            /*!< ADC group injected conversion trigger from external peripheral: TMR1_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR1_CC4     (ADC_JSQR_JEXTSEL_0 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR1_CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR2_TRGO    (ADC_JSQR_JEXTSEL_1 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR2_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR2_CC1     (ADC_JSQR_JEXTSEL_1 | ADC_JSQR_JEXTSEL_0 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group injected conversion trigger from external peripheral: TMR2_CC1. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR3_CC4     (ADC_JSQR_JEXTSEL_2 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR3_CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_TMR4_TRGO    (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_0 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group injected conversion trigger from external peripheral: TMR4_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC12_INJ_TRIG_EXT_EINT_LINE15  (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_1 | ADC12_INJ_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group injected conversion trigger from external peripheral: EINT_LINE15. Trigger edge set to rising edge (default setting). */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_TRIGGER_EDGE  ADC group injected - Trigger edge
  * @{
  */
#define DDL_ADC12_INJ_TRIG_EXT_RISING   (                    ADC_JSQR_JEXTEN_0)  /*!< ADC group injected conversion trigger polarity set to rising edge */
#define DDL_ADC12_INJ_TRIG_EXT_DISABLE  (0x00000000UL)                           /*!< ADC group injected conversion trigger polarity set to falling edge */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_SEQ_RANKS  ADC group injected - Sequencer ranks
  * @{
  */
#define DDL_ADC12_INJ_RANK_1  (ADC12_JDR1_REGOFFSET | ADC12_INJ_RANK_1_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 1 */
#define DDL_ADC12_INJ_RANK_2  (ADC12_JDR2_REGOFFSET | ADC12_INJ_RANK_2_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 2 */
#define DDL_ADC12_INJ_RANK_3  (ADC12_JDR3_REGOFFSET | ADC12_INJ_RANK_3_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 3 */
#define DDL_ADC12_INJ_RANK_4  (ADC12_JDR4_REGOFFSET | ADC12_INJ_RANK_4_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 4 */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_INJ_TRIG_AUTO  ADC group injected - Automatic trigger mode
  * @{
  */
#define DDL_ADC12_INJ_TRIG_INDEPENDENT       (0x00000000UL)    /*!< ADC group injected conversion trigger independent. Setting mandatory if ADC group injected injected trigger source is set to an external trigger. */
#define DDL_ADC12_INJ_TRIG_FROM_GRP_REGULAR  (ADC_CFGR_JAUTO)  /*!< ADC group injected conversion trigger from ADC group regular. Setting compliant only with group injected trigger source set to SW start, without any further action on  ADC group injected conversion start or stop: in this case, ADC group injected is controlled only from ADC group regular. */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_CHANNEL_SAMPLINGTIME  Channel - Sampling time
  * @{
  */
#define DDL_ADC12_SAMPLINGTIME_7CYCLES    (0x00000000)
#define DDL_ADC12_SAMPLINGTIME_16CYCLES   (ADC_SMPR1_SMP0_0)
#define DDL_ADC12_SAMPLINGTIME_27CYCLES   (ADC_SMPR1_SMP0_1)
#define DDL_ADC12_SAMPLINGTIME_32CYCLES   (ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)
#define DDL_ADC12_SAMPLINGTIME_67CYCLES   (ADC_SMPR1_SMP0_2)
#define DDL_ADC12_SAMPLINGTIME_96CYCLES   (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_0)
#define DDL_ADC12_SAMPLINGTIME_128CYCLES  (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1)
#define DDL_ADC12_SAMPLINGTIME_256CYCLES  (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)

/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_AWD_NUMBER Analog watchdog - Analog watchdog number
  * @{
  */
#define DDL_ADC12_AWD1  (ADC12_AWD_CR1_CHANNEL_MASK  | ADC12_AWD_CR1_REGOFFSET)  /*!< ADC analog watchdog number 1 */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_AWD_CHANNELS  Analog watchdog - Monitored channels
  * @{
  */
#define DDL_ADC12_AWD_DISABLE               (0x00000000UL)                                                                                            /*!< ADC analog watchdog monitoring disabled */
#define DDL_ADC12_AWD_ALL_CHANNELS_REG      (ADC_CFGR_AWD1EN                                                                                   )      /*!< ADC analog watchdog monitoring of all channels, converted by group regular only */
#define DDL_ADC12_AWD_ALL_CHANNELS_INJ      (ADC_CFGR_JAWD1EN                                                                                  )      /*!< ADC analog watchdog monitoring of all channels, converted by group injected only */
#define DDL_ADC12_AWD_ALL_CHANNELS_REG_INJ  (ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN                                                                )      /*!< ADC analog watchdog monitoring of all channels, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_0_REG         ((DDL_ADC12_CHANNEL_0  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN0, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_0_INJ         ((DDL_ADC12_CHANNEL_0  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN0, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_0_REG_INJ     ((DDL_ADC12_CHANNEL_0  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN0, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_1_REG         ((DDL_ADC12_CHANNEL_1  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN1, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_1_INJ         ((DDL_ADC12_CHANNEL_1  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN1, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_1_REG_INJ     ((DDL_ADC12_CHANNEL_1  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN1, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_2_REG         ((DDL_ADC12_CHANNEL_2  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN2, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_2_INJ         ((DDL_ADC12_CHANNEL_2  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN2, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_2_REG_INJ     ((DDL_ADC12_CHANNEL_2  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN2, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_3_REG         ((DDL_ADC12_CHANNEL_3  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN3, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_3_INJ         ((DDL_ADC12_CHANNEL_3  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN3, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_3_REG_INJ     ((DDL_ADC12_CHANNEL_3  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN3, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_4_REG         ((DDL_ADC12_CHANNEL_4  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN4, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_4_INJ         ((DDL_ADC12_CHANNEL_4  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN4, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_4_REG_INJ     ((DDL_ADC12_CHANNEL_4  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN4, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_5_REG         ((DDL_ADC12_CHANNEL_5  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN5, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_5_INJ         ((DDL_ADC12_CHANNEL_5  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN5, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_5_REG_INJ     ((DDL_ADC12_CHANNEL_5  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN5, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_6_REG         ((DDL_ADC12_CHANNEL_6  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN6, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_6_INJ         ((DDL_ADC12_CHANNEL_6  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN6, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_6_REG_INJ     ((DDL_ADC12_CHANNEL_6  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN6, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_7_REG         ((DDL_ADC12_CHANNEL_7  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN7, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_7_INJ         ((DDL_ADC12_CHANNEL_7  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN7, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_7_REG_INJ     ((DDL_ADC12_CHANNEL_7  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN7, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_8_REG         ((DDL_ADC12_CHANNEL_8  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN8, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_8_INJ         ((DDL_ADC12_CHANNEL_8  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN8, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_8_REG_INJ     ((DDL_ADC12_CHANNEL_8  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN8, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_9_REG         ((DDL_ADC12_CHANNEL_9  & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN9, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_9_INJ         ((DDL_ADC12_CHANNEL_9  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN9, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_9_REG_INJ     ((DDL_ADC12_CHANNEL_9  & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN9, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_10_REG        ((DDL_ADC12_CHANNEL_10 & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN10, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_10_INJ        ((DDL_ADC12_CHANNEL_10 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN10, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_10_REG_INJ    ((DDL_ADC12_CHANNEL_10 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN10, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_11_REG        ((DDL_ADC12_CHANNEL_11 & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN11, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_11_INJ        ((DDL_ADC12_CHANNEL_11 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN11, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_11_REG_INJ    ((DDL_ADC12_CHANNEL_11 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN11, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_12_REG        ((DDL_ADC12_CHANNEL_12 & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN12, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_12_INJ        ((DDL_ADC12_CHANNEL_12 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN12, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_12_REG_INJ    ((DDL_ADC12_CHANNEL_12 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN12, converted by either group regular or injected */
#define DDL_ADC12_AWD_CHANNEL_13_REG        ((DDL_ADC12_CHANNEL_13 & ADC12_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN13, converted by group regular only */
#define DDL_ADC12_AWD_CHANNEL_13_INJ        ((DDL_ADC12_CHANNEL_13 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN13, converted by group injected only */
#define DDL_ADC12_AWD_CHANNEL_13_REG_INJ    ((DDL_ADC12_CHANNEL_13 & ADC12_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) ADCx_IN13, converted by either group regular or injected */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_AWD_THRESHOLDS  Analog watchdog - Thresholds
  * @{
  */
#define DDL_ADC12_AWD_THRESHOLD_HIGH       (ADC_TR1_HT1              )  /*!< ADC analog watchdog threshold high */
#define DDL_ADC12_AWD_THRESHOLD_LOW        (              ADC_TR1_LT1)  /*!< ADC analog watchdog threshold low */
#define DDL_ADC12_AWD_THRESHOLDS_HIGH_LOW  (ADC_TR1_HT1 | ADC_TR1_LT1)  /*!< ADC analog watchdog both thresholds high and low concatenated into the same data */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_FLAG ADC flags
  * @brief    Flags defines which can be used with DDL_ADC12_ReadReg function
  * @{
  */
#define DDL_ADC12_FLAG_EOC   ADC_ISR_EOC   /*!< ADC flag ADC group regular end of unitary conversion */
#define DDL_ADC12_FLAG_EOS   ADC_ISR_EOS   /*!< ADC flag ADC group regular end of sequence conversions */
#define DDL_ADC12_FLAG_JEOC  ADC_ISR_JEOC  /*!< ADC flag ADC group injected end of unitary conversion */
#define DDL_ADC12_FLAG_JEOS  ADC_ISR_JEOS  /*!< ADC flag ADC group injected end of sequence conversions */
#define DDL_ADC12_FLAG_AWD1  ADC_ISR_AWD1  /*!< ADC flag ADC analog watchdog 1 */
/**
  * @}
  */

/** @defgroup ADC12_DDL_EC_IT ADC interruptions for configuration (interruption enable or disable)
  * @brief    IT defines which can be used with DDL_ADC12_ReadReg and  DDL_ADC12_WriteReg functions
  * @{
  */
#define DDL_ADC12_IT_EOC   ADC_IER_EOCIE   /*!< ADC interruption ADC group regular end of unitary conversion */
#define DDL_ADC12_IT_EOS   ADC_IER_EOSIE   /*!< ADC interruption ADC group regular end of sequence conversions */
#define DDL_ADC12_IT_JEOC  ADC_IER_JEOCIE  /*!< ADC interruption ADC group injected end of unitary conversion */
#define DDL_ADC12_IT_JEOS  ADC_IER_JEOSIE  /*!< ADC interruption ADC group injected end of sequence conversions */
#define DDL_ADC12_IT_AWD1  ADC_IER_AWD1IE  /*!< ADC interruption ADC analog watchdog 1 */
/**
  * @}
  */

/**
 * @defgroup Data alignment
  * @{
  */
#define DDL_ADC12_ALIGNMENT_LEFT   ADC_CFGR_ALIGN
#define DDL_ADC12_ALIGNMENT_RIGHT  (0x00000000UL)
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC12_DDL_Private_Macros ADC Private Macros
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
#define __ADC12_PTR_REG_OFFSET(__REG__,                 __REG_OFFFSET__)                         \
  ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2UL))))

/**
  * @brief  Helper macro to get ADC channel number in decimal format
  *         from literals DDL_ADC12_CHANNEL_x.
  * @note   Example:
  *           __DDL_ADC12_CHANNEL_TO_DECIMAL_NB(DDL_ADC12_CHANNEL_4)
  *           will return decimal number "4".
  * @note   The input can be a value from functions where a channel
  *         number is returned, either defined with number
  *         or with bitfield (only one bit must be set).
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @retval Value between Min_Data=0 and Max_Data=15
  */
#define __DDL_ADC12_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)  ((uint32_t)((__CHANNEL__ & ADC_CFGR_AWD1CH_Msk) >> ADC_CFGR_AWD1CH_Pos))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC12_DDL_Exported_Functions ADC Exported Functions
  * @{
  */
/** @defgroup ADC12_DDL_EF_DMA_Management ADC DMA management
  * @{
  */
/* Note: DDL ADC functions to set DMA transfer are located into sections of    */
/*       configuration of ADC instance, groups and multimode (if available):  */
/*       @ref DDL_ADC12_REG_SetDMATransfer(), ...                                */

/**
  * @brief  Function to help to configure DMA transfer from ADC: retrieve the
  *         ADC register address from ADC instance and a list of ADC registers
  *         intended to be used (most commonly) with DMA transfer.
  * @note   These ADC registers are data registers:
  *         when ADC conversion data is available in ADC data registers,
  *         ADC generates a DMA transfer request.
  * @note   This macro is intended to be used with DDL DMA driver, refer to
  *         function "DDL_DMA_ConfigAddresses()".
  *         Example:
  *           DDL_DMA_ConfigAddresses(DMA1,
  *                                  DDL_DMA_CHANNEL_1,
  *                                  DDL_ADC12_DMA_GetRegAddr(ADC2, DDL_ADC12_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< array or variable >,
  *                                  DDL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   For devices with several ADC: in multimode, some devices
  *         use a different data register outside of ADC instance scope
  *         (common data register). This macro manages this register difference,
  *         only ADC instance has to be set as parameter.
  * @param  ADCx ADC instance
  * @param  Register This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_DMA_REG_REGULAR_DATA
  *         @arg @ref DDL_ADC12_DMA_REG_REGULAR_DATA_MULTI (1)
  *
  *         (1) Available on devices with several ADC instances.
  * @retval ADC register address
  */
__STATIC_INLINE uint32_t DDL_ADC12_DMA_GetRegAddr(ADC12_TypeDef *ADCx, uint32_t Register)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(Register);

  /* Retrieve address of register DR */
  return (uint32_t) &(ADCx->DR);
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Configuration_ADC12_Instance Configuration of ADC hierarchical scope: ADC instance
  * @{
  */

/**
  * @brief  Set ADC selected offset number 1, 2, 3 or 4.
  * @note   This function set the 2 items of offset configuration:
  *         - ADC channel to which the offset programmed will be applied
  *           (independently of channel mapped on ADC group regular
  *           or group injected)
  *         - Offset level (offset to be subtracted from the raw
  *           converted data).
  * @note   This function enables the offset, by default. It can be forced
  *         to disable state using function DDL_ADC12_SetOffsetState().
  * @note   If a channel is mapped on several offsets numbers, only the offset
  *         with the lowest value is considered for the subtraction.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_JOFFSET_1
  *         @arg @ref DDL_ADC12_JOFFSET_2
  *         @arg @ref DDL_ADC12_JOFFSET_3
  *         @arg @ref DDL_ADC12_JOFFSET_4
  *
  * @param  OffsetLevel Value between Min_Data=0x0000 and Max_Data=0xFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetOffset(ADC12_TypeDef *ADCx, uint32_t Offsety, uint32_t OffsetLevel)
{
  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->JOFFSET1, Offsety);

  MODIFY_REG(*preg,
             ADC_JOFFSET1_JOFFSET1,
             OffsetLevel);
}

/**
  * @brief  Get for the ADC selected offset number 1, 2, 3 or 4:
  *         Offset level (offset to be subtracted from the raw
  *         converted data).
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_JOFFSET_1
  *         @arg @ref DDL_ADC12_JOFFSET_2
  *         @arg @ref DDL_ADC12_JOFFSET_3
  *         @arg @ref DDL_ADC12_JOFFSET_4
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFF
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetOffset(ADC12_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->JOFFSET1, Offsety);

  return (uint32_t)READ_BIT(*preg, ADC_JOFFSET1_JOFFSET1);
}

 /**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Configuration_ADC12_Group_Regular Configuration of ADC hierarchical scope: group regular
  * @{
  */
/**
  * @brief  Set ADC group regular conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC1
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC2
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC3
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR2_CC2
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR3_TRGO
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR4_CC4
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_EINT_LINE11
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetTriggerSource(ADC12_TypeDef *ADCx, uint32_t TriggerSource)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTEN | ADC_CFGR_EXTSEL, TriggerSource);
}

/**
  * @brief Get ADC group regular conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC1
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC2
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR1_CC3
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR2_CC2
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR3_TRGO
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_TMR4_CC4
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_EINT_LINE11
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetTriggerSource(ADC12_TypeDef *ADCx)
{
  return (uint32_t)READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN | ADC_CFGR_EXTSEL);
}

/**
  * @brief  Get ADC group regular conversion trigger source internal (SW start)
  *         or external.
  * @param  ADCx ADC instance
  * @retval Value "0" if trigger source external trigger
  *         Value "1" if trigger source SW start.
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_IsTriggerSourceSWStart(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN) == (DDL_ADC12_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_DISABLE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetTriggerEdge(ADC12_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTEN, ExternalTriggerEdge);
}

/**
  * @brief  Get ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC12_REG_TRIG_EXT_DISABLE
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetTriggerEdge(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN));
}

/**
  * @brief  Set ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC12_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function performs configuration of:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC12_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC12_REG_SetSequencerChannels()" available):
  *           sequencer length and each rank affectation to a channel
  *           are defined by channel number.
  *           This function performs configuration of:
  *           - Sequence length: Number of ranks in the scan sequence is
  *             defined by number of channels set in the sequence,
  *             rank of each channel is fixed by channel HW number.
  *             (channel 0 fixed on rank 0, channel 1 fixed on rank1, ...).
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from lowest channel number to
  *             highest channel number).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC12_REG_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_16RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetSequencerLength(ADC12_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_RL, SequencerNbRanks);
}

/**
  * @brief  Get ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC12_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function retrieves:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC12_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC12_REG_SetSequencerChannels()" available):
  *           sequencer length and each rank affectation to a channel
  *           are defined by channel number.
  *           This function retrieves:
  *           - Sequence length: Number of ranks in the scan sequence is
  *             defined by number of channels set in the sequence,
  *             rank of each channel is fixed by channel HW number.
  *             (channel 0 fixed on rank 0, channel 1 fixed on rank1, ...).
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from lowest channel number to
  *             highest channel number).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC12_REG_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_SCAN_ENABLE_16RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetSequencerLength(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SQR1, ADC_SQR1_RL));
}

/**
  * @brief  Set ADC group regular sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @note   It is not possible to enable both ADC group regular
  *         continuous mode and sequencer discontinuous mode.
  * @note   It is not possible to enable both ADC auto-injected mode
  *         and ADC group regular sequencer discontinuous mode.
  * @param  ADCx ADC instance
  * @param  SeqDiscont This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_8RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetSequencerDiscont(ADC12_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM, SeqDiscont);
}

/**
  * @brief  Get ADC group regular sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref DDL_ADC12_REG_SEQ_DISCONT_8RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetSequencerDiscont(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM));
}

/**
  * @brief  Set ADC group regular sequence: channel on the selected
  *         scan sequence rank.
  * @note   This function performs configuration of:
  *         - Channels ordering into each rank of scan sequence:
  *           whatever channel can be placed into whatever rank.
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_RANK_1
  *         @arg @ref DDL_ADC12_REG_RANK_2
  *         @arg @ref DDL_ADC12_REG_RANK_3
  *         @arg @ref DDL_ADC12_REG_RANK_4
  *         @arg @ref DDL_ADC12_REG_RANK_5
  *         @arg @ref DDL_ADC12_REG_RANK_6
  *         @arg @ref DDL_ADC12_REG_RANK_7
  *         @arg @ref DDL_ADC12_REG_RANK_8
  *         @arg @ref DDL_ADC12_REG_RANK_9
  *         @arg @ref DDL_ADC12_REG_RANK_10
  *         @arg @ref DDL_ADC12_REG_RANK_11
  *         @arg @ref DDL_ADC12_REG_RANK_12
  *         @arg @ref DDL_ADC12_REG_RANK_13
  *         @arg @ref DDL_ADC12_REG_RANK_14
  *         @arg @ref DDL_ADC12_REG_RANK_15
  *         @arg @ref DDL_ADC12_REG_RANK_16
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetSequencerRanks(ADC12_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Channel" with bits position          */
  /* in register and register position depending on parameter "Rank".         */
  /* Parameters "Rank" and "Channel" are used with masks because containing   */
  /* other bits reserved for other purpose.                                   */
  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->SQR1, ((Rank & ADC12_REG_SQRX_REGOFFSET_MASK) >> ADC12_SQRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC12_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC12_REG_RANK_ID_SQRX_MASK),
             ((Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC12_REG_RANK_ID_SQRX_MASK));
}

/**
  * @brief  Get ADC group regular sequence: channel on the selected
  *         scan sequence rank.
  *         Refer to description of function @ref DDL_ADC12_REG_SetSequencerLength().
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function DDL_ADC12_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals DDL_ADC12_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals DDL_ADC12_CHANNEL_x or using
  *           helper macro @ref __DDL_ADC12_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal DDL_ADC12_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __DDL_ADC12_CHANNEL_TO_DECIMAL_NB().
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_RANK_1
  *         @arg @ref DDL_ADC12_REG_RANK_2
  *         @arg @ref DDL_ADC12_REG_RANK_3
  *         @arg @ref DDL_ADC12_REG_RANK_4
  *         @arg @ref DDL_ADC12_REG_RANK_5
  *         @arg @ref DDL_ADC12_REG_RANK_6
  *         @arg @ref DDL_ADC12_REG_RANK_7
  *         @arg @ref DDL_ADC12_REG_RANK_8
  *         @arg @ref DDL_ADC12_REG_RANK_9
  *         @arg @ref DDL_ADC12_REG_RANK_10
  *         @arg @ref DDL_ADC12_REG_RANK_11
  *         @arg @ref DDL_ADC12_REG_RANK_12
  *         @arg @ref DDL_ADC12_REG_RANK_13
  *         @arg @ref DDL_ADC12_REG_RANK_14
  *         @arg @ref DDL_ADC12_REG_RANK_15
  *         @arg @ref DDL_ADC12_REG_RANK_16
  * @retval Returned value can be one of the following values:
  *         @arg @ref ADC12_CHANNEL_0_NUMBER
  *         @arg @ref ADC12_CHANNEL_1_NUMBER
  *         @arg @ref ADC12_CHANNEL_2_NUMBER
  *         @arg @ref ADC12_CHANNEL_3_NUMBER
  *         @arg @ref ADC12_CHANNEL_4_NUMBER
  *         @arg @ref ADC12_CHANNEL_5_NUMBER
  *         @arg @ref ADC12_CHANNEL_6_NUMBER
  *         @arg @ref ADC12_CHANNEL_7_NUMBER
  *         @arg @ref ADC12_CHANNEL_8_NUMBER
  *         @arg @ref ADC12_CHANNEL_9_NUMBER
  *         @arg @ref ADC12_CHANNEL_10_NUMBER
  *         @arg @ref ADC12_CHANNEL_11_NUMBER
  *         @arg @ref ADC12_CHANNEL_12_NUMBER
  *         @arg @ref ADC12_CHANNEL_13_NUMBER
  *         @arg @ref ADC12_CHANNEL_14_NUMBER
  *         @arg @ref ADC12_CHANNEL_15_NUMBER
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetSequencerRanks(ADC12_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->SQR1, ((Rank & ADC12_REG_SQRX_REGOFFSET_MASK) >> ADC12_SQRX_REGOFFSET_POS));

  return (uint32_t)((READ_BIT(*preg,
                              ADC12_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC12_REG_RANK_ID_SQRX_MASK))
                     >> (Rank & ADC12_REG_RANK_ID_SQRX_MASK)) << ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS
                   );
}

/**
  * @brief  Set ADC continuous conversion mode on ADC group regular.
  * @note   Description of ADC continuous conversion mode:
  *         - single mode: one conversion per trigger
  *         - continuous mode: after the first trigger, following
  *           conversions launched successively automatically.
  * @note   It is not possible to enable both ADC group regular
  *         continuous mode and sequencer discontinuous mode.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  Continuous This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC12_REG_CONV_CONTINUOUS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetContinuousMode(ADC12_TypeDef *ADCx, uint32_t Continuous)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_CONT, Continuous);
}

/**
  * @brief  Get ADC continuous conversion mode on ADC group regular.
  * @note   Description of ADC continuous conversion mode:
  *         - single mode: one conversion per trigger
  *         - continuous mode: after the first trigger, following
  *           conversions launched successively automatically.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC12_REG_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetContinuousMode(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_CONT));
}

/**
  * @brief  Set ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *        (overrun flag and interruption if enabled).
  * @note   For devices with several ADC instances: ADC multimode DMA
  *         settings are available using function @ref DDL_ADC12_SetMultiDMATransfer().
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC12_DMA_GetRegAddr().
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  DMATransfer This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_DMA_TRANSFER_DISABLE
  *         @arg @ref DDL_ADC12_REG_DMA_TRANSFER_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_SetDMATransfer(ADC12_TypeDef *ADCx, uint32_t DMATransfer)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DMAEN, DMATransfer);
}

/**
  * @brief  Get ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *         (overrun flag and interruption if enabled).
  * @note   For devices with several ADC instances: ADC multimode DMA
  *         settings are available using function @ref DDL_ADC12_GetMultiDMATransfer().
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC12_DMA_GetRegAddr().
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_REG_DMA_TRANSFER_DISABLE
  *         @arg @ref DDL_ADC12_REG_DMA_TRANSFER_ENABLE
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_GetDMATransfer(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DMAEN));
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Configuration_ADC12_Group_Injected Configuration of ADC hierarchical scope: group injected
  * @{
  */
/**
  * @brief  Set ADC group injected conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @note
  *         ADC must not be disabled. Can be enabled with or without conversion
  *         on going on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR3_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_EINT_LINE15
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetTriggerSource(ADC12_TypeDef *ADCx, uint32_t TriggerSource)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN, TriggerSource);
}

/**
  * @brief  Get ADC group injected conversion trigger source:
  *         internal (SW start) or from external peripheral (timer event,
  *         external interrupt line).
  * @note   Availability of parameters of trigger sources from timer
  *         depends on timers availability on the selected device.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR3_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_EINT_LINE15
  *
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetTriggerSource(ADC12_TypeDef *ADCx)
{
  return (uint32_t)READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN);
}

/**
  * @brief  Get ADC group injected conversion trigger source internal (SW start)
            or external
  * @param  ADCx ADC instance
  * @retval Value "0" if trigger source external trigger
  *         Value "1" if trigger source SW start.
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_IsTriggerSourceSWStart(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTEN) == (DDL_ADC12_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN)) ? 1UL : 0UL);
}
/**
  * @brief  Set ADC group injected conversion trigger polarity.
  *         Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must not be disabled. Can be enabled with or without conversion
  *         on going on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_DISABLE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetTriggerEdge(ADC12_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JEXTEN, ExternalTriggerEdge);
}

/**
  * @brief  Get ADC group injected conversion trigger polarity.
  *         Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_DISABLE
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetTriggerEdge(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTEN));
}

/**
  * @brief  Set ADC group injected sequencer length and scan direction.
  * @note   This function performs configuration of:
  *         - Sequence length: Number of ranks in the scan sequence.
  *         - Sequence direction: Unless specified in parameters, sequencer
  *           scan direction is forward (from rank 1 to rank n).
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @note
  *         ADC must not be disabled. Can be enabled with or without conversion
  *         on going on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_4RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetSequencerLength(ADC12_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JL, SequencerNbRanks);
}

/**
  * @brief  Get ADC group injected sequencer length and scan direction.
  * @note   This function retrieves:
  *         - Sequence length: Number of ranks in the scan sequence.
  *         - Sequence direction: Unless specified in parameters, sequencer
  *           scan direction is forward (from rank 1 to rank n).
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_4RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetSequencerLength(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JL));
}

/**
  * @brief  Set ADC group injected sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @note   It is not possible to enable both ADC group injected
  *         auto-injected mode and sequencer discontinuous mode.
  * @param  ADCx ADC instance
  * @param  SeqDiscont This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC12_INJ_SEQ_DISCONT_1RANK
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetSequencerDiscont(ADC12_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JDISCEN, SeqDiscont);
}

/**
  * @brief  Get ADC group injected sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC12_INJ_SEQ_DISCONT_1RANK
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetSequencerDiscont(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JDISCEN));
}

/**
  * @brief  Set ADC group injected sequence: channel on the selected
  *         sequence rank.
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_RANK_1
  *         @arg @ref DDL_ADC12_INJ_RANK_2
  *         @arg @ref DDL_ADC12_INJ_RANK_3
  *         @arg @ref DDL_ADC12_INJ_RANK_4
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetSequencerRanks(ADC12_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Channel" with bits position          */
  /* in register depending on parameter "Rank".                               */
  /* Parameters "Rank" and "Channel" are used with masks because containing   */
  /* other bits reserved for other purpose.                                   */
  MODIFY_REG(ADCx->JSQR,
             (ADC12_CHANNEL_ID_NUMBER_MASK >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC12_INJ_RANK_ID_JSQR_MASK),
             ((Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC12_INJ_RANK_ID_JSQR_MASK));
}

/**
  * @brief  Get ADC group injected sequence: channel on the selected
  *         sequence rank.
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_RANK_1
  *         @arg @ref DDL_ADC12_INJ_RANK_2
  *         @arg @ref DDL_ADC12_INJ_RANK_3
  *         @arg @ref DDL_ADC12_INJ_RANK_4
  * @retval Returned value can be one of the following values:
  *         @arg @ref ADC12_CHANNEL_0_NUMBER
  *         @arg @ref ADC12_CHANNEL_1_NUMBER
  *         @arg @ref ADC12_CHANNEL_2_NUMBER
  *         @arg @ref ADC12_CHANNEL_3_NUMBER
  *         @arg @ref ADC12_CHANNEL_4_NUMBER
  *         @arg @ref ADC12_CHANNEL_5_NUMBER
  *         @arg @ref ADC12_CHANNEL_6_NUMBER
  *         @arg @ref ADC12_CHANNEL_7_NUMBER
  *         @arg @ref ADC12_CHANNEL_8_NUMBER
  *         @arg @ref ADC12_CHANNEL_9_NUMBER
  *         @arg @ref ADC12_CHANNEL_10_NUMBER
  *         @arg @ref ADC12_CHANNEL_11_NUMBER
  *         @arg @ref ADC12_CHANNEL_12_NUMBER
  *         @arg @ref ADC12_CHANNEL_13_NUMBER
  *         @arg @ref ADC12_CHANNEL_14_NUMBER
  *         @arg @ref ADC12_CHANNEL_15_NUMBER
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetSequencerRanks(ADC12_TypeDef *ADCx, uint32_t Rank)
{
  return (uint32_t)((READ_BIT(ADCx->JSQR,
                              (ADC12_CHANNEL_ID_NUMBER_MASK >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC12_INJ_RANK_ID_JSQR_MASK))
                     >> (Rank & ADC12_INJ_RANK_ID_JSQR_MASK)) << ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS
                   );
}

/**
  * @brief  Set ADC group injected conversion trigger:
  *         independent or from ADC group regular.
  * @note   This mode can be used to extend number of data registers
  *         updated after one ADC conversion trigger and with data
  *         permanently kept (not erased by successive conversions of scan of
  *         ADC sequencer ranks), up to 5 data registers:
  *         1 data register on ADC group regular, 4 data registers
  *         on ADC group injected.
  * @note   If ADC group injected injected trigger source is set to an
  *         external trigger, this feature must be must be set to
  *         independent trigger.
  *         ADC group injected automatic trigger is compliant only with
  *         group injected trigger source set to SW start, without any
  *         further action on  ADC group injected conversion start or stop:
  *         in this case, ADC group injected is controlled only
  *         from ADC group regular.
  * @note   It is not possible to enable both ADC group injected
  *         auto-injected mode and sequencer discontinuous mode.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  TrigAuto This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_INDEPENDENT
  *         @arg @ref DDL_ADC12_INJ_TRIG_FROM_GRP_REGULAR
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_SetTrigAuto(ADC12_TypeDef *ADCx, uint32_t TrigAuto)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JAUTO, TrigAuto);
}

/**
  * @brief  Get ADC group injected conversion trigger:
  *         independent or from ADC group regular.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_INDEPENDENT
  *         @arg @ref DDL_ADC12_INJ_TRIG_FROM_GRP_REGULAR
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_GetTrigAuto(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JAUTO));
}

/**
  * @brief  Set one context on ADC group injected that will be checked in
  *         contexts queue.
  * @note   A context is a setting of group injected sequencer:
  *         - group injected trigger
  *         - sequencer length
  *         - sequencer ranks
  *         This function is intended to be used when contexts queue is enabled,
  *         because the sequence must be fully configured in one time
  *         (functions to set separately injected trigger and sequencer channels
  *         cannot be used):
  *         Refer to function @ref DDL_ADC12_INJ_SetQueueMode().
  * @note   In the contexts queue, only the active context can be read.
  *         The parameters of this function can be read using functions:
  *         @arg @ref DDL_ADC12_INJ_GetTriggerSource()
  *         @arg @ref DDL_ADC12_INJ_GetTriggerEdge()
  *         @arg @ref DDL_ADC12_INJ_GetSequencerRanks()
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR3_CC4
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_EINT_LINE15
  *
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC12_INJ_TRIG_EXT_DISABLE
  *
  *         Note: This parameter is discarded in case of SW start:
  *               parameter "TriggerSource" set to "DDL_ADC12_INJ_TRIG_SOFTWARE".
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC12_INJ_SEQ_SCAN_ENABLE_4RANKS
  * @param  Rank1_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @param  Rank2_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @param  Rank3_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @param  Rank4_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_ConfigQueueContext(ADC12_TypeDef *ADCx,
                                                   uint32_t TriggerSource,
                                                   uint32_t ExternalTriggerEdge,
                                                   uint32_t SequencerNbRanks,
                                                   uint32_t Rank1_Channel,
                                                   uint32_t Rank2_Channel,
                                                   uint32_t Rank3_Channel,
                                                   uint32_t Rank4_Channel)
{
  /* Set bits with content of parameter "Rankx_Channel" with bits position    */
  /* in register depending on literal "DDL_ADC12_INJ_RANK_x".                    */
  /* Parameters "Rankx_Channel" and "DDL_ADC12_INJ_RANK_x" are used with masks   */
  /* because containing other bits reserved for other purpose.                */
  /* If parameter "TriggerSource" is set to SW start, then parameter          */
  /* "ExternalTriggerEdge" is discarded.                                      */
  uint32_t is_trigger_not_sw = (uint32_t)((TriggerSource != DDL_ADC12_INJ_TRIG_SOFTWARE) ? 1UL : 0UL);
  MODIFY_REG(ADCx->JSQR,
             ADC_JSQR_JEXTSEL |
             ADC_JSQR_JEXTEN  |
             ADC_JSQR_JSQ4    |
             ADC_JSQR_JSQ3    |
             ADC_JSQR_JSQ2    |
             ADC_JSQR_JSQ1    |
             ADC_JSQR_JL,
             (TriggerSource & ADC_JSQR_JEXTSEL)          |
             (ExternalTriggerEdge * (is_trigger_not_sw)) |
             (((Rank4_Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC12_INJ_RANK_4 & ADC12_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank3_Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC12_INJ_RANK_3 & ADC12_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank2_Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC12_INJ_RANK_2 & ADC12_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank1_Channel & ADC12_CHANNEL_ID_NUMBER_MASK) >> ADC12_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC12_INJ_RANK_1 & ADC12_INJ_RANK_ID_JSQR_MASK)) |
             SequencerNbRanks
            );
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Configuration_Channels Configuration of ADC hierarchical scope: channels
  * @{
  */
/**
  * @brief  Set sampling time of the selected ADC channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @note   In case of internal channel (VrefInt, TempSensor, ...) to be
  *         converted:
  *         sampling time constraints must be respected (sampling time can be
  *         adjusted in function of ADC clock frequency and sampling time
  *         setting).
  *         Refer to device datasheet for timings values (parameters TS_vrefint,
  *         TS_temp, ...).
  * @note   In case of ADC conversion of internal channel (VrefInt,
  *         temperature sensor, ...), a sampling time minimum value
  *         is required.
  *         Refer to device datasheet.
  * @param  ADCx ADC instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_16CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_27CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_32CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_67CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_96CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_128CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_256CYCLES
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_SetChannelSamplingTime(ADC12_TypeDef *ADCx, uint32_t Channel, uint32_t SamplingTime)
{
  /* Set bits with content of parameter "SamplingTime" with bits position     */
  /* in register and register position depending on parameter "Channel".      */
  /* Parameter "Channel" is used with masks because containing                */
  /* other bits reserved for other purpose.                                   */

  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->SMPR1, ((Channel & ADC12_CHANNEL_SMPRX_REGOFFSET_MASK) >> ADC12_SMPRX_REGOFFSET_POS));
  MODIFY_REG(*preg,
             ADC_SMPR1_SMP0 << ((Channel & ADC12_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC12_CHANNEL_SMPx_BITOFFSET_POS),
             SamplingTime   << ((Channel & ADC12_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC12_CHANNEL_SMPx_BITOFFSET_POS));
}

/**
  * @brief  Get sampling time of the selected ADC channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @param  ADCx ADC instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_CHANNEL_0
  *         @arg @ref DDL_ADC12_CHANNEL_1
  *         @arg @ref DDL_ADC12_CHANNEL_2
  *         @arg @ref DDL_ADC12_CHANNEL_3
  *         @arg @ref DDL_ADC12_CHANNEL_4
  *         @arg @ref DDL_ADC12_CHANNEL_5
  *         @arg @ref DDL_ADC12_CHANNEL_6
  *         @arg @ref DDL_ADC12_CHANNEL_7
  *         @arg @ref DDL_ADC12_CHANNEL_8
  *         @arg @ref DDL_ADC12_CHANNEL_9
  *         @arg @ref DDL_ADC12_CHANNEL_10
  *         @arg @ref DDL_ADC12_CHANNEL_11
  *         @arg @ref DDL_ADC12_CHANNEL_12
  *         @arg @ref DDL_ADC12_CHANNEL_13
  *         @arg @ref DDL_ADC12_CHANNEL_14
  *         @arg @ref DDL_ADC12_CHANNEL_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_16CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_27CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_32CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_67CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_96CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_128CYCLES
  *         @arg @ref DDL_ADC12_SAMPLINGTIME_256CYCLES
  */
__STATIC_INLINE uint32_t DDL_ADC12_GetChannelSamplingTime(ADC12_TypeDef *ADCx, uint32_t Channel)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->SMPR1, ((Channel & ADC12_CHANNEL_SMPRX_REGOFFSET_MASK) >> ADC12_SMPRX_REGOFFSET_POS));
  return (uint32_t)(READ_BIT(*preg,
                             ADC_SMPR1_SMP0 << ((Channel & ADC12_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC12_CHANNEL_SMPx_BITOFFSET_POS))
                    >> ((Channel & ADC12_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC12_CHANNEL_SMPx_BITOFFSET_POS)
                   );
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Configuration_ADC12_AnalogWatchdog Configuration of ADC transversal scope: analog watchdog
  * @{
  */
/**
  * @brief  Set ADC analog watchdog monitored channels:
  *         a single channel, multiple channels or all channels,
  *         on ADC groups regular and-or injected.
  * @note   Once monitored channels are selected, analog watchdog
  *         is enabled.
  * @note
  *         - AWD standard (instance AWD1):
  *           - channels monitored: can monitor 1 channel or all channels.
  *           - groups monitored: ADC groups regular and-or injected.
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC12_AWD_CHANNEL4_REG_INJ | DDL_ADC12_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC12_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC12_AWD_CHANNELxx_REG and DDL_ADC12_AWD_CHANNELxx_INJ)
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD1
  * @param  AWDChannelGroup This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD_DISABLE
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_REG
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_INJ
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_REG_INJ
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_SetAnalogWDMonitChannels(ADC12_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDChannelGroup)
{
  /* Set bits with content of parameter "AWDChannelGroup" with bits position  */
  /* in register and register position depending on parameter "AWDy".         */
  /* Parameters "AWDChannelGroup" and "AWDy" are used with masks because      */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->CFGR, ((AWDy & ADC12_AWD_CRX_REGOFFSET_MASK) >> ADC12_AWD_CRX_REGOFFSET_POS)
                                             + ((AWDy & ADC12_AWD_CR12_REGOFFSETGAP_MASK) * ADC12_AWD_CR12_REGOFFSETGAP_VAL));

  MODIFY_REG(*preg,
             (AWDy & ADC12_AWD_CR_ALL_CHANNEL_MASK),
             AWDChannelGroup & AWDy);
}

/**
  * @brief  Get ADC analog watchdog monitored channel.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function DDL_ADC12_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals DDL_ADC12_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals DDL_ADC12_CHANNEL_x or using
  *           helper macro @ref __DDL_ADC12_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal DDL_ADC12_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __DDL_ADC12_CHANNEL_TO_DECIMAL_NB().
  *           Applicable only when the analog watchdog is set to monitor
  *           one channel.
  * @note
  *         - AWD standard (instance AWD1):
  *           - channels monitored: can monitor 1 channel or all channels.
  *           - groups monitored: ADC groups regular and-or injected.
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC12_AWD_CHANNEL4_REG_INJ | DDL_ADC12_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC12_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC12_AWD_CHANNELxx_REG and DDL_ADC12_AWD_CHANNELxx_INJ)
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD1
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD_DISABLE
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_REG
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_INJ
  *         @arg @ref DDL_ADC12_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_5_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_6_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_7_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_8_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_9_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_10_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_11_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_12_REG_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_REG
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_INJ
  *         @arg @ref DDL_ADC12_AWD_CHANNEL_13_REG_INJ
  */
__STATIC_INLINE uint32_t DDL_ADC12_GetAnalogWDMonitChannels(ADC12_TypeDef *ADCx, uint32_t AWDy)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->CFGR, ((AWDy & ADC12_AWD_CRX_REGOFFSET_MASK) >> ADC12_AWD_CRX_REGOFFSET_POS)
                                                   + ((AWDy & ADC12_AWD_CR12_REGOFFSETGAP_MASK) * ADC12_AWD_CR12_REGOFFSETGAP_VAL));

  uint32_t AnalogWDMonitChannels = (READ_BIT(*preg, AWDy) & ADC12_AWD_CR_ALL_CHANNEL_MASK);

  /* If "AnalogWDMonitChannels" == 0, then the selected AWD is disabled       */
  /* (parameter value DDL_ADC12_AWD_DISABLE).                                    */
  /* Else, the selected AWD is enabled and is monitoring a group of channels  */
  /* or a single channel.                                                     */

  return AnalogWDMonitChannels;
}

/**
  * @brief  Set ADC analog watchdog thresholds value of both thresholds
  *         high and low.
  * @note   If value of only one threshold high or low must be set,
  *         use function @ref DDL_ADC12_SetAnalogWDThresholds().
  * @note
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC12_AWD_CHANNEL4_REG_INJ | DDL_ADC12_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC12_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC12_AWD_CHANNELxx_REG and DDL_ADC12_AWD_CHANNELxx_INJ)
  * @note   If ADC oversampling is enabled, ADC analog watchdog thresholds are
  *         impacted: the comparison of analog watchdog thresholds is done on
  *         oversampling final computation (after ratio and shift application):
  *         ADC data register bitfield [15:0] (16 most significant bits).
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD1
  * @param  AWDThresholdHighValue Value between Min_Data=0x000 and Max_Data=0xFFF
  * @param  AWDThresholdLowValue Value between Min_Data=0x000 and Max_Data=0xFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ConfigAnalogWDThresholds(ADC12_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdHighValue,
                                                     uint32_t AWDThresholdLowValue)
{
  /* Set bits with content of parameter "AWDThresholdxxxValue" with bits      */
  /* position in register and register position depending on parameter        */
  /* "AWDy".                                                                  */
  /* Parameters "AWDy" and "AWDThresholdxxxValue" are used with masks because */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->TR1, ((AWDy & ADC12_AWD_TRX_REGOFFSET_MASK) >> ADC12_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_TR1_HT1 | ADC_TR1_LT1,
             (AWDThresholdHighValue << ADC12_TR1_HT1_BITOFFSET_POS) | AWDThresholdLowValue);
}

/**
  * @brief  Set ADC analog watchdog threshold value of threshold
  *         high or low.
  * @note   If values of both thresholds high or low must be set,
  *         use function @ref DDL_ADC12_ConfigAnalogWDThresholds().
  * @note
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC12_AWD_CHANNEL4_REG_INJ | DDL_ADC12_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC12_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC12_AWD_CHANNELxx_REG and DDL_ADC12_AWD_CHANNELxx_INJ)
  * @note   If ADC oversampling is enabled, ADC analog watchdog thresholds are
  *         impacted: the comparison of analog watchdog thresholds is done on
  *         oversampling final computation (after ratio and shift application):
  *         ADC data register bitfield [15:4] (12 most significant bits).
  *         ADC can be disabled, enabled with or without conversion on going
  *         on either ADC groups regular or injected.
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD1
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD_THRESHOLD_HIGH
  *         @arg @ref DDL_ADC12_AWD_THRESHOLD_LOW
  * @param  AWDThresholdValue Value between Min_Data=0x000 and Max_Data=0xFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_SetAnalogWDThresholds(ADC12_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdsHighLow,
                                                  uint32_t AWDThresholdValue)
{
  /* Set bits with content of parameter "AWDThresholdValue" with bits         */
  /* position in register and register position depending on parameters       */
  /* "AWDThresholdsHighLow" and "AWDy".                                       */
  /* Parameters "AWDy" and "AWDThresholdValue" are used with masks because    */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->TR1,
                                             ((AWDy & ADC12_AWD_TRX_REGOFFSET_MASK) >> ADC12_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             AWDThresholdsHighLow,
             AWDThresholdValue << ((AWDThresholdsHighLow & ADC12_AWD_TRX_BIT_HIGH_MASK) >> ADC12_AWD_TRX_BIT_HIGH_SHIFT4));
}

/**
  * @brief  Get ADC analog watchdog threshold value of threshold high,
  *         threshold low or raw data with ADC thresholds high and low
  *         concatenated.
  * @note   If raw data with ADC thresholds high and low is retrieved,
  *         the data of each threshold high or low can be isolated
  *         using helper macro:
  *         @ref __DDL_ADC12_ANALOGWD_THRESHOLDS_HIGH_LOW().
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD1
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_AWD_THRESHOLD_HIGH
  *         @arg @ref DDL_ADC12_AWD_THRESHOLD_LOW
  *         @arg @ref DDL_ADC12_AWD_THRESHOLDS_HIGH_LOW
  * @retval Value between Min_Data=0x000 and Max_Data=0xFFF
  */
__STATIC_INLINE uint32_t DDL_ADC12_GetAnalogWDThresholds(ADC12_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdsHighLow)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->TR1,
                                                   ((AWDy & ADC12_AWD_TRX_REGOFFSET_MASK) >> ADC12_AWD_TRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             (AWDThresholdsHighLow | ADC_TR1_LT1))
                    >> (((AWDThresholdsHighLow & ADC12_AWD_TRX_BIT_HIGH_MASK) >> ADC12_AWD_TRX_BIT_HIGH_SHIFT4)
                        & ~(AWDThresholdsHighLow & ADC_TR1_LT1)));
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Operation_ADC12_Instance Operation on ADC hierarchical scope: ADC instance
  * @{
  */
/**
  * @brief  Enable the selected ADC instance.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_Enable(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_ADEN,
             ADC_CR_ADEN);
}

/**
  * @brief  Disable the selected ADC instance.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_Disable(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_ADEN,
             0);
}

/**
  * @brief  Get the selected ADC instance enable state.
  * @param  ADCx ADC instance
  * @retval 0: ADC is disabled, 1: ADC is enabled.
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabled(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADEN) == (ADC_CR_ADEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set ADC data alignment.
  * @param  ADCx ADC instance
  * @param  Alignment This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_ALIGNMENT_LEFT
  *         @arg @ref DDL_ADC12_ALIGNMENT_RIGHT
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_SetDataAlignment(ADC12_TypeDef *ADCx, uint32_t Alignment)
{
    MODIFY_REG(ADCx->CFGR,
             ADC_CFGR_ALIGN,
             Alignment);
}

/**
  * @brief  Get ADC data alignment.
  * @param  ADCx ADC instance
  * @retval Data Alignment.
  *         @arg @ref DDL_ADC12_ALIGNMENT_LEFT
  *         @arg @ref DDL_ADC12_ALIGNMENT_RIGHT
  */
__STATIC_INLINE uint32_t DDL_ADC12_GetDataAlignment(ADC12_TypeDef *ADCx)
{
    return (uint32_t)READ_BIT(ADCx->CFGR, ADC_CFGR_ALIGN);
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Operation_ADC12_Group_Regular Operation on ADC hierarchical scope: group regular
  * @{
  */
/**
  * @brief  Start ADC group regular conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_StartConversion(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_ADSTART,
             ADC_CR_ADSTART);
}

/**
  * @brief  Stop ADC group regular conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_REG_StopConversion(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_ADSTP,
             ADC_CR_ADSTP);
}

/**
  * @brief  Get ADC group regular conversion state.
  * @param  ADCx ADC instance
  * @retval 0: no conversion is on going on ADC group regular.
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_IsConversionOngoing(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTART) == (ADC_CR_ADSTART)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group regular command of conversion stop state
  * @param  ADCx ADC instance
  * @retval 0: no command of conversion stop is on going on ADC group regular.
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_IsStopConversionOngoing(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTP) == (ADC_CR_ADSTP)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group regular conversion data, range fit for
  *         all ADC configurations: all ADC resolutions and
  *         all oversampling increased data width (for devices
  *         with feature oversampling).
  * @param  ADCx ADC instance
  * @retval Value between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC12_REG_ReadConversionData32(ADC12_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA | ADC_DR_ADC2RDATA));
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_Operation_ADC12_Group_Injected Operation on ADC hierarchical scope: group injected
  * @{
  */

/**
  * @brief  Start ADC group injected conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_StartConversion(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_JADSTART,
             ADC_CR_JADSTART);
}

/**
  * @brief  Stop ADC group injected conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_INJ_StopConversion(ADC12_TypeDef *ADCx)
{
  /* Note: Write register with some additional bits forced to state reset     */
  /*       instead of modifying only the selected bit for this function,      */
  /*       to not interfere with bits with HW property "rs".                  */
  MODIFY_REG(ADCx->CR,
             ADC_CR_JADSTP,
             ADC_CR_JADSTP);
}

/**
  * @brief  Get ADC group injected conversion state.
  * @param  ADCx ADC instance
  * @retval 0: no conversion is on going on ADC group injected.
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_IsConversionOngoing(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_JADSTART) == (ADC_CR_JADSTART)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group injected command of conversion stop state
  * @param  ADCx ADC instance
  * @retval 0: no command of conversion stop is on going on ADC group injected.
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_IsStopConversionOngoing(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_JADSTP) == (ADC_CR_JADSTP)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group injected conversion data, range fit for
  *         all ADC configurations: all ADC resolutions and
  *         all oversampling increased data width (for devices
  *         with feature oversampling).
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC12_INJ_RANK_1
  *         @arg @ref DDL_ADC12_INJ_RANK_2
  *         @arg @ref DDL_ADC12_INJ_RANK_3
  *         @arg @ref DDL_ADC12_INJ_RANK_4
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC12_INJ_ReadConversionData32(ADC12_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC12_PTR_REG_OFFSET(ADCx->JDR1, ((Rank & ADC12_INJ_JDRX_REGOFFSET_MASK) >> ADC12_JDRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
* @}
*/

/** @defgroup ADC12_DDL_EF_FLAG_Management ADC flag management
  * @{
  */

/**
  * @brief  Get flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsActiveFlag_EOC(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC12_FLAG_EOC) == (DDL_ADC12_FLAG_EOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsActiveFlag_EOS(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC12_FLAG_EOS) == (DDL_ADC12_FLAG_EOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsActiveFlag_JEOC(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC12_FLAG_JEOC) == (DDL_ADC12_FLAG_JEOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsActiveFlag_JEOS(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC12_FLAG_JEOS) == (DDL_ADC12_FLAG_JEOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC analog watchdog 1 flag
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsActiveFlag_AWD1(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC12_FLAG_AWD1) == (DDL_ADC12_FLAG_AWD1)) ? 1UL : 0UL);
}

/**
  * @brief  Clear flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ClearFlag_EOC(ADC12_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC12_FLAG_EOC);
}

/**
  * @brief  Clear flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ClearFlag_EOS(ADC12_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC12_FLAG_EOS);
}

/**
  * @brief  Clear flag ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ClearFlag_JEOC(ADC12_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC12_FLAG_JEOC);
}

/**
  * @brief  Clear flag ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ClearFlag_JEOS(ADC12_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC12_FLAG_JEOS);
}

/**
  * @brief  Clear flag ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_ClearFlag_AWD1(ADC12_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC12_FLAG_AWD1);
}

/**
  * @}
  */

/** @defgroup ADC12_DDL_EF_IT_Management ADC IT management
  * @{
  */

/**
  * @brief  Enable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_EnableIT_EOC(ADC12_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC12_IT_EOC);
}

/**
  * @brief  Enable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_EnableIT_EOS(ADC12_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC12_IT_EOS);
}

/**
  * @brief  Enable interruption ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_EnableIT_JEOC(ADC12_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC12_IT_JEOC);
}

/**
  * @brief  Enable interruption ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_EnableIT_JEOS(ADC12_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC12_IT_JEOS);
}

/**
  * @brief  Enable interruption ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_EnableIT_AWD1(ADC12_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC12_IT_AWD1);
}

/**
  * @brief  Disable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_DisableIT_EOC(ADC12_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC12_IT_EOC);
}

/**
  * @brief  Disable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_DisableIT_EOS(ADC12_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC12_IT_EOS);
}

/**
  * @brief  Disable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_DisableIT_JEOC(ADC12_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC12_IT_JEOC);
}

/**
  * @brief  Disable interruption ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_DisableIT_JEOS(ADC12_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC12_IT_JEOS);
}

/**
  * @brief  Disable interruption ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC12_DisableIT_AWD1(ADC12_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC12_IT_AWD1);
}

/**
  * @brief  Get state of interruption ADC group regular end of unitary conversion
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabledIT_EOC(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC12_IT_EOC) == (DDL_ADC12_IT_EOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group regular end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabledIT_EOS(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC12_IT_EOS) == (DDL_ADC12_IT_EOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group injected end of unitary conversion
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabledIT_JEOC(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC12_IT_JEOC) == (DDL_ADC12_IT_JEOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group injected end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabledIT_JEOS(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC12_IT_JEOS) == (DDL_ADC12_IT_JEOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC analog watchdog 1
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC12_IsEnabledIT_AWD1(ADC12_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC12_IT_AWD1) == (DDL_ADC12_IT_AWD1)) ? 1UL : 0UL);
}

/**
* @}
*/

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC12_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

/* De-initialization of ADC instance, ADC group regular and ADC group injected */
/* (availability of ADC group injected depends on G32R4 families) */
ErrorStatus DDL_ADC12_DeInit(ADC12_TypeDef *ADCx);

/* Initialization of some features of ADC instance */
ErrorStatus DDL_ADC12_Init(ADC12_TypeDef *ADCx, DDL_ADC12_InitTypeDef *ADC_InitStruct);
void        DDL_ADC12_StructInit(DDL_ADC12_InitTypeDef *ADC_InitStruct);

/* Initialization of some features of ADC instance and ADC group regular */
ErrorStatus DDL_ADC12_REG_Init(ADC12_TypeDef *ADCx, DDL_ADC12_REG_InitTypeDef *ADC_REG_InitStruct);
void        DDL_ADC12_REG_StructInit(DDL_ADC12_REG_InitTypeDef *ADC_REG_InitStruct);

/* Initialization of some features of ADC instance and ADC group injected */
ErrorStatus DDL_ADC12_INJ_Init(ADC12_TypeDef *ADCx, DDL_ADC12_INJ_InitTypeDef *ADC_INJ_InitStruct);
void        DDL_ADC12_INJ_StructInit(DDL_ADC12_INJ_InitTypeDef *ADC_INJ_InitStruct);

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

/**
  * @}
  */

#endif /* defined (ADC3) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4XX_DDL_ADC12_H */

