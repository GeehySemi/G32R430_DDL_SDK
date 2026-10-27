/**
  *
  * @file    g32r4xx_ddl_comp.c
  * @brief   COMP DDL module driver.
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
  * Copyright (C) 2025-2024 Geehy Semiconductor.
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
#include "g32r4xx_ddl_comp.h"
#include "g32r4xx_ddl_rcm.h"

#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif /* USE_FULL_ASSERT */

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

/** @defgroup COMP_DDL_Private_Macros COMP Private Macros
  * @{
  */

 /* Check of parameters for configuration of COMP hierarchical scope:          */
    /* COMP instance.                                                             */
#define IS_DDL_COMP_INPUT_PLUS(__COMP_INSTANCE__, __INPUT_PLUS__)     \
    (   ((__COMP_INSTANCE__) < COMP4) ?                                   \
    (   ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_INP0) ||                               \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_DAC1))                                   \
    :                                                                                   \
    (   ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_INP0) ||                               \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_INP1) ||                               \
        ((__INPUT_PLUS__) == DDL_COMP_INPUT_PLUS_DAC1))                                   \
)

#define IS_DDL_COMP_INPUT_MINUS(__COMP_INSTANCE__, __INPUT_MINUS__)   \
(   ((__COMP_INSTANCE__) < COMP4) ?                                   \
    (   ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_INN0) ||                              \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_DAC1) )                                \
    :                                                                               \
    (   ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_INN0) ||                              \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_INN1) ||                              \
        ((__INPUT_MINUS__) == DDL_COMP_INPUT_MINUS_DAC1) )                                \
)

#define IS_DDL_COMP_OUTPUT_POLARITY(__POLARITY__)               \
    (   ((__POLARITY__) == DDL_COMP_OUTPUTPOL_NONINVERTED) ||   \
        ((__POLARITY__) == DDL_COMP_OUTPUTPOL_INVERTED)         \
    )

#define IS_DDL_COMP_OUTPUT_BLANK(__BLANK__)     \
    (   ((__BLANK__) == DDL_COMP_BLANK_0) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_1) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_2) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_3) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_4) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_6) ||    \
        ((__BLANK__) == DDL_COMP_BLANK_7)       \
    )

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_DDL_Exported_Functions
  * @{
  */

/** @addtogroup COMP_DDL_EF_Init
  * @{
  */

/**
 * @brief  Initialize COMP function.
 * @param  COMPx COMP instance
 * @param  COMP_InitStruct Pointer to a @ref DDL_COMP_InitTypeDef structure
 * @retval An ErrorStatus enumeration value:
 *          - SUCCESS: COMP registers are initialized
 *          - ERROR: COMP registers are not initialized
 */
ErrorStatus DDL_COMP_Init(COMP_TypeDef *COMPx, DDL_COMP_InitTypeDef *COMP_InitStruct)
{
    ErrorStatus status = SUCCESS;

    /* Check parameters */
    ASSERT_PARAM(IS_COMP_ALL_INSTANCE(COMPx));
    ASSERT_PARAM(IS_DDL_COMP_INPUT_PLUS(COMPx, COMP_InitStruct->InputPlus));
    ASSERT_PARAM(IS_DDL_COMP_INPUT_MINUS(COMPx, COMP_InitStruct->InputMinus));
    ASSERT_PARAM(IS_DDL_COMP_OUTPUT_POLARITY(COMP_InitStruct->OutputPol));
    ASSERT_PARAM(IS_DDL_COMP_OUTPUT_BLANK(COMP_InitStruct->OutputBlank));

    /* COMP instance must not be locked */
    if (DDL_COMP_IsLocked(COMPx) == 0UL)
    {
        /* Configuration of comparator instance */
        MODIFY_REG(COMPx->CxCSR,
                    COMP_CSTS_VP_SEL |
                    COMP_CSTS_VN_SEL |
                    COMP_CSTS_BLANKSEL |
                    COMP_CSTS_POL,
                    COMP_InitStruct->InputPlus |
                    COMP_InitStruct->InputMinus |
                    COMP_InitStruct->OutputBlank |
                    COMP_InitStruct->OutputPol
        );
    }
    else
    {
        status = ERROR;
    }

    return status;
}

/**
 * @brief  De-Initialize COMP function.
 * @param  COMPx COMP instance
 * @retval An ErrorStatus enumeration value:
 *         - SUCCESS: COMP registers are de-initialized
 *         - ERROR: COMP registers are not de-initialized
 * @note   If COMP instance is locked, de-initialization can't be performed.
 *         The only way to unlock the COMP instance is to perform a system reset.
 */
ErrorStatus DDL_COMP_DeInit(COMP_TypeDef *COMPx)
{
    ErrorStatus status = SUCCESS;

    /* Check parameters */
    ASSERT_PARAM(IS_COMP_ALL_INSTANCE(COMPx));

    /* COMP instance must not be locked */
    if (DDL_COMP_IsLocked(COMPx) == 0UL)
    {
        /* De-initialize the COMP registers to the reset values */
        DDL_COMP_WriteReg((COMPx), CxCSR, 0x00000000UL);
    }
    else
    {
        /* COMP instance is locked */
        /* The only way to unlock the COMP instance is to perform a system reset */
        status = ERROR;
    }

    return status;
}

/**
 * @brief  Set the fields of structure COMP_InitStruct to default values.
 * @param  COMP_InitStruct Pointer to a @ref DDL_COMP_InitTypeDef structure
 *                          whose fields will be set to default values.
 * @retval None
 */
void DDL_COMP_StructInit(DDL_COMP_InitTypeDef *COMP_InitStruct)
{
    /* Set COMP_InitStruct fields to default values */
    COMP_InitStruct->InputPlus      = DDL_COMP_INPUT_PLUS_INP0;
    COMP_InitStruct->InputMinus     = DDL_COMP_INPUT_MINUS_INN0;
    COMP_InitStruct->OutputPol      = DDL_COMP_OUTPUTPOL_NONINVERTED;
    COMP_InitStruct->OutputBlank    = DDL_COMP_BLANK_0;
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

#endif /* COMP1 || COMP2 */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
