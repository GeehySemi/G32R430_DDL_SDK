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

/* Waiting TIMEOUT*/
#define I2CT_FLAG_TIMEOUT         ((uint32_t)0x500)
#define I2CT_LONG_TIMEOUT         ((uint32_t)(10 * I2CT_FLAG_TIMEOUT))

#define I2C_SCL_PIN   DDL_GPIO_PIN_5
#define I2C_SCL_PORT  GPIOD
#define I2C_SCL_AF    DDL_GPIO_AF_0

#define I2C_SDA_PIN   DDL_GPIO_PIN_9
#define I2C_SDA_PORT  GPIOD
#define I2C_SDA_AF    DDL_GPIO_AF_0

#define I2C_MASTER_ADDRESS 0x1A
#define I2C_SLAVE_ADDRESS  0x2C

#if defined (IS_I2C_MASTER)
#define I2C_ADDRESS     I2C_MASTER_ADDRESS
#define WRITE_ADDRESS   I2C_SLAVE_ADDRESS
#else
#define I2C_ADDRESS     I2C_SLAVE_ADDRESS
#define WRITE_ADDRESS   I2C_MASTER_ADDRESS
#endif

#define I2C_BUF_LENGTH 20

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
#if defined (IS_I2C_MASTER)
    uint8_t i2cTransmitBuf[I2C_BUF_LENGTH] = "Hello slave \r\n";
#else
    uint8_t i2cTransmitBuf[I2C_BUF_LENGTH] = "Hello master\r\n";
#endif

uint8_t i2cReceiveBuf[I2C_BUF_LENGTH] = {0};
volatile uint32_t receivedNum = 0;
/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void GPIO_Config(void);
void I2C_Config(void);
uint8_t I2C_Transmit_Handler(uint8_t* transmitBuf, uint32_t length);
uint8_t I2C_Receive_Handler(uint8_t* receiveBuf, uint32_t length);
void Delay(uint32_t count);
uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode);

void I2C_IRQ_Handler(void);

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

    /* Initialize GPIO */
    GPIO_Config();
    /* Initialize I2C */
    I2C_Config();
#if defined (IS_I2C_MASTER)
    printf("\r\nI am I2C Master!\r\n");
#else
    printf("\r\nI am I2C Slave!\r\n");
#endif

    /* Infinite loop */
    while (1)
    {
#if defined (IS_I2C_MASTER)
        I2C_Transmit_Handler(i2cTransmitBuf, 14);
#else
        I2C_Receive_Handler(i2cReceiveBuf, 14);
#endif

#if defined (IS_I2C_MASTER)
        I2C_Receive_Handler(i2cReceiveBuf, 14);
#else
        I2C_Transmit_Handler(i2cTransmitBuf, 14);
#endif

        printf("Received Data: %s", (char*)i2cReceiveBuf);

        Delay(0x50000);
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
 * @brief   I2C transmit handler
 * @param   transmitBuf: the point to the transmit buffer
 * @param   length: length limit for the receive buffer
 * @retval  1: success, 0: failed
 */
uint8_t I2C_Transmit_Handler(uint8_t* transmitBuf, uint32_t length)
{
    uint32_t transmitNum = 0;
    uint32_t I2CTimeout = I2CT_LONG_TIMEOUT;

    /* Check if the I2C bus is busy */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (DDL_I2C_IsActiveFlag_BUSY(I2C1))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(1);
    }
    
    DDL_I2C_DisableIT_EVT(I2C1);

    /*  Send START condition */
    DDL_I2C_GenerateStartCondition(I2C1);

    /* Wait for MASTER_MODE_SELECT (EV5) */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_MODE_SELECT))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(2);
    }

    /* Transmit send operation and address */
    DDL_I2C_TransmitData8(I2C1, WRITE_ADDRESS);
    /* Test on EV6 and clear it */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(3);
    }
    
    while (transmitNum < length)
    {
        /* Send the byte to be written */
        DDL_I2C_TransmitData8(I2C1, transmitBuf[transmitNum]);
        /* Test on EV8 and clear it */
        I2CTimeout = I2CT_LONG_TIMEOUT;
        while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        {
            if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(4);
        }
        transmitNum++;
    }

    /* Transmit stop frame */
    DDL_I2C_GenerateStopCondition(I2C1);

    DDL_I2C_EnableIT_EVT(I2C1);

    return 1;
}

