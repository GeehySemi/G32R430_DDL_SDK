/**
 *
 * @file        startup_g32r430xx.c
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

#include "g32r4xx.h"
#include <stdlib.h>

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
            void Default_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler          (void) __attribute__ ((weak));
void MemManage_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler             (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));

/* External Interrupts */
void WWDT_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void RCU_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR1_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR2_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR3_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void TMR4_IRQHandler            (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler          (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void LPTMR_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT0_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT1_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT3_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT4_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT5_9_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT10_15_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_ALARM_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void EVS_IRQHandler             (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP1_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP2_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP3_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP4_IRQHandler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TS_IRQHandler              (void) __attribute__ ((weak, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const G32R4XX_VECTOR __VECTOR_TABLE[55] __VECTOR_TABLE_ATTRIBUTE = {
  (G32R4XX_VECTOR)(&__INITIAL_SP),          /*     Initial Stack Pointer */
  Reset_Handler,                            /*     Reset Handler */
  NMI_Handler,                              /* -14 NMI Handler */
  HardFault_Handler,                        /* -13 Hard Fault Handler */
  MemManage_Handler,                        /* -12 MPU Fault Handler */
  BusFault_Handler,                         /* -11 Bus Fault Handler */
  UsageFault_Handler,                       /* -10 Usage Fault Handler */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  SVC_Handler,                              /*  -5 SVCall Handler */
  DebugMon_Handler,                         /*  -4 Debug Monitor Handler */
  0,                                        /*     Reserved */
  PendSV_Handler,                           /*  -2 PendSV Handler */
  SysTick_Handler,                          /*  -1 SysTick Handler */

  /* External Interrupts */
  WWDT_IRQHandler,                           /* Window WatchDog */
  FLASH_IRQHandler,                          /* PVD through EINT Line detection */
  RCU_IRQHandler,                            /* Tamper and TimeStamps through the EINT line */
  RTC_WKUP_IRQHandler,                       /* RTC Wakeup through the EINT line */
  DMA1_Stream0_IRQHandler,                   /* DMA1 Stream 0 */
  DMA1_Stream1_IRQHandler,                   /* DMA1 Stream 1 */
  DMA1_Stream2_IRQHandler,                   /* DMA1 Stream 2 */
  DMA1_Stream3_IRQHandler,                   /* DMA1 Stream 3 */
  DMA1_Stream4_IRQHandler,                   /* DMA1 Stream 4 */
  DMA1_Stream5_IRQHandler,                   /* DMA1 Stream 5 */
  DMA1_Stream6_IRQHandler,                   /* DMA1 Stream 6 */
  DMA1_Stream7_IRQHandler,                   /* DMA1 Stream 7 */
  ADC1_IRQHandler,                           /* ADC1 */
  ADC2_IRQHandler,                           /* ADC2 */
  ADC3_IRQHandler,                           /* ADC3 */
  TMR1_IRQHandler,                           /* TMR1 */
  TMR2_IRQHandler,                           /* TMR2 */
  TMR3_IRQHandler,                           /* TMR3 */
  TMR4_IRQHandler,                           /* TMR4 */
  SPI_IRQHandler,                            /* SPI */
  USART1_IRQHandler,                         /* USART1 */
  USART2_IRQHandler,                         /* USART2 */
  I2C_IRQHandler,                            /* I2C */
  LPTMR_IRQHandler,                          /* LPTMR */
  EINT0_IRQHandler,                          /* EINT0 */
  EINT1_IRQHandler,                          /* EINT1 */
  EINT2_IRQHandler,                          /* EINT2 */
  EINT3_IRQHandler,                          /* EINT3 */
  EINT4_IRQHandler,                          /* EINT4 */
  EINT5_9_IRQHandler,                        /* EINT5_9 */
  EINT10_15_IRQHandler,                      /* EINT10_15 */
  PVD_IRQHandler,                            /* PVD */
  RTC_ALARM_IRQHandler,                      /* RTC_ALARM */
  EVS_IRQHandler,                            /* EVS */
  COMP1_IRQHandler,                          /* COMP1 */
  COMP2_IRQHandler,                          /* COMP2 */
  COMP3_IRQHandler,                          /* COMP3 */
  COMP4_IRQHandler,                          /* COMP4 */
  TS_IRQHandler,                             /* TS */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

#if defined (__ICCARM__)
#pragma section = "itcm.ramfunc"
#pragma section = "itcm.ramfunc_init"
#pragma section = "itcm.instruction"
#pragma section = "itcm.instruction_init"
#pragma section = "atan2_instruction"
#pragma section = "atan2_instruction_init"
void ItcmData_Init(void)
{
    const uint8_t *romDataPtr;
    const uint8_t *romDataEndPtr;
    uint8_t *ramDataPtr;

    //
    // copy section itcm.ramfunc_init from Flash to RAM
    //
    romDataPtr    = __section_begin("itcm.ramfunc_init");
    romDataEndPtr = __section_end("itcm.ramfunc_init");
    ramDataPtr    = __section_begin("itcm.ramfunc");
    while (romDataEndPtr != romDataPtr)
    {
        *ramDataPtr++ = *romDataPtr++;
    }

    //
    // copy section itcm.instruction_init from Flash to RAM
    //
    romDataPtr    = __section_begin("itcm.instruction_init");
    romDataEndPtr = __section_end("itcm.instruction_init");
    ramDataPtr    = __section_begin("itcm.instruction");
    while (romDataEndPtr != romDataPtr)
    {
        *ramDataPtr++ = *romDataPtr++;
    }
    
    //
    // copy section atan2_instruction_init from Flash to RAM
    //
    romDataPtr    = __section_begin("atan2_instruction_init");
    romDataEndPtr = __section_end("atan2_instruction_init");
    ramDataPtr    = __section_begin("atan2_instruction");
    while (romDataEndPtr != romDataPtr)
    {
        *ramDataPtr++ = *romDataPtr++;
    }
}
#endif /* defined (__ICCARM__) */

#if defined (__clang__) && !defined (__ARMCC_VERSION)
extern int main(void);
void _start(void)
{
    extern void _start(void) __NO_RETURN;

    typedef struct __copy_table
    {
        uint32_t const* src;
        uint32_t* dest;
        uint32_t  wlen;
    } __copy_table_t;

    typedef struct __zero_table
    {
        uint32_t* dest;
        uint32_t  wlen;
    } __zero_table_t;

    extern const __copy_table_t __copy_table_start__;
    extern const __copy_table_t __copy_table_end__;
    extern const __zero_table_t __zero_table_start__;
    extern const __zero_table_t __zero_table_end__;

    for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable)
    {
        for(uint32_t i = 0u; i < pTable->wlen; ++i)
        {
            pTable->dest[i] = pTable->src[i];
        }
    }

    for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable)
    {
        for(uint32_t i = 0u; i < pTable->wlen; ++i)
        {
            pTable->dest[i] = 0u;
        }
    }

    main();
}
#endif /* defined (__clang__) && !defined (__ARMCC_VERSION) */

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    //
    // Initialize main stack limit register
    //
    __set_PSP((uint32_t)(&__INITIAL_SP));

    __set_MSPLIM((uint32_t)(&__STACK_LIMIT));
    __set_PSPLIM((uint32_t)(&__STACK_LIMIT));

    //
    // CMSIS System Initialization
    //
    SystemInit();

#if defined(__ICCARM__) && !defined(IAR_ITCM_AUTO_INIT)
    /* With g32r430xb_flash.icf __itcm_init_mode__==0 (manual). */
    /* If __itcm_init_mode__==1, define IAR_ITCM_AUTO_INIT and skip this call. */
    ItcmData_Init();
#endif

    //
    // Enter PreMain(__main) (C library entry point)
    //
    __PROGRAM_START();
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Hard Fault Handler
 *----------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif

