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

    /*ADC Init*/
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
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_ADC16_REG_InitTypeDef ADC_REG_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();

    /* Set ADC1 clock source to SYSCLK */
    DDL_RCM_ADC_SetAdcAnalogClkSource(DDL_RCM_ADCACLK_SYSCLK);

    /* Set ADC1 Clock Division */
    DDL_RCM_ADC_SetAdc16AnalogClkDivision(DDL_RCM_ADC16ACLK_DIV_6);

    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_ADC1);

    DDL_RCM_Lock();

    /* ADC channel 1 configuration */
    /* Note: J10 selects whether PA1 connects to LED1 or the external header. */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Config ADC1 */
    ADC_REG_InitStruct.TriggerSource    = DDL_ADC16_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength  = DDL_ADC16_REG_SEQ_SCAN_DISABLE;
    ADC_REG_InitStruct.SequencerDiscont = DDL_ADC16_REG_SEQ_DISCONT_DISABLE;
    ADC_REG_InitStruct.ContinuousMode   = DDL_ADC16_REG_CONV_CONTINUOUS;
    ADC_REG_InitStruct.DMATransfer      = DDL_ADC16_REG_DMA_TRANSFER_NONE;
    ADC_REG_InitStruct.Overrun          = DDL_ADC16_REG_OVR_DATA_OVERWRITTEN;
    DDL_ADC16_REG_Init(ADC1, &ADC_REG_InitStruct);

    /* Config ADC Oversampling Mode */
    DDL_ADC16_SetOverSamplingScope(ADC1, DDL_ADC16_OVS_GRP_REGULAR_CONTINUED);
    DDL_ADC16_SetOverSamplingDiscont(ADC1, DDL_ADC16_OVS_REG_CONT);
    DDL_ADC16_ConfigOverSamplingRatioShift(ADC1, DDL_ADC16_OVS_RATIO_2, DDL_ADC16_OVS_SHIFT_RIGHT_1);

    /* Set the sampling time of ADC1 */
    DDL_ADC16_SetChannelSamplingTime(ADC1, DDL_ADC16_CHANNEL_1, DDL_ADC16_SAMPLINGTIME_10CYCLES);
    DDL_ADC16_REG_SetSequencerLength(ADC1, DDL_ADC16_REG_SEQ_SCAN_DISABLE);
    DDL_ADC16_REG_SetSequencerRanks(ADC1, DDL_ADC16_REG_RANK_1, DDL_ADC16_CHANNEL_1);

    /* Set the reference voltage of ADC1 as external reference voltage. */
    DDL_ADC16_SetVerfExternal(ADC1);

    /* Set the sampling mode of ADC1 channel. */
    DDL_ADC16_SetChannelSingleDiff(ADC1, DDL_ADC16_CHANNEL_1, DDL_ADC16_SINGLE_ENDED);

    DDL_ADC16_Disable(ADC1);

    /* Enable Interrupt */
    DDL_ADC16_EnableIT_EOC(ADC1);

    DDL_Interrupt_Register(ADC1_IRQn, ADC_Isr);
    DDL_NVIC_EnableIRQRequest(ADC1_IRQn, 1, 0);

    DDL_ADC16_Enable(ADC1);
    while (DDL_RCM_ADC_IsAdc16AnalogClkRDY() == RESET);

    /* ADC start conversion */
    DDL_ADC16_REG_StartConversion(ADC1);
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

    if(DDL_ADC16_IsActiveFlag_EOC(ADC1))
    {
        adcData = DDL_ADC16_REG_ReadConversionData32(ADC1);
        voltage = (adcData * 3300) / 65535;

        printf("\r\n voltage : %d mV\r\n", voltage);
        Delay(0x4FFFF);
        /* Clear ADC1 EOC pending interrupt bit */
        DDL_ADC16_ClearFlag_EOC(ADC1);
    }
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
