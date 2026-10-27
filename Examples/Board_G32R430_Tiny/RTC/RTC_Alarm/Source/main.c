/**
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.0
 *
 * @date        2025-10-30
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
#include "main.h"

/* Private includes *******************************************************/
#include <stdio.h>

/* Private macro **********************************************************/
#define DEBUG_USART COM2_PORT
#define WAKEUP_DELAY_SECS        (5U)

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void RTC_Init(void);
void RTC_Alarm_Int_Init(void);
void RTC_Int_Init(void);

void RTC_Alarm_Handler(void);
void RTC_Handler(void);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Main program
 *
 * @param   None
 *
 * @retval  None
 */
int main(void)
{ 
    /* USART init structure */
    DDL_USART_InitTypeDef USART_InitStruct = {0U};

    /* RTC alarm init structure */
    DDL_RTC_AlarmTypeDef Alarm_InitStruct = {0};

    /* Configure interrupt group 4: 4-bit preemptive priority, 0-bit subpriority */
    DDL_NVIC_ConfigPriorityGroup(DDL_NVIC_PRIORITY_GROUP_4);

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Initialize RTC module */
    RTC_Init();
    
    /* Initialize external interrupt */
    RTC_Alarm_Int_Init();

    /* Configure RTC alarm to wake up the system after WAKEUP_DELAY_SECS seconds */
    Alarm_InitStruct.AlarmTime = DDL_RTC_GetTime(RTC) + WAKEUP_DELAY_SECS;
    DDL_RTC_ALM_Init(RTC, &Alarm_InitStruct);
    
    /* Clear any pending alarm flag */
    DDL_RTC_ClearFlag_ALR(RTC);
    
    /* Print message before entering low power mode */
    printf("*************************************\r\n");
    printf("Ready to enter low power mode with WFE!\r\n");
    printf("System will wake up in %u seconds using EINT17(RTC Alarm)\r\n", WAKEUP_DELAY_SECS);

    /* Enter wait for event mode (low power mode) */
    __WFE();

    /* Print message after system wake up */
    printf("System wake up from WFE mode!\r\n");
    printf("*************************************\r\n");

    /* Initialize external interrupt */
    RTC_Int_Init();

    /* Configure RTC alarm to wake up the system after WAKEUP_DELAY_SECS seconds */
    Alarm_InitStruct.AlarmTime = DDL_RTC_GetTime(RTC) + WAKEUP_DELAY_SECS;
    DDL_RTC_ALM_Init(RTC, &Alarm_InitStruct);
    
    /* Clear any pending alarm flag */
    DDL_RTC_ClearFlag_ALR(RTC);
    
    printf("*************************************\r\n");
    printf("Ready to enter low power mode with WFI!\r\n");
    printf("System will wake up in %u seconds using direct RTC interrupt\r\n", WAKEUP_DELAY_SECS);

    /* Enter wait for interrupt mode (low power mode) */
    __WFI();

    /* Print message after system wake up */
    printf("System wake up from WFI mode!\r\n");
    printf("*************************************\r\n");

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief   RTC Initialize
 *
 * @param   None
 *
 * @retval  None
 */
void RTC_Init(void)
{
    DDL_RTC_InitTypeDef RTC_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP);
    DDL_RCM_DisableBackupWriteProtect();
    DDL_RCM_LSI_Enable();
    while(!DDL_RCM_LSI_IsReady());
    DDL_RTC_SetClkSource(DDL_RTC_CLOCK_SOURCE_LSI);
    DDL_RCM_Lock();

    /* RTC frequency = LSI(32KHz) / (31999 + 1) = 1Hz */
    RTC_InitStruct.Prescaler = 31999;
    DDL_RTC_Init(RTC, &RTC_InitStruct);

    DDL_RTC_ClearFlag_SEC(RTC);
    DDL_RTC_ClearFlag_ALR(RTC);
    /* Enable RTC */
    DDL_RTC_EnableClk();
}

/**
 * @brief   Initialize RTC Alarm interrupt.
 *
 * @param   None
 *
 * @retval  None
 */
void RTC_Alarm_Int_Init(void)
{
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_EINT);
    DDL_RCM_Lock();

    EINT_InitStruct.Line = DDL_EINT_LINE_17;
    EINT_InitStruct.LineCommand = ENABLE;
    EINT_InitStruct.Mode = DDL_EINT_MODE_EVENT;
    EINT_InitStruct.Trigger = DDL_EINT_TRIGGER_RISING;

    DDL_EINT_Init(&EINT_InitStruct);
}

/**
 * @brief   Initialize RTC peripheral interrupt.
 *
 * @param   None
 *
 * @retval  None
 */
void RTC_Int_Init(void)
{
    DDL_RTC_EnableIT_ALR(RTC);

    DDL_Interrupt_Register(RTC_IRQn,&RTC_Handler);
    DDL_NVIC_EnableIRQRequest(RTC_IRQn, 0, 0);
}

/**
 * @brief   RTC Alarm (ALR) interrupt handler.
 *
 * @param   None
 *
 * @retval  None
 */
void RTC_Handler(void)
{
    if(DDL_RTC_IsActiveFlag_ALR(RTC))
    {
        DDL_RTC_ClearFlag_ALR(RTC);
    }
}

#if defined(__CC_ARM) || defined(__ARMCC_VERSION)
/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       ch:  The characters that need to be send.
*
* @param       *f:  pointer to a FILE that can recording all information
*              needed to control a stream
*
* @retval      The characters that need to be send.
*
* @note
*/
int fputc(int ch, FILE* f)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);
    
    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}
#elif defined(__ICCARM__)

/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       ch:  The characters that need to be send.
*
* @retval      The characters that need to be send.
*
* @note
*/
int __io_putchar(int ch)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);
    
    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}

/*!
* @brief       Redirect C Library function printf to serial port.
*              After Redirection, you can use printf function.
*
* @param       file:  Meaningless in this function.
*
* @param       *ptr:  Buffer pointer for data to be sent.
*
* @param       len:  Length of data to be sent.
*
* @retval      The characters that need to be send.
*
* @note
*/
int __write(int file, char* ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        __io_putchar(*ptr++);
    }

    return len;
}
#elif defined (__clang__) && !defined (__ARMCC_VERSION)

int uart_putc(char ch, FILE *file)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);
    
    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}

static FILE __stdio = FDEV_SETUP_STREAM(uart_putc, NULL, NULL, _FDEV_SETUP_WRITE);
FILE *const stdin = &__stdio;

__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);

#else

#warning Not supported compiler type
#endif
