/**
  *
  * @file    g32r4xx_ddl_dbgmcu.c
  * @brief   DDL module driver.
  *          This is the common part of the DDL initialization
  *
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
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The common DDL driver contains a set of generic and common APIs that can be
    used by the PPP peripheral drivers and the user to start using the DDL.
    [..]
    The DDL contains two APIs' categories:
         (+) Common DDL APIs
         (+) Services DDL APIs

  @endverbatim
  *
  */

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_dbgmcu.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

/** @defgroup DBGMCU_DDL DBGMCU
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup DBGMCU_Private_Constants
  * @{
  */
/**
  * @brief G32R4XX DDL Driver version number V1.0.0
  */
#define __G32R4XX_DDL_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __G32R4XX_DDL_VERSION_SUB1   (0x00U) /*!< [23:16] sub1 version */
#define __G32R4XX_DDL_VERSION_SUB2   (0x00U) /*!< [15:8]  sub2 version */
#define __G32R4XX_DDL_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __G32R4XX_DDL_VERSION         ((__G32R4XX_DDL_VERSION_MAIN << 24U)\
                                        |(__G32R4XX_DDL_VERSION_SUB1 << 16U)\
                                        |(__G32R4XX_DDL_VERSION_SUB2 << 8U )\
                                        |(__G32R4XX_DDL_VERSION_RC))
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup DBGMCU_Exported_Functions DBGMCU Exported Functions
  * @{
  */

/** @defgroup DBGMCU_Exported_Functions_Group2 DBGMCU Control functions
 *  @brief    DBGMCU Control functions
 *
@verbatim
 ===============================================================================
                      ##### DDL Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Get the DDL API driver version
      (+) Get the device identifier

@endverbatim
  * @{
  */

/**
  * @brief  Returns the DDL revision
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t DDL_GetHalVersion(void)
{
  return __G32R4XX_DDL_VERSION;
}

/**
  * @brief  Returns the device revision identifier.
  * @retval Device revision identifier
  */
uint32_t DDL_GetID(void)
{
  return(DBGMCU->ID);
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

/**
  * @}
  */
