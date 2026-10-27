/*!
 * @file        iap_flash.c
 *
 * @brief       Include IAP flash operation
 *
 * @version     V1.0.0
 *
 * @date        2025-10-30
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
#include "iap_flash.h"
#include <stdio.h>

/* Private includes *******************************************************/

/* Private macro **********************************************************/

/* Private typedef ********************************************************/

/* Private variables ******************************************************/

/* Private function prototypes ********************************************/

/* External variables *****************************************************/

/* External functions *****************************************************/

/*!
 * @brief       Unlocks Flash for write access
 *
 * @param       None
 *
 * @retval      None
 *
 */
void FLASH_IAP_Init(void)
{
    /* Unlock RCM */
    DDL_RCM_Unlock();
    /* Enable the flash peripheral clock */
    DDL_RCM_EnableAHBPeripheral(DDL_RCM_AHB_PERIPHERAL_FLASH);
    /* Lock RCM */
    DDL_RCM_Lock();

    /* Clear all flash flags */
    DDL_FLASH_ClearFlag_All();

    /* Unlock the main flash area for erase/program operations */
    DDL_FLASH_MAIN_UnLock();
}

/*!
 * @brief       Erase of all user flash area
 *
 * @param       Application
 *              @arg APP1 : Application1
 *              @arg APP2 : Application2
 *
 * @retval      SUCCESS: user flash area successfully erased
 *              ERROR: error occurred
 */
uint32_t FLASH_IAP_Erase(APP_TypeDef Application)
{
    uint32_t addr;
    uint32_t endAddr;

    /* Determine the start and end addresses */
    if (Application == APP1)
    {
        addr = USER_APP1_ADDRESS;
        endAddr = USER_APP1_END_ADDRESS;
    }
    else
    {
        addr = USER_APP2_ADDRESS;
        endAddr = USER_APP2_END_ADDRESS;
    }

    /* Erase flash sector by sector */
    while (addr < endAddr)
    {
        if (SUCCESS != DDL_FLASH_EraseMain(FLASH_DDL_CHIP_ERASE_TYPE_SECTOR, addr))
        {
            /* If erase operation fails, return ERROR */
            return ERROR;
        }
        addr += IAP_FLASH_SECTIR;
    }

    /* Erase completed successfully */
    return SUCCESS;
}

/*!
 * @brief       Write the appoint data buffer in flash
 *
 * @param       address: start address for writing data buffer
 *
 * @param       data: pointer on data buffer
 *
 * @param       length: length of data buffer (unit is 32-bit word)
 *
 * @param       Application
 *              @arg APP1 : Application1
 *              @arg APP2 : Application2
 *
 * @retval      SUCCESS: data successfully written to Flash memory
 *              ERROR: Error occurred while writing data in Flash memory
 *
 * @note        buffer data are 32-bit aligned
 */
uint32_t FLASH_IAP_Write(__IO uint32_t* address, uint32_t* data, uint16_t length, APP_TypeDef Application)
{
    uint32_t i = 0;
    uint32_t addressEnd;

    if (Application == APP1)
    {
        addressEnd = USER_APP1_END_ADDRESS - 4;
    }
    else
    {
        addressEnd = USER_APP2_END_ADDRESS - 4;
    }

    for (i = 0; i < length; i++)
    {
        if (*address > addressEnd)
        {
            return (ERROR);
        }

        /* The operation will be done by word and check the written value */
        if ((DDL_FLASH_MainProgram(
                 *address,                             /* baseAddr: start address to be programmed */
                 &((uint32_t *)data)[i],               /* data: pointer to the ith 32-bit word */
                 1                                     /* numWords: program one 32-bit word */
             ) != SUCCESS)
            || ( *(uint32_t *)(*address) != ((uint32_t *)data)[i] )) /* verify data */
        {
            return (ERROR);
        }

        *address += 4;
    }

    return (SUCCESS);
}
