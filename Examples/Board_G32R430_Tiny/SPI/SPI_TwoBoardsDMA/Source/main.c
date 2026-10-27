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

#define SPI_NSS_PIN   DDL_GPIO_PIN_6
#define SPI_NSS_PORT  GPIOC
#define SPI_NSS_AF    DDL_GPIO_AF_2

#define SPI_CLK_PIN   DDL_GPIO_PIN_5
#define SPI_CLK_PORT  GPIOC
#define SPI_CLK_AF    DDL_GPIO_AF_2

#define SPI_MOSI_PIN  DDL_GPIO_PIN_11
#define SPI_MOSI_PORT GPIOC
#define SPI_MOSI_AF   DDL_GPIO_AF_1

#define SPI_MISO_PIN  DDL_GPIO_PIN_10
#define SPI_MISO_PORT GPIOC
#define SPI_MISO_AF   DDL_GPIO_AF_2

#define SPI_BUF_LENGTH 20
/* Private typedef ********************************************************/

/* Private variables ******************************************************/
#if defined (IS_SPI_MASTER)
uint8_t spi_txBuffer[SPI_BUF_LENGTH] = "Hello slave \n";
#else
uint8_t spi_txBuffer[SPI_BUF_LENGTH] = "Hello master\n";
#endif

SECTION_DTCM_DATA
uint8_t spi_rxBuffer[SPI_BUF_LENGTH] = {0};

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void GPIO_Config(void);
void SPI_Config(void);
void DMA_Config(void);
void Delay(uint32_t count);

/* External variables *****************************************************/

/* External functions *****************************************************/

/**
 * @brief   Main program
 * @param   None
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

    /* GPIO Configuration */
    GPIO_Config();

    /* SPI Configuration */
    SPI_Config();

    /* DMA Configuration */
    DMA_Config();

    /* Infinite loop */
    while (1)
    {
        for (uint8_t Index = 0; Index < 14; Index++)
        {

            /* Wait until SPI TX buffer is empty */
            while (!DDL_SPI_IsActiveFlag_TXE(SPI1))
            {
                /* Optionally, add a timeout mechanism here */
            }

            /* Write to SPI data register */
            DDL_SPI_TransmitData8(SPI1, spi_txBuffer[Index]);
        }

        /* Waitting the end of data transfer*/
        while(DDL_DMA_IsActiveFlag_TC7(DMA1) == RESET);
        DDL_DMA_ClearFlag_TC7(DMA1);

        /* Output the received data */
        printf("Received Data: ");
        printf("%s ", spi_rxBuffer);

#if defined(IS_SPI_MASTER)
        Delay(0x60000);
#endif
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
 * @brief   GPIO Configuration
 * @param   None
 * @retval  None
 */
void GPIO_Config(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    GPIO_InitStruct.Mode = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;

    /* NSS Configuration */
    GPIO_InitStruct.Pin = SPI_NSS_PIN;
    GPIO_InitStruct.Alternate = SPI_NSS_AF;
    DDL_GPIO_Init(SPI_NSS_PORT, &GPIO_InitStruct);

    /* CLK Configuration */
    GPIO_InitStruct.Pin = SPI_CLK_PIN;
    GPIO_InitStruct.Alternate = SPI_CLK_AF;
    DDL_GPIO_Init(SPI_CLK_PORT, &GPIO_InitStruct);

    /* MOSI Configuration */
    GPIO_InitStruct.Pin = SPI_MOSI_PIN;
    GPIO_InitStruct.Alternate = SPI_MOSI_AF;
    DDL_GPIO_Init(SPI_MOSI_PORT, &GPIO_InitStruct);

    /* MISO Configuration */
    GPIO_InitStruct.Pin = SPI_MISO_PIN;
    GPIO_InitStruct.Alternate = SPI_MISO_AF;
    DDL_GPIO_Init(SPI_MISO_PORT, &GPIO_InitStruct);
}

/**
 * @brief   SPI Configuration
 * @param   None
 * @retval  None
 */
void SPI_Config(void)
{
    DDL_SPI_InitTypeDef SPI_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_SPI);
    DDL_RCM_Lock();

#if defined (IS_SPI_MASTER)
    SPI_InitStruct.TransferDirection = DDL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = DDL_SPI_MODE_MASTER;
    SPI_InitStruct.DataWidth = DDL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.ClockPolarity = DDL_SPI_POLARITY_LOW;
    SPI_InitStruct.ClockPhase = DDL_SPI_PHASE_1EDGE;
    SPI_InitStruct.NSS = DDL_SPI_NSS_HARD_OUTPUT;
    SPI_InitStruct.BaudRate = DDL_SPI_BAUDRATEPRESCALER_DIV256;
    SPI_InitStruct.BitOrder = DDL_SPI_MSB_FIRST;
    SPI_InitStruct.CRCCalculation = DDL_SPI_CRCCALCULATION_DISABLE;
#else
    SPI_InitStruct.TransferDirection = DDL_SPI_FULL_DUPLEX;
    SPI_InitStruct.Mode = DDL_SPI_MODE_SLAVE;
    SPI_InitStruct.DataWidth = DDL_SPI_DATAWIDTH_8BIT;
    SPI_InitStruct.ClockPolarity = DDL_SPI_POLARITY_LOW;
    SPI_InitStruct.ClockPhase = DDL_SPI_PHASE_1EDGE;
    SPI_InitStruct.NSS = DDL_SPI_NSS_HARD_INPUT;
    SPI_InitStruct.BaudRate = DDL_SPI_BAUDRATEPRESCALER_DIV256;
    SPI_InitStruct.BitOrder = DDL_SPI_MSB_FIRST;
    SPI_InitStruct.CRCCalculation = DDL_SPI_CRCCALCULATION_DISABLE;
#endif

    DDL_SPI_Init(SPI1, &SPI_InitStruct);
    DDL_SPI_DisableCRC(SPI1);

    DDL_SPI_EnableDMAReq_RX(SPI1);

    DDL_SPI_Enable(SPI1);
}

