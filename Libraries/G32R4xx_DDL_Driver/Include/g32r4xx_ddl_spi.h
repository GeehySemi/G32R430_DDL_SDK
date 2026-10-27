/**
  *
  * @file    g32r4xx_ddl_spi.h
  * @brief   Header file of SPI DDL module.
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
  * Copyright (c) 2016 STMicroelectronics.
  * Copyright (C) 2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef g32r4xx_DDL_SPI_H
#define g32r4xx_DDL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"
#include "g32r430.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */
#if defined (SPI1)

/** @defgroup SPI_DDL SPI
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SPI_DDL_ES_INIT SPI Exported Init structure
  * @{
  */

/**
  * @brief  SPI Init structures definition
  */
typedef struct
{
  uint32_t TransferDirection;       /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_DDL_EC_TRANSFER_MODE.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetTransferDirection().*/

  uint32_t Mode;                    /*!< Specifies the SPI mode (Master/Slave).
                                         This parameter can be a value of @ref SPI_DDL_EC_MODE.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetMode().*/

  uint32_t DataWidth;               /*!< Specifies the SPI data width.
                                         This parameter can be a value of @ref SPI_DDL_EC_DATAWIDTH.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetDataWidth().*/

  uint32_t ClockPolarity;           /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_DDL_EC_POLARITY.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetClockPolarity().*/

  uint32_t ClockPhase;              /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_DDL_EC_PHASE.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetClockPhase().*/

  uint32_t NSS;                     /*!< Specifies whether the NSS signal is managed by hardware (NSS pin) or by software using the SSI bit.
                                         This parameter can be a value of @ref SPI_DDL_EC_NSS_MODE.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetNSSMode().*/

  uint32_t BaudRate;                /*!< Specifies the BaudRate prescaler value which will be used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of @ref SPI_DDL_EC_BAUDRATEPRESCALER.
                                         @note The communication clock is derived from the master clock. The slave clock does not need to be set.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetBaudRatePrescaler().*/

  uint32_t BitOrder;                /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref SPI_DDL_EC_BIT_ORDER.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetTransferBitOrder().*/

  uint32_t CRCCalculation;          /*!< Specifies if the CRC calculation is enabled or not.
                                         This parameter can be a value of @ref SPI_DDL_EC_CRC_CALCULATION.

                                         This feature can be modified afterwards using unitary functions @ref DDL_SPI_EnableCRC() and @ref DDL_SPI_DisableCRC().*/

  uint32_t CRCPoly;                 /*!< Specifies the polynomial used for the CRC calculation.
                                         This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFFFF.

                                         This feature can be modified afterwards using unitary function @ref DDL_SPI_SetCRCPolynomial().*/

} DDL_SPI_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SPI_DDL_Exported_Constants SPI Exported Constants
  * @{
  */

/** @defgroup SPI_DDL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with DDL_SPI_ReadReg function
  * @{
  */
#define DDL_SPI_STS_RXBNEFLG  SPI_STS_RXBNEFLG  /*!< Rx buffer not empty flag         */
#define DDL_SPI_STS_TXBEFLG   SPI_STS_TXBEFLG   /*!< Tx buffer empty flag             */
#define DDL_SPI_STS_BSYFLG    SPI_STS_BSYFLG    /*!< Busy flag                        */
#define DDL_SPI_STS_CRCEFLG   SPI_STS_CRCEFLG   /*!< CRC error flag                   */
#define DDL_SPI_STS_MEFLG     SPI_STS_MEFLG     /*!< Mode fault flag                  */
#define DDL_SPI_STS_OVRFLG    SPI_STS_OVRFLG    /*!< Overrun flag                     */
#define DDL_SPI_STS_FREFLG    SPI_STS_FREFLG    /*!< TI mode frame format error flag  */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_IT IT Defines
  * @brief    IT defines which can be used with DDL_SPI_ReadReg and  DDL_SPI_WriteReg functions
  * @{
  */
#define DDL_SPI_CTRL2_RXBNEIEN  SPI_CTRL2_RXBNEIEN  /*!< Rx buffer not empty interrupt enable */
#define DDL_SPI_CTRL2_TXBEIEN   SPI_CTRL2_TXBEIEN   /*!< Tx buffer empty interrupt enable     */
#define DDL_SPI_CTRL2_ERRIEN    SPI_CTRL2_ERRIEN    /*!< Error interrupt enable               */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_MODE Operation Mode
  * @{
  */
#define DDL_SPI_MODE_MASTER  (SPI_CTRL1_MSMCFG | SPI_CTRL1_ISSEL)  /*!< Master configuration  */
#define DDL_SPI_MODE_SLAVE   0x00000000U                           /*!< Slave configuration   */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_PROTOCOL Serial Protocol
  * @{
  */
#define DDL_SPI_PROTOCOL_MOTOROLA  0x00000000U         /*!< Motorola mode. Used as default value */
#define DDL_SPI_PROTOCOL_TI        (SPI_CTRL2_FRFCFG)  /*!< TI mode                              */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_PHASE Clock Phase
  * @{
  */
#define DDL_SPI_PHASE_1EDGE  0x00000000U       /*!< First clock transition is the first data capture edge  */
#define DDL_SPI_PHASE_2EDGE  (SPI_CTRL1_CPHA)  /*!< Second clock transition is the first data capture edge */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_POLARITY Clock Polarity
  * @{
  */
#define DDL_SPI_POLARITY_LOW   0x00000000U       /*!< Clock to 0 when idle */
#define DDL_SPI_POLARITY_HIGH  (SPI_CTRL1_CPOL)  /*!< Clock to 1 when idle */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_BAUDRATEPRESCALER Baud Rate Prescaler
  * @{
  */
#define DDL_SPI_BAUDRATEPRESCALER_DIV2    (0x00000000U)                            /*!< BaudRate control equal to fPCLK/2   */
#define DDL_SPI_BAUDRATEPRESCALER_DIV4    (SPI_CTRL1_BRSEL_0)                      /*!< BaudRate control equal to fPCLK/4   */
#define DDL_SPI_BAUDRATEPRESCALER_DIV8    (SPI_CTRL1_BRSEL_1)                      /*!< BaudRate control equal to fPCLK/8   */
#define DDL_SPI_BAUDRATEPRESCALER_DIV16   (SPI_CTRL1_BRSEL_1 | SPI_CTRL1_BRSEL_0)  /*!< BaudRate control equal to fPCLK/16  */
#define DDL_SPI_BAUDRATEPRESCALER_DIV32   (SPI_CTRL1_BRSEL_2)                      /*!< BaudRate control equal to fPCLK/32  */
#define DDL_SPI_BAUDRATEPRESCALER_DIV64   (SPI_CTRL1_BRSEL_2 | SPI_CTRL1_BRSEL_0)  /*!< BaudRate control equal to fPCLK/64  */
#define DDL_SPI_BAUDRATEPRESCALER_DIV128  (SPI_CTRL1_BRSEL_2 | SPI_CTRL1_BRSEL_1)  /*!< BaudRate control equal to fPCLK/128 */
#define DDL_SPI_BAUDRATEPRESCALER_DIV256  (SPI_CTRL1_BRSEL)                        /*!< BaudRate control equal to fPCLK/256 */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_BIT_ORDER Transmission Bit Order
  * @{
  */
#define DDL_SPI_LSB_FIRST  (SPI_CTRL1_LSBSEL)  /*!< Data is transmitted/received with the LSB first */
#define DDL_SPI_MSB_FIRST  0x00000000U         /*!< Data is transmitted/received with the MSB first */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_TRANSFER_MODE Transfer Mode
  * @{
  */
#define DDL_SPI_FULL_DUPLEX     0x00000000U                         /*!< Full-Duplex mode. Rx and Tx transfer on 2 lines */
#define DDL_SPI_SIMPLEX_RX      (SPI_CTRL1_RXOMEN)                  /*!< Simplex Rx mode.  Rx transfer only on 1 line    */
#define DDL_SPI_HALF_DUPLEX_RX  (SPI_CTRL1_BMEN)                    /*!< Half-Duplex Rx mode. Rx transfer on 1 line      */
#define DDL_SPI_HALF_DUPLEX_TX  (SPI_CTRL1_BMEN | SPI_CTRL1_BMOEN)  /*!< Half-Duplex Tx mode. Tx transfer on 1 line      */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_NSS_MODE Slave Select Pin Mode
  * @{
  */
#define DDL_SPI_NSS_SOFT         (SPI_CTRL1_SSEN)                      /*!< NSS managed internally. NSS pin not used and free              */
#define DDL_SPI_NSS_HARD_INPUT   0x00000000U                           /*!< NSS pin used in Input. Only used in Master mode                */
#define DDL_SPI_NSS_HARD_OUTPUT  (((uint32_t)SPI_CTRL2_SSOEN << 16U))  /*!< NSS pin used in Output. Only used in Slave mode as chip select */
/**
  * @}
  */

/** @defgroup SPI_DDL_EC_DATAWIDTH Datawidth
  * @{
  */
#define DDL_SPI_DATAWIDTH_8BIT   0x00000000U         /*!< Data length for SPI transfer:  8 bits */
#define DDL_SPI_DATAWIDTH_16BIT  (SPI_CTRL1_DFLSEL)  /*!< Data length for SPI transfer:  16 bits */
/**
  * @}
  */
#if defined(USE_FULL_DDL_DRIVER)

/** @defgroup SPI_DDL_EC_CRC_CALCULATION CRC Calculation
  * @{
  */
#define DDL_SPI_CRCCALCULATION_DISABLE  0x00000000U        /*!< CRC calculation disabled */
#define DDL_SPI_CRCCALCULATION_ENABLE   (SPI_CTRL1_CRCEN)  /*!< CRC calculation enabled  */
/**
  * @}
  */
#endif /* USE_FULL_DDL_DRIVER */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup SPI_DDL_Exported_Macros SPI Exported Macros
  * @{
  */

/** @defgroup SPI_DDL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in SPI register
  * @param  __INSTANCE__ SPI Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define DDL_SPI_WriteReg(__INSTANCE__,  __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in SPI register
  * @param  __INSTANCE__ SPI Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define DDL_SPI_ReadReg(__INSTANCE__,  __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SPI_DDL_Exported_Functions SPI Exported Functions
  * @{
  */

/** @defgroup SPI_DDL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Enable SPI peripheral
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_Enable(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL1, SPI_CTRL1_SPIEN);
}

/**
  * @brief  Disable SPI peripheral
  * @note   When disabling the SPI, follow the procedure described in the Reference Manual.
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_Disable(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL1, SPI_CTRL1_SPIEN);
}

/**
  * @brief  Check if SPI peripheral is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabled(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL1, SPI_CTRL1_SPIEN) == (SPI_CTRL1_SPIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set SPI operation mode to Master or Slave
  * @note   This bit should not be changed when communication is ongoing.
  * @param  SPIx SPI Instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_MODE_MASTER
  *         @arg @ref DDL_SPI_MODE_SLAVE
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetMode(SPI_TypeDef *SPIx, uint32_t Mode)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_MSMCFG | SPI_CTRL1_ISSEL, Mode);
}

/**
  * @brief  Get SPI operation mode (Master or Slave)
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_MODE_MASTER
  *         @arg @ref DDL_SPI_MODE_SLAVE
  */
__STATIC_INLINE uint32_t DDL_SPI_GetMode(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_MSMCFG | SPI_CTRL1_ISSEL));
}

/**
  * @brief  Set serial protocol used
  * @note   This bit should be written only when SPI is disabled (SPE = 0) for correct operation.
  * @param  SPIx SPI Instance
  * @param  Standard This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_PROTOCOL_MOTOROLA
  *         @arg @ref DDL_SPI_PROTOCOL_TI
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetStandard(SPI_TypeDef *SPIx, uint32_t Standard)
{
  MODIFY_REG(SPIx->CTRL2, SPI_CTRL2_FRFCFG, Standard);
}

/**
  * @brief  Get serial protocol used
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_PROTOCOL_MOTOROLA
  *         @arg @ref DDL_SPI_PROTOCOL_TI
  */
__STATIC_INLINE uint32_t DDL_SPI_GetStandard(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL2, SPI_CTRL2_FRFCFG));
}

/**
  * @brief  Set clock phase
  * @note   This bit should not be changed when communication is ongoing.
  *         This bit is not used in SPI TI mode.
  * @param  SPIx SPI Instance
  * @param  ClockPhase This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_PHASE_1EDGE
  *         @arg @ref DDL_SPI_PHASE_2EDGE
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetClockPhase(SPI_TypeDef *SPIx, uint32_t ClockPhase)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_CPHA, ClockPhase);
}

/**
  * @brief  Get clock phase
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_PHASE_1EDGE
  *         @arg @ref DDL_SPI_PHASE_2EDGE
  */
__STATIC_INLINE uint32_t DDL_SPI_GetClockPhase(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_CPHA));
}

/**
  * @brief  Set clock polarity
  * @note   This bit should not be changed when communication is ongoing.
  *         This bit is not used in SPI TI mode.
  * @param  SPIx SPI Instance
  * @param  ClockPolarity This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_POLARITY_LOW
  *         @arg @ref DDL_SPI_POLARITY_HIGH
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetClockPolarity(SPI_TypeDef *SPIx, uint32_t ClockPolarity)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_CPOL, ClockPolarity);
}

/**
  * @brief  Get clock polarity
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_POLARITY_LOW
  *         @arg @ref DDL_SPI_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t DDL_SPI_GetClockPolarity(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_CPOL));
}

/**
  * @brief  Set baud rate prescaler
  * @note   These bits should not be changed when communication is ongoing. SPI BaudRate = fPCLK/Prescaler.
  * @param  SPIx SPI Instance
  * @param  BaudRate This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV2
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV4
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV8
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV16
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV32
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV64
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV128
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV256
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetBaudRatePrescaler(SPI_TypeDef *SPIx, uint32_t BaudRate)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_BRSEL, BaudRate);
}

/**
  * @brief  Get baud rate prescaler
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV2
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV4
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV8
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV16
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV32
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV64
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV128
  *         @arg @ref DDL_SPI_BAUDRATEPRESCALER_DIV256
  */
__STATIC_INLINE uint32_t DDL_SPI_GetBaudRatePrescaler(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_BRSEL));
}

/**
  * @brief  Set transfer bit order
  * @note   This bit should not be changed when communication is ongoing. This bit is not used in SPI TI mode.
  * @param  SPIx SPI Instance
  * @param  BitOrder This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_LSB_FIRST
  *         @arg @ref DDL_SPI_MSB_FIRST
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetTransferBitOrder(SPI_TypeDef *SPIx, uint32_t BitOrder)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_LSBSEL, BitOrder);
}

/**
  * @brief  Get transfer bit order
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_LSB_FIRST
  *         @arg @ref DDL_SPI_MSB_FIRST
  */
__STATIC_INLINE uint32_t DDL_SPI_GetTransferBitOrder(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_LSBSEL));
}

/**
  * @brief  Set transfer direction mode
  * @note   For Half-Duplex mode, Rx Direction is set by default.
  *         In master mode, the MOSI pin is used and in slave mode, the MISO pin is used for Half-Duplex.
  * @param  SPIx SPI Instance
  * @param  TransferDirection This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_FULL_DUPLEX
  *         @arg @ref DDL_SPI_SIMPLEX_RX
  *         @arg @ref DDL_SPI_HALF_DUPLEX_RX
  *         @arg @ref DDL_SPI_HALF_DUPLEX_TX
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetTransferDirection(SPI_TypeDef *SPIx, uint32_t TransferDirection)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_RXOMEN | SPI_CTRL1_BMEN | SPI_CTRL1_BMOEN, TransferDirection);
}

/**
  * @brief  Get transfer direction mode
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_FULL_DUPLEX
  *         @arg @ref DDL_SPI_SIMPLEX_RX
  *         @arg @ref DDL_SPI_HALF_DUPLEX_RX
  *         @arg @ref DDL_SPI_HALF_DUPLEX_TX
  */
__STATIC_INLINE uint32_t DDL_SPI_GetTransferDirection(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_RXOMEN | SPI_CTRL1_BMEN | SPI_CTRL1_BMOEN));
}

