/**
  *
  * @file    g32r4xx_ddl_dbgmcu.h
  * @brief   This file contains all the functions prototypes for the DDL
  *          module driver.
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
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4XX_DDL_DBGMCU_H
#define G32R4XX_DDL_DBGMCU_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

/** @defgroup DBGMCU_DDL DBGMCU
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup DBGMCU_Exported_Macros DBGMCU Exported Macros
  * @{
  */

/** @brief  Freeze/Unfreeze Peripherals in Debug mode
  * @{
  */
#define __DDL_DBGMCU_FREEZE_TMR1()     (DBGMCU->APB |= (DBGMCU_APB_DBG_TMR1_STOP))
#define __DDL_DBGMCU_FREEZE_TMR2()     (DBGMCU->APB |= (DBGMCU_APB_DBG_TMR2_STOP))
#define __DDL_DBGMCU_FREEZE_TMR3()     (DBGMCU->APB |= (DBGMCU_APB_DBG_TMR3_STOP))
#define __DDL_DBGMCU_FREEZE_TMR4()     (DBGMCU->APB |= (DBGMCU_APB_DBG_TMR4_STOP))
#define __DDL_DBGMCU_FREEZE_LPTMR()    (DBGMCU->APB |= (DBGMCU_APB_DBG_LPTMR_STOP))
#define __DDL_DBGMCU_FREEZE_RTC()      (DBGMCU->APB |= (DBGMCU_APB_DBG_RTC_STOP))
#define __DDL_DBGMCU_FREEZE_WWDT()     (DBGMCU->APB |= (DBGMCU_APB_DBG_WWDT_STOP))
#define __DDL_DBGMCU_FREEZE_IWDT()     (DBGMCU->APB |= (DBGMCU_APB_DBG_IWDT_STOP))

#define __DDL_DBGMCU_UNFREEZE_TMR1()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_TMR1_STOP))
#define __DDL_DBGMCU_UNFREEZE_TMR2()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_TMR2_STOP))
#define __DDL_DBGMCU_UNFREEZE_TMR3()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_TMR3_STOP))
#define __DDL_DBGMCU_UNFREEZE_TMR4()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_TMR4_STOP))
#define __DDL_DBGMCU_UNFREEZE_LPTMR()  (DBGMCU->APB &= ~(DBGMCU_APB_DBG_LPTMR_STOP))
#define __DDL_DBGMCU_UNFREEZE_RTC()    (DBGMCU->APB &= ~(DBGMCU_APB_DBG_RTC_STOP))
#define __DDL_DBGMCU_UNFREEZE_WWDT()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_WWDT_STOP))
#define __DDL_DBGMCU_UNFREEZE_IWDT()   (DBGMCU->APB &= ~(DBGMCU_APB_DBG_IWDT_STOP))
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup DBGMCU_Exported_Functions
  * @{
  */
/* Peripheral Control functions  ************************************************/
uint32_t DDL_GetHalVersion(void);
uint32_t DDL_GetID(void);
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4XX_DDL_DBGMCU_H */

