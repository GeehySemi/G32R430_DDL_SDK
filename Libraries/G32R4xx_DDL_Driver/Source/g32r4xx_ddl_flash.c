/**
  *
  * @file    g32r4xx_ddl_flash.c
  * @brief   ADC DDL module driver
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
  * Copyright (C) 2024-2025 Geehy Semiconductor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 #if defined(USE_FULL_DDL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "g32r4xx_ddl_flash.h"
#include "g32r4xx_ddl_rcm.h"

#ifdef  USE_FULL_ASSERT
  #include "g32_assert.h"
#else
  #define ASSERT_PARAM(_PARAM_) ((void)0U)
#endif

/** @addtogroup G32R4xx_DDL_Driver
  * @{
  */
#if defined (FLASH)

/** @addtogroup FLASH_DDL FLASH
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup FLASH_DDL_Private_Constants
  * @{
  */
#define DDL_FLASH_TIMEOUT_VALUE       500000U

#define IS_DDL_FLASH_ERASE_TYPE(__REG_ERASE_TYPE__)                       \
     (((__REG_ERASE_TYPE__) == FLASH_DDL_CHIP_ERASE_TYPE_SECTOR)          \
   || ((__REG_ERASE_TYPE__) == FLASH_DDL_CHIP_ERASE_TYPE_BLOCK)           \
   || ((__REG_ERASE_TYPE__) == FLASH_DDL_CHIP_ERASE_TYPE_MAIN)            \
  )

#define IS_DDL_FLASH_MAIN_BASE_ADDRESS(__BASE_ADDRESS__)                  \
        (((__BASE_ADDRESS__ >= 0x08000000UL) && (__BASE_ADDRESS__ <= 0x0801FFFFUL)) ? 1UL : 0UL)

#define IS_DDL_FLASH_SYSINFO_BASE_ADDRESS(__BASE_ADDRESS__)               \
        (((__BASE_ADDRESS__ >= 0x08020000UL) && (__BASE_ADDRESS__ <= 0x080203FFUL)) ? 1UL : 0UL)

#define IS_DDL_FLASH_READ_PROTECTION_LEVEL(__LEVEL__)             \
     (((__LEVEL__) == DDL_FLASH_READ_PROTECTION_LEVEL_0)          \
   || ((__LEVEL__) == DDL_FLASH_READ_PROTECTION_LEVEL_1)          \
   || ((__LEVEL__) == DDL_FLASH_READ_PROTECTION_LEVEL_2)          \
  )

#define IS_DDL_FLASH_IWDT_SOFTWARE_ENABLE(__SOFTWARE_ENABLE__)           \
     (((__SOFTWARE_ENABLE__) == DDL_FLASH_IWDT_ENABLE_HARDWARE)          \
   || ((__SOFTWARE_ENABLE__) == DDL_FLASH_IWDT_ENABLE_SOFTWARE)          \
  )

#define IS_DDL_FLASH_WWDT_SOFTWARE_ENABLE(__SOFTWARE_ENABLE__)           \
     (((__SOFTWARE_ENABLE__) == DDL_FLASH_WWDT_ENABLE_HARDWARE)          \
   || ((__SOFTWARE_ENABLE__) == DDL_FLASH_WWDT_ENABLE_SOFTWARE)          \
  )

#define IS_DDL_FLASH_WRITE_PROTECTION(__WRITE_PROTECTION__)                  \
     (((__WRITE_PROTECTION__) == DDL_FLASH_WRITE_PROTECTION_DISABLE)         \
   || ((__WRITE_PROTECTION__) == DDL_FLASH_WRITE_PROTECTION_ENABLE)          \
  )

#define IS_DDL_FLASH_NMI_ENABLE(__NMIEN__)                \
     (((__NMIEN__) == DDL_FLASH_NMI_DISABLE)              \
   || ((__NMIEN__) == DDL_FLASH_NMI_ENABLE)               \
  )

#define IS_DDL_FLASH_ADC_TRIM(__TRIM__)                         \
     (((__TRIM__) == DDL_FLASH_ADC_TRIM_SOFTWARE)               \
   || ((__TRIM__) == DDL_FLASH_ADC_TRIM_HARDWARE)               \
  )