/**
 * @brief   DMA Configuration
 * @param   None
 * @retval  None
 */
void DMA_Config(void)
{
    DDL_DMA_InitTypeDef DMA_InitStruct = {0};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_DMA);
    DDL_RCM_Lock();

    DMA_InitStruct.PeriphOrM2MSrcAddress = (uint32_t)&(SPI1->DATA);
    DMA_InitStruct.MemoryOrM2MDstAddress = (uint32_t)spi_rxBuffer;
    DMA_InitStruct.Direction = DDL_DMA_DIRECTION_PERIPH_TO_MEMORY;
    DMA_InitStruct.Mode = DDL_DMA_MODE_CIRCULAR;
    DMA_InitStruct.PeriphOrM2MSrcIncMode = DDL_DMA_PERIPH_NOINCREMENT;
    DMA_InitStruct.MemoryOrM2MDstIncMode = DDL_DMA_MEMORY_INCREMENT;
    DMA_InitStruct.PeriphOrM2MSrcDataSize = DDL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.MemoryOrM2MDstDataSize = DDL_DMA_PDATAALIGN_BYTE;
    DMA_InitStruct.NbData = 14;
    DMA_InitStruct.Channel = DDL_DMA_CHANNEL_2;
    DMA_InitStruct.Priority = DDL_DMA_PRIORITY_LOW;
    DMA_InitStruct.FIFOMode = DDL_DMA_FIFOMODE_DISABLE;
    DMA_InitStruct.FIFOThreshold = DDL_DMA_FIFOTHRESHOLD_1_4;
    DMA_InitStruct.MemBurst = DDL_DMA_MBURST_SINGLE;
    DMA_InitStruct.PeriphBurst = DDL_DMA_PBURST_SINGLE;

    DDL_DMA_Init(DMA1, DDL_DMA_STREAM_7, &DMA_InitStruct);

    DDL_DMA_EnableStream(DMA1, DDL_DMA_STREAM_7);
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
