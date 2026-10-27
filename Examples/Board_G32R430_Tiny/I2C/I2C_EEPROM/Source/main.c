/**
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.2
 *
 * @date        2026-08-16
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

#define IS_I2C_MASTER

#define I2C_SCL_PIN   DDL_GPIO_PIN_5
#define I2C_SCL_PORT  GPIOD
#define I2C_SCL_AF    DDL_GPIO_AF_0

#define I2C_SDA_PIN   DDL_GPIO_PIN_9
#define I2C_SDA_PORT  GPIOD
#define I2C_SDA_AF    DDL_GPIO_AF_0

#define I2C_MASTER_ADDRESS 0x1A

/* Tiny onboard ZD24C64A: 64-Kbit, 2-byte word address, 32-byte page. */
#define __24C64

/* change it if eeprom address different */
#define EEPROM_ADDRESS      0xA0
#define EEPROM_PAGE_SIZE    32
#define I2C_BUF_LENGTH      32 /* <= EEPROM_PAGE_SIZE */

/* Private typedef ********************************************************/

/* Private variables ******************************************************/
uint8_t i2cTransmitBuf[I2C_BUF_LENGTH] = {0};
uint8_t i2cReceiveBuf[I2C_BUF_LENGTH] = {0};
uint8_t i2cReceiveData = 0;

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void GPIO_Config(void);
void I2C_Config(void);
uint8_t I2C_EEPROM_WritePage(uint8_t* buffer, uint16_t address, uint8_t length);
uint8_t I2C_EEPROM_ReadPage(uint8_t* buffer, uint16_t address, uint8_t length);
uint8_t IsBufferEqual(uint8_t* buffer1, uint8_t* buffer2, uint32_t length);
uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode);
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

    /* Initialize GPIO */
    GPIO_Config();
    /* Initialize I2C */
    I2C_Config();

    /* Initialize LEDs */
    /* Note: J10 selects whether PA1/PA2 connect to LED1/LED2 or the external header. */
    BOARD_LEDInit(LED1);
    BOARD_LEDInit(LED2);

    /* Turn off LEDs */
    BOARD_LEDOff(LED1);
    BOARD_LEDOff(LED2);

    for (uint8_t i = 0; i < I2C_BUF_LENGTH; i++)
    {
        i2cTransmitBuf[i] = i;
        i2cReceiveBuf[i] = 0;
    }

    /* WritePage waits EEPROM tWR via ACK poll after STOP (no fixed Delay). */
    if (I2C_EEPROM_WritePage(i2cTransmitBuf, 0x0000, I2C_BUF_LENGTH) == 0U)
    {
        BOARD_LEDOn(LED1);
        printf("I2C EEPROM Write Failed (ACK/tWR poll timeout)!\r\n");
    }
    else if (I2C_EEPROM_ReadPage(i2cReceiveBuf, 0x0000, I2C_BUF_LENGTH) == 0U)
    {
        BOARD_LEDOn(LED1);
        printf("I2C EEPROM Read Failed!\r\n");
    }
    else if (IsBufferEqual(i2cTransmitBuf, i2cReceiveBuf, I2C_BUF_LENGTH) != 0U)
    {
        BOARD_LEDOn(LED2);
        printf("I2C EEPROM Read/Write Success!\r\n");
    }
    else
    {
        BOARD_LEDOn(LED1);
        printf("I2C EEPROM Read/Write Failed!\r\n");
    }
    /* Infinite loop */
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
    DDL_RCM_SetAHBPrescaler(DDL_RCM_AHB_DIV_2);
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

    /* Enable I2C clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_I2C);
    DDL_RCM_Lock();

    I2C_InitStruct.PeripheralMode = DDL_I2C_MODE_I2C;
    I2C_InitStruct.ClockSpeed = 400000;
    I2C_InitStruct.DutyCycle = DDL_I2C_DUTYCYCLE_2;
    I2C_InitStruct.OwnAddress1 = I2C_MASTER_ADDRESS;
    I2C_InitStruct.TypeAcknowledge = DDL_I2C_ACK;
    I2C_InitStruct.OwnAddrSize = DDL_I2C_OWNADDRESS1_7BIT;
    DDL_I2C_Init(I2C1, &I2C_InitStruct);

    /* Enable I2C */
    DDL_I2C_Enable(I2C1);
}

