/**
  *
  * @file    g32r4xx_ddl_flash.h
  * @brief   Header file of FLASH DDL module.
  ******************************************************************************
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
  * Copyright (C) 2024-2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef G32R4xx_DDL_FLASH_H
#define G32R4xx_DDL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx.h"

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */

#if defined (FLASH)

/** @defgroup FLASH_DDL FLASH
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup FLASH_DDL_Private_Constants FLASH Private Constants
  * @{
  */

/** @defgroup FLASH_DDL_WAIT_PERIOD  Flash waiting period
  * @{
  */
#define FLASH_DDL_WAIT_PERIOD_0                                (0x00000000UL)
#define FLASH_DDL_WAIT_PERIOD_1                                (FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_2                                (FLASH_CR2_RDWAIT_1)
#define FLASH_DDL_WAIT_PERIOD_3                                (FLASH_CR2_RDWAIT_1 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_4                                (FLASH_CR2_RDWAIT_2)
#define FLASH_DDL_WAIT_PERIOD_5                                (FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_6                                (FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_1)
#define FLASH_DDL_WAIT_PERIOD_7                                (FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_1 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_8                                (FLASH_CR2_RDWAIT_3)
#define FLASH_DDL_WAIT_PERIOD_9                                (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_10                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_1)
#define FLASH_DDL_WAIT_PERIOD_11                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_1 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_12                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_2)
#define FLASH_DDL_WAIT_PERIOD_13                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_0)
#define FLASH_DDL_WAIT_PERIOD_14                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_1)
#define FLASH_DDL_WAIT_PERIOD_15                               (FLASH_CR2_RDWAIT_3 | FLASH_CR2_RDWAIT_2 | FLASH_CR2_RDWAIT_1 | FLASH_CR2_RDWAIT_0)

/**
  * @}
  */

/** @defgroup FLASH_DDL_LOCK  Flash lock
  * @{
  */
#define FLASH_DDL_MAIN_LOCK                                    (FLASH_SR_MAINUNLOCK)
#define FLASH_DDL_MAIN_KEY1                                    (0x96969696UL)
#define FLASH_DDL_MAIN_KEY2                                    (0x3C3C3C3CUL)

#define FLASH_DDL_OPT_LOCK                                     (FLASH_SR_OPUNLOCK)
#define FLASH_DDL_OPT_KEY1                                     (0xAAAABBBBUL)
#define FLASH_DDL_OPT_KEY2                                     (0x44556677UL)

/**
  * @}
  */

/** @defgroup FLASH_DDL_CHIP_ERASE_TYPE  Chip Erase Type
  * @{
  */
#define FLASH_DDL_CHIP_ERASE_TYPE_SECTOR                       (0x00000000UL)
#define FLASH_DDL_CHIP_ERASE_TYPE_BLOCK                        (FLASH_CR1_ERTYPE_0)
#define FLASH_DDL_CHIP_ERASE_TYPE_MAIN                         (FLASH_CR1_ERTYPE_1 | FLASH_CR1_ERTYPE_0)

/**
  * @}
  */

/** @defgroup DDL_FLASH_OPTION_BYTE  Flash option bytes
  * @{
  */
#define DDL_FLASH_READ_PROTECTION_LEVEL_0  ((0xAAUL << FLASH_OBCR1_RDPWBF_Pos) & FLASH_OBCR1_RDPWBF_Msk)
#define DDL_FLASH_READ_PROTECTION_LEVEL_1  ((0xBBUL << FLASH_OBCR1_RDPWBF_Pos) & FLASH_OBCR1_RDPWBF_Msk)
#define DDL_FLASH_READ_PROTECTION_LEVEL_2  ((0xCCUL << FLASH_OBCR1_RDPWBF_Pos) & FLASH_OBCR1_RDPWBF_Msk)

#define DDL_FLASH_WRITE_PROTECTION_ENABLE   (FLASH_OBCR1_WLOCKENBF)
#define DDL_FLASH_WRITE_PROTECTION_DISABLE  (0x00000000UL)

