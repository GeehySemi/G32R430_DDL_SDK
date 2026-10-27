/**
  *
  * @file    g32r4xx_ddl_rcm.c
  * @brief   RCM DDL module driver.
  *
  * @attention
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *
  * 1. Redistributions of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of the copyright holder nor the names of its contributors
  *    may be used to endorse or promote products derived from this software without
  *    specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
  * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
  * OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  * The original code has been modified by Geehy Semiconductor.
  *
  * Copyright (c) 2017 STMicroelectronics.
  * Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_rcm.h"
#ifdef  USE_FULL_ASSERT
    #include "g32_assert.h"
#else
    #define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif
/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(RCM)

/** @addtogroup RCM_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup RCM_DDL_Private_Macros
  * @{
  */
#define DDL_RCM_TIMEOUT_VALUE       50000U
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCM_DDL_Private_Functions RCM Private functions
  * @{
  */
uint32_t RCM_GetSystemClockFreq(void);
uint32_t RCM_GetHCLKClockFreq(uint32_t SYSCLK_Frequency);
uint32_t RCM_GetPCLKClockFreq(uint32_t HCLK_Frequency);
uint32_t RCM_PLL_GetFreqDomain_SYS(uint32_t SYSCLK_Source);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCM_DDL_Exported_Functions
  * @{
  */

/** @addtogroup RCM_DDL_EF_Init
  * @{
  */

/**
  * @brief  Reset the RCM clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *         - HSI ON and used as system clock source
  *         - HSE and PLL OFF
  *         - AHB, APB1 and APB2 prescaler set to 1.
  *         - CSS, MCO OFF
  *         - All interrupts disabled
  * @note   This function doesn't modify the configuration of the
  *         - Peripheral clocks
  *         - LSI, LSE and RTC clocks
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RCM registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus DDL_RCM_DeInit(void)
{
    __IO uint32_t vl_mask;
    volatile uint32_t timeout = DDL_RCM_TIMEOUT_VALUE;
    ErrorStatus status = SUCCESS;

    /* Set HSIEN bit */
    DDL_RCM_HSI_Enable();

    /* Wait for HSI READY bit */
    timeout = DDL_RCM_TIMEOUT_VALUE;
    while (DDL_RCM_HSI_IsReady() != 1U)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Reset CFG register */
    DDL_RCM_WriteReg(SCCR, 0x00000000U);

    /* Switch system clock source to HSI by configuring MCCR. */
    DDL_RCM_WriteReg(MCCR, 0x00000001U);

    /* Disable automatic clock switch back from HSI. */
    DDL_RCM_WriteReg(MCCR, 0x00000000U);

    /* Wait for the system clock switch to complete and stabilize. */
    timeout = DDL_RCM_TIMEOUT_VALUE;
    while ((READ_BIT(RCM->MCCR, RCM_MCCR_SWST) >> RCM_MCCR_SWST_Pos) != 0U)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Read CTRL register */
    vl_mask = DDL_RCM_ReadReg(RCCR);

    /* Reset HSEEN, PLLEN, CSSEN bits */
    CLEAR_BIT(vl_mask, (RCM_RCCR_HSEON | RCM_RCCR_PLLON | RCM_RCCR_CSSON));

    /* Write new value in CTRL register */
    DDL_RCM_WriteReg(RCCR, vl_mask);

    /* Wait for PLL READY bit to be reset */
    timeout = DDL_RCM_TIMEOUT_VALUE;
    while (DDL_RCM_PLL_IsReady() != 0U)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Reset PLLCR register */
    DDL_RCM_WriteReg(PLLCR, RCM_PLLCR_RST_VALUE);

    /* Disable all interrupts */
    CLEAR_BIT(RCM->CIER,
              (RCM_CIER_LSIRDYIE | RCM_CIER_LSERDYIE | RCM_CIER_HSIRDYIE | \
               RCM_CIER_HSERDYIE | RCM_CIER_PLLRDYIE));

    /* Clear all interrupt flags */
    SET_BIT(RCM->CICR,
            (RCM_CICR_LSIRDYF | RCM_CICR_LSERDYF | RCM_CICR_HSIRDYF | \
             RCM_CICR_HSERDYF | RCM_CICR_PLLRDYF | RCM_CICR_HSECSSF | \
             RCM_CICR_LSECSSF));

    /* Reset all RSTFLGCLR flags */
    SET_BIT(RCM->RSTCSR,
            (RCM_RSTCSR_OPRSTF | RCM_RSTCSR_PINRSTF | RCM_RSTCSR_PORRSTF | \
             RCM_RSTCSR_SFTRSTF | RCM_RSTCSR_IWDTRSTF | RCM_RSTCSR_WWDTRSTF));

    return status;
}

/**
  * @}
  */

/** @addtogroup RCM_DDL_EF_Get_Freq
  * @brief  Return the frequencies of different on chip clocks;  System, AHB, APB1 and APB2 buses clocks
  *         and different peripheral clocks available on the device.
  * @note   If SYSCLK source is HSI, function returns values based on HSI_VALUE(**)
  * @note   If SYSCLK source is HSE, function returns values based on HSE_VALUE(***)
  * @note   If SYSCLK source is PLL, function returns values based on HSE_VALUE(***)
  *         or HSI_VALUE(**) multiplied/divided by the PLL factors.
  * @note   (**) HSI_VALUE is a constant defined in this file (default value
  *              16 MHz) but the real value may vary depending on the variations
  *              in voltage and temperature.
  * @note   (***) HSE_VALUE is a constant defined in this file (default value
  *               25 MHz), user has to ensure that HSE_VALUE is same as the real
  *               frequency of the crystal used. Otherwise, this function may
  *               have wrong result.
  * @note   The result of this function could be incorrect when using fractional
  *         value for HSE crystal.
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  * @{
  */

/**
  * @brief  Return the frequencies of different on chip clocks;  System, AHB, APB buses clocks
  * @note   Each time SYSCLK, HCLK, PCLK clock changes, this function
  *         must be called to update structure fields. Otherwise, any
  *         configuration based on this function will be incorrect.
  * @param  RCM_Clocks pointer to a @ref DDL_RCM_ClocksTypeDef structure which will hold the clocks frequencies
  * @retval None
  */
void DDL_RCM_GetSystemClocksFreq(DDL_RCM_ClocksTypeDef* RCM_Clocks)
{
    /* Get SYSCLK frequency */
    RCM_Clocks->SYSCLK_Frequency = RCM_GetSystemClockFreq();

    /* HCLK clock frequency */
    RCM_Clocks->HCLK_Frequency   = RCM_GetHCLKClockFreq(RCM_Clocks->SYSCLK_Frequency);

    /* PCLK clock frequency */
    RCM_Clocks->PCLK_Frequency  = RCM_GetPCLKClockFreq(RCM_Clocks->HCLK_Frequency);
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCM_DDL_Private_Functions
  * @{
  */

/**
  * @brief  Return SYSTEM clock frequency
  * @retval SYSTEM clock frequency (in Hz)
  */
uint32_t RCM_GetSystemClockFreq(void)
{
    uint32_t frequency = 0U;

    /* Get SYSCLK source -------------------------------------------------------*/
    switch (DDL_RCM_GetSysClkSource())
    {
        case DDL_RCM_SYS_CLKSOURCE_HSI:  /* HSI used as system clock source */
            frequency = HSI_VALUE;
            break;

        case DDL_RCM_SYS_CLKSOURCE_HSE:  /* HSE used as system clock source */
            frequency = HSE_VALUE;
            break;

        case DDL_RCM_SYS_CLKSOURCE_PLL:  /* PLL used as system clock source */
            frequency = RCM_PLL_GetFreqDomain_SYS(DDL_RCM_SYS_CLKSOURCE_PLL);
            break;

        default:
            frequency = HSI_VALUE;
            break;
    }

    return frequency;
}

/**
  * @brief  Return HCLK clock frequency
  * @param  SYSCLK_Frequency SYSCLK clock frequency
  * @retval HCLK clock frequency (in Hz)
  */
uint32_t RCM_GetHCLKClockFreq(uint32_t SYSCLK_Frequency)
{
    /* HCLK clock frequency */
    return __DDL_RCM_CALC_HCLK_FREQ(SYSCLK_Frequency, DDL_RCM_GetAHBPrescaler());
}

/**
  * @brief  Return PCLK clock frequency
  * @param  HCLK_Frequency HCLK clock frequency
  * @retval PCLK clock frequency (in Hz)
  */
uint32_t RCM_GetPCLKClockFreq(uint32_t HCLK_Frequency)
{
    /* PCLK clock frequency */
    return __DDL_RCM_CALC_PCLK_FREQ(HCLK_Frequency, DDL_RCM_GetAPBPrescaler());
}

/**
  * @brief  Return PLL clock frequency used for system domain
  * @param  SYSCLK_Source System clock source
  * @retval PLL clock frequency (in Hz)
  */
uint32_t RCM_PLL_GetFreqDomain_SYS(uint32_t SYSCLK_Source)
{
    uint32_t pllinputfreq = 0U, pllsource = 0U, plloutputfreq = 0U, pllprescaler = 0U;

    /* SYSCLK = ((HSE_VALUE or HSI_VALUE / PLLP) * PLLMUL */
    pllsource = DDL_RCM_PLL_GetClkSource();

    switch (pllsource)
    {
        case DDL_RCM_PLL_CLKSOURCE_HSI:  /* HSI used as PLL clock source */
            pllinputfreq = HSI_VALUE;
            break;

        case DDL_RCM_PLL_CLKSOURCE_HSE:  /* HSE used as PLL clock source */
            pllinputfreq = HSE_VALUE;
            break;

        default:
            pllinputfreq = HSI_VALUE;
            break;
    }

    if (SYSCLK_Source == DDL_RCM_SYS_CLKSOURCE_PLL)
    {
        pllprescaler = (DDL_RCM_PLL_GetPrescaler() >> RCM_PLLCR_PLLP_Pos);

        if(pllprescaler == 0)
        {
            pllprescaler = 1;
        }

        plloutputfreq = __DDL_RCM_CALC_PLLCLK_FREQ(pllinputfreq, \
        pllprescaler, DDL_RCM_PLL_GetMultiplier());
    }

    return plloutputfreq;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RCM) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */
