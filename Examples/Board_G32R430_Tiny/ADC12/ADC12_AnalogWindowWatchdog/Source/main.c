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
/* ADC AWD Active Flag */
uint8_t iAWD_Flag = 0;

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void ADC_Init(void);
void ADC_Isr(void);

/* Delay */
void Delay(uint32_t count);

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

    /* LED1 Init */
    /* Note: J10 selects whether PA1 connects to LED1 or the external header. */
    BOARD_LEDInit(LED1);

    printf("\r\nADC3 Analog Window Watchdog Examples.\r\n");

    /* ADC Init */
    ADC_Init();

    while (1)
    {
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

/*!
 * @brief     ADC Init
 *
 * @param     None
 *
 * @retval    None
 */
void ADC_Init(void)
{
    /* GPIO init structure */
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    /* ADC init structure */
    DDL_ADC12_REG_InitTypeDef ADC_REG_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();

    /* Set ADC3 clock source to SYSCLK */
    DDL_RCM_ADC_SetAdcAnalogClkSource(DDL_RCM_ADCACLK_SYSCLK);

    /* Set ADC3 Clock Division */
    DDL_RCM_ADC_SetAdc12AnalogClkDivision(DDL_RCM_ADC12ACLK_DIV_8);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_ADC3);
    DDL_RCM_Lock();

    /* ADC channel 0 configuration */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_3;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    DDL_GPIO_EnableAdc3AnalogSwitchPin(GPIOC, DDL_GPIO_PIN_3);

    DDL_ADC12_InitTypeDef ADC_InitStruct = {0U};
    ADC_InitStruct.DataAlignment = DDL_ADC12_ALIGNMENT_RIGHT;
    DDL_ADC12_Init(ADC3, &ADC_InitStruct);

    /* Config ADC3 */
    ADC_REG_InitStruct.TriggerSource    = DDL_ADC12_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength  = DDL_ADC12_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DDL_ADC12_REG_SEQ_DISCONT_DISABLE;
    ADC_REG_InitStruct.ContinuousMode   = DDL_ADC12_REG_CONV_CONTINUOUS;
    ADC_REG_InitStruct.DMATransfer      = DDL_ADC12_REG_DMA_TRANSFER_DISABLE;
    DDL_ADC12_REG_Init(ADC3, &ADC_REG_InitStruct);

    /* Set the sampling time of ADC3 */
    DDL_ADC12_SetChannelSamplingTime(ADC3, DDL_ADC12_CHANNEL_0, DDL_ADC12_SAMPLINGTIME_128CYCLES);

    DDL_ADC12_REG_SetSequencerLength(ADC3, DDL_ADC12_REG_SEQ_SCAN_DISABLE);
    DDL_ADC12_REG_SetSequencerRanks(ADC3, DDL_ADC12_REG_RANK_1, DDL_ADC12_CHANNEL_0);

    /* Set the upper and lower threshold of AWD1 for ADC3. */
    /* Upper threshold voltage: 2270 mV = 0xB00 * 3300 / 4095 */
    /* Lower threshold voltage:  618 mV = 0x300 * 3300 / 4095 */
    DDL_ADC12_ConfigAnalogWDThresholds(ADC3, DDL_ADC12_AWD1, 0xB00, 0x300);

    /* Enable the mode for ADC3 AWD1 */
    DDL_ADC12_SetAnalogWDMonitChannels(ADC3, DDL_ADC12_AWD1, DDL_ADC12_AWD_CHANNEL_0_REG);

    /* Enable Interrupt */
    DDL_ADC12_EnableIT_EOC(ADC3);
    DDL_ADC12_EnableIT_AWD1(ADC3);

    DDL_Interrupt_Register(ADC3_IRQn, ADC_Isr);
    DDL_NVIC_EnableIRQRequest(ADC3_IRQn, 1, 1);

    DDL_ADC12_Enable(ADC3);
    while (DDL_RCM_ADC_IsAdc12AnalogClkRDY() == RESET);

    /* ADC start conversion */
    DDL_ADC12_REG_StartConversion(ADC3);
}

/*!
 * @brief     ADC interrupt service routine
 *
 * @param     None
 *
 * @retval    None
 */

void ADC_Isr(void)
{
    uint16_t adcData = 0;
    uint16_t voltage = 0;

    if(DDL_ADC12_IsActiveFlag_AWD1(ADC3))
    {
        /* Turn on LED1 */
        BOARD_LEDOn(LED1);
        iAWD_Flag = 1;
    }

    if(DDL_ADC12_IsActiveFlag_EOC(ADC3))
    {
        adcData = DDL_ADC12_REG_ReadConversionData32(ADC3);
        voltage = (adcData * 3300) / 4095;
        if(iAWD_Flag == 1 )
        {
            printf("\r\nADC1 Analog Window Watchdog is active.\r\n");
            iAWD_Flag = 0;
        }
        else
        {
            /* Turn off LED1 */
            BOARD_LEDOff(LED1);
        }
        printf("\r\n voltage : %d mV\r\n", voltage);
        Delay(0x1FF);
    }
    /* Clear ADC3 AWD pending interrupt bit */
    DDL_ADC12_ClearFlag_AWD1(ADC3);
    /* Clear ADC3 EOC pending interrupt bit */
    DDL_ADC12_ClearFlag_EOC(ADC3);
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
