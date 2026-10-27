/*!
 * @file        board_g32r430_tiny.h
 *
 * @brief       This file contains definitions for G32R430 TINY's Leds, push-buttons hardware resources
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
 */

/* Define to prevent recursive inclusion */
#ifndef __BOARD_G32R430_TINY_H
#define __BOARD_G32R430_TINY_H

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ***************************************************************/
#include "g32r430.h"  
#include "g32r4xx_ddl_rcm.h"
#include "g32r4xx_ddl_gpio.h"
#include "g32r4xx_ddl_rcm.h"
#include "g32r4xx_ddl_eint.h"
#include "g32r4xx_ddl_usart.h"
#include "g32r4xx_ddl_nvic.h"

/* Exported typedef *******************************************************/

typedef enum
{
    LED1 = 0,
    LED2 = 1
} BOARD_LED_T;

typedef enum
{
    BUTTON_KEY1 = 0,
} BOARD_BUTTON_T;

typedef enum
{
    BUTTON_MODE_GPIO = 0,
    BUTTON_MODE_EINT = 1
} BOARD_BUTTON_MODE_T;

typedef enum
{
    COM1 = 0,
    COM2 = 1
} COM_TypeDef;

/* Exported macro *********************************************************/

/** @addtogroup G32R430_TINY_LED
  @{
  */
#define LEDn                             2

/* Note: J10 selects whether PA1 connects to LED1 or the external header. */
#define LED1_PIN                         DDL_GPIO_PIN_1
#define LED1_GPIO_PORT                   GPIOA
#define LED1_GPIO_CLK                    DDL_RCM_AHB_PERIPHERAL_GPIO

/* Note: J10 selects whether PA2 connects to LED2 or the external header. */
#define LED2_PIN                         DDL_GPIO_PIN_2
#define LED2_GPIO_PORT                   GPIOA
#define LED2_GPIO_CLK                    DDL_RCM_AHB_PERIPHERAL_GPIO

/**
  * @}
  */

/** @addtogroup G32R430_TINY_BUTTON
  @{
  */
#define BUTTONn                          1

/**
 * @brief Key1 push-button
 */
/* Note: J10 selects whether PA5 connects to KEY1 or the external header. */
#define KEY1_BUTTON_PIN                   DDL_GPIO_PIN_5
#define KEY1_BUTTON_GPIO_PORT             GPIOA
#define KEY1_BUTTON_GPIO_CLK              DDL_RCM_AHB_PERIPHERAL_GPIO
#define KEY1_BUTTON_EINT_LINE             DDL_EINT_LINE_5
#define KEY1_BUTTON_EINT_IRQn             EINT5_9_IRQn


/**
  * @}
  */

/** @addtogroup G32R430_TINY_COM
  @{
  */
#define COMn                            2

/**
 * @brief Definition for COM port1, connected to USART1
 */
#define COM1_PORT                        USART1
#define COM1_CLK                         DDL_RCM_APB_PERIPHERAL_USART1
#define COM1_TX_PIN                      DDL_GPIO_PIN_9
#define COM1_TX_GPIO_PORT                GPIOB
#define COM1_TX_GPIO_CLK                 DDL_RCM_AHB_PERIPHERAL_GPIO
#define COM1_RX_PIN                      DDL_GPIO_PIN_6
#define COM1_RX_GPIO_PORT                GPIOB
#define COM1_RX_GPIO_CLK                 DDL_RCM_AHB_PERIPHERAL_GPIO
#define COM1_IRQn                        USART1_IRQn
#define COM1_GPIO_AF                     DDL_GPIO_AF_0  

/**
 * @brief Definition for COM port2, connected to USART2
 */
#define COM2_PORT                        USART2
#define COM2_CLK                    DDL_RCM_APB_PERIPHERAL_USART2
#define COM2_TX_PIN                 DDL_GPIO_PIN_0
#define COM2_TX_GPIO_PORT           GPIOD
#define COM2_TX_GPIO_CLK            DDL_RCM_AHB_PERIPHERAL_GPIO
#define COM2_RX_PIN                 DDL_GPIO_PIN_12
#define COM2_RX_GPIO_PORT           GPIOC
#define COM2_RX_GPIO_CLK            DDL_RCM_AHB_PERIPHERAL_GPIO
#define COM2_IRQn                   USART2_IRQn
#define COM2_GPIO_AF                DDL_GPIO_AF_0

/**
  * @}
  */

/* Exported function prototypes *******************************************/

void BOARD_LEDInit(BOARD_LED_T Led);
void BOARD_LEDOn(BOARD_LED_T Led);
void BOARD_LEDOff(BOARD_LED_T Led);
void BOARD_LEDToggle(BOARD_LED_T Led);

void BOARD_PBInit(BOARD_BUTTON_T Button, BOARD_BUTTON_MODE_T Button_Mode);
uint32_t BOARD_PBGetState(BOARD_BUTTON_T Button);

void BOARD_COMInit(COM_TypeDef COM, DDL_USART_InitTypeDef* configStruct);

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_G32R430_TINY_H */
