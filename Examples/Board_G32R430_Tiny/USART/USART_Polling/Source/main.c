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
#define DATA_BUF_SIZE       (32)

/* Private typedef ********************************************************/
typedef enum {FALSE, TRUE} BOOL;

/* Private variables ******************************************************/
/** USART1 receive buffer*/
uint8_t rxDataBufUSART1[DATA_BUF_SIZE] = {0};
/** USART1 transmit buffer*/
uint8_t txDataBufUSART1[DATA_BUF_SIZE] = {0};

/** USART2 receive buffer*/
uint8_t rxDataBufUSART2[DATA_BUF_SIZE] = {0};
/** USART2 transmit buffer*/
uint8_t txDataBufUSART2[DATA_BUF_SIZE] = {0};

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
/** USART Init */
void USART_Init(void);
/** Delay */
void Delay(uint32_t count);
/** Buffer compare*/
BOOL BufferCompare(uint8_t *buf1, uint8_t *buf2, uint8_t size);

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
    BOOL state = TRUE;

    /* Configure system clock */
    DDL_SysClkConfig();

    /* Init txDataBufUSARTx */
    for(int i = 0; i < DATA_BUF_SIZE; i++)
    {
        txDataBufUSART1[i] = i+1;
        rxDataBufUSART1[i] = 0;

        txDataBufUSART2[i] = i+2;
        rxDataBufUSART2[i] = 0;
    }

    /* LED1/LED2 Init */
    /* Note: J10 selects whether PA1/PA2 connect to LED1/LED2 or the external header. */
    BOARD_LEDInit(LED1);
    BOARD_LEDInit(LED2);

    /* Turn off LED1/LED2 */
    BOARD_LEDOff(LED1);
    BOARD_LEDOff(LED2);

    USART_Init();

    /* Send Data from USART1 to USART2 */
    for(int i = 0; i < DATA_BUF_SIZE; i++)
    {
        /* Wait until end of transmission */
        while( DDL_USART_IsActiveFlag_TXE(USART1) == RESET);
        DDL_USART_TransmitData8(USART1, txDataBufUSART1[i]);

        /* Wait until end of reception */
        while( DDL_USART_IsActiveFlag_RXNE(USART2) == RESET);
        rxDataBufUSART2[i] = DDL_USART_ReceiveData8(USART2);
    }

     /* Verify data */
    state = BufferCompare(rxDataBufUSART2, txDataBufUSART1, DATA_BUF_SIZE);

    if(state == TRUE)
    {
        /* Turn on LED1 */
        BOARD_LEDOn(LED1);
    }

    /* Send Data from USART2 to USART1 */
    for(int i = 0; i < DATA_BUF_SIZE; i++)
    {
        /* Wait until end of transmission */
        while(DDL_USART_IsActiveFlag_TXE(USART2) == RESET);
        DDL_USART_TransmitData8(USART2, txDataBufUSART2[i]);

        /* Wait until end of reception */
        while(DDL_USART_IsActiveFlag_RXNE(USART1) == RESET);
        rxDataBufUSART1[i] = DDL_USART_ReceiveData8(USART1);
    }

     /* Verify data */
    state = BufferCompare(rxDataBufUSART1, txDataBufUSART2, DATA_BUF_SIZE);

    if(state == TRUE)
    {
        /* Turn on LED2 */
        BOARD_LEDOn(LED2);
    }

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
 * @brief       USARTS Initialization
 *
 * @param       None
 *
 * @retval      None
 */
void USART_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_USART_InitTypeDef USART_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_USART1);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_USART2);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /* USART1 GPIO Config */
    /* USART1_TX PD15 AF0 */
    /* USART1_RX PD12 AF0 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_12 | DDL_GPIO_PIN_15;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Set PD12 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_12, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_15, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT);

    /* USART1 Config */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    DDL_USART_Init(USART1, &USART_InitStruct);

    /* USART2 GPIO Config */
    /* USART2_TX PD0 AF0 */
    /* USART2_RX PC12 AF0 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_0 ;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_12;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* Set PC12 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOC, DDL_GPIO_PIN_12, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 

    /* USART2 Config*/
    DDL_USART_Init(USART2, &USART_InitStruct);

    /* USART Enable */
    DDL_USART_Enable(USART1);
    DDL_USART_Enable(USART2);
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

/*!
 * @brief       Compares two buffers
 *
 * @param       buf1:    First buffer to be compared
 *
 * @param       buf1:    Second buffer to be compared
 *
 * @param       size:    Buffer size
 *
 * @retval      Return SET if buf1 = buf2. If not then return RESET
 */
BOOL BufferCompare(uint8_t *buf1, uint8_t *buf2, uint8_t size)
{
    uint8_t i;

    for(i = 0; i < size; i++)
    {
        if(buf1[i] != buf2[i])
        {
            return FALSE;
        }
    }

    return TRUE;
}