#define DDL_FLASH_IWDT_ENABLE_SOFTWARE  (FLASH_OBCR1_IWDTSWBF)
#define DDL_FLASH_IWDT_ENABLE_HARDWARE  (0x00000000UL)

#define DDL_FLASH_WWDT_ENABLE_SOFTWARE  (FLASH_OBCR1_WWDTSWBF)
#define DDL_FLASH_WWDT_ENABLE_HARDWARE  (0x00000000UL)

#define DDL_FLASH_NMI_ENABLE   (FLASH_OBCR1_NMIDISWBF)
#define DDL_FLASH_NMI_DISABLE  (0x00000000UL)

#define DDL_FLASH_ADC_TRIM_SOFTWARE  (0x00000000)
#define DDL_FLASH_ADC_TRIM_HARDWARE  FLASH_OBCR1_ADTSLOADWBF

#define DDL_FLASH_SECTOR_NONE     (0x00000000)
#define DDL_FLASH_SECTOR_0_31     (FLASH_OBCR1_WLOCKBF_0)
#define DDL_FLASH_SECTOR_32_63    (FLASH_OBCR1_WLOCKBF_1)
#define DDL_FLASH_SECTOR_64_95    (FLASH_OBCR1_WLOCKBF_2)
#define DDL_FLASH_SECTOR_96_127   (FLASH_OBCR1_WLOCKBF_3)
#define DDL_FLASH_SECTOR_128_159  (FLASH_OBCR1_WLOCKBF_4)
#define DDL_FLASH_SECTOR_160_191  (FLASH_OBCR1_WLOCKBF_5)
#define DDL_FLASH_SECTOR_192_223  (FLASH_OBCR1_WLOCKBF_6)
#define DDL_FLASH_SECTOR_224_255  (FLASH_OBCR1_WLOCKBF_7)

/**
 * @}
 */

/** @defgroup DDL_FLASH_CACHE  cache.
  * @{
  */

#define DDL_FLASH_CACHE_PRELOAD_ENABLE   FLASH_CR2_PREFETCHEN
#define DDL_FLASH_CACHE_PRELOAD_DISABLE  (0x00000000UL)

/**
  * @}
  */

/** @defgroup Flash common value.
  * @{
  */
#define FLASH_SECTOR_SIZE                                      (512UL)
#define FLASH_MAIN_SIZE                                        (256UL * FLASH_SECTOR_SIZE)

#define FLASH_SYSTEMINFO_BASE  (0x08020000UL)
#define FLASH_MAIN_BASE        (0x08000000UL)