/**
  * @brief  Set frame data width
  * @param  SPIx SPI Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_DATAWIDTH_8BIT
  *         @arg @ref DDL_SPI_DATAWIDTH_16BIT
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetDataWidth(SPI_TypeDef *SPIx, uint32_t DataWidth)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_DFLSEL, DataWidth);
}

/**
  * @brief  Get frame data width
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_DATAWIDTH_8BIT
  *         @arg @ref DDL_SPI_DATAWIDTH_16BIT
  */
__STATIC_INLINE uint32_t DDL_SPI_GetDataWidth(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRL1, SPI_CTRL1_DFLSEL));
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_BISS_Configuration Biss Configuration
  * @{
  */

/**
  * @brief  Enable Biss-c mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_EnableBiss(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->BCR, SPI_BCR_BISS_EN);
}

/**
  * @brief  Disable Biss-c mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_DisableBiss(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->BCR, SPI_BCR_BISS_EN);
}

/**
  * @brief  Check Biss-c mode is enable
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_IsEnabledBiss(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->BCR, SPI_BCR_BISS_EN) == SPI_BCR_BISS_EN) ? 1UL : 0UL);
}

/**
  * @brief  Enable Ssi mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_EnableSsi(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->BCR, SPI_BCR_SSI_EN);
}

/**
  * @brief  Disable Ssi mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_DisableSsi(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->BCR, SPI_BCR_SSI_EN);
}

/**
  * @brief  Check Ssi mode is enable
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_IsEnabledSsi(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->BCR, SPI_BCR_SSI_EN) == SPI_BCR_SSI_EN) ? 1UL : 0UL);
}

/**
  * @brief  Enable Stop mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_EnableStop(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->BCR, SPI_BCR_STOP_EN);
}

/**
  * @brief  Disable Stop mode
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_DisableStop(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->BCR, SPI_BCR_STOP_EN);
}

/**
  * @brief  Check Stop mode is enable
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_IsEnabledStop(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->BCR, SPI_BCR_STOP_EN) == SPI_BCR_STOP_EN) ? 1UL : 0UL);
}

/**
  * @brief  Set BISS timeout
  * @param  SPIx SPI Instance
  * @param  Timeout This parameter can between 0x0 to 0x2F
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_SetTimeout(SPI_TypeDef *SPIx, uint32_t Timeout)
{
  MODIFY_REG(SPIx->BCFG, SPI_BCFG_TOPER, (Timeout << SPI_BCFG_TOPER_Pos) );
}

/**
  * @brief  Get BISS timeout
  * @param  SPIx SPI Instance
  * @retval Returned value can between 0x0 to 0x2F
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_GetTimeout(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->BCFG, SPI_BCFG_TOPER) >> SPI_BCFG_TOPER_Pos);
}

/**
  * @brief  Set BISS frequency
  * @param  SPIx SPI Instance
  * @param  Frequency This parameter can between 0x0 to 0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_BISS_SetFrequency(SPI_TypeDef *SPIx, uint32_t Frequency)
{
  MODIFY_REG(SPIx->BCFG, SPI_BCFG_SPISYSCLK, Frequency);
}

/**
  * @brief  Get BISS frequency
  * @param  SPIx SPI Instance
  * @retval Returned value can between 0x0 to 0xFF
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_GetFrequency(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->BCFG, SPI_BCFG_SPISYSCLK));
}

/**
  * @brief  Receive CDM data
  * @param  SPIx SPI Instance
  * @retval Returned value can between 0x0 to 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_SPI_BISS_ReceiveCDMData(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CDMDATA, SPI_CDMDATA_DATA));
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_CRC_Management CRC Management
  * @{
  */

/**
  * @brief  Enable CRC
  * @note   This bit should be written only when SPI is disabled (SPE = 0) for correct operation.
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableCRC(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL1, SPI_CTRL1_CRCEN);
}

/**
  * @brief  Disable CRC
  * @note   This bit should be written only when SPI is disabled (SPE = 0) for correct operation.
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableCRC(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL1, SPI_CTRL1_CRCEN);
}

/**
  * @brief  Check if CRC is enabled
  * @note   This bit should be written only when SPI is disabled (SPE = 0) for correct operation.
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledCRC(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL1, SPI_CTRL1_CRCEN) == (SPI_CTRL1_CRCEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set CRCNext to transfer CRC on the line
  * @note   This bit has to be written as soon as the last data is written in the SPIx_DR register.
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetCRCNext(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL1, SPI_CTRL1_CRCNXT);
}

/**
  * @brief  Set polynomial for CRC calculation
  * @param  SPIx SPI Instance
  * @param  CRCPoly This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetCRCPolynomial(SPI_TypeDef *SPIx, uint32_t CRCPoly)
{
  WRITE_REG(SPIx->CRCPOLY, (uint16_t)CRCPoly);
}

/**
  * @brief  Get polynomial for CRC calculation
  * @param  SPIx SPI Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_SPI_GetCRCPolynomial(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->CRCPOLY));
}

/**
  * @brief  Get Rx CRC
  * @param  SPIx SPI Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_SPI_GetRxCRC(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->RXCRC));
}

/**
  * @brief  Get Tx CRC
  * @param  SPIx SPI Instance
  * @retval Returned value is a number between Min_Data = 0x00 and Max_Data = 0xFFFF
  */
__STATIC_INLINE uint32_t DDL_SPI_GetTxCRC(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->TXCRC));
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_NSS_Management Slave Select Pin Management
  * @{
  */

/**
  * @brief  Set NSS mode
  * @note   DDL_SPI_NSS_SOFT Mode is not used in SPI TI mode.
  * @param  SPIx SPI Instance
  * @param  NSS This parameter can be one of the following values:
  *         @arg @ref DDL_SPI_NSS_SOFT
  *         @arg @ref DDL_SPI_NSS_HARD_INPUT
  *         @arg @ref DDL_SPI_NSS_HARD_OUTPUT
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_SetNSSMode(SPI_TypeDef *SPIx, uint32_t NSS)
{
  MODIFY_REG(SPIx->CTRL1, SPI_CTRL1_SSEN,  NSS);
  MODIFY_REG(SPIx->CTRL2, SPI_CTRL2_SSOEN, ((uint32_t)(NSS >> 16U)));
}

/**
  * @brief  Get NSS mode
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref DDL_SPI_NSS_SOFT
  *         @arg @ref DDL_SPI_NSS_HARD_INPUT
  *         @arg @ref DDL_SPI_NSS_HARD_OUTPUT
  */
__STATIC_INLINE uint32_t DDL_SPI_GetNSSMode(SPI_TypeDef *SPIx)
{
  uint32_t Ssm  = (READ_BIT(SPIx->CTRL1, SPI_CTRL1_SSEN));
  uint32_t Ssoe = (READ_BIT(SPIx->CTRL2,  SPI_CTRL2_SSOEN) << 16U);
  return (Ssm | Ssoe);
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_FLAG_Management FLAG Management
  * @{
  */

/**
  * @brief  Check if Rx buffer is not empty
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_RXNE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_RXBNEFLG) == (SPI_STS_RXBNEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Tx buffer is empty
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_TXE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_TXBEFLG) == (SPI_STS_TXBEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Get CRC error flag
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_CRCERR(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_CRCEFLG) == (SPI_STS_CRCEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear CRC error flag
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_ClearFlag_CRCERR(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->STS, SPI_STS_CRCEFLG);
}

/**
  * @brief  Get mode fault error flag
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_MODF(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_MEFLG) == (SPI_STS_MEFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear mode fault error flag
  * @note   Clearing this flag is done by a read access to the SPIx_STS
  *         register followed by a write access to the SPIx_CTRL1 register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_ClearFlag_MODF(SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg_sr;
  tmpreg_sr = SPIx->STS;
  (void) tmpreg_sr;
  CLEAR_BIT(SPIx->CTRL1, SPI_CTRL1_SPIEN);
}

/**
  * @brief  Get overrun error flag
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_OVR(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_OVRFLG) == (SPI_STS_OVRFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear overrun error flag
  * @note   Clearing this flag is done by a read access to the SPIx_DATA
  *         register followed by a read access to the SPIx_SR register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_ClearFlag_OVR(SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg;
  tmpreg = SPIx->DATA;
  (void) tmpreg;
  tmpreg = SPIx->STS;
  (void) tmpreg;
}

/**
  * @brief  Get busy flag
  * @note   The BSY flag is cleared under any one of the following conditions:
  * -When the SPI is correctly disabled
  * -When a fault is detected in Master mode (MODF bit set to 1)
  * -In Master mode, when it finishes a data transmission and no new data is ready to be
  * sent
  * -In Slave mode, when the BSY flag is set to '0' for at least one SPI clock cycle between
  * each data transfer.
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_BSY(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_BSYFLG) == (SPI_STS_BSYFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Get frame format error flag
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_FRE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_FREFLG) == (SPI_STS_FREFLG)) ? 1UL : 0UL);
}

/**
  * @brief  Clear frame format error flag
  * @note   Clearing this flag is done by reading SPIx_STS register
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_ClearFlag_FRE(SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg;
  tmpreg = SPIx->STS;
  (void) tmpreg;
}

/**
  * @brief  Check if CDM is not empty
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_CDM_NE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_CDM_NE) == (SPI_STS_CDM_NE)) ? 1UL : 0UL);
}

/**
  * @brief  Get Biss busy flag
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsActiveFlag_BSBUSY(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->STS, SPI_STS_BSBUSY) == (SPI_STS_BSBUSY)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_IT_Management Interrupt Management
  * @{
  */

/**
  * @brief  Enable error interrupt
  * @note   This bit controls the generation of an interrupt when an error condition occurs (CRCERR, OVR, MODF in SPI mode, FRE at TI mode).
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableIT_ERR(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL2, SPI_CTRL2_ERRIEN);
}

/**
  * @brief  Disable error interrupt
  * @note   This bit controls the generation of an interrupt when an error condition occurs (CRCERR, OVR, MODF in SPI mode, FRE at TI mode).
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableIT_ERR(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL2, SPI_CTRL2_ERRIEN);
}

/**
  * @brief  Check if error interrupt is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledIT_ERR(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL2, SPI_CTRL2_ERRIEN) == (SPI_CTRL2_ERRIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Rx buffer not empty interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableIT_RXNE(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL2, SPI_CTRL2_RXBNEIEN);
}

/**
  * @brief  Disable Rx buffer not empty interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableIT_RXNE(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL2, SPI_CTRL2_RXBNEIEN);
}

/**
  * @brief  Check if Rx buffer not empty interrupt is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledIT_RXNE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL2, SPI_CTRL2_RXBNEIEN) == (SPI_CTRL2_RXBNEIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Tx buffer empty interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableIT_TXE(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL2, SPI_CTRL2_TXBEIEN);
}

/**
  * @brief  Disable Tx buffer empty interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableIT_TXE(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL2, SPI_CTRL2_TXBEIEN);
}

/**
  * @brief  Check if Tx buffer empty interrupt
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledIT_TXE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL2, SPI_CTRL2_TXBEIEN) == (SPI_CTRL2_TXBEIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable CDM interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableIT_CDM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->BCR, SPI_BCR_CDM_IE);
}

/**
  * @brief  Disable CDM interrupt
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableIT_CDM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->BCR, SPI_BCR_CDM_IE);
}

/**
  * @brief  Check if CDM interrupt is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledIT_CDM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->BCR, SPI_BCR_CDM_IE) == SPI_BCR_CDM_IE) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_DMA_Management DMA Management
  * @{
  */

/**
  * @brief  Enable DMA Rx
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableDMAReq_RX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL2, SPI_CTRL2_RXDEN);
}

/**
  * @brief  Disable DMA Rx
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableDMAReq_RX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL2, SPI_CTRL2_RXDEN);
}

/**
  * @brief  Check if DMA Rx is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledDMAReq_RX(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL2, SPI_CTRL2_RXDEN) == (SPI_CTRL2_RXDEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA Tx
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableDMAReq_TX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CTRL2, SPI_CTRL2_TXDEN);
}

/**
  * @brief  Disable DMA Tx
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableDMAReq_TX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CTRL2, SPI_CTRL2_TXDEN);
}

/**
  * @brief  Check if DMA Tx is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledDMAReq_TX(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CTRL2, SPI_CTRL2_TXDEN) == (SPI_CTRL2_TXDEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable CDM dma require
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_EnableDMAReq_CDM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->BCR, SPI_BCR_CDM_DMAEN);
}

/**
  * @brief  Disable CDM dma require
  * @param  SPIx SPI Instance
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_DisableDMAReq_CDM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->BCR, SPI_BCR_CDM_DMAEN);
}

/**
  * @brief  Check if CDM dma require is enabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0)
  */
__STATIC_INLINE uint32_t DDL_SPI_IsEnabledDMAReq_CDM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->BCR, SPI_BCR_CDM_DMAEN) == SPI_BCR_CDM_DMAEN) ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @param  SPIx SPI Instance
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t DDL_SPI_DMA_GetRegAddr(SPI_TypeDef *SPIx)
{
  return (uint32_t) &(SPIx->DATA);
}

/**
  * @}
  */

/** @defgroup SPI_DDL_EF_DATA_Management DATA Management
  * @{
  */

/**
  * @brief  Read 8-Bits in the data register
  * @param  SPIx SPI Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t DDL_SPI_ReceiveData8(SPI_TypeDef *SPIx)
{
  return (*((__IO uint8_t *)&SPIx->DATA));
}

/**
  * @brief  Read 16-Bits in the data register
  * @param  SPIx SPI Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint16_t DDL_SPI_ReceiveData16(SPI_TypeDef *SPIx)
{
  return (uint16_t)(READ_REG(SPIx->DATA));
}

/**
  * @brief  Write 8-Bits in the data register
  * @param  SPIx SPI Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_TransmitData8(SPI_TypeDef *SPIx, uint8_t TxData)
{
#if defined (__GNUC__)
  __IO uint8_t *spidr = ((__IO uint8_t *)&SPIx->DATA);
  *spidr = TxData;
#else
  *((__IO uint8_t *)&SPIx->DATA) = TxData;
#endif /* __GNUC__ */
}

/**
  * @brief  Write 16-Bits in the data register
  * @param  SPIx SPI Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void DDL_SPI_TransmitData16(SPI_TypeDef *SPIx, uint16_t TxData)
{
#if defined (__GNUC__)
  __IO uint16_t *spidr = ((__IO uint16_t *)&SPIx->DATA);
  *spidr = TxData;
#else
  SPIx->DATA = TxData;
#endif /* __GNUC__ */
}

/**
  * @}
  */
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup SPI_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus DDL_SPI_DeInit(SPI_TypeDef *SPIx);
ErrorStatus DDL_SPI_Init(SPI_TypeDef *SPIx, DDL_SPI_InitTypeDef *SPI_InitStruct);
void        DDL_SPI_StructInit(DDL_SPI_InitTypeDef *SPI_InitStruct);

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

#endif /* SPI1 */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* G32R4xx_DDL_SPI_H */