#define IS_DDL_FLASH_WRITE_PROTECTION_SECTORS(__SECTORS__)              \
     (((__SECTORS__) == DDL_FLASH_SECTOR_NONE)                          \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_0_31)                          \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_32_63)                         \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_64_95)                         \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_96_127)                        \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_128_159)                       \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_160_191)                       \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_192_223)                       \
   || ((__SECTORS__) == DDL_FLASH_SECTOR_224_255)                       \
  )


 /**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_DDL_Exported_Functions
  * @{
  */

/**
  * @brief  Erase the main area of the flash.
  * @note   Before calling this function, please unlock the flash main area by
  *         using DDL_FLASH_MAIN_UnLock().
  * @param  Types of chip erasure.
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_SECTOR
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_BLOCK
  *         @arg @ref FLASH_DDL_CHIP_ERASE_TYPE_MAIN
  * @param  baseAddr  --0x08000000 ~ 0x0801FFFF
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Flash erase is success
  *          - ERROR: Flash erase is fail
  */
ErrorStatus DDL_FLASH_EraseMain(uint32_t type, uint32_t baseAddr)
{
    volatile uint32_t timeout = DDL_FLASH_TIMEOUT_VALUE;
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(IS_DDL_FLASH_ERASE_TYPE(type));
    ASSERT_PARAM(IS_DDL_FLASH_MAIN_BASE_ADDRESS(baseAddr));

    /*  Check the FLASH_SR->BUSY bit to confirm that the last programming operation has ended. */
    if (DDL_FLASH_IsActiveFlag_BUSY() != RESET)
    {
        status = ERROR;
        return status;
    }

    /* Check FLASH_SR->MAINUNLOCK is 1. */
    if (DDL_FLASH_IsActiveFlag_MAINUNLOCK() == RESET)
    {
        status = ERROR;
        return status;
    }

    /* Set the erasure type of flash. */
    DDL_FLASH_SetErasureType(type);

    /* Set the EREQ bit of FLASH_CR to 1. */
    DDL_FLASH_EnableErasure();

    /* Write 0xA5A5 to baseAddr. */
    __DDL_FLASH_WRITE_TO_ADDRESS(baseAddr, 0xA5A5);

    /* Wait for the FLASH_SR->BSY bit to be cleared. */
    timeout = DDL_FLASH_TIMEOUT_VALUE;
    while(DDL_FLASH_IsActiveFlag_BUSY() != RESET)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Wait for the erasing to be completed. */
    timeout = DDL_FLASH_TIMEOUT_VALUE;
    while(DDL_FLASH_IsActiveFlag_ERD() == RESET)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Clear the erase completion flag. */
    DDL_FLASH_ClearFlag_ERD();

    if (DDL_FLASH_IsActiveFlag_WADRERR() != RESET)
    {
        status = ERROR;
    }
    
    if (DDL_FLASH_IsActiveFlag_WRPRTERR() != RESET)
    {
        status = ERROR;
    }

    return status;
}

/**
  * @brief  Erase the systemInfo area of the flash.
  * @param  baseAddr
  * @param  Target Array
  * @param  Length of data to be read
  * @retval None.
  */
void DDL_FLASH_ReadData(uint32_t baseAddr, uint32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
        data[i] = *((uint32_t *)(baseAddr + i * sizeof(uint32_t)));
    }
}

/**
  * @brief  Erase the systemInfo area of the flash.
  * @param  baseAddr
  * @param  Target Array
  * @param  Length of data to be read
  * @retval None.
  */
void DDL_FLASH_WriteData(uint32_t baseAddr, uint32_t *data, uint32_t length)
{
    for (uint32_t i = 0; i < length; i++)
    {
        *((uint32_t *)(baseAddr + i * sizeof(uint32_t))) = data[i];
    }
}

