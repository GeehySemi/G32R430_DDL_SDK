/*!
 * @file        board_g32r430_tiny.c
 *
 * @brief       This file provides firmware functions to manage Leds and key buttons
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

/* Includes ***************************************************************/
#include "Board_G32R430_TINY/inc/board_g32r430_tiny.h"

/* Private variables ******************************************************/
GPIO_Type GPIO_PORT[LEDn] = {LED1_GPIO_PORT, LED2_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED1_PIN, LED2_PIN};
const uint32_t GPIO_CLK[LEDn] = {LED1_GPIO_CLK, LED2_GPIO_CLK};

GPIO_Type BUTTON_PORT[BUTTONn] = {KEY1_BUTTON_GPIO_PORT};

const uint16_t BUTTON_PIN[BUTTONn] = {KEY1_BUTTON_PIN};

const uint32_t BUTTON_CLK[BUTTONn] = {KEY1_BUTTON_GPIO_CLK};

const uint32_t BUTTON_EINT_LINE[BUTTONn] = {KEY1_BUTTON_EINT_LINE};

const IRQn_Type BUTTON_IRQn[BUTTONn] = {KEY1_BUTTON_EINT_IRQn};

USART_TypeDef* COM_USART[COMn] = {COM1_PORT, COM2_PORT};

GPIO_Type COM_TX_PORT[COMn] = {COM1_TX_GPIO_PORT, COM2_TX_GPIO_PORT};

GPIO_Type COM_RX_PORT[COMn] = {COM1_RX_GPIO_PORT, COM2_RX_GPIO_PORT};

const uint32_t COM_GPIO_AF[COMn] = {COM1_GPIO_AF, COM2_GPIO_AF};

const uint32_t COM_USART_CLK[COMn] = {COM1_CLK, COM2_CLK};

const uint32_t COM_TX_PORT_CLK[COMn] = {COM1_TX_GPIO_CLK, COM2_TX_GPIO_CLK};

const uint32_t COM_RX_PORT_CLK[COMn] = {COM1_RX_GPIO_CLK, COM2_RX_GPIO_CLK};

const uint16_t COM_TX_PIN[COMn] = {COM1_TX_PIN, COM2_TX_PIN};

const uint16_t COM_RX_PIN[COMn] = {COM1_RX_PIN, COM2_RX_PIN};

/* External functions *****************************************************/

/*!
 * @brief       Configures LED GPIO.
 *
 * @param       Led: Specifies the Led to be configured.
 *              This parameter can be one of following parameters:
 *              @arg LED1
 *              @arg LED2
 *
 * @retval      None
 */
