/**
 *
 * @file        main.c
 *
 * @brief       Main program body
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
#include "main.h"

/* Private includes *******************************************************/
#include <stdio.h>

/* Private macro **********************************************************/
#define DEBUG_USART COM2_PORT

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
volatile uint32_t tick = 0;

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void TMR_Init(void);
void TMR2_UpdateIsr(void);
void Delay(void);

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

    /* Configure interrupt group 4: 4-bit preemptive priority, 0-bit subpriority */
    DDL_NVIC_ConfigPriorityGroup(DDL_NVIC_PRIORITY_GROUP_4);

    /* Initialize TMR */
    TMR_Init();

    /* Initialize LED */
    /* Note: J10 selects whether PA2 connects to LED2 or the external header. */
    BOARD_LEDInit(LED2);

    /* Turn off LED */
    BOARD_LEDOff(LED2);

    while (1)
    {
        Delay();
        BOARD_LEDToggle(LED2);

        /* Get TMR1 counter value */
        printf("TMR1 Counter : %d\r\n",DDL_TMR_GetCounter(TMR1));
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
    /* Unlock clock control registers */
    /* Wait until the registers are unlocked */
    DDL_RCM_Unlock();
    while ((RCM->KEY & RCM_KEY_KEYST) != RCM_KEY_KEYST) 
    { 
    }

    /* Enable HSE and wait for ready */
    /* Enable HSE input clock */
    DDL_RCM_HSE_Enable();
    /* Wait until HSE is ready */
    while (DDL_RCM_HSE_IsReady() != 1) 
    {
        /* wait for HSERDY */
    }

    /* Configure Flash wait states appropriate for 120 MHz */
    /* Set Flash wait period to accommodate higher frequency */
    DDL_FLASH_SetWaitPeriod(FLASH_DDL_WAIT_PERIOD_3);
    /* Set Flash erase time base to 120 MHz (use 119 to represent 120 MHz) */
    DDL_FLASH_SetEraseTimeBase(119);

    /* Configure PLL */
    /* Ensure PLL is disabled prior to configuration */
    DDL_RCM_PLL_Disable();

    /* Configure PLL settings: multiplier, prescaler, and clock source */
    /* PLL multiplier set to 15 (x15), prescaler no division, clock source from HSE */
    DDL_RCM_PLL_SetMultiplier(15);
    DDL_RCM_PLL_SetPrescaler(DDL_RCM_PLL_DIV1);
    DDL_RCM_PLL_SetClkSource(DDL_RCM_PLL_CLKSOURCE_HSE);

    /* Enable PLL and wait for ready */
    DDL_RCM_PLL_Enable();
    while (DDL_RCM_PLL_IsReady() != 1)
    {
        /* wait for PLL Ready */
    }

    /* Switch system clock to PLL output */
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_PLL);

    /* Enable clock switch and wait for completion */
    DDL_RCM_EnableSysClkSwitch();
    while (DDL_RCM_IsActiveFlag_SWDONE() != 1)
    {
    }

    /* Set AHB, APB prescalers */
    DDL_RCM_SetAHBPrescaler(DDL_RCM_AHB_DIV_1);
    DDL_RCM_SetAPBPrescaler(DDL_RCM_APB_DIV_1);
    
    /* Disable clock switch controls */
    DDL_RCM_DisableSysClkSwitch();
    
    /* Lock clock control registers */
    DDL_RCM_Lock();

    /* Update SystemCoreClock if used by the project */
    SystemCoreClockUpdate();
}

/**
 * @brief     TMR Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_TMR_InitTypeDef TMR_InitStruct = {0U};
    DDL_TMR_ENCODER_InitTypeDef TMR_EncoderInitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR1);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR2);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*Config PD1 for TMR1 CH1 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Config PD5 for TMR1 CH2 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_5;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Set PD5 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_5, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 

    /* Config TMR1 */
    TMR_InitStruct.Prescaler         = 119;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 65535;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR1, &TMR_InitStruct);

    TMR_InitStruct.Prescaler         = 119;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 999;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR2, &TMR_InitStruct);

    /* Encoder */
    TMR_EncoderInitStruct.EncoderMode    = DDL_TMR_ENCODERMODE_X4_TI12;
    TMR_EncoderInitStruct.IC1Polarity    = DDL_TMR_IC_POLARITY_RISING;
    TMR_EncoderInitStruct.IC1ActiveInput = DDL_TMR_ACTIVEINPUT_DIRECTTI;
    TMR_EncoderInitStruct.IC1Prescaler   = DDL_TMR_ICPSC_DIV1;
    TMR_EncoderInitStruct.IC1Filter      = DDL_TMR_IC_FILTER_FDIV1;
    TMR_EncoderInitStruct.IC2Polarity    = DDL_TMR_IC_POLARITY_RISING;
    TMR_EncoderInitStruct.IC2ActiveInput = DDL_TMR_ACTIVEINPUT_DIRECTTI;
    TMR_EncoderInitStruct.IC2Prescaler   = DDL_TMR_ICPSC_DIV1;
    TMR_EncoderInitStruct.IC2Filter      = DDL_TMR_IC_FILTER_FDIV1;
    DDL_TMR_ENCODER_Init(TMR1, &TMR_EncoderInitStruct);

    DDL_TMR_SetCounter(TMR1, 32767);
    DDL_TMR_ClearFlag_UPDATE(TMR2);

    /* Enable TMR2 Interrupt */
    DDL_TMR_EnableIT_UPDATE(TMR2);
    DDL_Interrupt_Register(TMR2_IRQn, TMR2_UpdateIsr);
    DDL_NVIC_EnableIRQRequest(TMR2_IRQn, 0, 0);

    /* Enable TMR */
    DDL_TMR_EnableCounter(TMR1);
    DDL_TMR_EnableCounter(TMR2);
}

/**
 * @brief     TMR2 update Interrupt function
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR2_UpdateIsr(void)
{
    if (DDL_TMR_IsActiveFlag_UPDATE(TMR2) == SET)
    {
        tick++;
        DDL_TMR_ClearFlag_UPDATE(TMR2);
    }
}

/*!
 * @brief       Delay
 *
 * @param       None
 *
 * @retval      None
 */
void Delay(void)
{
    tick = 0;
    while(tick < 500)
    {
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
