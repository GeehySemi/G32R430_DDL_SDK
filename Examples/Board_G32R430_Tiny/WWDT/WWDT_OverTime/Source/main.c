/**
 *
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
/* Define the delay time (ms) between WWDT feed attempts */
#define WWDT_FEED_DELAY_MS 200u

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
static __IO uint32_t TimingDelay;

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void Systick_Init(void);
void SysTick_Delay_ms(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

void WWDT_Init(void);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief     Main program
 *
 * @param     None
 *
 * @retval    None
 *
 */
int main(void)
{
    /* USART init structure */
    DDL_USART_InitTypeDef USART_InitStruct = {0U};

    /* Configure system clock */
    DDL_SysClkConfig();

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Check if the system has resumed from WWDT reset */
    if (DDL_RCM_IsActiveFlag_WWDTRST())
    {
        DDL_RCM_Unlock();
        DDL_RCM_ClearFlag_WWDTRST();
        DDL_RCM_Lock();
        printf("\r\nWWDT Reset!\r\n");
    }
    printf("\r\nThe overtime is from 192.512ms to 262.144ms \r\n");
    printf("WWDT feed delay: %d ms\r\n", WWDT_FEED_DELAY_MS);

    /* Start SysTick timer and configure for 1 ms interrupts */
    Systick_Init();
    SysTick_Delay_ms(500);

    /* WWDT configuration */
    WWDT_Init();

    while (1)
    {
        /* Delay 200 ms  (262.144ms > 200ms) and refresh within window
           If SysTick delay drifts beyond ~192.512ms but before ~262.144ms, refresh is safe.
           If delay exceeds ~262.144ms, WWDT will reset. */
        SysTick_Delay_ms(WWDT_FEED_DELAY_MS);
        DDL_WWDT_SetCounter(WWDT, 127);
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
    /* Due to the timeout design of the WWDT */
    /* this routine uses the default system power-on clock HSI to operate. */
}

/*!
 * @brief       WWDT configuration
 *
 * @param       None
 *
 * @retval      None
 */
void WWDT_Init(void)
{
    /* Enable WWDT clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_WWDT);
    DDL_RCM_Lock();

    /* WWDT TimeBase =  8MHz/4096)/8 = 244Hz (~4.096 ms)  */
    DDL_WWDT_SetPrescaler(WWDT, DDL_WWDT_PRESCALER_8);

    /* Set Window value to 80; WWDT counter should be refreshed only when the counter
    is below 80 (and greater than 64) otherwise a reset will be generated  */
    DDL_WWDT_SetWindow(WWDT, 80);

    /* Enable WWDT and set counter value to 127
     In this case the refresh window is: ~4.096 * (127-80)= 192.512ms < refresh window < ~4.096 * 64 = 262.144ms*/
    DDL_WWDT_SetCounter(WWDT, 127);
    DDL_WWDT_Enable(WWDT);
}

/*!
 * @brief       Start SysTick
 *
 * @param       None
 *
 * @retval      None
 */
void Systick_Init(void)
{
    SystemCoreClockUpdate();
    /* SystemFrequency / 1000 = 1ms */
    if (SysTick_Config(SystemCoreClock / 1000))
    {
        /* Capture error */
        while (1);
    }
}

/*!
 * @brief       Precise Delay
 *
 * @param       nTime in milliseconds
 *
 * @retval      None
 */
void SysTick_Delay_ms(__IO uint32_t nTime)
{
    TimingDelay = nTime;
    while(TimingDelay != 0);
}

/*!
 * @brief       Decrements the TimingDelay
 *
 * @param       None
 *
 * @retval      None
 */
void TimingDelay_Decrement(void)
{
    if(TimingDelay != 0)
    {
        TimingDelay--;
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
