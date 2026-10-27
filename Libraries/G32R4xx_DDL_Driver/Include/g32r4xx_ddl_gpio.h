/**
  *
  * @file    g32r4xx_ddl_gpio.h
  * @brief   Header file of GPIO DDL module.
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
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_GPIO_H
#define G32R4xx_DDL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (GPIO)

/** @defgroup GPIO_DDL GPIO
  * @{
  */

/* Private types -------------------------------------------------------------*/

/**
 * @brief G32R4XX GPIO port Definition, according to the selected device
 *        configuration in the CMSIS device header.
 */
typedef enum
{
    GPIOA = 0, /*!< GPIO port A */
    GPIOB = 1, /*!< GPIO port B */
    GPIOC = 2, /*!< GPIO port C */
    GPIOD = 3  /*!< GPIO port D */
} GPIO_Type;

/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup GPIO_DDL_Private_Macros GPIO Private Macros
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_DDL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup GPIO_DDL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Structure definition
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_DDL_EC_PIN */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinMode().*/

  uint32_t Speed;        /*!< Specifies the speed for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_SPEED.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinSpeed().*/

  uint32_t OutputType;   /*!< Specifies the operating output type for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_OUTPUT.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinOutputType().*/

  uint32_t Pull;         /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_PULL.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetPinPull().*/

  uint32_t Alternate;    /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIO_DDL_EC_AF.

                              GPIO HW configuration can be modified afterwards using unitary function @ref DDL_GPIO_SetAFPin_0_7() and DDL_GPIO_SetAFPin_8_15().*/
} DDL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_DDL_EC_PIN PIN
  * @{
  */
#define DDL_GPIO_PIN_0    GPIO_PIN0   /*!< Select pin 0 */
#define DDL_GPIO_PIN_1    GPIO_PIN1   /*!< Select pin 1 */
#define DDL_GPIO_PIN_2    GPIO_PIN2   /*!< Select pin 2 */
#define DDL_GPIO_PIN_3    GPIO_PIN3   /*!< Select pin 3 */
#define DDL_GPIO_PIN_4    GPIO_PIN4   /*!< Select pin 4 */
#define DDL_GPIO_PIN_5    GPIO_PIN5   /*!< Select pin 5 */
#define DDL_GPIO_PIN_6    GPIO_PIN6   /*!< Select pin 6 */
#define DDL_GPIO_PIN_7    GPIO_PIN7   /*!< Select pin 7 */
#define DDL_GPIO_PIN_8    GPIO_PIN8   /*!< Select pin 8 */
#define DDL_GPIO_PIN_9    GPIO_PIN9   /*!< Select pin 9 */
#define DDL_GPIO_PIN_10   GPIO_PIN10  /*!< Select pin 10 */
#define DDL_GPIO_PIN_11   GPIO_PIN11  /*!< Select pin 11 */
#define DDL_GPIO_PIN_12   GPIO_PIN12  /*!< Select pin 12 */
#define DDL_GPIO_PIN_13   GPIO_PIN13  /*!< Select pin 13 */
#define DDL_GPIO_PIN_14   GPIO_PIN14  /*!< Select pin 14 */
#define DDL_GPIO_PIN_15   GPIO_PIN15  /*!< Select pin 15 */
#define DDL_GPIO_PIN_ALL  (GPIO_PIN0  | GPIO_PIN1  | GPIO_PIN2  | \
                                             GPIO_PIN3  | GPIO_PIN4  | GPIO_PIN5  | \
                                             GPIO_PIN6  | GPIO_PIN7  | GPIO_PIN8  | \
                                             GPIO_PIN9  | GPIO_PIN10 | GPIO_PIN11 | \
                                             GPIO_PIN12 | GPIO_PIN13 | GPIO_PIN14 | \
                                             GPIO_PIN15) /*!< Select all pins */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_MODE Mode
  * @{
  */
#define DDL_GPIO_MODE_ANALOG     (0x00000000U)      /*!< Select analog mode */
#define DDL_GPIO_MODE_INPUT      GPIO_MODE_MODE0_0  /*!< Select input mode */
#define DDL_GPIO_MODE_OUTPUT     GPIO_MODE_MODE0_1  /*!< Select output mode */
#define DDL_GPIO_MODE_ALTERNATE  GPIO_MODE_MODE0    /*!< Select alternate function mode */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_OUTPUT Output Type
  * @{
  */
#define DDL_GPIO_OUTPUT_PUSHPULL   (0x00000000U)    /*!< Select push-pull as output type */
#define DDL_GPIO_OUTPUT_OPENDRAIN  GPIO_OMODE_OT_0  /*!< Select open-drain as output type */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_SPEED Output Speed
  * @{
  */
#define DDL_GPIO_SPEED_FREQ_LOW     GPIO_OSPEEDER_OSPEEDR0_0  /*!< Select I/O low output speed    */
#define DDL_GPIO_SPEED_FREQ_MEDIUM  GPIO_OSPEEDER_OSPEEDR0_1  /*!< Select I/O medium output speed */
#define DDL_GPIO_SPEED_FREQ_HIGH    GPIO_OSPEEDER_OSPEEDR0    /*!< Select I/O fast output speed   */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_PULL Pull Up Pull Down
  * @{
  */
#define DDL_GPIO_PULL_NO    (0x00000000U)       /*!< Select I/O no pull */
#define DDL_GPIO_PULL_UP    GPIO_PUPD_PUPDR0_0  /*!< Select I/O pull up */
#define DDL_GPIO_PULL_DOWN  GPIO_PUPD_PUPDR0    /*!< Select I/O pull down */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_AF Alternate Function
  * @{
  */
#define DDL_GPIO_AF_0  (0x0000000U)  /*!< Select alternate function 0 */
#define DDL_GPIO_AF_1  (0x0000001U)  /*!< Select alternate function 1 */
#define DDL_GPIO_AF_2  (0x0000002U)  /*!< Select alternate function 2 */
#define DDL_GPIO_AF_3  (0x0000003U)  /*!< Select alternate function 3 */
/**
  * @}
  */

/** @defgroup GPIO_DDL_EC_SPECIAL_PIN_TYPE Special Pin Type Configuration
  * @{
  */
#define DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT         (0x00000000U)  /*!< Select digital 5 V tolerant input */
#define DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT  (0x00000001U)  /*!< Select analog 3.3 V input/output */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Macros GPIO Exported Macros
  * @{
  */

/** @defgroup GPIO_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */
#define DDL_GPIO_Locate32BitReg(__BASEADDR__,  __GPIO__) ((__BASEADDR__) + (__GPIO__ << 2))

#define DDL_GPIO_Locate16BitReg(__BASEADDR__,  __GPIO__) \
  ((volatile uint16_t *)(((volatile uint8_t *)(__BASEADDR__)) + (((uint32_t)(__GPIO__)) << 1)))

/**
  * @brief  Write a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_GPIO_WriteReg(__INSTANCE__,  __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_GPIO_ReadReg(__INSTANCE__,  __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_DDL_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_DDL_EF_Port_Configuration Port Configuration
  * @{
  */

/**
  * @brief  Configure gpio mode for a dedicated pin on a dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_MODE_ANALOG
  *         @arg @ref DDL_GPIO_MODE_INPUT
  *         @arg @ref DDL_GPIO_MODE_OUTPUT
  *         @arg @ref DDL_GPIO_MODE_ALTERNATE
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinMode(GPIO_Type GPIOx, uint32_t Pin, uint32_t Mode)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->MODER1), GPIOx);
  MODIFY_REG((*reg), (GPIO_MODE_MODE0 << (POSITION_VAL(Pin) * 2U)), (Mode << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on a dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_MODE_ANALOG
  *         @arg @ref DDL_GPIO_MODE_INPUT
  *         @arg @ref DDL_GPIO_MODE_OUTPUT
  *         @arg @ref DDL_GPIO_MODE_ALTERNATE
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinMode(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->MODER1), GPIOx);
  return (uint32_t)(READ_BIT((*reg),
                             (GPIO_MODE_MODE0 << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Configure gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @param  GPIOx GPIO port.
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @param  OutputType This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref DDL_GPIO_OUTPUT_OPENDRAIN
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinOutputType(GPIO_Type GPIOx, uint32_t PinMask, uint32_t OutputType)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->OTYPER1), GPIOx);
  MODIFY_REG16((reg), PinMask, (PinMask * OutputType));
}

/**
  * @brief  Return gpio output type for several pins on dedicated port.
  * @note   Output type as to be set when gpio pin is in output or
  *         alternate modes. Possible type are Push-pull or Open-drain.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO Port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref DDL_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinOutputType(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->OTYPER1), GPIOx);
  return (uint32_t)(READ_BIT16((reg), Pin) >> POSITION_VAL(Pin));
}

/**
  * @brief  Configure gpio speed for a dedicated pin on a dedicated port.
  * @note   I/O speed can be Low, Medium, Fast or High speed.
  * @note   Warning: only one pin can be passed as parameter.
  * @note   Refer to datasheet for frequency specifications and the power
  *         supply and load conditions for each speed.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @param  Speed This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref DDL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref DDL_GPIO_SPEED_FREQ_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinSpeed(GPIO_Type GPIOx, uint32_t Pin, uint32_t Speed)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->OSPEEDR1), GPIOx);
  MODIFY_REG((*reg), (GPIO_OSPEEDER_OSPEEDR0 << (POSITION_VAL(Pin) * 2U)),
             (Speed << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio speed for a dedicated pin on dedicated port.
  * @note   I/O speed can be Low, Medium, Fast or High speed.
  * @note   Warning: only one pin can be passed as parameter.
  * @note   Refer to datasheet for frequency specifications and the power
  *         supply and load conditions for each speed.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref DDL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref DDL_GPIO_SPEED_FREQ_HIGH
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinSpeed(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->OSPEEDR1), GPIOx);
  return (uint32_t)(READ_BIT((*reg),
                             (GPIO_OSPEEDER_OSPEEDR0 << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Configure gpio pull-up or pull-down for a dedicated pin on a dedicated port.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @param  Pull This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PULL_NO
  *         @arg @ref DDL_GPIO_PULL_UP
  *         @arg @ref DDL_GPIO_PULL_DOWN
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetPinPull(GPIO_Type GPIOx, uint32_t Pin, uint32_t Pull)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->PUPDR1), GPIOx);
  MODIFY_REG((*reg), (GPIO_PUPD_PUPDR0 << (POSITION_VAL(Pin) * 2U)), (Pull << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio pull-up or pull-down for a dedicated pin on a dedicated port
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_PULL_NO
  *         @arg @ref DDL_GPIO_PULL_UP
  *         @arg @ref DDL_GPIO_PULL_DOWN
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetPinPull(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->PUPDR1), GPIOx);
  return (uint32_t)(READ_BIT((*reg),
                             (GPIO_PUPD_PUPDR0 << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Configure gpio alternate function of a dedicated pin for a dedicated port.
  * @note   Possible values are from AF0 to AF15 depending on target.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @param  Alternate This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_AF_0
  *         @arg @ref DDL_GPIO_AF_1
  *         @arg @ref DDL_GPIO_AF_2
  *         @arg @ref DDL_GPIO_AF_3
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetAFPin(GPIO_Type GPIOx, uint32_t Pin, uint32_t Alternate)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->AFSELR1), GPIOx);
  MODIFY_REG((*reg), (GPIO_ALF_ALFSEL0 << (POSITION_VAL(Pin) * 2U)),
               (Alternate << (POSITION_VAL(Pin) * 2U)));
}

/**
  * @brief  Return gpio alternate function of a dedicated pin for a dedicated port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_AF_0
  *         @arg @ref DDL_GPIO_AF_1
  *         @arg @ref DDL_GPIO_AF_2
  *         @arg @ref DDL_GPIO_AF_3
  */
__STATIC_INLINE uint32_t DDL_GPIO_GetAFPin(GPIO_Type GPIOx, uint32_t Pin)
{
    volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->AFSELR1) ,GPIOx);
    return (uint32_t)(READ_BIT((*reg),
                               (GPIO_ALF_ALFSEL0 << (POSITION_VAL(Pin) * 2U))) >> (POSITION_VAL(Pin) * 2U));
}

/**
  * @brief  Enable the wave filter for a certain pin of the specified GPIO port.
  * @note   This function sets the corresponding FLTEN bit in the GPIO_FILTERR register
  *         to enable the filtering feature for the selected pin.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_EnablePinFilter(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->FILTERR1), GPIOx);
  SET_BIT16((reg), (Pin & DDL_GPIO_PIN_ALL));
}

/**
  * @brief  Disable the wave filter for a certain pin of the specified GPIO port.
  * @note   This function clears the corresponding FLTEN bit in the GPIO_FILTERR register
  *         to disable the filtering feature for the selected pin.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_DisablePinFilter(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->FILTERR1), GPIOx);
  CLEAR_BIT16((reg), (Pin & DDL_GPIO_PIN_ALL));
}

/**
  * @brief  Check whether the wave filter for a certain pin is enabled or disabled.
  * @note   This function reads the corresponding FLTEN bit in the GPIO_FILTERR register
  *         to determine the filtering status of the selected pin.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsEnabledPinFilter(GPIO_Type GPIOx, uint32_t Pin)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->FILTERR1), GPIOx);
  uint32_t pinMask = (Pin & DDL_GPIO_PIN_ALL);
  return (uint32_t)(READ_BIT16((reg), pinMask) == pinMask);
}

/**
  * @}
  */

/** @defgroup GPIO_DDL_EF_Data_Access Data Access
  * @{
  */

/**
  * @brief  Return full input data register value for a dedicated port.
  * @param  GPIOx GPIO port.
  * @retval Input data register value of port
  */
__STATIC_INLINE uint32_t DDL_GPIO_ReadInputPort(GPIO_Type GPIOx)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->IDR1), GPIOx);
  return (uint32_t)(READ_REG16(reg));
}

/**
  * @brief  Return if input data level for several pins of a dedicated port is high or low.
  * @param  GPIOx GPIO Port.
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsInputPinSet(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->IDR1), GPIOx);
  return ((READ_BIT16((reg), PinMask) == (PinMask)) ? 1UL : 0UL);
}

/**
  * @brief  Write output data register for the port.
  * @param  GPIOx GPIO Port.
  * @param  PortValue Level value for each pin of the port. limited in 0x0000 - 0xffff
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_WriteOutputPort(GPIO_Type GPIOx, uint32_t PortValue)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->ODR1), GPIOx);
  WRITE_REG16((reg), PortValue);
}

/**
  * @brief  Return full output data register value for a dedicated port.
  * @param  GPIOx GPIO Port
  * @retval Output data register value of port
  */
__STATIC_INLINE uint32_t DDL_GPIO_ReadOutputPort(GPIO_Type GPIOx)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->ODR1), GPIOx);
  return (uint32_t)(READ_REG16((reg)));
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_GPIO_IsOutputPinSet(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->ODR1), GPIOx);
  return ((READ_BIT16((reg), PinMask) == (PinMask)) ? 1UL : 0UL);
}