/**
 * @brief   I2C write one byte data to EEPROM
 * @param   buffer: a set of data to be written
 * @param   address: address to be written into EEPROM for data
 * @param   length: the length of data to be written
 * @retval  1: success, 0: failed
 */
uint8_t I2C_EEPROM_WritePage(uint8_t* buffer, uint16_t address, uint8_t length)
{
    uint8_t writeNum = 0;
    uint32_t I2CTimeout = I2CT_LONG_TIMEOUT;

    /* Generate I2C START condition */
    DDL_I2C_GenerateStartCondition(I2C1);

    /* Wait for EV5: Start condition generated */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_MODE_SELECT))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(0);
    }

    /* Send EEPROM device address for write operation */
    DDL_I2C_TransmitData8(I2C1, (0x00 | EEPROM_ADDRESS));

    /* Wait for EV6: Master transmitter mode selected */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(1);
    }

#ifdef __24C64
    /* Send EEPROM internal memory address (High Byte, A12..A8) */
    DDL_I2C_TransmitData8(I2C1, (uint8_t)((address >> 8) & 0x1F));

    /* Wait for EV8_2: Byte transmission finished */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(2);
    }
#endif

    /* Send EEPROM internal memory address (Low Byte) */
    DDL_I2C_TransmitData8(I2C1, (uint8_t)address);

    /* Wait for EV8_2: Byte transmission finished */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(3);
    }

    /* Loop to write data bytes */
    while (writeNum < length)
    {
        /* Send the data byte */
        DDL_I2C_TransmitData8(I2C1, buffer[writeNum]);

        /* Wait for EV8_2: Byte transmission finished */
        I2CTimeout = I2CT_LONG_TIMEOUT;
        while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTED))
        {
            if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(4);
        }
        writeNum++;
    }

    /* Generate I2C STOP condition */
    DDL_I2C_GenerateStopCondition(I2C1);

    /* Wait EEPROM internal write cycle (tWR): device NACKs address while busy. */
    {
        uint32_t poll;

        for (poll = 0U; poll < 1000U; poll++)
        {
            Delay(0x2000);
            DDL_I2C_GenerateStartCondition(I2C1);
            I2CTimeout = I2CT_FLAG_TIMEOUT;
            while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_MODE_SELECT))
            {
                if ((I2CTimeout--) == 0U)
                {
                    break;
                }
            }

            DDL_I2C_TransmitData8(I2C1, (EEPROM_ADDRESS & 0xFE));
            I2CTimeout = I2CT_FLAG_TIMEOUT;
            while (I2CTimeout-- != 0U)
            {
                if (DDL_I2C_IsActiveFlag_ADDR(I2C1))
                {
                    DDL_I2C_ClearFlag_ADDR(I2C1);
                    DDL_I2C_GenerateStopCondition(I2C1);
                    return 1U;
                }
                if (DDL_I2C_IsActiveFlag_AF(I2C1))
                {
                    DDL_I2C_ClearFlag_AF(I2C1);
                    DDL_I2C_GenerateStopCondition(I2C1);
                    break;
                }
            }
            DDL_I2C_GenerateStopCondition(I2C1);
        }
    }

    /* ACK poll timed out: internal write may still be busy. */
    return 0U;
}

/**
 * @brief   I2C read one byte data from EEPROM
 * @param   address: address to be read into EEPROM for data
 * @param   address: address to be read into EEPROM for data
 * @retval  1: success, 0: failed
 */
