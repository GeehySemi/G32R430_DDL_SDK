/**
  *
  * @file    g32r4xx_ddl_adc16.h
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
#ifndef G32R4xx_DDL_ADC16_H
#define G32R4xx_DDL_ADC16_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (ADC1) || defined (ADC2)

/** @defgroup ADC_DDL ADC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Constants ADC Private Constants
  * @{
  */

/* Internal mask for ADC group regular sequencer:                             */
/* To select into literal DDL_ADC16_REG_RANK_x the relevant bits for:            */
/* - sequencer register offset                                                */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group regular sequencer configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC_SQR1_REGOFFSET                              (0x00000000UL)
#define ADC_SQR2_REGOFFSET                              (0x00000100UL)

#define ADC_REG_SQRX_REGOFFSET_MASK                     (ADC_SQR1_REGOFFSET | ADC_SQR2_REGOFFSET)
#define ADC_SQRX_REGOFFSET_POS                          (8UL) /* Position of bits ADC_SQRx_REGOFFSET in ADC_REG_SQRX_REGOFFSET_MASK */
#define ADC_REG_RANK_ID_SQRX_MASK                       (0x1F)

/* Definition of ADC group regular sequencer bits information to be inserted  */
/* into ADC group regular sequencer ranks literals definition.                */
#define ADC_REG_RANK_1_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ1_Pos)
#define ADC_REG_RANK_2_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ2_Pos)
#define ADC_REG_RANK_3_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ3_Pos)
#define ADC_REG_RANK_4_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ4_Pos)
#define ADC_REG_RANK_5_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ5_Pos)
#define ADC_REG_RANK_6_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ6_Pos)
#define ADC_REG_RANK_7_SQRX_BITOFFSET_POS               (ADC_SQR1_SQ7_Pos)
#define ADC_REG_RANK_8_SQRX_BITOFFSET_POS               (ADC_SQR2_SQ8_Pos)
#define ADC_REG_RANK_9_SQRX_BITOFFSET_POS               (ADC_SQR2_SQ9_Pos)
#define ADC_REG_RANK_10_SQRX_BITOFFSET_POS              (ADC_SQR2_SQ10_Pos)
#define ADC_REG_RANK_11_SQRX_BITOFFSET_POS              (ADC_SQR2_SQ11_Pos)
#define ADC_REG_RANK_12_SQRX_BITOFFSET_POS              (ADC_SQR2_SQ12_Pos)

/* Internal mask for ADC group injected sequencer:                            */
/* To select into literal DDL_ADC16_INJ_RANK_x the relevant bits for:            */
/* - data register offset                                                     */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group injected data register */
/* (offset placed into a spare area of literal definition) */
#define ADC_JDR1_REGOFFSET                              (0x00000000UL)
#define ADC_JDR2_REGOFFSET                              (0x00000100UL)
#define ADC_JDR3_REGOFFSET                              (0x00000200UL)
#define ADC_JDR4_REGOFFSET                              (0x00000300UL)

#define ADC_INJ_JDRX_REGOFFSET_MASK                     (ADC_JDR1_REGOFFSET | ADC_JDR2_REGOFFSET \
                                            | ADC_JDR3_REGOFFSET | ADC_JDR4_REGOFFSET)
#define ADC_INJ_RANK_ID_JSQR_MASK                       (0x1F)
#define ADC_JDRX_REGOFFSET_POS                          (8UL) /* Position of bits ADC_JDRx_REGOFFSET in ADC_INJ_JDRX_REGOFFSET_MASK */

/* Definition of ADC group injected sequencer bits information to be inserted */
/* into ADC group injected sequencer ranks literals definition.               */
#define ADC_INJ_RANK_1_JSQR_BITOFFSET_POS               (ADC_JSQR_JSQ1_Pos)
#define ADC_INJ_RANK_2_JSQR_BITOFFSET_POS               (ADC_JSQR_JSQ2_Pos)
#define ADC_INJ_RANK_3_JSQR_BITOFFSET_POS               (ADC_JSQR_JSQ3_Pos)
#define ADC_INJ_RANK_4_JSQR_BITOFFSET_POS               (ADC_JSQR_JSQ4_Pos)

/* Internal mask for ADC group regular trigger:                               */
/* To select into literal DDL_ADC16_REG_TRIG_x the relevant bits for:            */
/* - regular trigger source                                                   */
/* - regular trigger edge                                                     */
#define ADC_REG_TRIG_EXT_EDGE_DEFAULT                   (ADC_CFGR_EXTEN_0) /* Trigger edge set to rising edge */

/* Mask containing trigger source masks for each of possible                  */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC_REG_TRIG_SOURCE_MASK                        (((DDL_ADC16_REG_TRIG_SOFTWARE & ADC_CFGR_EXTSEL) << (4U * 0UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 1UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 2UL)) | \
                                             ((ADC_CFGR_EXTSEL)                             << (4U * 3UL))  )

/* Mask containing trigger edge masks for each of possible                    */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC_REG_TRIG_EDGE_MASK                          (((DDL_ADC16_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN) << (4U * 0UL)) | \
                                             ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 1UL)) | \
                                             ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 2UL)) | \
                                             ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)              << (4U * 3UL))  )

/* Definition of ADC group regular trigger bits information.                  */
#define ADC_REG_TRIG_EXTSEL_BITOFFSET_POS               (ADC_CFGR_EXTSEL_Pos)
#define ADC_REG_TRIG_EXTEN_BITOFFSET_POS                (ADC_CFGR_EXTEN_Pos)

/* Internal mask for ADC group injected trigger:                              */
/* To select into literal DDL_ADC16_INJ_TRIG_x the relevant bits for:            */
/* - injected trigger source                                                  */
/* - injected trigger edge                                                    */
#define ADC_INJ_TRIG_EXT_EDGE_DEFAULT                   (ADC_JSQR_JEXTEN_0) /* Trigger edge set to rising edge */

/* Mask containing trigger source masks for each of possible                  */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC_INJ_TRIG_SOURCE_MASK                        (((DDL_ADC16_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTSEL)  << (4U * 0UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 1UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 2UL)) | \
                                             ((ADC_JSQR_JEXTSEL)                             << (4U * 3UL))  )

/* Mask containing trigger edge masks for each of possible                    */
/* trigger edge selection duplicated with shifts [0; 4; 8; 12]                */
/* corresponding to {SW start; ext trigger; ext trigger; ext trigger}.        */
#define ADC_INJ_TRIG_EDGE_MASK                          (((DDL_ADC16_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN) << (4U * 0UL)) | \
                                             ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 1UL)) | \
                                             ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 2UL)) | \
                                             ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 3UL))  )

/* Definition of ADC group injected trigger bits information.                 */
#define ADC_INJ_TRIG_EXTSEL_BITOFFSET_POS               (ADC_JSQR_JEXTSEL_Pos)
#define ADC_INJ_TRIG_EXTEN_BITOFFSET_POS                (ADC_JSQR_JEXTEN_Pos)

/* Internal mask for ADC channel:                                             */
/* To select into literal DDL_ADC16_CHANNEL_x the relevant bits for:             */
/* - channel identifier defined by number                                     */
/* - channel identifier defined by bitfield                                   */
/* - channel differentiation between external channels (connected to          */
/*   GPIO pins) and internal channels (connected to internal paths)           */
/* - channel sampling time defined by SMPRx register offset                   */
/*   and SMPx bits positions into SMPRx register                              */
#define ADC16_CFGR_AWD1CH                               (0x7UL << ADC_CFGR_AWD1CH_Pos)
#define ADC_CHANNEL_ID_NUMBER_MASK                      (ADC16_CFGR_AWD1CH)
#define ADC_CHANNEL_ID_BITFIELD_MASK                    (ADC_AWD2CR_AWD2CH)
#define ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS             (ADC_CFGR_AWD1CH_Pos)
#define ADC_CHANNEL_ID_MASK                             (ADC_CHANNEL_ID_NUMBER_MASK | ADC_CHANNEL_ID_BITFIELD_MASK \
                                            | ADC_CHANNEL_ID_INTERNAL_CH_MASK)
/* Equivalent mask of ADC_CHANNEL_NUMBER_MASK aligned on register LSB (bit 0) */
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0              (ADC_SQR2_SQ8) /* Equivalent to shift: (ADC_CHANNEL_NUMBER_MASK >> [Position of bitfield "ADC_CHANNEL_NUMBER_MASK" in register]) */

/* Channel differentiation between external and internal channels */
#define ADC_CHANNEL_ID_INTERNAL_CH                      (0x80000000UL) /* Marker of internal channel */
#define ADC_CHANNEL_ID_INTERNAL_CH_2                    (0x00080000UL) /* Marker of internal channel for other ADC instances, in case of different ADC internal channels mapped on same channel number on different ADC instances */
#define ADC_CHANNEL_ID_INTERNAL_CH_MASK                 (ADC_CHANNEL_ID_INTERNAL_CH | ADC_CHANNEL_ID_INTERNAL_CH_2)

/* Internal register offset for ADC channel sampling time configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC_SMPR1_REGOFFSET                             (0x00000000UL)
#define ADC_CHANNEL_SMPRX_REGOFFSET_MASK                (ADC_SMPR1_REGOFFSET)
#define ADC_SMPRX_REGOFFSET_POS                         (25UL) /* Position of bits ADC_SMPRx_REGOFFSET in ADC_CHANNEL_SMPRX_REGOFFSET_MASK */

#define ADC_CHANNEL_SMPx_BITOFFSET_MASK                 (0x01F00000UL)
#define ADC_CHANNEL_SMPx_BITOFFSET_POS                  (20UL)           /* Value equivalent to bitfield "ADC_CHANNEL_SMPx_BITOFFSET_MASK" position in register */

/* Definition of channels ID number information to be inserted into           */
/* channels literals definition.                                              */
#define ADC_CHANNEL_0_NUMBER                            (0x00000000UL)
#define ADC_CHANNEL_1_NUMBER                            (ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_2_NUMBER                            (ADC_CFGR_AWD1CH_1)
#define ADC_CHANNEL_3_NUMBER                            (ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_4_NUMBER                            (ADC_CFGR_AWD1CH_2)
#define ADC_CHANNEL_5_NUMBER                            (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_0)

/* Definition of channels ID bitfield information to be inserted into         */
/* channels literals definition.                                              */
#define ADC_CHANNEL_0_BITFIELD                          (ADC_AWD2CR_AWD2CH_0)
#define ADC_CHANNEL_1_BITFIELD                          (ADC_AWD2CR_AWD2CH_1)
#define ADC_CHANNEL_2_BITFIELD                          (ADC_AWD2CR_AWD2CH_2)
#define ADC_CHANNEL_3_BITFIELD                          (ADC_AWD2CR_AWD2CH_3)
#define ADC_CHANNEL_4_BITFIELD                          (ADC_AWD2CR_AWD2CH_4)
#define ADC_CHANNEL_5_BITFIELD                          (ADC_AWD2CR_AWD2CH_5)

/* Definition of channels sampling time information to be inserted into       */
/* channels literals definition.                                              */
#define ADC_CHANNEL_0_SMP                               (ADC_SMPR1_REGOFFSET | (( 0UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP0" position in register */
#define ADC_CHANNEL_1_SMP                               (ADC_SMPR1_REGOFFSET | (( 4UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP1" position in register */
#define ADC_CHANNEL_2_SMP                               (ADC_SMPR1_REGOFFSET | (( 8UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP2" position in register */
#define ADC_CHANNEL_3_SMP                               (ADC_SMPR1_REGOFFSET | ((12UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP3" position in register */
#define ADC_CHANNEL_4_SMP                               (ADC_SMPR1_REGOFFSET | ((16UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP4" position in register */
#define ADC_CHANNEL_5_SMP                               (ADC_SMPR1_REGOFFSET | ((20UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to bitfield "ADC_SMPR1_SMP5" position in register */

/* Internal mask for ADC analog watchdog:                                     */
/* To select into literals DDL_ADC16_AWD_CHANNELx_xxx the relevant bits for:     */
/* (concatenation of multiple bits used in different analog watchdogs,        */
/* - analog watchdog 1: monitored channel defined by number,                  */
/*   selection of ADC group (ADC groups regular and-or injected).             */
/* - analog watchdog 2 and 3: monitored channel defined by bitfield, no       */
/*   selection on groups.                                                     */

/* Internal register offset for ADC analog watchdog channel configuration */
#define ADC_AWD_CR1_REGOFFSET                           (0x00000000UL)
#define ADC_AWD_CR2_REGOFFSET                           (0x00100000UL)
#define ADC_AWD_CR3_REGOFFSET                           (0x00200000UL)

/* Register offset gap between AWD1 and AWD2-AWD3 configuration registers */
/* (Set separately as ADC_AWD_CRX_REGOFFSET to spare 32 bits space */
#define ADC_AWD_CR12_REGOFFSETGAP_MASK                  (ADC_AWD2CR_AWD2CH_0)
#define ADC_AWD_CR12_REGOFFSETGAP_VAL                   (0x00000010UL)

#define ADC_AWD_CRX_REGOFFSET_MASK                      (ADC_AWD_CR1_REGOFFSET | ADC_AWD_CR2_REGOFFSET | ADC_AWD_CR3_REGOFFSET)

#define ADC_AWD_CR1_CHANNEL_MASK                        (ADC16_CFGR_AWD1CH | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)
#define ADC_AWD_CR23_CHANNEL_MASK                       (ADC_AWD2CR_AWD2CH)
#define ADC_AWD_CR_ALL_CHANNEL_MASK                     (ADC_AWD_CR1_CHANNEL_MASK | ADC_AWD_CR23_CHANNEL_MASK)

#define ADC_AWD_CRX_REGOFFSET_POS                       (20UL) /* Position of bits ADC_AWD_CRx_REGOFFSET in ADC_AWD_CRX_REGOFFSET_MASK */

/* Internal register offset for ADC analog watchdog threshold configuration */
#define ADC_AWD_TR1_REGOFFSET                           (ADC_AWD_CR1_REGOFFSET)
#define ADC_AWD_TR2_REGOFFSET                           (ADC_AWD_CR2_REGOFFSET)
#define ADC_AWD_TR3_REGOFFSET                           (ADC_AWD_CR3_REGOFFSET)
#define ADC_AWD_TRX_REGOFFSET_MASK                      (ADC_AWD_TR1_REGOFFSET | ADC_AWD_TR2_REGOFFSET | ADC_AWD_TR3_REGOFFSET)
#define ADC_AWD_TRX_REGOFFSET_POS                       (ADC_AWD_CRX_REGOFFSET_POS)     /* Position of bits ADC_SQRx_REGOFFSET in ADC_AWD_TRX_REGOFFSET_MASK */
#define ADC_AWD_TRX_BIT_HIGH_MASK                       (0x00010000UL)                   /* Selection of 1 bit to discriminate threshold high: mask of bit */
#define ADC_AWD_TRX_BIT_HIGH_POS                        (16UL)                           /* Selection of 1 bit to discriminate threshold high: position of bit */
#define ADC_AWD_TRX_BIT_HIGH_SHIFT4                     (ADC_AWD_TRX_BIT_HIGH_POS - 4UL) /* Shift of bit ADC_AWD_TRX_BIT_HIGH to position to perform a shift of 4 ranks */

