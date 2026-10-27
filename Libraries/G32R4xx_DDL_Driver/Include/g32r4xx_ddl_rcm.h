/**
  *
  * @file    g32r4xx_ddl_rcm.h
  * @brief   Header file of RCM DDL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_RCM_H
#define G32R4xx_DDL_RCM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined(RCM)

/** @defgroup RCM_DDL RCM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RCM_DDL_Private_Macros RCM Private Macros
  * @{
  */
extern const uint8_t  AHBPrescTable[16];  /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];   /*!< APB prescalers table values */
/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RCM_DDL_Exported_Types RCM Exported Types
  * @{
  */

/** @defgroup DDL_ES_CLOCK_FREQ Clocks Frequency Structure
  * @{
  */

/**
  * @brief  RCM Clocks Frequency Structure
  */
typedef struct
{
  uint32_t SYSCLK_Frequency;  /*!< SYSCLK clock frequency */
  uint32_t HCLK_Frequency;    /*!< HCLK clock frequency */
  uint32_t PCLK_Frequency;    /*!< PCLK clock frequency */
} DDL_RCM_ClocksTypeDef;

/**
  * @}
  */

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCM_DDL_Exported_Constants RCM Exported Constants
  * @{
  */

/** @defgroup RCM_DDL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE  8000000U  /*!< Value of the HSE oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
#define HSI_VALUE  8000000U  /*!< Value of the HSI oscillator in Hz */
#endif /* HSI_VALUE */

#if !defined  (LSE_VALUE)
#define LSE_VALUE  32768U  /*!< Value of the LSE oscillator in Hz */
#endif /* LSE_VALUE */

#if !defined  (LSI_VALUE)
#define LSI_VALUE  32000U  /*!< Value of the LSI oscillator in Hz */
#endif /* LSI_VALUE */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_INT_FLAG Interrupt Flags Defines
  * @brief    Flags defines which can be used with DDL_RCM_ReadRegand DDL_RCM_WriteReg function
  * @{
  */
#define DDL_RCM_INT_LSIRDYFLG      RCM_CICR_LSIRDYF     /*!< LSI Ready Interrupt flag */
#define DDL_RCM_INT_LSERDYFLG      RCM_CICR_LSERDYF     /*!< LSE Ready Interrupt flag */
#define DDL_RCM_INT_HSIRDYFLG      RCM_CICR_HSIRDYF     /*!< HSI Ready Interrupt flag */
#define DDL_RCM_INT_HSERDYFLG      RCM_CICR_HSERDYF     /*!< HSE Ready Interrupt flag */
#define DDL_RCM_INT_PLLRDYFLG      RCM_CICR_PLLRDYF     /*!< PLL Ready Interrupt flag */
#define DDL_RCM_INT_HSECSSFLG      RCM_CICR_HSECSSF     /*!< Clock Security System Interrupt flag */
#define DDL_RCM_INT_LSECSSFLG      RCM_CICR_LSECSSF     /*!< Clock Security System Interrupt flag */
#define DDL_RCM_RSTCSR_OPRSTFLG    RCM_RSTCSR_OPRSTF    /*!< Opload reset flag */
#define DDL_RCM_RSTCSR_PINRSTFLG   RCM_RSTCSR_PINRSTF   /*!< PIN reset flag */
#define DDL_RCM_RSTCSR_PORRSTFLG   RCM_RSTCSR_PORRSTF   /*!< Borrst reset flag */
#define DDL_RCM_RSTCSR_SFTRSTFLG   RCM_RSTCSR_SFTRSTF   /*!< Software Reset flag */
#define DDL_RCM_RSTCSR_IWDTRSTFLG  RCM_RSTCSR_IWDTRSTF  /*!< Independent Watchdog reset flag */
#define DDL_RCM_RSTCSR_WWDTRSTFLG  RCM_RSTCSR_WWDTRSTF  /*!< Window watchdog reset flag */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_IT Interrupt Defines
  * @brief    IT defines which can be used with DDL_RCM_ReadReg and DDL_RCM_WriteReg functions
  * @{
  */
#define DDL_RCM_INT_LSIRDYEN  RCM_CIER_LSIRDYIE  /*!< LSI Ready Interrupt Enable */
#define DDL_RCM_INT_LSERDYEN  RCM_CIER_LSERDYIE  /*!< LSE Ready Interrupt Enable */
#define DDL_RCM_INT_HSIRDYEN  RCM_CIER_HSIRDYIE  /*!< HSI Ready Interrupt Enable */
#define DDL_RCM_INT_HSERDYEN  RCM_CIER_HSERDYIE  /*!< HSE Ready Interrupt Enable */
#define DDL_RCM_INT_PLLRDYEN  RCM_CIER_PLLRDYIE  /*!< PLL Ready Interrupt Enable */
#define DDL_RCM_INT_HSECSSEN  RCM_CIER_HSECSSIE  /*!< PLL Ready Interrupt Enable */
#define DDL_RCM_INT_LSECSSEN  RCM_CIER_LSECSSIE  /*!< PLL Ready Interrupt Enable */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_SYS_CLKSOURCE  System clock switch
  * @{
  */
#define DDL_RCM_SYS_CLKSOURCE_HSI  (0x00000000U)  /*!< HSI selection as system clock */
#define DDL_RCM_SYS_CLKSOURCE_HSE  (0x00000001U)  /*!< HSE selection as system clock */
#define DDL_RCM_SYS_CLKSOURCE_PLL  (0x00000002U)  /*!< PLL selection as system clock */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_SYSCLK_DIV  AHB prescaler
  * @{
  */
#define DDL_RCM_AHB_DIV_1    (RCM_SCCR_HDIV_0)                                      /*!< SYSCLK not divided */
#define DDL_RCM_AHB_DIV_2    (RCM_SCCR_HDIV_3)                                      /*!< SYSCLK divided by 2 */
#define DDL_RCM_AHB_DIV_4    (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_0)                    /*!< SYSCLK divided by 4 */
#define DDL_RCM_AHB_DIV_8    (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_1)                    /*!< SYSCLK divided by 8 */
#define DDL_RCM_AHB_DIV_16   (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_1 | RCM_SCCR_HDIV_0)  /*!< SYSCLK divided by 16 */
#define DDL_RCM_AHB_DIV_32   (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_2)                    /*!< SYSCLK divided by 32 */
#define DDL_RCM_AHB_DIV_64   (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_2 | RCM_SCCR_HDIV_0)  /*!< SYSCLK divided by 64 */
#define DDL_RCM_AHB_DIV_128  (RCM_SCCR_HDIV_3 | RCM_SCCR_HDIV_2 | RCM_SCCR_HDIV_1)  /*!< SYSCLK divided by 128 */
#define DDL_RCM_AHB_DIV_256  (RCM_SCCR_HDIV)                                        /*!< SYSCLK divided by 256 */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_APB_DIV  APB low-speed prescaler (APB)
  * @{
  */
#define DDL_RCM_APB_DIV_1   (0x00000000U)                        /*!< HCLK not divided */
#define DDL_RCM_APB_DIV_2   (RCM_SCCR_PDIV_2)                    /*!< HCLK divided by 2 */
#define DDL_RCM_APB_DIV_4   (RCM_SCCR_PDIV_2 | RCM_SCCR_PDIV_0)  /*!< HCLK divided by 4 */
#define DDL_RCM_APB_DIV_8   (RCM_SCCR_PDIV_2 | RCM_SCCR_PDIV_1)  /*!< HCLK divided by 8 */
#define DDL_RCM_APB_DIV_16  (RCM_SCCR_PDIV)                      /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_AHB_RESET AHB reset
  * @{
  */
#define DDL_RCM_AHB_RESET_DMA    RCM_AHBRST_DMARST
#define DDL_RCM_AHB_RESET_GPIO   RCM_AHBRST_GPIORST
#define DDL_RCM_AHB_RESET_ADC1   RCM_AHBRST_ADC1RST
#define DDL_RCM_AHB_RESET_ADC2   RCM_AHBRST_ADC2RST
#define DDL_RCM_AHB_RESET_ADC3   RCM_AHBRST_ADC3RST
#define DDL_RCM_AHB_RESET_FLASH  RCM_AHBRST_FLASHRST
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_APB_RESET APB reset
  * @{
  */
#define DDL_RCM_APB_RESET_TMR1    RCM_APBRST_TMR1RST
#define DDL_RCM_APB_RESET_TMR2    RCM_APBRST_TMR2RST
#define DDL_RCM_APB_RESET_TMR3    RCM_APBRST_TMR3RST
#define DDL_RCM_APB_RESET_TMR4    RCM_APBRST_TMR4RST
#define DDL_RCM_APB_RESET_SPI     RCM_APBRST_SPIRST
#define DDL_RCM_APB_RESET_USART1  RCM_APBRST_USART1RST
#define DDL_RCM_APB_RESET_USART2  RCM_APBRST_USART2RST
#define DDL_RCM_APB_RESET_I2C     RCM_APBRST_I2CRST
#define DDL_RCM_APB_RESET_TS      RCM_APBRST_TSRST
#define DDL_RCM_APB_RESET_EINT    RCM_APBRST_EINTRST
#define DDL_RCM_APB_RESET_DAC1    RCM_APBRST_DAC1RST
#define DDL_RCM_APB_RESET_DAC2    RCM_APBRST_DAC2RST
#define DDL_RCM_APB_RESET_COMP    RCM_APBRST_COMPRST
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_AHB_Peripheral AHB peripheral
  * @{
  */
#define DDL_RCM_AHB_PERIPHERAL_DMA    RCM_AHBCG_DMACEN
#define DDL_RCM_AHB_PERIPHERAL_GPIO   RCM_AHBCG_GPIOCEN
#define DDL_RCM_AHB_PERIPHERAL_ADC1   RCM_AHBCG_ADC1EN
#define DDL_RCM_AHB_PERIPHERAL_ADC2   RCM_AHBCG_ADC2EN
#define DDL_RCM_AHB_PERIPHERAL_ADC3   RCM_AHBCG_ADC3EN
#define DDL_RCM_AHB_PERIPHERAL_FLASH  RCM_AHBCG_FLASHCEN
#define DDL_RCM_AHB_PERIPHERAL_ROM    RCM_AHBCG_ROMCEN
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_APB_PERIPHERAL APB peripheral
  * @{
  */
#define DDL_RCM_APB_PERIPHERAL_TMR1    RCM_APBCG_TMR1CEN
#define DDL_RCM_APB_PERIPHERAL_TMR2    RCM_APBCG_TMR2CEN
#define DDL_RCM_APB_PERIPHERAL_TMR3    RCM_APBCG_TMR3CEN
#define DDL_RCM_APB_PERIPHERAL_TMR4    RCM_APBCG_TMR4CEN
#define DDL_RCM_APB_PERIPHERAL_SPI     RCM_APBCG_SPICEN
#define DDL_RCM_APB_PERIPHERAL_USART1  RCM_APBCG_USART1CEN
#define DDL_RCM_APB_PERIPHERAL_USART2  RCM_APBCG_USART2CEN
#define DDL_RCM_APB_PERIPHERAL_I2C     RCM_APBCG_I2CCEN
#define DDL_RCM_APB_PERIPHERAL_WWDT    RCM_APBCG_WWDTCEN
#define DDL_RCM_APB_PERIPHERAL_TS      RCM_APBCG_TSCEN
#define DDL_RCM_APB_PERIPHERAL_EINT    RCM_APBCG_EINTCEN
#define DDL_RCM_APB_PERIPHERAL_DAC1    RCM_APBCG_DAC1CEN
#define DDL_RCM_APB_PERIPHERAL_DAC2    RCM_APBCG_DAC2CEN
#define DDL_RCM_APB_PERIPHERAL_COMP    RCM_APBCG_COMPCEN
#define DDL_RCM_APB_PERIPHERAL_BKP     RCM_APBCG_BKPCEN
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_MCOSOURCE MCO source selection
  * @{
  */
#define DDL_RCM_MCOSOURCE_SYSCLK  (0x00000000U)                                  /*!< SYSCLK selection as MCO source */
#define DDL_RCM_MCOSOURCE_HSI     (RCM_SCCR_CLKOUTSEL_0)                         /*!< HSI selection as MCO source */
#define DDL_RCM_MCOSOURCE_HSE     (RCM_SCCR_CLKOUTSEL_1)                         /*!< HSE selection as MCO source */
#define DDL_RCM_MCOSOURCE_PLL     (RCM_SCCR_CLKOUTSEL_1 | RCM_SCCR_CLKOUTSEL_0)  /*!< PLL selection as MCO source */
#define DDL_RCM_MCOSOURCE_LSI     (RCM_SCCR_CLKOUTSEL_2)                         /*!< LSI selection as MCO source */
#define DDL_RCM_MCOSOURCE_LSE     (RCM_SCCR_CLKOUTSEL_2 | RCM_SCCR_CLKOUTSEL_0)  /*!< LSE selection as MCO source */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_MCO_DIV  MCO prescaler
  * @{
  */
#define DDL_RCM_MCO_DIV_1   (0x00000000U)                                  /*!< MCO not divided */
#define DDL_RCM_MCO_DIV_2   (RCM_SCCR_CLKOUTDIV_0)                         /*!< MCO divided by 2 */
#define DDL_RCM_MCO_DIV_4   (RCM_SCCR_CLKOUTDIV_1)                         /*!< MCO divided by 4 */
#define DDL_RCM_MCO_DIV_8   (RCM_SCCR_CLKOUTDIV_1 | RCM_SCCR_CLKOUTDIV_0)  /*!< MCO divided by 8 */
#define DDL_RCM_MCO_DIV_16  (RCM_SCCR_CLKOUTDIV_2)                         /*!< MCO divided by 16 */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_PLL_CLK_SOURCE PLL clock source selection
  * @{
  */
#define DDL_RCM_PLL_CLKSOURCE_NONE  (0x00000000UL)        /*!< No PLL source */
#define DDL_RCM_PLL_CLKSOURCE_HSI   (RCM_PLLCR_PLLSRC_1)  /*!< HSI selection as PLL source */
#define DDL_RCM_PLL_CLKSOURCE_HSE   (RCM_PLLCR_PLLSRC)    /*!< HSE selection as PLL source */
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_PLL_DIV PLL clock source prescaler
  * @{
  */
#define DDL_RCM_PLL_DIV1   (0x00000000U)                                             /*!< PLL do not division */
#define DDL_RCM_PLL_DIV2   (RCM_PLLCR_PLLP_1)                                        /*!< PLL 2 division  */
#define DDL_RCM_PLL_DIV3   (RCM_PLLCR_PLLP_1 | RCM_PLLCR_PLLP_0)                     /*!< PLL 3 division  */
#define DDL_RCM_PLL_DIV4   (RCM_PLLCR_PLLP_2)                                        /*!< PLL 4 division  */
#define DDL_RCM_PLL_DIV5   (RCM_PLLCR_PLLP_2 | RCM_PLLCR_PLLP_0)                     /*!< PLL 5 division  */
#define DDL_RCM_PLL_DIV6   (RCM_PLLCR_PLLP_2 | RCM_PLLCR_PLLP_1)                     /*!< PLL 6 division  */
#define DDL_RCM_PLL_DIV7   (RCM_PLLCR_PLLP_2 | RCM_PLLCR_PLLP_1 | RCM_PLLCR_PLLP_0)  /*!< PLL 7 division  */
#define DDL_RCM_PLL_DIV8   (RCM_PLLCR_PLLP_3)                                        /*!< PLL 8 division  */
#define DDL_RCM_PLL_DIV9   (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_0)                     /*!< PLL 9 division  */
#define DDL_RCM_PLL_DIV10  (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_1)                     /*!< PLL 10 division */
#define DDL_RCM_PLL_DIV11  (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_1| RCM_PLLCR_PLLP_0)   /*!< PLL 11 division */
#define DDL_RCM_PLL_DIV12  (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_2 )                    /*!< PLL 12 division */
#define DDL_RCM_PLL_DIV13  (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_2 | RCM_PLLCR_PLLP_0)  /*!< PLL 13 division */
#define DDL_RCM_PLL_DIV14  (RCM_PLLCR_PLLP_3 | RCM_PLLCR_PLLP_2 | RCM_PLLCR_PLLP_1)  /*!< PLL 14 division */
#define DDL_RCM_PLL_DIV15  (RCM_PLLCR_PLLP)                                          /*!< PLL 15 division */
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RCM_DDL_EC_PERIPH_FREQUENCY Peripheral clock frequency
  * @{
  */
#define DDL_RCM_PERIPH_FREQUENCY_NO  0x00000000U  /*!< No clock enabled for the peripheral            */
#define DDL_RCM_PERIPH_FREQUENCY_NA  0xFFFFFFFFU  /*!< Frequency cannot be provided as external clock */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/** @defgroup RCM_DDL_EC_LOWPOWER  Low power mode
  * @{
  */
#define DDL_RCM_LOWPOWER_STOP           (0x00000000U)
#define DDL_RCM_LOWPOWER_STANDBY        RCM_PWRCR_LPM
#define DDL_RCM_LOWPOWER_SRAM_NO_RESET  (0x00000000U)
#define DDL_RCM_LOWPOWER_SRAM_RESET     RCM_PWRCR_RAM1RET
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_ADC16_ANALOG_CLK_PRESCALER ADC16 Analog clock prescaler
  * @{
  */
#define DDL_RCM_ADC16ACLK_DIV_6   (0x00000000U)
#define DDL_RCM_ADC16ACLK_DIV_12  (RCM_ADCCR_ADC16ADIV_1)
#define DDL_RCM_ADC16ACLK_DIV_24  (RCM_ADCCR_ADC16ADIV)
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_ADC12_ANALOG_CLK_PRESCALER ADC12 Analog clock prescaler
  * @{
  */
#define DDL_RCM_ADC12ACLK_DIV_4   (0x00000000U)
#define DDL_RCM_ADC12ACLK_DIV_8   (RCM_ADCCR_ADC12ADIV_0)
#define DDL_RCM_ADC12ACLK_DIV_16  (RCM_ADCCR_ADC12ADIV_1)
#define DDL_RCM_ADC12ACLK_DIV_32  (RCM_ADCCR_ADC12ADIV)
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_ADC_ANALOG_CLK_SOURCE ADC Analog clock source
  * @{
  */
#define DDL_RCM_ADCACLK_PLL     (0x00000000U)
#define DDL_RCM_ADCACLK_SYSCLK  (RCM_ADCCR_ADCACLKSEL)
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_PLL_INTERCLK_OUTPUT_SOURCE PLL internal clock output source
  * @{
  */
#define DDL_RCM_PLL_INTERCLK_OUTPUTSOURCE_NONE      (0x00000000UL)
#define DDL_RCM_PLL_INTERCLK_OUTPUTSOURCE_FBK       (0x00000001UL)
#define DDL_RCM_PLL_INTERCLK_OUTPUTSOURCE_FBK_DIV2  (0x00000002UL)
#define DDL_RCM_PLL_INTERCLK_OUTPUTSOURCE_CLKREF    (0x00000003UL)
/**
  * @}
  */

/** @defgroup RCM_DDL_EC_LSE_DRIVE LSE drive capacity
  * @{
  */
#define DDL_RCM_LSE_DRIVE_LOW   (0x00000000UL)
#define DDL_RCM_LSE_DRIVE_HIGH  RCM_SYS_ANACR0_LSEDRV
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCM_DDL_Exported_Macros RCM Exported Macros
  * @{
  */

/** @defgroup RCM_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RCM register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_RCM_WriteReg(__REG__,  __VALUE__) WRITE_REG(RCM->__REG__, (__VALUE__))

/**
  * @brief  Read a value in RCM register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_RCM_ReadReg(__REG__)  READ_REG(RCM->__REG__)
/**
  * @}
  */

/** @defgroup RCM_DDL_EM_CALC_FREQ Calculate frequencies
  * @{
  */

/**
  * @brief  Helper macro to calculate the PLLCLK frequency on system domain
  * @note ex: @ref __DDL_RCM_CALC_PLLCLK_FREQ (HSE_VALUE,@ref DDL_RCM_PLL_GetHSEFreqPrescaler (),
  *             @ref DDL_RCM_PLL_GetN (), @ref DDL_RCM_PLL_GetP ());
  * @param  __INPUTFREQ__ PLL Input frequency (based on HSE/HSI)
  * @param  __PLLP__ This parameter can be between 0x1 to 0xF
  * @param  __PLLMUL__ This parameter can be between 0x0 to 0x3F
  * @retval PLL clock frequency (in Hz)
  */
#define __DDL_RCM_CALC_PLLCLK_FREQ(__INPUTFREQ__,  __PLLP__, __PLLMUL__) (((__INPUTFREQ__) / (__PLLP__)) * (__PLLMUL__))

/**
  * @brief  Helper macro to calculate the HCLK frequency
  * @param  __SYSCLKFREQ__ SYSCLK frequency (based on HSE/HSI/PLLCLK)
  * @param  __AHBPRESCALER__ This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_DIV_1
  *         @arg @ref DDL_RCM_AHB_DIV_2
  *         @arg @ref DDL_RCM_AHB_DIV_4
  *         @arg @ref DDL_RCM_AHB_DIV_8
  *         @arg @ref DDL_RCM_AHB_DIV_16
  *         @arg @ref DDL_RCM_AHB_DIV_32
  *         @arg @ref DDL_RCM_AHB_DIV_64
  *         @arg @ref DDL_RCM_AHB_DIV_128
  *         @arg @ref DDL_RCM_AHB_DIV_512
  * @retval HCLK clock frequency (in Hz)
  */
#define __DDL_RCM_CALC_HCLK_FREQ(__SYSCLKFREQ__,   __AHBPRESCALER__) ((__SYSCLKFREQ__) >> AHBPrescTable[((__AHBPRESCALER__) & RCM_SCCR_HDIV) >>  RCM_SCCR_HDIV_Pos])

/**
  * @brief  Helper macro to calculate the PCLK frequency (ABP)
  * @param  __HCLKFREQ__ HCLK frequency
  * @param  __APBPRESCALER__ This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_DIV_1
  *         @arg @ref DDL_RCM_APB_DIV_2
  *         @arg @ref DDL_RCM_APB_DIV_4
  *         @arg @ref DDL_RCM_APB_DIV_8
  *         @arg @ref DDL_RCM_APB_DIV_16
  * @retval PCLK1 clock frequency (in Hz)
  */
#define __DDL_RCM_CALC_PCLK_FREQ(__HCLKFREQ__,     __APBPRESCALER__) ((__HCLKFREQ__) >> APBPrescTable[(__APBPRESCALER__) >>  RCM_SCCR_PDIV_Pos])

#define __DDL_RCM_KEY                              0x87E4

#define IS_DDL_RCM_LSE_DRIVE(__VALUE__)  (((__VALUE__) == DDL_RCM_LSE_DRIVE_LOW) \
                                      || ((__VALUE__) == DDL_RCM_LSE_DRIVE_HIGH))

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RCM_DDL_Exported_Functions RCM Exported Functions
  * @{
  */

/** @defgroup RCM_DDL_EF_Lock Lock
  * @{
  */

/**
  * @brief  Unlock the RCM register.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_Unlock(void)
{
  WRITE_REG(RCM->KEY, (0xffff & __DDL_RCM_KEY));
}

/**
  * @brief  Lock the RCM register.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_Lock(void)
{
  SET_BIT(RCM->KEY, RCM_KEY_KEYST);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_SYS_ANACR0 SYS_ANACR0
  * @{
  */

/**
  * @brief  Enable LSE leakage detection.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableLSELeakageDetect(void)
{
  SET_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSELKDTEN);
}

/**
  * @brief  Disable LSE leakage detection.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableLSELeakageDetect(void)
{
  CLEAR_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSELKDTEN);
}

/**
  * @brief  Check whether LSE leakage detection is enabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledLSELeakageDetect(void)
{
  return ((READ_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSELKDTEN) == RCM_SYS_ANACR0_LSELKDTEN) ? 1UL : 0UL);
}

/**
  * @brief  Set LSE drive capacity.
  * @param  Drive This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_LSE_DRIVE_LOW
  *         @arg @ref DDL_RCM_LSE_DRIVE_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetLSEDrive(uint32_t Drive)
{
  MODIFY_REG(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSEDRV, Drive);
}

/**
  * @brief  Get LSE drive capacity.
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_RCM_LSE_DRIVE_LOW
  *         @arg @ref DDL_RCM_LSE_DRIVE_HIGH
  */
__STATIC_INLINE uint32_t DDL_RCM_GetLSEDrive(void)
{
  return (uint32_t)READ_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSEDRV);
}

/**
  * @brief  Get LSE leakage detection status.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_LSELeakageDetect(void)
{
  return ((READ_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSELKDTSTA) == RCM_SYS_ANACR0_LSELKDTSTA) ? 1UL : 0UL);
}

/**
  * @brief  Request LSE leakage compensation automatic calibration.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_RequestLSEAutoTrim(void)
{
  SET_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSEAUTOTRIMREQ);
}

/**
  * @brief  Set XIN port leakage compensation trim value.
  * @param  Trim Value between Min_Data=0 and Max_Data=15
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetLSELeakageTrim(uint32_t Trim)
{
  MODIFY_REG(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSE_LEAKTRIM, (Trim << RCM_SYS_ANACR0_LSE_LEAKTRIM_Pos));
}

/**
  * @brief  Get XIN port leakage compensation trim value.
  * @retval Value between Min_Data=0 and Max_Data=15
  */
__STATIC_INLINE uint32_t DDL_RCM_GetLSELeakageTrim(void)
{
  return (uint32_t)(READ_BIT(RCM->SYS_ANACR0, RCM_SYS_ANACR0_LSE_LEAKTRIM) >> RCM_SYS_ANACR0_LSE_LEAKTRIM_Pos);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_LSI LSI
  * @{
  */

/**
  * @brief  Enable LSI oscillator
  * @note   Accesses PMU->CR in the backup domain. Call DDL_RCM_Unlock(),
  *         DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP) and
  *         DDL_RCM_DisableBackupWriteProtect() first; otherwise a BusFault may occur.
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSI_Enable(void)
{
  SET_BIT(PMU->CR, PMU_CR_LSION);
}

/**
  * @brief  Disable LSI oscillator
  * @note   Accesses PMU->CR in the backup domain. Call DDL_RCM_Unlock(),
  *         DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP) and
  *         DDL_RCM_DisableBackupWriteProtect() first; otherwise a BusFault may occur.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSI_Disable(void)
{
  CLEAR_BIT(PMU->CR, PMU_CR_LSION);
}

/**
  * @brief  Check if LSI clock is ready
  * @note   Accesses PMU->CR in the backup domain. Call DDL_RCM_Unlock(),
  *         DDL_RCM_EnableAPBPeripheral(DDL_RCM_APB_PERIPHERAL_BKP) and
  *         DDL_RCM_DisableBackupWriteProtect() first; otherwise a BusFault may occur.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_LSI_IsReady(void)
{
  return (READ_BIT(PMU->CR, PMU_CR_LSIRDY) == (PMU_CR_LSIRDY));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_HSI HSI
  * @{
  */

/**
  * @brief  Enable HSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSI_Enable(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_HSION);
}

/**
  * @brief  Disable HSI oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSI_Disable(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_HSION);
}

/**
  * @brief  Check if HSI clock is ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_HSI_IsReady(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_HSIRDY) == (RCM_RCCR_HSIRDY));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_HSE HSE
  * @{
  */

/**
  * @brief  Enable the Clock Security System.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSE_EnableCSS(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_CSSON);
}

/**
  * @brief  Disable the Clock Security System.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSE_DisableCSS(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_CSSON);
}

/** @brief  Enable HSE crystal oscillator (HSE ON)
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSE_Enable(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_HSEON);
}

/**
  * @brief  Disable HSE crystal oscillator (HSE ON)
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_HSE_Disable(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_HSEON);
}

/** @brief  Check if HSE oscillator ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_HSE_IsReady(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_HSERDY) == (RCM_RCCR_HSERDY));
}

/** @brief  Check if HSE oscillator byPass
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_HSE_IsByPass(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_HSEBYPASS) == (RCM_RCCR_HSEBYPASS));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_LSE LSE
  * @{
  */
/**
  * @brief  Enable the Clock Security System.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSE_EnableCSS(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_LSECSSON);
}

/**
  * @brief  Disable the Clock Security System.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSE_DisableCSS(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_LSECSSON);
}

/**
  * @brief  Enable  Low Speed External (LSE) crystal.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSE_Enable(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_LSEON);
}

/**
  * @brief  Disable  Low Speed External (LSE) crystal.
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_LSE_Disable(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_LSEON);
}

/**
  * @brief  Check if LSE oscillator ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_LSE_IsReady(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_LSERDY) == (RCM_RCCR_LSERDY));
}

/**
  * @brief  Check if LSE oscillator byPass
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_LSE_IsByPass(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_LSEBYPASS) == (RCM_RCCR_LSEBYPASS));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_PLL PLL
  * @{
  */
/**
  * @brief  Enable PLL Oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_PLL_Enable(void)
{
  SET_BIT(RCM->RCCR, RCM_RCCR_PLLON);
}

/**
  * @brief  Disable PLL Oscillator
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_PLL_Disable(void)
{
  CLEAR_BIT(RCM->RCCR, RCM_RCCR_PLLON);
}

/**
  * @brief  Check if PLL is Ready
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_PLL_IsReady(void)
{
  return (READ_BIT(RCM->RCCR, RCM_RCCR_PLLRDY) == (RCM_RCCR_PLLRDY));
}

/**
  * @brief  Configure PLL clock source
  * @param Source this parameter can be one of the following values:
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_NONE
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_HSI
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_HSE
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_PLL_SetClkSource(uint32_t Source)
{
  MODIFY_REG(RCM->PLLCR, RCM_PLLCR_PLLSRC, Source);
}

/**
  * @brief  Get PLL control clock source
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_NONE
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_HSI
  *        @arg @ref DDL_RCM_PLL_CLKSOURCE_HSE
  */
__STATIC_INLINE uint32_t DDL_RCM_PLL_GetClkSource(void)
{
  return (uint32_t)(READ_BIT(RCM->PLLCR, RCM_PLLCR_PLLSRC));
}

/**
  * @brief  Configure PLL clock source prescaler factor
  * @param Prescaler this parameter can be one of the following values:
  *        @arg @ref DDL_RCM_PLL_DIV1
  *        @arg @ref DDL_RCM_PLL_DIV2
  *        @arg @ref DDL_RCM_PLL_DIV3
  *        @arg @ref DDL_RCM_PLL_DIV4
  *        @arg @ref DDL_RCM_PLL_DIV5
  *        @arg @ref DDL_RCM_PLL_DIV6
  *        @arg @ref DDL_RCM_PLL_DIV7
  *        @arg @ref DDL_RCM_PLL_DIV8
  *        @arg @ref DDL_RCM_PLL_DIV9
  *        @arg @ref DDL_RCM_PLL_DIV10
  *        @arg @ref DDL_RCM_PLL_DIV11
  *        @arg @ref DDL_RCM_PLL_DIV12
  *        @arg @ref DDL_RCM_PLL_DIV13
  *        @arg @ref DDL_RCM_PLL_DIV14
  *        @arg @ref DDL_RCM_PLL_DIV15
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_PLL_SetPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCM->PLLCR, RCM_PLLCR_PLLP, Prescaler);
}

/**
  * @brief  Get PLL clock source prescaler factor
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_RCM_PLL_DIV1
  *        @arg @ref DDL_RCM_PLL_DIV2
  *        @arg @ref DDL_RCM_PLL_DIV3
  *        @arg @ref DDL_RCM_PLL_DIV4
  *        @arg @ref DDL_RCM_PLL_DIV5
  *        @arg @ref DDL_RCM_PLL_DIV6
  *        @arg @ref DDL_RCM_PLL_DIV7
  *        @arg @ref DDL_RCM_PLL_DIV8
  *        @arg @ref DDL_RCM_PLL_DIV9
  *        @arg @ref DDL_RCM_PLL_DIV10
  *        @arg @ref DDL_RCM_PLL_DIV11
  *        @arg @ref DDL_RCM_PLL_DIV12
  *        @arg @ref DDL_RCM_PLL_DIV13
  *        @arg @ref DDL_RCM_PLL_DIV14
  *        @arg @ref DDL_RCM_PLL_DIV15
  */
__STATIC_INLINE uint32_t DDL_RCM_PLL_GetPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCM->PLLCR, RCM_PLLCR_PLLP));
}

/**
  * @brief  Configure PLL multiplier
  * @param Mul this parameter can between 0x0002 to 0x003F
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_PLL_SetMultiplier(uint32_t Mul)
{
  MODIFY_REG(RCM->PLLCR, RCM_PLLCR_PLLMUL, (Mul << RCM_PLLCR_PLLMUL_Pos));
}

/**
  * @brief  Get PLL multiplier
  * @retval return values can be between 0x0002 to 0x003F
  */
__STATIC_INLINE uint32_t DDL_RCM_PLL_GetMultiplier(void)
{
  return (uint32_t)(READ_BIT(RCM->PLLCR, RCM_PLLCR_PLLMUL) >> RCM_PLLCR_PLLMUL_Pos);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_BDRST BDRST
  * @{
  */

/**
  * @brief  Enable backup domain reset
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableBackupDomainReset(void)
{
  SET_BIT(PMU->CR, (uint32_t)PMU_CR_BDRST);
}

/**
  * @brief  Disable backup domain reset
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableBackupDomainReset(void)
{
  CLEAR_BIT(PMU->CR, (uint32_t)PMU_CR_BDRST);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_NRSTOUTDIS NRSTOUTDIS
  * @{
  */

/**
  * @brief  Enable NRST output pulse to NRST pin
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableInternalResetPulseToNRST(void)
{
  SET_BIT(PMU->CR, (uint32_t)PMU_CR_NRSTOUTDIS);
}

/**
  * @brief  Disable NRST output pulse to NRST pin
  * @param  None
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableInternalResetPulseToNRST(void)
{
  CLEAR_BIT(PMU->CR, (uint32_t)PMU_CR_NRSTOUTDIS);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_System System
  * @{
  */
/**
  * @brief  Configure System clock source
  * @param Source this parameter can be one of the following values:
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_HSI
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_HSE
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_PLL
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetSysClkSource(uint32_t Source)
{
  MODIFY_REG(RCM->SCCR, RCM_SCCR_SW, (Source << RCM_SCCR_SW_Pos));
}

/**
  * @brief  Get System clock source
  * @retval return values can be one of the following values:
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_HSI
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_HSE
  *        @arg @ref DDL_RCM_SYS_CLKSOURCE_PLL
  */
__STATIC_INLINE uint32_t DDL_RCM_GetSysClkSource(void)
{
  return (uint32_t)(READ_BIT(RCM->MCCR, RCM_MCCR_SWST) >> RCM_MCCR_SWST_Pos);
}

/**
  * @brief  Enable System clock source switching
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableSysClkSwitch(void)
{
  SET_BIT(RCM->MCCR, RCM_MCCR_CSEN);
}

/**
  * @brief  Disable System clock source switching
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableSysClkSwitch(void)
{
  CLEAR_BIT(RCM->MCCR, RCM_MCCR_CSEN);
}

/**
  * @brief  Check if swtich done event occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_SWDONE(void)
{
  return (uint32_t)(READ_BIT(RCM->MCCR, RCM_MCCR_SWDONE) == RCM_MCCR_SWDONE ? 1UL : 0UL);
}

/**
  * @brief  Check if switch error event occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_SWERR(void)
{
  return (uint32_t)(READ_BIT(RCM->MCCR, RCM_MCCR_SWERR) == RCM_MCCR_SWERR ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup RCM_DDL_EF_Prescaler Prescaler
  * @{
  */
/**
  * @brief  Set AHB prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_DIV_1
  *         @arg @ref DDL_RCM_AHB_DIV_2
  *         @arg @ref DDL_RCM_AHB_DIV_4
  *         @arg @ref DDL_RCM_AHB_DIV_8
  *         @arg @ref DDL_RCM_AHB_DIV_16
  *         @arg @ref DDL_RCM_AHB_DIV_32
  *         @arg @ref DDL_RCM_AHB_DIV_64
  *         @arg @ref DDL_RCM_AHB_DIV_128
  *         @arg @ref DDL_RCM_AHB_DIV_512
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetAHBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCM->SCCR, RCM_SCCR_HDIV, Prescaler);
}

/**
  * @brief  Get AHB prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_DIV_1
  *         @arg @ref DDL_RCM_AHB_DIV_2
  *         @arg @ref DDL_RCM_AHB_DIV_4
  *         @arg @ref DDL_RCM_AHB_DIV_8
  *         @arg @ref DDL_RCM_AHB_DIV_16
  *         @arg @ref DDL_RCM_AHB_DIV_32
  *         @arg @ref DDL_RCM_AHB_DIV_64
  *         @arg @ref DDL_RCM_AHB_DIV_128
  *         @arg @ref DDL_RCM_AHB_DIV_512
  */
__STATIC_INLINE uint32_t DDL_RCM_GetAHBPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCM->SCCR, RCM_SCCR_HDIV));
}

/**
  * @brief  Set APB prescaler
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_DIV_1
  *         @arg @ref DDL_RCM_APB_DIV_2
  *         @arg @ref DDL_RCM_APB_DIV_4
  *         @arg @ref DDL_RCM_APB_DIV_8
  *         @arg @ref DDL_RCM_APB_DIV_16
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetAPBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCM->SCCR, RCM_SCCR_PDIV, Prescaler);
}

/**
  * @brief  Get APB prescaler
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_RCM_APB_DIV_1
  *         @arg @ref DDL_RCM_APB_DIV_2
  *         @arg @ref DDL_RCM_APB_DIV_4
  *         @arg @ref DDL_RCM_APB_DIV_8
  *         @arg @ref DDL_RCM_APB_DIV_16
  */
__STATIC_INLINE uint32_t DDL_RCM_GetAPBPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCM->SCCR, RCM_SCCR_PDIV));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_MCO MCO
  * @{
  */
/**
  * @brief  Enable clock output
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableMCO(void)
{
  SET_BIT(RCM->SCCR, RCM_SCCR_CLKOUTEN);
}

/**
  * @brief  Disable clock output
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableMCO(void)
{
  CLEAR_BIT(RCM->SCCR, RCM_SCCR_CLKOUTEN);
}

/**
  * @brief  Configure MCOx
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_MCOSOURCE_SYSCLK
  *         @arg @ref DDL_RCM_MCOSOURCE_HSI
  *         @arg @ref DDL_RCM_MCOSOURCE_HSE
  *         @arg @ref DDL_RCM_MCOSOURCE_PLL
  *         @arg @ref DDL_RCM_MCOSOURCE_LSI
  *         @arg @ref DDL_RCM_MCOSOURCE_LSE
  * @param  Prescaler This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_MCO_DIV_1
  *         @arg @ref DDL_RCM_MCO_DIV_2
  *         @arg @ref DDL_RCM_MCO_DIV_4
  *         @arg @ref DDL_RCM_MCO_DIV_8
  *         @arg @ref DDL_RCM_MCO_DIV_16
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ConfigMCO(uint32_t Source, uint32_t Prescaler)
{
  MODIFY_REG(RCM->SCCR, (RCM_SCCR_CLKOUTSEL | RCM_SCCR_CLKOUTDIV),  (Source | Prescaler));
}
/**
  * @}
  */

/** @defgroup RCM_DDL_EF_Reset Reset
  * @{
  */
/**
  * @brief  Enable the AHB peripheral reset.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_RESET_DMA
  *         @arg @ref DDL_RCM_AHB_RESET_GPIO
  *         @arg @ref DDL_RCM_AHB_RESET_ADC1
  *         @arg @ref DDL_RCM_AHB_RESET_ADC2
  *         @arg @ref DDL_RCM_AHB_RESET_ADC3
  *         @arg @ref DDL_RCM_AHB_RESET_FLASH
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableAHBReset(uint32_t Peripheral)
{
  CLEAR_BIT(RCM->AHBRST, Peripheral);
}
/**
  * @brief  Disable the AHB peripheral reset.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_RESET_DMA
  *         @arg @ref DDL_RCM_AHB_RESET_GPIO
  *         @arg @ref DDL_RCM_AHB_RESET_ADC1
  *         @arg @ref DDL_RCM_AHB_RESET_ADC2
  *         @arg @ref DDL_RCM_AHB_RESET_ADC3
  *         @arg @ref DDL_RCM_AHB_RESET_FLASH
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableAHBReset(uint32_t Peripheral)
{
  SET_BIT(RCM->AHBRST, Peripheral);
}

/**
  * @brief  Enable the APB peripheral reset.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_RESET_TMR1
  *         @arg @ref DDL_RCM_APB_RESET_TMR2
  *         @arg @ref DDL_RCM_APB_RESET_TMR3
  *         @arg @ref DDL_RCM_APB_RESET_TMR4
  *         @arg @ref DDL_RCM_APB_RESET_SPI
  *         @arg @ref DDL_RCM_APB_RESET_USART1
  *         @arg @ref DDL_RCM_APB_RESET_USART2
  *         @arg @ref DDL_RCM_APB_RESET_I2C
  *         @arg @ref DDL_RCM_APB_RESET_TS
  *         @arg @ref DDL_RCM_APB_RESET_EINT
  *         @arg @ref DDL_RCM_APB_RESET_DAC1
  *         @arg @ref DDL_RCM_APB_RESET_DAC2
  *         @arg @ref DDL_RCM_APB_RESET_COMP
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableAPBReset(uint32_t Peripheral)
{
  CLEAR_BIT(RCM->APBRST, Peripheral);
}

/**
  * @brief  Disable the APB peripheral reset.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_RESET_TMR1
  *         @arg @ref DDL_RCM_APB_RESET_TMR2
  *         @arg @ref DDL_RCM_APB_RESET_TMR3
  *         @arg @ref DDL_RCM_APB_RESET_TMR4
  *         @arg @ref DDL_RCM_APB_RESET_SPI
  *         @arg @ref DDL_RCM_APB_RESET_USART1
  *         @arg @ref DDL_RCM_APB_RESET_USART2
  *         @arg @ref DDL_RCM_APB_RESET_I2C
  *         @arg @ref DDL_RCM_APB_RESET_TS
  *         @arg @ref DDL_RCM_APB_RESET_EINT
  *         @arg @ref DDL_RCM_APB_RESET_DAC1
  *         @arg @ref DDL_RCM_APB_RESET_DAC2
  *         @arg @ref DDL_RCM_APB_RESET_COMP
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableAPBReset(uint32_t Peripheral)
{
  SET_BIT(RCM->APBRST, Peripheral);
}
/**
  * @}
  */

/** @defgroup RCM_DDL_EF_Peripheral Peripheral
  * @{
  */
/**
  * @brief  Enable the AHB peripheral.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_DMA
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_GPIO
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC1
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC2
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC3
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_FLASH
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ROM
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableAHBPeripheral(uint32_t Peripheral)
{
  SET_BIT(RCM->AHBCG, Peripheral);
}

/**
  * @brief  Disable the AHB peripheral.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_DMA
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_GPIO
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC1
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC2
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ADC3
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_FLASH
  *         @arg @ref DDL_RCM_AHB_PERIPHERAL_ROM
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableAHBPeripheral(uint32_t Peripheral)
{
  CLEAR_BIT(RCM->AHBCG, Peripheral);
}

/**
  * @brief  Enable the APB peripheral.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR3
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR4
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_SPI
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_USART1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_USART2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_I2C
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_WWDT
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TS
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_EINT
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_DAC1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_DAC2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_COMP
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_BKP
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableAPBPeripheral(uint32_t Peripheral)
{
  SET_BIT(RCM->APBCG, Peripheral);
}

/**
  * @brief  Disable the APB peripheral.
  * @param  Peripheral This parameter can be one of the following values:
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR3
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TMR4
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_SPI
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_USART1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_USART2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_I2C
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_WWDT
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_TS
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_EINT
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_DAC1
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_DAC2
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_COMP
  *         @arg @ref DDL_RCM_APB_PERIPHERAL_BKP
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableAPBPeripheral(uint32_t Peripheral)
{
  CLEAR_BIT(RCM->APBCG, Peripheral);
}
/**
  * @}
  */

/** @defgroup RCM_DDL_EF_LowPower LowPower
  * @{
  */
/**
  * @brief  Select the low power mode when enter deep sleep mode
  * @param Mode This parameter can be one of the following values:
  *        @arg @ref DDL_RCM_LOWPOWER_STOP
  *        @arg @ref DDL_RCM_LOWPOWER_STANDBY
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetLowPowerMode(uint32_t Mode)
{
  MODIFY_REG(RCM->PWRCR, RCM_PWRCR_LPM, Mode);
}

/**
  * @brief  Configura the SRAM work mode when enter stop mode
  * @param WorkMode This parameter can be one of the following values:
  *        @arg @ref DDL_RCM_LOWPOWER_SRAM_NO_RESET
  *        @arg @ref DDL_RCM_LOWPOWER_SRAM_RESET
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_SetSRAMLowPowerMode(uint32_t WorkMode)
{
  MODIFY_REG(RCM->PWRCR, RCM_PWRCR_RAM1RET, WorkMode);
}

/**
  * @brief  Enable the back up area write protect
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableBackupWriteProtect(void)
{
  CLEAR_BIT(RCM->PWRCR, RCM_PWRCR_BKPWP);
}

/**
  * @brief  Disable the back up area write protect
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableBackupWriteProtect(void)
{
  SET_BIT(RCM->PWRCR, RCM_PWRCR_BKPWP);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_ADC ADC
  * @{
  */

/**
  * @brief  Set Adc16 analog clock division
  * @param Division This parameter can be one of the following values:
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_6
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_12
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_24
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ADC_SetAdc16AnalogClkDivision(uint32_t Division)
{
  MODIFY_REG(RCM->ADCCR, RCM_ADCCR_ADC16ADIV, Division);
}

/**
  * @brief  Get Adc16 analog clock division
  * @param None
  * @retval This return value can be one of the following values:
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_6
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_12
  *        @arg @ref DDL_RCM_ADC16ACLK_DIV_24
  */
__STATIC_INLINE uint32_t DDL_RCM_ADC_GetAdc16AnalogClkDivision(void)
{
  return (uint32_t)(READ_BIT(RCM->ADCCR, RCM_ADCCR_ADC16ADIV));
}

/**
  * @brief  Check whether Adc16 analog clock is ready
  * @param None
  * @retval  State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_ADC_IsAdc16AnalogClkRDY(void)
{
  return (uint32_t)(READ_BIT(RCM->ADCCR, RCM_ADCCR_ADC16ACLKRDY) == RCM_ADCCR_ADC16ACLKRDY);
}

/**
  * @brief  Set Adc12 analog clock division
  * @param Division This parameter can be one of the following values:
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_4
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_8
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_16
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_32
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ADC_SetAdc12AnalogClkDivision(uint32_t Division)
{
  MODIFY_REG(RCM->ADCCR, RCM_ADCCR_ADC12ADIV, Division);
}

/**
  * @brief  Get Adc12 analog clock division
  * @param None
  * @retval This return value can be one of the following values:
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_4
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_8
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_16
  *        @arg @ref DDL_RCM_ADC12ACLK_DIV_32
  */
__STATIC_INLINE uint32_t DDL_RCM_ADC_GetAdc12AnalogClkDivision(void)
{
  return (uint32_t)(READ_BIT(RCM->ADCCR, RCM_ADCCR_ADC12ADIV));
}

/**
  * @brief  Check whether Adc12 analog clock is ready
  * @param None
  * @retval  State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_ADC_IsAdc12AnalogClkRDY(void)
{
  return (uint32_t)(READ_BIT(RCM->ADCCR, RCM_ADCCR_ADC12ACLKRDY) == RCM_ADCCR_ADC12ACLKRDY);
}

/**
  * @brief  Set Adc analog clock source
  * @param Source This parameter can be one of the following values:
  *        @arg @ref DDL_RCM_ADCACLK_PLL
  *        @arg @ref DDL_RCM_ADCACLK_SYSCLK
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ADC_SetAdcAnalogClkSource(uint32_t Source)
{
  MODIFY_REG(RCM->ADCCR, RCM_ADCCR_ADCACLKSEL, Source);
}

/**
  * @brief  Get Adc analog clock source
  * @param None
  * @retval This return value can be one of the following values:
  *        @arg @ref DDL_RCM_ADCACLK_PLL
  *        @arg @ref DDL_RCM_ADCACLK_SYSCLK
  */
__STATIC_INLINE uint32_t DDL_RCM_ADC_GetAdcAnalogClkSource(void)
{
  return (uint32_t)(READ_BIT(RCM->ADCCR, RCM_ADCCR_ADCACLKSEL));
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_FLAG_Management FLAG Management
  * @{
  */
/**
  * @brief  Check if LSI ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_LSIRDY(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_LSIRDYFLG) == (DDL_RCM_INT_LSIRDYFLG));
}

/**
  * @brief  Clear LSI ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_LSIRDY(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_LSIRDYFLG);
}

/**
  * @brief  Check if LSE ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_LSERDY(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_LSERDYFLG) == (DDL_RCM_INT_LSERDYFLG));
}

/**
  * @brief  Clear LSE ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_LSERDY(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_LSERDYFLG);
}

/**
  * @brief  Check if HSI ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_HSIRDY(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_HSIRDYFLG) == (DDL_RCM_INT_HSIRDYFLG));
}

/**
  * @brief  Clear HSI ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_HSIRDY(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_HSIRDYFLG);
}

/**
  * @brief  Check if HSE ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_HSERDY(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_HSERDYFLG) == (DDL_RCM_INT_HSERDYFLG));
}

/**
  * @brief  Clear HSE ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_HSERDY(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_HSERDYFLG);
}

/**
  * @brief  Check if PLL ready interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_PLLRDY(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_PLLRDYFLG) == (DDL_RCM_INT_PLLRDYFLG));
}

/**
  * @brief  Clear PLL ready interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_PLLRDY(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_PLLRDYFLG);
}

/**
  * @brief  Check if HSE clock security system interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_HSECSS(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_HSECSSFLG) == (DDL_RCM_INT_HSECSSFLG));
}

/**
  * @brief  Clear HSE clock security system interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_HSECSS(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_HSECSSFLG);
}

/**
  * @brief  Check if LSE clock security system interrupt occurred or not
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_LSECSS(void)
{
  return (READ_BIT(RCM->CICR, DDL_RCM_INT_LSECSSFLG) == (DDL_RCM_INT_LSECSSFLG));
}

/**
  * @brief  Clear LSE clock security system interrupt flag
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_LSECSS(void)
{
  WRITE_REG(RCM->CICR, DDL_RCM_INT_LSECSSFLG);
}

/**
  * @brief  Check if opload reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_OPRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_OPRSTFLG) == (DDL_RCM_RSTCSR_OPRSTFLG));
}

/**
  * @brief  Clear opload reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_OPRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_OPRSTFLG);
}

/**
  * @brief  Check if pin reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_PINRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_PINRSTFLG) == (DDL_RCM_RSTCSR_PINRSTFLG));
}

/**
  * @brief  Clear pin reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_PINRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_PINRSTFLG);
}

/**
  * @brief  Check if Borrst reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_PORRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_PORRSTFLG) == (DDL_RCM_RSTCSR_PORRSTFLG));
}

/**
  * @brief  Clear Borrst reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_PORRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_PORRSTFLG);
}

/**
  * @brief  Check if Software reset flag is set or not.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_SFTRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_SFTRSTFLG) == (DDL_RCM_RSTCSR_SFTRSTFLG));
}

/**
  * @brief  Clear Software reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_SFTRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_SFTRSTFLG);
}

/**
  * @brief  Check if Independent Watchdog reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_IWDTRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_IWDTRSTFLG) == (DDL_RCM_RSTCSR_IWDTRSTFLG));
}

/**
  * @brief  Clear if Independent Watchdog reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_IWDTRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_IWDTRSTFLG);
}

/**
  * @brief  Check if Window Watchdog reset flag is set or not.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsActiveFlag_WWDTRST(void)
{
  return (READ_BIT(RCM->RSTCSR, DDL_RCM_RSTCSR_WWDTRSTFLG) == (DDL_RCM_RSTCSR_WWDTRSTFLG));
}

/**
  * @brief  Clear Window Watchdog reset flag.
  * @note   Before calling this function, ensure that the RCM registers are unlocked
  *         by calling DDL_RCM_Unlock(). Otherwise, the write to RCM->RSTCSR may be
  *         ignored and the flag will not be cleared.
  * @retval None.
  */
__STATIC_INLINE void DDL_RCM_ClearFlag_WWDTRST(void)
{
  WRITE_REG(RCM->RSTCSR, DDL_RCM_RSTCSR_WWDTRSTFLG);
}

/**
  * @}
  */

/** @defgroup RCM_DDL_EF_IT_Management IT Management
  * @{
  */
/**
  * @brief  Enable LSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_LSIRDY(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_LSIRDYEN);
}

/**
  * @brief  Disable LSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_LSIRDY(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_LSIRDYEN);
}

/**
  * @brief  Checks if LSI ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_LSIRDY(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_LSIRDYEN) == (DDL_RCM_INT_LSIRDYEN));
}

/**
  * @brief  Enable LSE ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_LSERDY(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_LSERDYEN);
}

/**
  * @brief  Disable LSE ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_LSERDY(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_LSERDYEN);
}

/**
  * @brief  Checks if LSE ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_LSERDY(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_LSERDYEN) == (DDL_RCM_INT_LSERDYEN));
}

/**
  * @brief  Enable HSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_HSIRDY(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_HSIRDYEN);
}

/**
  * @brief  Disable HSI ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_HSIRDY(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_HSIRDYEN);
}

/**
  * @brief  Checks if HSI ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_HSIRDY(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_HSIRDYEN) == (DDL_RCM_INT_HSIRDYEN));
}

/**
  * @brief  Enable HSE ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_HSERDY(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_HSERDYEN);
}

/**
  * @brief  Disable HSE ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_HSERDY(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_HSERDYEN);
}

/**
  * @brief  Checks if HSE ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_HSERDY(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_HSERDYEN) == (DDL_RCM_INT_HSERDYEN));
}

/**
  * @brief  Enable PLL ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_PLLRDY(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_PLLRDYEN);
}

/**
  * @brief  Disable PLL ready interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_PLLRDY(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_PLLRDYEN);
}

/**
  * @brief  Checks if PLL ready interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_PLLRDY(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_PLLRDYEN) == (DDL_RCM_INT_PLLRDYEN));
}

/**
  * @brief  Enable HSE clock security system interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_HSECSS(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_HSECSSEN);
}

/**
  * @brief  Disable HSE clock security system interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_HSECSS(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_HSECSSEN);
}

/**
  * @brief  Checks if HSE clock security system interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_HSECSS(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_HSECSSEN) == (DDL_RCM_INT_HSECSSEN));
}

/**
  * @brief  Enable LSE clock security system interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_EnableIT_LSECSS(void)
{
  SET_BIT(RCM->CIER, DDL_RCM_INT_LSECSSEN);
}

/**
  * @brief  Disable LSE clock security system interrupt
  * @retval None
  */
__STATIC_INLINE void DDL_RCM_DisableIT_LSECSS(void)
{
  CLEAR_BIT(RCM->CIER, DDL_RCM_INT_LSECSSEN);
}

/**
  * @brief  Checks if LSE clock security system interrupt source is enabled or disabled.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_RCM_IsEnabledIT_LSECSS(void)
{
  return (READ_BIT(RCM->CIER, DDL_RCM_INT_LSECSSEN) == (DDL_RCM_INT_LSECSSEN));
}
/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup RCM_DDL_EF_Init De-initialization function
  * @{
  */
ErrorStatus DDL_RCM_DeInit(void);
/**
  * @}
  */

/** @defgroup RCM_DDL_EF_Get_Freq Get system and peripherals clocks frequency functions
  * @{
  */
void        DDL_RCM_GetSystemClocksFreq(DDL_RCM_ClocksTypeDef *RCM_Clocks);
/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

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

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_RCM_H */

