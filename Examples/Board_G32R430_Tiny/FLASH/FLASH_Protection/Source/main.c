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

#define FLASH_PROTECTION_PAGE  (DDL_FLASH_SECTOR_32_63)
#define FLASH_PAGE_WRITE
#define FLASH_WRITE_PROTECTION
//#define FLASH_DISABLE_PROTECTION

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);

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
    /* Variable used to return status of flash operation */
    ErrorStatus status;

    /* FLASH option byte init structure */
    DDL_FLASH_OPT_InitTypeDef FLASH_OPT_InitStruct = {0U};

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

    /* Unlock RCM */
    DDL_RCM_Unlock();
    /* Enable the flash peripheral clock */
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_FLASH);
    /* Lock RCM */
    DDL_RCM_Lock();

    /* Initialize the structure */
    FLASH_OPT_InitStruct.readProtectionLevel = DDL_FLASH_READ_PROTECTION_LEVEL_0;
    FLASH_OPT_InitStruct.iwdtSoftwareEnable = DDL_FLASH_IWDT_ENABLE_SOFTWARE;
    FLASH_OPT_InitStruct.wwdtSoftwareEnable = DDL_FLASH_WWDT_ENABLE_SOFTWARE;
    FLASH_OPT_InitStruct.nmiEnable = DDL_FLASH_NMI_DISABLE;
    FLASH_OPT_InitStruct.adcTrim = DDL_FLASH_ADC_TRIM_HARDWARE;
    FLASH_OPT_InitStruct.bootAddr = 0x4000;

    /* Clear all flash flags */
    DDL_FLASH_ClearFlag_All();

    /* Unlock the option byte block access */
    DDL_FLASH_OPT_UnLock();

#ifdef FLASH_WRITE_PROTECTION
    /* check whether pages need write protection */
    if (DDL_FLASH_GetWriteProtectionEnableBitInOptionByte() != DDL_FLASH_WRITE_PROTECTION_ENABLE)
    {
        printf("Enable write protection!\r\n");

        /* set write protection */
        FLASH_OPT_InitStruct.writeProtectionEnable = DDL_FLASH_WRITE_PROTECTION_ENABLE;
        FLASH_OPT_InitStruct.writeProtectionSectors = FLASH_PROTECTION_PAGE;
        DDL_FLASH_OptionByteProgram(&FLASH_OPT_InitStruct);
    }
    else
    {
        printf("Write protection already enabled!\r\n");
    }

#elif defined FLASH_DISABLE_PROTECTION
    /* check whether pages need close write protection */
    if (DDL_FLASH_GetWriteProtectionEnableBitInOptionByte() != DDL_FLASH_WRITE_PROTECTION_DISABLE)
    {
        printf("Disable write protection!\r\n");

        /* set write protection for pages which don't close */
        FLASH_OPT_InitStruct.writeProtectionEnable = DDL_FLASH_WRITE_PROTECTION_DISABLE;
        FLASH_OPT_InitStruct.writeProtectionSectors = DDL_FLASH_SECTOR_NONE;
        DDL_FLASH_OptionByteProgram(&FLASH_OPT_InitStruct);
    }
    else
    {
        printf("Write protection already disabled!\r\n");
    }

#endif
    /* Lock the option byte block access */
    DDL_FLASH_OPT_Lock();

#ifdef FLASH_PAGE_WRITE

    /* Clear all flash flags */
    DDL_FLASH_ClearFlag_All();

    /* Unlock the main flash area for erase/program operations */
    DDL_FLASH_MAIN_UnLock();

    /* erase flash page */
    status = DDL_FLASH_EraseMain(FLASH_DDL_CHIP_ERASE_TYPE_BLOCK, 0x08004000);

    /* Lock the main flash area to prevent unintended modifications */
    DDL_FLASH_MAIN_Lock();

    /* check whether it is write protection error */
    if (status == ERROR)
    {
        /* If the status is ERROR, it indicates that the flash operation failed due to write protection */
        printf("Erase flash ERROR!\r\n");
    }
    else
    {
        printf("Erase flash SUCCESSFUL!\r\n");

        /* write page */
        uint32_t data = 0x12345678;
        /* Unlock the main flash area for erase/program operations */
        DDL_FLASH_MAIN_UnLock();
        status = DDL_FLASH_MainProgram(0x08004000, &data, 1);
        /* Lock the main flash area to prevent unintended modifications */
        DDL_FLASH_MAIN_Lock();
        /* check whether writing successful */
        if (status == SUCCESS)
        {
            printf("WRITE flash SUCCESSFUL!\r\n");
        }
        else
        {
            printf("WRITE flash ERROR!\r\n");
        }
    }
#endif

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
