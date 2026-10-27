/**
  *
  * @file    g32r4xx_ddl_comp.h
  * @brief   Header file of COMP DDL module.
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
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (C) 2025-2024 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _G32R4XX_DDL_COMP_H__
#define _G32R4XX_DDL_COMP_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (COMP1) || defined (COMP2) || defined (COMP3) || defined (COMP4)

/** @addtogroup COMP_DDL COMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup COMP_DDL_ES_INIT COMP Exported Init Structure
  * @{
  */

/**
 * @brief COMP Init structure definition
 */
typedef struct
{
    uint32_t InputPlus;             /*!< Set comparator input plus.
                                        Note: Input plus is available only for COMP2.
                                        This parameter can be a value of @ref COMP_DDL_EC_INPUT_PLUS

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetInputPlus(). */

    uint32_t InputMinus;            /*!< Set comparator input minus.
                                        This parameter can be a value of @ref COMP_DDL_EC_INPUT_MINUS

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetInputMinus(). */

    uint32_t OutputPol;             /*!< Set comparator output polarity.
                                        This parameter can be a value of @ref COMP_DDL_EC_OUTPUT_POLARITY

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetOutputPolarity(). */

    uint32_t OutputBlank;           /*!< Set comparator output blank.
                                        This parameter can be a value between 0x00 ~ 0x07

                                        This feature can be modified afterwards using unitary function @ref DDL_COMP_SetOutputBlank(). */
} DDL_COMP_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_DDL_EC_INPUT_PLUS COMP input plus
 * @{
 */
#define DDL_COMP_INPUT_PLUS_INP0  (0x00000000UL)        /*!< Input plus: INP0. Scope: COMP1-4. */
#define DDL_COMP_INPUT_PLUS_INP1  (COMP_CSTS_VP_SEL_0)  /*!< Input plus: INP1. Scope: COMP1-4. */
#define DDL_COMP_INPUT_PLUS_DAC2  (COMP_CSTS_VP_SEL_1)  /*!< Input plus: DAC2 output. Scope: COMP1-2. */
#define DDL_COMP_INPUT_PLUS_DAC1  (COMP_CSTS_VP_SEL_1)  /*!< Input plus: DAC1 output. Scope: COMP3-4. */

/**
 * @}
 */

/** @defgroup COMP_DDL_EC_INPUT_MINUS COMP input minus
 * @{
 */
#define DDL_COMP_INPUT_MINUS_INN0  (0x00000000UL)        /*!< Input minus: INN0. Scope: COMP1-4.*/
#define DDL_COMP_INPUT_MINUS_INN1  (COMP_CSTS_VN_SEL_0)  /*!< Input minus: INN1. Scope: COMP1-4. */
#define DDL_COMP_INPUT_MINUS_DAC2  (COMP_CSTS_VN_SEL_1)  /*!< Input minus: DAC2 output. Scope:COMP1-2. */
#define DDL_COMP_INPUT_MINUS_DAC1  (COMP_CSTS_VN_SEL_1)  /*!< Input minus: DAC1 output. Scope:COMP3-4. */

/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_POLARITY COMP output polarity
 * @{
 */
#define DDL_COMP_OUTPUTPOL_NONINVERTED  (0x00000000UL)   /*!< Comparator output is non-inverted. */
#define DDL_COMP_OUTPUTPOL_INVERTED     (COMP_CSTS_POL)  /*!< Comparator output is inverted. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_HYSTERESIS COMP hysteresis
 * @{
 */
#define DDL_COMP_HYS_DISABLE  (0x00000000UL)

#define DDL_COMP_HYS_LEVEL0  (COMP_CSTS_HYS_0)
#define DDL_COMP_HYS_LEVEL1  (COMP_CSTS_HYS_1)
#define DDL_COMP_HYS_LEVEL2  (COMP_CSTS_HYS_1 | COMP_CSTS_HYS_0)
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_BLANK COMP output blank
 * @{
 */
#define DDL_COMP_BLANK_0  (0x00000000UL)                                 /*!< Comparator output blank 0. */
#define DDL_COMP_BLANK_1  (COMP_CSTS_BLANKSEL_0)                         /*!< Comparator output blank 1. */
#define DDL_COMP_BLANK_2  (COMP_CSTS_BLANKSEL_1)                         /*!< Comparator output blank 1. */
#define DDL_COMP_BLANK_3  (COMP_CSTS_BLANKSEL_0 | COMP_CSTS_BLANKSEL_1)  /*!< Comparator output blank 1. */
#define DDL_COMP_BLANK_4  (COMP_CSTS_BLANKSEL_2)                         /*!< Comparator output blank 1. */
#define DDL_COMP_BLANK_6  (COMP_CSTS_BLANKSEL_2 | COMP_CSTS_BLANKSEL_1)  /*!< Comparator output blank 1. */
#define DDL_COMP_BLANK_7  (COMP_CSTS_BLANKSEL)                           /*!< Comparator output blank 1. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_SEL COMP output select
 * @{
 */
#define DDL_COMP_OUTPUT_SEL_NONE       (0x00000000UL)
#define DDL_COMP_OUTPUT_SEL_TMR1_BKIN  (COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR1_IC1   (COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_OUTPUT_SEL_TMR1_IC2   (COMP_CSTS_TMR_SEL_1 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR1_ETR   (COMP_CSTS_TMR_SEL_2)
#define DDL_COMP_OUTPUT_SEL_TMR2_IC1   (COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR2_IC2   (COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_OUTPUT_SEL_TMR2_IC3   (COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_1 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR2_IC4   (COMP_CSTS_TMR_SEL_3)
#define DDL_COMP_OUTPUT_SEL_TMR2_ETR   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR3_IC1   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_OUTPUT_SEL_TMR3_IC2   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_1 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR3_ETR   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_2)
#define DDL_COMP_OUTPUT_SEL_TMR4_IC1   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_0)
#define DDL_COMP_OUTPUT_SEL_TMR4_IC2   (COMP_CSTS_TMR_SEL_3 | COMP_CSTS_TMR_SEL_2 | COMP_CSTS_TMR_SEL_1)
#define DDL_COMP_OUTPUT_SEL_TMR4_ETR   (COMP_CSTS_TMR_SEL)
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_OUTPUT_LEVEL COMP output level
 * @{
 */
#define DDL_COMP_OUTPUT_LEVEL_LOW   (0x00000000UL)      /*!< Comparator output level is low. */
#define DDL_COMP_OUTPUT_LEVEL_HIGH  (COMP_CSTS_OUTVAL)  /*!< Comparator output level is high. */
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_FILTER_TIME COMP filter time
 * @{
 */
#define DDL_COMP_FILTER_NONE      (0x00000000UL)
#define DDL_COMP_FILTER_2HSICLK   (COMP_CSTS_FILTER_0)
#define DDL_COMP_FILTER_4HSICLK   (COMP_CSTS_FILTER_1)
#define DDL_COMP_FILTER_6HSICLK   (COMP_CSTS_FILTER_1 | COMP_CSTS_FILTER_0)
#define DDL_COMP_FILTER_12HSICLK  (COMP_CSTS_FILTER_2)
#define DDL_COMP_FILTER_18HSICLK  (COMP_CSTS_FILTER_2 | COMP_CSTS_FILTER_0)
#define DDL_COMP_FILTER_24HSICLK  (COMP_CSTS_FILTER_2 | COMP_CSTS_FILTER_1)
#define DDL_COMP_FILTER_30HSICLK  (COMP_CSTS_FILTER)
/**
 * @}
 */

/** @defgroup COMP_DDL_EC_HW_DELAYS COMP hardware delay
 * @{
 */

/* Delay for comparator startup time */
#define DDL_COMP_DELAY_STARTUP_US  (80UL)  /*!< Comparator startup time. */
/**
 * @}
 */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Macros COMP Exported Macros
  * @{
  */
/** @defgroup COMP_DDL_EM_WRITE_READ Common write and read registers macro
  * @{
  */

/**
 * @brief  Write a value in COMP register.
 * @param  __INSTANCE__ COMP instance.
 * @param  __REG__ COMP register.
 * @param  __VALUE__ Value to be written.
 * @retval None
 */
#define DDL_COMP_WriteReg(__INSTANCE__,  __REG__, __VALUE__)     WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
 * @brief  Read a value in COMP register.
 * @param  __INSTANCE__ COMP instance.
 * @param  __REG__ COMP register.
 * @retval Register value
 */
#define DDL_COMP_ReadReg(__INSTANCE__,  __REG__)                 READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
 * @}
 */

/* Exported functions --------------------------------------------------------*/
/** @defgroup COMP_DDL_Exported_Functions COMP Exported Functions
  * @{
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_modes Configuration of comparator instance mode
 * @{
 */

/**
 * @brief  Select comparator hysteresis.
 * @param  COMPx COMP instance.
 * @param  Hysteresis This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_HYS_DISABLE
 *         @arg @ref DDL_COMP_HYS_LEVEL0
 *         @arg @ref DDL_COMP_HYS_LEVEL1
 *         @arg @ref DDL_COMP_HYS_LEVEL2
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetHysteresis(COMP_TypeDef *COMPx, uint32_t Hysteresis)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_HYS, Hysteresis);
}

/**
 * @brief Get comparator hysteresis.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_HYS_DISABLE
 *         @arg @ref DDL_COMP_HYS_LEVEL0
 *         @arg @ref DDL_COMP_HYS_LEVEL1
 *         @arg @ref DDL_COMP_HYS_LEVEL2
 */
__STATIC_INLINE uint32_t DDL_COMP_GetHysteresis(COMP_TypeDef *COMPx)
{
    return (uint32_t)READ_BIT(COMPx->CxCSR, COMP_CSTS_HYS);
}

/**
 * @brief  Set comparator output blank.
 * @param  COMPx COMP instance.
 * @param  Blank This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_BLANK_0
 *         @arg @ref DDL_COMP_BLANK_1
 *         @arg @ref DDL_COMP_BLANK_2
 *         @arg @ref DDL_COMP_BLANK_3
 *         @arg @ref DDL_COMP_BLANK_4
 *         @arg @ref DDL_COMP_BLANK_6
 *         @arg @ref DDL_COMP_BLANK_7
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetOutputBlank(COMP_TypeDef *COMPx,
                                            uint32_t Blank)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_BLANKSEL, Blank);
}

/**
 * @brief Get comparator output blank.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_BLANK_0
 *         @arg @ref DDL_COMP_BLANK_1
 *         @arg @ref DDL_COMP_BLANK_2
 *         @arg @ref DDL_COMP_BLANK_3
 *         @arg @ref DDL_COMP_BLANK_4
 *         @arg @ref DDL_COMP_BLANK_6
 *         @arg @ref DDL_COMP_BLANK_7
 */
__STATIC_INLINE uint32_t DDL_COMP_GetOutputBlank(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_BLANKSEL));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_inputs Configuration of comparator inputs
 * @{
 */

/**
 * @brief  Set comparator input plus.
 * @param  COMPx COMP instance.
 * @param  InputPlus COMP1-3: This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_PLUS_INP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_DAC1
 *
 * @param  InputPlus COMP4: This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_PLUS_INP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_INP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_DAC1
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetInputPlus(COMP_TypeDef *COMPx,
                                            uint32_t InputPlus)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_VP_SEL, InputPlus);
}

/**
 * @brief Get comparator input plus.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_PLUS_INP0
 *         @arg @ref DDL_COMP_INPUT_PLUS_INP1
 *         @arg @ref DDL_COMP_INPUT_PLUS_DAC1
 */
__STATIC_INLINE uint32_t DDL_COMP_GetInputPlus(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_VP_SEL));
}

/**
 * @brief  Set comparator input minus.
 * @param  COMPx COMP instance.
 * @param  InputMinus COMP1-3: This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_MINUS_INN0
 *         @arg @ref DDL_COMP_INPUT_MINUS_DAC1
 *
 * @param  InputMinus COMP4: This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_MINUS_INN0
 *         @arg @ref DDL_COMP_INPUT_MINUS_INN1
 *         @arg @ref DDL_COMP_INPUT_MINUS_DAC1
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetInputMinus(COMP_TypeDef *COMPx,
                                            uint32_t InputMinus)
{
    /* Note: Input minus is available only for COMP1 and COMP2. */
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_VN_SEL, InputMinus);
}

/**
 * @brief Get comparator input minus.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *         @arg @ref DDL_COMP_INPUT_MINUS_INN0
 *         @arg @ref DDL_COMP_INPUT_MINUS_INN1
 *         @arg @ref DDL_COMP_INPUT_MINUS_DAC1
 */
__STATIC_INLINE uint32_t DDL_COMP_GetInputMinus(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_VN_SEL));
}

/**
  * @}
  */

/** @defgroup COMP_DDL_EF_Configuration_comparator_output Configuration of comparator output
 * @{
 */

/**
 * @brief  Set comparator output select.
 * @param  COMPx COMP instance.
 * @param  OutputSel This parameter can be one of the following values:
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_BKIN
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC3
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC4
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_ETR
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetOutputSelect(COMP_TypeDef *COMPx,
                                                uint32_t OutputSel)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_TMR_SEL, OutputSel);
}

/**
 * @brief  Set comparator output select.
 * @param  COMPx COMP instance.
 * @retval  Return value can be one of the following values:
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_BKIN
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR1_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC3
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_IC4
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR2_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR3_ETR
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_IC1
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_IC2
 *         @arg @ref DDL_COMP_OUTPUT_SEL_TMR4_ETR
 */
__STATIC_INLINE uint32_t DDL_COMP_GetOutputSelect(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_TMR_SEL));
}