/**
  * @brief  Set several pins to high level on dedicated gpio port.
  * @param  GPIOx GPIO Port.
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_SetOutputPin(GPIO_Type GPIOx, uint32_t PinMask)
{    
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->BSRR1), GPIOx);
  SET_BIT((*reg), (PinMask));
}

/**
  * @brief  Set several pins to low level on dedicated gpio port.
  * @param  GPIOx GPIO Port.
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_ResetOutputPin(GPIO_Type GPIOx, uint32_t PinMask)
{
  volatile uint32_t *reg = (volatile uint32_t*)DDL_GPIO_Locate32BitReg((uint32_t)(&GPIO->BSRR1), GPIOx);
  SET_BIT((*reg), (PinMask << 16));
}

/**
  * @brief  Toggle data value for several pin of dedicated port.
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref DDL_GPIO_PIN_0
  *         @arg @ref DDL_GPIO_PIN_1
  *         @arg @ref DDL_GPIO_PIN_2
  *         @arg @ref DDL_GPIO_PIN_3
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_7
  *         @arg @ref DDL_GPIO_PIN_8
  *         @arg @ref DDL_GPIO_PIN_9
  *         @arg @ref DDL_GPIO_PIN_10
  *         @arg @ref DDL_GPIO_PIN_11
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_13
  *         @arg @ref DDL_GPIO_PIN_14
  *         @arg @ref DDL_GPIO_PIN_15
  *         @arg @ref DDL_GPIO_PIN_ALL
  * @retval None
  */