/**
 * @brief   I2C receive handler
 * @param   receiveBuf: the point to the receive buffer
 * @param   length: length limit for the receive buffer
 * @retval  1: success, 0: failed
 */
uint8_t I2C_Receive_Handler(uint8_t* receiveBuf, uint32_t length)
{
    DDL_I2C_EnableIT_EVT(I2C1);

    receivedNum = 0;

    while (receivedNum < length)
    {
        __NOP();
    }

    DDL_I2C_DisableIT_EVT(I2C1);
    return 1;
}


/**
 * @brief   I2C receive handler
 * @param   receiveBuf: the point to the receive buffer
 * @param   length: length limit for the receive buffer
 * @retval  The number of characters received
 */
void I2C_IRQ_Handler(void)
{
    if (DDL_I2C_IsActiveFlag_ADDR(I2C1))
    {
        /* Reading STS2  before clears the ADDR flag, even if the ADDR flag was set after reading I2C_STS1 */
        *(__IO uint16_t*)I2C1->STS2;
        DDL_I2C_ClearFlag_ADDR(I2C1);
    }
    
    if (DDL_I2C_IsActiveFlag_RXNE(I2C1))
    {
        i2cReceiveBuf[receivedNum] = DDL_I2C_ReceiveData8(I2C1);
        receivedNum ++;
    }

    if (DDL_I2C_IsActiveFlag_STOP(I2C1))
    {
        DDL_I2C_Enable(I2C1);
    }
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
    GPIO_InitStruct.Pull = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_OPENDRAIN;

    /* SCL Configuration */
    GPIO_InitStruct.Pin = I2C_SCL_PIN;
    GPIO_InitStruct.Alternate = I2C_SCL_AF;
    DDL_GPIO_Init(I2C_SCL_PORT, &GPIO_InitStruct);

    /* Set PD5 mode to digital tolerant input */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_5, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT); 

    /* SDA Configuration */
    GPIO_InitStruct.Pin = I2C_SDA_PIN;
    GPIO_InitStruct.Alternate = I2C_SDA_AF;
    DDL_GPIO_Init(I2C_SDA_PORT, &GPIO_InitStruct);
}

/**
 * @brief   I2C Configuration
 * @param   None
 * @retval  None
 */
void I2C_Config(void)
{
    DDL_I2C_InitTypeDef I2C_InitStruct = {0U};

    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_I2C);
    DDL_RCM_Lock();

    I2C_InitStruct.PeripheralMode = DDL_I2C_MODE_I2C;
    I2C_InitStruct.ClockSpeed = 100000;
    I2C_InitStruct.DutyCycle = DDL_I2C_DUTYCYCLE_2;
    I2C_InitStruct.OwnAddress1 = I2C_ADDRESS;
    I2C_InitStruct.TypeAcknowledge = DDL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = DDL_I2C_OWNADDRESS1_7BIT;

    DDL_I2C_Init(I2C1, &I2C_InitStruct);
    DDL_Interrupt_Register(I2C_IRQn, I2C_IRQ_Handler);

    DDL_NVIC_EnableIRQRequest(I2C_IRQn, 0, 0);

    DDL_I2C_Enable(I2C1);
}

/**
 * @brief     Used to locate the wrong location of the
 *            I2C_Transmit_Handler()
 * @param     errorCode
 * @retval    Error code location information
 */
uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode)
{
    printf("I2C Wait TIMEOUT! errorCode = %d\r\n", errorCode);
    return 0;
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