/**
 * @brief  Set comparator output polarity.
 * @param  COMPx COMP instance.
 * @param  OutputPol This parameter can be one of the following values:
 *        @arg @ref DDL_COMP_OUTPUTPOL_NONINVERTED
 *        @arg @ref DDL_COMP_OUTPUTPOL_INVERTED
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetOutputPolarity(COMP_TypeDef *COMPx,
                                                uint32_t OutputPol)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_POL, OutputPol);
}

/**
 * @brief Get comparator output polarity.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *       @arg @ref DDL_COMP_OUTPUTPOL_NONINVERTED
 *       @arg @ref DDL_COMP_OUTPUTPOL_INVERTED
 */
__STATIC_INLINE uint32_t DDL_COMP_GetOutputPolarity(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_POL));
}

/**
  * @}
  */

 /** @defgroup COMP_DDL_EF_Operation Operation on comparator instance
  * @{
  */

/**
 * @brief  Enable comparator instance.
 * @param  COMPx COMP instance.
 * @retval None
 * @note   After enable from off state, comparator startup time is needed.
 */
__STATIC_INLINE void DDL_COMP_Enable(COMP_TypeDef *COMPx)
{
    SET_BIT(COMPx->CxCSR, COMP_CSTS_EN);
}

/**
 * @brief  Disable comparator instance.
 * @param  COMPx COMP instance.
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_Disable(COMP_TypeDef *COMPx)
{
    CLEAR_BIT(COMPx->CxCSR, COMP_CSTS_EN);
}

/**
 * @brief  Get comparator enable state.
 * @param  COMPx COMP instance.
 * @retval State of bit (1 or 0).
 *        - 0: comparator instance is disabled.
 *        - 1: comparator instance is enabled.
 */
