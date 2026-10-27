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
#define PMU_SR_ADDRESS (0x40003808UL)

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
uint16_t GetWakeupCount(void);
void EVS_Init(void);
void PMU_Init(void);
void EVS_Isr(void);
void PrintPMUSRStatus(const char *title);

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

    /* EVS Init */
    EVS_Init();

    /* PMU Init */
    PMU_Init();

    /* Print Power-Up Message */
    printf("System Power-Up!\r\n");

    
    if(DDL_PMU_IsActiveFlag_EVS())
    {
        printf("Wakeup from EVS!\r\n");
        
        printf("Check DDL_PMU_ClearFlag_Standby impact on PMU_SR.\r\n");
        PrintPMUSRStatus("Before DDL_PMU_ClearFlag_Standby");
        DDL_PMU_ClearFlag_Standby();
        PrintPMUSRStatus("After DDL_PMU_ClearFlag_Standby");

        DDL_PMU_ClearFlag_EVS();

        if(DDL_PMU_IsActiveFlag_EVS())
        {
            printf("EVS Flag Clear Failed!\r\n");
        }
        else
        {
            printf("EVS Flag Cleared!\r\n");
        }
        
        /* Print the current wake-up count */
        printf("Current wake-up count: %d\r\n", GetWakeupCount());
        
        
        
        while (1);
        
        
    }

    printf("Enter Standby Mode!\r\n");

    printf("Please ensure EVS pin (PD15) exceeds 4.6V to wake up the MCU.\r\n");

    DDL_PMU_EnterStandbyModeWFI();

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
    /* Since the system clock is HSI after exiting stop mode, */
    /* the clock here will use the HSI as the main clock during power-up. */
    /* No clock configuration is performed here. */
}

/**
 * @brief     PMU Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void PMU_Init(void)
{
    /* Enable LSI Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP);
    DDL_RCM_DisableBackupWriteProtect();
    DDL_RCM_LSI_Enable();
    while (DDL_RCM_LSI_IsReady() == RESET);

    /* Config PMU */
    DDL_PMU_SetEVSFilter(DDL_PMU_EVS_FILTER_8LSICLK);
    DDL_PMU_SetEVSThreshold(0x01);
    DDL_PMU_EnableEVS();
    DDL_PMU_EnableEVSWakeUp();
}

/**
 * @brief     Get the current wake-up count from the backup domain
 *
 * @param     None
 *
 * @retval    The updated wake-up count
 *
 */
uint16_t GetWakeupCount(void)
{
    uint16_t wakeupCount = 0;

    /* Disable backup write protection to allow modification */
    DDL_RCM_DisableBackupWriteProtect();

    /* Read the current wake-up count from the backup register */
    wakeupCount = DDL_BKP_GetDataBackUp(DDL_BKP_DR0);

    /* Increment the wake-up count */
    wakeupCount++;

    /* Write the updated wake-up count back to the backup register */
    DDL_BKP_SetDataBackUp(DDL_BKP_DR0, wakeupCount);

    /* Enable backup write protection to prevent unintended modifications */
    DDL_RCM_EnableBackupWriteProtect();

    /* Return the updated wake-up count */
    return wakeupCount;
}

/**
 * @brief     Print PMU_SR register and each valid bit state
 *
 * @param     title  Prompt printed before the PMU_SR status
 *
 * @retval    None
 *
 */
void PrintPMUSRStatus(const char *title)
{
    uint32_t pmuSr = *(volatile uint32_t *)PMU_SR_ADDRESS;

    printf("%s\r\n", title);
    printf("PMU_SR(0x%08X) = 0x%08X\r\n", (unsigned int)PMU_SR_ADDRESS, (unsigned int)pmuSr);
    printf("  bit6 PVDO   = %u\r\n", (unsigned int)((pmuSr & PMU_SR_PVDO) >> PMU_SR_PVDO_Pos));
    printf("  bit5 EVSWKF = %u\r\n", (unsigned int)((pmuSr & PMU_SR_EVSWKF) >> PMU_SR_EVSWKF_Pos));
    printf("  bit4 SBF    = %u\r\n", (unsigned int)((pmuSr & PMU_SR_SBF) >> PMU_SR_SBF_Pos));
    printf("  bit3 WKUPF3 = %u\r\n", (unsigned int)((pmuSr & PMU_SR_WKUPF3) >> PMU_SR_WKUPF3_Pos));
    printf("  bit2 WKUPF2 = %u\r\n", (unsigned int)((pmuSr & PMU_SR_WKUPF2) >> PMU_SR_WKUPF2_Pos));
    printf("  bit1 WKUPF1 = %u\r\n", (unsigned int)((pmuSr & PMU_SR_WKUPF1) >> PMU_SR_WKUPF1_Pos));
    printf("  bit0 WKUPF0 = %u\r\n", (unsigned int)((pmuSr & PMU_SR_WKUPF0) >> PMU_SR_WKUPF0_Pos));
}

/**
 * @brief     GPIO Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void EVS_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_EINT_InitTypeDef EINT_InitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_EINT);
    DDL_RCM_Lock();

    /* PD15 Init */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_15;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct); 

    /* PD15 as EVS (SWR supplement V1.1 rule 3): keep SWR at 0 (recommended).
       PD15 is not in the 5VIO SWR=1 table. SWR=1 does not block EVS. */
    DDL_GPIO_SetSpecialPinType(GPIOD, DDL_GPIO_PIN_15, DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT);

    /* Enable EINT1 */
    EINT_InitStruct.Line           = DDL_EINT_LINE_18;
    EINT_InitStruct.LineCommand    = ENABLE;
    EINT_InitStruct.Mode           = DDL_EINT_MODE_IT;
    EINT_InitStruct.Trigger        = DDL_EINT_TRIGGER_RISING_FALLING;
    DDL_EINT_Init(&EINT_InitStruct);

    DDL_Interrupt_Register(EVS_IRQn, EVS_Isr);
    DDL_NVIC_EnableIRQRequest(EVS_IRQn, 0, 0);
}

/**
 * @brief     EINT0 Isr
 *
 * @param     None
 *
 * @retval    None
 *
 */
void EVS_Isr(void)
{
    if (DDL_EINT_ReadFlag(DDL_EINT_LINE_18))
    {
        DDL_EINT_ClearFlag(DDL_EINT_LINE_18);
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
