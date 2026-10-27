/**
 * @file        system_g32r4xx.h
 *
 * @brief       CMSIS Cortex-M52 Device System Source File for G32R4xx devices.
 *
 * @version     V1.0.1
 *
 * @date        2026-07-31
 *
 * @attention
 *
 *  Copyright (C) 2025 Geehy Semiconductor
 *
 *  You may not use this file except in compliance with the
 *  GEEHY COPYRIGHT NOTICE (GEEHY SOFTWARE PACKAGE LICENSE).
 *
 *  The program is only for reference, which is distributed in the hope
 *  that it will be useful and instructional for customers to develop
 *  their software. Unless required by applicable law or agreed to in
 *  writing, the program is distributed on an "AS IS" BASIS, WITHOUT
 *  ANY WARRANTY OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the GEEHY SOFTWARE PACKAGE LICENSE for the governing permissions
 *  and limitations under the License.
 *
 */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup g32r4xx_system
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_G32R4XX_H
#define __SYSTEM_G32R4XX_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup G32R4xx_System_Includes
  * @{
  */
/**
  * @}
  */

/** @addtogroup G32R4xx_System_Exported_types
  * @{
  */
extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
extern const uint8_t  AHBPrescTable[16];  /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];   /*!< APB prescalers table values */

typedef void(*G32R4XX_VECTOR) (void);
/**
  * @}
  */

/** @addtogroup G32R4xx_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Exported_Functions
  * @{
  */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_G32R4XX_H */

/**
  * @}
  */

/**
  * @}
  */

