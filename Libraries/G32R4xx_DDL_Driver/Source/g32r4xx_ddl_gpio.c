/**
  *
  * @file    g32r4xx_ddl_gpio.c
  * @brief   GPIO DDL module driver.
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
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  *
  */
#if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_gpio.h"
#include "g32r4xx_ddl_rcm.h"
#ifdef  USE_FULL_ASSERT
#include "g32_assert.h"
#else
#define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (GPIO)

/** @addtogroup GPIO_DDL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup GPIO_DDL_Private_Macros
  * @{
  */
#define IS_DDL_GPIO_PORT(__VALUE__)         ((__VALUE__) < (4U))

#define IS_DDL_GPIO_PIN(__VALUE__)          (((0x00000000U) < (__VALUE__)) && ((__VALUE__) <= (DDL_GPIO_PIN_ALL)))

#define DDL_GPIO_PIN_0_5                    (DDL_GPIO_PIN_0 | DDL_GPIO_PIN_1 | DDL_GPIO_PIN_2 | \
                                             DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4 | DDL_GPIO_PIN_5)

#define IS_DDL_GPIO_PIN_FOR_PORT(__GPIO__, __PIN__) \
                                            (((__GPIO__) == GPIOA) ? (((__PIN__) & ~DDL_GPIO_PIN_0_5) == 0U) : \
                                                                     (((__PIN__) & ~DDL_GPIO_PIN_ALL) == 0U))

#define IS_DDL_GPIO_MODE(__VALUE__)         (((__VALUE__) == DDL_GPIO_MODE_INPUT)     ||\
                                            ((__VALUE__) == DDL_GPIO_MODE_OUTPUT)    ||\
                                            ((__VALUE__) == DDL_GPIO_MODE_ALTERNATE) ||\
                                            ((__VALUE__) == DDL_GPIO_MODE_ANALOG))

#define IS_DDL_GPIO_OUTPUT_TYPE(__VALUE__)  (((__VALUE__) == DDL_GPIO_OUTPUT_PUSHPULL)  ||\
                                            ((__VALUE__) == DDL_GPIO_OUTPUT_OPENDRAIN))

#define IS_DDL_GPIO_SPEED(__VALUE__)        (((__VALUE__) == DDL_GPIO_SPEED_FREQ_LOW)       ||\
                                            ((__VALUE__) == DDL_GPIO_SPEED_FREQ_MEDIUM)    ||\
                                            ((__VALUE__) == DDL_GPIO_SPEED_FREQ_HIGH))

#define IS_DDL_GPIO_PULL(__VALUE__)         (((__VALUE__) == DDL_GPIO_PULL_NO)   ||\
                                            ((__VALUE__) == DDL_GPIO_PULL_UP)   ||\
                                            ((__VALUE__) == DDL_GPIO_PULL_DOWN))

#define IS_DDL_GPIO_ALTERNATE(__VALUE__)    (((__VALUE__) == DDL_GPIO_AF_0)   ||\
                                            ((__VALUE__) == DDL_GPIO_AF_1)   ||\
                                            ((__VALUE__) == DDL_GPIO_AF_2)   ||\
                                            ((__VALUE__) == DDL_GPIO_AF_3))

#define IS_DDL_GPIO_SPECIAL_PIN_TYPE(__VALUE__) (((__VALUE__) == DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT) ||\
                                                ((__VALUE__) == DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT))

#define IS_DDL_GPIO_SPECIAL_PIN(__GPIO__, __PIN__)  ((((__GPIO__) == GPIOB) && (((__PIN__) == DDL_GPIO_PIN_4)  || ((__PIN__) == DDL_GPIO_PIN_6)))  ||\
                                                    (((__GPIO__) == GPIOC) && ((__PIN__) == DDL_GPIO_PIN_12)) ||\
                                                    (((__GPIO__) == GPIOD) && (((__PIN__) == DDL_GPIO_PIN_5) || ((__PIN__) == DDL_GPIO_PIN_12) || ((__PIN__) == DDL_GPIO_PIN_15))))

#define DDL_GPIO_ADC3_SWR_PIN_B  (DDL_GPIO_PIN_2 | DDL_GPIO_PIN_3 | DDL_GPIO_PIN_5)
#define DDL_GPIO_ADC3_SWR_PIN_C  (DDL_GPIO_PIN_3 | DDL_GPIO_PIN_4 | DDL_GPIO_PIN_5 | \
                                  DDL_GPIO_PIN_6 | DDL_GPIO_PIN_9 | DDL_GPIO_PIN_10 | DDL_GPIO_PIN_11)
