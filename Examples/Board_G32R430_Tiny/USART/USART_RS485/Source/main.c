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
#define DATA_BUF_SIZE       (100)

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
/** USART Init */
void USART_Init(void);
/** Delay */
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
    char rxBuffer[DATA_BUF_SIZE] = {0};
    char txPrompt[] = "Please enter the content to send:\r\n";
    char txResponse[DATA_BUF_SIZE * 2];

    /* Configure system clock */
    DDL_SysClkConfig();

    /* Initialize USART */
    USART_Init();

    while (1)
    {
        /* Send prompt message via USART1 */
        for (int i = 0; txPrompt[i] != '\0'; i++)
        {
            /* Wait until the transmit buffer is empty */
            while (DDL_USART_IsActiveFlag_TXE(USART1) == RESET);
            /* Transmit one character */
            DDL_USART_TransmitData8(USART1, txPrompt[i]);
            /* Wait for the transmission to complete */
            while (DDL_USART_IsActiveFlag_TC(USART1) == RESET);
        }

        /* Receive data from RS485 bus */
        int index = 0;
        while (index < DATA_BUF_SIZE - 1)
        {
            /* Wait until data is received */
            while (DDL_USART_IsActiveFlag_RXNE(USART1) == RESET);
            /* Read the received character */
            rxBuffer[index] = DDL_USART_ReceiveData8(USART1);

            /* Check for end of input (e.g., newline character) */
            if (rxBuffer[index] == '\n')
            {
                break;
            }

            index++;
        }
        /* Null-terminate the received string */
        rxBuffer[index+1] = '\0';

        /* Prepare the response message */
        snprintf(txResponse, sizeof(txResponse), "Received content is: %s\r\n", rxBuffer);

        /* Send the response message via USART1 */
        for (int i = 0; txResponse[i] != '\0'; i++)
        {
            /* Wait until the transmit buffer is empty */
            while (DDL_USART_IsActiveFlag_TXE(USART1) == RESET);
            /* Transmit one character */
            DDL_USART_TransmitData8(USART1, txResponse[i]);
            /* Wait for the transmission to complete */
            while (DDL_USART_IsActiveFlag_TC(USART1) == RESET);
        }
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
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /* USART1 GPIO Config USART1_RX(PB6) USART1_TX(PB9)*/
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_6 | DDL_GPIO_PIN_9;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Set PB6 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOB, DDL_GPIO_PIN_6, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 
    
    /* USART1_DE(PB11)*/
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_11;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_UP;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART1 Config */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    DDL_USART_Init(USART1, &USART_InitStruct);

    /* RS485 DE Mode Configuration */
    /* Calculation for DE deassertion time (DEDT): */
    /* DEDT time = DEDT value * (bit time / oversampling rate) */
    /* Bit time = 1 / Baud rate */
    /* Oversampling rate = 16 (DDL_USART_OVERSAMPLING_16) */
    /* Assuming Baud rate = 115200: */
    /* Bit time = 1 / 115200 ≈ 8.68 us */
    /* DEDT time = 16 * (8.68 us / 16) = 8.68 us */
    DDL_USART_SetDEDeassertionTime(USART1, 0x10);

    /* Calculation for DE assertion time (DEAT): */
    /* DEAT time = 16 * (8.68 us / 16) = 8.68 us */
    DDL_USART_SetDEAssertionTime(USART1, 0x10);

    /* Enable USART DE Mode */
    DDL_USART_EnableDEMode(USART1);

    /* USART Enable */
    DDL_USART_Enable(USART1);
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
    while(delay--)
    {
        __NOP();
    }
}