/**
  * @brief  Set each @ref DDL_FLASH_OPT_InitTypeDef field to default value.
  * @param  FLASH_OPT_InitStruct Pointer to a @ref DDL_FLASH_OPT_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
void DDL_FLASH_OPT_StructInit(DDL_FLASH_OPT_InitTypeDef *FLASH_OPT_InitStruct)
{
    FLASH_OPT_InitStruct->readProtectionLevel = DDL_FLASH_READ_PROTECTION_LEVEL_1;
    FLASH_OPT_InitStruct->iwdtSoftwareEnable = DDL_FLASH_IWDT_ENABLE_SOFTWARE;
    FLASH_OPT_InitStruct->wwdtSoftwareEnable = DDL_FLASH_WWDT_ENABLE_SOFTWARE;
    FLASH_OPT_InitStruct->writeProtectionEnable = DDL_FLASH_WRITE_PROTECTION_DISABLE;
    FLASH_OPT_InitStruct->nmiEnable = DDL_FLASH_NMI_DISABLE;
    FLASH_OPT_InitStruct->adcTrim = DDL_FLASH_ADC_TRIM_SOFTWARE;
    FLASH_OPT_InitStruct->writeProtectionSectors = DDL_FLASH_SECTOR_NONE;
    FLASH_OPT_InitStruct->bootAddr = 0x4000;
}

/**
  * @brief  Flash option byte programming.
  * @note   Before calling this function, please unlock the flash main area by
  *         using DDL_FLASH_OPT_UnLock().
  * @param  FLASH_OPT_InitStruct Pointer to a @ref DDL_FLASH_OPT_InitTypeDef structure
  *                            whose fields will be set to default values.
  * @retval None
  */
ErrorStatus DDL_FLASH_OptionByteProgram(DDL_FLASH_OPT_InitTypeDef* FLASH_OPT_InitStruct)
{
    volatile uint32_t timeout = DDL_FLASH_TIMEOUT_VALUE;
    ErrorStatus status = SUCCESS;

    /* Check the parameters */
    ASSERT_PARAM(IS_DDL_FLASH_READ_PROTECTION_LEVEL(FLASH_OPT_InitStruct->readProtectionLevel));
    ASSERT_PARAM(IS_DDL_FLASH_IWDT_SOFTWARE_ENABLE(FLASH_OPT_InitStruct->iwdtSoftwareEnable));
    ASSERT_PARAM(IS_DDL_FLASH_WWDT_SOFTWARE_ENABLE(FLASH_OPT_InitStruct->wwdtSoftwareEnable));
    ASSERT_PARAM(IS_DDL_FLASH_WRITE_PROTECTION(FLASH_OPT_InitStruct->writeProtectionEnable));
    ASSERT_PARAM(IS_DDL_FLASH_NMI_ENABLE(FLASH_OPT_InitStruct->nmiEnable));
    ASSERT_PARAM(IS_DDL_FLASH_ADC_TRIM(FLASH_OPT_InitStruct->adcTrim));
    ASSERT_PARAM(IS_DDL_FLASH_WRITE_PROTECTION_SECTORS(FLASH_OPT_InitStruct->writeProtectionSectors));

    /* Read RDP from NVR1 region at 0x1FFF0000. */
    (void)*((volatile uint32_t *)0x1FFF0000U);
    __DMB();

    /* Check the FLASH_SR->BUSY bit to confirm that the last programming operation has ended. */
    if (DDL_FLASH_IsActiveFlag_BUSY() != RESET)
    {
        status = ERROR;
        return status;
    }

    /* Check FLASH_SR->OPUNLOCK is 1. */
    if (DDL_FLASH_IsActiveFlag_OPUNLOCK() == RESET)
    {
        status = ERROR;
        return status;
    }

    /* Fill data to register OBCR1. */
    MODIFY_REG(FLASH->OBCR1,
                 FLASH_OBCR1_RDPWBF         \
               | FLASH_OBCR1_IWDTSWBF      \
               | FLASH_OBCR1_WWDTSWBF      \
               | FLASH_OBCR1_WLOCKENBF     \
               | FLASH_OBCR1_NMIDISWBF      \
               | FLASH_OBCR1_ADTSLOADWBF    \
               | FLASH_OBCR1_WLOCKBF ,
                 FLASH_OPT_InitStruct->readProtectionLevel  \
               | FLASH_OPT_InitStruct->iwdtSoftwareEnable   \
               | FLASH_OPT_InitStruct->wwdtSoftwareEnable   \
               | FLASH_OPT_InitStruct->writeProtectionEnable \
               | FLASH_OPT_InitStruct->adcTrim              \
               | FLASH_OPT_InitStruct->nmiEnable            \
               | (~FLASH_OPT_InitStruct->writeProtectionSectors) & 0xFF0000);

    /* Checking the validity of the data. */
    uint32_t actualAddr = DDL_FLASH_GetBootAddrTransferActualAddress();

    if (__DDL_FLASH_IS_VALID_BOOT_ADDRESS(actualAddr) == RESET)
    {
        status = ERROR;
        return status;
    }

    /* If the data is valid, fill the data into the register. */
    MODIFY_REG(FLASH->OBCR2, FLASH_OBCR2_BOOTADDRBF, FLASH_OPT_InitStruct->bootAddr);

    DDL_FLASH_OptionByteUpdate();

    /* Wait for the FLASH_SR->BSY bit to be cleared. */
    timeout = DDL_FLASH_TIMEOUT_VALUE;
    while(DDL_FLASH_IsActiveFlag_BUSY() != RESET)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Wait for the programing to be completed. */
    timeout = DDL_FLASH_TIMEOUT_VALUE;
    while(DDL_FLASH_IsActiveFlag_OPBPRD() == RESET)
    {
        if (timeout-- == 0)
        {
            status = ERROR;
            return status;
        }
    }

    /* Re-power on or write 1 to opreload, FLS_OBSR1/1 status updates. */
    DDL_FLASH_OptionByteForcedUpdate();

    return status;
}

