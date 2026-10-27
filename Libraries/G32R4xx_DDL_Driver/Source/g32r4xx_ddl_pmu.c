/**
  *
  * @file    g32r4xx_ddl_pmu.c
  * @brief   PMU DDL module driver.
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
  * Copyright (C) 2024-2025 Geehy Semiconductor.
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
#include "g32r4xx_ddl_pmu.h"
#include "g32r4xx_ddl_rcm.h"
#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @addtogroup PMU_DDL_Exported_Functions
  * @{
  */

/** @addtogroup PMU_DDL_EF_Config
  * @{
  */

/**
  * @brief  Enter Standby Mode by WFI.
  * @param  None
  * @retval None
  */
void DDL_PMU_EnterStandbyModeWFI(void)
{
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= (uint32_t)0x04;

    DDL_RCM_Unlock();
    DDL_RCM_SetLowPowerMode(DDL_RCM_LOWPOWER_STANDBY);
    DDL_RCM_Lock();

    __WFI();
}

/**
  * @brief  Enter Stop Mode by WFI.
  * @param  None
  * @retval None
  */
void DDL_PMU_EnterStopModeWFI(void)
{
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= (uint32_t)0x04;

    DDL_RCM_Unlock();
    DDL_RCM_SetLowPowerMode(DDL_RCM_LOWPOWER_STOP);
    DDL_RCM_Lock();

    __WFI();
}

/**
  * @brief  Enter Standby Mode by WFE.
  * @param  None
  * @retval None
  */
void DDL_PMU_EnterStandbyModeWFE(void)
{
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= (uint32_t)0x04;

    DDL_RCM_Unlock();
    DDL_RCM_SetLowPowerMode(DDL_RCM_LOWPOWER_STANDBY);
    DDL_RCM_Lock();

    __WFE();
}

/**
  * @brief  Enter Stop Mode by WFE.
  * @param  None
  * @retval None
  */
void DDL_PMU_EnterStopModeWFE(void)
{
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= (uint32_t)0x04;

    DDL_RCM_Unlock();
    DDL_RCM_SetLowPowerMode(DDL_RCM_LOWPOWER_STOP);
    DDL_RCM_Lock();

    __WFE();
}

/**
 * @}
 */

/**
 * @}
 */

#endif