__STATIC_INLINE uint32_t DDL_COMP_IsEnabled(COMP_TypeDef *COMPx)
{
    return ((READ_BIT(COMPx->CxCSR, COMP_CSTS_EN) == (COMP_CSTS_EN)) ? 1UL : 0UL);
}

/**
 * @brief  Lock comparator instance.
 * @param  COMPx COMP instance.
 * @retval None
 * @note   Once locked, comparator configuration can no longer be modified until next reset.
 * @note   The only way to unlock the comparator is a device hardware reset.
 */
__STATIC_INLINE void DDL_COMP_Lock(COMP_TypeDef *COMPx)
{
    SET_BIT(COMPx->CxCSR, COMP_CSTS_LOCK);
}

/**
 * @brief  Get comparator lock state.
 * @param  COMPx COMP instance.
 * @retval State of bit (1 or 0).
 *       - 0: comparator instance is unlocked.
 *      - 1: comparator instance is locked.
 */
__STATIC_INLINE uint32_t DDL_COMP_IsLocked(COMP_TypeDef *COMPx)
{
    return ((READ_BIT(COMPx->CxCSR, COMP_CSTS_LOCK) == (COMP_CSTS_LOCK)) ? 1UL : 0UL);
}

/**
 * @brief  Read comparator output level.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *       @arg @ref DDL_COMP_OUTPUT_LEVEL_LOW
 *       @arg @ref DDL_COMP_OUTPUT_LEVEL_HIGH
 * @note   The comparator output level depends on the selected polarity.
 *         If the polarity is not inverted:
 *         - Comparator output is low level when the input plus is lower than the input minus.
 *         - Comparator output is high level when the input plus is higher than the input minus.
 *         If the polarity is inverted:
 *         - Comparator output is high level when the input plus is lower than the input minus.
 *         - Comparator output is low level when the input plus is higher than the input minus.
 */