uint8_t I2C_EEPROM_ReadPage(uint8_t* buffer, uint16_t address, uint8_t length)
{
    uint32_t I2CTimeout = I2CT_LONG_TIMEOUT;

    /* Wait until I2C bus is not busy */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (DDL_I2C_IsActiveFlag_BUSY(I2C1))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(5);
    }

    /* Generate I2C START condition */
    DDL_I2C_GenerateStartCondition(I2C1);

    /* Wait for EV5: Start condition generated */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_MODE_SELECT))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(6);
    }

    /* Send EEPROM device address for write operation (Dummy Write) */
    DDL_I2C_TransmitData8(I2C1, (EEPROM_ADDRESS & 0xFE));

    /* Wait for EV6: Master transmitter mode selected */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(7);
    }

#ifdef __24C64
    /* Send EEPROM internal memory address (High Byte, A12..A8) */
    DDL_I2C_TransmitData8(I2C1, (uint8_t)((address >> 8) & 0x1F));

    /* Wait for EV8_2: Byte transmission finished */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(8);
    }
#endif

    /* Send EEPROM internal memory address (Low Byte) */
    DDL_I2C_TransmitData8(I2C1, (uint8_t)address);

    /* Wait for EV8: Byte transmitting (ensure address sent before Re-Start) */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_TRANSMITTING))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(3);
    }

    /* Generate I2C Re-START condition */
    DDL_I2C_GenerateStartCondition(I2C1);

    /* Wait for EV5: Start condition generated */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_MODE_SELECT))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(9);
    }

    /* Send EEPROM device address for read operation */
    DDL_I2C_TransmitData8(I2C1, (EEPROM_ADDRESS | 0x01));

    /* Wait for EV6: Master receiver mode selected */
    I2CTimeout = I2CT_LONG_TIMEOUT;
    while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
    {
        if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(10);
    }

    /* Loop to read data bytes */
    while (length > 0U)
    {
        /* Check if this is the last byte */
        if (length == 1U)
        {
            /* Disable ACK for the last byte */
            DDL_I2C_AcknowledgeNextData(I2C1, DDL_I2C_NACK);

            /* Generate STOP condition */
            DDL_I2C_GenerateStopCondition(I2C1);
        }
        else
        {
            /* Enable ACK for the next byte */
            DDL_I2C_AcknowledgeNextData(I2C1, DDL_I2C_ACK);
        }

        /* Wait for EV7: Byte received */
        I2CTimeout = I2CT_LONG_TIMEOUT;
        while (!DDL_I2C_ReadEventStatus(I2C1, DDL_I2C_EVENT_MASTER_BYTE_RECEIVED))
        {
            if ((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(11);
        }

        /* Read the received data from DATA */
        *buffer = DDL_I2C_ReceiveData8(I2C1);

        /* Move the buffer pointer */
        buffer++;

        /* Decrement the read bytes counter */
        length--;
    }

    /* Re-enable ACK for subsequent operations */
    DDL_I2C_AcknowledgeNextData(I2C1, DDL_I2C_ACK);

    return 1;
}

/**
 * @brief   Compare whether two buffers ara equal
 * @param   buffer1: To be compared buffer1
 * @param   buffer2: To be compared buffer2
 * @param   length: comparative length
 * @retval  The state of compare results (1 or 0)
 */
uint8_t IsBufferEqual(uint8_t* buffer1, uint8_t* buffer2, uint32_t length)
{
    uint32_t offset = 0;
    while (offset < length)
    {
        if (buffer1[offset] != buffer2[offset])
        {
            return 0;
        }
        offset++;
    }

    return 1;
}

/**
 * @brief       Delay
 * @param       count:  delay count
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

/**
 * @brief     Used to locate the wrong location of the
 *            I2C_Write()
 * @param     errorCode
 * @retval    Error code location information
 */
uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode)
{
    printf("I2C Wait TIMEOUT! errorCode = %d\r\n", errorCode);
    return 0;
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