#define DDL_GPIO_ADC3_SWR_PIN_D  (DDL_GPIO_PIN_0 | DDL_GPIO_PIN_1 | DDL_GPIO_PIN_2)

#define IS_DDL_GPIO_ADC3_ANALOG_SWITCH_PIN(__GPIO__, __PIN__) \
  ( ((__PIN__) != 0U) && \
    ( (((__GPIO__) == GPIOB) && (((__PIN__) & ~DDL_GPIO_ADC3_SWR_PIN_B) == 0U)) || \
      (((__GPIO__) == GPIOC) && (((__PIN__) & ~DDL_GPIO_ADC3_SWR_PIN_C) == 0U)) || \
      (((__GPIO__) == GPIOD) && (((__PIN__) & ~DDL_GPIO_ADC3_SWR_PIN_D) == 0U)) ) )

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup GPIO_DDL_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_DDL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize GPIO registers (Registers restored to their default values).
  * @param  GPIOx GPIO Port
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: GPIO registers are de-initialized
  *          - ERROR:   Wrong GPIO Port
  */
ErrorStatus DDL_GPIO_DeInit(GPIO_Type GPIOx)
{
  if(!IS_DDL_GPIO_PORT(GPIOx))
  {
    return (ERROR);
  }

  DDL_GPIO_InitTypeDef deInitStruct;
  DDL_GPIO_StructInit(&deInitStruct);
  DDL_GPIO_Init(GPIOx, &deInitStruct);

  return (SUCCESS);
}

/**
  * @brief  Initialize GPIO registers according to the specified parameters in GPIO_InitStruct.
  * @param  GPIOx GPIO port.
  * @param  GPIO_InitStruct pointer to a @ref DDL_GPIO_InitTypeDef structure
  *         that contains the configuration information for the specified GPIO peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: GPIO registers are initialized according to GPIO_InitStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus DDL_GPIO_Init(GPIO_Type GPIOx, DDL_GPIO_InitTypeDef *GPIO_InitStruct)
{
  uint32_t pinpos     = 0x00000000U;
  uint32_t currentpin = 0x00000000U;

  /* Check the parameters */
  ASSERT_PARAM(IS_DDL_GPIO_PIN(GPIO_InitStruct->Pin));
  ASSERT_PARAM(IS_DDL_GPIO_PIN_FOR_PORT(GPIOx, GPIO_InitStruct->Pin));
  ASSERT_PARAM(IS_DDL_GPIO_MODE(GPIO_InitStruct->Mode));
  ASSERT_PARAM(IS_DDL_GPIO_PULL(GPIO_InitStruct->Pull));

  if (!IS_DDL_GPIO_PIN_FOR_PORT(GPIOx, GPIO_InitStruct->Pin))
  {
    return (ERROR);
  }

  /* ------------------------- Configure the port pins ---------------- */
  /* Initialize  pinpos on first pin set */
  pinpos = POSITION_VAL(GPIO_InitStruct->Pin);

  /* Configure the port pins */
  while (((GPIO_InitStruct->Pin) >> pinpos) != 0x00000000U)
  {
    /* Get current io position */
    currentpin = (GPIO_InitStruct->Pin) & (0x00000001U << pinpos);

    if (currentpin)
    {

      if ((GPIO_InitStruct->Mode == DDL_GPIO_MODE_OUTPUT) || (GPIO_InitStruct->Mode == DDL_GPIO_MODE_ALTERNATE))
      {
        /* Check Speed mode parameters */
        ASSERT_PARAM(IS_DDL_GPIO_SPEED(GPIO_InitStruct->Speed));

        /* Speed mode configuration */
        DDL_GPIO_SetPinSpeed(GPIOx, currentpin, GPIO_InitStruct->Speed);

        /* Check Output mode parameters */
        ASSERT_PARAM(IS_DDL_GPIO_OUTPUT_TYPE(GPIO_InitStruct->OutputType));

        /* Output mode configuration*/
        DDL_GPIO_SetPinOutputType(GPIOx, currentpin, GPIO_InitStruct->OutputType);
      }

      /* Pull-up Pull down resistor configuration*/
      DDL_GPIO_SetPinPull(GPIOx, currentpin, GPIO_InitStruct->Pull);

      if (GPIO_InitStruct->Mode == DDL_GPIO_MODE_ALTERNATE)
      {
        /* Check Alternate parameter */
        ASSERT_PARAM(IS_DDL_GPIO_ALTERNATE(GPIO_InitStruct->Alternate));

        /* Alternate function configuration */
        DDL_GPIO_SetAFPin(GPIOx, currentpin, GPIO_InitStruct->Alternate);
      }

      /* Init always clears SWR. ADC3 channels use DDL_GPIO_EnableAdc3AnalogSwitchPin();
         5 V-tolerant special pins use DDL_GPIO_SetSpecialPinType(). */
      {
        volatile uint16_t *swr = DDL_GPIO_Locate16BitReg((&GPIO->SWR1), GPIOx);
        CLEAR_BIT16((swr), currentpin);
      }

      /* Pin Mode configuration */
      DDL_GPIO_SetPinMode(GPIOx, currentpin, GPIO_InitStruct->Mode);
    }
    pinpos++;
  }

  return (SUCCESS);
}

