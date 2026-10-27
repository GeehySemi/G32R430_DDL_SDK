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

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void LPTMR_Init(void);
void LPTMR_Isr(void);

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

    /* Configure system clock */
    DDL_SysClkConfig();
    
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

    /* LPTMR Init */
    LPTMR_Init();

    /* Infinite loop */
    while (1)
    {
        /* Print a message indicating the system is ready to enter low power mode */
        printf("Ready to enter low power mode! \r\n");
        printf("The system will wake up in approximately 2 seconds.\r\n");

        /* Enter low power mode */
        DDL_PMU_EnterStopModeWFI();

        /* Print a message indicating the system has woken up from low power mode */
        printf("System wake up!\r\n");
    }
}

/**
 * @brief   System clock configuration
 *
 * @param   None
 *
 * @retval  None
 */
void DDL_SysClkConfig(void)
{
    /* Since the system clock is HSI after exiting stop mode, */
    /* the clock here will use the HSI as the main clock during power-up. */
    /* No clock configuration is performed here. */
}

/**
 * @brief   LPTMR Initialize
 *
 * @param   None
 *
 * @retval  None
 */
void LPTMR_Init(void)
{
    DDL_LPTMR_InitTypeDef LPTMR_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP);
    DDL_RCM_DisableBackupWriteProtect();

    /* Reset the backup domain */
    DDL_RCM_EnableBackupDomainReset();
    DDL_RCM_DisableBackupDomainReset();

    DDL_RCM_LSI_Enable();
    while (DDL_RCM_LSI_IsReady() == RESET);

    DDL_RCM_Lock();

    DDL_LPTMR_EnableClk();

    /* Configure the LPTMR prescaler and wake-up value */
    /* LPTMR frequency = LSI(32KHz) / 32 = 1KHz */
    /* Set prescaler to divide by 32 */
    /* Set wake-up value to 2000 counts (2 seconds) */
    LPTMR_InitStruct.Prescaler = 0x5;
    LPTMR_InitStruct.WakeUpValue = 2000;
    DDL_LPTMR_Init(LPTMR, &LPTMR_InitStruct);

    DDL_Interrupt_Register(LPTMR_IRQn, LPTMR_Isr);
    DDL_NVIC_EnableIRQRequest(LPTMR_IRQn, 0, 0);

    /* Enable the LPTMR wake-up interrupt */
    DDL_LPTMR_EnableIT_WakeUp(LPTMR);

    /* Start the LPTMR */
    DDL_LPTMR_Enable(LPTMR);
}


/*!
 * @brief     EINT0 interrupt service routine
 *
 * @param     None
 *
 * @retval    None
 */
void LPTMR_Isr(void)
{
    if (DDL_LPTMR_IsActiveFlag_WakeUp(LPTMR))
    {
        DDL_LPTMR_ClearFlag_WakeUp(LPTMR);
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

int uart_putc(char ch, FILE* file)
{
    /* send a byte of data to the serial port */
    DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)ch);

    /* wait for the data to be send */
    while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);

    return (ch);
}

static FILE __stdio = FDEV_SETUP_STREAM(uart_putc, NULL, NULL, _FDEV_SETUP_WRITE);
FILE* const stdin = &__stdio;

__strong_reference(stdin, stdout);
__strong_reference(stdin, stderr);

#else

#warning Not supported compiler type
#endif
