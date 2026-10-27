/**
 *
 * @file        system_g32r4xx.c
 *
 * @brief       CMSIS Cortex-M52 Device Peripheral Access Layer System Source File.
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

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup g32r4xx_system
  * @{
  */

/** @addtogroup G32R4xx_System_Private_Includes
  * @{
  */

#include "g32r4xx.h"
#include "system_g32r4xx.h"

/* Value of the external oscillator in Hz */
#if !defined  (HSE_VALUE)
    #define HSE_VALUE    ((uint32_t)8000000U)
#endif /* HSE_VALUE */

/* Value of the internal oscillator in Hz */
#if !defined  (HSI_VALUE)
    #define HSI_VALUE    ((uint32_t)8000000U)
#endif /* HSI_VALUE */

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_Defines
  * @{
  */
/* Vector table base offset field. This value must be a multiple of 0x100 */
#define VECT_TAB_OFFSET  0x00

/* Uncomment to relocate the vector table into internal SRAM
 * Relocate the NVIC vector table to RAM at runtime and use VTOR to point to it.
 * Ensure the linker script reserves the RAM region and there is enough space.
 * (.sct for MDK, .icf for IAR, .ld for GCC).
 */
#ifndef VECT_TAB_FLASH
    #ifndef VECT_TAB_SRAM
        #define VECT_TAB_SRAM
    #endif
#endif

#define NVIC_RAM_VECTOR_SIZE        (16+39)

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_Macros
  * @{
  */

typedef void(*PINT)(void);

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_Variables
  * @{
  */
uint32_t SystemCoreClock = HSI_VALUE;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};
const uint8_t APBBKPPrescTable[8]  = {0, 0, 0, 0, 4, 5, 6, 7};

extern const PINT __VECTOR_TABLE[NVIC_RAM_VECTOR_SIZE];

#ifdef VECT_TAB_SRAM
SECTION_RAM_VEC
static PINT Interrupt_vectorTable[NVIC_RAM_VECTOR_SIZE] __ALIGNED(0x100);
#endif

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @addtogroup G32R4xx_System_Private_Functions
  * @{
  */
static void SystemReset(void);
static void CopyVectorTable(void);

/**
 * @brief     Setup the microcontroller system
 *
 * @param     None
 *
 * @retval    None
 */
void SystemInit(void)
{
    uint16_t i;

    /* Disable global interrupt */
    __disable_irq();

    SysTick->CTRL = 0U;
    SysTick->LOAD = 0U;
    SysTick->VAL = 0U;

    for (i = 0U; i < 8U; i++)
    {
        NVIC->ICER[i] = 0xFFFFFFFFU;
        NVIC->ICPR[i] = 0xFFFFFFFFU;
    }

    /* Reset the scu configuration to the default reset state:
       - HSI clock is ON and used as system clock source
       - AHB, APB prescaler are divided by 1.
       - MCO OFF
       - All interrupts disabled
       - Reset all wakeup-configuration
    */
    SystemReset();

    /* Configure the Vector Table location add offset address */
#ifdef VECT_TAB_SRAM
    CopyVectorTable();
#else
    /* Vector Table Relocation in Internal FLASH */
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; 
#endif

    /* Enable global interrupt */
    __enable_irq();
}

/**
   * @brief Update SystemCoreClock variable according to clock register values
  *          The SystemCoreClock variable contains the core clock (HCLK)
  *
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
    uint32_t sysClock = 0, pllvco = 0, pllmul = 0, pllClock = 0;

    /* Get SYSCLK source */
    sysClock = RCM->MCCR & RCM_MCCR_SWST;

    switch (sysClock)
    {
        case 0x00:  /* HSI used as system clock source */
            SystemCoreClock = HSI_VALUE;
            break;

        case 0x02:  /* HSE used as system clock source */
            SystemCoreClock = HSE_VALUE;
            break;

        case 0x04:
        case 0x06: /* PLL used as system clock source */
            pllClock = (RCM->PLLCR & RCM_PLLCR_PLLSRC) >> RCM_PLLCR_PLLSRC_Pos;
            pllmul = (RCM->PLLCR & RCM_PLLCR_PLLMUL) >> RCM_PLLCR_PLLMUL_Pos;

            if (pllClock == 0)
            {
                pllvco = 0;
            }
            else if (pllClock == 3)
            {
                /* HSE used as PLL clock source */
                pllvco = (HSE_VALUE) * pllmul;
            }
            else
            {
                /* HSI used as PLL clock source */
                pllvco = (HSI_VALUE) * pllmul;
            }

            SystemCoreClock = pllvco;
            break;

        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    /* Compute HCLK frequency */
    /* Get HCLK prescaler */
    sysClock = AHBPrescTable[((RCM->SCCR & RCM_SCCR_HDIV) >> 4)];
    /* HCLK frequency */
    SystemCoreClock >>= sysClock;
}

/**
 * @brief     Resets the RCM configuration:
 *            - Enables HSI clock and uses it as the system clock source.
 *            - Sets AHB and APB prescalers to 1.
 *            - Disables MCO.
 *            - Disables all interrupts.
 *            - Resets all wake-up configurations.
 *
 * @param     None
 *
 * @retval    None
 */
static void SystemReset(void)
{
    /* Unlock RCM register */
    RCM->KEY |= 0x87e4;

    /* Set HSIEN bit */
    RCM->RCCR |= (uint32_t)0x00000001;

    /* Resets SCCR register */
    /* Disables MCO */
    /* Sets both AHB and APB prescalers to 1 (no division) */
    /* Selects HSI as the system clock source */
    RCM->SCCR = 0x00000000;

    /* Reset HSEEN, CSSEN and PLLEN bits */
    RCM->RCCR &= (uint32_t)0xFFFEF6FF;

    /* Reset PLLCR register */
    RCM->PLLCR = 0x00000000;

    /* Disable all interrupts */
    RCM->CIER = 0x00000000;
    
    /* If the current clock source is not HSI, switch to HSI clock */
    if (RCM->MCCR & RCM_MCCR_SWST)
    {
        /* Wait until HSI is ready */
        while ((RCM->RCCR & RCM_RCCR_HSIRDY) == 0)
        {
            /* Waiting for HSIRDY to be cleared or set (depends on definition) */
        }

        /* Start clock switching */
        RCM->MCCR |= RCM_MCCR_CSEN;

        /* Wait until clock switch is done */
        while ((RCM->MCCR & RCM_MCCR_SWDONE) != RCM_MCCR_SWDONE)
        {
            if ((RCM->MCCR & RCM_MCCR_SWERR) != 0)
            {
                /* Clock switch error handling */
            }
        }

        /* Clock switch has completed, disable switching */
        RCM->MCCR &= (uint32_t)~RCM_MCCR_CSEN;
    }

    /* Reset all digital module */
    RCM->AHBRST = 0x1E0U;
    RCM->APBRST = 0x1A00U;
    RCM->AHBRST = 0x1E3U;
    RCM->APBRST = 0x3EFFU;

    /* Lock the RCM register. */
    RCM->KEY = RCM_KEY_KEYST;
}

#ifdef VECT_TAB_SRAM

/**
 * @brief     The default interrupt handler for unexpected or unassigned interrupts.
 *
 * @param     None
 *
 * @retval    None
 */
static void Interrupt_defaultHandler(void)
{
    uint32_t vectID;

    /* Get the vector ID (bits 8:0 of xPSR.Exception). */
    vectID = __get_xPSR() & 0x1FFU;
    (void)vectID; 

    while(1)
    {
        __NOP();
    }
}

/**
 * @brief     Copies the initial system exception vectors, assigns default handlers,
 *            and updates the VTOR to use the new vector table in RAM.
 *
 * @param     None
 *
 * @retval    None
 */
static void CopyVectorTable(void)
{
    int16_t i;

    /* Copy 0-15 system exceptions from the original vector table. */
    for(i = 0; i < 16; i++)
    {
        Interrupt_vectorTable[i] = __VECTOR_TABLE[i];
    }

    /* Assign the default handler to interrupt vectors 16 to NVIC_RAM_VECTOR_SIZE. */
    for(i = 16; i < NVIC_RAM_VECTOR_SIZE; i++)
    {
        Interrupt_vectorTable[i] = Interrupt_defaultHandler;
    }

    /* Update VTOR to point to the new vector table in RAM. */
    SCB->VTOR = (uint32_t)&Interrupt_vectorTable;

    __DSB();
}

#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
