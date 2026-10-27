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
#include <math.h>

/* Private macro **********************************************************/
#define DEBUG_USART COM2_PORT

/* Private typedef ********************************************************/
#define q30_to_double(q30)  (((double)(q30))/1073741824.0)
#define q31_to_double(q31)  (((double)(q31))/2147483648.0)

#define double_to_q30(x)    ((int32_t)((x)*1073741824.0))

#define PI  (double)(3.1415926535897932384626433832795)
#define PI_RECIP (double)(1.0 / 3.1415926535897932384626433832795)

/* Optimized structure for ATAN2 comparison results */
typedef struct {
    double projected_value;     /* Output from custom ATAN2 (angle) as floating-point */
    double reference_value;     /* Reference atan2(angle) as floating-point */
    double error_abs;           /* Absolute error between two angles */
    uint32_t cde_time_cycles;   /* Cycles for custom ATAN2 (hardware-based CDE) */
    uint32_t ref_time_cycles;   /* Cycles for reference atan2 */
    int32_t time_delta;         /* Difference: ref_time - cde_time (cycles) */
} Atan2CompareResult;


/* Private variables ******************************************************/
volatile Atan2CompareResult results[10] = {0};

/* Private function prototypes ********************************************/
void DDL_SysClkConfig(void);

/* External variables *****************************************************/

/* External functions *****************************************************/
void RunArctan2Comparison (void);

/**
 * @brief   Main program
 *
 * @param   None
 *
 * @retval  None
 */
int main(void)
{
    /* USART init structure */
    DDL_USART_InitTypeDef USART_InitStruct = {0U};

    /* Configure system clock */
    DDL_SysClkConfig();

    /* Enable I-Cache and D-Cache */
    SCB_InvalidateDCache();
    SCB_InvalidateICache();
    SCB_EnableDCache();
    SCB_EnableICache();
    __DSB();
    __ISB();

    /* USART Init */
    USART_InitStruct.BaudRate            = 115200U;
    USART_InitStruct.DataWidth           = DDL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = DDL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = DDL_USART_PARITY_NONE ;
    USART_InitStruct.TransferDirection   = DDL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = DDL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = DDL_USART_OVERSAMPLING_16;
    BOARD_COMInit(COM2, &USART_InitStruct);

    /* Run ATAN2 comparison tests */
    RunArctan2Comparison();

    for(uint8_t i = 0; i< 10; i++)
    {
        printf("Test %d:\n", i);
        printf("  Reference ATAN2:       %.10f\n", results[i].reference_value);
        printf("  Custom ATAN2 (CDE):    %.10f\n", results[i].projected_value);
        printf("  Absolute Error:        %.10f\n", results[i].error_abs);
        printf("  Reference Time (cyc):  %d\n", results[i].ref_time_cycles);
        printf("  Custom Time (cyc):     %d\n", results[i].cde_time_cycles);
        printf("  Time Delta (cyc):      %d\n\n", results[i].time_delta);
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
 * @brief   Test scenarios for executing the ATAN2 function..
 *
 * @param   None
 *
 * @retval  None
 */
void RunArctan2Comparison(void)
{
    /* Enable CDE */
    SCB->CPACR |= 0xFFFF;
    __ISB();

    int64_t i_x, i_y;
    double fi_float, fq_float, s_float, c_float;
    double local_projected_value, local_reference_value;
    uint32_t temp_ref_time, temp_cde_time;
    int32_t theta_custom;          /* Q31-like angle for custom ATAN2 (returned by ATAN2) */

    /* Iterate across a small set of angle steps around unit circle */
    for (int idx = -5; idx < 5; idx++) 
    {
        /* Generate sample angles on the unit circle */
        double angle_param = PI / 65536.0 * idx * 4.0;
        s_float = sin(angle_param);
        c_float = cos(angle_param);

        /* Convert to fixed-point representation (Q30) as per existing code path */
        i_x = double_to_q30(c_float);
        i_y = double_to_q30(s_float);

        /* Inverse transform back to floating for reference atan2 */
        fi_float = q30_to_double(i_x);
        fq_float = q30_to_double(i_y);

        /* Reference: atan2(y, x) and convert to radians  */
        GET_DWT_CYCLE_COUNT(results[idx + 5].ref_time_cycles,
            results[idx + 5].reference_value = atan2(fq_float, fi_float);
            results[idx + 5].reference_value = results[idx + 5].reference_value * PI_RECIP;);

        /* Custom ATAN2: uses hardware-accelerated CDE path with 6 as precision level */
        GET_DWT_CYCLE_COUNT(results[idx + 5].cde_time_cycles,
            theta_custom = ATAN2(i_x, i_y, 6);
            results[idx + 5].projected_value = q31_to_double(theta_custom);
        );

        /* Compute absolute error between projected and reference values */
        /* Copy volatile data to local variables for well-defined read order */
        local_projected_value  = results[idx + 5].projected_value;
        local_reference_value  = results[idx + 5].reference_value;                               

        /* Calculate absolute error */
        if (local_projected_value > local_reference_value)
        {
            results[idx + 5].error_abs = local_projected_value - local_reference_value;
        } 
        else 
        {
            results[idx + 5].error_abs = local_reference_value - local_projected_value;
        }

        /* Copy timing data to local variables */
        temp_ref_time  = (int32_t)results[idx + 5].ref_time_cycles;
        temp_cde_time  = (int32_t)results[idx + 5].cde_time_cycles;

        /* Compute time delta */
        results[idx + 5].time_delta = temp_ref_time - temp_cde_time;
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
