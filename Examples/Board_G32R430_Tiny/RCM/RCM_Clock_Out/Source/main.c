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
//#define HSI_TO_120MHz
#define DEBUG_USART COM2_PORT

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void SystemClock_Update_to_120MHz(void);
void ConfigureMCOClockOutput(void);

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

    /* Update system clock to 120 MHz */
    SystemClock_Update_to_120MHz();

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Optionally print the current system core clock (if available in your library) */
    printf("SystemCoreClock: %d Hz\n", SystemCoreClock);

#ifdef HSI_TO_120MHz
    printf("   PLL Source: HSI\n");
#else
    printf("   PLL Source: HSE\n");
#endif

    /* Indicate that MCO is configured */
    printf("MCO Clock Output is configured on PC12\n\n");

    /* Configure MCO clock output */
    /* PC12 will be used as MCO output. Its USART2 RX function will be disabled */
    ConfigureMCOClockOutput();

    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief  Configures PC12 pin for MCO (Microcontroller Clock Output) function.
 *         The function unlocks the clock control registers, initializes PC12 
 *         in alternate function mode, sets PLL as the MCO source with a division factor,
 *         enables MCO output, and locks the clock control registers again.
 * @param  None
 * @retval None
 */
void ConfigureMCOClockOutput(void)
{
    DDL_GPIO_InitTypeDef configStruct = {0U};

    /* Unlock clock control registers */
    DDL_RCM_Unlock();

    /* Enable the GPIO clock (for GPIOC) */
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);

    /* Initialize GPIO pin PC12 as high-speed push-pull output with no pull */
    /* Configure PC12 to alternate function mode for MCO */
    DDL_GPIO_StructInit(&configStruct);
    configStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    configStruct.Pin = DDL_GPIO_PIN_12;
    configStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    configStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    configStruct.Pull = DDL_GPIO_PULL_NO;
    configStruct.Alternate = DDL_GPIO_AF_2;
    DDL_GPIO_Init(GPIOC, &configStruct);

    /* Set PC12 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOC, DDL_GPIO_PIN_12, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 

    printf("MCO configured: Source = SYSCLK, Division = 16\n");
    printf("Output clock freq = %d Hz\n", SystemCoreClock / 16);

    /* Select PLL as the MCO source and set the division factor to 16 */
    DDL_RCM_ConfigMCO(DDL_RCM_MCOSOURCE_SYSCLK, DDL_RCM_MCO_DIV_16);

    /* Enable MCO output */
    DDL_RCM_EnableMCO();

    /* Lock clock control registers */
    DDL_RCM_Lock();
}

#ifdef HSI_TO_120MHz

/**
 * @brief  Update system clock configuration to 120 MHz from 8 MHz (HSI + PLL),
 *         with appropriate Flash wait-state setup.
 *
 * The routine performs the following high-level actions:
 *   - Unlock clock control registers .
 *   - Enable HSI and wait for it to become ready.
 *   - Apply Flash access wait states suitable for 120 MHz operation.
 *   - Configure PLL: source = HSI, multiplication factor = 16, no prescaler.
 *   - Enable PLL and wait for PLL ready.
 *   - Switch the system clock source to PLL output.
 *   - Optionally verify system core clock and stability; adjust wait states if needed.
 *
 * @param  None
 * @retval None
 */
void SystemClock_Update_to_120MHz(void)
{
    /* Unlock clock control registers */
    /* Restore access to protected system control registers, if a KEY/LOCK mechanism exists */
    DDL_RCM_Unlock();
    while ((RCM->KEY & RCM_KEY_KEYST) != RCM_KEY_KEYST) 
    { 
    }

    /* Enable HSI and wait for ready */
    /* Enable HSI input clock */
    DDL_RCM_HSI_Enable();
    /* Wait until HSI is ready */
    while(DDL_RCM_HSI_IsReady() != 1U)
    {
        /* wait for HSIRDY */
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
    /* PLL multiplier set to 16 (x16), prescaler no division, clock source from HSI */
    DDL_RCM_PLL_SetMultiplier(16);
    DDL_RCM_PLL_SetPrescaler(DDL_RCM_PLL_DIV1);
    DDL_RCM_PLL_SetClkSource(DDL_RCM_PLL_CLKSOURCE_HSI);

    /* Enable PLL and wait for ready */
    DDL_RCM_PLL_Enable();
    while (DDL_RCM_PLL_IsReady() == 0)
    {
        /* wait for PLL Ready */
    }

    /* Switch system clock to PLL output */
    DDL_RCM_SetSysClkSource(DDL_RCM_SYS_CLKSOURCE_PLL);

    /* Enable clock switch and wait for completion */
    DDL_RCM_EnableSysClkSwitch();
    while (DDL_RCM_IsActiveFlag_SWDONE() == 0)
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
#else
/**
 * @brief  Update system clock configuration to 120 MHz from 8 MHz (HSE + PLL),
 *         with appropriate Flash wait-state setup.
 *
 * The routine performs the following high-level actions:
 *   - Unlock clock control registers .
 *   - Enable HSE and wait for it to become ready.
 *   - Apply Flash access wait states suitable for 120 MHz operation.
 *   - Configure PLL: source = HSE, multiplication factor = 16, no prescaler.
 *   - Enable PLL and wait for PLL ready.
 *   - Switch the system clock source to PLL output.
 *   - Optionally verify system core clock and stability; adjust wait states if needed.
 *
 * @param  None
 * @retval None
 */
void SystemClock_Update_to_120MHz(void)
{
    /* Unlock clock control registers */
    /* Restore access to protected system control registers, if a KEY/LOCK mechanism exists */
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
    /* PLL multiplier set to 16 (x16), prescaler no division, clock source from HSE */
    DDL_RCM_PLL_SetMultiplier(16);
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
#endif

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