/* Internal mask for ADC offset:                                              */
/* Internal register offset for ADC offset number configuration */
#define ADC_OFFSET0_REGOFFSET                           (0x00000000UL)
#define ADC_OFFSET1_REGOFFSET                           (0x00000001UL)
#define ADC_OFFSET2_REGOFFSET                           (0x00000002UL)
#define ADC_OFFSET3_REGOFFSET                           (0x00000003UL)
#define ADC_OFFSET4_REGOFFSET                           (0x00000004UL)
#define ADC_OFFSET5_REGOFFSET                           (0x00000005UL)
#define ADC_OFFSETx_REGOFFSET_MASK                      (ADC_OFFSET0_REGOFFSET | ADC_OFFSET1_REGOFFSET \
                                          | ADC_OFFSET2_REGOFFSET | ADC_OFFSET3_REGOFFSET \
                                          | ADC_OFFSET4_REGOFFSET | ADC_OFFSET5_REGOFFSET)

/* ADC registers bits positions */
#define ADC_CFGR_AWD1SGL_BITOFFSET_POS                  (ADC_CFGR_AWD1SGL_Pos)
#define ADC_CFGR_AWD1EN_BITOFFSET_POS                   (ADC_CFGR_AWD1EN_Pos)
#define ADC_CFGR_JAWD1EN_BITOFFSET_POS                  (ADC_CFGR_JAWD1EN_Pos)
#define ADC_TR1_HT1_BITOFFSET_POS                       (ADC_TR1_HT1_Pos)

/* ADC registers bits groups */
#define ADC_CR_BITS_PROPERTY_RS                         (ADC_CR_JADSTP | ADC_CR_ADSTP | ADC_CR_JADSTART | ADC_CR_ADSTART | ADC_CR_ADEN) /* ADC register CR bits with HW property "rs": Software can read as well as set this bit. Writing '0' has no effect on the bit value. */

/** @defgroup ADC_DDL_EC_REG_TRIGGER_SOURCE  ADC group regular - Trigger source
  * @{
  */

