/**
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

#define COMP_INPUT_PLUS_PIN     DDL_GPIO_PIN_12
#define COMP_INPUT_PLUS_PORT    GPIOD

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void GPIO_Init(void);
void COMP_Init(void);
void DAC_Init(void);
void Delay(uint32_t count);
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

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Initialize LEDs */
    /* Note: J10 selects whether PA1/PA2 connect to LED1/LED2 or the external header. */
    BOARD_LEDInit(LED1);
    BOARD_LEDInit(LED2);

    /* Turn off LEDs */
    BOARD_LEDOff(LED1);
    BOARD_LEDOff(LED2);
    
    /* Initialize GPIO, COMP and DAC */
    GPIO_Init();
    COMP_Init();
    DAC_Init();

    /* Infinite loop */
    while (1)
    {
        /* Read COMP output level and turn on corresponding LED */
        if (DDL_COMP_ReadOutputLevel(COMP1) == 1)
        {
            printf("COMP Output High, ");
            printf(" COMP + Input Voltage > DAC Output Voltage(1.65V)\r\n");

            /* Turn on LED1 and turn off LED2 */
            BOARD_LEDOn(LED1);
            BOARD_LEDOff(LED2);
        }
        else
        {
            printf("COMP Output Low, ");
            printf(" COMP + Input Voltage < DAC Output Voltage(1.65V)\r\n");

            /* Turn off LED1 and turn on LED2 */
            BOARD_LEDOff(LED1);
            BOARD_LEDOn(LED2);
        }

        Delay(0x20000);
        
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
 * @brief   GPIO Initialize
 *
 * @param   None
 *
 * @retval  None
 */
void GPIO_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /* COMP input plus pin configure */
    GPIO_InitStruct.Pin = COMP_INPUT_PLUS_PIN;
    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    DDL_GPIO_Init(COMP_INPUT_PLUS_PORT, &GPIO_InitStruct);

    /* Set PD12 mode to analog 3.3V input/output */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_12, DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT); 
}

/**
 * @brief   DAC Initialize
 *
 * @param   None
 *
 * @retval  None
 */
void DAC_Init(void)
{
    DDL_DAC_InitTypeDef DAC_InitStruct = {0};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_DAC2);
    DDL_RCM_Lock();

    DAC_InitStruct.TriggerSource = DDL_DAC_CHANNEL_TRIG_SOURCE_SOFTWARE;
    DAC_InitStruct.WaveAutoGeneration = DDL_DAC_WAVE_GENERATE_NONE;
    DAC_InitStruct.WaveAutoGenerationConfig = 0;
    DAC_InitStruct.OutputBuffer = 0;

    DDL_DAC_Init(DAC2, &DAC_InitStruct);
    
    /* DACoutput = VREF * DOR / 1024 = 3.3V * 512 / 1024 = 1.65V */
    DDL_DAC_SetRightAlignmentData(DAC2, 512);

    DDL_DAC_Enable(DAC2);
    DDL_DAC_EnableSoftwareTrigger(DAC2);
}

/**
 * @brief   COMP Initialize
 *
 * @param   None
 *
 * @retval  None
 */
void COMP_Init(void)
{
    DDL_COMP_InitTypeDef COMP_InitStruct = {0};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_COMP);
    DDL_RCM_Lock();

    COMP_InitStruct.InputPlus = DDL_COMP_INPUT_PLUS_INP0;
    COMP_InitStruct.InputMinus = DDL_COMP_INPUT_MINUS_DAC2;
    COMP_InitStruct.OutputPol = DDL_COMP_OUTPUTPOL_INVERTED;
    COMP_InitStruct.OutputBlank = DDL_COMP_BLANK_0;

    DDL_COMP_Init(COMP1, &COMP_InitStruct);
    DDL_COMP_Enable(COMP1);
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
    while (delay--)
    {
        __NOP();
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