__STATIC_INLINE void DDL_GPIO_TogglePin(GPIO_Type GPIOx, uint32_t PinMask)
{
  uint32_t odr = 0;
 volatile uint16_t *reg = DDL_GPIO_Locate16BitReg((&GPIO->ODR1), GPIOx);    
  odr = READ_REG16((reg));
  MODIFY_REG16((reg), (odr & PinMask), (~odr & PinMask));
}

/**
  * @brief  Enable ADC3 analog switch bits in SWR for the given GPIO port.
  * @note   Call this only after configuring the pin as analog and only when the
  *         pin is used as the listed ADC3 channel. DDL_GPIO_Init() leaves SWR at 0.
  *         Do not use this API for ADC16 GPIO (Init leaves SWR at 0).
  *         Do not use this API for 5VIO pins (PB4, PB6, PC12, PD5, PD12); use
  *         @ref DDL_GPIO_SetSpecialPinType() instead.
  *         Do not use for PD15 (not ADC3; not in the 5VIO table; for EVS keep
  *         SWR at 0 per SWR supplement V1.1 rule 3).
  * @param  GPIOx GPIO Port.
  * @param  PinMask Combination of pins allowed for this port:
  *         GPIOB: @ref DDL_GPIO_PIN_2 (ADC3_CH0), @ref DDL_GPIO_PIN_3 (ADC3_CH1),
  *                @ref DDL_GPIO_PIN_5 (ADC3_CH2)
  *         GPIOC: @ref DDL_GPIO_PIN_3 (ADC3_CH0), @ref DDL_GPIO_PIN_4 (ADC3_CH1),
  *                @ref DDL_GPIO_PIN_5 (ADC3_CH2), @ref DDL_GPIO_PIN_6 (ADC3_CH3),
  *                @ref DDL_GPIO_PIN_9 (ADC3_CH6), @ref DDL_GPIO_PIN_10 (ADC3_CH7),
  *                @ref DDL_GPIO_PIN_11 (ADC3_CH8)
  *         GPIOD: @ref DDL_GPIO_PIN_0 (ADC3_CH10), @ref DDL_GPIO_PIN_1 (ADC3_CH11),
  *                @ref DDL_GPIO_PIN_2 (ADC3_CH12)
  * @retval None
  */
