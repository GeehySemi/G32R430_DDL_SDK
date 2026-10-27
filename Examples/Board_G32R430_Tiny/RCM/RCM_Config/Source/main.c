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
void Delay(uint32_t count);

/* Private function prototypes ********************************************/
uint32_t RCM_Clock_Switch_To_HSI(void);
uint32_t RCM_Clock_Switch_To_HSE(void);

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

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Switch system clock to HSE */
    if(!RCM_Clock_Switch_To_HSE())
    {
        printf("Switch to HSE fail\n");
    }
    else
    {
        printf("Switch to HSE successful\n");
    }

    Delay(30000);

    /* Switch system clock to HSI */
    if(!RCM_Clock_Switch_To_HSI())
    {
        printf("Switch to HSI fail\n");
    }
    else
    {
        printf("Switch to HSI successful\n");
    }

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief   RCM Configuration
 *
 * @param   None
 *
 * @retval  None
 */
void RCM_Config(void)
{
    DDL_RCM_Unlock();
    DDL_RCM_HSI_Enable();
    DDL_RCM_HSE_Enable();
    DDL_RCM_Lock();
}

/**
 * @brief   Swtich master clock to HSE
 *
 * @param   None
 *
 * @retval  state of bit (1 or 0)
 */
uint32_t RCM_Clock_Switch_To_HSE(void)
{
    DDL_RCM_Unlock();

    DDL_RCM_HSE_Enable();

    /* wait for HSE ready */
    while(!DDL_RCM_HSE_IsReady());
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_HSE);
    DDL_RCM_EnableSysClkSwitch();

    DDL_RCM_Lock();

    while(!DDL_RCM_IsActiveFlag_SWDONE())
    {
        if(DDL_RCM_IsActiveFlag_SWERR())
        {
            return 0;
        }
    }

    return 1;
}

/**
 * @brief   Swtich master clock to HSI
 *
 * @param   None
 *
 * @retval  state of bit (1 or 0)
 */
uint32_t RCM_Clock_Switch_To_HSI(void)
{
    DDL_RCM_Unlock();

    /* wait for HSI ready */
    while(!DDL_RCM_HSI_IsReady());
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_HSI);
    DDL_RCM_EnableSysClkSwitch();

    DDL_RCM_Lock();

    while(!DDL_RCM_IsActiveFlag_SWDONE())
    {
        if(DDL_RCM_IsActiveFlag_SWERR())
        {
            return 0;
        }
    }
    return 1;
}

/*!
 * @brief       Delay
 *
 * @param       count:  delay count
 *
 * @retval      None
 */
void Delay(uint32_t count)
{
    volatile uint32_t delay = count;
    while(delay--);
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
    if (ch == '\n')
    {
        /* send a carriage return byte to the serial port */
        DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)'\r');
        
        /* wait for the data to be send */
        while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);
    }

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
    if (ch == '\n')
    {
        /* send a carriage return byte to the serial port */
        DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)'\r');
        
        /* wait for the data to be send */
        while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);
    }

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
    if (ch == '\n')
    {
        /* send a carriage return byte to the serial port */
        DDL_USART_TransmitData8(DEBUG_USART, (uint8_t)'\r');
        
        /* wait for the data to be send */
        while (DDL_USART_IsActiveFlag_TC(DEBUG_USART) == RESET);
    }

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
