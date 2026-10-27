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
uint8_t  irqFlag = 0;
uint32_t IC2Value[2] = {0};
float Frequency = 0.0f;

volatile uint32_t tick = 0;

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);
void TMR1_Init(void);
void TMR2_Init(void);
void TMR1_UpdateIsr(void);
void TMR2_CC2Isr(void);
void Delay(void);

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

    /* Initialize TMR */
    TMR1_Init();
    TMR2_Init();

    while (1)
    {
        printf("Frequency: %0.2f Hz\r\n",Frequency);
        Delay();
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
 * @brief     TMR2 Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR2_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_TMR_IC_InitTypeDef TMR_ICInitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR2);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*Config PA1 for TMR2 CH2 */
    /* Note: J10 selects whether PA1 connects to LED1 or the external header. */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_0;
    DDL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* TMR2 PWM Input mode */
    TMR_ICInitStruct.ICPolarity    = DDL_TMR_IC_POLARITY_RISING;
    TMR_ICInitStruct.ICActiveInput = DDL_TMR_ACTIVEINPUT_DIRECTTI;
    TMR_ICInitStruct.ICPrescaler   = DDL_TMR_ICPSC_DIV1;
    TMR_ICInitStruct.ICFilter      = DDL_TMR_IC_FILTER_FDIV1;
    DDL_TMR_IC_Init(TMR2, DDL_TMR_CHANNEL_CH2, &TMR_ICInitStruct);

    /* Enable TMR2 Interrupt */
    DDL_TMR_EnableIT_CC2(TMR2);
    DDL_Interrupt_Register(TMR2_IRQn, TMR2_CC2Isr);
    DDL_NVIC_EnableIRQRequest(TMR2_IRQn, 0, 0);

    /* Enable TMR2 */
    DDL_TMR_EnableCounter(TMR2);
}

/**
 * @brief     TMR2 CC2 Interrupt function
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR2_CC2Isr(void)
{
    uint32_t tempValue = 0;

    /* Get System clock frequncy */
    DDL_RCM_ClocksTypeDef RCM_Clocks;
    DDL_RCM_GetSystemClocksFreq(&RCM_Clocks);

    /* Clear TMR2 Capture compare 2 interrupt pending bit */
    DDL_TMR_ClearFlag_CC2(TMR2);

    /* Get the Input Capture value */
    IC2Value[irqFlag] = DDL_TMR_IC_GetCaptureCH2(TMR2);

    if(irqFlag != 0)
    {
        irqFlag = 0;

        /* Capture computation */
        if(IC2Value[1] > IC2Value[0])
        {
            tempValue = IC2Value[1] - IC2Value[0];
        }
        else if(IC2Value[1] < IC2Value[0])
        {
            /* 0xFFFF is TMR2 16bit Autoreload value */
            tempValue = 0xFFFF - IC2Value[0] + IC2Value[1];
        }
        else
        {
            tempValue = 0;
        }

        if(tempValue != 0)
        {
            /* Frequency computation */
            Frequency = (float)RCM_Clocks.HCLK_Frequency / (float)tempValue;
        }
    }
    else
    {
        irqFlag++;
    }
}

/**
 * @brief     TMR1 Init
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR1_Init(void)
{
    DDL_GPIO_InitTypeDef GPIO_InitStruct = {0U};
    DDL_TMR_InitTypeDef TMR_InitStruct = {0U};
    DDL_TMR_OC_InitTypeDef TMR_OCInitStruct = {0U};

    /* Config Clock */
    DDL_RCM_Unlock();
    DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_TMR1);
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_GPIO);
    DDL_RCM_Lock();

    /*Config PD1 for TMR1 CH1 */
    GPIO_InitStruct.Pin        = DDL_GPIO_PIN_1;
    GPIO_InitStruct.Mode       = DDL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed      = DDL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull       = DDL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate  = DDL_GPIO_AF_1;
    DDL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Config TMR1 */
    /* Frequency Calculation */
    /* 1. Timer input clock frequency = System clock frequency / (Prescaler + 1). */
    /*    Assuming system clock frequency = 120 MHz: */
    /*    Timer frequency = 120 MHz / (11 + 1) = 10 MHz. */
    /* 2. Timer period (T) is determined by the auto-reload value (Autoreload). */
    /*    Timer period = (Autoreload + 1) / Timer frequency. */
    /*    Timer period = (999 + 1) / 10 MHz = 0.1 ms. */
    /* 3. PWM output frequency is the inverse of the timer period. */
    /*    PWM frequency = 1 / Timer period = 1 / 0.1 ms = 10 kHz. */
    TMR_InitStruct.Prescaler         = 11;
    TMR_InitStruct.CounterMode       = DDL_TMR_COUNTERMODE_UP;
    TMR_InitStruct.Autoreload        = 999;
    TMR_InitStruct.ClockDivision     = DDL_TMR_CLOCKDIVISION_DIV1;
    TMR_InitStruct.RepetitionCounter = 0x00000000U;
    DDL_TMR_Init(TMR1, &TMR_InitStruct);

    /* Configure TMR1 PWM Duty Cycle */
    /* Assuming a 50% duty cycle: */
    /* CompareValue = (Autoreload + 1) * DutyCycle / 100 */
    /* CompareValue = (999 + 1) * 50 / 100 = 500 */
    TMR_OCInitStruct.OCMode       = DDL_TMR_OCMODE_PWM1;
    TMR_OCInitStruct.OCState      = DDL_TMR_OCSTATE_ENABLE;
    TMR_OCInitStruct.CompareValue = 500;
    TMR_OCInitStruct.OCPolarity   = DDL_TMR_OCPOLARITY_HIGH;
    DDL_TMR_OC_Init(TMR1, DDL_TMR_CHANNEL_CH1, &TMR_OCInitStruct);

    /* Enable TMR1 Interrupt */
    DDL_TMR_EnableIT_UPDATE(TMR1);
    DDL_Interrupt_Register(TMR1_IRQn, TMR1_UpdateIsr);
    DDL_NVIC_EnableIRQRequest(TMR1_IRQn, 0, 1);

    /* Enable TMR1 */
    DDL_TMR_EnableCounter(TMR1);
    /* Enable all outputs for TMR1 */
    DDL_TMR_EnableAllOutputs(TMR1);
}

/**
 * @brief     TMR1 update Interrupt function
 *
 * @param     None
 *
 * @retval    None
 *
 */
void TMR1_UpdateIsr(void)
{
    if (DDL_TMR_IsActiveFlag_UPDATE(TMR1) == SET)
    {
        tick++;
        DDL_TMR_ClearFlag_UPDATE(TMR1);
    }
}

/*!
 * @brief       Delay
 *
 * @param       None
 *
 * @retval      None
 */
void Delay(void)
{
    tick = 0;
    while(tick < 500)
    {
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