void DDL_GPIO_EnableAdc3AnalogSwitchPin(GPIO_Type GPIOx, uint32_t PinMask);

/**
  * @brief  Disable ADC3 analog switch bits in SWR for the given GPIO port.
  * @note   Same pin whitelist as @ref DDL_GPIO_EnableAdc3AnalogSwitchPin.
  * @param  GPIOx GPIO Port.
  * @param  PinMask Combination of pins allowed for this port (see Enable API).
  * @retval None
  */
void DDL_GPIO_DisableAdc3AnalogSwitchPin(GPIO_Type GPIOx, uint32_t PinMask);

/**
  * @brief  Configure special pin type for the dedicated special GPIO pin.
  * @note   This API is only applicable to the following GPIO/pin combinations:
  *         @arg GPIOB + @ref DDL_GPIO_PIN_4
  *         @arg GPIOB + @ref DDL_GPIO_PIN_6
  *         @arg GPIOC + @ref DDL_GPIO_PIN_12
  *         @arg GPIOD + @ref DDL_GPIO_PIN_5
  *         @arg GPIOD + @ref DDL_GPIO_PIN_12
  *         @arg GPIOD + @ref DDL_GPIO_PIN_15
  * @note   For 5VIO pins PB4, PB6, PC12, PD5, PD12 (SWR supplement V1.1 table):
  *         SWR 0 = digital 5 V-tolerant input, SWR 1 = analog 3.3 V input/output.
  * @note   PD15 is not in the 5VIO table. For EVS, keep SWR at 0 (recommended);
  *         SWR=1 does not block EVS. Do not select
  *         @ref DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT on PD15.
  *         This API may still be used on PD15 (e.g. USART) to force SWR=0 via
  *         @ref DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT.
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  PinMask This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_15
  * @param  PinType This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT
  *         @arg @ref DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT
  */