void BOARD_LEDInit(BOARD_LED_T Led)
{
    DDL_GPIO_InitTypeDef  configStruct;

    /* Unlock RCM */
    DDL_RCM_Unlock();

    /* Enable the GPIO_LED Clock */
    DDL_RCM_EnableAHBPeripheral(GPIO_CLK[Led]);

    /* Lock RCM */
    DDL_RCM_Lock();

    /* Configure the GPIO_LED pin */
    /* Note: J10 selects whether PA1/PA2 connect to LED1/LED2 or the external header. */
    DDL_GPIO_StructInit(&configStruct);
    configStruct.Pin = GPIO_PIN[Led];
    configStruct.Mode = DDL_GPIO_MODE_OUTPUT;
    configStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    configStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    configStruct.Pull = DDL_GPIO_PULL_NO;

    DDL_GPIO_Init(GPIO_PORT[Led], &configStruct);
    DDL_GPIO_SetOutputPin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*!
 * @brief       Turns selected LED On.
 *
 * @param       Led: Specifies the Led to be configured.
 *              This parameter can be one of following parameters:
 *              @arg LED1
 *              @arg LED2
 *
 * @retval      None
 */
void BOARD_LEDOn(BOARD_LED_T Led)
{
    DDL_GPIO_ResetOutputPin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*!
 * @brief       Turns selected LED Off.
 *
 * @param       Led: Specifies the Led to be configured.
 *              This parameter can be one of following parameters:
 *              @arg LED1
 *              @arg LED2
 *
 * @retval      None
 */
void BOARD_LEDOff(BOARD_LED_T Led)
{
    DDL_GPIO_SetOutputPin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*!
 * @brief       Toggles the selected LED.
 *
 * @param       Led: Specifies the Led to be configured.
 *              This parameter can be one of following parameters:
 *              @arg LED1
 *              @arg LED2
 *
 * @retval      None
 */
void BOARD_LEDToggle(BOARD_LED_T Led)
{
    DDL_GPIO_TogglePin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*!
 * @brief       Configures Button GPIO and EINT Line.
 *
 * @param       Button: Specifies the Button to be configured.
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_KEY1: Key1 Push Button
 *              @arg BUTTON_KEY2: Key2 Push Button
 * @param       Button_Mode: Specifies Button mode.
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_MODE_GPIO: Button will be used as simple IO
 *              @arg BUTTON_MODE_EINT: Button will be connected to EINT line
 *                   with interrupt generation capability
 *
 * @retval      None
 */
void BOARD_PBInit(BOARD_BUTTON_T Button, BOARD_BUTTON_MODE_T Button_Mode)
{
    DDL_GPIO_InitTypeDef     GPIO_configStruct;
    DDL_EINT_InitTypeDef     EINT_configStruct;

    /* Unlock RCM */
    DDL_RCM_Unlock();

    /* Enable the BUTTON Clock */
    DDL_RCM_EnableAHBPeripheral(BUTTON_CLK[Button]);

    /* Lock RCM */
    DDL_RCM_Lock();

    /* Configure Button pin as input floating */
    /* Note: J10 selects whether PA5 connects to KEY1 or the external header. */
    DDL_GPIO_StructInit(&GPIO_configStruct);
    GPIO_configStruct.Pin = BUTTON_PIN[Button];
    GPIO_configStruct.Mode = DDL_GPIO_MODE_INPUT;
    GPIO_configStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_configStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_configStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    DDL_GPIO_Init(BUTTON_PORT[Button], &GPIO_configStruct);

    if (Button_Mode == BUTTON_MODE_EINT)
    {
        /* Configure Button EINT line */
        EINT_configStruct.Line = BUTTON_EINT_LINE[Button];
        EINT_configStruct.Mode = DDL_EINT_MODE_IT;
        EINT_configStruct.Trigger = DDL_EINT_TRIGGER_FALLING;
        EINT_configStruct.LineCommand = ENABLE;
        DDL_EINT_Init(&EINT_configStruct);

        /* Enable and set Button EINT Interrupt to the lowest priority */
        DDL_NVIC_EnableIRQRequest(BUTTON_IRQn[Button], 0x0f, 0x0f);
    }
}

/*!
 * @brief       Returns the selected Button state.
 *
 * @param       Button: Specifies the Button to be configured.
 *              This parameter can be one of following parameters:
 *              @arg BUTTON_KEY1: Key1 Push Button
 *              @arg BUTTON_KEY2: Key2 Push Button
 *
 * @retval      The Button GPIO pin value.
 */
uint32_t BOARD_PBGetState(BOARD_BUTTON_T Button)
{
    return DDL_GPIO_IsInputPinSet(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

/*!
 * @brief       Configures COM port.
 *
 * @param       COM: Specifies the COM port to be configured.
 *              This parameter can be one of following parameters:
 *              @arg COM1
 *              @arg COM2
 *
 * @retval      None
 */
void BOARD_COMInit(COM_TypeDef COM, DDL_USART_InitTypeDef* configStruct)
{
    DDL_GPIO_InitTypeDef GPIO_configStruct;
    DDL_GPIO_StructInit(&GPIO_configStruct);

    /* Unlock RCM */
    DDL_RCM_Unlock();

    /* Enable GPIO clock */
    DDL_RCM_EnableAHBPeripheral(COM_TX_PORT_CLK[COM] | COM_RX_PORT_CLK[COM]);

    if (COM == COM1)
    {
        DDL_RCM_EnableAPBPeripheral(COM_USART_CLK[COM]);
    }
    else
    {
        DDL_RCM_EnableAPBPeripheral(COM_USART_CLK[COM]);
    }

    /* Lock RCM */
    DDL_RCM_Lock();

    /* Configure USART Tx as alternate function push-pull */
    GPIO_configStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_configStruct.Pin = COM_TX_PIN[COM];
    GPIO_configStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_configStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_configStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_configStruct.Alternate = COM_GPIO_AF[COM];

    DDL_GPIO_Init(COM_TX_PORT[COM], &GPIO_configStruct);

    /* Configure USART Rx as input floating */
    GPIO_configStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_configStruct.Pin = COM_RX_PIN[COM];
    DDL_GPIO_Init(COM_RX_PORT[COM], &GPIO_configStruct);

    /* USART configuration */
    DDL_USART_Init(COM_USART[COM], configStruct);

    /* Enable USART */
    DDL_USART_Enable(COM_USART[COM]);
}