/**
  * @brief  Program the systemInfo area of the flash.
  * @note   Before calling this function, please unlock the flash main area by
  *         using DDL_FLASH_MAIN_UnLock().
  * @param  baseAddr  --0x08000000~0x0801FFFF
  * @param  Target Array
  * @param  Length of data to be program
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Flash erase is success
  *          - ERROR: Flash erase is fail
  */
ErrorStatus DDL_FLASH_MainProgram(uint32_t baseAddr, uint32_t *data, uint32_t numWords)
{
    volatile uint32_t timeout = DDL_FLASH_TIMEOUT_VALUE;
    ErrorStatus status = SUCCESS;

    /*  Check the FLASH_SR->BUSY bit to confirm that the last programming operation has ended. */
    if (DDL_FLASH_IsActiveFlag_BUSY() != RESET)
    {
        status = ERROR;
        return status;
    }

    /* Write data to Flash */
    for (uint32_t i = 0; i < numWords; i++)
    {
        /* Check FLASH_SR->MAINUNLOCK is 1. */
        if (DDL_FLASH_IsActiveFlag_MAINUNLOCK() == RESET)
        {
            status = ERROR;
            return status;
        }

        /* Set the  PREQ bit of FLASH_CR to 1. */
        DDL_FLASH_EnableProgram();

        *((uint32_t*)(baseAddr + i * sizeof(uint32_t))) = data[i];
        /* Wait for the FLASH_SR->BSY bit to be cleared. */
        timeout = DDL_FLASH_TIMEOUT_VALUE;
        while(DDL_FLASH_IsActiveFlag_BUSY() != RESET)
        {
            if (timeout-- == 0)
            {
                status = ERROR;
                return status;
            }
        }

        /* Wait for the programing to be completed. */
        timeout = DDL_FLASH_TIMEOUT_VALUE;
        while(DDL_FLASH_IsActiveFlag_PRD() == RESET)
        {
            if (timeout-- == 0)
            {
                status = ERROR;
                return status;
            }
        }

        DDL_FLASH_ClearFlag_PRD();
    }


    if (DDL_FLASH_IsActiveFlag_WADRERR() != RESET)
    {
        status = ERROR;
        return status;
    }
    
    if (DDL_FLASH_IsActiveFlag_WRPRTERR() != RESET)
    {
        status = ERROR;
        return status;
    }
    return status;
}

 /**
  * @}
  */

#endif

 /**
  * @}
  */

  /**
  * @}
  */


#endif