/**
  * @}
  */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FLASH_Exported_Types FLASH Exported Types
  * @{
  */

/** 
  * @brief Flash Options Byte Structure definition  
  */
typedef struct
{
  uint32_t readProtectionLevel;         /* Read Protection Level
                                         * @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_0
                                         * @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_1
                                         * @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_2 */

  uint32_t iwdtSoftwareEnable;          /* IWDT software enabled.
                                         * @arg @ref DDL_FLASH_IWDT_ENABLE_HARDWARE
                                         * @arg @ref DDL_FLASH_IWDT_ENABLE_SOFTWARE */

  uint32_t wwdtSoftwareEnable;          /* WWDT software enabled.
                                         * @arg @ref DDL_FLASH_WWDT_ENABLE_HARDWARE
                                         * @arg @ref DDL_FLASH_WWDT_ENABLE_SOFTWARE */

  uint32_t writeProtectionEnable;       /* Read Protection enabled
                                         * @arg @ref DDL_FLASH_WRITE_PROTECTION_DISABLE
                                         * @arg @ref DDL_FLASH_WRITE_PROTECTION_ENABLE */

  uint32_t nmiEnable;                   /* NMI Pin Enable Configuration
                                         * @arg @ref DDL_FLASH_NMI_DISABLE
                                         * @arg @ref DDL_FLASH_NMI_ENABLE */

  uint32_t adcTrim;                     /* ADC TRIM Configuration
                                         * @arg @ref DDL_FLASH_ADC_TRIM_SOFTWARE
                                         * @arg @ref DDL_FLASH_ADC_TRIM_HARDWARE */

  uint32_t writeProtectionSectors;      /* Write-protected sectors.
                                         * @arg @ref DDL_FLASH_SECTOR_NONE
                                         * @arg @ref DDL_FLASH_SECTOR_0_31
                                         * @arg @ref DDL_FLASH_SECTOR_32_63
                                         * @arg @ref DDL_FLASH_SECTOR_64_95
                                         * @arg @ref DDL_FLASH_SECTOR_96_127
                                         * @arg @ref DDL_FLASH_SECTOR_128_159
                                         * @arg @ref DDL_FLASH_SECTOR_160_191
                                         * @arg @ref DDL_FLASH_SECTOR_192_223
                                         * @arg @ref DDL_FLASH_SECTOR_224_255 */

  uint32_t bootAddr;                    /* Boot Address  0x0000~0xFFFF*/
}DDL_FLASH_OPT_InitTypeDef;

#endif

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup FLASH_DDL_Private_Macros FLASH Private Macros
  * @{
  */
#define __DDL_FLASH_CALCULATE_BOOT_ADDRESS(__BOOT_ADDR__)      \
        (((__BOOT_ADDR__ & 0x8000UL) << 14UL) | ((__BOOT_ADDR__ & 0x7FFF) << 13UL))

#define __DDL_FLASH_IS_VALID_BOOT_ADDRESS(__TRNS_BOOT_ADDR__)  \
        (((__TRNS_BOOT_ADDR__ >= 0x00100000UL) && (__TRNS_BOOT_ADDR__ <= 0x2000BFFFUL)) ? 1UL : 0UL)

#define __DDL_FLASH_WRITE_TO_ADDRESS(__ADDR__,                 __DATA__)    \
        (*(uint32_t *)(__ADDR__) = (__DATA__))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_NOR_Exported_Functions FLASH Exported Functions
  * @{
  */

/** @defgroup FLASHEx_Exported_Functions_Group1 Configure locking and unlocking on FLASH, including MAIN area, SYSINFO area, OPT area
  * @{
  */

/**
  * @brief  Set flash wait period.
  * @param  Flash waiting period.
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_0
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_1
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_2
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_3
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_4
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_5
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_6
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_7
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_8
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_9
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_10
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_11
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_12
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_13
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_14
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_15
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_SetWaitPeriod(uint32_t waitPeriod)
{
    MODIFY_REG(FLASH->CR2,
                FLASH_CR2_RDWAIT, waitPeriod & FLASH_CR2_RDWAIT_Msk);
}

/**
  * @brief  Get flash wait period.
  * @retval  Flash waiting period.
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_0
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_1
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_2
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_3
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_4
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_5
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_6
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_7
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_8
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_9
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_10
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_11
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_12
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_13
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_14
  *         @arg @ref FLASH_DDL_WAIT_PERIOD_15
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWaitPeriod(void)
{
    return (uint32_t)READ_BIT(FLASH->CR2, FLASH_CR2_RDWAIT);
}

/**
  * @brief  Lock the flash main storage area.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_MAIN_Lock(void)
{
    FLASH->SR = FLASH_DDL_MAIN_LOCK;
}

/**
  * @brief  Unlock the flash main storage area.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_MAIN_UnLock(void)
{
    MODIFY_REG(FLASH->KEY, FLASH_KEY_FKEY, FLASH_DDL_MAIN_KEY1);
    MODIFY_REG(FLASH->KEY, FLASH_KEY_FKEY, FLASH_DDL_MAIN_KEY2);
}

/**
  * @brief  Lock the flash opt storage area.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_OPT_Lock(void)
{
    FLASH->SR = FLASH_DDL_OPT_LOCK;
}

/**
  * @brief  Unlock the flash sysinfo storage area.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_OPT_UnLock(void)
{
    MODIFY_REG(FLASH->OPTKEY, FLASH_OPTKEY_OPTKEY, FLASH_DDL_OPT_KEY1);
    MODIFY_REG(FLASH->OPTKEY, FLASH_OPTKEY_OPTKEY, FLASH_DDL_OPT_KEY2);
}

/**
  * @}
  */

/** @defgroup FLASHEx_Exported_Functions_Erasure Chip erasure
  * @{
  */

/**
  * @brief  Start erasure.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableErasure(void)
{
    MODIFY_REG(FLASH->CR1, FLASH_CR1_EREQ, FLASH_CR1_EREQ);
}

/**
  * @brief  Get erasure status.
  * @retval 0 or 1.
  */
__STATIC_INLINE uint32_t DDL_FLASH_ErasureOngoing(void)
{
    return (READ_BIT(FLASH->CR1, FLASH_CR1_EREQ) == FLASH_CR1_EREQ) ? 1UL : 0UL;
}

/**
  * @brief  Types of chip erasure configuration.
  * @param  Types of chip erasure.
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_SECTOR
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_BLOCK
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_MAIN
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_SetErasureType(uint32_t type)
{
    MODIFY_REG(FLASH->CR1, FLASH_CR1_ERTYPE, type);
}

/**
  * @brief  Get the type of configuration chip erasure.
  * @retval Types of chip erasure.
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_SECTOR
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_BLOCK
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_MAIN
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetErasureType(void)
{
    return (uint32_t)READ_BIT(FLASH->CR1, FLASH_CR1_ERTYPE);
}

/**
  * @brief  Configuring chip erasing time base.
  * @param  chip erasing time base.
  *         0x00 ~ 0xFF
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_SetEraseTimeBase(uint32_t timeBase)
{
  MODIFY_REG(FLASH->TMCR, FLASH_TMCR_UNIT, timeBase & FLASH_TMCR_UNIT_Msk);
}

/**
  * @brief  Get chip erasing time base.
  * @retval  chip erasing time base.
  *         0x00 ~ 0xFF
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetEraseTimeBase(void)
{
  return (uint32_t)READ_BIT(FLASH->TMCR, FLASH_TMCR_UNIT);
}

/**
  * @}
  */

/** @defgroup FLASHEx_Exported_Functions_Program Chip program
  * @{
  */

/**
  * @brief  Start program.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableProgram(void)
{
  MODIFY_REG(FLASH->CR1, FLASH_CR1_PREQ, FLASH_CR1_PREQ);
}

/**
  * @brief  Get program status.
  * @retval 0 or 1.
  */
__STATIC_INLINE uint32_t DDL_FLASH_ProgramOngoing(void)
{
  return (READ_BIT(FLASH->CR1, FLASH_CR1_PREQ) == FLASH_CR1_PREQ) ? 1UL : 0UL;
}

/**
  * @}
  */

/** @defgroup FLASHEx_Exported_Functions_Option Flash option byte programming
  * @{
  */

/**
  * @brief Set read protection cache bit.
  * @param Flash Read Protection Level.
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_0
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_1
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_2
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetReadProtectionCacheBit(uint32_t level)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_RDPWBF, level);
}

/**
  * @brief  Get read protection cache bit.
  * @retval Flash Read Protection Level.
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_0
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_1
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_2
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetReadProtectionCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_RDPWBF);
}

/**
  * @brief  Get the read protection bit in the option byte.
  * @retval Flash Read Protection Level.
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_0
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_1
  *        @arg @ref DDL_FLASH_READ_PROTECTION_LEVEL_2
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetReadProtectionBitInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_RDP);
}

/**
  * @brief Set write protection enable cache bit.
  * @param Flash Write Protection Status.
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_ENABLE
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_DISABLE
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetWriteProtectionEnableCacheBit(uint32_t isEnabled)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_WLOCKENBF, isEnabled);
}

/**
  * @brief  Get write protection enable cache bit.
  * @retval Flash Write Protection Status.
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_ENABLE
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_DISABLE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWriteProtectionEnableCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_WLOCKENBF);
}

/**
  * @brief  Get the write protection enable bit in the option byte.
  * @retval Flash Write Protection Status.
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_ENABLE
  *        @arg @ref DDL_FLASH_WRITE_PROTECTION_DISABLE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWriteProtectionEnableBitInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_WLOCKEN);
}

/**
  * @brief Set write protection cache bit.
  * @param Flash Write Protection Sector.
  *        @arg @ref DDL_FLASH_SECTOR_NONE
  *        @arg @ref DDL_FLASH_SECTOR_0_31
  *        @arg @ref DDL_FLASH_SECTOR_32_63
  *        @arg @ref DDL_FLASH_SECTOR_64_95
  *        @arg @ref DDL_FLASH_SECTOR_96_127
  *        @arg @ref DDL_FLASH_SECTOR_128_159
  *        @arg @ref DDL_FLASH_SECTOR_160_191
  *        @arg @ref DDL_FLASH_SECTOR_192_223
  *        @arg @ref DDL_FLASH_SECTOR_224_255
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetWriteProtectionCacheBit(uint32_t sectorBlock)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_WLOCKBF, ~sectorBlock);
}

/**
  * @brief  Get write protection cache bit.
  * @retval Flash Write Protection Sector.
  *        @arg @ref DDL_FLASH_SECTOR_NONE
  *        @arg @ref DDL_FLASH_SECTOR_0_31
  *        @arg @ref DDL_FLASH_SECTOR_32_63
  *        @arg @ref DDL_FLASH_SECTOR_64_95
  *        @arg @ref DDL_FLASH_SECTOR_96_127
  *        @arg @ref DDL_FLASH_SECTOR_128_159
  *        @arg @ref DDL_FLASH_SECTOR_160_191
  *        @arg @ref DDL_FLASH_SECTOR_192_223
  *        @arg @ref DDL_FLASH_SECTOR_224_255
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWriteProtectionCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_WLOCKBF);
}

/**
  * @brief  Get the write protection bit in the option byte.
  * @retval Flash Write Protection Sector.
  *        @arg @ref DDL_FLASH_SECTOR_NONE
  *        @arg @ref DDL_FLASH_SECTOR_0_31
  *        @arg @ref DDL_FLASH_SECTOR_32_63
  *        @arg @ref DDL_FLASH_SECTOR_64_95
  *        @arg @ref DDL_FLASH_SECTOR_96_127
  *        @arg @ref DDL_FLASH_SECTOR_128_159
  *        @arg @ref DDL_FLASH_SECTOR_160_191
  *        @arg @ref DDL_FLASH_SECTOR_192_223
  *        @arg @ref DDL_FLASH_SECTOR_224_255
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWriteProtectionBitInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_WLOCK);
}

/**
  * @brief  Set NMI Pin Enable Configuration.
  * @param nmiEnable NMI Pin Enable Configuration.
  *        @arg @ref DDL_FLASH_NMI_ENABLE
  *        @arg @ref DDL_FLASH_NMI_DISABLE
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_SetNMIEnableCacheBit(uint32_t nmiEnable)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_NMIDISWBF, nmiEnable);
}

/**
  * @brief  Get NMI Pin Enable Configuration.
  * @retval nmiEnable NMI Pin Enable Configuration.
  *        @arg @ref DDL_FLASH_NMI_ENABLE
  *        @arg @ref DDL_FLASH_NMI_DISABLE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetNMIEnableCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_NMIDISWBF);
}

/**
  * @brief  Get NMI Pin Enable Configuration.
  * @retval nmiEnable NMI Pin Enable Configuration.
  *        @arg @ref DDL_FLASH_NMI_ENABLE
  *        @arg @ref DDL_FLASH_NMI_DISABLE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetNMIEnableCacheBitInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_NMIDIS);
}

/**
  * @brief Set ADC TRIM Configuration.
  * @param adcTrim ADC TRIM Configuration.
  *        @arg @ref DDL_FLASH_ADC_TRIM_SOFTWARE
  *        @arg @ref DDL_FLASH_ADC_TRIM_HARDWARE
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_SetADCTRIMCacheBit(uint32_t adcTrim)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_ADTSLOADWBF, adcTrim);
}

/**
  * @brief  Get ADC TRIM Configuration.
  * @retval ADC TRIM Configuration.
  *        @arg @ref DDL_FLASH_ADC_TRIM_SOFTWARE
  *        @arg @ref
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetADCTRIMCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_ADTSLOADWBF);
}

/**
  * @brief  Get ADC TRIM Configuration.
  * @retval ADC TRIM Configuration.
  *        @arg @ref DDL_FLASH_ADC_TRIM_SOFTWARE
  *        @arg @ref DDL_FLASH_ADC_TRIM_HARDWARE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetADCTRIMCacheBitInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_ADTSLOAD);
}

/**
  * @brief Set IWDT software enables cache bits.
  * @param IWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_HARDWARE
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetIWDTTriggerBySoftwareCacheBit(uint32_t isEnabled)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_IWDTSWBF, isEnabled);
}

/**
  * @brief  Get IWDT software enables cache bits.
  * @retval IWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_HARDWARE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetIWDTTriggerBySoftwareCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_IWDTSWBF);
}

/**
  * @brief  Get the IWDT software enables in the option byte.
  * @retval IWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_IWDT_ENABLE_HARDWARE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetIWDTTriggerBySoftwareInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_IWDTSW);
}

/**
  * @brief Set WWDT software enables cache bits.
  * @param WWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_HARDWARE
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetWWDTTriggerBySoftwareCacheBit(uint32_t isEnabled)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_WWDTSWBF, isEnabled);
}

/**
  * @brief  Get WWDT software enables cache bits.
  * @retval WWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_HARDWARE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWWDTTriggerBySoftwareCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR1, FLASH_OBCR1_WWDTSWBF);
}

/**
  * @brief  Get the WWDT software enables in the option byte.
  * @retval WWDT software enables cache bits.
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_SOFTWARE
  *        @arg @ref DDL_FLASH_WWDT_ENABLE_HARDWARE
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetWWDTTriggerBySoftwareInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR1, FLASH_OBSR1_WWDTSW);
}

/**
  * @brief Set the write cache bit for setting BOOTADDR.
  * @param the write cache bit for setting BOOTADDR..
  *        0x0000~0xFFFF
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_SetBootAddrCacheBit(uint32_t bootAddr)
{
  MODIFY_REG(FLASH->OBCR2, FLASH_OBCR2_BOOTADDRBF, bootAddr);
}

/**
  * @brief  Get the write cache bit for setting BOOTADDR.
  * @retval the write cache bit for setting BOOTADDR..
  *        0x0000~0xFFFF
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetBootAddrCacheBit(void)
{
  return (uint32_t)READ_BIT(FLASH->OBCR2, FLASH_OBCR2_BOOTADDRBF);
}

/**
  * @brief  Get the write cache bit for setting BOOTADDR in Option Byte.
  * @retval the write cache bit for setting BOOTADDR..
  *        0x0000~0xFFFF
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetBootAddrInOptionByte(void)
{
  return (uint32_t)READ_BIT(FLASH->OBSR2, FLASH_OBSR2_BOOTADDR);
}

/**
  * @brief  Retrieve the data in the BOOTADDR option byte,
  *         which corresponds to the converted address.
  * @retval the write cache bit for setting BOOTADDR..
  *         0x0000~0xFFFF
  */
__STATIC_INLINE uint32_t DDL_FLASH_GetBootAddrTransferActualAddress(void)
{
  uint32_t bootAddr = (uint32_t)READ_BIT(FLASH->OBSR2, FLASH_OBSR2_BOOTADDR);
  uint32_t actualAddr = __DDL_FLASH_CALCULATE_BOOT_ADDRESS(bootAddr);
  return actualAddr;
}

/**
  * @brief  Byte programming options.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_OptionByteUpdate(void)
{
  MODIFY_REG(FLASH->OBCR1, FLASH_OBCR1_OPBWREQ, FLASH_OBCR1_OPBWREQ);
}

/**
  * @brief  Byte programming options Status.
  * @retval None.
  */
__STATIC_INLINE uint32_t DDL_FLASH_OptionByteUpdateOngoing(void)
{
  return (READ_BIT(FLASH->OBCR1, FLASH_OBCR1_OPBWREQ) == FLASH_OBCR1_OPBWREQ) ? 1UL : 0UL;
}

/**
  * @brief  Forced update of the options byte
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_OptionByteForcedUpdate(void)
{
  MODIFY_REG(FLASH->CR1, FLASH_CR1_OPRELOAD, 0xA5A50000 | FLASH_CR1_OPRELOAD);
}

/**
  * @}
  */

/** @defgroup FLASHEx_Exported_Functions_Cache Cache configuration
  * @{
  */

/**
  * @brief  Cache reset.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_CacheReset(void)
{
  MODIFY_REG(FLASH->CR2, FLASH_CR2_CACHERST, FLASH_CR2_CACHERST);
}

/**
  * @brief  Cache reset.
  * @retval 1 or 0.
  */
__STATIC_INLINE uint32_t DDL_FLASH_CacheResetOngoing(void)
{
  return (READ_BIT(FLASH->CR2, FLASH_CR2_CACHERST) == FLASH_CR2_CACHERST) ? 1UL : 0UL;
}

/**
  * @brief  Enable cache preload mode.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_EnableCachePreloadMode(void)
{
  MODIFY_REG(FLASH->CR2, FLASH_CR2_PREFETCHEN, DDL_FLASH_CACHE_PRELOAD_ENABLE);
}

/**
  * @brief  Disable cache preload mode.
  * @retval None.
  */
__STATIC_INLINE void DDL_FLASH_DisableCachePreloadMode(void)
{
  MODIFY_REG(FLASH->CR2, FLASH_CR2_PREFETCHEN, DDL_FLASH_CACHE_PRELOAD_DISABLE);
}

/**
  * @brief  Get cache preload mode status.
  * @retval 1 or 0.
  */
__STATIC_INLINE uint32_t DDL_FLASH_CachePreloadModeIsEnabled(void)
{
  return (READ_BIT(FLASH->CR2, FLASH_CR2_PREFETCHEN) == DDL_FLASH_CACHE_PRELOAD_ENABLE) ? 1UL : 0UL;
}

/**
  * @}
  */

/** @defgroup FLASH_DDL_EF_FLAG_Management FLASH flag management
  * @{
  */

/**
  * @brief  Enable interruption Flash error.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_ERR(void)
{
  SET_BIT(FLASH->CR1, FLASH_CR1_ERRIE);
}

/**
  * @brief  Disable interruption Flash error.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_ERR(void)
{
  CLEAR_BIT(FLASH->CR1, FLASH_CR1_ERRIE);
}

/**
  * @brief  Get state of interruption Flash error.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_ERR(void)
{
  return ((READ_BIT(FLASH->CR1, FLASH_CR1_ERRIE) == (FLASH_CR1_ERRIE)) ? 1UL : 0UL);
}

/**
  * @brief  Incorrect address write flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_WADRERR(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_WADRERR) == (FLASH_SR_WADRERR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear the address write error flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_WADRERR(void)
{
  FLASH->SR = FLASH_SR_WADRERR;
}

/**
  * @brief  Write protection error flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_WRPRTERR(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_WRPRTERR) == (FLASH_SR_WRPRTERR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear write protection error flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_WRPRTERR(void)
{
  FLASH->SR = FLASH_SR_WRPRTERR;
}

/**
  * @brief  Flash KEY error flag
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_KEYERR(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_KEYERR) == (FLASH_SR_KEYERR)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Flash KEY error flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_KEYERR(void)
{
  FLASH->SR = FLASH_SR_KEYERR;
}

/**
  * @brief  Enable interruption programming or erase end.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_EnableIT_EOP(void)
{
  SET_BIT(FLASH->CR1, FLASH_CR1_EOPIE);
}

/**
  * @brief  Disable interruption programming or erase end.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_DisableIT_EOP(void)
{
  CLEAR_BIT(FLASH->CR1, FLASH_CR1_EOPIE);
}

/**
  * @brief  Get state of interruption programming or erase end.
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsEnabledIT_EOP(void)
{
  return ((READ_BIT(FLASH->CR1, FLASH_CR1_EOPIE) == (FLASH_CR1_EOPIE)) ? 1UL : 0UL);
}

/**
  * @brief  Programming completed flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_PRD(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_PRD) == (FLASH_SR_PRD)) ? 1UL : 0UL);
}

/**
  * @brief  Clear programming completed flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_PRD(void)
{
  FLASH->SR = FLASH_SR_PRD;
}

/**
  * @brief  Erase completed flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_ERD(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_ERD) == (FLASH_SR_ERD)) ? 1UL : 0UL);
}

/**
  * @brief  Clear erase completed flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_ERD(void)
{
  FLASH->SR = FLASH_SR_ERD;
}

/**
  * @brief  Locking flag for option byte area.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_OPUNLOCK(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_OPUNLOCK) == (FLASH_SR_OPUNLOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Locking flag for main area.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_MAINUNLOCK(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_MAINUNLOCK) == (FLASH_SR_MAINUNLOCK)) ? 1UL : 0UL);
}

/**
  * @brief  The option_byte does not meet the parity check flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_OPTERR(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_OPTERR) == (FLASH_SR_OPTERR)) ? 1UL : 0UL);
}

/**
  * @brief  Trim check error flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_TRIMERR(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_TRIMERR) == (FLASH_SR_TRIMERR)) ? 1UL : 0UL);
}

/**
  * @brief  The optionbyte programming completion flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_OPBPRD(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_OPBPRD) == (FLASH_SR_OPBPRD)) ? 1UL : 0UL);
}

/**
  * @brief  Clear optionbyte programming completion flag.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_OPBPRD(void)
{
  FLASH->SR = FLASH_SR_OPBPRD;
}

/**
  * @brief  FLASH erasing busy flag.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t DDL_FLASH_IsActiveFlag_BUSY(void)
{
  return ((READ_BIT(FLASH->SR, FLASH_SR_BUSY) == (FLASH_SR_BUSY)) ? 1UL : 0UL);
}

/**
  * @brief  Clear all flag.
  * @note   OPUNLOCK and MAINUNLOCK are intentionally kept untouched.
  *         Writing '1' to either of these bits would re-lock the option-byte
  *         area or the main program area, which would then require the full
  *         unlock sequence (key writing) before any further erase/program
  *         operation can be performed.
  * @note   OPTERR and TRIMERR are read-only and are not cleared by this function.
  * @retval None
  */
__STATIC_INLINE void DDL_FLASH_ClearFlag_All(void)
{
    FLASH->SR = (FLASH_SR_ERD | FLASH_SR_PRD | FLASH_SR_KEYERR
      | FLASH_SR_WRPRTERR | FLASH_SR_WADRERR | FLASH_SR_OPBPRD);
}

/**
  * @}
  */

#if defined(USE_FULL_DDL_DRIVER)
/** @defgroup FLASH_DDL_EF_Init Initialization and de-initialization functions
  * @{
  */
void DDL_FLASH_ReadData(uint32_t baseAddr, uint32_t *data, uint32_t length);
void DDL_FLASH_WriteData(uint32_t baseAddr, uint32_t *data, uint32_t length);

ErrorStatus DDL_FLASH_EraseMain(uint32_t type, uint32_t baseAddr);

void DDL_FLASH_OPT_StructInit(DDL_FLASH_OPT_InitTypeDef *FLASH_OPT_InitStruct);
ErrorStatus DDL_FLASH_OptionByteProgram(DDL_FLASH_OPT_InitTypeDef* FLASH_OPT_InitStruct);
ErrorStatus DDL_FLASH_MainProgram(uint32_t baseAddr, uint32_t *data, uint32_t numWords);
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

#endif /* defined (FLASH) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