/**
  * @brief Set each @ref DDL_GPIO_InitTypeDef field to default value.
  * @param GPIO_InitStruct pointer to a @ref DDL_GPIO_InitTypeDef structure
  *                          whose fields will be set to default values.
  * @retval None
  */

void DDL_GPIO_StructInit(DDL_GPIO_InitTypeDef *GPIO_InitStruct)
{
  /* Reset GPIO init structure parameters values */
  GPIO_InitStruct->Pin        = DDL_GPIO_PIN_ALL;
  GPIO_InitStruct->Mode       = DDL_GPIO_MODE_ANALOG;
  GPIO_InitStruct->Speed      = DDL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct->OutputType = DDL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct->Pull       = DDL_GPIO_PULL_NO;
  GPIO_InitStruct->Alternate  = DDL_GPIO_AF_0;
}

/**
  * @brief  Enable ADC3 analog switch bits in SWR.
  * @param  GPIOx GPIO port.
  * @param  PinMask ADC3 analog-switch pin mask for this port.
  * @retval None
  */
void DDL_GPIO_EnableAdc3AnalogSwitchPin(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint16_t *reg;

  ASSERT_PARAM(IS_DDL_GPIO_ADC3_ANALOG_SWITCH_PIN(GPIOx, PinMask));

  reg = DDL_GPIO_Locate16BitReg((&GPIO->SWR1), GPIOx);
  SET_BIT16((reg), PinMask);
}

/**
  * @brief  Disable ADC3 analog switch bits in SWR.
  * @param  GPIOx GPIO port.
  * @param  PinMask ADC3 analog-switch pin mask for this port.
  * @retval None
  */
void DDL_GPIO_DisableAdc3AnalogSwitchPin(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint16_t *reg;

  ASSERT_PARAM(IS_DDL_GPIO_ADC3_ANALOG_SWITCH_PIN(GPIOx, PinMask));

  reg = DDL_GPIO_Locate16BitReg((&GPIO->SWR1), GPIOx);
  CLEAR_BIT16((reg), PinMask);
}

/**
  * @brief  Configure special pin type for the dedicated special GPIO pin.
  * @param  GPIOx GPIO port.
  * @param  PinMask GPIO pin mask.
  * @param  PinType This parameter can be a value of @ref GPIO_DDL_EC_SPECIAL_PIN_TYPE.
  * @retval None
  */
void DDL_GPIO_SetSpecialPinType(GPIO_Type GPIOx, uint32_t PinMask, uint32_t PinType)
{
  volatile uint16_t *reg;

  ASSERT_PARAM(IS_DDL_GPIO_SPECIAL_PIN_TYPE(PinType));
  ASSERT_PARAM(IS_DDL_GPIO_SPECIAL_PIN(GPIOx, PinMask));

  reg = DDL_GPIO_Locate16BitReg((&GPIO->SWR1), GPIOx);
  MODIFY_REG16((reg), PinMask, (PinMask * PinType));
}

/**
  * @brief  Return special pin type configuration for the dedicated special GPIO pin.
  * @param  GPIOx GPIO port.
  * @param  PinMask GPIO pin mask.
  * @retval Returned value can be a value of @ref GPIO_DDL_EC_SPECIAL_PIN_TYPE.
  */
uint32_t DDL_GPIO_GetSpecialPinType(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint16_t *reg;

  ASSERT_PARAM(IS_DDL_GPIO_SPECIAL_PIN(GPIOx, PinMask));

  reg = DDL_GPIO_Locate16BitReg((&GPIO->SWR1), GPIOx);
  return (uint32_t)(READ_BIT16((reg), PinMask) >> POSITION_VAL(PinMask));
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (GPIO) */

/**
  * @}
  */

#endif /* USE_FULL_DDL_DRIVER */