#define DDL_ADC16_REG_TRIG_SOFTWARE         (0x00000000UL)                                                                               /*!< ADC group regular conversion trigger internal: SW start. */
#define DDL_ADC16_REG_TRIG_EXT_TMR1_CC1     (ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                                              /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC1. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR1_CC2     (ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                          /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC2. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR1_CC3     (ADC_CFGR_EXTSEL_1 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                          /*!< ADC group regular conversion trigger from external peripheral: TMR1 CC3. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR2_CC2     (ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR2 CC2. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR3_TRGO    (ADC_CFGR_EXTSEL_2 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                          /*!< ADC group regular conversion trigger from external peripheral: TMR3 TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR4_CC4     (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR4 CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_EINT_LINE11  (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_1 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: EINT Line 11. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR1_TRGO    (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group regular conversion trigger from external peripheral: TMR1 TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO    (ADC_CFGR_EXTSEL_3 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                          /*!< ADC group regular conversion trigger from external peripheral: TMR2 TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR4_TRGO    (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR4 TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_TMR3_CC4     (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_1 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                      /*!< ADC group regular conversion trigger from external peripheral: TMR3 CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_REG_TRIG_EXT_LPTMROUT     (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group regular conversion trigger from external peripheral: LPTIMER output. Trigger edge set to rising edge (default setting). */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_TRIGGER_EDGE  ADC group regular - Trigger edge
  * @{
  */
#define DDL_ADC16_REG_TRIG_EXT_RISING         (                   ADC_CFGR_EXTEN_0)  /*!< ADC group regular conversion trigger polarity set to rising edge */
#define DDL_ADC16_REG_TRIG_EXT_FALLING        (ADC_CFGR_EXTEN_1                   )  /*!< ADC group regular conversion trigger polarity set to falling edge */
#define DDL_ADC16_REG_TRIG_EXT_RISINGFALLING  (ADC_CFGR_EXTEN_1 | ADC_CFGR_EXTEN_0)  /*!< ADC group regular conversion trigger polarity set to both rising and falling edges */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_SEQ_SCAN_LENGTH  ADC group regular - Sequencer scan length
  * @{
  */
#define DDL_ADC16_REG_SEQ_SCAN_DISABLE         (0x00000000UL)                                                  /*!< ADC group regular sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_2RANKS   (                                             ADC_SQR1_RL_0)    /*!< ADC group regular sequencer enable with 2 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_3RANKS   (                              ADC_SQR1_RL_1               )    /*!< ADC group regular sequencer enable with 3 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_4RANKS   (                              ADC_SQR1_RL_1 | ADC_SQR1_RL_0)   /*!< ADC group regular sequencer enable with 4 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_5RANKS   (               ADC_SQR1_RL_2                              )    /*!< ADC group regular sequencer enable with 5 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_6RANKS   (               ADC_SQR1_RL_2                | ADC_SQR1_RL_0)   /*!< ADC group regular sequencer enable with 6 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_7RANKS   (               ADC_SQR1_RL_2 | ADC_SQR1_RL_1               )   /*!< ADC group regular sequencer enable with 7 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_8RANKS   (               ADC_SQR1_RL_2 | ADC_SQR1_RL_1 | ADC_SQR1_RL_0)  /*!< ADC group regular sequencer enable with 8 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_9RANKS   (ADC_SQR1_RL_3                                             )    /*!< ADC group regular sequencer enable with 9 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_10RANKS  (ADC_SQR1_RL_3                               | ADC_SQR1_RL_0)   /*!< ADC group regular sequencer enable with 10 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_11RANKS  (ADC_SQR1_RL_3                | ADC_SQR1_RL_1               )   /*!< ADC group regular sequencer enable with 11 ranks in the sequence */
#define DDL_ADC16_REG_SEQ_SCAN_ENABLE_12RANKS  (ADC_SQR1_RL_3                | ADC_SQR1_RL_1 | ADC_SQR1_RL_0)  /*!< ADC group regular sequencer enable with 12 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_SEQ_DISCONT_MODE  ADC group regular - Sequencer discontinuous mode
  * @{
  */
#define DDL_ADC16_REG_SEQ_DISCONT_DISABLE  (0x00000000UL)                                                                    /*!< ADC group regular sequencer discontinuous mode disable */
#define DDL_ADC16_REG_SEQ_DISCONT_1RANK    (                                                               ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every rank */
#define DDL_ADC16_REG_SEQ_DISCONT_2RANKS   (                                          ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enabled with sequence interruption every 2 ranks */
#define DDL_ADC16_REG_SEQ_DISCONT_3RANKS   (                     ADC_CFGR_DISCNUM_1                      | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 3 ranks */
#define DDL_ADC16_REG_SEQ_DISCONT_4RANKS   (                     ADC_CFGR_DISCNUM_1 | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 4 ranks */
#define DDL_ADC16_REG_SEQ_DISCONT_5RANKS   (ADC_CFGR_DISCNUM_2                                           | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 5 ranks */
#define DDL_ADC16_REG_SEQ_DISCONT_6RANKS   (ADC_CFGR_DISCNUM_2                      | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)  /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 6 ranks */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_SEQ_RANKS  ADC group regular - Sequencer ranks
  * @{
  */
#define DDL_ADC16_REG_RANK_1   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_1_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 1 */
#define DDL_ADC16_REG_RANK_2   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_2_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 2 */
#define DDL_ADC16_REG_RANK_3   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_3_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 3 */
#define DDL_ADC16_REG_RANK_4   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_4_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 4 */
#define DDL_ADC16_REG_RANK_5   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_5_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 5 */
#define DDL_ADC16_REG_RANK_6   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_6_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 6 */
#define DDL_ADC16_REG_RANK_7   (ADC_SQR1_REGOFFSET | ADC_REG_RANK_7_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 7 */
#define DDL_ADC16_REG_RANK_8   (ADC_SQR2_REGOFFSET | ADC_REG_RANK_8_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 8 */
#define DDL_ADC16_REG_RANK_9   (ADC_SQR2_REGOFFSET | ADC_REG_RANK_9_SQRX_BITOFFSET_POS)   /*!< ADC group regular sequencer rank 9 */
#define DDL_ADC16_REG_RANK_10  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_10_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 10 */
#define DDL_ADC16_REG_RANK_11  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_11_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 11 */
#define DDL_ADC16_REG_RANK_12  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_12_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 12 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_SEQ_SCAN_LENGTH  ADC group injected - Sequencer scan length
  * @{
  */
#define DDL_ADC16_INJ_SEQ_SCAN_DISABLE        (0x00000000UL)                   /*!< ADC group injected sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define DDL_ADC16_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0)  /*!< ADC group injected sequencer enable with 2 ranks in the sequence */
#define DDL_ADC16_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                )  /*!< ADC group injected sequencer enable with 3 ranks in the sequence */
#define DDL_ADC16_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0)  /*!< ADC group injected sequencer enable with 4 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_SEQ_DISCONT_MODE  ADC group injected - Sequencer discontinuous mode
  * @{
  */
#define DDL_ADC16_INJ_SEQ_DISCONT_DISABLE  (0x00000000UL)      /*!< ADC group injected sequencer discontinuous mode disable */
#define DDL_ADC16_INJ_SEQ_DISCONT_1RANK    (ADC_CFGR_JDISCEN)  /*!< ADC group injected sequencer discontinuous mode enable with sequence interruption every rank */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_MULTI_MODE  Multimode - Mode
  * @{
  */
#define DDL_ADC16_MULTI_INDEPENDENT           (0x00000000UL)                                            /*!< ADC dual mode disabled (ADC independent mode) */
#define DDL_ADC16_MULTI_DUAL_REG_SIMULT       (ADC_CR_DUALMOD_2 | ADC_CR_DUALMOD_1)                     /*!< ADC dual mode enabled: group regular simultaneous */
#define DDL_ADC16_MULTI_DUAL_REG_INTERL       (ADC_CR_DUALMOD_2 | ADC_CR_DUALMOD_1 | ADC_CR_DUALMOD_0)  /*!< ADC dual mode enabled: Combined group regular interleaved */
#define DDL_ADC16_MULTI_DUAL_INJ_SIMULT       (ADC_CR_DUALMOD_2 | ADC_CR_DUALMOD_0)                     /*!< ADC dual mode enabled: group injected simultaneous */
#define DDL_ADC16_MULTI_DUAL_INJ_ALTERN       (ADC_CR_DUALMOD_3 | ADC_CR_DUALMOD_0)                     /*!< ADC dual mode enabled: group injected alternate trigger. Works only with external triggers (not internal SW start) */
#define DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_SIM  (ADC_CR_DUALMOD_0)                                        /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected simultaneous */
#define DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_ALT  (ADC_CR_DUALMOD_1)                                        /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected alternate trigger */
#define DDL_ADC16_MULTI_DUAL_REG_INT_INJ_SIM  (ADC_CR_DUALMOD_1 | ADC_CR_DUALMOD_0)                     /*!< ADC dual mode enabled: Combined group regular interleaved + group injected simultaneous */
/**
  * @}
  */

/** @defgroup ADC_CR_ADDIS ADC DISABLE COMMAND
  * @{
  */
#define DDL_ADC16_CR_ADDIS_NOT_EXECUTED           (0x00000000UL)
#define DDL_ADC16_CR_ADDIS_EXECUTION_IN_PROGRESS  ADC_CR_ADDIS
  /**
  * @}
  */

/** @defgroup ADC_DDL_EC_SINGLE_CHANNEL ADC instance - Single-ended channels
  * @{
  */
#define DDL_ADC16_SINGLE_INP0  (0x00U)  /*!< Single-ended channel INP0 */
#define DDL_ADC16_SINGLE_INP1  (0x01U)  /*!< Single-ended channel INP1 */
#define DDL_ADC16_SINGLE_INP2  (0x02U)  /*!< Single-ended channel INP2 */
#define DDL_ADC16_SINGLE_INN0  (0x03U)  /*!< Single-ended channel INN0 */
#define DDL_ADC16_SINGLE_INN1  (0x04U)  /*!< Single-ended channel INN1 */
#define DDL_ADC16_SINGLE_INN2  (0x05U)  /*!< Single-ended channel INN2 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_DIFFERENTIAL_CHANNEL ADC instance - Differential channels
  * @{
  */
#define DDL_ADC16_DIFF_CHANNEL0  (0x00U)  /*!< Differential channel 0 */
#define DDL_ADC16_DIFF_CHANNEL1  (0x01U)  /*!< Differential channel 1 */
#define DDL_ADC16_DIFF_CHANNEL2  (0x02U)  /*!< Differential channel 2 */
/**
  * @}
  */

  /**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC_DDL_ES_INIT ADC Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of ADC instance.
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on G32R4 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Instance .
  * @note   The setting of these parameters by function @ref DDL_ADC16_Init()
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
  uint32_t LowPowerMode;  /*!< Set ADC low power mode.*/

} DDL_ADC16_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref DDL_ADC16_REG_Init()
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

  uint32_t Overrun;           /*!< Set ADC group regular behavior */

} DDL_ADC16_REG_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group injected.
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_DDL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "INJ").
  * @note   The setting of these parameters by function @ref DDL_ADC16_INJ_Init()
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

} DDL_ADC16_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Macros ADC Private Macros
  * @{
  */
/** @defgroup ADC_DDL_EC_REGISTERS  ADC registers compliant with specific purpose
  * @{
  */
/* List of ADC registers intended to be used (most commonly) with             */
/* DMA transfer.                                                              */
/* Refer to function @ref DDL_ADC16_DMA_GetRegAddr().                            */
#define DDL_ADC16_DMA_REG_REGULAR_DATA  (0x00000000UL) /* ADC group regular conversion data register (corresponding to register DR) to be used with ADC configured in independent mode. Without DMA transfer, register accessed by DDL function @ref DDL_ADC16_REG_ReadConversionData32() and other functions @ref DDL_ADC16_REG_ReadConversionDatax() */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_LP_MODE  ADC instance - Low power mode
  * @{
  */
#define DDL_ADC16_LP_MODE_NONE  (0x00000000UL)     /*!< No ADC low power mode activated */
#define DDL_ADC16_LP_AUTOWAIT   (ADC_CFGR_AUTDLY)  /*!< ADC low power mode auto delay: Dynamic low power mode, ADC conversions are performed only when necessary (when previous ADC conversion data is read). See description with function @ref DDL_ADC16_SetLowPowerMode(). */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OFFSET_NB  ADC instance - Offset number
  * @{
  */
#define DDL_ADC16_OFFSET_0  ADC_OFFSET0_REGOFFSET  /*!< ADC offset number 0: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC16_OFFSET_1  ADC_OFFSET1_REGOFFSET  /*!< ADC offset number 1: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC16_OFFSET_2  ADC_OFFSET2_REGOFFSET  /*!< ADC offset number 2: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC16_OFFSET_3  ADC_OFFSET3_REGOFFSET  /*!< ADC offset number 3: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC16_OFFSET_4  ADC_OFFSET4_REGOFFSET  /*!< ADC offset number 4: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
#define DDL_ADC16_OFFSET_5  ADC_OFFSET5_REGOFFSET  /*!< ADC offset number 5: ADC channel and offset level to which the offset programmed will be applied (independently of channel mapped on ADC group regular or group injected) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OFFSET_STATE ADC instance - Offset state
  * @{
  */
#define DDL_ADC16_OFFSET_DISABLE  (0x00000000UL)            /*!< ADC offset disabled (among ADC selected offset number 1, 2, 3 or 4) */
#define DDL_ADC16_OFFSET_ENABLE   (ADC_OFFSET1_OFFSET1_EN)  /*!< ADC offset enabled (among ADC selected offset number 1, 2, 3 or 4) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OFFSET_SIGN ADC instance - Offset sign
  * @{
  */
#define DDL_ADC16_OFFSET_SIGN_NEGATIVE  (0x00000000UL)           /*!< ADC offset is negative (among ADC selected offset number 1, 2, 3 or 4) */
#define DDL_ADC16_OFFSET_SIGN_POSITIVE  (ADC_OFFSET1_OFFSETPOS)  /*!< ADC offset is positive (among ADC selected offset number 1, 2, 3 or 4) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_CHANNEL  ADC instance - Channel number
  * @{
  */
#define DDL_ADC16_CHANNEL_0  (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP  | ADC_CHANNEL_0_BITFIELD )  /*!< ADC analog input channel INP0 */
#define DDL_ADC16_CHANNEL_1  (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP  | ADC_CHANNEL_1_BITFIELD )  /*!< ADC analog input channel INP1 */
#define DDL_ADC16_CHANNEL_2  (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP  | ADC_CHANNEL_2_BITFIELD )  /*!< ADC analog input channel INP2 */
#define DDL_ADC16_CHANNEL_3  (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP  | ADC_CHANNEL_3_BITFIELD )  /*!< ADC analog input channel INN0 */
#define DDL_ADC16_CHANNEL_4  (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP  | ADC_CHANNEL_4_BITFIELD )  /*!< ADC analog input channel INN1 */
#define DDL_ADC16_CHANNEL_5  (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP  | ADC_CHANNEL_5_BITFIELD )  /*!< ADC analog input channel INN2 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_CONTINUOUS_MODE  ADC group regular - Continuous mode
  * @{
  */
#define DDL_ADC16_REG_CONV_SINGLE      (0x00000000UL)   /*!< ADC conversions are performed in single mode: one conversion per trigger */
#define DDL_ADC16_REG_CONV_CONTINUOUS  (ADC_CFGR_CONT)  /*!< ADC conversions are performed in continuous mode: after the first trigger, following conversions launched successively automatically */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_DMA_TRANSFER  ADC group regular - DMA transfer of ADC conversion data
  * @{
  */
#define DDL_ADC16_REG_DMA_TRANSFER_NONE       (0x00000000UL)                      /*!< ADC conversions are not transferred by DMA */
#define DDL_ADC16_REG_DMA_TRANSFER_LIMITED    (                  ADC_CFGR_DMAEN)  /*!< ADC conversion data are transferred by DMA, in limited mode (one shot mode): DMA transfer requests are stopped when number of DMA data transfers (number of ADC conversions) is reached. This ADC mode is intended to be used with DMA mode non-circular. */
#define DDL_ADC16_REG_DMA_TRANSFER_UNLIMITED  (ADC_CFGR_DMACFG | ADC_CFGR_DMAEN)  /*!< ADC conversion data are transferred by DMA, in unlimited mode: DMA transfer requests are unlimited, whatever number of DMA data transferred (number of ADC conversions). This ADC mode is intended to be used with DMA mode circular. */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_REG_OVR_DATA_BEHAVIOR  ADC group regular - Overrun behavior on conversion data
  * @{
  */
#define DDL_ADC16_REG_OVR_DATA_PRESERVED    (0x00000000UL)     /*!< ADC group regular behavior in case of overrun: data preserved */
#define DDL_ADC16_REG_OVR_DATA_OVERWRITTEN  (ADC_CFGR_OVRMOD)  /*!< ADC group regular behavior in case of overrun: data overwritten */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_TRIGGER_SOURCE  ADC group injected - Trigger source
  * @{
  */
#define DDL_ADC16_INJ_TRIG_SOFTWARE         (0x00000000UL)                                                                                  /*!< ADC group injected conversion trigger internal: SW start.. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR1_TRGO    (ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                                                 /*!< ADC group injected conversion trigger from external peripheral: TMR1_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR1_CC4     (ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                            /*!< ADC group injected conversion trigger from external peripheral: TMR1_CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR2_TRGO    (ADC_JSQR_JEXTSEL_1 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                            /*!< ADC group injected conversion trigger from external peripheral: TMR2_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1     (ADC_JSQR_JEXTSEL_1 | ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR2_CC1. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR2_CC4     (ADC_JSQR_JEXTSEL_2 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                            /*!< ADC group injected conversion trigger from external peripheral: TMR2_CC4. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR4_TRGO    (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR4_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_EINT_LINE15  (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_1 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: EINT_LINE15. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR3_CC3     (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_1 | ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)  /*!< ADC group injected conversion trigger from external peripheral: TMR3_CC3. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR3_TRGO    (ADC_JSQR_JEXTSEL_3 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                            /*!< ADC group injected conversion trigger from external peripheral: TMR3_TRGO. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_TMR3_CC1     (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: TMR3_CC1. Trigger edge set to rising edge (default setting). */
#define DDL_ADC16_INJ_TRIG_EXT_LPTMROUT     (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_1 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                       /*!< ADC group injected conversion trigger from external peripheral: LPTMROUT. Trigger edge set to rising edge (default setting). */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_TRIGGER_EDGE  ADC group injected - Trigger edge
  * @{
  */
#define DDL_ADC16_INJ_TRIG_EXT_RISING         (                    ADC_JSQR_JEXTEN_0)  /*!< ADC group injected conversion trigger polarity set to rising edge */
#define DDL_ADC16_INJ_TRIG_EXT_FALLING        (ADC_JSQR_JEXTEN_1                    )  /*!< ADC group injected conversion trigger polarity set to falling edge */
#define DDL_ADC16_INJ_TRIG_EXT_RISINGFALLING  (ADC_JSQR_JEXTEN_1 | ADC_JSQR_JEXTEN_0)  /*!< ADC group injected conversion trigger polarity set to both rising and falling edges */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_SEQ_RANKS  ADC group injected - Sequencer ranks
  * @{
  */
#define DDL_ADC16_INJ_RANK_1  (ADC_JDR1_REGOFFSET | ADC_INJ_RANK_1_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 1 */
#define DDL_ADC16_INJ_RANK_2  (ADC_JDR2_REGOFFSET | ADC_INJ_RANK_2_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 2 */
#define DDL_ADC16_INJ_RANK_3  (ADC_JDR3_REGOFFSET | ADC_INJ_RANK_3_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 3 */
#define DDL_ADC16_INJ_RANK_4  (ADC_JDR4_REGOFFSET | ADC_INJ_RANK_4_JSQR_BITOFFSET_POS)  /*!< ADC group injected sequencer rank 4 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_TRIG_AUTO  ADC group injected - Automatic trigger mode
  * @{
  */
#define DDL_ADC16_INJ_TRIG_INDEPENDENT       (0x00000000UL)    /*!< ADC group injected conversion trigger independent. Setting mandatory if ADC group injected injected trigger source is set to an external trigger. */
#define DDL_ADC16_INJ_TRIG_FROM_GRP_REGULAR  (ADC_CFGR_JAUTO)  /*!< ADC group injected conversion trigger from ADC group regular. Setting compliant only with group injected trigger source set to SW start, without any further action on  ADC group injected conversion start or stop: in this case, ADC group injected is controlled only from ADC group regular. */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_INJ_CONTEXT_QUEUE  ADC group injected - Context queue mode
  * @{
  */
#define DDL_ADC16_INJ_QUEUE_2CONTEXTS_LAST_ACTIVE  (0x00000000UL)         /* Group injected sequence context queue is enabled and can contain up to 2 contexts. When all contexts have been processed, the queue maintains the last context active perpetually. */
#define DDL_ADC16_INJ_QUEUE_2CONTEXTS_END_EMPTY    (ADC_CFGR_JQM)         /* Group injected sequence context queue is enabled and can contain up to 2 contexts. When all contexts have been processed, the queue is empty and injected group triggers are disabled. */
#define DDL_ADC16_INJ_QUEUE_DISABLE                (ADC_CFGR_JQDIS)       /* Group injected sequence context queue is disabled: only 1 sequence can be configured and is active perpetually. */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_CHANNEL_SAMPLINGTIME  Channel - Sampling time
  * @{
  */
#define DDL_ADC16_SAMPLINGTIME_1CYCLES   (0x00000000)
#define DDL_ADC16_SAMPLINGTIME_2CYCLES   (ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_3CYCLES   (ADC_SMPR1_SMP0_1)
#define DDL_ADC16_SAMPLINGTIME_4CYCLES   (ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_5CYCLES   (ADC_SMPR1_SMP0_2)
#define DDL_ADC16_SAMPLINGTIME_6CYCLES   (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_7CYCLES   (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1)
#define DDL_ADC16_SAMPLINGTIME_8CYCLES   (ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_9CYCLES   (ADC_SMPR1_SMP0_3)
#define DDL_ADC16_SAMPLINGTIME_10CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_11CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_1)
#define DDL_ADC16_SAMPLINGTIME_12CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_13CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_2)
#define DDL_ADC16_SAMPLINGTIME_14CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_0)
#define DDL_ADC16_SAMPLINGTIME_15CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1)
#define DDL_ADC16_SAMPLINGTIME_16CYCLES  (ADC_SMPR1_SMP0_3 | ADC_SMPR1_SMP0_2 | ADC_SMPR1_SMP0_1 | ADC_SMPR1_SMP0_0)

/**
  * @}
  */

/** @defgroup ADC_DDL_EC_AWD_NUMBER Analog watchdog - Analog watchdog number
  * @{
  */
#define DDL_ADC16_AWD1  (ADC_AWD_CR1_CHANNEL_MASK  | ADC_AWD_CR1_REGOFFSET)  /*!< ADC analog watchdog number 1 */
#define DDL_ADC16_AWD2  (ADC_AWD_CR23_CHANNEL_MASK | ADC_AWD_CR2_REGOFFSET)  /*!< ADC analog watchdog number 2 */
#define DDL_ADC16_AWD3  (ADC_AWD_CR23_CHANNEL_MASK | ADC_AWD_CR3_REGOFFSET)  /*!< ADC analog watchdog number 3 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_AWD_CHANNELS  Analog watchdog - Monitored channels
  * @{
  */
#define DDL_ADC16_AWD_DISABLE               (0x00000000UL)                                                                                          /*!< ADC analog watchdog monitoring disabled */
#define DDL_ADC16_AWD_ALL_CHANNELS_REG      (ADC_AWD_CR23_CHANNEL_MASK                                     | ADC_CFGR_AWD1EN                   )    /*!< ADC analog watchdog monitoring of all channels, converted by group regular only */
#define DDL_ADC16_AWD_ALL_CHANNELS_INJ      (ADC_AWD_CR23_CHANNEL_MASK                  | ADC_CFGR_JAWD1EN                                     )    /*!< ADC analog watchdog monitoring of all channels, converted by group injected only */
#define DDL_ADC16_AWD_ALL_CHANNELS_REG_INJ  (ADC_AWD_CR23_CHANNEL_MASK                  | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN                   )    /*!< ADC analog watchdog monitoring of all channels, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_0_REG         ((DDL_ADC16_CHANNEL_0  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP0, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_0_INJ         ((DDL_ADC16_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP0, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_0_REG_INJ     ((DDL_ADC16_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP0, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_1_REG         ((DDL_ADC16_CHANNEL_1  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP1, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_1_INJ         ((DDL_ADC16_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP1, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_1_REG_INJ     ((DDL_ADC16_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP1, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_2_REG         ((DDL_ADC16_CHANNEL_2  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP2, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_2_INJ         ((DDL_ADC16_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP2, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_2_REG_INJ     ((DDL_ADC16_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INP2, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_3_REG         ((DDL_ADC16_CHANNEL_3  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN0, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_3_INJ         ((DDL_ADC16_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN0, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_3_REG_INJ     ((DDL_ADC16_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN0, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_4_REG         ((DDL_ADC16_CHANNEL_4  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN1, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_4_INJ         ((DDL_ADC16_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN1, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_4_REG_INJ     ((DDL_ADC16_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN1, converted by either group regular or injected */
#define DDL_ADC16_AWD_CHANNEL_5_REG         ((DDL_ADC16_CHANNEL_5  & ADC_CHANNEL_ID_MASK)                    | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN2, converted by group regular only */
#define DDL_ADC16_AWD_CHANNEL_5_INJ         ((DDL_ADC16_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN                   | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN2, converted by group injected only */
#define DDL_ADC16_AWD_CHANNEL_5_REG_INJ     ((DDL_ADC16_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)  /*!< ADC analog watchdog monitoring of ADC external channel (channel connected to GPIO pin) INN2, converted by either group regular or injected */

/**
  * @}
  */

/** @defgroup ADC_DDL_EC_AWD_THRESHOLDS  Analog watchdog - Thresholds
  * @{
  */
#define DDL_ADC16_AWD_THRESHOLD_HIGH       (ADC_TR1_HT1              )  /*!< ADC analog watchdog threshold high */
#define DDL_ADC16_AWD_THRESHOLD_LOW        (              ADC_TR1_LT1)  /*!< ADC analog watchdog threshold low */
#define DDL_ADC16_AWD_THRESHOLDS_HIGH_LOW  (ADC_TR1_HT1 | ADC_TR1_LT1)  /*!< ADC analog watchdog both thresholds high and low concatenated into the same data */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OVS_SCOPE  Oversampling - Oversampling scope
  * @{
  */
#define DDL_ADC16_OVS_DISABLE                (0x00000000UL)                                         /*!< ADC oversampling disabled. */
#define DDL_ADC16_OVS_GRP_REGULAR_CONTINUED  (                                    ADC_CFGR2_ROVSE)  /*!< ADC oversampling on conversions of ADC group regular. If group injected interrupts group regular: when ADC group injected is triggered, the oversampling on ADC group regular is temporary stopped and continued afterwards. */
#define DDL_ADC16_OVS_GRP_REGULAR_RESUMED    (ADC_CFGR2_ROVSM |                   ADC_CFGR2_ROVSE)  /*!< ADC oversampling on conversions of ADC group regular. If group injected interrupts group regular: when ADC group injected is triggered, the oversampling on ADC group regular is resumed from start (oversampler buffer reset). */
#define DDL_ADC16_OVS_GRP_INJECTED           (                  ADC_CFGR2_JOVSE                  )  /*!< ADC oversampling on conversions of ADC group injected. */
#define DDL_ADC16_OVS_GRP_INJ_REG_RESUMED    (                  ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSE)  /*!< ADC oversampling on conversions of both ADC groups regular and injected. If group injected interrupting group regular: when ADC group injected is triggered, the oversampling on ADC group regular is resumed from start (oversampler buffer reset). */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OVS_DISCONT_MODE  Oversampling - Discontinuous mode
  * @{
  */
#define DDL_ADC16_OVS_REG_CONT     (0x00000000UL)     /*!< ADC oversampling discontinuous mode: continuous mode (all conversions of oversampling ratio are done from 1 trigger) */
#define DDL_ADC16_OVS_REG_DISCONT  (ADC_CFGR2_TROVS)  /*!< ADC oversampling discontinuous mode: discontinuous mode (each conversion of oversampling ratio needs a trigger) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OVS_RATIO  Oversampling - Ratio
  * @{
  */
#define DDL_ADC16_OVS_RATIO_2   (0x00000000UL)                                            /*!< ADC oversampling ratio of 2 (2 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define DDL_ADC16_OVS_RATIO_4   (                                      ADC_CFGR2_OVSR_0)  /*!< ADC oversampling ratio of 4 (4 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define DDL_ADC16_OVS_RATIO_8   (                   ADC_CFGR2_OVSR_1                   )  /*!< ADC oversampling ratio of 8 (8 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
#define DDL_ADC16_OVS_RATIO_16  (                   ADC_CFGR2_OVSR_1 | ADC_CFGR2_OVSR_0)  /*!< ADC oversampling ratio of 16 (16 ADC conversions are performed, sum of these conversions data is computed to result as the ADC oversampling conversion data (before potential shift) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_OVS_SHIFT  Oversampling - Data shift
  * @{
  */
#define DDL_ADC16_OVS_SHIFT_NONE     (0x00000000UL)                                                               /*!< ADC oversampling no shift (sum of the ADC conversions data is not divided to result as the ADC oversampling conversion data) */
#define DDL_ADC16_OVS_SHIFT_RIGHT_1  (                                                         ADC_CFGR2_OVSS_0)  /*!< ADC oversampling shift of 1 (sum of the ADC conversions data is divided by 2 to result as the ADC oversampling conversion data) */
#define DDL_ADC16_OVS_SHIFT_RIGHT_2  (                                      ADC_CFGR2_OVSS_1                   )  /*!< ADC oversampling shift of 2 (sum of the ADC conversions data is divided by 4 to result as the ADC oversampling conversion data) */
#define DDL_ADC16_OVS_SHIFT_RIGHT_3  (                                      ADC_CFGR2_OVSS_1 | ADC_CFGR2_OVSS_0)  /*!< ADC oversampling shift of 3 (sum of the ADC conversions data is divided by 8 to result as the ADC oversampling conversion data) */
#define DDL_ADC16_OVS_SHIFT_RIGHT_4  (                   ADC_CFGR2_OVSS_2                                      )  /*!< ADC oversampling shift of 4 (sum of the ADC conversions data is divided by 16 to result as the ADC oversampling conversion data) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_FLAG ADC flags
  * @brief    Flags defines which can be used with DDL_ADC16_ReadReg function
  * @{
  */
#define DDL_ADC16_FLAG_EOC    ADC_ISR_EOC    /*!< ADC flag ADC group regular end of unitary conversion */
#define DDL_ADC16_FLAG_EOS    ADC_ISR_EOS    /*!< ADC flag ADC group regular end of sequence conversions */
#define DDL_ADC16_FLAG_OVR    ADC_ISR_OVR    /*!< ADC flag ADC group regular overrun */
#define DDL_ADC16_FLAG_EOSMP  ADC_ISR_EOSMP  /*!< ADC flag ADC group regular end of sampling phase */
#define DDL_ADC16_FLAG_JEOC   ADC_ISR_JEOC   /*!< ADC flag ADC group injected end of unitary conversion */
#define DDL_ADC16_FLAG_JEOS   ADC_ISR_JEOS   /*!< ADC flag ADC group injected end of sequence conversions */
#define DDL_ADC16_FLAG_JQOVF  ADC_ISR_JQOVF  /*!< ADC flag ADC group injected contexts queue overflow */
#define DDL_ADC16_FLAG_AWD1   ADC_ISR_AWD1   /*!< ADC flag ADC analog watchdog 1 */
#define DDL_ADC16_FLAG_AWD2   ADC_ISR_AWD2   /*!< ADC flag ADC analog watchdog 2 */
#define DDL_ADC16_FLAG_AWD3   ADC_ISR_AWD3   /*!< ADC flag ADC analog watchdog 3 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_IT ADC interruptions for configuration (interruption enable or disable)
  * @brief    IT defines which can be used with DDL_ADC16_ReadReg and  DDL_ADC16_WriteReg functions
  * @{
  */
#define DDL_ADC16_IT_EOC    ADC_IER_EOCIE    /*!< ADC interruption ADC group regular end of unitary conversion */
#define DDL_ADC16_IT_EOS    ADC_IER_EOSIE    /*!< ADC interruption ADC group regular end of sequence conversions */
#define DDL_ADC16_IT_OVR    ADC_IER_OVRIE    /*!< ADC interruption ADC group regular overrun */
#define DDL_ADC16_IT_EOSMP  ADC_IER_EOSMPIE  /*!< ADC interruption ADC group regular end of sampling phase */
#define DDL_ADC16_IT_JEOC   ADC_IER_JEOCIE   /*!< ADC interruption ADC group injected end of unitary conversion */
#define DDL_ADC16_IT_JEOS   ADC_IER_JEOSIE   /*!< ADC interruption ADC group injected end of sequence conversions */
#define DDL_ADC16_IT_JQOVF  ADC_IER_JQOVFIE  /*!< ADC interruption ADC group injected contexts queue overflow */
#define DDL_ADC16_IT_AWD1   ADC_IER_AWD1IE   /*!< ADC interruption ADC analog watchdog 1 */
#define DDL_ADC16_IT_AWD2   ADC_IER_AWD2IE   /*!< ADC interruption ADC analog watchdog 2 */
#define DDL_ADC16_IT_AWD3   ADC_IER_AWD3IE   /*!< ADC interruption ADC analog watchdog 3 */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_CHANNEL_SINGLE_DIFF_ENDING  Channel - Single or differential ending
  * @{
  */
#define DDL_ADC16_SINGLE_ENDED        (0x00000000)            /*!< ADC channel ending set to single ended (literal also used to set calibration mode) */
#define DDL_ADC16_DIFFERENTIAL_ENDED  (ADC_CFGR2_DIFSEL_Msk)  /*!< ADC channel ending set to differential (literal also used to set calibration mode) */
/**
  * @}
  */

/** @defgroup ADC_DDL_EC_AWD_FILTERING_CONFIG  Analog watchdog - filtering config
  * @{
  */
#define DDL_ADC16_AWD_FILTERING_NONE      (0x00000000UL)                                                     /*!< ADC analog wathdog no filtering, one out-of-window sample is needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_2SAMPLES  (                                            ADC_CFGR2_AWDFILT_0)  /*!< ADC analog wathdog 2 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_3SAMPLES  (                      ADC_CFGR2_AWDFILT_1                      )  /*!< ADC analog wathdog 3 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_4SAMPLES  (                      ADC_CFGR2_AWDFILT_1 | ADC_CFGR2_AWDFILT_0)  /*!< ADC analog wathdog 4 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_5SAMPLES  (ADC_CFGR2_AWDFILT_2                                            )  /*!< ADC analog wathdog 5 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_6SAMPLES  (ADC_CFGR2_AWDFILT_2 |                       ADC_CFGR2_AWDFILT_0)  /*!< ADC analog wathdog 6 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_7SAMPLES  (ADC_CFGR2_AWDFILT_2 | ADC_CFGR2_AWDFILT_1                      )  /*!< ADC analog wathdog 7 consecutives out-of-window samples are needed to raise flag or interrupt */
#define DDL_ADC16_AWD_FILTERING_8SAMPLES  (ADC_CFGR2_AWDFILT_2 | ADC_CFGR2_AWDFILT_1 | ADC_CFGR2_AWDFILT_0)  /*!< ADC analog wathdog 8 consecutives out-of-window samples are needed to raise flag or interrupt */
/**
  * @}
  */

/** @defgroup ADC_DDL_Calibration  ADC Calibration
  * @{
  */
#define DDL_ADC16_VREF_INTERNAL  (ADC_CAL_REF_SEL)
#define DDL_ADC16_VREF_EXTERNAL  (0x00000000)

/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC_DDL_Private_Macros ADC Private Macros
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
#define __ADC_PTR_REG_OFFSET(__REG__,                   __REG_OFFFSET__)                         \
  ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2UL))))

/**
  * @brief  Helper macro to get ADC channel number in decimal format
  *         from literals DDL_ADC16_CHANNEL_x.
  * @note   Example:
  *           __DDL_ADC16_CHANNEL_TO_DECIMAL_NB(DDL_ADC16_CHANNEL_4)
  *           will return decimal number "4".
  * @note   The input can be a value from functions where a channel
  *         number is returned, either defined with number
  *         or with bitfield (only one bit must be set).
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @retval Value between Min_Data=0 and Max_Data=5
  */
#define __DDL_ADC16_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)  \
  ((((__CHANNEL__) & ADC_CHANNEL_ID_BITFIELD_MASK) == 0UL) ?                               \
   (                                                                                       \
       ((__CHANNEL__) & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS \
   )                                                                                       \
   :                                                                                       \
   (                                                                                       \
       (uint32_t)POSITION_VAL((__CHANNEL__))                                               \
   )                                                                                       \
  )

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_DDL_Exported_Functions ADC Exported Functions
  * @{
  */
/** @defgroup ADC_DDL_EF_DMA_Management ADC DMA management
  * @{
  */
/* Note: DDL ADC functions to set DMA transfer are located into sections of    */
/*       configuration of ADC instance, groups and multimode (if available):  */
/*       @ref DDL_ADC16_REG_SetDMATransfer(), ...                                */

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
  *                                  DDL_ADC16_DMA_GetRegAddr(ADC2, DDL_ADC16_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< array or variable >,
  *                                  DDL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   For devices with several ADC: in multimode, some devices
  *         use a different data register outside of ADC instance scope
  *         (common data register). This macro manages this register difference,
  *         only ADC instance has to be set as parameter.
  * @param  ADCx ADC instance
  * @param  Register This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_DMA_REG_REGULAR_DATA
  *         @arg @ref DDL_ADC16_DMA_REG_REGULAR_DATA_MULTI (1)
  *
  *         (1) Available on devices with several ADC instances.
  * @retval ADC register address
  */
__STATIC_INLINE uint32_t DDL_ADC16_DMA_GetRegAddr(ADC16_TypeDef *ADCx, uint32_t Register)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(Register);

  /* Retrieve address of register DR */
  return (uint32_t) &(ADCx->DR);
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_Instance Configuration of ADC hierarchical scope: ADC instance
  * @{
  */

/**
  * @brief  Set ADC low power mode.
  * @note   Description of ADC low power modes:
  *         - ADC low power mode "auto wait": Dynamic low power mode,
  *           ADC conversions occurrences are limited to the minimum necessary
  *           in order to reduce power consumption.
  *           New ADC conversion starts only when the previous
  *           unitary conversion data (for ADC group regular)
  *           or previous sequence conversions data (for ADC group injected)
  *           has been retrieved by user software.
  *           In the meantime, ADC remains idle: does not performs any
  *           other conversion.
  *           This mode allows to automatically adapt the ADC conversions
  *           triggers to the speed of the software that reads the data.
  *           Moreover, this avoids risk of overrun for low frequency
  *           applications.
  *           How to use this low power mode:
  *           - It is not recommended to use with interruption or DMA
  *             since these modes have to clear immediately the EOC flag
  *             (by CPU to free the IRQ pending event or by DMA).
  *             Auto wait will work but fort a very short time, discarding
  *             its intended benefit (except specific case of high load of CPU
  *             or DMA transfers which can justify usage of auto wait).
  *           - Do use with polling: 1. Start conversion,
  *             2. Later on, when conversion data is needed: poll for end of
  *             conversion  to ensure that conversion is completed and
  *             retrieve ADC conversion data. This will trig another
  *             ADC conversion start.
  *         - ADC low power mode "auto power-off" (feature available on
  *           this device if parameter DD_ADC_LP_AUTOPOWEROFF is available):
  *           the ADC automatically powers-off after a conversion and
  *           automatically wakes up when a new conversion is triggered
  *           (with startup time between trigger and start of sampling).
  *           This feature can be combined with low power mode "auto wait".
  * @note   With ADC low power mode "auto wait", the ADC conversion data read
  *         is corresponding to previous ADC conversion start, independently
  *         of delay during which ADC was idle.
  *         Therefore, the ADC conversion data may be outdated: does not
  *         correspond to the current voltage level on the selected
  *         ADC channel.
  * @param  ADCx ADC instance
  * @param  LowPowerMode This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_LP_MODE_NONE
  *         @arg @ref DDL_ADC16_LP_AUTOWAIT
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetLowPowerMode(ADC16_TypeDef *ADCx, uint32_t LowPowerMode)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_AUTDLY, LowPowerMode);
}

/**
  * @brief  Get ADC low power mode:
  * @note   Description of ADC low power modes:
  *         - ADC low power mode "auto wait": Dynamic low power mode,
  *           ADC conversions occurrences are limited to the minimum necessary
  *           in order to reduce power consumption.
  *           New ADC conversion starts only when the previous
  *           unitary conversion data (for ADC group regular)
  *           or previous sequence conversions data (for ADC group injected)
  *           has been retrieved by user software.
  *           In the meantime, ADC remains idle: does not performs any
  *           other conversion.
  *           This mode allows to automatically adapt the ADC conversions
  *           triggers to the speed of the software that reads the data.
  *           Moreover, this avoids risk of overrun for low frequency
  *           applications.
  *           How to use this low power mode:
  *           - It is not recommended to use with interruption or DMA
  *             since these modes have to clear immediately the EOC flag
  *             (by CPU to free the IRQ pending event or by DMA).
  *             Auto wait will work but fort a very short time, discarding
  *             its intended benefit (except specific case of high load of CPU
  *             or DMA transfers which can justify usage of auto wait).
  *           - Do use with polling: 1. Start conversion,
  *             2. Later on, when conversion data is needed: poll for end of
  *             conversion  to ensure that conversion is completed and
  *             retrieve ADC conversion data. This will trig another
  *             ADC conversion start.
  *         - ADC low power mode "auto power-off" (feature available on
  *           this device if parameter DDL_ADC16_LP_AUTOPOWEROFF is available):
  *           the ADC automatically powers-off after a conversion and
  *           automatically wakes up when a new conversion is triggered
  *           (with startup time between trigger and start of sampling).
  *           This feature can be combined with low power mode "auto wait".
  * @note   With ADC low power mode "auto wait", the ADC conversion data read
  *         is corresponding to previous ADC conversion start, independently
  *         of delay during which ADC was idle.
  *         Therefore, the ADC conversion data may be outdated: does not
  *         correspond to the current voltage level on the selected
  *         ADC channel.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_LP_MODE_NONE
  *         @arg @ref DDL_ADC16_LP_AUTOWAIT
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetLowPowerMode(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_AUTDLY));
}

/**
  * @brief  Set ADC selected offset number 1, 2, 3 or 4.
  * @note   This function set the 2 items of offset configuration:
  *         - ADC channel to which the offset programmed will be applied
  *           (independently of channel mapped on ADC group regular
  *           or group injected)
  *         - Offset level (offset to be subtracted from the raw
  *           converted data).
  * @note   This function enables the offset, by default. It can be forced
  *         to disable state using function DDL_ADC16_SetOffsetState().
  * @note   If a channel is mapped on several offsets numbers, only the offset
  *         with the lowest value is considered for the subtraction.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  *
  * @param  OffsetLevel Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetOffset(ADC16_TypeDef *ADCx, uint32_t Offsety, uint32_t OffsetLevel)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  MODIFY_REG(*preg,
             ADC_OFFSET1_OFFSET1_EN | ADC_OFFSET1_OFFSET1,
             ADC_OFFSET1_OFFSET1_EN | OffsetLevel);
}

/**
  * @brief  Get for the ADC selected offset number 1, 2, 3 or 4:
  *         Offset level (offset to be subtracted from the raw
  *         converted data).
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOffsetLevel(ADC16_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFFSET1_OFFSET1);
}

/**
  * @brief  Set for the ADC selected offset number 1, 2, 3 or 4:
  *         force offset state disable or enable
  *         without modifying offset channel or offset value.
  * @note   This function should be needed only in case of offset to be
  *         enabled-disabled dynamically, and should not be needed in other cases:
  *         function DDL_ADC16_SetOffset() automatically enables the offset.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  * @param  OffsetState This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_DISABLE
  *         @arg @ref DDL_ADC16_OFFSET_ENABLE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetOffsetState(ADC16_TypeDef *ADCx, uint32_t Offsety, uint32_t OffsetState)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  MODIFY_REG(*preg,
             ADC_OFFSET1_OFFSET1_EN,
             OffsetState);
}

/**
  * @brief  Get for the ADC selected offset number 1, 2, 3 or 4:
  *         offset state disabled or enabled.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_DISABLE
  *         @arg @ref DDL_ADC16_OFFSET_ENABLE
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOffsetState(ADC16_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFFSET1_OFFSET1_EN);
}

/**
  * @brief  Set for the ADC selected offset number 1, 2, 3 or 4:
  *         choose offset sign.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  * @param  OffsetSign This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_SIGN_NEGATIVE
  *         @arg @ref DDL_ADC16_OFFSET_SIGN_POSITIVE
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetOffsetSign(ADC16_TypeDef *ADCx, uint32_t Offsety, uint32_t OffsetSign)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  MODIFY_REG(*preg,
             ADC_OFFSET1_OFFSETPOS,
             OffsetSign);
}

/**
  * @brief  Get for the ADC selected offset number 1, 2, 3 or 4:
  *         offset sign if positive or negative.
  * @param  ADCx ADC instance
  * @param  Offsety This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_0
  *         @arg @ref DDL_ADC16_OFFSET_1
  *         @arg @ref DDL_ADC16_OFFSET_2
  *         @arg @ref DDL_ADC16_OFFSET_3
  *         @arg @ref DDL_ADC16_OFFSET_4
  *         @arg @ref DDL_ADC16_OFFSET_5
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_OFFSET_SIGN_NEGATIVE
  *         @arg @ref DDL_ADC16_OFFSET_SIGN_POSITIVE
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOffsetSign(ADC16_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFFSET0, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFFSET1_OFFSETPOS);
}

 /**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_Group_Regular Configuration of ADC hierarchical scope: group regular
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
  *         @arg @ref DDL_ADC16_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC1
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC2
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC3
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_CC2
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR4_CC4
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_EINT_LINE11
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR3_CC4
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_LPTMROUT
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetTriggerSource(ADC16_TypeDef *ADCx, uint32_t TriggerSource)
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
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC1
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC2
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_CC3
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_CC2
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR4_CC4
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_EINT_LINE11
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_TMR3_CC4
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_LPTMROUT
  *
  * @retval None
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetTriggerSource(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_REG_IsTriggerSourceSWStart(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN) == (DDL_ADC16_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_FALLING
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_RISINGFALLING
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetTriggerEdge(ADC16_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTEN, ExternalTriggerEdge);
}

/**
  * @brief  Get ADC group regular conversion trigger polarity.
  * @note   Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_FALLING
  *         @arg @ref DDL_ADC16_REG_TRIG_EXT_RISINGFALLING
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetTriggerEdge(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN));
}

/**
  * @brief  Set ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC16_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function performs configuration of:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC16_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC16_REG_SetSequencerChannels()" available):
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
  *           function "DDL_ADC16_REG_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_12RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetSequencerLength(ADC16_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_RL, SequencerNbRanks);
}

/**
  * @brief  Get ADC group regular sequencer length and scan direction.
  * @note   Description of ADC group regular sequencer features:
  *         - For devices with sequencer fully configurable
  *           (function "DDL_ADC16_REG_SetSequencerRanks()" available):
  *           sequencer length and each rank affectation to a channel
  *           are configurable.
  *           This function retrieves:
  *           - Sequence length: Number of ranks in the scan sequence.
  *           - Sequence direction: Unless specified in parameters, sequencer
  *             scan direction is forward (from rank 1 to rank n).
  *           Sequencer ranks are selected using
  *           function "DDL_ADC16_REG_SetSequencerRanks()".
  *         - For devices with sequencer not fully configurable
  *           (function "DDL_ADC16_REG_SetSequencerChannels()" available):
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
  *           function "DDL_ADC16_REG_SetSequencerChannels()".
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_SCAN_ENABLE_12RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetSequencerLength(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_6RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetSequencerDiscont(ADC16_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM, SeqDiscont);
}

/**
  * @brief  Get ADC group regular sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_1RANK
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref DDL_ADC16_REG_SEQ_DISCONT_6RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetSequencerDiscont(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_REG_RANK_1
  *         @arg @ref DDL_ADC16_REG_RANK_2
  *         @arg @ref DDL_ADC16_REG_RANK_3
  *         @arg @ref DDL_ADC16_REG_RANK_4
  *         @arg @ref DDL_ADC16_REG_RANK_5
  *         @arg @ref DDL_ADC16_REG_RANK_6
  *         @arg @ref DDL_ADC16_REG_RANK_7
  *         @arg @ref DDL_ADC16_REG_RANK_8
  *         @arg @ref DDL_ADC16_REG_RANK_9
  *         @arg @ref DDL_ADC16_REG_RANK_10
  *         @arg @ref DDL_ADC16_REG_RANK_11
  *         @arg @ref DDL_ADC16_REG_RANK_12
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetSequencerRanks(ADC16_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Channel" with bits position          */
  /* in register and register position depending on parameter "Rank".         */
  /* Parameters "Rank" and "Channel" are used with masks because containing   */
  /* other bits reserved for other purpose.                                   */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, ((Rank & ADC_REG_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));
  __IO uint32_t value = ((Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS);
  __IO uint32_t temp = 0;
  uint32_t regVal;

  switch(value)
  {
    case 0: temp = 1; break;
    case 1: temp = 2; break;
    case 2: temp = 3; break;
    case 3: temp = 4; break;
    case 4: temp = 8; break;
    case 5: temp = 12; break;
    default: temp = 0; break;
  }

     regVal = *preg;

     regVal &= ~(ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC_REG_RANK_ID_SQRX_MASK));

     regVal |= (temp << (Rank & ADC_REG_RANK_ID_SQRX_MASK));

     *preg = regVal;
}

/**
  * @brief  Get ADC group regular sequence: channel on the selected
  *         scan sequence rank.
  *         Refer to description of function @ref DDL_ADC16_REG_SetSequencerLength().
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function DDL_ADC16_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals DDL_ADC16_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals DDL_ADC16_CHANNEL_x or using
  *           helper macro @ref __DDL_ADC16_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal DDL_ADC16_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __DDL_ADC16_CHANNEL_TO_DECIMAL_NB().
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_RANK_1
  *         @arg @ref DDL_ADC16_REG_RANK_2
  *         @arg @ref DDL_ADC16_REG_RANK_3
  *         @arg @ref DDL_ADC16_REG_RANK_4
  *         @arg @ref DDL_ADC16_REG_RANK_5
  *         @arg @ref DDL_ADC16_REG_RANK_6
  *         @arg @ref DDL_ADC16_REG_RANK_7
  *         @arg @ref DDL_ADC16_REG_RANK_8
  *         @arg @ref DDL_ADC16_REG_RANK_9
  *         @arg @ref DDL_ADC16_REG_RANK_10
  *         @arg @ref DDL_ADC16_REG_RANK_11
  *         @arg @ref DDL_ADC16_REG_RANK_12
  * @retval Returned value can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0_NUMBER
  *         @arg @ref ADC_CHANNEL_1_NUMBER
  *         @arg @ref ADC_CHANNEL_2_NUMBER
  *         @arg @ref ADC_CHANNEL_3_NUMBER
  *         @arg @ref ADC_CHANNEL_4_NUMBER
  *         @arg @ref ADC_CHANNEL_5_NUMBER
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetSequencerRanks(ADC16_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, ((Rank & ADC_REG_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));
  __IO uint32_t value = (READ_BIT(*preg, ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC_REG_RANK_ID_SQRX_MASK)) >> (Rank & ADC_REG_RANK_ID_SQRX_MASK));
  __IO uint32_t temp = 0;

  switch(value)
  {
    case 1: temp = 0; break;
    case 2: temp = 1; break;
    case 3: temp = 2; break;
    case 4: temp = 3; break;
    case 8: temp = 4; break;
    case 12: temp = 5; break;
  }

  return (uint32_t)(temp << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS);
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
  *         @arg @ref DDL_ADC16_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC16_REG_CONV_CONTINUOUS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetContinuousMode(ADC16_TypeDef *ADCx, uint32_t Continuous)
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
  *         @arg @ref DDL_ADC16_REG_CONV_SINGLE
  *         @arg @ref DDL_ADC16_REG_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetContinuousMode(ADC16_TypeDef *ADCx)
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
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC16_DMA_GetRegAddr().
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  DMATransfer This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_NONE
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_LIMITED
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_UNLIMITED
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetDMATransfer(ADC16_TypeDef *ADCx, uint32_t DMATransfer)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DMAEN | ADC_CFGR_DMACFG, DMATransfer);
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
  *         settings are available using function @ref DDL_ADC16_GetMultiDMATransfer().
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref DDL_ADC16_DMA_GetRegAddr().
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_NONE
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_LIMITED
  *         @arg @ref DDL_ADC16_REG_DMA_TRANSFER_UNLIMITED
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetDMATransfer(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DMAEN | ADC_CFGR_DMACFG));
}

/**
  * @brief  Set ADC group regular behavior in case of overrun:
  *         data preserved or overwritten.
  * @note   Compatibility with devices without feature overrun:
  *         other devices without this feature have a behavior
  *         equivalent to data overwritten.
  *         The default setting of overrun is data preserved.
  *         Therefore, for compatibility with all devices, parameter
  *         overrun should be set to data overwritten.
  * @note
  *         ADC must be disabled or enabled without conversion on going
  *         on group regular.
  * @param  ADCx ADC instance
  * @param  Overrun This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_OVR_DATA_PRESERVED
  *         @arg @ref DDL_ADC16_REG_OVR_DATA_OVERWRITTEN
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_SetOverrun(ADC16_TypeDef *ADCx, uint32_t Overrun)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_OVRMOD, Overrun);
}

/**
  * @brief  Get ADC group regular behavior in case of overrun:
  *         data preserved or overwritten.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_OVR_DATA_PRESERVED
  *         @arg @ref DDL_ADC16_REG_OVR_DATA_OVERWRITTEN
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_GetOverrun(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVRMOD));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_Group_Injected Configuration of ADC hierarchical scope: group injected
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
  *         @arg @ref DDL_ADC16_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_EINT_LINE15
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_CC3
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_LPTMROUT
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetTriggerSource(ADC16_TypeDef *ADCx, uint32_t TriggerSource)
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
  *         @arg @ref DDL_ADC16_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_EINT_LINE15
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_CC3
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_LPTMROUT
  *
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetTriggerSource(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_INJ_IsTriggerSourceSWStart(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTEN) == (DDL_ADC16_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN)) ? 1UL : 0UL);
}
/**
  * @brief  Set ADC group injected conversion trigger polarity.
  *         Applicable only for trigger source set to external trigger.
  * @note
  *         ADC must not be disabled. Can be enabled with or without conversion
  *         on going on either groups regular or injected.
  * @param  ADCx ADC instance
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_FALLING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISINGFALLING
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetTriggerEdge(ADC16_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JEXTEN, ExternalTriggerEdge);
}

/**
  * @brief  Get ADC group injected conversion trigger polarity.
  *         Applicable only for trigger source set to external trigger.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_FALLING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISINGFALLING
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetTriggerEdge(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_4RANKS
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetSequencerLength(ADC16_TypeDef *ADCx, uint32_t SequencerNbRanks)
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
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_4RANKS
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetSequencerLength(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC16_INJ_SEQ_DISCONT_1RANK
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetSequencerDiscont(ADC16_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JDISCEN, SeqDiscont);
}

/**
  * @brief  Get ADC group injected sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref DDL_ADC16_INJ_SEQ_DISCONT_1RANK
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetSequencerDiscont(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_INJ_RANK_1
  *         @arg @ref DDL_ADC16_INJ_RANK_2
  *         @arg @ref DDL_ADC16_INJ_RANK_3
  *         @arg @ref DDL_ADC16_INJ_RANK_4
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetSequencerRanks(ADC16_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Channel" with bits position          */
  /* in register depending on parameter "Rank".                               */
  /* Parameters "Rank" and "Channel" are used with masks because containing   */
  /* other bits reserved for other purpose.                                   */
  __IO uint32_t value = ((Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS);
  __IO uint32_t temp = 0;

  switch(value)
  {
    case 0: temp = 1; break;
    case 1: temp = 2; break;
    case 2: temp = 3; break;
    case 3: temp = 4; break;
    case 4: temp = 8; break;
    case 5: temp = 12; break;
    default: temp = 0; break;
  }

  MODIFY_REG(ADCx->JSQR,
             (ADC_CHANNEL_ID_NUMBER_MASK >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC_INJ_RANK_ID_JSQR_MASK),
             temp << (Rank & ADC_INJ_RANK_ID_JSQR_MASK));
}

/**
  * @brief  Get ADC group injected sequence: channel on the selected
  *         sequence rank.
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @param  ADCx ADC instance
  *         @arg @ref DDL_ADC16_INJ_RANK_1
  *         @arg @ref DDL_ADC16_INJ_RANK_2
  *         @arg @ref DDL_ADC16_INJ_RANK_3
  *         @arg @ref DDL_ADC16_INJ_RANK_4
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0_NUMBER
  *         @arg @ref ADC_CHANNEL_1_NUMBER
  *         @arg @ref ADC_CHANNEL_2_NUMBER
  *         @arg @ref ADC_CHANNEL_3_NUMBER
  *         @arg @ref ADC_CHANNEL_4_NUMBER
  *         @arg @ref ADC_CHANNEL_5_NUMBER
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetSequencerRanks(ADC16_TypeDef *ADCx, uint32_t Rank)
{
  __IO uint32_t value = (READ_BIT(ADCx->JSQR, (ADC_CHANNEL_ID_NUMBER_MASK >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (Rank & ADC_INJ_RANK_ID_JSQR_MASK)) >> (Rank & ADC_INJ_RANK_ID_JSQR_MASK));
  __IO uint32_t temp = 0;
  switch(value)
  {
    case 1: temp = 0; break;
    case 2: temp = 1; break;
    case 3: temp = 2; break;
    case 4: temp = 3; break;
    case 8: temp = 4; break;
    case 12: temp = 5; break;
  }

  return (uint32_t)(temp << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS);
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
  *         @arg @ref DDL_ADC16_INJ_TRIG_INDEPENDENT
  *         @arg @ref DDL_ADC16_INJ_TRIG_FROM_GRP_REGULAR
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetTrigAuto(ADC16_TypeDef *ADCx, uint32_t TrigAuto)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JAUTO, TrigAuto);
}

/**
  * @brief  Get ADC group injected conversion trigger:
  *         independent or from ADC group regular.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_TRIG_INDEPENDENT
  *         @arg @ref DDL_ADC16_INJ_TRIG_FROM_GRP_REGULAR
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetTrigAuto(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JAUTO));
}

/**
  * @brief  Set ADC group injected contexts queue mode.
  * @note   A context is a setting of group injected sequencer:
  *         - group injected trigger
  *         - sequencer length
  *         - sequencer ranks
  *         If contexts queue is disabled:
  *         - only 1 sequence can be configured
  *           and is active perpetually.
  *         If contexts queue is enabled:
  *         - up to 2 contexts can be queued
  *           and are checked in and out as a FIFO stack (first-in, first-out).
  *         - If a new context is set when queues is full, error is triggered
  *           by interruption "Injected Queue Overflow".
  *         - Two behaviors are possible when all contexts have been processed:
  *           the contexts queue can maintain the last context active perpetually
  *           or can be empty and injected group triggers are disabled.
  *         - Triggers can be only external (not internal SW start)
  *         - Caution: The sequence must be fully configured in one time
  *           (one write of register JSQR makes a check-in of a new context
  *           into the queue).
  *           Therefore functions to set separately injected trigger and
  *           sequencer channels cannot be used, register JSQR must be set
  *           using function @ref DDL_ADC16_INJ_ConfigQueueContext().
  * @note   This parameter can be modified only when no conversion is on going
  *         on either groups regular or injected.
  * @note   A modification of the context mode (bit JQDIS) causes the contexts
  *         queue to be flushed and the register JSQR is cleared.
  * @param  ADCx ADC instance
  * @param  QueueMode This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_QUEUE_DISABLE
  *         @arg @ref DDL_ADC16_INJ_QUEUE_2CONTEXTS_LAST_ACTIVE
  *         @arg @ref DDL_ADC16_INJ_QUEUE_2CONTEXTS_END_EMPTY
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_SetQueueMode(ADC16_TypeDef *ADCx, uint32_t QueueMode)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JQM | ADC_CFGR_JQDIS, QueueMode);
}

/**
  * @brief  Get ADC group injected context queue mode.
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_QUEUE_DISABLE
  *         @arg @ref DDL_ADC16_INJ_QUEUE_2CONTEXTS_LAST_ACTIVE
  *         @arg @ref DDL_ADC16_INJ_QUEUE_2CONTEXTS_END_EMPTY
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_GetQueueMode(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JQM | ADC_CFGR_JQDIS));
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
  *         Refer to function @ref DDL_ADC16_INJ_SetQueueMode().
  * @note   In the contexts queue, only the active context can be read.
  *         The parameters of this function can be read using functions:
  *         @arg @ref DDL_ADC16_INJ_GetTriggerSource()
  *         @arg @ref DDL_ADC16_INJ_GetTriggerEdge()
  *         @arg @ref DDL_ADC16_INJ_GetSequencerRanks()
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_TRIG_SOFTWARE
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR1_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC4
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR4_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_EINT_LINE15
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_CC3
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR3_TRGO
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_TMR2_CC1
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_LPTMROUT
  *
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_FALLING
  *         @arg @ref DDL_ADC16_INJ_TRIG_EXT_RISINGFALLING
  *
  *         Note: This parameter is discarded in case of SW start:
  *               parameter "TriggerSource" set to "DDL_ADC16_INJ_TRIG_SOFTWARE".
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref DDL_ADC16_INJ_SEQ_SCAN_ENABLE_4RANKS
  * @param  Rank1_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @param  Rank2_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @param  Rank3_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @param  Rank4_Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_ConfigQueueContext(ADC16_TypeDef *ADCx,
                                                   uint32_t TriggerSource,
                                                   uint32_t ExternalTriggerEdge,
                                                   uint32_t SequencerNbRanks,
                                                   uint32_t Rank1_Channel,
                                                   uint32_t Rank2_Channel,
                                                   uint32_t Rank3_Channel,
                                                   uint32_t Rank4_Channel)
{
  /* Set bits with content of parameter "Rankx_Channel" with bits position    */
  /* in register depending on literal "DDL_ADC16_INJ_RANK_x".                    */
  /* Parameters "Rankx_Channel" and "DDL_ADC16_INJ_RANK_x" are used with masks   */
  /* because containing other bits reserved for other purpose.                */
  /* If parameter "TriggerSource" is set to SW start, then parameter          */
  /* "ExternalTriggerEdge" is discarded.                                      */
  uint32_t is_trigger_not_sw = (uint32_t)((TriggerSource != DDL_ADC16_INJ_TRIG_SOFTWARE) ? 1UL : 0UL);
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
             (((Rank4_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC16_INJ_RANK_4 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank3_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC16_INJ_RANK_3 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank2_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC16_INJ_RANK_2 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank1_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) << (DDL_ADC16_INJ_RANK_1 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             SequencerNbRanks
            );
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_Channels Configuration of ADC hierarchical scope: channels
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
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_1CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_2CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_3CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_4CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_5CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_6CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_8CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_9CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_10CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_11CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_12CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_13CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_14CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_15CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_16CYCLES
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetChannelSamplingTime(ADC16_TypeDef *ADCx, uint32_t Channel, uint32_t SamplingTime)
{
  /* Set bits with content of parameter "SamplingTime" with bits position     */
  /* in register and register position depending on parameter "Channel".      */
  /* Parameter "Channel" is used with masks because containing                */
  /* other bits reserved for other purpose.                                   */

  MODIFY_REG(ADCx->SMPR1,
             ADC_SMPR1_SMP0 << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS),
             SamplingTime   << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS));
}

/**
  * @brief  Get sampling time of the selected ADC channel
  *         Unit: ADC clock cycles.
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  * @param  ADCx ADC instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_1CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_2CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_3CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_4CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_5CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_6CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_8CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_9CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_10CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_11CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_12CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_13CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_14CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_15CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_16CYCLES
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetChannelSamplingTime(ADC16_TypeDef *ADCx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(ADCx->SMPR1,
                             ADC_SMPR1_SMP0 << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS))
                    >> ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS)
                   );
}

/**
  * @brief  Set ADC Disable Command
  * @note   ADDIS can only be set to 1 by software when ADEN=1, ADSTART=0, and JADSTART=0
  *         (this ensures that no conversions are currently in progress)
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetDisableCommand(ADC16_TypeDef *ADCx)
{
  MODIFY_REG(ADCx->CR, ADC_CR_ADDIS, DDL_ADC16_CR_ADDIS_EXECUTION_IN_PROGRESS);
}

/**
  * @brief  Get ADC Disable Command
  * @param  ADCx ADC instance
  * @retval ADC Disable Command
  *         @arg @ref DDL_ADC16_CR_ADDIS_NOT_EXECUTED
  *         @arg @ref DDL_ADC16_CR_ADDIS_EXECUTION_IN_PROGRESS
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetDisableCommandStatus(ADC16_TypeDef *ADCx)
{
  return (uint32_t)READ_BIT(ADCx->CR, ADC_CR_ADDIS);
}

/**
  * @brief  Set mode single-ended or differential input of the selected
  *         ADC channel.
  * @note   Channel ending is on channel scope: independently of channel mapped
  *         on ADC group regular or injected.
  *         In differential mode: Differential measurement is carried out
  *         between the selected channel 'i' (positive input) and
  *         channel 'i+1' (negative input). Only channel 'i' has to be
  *         configured, channel 'i+1' is configured automatically.
  * @note   Refer to Reference Manual to ensure the selected channel is
  *         available in differential mode.
  *         For example, internal channels (VrefInt, TempSensor, ...) are
  *         not available in differential mode.
  * @note   When configuring a channel 'i' in differential mode,
  *         the channel 'i+1' is not usable separately.
  * @param  ADCx ADC instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @param  SingleDiff This parameter can be a combination of the following values:
  *         @arg @ref DDL_ADC16_SINGLE_ENDED
  *         @arg @ref DDL_ADC16_DIFFERENTIAL_ENDED
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetChannelSingleDiff(ADC16_TypeDef *ADCx, uint32_t Channel, uint32_t SingleDiff)
{
  /* Bits for single or differential mode selection for each channel are set  */
  /* to 1 only when the differential mode is selected, and to 0 when the      */
  /* single mode is selected.                                                 */
  (void)Channel;
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_DIFSEL, SingleDiff);
}

/**
  * @brief  Get mode single-ended or differential input of the selected
  *         ADC channel.
  * @note   When configuring a channel 'i' in differential mode,
  *         the channel 'i+1' is not usable separately.
  *         Therefore, to ensure a channel is configured in single-ended mode,
  *         the configuration of channel itself and the channel 'i-1' must be
  *         read back (to ensure that the selected channel channel has not been
  *         configured in differential mode by the previous channel).
  * @note   Refer to Reference Manual to ensure the selected channel is
  *         available in differential mode.
  *         For example, internal channels (VrefInt, TempSensor, ...) are
  *         not available in differential mode.
  * @note   When configuring a channel 'i' in differential mode,
  *         the channel 'i+1' is not usable separately.
  * @param  ADCx ADC instance
  * @param  Channel This parameter can be a combination of the following values:
  *         @arg @ref DDL_ADC16_CHANNEL_0
  *         @arg @ref DDL_ADC16_CHANNEL_1
  *         @arg @ref DDL_ADC16_CHANNEL_2
  *         @arg @ref DDL_ADC16_CHANNEL_3
  *         @arg @ref DDL_ADC16_CHANNEL_4
  *         @arg @ref DDL_ADC16_CHANNEL_5
  * @retval 0: channel in single-ended mode, else: channel in differential mode
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetChannelSingleDiff(ADC16_TypeDef *ADCx, uint32_t Channel)
{
  (void)Channel;
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DIFSEL));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_AnalogWatchdog Configuration of ADC transversal scope: analog watchdog
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
  *             (DDL_ADC16_AWD_CHANNEL4_REG_INJ | DDL_ADC16_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC16_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC16_AWD_CHANNELxx_REG and DDL_ADC16_AWD_CHANNELxx_INJ)
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @param  AWDChannelGroup This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD_DISABLE
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_REG
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_INJ
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_REG_INJ
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetAnalogWDMonitChannels(ADC16_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDChannelGroup)
{
  /* Set bits with content of parameter "AWDChannelGroup" with bits position  */
  /* in register and register position depending on parameter "AWDy".         */
  /* Parameters "AWDChannelGroup" and "AWDy" are used with masks because      */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR, ((AWDy & ADC_AWD_CRX_REGOFFSET_MASK) >> ADC_AWD_CRX_REGOFFSET_POS)
                                             + ((AWDy & ADC_AWD_CR12_REGOFFSETGAP_MASK) * ADC_AWD_CR12_REGOFFSETGAP_VAL));

  MODIFY_REG(*preg,
             (AWDy & ADC_AWD_CR_ALL_CHANNEL_MASK),
             AWDChannelGroup & AWDy);
}

/**
  * @brief  Get ADC analog watchdog monitored channel.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function DDL_ADC16_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals DDL_ADC16_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals DDL_ADC16_CHANNEL_x or using
  *           helper macro @ref __DDL_ADC16_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal DDL_ADC16_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __DDL_ADC16_CHANNEL_TO_DECIMAL_NB().
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
  *             (DDL_ADC16_AWD_CHANNEL4_REG_INJ | DDL_ADC16_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC16_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC16_AWD_CHANNELxx_REG and DDL_ADC16_AWD_CHANNELxx_INJ)
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD_DISABLE
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_REG
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_INJ
  *         @arg @ref DDL_ADC16_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_REG
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_INJ
  *         @arg @ref DDL_ADC16_AWD_CHANNEL_5_REG_INJ
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetAnalogWDMonitChannels(ADC16_TypeDef *ADCx, uint32_t AWDy)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR, ((AWDy & ADC_AWD_CRX_REGOFFSET_MASK) >> ADC_AWD_CRX_REGOFFSET_POS)
                                                   + ((AWDy & ADC_AWD_CR12_REGOFFSETGAP_MASK) * ADC_AWD_CR12_REGOFFSETGAP_VAL));

  uint32_t AnalogWDMonitChannels = (READ_BIT(*preg, AWDy) & ADC_AWD_CR_ALL_CHANNEL_MASK);

  /* If "AnalogWDMonitChannels" == 0, then the selected AWD is disabled       */
  /* (parameter value DDL_ADC16_AWD_DISABLE).                                    */
  /* Else, the selected AWD is enabled and is monitoring a group of channels  */
  /* or a single channel.                                                     */
  if (AnalogWDMonitChannels != 0UL)
  {
    if (AWDy == DDL_ADC16_AWD1)
    {
      if ((AnalogWDMonitChannels & ADC_CFGR_AWD1SGL) == 0UL)
      {
        /* AWD monitoring a group of channels */
        AnalogWDMonitChannels = ((AnalogWDMonitChannels
                                  | (ADC_AWD_CR23_CHANNEL_MASK)
                                 )
                                 & (~(ADC16_CFGR_AWD1CH))
                                );
      }
      else
      {
        /* AWD monitoring a single channel */
        AnalogWDMonitChannels = (AnalogWDMonitChannels
                                 | (ADC_AWD2CR_AWD2CH_0 << (AnalogWDMonitChannels >> ADC_CFGR_AWD1CH_Pos))
                                );
      }
    }
    else
    {
      if ((AnalogWDMonitChannels & ADC_AWD_CR23_CHANNEL_MASK) == ADC_AWD_CR23_CHANNEL_MASK)
      {
        /* AWD monitoring a group of channels */
        AnalogWDMonitChannels = (ADC_AWD_CR23_CHANNEL_MASK
                                 | ((ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN))
                                );
      }
      else
      {
        /* AWD monitoring a single channel */
        /* AWD monitoring a group of channels */
        AnalogWDMonitChannels = (AnalogWDMonitChannels
                                 | (ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)
                                 | (__DDL_ADC16_CHANNEL_TO_DECIMAL_NB(AnalogWDMonitChannels) << ADC_CFGR_AWD1CH_Pos)
                                );
      }
    }
  }

  return AnalogWDMonitChannels;
}

/**
  * @brief  Set ADC analog watchdog thresholds value of both thresholds
  *         high and low.
  * @note   If value of only one threshold high or low must be set,
  *         use function @ref DDL_ADC16_SetAnalogWDThresholds().
  * @note
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC16_AWD_CHANNEL4_REG_INJ | DDL_ADC16_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC16_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC16_AWD_CHANNELxx_REG and DDL_ADC16_AWD_CHANNELxx_INJ)
  * @note   If ADC oversampling is enabled, ADC analog watchdog thresholds are
  *         impacted: the comparison of analog watchdog thresholds is done on
  *         oversampling final computation (after ratio and shift application):
  *         ADC data register bitfield [15:0] (16 most significant bits).
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @param  AWDThresholdHighValue Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @param  AWDThresholdLowValue Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ConfigAnalogWDThresholds(ADC16_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdHighValue,
                                                     uint32_t AWDThresholdLowValue)
{
  /* Set bits with content of parameter "AWDThresholdxxxValue" with bits      */
  /* position in register and register position depending on parameter        */
  /* "AWDy".                                                                  */
  /* Parameters "AWDy" and "AWDThresholdxxxValue" are used with masks because */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1, ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_TR1_HT1 | ADC_TR1_LT1,
             (AWDThresholdHighValue << ADC_TR1_HT1_BITOFFSET_POS) | AWDThresholdLowValue);
}

/**
  * @brief  Set ADC analog watchdog threshold value of threshold
  *         high or low.
  * @note   If values of both thresholds high or low must be set,
  *         use function @ref DDL_ADC16_ConfigAnalogWDThresholds().
  * @note
  *         - AWD flexible (instances AWD2, AWD3):
  *           - channels monitored: flexible on channels monitored, selection is
  *             channel wise, from from 1 to all channels.
  *             Specificity of this analog watchdog: Multiple channels can
  *             be selected. For example:
  *             (DDL_ADC16_AWD_CHANNEL4_REG_INJ | DDL_ADC16_AWD_CHANNEL5_REG_INJ | ...)
  *           - groups monitored: not selection possible (monitoring on both
  *             groups regular and injected).
  *             Channels selected are monitored on groups regular and injected:
  *             DDL_ADC16_AWD_CHANNELxx_REG_INJ (do not use parameters
  *             DDL_ADC16_AWD_CHANNELxx_REG and DDL_ADC16_AWD_CHANNELxx_INJ)
  * @note   If ADC oversampling is enabled, ADC analog watchdog thresholds are
  *         impacted: the comparison of analog watchdog thresholds is done on
  *         oversampling final computation (after ratio and shift application):
  *         ADC data register bitfield [15:4] (12 most significant bits).
  *         ADC can be disabled, enabled with or without conversion on going
  *         on either ADC groups regular or injected.
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD_THRESHOLD_HIGH
  *         @arg @ref DDL_ADC16_AWD_THRESHOLD_LOW
  * @param  AWDThresholdValue Value between Min_Data=0x0000 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetAnalogWDThresholds(ADC16_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdsHighLow,
                                                  uint32_t AWDThresholdValue)
{
  /* Set bits with content of parameter "AWDThresholdValue" with bits         */
  /* position in register and register position depending on parameters       */
  /* "AWDThresholdsHighLow" and "AWDy".                                       */
  /* Parameters "AWDy" and "AWDThresholdValue" are used with masks because    */
  /* containing other bits reserved for other purpose.                        */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1,
                                             ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             AWDThresholdsHighLow,
             AWDThresholdValue << ((AWDThresholdsHighLow & ADC_AWD_TRX_BIT_HIGH_MASK) >> ADC_AWD_TRX_BIT_HIGH_SHIFT4));
}

/**
  * @brief  Get ADC analog watchdog threshold value of threshold high,
  *         threshold low or raw data with ADC thresholds high and low
  *         concatenated.
  * @note   If raw data with ADC thresholds high and low is retrieved,
  *         the data of each threshold high or low can be isolated
  *         using helper macro:
  *         @ref __DDL_ADC16_ANALOGWD_THRESHOLDS_HIGH_LOW().
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD_THRESHOLD_HIGH
  *         @arg @ref DDL_ADC16_AWD_THRESHOLD_LOW
  *         @arg @ref DDL_ADC16_AWD_THRESHOLDS_HIGH_LOW
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetAnalogWDThresholds(ADC16_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdsHighLow)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1,
                                                   ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             (AWDThresholdsHighLow | ADC_TR1_LT1))
                    >> (((AWDThresholdsHighLow & ADC_AWD_TRX_BIT_HIGH_MASK) >> ADC_AWD_TRX_BIT_HIGH_SHIFT4)
                        & ~(AWDThresholdsHighLow & ADC_TR1_LT1)));
}

/**
  * @brief  Set ADC analog watchdog filtering configuration
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  *         @arg @ref DDL_ADC16_AWD2
  *         @arg @ref DDL_ADC16_AWD3
  * @param  FilteringConfig This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD_FILTERING_NONE
  *         @arg @ref DDL_ADC16_AWD_FILTERING_2SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_3SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_4SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_5SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_6SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_7SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_8SAMPLES
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetAWDFilteringConfiguration(ADC16_TypeDef *ADCx, uint32_t AWDy, uint32_t FilteringConfig)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(AWDy);
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AWDFILT, FilteringConfig);
}

/**
  * @brief  Get ADC analog watchdog filtering configuration
  * @param  ADCx ADC instance
  * @param  AWDy This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_AWD1
  * @retval Returned value can be:
  *         @arg @ref DDL_ADC16_AWD_FILTERING_NONE
  *         @arg @ref DDL_ADC16_AWD_FILTERING_2SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_3SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_4SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_5SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_6SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_7SAMPLES
  *         @arg @ref DDL_ADC16_AWD_FILTERING_8SAMPLES
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetAWDFilteringConfiguration(ADC16_TypeDef *ADCx, uint32_t AWDy)
{
  /* Prevent unused argument(s) compilation warning */
  (void)(AWDy);
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AWDFILT));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_oversampling Configuration of ADC transversal scope: oversampling
  * @{
  */
/**
  * @brief  Set ADC oversampling scope: ADC groups regular and-or injected
  * @note   If both groups regular and injected are selected,
  *         specify behavior of ADC group injected interrupting
  *         group regular: when ADC group injected is triggered,
  *         the oversampling on ADC group regular is either
  *         temporary stopped and continued, or resumed from start
  *         (oversampler buffer reset).
  * @param  ADCx ADC instance
  * @param  OvsScope This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_DISABLE
  *         @arg @ref DDL_ADC16_OVS_GRP_REGULAR_CONTINUED
  *         @arg @ref DDL_ADC16_OVS_GRP_REGULAR_RESUMED
  *         @arg @ref DDL_ADC16_OVS_GRP_INJECTED
  *         @arg @ref DDL_ADC16_OVS_GRP_INJ_REG_RESUMED
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetOverSamplingScope(ADC16_TypeDef *ADCx, uint32_t OvsScope)
{
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_ROVSE | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSM, OvsScope);
}

/**
  * @brief  Get ADC oversampling scope: ADC groups regular and-or injected
  * @note   If both groups regular and injected are selected,
  *         specify behavior of ADC group injected interrupting
  *         group regular: when ADC group injected is triggered,
  *         the oversampling on ADC group regular is either
  *         temporary stopped and continued, or resumed from start
  *         (oversampler buffer reset).
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_DISABLE
  *         @arg @ref DDL_ADC16_OVS_GRP_REGULAR_CONTINUED
  *         @arg @ref DDL_ADC16_OVS_GRP_REGULAR_RESUMED
  *         @arg @ref DDL_ADC16_OVS_GRP_INJECTED
  *         @arg @ref DDL_ADC16_OVS_GRP_INJ_REG_RESUMED
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOverSamplingScope(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_ROVSE | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSM));
}

/**
  * @brief  Set ADC oversampling discontinuous mode (triggered mode)
  *         on the selected ADC group.
  * @note   Number of oversampled conversions are done either in:
  *         - continuous mode (all conversions of oversampling ratio
  *           are done from 1 trigger)
  *         - discontinuous mode (each conversion of oversampling ratio
  *           needs a trigger)
  * @note   Oversampling discontinuous mode
  *         (triggered mode) can be used only when oversampling is
  *         set on group regular only and in resumed mode.
  * @param  ADCx ADC instance
  * @param  OverSamplingDiscont This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_REG_CONT
  *         @arg @ref DDL_ADC16_OVS_REG_DISCONT
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetOverSamplingDiscont(ADC16_TypeDef *ADCx, uint32_t OverSamplingDiscont)
{
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_TROVS, OverSamplingDiscont);
}

/**
  * @brief  Get ADC oversampling discontinuous mode (triggered mode)
  *         on the selected ADC group.
  * @note   Number of oversampled conversions are done either in:
  *         - continuous mode (all conversions of oversampling ratio
  *           are done from 1 trigger)
  *         - discontinuous mode (each conversion of oversampling ratio
  *           needs a trigger)
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_REG_CONT
  *         @arg @ref DDL_ADC16_OVS_REG_DISCONT
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOverSamplingDiscont(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_TROVS));
}

/**
  * @brief  Set ADC oversampling
  *         (impacting both ADC groups regular and injected)
  * @note   This function set the 2 items of oversampling configuration:
  *         - ratio
  *         - shift
  * @param  ADCx ADC instance
  * @param  Ratio This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_RATIO_2
  *         @arg @ref DDL_ADC16_OVS_RATIO_4
  *         @arg @ref DDL_ADC16_OVS_RATIO_8
  *         @arg @ref DDL_ADC16_OVS_RATIO_16
  * @param  Shift This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_SHIFT_NONE
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_1
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_2
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_3
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_4
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ConfigOverSamplingRatioShift(ADC16_TypeDef *ADCx, uint32_t Ratio, uint32_t Shift)
{
  MODIFY_REG(ADCx->CFGR2, (ADC_CFGR2_OVSS | ADC_CFGR2_OVSR), (Shift | Ratio));
}

/**
  * @brief  Get ADC oversampling ratio
  *        (impacting both ADC groups regular and injected)
  * @param  ADCx ADC instance
  * @retval Ratio This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_RATIO_2
  *         @arg @ref DDL_ADC16_OVS_RATIO_4
  *         @arg @ref DDL_ADC16_OVS_RATIO_8
  *         @arg @ref DDL_ADC16_OVS_RATIO_16
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOverSamplingRatio(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSR));
}

/**
  * @brief  Get ADC oversampling shift
  *        (impacting both ADC groups regular and injected)
  * @param  ADCx ADC instance
  * @retval Shift This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_OVS_SHIFT_NONE
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_1
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_2
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_3
  *         @arg @ref DDL_ADC16_OVS_SHIFT_RIGHT_4
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetOverSamplingShift(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSS));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Configuration_ADC_Multimode Configuration of ADC hierarchical scope: multimode
  * @{
  */
/**
  * @brief  Set ADC multimode configuration to operate in independent mode
  *         or multimode (for devices with several ADC instances).
  * @note   If multimode configuration: the selected ADC instance is
  *         either master or slave depending on hardware.
  *         Refer to reference manual.
  * @param  ADCx ADC instance    - only for ADC2
  * @param  Multimode This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_MULTI_INDEPENDENT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIMULT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_INTERL
  *         @arg @ref DDL_ADC16_MULTI_DUAL_INJ_SIMULT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_INJ_ALTERN
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_SIM
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_ALT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_INT_INJ_SIM
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetMultimode(ADC16_TypeDef *ADCx, uint32_t Multimode)
{
  MODIFY_REG(ADCx->CR, ADC_CR_DUALMOD, Multimode);
}

/**
  * @brief  Get ADC multimode configuration to operate in independent mode
  *         or multimode (for devices with several ADC instances).
  * @note   If multimode configuration: the selected ADC instance is
  *         either master or slave depending on hardware.
  *         Refer to reference manual.
  * @param  ADCx ADC instance    - only for ADC2
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_ADC16_MULTI_INDEPENDENT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIMULT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_INTERL
  *         @arg @ref DDL_ADC16_MULTI_DUAL_INJ_SIMULT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_INJ_ALTERN
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_SIM
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_SIM_INJ_ALT
  *         @arg @ref DDL_ADC16_MULTI_DUAL_REG_INT_INJ_SIM
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetMultimode(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR, ADC_CR_DUALMOD));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Operation_ADC_Instance Operation on ADC hierarchical scope: ADC instance
  * @{
  */
/**
  * @brief  Enable the selected ADC instance.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_Enable(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE void DDL_ADC16_Disable(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabled(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADEN) == (ADC_CR_ADEN)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Operation_ADC_Group_Regular Operation on ADC hierarchical scope: group regular
  * @{
  */
/**
  * @brief  Start ADC group regular conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_REG_StartConversion(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE void DDL_ADC16_REG_StopConversion(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_REG_IsConversionOngoing(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTART) == (ADC_CR_ADSTART)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group regular command of conversion stop state
  * @param  ADCx ADC instance
  * @retval 0: no command of conversion stop is on going on ADC group regular.
  */
__STATIC_INLINE uint32_t DDL_ADC16_REG_IsStopConversionOngoing(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_REG_ReadConversionData32(ADC16_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA | ADC_DR_ADC2RDATA));
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_Operation_ADC_Group_Injected Operation on ADC hierarchical scope: group injected
  * @{
  */

/**
  * @brief  Start ADC group injected conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_INJ_StartConversion(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE void DDL_ADC16_INJ_StopConversion(ADC16_TypeDef *ADCx)
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
__STATIC_INLINE uint32_t DDL_ADC16_INJ_IsConversionOngoing(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_JADSTART) == (ADC_CR_JADSTART)) ? 1UL : 0UL);
}

/**
  * @brief  Get ADC group injected command of conversion stop state
  * @param  ADCx ADC instance
  * @retval 0: no command of conversion stop is on going on ADC group injected.
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_IsStopConversionOngoing(ADC16_TypeDef *ADCx)
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
  *         @arg @ref DDL_ADC16_INJ_RANK_1
  *         @arg @ref DDL_ADC16_INJ_RANK_2
  *         @arg @ref DDL_ADC16_INJ_RANK_3
  *         @arg @ref DDL_ADC16_INJ_RANK_4
  * @retval Value between Min_Data=0x0000 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t DDL_ADC16_INJ_ReadConversionData32(ADC16_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,ADC_JDR1_JDATA));
}

/**
* @}
*/

/** @defgroup ADC_DDL_EF_Operation_ADC_Instance Operation on ADC calibration : ADC instance
  * @{
  */

/**
  * @brief  Set VREF to be internally generated.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetVerfInternal(ADC16_TypeDef *ADCx)
{
  MODIFY_REG(ADCx->CAL, ADC_CAL_REF_SEL, DDL_ADC16_VREF_INTERNAL);
}

/**
  * @brief  Determine whether the current setting of VREF is
  *         internally generated or externally connected.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetVerfExternal(ADC16_TypeDef *ADCx)
{
  MODIFY_REG(ADCx->CAL, ADC_CAL_REF_SEL, DDL_ADC16_VREF_EXTERNAL);
}

/**
  * @brief  Get VREF Status
  * @param  ADCx ADC instance
  * @retval Status
  *         @arg @ref DDL_ADC16_VREF_EXTERNAL
  *         @arg @ref DDL_ADC16_VREF_INTERNAL
  */
__STATIC_INLINE uint32_t DDL_ADC16_GetVerfStatus(ADC16_TypeDef *ADCx)
{
  return (uint32_t)READ_BIT(ADCx->CAL, ADC_CAL_REF_SEL);
}

/**
* @}
*/

/** @defgroup ADC_DDL_EF_FLAG_Management ADC flag management
  * @{
  */

/**
  * @brief  Get flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_EOC(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_EOC) == (DDL_ADC16_FLAG_EOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_EOS(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_EOS) == (DDL_ADC16_FLAG_EOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular overrun.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_OVR(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_OVR) == (DDL_ADC16_FLAG_OVR)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group regular end of sampling phase.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_EOSMP(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_EOSMP) == (DDL_ADC16_FLAG_EOSMP)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_JEOC(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_JEOC) == (DDL_ADC16_FLAG_JEOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_JEOS(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_JEOS) == (DDL_ADC16_FLAG_JEOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC group injected contexts queue overflow.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_JQOVF(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_JQOVF) == (DDL_ADC16_FLAG_JQOVF)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC analog watchdog 1 flag
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_AWD1(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_AWD1) == (DDL_ADC16_FLAG_AWD1)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC analog watchdog 2.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_AWD2(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_AWD2) == (DDL_ADC16_FLAG_AWD2)) ? 1UL : 0UL);
}

/**
  * @brief  Get flag ADC analog watchdog 3.
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsActiveFlag_AWD3(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, DDL_ADC16_FLAG_AWD3) == (DDL_ADC16_FLAG_AWD3)) ? 1UL : 0UL);
}

/**
  * @brief  Clear flag ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_EOC(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_EOC);
}

/**
  * @brief  Clear flag ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_EOS(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_EOS);
}

/**
  * @brief  Clear flag ADC group regular overrun.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_OVR(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_OVR);
}

/**
  * @brief  Clear flag ADC group regular end of sampling phase.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_EOSMP(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_EOSMP);
}

/**
  * @brief  Clear flag ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_JEOC(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_JEOC);
}

/**
  * @brief  Clear flag ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_JEOS(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_JEOS);
}

/**
  * @brief  Clear flag ADC group injected contexts queue overflow.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_JQOVF(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_JQOVF);
}

/**
  * @brief  Clear flag ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_AWD1(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_AWD1);
}

/**
  * @brief  Clear flag ADC analog watchdog 2.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_AWD2(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_AWD2);
}

/**
  * @brief  Clear flag ADC analog watchdog 3.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_ClearFlag_AWD3(ADC16_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, DDL_ADC16_FLAG_AWD3);
}

/**
  * @}
  */

/** @defgroup ADC_DDL_EF_IT_Management ADC IT management
  * @{
  */

/**
  * @brief  Enable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_EOC(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_EOC);
}

/**
  * @brief  Enable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_EOS(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_EOS);
}

/**
  * @brief  Enable ADC group regular interruption overrun.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_OVR(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_OVR);
}

/**
  * @brief  Enable interruption ADC group regular end of sampling.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_EOSMP(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_EOSMP);
}

/**
  * @brief  Enable interruption ADC group injected end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_JEOC(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_JEOC);
}

/**
  * @brief  Enable interruption ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_JEOS(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_JEOS);
}

/**
  * @brief  Enable interruption ADC group injected context queue overflow.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_JQOVF(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_JQOVF);
}

/**
  * @brief  Enable interruption ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_AWD1(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_AWD1);
}

/**
  * @brief  Enable interruption ADC analog watchdog 2.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_AWD2(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_AWD2);
}

/**
  * @brief  Enable interruption ADC analog watchdog 3.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_EnableIT_AWD3(ADC16_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, DDL_ADC16_IT_AWD3);
}

/**
  * @brief  Disable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_EOC(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_EOC);
}

/**
  * @brief  Disable interruption ADC group regular end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_EOS(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_EOS);
}

/**
  * @brief  Disable interruption ADC group regular overrun.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_OVR(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_OVR);
}

/**
  * @brief  Disable interruption ADC group regular end of sampling.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_EOSMP(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_EOSMP);
}

/**
  * @brief  Disable interruption ADC group regular end of unitary conversion.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_JEOC(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_JEOC);
}

/**
  * @brief  Disable interruption ADC group injected end of sequence conversions.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_JEOS(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_JEOS);
}

/**
  * @brief  Disable interruption ADC group injected context queue overflow.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_JQOVF(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_JQOVF);
}

/**
  * @brief  Disable interruption ADC analog watchdog 1.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_AWD1(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_AWD1);
}

/**
  * @brief  Disable interruption ADC analog watchdog 2.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_AWD2(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_AWD2);
}

/**
  * @brief  Disable interruption ADC analog watchdog 3.
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_DisableIT_AWD3(ADC16_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, DDL_ADC16_IT_AWD3);
}

/**
  * @brief  Get state of interruption ADC group regular end of unitary conversion
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_EOC(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_EOC) == (DDL_ADC16_IT_EOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group regular end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_EOS(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_EOS) == (DDL_ADC16_IT_EOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group regular overrun
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_OVR(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_OVR) == (DDL_ADC16_IT_OVR)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group regular end of sampling
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_EOSMP(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_EOSMP) == (DDL_ADC16_IT_EOSMP)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group injected end of unitary conversion
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_JEOC(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_JEOC) == (DDL_ADC16_IT_JEOC)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group injected end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_JEOS(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_JEOS) == (DDL_ADC16_IT_JEOS)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC group injected context queue overflow interrupt state
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_JQOVF(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_JQOVF) == (DDL_ADC16_IT_JQOVF)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption ADC analog watchdog 1
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_AWD1(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_AWD1) == (DDL_ADC16_IT_AWD1)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption Get ADC analog watchdog 2
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_AWD2(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_AWD2) == (DDL_ADC16_IT_AWD2)) ? 1UL : 0UL);
}

/**
  * @brief  Get state of interruption Get ADC analog watchdog 3
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_ADC16_IsEnabledIT_AWD3(ADC16_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, DDL_ADC16_IT_AWD3) == (DDL_ADC16_IT_AWD3)) ? 1UL : 0UL);
}

/**
  * @brief  Set the sampling time for a single-ended ADC channel.
  *         The sampling time is in terms of ADC clock cycles.
  * @param  ADCx ADC instance
  * @param  diffCh This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_SINGLE_INP0
  *         @arg @ref DDL_ADC16_SINGLE_INP1
  *         @arg @ref DDL_ADC16_SINGLE_INP2
  *         @arg @ref DDL_ADC16_SINGLE_INN0
  *         @arg @ref DDL_ADC16_SINGLE_INN1
  *         @arg @ref DDL_ADC16_SINGLE_INN2
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_1CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_2CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_3CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_4CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_5CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_6CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_8CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_9CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_10CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_11CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_12CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_13CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_14CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_15CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_16CYCLES
  *
  * @retval None
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetChannelSamplingTime_Single(ADC16_TypeDef *ADCx, uint32_t SingleCh, uint32_t SamplingTime)
{
    MODIFY_REG(ADCx->SMPR1,
               (0xFU << (4U * SingleCh)),
               ((SamplingTime & 0xFU) << (4U * SingleCh)));
}

/**
  * @brief  Set the sampling time for a differential ADC channel.
  *         The function updates both the positive and negative input channel.
  * @param  ADCx ADC instance
  * @param  diffCh This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL0
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL1
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL2
  * @param  SamplingTime This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_1CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_2CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_3CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_4CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_5CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_6CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_7CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_8CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_9CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_10CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_11CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_12CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_13CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_14CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_15CYCLES
  *         @arg @ref DDL_ADC16_SAMPLINGTIME_16CYCLES
  *
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetChannelSamplingTime_Diff(ADC16_TypeDef *ADCx, uint32_t DiffCh, uint32_t SamplingTime)
{
    MODIFY_REG(ADCx->SMPR1,
        (0xFU << (4U * DiffCh)),
        ((SamplingTime & 0xFU) << (4U * DiffCh)));

    MODIFY_REG(ADCx->SMPR1,
        (0xFU << (4U * (DiffCh + 3U))),
        ((SamplingTime & 0xFU) << (4U * (DiffCh + 3U))));
}

/**
  * @brief  Configure a single-ended channel rank in the regular conversion sequence.
  * @param  ADCx ADC instance
  * @param  rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_RANK_1
  *         @arg @ref DDL_ADC16_REG_RANK_2
  *         @arg @ref DDL_ADC16_REG_RANK_3
  *         @arg @ref DDL_ADC16_REG_RANK_4
  *         @arg @ref DDL_ADC16_REG_RANK_5
  *         @arg @ref DDL_ADC16_REG_RANK_6
  *         @arg @ref DDL_ADC16_REG_RANK_7
  *         @arg @ref DDL_ADC16_REG_RANK_8
  *         @arg @ref DDL_ADC16_REG_RANK_9
  *         @arg @ref DDL_ADC16_REG_RANK_10
  *         @arg @ref DDL_ADC16_REG_RANK_11
  *         @arg @ref DDL_ADC16_REG_RANK_12
  * @param  singleCh This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_SINGLE_INP0
  *         @arg @ref DDL_ADC16_SINGLE_INP1
  *         @arg @ref DDL_ADC16_SINGLE_INP2
  *         @arg @ref DDL_ADC16_SINGLE_INN0
  *         @arg @ref DDL_ADC16_SINGLE_INN1
  *         @arg @ref DDL_ADC16_SINGLE_INN2
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetSequencerRanks_Single(ADC16_TypeDef *ADCx, uint32_t Rank, uint32_t SingleCh)
{
    uint32_t regVal;
    uint32_t channelMask;
    uint32_t regOffset;
    uint32_t bitOffset;

    regOffset = (Rank & 0xFF00U);
    bitOffset = (Rank & 0x00FFU);

    channelMask = (0xFU << bitOffset);

    if (regOffset == ADC_SQR1_REGOFFSET)
    {
        /* SQR1 register */
        regVal = READ_REG(ADCx->SQR1);
        regVal &= ~channelMask;

        if (SingleCh < DDL_ADC16_SINGLE_INN0)
        {
            /* Positive input channel */
            regVal |= ((SingleCh + 1U) << bitOffset);
        }
        else 
        {
            /* Negative input channel */
            /* shifting +2 bits from original position, per original logic. */
            regVal |= ((SingleCh - 2U) << (bitOffset + 2U));
        }
        WRITE_REG(ADCx->SQR1, regVal);
    }
    else if (regOffset == ADC_SQR2_REGOFFSET)
    {
        /* SQR2 register */
        regVal = READ_REG(ADCx->SQR2);
        regVal &= ~channelMask;

        if (SingleCh < DDL_ADC16_SINGLE_INN0)
        {
            /* Positive input channel */
            regVal |= ((SingleCh + 1U) << bitOffset);
        }
        else
        {
            /* Negative input channel */
            regVal |= ((SingleCh - 2U) << (bitOffset + 2U));
        }
        WRITE_REG(ADCx->SQR2, regVal);
    }
}

/**
  * @brief  Configure a differential channel rank in the regular conversion sequence.
  * @param  ADCx ADC instance
  * @param  rank This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_REG_RANK_1
  *         @arg @ref DDL_ADC16_REG_RANK_2
  *         @arg @ref DDL_ADC16_REG_RANK_3
  *         @arg @ref DDL_ADC16_REG_RANK_4
  *         @arg @ref DDL_ADC16_REG_RANK_5
  *         @arg @ref DDL_ADC16_REG_RANK_6
  *         @arg @ref DDL_ADC16_REG_RANK_7
  *         @arg @ref DDL_ADC16_REG_RANK_8
  *         @arg @ref DDL_ADC16_REG_RANK_9
  *         @arg @ref DDL_ADC16_REG_RANK_10
  *         @arg @ref DDL_ADC16_REG_RANK_11
  *         @arg @ref DDL_ADC16_REG_RANK_12
  * @param  diffCh This parameter can be one of the following values:
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL0
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL1
  *         @arg @ref DDL_ADC16_DIFF_CHANNEL2
  * @retval None
  */
__STATIC_INLINE void DDL_ADC16_SetSequencerRanks_Diff(ADC16_TypeDef *ADCx, uint32_t Rank, uint32_t DiffCh)
{
    uint32_t regVal;
    uint32_t channelMask;
    uint32_t posShifted;
    uint32_t negShifted;
    uint32_t regOffset;
    uint32_t bitOffset;

    regOffset = (Rank & 0xFF00U);
    bitOffset = (Rank & 0x00FFU);
    channelMask = (0xFU << bitOffset);

    if (regOffset == ADC_SQR1_REGOFFSET)
    {
        /* SQR1 register */
        regVal = READ_REG(ADCx->SQR1);
        regVal &= ~channelMask;

        posShifted = ((DiffCh + 1U) << bitOffset);
        negShifted = ((DiffCh + 1U) << (bitOffset + 2U));
        regVal |= (posShifted | negShifted);

        WRITE_REG(ADCx->SQR1, regVal);
    }
    else if (regOffset == ADC_SQR2_REGOFFSET)
    {
        /* SQR2 register */
        regVal = READ_REG(ADCx->SQR2);
        regVal &= ~channelMask;

        posShifted = ((DiffCh + 1U) << bitOffset);
        negShifted = ((DiffCh + 1U) << (bitOffset + 2U));
        regVal |= (posShifted | negShifted);

        WRITE_REG(ADCx->SQR2, regVal);
    }
}

/**
* @}
*/

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup ADC_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

/* De-initialization of ADC instance, ADC group regular and ADC group injected */
/* (availability of ADC group injected depends on G32R4 families) */
ErrorStatus DDL_ADC16_DeInit(ADC16_TypeDef *ADCx);

/* Initialization of some features of ADC instance */
ErrorStatus DDL_ADC16_Init(ADC16_TypeDef *ADCx, DDL_ADC16_InitTypeDef *ADC_InitStruct);
void        DDL_ADC16_StructInit(DDL_ADC16_InitTypeDef *ADC_InitStruct);

/* Initialization of some features of ADC instance and ADC group regular */
ErrorStatus DDL_ADC16_REG_Init(ADC16_TypeDef *ADCx, DDL_ADC16_REG_InitTypeDef *ADC_REG_InitStruct);
void        DDL_ADC16_REG_StructInit(DDL_ADC16_REG_InitTypeDef *ADC_REG_InitStruct);

/* Initialization of some features of ADC instance and ADC group injected */
ErrorStatus DDL_ADC16_INJ_Init(ADC16_TypeDef *ADCx, DDL_ADC16_INJ_InitTypeDef *ADC_INJ_InitStruct);
void        DDL_ADC16_INJ_StructInit(DDL_ADC16_INJ_InitTypeDef *ADC_INJ_InitStruct);

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

#endif /* defined (ADC1) || defined (ADC2) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

