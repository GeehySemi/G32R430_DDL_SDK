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
#define ADC_CH_SIZE         3

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
SECTION_DTCM_DATA
uint32_t adcData[ADC_CH_SIZE] __attribute__((aligned(4)));

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void ADC_Init(void);
void DMA_Init(void);
void ADC_MultiChannelPolling(void);

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

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* DMA Init */
    DMA_Init();

    /* ADC Init */
    ADC_Init();

    while (1)
    {
        ADC_MultiChannelPolling();
        Delay(0x3FFFFF);
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
 * @brief     DMA Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void DMA_Init(void)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_DMA);
    DDL_RCM_Lock();

    DMA_InitStruct.PeriphOrM2MSrcAddress  = (uint32_t)&ADC3->DR;
    DMA_InitStruct.MemoryOrM2MDstAddress  = (uint32_t)&adcData;
    DMA_InitStruct.Direction              = DDL_DMA_DIRECTION_PERIPH_TO_MEMORY;
    DMA_InitStruct.Mode                   = DDL_DMA_MODE_CIRCULAR;
    DMA_InitStruct.PeriphOrM2MSrcIncMode  = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode  = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.NbData                 = ADC_CH_SIZE;
    DMA_InitStruct.Channel                = DDL_DMA_CHANNEL_0;
    DMA_InitStruct.Priority               = DDL_DMA_PRIORITY_HIGH;
    DMA_InitStruct.FIFOMode               = DDL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold          = DDL_DMA_FIFOTHRESHOLD_1_2;
    DMA_InitStruct.MemBurst               = DDL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst            = DDL_DMA_PBURST_SINGLE;

    /* ADC3 can only perform DMA data transfer using WORD size */
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_WORD;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_MDATAALIGN_WORD;

    /* Initialize DMA1 Stream2 */
    DDL_DMA_Init(DMA1, DDL_DMA_STREAM_2, &DMA_InitStruct);

    /* Enable DMA1 Stream2 */
    DDL_DMA_EnableStream(DMA1, DDL_DMA_STREAM_2);
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
    DDL_ADC12_InitTypeDef ADC_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();

    /* Set ADC3 clock source to SYSCLK */
    DDL_RCM_ADC_SetAdcAnalogClkSource(DDL_RCM_ADCACLK_SYSCLK);

    /* Set ADC3 Clock Division */
    DDL_RCM_ADC_SetAdc12AnalogClkDivision(DDL_RCM_ADC12ACLK_DIV_4);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_ADC3);
    DDL_RCM_Lock();

    /* ADC channel 0,1,2 configuration */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4 | DDL_GPIO_PIN_5;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    DDL_GPIO_EnableAdc3AnalogSwitchPin(GPIOC, DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4 | DDL_GPIO_PIN_5);

    ADC_InitStruct.DataAlignment = DDL_ADC12_ALIGNMENT_RIGHT;
    DDL_ADC12_Init(ADC3, &ADC_InitStruct);

    /* Config ADC3 */
    ADC_REG_InitStruct.TriggerSource    = DDL_ADC12_REG_TRIG_SOFTWARE;
    ADC_REG_InitStruct.SequencerLength  = DDL_ADC12_REG_SEQ_SCAN_ENABLE_3RANKS;
    ADC_REG_InitStruct.SequencerDiscont = DDL_ADC12_REG_SEQ_DISCONT_3RANKS;
    ADC_REG_InitStruct.ContinuousMode   = DDL_ADC12_REG_CONV_SINGLE;
    ADC_REG_InitStruct.DMATransfer      = DDL_ADC12_REG_DMA_TRANSFER_ENABLE;
    DDL_ADC12_REG_Init(ADC3, &ADC_REG_InitStruct);

    /* Set the sampling time of ADC3 */
    DDL_ADC12_SetChannelSamplingTime(ADC3, DDL_ADC12_CHANNEL_0, DDL_ADC12_SAMPLINGTIME_256CYCLES);
    DDL_ADC12_SetChannelSamplingTime(ADC3, DDL_ADC12_CHANNEL_1, DDL_ADC12_SAMPLINGTIME_256CYCLES);
    DDL_ADC12_SetChannelSamplingTime(ADC3, DDL_ADC12_CHANNEL_2, DDL_ADC12_SAMPLINGTIME_256CYCLES);

    DDL_ADC12_REG_SetSequencerRanks(ADC3, DDL_ADC12_REG_RANK_1, DDL_ADC12_CHANNEL_0);
    DDL_ADC12_REG_SetSequencerRanks(ADC3, DDL_ADC12_REG_RANK_2, DDL_ADC12_CHANNEL_1);
    DDL_ADC12_REG_SetSequencerRanks(ADC3, DDL_ADC12_REG_RANK_3, DDL_ADC12_CHANNEL_2);

    DDL_ADC12_Enable(ADC3);
    while (DDL_RCM_ADC_IsAdc12AnalogClkRDY() == RESET);

    /* ADC start conversion */
    DDL_ADC12_REG_StartConversion(ADC3);
}

/*!
 * @brief     ADC multi channel polling
 *
 * @param     None
 *
 * @retval    None
 */
void ADC_MultiChannelPolling(void)
{
    float voltage;
    uint8_t index;

    if(DDL_DMA_IsActiveFlag_TC2(DMA1) == SET)
    {
        for(index = 0; index < ADC_CH_SIZE; index++)
        {
            voltage = (adcData[index] * 3300.0f ) / 4095.0f;
            printf("ADC CH[%d] voltage = %.3f mV\r\n", index, voltage);
        }
        printf("\r\n");

        DDL_DMA_ClearFlag_TC2(DMA1);

        /* If the conversion is not restarted, no new DMA requests will be generated */
        /* DDL_ADC12_REG_StartConversion(ADC3); */
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