void DDL_GPIO_SetSpecialPinType(GPIO_Type GPIOx, uint32_t PinMask, uint32_t PinType);

/**
  * @brief  Return special pin type configuration for the dedicated special GPIO pin.
  * @note   This API is only applicable to the following GPIO/pin combinations:
  *         @arg GPIOB + @ref DDL_GPIO_PIN_4
  *         @arg GPIOB + @ref DDL_GPIO_PIN_6
  *         @arg GPIOC + @ref DDL_GPIO_PIN_12
  *         @arg GPIOD + @ref DDL_GPIO_PIN_5
  *         @arg GPIOD + @ref DDL_GPIO_PIN_12
  *         @arg GPIOD + @ref DDL_GPIO_PIN_15
  * @note   Warning: only one pin can be passed as parameter.
  * @param  GPIOx GPIO port.
  * @param  PinMask This parameter can be one of the following values:
  *         @arg @ref DDL_GPIO_PIN_4
  *         @arg @ref DDL_GPIO_PIN_5
  *         @arg @ref DDL_GPIO_PIN_6
  *         @arg @ref DDL_GPIO_PIN_12
  *         @arg @ref DDL_GPIO_PIN_15
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_GPIO_SPECIAL_PIN_TYPE_DIGITAL_5V_INPUT
  *         @arg @ref DDL_GPIO_SPECIAL_PIN_TYPE_ANALOG_3V3_INPUT_OUTPUT
  */
uint32_t DDL_GPIO_GetSpecialPinType(GPIO_Type GPIOx, uint32_t PinMask);

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup GPIO_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_GPIO_DeInit(GPIO_Type GPIOx);
ErrorStatus DDL_GPIO_Init(GPIO_Type GPIOx, DDL_GPIO_InitTypeDef *GPIO_InitStruct);
void        DDL_GPIO_StructInit(DDL_GPIO_InitTypeDef *GPIO_InitStruct);

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

#endif /* defined (GPIO) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_GPIO_H */