__STATIC_INLINE uint32_t DDL_COMP_ReadOutputLevel(COMP_TypeDef *COMPx)
{
    return((READ_BIT(COMPx->CxCSR, COMP_CSTS_OUTVAL) == (COMP_CSTS_OUTVAL)) ? 1UL : 0UL);
}

/**
  * @}
  */

 /** @defgroup COMP_DDL_EF_FILTER Filter
  * @{
  */

/**
 * @brief  Set comparator filter.
 * @param  COMPx COMP instance.
 * @param  Filter This parameter can be one of the following values:
 *       @arg @ref DDL_COMP_FILTER_NONE
 *       @arg @ref DDL_COMP_FILTER_2HSICLK
 *       @arg @ref DDL_COMP_FILTER_4HSICLK
 *       @arg @ref DDL_COMP_FILTER_6HSICLK
 *       @arg @ref DDL_COMP_FILTER_12HSICLK
 *       @arg @ref DDL_COMP_FILTER_18HSICLK
 *       @arg @ref DDL_COMP_FILTER_24HSICLK
 *       @arg @ref DDL_COMP_FILTER_30HSICLK
 * @retval None
 */
__STATIC_INLINE void DDL_COMP_SetFilter(COMP_TypeDef *COMPx, uint32_t Filter)
{
    MODIFY_REG(COMPx->CxCSR, COMP_CSTS_FILTER, Filter);
}

/**
 * @brief Get comparator filter.
 * @param  COMPx COMP instance.
 * @retval Returned value can be one of the following values:
 *       @arg @ref DDL_COMP_FILTER_NONE
 *       @arg @ref DDL_COMP_FILTER_2HSICLK
 *       @arg @ref DDL_COMP_FILTER_4HSICLK
 *       @arg @ref DDL_COMP_FILTER_6HSICLK
 *       @arg @ref DDL_COMP_FILTER_12HSICLK
 *       @arg @ref DDL_COMP_FILTER_18HSICLK
 *       @arg @ref DDL_COMP_FILTER_24HSICLK
 *       @arg @ref DDL_COMP_FILTER_30HSICLK
 */
__STATIC_INLINE uint32_t DDL_COMP_GetFilter(COMP_TypeDef *COMPx)
{
    return (uint32_t)(READ_BIT(COMPx->CxCSR, COMP_CSTS_FILTER));
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup COMP_DDL_EF_Init Initialization and de-initialization functions
 * @{
 */

ErrorStatus DDL_COMP_Init(COMP_TypeDef *COMPx, DDL_COMP_InitTypeDef *COMP_InitStruct);
ErrorStatus DDL_COMP_DeInit(COMP_TypeDef *COMPx);
void        DDL_COMP_StructInit(DDL_COMP_InitTypeDef *COMP_InitStruct);

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

#endif /* COMP1 || COMP2 || COMP3 || COMP4 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _G32R4XX_DDL_COMP_H__ */

