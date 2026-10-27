/**
 *
 * @file        g32r430.h
 *
 * @brief       CMSIS g32r430 Device Peripheral Access Layer Header File.
 *
 * @version     V1.0.2
 *
 * @date        2026-07-31
 *
 * @attention
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup G32R430
  * @{
  */

#ifndef __G32R430_H
#define __G32R430_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M52 Processor and Core Peripherals
  */
#define __CM52_REV                         0x0001U                                       /*!< CM52 Core Revision                                    */
#define __NVIC_PRIO_BITS                   4                                             /*!< Number of Bits used for Priority Levels               */
#define __Vendor_SysTickConfig             0                                             /*!< Set to 1 if different SysTick Config is used          */
#define __VTOR_PRESENT                     1                                             /*!< Set to 1 if CPU supports Vector Table Offset Register */
#define __MPU_PRESENT                      1                                             /*!< MPU present                                           */
#define __FPU_PRESENT                      0                                             /*!< FPU present                                           */
#define __FPU_DP                           0                                             /*!< unused, Device has no FPU                             */
#define __DSP_PRESENT                      1                                             /*!< DSP extension present                                 */
#define __SAUREGION_PRESENT                0                                             /*!< SAU region present                                    */
#define __PMU_PRESENT                      0                                             /*!< PMU present                                           */
#define __PMU_NUM_EVENTCNT                 0                                             /*!< PMU Event Counters                                    */
#define __ICACHE_PRESENT                   1U                                            /*!< Instruction Cache present                             */
#define __DCACHE_PRESENT                   1U                                            /*!< Data Cache present                                    */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief G32R4XX Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum
{
/******  Cortex-M52 Processor Exceptions Numbers **************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M52 Memory Management Interrupt             */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M52 Bus Fault Interrupt                     */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M52 Usage Fault Interrupt                   */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M52 SV Call Interrupt                      */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M52 Debug Monitor Interrupt                */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M52 Pend SV Interrupt                      */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M52 System Tick Interrupt                  */
/******  G32R4 specific Interrupt Numbers *********************************************************/
  WWDT_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  FLASH_IRQn                  = 1,      /*!< FLASH global Interrupt                               */
  RCU_IRQn                    = 2,      /*!< Reset clock management Interrupt                     */
  RTC_IRQn                    = 3,      /*!< RTC Wakeup interrupt through the EINT line           */
  DMA1_Stream0_IRQn           = 4,      /*!< DMA Stream 0 global Interrupt                        */
  DMA1_Stream1_IRQn           = 5,      /*!< DMA Stream 1 global Interrupt                        */
  DMA1_Stream2_IRQn           = 6,      /*!< DMA Stream 2 global Interrupt                        */
  DMA1_Stream3_IRQn           = 7,      /*!< DMA Stream 3 global Interrupt                        */
  DMA1_Stream4_IRQn           = 8,      /*!< DMA Stream 4 global Interrupt                        */
  DMA1_Stream5_IRQn           = 9,      /*!< DMA Stream 5 global Interrupt                        */
  DMA1_Stream6_IRQn           = 10,     /*!< DMA Stream 6 global Interrupt                        */
  DMA1_Stream7_IRQn           = 11,     /*!< DMA Stream 7 global Interrupt                        */
  ADC1_IRQn                   = 12,     /*!< ADC1 global Interrupts                               */
  ADC2_IRQn                   = 13,     /*!< ADC2 global Interrupts                               */
  ADC3_IRQn                   = 14,     /*!< ADC3 global Interrupts                               */
  TMR1_IRQn                   = 15,     /*!< TMR1 global Interrupt                                */
  TMR2_IRQn                   = 16,     /*!< TMR2 global Interrupt                                */
  TMR3_IRQn                   = 17,     /*!< TMR3 global Interrupt                                */
  TMR4_IRQn                   = 18,     /*!< TMR4 global Interrupt                                */
  SPI_IRQn                    = 19,     /*!< SPI global Interrupt                                 */
  USART1_IRQn                 = 20,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 21,     /*!< USART2 global Interrupt                              */
  I2C_IRQn                    = 22,     /*!< I2C global Interrupt                                 */
  LPTMR_IRQn                  = 23,     /*!< LPTMR global Interrupt                               */
  EINT0_IRQn                  = 24,     /*!< EINT Line0 Interrupt                                 */
  EINT1_IRQn                  = 25,     /*!< EINT Line1 Interrupt                                 */
  EINT2_IRQn                  = 26,     /*!< EINT Line2 Interrupt                                 */
  EINT3_IRQn                  = 27,     /*!< EINT Line3 Interrupt                                 */
  EINT4_IRQn                  = 28,     /*!< EINT Line4 Interrupt                                 */
  EINT5_9_IRQn                = 29,     /*!< EINT Line[9:5] Interrupt                             */
  EINT10_15_IRQn              = 30,     /*!< EINT Line[15:10] Interrupts                          */
  PVD_IRQn                    = 31,     /*!< PVD through EINT16 Line detection Interrupt          */
  RTC_ALARM_IRQn              = 32,     /*!< RTC_ALARM through EINT17 Line detection Interrupt    */
  EVS_IRQn                    = 33,     /*!< Main Power Wake-up Interrupt                         */
  COMP1_IRQn                  = 34,     /*!< COMP1 through EINT19 Line detection Interrupt        */
  COMP2_IRQn                  = 35,     /*!< COMP2 through EINT20 Line detection Interrupt        */
  COMP3_IRQn                  = 36,     /*!< COMP3 through EINT21 Line detection Interrupt        */
  COMP4_IRQn                  = 37,     /*!< COMP4 through EINT22 Line detection Interrupt        */
  TS_IRQn                     = 38,     /*!< TS Temperature Sensor Interrupt                      */
} IRQn_Type;

/**
  * @}
  */

/* Define macros to place functions or variables in specific memory sections */
/* Usage: */
/* - Use these macros before function declarations or variable definitions to place them in specific sections. */
/* - Ensure that the linker script (MDK) or ICF file (IAR), or LD script (GCC) includes the corresponding sections. */

#if defined (__CC_ARM) || defined (__ICCARM__) || defined (__GNUC__) || defined (__ARMCC_VERSION)
  #define SECTION_ITCM_INSTRUCTION           __attribute__((section("itcm.instruction")))
  #define SECTION_ITCM_RAMFUNC               __attribute__((section("itcm.ramfunc")))
  #define SECTION_DTCM_DATA                  __attribute__((section("dtcm.data")))
  #define SECTION_DTCM_BSS                   __attribute__((section("dtcm.bss")))
#else
  #error "Unsupported compiler: no section macros can be defined."
#endif

#if defined (__clang__) && !defined (__ARMCC_VERSION)
    #define SECTION_RAM_VEC                    __attribute__((section("ram.intvec")))
#else
    #define SECTION_RAM_VEC                    __attribute__((section(".bss.ram.intvec")))
#endif

#include "core_cm52.h"             /* Cortex-M52 processor and core peripherals */
#include "system_g32r4xx.h"
#include <stdint.h>
/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  __IO uint32_t ISR;           /*!< ADC interrupt and status register,             Address offset: 0x00 */
  __IO uint32_t IER;           /*!< ADC interrupt enable register,                 Address offset: 0x04 */
  __IO uint32_t CR;            /*!< ADC control register,                          Address offset: 0x08 */
  __IO uint32_t CFGR;          /*!< ADC configuration register 1,                  Address offset: 0x0C */
  __IO uint32_t CFGR2;         /*!< ADC configuration register 2,                  Address offset: 0x10 */
  __IO uint32_t SMPR1;         /*!< ADC sampling time register 1,                  Address offset: 0x14 */
  __IO uint32_t RESERVED1;
  __IO uint32_t RESERVED2;
  __IO uint32_t TR1;           /*!< ADC analog watchdog 1 threshold register,      Address offset: 0x20 */
  __IO uint32_t TR2;           /*!< ADC analog watchdog 2 threshold register,      Address offset: 0x24 */
  __IO uint32_t TR3;           /*!< ADC analog watchdog 3 threshold register,      Address offset: 0x28 */
  __IO uint32_t RESERVED3;
  __IO uint32_t SQR1;          /*!< ADC group regular sequencer register 1,        Address offset: 0x30 */
  __IO uint32_t SQR2;          /*!< ADC group regular sequencer register 2,        Address offset: 0x34 */
  __IO uint32_t DR;            /*!< ADC group regular data register,               Address offset: 0x38 */
  __IO uint32_t JSQR;          /*!< ADC group injected sequencer register,         Address offset: 0x3C */
  __IO uint32_t JDR1;          /*!< ADC group injected rank 1 data register,       Address offset: 0x40 */
  __IO uint32_t JDR2;          /*!< ADC group injected rank 2 data register,       Address offset: 0x44 */
  __IO uint32_t JDR3;          /*!< ADC group injected rank 3 data register,       Address offset: 0x48 */
  __IO uint32_t JDR4;          /*!< ADC group injected rank 4 data register,       Address offset: 0x4C */
  __IO uint32_t AWD2CR;        /*!< ADC analog watchdog 2 configuration register,  Address offset: 0x50 */
  __IO uint32_t AWD3CR;        /*!< ADC analog watchdog 3 Configuration Register,  Address offset: 0x54 */
  __IO uint32_t OFFSET0;       /*!< ADC offset register 0,                         Address offset: 0x58 */
  __IO uint32_t OFFSET1;       /*!< ADC offset register 1,                         Address offset: 0x5C */
  __IO uint32_t OFFSET2;       /*!< ADC offset register 2,                         Address offset: 0x60 */
  __IO uint32_t OFFSET3;       /*!< ADC offset register 3,                         Address offset: 0x64 */
  __IO uint32_t OFFSET4;       /*!< ADC offset register 4,                         Address offset: 0x68 */
  __IO uint32_t OFFSET5;       /*!< ADC offset register 5,                         Address offset: 0x6C */
  __IO uint32_t RESERVED4[4];
  __IO uint32_t CAL;           /*!< ADC calibration,                               Address offset: 0x80 */
} ADC16_TypeDef;

typedef struct
{
  __IO uint32_t ISR;           /*!< ADC interrupt and status register,         Address offset: 0x00 */
  __IO uint32_t IER;           /*!< ADC interrupt enable register,             Address offset: 0x04 */
  __IO uint32_t CR;            /*!< ADC control register,                      Address offset: 0x08 */
  __IO uint32_t CFGR;          /*!< ADC configuration register 1,              Address offset: 0x0C */
  __IO uint32_t RESERVED1;
  __IO uint32_t SMPR1;         /*!< ADC sampling time register 1,              Address offset: 0x14 */
  __IO uint32_t SMPR2;         /*!< ADC sampling time register 2,              Address offset: 0x18 */
  __IO uint32_t RESERVED2;
  __IO uint32_t TR1;           /*!< ADC analog watchdog 1 threshold register,  Address offset: 0x20 */
  __IO uint32_t RESERVED3[2];
  __IO uint32_t SQR1;          /*!< ADC group regular sequencer register 1,    Address offset: 0x2C */
  __IO uint32_t SQR2;          /*!< ADC group regular sequencer register 3,    Address offset: 0x30 */
  __IO uint32_t SQR3;          /*!< ADC group regular sequencer register 3,    Address offset: 0x34 */
  __IO uint32_t DR;            /*!< ADC group regular data register,           Address offset: 0x38 */
  __IO uint32_t JSQR;          /*!< ADC group injected sequencer register,     Address offset: 0x3C */
  __IO uint32_t JDR1;          /*!< ADC group injected rank 1 data register,   Address offset: 0x40 */
  __IO uint32_t JDR2;          /*!< ADC group injected rank 2 data register,   Address offset: 0x44 */
  __IO uint32_t JDR3;          /*!< ADC group injected rank 3 data register,   Address offset: 0x48 */
  __IO uint32_t JDR4;          /*!< ADC group injected rank 4 data register,   Address offset: 0x4C */
  __IO uint32_t RESERVED4[2];
  __IO uint32_t JOFFSET1;      /*!< ADC offset register 0,                     Address offset: 0x58 */
  __IO uint32_t JOFFSET2;      /*!< ADC offset register 1,                     Address offset: 0x5C */
  __IO uint32_t JOFFSET3;      /*!< ADC offset register 2,                     Address offset: 0x60 */
  __IO uint32_t JOFFSET4;      /*!< ADC offset register 3,                     Address offset: 0x64 */
} ADC12_TypeDef;

/**
  * @brief DAC
  */
typedef struct
{
  __IO uint32_t CR;      /*!< Control registers,                               Address offset: 0x00 */
  __IO uint32_t SWTRGR;  /*!< Software Triggered Register,                     Address offset: 0x04 */
  __IO uint32_t DHR10R;  /*!< DAC channel 10-bit right-aligned data register,  Address offset: 0x08 */
  __IO uint32_t DHR10L;  /*!< DAC channel 10-bit left-aligned data register,   Address offset: 0x0C */
  __IO uint32_t DOR;     /*!< DAC channel data output register,                Address offset: 0x10 */
  __IO uint32_t STR;     /*!< DAC channel sawtooth waveform register,          Address offset: 0x14 */
  __IO uint32_t STMODR;  /*!< DAC sawtooth mode register,                      Address offset: 0x18 */
  __IO uint32_t SR;      /*!< DAC status register,                             Address offset: 0x1C */
} DAC_TypeDef;

/**
  * @brief Debug MCU
  */

typedef struct
{
  __IO uint32_t ID;           /*!< MCU device ID,                  Address offset: 0x00 */
  uint32_t      RESERVED[2];
  __IO uint32_t APB;          /*!< Debug MCU APB freeze register,  Address offset: 0x0C */
} DBGMCU_TypeDef;

/**
  * @brief DMA Controller
  */

typedef struct
{
  __IO uint32_t SCFG;    /*!< DMA stream x configuration register      */
  __IO uint32_t NDATA;   /*!< DMA stream x number of data register     */
  __IO uint32_t PADDR;   /*!< DMA stream x peripheral address register */
  __IO uint32_t M0ADDR;  /*!< DMA stream x memory 0 address register   */
  __IO uint32_t M1ADDR;  /*!< DMA stream x memory 1 address register   */
  __IO uint32_t FCTRL;   /*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct
{
  __I  uint32_t LINTSTS;  /*!< DMA low interrupt status register,       Address offset: 0x00 */
  __I  uint32_t HINTSTS;  /*!< DMA high interrupt status register,      Address offset: 0x04 */
  __O  uint32_t LIFCLR;   /*!< DMA low interrupt flag clear register,   Address offset: 0x08 */
  __O  uint32_t HIFCLR;   /*!< DMA high interrupt flag clear register,  Address offset: 0x0C */
} DMA_TypeDef;

/**
  * @brief External Interrupt/Event Controller
  */

typedef struct
{
  __IO uint32_t IMASK;    /*!< EINT Interrupt mask register,             Address offset: 0x00 */
  __IO uint32_t EMASK;    /*!< EINT Event mask register,                 Address offset: 0x04 */
  __IO uint32_t RTEN;     /*!< EINT Rising trigger selection register,   Address offset: 0x08 */
  __IO uint32_t FTEN;     /*!< EINT Falling trigger selection register,  Address offset: 0x0C */
  __IO uint32_t SWINTE;   /*!< EINT Software interrupt event register,   Address offset: 0x10 */
  __IO uint32_t IPEND;    /*!< EINT Pending register,                    Address offset: 0x14 */
  __IO uint32_t IOSELR1;  /*!< EINT IO select register,                  Address offset: 0x18 */
  __IO uint32_t IOSELR2;  /*!< EINT IO select register,                  Address offset: 0x1C */
} EINT_TypeDef;

/**
  * @brief FLASH Registers
  */

typedef struct
{
  __IO uint32_t KEY;        /*!< FLASH key register,               Address offset: 0x00 */
  __IO uint32_t OPTKEY;     /*!< FLASH option key register,        Address offset: 0x04 */
  __IO uint32_t SR;         /*!< FLASH status register,            Address offset: 0x08 */
  __IO uint32_t CR1;        /*!< FLASH control register,           Address offset: 0x0C */
  __IO uint32_t CR2;        /*!< FLASH control register,           Address offset: 0x10 */
  __IO uint32_t RESERVED;
  __IO uint32_t TMCR;       /*!< FLASH Clock Frequency ,           Address offset: 0x18 */
  __IO uint32_t RESERVED1;
  __IO uint32_t OBSR1;      /*!< FLASH option status register 0,   Address offset: 0x20 */
  __IO uint32_t OBSR2;      /*!< FLASH option status register 1,   Address offset: 0x24 */
  __IO uint32_t OBCR1;      /*!< FLASH option control register 1,  Address offset: 0x28 */
  __IO uint32_t OBCR2;      /*!< FLASH option control register 1,  Address offset: 0x2C */
} FLASH_TypeDef;

/**
  * @brief General Purpose I/O
  */

typedef struct
{
  __IO uint32_t MODER1;    /*!< GPIO mode register 1,                Address offset: 0x00 */
  __IO uint32_t MODER2;    /*!< GPIO mode register 2,                Address offset: 0x04 */
  __IO uint32_t MODER3;    /*!< GPIO mode register 3,                Address offset: 0x08 */
  __IO uint32_t MODER4;    /*!< GPIO mode register 4,                Address offset: 0x0C */
  __IO uint32_t PUPDR1;    /*!< GPIO pull-up/pull-down register 1,   Address offset: 0x10 */
  __IO uint32_t PUPDR2;    /*!< GPIO pull-up/pull-down register 2,   Address offset: 0x14 */
  __IO uint32_t PUPDR3;    /*!< GPIO pull-up/pull-down register 3,   Address offset: 0x18 */
  __IO uint32_t PUPDR4;    /*!< GPIO pull-up/pull-down register 4,   Address offset: 0x1C */
  __IO uint32_t OTYPER1;   /*!< GPIO output type register 1,         Address offset: 0x20 */
  __IO uint32_t OTYPER2;   /*!< GPIO output type register 2,         Address offset: 0x24 */
  __IO uint32_t OSPEEDR1;  /*!< GPIO output speed register 1,        Address offset: 0x28 */
  __IO uint32_t OSPEEDR2;  /*!< GPIO output speed register 2,        Address offset: 0x2C */
  __IO uint32_t OSPEEDR3;  /*!< GPIO output speed register 3,        Address offset: 0x30 */
  __IO uint32_t OSPEEDR4;  /*!< GPIO output speed register 4,        Address offset: 0x34 */
  __IO uint32_t IDR1;      /*!< GPIO input data register 1,          Address offset: 0x38 */
  __IO uint32_t IDR2;      /*!< GPIO input data register 2,          Address offset: 0x3C */
  __IO uint32_t ODR1;      /*!< GPIO output data register 1,         Address offset: 0x40 */
  __IO uint32_t ODR2;      /*!< GPIO output data register 2,         Address offset: 0x44 */
  __IO uint32_t AFSELR1;   /*!< GPIO alternate function register 1,  Address offset: 0x48 */
  __IO uint32_t AFSELR2;   /*!< GPIO alternate function register 2,  Address offset: 0x4C */
  __IO uint32_t AFSELR3;   /*!< GPIO alternate function register 3,  Address offset: 0x50 */
  __IO uint32_t AFSELR4;   /*!< GPIO alternate function register 4,  Address offset: 0x54 */
  __IO uint32_t FILTERR1;  /*!< Wave Filter Enable Register 1,       Address offset: 0x58 */
  __IO uint32_t FILTERR2;  /*!< Wave Filter Enable Register 2,       Address offset: 0x5C */
  __O  uint32_t BSRR1;     /*!< Bit Set/Reset Register 1,            Address offset: 0x60 */
  __O  uint32_t BSRR2;     /*!< Bit Set/Reset Register 2,            Address offset: 0x64 */
  __O  uint32_t BSRR3;     /*!< Bit Set/Reset Register 3,            Address offset: 0x68 */
  __O  uint32_t BSRR4;     /*!< Bit Set/Reset Register 4,            Address offset: 0x6C */
  __IO uint32_t BRR1;      /*!< Bit Reset Register 1,                Address offset: 0x70 */
  __IO uint32_t BRR2;      /*!< Bit Reset Register 2,                Address offset: 0x74 */
  __IO uint32_t BRR3;      /*!< Bit Reset Register 3,                Address offset: 0x78 */
  __IO uint32_t BRR4;      /*!< Bit Reset Register 4,                Address offset: 0x7C */
  __IO uint32_t SWR1;      /*!< Analog switch reg 1 (ADC3 or 5VIO PB4/PB6/PC12; keep 0 otherwise), Address offset: 0x80 */
  __IO uint32_t SWR2;      /*!< Analog switch reg 2 (ADC3 or 5VIO PD5/PD12; PD15 EVS keep 0; else 0), Address offset: 0x84 */
} GPIO_TypeDef;

/**
  * @brief LPTMR
  */

typedef struct
{
  __IO uint32_t CR;   /*!< LPTMR control register,       Address offset: 0x00 */
  __IO uint32_t PSC;  /*!< LPTMR presclar register,      Address offset: 0x04 */
  __IO uint32_t WVR;  /*!< LPTMR wakeup value register,  Address offset: 0x08 */
  __IO uint32_t SR;   /*!< LPTMR status register,        Address offset: 0x0C */
} LPTMR_TypeDef;

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t KEY;           /*!< RCM key register,                      Address offset: 0x00 */
  __IO uint32_t RCCR;          /*!< RCM reset and clock control register,  Address offset: 0x04 */
  __IO uint32_t PLLCR;         /*!< RCM PLL control register,              Address offset: 0x08 */
  __IO uint32_t SCCR;          /*!< RCM system clock control register,     Address offset: 0x0C */
  __IO uint32_t MCCR;          /*!< RCM master clock control register,     Address offset: 0x10 */
  __IO uint32_t CIER;          /*!< RCM clock interrupt enable register,   Address offset: 0x14 */
  __IO uint32_t CICR;          /*!< RCM clock interrupt clear register,    Address offset: 0x18 */
  uint32_t      RESERVED0;
  __IO uint32_t AHBRST;        /*!< RCM AHB reset register,                Address offset: 0x20 */
  __IO uint32_t APBRST;        /*!< RCM APB reset register,                Address offset: 0x24 */
  __IO uint32_t AHBCG;         /*!< RCM AHB clock register,                Address offset: 0x28 */
  uint32_t      RESERVED1;
  __IO uint32_t APBCG;         /*!< RCM APB clock register,                Address offset: 0x30 */
  uint32_t      RESERVED2;
  __IO uint32_t PWRCR;         /*!< RCM power control register,            Address offset: 0x38 */
  __IO uint32_t RSTCSR;        /*!< RCM reset control / status register,   Address offset: 0x3C */
  uint32_t      RESERVED3;
  __IO uint32_t ADCCR;         /*!< RCM ADC control register,              Address offset: 0x44 */
  uint32_t      RESERVED4[6];
  __IO uint32_t SYS_ANACR0;    /*!< RCM system analog control register 0,  Address offset: 0x60 */
} RCM_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */

typedef struct
{
  __IO uint32_t CTRL1;     /*!< I2C Control register 1,      Address offset: 0x00 */
  __IO uint32_t CTRL2;     /*!< I2C Control register 2,      Address offset: 0x04 */
  __IO uint32_t SADDR1;    /*!< I2C Own address register 1,  Address offset: 0x08 */
  __IO uint32_t SADDR2;    /*!< I2C Own address register 2,  Address offset: 0x0C */
  __IO uint32_t DATA;      /*!< I2C Data register,           Address offset: 0x10 */
  __IO uint32_t STS1;      /*!< I2C Status register 1,       Address offset: 0x14 */
  __IO uint32_t STS2;      /*!< I2C Status register 2,       Address offset: 0x18 */
  __IO uint32_t CLKCTRL;   /*!< I2C Clock control register,  Address offset: 0x1C */
  __IO uint32_t RISETMAX;  /*!< I2C RISETMAX register,       Address offset: 0x20 */
  __IO uint32_t FILTER;    /*!< I2C Filter register,         Address offset: 0x24 */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */

typedef struct
{
  __IO uint32_t KEY;     /*!< IWDT Key register,        Address offset: 0x00 */
  __IO uint32_t PSC;     /*!< IWDT Prescaler register,  Address offset: 0x04 */
  __IO uint32_t CNTRLD;  /*!< IWDT Reload register,     Address offset: 0x08 */
  __IO uint32_t STS;     /*!< IWDT Status register,     Address offset: 0x0C */
} IWDT_TypeDef;

/**
  * @brief Real-Time Clock
  */

typedef struct
{
  __IO uint32_t CTRL;     /*!< RTC control register,                       Address offset: 0x00 */
  __IO uint32_t CSTS;     /*!< RTC control / status register,              Address offset: 0x04 */
  __IO uint32_t PSCRLDH;  /*!< RTC prescaler reload high bit register,     Address offset: 0x08 */
  __IO uint32_t PSCRLDL;  /*!< RTC prescaler reload low bit register,      Address offset: 0x0C */
  __IO uint32_t DIVH;     /*!< RTC prescaler remainder high bit register,  Address offset: 0x10 */
  __IO uint32_t DIVL;     /*!< RTC prescaler remainder low bit register,   Address offset: 0x14 */
  __IO uint32_t CNTH;     /*!< RTC counter high bit register,              Address offset: 0x18 */
  __IO uint32_t CNTL;     /*!< RTC counter low bit register,               Address offset: 0x1C */
  __IO uint32_t ALRH;     /*!< RTC alarm high bit register,                Address offset: 0x20 */
  __IO uint32_t ALRL;     /*!< RTC alarm low bit register,                 Address offset: 0x24 */
} RTC_TypeDef;

/**
  * @brief Power manager unit
  */

typedef struct
{
  __IO uint32_t CR;         /*!< Backup control register,                  Address offset: 0x00 */
  __IO uint32_t WKPCR;      /*!< Backup wakeup polarity control register,  Address offset: 0x04 */
  __IO uint32_t SR;         /*!< Backup status register,                   Address offset: 0x08 */
  uint32_t      RESERVED0;
  __IO uint32_t PUCRA;      /*!< Backup pull up control register,          Address offset: 0x10 */
  __IO uint32_t PDCRA;      /*!< Backup pull down control register,        Address offset: 0x14 */
  uint32_t      RESERVED1;
  __IO uint32_t EVSCR;      /*!< EVS control register,                     Address offset: 0x1C */
  __IO uint32_t PVDCR;      /*!< Backup PVD control register,              Address offset: 0x20 */
} PMU_TypeDef;

/**
  * @brief Back up
  */

typedef struct
{
  __IO uint32_t DR0;   /*!< Backup data register 0,   Address offset: 0x00 */
  __IO uint32_t DR1;   /*!< Backup data register 1,   Address offset: 0x04 */
  __IO uint32_t DR2;   /*!< Backup data register 2,   Address offset: 0x08 */
  __IO uint32_t DR3;   /*!< Backup data register 3,   Address offset: 0x0C */
  __IO uint32_t DR4;   /*!< Backup data register 4,   Address offset: 0x10 */
  __IO uint32_t DR5;   /*!< Backup data register 5,   Address offset: 0x14 */
  __IO uint32_t DR6;   /*!< Backup data register 6,   Address offset: 0x18 */
  __IO uint32_t DR7;   /*!< Backup data register 7,   Address offset: 0x1C */
  __IO uint32_t DR8;   /*!< Backup data register 8,   Address offset: 0x20 */
  __IO uint32_t DR9;   /*!< Backup data register 9,   Address offset: 0x24 */
  __IO uint32_t DR10;  /*!< Backup data register 10,  Address offset: 0x28 */
  __IO uint32_t DR11;  /*!< Backup data register 11,  Address offset: 0x2C */
  __IO uint32_t DR12;  /*!< Backup data register 12,  Address offset: 0x30 */
  __IO uint32_t DR13;  /*!< Backup data register 13,  Address offset: 0x34 */
  __IO uint32_t DR14;  /*!< Backup data register 14,  Address offset: 0x38 */
  __IO uint32_t DR15;  /*!< Backup data register 15,  Address offset: 0x3C */
} BKP_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */

typedef struct
{
  __IO uint32_t CTRL1;    /*!< SPI control register 1,       Address offset: 0x00 */
  __IO uint32_t CTRL2;    /*!< SPI control register 2,       Address offset: 0x04 */
  __IO uint32_t STS;      /*!< SPI status register,          Address offset: 0x08 */
  __IO uint32_t DATA;     /*!< SPI data register,            Address offset: 0x0C */
  __IO uint32_t CRCPOLY;  /*!< SPI CRC polynomial register,  Address offset: 0x10 */
  __IO uint32_t RXCRC;    /*!< SPI RX CRC register,          Address offset: 0x14 */
  __IO uint32_t TXCRC;    /*!< SPI TX CRC register,          Address offset: 0x18 */
  __IO uint32_t BCR;      /*!< SPI BISS control register,    Address offset: 0x1C */
  __IO uint32_t BCFG;     /*!< SPI BISS configure register,  Address offset: 0x20 */
  __IO uint32_t CDMDATA;  /*!< SPI CDM data register,        Address offset: 0x24 */
} SPI_TypeDef;

/**
  * @brief TMR
  */

typedef struct
{
  __IO uint32_t CTRL1;    /*!< TMR control register 1,                        Address offset: 0x00 */
  __IO uint32_t CTRL2;    /*!< TMR control register 2,                        Address offset: 0x04 */
  __IO uint32_t SMCTRL;   /*!< TMR slave mode control register,               Address offset: 0x08 */
  __IO uint32_t DIEN;     /*!< TMR DMA/interrupt enable register,             Address offset: 0x0C */
  __IO uint32_t STS;      /*!< TMR status register,                           Address offset: 0x10 */
  __IO uint32_t CEG;      /*!< TMR event generation register,                 Address offset: 0x14 */
  __IO uint32_t CCM1;     /*!< TMR capture/compare mode register 1,           Address offset: 0x18 */
  __IO uint32_t CCM2;     /*!< TMR capture/compare mode register 2,           Address offset: 0x1C */
  __IO uint32_t CCEN;     /*!< TMR capture/compare enable register,           Address offset: 0x20 */
  __IO uint32_t CNT;      /*!< TMR counter register,                          Address offset: 0x24 */
  __IO uint32_t PSC;      /*!< TMR prescaler,                                 Address offset: 0x28 */
  __IO uint32_t AUTORLD;  /*!< TMR auto-reload register,                      Address offset: 0x2C */
  __IO uint32_t REPCNT;   /*!< TMR repetition counter register (TMR1 only),   Address offset: 0x30 */
  __IO uint32_t CC1;      /*!< TMR capture/compare register 1,                Address offset: 0x34 */
  __IO uint32_t CC2;      /*!< TMR capture/compare register 2,                Address offset: 0x38 */
  __IO uint32_t CC3;      /*!< TMR capture/compare register 3,                Address offset: 0x3C */
  __IO uint32_t CC4;      /*!< TMR capture/compare register 4,                Address offset: 0x40 */
  __IO uint32_t BDT;      /*!< TMR break and dead-time register (TMR1 only),  Address offset: 0x44 */
  __IO uint32_t DCTRL;    /*!< TMR DMA control register,                      Address offset: 0x48 */
  __IO uint32_t DMADDR;   /*!< TMR DMA address for full transfer,             Address offset: 0x4C */
} TMR_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */

typedef struct
{
  __IO uint32_t STS;    /*!< USART Status register,                    Address offset: 0x00 */
  __IO uint32_t DATA;   /*!< USART Data register,                      Address offset: 0x04 */
  __IO uint32_t BR;     /*!< USART Baud rate register,                 Address offset: 0x08 */
  __IO uint32_t CTRL1;  /*!< USART Control register 1,                 Address offset: 0x0C */
  __IO uint32_t CTRL2;  /*!< USART Control register 2,                 Address offset: 0x10 */
  __IO uint32_t CTRL3;  /*!< USART Control register 3,                 Address offset: 0x14 */
  __IO uint32_t GTPSC;  /*!< USART Guard time and prescaler register,  Address offset: 0x18 */
} USART_TypeDef;

/**
  * @brief Window WATCHDOG
  */

typedef struct
{
  __IO uint32_t CTRL;  /*!< WWDT Control register,        Address offset: 0x00 */
  __IO uint32_t CFG;   /*!< WWDT Configuration register,  Address offset: 0x04 */
  __IO uint32_t STS;   /*!< WWDT Status register,         Address offset: 0x08 */
} WWDT_TypeDef;

/**
  * @brief Temperature sensor
  */

typedef struct
{
    __IO uint32_t CR;  /*!< TS Control register,  Address offset: 0x00 */
    __IO uint32_t DR;  /*!< TS Data register,     Address offset: 0x04 */
    __IO uint32_t SR;  /*!< TS Status register,   Address offset: 0x08 */
} TS_TypeDef;

/**
  * @brief Comparator
  */

typedef struct
{
    __IO uint32_t CxCSR;  /*!< COMP control and status register (x=1..4),  Address offset: 0x00 */
} COMP_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define ROM_BASE         0x00100000UL  /*!< ROM(up to 8 KB) base address in the alias region    */
#define ROM_END          0x00101FFFUL  /*!< ROM end address                                     */
#define FLASH_BASE       0x08000000UL  /*!< FLASH(128 KB) base address in the alias region      */
#define FLASH_END        0x0801FFFFUL  /*!< FLASH end address                                   */
#define FLASH_NVR_BASE   0x08020000UL  /*!< FLASH nvr base address in the alias region          */
#define FLASH_NVR_END    0x080203FFUL  /*!< FLASH nvr end address                               */
#define ITCM_BASE        0x00000000UL  /*!< ITCM(32 KB) base address in the alias region        */
#define ITCM_END         0x00007FFFUL  /*!< ITCM end address                                    */
#define DTCM_BASE        0x20000000UL  /*!< DTCM(16 KB) base address in the alias region        */
#define DTCM_END         0x20003FFFUL  /*!< DTCM end address                                    */
#define FLASH_TRIM_BASE  0x1FFF0200UL  /*!< FLASH TRIM base address in the alias region         */
#define FLASH_TRIM_END   0x1FFF03FFUL  /*!< FLASH TRIM end address in the alias region          */
#define PERIPH_BASE      0x40000000UL  /*!< Peripheral base address in the alias region         */

/* Legacy defines */
#define SRAM_BASE  DTCM_BASE

/*!< Peripheral memory map */
#define APBPERIPH_BASE  PERIPH_BASE
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000UL)

/*!< APB peripherals */
#define TMR1_BASE    (APBPERIPH_BASE + 0x0000UL)
#define TMR2_BASE    (APBPERIPH_BASE + 0x0400UL)
#define TMR3_BASE    (APBPERIPH_BASE + 0x0800UL)
#define TMR4_BASE    (APBPERIPH_BASE + 0x0C00UL)
#define SPI_BASE     (APBPERIPH_BASE + 0x1000UL)
#define USART1_BASE  (APBPERIPH_BASE + 0x1400UL)
#define USART2_BASE  (APBPERIPH_BASE + 0x1800UL)
#define I2C_BASE     (APBPERIPH_BASE + 0x1C00UL)
#define WWDT_BASE    (APBPERIPH_BASE + 0x2000UL)
#define IWDT_BASE    (APBPERIPH_BASE + 0x2400UL)
#define EINT_BASE    (APBPERIPH_BASE + 0x2800UL)
#define DAC1_BASE    (APBPERIPH_BASE + 0x2C00UL)
#define DAC2_BASE    (APBPERIPH_BASE + 0x3000UL)
#define COMP1_BASE   (APBPERIPH_BASE + 0x3400UL)
#define COMP2_BASE   (APBPERIPH_BASE + 0x3404UL)
#define COMP3_BASE   (APBPERIPH_BASE + 0x3408UL)
#define COMP4_BASE   (APBPERIPH_BASE + 0x340CUL)
#define PMU_BASE     (APBPERIPH_BASE + 0x3800UL)
#define BKP_BASE     (APBPERIPH_BASE + 0x3830UL)
#define RTC_BASE     (APBPERIPH_BASE + 0x3A00UL)
#define LPTMR_BASE   (APBPERIPH_BASE + 0x3B00UL)
#define TS_BASE      (APBPERIPH_BASE + 0x3C00UL)
#define DBGMCU_BASE  (APBPERIPH_BASE + 0x5800UL)

/*!< AHB peripherals */
#define DMA1_BASE       (AHBPERIPH_BASE + 0x0000UL)
#define RCM_BASE        (AHBPERIPH_BASE + 0x0400UL)
#define FLASHCTRL_BASE  (AHBPERIPH_BASE + 0x0800UL)
#define ADC1_BASE       (AHBPERIPH_BASE + 0x0C00UL)
#define ADC2_BASE       (AHBPERIPH_BASE + 0x1000UL)
#define ADC3_BASE       (AHBPERIPH_BASE + 0x1400UL)
#define GPIO_BASE       (AHBPERIPH_BASE + 0x1800UL)

/* DMA Stream base */
#define DMA1_Stream0_BASE  (DMA1_BASE + 0x10)
#define DMA1_Stream1_BASE  (DMA1_BASE + 0x28)
#define DMA1_Stream2_BASE  (DMA1_BASE + 0x40)
#define DMA1_Stream3_BASE  (DMA1_BASE + 0x58)
#define DMA1_Stream4_BASE  (DMA1_BASE + 0x70)
#define DMA1_Stream5_BASE  (DMA1_BASE + 0x88)
#define DMA1_Stream6_BASE  (DMA1_BASE + 0xA0)
#define DMA1_Stream7_BASE  (DMA1_BASE + 0xB8)

/*!< FLASH Size register base address */
#define FLASHSIZE_BASE  0x08020208UL
/*!< Unique device ID register base address */
#define UID_BASE        0x0802020CUL

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */
#define TMR1    ((TMR_TypeDef *) TMR1_BASE)
#define TMR2    ((TMR_TypeDef *) TMR2_BASE)
#define TMR3    ((TMR_TypeDef *) TMR3_BASE)
#define TMR4    ((TMR_TypeDef *) TMR4_BASE)
#define SPI1    ((SPI_TypeDef *) SPI_BASE)
#define USART1  ((USART_TypeDef *) USART1_BASE)
#define USART2  ((USART_TypeDef *) USART2_BASE)
#define I2C1    ((I2C_TypeDef *) I2C_BASE)
#define WWDT    ((WWDT_TypeDef *) WWDT_BASE)
#define IWDT    ((IWDT_TypeDef *) IWDT_BASE)
#define EINT    ((EINT_TypeDef *) EINT_BASE)
#define DAC1    ((DAC_TypeDef *) DAC1_BASE)
#define DAC2    ((DAC_TypeDef *) DAC2_BASE)
#define COMP1   ((COMP_TypeDef *) COMP1_BASE)
#define COMP2   ((COMP_TypeDef *) COMP2_BASE)
#define COMP3   ((COMP_TypeDef *) COMP3_BASE)
#define COMP4   ((COMP_TypeDef *) COMP4_BASE)
#define PMU     ((PMU_TypeDef *) PMU_BASE)
#define BKP     ((BKP_TypeDef *) BKP_BASE)
#define RTC     ((RTC_TypeDef *) RTC_BASE)
#define LPTMR   ((LPTMR_TypeDef *) LPTMR_BASE)
#define TS      ((TS_TypeDef *) TS_BASE)
#define DBGMCU  ((DBGMCU_TypeDef *) DBGMCU_BASE)

#define DMA1          ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Stream0  ((DMA_Stream_TypeDef *) DMA1_Stream0_BASE)
#define DMA1_Stream1  ((DMA_Stream_TypeDef *) DMA1_Stream1_BASE)
#define DMA1_Stream2  ((DMA_Stream_TypeDef *) DMA1_Stream2_BASE)
#define DMA1_Stream3  ((DMA_Stream_TypeDef *) DMA1_Stream3_BASE)
#define DMA1_Stream4  ((DMA_Stream_TypeDef *) DMA1_Stream4_BASE)
#define DMA1_Stream5  ((DMA_Stream_TypeDef *) DMA1_Stream5_BASE)
#define DMA1_Stream6  ((DMA_Stream_TypeDef *) DMA1_Stream6_BASE)
#define DMA1_Stream7  ((DMA_Stream_TypeDef *) DMA1_Stream7_BASE)
#define RCM           ((RCM_TypeDef *) RCM_BASE)
#define FLASH         ((FLASH_TypeDef *) FLASHCTRL_BASE)
#define ADC1          ((ADC16_TypeDef *) ADC1_BASE)
#define ADC2          ((ADC16_TypeDef *) ADC2_BASE)
#define ADC3          ((ADC12_TypeDef *) ADC3_BASE)
#define GPIO          ((GPIO_TypeDef *) GPIO_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Hardware_Constant_Definition
  * @{
  */
#define LSI_STARTUP_TIME                   40U                                           /*!< LSI Maximum startup time in us */
/**
  * @}
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_ISR register  *******************/

#define ADC_ISR_EOSMP_Pos                  (1U)
#define ADC_ISR_EOSMP_Msk                  (0x1UL << ADC_ISR_EOSMP_Pos)                  /*!< 0x00000002 */
#define ADC_ISR_EOSMP                      ADC_ISR_EOSMP_Msk                             /*!< ADC group regular end of sampling flag */
#define ADC_ISR_EOC_Pos                    (2U)
#define ADC_ISR_EOC_Msk                    (0x1UL << ADC_ISR_EOC_Pos)                    /*!< 0x00000004 */
#define ADC_ISR_EOC                        ADC_ISR_EOC_Msk                               /*!< ADC group regular end of unitary conversion flag */
#define ADC_ISR_EOS_Pos                    (3U)
#define ADC_ISR_EOS_Msk                    (0x1UL << ADC_ISR_EOS_Pos)                    /*!< 0x00000008 */
#define ADC_ISR_EOS                        ADC_ISR_EOS_Msk                               /*!< ADC group regular end of sequence conversions flag */
#define ADC_ISR_OVR_Pos                    (4U)
#define ADC_ISR_OVR_Msk                    (0x1UL << ADC_ISR_OVR_Pos)                    /*!< 0x00000010 */
#define ADC_ISR_OVR                        ADC_ISR_OVR_Msk                               /*!< ADC group regular overrun flag */
#define ADC_ISR_JEOC_Pos                   (5U)
#define ADC_ISR_JEOC_Msk                   (0x1UL << ADC_ISR_JEOC_Pos)                   /*!< 0x00000020 */
#define ADC_ISR_JEOC                       ADC_ISR_JEOC_Msk                              /*!< ADC group injected end of unitary conversion flag */
#define ADC_ISR_JEOS_Pos                   (6U)
#define ADC_ISR_JEOS_Msk                   (0x1UL << ADC_ISR_JEOS_Pos)                   /*!< 0x00000040 */
#define ADC_ISR_JEOS                       ADC_ISR_JEOS_Msk                              /*!< ADC group injected end of sequence conversions flag */
#define ADC_ISR_AWD1_Pos                   (7U)
#define ADC_ISR_AWD1_Msk                   (0x1UL << ADC_ISR_AWD1_Pos)                   /*!< 0x00000080 */
#define ADC_ISR_AWD1                       ADC_ISR_AWD1_Msk                              /*!< ADC analog watchdog 1 flag */
#define ADC_ISR_AWD2_Pos                   (8U)
#define ADC_ISR_AWD2_Msk                   (0x1UL << ADC_ISR_AWD2_Pos)                   /*!< 0x00000100 */
#define ADC_ISR_AWD2                       ADC_ISR_AWD2_Msk                              /*!< ADC analog watchdog 2 flag */
#define ADC_ISR_AWD3_Pos                   (9U)
#define ADC_ISR_AWD3_Msk                   (0x1UL << ADC_ISR_AWD3_Pos)                   /*!< 0x00000200 */
#define ADC_ISR_AWD3                       ADC_ISR_AWD3_Msk                              /*!< ADC analog watchdog 3 flag */
#define ADC_ISR_JQOVF_Pos                  (10U)
#define ADC_ISR_JQOVF_Msk                  (0x1UL << ADC_ISR_JQOVF_Pos)                  /*!< 0x00000400 */
#define ADC_ISR_JQOVF                      ADC_ISR_JQOVF_Msk                             /*!< ADC group injected contexts queue overflow flag */

/********************  Bit definition for ADC_IER register  *******************/
#define ADC_IER_EOSMPIE_Pos                (1U)
#define ADC_IER_EOSMPIE_Msk                (0x1UL << ADC_IER_EOSMPIE_Pos)                /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                    ADC_IER_EOSMPIE_Msk                           /*!< ADC group regular end of sampling interrupt */
#define ADC_IER_EOCIE_Pos                  (2U)
#define ADC_IER_EOCIE_Msk                  (0x1UL << ADC_IER_EOCIE_Pos)                  /*!< 0x00000004 */
#define ADC_IER_EOCIE                      ADC_IER_EOCIE_Msk                             /*!< ADC group regular end of unitary conversion interrupt */
#define ADC_IER_EOSIE_Pos                  (3U)
#define ADC_IER_EOSIE_Msk                  (0x1UL << ADC_IER_EOSIE_Pos)                  /*!< 0x00000008 */
#define ADC_IER_EOSIE                      ADC_IER_EOSIE_Msk                             /*!< ADC group regular end of sequence conversions interrupt */
#define ADC_IER_OVRIE_Pos                  (4U)
#define ADC_IER_OVRIE_Msk                  (0x1UL << ADC_IER_OVRIE_Pos)                  /*!< 0x00000010 */
#define ADC_IER_OVRIE                      ADC_IER_OVRIE_Msk                             /*!< ADC group regular overrun interrupt */
#define ADC_IER_JEOCIE_Pos                 (5U)
#define ADC_IER_JEOCIE_Msk                 (0x1UL << ADC_IER_JEOCIE_Pos)                 /*!< 0x00000020 */
#define ADC_IER_JEOCIE                     ADC_IER_JEOCIE_Msk                            /*!< ADC group injected end of unitary conversion interrupt */
#define ADC_IER_JEOSIE_Pos                 (6U)
#define ADC_IER_JEOSIE_Msk                 (0x1UL << ADC_IER_JEOSIE_Pos)                 /*!< 0x00000040 */
#define ADC_IER_JEOSIE                     ADC_IER_JEOSIE_Msk                            /*!< ADC group injected end of sequence conversions interrupt */
#define ADC_IER_AWD1IE_Pos                 (7U)
#define ADC_IER_AWD1IE_Msk                 (0x1UL << ADC_IER_AWD1IE_Pos)                 /*!< 0x00000080 */
#define ADC_IER_AWD1IE                     ADC_IER_AWD1IE_Msk                            /*!< ADC analog watchdog 1 interrupt */
#define ADC_IER_AWD2IE_Pos                 (8U)
#define ADC_IER_AWD2IE_Msk                 (0x1UL << ADC_IER_AWD2IE_Pos)                 /*!< 0x00000100 */
#define ADC_IER_AWD2IE                     ADC_IER_AWD2IE_Msk                            /*!< ADC analog watchdog 2 interrupt */
#define ADC_IER_AWD3IE_Pos                 (9U)
#define ADC_IER_AWD3IE_Msk                 (0x1UL << ADC_IER_AWD3IE_Pos)                 /*!< 0x00000200 */
#define ADC_IER_AWD3IE                     ADC_IER_AWD3IE_Msk                            /*!< ADC analog watchdog 3 interrupt */
#define ADC_IER_JQOVFIE_Pos                (10U)
#define ADC_IER_JQOVFIE_Msk                (0x1UL << ADC_IER_JQOVFIE_Pos)                /*!< 0x00000400 */
#define ADC_IER_JQOVFIE                    ADC_IER_JQOVFIE_Msk                           /*!< ADC group injected contexts queue overflow interrupt */

/********************  Bit definition for ADC_CR register  ********************/
#define ADC_CR_ADEN_Pos                    (0U)
#define ADC_CR_ADEN_Msk                    (0x1UL << ADC_CR_ADEN_Pos)                    /*!< 0x00000001 */
#define ADC_CR_ADEN                        ADC_CR_ADEN_Msk                               /*!< ADC enable */
#define ADC_CR_ADDIS_Pos                   (1U)
#define ADC_CR_ADDIS_Msk                   (0x1UL << ADC_CR_ADDIS_Pos)                   /*!< 0x00000002 */
#define ADC_CR_ADDIS                       ADC_CR_ADDIS_Msk                              /*!< ADC Disable Command */
#define ADC_CR_ADSTART_Pos                 (2U)
#define ADC_CR_ADSTART_Msk                 (0x1UL << ADC_CR_ADSTART_Pos)                 /*!< 0x00000004 */
#define ADC_CR_ADSTART                     ADC_CR_ADSTART_Msk                            /*!< ADC group regular conversion start */
#define ADC_CR_JADSTART_Pos                (3U)
#define ADC_CR_JADSTART_Msk                (0x1UL << ADC_CR_JADSTART_Pos)                /*!< 0x00000008 */
#define ADC_CR_JADSTART                    ADC_CR_JADSTART_Msk                           /*!< ADC group injected conversion start */
#define ADC_CR_ADSTP_Pos                   (4U)
#define ADC_CR_ADSTP_Msk                   (0x1UL << ADC_CR_ADSTP_Pos)                   /*!< 0x00000010 */
#define ADC_CR_ADSTP                       ADC_CR_ADSTP_Msk                              /*!< ADC group regular conversion stop */
#define ADC_CR_JADSTP_Pos                  (5U)
#define ADC_CR_JADSTP_Msk                  (0x1UL << ADC_CR_JADSTP_Pos)                  /*!< 0x00000020 */
#define ADC_CR_JADSTP                      ADC_CR_JADSTP_Msk                             /*!< ADC group injected conversion stop */
#define ADC_CR_DUALMOD_Pos                 (6U)
#define ADC_CR_DUALMOD_Msk                 (0xFUL << ADC_CR_DUALMOD_Pos)                 /*!< 0x000003C0 */
#define ADC_CR_DUALMOD                     ADC_CR_DUALMOD_Msk                            /*!< ADC multimode mode selection */
#define ADC_CR_DUALMOD_0                   (0x1UL << ADC_CR_DUALMOD_Pos)                 /*!< 0x00000040 */
#define ADC_CR_DUALMOD_1                   (0x2UL << ADC_CR_DUALMOD_Pos)                 /*!< 0x00000080 */
#define ADC_CR_DUALMOD_2                   (0x4UL << ADC_CR_DUALMOD_Pos)                 /*!< 0x00000100 */
#define ADC_CR_DUALMOD_3                   (0x8UL << ADC_CR_DUALMOD_Pos)                 /*!< 0x00000200 */

/********************  Bit definition for ADC_CFGR register  ******************/
#define ADC_CFGR_DMAEN_Pos                 (0U)
#define ADC_CFGR_DMAEN_Msk                 (0x1UL << ADC_CFGR_DMAEN_Pos)                 /*!< 0x00000001 */
#define ADC_CFGR_DMAEN                     ADC_CFGR_DMAEN_Msk                            /*!< ADC DMA transfer enable */
#define ADC_CFGR_DMACFG_Pos                (1U)
#define ADC_CFGR_DMACFG_Msk                (0x1UL << ADC_CFGR_DMACFG_Pos)                /*!< 0x00000002 */
#define ADC_CFGR_DMACFG                    ADC_CFGR_DMACFG_Msk                           /*!< ADC DMA transfer configuration */

#define ADC_CFGR_ALIGN_Pos                 (5U)                                          /*!< 0x00000020>*/
#define ADC_CFGR_ALIGN_Msk                 (0x1UL << ADC_CFGR_ALIGN_Pos)                 /*!< Data alignment*/
#define ADC_CFGR_ALIGN                     ADC_CFGR_ALIGN_Msk

#define ADC_CFGR_EXTSEL_Pos                (6U)
#define ADC_CFGR_EXTSEL_Msk                (0xFUL << ADC_CFGR_EXTSEL_Pos)                /*!< 0x000003C0 */
#define ADC_CFGR_EXTSEL                    ADC_CFGR_EXTSEL_Msk                           /*!< ADC group regular external trigger source */
#define ADC_CFGR_EXTSEL_0                  (0x1UL << ADC_CFGR_EXTSEL_Pos)                /*!< 0x00000040 */
#define ADC_CFGR_EXTSEL_1                  (0x2UL << ADC_CFGR_EXTSEL_Pos)                /*!< 0x00000080 */
#define ADC_CFGR_EXTSEL_2                  (0x4UL << ADC_CFGR_EXTSEL_Pos)                /*!< 0x00000100 */
#define ADC_CFGR_EXTSEL_3                  (0x8UL << ADC_CFGR_EXTSEL_Pos)                /*!< 0x00000200 */

#define ADC_CFGR_EXTEN_Pos                 (10U)
#define ADC_CFGR_EXTEN_Msk                 (0x3UL << ADC_CFGR_EXTEN_Pos)                 /*!< 0x00000C00 */
#define ADC_CFGR_EXTEN                     ADC_CFGR_EXTEN_Msk                            /*!< ADC group regular external trigger polarity */
#define ADC_CFGR_EXTEN_0                   (0x1UL << ADC_CFGR_EXTEN_Pos)                 /*!< 0x00000400 */
#define ADC_CFGR_EXTEN_1                   (0x2UL << ADC_CFGR_EXTEN_Pos)                 /*!< 0x00000800 */

#define ADC_CFGR_OVRMOD_Pos                (12U)
#define ADC_CFGR_OVRMOD_Msk                (0x1UL << ADC_CFGR_OVRMOD_Pos)                /*!< 0x00001000 */
#define ADC_CFGR_OVRMOD                    ADC_CFGR_OVRMOD_Msk                           /*!< ADC group regular overrun configuration */
#define ADC_CFGR_CONT_Pos                  (13U)
#define ADC_CFGR_CONT_Msk                  (0x1UL << ADC_CFGR_CONT_Pos)                  /*!< 0x00002000 */
#define ADC_CFGR_CONT                      ADC_CFGR_CONT_Msk                             /*!< ADC group regular continuous conversion mode */
#define ADC_CFGR_AUTDLY_Pos                (14U)
#define ADC_CFGR_AUTDLY_Msk                (0x1UL << ADC_CFGR_AUTDLY_Pos)                /*!< 0x00004000 */
#define ADC_CFGR_AUTDLY                    ADC_CFGR_AUTDLY_Msk                           /*!< ADC low power auto wait */

#define ADC_CFGR_DISCEN_Pos                (16U)
#define ADC_CFGR_DISCEN_Msk                (0x1UL << ADC_CFGR_DISCEN_Pos)                /*!< 0x00010000 */
#define ADC_CFGR_DISCEN                    ADC_CFGR_DISCEN_Msk                           /*!< ADC group regular sequencer discontinuous mode */

#define ADC_CFGR_DISCNUM_Pos               (17U)
#define ADC_CFGR_DISCNUM_Msk               (0x7UL << ADC_CFGR_DISCNUM_Pos)               /*!< 0x000E0000 */
#define ADC_CFGR_DISCNUM                   ADC_CFGR_DISCNUM_Msk                          /*!< ADC group regular sequencer discontinuous number of ranks */
#define ADC_CFGR_DISCNUM_0                 (0x1UL << ADC_CFGR_DISCNUM_Pos)               /*!< 0x00020000 */
#define ADC_CFGR_DISCNUM_1                 (0x2UL << ADC_CFGR_DISCNUM_Pos)               /*!< 0x00040000 */
#define ADC_CFGR_DISCNUM_2                 (0x4UL << ADC_CFGR_DISCNUM_Pos)               /*!< 0x00080000 */

#define ADC_CFGR_JDISCEN_Pos               (20U)
#define ADC_CFGR_JDISCEN_Msk               (0x1UL << ADC_CFGR_JDISCEN_Pos)               /*!< 0x00100000 */
#define ADC_CFGR_JDISCEN                   ADC_CFGR_JDISCEN_Msk                          /*!< ADC group injected sequencer discontinuous mode */
#define ADC_CFGR_JQM_Pos                   (21U)
#define ADC_CFGR_JQM_Msk                   (0x1UL << ADC_CFGR_JQM_Pos)                   /*!< 0x00200000 */
#define ADC_CFGR_JQM                       ADC_CFGR_JQM_Msk                              /*!< ADC group injected contexts queue mode */
#define ADC_CFGR_AWD1SGL_Pos               (22U)
#define ADC_CFGR_AWD1SGL_Msk               (0x1UL << ADC_CFGR_AWD1SGL_Pos)               /*!< 0x00400000 */
#define ADC_CFGR_AWD1SGL                   ADC_CFGR_AWD1SGL_Msk                          /*!< ADC analog watchdog 1 monitoring a single channel or all channels */
#define ADC_CFGR_AWD1EN_Pos                (23U)
#define ADC_CFGR_AWD1EN_Msk                (0x1UL << ADC_CFGR_AWD1EN_Pos)                /*!< 0x00800000 */
#define ADC_CFGR_AWD1EN                    ADC_CFGR_AWD1EN_Msk                           /*!< ADC analog watchdog 1 enable on scope ADC group regular */
#define ADC_CFGR_JAWD1EN_Pos               (24U)
#define ADC_CFGR_JAWD1EN_Msk               (0x1UL << ADC_CFGR_JAWD1EN_Pos)               /*!< 0x01000000 */
#define ADC_CFGR_JAWD1EN                   ADC_CFGR_JAWD1EN_Msk                          /*!< ADC analog watchdog 1 enable on scope ADC group injected */
#define ADC_CFGR_JAUTO_Pos                 (25U)
#define ADC_CFGR_JAUTO_Msk                 (0x1UL << ADC_CFGR_JAUTO_Pos)                 /*!< 0x02000000 */
#define ADC_CFGR_JAUTO                     ADC_CFGR_JAUTO_Msk                            /*!< ADC group injected automatic trigger mode */

#define ADC_CFGR_AWD1CH_Pos                (26U)
#define ADC_CFGR_AWD1CH_Msk                (0xFUL << ADC_CFGR_AWD1CH_Pos)                /*!< 0x3C000000 */
/*!< Note: shared ADC_* mask; ADC16 chapter width is 3 bits, ADC12 is 4 - wider mask retained intentionally. */
#define ADC_CFGR_AWD1CH                    ADC_CFGR_AWD1CH_Msk                           /*!< ADC analog watchdog 1 monitored channel selection */
#define ADC_CFGR_AWD1CH_0                  (0x01UL << ADC_CFGR_AWD1CH_Pos)               /*!< 0x04000000 */
#define ADC_CFGR_AWD1CH_1                  (0x02UL << ADC_CFGR_AWD1CH_Pos)               /*!< 0x08000000 */
#define ADC_CFGR_AWD1CH_2                  (0x04UL << ADC_CFGR_AWD1CH_Pos)               /*!< 0x10000000 */
#define ADC_CFGR_AWD1CH_3                  (0x08UL << ADC_CFGR_AWD1CH_Pos)               /*!< 0x20000000 */

#define ADC_CFGR_JQDIS_Pos                 (31U)
#define ADC_CFGR_JQDIS_Msk                 (0x1UL << ADC_CFGR_JQDIS_Pos)                 /*!< 0x80000000 */
#define ADC_CFGR_JQDIS                     ADC_CFGR_JQDIS_Msk                            /*!< ADC group injected contexts queue disable */

/********************  Bit definition for ADC_CFGR2 register  *****************/
#define ADC_CFGR2_ROVSE_Pos                (0U)
#define ADC_CFGR2_ROVSE_Msk                (0x1UL << ADC_CFGR2_ROVSE_Pos)                /*!< 0x00000001 */
#define ADC_CFGR2_ROVSE                    ADC_CFGR2_ROVSE_Msk                           /*!< ADC oversampler enable on scope ADC group regular */
#define ADC_CFGR2_JOVSE_Pos                (1U)
#define ADC_CFGR2_JOVSE_Msk                (0x1UL << ADC_CFGR2_JOVSE_Pos)                /*!< 0x00000002 */
#define ADC_CFGR2_JOVSE                    ADC_CFGR2_JOVSE_Msk                           /*!< ADC oversampler enable on scope ADC group injected */

#define ADC_CFGR2_OVSR_Pos                 (2U)
#define ADC_CFGR2_OVSR_Msk                 (0x3UL << ADC_CFGR2_OVSR_Pos)                 /*!< 0x0000001C */
#define ADC_CFGR2_OVSR                     ADC_CFGR2_OVSR_Msk                            /*!< ADC oversampling ratio */
#define ADC_CFGR2_OVSR_0                   (0x1UL << ADC_CFGR2_OVSR_Pos)                 /*!< 0x00000004 */
#define ADC_CFGR2_OVSR_1                   (0x2UL << ADC_CFGR2_OVSR_Pos)                 /*!< 0x00000008 */

#define ADC_CFGR2_OVSS_Pos                 (6U)
#define ADC_CFGR2_OVSS_Msk                 (0x7UL << ADC_CFGR2_OVSS_Pos)                 /*!< 0x000001C0 */
#define ADC_CFGR2_OVSS                     ADC_CFGR2_OVSS_Msk                            /*!< ADC oversampling shift */
#define ADC_CFGR2_OVSS_0                   (0x1UL << ADC_CFGR2_OVSS_Pos)                 /*!< 0x00000040 */
#define ADC_CFGR2_OVSS_1                   (0x2UL << ADC_CFGR2_OVSS_Pos)                 /*!< 0x00000080 */
#define ADC_CFGR2_OVSS_2                   (0x4UL << ADC_CFGR2_OVSS_Pos)                 /*!< 0x00000100 */

#define ADC_CFGR2_TROVS_Pos                (9U)
#define ADC_CFGR2_TROVS_Msk                (0x1UL << ADC_CFGR2_TROVS_Pos)                /*!< 0x00000200 */
#define ADC_CFGR2_TROVS                    ADC_CFGR2_TROVS_Msk                           /*!< ADC oversampling discontinuous mode (triggered mode) for ADC group regular */
#define ADC_CFGR2_ROVSM_Pos                (10U)
#define ADC_CFGR2_ROVSM_Msk                (0x1UL << ADC_CFGR2_ROVSM_Pos)                /*!< 0x00000400 */
#define ADC_CFGR2_ROVSM                    ADC_CFGR2_ROVSM_Msk                           /*!< ADC oversampling mode managing interlaced conversions of ADC group regular and group injected */

#define ADC_CFGR2_AWDFILT_Pos              (11U)
#define ADC_CFGR2_AWDFILT_Msk              (0x7UL << ADC_CFGR2_AWDFILT_Pos)              /*!< 0x00003800 */
#define ADC_CFGR2_AWDFILT                  ADC_CFGR2_AWDFILT_Msk                         /*!< Analog watchdog filtering parameter*/
#define ADC_CFGR2_AWDFILT_0                (0x1UL << ADC_CFGR2_AWDFILT_Pos)              /*!< 0x00000800 */
#define ADC_CFGR2_AWDFILT_1                (0x2UL << ADC_CFGR2_AWDFILT_Pos)              /*!< 0x00001000 */
#define ADC_CFGR2_AWDFILT_2                (0x4UL << ADC_CFGR2_AWDFILT_Pos)              /*!< 0x00002000 */

#define ADC_CFGR2_DIFSEL_Pos               (14U)
#define ADC_CFGR2_DIFSEL_Msk               (0x1UL << ADC_CFGR2_DIFSEL_Pos)               /*!< 0x00004000 */
#define ADC_CFGR2_DIFSEL                   ADC_CFGR2_DIFSEL_Msk                          /*!< ADC single-ended/differential mode control signal */

/********************  Bit definition for ADC_SMPR1 register  *****************/
#define ADC_SMPR1_SMP0_Pos                 (0U)
#define ADC_SMPR1_SMP0_Msk                 (0xFUL << ADC_SMPR1_SMP0_Pos)                 /*!< 0x0000000F */
#define ADC_SMPR1_SMP0                     ADC_SMPR1_SMP0_Msk                            /*!< ADC channel 0 sampling time selection */
#define ADC_SMPR1_SMP0_0                   (0x1UL << ADC_SMPR1_SMP0_Pos)                 /*!< 0x00000001 */
#define ADC_SMPR1_SMP0_1                   (0x2UL << ADC_SMPR1_SMP0_Pos)                 /*!< 0x00000002 */
#define ADC_SMPR1_SMP0_2                   (0x4UL << ADC_SMPR1_SMP0_Pos)                 /*!< 0x00000004 */
#define ADC_SMPR1_SMP0_3                   (0x8UL << ADC_SMPR1_SMP0_Pos)                 /*!< 0x00000008 */

#define ADC_SMPR1_SMP1_Pos                 (4U)
#define ADC_SMPR1_SMP1_Msk                 (0xFUL << ADC_SMPR1_SMP1_Pos)                 /*!< 0x000000F0 */
#define ADC_SMPR1_SMP1                     ADC_SMPR1_SMP1_Msk                            /*!< ADC channel 1 sampling time selection */
#define ADC_SMPR1_SMP1_0                   (0x1UL << ADC_SMPR1_SMP1_Pos)                 /*!< 0x00000010 */
#define ADC_SMPR1_SMP1_1                   (0x2UL << ADC_SMPR1_SMP1_Pos)                 /*!< 0x00000020 */
#define ADC_SMPR1_SMP1_2                   (0x4UL << ADC_SMPR1_SMP1_Pos)                 /*!< 0x00000040 */
#define ADC_SMPR1_SMP1_3                   (0x8UL << ADC_SMPR1_SMP1_Pos)                 /*!< 0x00000080 */

#define ADC_SMPR1_SMP2_Pos                 (8U)
#define ADC_SMPR1_SMP2_Msk                 (0xFUL << ADC_SMPR1_SMP2_Pos)                 /*!< 0x00000F00 */
#define ADC_SMPR1_SMP2                     ADC_SMPR1_SMP2_Msk                            /*!< ADC channel 2 sampling time selection */
#define ADC_SMPR1_SMP2_0                   (0x1UL << ADC_SMPR1_SMP2_Pos)                 /*!< 0x00000100 */
#define ADC_SMPR1_SMP2_1                   (0x2UL << ADC_SMPR1_SMP2_Pos)                 /*!< 0x00000200 */
#define ADC_SMPR1_SMP2_2                   (0x4UL << ADC_SMPR1_SMP2_Pos)                 /*!< 0x00000400 */
#define ADC_SMPR1_SMP2_3                   (0x8UL << ADC_SMPR1_SMP2_Pos)                 /*!< 0x00000800 */

#define ADC_SMPR1_SMP3_Pos                 (12U)
#define ADC_SMPR1_SMP3_Msk                 (0xFUL << ADC_SMPR1_SMP3_Pos)                 /*!< 0x0000F000 */
#define ADC_SMPR1_SMP3                     ADC_SMPR1_SMP3_Msk                            /*!< ADC channel 3 sampling time selection */
#define ADC_SMPR1_SMP3_0                   (0x1UL << ADC_SMPR1_SMP3_Pos)                 /*!< 0x00001000 */
#define ADC_SMPR1_SMP3_1                   (0x2UL << ADC_SMPR1_SMP3_Pos)                 /*!< 0x00002000 */
#define ADC_SMPR1_SMP3_2                   (0x4UL << ADC_SMPR1_SMP3_Pos)                 /*!< 0x00004000 */
#define ADC_SMPR1_SMP3_3                   (0x8UL << ADC_SMPR1_SMP3_Pos)                 /*!< 0x00008000 */

#define ADC_SMPR1_SMP4_Pos                 (16U)
#define ADC_SMPR1_SMP4_Msk                 (0xFUL << ADC_SMPR1_SMP4_Pos)                 /*!< 0x000F0000 */
#define ADC_SMPR1_SMP4                     ADC_SMPR1_SMP4_Msk                            /*!< ADC channel 4 sampling time selection */
#define ADC_SMPR1_SMP4_0                   (0x1UL << ADC_SMPR1_SMP4_Pos)                 /*!< 0x00010000 */
#define ADC_SMPR1_SMP4_1                   (0x2UL << ADC_SMPR1_SMP4_Pos)                 /*!< 0x00020000 */
#define ADC_SMPR1_SMP4_2                   (0x4UL << ADC_SMPR1_SMP4_Pos)                 /*!< 0x00040000 */
#define ADC_SMPR1_SMP4_3                   (0x8UL << ADC_SMPR1_SMP4_Pos)                 /*!< 0x00080000 */

#define ADC_SMPR1_SMP5_Pos                 (20U)
#define ADC_SMPR1_SMP5_Msk                 (0xFUL << ADC_SMPR1_SMP5_Pos)                 /*!< 0x00F00000 */
#define ADC_SMPR1_SMP5                     ADC_SMPR1_SMP5_Msk                            /*!< ADC channel 5 sampling time selection */
#define ADC_SMPR1_SMP5_0                   (0x1UL << ADC_SMPR1_SMP5_Pos)                 /*!< 0x00100000 */
#define ADC_SMPR1_SMP5_1                   (0x2UL << ADC_SMPR1_SMP5_Pos)                 /*!< 0x00200000 */
#define ADC_SMPR1_SMP5_2                   (0x4UL << ADC_SMPR1_SMP5_Pos)                 /*!< 0x00400000 */
#define ADC_SMPR1_SMP5_3                   (0x8UL << ADC_SMPR1_SMP5_Pos)                 /*!< 0x00800000 */

#define ADC_SMPR1_SMP6_Pos                 (24U)
#define ADC_SMPR1_SMP6_Msk                 (0xFUL << ADC_SMPR1_SMP6_Pos)                 /*!< 0x0F000000 */
#define ADC_SMPR1_SMP6                     ADC_SMPR1_SMP6_Msk                            /*!< ADC channel 6 sampling time selection */
#define ADC_SMPR1_SMP6_0                   (0x1UL << ADC_SMPR1_SMP6_Pos)                 /*!< 0x00100000 */
#define ADC_SMPR1_SMP6_1                   (0x2UL << ADC_SMPR1_SMP6_Pos)                 /*!< 0x00200000 */
#define ADC_SMPR1_SMP6_2                   (0x4UL << ADC_SMPR1_SMP6_Pos)                 /*!< 0x00400000 */
#define ADC_SMPR1_SMP6_3                   (0x8UL << ADC_SMPR1_SMP6_Pos)                 /*!< 0x00800000 */

#define ADC_SMPR1_SMP7_Pos                 (28U)
#define ADC_SMPR1_SMP7_Msk                 (0xFUL << ADC_SMPR1_SMP7_Pos)                 /*!< 0xF0000000 */
#define ADC_SMPR1_SMP7                     ADC_SMPR1_SMP7_Msk                            /*!< ADC channel 7 sampling time selection */
#define ADC_SMPR1_SMP7_0                   (0x1UL << ADC_SMPR1_SMP7_Pos)                 /*!< 0x00100000 */
#define ADC_SMPR1_SMP7_1                   (0x2UL << ADC_SMPR1_SMP7_Pos)                 /*!< 0x00200000 */
#define ADC_SMPR1_SMP7_2                   (0x4UL << ADC_SMPR1_SMP7_Pos)                 /*!< 0x00400000 */
#define ADC_SMPR1_SMP7_3                   (0x8UL << ADC_SMPR1_SMP7_Pos)                 /*!< 0x00800000 */

/********************  Bit definition for ADC_SMPR2 register  *****************/
#define ADC_SMPR2_SMP8_Pos                 (0U)
#define ADC_SMPR2_SMP8_Msk                 (0xFUL << ADC_SMPR2_SMP8_Pos)                 /*!< 0x0000000F */
#define ADC_SMPR2_SMP8                     ADC_SMPR2_SMP8_Msk                            /*!< ADC channel 8 sampling time selection */
#define ADC_SMPR2_SMP8_0                   (0x1UL << ADC_SMPR2_SMP8_Pos)                 /*!< 0x00000001 */
#define ADC_SMPR2_SMP8_1                   (0x2UL << ADC_SMPR2_SMP8_Pos)                 /*!< 0x00000002 */
#define ADC_SMPR2_SMP8_2                   (0x4UL << ADC_SMPR2_SMP8_Pos)                 /*!< 0x00000004 */
#define ADC_SMPR2_SMP8_3                   (0x8UL << ADC_SMPR2_SMP8_Pos)                 /*!< 0x00000008 */

#define ADC_SMPR2_SMP9_Pos                 (4U)
#define ADC_SMPR2_SMP9_Msk                 (0xFUL << ADC_SMPR2_SMP9_Pos)                 /*!< 0x000000F0 */
#define ADC_SMPR2_SMP9                     ADC_SMPR2_SMP9_Msk                            /*!< ADC channel 9 sampling time selection */
#define ADC_SMPR2_SMP9_0                   (0x1UL << ADC_SMPR2_SMP9_Pos)                 /*!< 0x00000010 */
#define ADC_SMPR2_SMP9_1                   (0x2UL << ADC_SMPR2_SMP9_Pos)                 /*!< 0x00000020 */
#define ADC_SMPR2_SMP9_2                   (0x4UL << ADC_SMPR2_SMP9_Pos)                 /*!< 0x00000040 */
#define ADC_SMPR2_SMP9_3                   (0x8UL << ADC_SMPR2_SMP9_Pos)                 /*!< 0x00000080 */

#define ADC_SMPR2_SMP10_Pos                (8U)
#define ADC_SMPR2_SMP10_Msk                (0xFUL << ADC_SMPR2_SMP10_Pos)                /*!< 0x00000F00 */
#define ADC_SMPR2_SMP10                    ADC_SMPR2_SMP10_Msk                           /*!< ADC channel 10 sampling time selection */
#define ADC_SMPR2_SMP10_0                  (0x1UL << ADC_SMPR2_SMP10_Pos)                /*!< 0x00000100 */
#define ADC_SMPR2_SMP10_1                  (0x2UL << ADC_SMPR2_SMP10_Pos)                /*!< 0x00000200 */
#define ADC_SMPR2_SMP10_2                  (0x4UL << ADC_SMPR2_SMP10_Pos)                /*!< 0x00000400 */
#define ADC_SMPR2_SMP10_3                  (0x8UL << ADC_SMPR2_SMP10_Pos)                /*!< 0x00000800 */

#define ADC_SMPR2_SMP11_Pos                (12U)
#define ADC_SMPR2_SMP11_Msk                (0xFUL << ADC_SMPR2_SMP11_Pos)                /*!< 0x0000F000 */
#define ADC_SMPR2_SMP11                    ADC_SMPR2_SMP11_Msk                           /*!< ADC channel 11 sampling time selection */
#define ADC_SMPR2_SMP11_0                  (0x1UL << ADC_SMPR2_SMP11_Pos)                /*!< 0x00001000 */
#define ADC_SMPR2_SMP11_1                  (0x2UL << ADC_SMPR2_SMP11_Pos)                /*!< 0x00002000 */
#define ADC_SMPR2_SMP11_2                  (0x4UL << ADC_SMPR2_SMP11_Pos)                /*!< 0x00004000 */
#define ADC_SMPR2_SMP11_3                  (0x8UL << ADC_SMPR2_SMP11_Pos)                /*!< 0x00008000 */

#define ADC_SMPR2_SMP12_Pos                (16U)
#define ADC_SMPR2_SMP12_Msk                (0xFUL << ADC_SMPR2_SMP12_Pos)                /*!< 0x000F0000 */
#define ADC_SMPR2_SMP12                    ADC_SMPR2_SMP12_Msk                           /*!< ADC channel 12 sampling time selection */
#define ADC_SMPR2_SMP12_0                  (0x1UL << ADC_SMPR2_SMP12_Pos)                /*!< 0x00010000 */
#define ADC_SMPR2_SMP12_1                  (0x2UL << ADC_SMPR2_SMP12_Pos)                /*!< 0x00020000 */
#define ADC_SMPR2_SMP12_2                  (0x4UL << ADC_SMPR2_SMP12_Pos)                /*!< 0x00040000 */
#define ADC_SMPR2_SMP12_3                  (0x8UL << ADC_SMPR2_SMP12_Pos)                /*!< 0x00080000 */

#define ADC_SMPR2_SMP13_Pos                (20U)
#define ADC_SMPR2_SMP13_Msk                (0xFUL << ADC_SMPR2_SMP13_Pos)                /*!< 0x00F00000 */
#define ADC_SMPR2_SMP13                    ADC_SMPR2_SMP13_Msk                           /*!< ADC channel 13 sampling time selection */
#define ADC_SMPR2_SMP13_0                  (0x1UL << ADC_SMPR2_SMP13_Pos)                /*!< 0x00100000 */
#define ADC_SMPR2_SMP13_1                  (0x2UL << ADC_SMPR2_SMP13_Pos)                /*!< 0x00200000 */
#define ADC_SMPR2_SMP13_2                  (0x4UL << ADC_SMPR2_SMP13_Pos)                /*!< 0x00400000 */
#define ADC_SMPR2_SMP13_3                  (0x8UL << ADC_SMPR2_SMP13_Pos)                /*!< 0x00800000 */

#define ADC_SMPR2_SMP14_Pos                (24U)
#define ADC_SMPR2_SMP14_Msk                (0xFUL << ADC_SMPR2_SMP14_Pos)                /*!< 0x0F000000 */
#define ADC_SMPR2_SMP14                    ADC_SMPR2_SMP14_Msk                           /*!< ADC channel 14 sampling time selection */
#define ADC_SMPR2_SMP14_0                  (0x1UL << ADC_SMPR2_SMP14_Pos)                /*!< 0x00100000 */
#define ADC_SMPR2_SMP14_1                  (0x2UL << ADC_SMPR2_SMP14_Pos)                /*!< 0x00200000 */
#define ADC_SMPR2_SMP14_2                  (0x4UL << ADC_SMPR2_SMP14_Pos)                /*!< 0x00400000 */
#define ADC_SMPR2_SMP14_3                  (0x8UL << ADC_SMPR2_SMP14_Pos)                /*!< 0x00800000 */

#define ADC_SMPR2_SMP15_Pos                (28U)
#define ADC_SMPR2_SMP15_Msk                (0xFUL << ADC_SMPR2_SMP15_Pos)                /*!< 0xF0000000 */
#define ADC_SMPR2_SMP15                    ADC_SMPR2_SMP15_Msk                           /*!< ADC channel 15 sampling time selection */
#define ADC_SMPR2_SMP15_0                  (0x1UL << ADC_SMPR2_SMP15_Pos)                /*!< 0x00100000 */
#define ADC_SMPR2_SMP15_1                  (0x2UL << ADC_SMPR2_SMP15_Pos)                /*!< 0x00200000 */
#define ADC_SMPR2_SMP15_2                  (0x4UL << ADC_SMPR2_SMP15_Pos)                /*!< 0x00400000 */
#define ADC_SMPR2_SMP15_3                  (0x8UL << ADC_SMPR2_SMP15_Pos)                /*!< 0x00800000 */

/********************  Bit definition for ADC_TR1 register  *******************/
#define ADC_TR1_LT1_Pos                    (0U)
#define ADC_TR1_LT1_Msk                    (0xFFFFUL << ADC_TR1_LT1_Pos)                 /*!< 0x0000FFFF */
#define ADC_TR1_LT1                        ADC_TR1_LT1_Msk                               /*!< ADC analog watchdog 1 threshold low */
#define ADC_TR1_HT1_Pos                    (16U)
#define ADC_TR1_HT1_Msk                    (0xFFFFUL << ADC_TR1_HT1_Pos)                 /*!< 0xFFFF0000 */
#define ADC_TR1_HT1                        ADC_TR1_HT1_Msk                               /*!< ADC analog watchdog 1 threshold high */

/********************  Bit definition for ADC_TR2 register  *******************/
#define ADC_TR2_LT2_Pos                    (0U)
#define ADC_TR2_LT2_Msk                    (0xFFFUL << ADC_TR2_LT2_Pos)                  /*!< 0x00000FFF */
#define ADC_TR2_LT2                        ADC_TR2_LT2_Msk                               /*!< ADC analog watchdog 2 threshold low */
#define ADC_TR2_HT2_Pos                    (16U)
#define ADC_TR2_HT2_Msk                    (0xFFFUL << ADC_TR2_HT2_Pos)                  /*!< 0x0FFF0000 */
#define ADC_TR2_HT2                        ADC_TR2_HT2_Msk                               /*!< ADC analog watchdog 2 threshold high */

/********************  Bit definition for ADC_TR3 register  *******************/
#define ADC_TR3_LT3_Pos                    (0U)
#define ADC_TR3_LT3_Msk                    (0xFFUL << ADC_TR3_LT3_Pos)                   /*!< 0x000000FF */
#define ADC_TR3_LT3                        ADC_TR3_LT3_Msk                               /*!< ADC analog watchdog 3 threshold low */
#define ADC_TR3_HT3_Pos                    (16U)
#define ADC_TR3_HT3_Msk                    (0xFFUL << ADC_TR3_HT3_Pos)                   /*!< 0x00FF0000 */
#define ADC_TR3_HT3                        ADC_TR3_HT3_Msk                               /*!< ADC analog watchdog 3 threshold high */

/********************  Bit definition for ADC_SQR1 register  ******************/
#define ADC_SQR1_RL_Pos                    (0U)
#define ADC_SQR1_RL_Msk                    (0xFUL << ADC_SQR1_RL_Pos)                    /*!< 0x0000000F */
#define ADC_SQR1_RL                        ADC_SQR1_RL_Msk                               /*!< ADC group regular sequencer scan length */
#define ADC_SQR1_RL_0                      (0x1UL << ADC_SQR1_RL_Pos)                    /*!< 0x00000001 */
#define ADC_SQR1_RL_1                      (0x2UL << ADC_SQR1_RL_Pos)                    /*!< 0x00000002 */
#define ADC_SQR1_RL_2                      (0x4UL << ADC_SQR1_RL_Pos)                    /*!< 0x00000004 */
#define ADC_SQR1_RL_3                      (0x8UL << ADC_SQR1_RL_Pos)                    /*!< 0x00000008 */

#define ADC_SQR1_SQ1_Pos                   (4U)
#define ADC_SQR1_SQ1_Msk                   (0xFUL << ADC_SQR1_SQ1_Pos)                   /*!< 0x000000F0 */
#define ADC_SQR1_SQ1                       ADC_SQR1_SQ1_Msk                              /*!< ADC group regular sequencer rank 1 */
#define ADC_SQR1_SQ1_0                     (0x01UL << ADC_SQR1_SQ1_Pos)                  /*!< 0x00000010 */
#define ADC_SQR1_SQ1_1                     (0x02UL << ADC_SQR1_SQ1_Pos)                  /*!< 0x00000020 */
#define ADC_SQR1_SQ1_2                     (0x04UL << ADC_SQR1_SQ1_Pos)                  /*!< 0x00000040 */
#define ADC_SQR1_SQ1_3                     (0x08UL << ADC_SQR1_SQ1_Pos)                  /*!< 0x00000080 */

#define ADC_SQR1_SQ2_Pos                   (8U)
#define ADC_SQR1_SQ2_Msk                   (0xFUL << ADC_SQR1_SQ2_Pos)                   /*!< 0x0000F00 */
#define ADC_SQR1_SQ2                       ADC_SQR1_SQ2_Msk                              /*!< ADC group regular sequencer rank 2 */
#define ADC_SQR1_SQ2_0                     (0x01UL << ADC_SQR1_SQ2_Pos)                  /*!< 0x00000100 */
#define ADC_SQR1_SQ2_1                     (0x02UL << ADC_SQR1_SQ2_Pos)                  /*!< 0x00000200 */
#define ADC_SQR1_SQ2_2                     (0x04UL << ADC_SQR1_SQ2_Pos)                  /*!< 0x00000400 */
#define ADC_SQR1_SQ2_3                     (0x08UL << ADC_SQR1_SQ2_Pos)                  /*!< 0x00000800 */

#define ADC_SQR1_SQ3_Pos                   (12U)
#define ADC_SQR1_SQ3_Msk                   (0xFUL << ADC_SQR1_SQ3_Pos)                   /*!< 0x0000F000 */
#define ADC_SQR1_SQ3                       ADC_SQR1_SQ3_Msk                              /*!< ADC group regular sequencer rank 3 */
#define ADC_SQR1_SQ3_0                     (0x01UL << ADC_SQR1_SQ3_Pos)                  /*!< 0x00001000 */
#define ADC_SQR1_SQ3_1                     (0x02UL << ADC_SQR1_SQ3_Pos)                  /*!< 0x00002000 */
#define ADC_SQR1_SQ3_2                     (0x04UL << ADC_SQR1_SQ3_Pos)                  /*!< 0x00004000 */
#define ADC_SQR1_SQ3_3                     (0x08UL << ADC_SQR1_SQ3_Pos)                  /*!< 0x00008000 */

#define ADC_SQR1_SQ4_Pos                   (16U)
#define ADC_SQR1_SQ4_Msk                   (0xFUL << ADC_SQR1_SQ4_Pos)                   /*!< 0x000F0000 */
#define ADC_SQR1_SQ4                       ADC_SQR1_SQ4_Msk                              /*!< ADC group regular sequencer rank 4 */
#define ADC_SQR1_SQ4_0                     (0x01UL << ADC_SQR1_SQ4_Pos)                  /*!< 0x00010000 */
#define ADC_SQR1_SQ4_1                     (0x02UL << ADC_SQR1_SQ4_Pos)                  /*!< 0x00020000 */
#define ADC_SQR1_SQ4_2                     (0x04UL << ADC_SQR1_SQ4_Pos)                  /*!< 0x00040000 */
#define ADC_SQR1_SQ4_3                     (0x08UL << ADC_SQR1_SQ4_Pos)                  /*!< 0x00080000 */

#define ADC_SQR1_SQ5_Pos                   (20U)
#define ADC_SQR1_SQ5_Msk                   (0xFUL << ADC_SQR1_SQ5_Pos)                   /*!< 0x00F00000 */
#define ADC_SQR1_SQ5                       ADC_SQR1_SQ5_Msk                              /*!< ADC group regular sequencer rank 5 */
#define ADC_SQR1_SQ5_0                     (0x01UL << ADC_SQR1_SQ5_Pos)                  /*!< 0x00100000 */
#define ADC_SQR1_SQ5_1                     (0x02UL << ADC_SQR1_SQ5_Pos)                  /*!< 0x002000000 */
#define ADC_SQR1_SQ5_2                     (0x04UL << ADC_SQR1_SQ5_Pos)                  /*!< 0x00400000 */
#define ADC_SQR1_SQ5_3                     (0x08UL << ADC_SQR1_SQ5_Pos)                  /*!< 0x00800000 */

#define ADC_SQR1_SQ6_Pos                   (24U)
#define ADC_SQR1_SQ6_Msk                   (0xFUL << ADC_SQR1_SQ6_Pos)                   /*!< 0x0F000000 */
#define ADC_SQR1_SQ6                       ADC_SQR1_SQ6_Msk                              /*!< ADC group regular sequencer rank 6 */
#define ADC_SQR1_SQ6_0                     (0x01UL << ADC_SQR1_SQ6_Pos)                  /*!< 0x01000000 */
#define ADC_SQR1_SQ6_1                     (0x02UL << ADC_SQR1_SQ6_Pos)                  /*!< 0x02000000 */
#define ADC_SQR1_SQ6_2                     (0x04UL << ADC_SQR1_SQ6_Pos)                  /*!< 0x04000000 */
#define ADC_SQR1_SQ6_3                     (0x08UL << ADC_SQR1_SQ6_Pos)                  /*!< 0x08000000 */

#define ADC_SQR1_SQ7_Pos                   (28U)
#define ADC_SQR1_SQ7_Msk                   (0xFUL << ADC_SQR1_SQ7_Pos)                   /*!< 0xF0000000 */
#define ADC_SQR1_SQ7                       ADC_SQR1_SQ7_Msk                              /*!< ADC group regular sequencer rank 7 */
#define ADC_SQR1_SQ7_0                     (0x01UL << ADC_SQR1_SQ7_Pos)                  /*!< 0x10000000 */
#define ADC_SQR1_SQ7_1                     (0x02UL << ADC_SQR1_SQ7_Pos)                  /*!< 0x20000000 */
#define ADC_SQR1_SQ7_2                     (0x04UL << ADC_SQR1_SQ7_Pos)                  /*!< 0x40000000 */
#define ADC_SQR1_SQ7_3                     (0x08UL << ADC_SQR1_SQ7_Pos)                  /*!< 0x80000000 */

/********************  Bit definition for ADC_SQR2 register  ******************/
#define ADC_SQR2_SQ8_Pos                   (0U)
#define ADC_SQR2_SQ8_Msk                   (0xFUL << ADC_SQR2_SQ8_Pos)                   /*!< 0x0000000F */
#define ADC_SQR2_SQ8                       ADC_SQR2_SQ8_Msk                              /*!< ADC group regular sequencer rank 8 */
#define ADC_SQR2_SQ8_0                     (0x01UL << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000001 */
#define ADC_SQR2_SQ8_1                     (0x02UL << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000002 */
#define ADC_SQR2_SQ8_2                     (0x04UL << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000004 */
#define ADC_SQR2_SQ8_3                     (0x08UL << ADC_SQR2_SQ8_Pos)                  /*!< 0x00000008 */

#define ADC_SQR2_SQ9_Pos                   (4U)
#define ADC_SQR2_SQ9_Msk                   (0xFUL << ADC_SQR2_SQ9_Pos)                   /*!< 0x000000F0*/
#define ADC_SQR2_SQ9                       ADC_SQR2_SQ9_Msk                              /*!< ADC group regular sequencer rank 9 */
#define ADC_SQR2_SQ9_0                     (0x01UL << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000010 */
#define ADC_SQR2_SQ9_1                     (0x02UL << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000020 */
#define ADC_SQR2_SQ9_2                     (0x04UL << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000040 */
#define ADC_SQR2_SQ9_3                     (0x08UL << ADC_SQR2_SQ9_Pos)                  /*!< 0x00000080 */

#define ADC_SQR2_SQ10_Pos                  (8U)
#define ADC_SQR2_SQ10_Msk                  (0xFUL << ADC_SQR2_SQ10_Pos)                  /*!< 0x00000F00 */
#define ADC_SQR2_SQ10                      ADC_SQR2_SQ10_Msk                             /*!< ADC group regular sequencer rank 10 */
#define ADC_SQR2_SQ10_0                    (0x01UL << ADC_SQR2_SQ10_Pos)                 /*!< 0x00000100 */
#define ADC_SQR2_SQ10_1                    (0x02UL << ADC_SQR2_SQ10_Pos)                 /*!< 0x00000200 */
#define ADC_SQR2_SQ10_2                    (0x04UL << ADC_SQR2_SQ10_Pos)                 /*!< 0x00000400 */
#define ADC_SQR2_SQ10_3                    (0x08UL << ADC_SQR2_SQ10_Pos)                 /*!< 0x00000800 */

#define ADC_SQR2_SQ11_Pos                  (12U)
#define ADC_SQR2_SQ11_Msk                  (0xFUL << ADC_SQR2_SQ11_Pos)                  /*!< 0x0000F000 */
#define ADC_SQR2_SQ11                      ADC_SQR2_SQ11_Msk                             /*!< ADC group regular sequencer rank 11 */
#define ADC_SQR2_SQ11_0                    (0x01UL << ADC_SQR2_SQ11_Pos)                 /*!< 0x00001000 */
#define ADC_SQR2_SQ11_1                    (0x02UL << ADC_SQR2_SQ11_Pos)                 /*!< 0x00002000 */
#define ADC_SQR2_SQ11_2                    (0x04UL << ADC_SQR2_SQ11_Pos)                 /*!< 0x00004000 */
#define ADC_SQR2_SQ11_3                    (0x08UL << ADC_SQR2_SQ11_Pos)                 /*!< 0x00008000 */

#define ADC_SQR2_SQ12_Pos                  (16U)
#define ADC_SQR2_SQ12_Msk                  (0xFUL << ADC_SQR2_SQ12_Pos)                  /*!< 0x000F0000 */
#define ADC_SQR2_SQ12                      ADC_SQR2_SQ12_Msk                             /*!< ADC group regular sequencer rank 12 */
#define ADC_SQR2_SQ12_0                    (0x01UL << ADC_SQR2_SQ12_Pos)                 /*!< 0x00010000 */
#define ADC_SQR2_SQ12_1                    (0x02UL << ADC_SQR2_SQ12_Pos)                 /*!< 0x00020000 */
#define ADC_SQR2_SQ12_2                    (0x04UL << ADC_SQR2_SQ12_Pos)                 /*!< 0x00040000 */
#define ADC_SQR2_SQ12_3                    (0x08UL << ADC_SQR2_SQ12_Pos)                 /*!< 0x00080000 */

#define ADC_SQR2_SQ13_Pos                  (20U)
#define ADC_SQR2_SQ13_Msk                  (0xFUL << ADC_SQR2_SQ13_Pos)                  /*!< 0x00F00000 */
#define ADC_SQR2_SQ13                      ADC_SQR2_SQ13_Msk                             /*!< ADC group regular sequencer rank 13 */
#define ADC_SQR2_SQ13_0                    (0x01UL << ADC_SQR2_SQ13_Pos)                 /*!< 0x00010000 */
#define ADC_SQR2_SQ13_1                    (0x02UL << ADC_SQR2_SQ13_Pos)                 /*!< 0x00020000 */
#define ADC_SQR2_SQ13_2                    (0x04UL << ADC_SQR2_SQ13_Pos)                 /*!< 0x00040000 */
#define ADC_SQR2_SQ13_3                    (0x08UL << ADC_SQR2_SQ13_Pos)                 /*!< 0x00080000 */

#define ADC_SQR2_SQ14_Pos                  (24)
#define ADC_SQR2_SQ14_Msk                  (0xFUL << ADC_SQR2_SQ14_Pos)                  /*!< 0x0F000000 */
#define ADC_SQR2_SQ14                      ADC_SQR2_SQ14_Msk                             /*!< ADC group regular sequencer rank 14 */
#define ADC_SQR2_SQ14_0                    (0x01UL << ADC_SQR2_SQ14_Pos)                 /*!< 0x00010000 */
#define ADC_SQR2_SQ14_1                    (0x02UL << ADC_SQR2_SQ14_Pos)                 /*!< 0x00020000 */
#define ADC_SQR2_SQ14_2                    (0x04UL << ADC_SQR2_SQ14_Pos)                 /*!< 0x00040000 */
#define ADC_SQR2_SQ14_3                    (0x08UL << ADC_SQR2_SQ14_Pos)                 /*!< 0x00080000 */

/********************  Bit definition for ADC_SQR3 register  ******************/
#define ADC_SQR3_SQ15_Pos                  (0U)
#define ADC_SQR3_SQ15_Msk                  (0xFUL << ADC_SQR3_SQ15_Pos)                  /*!< 0x0000000F */
#define ADC_SQR3_SQ15                      ADC_SQR3_SQ15_Msk                             /*!< ADC group regular sequencer rank 15 */
#define ADC_SQR3_SQ15_0                    (0x01UL << ADC_SQR3_SQ15_Pos)                 /*!< 0x00000001 */
#define ADC_SQR3_SQ15_1                    (0x02UL << ADC_SQR3_SQ15_Pos)                 /*!< 0x00000002 */
#define ADC_SQR3_SQ15_2                    (0x04UL << ADC_SQR3_SQ15_Pos)                 /*!< 0x00000004 */
#define ADC_SQR3_SQ15_3                    (0x08UL << ADC_SQR3_SQ15_Pos)                 /*!< 0x00000008 */

#define ADC_SQR3_SQ16_Pos                  (4U)
#define ADC_SQR3_SQ16_Msk                  (0xFUL << ADC_SQR3_SQ16_Pos)                  /*!< 0x000000F0*/
#define ADC_SQR3_SQ16                      ADC_SQR3_SQ16_Msk                             /*!< ADC group regular sequencer rank 16 */
#define ADC_SQR3_SQ16_0                    (0x01UL << ADC_SQR3_SQ16_Pos)                 /*!< 0x00000010 */
#define ADC_SQR3_SQ16_1                    (0x02UL << ADC_SQR3_SQ16_Pos)                 /*!< 0x00000020 */
#define ADC_SQR3_SQ16_2                    (0x04UL << ADC_SQR3_SQ16_Pos)                 /*!< 0x00000040 */
#define ADC_SQR3_SQ16_3                    (0x08UL << ADC_SQR3_SQ16_Pos)                 /*!< 0x00000080 */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_RDATA_Pos                   (0U)
#define ADC_DR_RDATA_Msk                   (0xFFFFUL << ADC_DR_RDATA_Pos)                /*!< 0x0000FFFF */
#define ADC_DR_RDATA                       ADC_DR_RDATA_Msk                              /*!< ADC group regular conversion data */
#define ADC_DR_ADC2RDATA_Pos               (16U)
#define ADC_DR_ADC2RDATA_Msk               (0xFFFFUL << ADC_DR_ADC2RDATA_Pos)            /*!< 0xFFFF0000 */
#define ADC_DR_ADC2RDATA                   ADC_DR_ADC2RDATA_Msk                          /*!< ADC2 group regular conversion data */

/********************  Bit definition for ADC_JSQR register  ******************/
#define ADC_JSQR_JL_Pos                    (0U)
#define ADC_JSQR_JL_Msk                    (0x3UL << ADC_JSQR_JL_Pos)                    /*!< 0x00000003 */
#define ADC_JSQR_JL                        ADC_JSQR_JL_Msk                               /*!< ADC group injected sequencer scan length */
#define ADC_JSQR_JL_0                      (0x1UL << ADC_JSQR_JL_Pos)                    /*!< 0x00000001 */
#define ADC_JSQR_JL_1                      (0x2UL << ADC_JSQR_JL_Pos)                    /*!< 0x00000002 */

#define ADC_JSQR_JEXTSEL_Pos               (2U)
#define ADC_JSQR_JEXTSEL_Msk               (0xFUL << ADC_JSQR_JEXTSEL_Pos)               /*!< 0x0000003C */
/*!< Note: shared ADC_* mask; ADC12 chapter width is 3 bits - wider 4-bit mask retained intentionally. */
#define ADC_JSQR_JEXTSEL                   ADC_JSQR_JEXTSEL_Msk                          /*!< ADC group injected external trigger source */
#define ADC_JSQR_JEXTSEL_0                 (0x1UL << ADC_JSQR_JEXTSEL_Pos)               /*!< 0x00000004 */
#define ADC_JSQR_JEXTSEL_1                 (0x2UL << ADC_JSQR_JEXTSEL_Pos)               /*!< 0x00000008 */
#define ADC_JSQR_JEXTSEL_2                 (0x4UL << ADC_JSQR_JEXTSEL_Pos)               /*!< 0x00000010 */
#define ADC_JSQR_JEXTSEL_3                 (0x8UL << ADC_JSQR_JEXTSEL_Pos)               /*!< 0x00000020 */

#define ADC_JSQR_JEXTEN_Pos                (6U)
#define ADC_JSQR_JEXTEN_Msk                (0x3UL << ADC_JSQR_JEXTEN_Pos)                /*!< 0x000000C0 */
/*!< Note: shared ADC_* mask; ADC12 chapter width is 1 bit - wider 2-bit mask retained intentionally. */
#define ADC_JSQR_JEXTEN                    ADC_JSQR_JEXTEN_Msk                           /*!< ADC group injected external trigger polarity */
#define ADC_JSQR_JEXTEN_0                  (0x1UL << ADC_JSQR_JEXTEN_Pos)                /*!< 0x00000040 */
#define ADC_JSQR_JEXTEN_1                  (0x2UL << ADC_JSQR_JEXTEN_Pos)                /*!< 0x00000080 */

#define ADC_JSQR_JSQ1_Pos                  (8U)
#define ADC_JSQR_JSQ1_Msk                  (0xFUL << ADC_JSQR_JSQ1_Pos)                  /*!< 0x00000F00 */
#define ADC_JSQR_JSQ1                      ADC_JSQR_JSQ1_Msk                             /*!< ADC group injected sequencer rank 1 */
#define ADC_JSQR_JSQ1_0                    (0x01UL << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000100 */
#define ADC_JSQR_JSQ1_1                    (0x02UL << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000200 */
#define ADC_JSQR_JSQ1_2                    (0x04UL << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000400 */
#define ADC_JSQR_JSQ1_3                    (0x08UL << ADC_JSQR_JSQ1_Pos)                 /*!< 0x00000800 */

#define ADC_JSQR_JSQ2_Pos                  (12U)
#define ADC_JSQR_JSQ2_Msk                  (0xFUL << ADC_JSQR_JSQ2_Pos)                  /*!< 0x0000F000 */
#define ADC_JSQR_JSQ2                      ADC_JSQR_JSQ2_Msk                             /*!< ADC group injected sequencer rank 2 */
#define ADC_JSQR_JSQ2_0                    (0x01UL << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00001000 */
#define ADC_JSQR_JSQ2_1                    (0x02UL << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00002000 */
#define ADC_JSQR_JSQ2_2                    (0x04UL << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00004000 */
#define ADC_JSQR_JSQ2_3                    (0x08UL << ADC_JSQR_JSQ2_Pos)                 /*!< 0x00008000 */

#define ADC_JSQR_JSQ3_Pos                  (16U)
#define ADC_JSQR_JSQ3_Msk                  (0xFUL << ADC_JSQR_JSQ3_Pos)                  /*!< 0x000F0000 */
#define ADC_JSQR_JSQ3                      ADC_JSQR_JSQ3_Msk                             /*!< ADC group injected sequencer rank 3 */
#define ADC_JSQR_JSQ3_0                    (0x01UL << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00010000 */
#define ADC_JSQR_JSQ3_1                    (0x02UL << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00020000 */
#define ADC_JSQR_JSQ3_2                    (0x04UL << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00040000 */
#define ADC_JSQR_JSQ3_3                    (0x08UL << ADC_JSQR_JSQ3_Pos)                 /*!< 0x00080000 */

#define ADC_JSQR_JSQ4_Pos                  (20U)
#define ADC_JSQR_JSQ4_Msk                  (0xFUL << ADC_JSQR_JSQ4_Pos)                  /*!< 0x00F00000 */
#define ADC_JSQR_JSQ4                      ADC_JSQR_JSQ4_Msk                             /*!< ADC group injected sequencer rank 4 */
#define ADC_JSQR_JSQ4_0                    (0x01UL << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00100000 */
#define ADC_JSQR_JSQ4_1                    (0x02UL << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00200000 */
#define ADC_JSQR_JSQ4_2                    (0x04UL << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00400000 */
#define ADC_JSQR_JSQ4_3                    (0x08UL << ADC_JSQR_JSQ4_Pos)                 /*!< 0x00800000 */

/********************  Bit definition for ADC_JDR1 register  ******************/
#define ADC_JDR1_JDATA_Pos                 (0U)
#define ADC_JDR1_JDATA_Msk                 (0xFFFFUL << ADC_JDR1_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR1_JDATA                     ADC_JDR1_JDATA_Msk                            /*!< ADC group injected sequencer rank 1 conversion data */

/********************  Bit definition for ADC_JDR2 register  ******************/
#define ADC_JDR2_JDATA_Pos                 (0U)
#define ADC_JDR2_JDATA_Msk                 (0xFFFFUL << ADC_JDR2_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR2_JDATA                     ADC_JDR2_JDATA_Msk                            /*!< ADC group injected sequencer rank 2 conversion data */

/********************  Bit definition for ADC_JDR3 register  ******************/
#define ADC_JDR3_JDATA_Pos                 (0U)
#define ADC_JDR3_JDATA_Msk                 (0xFFFFUL << ADC_JDR3_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR3_JDATA                     ADC_JDR3_JDATA_Msk                            /*!< ADC group injected sequencer rank 3 conversion data */

/********************  Bit definition for ADC_JDR4 register  ******************/
#define ADC_JDR4_JDATA_Pos                 (0U)
#define ADC_JDR4_JDATA_Msk                 (0xFFFFUL << ADC_JDR4_JDATA_Pos)              /*!< 0x0000FFFF */
#define ADC_JDR4_JDATA                     ADC_JDR4_JDATA_Msk                            /*!< ADC group injected sequencer rank 4 conversion data */

/********************  Bit definition for ADC_AWD2CR register  ****************/
#define ADC_AWD2CR_AWD2CH_Pos              (0U)
#define ADC_AWD2CR_AWD2CH_Msk              (0x3FUL << ADC_AWD2CR_AWD2CH_Pos)             /*!< 0x0000007F */
#define ADC_AWD2CR_AWD2CH                  ADC_AWD2CR_AWD2CH_Msk                         /*!< ADC analog watchdog 2 monitored channel selection */
#define ADC_AWD2CR_AWD2CH_0                (0x00001UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000001 */
#define ADC_AWD2CR_AWD2CH_1                (0x00002UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000002 */
#define ADC_AWD2CR_AWD2CH_2                (0x00004UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000004 */
#define ADC_AWD2CR_AWD2CH_3                (0x00008UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000008 */
#define ADC_AWD2CR_AWD2CH_4                (0x00010UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000010 */
#define ADC_AWD2CR_AWD2CH_5                (0x00020UL << ADC_AWD2CR_AWD2CH_Pos)          /*!< 0x00000020 */

/********************  Bit definition for ADC_AWD3CR register  ****************/
#define ADC_AWD3CR_AWD3CH_Pos              (0U)
#define ADC_AWD3CR_AWD3CH_Msk              (0x3FUL << ADC_AWD3CR_AWD3CH_Pos)             /*!< 0x0000007F */
#define ADC_AWD3CR_AWD3CH                  ADC_AWD3CR_AWD3CH_Msk                         /*!< ADC analog watchdog 3 monitored channel selection */
#define ADC_AWD3CR_AWD3CH_0                (0x00001UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000001 */
#define ADC_AWD3CR_AWD3CH_1                (0x00002UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000002 */
#define ADC_AWD3CR_AWD3CH_2                (0x00004UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000004 */
#define ADC_AWD3CR_AWD3CH_3                (0x00008UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000008 */
#define ADC_AWD3CR_AWD3CH_4                (0x00010UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000010 */
#define ADC_AWD3CR_AWD3CH_5                (0x00020UL << ADC_AWD3CR_AWD3CH_Pos)          /*!< 0x00000020 */

/********************  Bit definition for ADC_OFFSET0 register  ******************/
#define ADC_OFFSET0_OFFSET0_Pos            (0U)
#define ADC_OFFSET0_OFFSET0_Msk            (0xFFFFUL << ADC_OFFSET0_OFFSET0_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET0_OFFSET0                ADC_OFFSET0_OFFSET0_Msk                       /*!< ADC offset number 0 offset level */
#define ADC_OFFSET0_OFFSET0_EN_Pos         (16U)
#define ADC_OFFSET0_OFFSET0_EN_Msk         (0x1UL << ADC_OFFSET0_OFFSET0_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET0_OFFSET0_EN             ADC_OFFSET0_OFFSET0_EN_Msk                    /*!< ADC offset number 0 enable */
#define ADC_OFFSET0_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET0_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET0_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET0_OFFSETPOS              ADC_OFFSET0_OFFSETPOS_Msk                     /*!< ADC offset number 0 positive */

/********************  Bit definition for ADC_OFFSET1 register  ******************/
#define ADC_OFFSET1_OFFSET1_Pos            (0U)
#define ADC_OFFSET1_OFFSET1_Msk            (0xFFFFUL << ADC_OFFSET1_OFFSET1_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET1_OFFSET1                ADC_OFFSET1_OFFSET1_Msk                       /*!< ADC offset number 1 offset level */
#define ADC_OFFSET1_OFFSET1_EN_Pos         (16U)
#define ADC_OFFSET1_OFFSET1_EN_Msk         (0x1UL << ADC_OFFSET1_OFFSET1_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET1_OFFSET1_EN             ADC_OFFSET1_OFFSET1_EN_Msk                    /*!< ADC offset number 1 enable */
#define ADC_OFFSET1_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET1_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET1_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET1_OFFSETPOS              ADC_OFFSET1_OFFSETPOS_Msk                     /*!< ADC offset number 1 positive */

/********************  Bit definition for ADC_OFFSET2 register  ******************/
#define ADC_OFFSET2_OFFSET2_Pos            (0U)
#define ADC_OFFSET2_OFFSET2_Msk            (0xFFFFUL << ADC_OFFSET2_OFFSET2_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET2_OFFSET2                ADC_OFFSET2_OFFSET2_Msk                       /*!< ADC offset number 2 offset level */
#define ADC_OFFSET2_OFFSET2_EN_Pos         (16U)
#define ADC_OFFSET2_OFFSET2_EN_Msk         (0x1UL << ADC_OFFSET2_OFFSET2_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET2_OFFSET2_EN             ADC_OFFSET2_OFFSET2_EN_Msk                    /*!< ADC offset number 2 enable */
#define ADC_OFFSET2_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET2_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET2_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET2_OFFSETPOS              ADC_OFFSET2_OFFSETPOS_Msk                     /*!< ADC offset number 2 positive */

/********************  Bit definition for ADC_OFFSET3 register  ******************/
#define ADC_OFFSET3_OFFSET3_Pos            (0U)
#define ADC_OFFSET3_OFFSET3_Msk            (0xFFFFUL << ADC_OFFSET3_OFFSET3_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET3_OFFSET3                ADC_OFFSET3_OFFSET3_Msk                       /*!< ADC offset number 3 offset level */
#define ADC_OFFSET3_OFFSET3_EN_Pos         (16U)
#define ADC_OFFSET3_OFFSET3_EN_Msk         (0x1UL << ADC_OFFSET3_OFFSET3_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET3_OFFSET3_EN             ADC_OFFSET3_OFFSET3_EN_Msk                    /*!< ADC offset number 3 enable */
#define ADC_OFFSET3_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET3_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET3_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET3_OFFSETPOS              ADC_OFFSET3_OFFSETPOS_Msk                     /*!< ADC offset number 3 positive */

/********************  Bit definition for ADC_OFFSET4 register  ******************/
#define ADC_OFFSET4_OFFSET4_Pos            (0U)
#define ADC_OFFSET4_OFFSET4_Msk            (0xFFFFUL << ADC_OFFSET4_OFFSET4_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET4_OFFSET4                ADC_OFFSET4_OFFSET4_Msk                       /*!< ADC offset number 4 offset level */
#define ADC_OFFSET4_OFFSET4_EN_Pos         (16U)
#define ADC_OFFSET4_OFFSET4_EN_Msk         (0x1UL << ADC_OFFSET4_OFFSET4_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET4_OFFSET4_EN             ADC_OFFSET4_OFFSET4_EN_Msk                    /*!< ADC offset number 4 enable */
#define ADC_OFFSET4_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET4_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET4_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET4_OFFSETPOS              ADC_OFFSET4_OFFSETPOS_Msk                     /*!< ADC offset number 4 positive */

/********************  Bit definition for ADC_OFFSET5 register  ******************/
#define ADC_OFFSET5_OFFSET5_Pos            (0U)
#define ADC_OFFSET5_OFFSET5_Msk            (0xFFFFUL << ADC_OFFSET5_OFFSET5_Pos)         /*!< 0x0000FFFF */
#define ADC_OFFSET5_OFFSET5                ADC_OFFSET5_OFFSET5_Msk                       /*!< ADC offset number 5 offset level */
#define ADC_OFFSET5_OFFSET5_EN_Pos         (16U)
#define ADC_OFFSET5_OFFSET5_EN_Msk         (0x1UL << ADC_OFFSET5_OFFSET5_EN_Pos)         /*!< 0x00010000 */
#define ADC_OFFSET5_OFFSET5_EN             ADC_OFFSET5_OFFSET5_EN_Msk                    /*!< ADC offset number 5 enable */
#define ADC_OFFSET5_OFFSETPOS_Pos          (17U)
#define ADC_OFFSET5_OFFSETPOS_Msk          (0x1UL << ADC_OFFSET5_OFFSETPOS_Pos)          /*!< 0x00020000 */
#define ADC_OFFSET5_OFFSETPOS              ADC_OFFSET5_OFFSETPOS_Msk                     /*!< ADC offset number 5 positive */

/********************  Bit definition for ADC_CAL register  *******************/
#define ADC_CAL_REF_SEL_Pos                (3U)
#define ADC_CAL_REF_SEL_Msk                (0x1UL << ADC_CAL_REF_SEL_Pos)                /*!< 0x00000008 */
#define ADC_CAL_REF_SEL                    ADC_CAL_REF_SEL_Msk                           /*!< ADC Choosing whether vref is externally generated or internally generated */

/********************  Bit definition for ADC_JOFFSET1 register  **************/
#define ADC_JOFFSET1_JOFFSET1_Pos          (0UL)
#define ADC_JOFFSET1_JOFFSET1_Msk          (0xFFFUL << ADC_JOFFSET1_JOFFSET1_Pos)        /*!< 0x00000FFF */
#define ADC_JOFFSET1_JOFFSET1              ADC_JOFFSET1_JOFFSET1_Msk                     /*!< Inject the data offset corresponding to the first transformation in the sequence. */

/********************  Bit definition for ADC_JOFFSET2 register  **************/
#define ADC_JOFFSET2_JOFFSET2_Pos          (0UL)
#define ADC_JOFFSET2_JOFFSET2_Msk          (0xFFFUL << ADC_JOFFSET2_JOFFSET2_Pos)        /*!< 0x00000FFF */
#define ADC_JOFFSET2_JOFFSET2              ADC_JOFFSET2_JOFFSET2_Msk                     /*!< Inject the data offset corresponding to the first transformation in the sequence. */

/********************  Bit definition for ADC_JOFFSET3 register  **************/
#define ADC_JOFFSET3_JOFFSET3_Pos          (0UL)
#define ADC_JOFFSET3_JOFFSET3_Msk          (0xFFFUL << ADC_JOFFSET3_JOFFSET3_Pos)        /*!< 0x00000FFF */
#define ADC_JOFFSET3_JOFFSET3              ADC_JOFFSET3_JOFFSET3_Msk                     /*!< Inject the data offset corresponding to the first transformation in the sequence. */

/********************  Bit definition for ADC_JOFFSET4 register  **************/
#define ADC_JOFFSET4_JOFFSET4_Pos          (0UL)
#define ADC_JOFFSET4_JOFFSET4_Msk          (0xFFFUL << ADC_JOFFSET4_JOFFSET4_Pos)        /*!< 0x00000FFF */
#define ADC_JOFFSET4_JOFFSET4              ADC_JOFFSET4_JOFFSET4_Msk                     /*!< Inject the data offset corresponding to the first transformation in the sequence. */

/******************************************************************************/
/*                                                                            */
/*                             Digital to Analog Converter                    */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DAC_CR register  *******************/
#define DAC_CR_EN_Pos                      (0UL)
#define DAC_CR_EN_Msk                      (0x1UL << DAC_CR_EN_Pos)                      /*!< 0x00000001 */
#define DAC_CR_EN                          DAC_CR_EN_Msk                                 /*!< DAC analog channel enable */
#define DAC_CR_TSEL_Pos                    (2UL)
#define DAC_CR_TSEL_Msk                    (0x7UL << DAC_CR_TSEL_Pos)                    /*!< 0x0000001C */
#define DAC_CR_TSEL                        DAC_CR_TSEL_Msk                               /*!< DAC channel trigger selection */
#define DAC_CR_TSEL_0                      (0x1UL << DAC_CR_TSEL_Pos)                    /*!< 0x00000004 */
#define DAC_CR_TSEL_1                      (0x2UL << DAC_CR_TSEL_Pos)                    /*!< 0x00000008 */
#define DAC_CR_TSEL_2                      (0x4UL << DAC_CR_TSEL_Pos)                    /*!< 0x00000010 */

#define DAC_CR_WAVE_Pos                    (6)
#define DAC_CR_WAVE_Msk                    (0x3UL << DAC_CR_WAVE_Pos)                    /*!< 0x000000C0 */
#define DAC_CR_WAVE                        DAC_CR_WAVE_Msk                               /*!< DAC channel noise/triangle wave generation enable */
#define DAC_CR_WAVE_0                      (0x1UL << DAC_CR_WAVE_Pos)                    /*!< 0x00000040 */
#define DAC_CR_WAVE_1                      (0x2UL << DAC_CR_WAVE_Pos)                    /*!< 0x00000080 */

#define DAC_CR_MAMP_Pos                    (8)
#define DAC_CR_MAMP_Msk                    (0xFUL << DAC_CR_MAMP_Pos)                    /*!< 0x00000F00 */
#define DAC_CR_MAMP                        DAC_CR_MAMP_Msk                               /*!< DAC channel mute/amplitude selector */
#define DAC_CR_MAMP_0                      (0x1UL << DAC_CR_MAMP_Pos)                    /*!< 0x00000100 */
#define DAC_CR_MAMP_1                      (0x2UL << DAC_CR_MAMP_Pos)                    /*!< 0x00000200 */
#define DAC_CR_MAMP_2                      (0x4UL << DAC_CR_MAMP_Pos)                    /*!< 0x00000400 */
#define DAC_CR_MAMP_3                      (0x8UL << DAC_CR_MAMP_Pos)                    /*!< 0x00000800 */

#define DAC_CR_EN_RDAC_Pos                 (12)
#define DAC_CR_EN_RDAC_Msk                 (0x3UL << DAC_CR_EN_RDAC_Pos)                 /*!< 0x000C0000 */
#define DAC_CR_EN_RDAC                     DAC_CR_EN_RDAC_Msk                            /*!< Switch that controls the output signal from the DAC resistor string to the operational amplifier input, is active low. */
#define DAC_CR_EN_RDAC_0                   (0x1UL << DAC_CR_EN_RDAC_Pos)                 /*!< 0x00001000 */
#define DAC_CR_EN_RDAC_1                   (0x2UL << DAC_CR_EN_RDAC_Pos)                 /*!< 0x00002000 */

#define DAC_CR_EXT_SEL_Pos                 (14)
#define DAC_CR_EXT_SEL_Msk                 (0x1UL << DAC_CR_EXT_SEL_Pos)                 /*!< 0x00004000 */
#define DAC_CR_EXT_SEL                     DAC_CR_EXT_SEL_Msk                            /*!< Whether the BUFFER output is enabled by connecting to the PAD pin. */

/********************  Bits definition for DAC_SWTRGR register  ***************/
#define DAC_SWTRGR_SWTRIG_Pos              (0)
#define DAC_SWTRGR_SWTRIG_Msk              (0x1UL << DAC_SWTRGR_SWTRIG_Pos)              /*!< 0x00000001 */
#define DAC_SWTRGR_SWTRIG                  DAC_SWTRGR_SWTRIG_Msk                         /*!< DAC channel software trigger. */

#define DAC_SWTRGR_SWTRIGB_Pos             (16)
#define DAC_SWTRGR_SWTRIGB_Msk             (0x1UL << DAC_SWTRGR_SWTRIGB_Pos)             /*!< 0x00010000 */
#define DAC_SWTRGR_SWTRIGB                 DAC_SWTRGR_SWTRIGB_Msk                        /*!< DAC channel software trigger B */

/********************  Bits definition for DAC_DHR10R register  ***************/
#define DAC_DHR10R_DHR10R_Pos              (0)
#define DAC_DHR10R_DHR10R_Msk              (0x3FFUL << DAC_DHR10R_DHR10R_Pos)            /*!< 0x000003FF */
#define DAC_DHR10R_DHR10R                  DAC_DHR10R_DHR10R_Msk                         /*!< DAC channel 10-bit right-aligned data */

/********************  Bits definition for DAC_DHL10L register  ***************/
#define DAC_DHR10L_DHR10L_Pos              (6)
#define DAC_DHR10L_DHR10L_Msk              (0x3FFUL << DAC_DHR10L_DHR10L_Pos)            /*!< 0xFFC00000 */
#define DAC_DHR10L_DHR10L                  DAC_DHR10L_DHR10L_Msk                         /*!< DAC channel 10-bit left-aligned data. */

/********************  Bits definition for DAC_DOR register  ******************/
#define DAC_DOR_DOR_Pos                    (0)
#define DAC_DOR_DOR_Msk                    (0x3FFUL << DAC_DOR_DOR_Pos)                  /*!< 0x000003FF */
#define DAC_DOR_DOR                        DAC_DOR_DOR_Msk                               /*!< DAC channel data output */

/********************  Bits definition for DAC_STR register  ******************/
#define DAC_STR_STRSTDATA_Pos              (0)
#define DAC_STR_STRSTDATA_Msk              (0x3FFUL << DAC_STR_STRSTDATA_Pos)            /*!< 0x000003FF */
#define DAC_STR_STRSTDATA                  DAC_STR_STRSTDATA_Msk                         /*!< DAC channel sawtooth wave reset value. */

#define DAC_STR_STDIR_Pos                  (12)
#define DAC_STR_STDIR_Msk                  (0x1UL << DAC_STR_STDIR_Pos)                  /*!< 0x00001000 */
#define DAC_STR_STDIR                      DAC_STR_STDIR_Msk                             /*!< Direction Setting of DAC Channel Sawtooth Wave */

#define DAC_STR_STINCDATA_Pos              (22)
#define DAC_STR_STINCDATA_Msk              (0x3FFUL << DAC_STR_STINCDATA_Pos)            /*!< 0xFFC00000 */
#define DAC_STR_STINCDATA                  DAC_STR_STINCDATA_Msk                         /*!< DAC channel sawtooth wave increment value */

/********************  Bits definition for DAC_STMODR register  ***************/
#define DAC_STMODR_STRSTTRIGSEL_Pos        (0)
#define DAC_STMODR_STRSTTRIGSEL_Msk        (0x7UL << DAC_STMODR_STRSTTRIGSEL_Pos)        /*!< 0x00000007 */
#define DAC_STMODR_STRSTTRIGSEL            DAC_STMODR_STRSTTRIGSEL_Msk                   /*!< DAC channel sawtooth wave reset trigger selection */
#define DAC_STMODR_STRSTTRIGSEL_0          (0x1UL << DAC_STMODR_STRSTTRIGSEL_Pos)        /*!< 0x00000001 */
#define DAC_STMODR_STRSTTRIGSEL_1          (0x2UL << DAC_STMODR_STRSTTRIGSEL_Pos)        /*!< 0x00000002 */
#define DAC_STMODR_STRSTTRIGSEL_2          (0x4UL << DAC_STMODR_STRSTTRIGSEL_Pos)        /*!< 0x00000004 */

#define DAC_STMODR_STINCTRIGSEL_Pos        (8)
#define DAC_STMODR_STINCTRIGSEL_Msk        (0x7UL << DAC_STMODR_STINCTRIGSEL_Pos)        /*!< 0x00000700 */
#define DAC_STMODR_STINCTRIGSEL            DAC_STMODR_STINCTRIGSEL_Msk                   /*!< DAC channel sawtooth wave incremental trigger selection. */
#define DAC_STMODR_STINCTRIGSEL_0          (0x1UL << DAC_STMODR_STINCTRIGSEL_Pos)        /*!< 0x00000100 */
#define DAC_STMODR_STINCTRIGSEL_1          (0x2UL << DAC_STMODR_STINCTRIGSEL_Pos)        /*!< 0x00000200 */
#define DAC_STMODR_STINCTRIGSEL_2          (0x4UL << DAC_STMODR_STINCTRIGSEL_Pos)        /*!< 0x00000400 */

/********************  Bits definition for DAC_SR register  *******************/
#define DAC_SR_DOWN_OW_FLAG_Pos            (0)
#define DAC_SR_DOWN_OW_FLAG_Msk            (0x1UL << DAC_SR_DOWN_OW_FLAG_Pos)            /*!< 0x00000001 */
#define DAC_SR_DOWN_OW_FLAG                DAC_SR_DOWN_OW_FLAG_Msk                       /*!< DOR Data Underflow Flag */

#define DAC_SR_UP_OW_FLAG_Pos              (1)
#define DAC_SR_UP_OW_FLAG_Msk              (0x1UL << DAC_SR_UP_OW_FLAG_Pos)              /*!< 0x00000002 */
#define DAC_SR_UP_OW_FLAG                  DAC_SR_UP_OW_FLAG_Msk                         /*!< DOR Data Upflow Flag */

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_LINTSTS register  **************/
#define DMA_LINTSTS_FEIFLG0_Pos            (0U)
#define DMA_LINTSTS_FEIFLG0_Msk            (0x1UL << DMA_LINTSTS_FEIFLG0_Pos)            /*!< 0x00000001 */
#define DMA_LINTSTS_FEIFLG0                DMA_LINTSTS_FEIFLG0_Msk
#define DMA_LINTSTS_DMEIFLG0_Pos           (2U)
#define DMA_LINTSTS_DMEIFLG0_Msk           (0x1UL << DMA_LINTSTS_DMEIFLG0_Pos)           /*!< 0x00000004 */
#define DMA_LINTSTS_DMEIFLG0               DMA_LINTSTS_DMEIFLG0_Msk
#define DMA_LINTSTS_TXEIFLG0_Pos           (3U)
#define DMA_LINTSTS_TXEIFLG0_Msk           (0x1UL << DMA_LINTSTS_TXEIFLG0_Pos)           /*!< 0x00000008 */
#define DMA_LINTSTS_TXEIFLG0               DMA_LINTSTS_TXEIFLG0_Msk
#define DMA_LINTSTS_HTXIFLG0_Pos           (4U)
#define DMA_LINTSTS_HTXIFLG0_Msk           (0x1UL << DMA_LINTSTS_HTXIFLG0_Pos)           /*!< 0x00000010 */
#define DMA_LINTSTS_HTXIFLG0               DMA_LINTSTS_HTXIFLG0_Msk
#define DMA_LINTSTS_TXCIFLG0_Pos           (5U)
#define DMA_LINTSTS_TXCIFLG0_Msk           (0x1UL << DMA_LINTSTS_TXCIFLG0_Pos)           /*!< 0x00000020 */
#define DMA_LINTSTS_TXCIFLG0               DMA_LINTSTS_TXCIFLG0_Msk
#define DMA_LINTSTS_FEIFLG1_Pos            (6U)
#define DMA_LINTSTS_FEIFLG1_Msk            (0x1UL << DMA_LINTSTS_FEIFLG1_Pos)            /*!< 0x00000040 */
#define DMA_LINTSTS_FEIFLG1                DMA_LINTSTS_FEIFLG1_Msk
#define DMA_LINTSTS_DMEIFLG1_Pos           (8U)
#define DMA_LINTSTS_DMEIFLG1_Msk           (0x1UL << DMA_LINTSTS_DMEIFLG1_Pos)           /*!< 0x00000100 */
#define DMA_LINTSTS_DMEIFLG1               DMA_LINTSTS_DMEIFLG1_Msk
#define DMA_LINTSTS_TXEIFLG1_Pos           (9U)
#define DMA_LINTSTS_TXEIFLG1_Msk           (0x1UL << DMA_LINTSTS_TXEIFLG1_Pos)           /*!< 0x00000200 */
#define DMA_LINTSTS_TXEIFLG1               DMA_LINTSTS_TXEIFLG1_Msk
#define DMA_LINTSTS_HTXIFLG1_Pos           (10U)
#define DMA_LINTSTS_HTXIFLG1_Msk           (0x1UL << DMA_LINTSTS_HTXIFLG1_Pos)           /*!< 0x00000400 */
#define DMA_LINTSTS_HTXIFLG1               DMA_LINTSTS_HTXIFLG1_Msk
#define DMA_LINTSTS_TXCIFLG1_Pos           (11U)
#define DMA_LINTSTS_TXCIFLG1_Msk           (0x1UL << DMA_LINTSTS_TXCIFLG1_Pos)           /*!< 0x00000800 */
#define DMA_LINTSTS_TXCIFLG1               DMA_LINTSTS_TXCIFLG1_Msk
#define DMA_LINTSTS_FEIFLG2_Pos            (16U)
#define DMA_LINTSTS_FEIFLG2_Msk            (0x1UL << DMA_LINTSTS_FEIFLG2_Pos)            /*!< 0x00010000 */
#define DMA_LINTSTS_FEIFLG2                DMA_LINTSTS_FEIFLG2_Msk
#define DMA_LINTSTS_DMEIFLG2_Pos           (18U)
#define DMA_LINTSTS_DMEIFLG2_Msk           (0x1UL << DMA_LINTSTS_DMEIFLG2_Pos)           /*!< 0x00040000 */
#define DMA_LINTSTS_DMEIFLG2               DMA_LINTSTS_DMEIFLG2_Msk
#define DMA_LINTSTS_TXEIFLG2_Pos           (19U)
#define DMA_LINTSTS_TXEIFLG2_Msk           (0x1UL << DMA_LINTSTS_TXEIFLG2_Pos)           /*!< 0x00080000 */
#define DMA_LINTSTS_TXEIFLG2               DMA_LINTSTS_TXEIFLG2_Msk
#define DMA_LINTSTS_HTXIFLG2_Pos           (20U)
#define DMA_LINTSTS_HTXIFLG2_Msk           (0x1UL << DMA_LINTSTS_HTXIFLG2_Pos)           /*!< 0x00100000 */
#define DMA_LINTSTS_HTXIFLG2               DMA_LINTSTS_HTXIFLG2_Msk
#define DMA_LINTSTS_TXCIFLG2_Pos           (21U)
#define DMA_LINTSTS_TXCIFLG2_Msk           (0x1UL << DMA_LINTSTS_TXCIFLG2_Pos)           /*!< 0x00200000 */
#define DMA_LINTSTS_TXCIFLG2               DMA_LINTSTS_TXCIFLG2_Msk
#define DMA_LINTSTS_FEIFLG3_Pos            (22U)
#define DMA_LINTSTS_FEIFLG3_Msk            (0x1UL << DMA_LINTSTS_FEIFLG3_Pos)            /*!< 0x00400000 */
#define DMA_LINTSTS_FEIFLG3                DMA_LINTSTS_FEIFLG3_Msk
#define DMA_LINTSTS_DMEIFLG3_Pos           (24U)
#define DMA_LINTSTS_DMEIFLG3_Msk           (0x1UL << DMA_LINTSTS_DMEIFLG3_Pos)           /*!< 0x01000000 */
#define DMA_LINTSTS_DMEIFLG3               DMA_LINTSTS_DMEIFLG3_Msk
#define DMA_LINTSTS_TXEIFLG3_Pos           (25U)
#define DMA_LINTSTS_TXEIFLG3_Msk           (0x1UL << DMA_LINTSTS_TXEIFLG3_Pos)           /*!< 0x02000000 */
#define DMA_LINTSTS_TXEIFLG3               DMA_LINTSTS_TXEIFLG3_Msk
#define DMA_LINTSTS_HTXIFLG3_Pos           (26U)
#define DMA_LINTSTS_HTXIFLG3_Msk           (0x1UL << DMA_LINTSTS_HTXIFLG3_Pos)           /*!< 0x04000000 */
#define DMA_LINTSTS_HTXIFLG3               DMA_LINTSTS_HTXIFLG3_Msk
#define DMA_LINTSTS_TXCIFLG3_Pos           (27U)
#define DMA_LINTSTS_TXCIFLG3_Msk           (0x1UL << DMA_LINTSTS_TXCIFLG3_Pos)           /*!< 0x08000000 */
#define DMA_LINTSTS_TXCIFLG3               DMA_LINTSTS_TXCIFLG3_Msk

/********************  Bits definition for DMA_HINTSTS register  **************/
#define DMA_HINTSTS_FEIFLG4_Pos            (0U)
#define DMA_HINTSTS_FEIFLG4_Msk            (0x1UL << DMA_HINTSTS_FEIFLG4_Pos)            /*!< 0x00000001 */
#define DMA_HINTSTS_FEIFLG4                DMA_HINTSTS_FEIFLG4_Msk
#define DMA_HINTSTS_DMEIFLG4_Pos           (2U)
#define DMA_HINTSTS_DMEIFLG4_Msk           (0x1UL << DMA_HINTSTS_DMEIFLG4_Pos)           /*!< 0x00000004 */
#define DMA_HINTSTS_DMEIFLG4               DMA_HINTSTS_DMEIFLG4_Msk
#define DMA_HINTSTS_TXEIFLG4_Pos           (3U)
#define DMA_HINTSTS_TXEIFLG4_Msk           (0x1UL << DMA_HINTSTS_TXEIFLG4_Pos)           /*!< 0x00000008 */
#define DMA_HINTSTS_TXEIFLG4               DMA_HINTSTS_TXEIFLG4_Msk
#define DMA_HINTSTS_HTXIFLG4_Pos           (4U)
#define DMA_HINTSTS_HTXIFLG4_Msk           (0x1UL << DMA_HINTSTS_HTXIFLG4_Pos)           /*!< 0x00000010 */
#define DMA_HINTSTS_HTXIFLG4               DMA_HINTSTS_HTXIFLG4_Msk
#define DMA_HINTSTS_TXCIFLG4_Pos           (5U)
#define DMA_HINTSTS_TXCIFLG4_Msk           (0x1UL << DMA_HINTSTS_TXCIFLG4_Pos)           /*!< 0x00000020 */
#define DMA_HINTSTS_TXCIFLG4               DMA_HINTSTS_TXCIFLG4_Msk
#define DMA_HINTSTS_FEIFLG5_Pos            (6U)
#define DMA_HINTSTS_FEIFLG5_Msk            (0x1UL << DMA_HINTSTS_FEIFLG5_Pos)            /*!< 0x00000040 */
#define DMA_HINTSTS_FEIFLG5                DMA_HINTSTS_FEIFLG5_Msk
#define DMA_HINTSTS_DMEIFLG5_Pos           (8U)
#define DMA_HINTSTS_DMEIFLG5_Msk           (0x1UL << DMA_HINTSTS_DMEIFLG5_Pos)           /*!< 0x00000100 */
#define DMA_HINTSTS_DMEIFLG5               DMA_HINTSTS_DMEIFLG5_Msk
#define DMA_HINTSTS_TXEIFLG5_Pos           (9U)
#define DMA_HINTSTS_TXEIFLG5_Msk           (0x1UL << DMA_HINTSTS_TXEIFLG5_Pos)           /*!< 0x00000200 */
#define DMA_HINTSTS_TXEIFLG5               DMA_HINTSTS_TXEIFLG5_Msk
#define DMA_HINTSTS_HTXIFLG5_Pos           (10U)
#define DMA_HINTSTS_HTXIFLG5_Msk           (0x1UL << DMA_HINTSTS_HTXIFLG5_Pos)           /*!< 0x00000400 */
#define DMA_HINTSTS_HTXIFLG5               DMA_HINTSTS_HTXIFLG5_Msk
#define DMA_HINTSTS_TXCIFLG5_Pos           (11U)
#define DMA_HINTSTS_TXCIFLG5_Msk           (0x1UL << DMA_HINTSTS_TXCIFLG5_Pos)           /*!< 0x00000800 */
#define DMA_HINTSTS_TXCIFLG5               DMA_HINTSTS_TXCIFLG5_Msk
#define DMA_HINTSTS_FEIFLG6_Pos            (16U)
#define DMA_HINTSTS_FEIFLG6_Msk            (0x1UL << DMA_HINTSTS_FEIFLG6_Pos)            /*!< 0x00010000 */
#define DMA_HINTSTS_FEIFLG6                DMA_HINTSTS_FEIFLG6_Msk
#define DMA_HINTSTS_DMEIFLG6_Pos           (18U)
#define DMA_HINTSTS_DMEIFLG6_Msk           (0x1UL << DMA_HINTSTS_DMEIFLG6_Pos)           /*!< 0x00040000 */
#define DMA_HINTSTS_DMEIFLG6               DMA_HINTSTS_DMEIFLG6_Msk
#define DMA_HINTSTS_TXEIFLG6_Pos           (19U)
#define DMA_HINTSTS_TXEIFLG6_Msk           (0x1UL << DMA_HINTSTS_TXEIFLG6_Pos)           /*!< 0x00080000 */
#define DMA_HINTSTS_TXEIFLG6               DMA_HINTSTS_TXEIFLG6_Msk
#define DMA_HINTSTS_HTXIFLG6_Pos           (20U)
#define DMA_HINTSTS_HTXIFLG6_Msk           (0x1UL << DMA_HINTSTS_HTXIFLG6_Pos)           /*!< 0x00100000 */
#define DMA_HINTSTS_HTXIFLG6               DMA_HINTSTS_HTXIFLG6_Msk
#define DMA_HINTSTS_TXCIFLG6_Pos           (21U)
#define DMA_HINTSTS_TXCIFLG6_Msk           (0x1UL << DMA_HINTSTS_TXCIFLG6_Pos)           /*!< 0x00200000 */
#define DMA_HINTSTS_TXCIFLG6               DMA_HINTSTS_TXCIFLG6_Msk
#define DMA_HINTSTS_FEIFLG7_Pos            (22U)
#define DMA_HINTSTS_FEIFLG7_Msk            (0x1UL << DMA_HINTSTS_FEIFLG7_Pos)            /*!< 0x00400000 */
#define DMA_HINTSTS_FEIFLG7                DMA_HINTSTS_FEIFLG7_Msk
#define DMA_HINTSTS_DMEIFLG7_Pos           (24U)
#define DMA_HINTSTS_DMEIFLG7_Msk           (0x1UL << DMA_HINTSTS_DMEIFLG7_Pos)           /*!< 0x01000000 */
#define DMA_HINTSTS_DMEIFLG7               DMA_HINTSTS_DMEIFLG7_Msk
#define DMA_HINTSTS_TXEIFLG7_Pos           (25U)
#define DMA_HINTSTS_TXEIFLG7_Msk           (0x1UL << DMA_HINTSTS_TXEIFLG7_Pos)           /*!< 0x02000000 */
#define DMA_HINTSTS_TXEIFLG7               DMA_HINTSTS_TXEIFLG7_Msk
#define DMA_HINTSTS_HTXIFLG7_Pos           (26U)
#define DMA_HINTSTS_HTXIFLG7_Msk           (0x1UL << DMA_HINTSTS_HTXIFLG7_Pos)           /*!< 0x04000000 */
#define DMA_HINTSTS_HTXIFLG7               DMA_HINTSTS_HTXIFLG7_Msk
#define DMA_HINTSTS_TXCIFLG7_Pos           (27U)
#define DMA_HINTSTS_TXCIFLG7_Msk           (0x1UL << DMA_HINTSTS_TXCIFLG7_Pos)           /*!< 0x08000000 */
#define DMA_HINTSTS_TXCIFLG7               DMA_HINTSTS_TXCIFLG7_Msk

/********************  Bits definition for DMA_LIFCLR register  ***************/
#define DMA_LIFCLR_CFEIFLG0_Pos            (0U)
#define DMA_LIFCLR_CFEIFLG0_Msk            (0x1UL << DMA_LIFCLR_CFEIFLG0_Pos)            /*!< 0x00000001 */
#define DMA_LIFCLR_CFEIFLG0                DMA_LIFCLR_CFEIFLG0_Msk
#define DMA_LIFCLR_CDMEIFLG0_Pos           (2U)
#define DMA_LIFCLR_CDMEIFLG0_Msk           (0x1UL << DMA_LIFCLR_CDMEIFLG0_Pos)           /*!< 0x00000004 */
#define DMA_LIFCLR_CDMEIFLG0               DMA_LIFCLR_CDMEIFLG0_Msk
#define DMA_LIFCLR_CTXEIFLG0_Pos           (3U)
#define DMA_LIFCLR_CTXEIFLG0_Msk           (0x1UL << DMA_LIFCLR_CTXEIFLG0_Pos)           /*!< 0x00000008 */
#define DMA_LIFCLR_CTXEIFLG0               DMA_LIFCLR_CTXEIFLG0_Msk
#define DMA_LIFCLR_CHTXIFLG0_Pos           (4U)
#define DMA_LIFCLR_CHTXIFLG0_Msk           (0x1UL << DMA_LIFCLR_CHTXIFLG0_Pos)           /*!< 0x00000010 */
#define DMA_LIFCLR_CHTXIFLG0               DMA_LIFCLR_CHTXIFLG0_Msk
#define DMA_LIFCLR_CTXCIFLG0_Pos           (5U)
#define DMA_LIFCLR_CTXCIFLG0_Msk           (0x1UL << DMA_LIFCLR_CTXCIFLG0_Pos)           /*!< 0x00000020 */
#define DMA_LIFCLR_CTXCIFLG0               DMA_LIFCLR_CTXCIFLG0_Msk
#define DMA_LIFCLR_CFEIFLG1_Pos            (6U)
#define DMA_LIFCLR_CFEIFLG1_Msk            (0x1UL << DMA_LIFCLR_CFEIFLG1_Pos)            /*!< 0x00000040 */
#define DMA_LIFCLR_CFEIFLG1                DMA_LIFCLR_CFEIFLG1_Msk
#define DMA_LIFCLR_CDMEIFLG1_Pos           (8U)
#define DMA_LIFCLR_CDMEIFLG1_Msk           (0x1UL << DMA_LIFCLR_CDMEIFLG1_Pos)           /*!< 0x00000100 */
#define DMA_LIFCLR_CDMEIFLG1               DMA_LIFCLR_CDMEIFLG1_Msk
#define DMA_LIFCLR_CTXEIFLG1_Pos           (9U)
#define DMA_LIFCLR_CTXEIFLG1_Msk           (0x1UL << DMA_LIFCLR_CTXEIFLG1_Pos)           /*!< 0x00000200 */
#define DMA_LIFCLR_CTXEIFLG1               DMA_LIFCLR_CTXEIFLG1_Msk
#define DMA_LIFCLR_CHTXIFLG1_Pos           (10U)
#define DMA_LIFCLR_CHTXIFLG1_Msk           (0x1UL << DMA_LIFCLR_CHTXIFLG1_Pos)           /*!< 0x00000400 */
#define DMA_LIFCLR_CHTXIFLG1               DMA_LIFCLR_CHTXIFLG1_Msk
#define DMA_LIFCLR_CTXCIFLG1_Pos           (11U)
#define DMA_LIFCLR_CTXCIFLG1_Msk           (0x1UL << DMA_LIFCLR_CTXCIFLG1_Pos)           /*!< 0x00000800 */
#define DMA_LIFCLR_CTXCIFLG1               DMA_LIFCLR_CTXCIFLG1_Msk
#define DMA_LIFCLR_CFEIFLG2_Pos            (16U)
#define DMA_LIFCLR_CFEIFLG2_Msk            (0x1UL << DMA_LIFCLR_CFEIFLG2_Pos)            /*!< 0x00010000 */
#define DMA_LIFCLR_CFEIFLG2                DMA_LIFCLR_CFEIFLG2_Msk
#define DMA_LIFCLR_CDMEIFLG2_Pos           (18U)
#define DMA_LIFCLR_CDMEIFLG2_Msk           (0x1UL << DMA_LIFCLR_CDMEIFLG2_Pos)           /*!< 0x00040000 */
#define DMA_LIFCLR_CDMEIFLG2               DMA_LIFCLR_CDMEIFLG2_Msk
#define DMA_LIFCLR_CTXEIFLG2_Pos           (19U)
#define DMA_LIFCLR_CTXEIFLG2_Msk           (0x1UL << DMA_LIFCLR_CTXEIFLG2_Pos)           /*!< 0x00080000 */
#define DMA_LIFCLR_CTXEIFLG2               DMA_LIFCLR_CTXEIFLG2_Msk
#define DMA_LIFCLR_CHTXIFLG2_Pos           (20U)
#define DMA_LIFCLR_CHTXIFLG2_Msk           (0x1UL << DMA_LIFCLR_CHTXIFLG2_Pos)           /*!< 0x00100000 */
#define DMA_LIFCLR_CHTXIFLG2               DMA_LIFCLR_CHTXIFLG2_Msk
#define DMA_LIFCLR_CTXCIFLG2_Pos           (21U)
#define DMA_LIFCLR_CTXCIFLG2_Msk           (0x1UL << DMA_LIFCLR_CTXCIFLG2_Pos)           /*!< 0x00200000 */
#define DMA_LIFCLR_CTXCIFLG2               DMA_LIFCLR_CTXCIFLG2_Msk
#define DMA_LIFCLR_CFEIFLG3_Pos            (22U)
#define DMA_LIFCLR_CFEIFLG3_Msk            (0x1UL << DMA_LIFCLR_CFEIFLG3_Pos)            /*!< 0x00400000 */
#define DMA_LIFCLR_CFEIFLG3                DMA_LIFCLR_CFEIFLG3_Msk
#define DMA_LIFCLR_CDMEIFLG3_Pos           (24U)
#define DMA_LIFCLR_CDMEIFLG3_Msk           (0x1UL << DMA_LIFCLR_CDMEIFLG3_Pos)           /*!< 0x01000000 */
#define DMA_LIFCLR_CDMEIFLG3               DMA_LIFCLR_CDMEIFLG3_Msk
#define DMA_LIFCLR_CTXEIFLG3_Pos           (25U)
#define DMA_LIFCLR_CTXEIFLG3_Msk           (0x1UL << DMA_LIFCLR_CTXEIFLG3_Pos)           /*!< 0x02000000 */
#define DMA_LIFCLR_CTXEIFLG3               DMA_LIFCLR_CTXEIFLG3_Msk
#define DMA_LIFCLR_CHTXIFLG3_Pos           (26U)
#define DMA_LIFCLR_CHTXIFLG3_Msk           (0x1UL << DMA_LIFCLR_CHTXIFLG3_Pos)           /*!< 0x04000000 */
#define DMA_LIFCLR_CHTXIFLG3               DMA_LIFCLR_CHTXIFLG3_Msk
#define DMA_LIFCLR_CTXCIFLG3_Pos           (27U)
#define DMA_LIFCLR_CTXCIFLG3_Msk           (0x1UL << DMA_LIFCLR_CTXCIFLG3_Pos)           /*!< 0x08000000 */
#define DMA_LIFCLR_CTXCIFLG3               DMA_LIFCLR_CTXCIFLG3_Msk

/********************  Bits definition for DMA_HIFCLR  register  **************/
#define DMA_HIFCLR_CFEIFLG4_Pos            (0U)
#define DMA_HIFCLR_CFEIFLG4_Msk            (0x1UL << DMA_HIFCLR_CFEIFLG4_Pos)            /*!< 0x00000001 */
#define DMA_HIFCLR_CFEIFLG4                DMA_HIFCLR_CFEIFLG4_Msk
#define DMA_HIFCLR_CDMEIFLG4_Pos           (2U)
#define DMA_HIFCLR_CDMEIFLG4_Msk           (0x1UL << DMA_HIFCLR_CDMEIFLG4_Pos)           /*!< 0x00000004 */
#define DMA_HIFCLR_CDMEIFLG4               DMA_HIFCLR_CDMEIFLG4_Msk
#define DMA_HIFCLR_CTXEIFLG4_Pos           (3U)
#define DMA_HIFCLR_CTXEIFLG4_Msk           (0x1UL << DMA_HIFCLR_CTXEIFLG4_Pos)           /*!< 0x00000008 */
#define DMA_HIFCLR_CTXEIFLG4               DMA_HIFCLR_CTXEIFLG4_Msk
#define DMA_HIFCLR_CHTXIFLG4_Pos           (4U)
#define DMA_HIFCLR_CHTXIFLG4_Msk           (0x1UL << DMA_HIFCLR_CHTXIFLG4_Pos)           /*!< 0x00000010 */
#define DMA_HIFCLR_CHTXIFLG4               DMA_HIFCLR_CHTXIFLG4_Msk
#define DMA_HIFCLR_CTXCIFLG4_Pos           (5U)
#define DMA_HIFCLR_CTXCIFLG4_Msk           (0x1UL << DMA_HIFCLR_CTXCIFLG4_Pos)           /*!< 0x00000020 */
#define DMA_HIFCLR_CTXCIFLG4               DMA_HIFCLR_CTXCIFLG4_Msk
#define DMA_HIFCLR_CFEIFLG5_Pos            (6U)
#define DMA_HIFCLR_CFEIFLG5_Msk            (0x1UL << DMA_HIFCLR_CFEIFLG5_Pos)            /*!< 0x00000040 */
#define DMA_HIFCLR_CFEIFLG5                DMA_HIFCLR_CFEIFLG5_Msk
#define DMA_HIFCLR_CDMEIFLG5_Pos           (8U)
#define DMA_HIFCLR_CDMEIFLG5_Msk           (0x1UL << DMA_HIFCLR_CDMEIFLG5_Pos)           /*!< 0x00000100 */
#define DMA_HIFCLR_CDMEIFLG5               DMA_HIFCLR_CDMEIFLG5_Msk
#define DMA_HIFCLR_CTXEIFLG5_Pos           (9U)
#define DMA_HIFCLR_CTXEIFLG5_Msk           (0x1UL << DMA_HIFCLR_CTXEIFLG5_Pos)           /*!< 0x00000200 */
#define DMA_HIFCLR_CTXEIFLG5               DMA_HIFCLR_CTXEIFLG5_Msk
#define DMA_HIFCLR_CHTXIFLG5_Pos           (10U)
#define DMA_HIFCLR_CHTXIFLG5_Msk           (0x1UL << DMA_HIFCLR_CHTXIFLG5_Pos)           /*!< 0x00000400 */
#define DMA_HIFCLR_CHTXIFLG5               DMA_HIFCLR_CHTXIFLG5_Msk
#define DMA_HIFCLR_CTXCIFLG5_Pos           (11U)
#define DMA_HIFCLR_CTXCIFLG5_Msk           (0x1UL << DMA_HIFCLR_CTXCIFLG5_Pos)           /*!< 0x00000800 */
#define DMA_HIFCLR_CTXCIFLG5               DMA_HIFCLR_CTXCIFLG5_Msk
#define DMA_HIFCLR_CFEIFLG6_Pos            (16U)
#define DMA_HIFCLR_CFEIFLG6_Msk            (0x1UL << DMA_HIFCLR_CFEIFLG6_Pos)            /*!< 0x00010000 */
#define DMA_HIFCLR_CFEIFLG6                DMA_HIFCLR_CFEIFLG6_Msk
#define DMA_HIFCLR_CDMEIFLG6_Pos           (18U)
#define DMA_HIFCLR_CDMEIFLG6_Msk           (0x1UL << DMA_HIFCLR_CDMEIFLG6_Pos)           /*!< 0x00040000 */
#define DMA_HIFCLR_CDMEIFLG6               DMA_HIFCLR_CDMEIFLG6_Msk
#define DMA_HIFCLR_CTXEIFLG6_Pos           (19U)
#define DMA_HIFCLR_CTXEIFLG6_Msk           (0x1UL << DMA_HIFCLR_CTXEIFLG6_Pos)           /*!< 0x00080000 */
#define DMA_HIFCLR_CTXEIFLG6               DMA_HIFCLR_CTXEIFLG6_Msk
#define DMA_HIFCLR_CHTXIFLG6_Pos           (20U)
#define DMA_HIFCLR_CHTXIFLG6_Msk           (0x1UL << DMA_HIFCLR_CHTXIFLG6_Pos)           /*!< 0x00100000 */
#define DMA_HIFCLR_CHTXIFLG6               DMA_HIFCLR_CHTXIFLG6_Msk
#define DMA_HIFCLR_CTXCIFLG6_Pos           (21U)
#define DMA_HIFCLR_CTXCIFLG6_Msk           (0x1UL << DMA_HIFCLR_CTXCIFLG6_Pos)           /*!< 0x00200000 */
#define DMA_HIFCLR_CTXCIFLG6               DMA_HIFCLR_CTXCIFLG6_Msk
#define DMA_HIFCLR_CFEIFLG7_Pos            (22U)
#define DMA_HIFCLR_CFEIFLG7_Msk            (0x1UL << DMA_HIFCLR_CFEIFLG7_Pos)            /*!< 0x00400000 */
#define DMA_HIFCLR_CFEIFLG7                DMA_HIFCLR_CFEIFLG7_Msk
#define DMA_HIFCLR_CDMEIFLG7_Pos           (24U)
#define DMA_HIFCLR_CDMEIFLG7_Msk           (0x1UL << DMA_HIFCLR_CDMEIFLG7_Pos)           /*!< 0x01000000 */
#define DMA_HIFCLR_CDMEIFLG7               DMA_HIFCLR_CDMEIFLG7_Msk
#define DMA_HIFCLR_CTXEIFLG7_Pos           (25U)
#define DMA_HIFCLR_CTXEIFLG7_Msk           (0x1UL << DMA_HIFCLR_CTXEIFLG7_Pos)           /*!< 0x02000000 */
#define DMA_HIFCLR_CTXEIFLG7               DMA_HIFCLR_CTXEIFLG7_Msk
#define DMA_HIFCLR_CHTXIFLG7_Pos           (26U)
#define DMA_HIFCLR_CHTXIFLG7_Msk           (0x1UL << DMA_HIFCLR_CHTXIFLG7_Pos)           /*!< 0x04000000 */
#define DMA_HIFCLR_CHTXIFLG7               DMA_HIFCLR_CHTXIFLG7_Msk
#define DMA_HIFCLR_CTXCIFLG7_Pos           (27U)
#define DMA_HIFCLR_CTXCIFLG7_Msk           (0x1UL << DMA_HIFCLR_CTXCIFLG7_Pos)           /*!< 0x08000000 */
#define DMA_HIFCLR_CTXCIFLG7               DMA_HIFCLR_CTXCIFLG7_Msk

/********************  Bits definition for DMA_SCFG register  *****************/

#define DMA_SCFG_EN_Pos                    (0U)
#define DMA_SCFG_EN_Msk                    (0x1UL << DMA_SCFG_EN_Pos)                    /*!< 0x00000001 */
#define DMA_SCFG_EN                        DMA_SCFG_EN_Msk
#define DMA_SCFG_DMEIEN_Pos                (1U)
#define DMA_SCFG_DMEIEN_Msk                (0x1UL << DMA_SCFG_DMEIEN_Pos)                /*!< 0x00000000 */
#define DMA_SCFG_DMEIEN                    DMA_SCFG_DMEIEN_Msk
#define DMA_SCFG_TXEIEN_Pos                (2U)
#define DMA_SCFG_TXEIEN_Msk                (0x1UL << DMA_SCFG_TXEIEN_Pos)                /*!< 0x00000004 */
#define DMA_SCFG_TXEIEN                    DMA_SCFG_TXEIEN_Msk
#define DMA_SCFG_HTXIEN_Pos                (3U)
#define DMA_SCFG_HTXIEN_Msk                (0x1UL << DMA_SCFG_HTXIEN_Pos)                /*!< 0x00000008 */
#define DMA_SCFG_HTXIEN                    DMA_SCFG_HTXIEN_Msk
#define DMA_SCFG_TXCIEN_Pos                (4U)
#define DMA_SCFG_TXCIEN_Msk                (0x1UL << DMA_SCFG_TXCIEN_Pos)                /*!< 0x00000010 */
#define DMA_SCFG_TXCIEN                    DMA_SCFG_TXCIEN_Msk
#define DMA_SCFG_PERFC_Pos                 (5U)
#define DMA_SCFG_PERFC_Msk                 (0x1UL << DMA_SCFG_PERFC_Pos)                 /*!< 0x00000020 */
#define DMA_SCFG_PERFC                     DMA_SCFG_PERFC_Msk
#define DMA_SCFG_DIRCFG_Pos                (6U)
#define DMA_SCFG_DIRCFG_Msk                (0x3UL << DMA_SCFG_DIRCFG_Pos)                /*!< 0x000000C0 */
#define DMA_SCFG_DIRCFG                    DMA_SCFG_DIRCFG_Msk
#define DMA_SCFG_DIRCFG_0                  (0x1UL << DMA_SCFG_DIRCFG_Pos)                /*!< 0x00000040 */
#define DMA_SCFG_DIRCFG_1                  (0x2UL << DMA_SCFG_DIRCFG_Pos)                /*!< 0x00000080 */

#define DMA_SCFG_CIRCMEN_Pos               (8U)
#define DMA_SCFG_CIRCMEN_Msk               (0x1UL << DMA_SCFG_CIRCMEN_Pos)               /*!< 0x00000100 */
#define DMA_SCFG_CIRCMEN                   DMA_SCFG_CIRCMEN_Msk
#define DMA_SCFG_PERIM_Pos                 (9U)
#define DMA_SCFG_PERIM_Msk                 (0x1UL << DMA_SCFG_PERIM_Pos)                 /*!< 0x00000200 */
#define DMA_SCFG_PERIM                     DMA_SCFG_PERIM_Msk
#define DMA_SCFG_MEMIM_Pos                 (10U)
#define DMA_SCFG_MEMIM_Msk                 (0x1UL << DMA_SCFG_MEMIM_Pos)                 /*!< 0x00000400 */
#define DMA_SCFG_MEMIM                     DMA_SCFG_MEMIM_Msk
#define DMA_SCFG_PERSIZECFG_Pos            (11U)
#define DMA_SCFG_PERSIZECFG_Msk            (0x3UL << DMA_SCFG_PERSIZECFG_Pos)            /*!< 0x00001800 */
#define DMA_SCFG_PERSIZECFG                DMA_SCFG_PERSIZECFG_Msk
#define DMA_SCFG_PERSIZECFG_0              (0x1UL << DMA_SCFG_PERSIZECFG_Pos)            /*!< 0x00000800 */
#define DMA_SCFG_PERSIZECFG_1              (0x2UL << DMA_SCFG_PERSIZECFG_Pos)            /*!< 0x00001000 */

#define DMA_SCFG_MEMSIZECFG_Pos            (13U)
#define DMA_SCFG_MEMSIZECFG_Msk            (0x3UL << DMA_SCFG_MEMSIZECFG_Pos)            /*!< 0x00006000 */
#define DMA_SCFG_MEMSIZECFG                DMA_SCFG_MEMSIZECFG_Msk
#define DMA_SCFG_MEMSIZECFG_0              (0x1UL << DMA_SCFG_MEMSIZECFG_Pos)            /*!< 0x00002000 */
#define DMA_SCFG_MEMSIZECFG_1              (0x2UL << DMA_SCFG_MEMSIZECFG_Pos)            /*!< 0x00004000 */

#define DMA_SCFG_PERIOSIZE_Pos             (15U)
#define DMA_SCFG_PERIOSIZE_Msk             (0x1UL << DMA_SCFG_PERIOSIZE_Pos)             /*!< 0x00008000 */
#define DMA_SCFG_PERIOSIZE                 DMA_SCFG_PERIOSIZE_Msk
#define DMA_SCFG_PRILCFG_Pos               (16U)
#define DMA_SCFG_PRILCFG_Msk               (0x3UL << DMA_SCFG_PRILCFG_Pos)               /*!< 0x00030000 */
#define DMA_SCFG_PRILCFG                   DMA_SCFG_PRILCFG_Msk
#define DMA_SCFG_PRILCFG_0                 (0x1UL << DMA_SCFG_PRILCFG_Pos)               /*!< 0x00010000 */
#define DMA_SCFG_PRILCFG_1                 (0x2UL << DMA_SCFG_PRILCFG_Pos)               /*!< 0x00020000 */

#define DMA_SCFG_DBM_Pos                   (18U)
#define DMA_SCFG_DBM_Msk                   (0x1UL << DMA_SCFG_DBM_Pos)                   /*!< 0x00040000 */
#define DMA_SCFG_DBM                       DMA_SCFG_DBM_Msk
#define DMA_SCFG_CTARG_Pos                 (19U)
#define DMA_SCFG_CTARG_Msk                 (0x1UL << DMA_SCFG_CTARG_Pos)                 /*!< 0x00080000 */
#define DMA_SCFG_CTARG                     DMA_SCFG_CTARG_Msk
#define DMA_SCFG_PBCFG_Pos                 (21U)
#define DMA_SCFG_PBCFG_Msk                 (0x3UL << DMA_SCFG_PBCFG_Pos)                 /*!< 0x00600000 */
#define DMA_SCFG_PBCFG                     DMA_SCFG_PBCFG_Msk
#define DMA_SCFG_PBCFG_0                   (0x1UL << DMA_SCFG_PBCFG_Pos)                 /*!< 0x00200000 */
#define DMA_SCFG_PBCFG_1                   (0x2UL << DMA_SCFG_PBCFG_Pos)                 /*!< 0x00400000 */

#define DMA_SCFG_MBCFG_Pos                 (23U)
#define DMA_SCFG_MBCFG_Msk                 (0x3UL << DMA_SCFG_MBCFG_Pos)                 /*!< 0x01800000 */
#define DMA_SCFG_MBCFG                     DMA_SCFG_MBCFG_Msk
#define DMA_SCFG_MBCFG_0                   (0x1UL << DMA_SCFG_MBCFG_Pos)                 /*!< 0x00800000 */
#define DMA_SCFG_MBCFG_1                   (0x2UL << DMA_SCFG_MBCFG_Pos)                 /*!< 0x01000000 */

#define DMA_SCFG_CHSEL_Pos                 (25U)
#define DMA_SCFG_CHSEL_Msk                 (0x7UL << DMA_SCFG_CHSEL_Pos)                 /*!< 0x0E000000 */
#define DMA_SCFG_CHSEL                     DMA_SCFG_CHSEL_Msk
#define DMA_SCFG_CHSEL_0                   (0x1UL << DMA_SCFG_CHSEL_Pos)
#define DMA_SCFG_CHSEL_1                   (0x2UL << DMA_SCFG_CHSEL_Pos)
#define DMA_SCFG_CHSEL_2                   (0x4UL << DMA_SCFG_CHSEL_Pos)

/********************  Bits definition for DMA_NDATA register  ****************/
#define DMA_NDATA_NDATA_Pos                (0U)
#define DMA_NDATA_NDATA_Msk                (0xFFFFUL << DMA_NDATA_NDATA_Pos)             /*!< 0x0000FFFF */
#define DMA_NDATA_NDATA                    DMA_NDATA_NDATA_Msk

/******************  Bit definition for DMA_PADDR register  *******************/
#define DMA_PADDR_PADDR_Pos                (0U)
#define DMA_PADDR_PADDR_Msk                (0xFFFFFFFFUL << DMA_PADDR_PADDR_Pos)         /*!< 0xFFFFFFFF */
#define DMA_PADDR_PADDR                    DMA_PADDR_PADDR_Msk                           /*!< Peripheral Address */

/******************  Bit definition for DMA_M0ADDR register  ******************/
#define DMA_M0ADDR_M0ADDR_Pos              (0U)
#define DMA_M0ADDR_M0ADDR_Msk              (0xFFFFFFFFUL << DMA_M0ADDR_M0ADDR_Pos)       /*!< 0xFFFFFFFF */
#define DMA_M0ADDR_M0ADDR                  DMA_M0ADDR_M0ADDR_Msk                         /*!< Memory Address */

/******************  Bit definition for DMA_M1ADDR register  ******************/
#define DMA_M1ADDR_M1ADDR_Pos              (0U)
#define DMA_M1ADDR_M1ADDR_Msk              (0xFFFFFFFFUL << DMA_M1ADDR_M1ADDR_Pos)       /*!< 0xFFFFFFFF */
#define DMA_M1ADDR_M1ADDR                  DMA_M1ADDR_M1ADDR_Msk                         /*!< Memory Address */

/********************  Bits definition for DMA_FCTRL register  ****************/
#define DMA_FCTRL_FTHSEL_Pos               (0U)
#define DMA_FCTRL_FTHSEL_Msk               (0x3UL << DMA_FCTRL_FTHSEL_Pos)               /*!< 0x00000003 */
#define DMA_FCTRL_FTHSEL                   DMA_FCTRL_FTHSEL_Msk
#define DMA_FCTRL_FTHSEL_0                 (0x1UL << DMA_FCTRL_FTHSEL_Pos)               /*!< 0x00000001 */
#define DMA_FCTRL_FTHSEL_1                 (0x2UL << DMA_FCTRL_FTHSEL_Pos)               /*!< 0x00000000 */

#define DMA_FCTRL_DMDEN_Pos                (2U)
#define DMA_FCTRL_DMDEN_Msk                (0x1UL << DMA_FCTRL_DMDEN_Pos)                /*!< 0x00000004 */
#define DMA_FCTRL_DMDEN                    DMA_FCTRL_DMDEN_Msk
#define DMA_FCTRL_FSTS_Pos                 (3U)
#define DMA_FCTRL_FSTS_Msk                 (0x7UL << DMA_FCTRL_FSTS_Pos)                 /*!< 0x00000038 */
#define DMA_FCTRL_FSTS                     DMA_FCTRL_FSTS_Msk
#define DMA_FCTRL_FSTS_0                   (0x1UL << DMA_FCTRL_FSTS_Pos)                 /*!< 0x00000008 */
#define DMA_FCTRL_FSTS_1                   (0x2UL << DMA_FCTRL_FSTS_Pos)                 /*!< 0x00000010 */
#define DMA_FCTRL_FSTS_2                   (0x4UL << DMA_FCTRL_FSTS_Pos)                 /*!< 0x00000020 */

#define DMA_FCTRL_FEIEN_Pos                (7U)
#define DMA_FCTRL_FEIEN_Msk                (0x1UL << DMA_FCTRL_FEIEN_Pos)                /*!< 0x00000080 */
#define DMA_FCTRL_FEIEN                    DMA_FCTRL_FEIEN_Msk

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EINT_IMASK register  *****************/
#define EINT_IMASK_IMASK0_Pos              (0U)
#define EINT_IMASK_IMASK0_Msk              (0x1UL << EINT_IMASK_IMASK0_Pos)              /*!< 0x00000001 */
#define EINT_IMASK_IMASK0                  EINT_IMASK_IMASK0_Msk                         /*!< Interrupt Mask on line 0 */
#define EINT_IMASK_IMASK1_Pos              (1U)
#define EINT_IMASK_IMASK1_Msk              (0x1UL << EINT_IMASK_IMASK1_Pos)              /*!< 0x00000000 */
#define EINT_IMASK_IMASK1                  EINT_IMASK_IMASK1_Msk                         /*!< Interrupt Mask on line 1 */
#define EINT_IMASK_IMASK2_Pos              (2U)
#define EINT_IMASK_IMASK2_Msk              (0x1UL << EINT_IMASK_IMASK2_Pos)              /*!< 0x00000004 */
#define EINT_IMASK_IMASK2                  EINT_IMASK_IMASK2_Msk                         /*!< Interrupt Mask on line 2 */
#define EINT_IMASK_IMASK3_Pos              (3U)
#define EINT_IMASK_IMASK3_Msk              (0x1UL << EINT_IMASK_IMASK3_Pos)              /*!< 0x00000008 */
#define EINT_IMASK_IMASK3                  EINT_IMASK_IMASK3_Msk                         /*!< Interrupt Mask on line 3 */
#define EINT_IMASK_IMASK4_Pos              (4U)
#define EINT_IMASK_IMASK4_Msk              (0x1UL << EINT_IMASK_IMASK4_Pos)              /*!< 0x00000010 */
#define EINT_IMASK_IMASK4                  EINT_IMASK_IMASK4_Msk                         /*!< Interrupt Mask on line 4 */
#define EINT_IMASK_IMASK5_Pos              (5U)
#define EINT_IMASK_IMASK5_Msk              (0x1UL << EINT_IMASK_IMASK5_Pos)              /*!< 0x00000020 */
#define EINT_IMASK_IMASK5                  EINT_IMASK_IMASK5_Msk                         /*!< Interrupt Mask on line 5 */
#define EINT_IMASK_IMASK6_Pos              (6U)
#define EINT_IMASK_IMASK6_Msk              (0x1UL << EINT_IMASK_IMASK6_Pos)              /*!< 0x00000040 */
#define EINT_IMASK_IMASK6                  EINT_IMASK_IMASK6_Msk                         /*!< Interrupt Mask on line 6 */
#define EINT_IMASK_IMASK7_Pos              (7U)
#define EINT_IMASK_IMASK7_Msk              (0x1UL << EINT_IMASK_IMASK7_Pos)              /*!< 0x00000080 */
#define EINT_IMASK_IMASK7                  EINT_IMASK_IMASK7_Msk                         /*!< Interrupt Mask on line 7 */
#define EINT_IMASK_IMASK8_Pos              (8U)
#define EINT_IMASK_IMASK8_Msk              (0x1UL << EINT_IMASK_IMASK8_Pos)              /*!< 0x00000100 */
#define EINT_IMASK_IMASK8                  EINT_IMASK_IMASK8_Msk                         /*!< Interrupt Mask on line 8 */
#define EINT_IMASK_IMASK9_Pos              (9U)
#define EINT_IMASK_IMASK9_Msk              (0x1UL << EINT_IMASK_IMASK9_Pos)              /*!< 0x00000200 */
#define EINT_IMASK_IMASK9                  EINT_IMASK_IMASK9_Msk                         /*!< Interrupt Mask on line 9 */
#define EINT_IMASK_IMASK10_Pos             (10U)
#define EINT_IMASK_IMASK10_Msk             (0x1UL << EINT_IMASK_IMASK10_Pos)             /*!< 0x00000400 */
#define EINT_IMASK_IMASK10                 EINT_IMASK_IMASK10_Msk                        /*!< Interrupt Mask on line 10 */
#define EINT_IMASK_IMASK11_Pos             (11U)
#define EINT_IMASK_IMASK11_Msk             (0x1UL << EINT_IMASK_IMASK11_Pos)             /*!< 0x00000800 */
#define EINT_IMASK_IMASK11                 EINT_IMASK_IMASK11_Msk                        /*!< Interrupt Mask on line 11 */
#define EINT_IMASK_IMASK12_Pos             (12U)
#define EINT_IMASK_IMASK12_Msk             (0x1UL << EINT_IMASK_IMASK12_Pos)             /*!< 0x00001000 */
#define EINT_IMASK_IMASK12                 EINT_IMASK_IMASK12_Msk                        /*!< Interrupt Mask on line 12 */
#define EINT_IMASK_IMASK13_Pos             (13U)
#define EINT_IMASK_IMASK13_Msk             (0x1UL << EINT_IMASK_IMASK13_Pos)             /*!< 0x00002000 */
#define EINT_IMASK_IMASK13                 EINT_IMASK_IMASK13_Msk                        /*!< Interrupt Mask on line 13 */
#define EINT_IMASK_IMASK14_Pos             (14U)
#define EINT_IMASK_IMASK14_Msk             (0x1UL << EINT_IMASK_IMASK14_Pos)             /*!< 0x00004000 */
#define EINT_IMASK_IMASK14                 EINT_IMASK_IMASK14_Msk                        /*!< Interrupt Mask on line 14 */
#define EINT_IMASK_IMASK15_Pos             (15U)
#define EINT_IMASK_IMASK15_Msk             (0x1UL << EINT_IMASK_IMASK15_Pos)             /*!< 0x00008000 */
#define EINT_IMASK_IMASK15                 EINT_IMASK_IMASK15_Msk                        /*!< Interrupt Mask on line 15 */
#define EINT_IMASK_IMASK16_Pos             (16U)
#define EINT_IMASK_IMASK16_Msk             (0x1UL << EINT_IMASK_IMASK16_Pos)             /*!< 0x00010000 */
#define EINT_IMASK_IMASK16                 EINT_IMASK_IMASK16_Msk                        /*!< Interrupt Mask on line 16 */
#define EINT_IMASK_IMASK17_Pos             (17U)
#define EINT_IMASK_IMASK17_Msk             (0x1UL << EINT_IMASK_IMASK17_Pos)             /*!< 0x00020000 */
#define EINT_IMASK_IMASK17                 EINT_IMASK_IMASK17_Msk                        /*!< Interrupt Mask on line 17 */
#define EINT_IMASK_IMASK18_Pos             (18U)
#define EINT_IMASK_IMASK18_Msk             (0x1UL << EINT_IMASK_IMASK18_Pos)             /*!< 0x00040000 */
#define EINT_IMASK_IMASK18                 EINT_IMASK_IMASK18_Msk                        /*!< Interrupt Mask on line 18 */
#define EINT_IMASK_IMASK19_Pos             (19U)
#define EINT_IMASK_IMASK19_Msk             (0x1UL << EINT_IMASK_IMASK19_Pos)             /*!< 0x00080000 */
#define EINT_IMASK_IMASK19                 EINT_IMASK_IMASK19_Msk                        /*!< Interrupt Mask on line 19 */
#define EINT_IMASK_IMASK20_Pos             (20U)
#define EINT_IMASK_IMASK20_Msk             (0x1UL << EINT_IMASK_IMASK20_Pos)             /*!< 0x00100000 */
#define EINT_IMASK_IMASK20                 EINT_IMASK_IMASK20_Msk                        /*!< Interrupt Mask on line 20 */
#define EINT_IMASK_IMASK21_Pos             (21U)
#define EINT_IMASK_IMASK21_Msk             (0x1UL << EINT_IMASK_IMASK21_Pos)             /*!< 0x00200000 */
#define EINT_IMASK_IMASK21                 EINT_IMASK_IMASK21_Msk                        /*!< Interrupt Mask on line 21 */
#define EINT_IMASK_IMASK22_Pos             (22U)
#define EINT_IMASK_IMASK22_Msk             (0x1UL << EINT_IMASK_IMASK22_Pos)             /*!< 0x00400000 */
#define EINT_IMASK_IMASK22                 EINT_IMASK_IMASK22_Msk                        /*!< Interrupt Mask on line 22 */

/* Reference Defines */
#define EINT_IMASK_IM0                     EINT_IMASK_IMASK0
#define EINT_IMASK_IM1                     EINT_IMASK_IMASK1
#define EINT_IMASK_IM2                     EINT_IMASK_IMASK2
#define EINT_IMASK_IM3                     EINT_IMASK_IMASK3
#define EINT_IMASK_IM4                     EINT_IMASK_IMASK4
#define EINT_IMASK_IM5                     EINT_IMASK_IMASK5
#define EINT_IMASK_IM6                     EINT_IMASK_IMASK6
#define EINT_IMASK_IM7                     EINT_IMASK_IMASK7
#define EINT_IMASK_IM8                     EINT_IMASK_IMASK8
#define EINT_IMASK_IM9                     EINT_IMASK_IMASK9
#define EINT_IMASK_IM10                    EINT_IMASK_IMASK10
#define EINT_IMASK_IM11                    EINT_IMASK_IMASK11
#define EINT_IMASK_IM12                    EINT_IMASK_IMASK12
#define EINT_IMASK_IM13                    EINT_IMASK_IMASK13
#define EINT_IMASK_IM14                    EINT_IMASK_IMASK14
#define EINT_IMASK_IM15                    EINT_IMASK_IMASK15
#define EINT_IMASK_IM16                    EINT_IMASK_IMASK16
#define EINT_IMASK_IM17                    EINT_IMASK_IMASK17
#define EINT_IMASK_IM18                    EINT_IMASK_IMASK18
#define EINT_IMASK_IM19                    EINT_IMASK_IMASK19
#define EINT_IMASK_IM20                    EINT_IMASK_IMASK20
#define EINT_IMASK_IM21                    EINT_IMASK_IMASK21
#define EINT_IMASK_IM22                    EINT_IMASK_IMASK22
#define EINT_IMASK_IM_Pos                  (0U)
#define EINT_IMASK_IM_Msk                  (0x7FFFFFUL << EINT_IMASK_IM_Pos)             /*!< 0x007FFFFF */
#define EINT_IMASK_IM                      EINT_IMASK_IM_Msk                             /*!< Interrupt Mask All */

/*******************  Bit definition for EINT_EMASK register  *****************/
#define EINT_EMASK_EMASK0_Pos              (0U)
#define EINT_EMASK_EMASK0_Msk              (0x1UL << EINT_EMASK_EMASK0_Pos)              /*!< 0x00000001 */
#define EINT_EMASK_EMASK0                  EINT_EMASK_EMASK0_Msk                         /*!< Event Mask on line 0 */
#define EINT_EMASK_EMASK1_Pos              (1U)
#define EINT_EMASK_EMASK1_Msk              (0x1UL << EINT_EMASK_EMASK1_Pos)              /*!< 0x00000000 */
#define EINT_EMASK_EMASK1                  EINT_EMASK_EMASK1_Msk                         /*!< Event Mask on line 1 */
#define EINT_EMASK_EMASK2_Pos              (2U)
#define EINT_EMASK_EMASK2_Msk              (0x1UL << EINT_EMASK_EMASK2_Pos)              /*!< 0x00000004 */
#define EINT_EMASK_EMASK2                  EINT_EMASK_EMASK2_Msk                         /*!< Event Mask on line 2 */
#define EINT_EMASK_EMASK3_Pos              (3U)
#define EINT_EMASK_EMASK3_Msk              (0x1UL << EINT_EMASK_EMASK3_Pos)              /*!< 0x00000008 */
#define EINT_EMASK_EMASK3                  EINT_EMASK_EMASK3_Msk                         /*!< Event Mask on line 3 */
#define EINT_EMASK_EMASK4_Pos              (4U)
#define EINT_EMASK_EMASK4_Msk              (0x1UL << EINT_EMASK_EMASK4_Pos)              /*!< 0x00000010 */
#define EINT_EMASK_EMASK4                  EINT_EMASK_EMASK4_Msk                         /*!< Event Mask on line 4 */
#define EINT_EMASK_EMASK5_Pos              (5U)
#define EINT_EMASK_EMASK5_Msk              (0x1UL << EINT_EMASK_EMASK5_Pos)              /*!< 0x00000020 */
#define EINT_EMASK_EMASK5                  EINT_EMASK_EMASK5_Msk                         /*!< Event Mask on line 5 */
#define EINT_EMASK_EMASK6_Pos              (6U)
#define EINT_EMASK_EMASK6_Msk              (0x1UL << EINT_EMASK_EMASK6_Pos)              /*!< 0x00000040 */
#define EINT_EMASK_EMASK6                  EINT_EMASK_EMASK6_Msk                         /*!< Event Mask on line 6 */
#define EINT_EMASK_EMASK7_Pos              (7U)
#define EINT_EMASK_EMASK7_Msk              (0x1UL << EINT_EMASK_EMASK7_Pos)              /*!< 0x00000080 */
#define EINT_EMASK_EMASK7                  EINT_EMASK_EMASK7_Msk                         /*!< Event Mask on line 7 */
#define EINT_EMASK_EMASK8_Pos              (8U)
#define EINT_EMASK_EMASK8_Msk              (0x1UL << EINT_EMASK_EMASK8_Pos)              /*!< 0x00000100 */
#define EINT_EMASK_EMASK8                  EINT_EMASK_EMASK8_Msk                         /*!< Event Mask on line 8 */
#define EINT_EMASK_EMASK9_Pos              (9U)
#define EINT_EMASK_EMASK9_Msk              (0x1UL << EINT_EMASK_EMASK9_Pos)              /*!< 0x00000200 */
#define EINT_EMASK_EMASK9                  EINT_EMASK_EMASK9_Msk                         /*!< Event Mask on line 9 */
#define EINT_EMASK_EMASK10_Pos             (10U)
#define EINT_EMASK_EMASK10_Msk             (0x1UL << EINT_EMASK_EMASK10_Pos)             /*!< 0x00000400 */
#define EINT_EMASK_EMASK10                 EINT_EMASK_EMASK10_Msk                        /*!< Event Mask on line 10 */
#define EINT_EMASK_EMASK11_Pos             (11U)
#define EINT_EMASK_EMASK11_Msk             (0x1UL << EINT_EMASK_EMASK11_Pos)             /*!< 0x00000800 */
#define EINT_EMASK_EMASK11                 EINT_EMASK_EMASK11_Msk                        /*!< Event Mask on line 11 */
#define EINT_EMASK_EMASK12_Pos             (12U)
#define EINT_EMASK_EMASK12_Msk             (0x1UL << EINT_EMASK_EMASK12_Pos)             /*!< 0x00001000 */
#define EINT_EMASK_EMASK12                 EINT_EMASK_EMASK12_Msk                        /*!< Event Mask on line 12 */
#define EINT_EMASK_EMASK13_Pos             (13U)
#define EINT_EMASK_EMASK13_Msk             (0x1UL << EINT_EMASK_EMASK13_Pos)             /*!< 0x00002000 */
#define EINT_EMASK_EMASK13                 EINT_EMASK_EMASK13_Msk                        /*!< Event Mask on line 13 */
#define EINT_EMASK_EMASK14_Pos             (14U)
#define EINT_EMASK_EMASK14_Msk             (0x1UL << EINT_EMASK_EMASK14_Pos)             /*!< 0x00004000 */
#define EINT_EMASK_EMASK14                 EINT_EMASK_EMASK14_Msk                        /*!< Event Mask on line 14 */
#define EINT_EMASK_EMASK15_Pos             (15U)
#define EINT_EMASK_EMASK15_Msk             (0x1UL << EINT_EMASK_EMASK15_Pos)             /*!< 0x00008000 */
#define EINT_EMASK_EMASK15                 EINT_EMASK_EMASK15_Msk                        /*!< Event Mask on line 15 */
#define EINT_EMASK_EMASK16_Pos             (16U)
#define EINT_EMASK_EMASK16_Msk             (0x1UL << EINT_EMASK_EMASK16_Pos)             /*!< 0x00010000 */
#define EINT_EMASK_EMASK16                 EINT_EMASK_EMASK16_Msk                        /*!< Event Mask on line 16 */
#define EINT_EMASK_EMASK17_Pos             (17U)
#define EINT_EMASK_EMASK17_Msk             (0x1UL << EINT_EMASK_EMASK17_Pos)             /*!< 0x00020000 */
#define EINT_EMASK_EMASK17                 EINT_EMASK_EMASK17_Msk                        /*!< Event Mask on line 17 */
#define EINT_EMASK_EMASK18_Pos             (18U)
#define EINT_EMASK_EMASK18_Msk             (0x1UL << EINT_EMASK_EMASK18_Pos)             /*!< 0x00040000 */
#define EINT_EMASK_EMASK18                 EINT_EMASK_EMASK18_Msk                        /*!< Event Mask on line 18 */
#define EINT_EMASK_EMASK19_Pos             (19U)
#define EINT_EMASK_EMASK19_Msk             (0x1UL << EINT_EMASK_EMASK19_Pos)             /*!< 0x00080000 */
#define EINT_EMASK_EMASK19                 EINT_EMASK_EMASK19_Msk                        /*!< Event Mask on line 19 */
#define EINT_EMASK_EMASK20_Pos             (20U)
#define EINT_EMASK_EMASK20_Msk             (0x1UL << EINT_EMASK_EMASK20_Pos)             /*!< 0x00100000 */
#define EINT_EMASK_EMASK20                 EINT_EMASK_EMASK20_Msk                        /*!< Event Mask on line 20 */
#define EINT_EMASK_EMASK21_Pos             (21U)
#define EINT_EMASK_EMASK21_Msk             (0x1UL << EINT_EMASK_EMASK21_Pos)             /*!< 0x00200000 */
#define EINT_EMASK_EMASK21                 EINT_EMASK_EMASK21_Msk                        /*!< Event Mask on line 21 */
#define EINT_EMASK_EMASK22_Pos             (22U)
#define EINT_EMASK_EMASK22_Msk             (0x1UL << EINT_EMASK_EMASK22_Pos)             /*!< 0x00400000 */
#define EINT_EMASK_EMASK22                 EINT_EMASK_EMASK22_Msk                        /*!< Event Mask on line 22 */

/* Reference Defines */
#define EINT_EMASK_EM0                     EINT_EMASK_EMASK0
#define EINT_EMASK_EM1                     EINT_EMASK_EMASK1
#define EINT_EMASK_EM2                     EINT_EMASK_EMASK2
#define EINT_EMASK_EM3                     EINT_EMASK_EMASK3
#define EINT_EMASK_EM4                     EINT_EMASK_EMASK4
#define EINT_EMASK_EM5                     EINT_EMASK_EMASK5
#define EINT_EMASK_EM6                     EINT_EMASK_EMASK6
#define EINT_EMASK_EM7                     EINT_EMASK_EMASK7
#define EINT_EMASK_EM8                     EINT_EMASK_EMASK8
#define EINT_EMASK_EM9                     EINT_EMASK_EMASK9
#define EINT_EMASK_EM10                    EINT_EMASK_EMASK10
#define EINT_EMASK_EM11                    EINT_EMASK_EMASK11
#define EINT_EMASK_EM12                    EINT_EMASK_EMASK12
#define EINT_EMASK_EM13                    EINT_EMASK_EMASK13
#define EINT_EMASK_EM14                    EINT_EMASK_EMASK14
#define EINT_EMASK_EM15                    EINT_EMASK_EMASK15
#define EINT_EMASK_EM16                    EINT_EMASK_EMASK16
#define EINT_EMASK_EM17                    EINT_EMASK_EMASK17
#define EINT_EMASK_EM18                    EINT_EMASK_EMASK18
#define EINT_EMASK_EM19                    EINT_EMASK_EMASK19
#define EINT_EMASK_EM20                    EINT_EMASK_EMASK20
#define EINT_EMASK_EM21                    EINT_EMASK_EMASK21
#define EINT_EMASK_EM22                    EINT_EMASK_EMASK22

/******************  Bit definition for EINT_RTEN register  *******************/
#define EINT_RTEN_RTEN0_Pos                (0U)
#define EINT_RTEN_RTEN0_Msk                (0x1UL << EINT_RTEN_RTEN0_Pos)                /*!< 0x00000001 */
#define EINT_RTEN_RTEN0                    EINT_RTEN_RTEN0_Msk                           /*!< Rising trigger event configuration bit of line 0 */
#define EINT_RTEN_RTEN1_Pos                (1U)
#define EINT_RTEN_RTEN1_Msk                (0x1UL << EINT_RTEN_RTEN1_Pos)                /*!< 0x00000000 */
#define EINT_RTEN_RTEN1                    EINT_RTEN_RTEN1_Msk                           /*!< Rising trigger event configuration bit of line 1 */
#define EINT_RTEN_RTEN2_Pos                (2U)
#define EINT_RTEN_RTEN2_Msk                (0x1UL << EINT_RTEN_RTEN2_Pos)                /*!< 0x00000004 */
#define EINT_RTEN_RTEN2                    EINT_RTEN_RTEN2_Msk                           /*!< Rising trigger event configuration bit of line 2 */
#define EINT_RTEN_RTEN3_Pos                (3U)
#define EINT_RTEN_RTEN3_Msk                (0x1UL << EINT_RTEN_RTEN3_Pos)                /*!< 0x00000008 */
#define EINT_RTEN_RTEN3                    EINT_RTEN_RTEN3_Msk                           /*!< Rising trigger event configuration bit of line 3 */
#define EINT_RTEN_RTEN4_Pos                (4U)
#define EINT_RTEN_RTEN4_Msk                (0x1UL << EINT_RTEN_RTEN4_Pos)                /*!< 0x00000010 */
#define EINT_RTEN_RTEN4                    EINT_RTEN_RTEN4_Msk                           /*!< Rising trigger event configuration bit of line 4 */
#define EINT_RTEN_RTEN5_Pos                (5U)
#define EINT_RTEN_RTEN5_Msk                (0x1UL << EINT_RTEN_RTEN5_Pos)                /*!< 0x00000020 */
#define EINT_RTEN_RTEN5                    EINT_RTEN_RTEN5_Msk                           /*!< Rising trigger event configuration bit of line 5 */
#define EINT_RTEN_RTEN6_Pos                (6U)
#define EINT_RTEN_RTEN6_Msk                (0x1UL << EINT_RTEN_RTEN6_Pos)                /*!< 0x00000040 */
#define EINT_RTEN_RTEN6                    EINT_RTEN_RTEN6_Msk                           /*!< Rising trigger event configuration bit of line 6 */
#define EINT_RTEN_RTEN7_Pos                (7U)
#define EINT_RTEN_RTEN7_Msk                (0x1UL << EINT_RTEN_RTEN7_Pos)                /*!< 0x00000080 */
#define EINT_RTEN_RTEN7                    EINT_RTEN_RTEN7_Msk                           /*!< Rising trigger event configuration bit of line 7 */
#define EINT_RTEN_RTEN8_Pos                (8U)
#define EINT_RTEN_RTEN8_Msk                (0x1UL << EINT_RTEN_RTEN8_Pos)                /*!< 0x00000100 */
#define EINT_RTEN_RTEN8                    EINT_RTEN_RTEN8_Msk                           /*!< Rising trigger event configuration bit of line 8 */
#define EINT_RTEN_RTEN9_Pos                (9U)
#define EINT_RTEN_RTEN9_Msk                (0x1UL << EINT_RTEN_RTEN9_Pos)                /*!< 0x00000200 */
#define EINT_RTEN_RTEN9                    EINT_RTEN_RTEN9_Msk                           /*!< Rising trigger event configuration bit of line 9 */
#define EINT_RTEN_RTEN10_Pos               (10U)
#define EINT_RTEN_RTEN10_Msk               (0x1UL << EINT_RTEN_RTEN10_Pos)               /*!< 0x00000400 */
#define EINT_RTEN_RTEN10                   EINT_RTEN_RTEN10_Msk                          /*!< Rising trigger event configuration bit of line 10 */
#define EINT_RTEN_RTEN11_Pos               (11U)
#define EINT_RTEN_RTEN11_Msk               (0x1UL << EINT_RTEN_RTEN11_Pos)               /*!< 0x00000800 */
#define EINT_RTEN_RTEN11                   EINT_RTEN_RTEN11_Msk                          /*!< Rising trigger event configuration bit of line 11 */
#define EINT_RTEN_RTEN12_Pos               (12U)
#define EINT_RTEN_RTEN12_Msk               (0x1UL << EINT_RTEN_RTEN12_Pos)               /*!< 0x00001000 */
#define EINT_RTEN_RTEN12                   EINT_RTEN_RTEN12_Msk                          /*!< Rising trigger event configuration bit of line 12 */
#define EINT_RTEN_RTEN13_Pos               (13U)
#define EINT_RTEN_RTEN13_Msk               (0x1UL << EINT_RTEN_RTEN13_Pos)               /*!< 0x00002000 */
#define EINT_RTEN_RTEN13                   EINT_RTEN_RTEN13_Msk                          /*!< Rising trigger event configuration bit of line 13 */
#define EINT_RTEN_RTEN14_Pos               (14U)
#define EINT_RTEN_RTEN14_Msk               (0x1UL << EINT_RTEN_RTEN14_Pos)               /*!< 0x00004000 */
#define EINT_RTEN_RTEN14                   EINT_RTEN_RTEN14_Msk                          /*!< Rising trigger event configuration bit of line 14 */
#define EINT_RTEN_RTEN15_Pos               (15U)
#define EINT_RTEN_RTEN15_Msk               (0x1UL << EINT_RTEN_RTEN15_Pos)               /*!< 0x00008000 */
#define EINT_RTEN_RTEN15                   EINT_RTEN_RTEN15_Msk                          /*!< Rising trigger event configuration bit of line 15 */
#define EINT_RTEN_RTEN16_Pos               (16U)
#define EINT_RTEN_RTEN16_Msk               (0x1UL << EINT_RTEN_RTEN16_Pos)               /*!< 0x00010000 */
#define EINT_RTEN_RTEN16                   EINT_RTEN_RTEN16_Msk                          /*!< Rising trigger event configuration bit of line 16 */
#define EINT_RTEN_RTEN17_Pos               (17U)
#define EINT_RTEN_RTEN17_Msk               (0x1UL << EINT_RTEN_RTEN17_Pos)               /*!< 0x00020000 */
#define EINT_RTEN_RTEN17                   EINT_RTEN_RTEN17_Msk                          /*!< Rising trigger event configuration bit of line 17 */
#define EINT_RTEN_RTEN18_Pos               (18U)
#define EINT_RTEN_RTEN18_Msk               (0x1UL << EINT_RTEN_RTEN18_Pos)               /*!< 0x00040000 */
#define EINT_RTEN_RTEN18                   EINT_RTEN_RTEN18_Msk                          /*!< Rising trigger event configuration bit of line 18 */
#define EINT_RTEN_RTEN19_Pos               (19U)
#define EINT_RTEN_RTEN19_Msk               (0x1UL << EINT_RTEN_RTEN19_Pos)               /*!< 0x00080000 */
#define EINT_RTEN_RTEN19                   EINT_RTEN_RTEN19_Msk                          /*!< Rising trigger event configuration bit of line 19 */
#define EINT_RTEN_RTEN20_Pos               (20U)
#define EINT_RTEN_RTEN20_Msk               (0x1UL << EINT_RTEN_RTEN20_Pos)               /*!< 0x00100000 */
#define EINT_RTEN_RTEN20                   EINT_RTEN_RTEN20_Msk                          /*!< Rising trigger event configuration bit of line 20 */
#define EINT_RTEN_RTEN21_Pos               (21U)
#define EINT_RTEN_RTEN21_Msk               (0x1UL << EINT_RTEN_RTEN21_Pos)               /*!< 0x00200000 */
#define EINT_RTEN_RTEN21                   EINT_RTEN_RTEN21_Msk                          /*!< Rising trigger event configuration bit of line 21 */
#define EINT_RTEN_RTEN22_Pos               (22U)
#define EINT_RTEN_RTEN22_Msk               (0x1UL << EINT_RTEN_RTEN22_Pos)               /*!< 0x00400000 */
#define EINT_RTEN_RTEN22                   EINT_RTEN_RTEN22_Msk                          /*!< Rising trigger event configuration bit of line 22 */

/******************  Bit definition for EINT_FTEN register  *******************/
#define EINT_FTEN_FTEN0_Pos                (0U)
#define EINT_FTEN_FTEN0_Msk                (0x1UL << EINT_FTEN_FTEN0_Pos)                /*!< 0x00000001 */
#define EINT_FTEN_FTEN0                    EINT_FTEN_FTEN0_Msk                           /*!< Falling trigger event configuration bit of line 0 */
#define EINT_FTEN_FTEN1_Pos                (1U)
#define EINT_FTEN_FTEN1_Msk                (0x1UL << EINT_FTEN_FTEN1_Pos)                /*!< 0x00000000 */
#define EINT_FTEN_FTEN1                    EINT_FTEN_FTEN1_Msk                           /*!< Falling trigger event configuration bit of line 1 */
#define EINT_FTEN_FTEN2_Pos                (2U)
#define EINT_FTEN_FTEN2_Msk                (0x1UL << EINT_FTEN_FTEN2_Pos)                /*!< 0x00000004 */
#define EINT_FTEN_FTEN2                    EINT_FTEN_FTEN2_Msk                           /*!< Falling trigger event configuration bit of line 2 */
#define EINT_FTEN_FTEN3_Pos                (3U)
#define EINT_FTEN_FTEN3_Msk                (0x1UL << EINT_FTEN_FTEN3_Pos)                /*!< 0x00000008 */
#define EINT_FTEN_FTEN3                    EINT_FTEN_FTEN3_Msk                           /*!< Falling trigger event configuration bit of line 3 */
#define EINT_FTEN_FTEN4_Pos                (4U)
#define EINT_FTEN_FTEN4_Msk                (0x1UL << EINT_FTEN_FTEN4_Pos)                /*!< 0x00000010 */
#define EINT_FTEN_FTEN4                    EINT_FTEN_FTEN4_Msk                           /*!< Falling trigger event configuration bit of line 4 */
#define EINT_FTEN_FTEN5_Pos                (5U)
#define EINT_FTEN_FTEN5_Msk                (0x1UL << EINT_FTEN_FTEN5_Pos)                /*!< 0x00000020 */
#define EINT_FTEN_FTEN5                    EINT_FTEN_FTEN5_Msk                           /*!< Falling trigger event configuration bit of line 5 */
#define EINT_FTEN_FTEN6_Pos                (6U)
#define EINT_FTEN_FTEN6_Msk                (0x1UL << EINT_FTEN_FTEN6_Pos)                /*!< 0x00000040 */
#define EINT_FTEN_FTEN6                    EINT_FTEN_FTEN6_Msk                           /*!< Falling trigger event configuration bit of line 6 */
#define EINT_FTEN_FTEN7_Pos                (7U)
#define EINT_FTEN_FTEN7_Msk                (0x1UL << EINT_FTEN_FTEN7_Pos)                /*!< 0x00000080 */
#define EINT_FTEN_FTEN7                    EINT_FTEN_FTEN7_Msk                           /*!< Falling trigger event configuration bit of line 7 */
#define EINT_FTEN_FTEN8_Pos                (8U)
#define EINT_FTEN_FTEN8_Msk                (0x1UL << EINT_FTEN_FTEN8_Pos)                /*!< 0x00000100 */
#define EINT_FTEN_FTEN8                    EINT_FTEN_FTEN8_Msk                           /*!< Falling trigger event configuration bit of line 8 */
#define EINT_FTEN_FTEN9_Pos                (9U)
#define EINT_FTEN_FTEN9_Msk                (0x1UL << EINT_FTEN_FTEN9_Pos)                /*!< 0x00000200 */
#define EINT_FTEN_FTEN9                    EINT_FTEN_FTEN9_Msk                           /*!< Falling trigger event configuration bit of line 9 */
#define EINT_FTEN_FTEN10_Pos               (10U)
#define EINT_FTEN_FTEN10_Msk               (0x1UL << EINT_FTEN_FTEN10_Pos)               /*!< 0x00000400 */
#define EINT_FTEN_FTEN10                   EINT_FTEN_FTEN10_Msk                          /*!< Falling trigger event configuration bit of line 10 */
#define EINT_FTEN_FTEN11_Pos               (11U)
#define EINT_FTEN_FTEN11_Msk               (0x1UL << EINT_FTEN_FTEN11_Pos)               /*!< 0x00000800 */
#define EINT_FTEN_FTEN11                   EINT_FTEN_FTEN11_Msk                          /*!< Falling trigger event configuration bit of line 11 */
#define EINT_FTEN_FTEN12_Pos               (12U)
#define EINT_FTEN_FTEN12_Msk               (0x1UL << EINT_FTEN_FTEN12_Pos)               /*!< 0x00001000 */
#define EINT_FTEN_FTEN12                   EINT_FTEN_FTEN12_Msk                          /*!< Falling trigger event configuration bit of line 12 */
#define EINT_FTEN_FTEN13_Pos               (13U)
#define EINT_FTEN_FTEN13_Msk               (0x1UL << EINT_FTEN_FTEN13_Pos)               /*!< 0x00002000 */
#define EINT_FTEN_FTEN13                   EINT_FTEN_FTEN13_Msk                          /*!< Falling trigger event configuration bit of line 13 */
#define EINT_FTEN_FTEN14_Pos               (14U)
#define EINT_FTEN_FTEN14_Msk               (0x1UL << EINT_FTEN_FTEN14_Pos)               /*!< 0x00004000 */
#define EINT_FTEN_FTEN14                   EINT_FTEN_FTEN14_Msk                          /*!< Falling trigger event configuration bit of line 14 */
#define EINT_FTEN_FTEN15_Pos               (15U)
#define EINT_FTEN_FTEN15_Msk               (0x1UL << EINT_FTEN_FTEN15_Pos)               /*!< 0x00008000 */
#define EINT_FTEN_FTEN15                   EINT_FTEN_FTEN15_Msk                          /*!< Falling trigger event configuration bit of line 15 */
#define EINT_FTEN_FTEN16_Pos               (16U)
#define EINT_FTEN_FTEN16_Msk               (0x1UL << EINT_FTEN_FTEN16_Pos)               /*!< 0x00010000 */
#define EINT_FTEN_FTEN16                   EINT_FTEN_FTEN16_Msk                          /*!< Falling trigger event configuration bit of line 16 */
#define EINT_FTEN_FTEN17_Pos               (17U)
#define EINT_FTEN_FTEN17_Msk               (0x1UL << EINT_FTEN_FTEN17_Pos)               /*!< 0x00020000 */
#define EINT_FTEN_FTEN17                   EINT_FTEN_FTEN17_Msk                          /*!< Falling trigger event configuration bit of line 17 */
#define EINT_FTEN_FTEN18_Pos               (18U)
#define EINT_FTEN_FTEN18_Msk               (0x1UL << EINT_FTEN_FTEN18_Pos)               /*!< 0x00040000 */
#define EINT_FTEN_FTEN18                   EINT_FTEN_FTEN18_Msk                          /*!< Falling trigger event configuration bit of line 18 */
#define EINT_FTEN_FTEN19_Pos               (19U)
#define EINT_FTEN_FTEN19_Msk               (0x1UL << EINT_FTEN_FTEN19_Pos)               /*!< 0x00080000 */
#define EINT_FTEN_FTEN19                   EINT_FTEN_FTEN19_Msk                          /*!< Falling trigger event configuration bit of line 19 */
#define EINT_FTEN_FTEN20_Pos               (20U)
#define EINT_FTEN_FTEN20_Msk               (0x1UL << EINT_FTEN_FTEN20_Pos)               /*!< 0x00100000 */
#define EINT_FTEN_FTEN20                   EINT_FTEN_FTEN20_Msk                          /*!< Falling trigger event configuration bit of line 20 */
#define EINT_FTEN_FTEN21_Pos               (21U)
#define EINT_FTEN_FTEN21_Msk               (0x1UL << EINT_FTEN_FTEN21_Pos)               /*!< 0x00200000 */
#define EINT_FTEN_FTEN21                   EINT_FTEN_FTEN21_Msk                          /*!< Falling trigger event configuration bit of line 21 */
#define EINT_FTEN_FTEN22_Pos               (22U)
#define EINT_FTEN_FTEN22_Msk               (0x1UL << EINT_FTEN_FTEN22_Pos)               /*!< 0x00400000 */
#define EINT_FTEN_FTEN22                   EINT_FTEN_FTEN22_Msk                          /*!< Falling trigger event configuration bit of line 22 */

/******************  Bit definition for EINT_SWINTE register  *****************/
#define EINT_SWINTE_SWINTE0_Pos            (0U)
#define EINT_SWINTE_SWINTE0_Msk            (0x1UL << EINT_SWINTE_SWINTE0_Pos)            /*!< 0x00000001 */
#define EINT_SWINTE_SWINTE0                EINT_SWINTE_SWINTE0_Msk                       /*!< Software Interrupt on line 0 */
#define EINT_SWINTE_SWINTE1_Pos            (1U)
#define EINT_SWINTE_SWINTE1_Msk            (0x1UL << EINT_SWINTE_SWINTE1_Pos)            /*!< 0x00000000 */
#define EINT_SWINTE_SWINTE1                EINT_SWINTE_SWINTE1_Msk                       /*!< Software Interrupt on line 1 */
#define EINT_SWINTE_SWINTE2_Pos            (2U)
#define EINT_SWINTE_SWINTE2_Msk            (0x1UL << EINT_SWINTE_SWINTE2_Pos)            /*!< 0x00000004 */
#define EINT_SWINTE_SWINTE2                EINT_SWINTE_SWINTE2_Msk                       /*!< Software Interrupt on line 2 */
#define EINT_SWINTE_SWINTE3_Pos            (3U)
#define EINT_SWINTE_SWINTE3_Msk            (0x1UL << EINT_SWINTE_SWINTE3_Pos)            /*!< 0x00000008 */
#define EINT_SWINTE_SWINTE3                EINT_SWINTE_SWINTE3_Msk                       /*!< Software Interrupt on line 3 */
#define EINT_SWINTE_SWINTE4_Pos            (4U)
#define EINT_SWINTE_SWINTE4_Msk            (0x1UL << EINT_SWINTE_SWINTE4_Pos)            /*!< 0x00000010 */
#define EINT_SWINTE_SWINTE4                EINT_SWINTE_SWINTE4_Msk                       /*!< Software Interrupt on line 4 */
#define EINT_SWINTE_SWINTE5_Pos            (5U)
#define EINT_SWINTE_SWINTE5_Msk            (0x1UL << EINT_SWINTE_SWINTE5_Pos)            /*!< 0x00000020 */
#define EINT_SWINTE_SWINTE5                EINT_SWINTE_SWINTE5_Msk                       /*!< Software Interrupt on line 5 */
#define EINT_SWINTE_SWINTE6_Pos            (6U)
#define EINT_SWINTE_SWINTE6_Msk            (0x1UL << EINT_SWINTE_SWINTE6_Pos)            /*!< 0x00000040 */
#define EINT_SWINTE_SWINTE6                EINT_SWINTE_SWINTE6_Msk                       /*!< Software Interrupt on line 6 */
#define EINT_SWINTE_SWINTE7_Pos            (7U)
#define EINT_SWINTE_SWINTE7_Msk            (0x1UL << EINT_SWINTE_SWINTE7_Pos)            /*!< 0x00000080 */
#define EINT_SWINTE_SWINTE7                EINT_SWINTE_SWINTE7_Msk                       /*!< Software Interrupt on line 7 */
#define EINT_SWINTE_SWINTE8_Pos            (8U)
#define EINT_SWINTE_SWINTE8_Msk            (0x1UL << EINT_SWINTE_SWINTE8_Pos)            /*!< 0x00000100 */
#define EINT_SWINTE_SWINTE8                EINT_SWINTE_SWINTE8_Msk                       /*!< Software Interrupt on line 8 */
#define EINT_SWINTE_SWINTE9_Pos            (9U)
#define EINT_SWINTE_SWINTE9_Msk            (0x1UL << EINT_SWINTE_SWINTE9_Pos)            /*!< 0x00000200 */
#define EINT_SWINTE_SWINTE9                EINT_SWINTE_SWINTE9_Msk                       /*!< Software Interrupt on line 9 */
#define EINT_SWINTE_SWINTE10_Pos           (10U)
#define EINT_SWINTE_SWINTE10_Msk           (0x1UL << EINT_SWINTE_SWINTE10_Pos)           /*!< 0x00000400 */
#define EINT_SWINTE_SWINTE10               EINT_SWINTE_SWINTE10_Msk                      /*!< Software Interrupt on line 10 */
#define EINT_SWINTE_SWINTE11_Pos           (11U)
#define EINT_SWINTE_SWINTE11_Msk           (0x1UL << EINT_SWINTE_SWINTE11_Pos)           /*!< 0x00000800 */
#define EINT_SWINTE_SWINTE11               EINT_SWINTE_SWINTE11_Msk                      /*!< Software Interrupt on line 11 */
#define EINT_SWINTE_SWINTE12_Pos           (12U)
#define EINT_SWINTE_SWINTE12_Msk           (0x1UL << EINT_SWINTE_SWINTE12_Pos)           /*!< 0x00001000 */
#define EINT_SWINTE_SWINTE12               EINT_SWINTE_SWINTE12_Msk                      /*!< Software Interrupt on line 12 */
#define EINT_SWINTE_SWINTE13_Pos           (13U)
#define EINT_SWINTE_SWINTE13_Msk           (0x1UL << EINT_SWINTE_SWINTE13_Pos)           /*!< 0x00002000 */
#define EINT_SWINTE_SWINTE13               EINT_SWINTE_SWINTE13_Msk                      /*!< Software Interrupt on line 13 */
#define EINT_SWINTE_SWINTE14_Pos           (14U)
#define EINT_SWINTE_SWINTE14_Msk           (0x1UL << EINT_SWINTE_SWINTE14_Pos)           /*!< 0x00004000 */
#define EINT_SWINTE_SWINTE14               EINT_SWINTE_SWINTE14_Msk                      /*!< Software Interrupt on line 14 */
#define EINT_SWINTE_SWINTE15_Pos           (15U)
#define EINT_SWINTE_SWINTE15_Msk           (0x1UL << EINT_SWINTE_SWINTE15_Pos)           /*!< 0x00008000 */
#define EINT_SWINTE_SWINTE15               EINT_SWINTE_SWINTE15_Msk                      /*!< Software Interrupt on line 15 */
#define EINT_SWINTE_SWINTE16_Pos           (16U)
#define EINT_SWINTE_SWINTE16_Msk           (0x1UL << EINT_SWINTE_SWINTE16_Pos)           /*!< 0x00010000 */
#define EINT_SWINTE_SWINTE16               EINT_SWINTE_SWINTE16_Msk                      /*!< Software Interrupt on line 16 */
#define EINT_SWINTE_SWINTE17_Pos           (17U)
#define EINT_SWINTE_SWINTE17_Msk           (0x1UL << EINT_SWINTE_SWINTE17_Pos)           /*!< 0x00020000 */
#define EINT_SWINTE_SWINTE17               EINT_SWINTE_SWINTE17_Msk                      /*!< Software Interrupt on line 17 */
#define EINT_SWINTE_SWINTE18_Pos           (18U)
#define EINT_SWINTE_SWINTE18_Msk           (0x1UL << EINT_SWINTE_SWINTE18_Pos)           /*!< 0x00040000 */
#define EINT_SWINTE_SWINTE18               EINT_SWINTE_SWINTE18_Msk                      /*!< Software Interrupt on line 18 */
#define EINT_SWINTE_SWINTE19_Pos           (19U)
#define EINT_SWINTE_SWINTE19_Msk           (0x1UL << EINT_SWINTE_SWINTE19_Pos)           /*!< 0x00080000 */
#define EINT_SWINTE_SWINTE19               EINT_SWINTE_SWINTE19_Msk                      /*!< Software Interrupt on line 19 */
#define EINT_SWINTE_SWINTE20_Pos           (20U)
#define EINT_SWINTE_SWINTE20_Msk           (0x1UL << EINT_SWINTE_SWINTE20_Pos)           /*!< 0x00100000 */
#define EINT_SWINTE_SWINTE20               EINT_SWINTE_SWINTE20_Msk                      /*!< Software Interrupt on line 20 */
#define EINT_SWINTE_SWINTE21_Pos           (21U)
#define EINT_SWINTE_SWINTE21_Msk           (0x1UL << EINT_SWINTE_SWINTE21_Pos)           /*!< 0x00200000 */
#define EINT_SWINTE_SWINTE21               EINT_SWINTE_SWINTE21_Msk                      /*!< Software Interrupt on line 21 */
#define EINT_SWINTE_SWINTE22_Pos           (22U)
#define EINT_SWINTE_SWINTE22_Msk           (0x1UL << EINT_SWINTE_SWINTE22_Pos)           /*!< 0x00400000 */
#define EINT_SWINTE_SWINTE22               EINT_SWINTE_SWINTE22_Msk                      /*!< Software Interrupt on line 22 */

/*******************  Bit definition for EINT_IPEND register  *****************/
#define EINT_IPEND_IPEND0_Pos              (0U)
#define EINT_IPEND_IPEND0_Msk              (0x1UL << EINT_IPEND_IPEND0_Pos)              /*!< 0x00000001 */
#define EINT_IPEND_IPEND0                  EINT_IPEND_IPEND0_Msk                         /*!< Pending bit for line 0 */
#define EINT_IPEND_IPEND1_Pos              (1U)
#define EINT_IPEND_IPEND1_Msk              (0x1UL << EINT_IPEND_IPEND1_Pos)              /*!< 0x00000000 */
#define EINT_IPEND_IPEND1                  EINT_IPEND_IPEND1_Msk                         /*!< Pending bit for line 1 */
#define EINT_IPEND_IPEND2_Pos              (2U)
#define EINT_IPEND_IPEND2_Msk              (0x1UL << EINT_IPEND_IPEND2_Pos)              /*!< 0x00000004 */
#define EINT_IPEND_IPEND2                  EINT_IPEND_IPEND2_Msk                         /*!< Pending bit for line 2 */
#define EINT_IPEND_IPEND3_Pos              (3U)
#define EINT_IPEND_IPEND3_Msk              (0x1UL << EINT_IPEND_IPEND3_Pos)              /*!< 0x00000008 */
#define EINT_IPEND_IPEND3                  EINT_IPEND_IPEND3_Msk                         /*!< Pending bit for line 3 */
#define EINT_IPEND_IPEND4_Pos              (4U)
#define EINT_IPEND_IPEND4_Msk              (0x1UL << EINT_IPEND_IPEND4_Pos)              /*!< 0x00000010 */
#define EINT_IPEND_IPEND4                  EINT_IPEND_IPEND4_Msk                         /*!< Pending bit for line 4 */
#define EINT_IPEND_IPEND5_Pos              (5U)
#define EINT_IPEND_IPEND5_Msk              (0x1UL << EINT_IPEND_IPEND5_Pos)              /*!< 0x00000020 */
#define EINT_IPEND_IPEND5                  EINT_IPEND_IPEND5_Msk                         /*!< Pending bit for line 5 */
#define EINT_IPEND_IPEND6_Pos              (6U)
#define EINT_IPEND_IPEND6_Msk              (0x1UL << EINT_IPEND_IPEND6_Pos)              /*!< 0x00000040 */
#define EINT_IPEND_IPEND6                  EINT_IPEND_IPEND6_Msk                         /*!< Pending bit for line 6 */
#define EINT_IPEND_IPEND7_Pos              (7U)
#define EINT_IPEND_IPEND7_Msk              (0x1UL << EINT_IPEND_IPEND7_Pos)              /*!< 0x00000080 */
#define EINT_IPEND_IPEND7                  EINT_IPEND_IPEND7_Msk                         /*!< Pending bit for line 7 */
#define EINT_IPEND_IPEND8_Pos              (8U)
#define EINT_IPEND_IPEND8_Msk              (0x1UL << EINT_IPEND_IPEND8_Pos)              /*!< 0x00000100 */
#define EINT_IPEND_IPEND8                  EINT_IPEND_IPEND8_Msk                         /*!< Pending bit for line 8 */
#define EINT_IPEND_IPEND9_Pos              (9U)
#define EINT_IPEND_IPEND9_Msk              (0x1UL << EINT_IPEND_IPEND9_Pos)              /*!< 0x00000200 */
#define EINT_IPEND_IPEND9                  EINT_IPEND_IPEND9_Msk                         /*!< Pending bit for line 9 */
#define EINT_IPEND_IPEND10_Pos             (10U)
#define EINT_IPEND_IPEND10_Msk             (0x1UL << EINT_IPEND_IPEND10_Pos)             /*!< 0x00000400 */
#define EINT_IPEND_IPEND10                 EINT_IPEND_IPEND10_Msk                        /*!< Pending bit for line 10 */
#define EINT_IPEND_IPEND11_Pos             (11U)
#define EINT_IPEND_IPEND11_Msk             (0x1UL << EINT_IPEND_IPEND11_Pos)             /*!< 0x00000800 */
#define EINT_IPEND_IPEND11                 EINT_IPEND_IPEND11_Msk                        /*!< Pending bit for line 11 */
#define EINT_IPEND_IPEND12_Pos             (12U)
#define EINT_IPEND_IPEND12_Msk             (0x1UL << EINT_IPEND_IPEND12_Pos)             /*!< 0x00001000 */
#define EINT_IPEND_IPEND12                 EINT_IPEND_IPEND12_Msk                        /*!< Pending bit for line 12 */
#define EINT_IPEND_IPEND13_Pos             (13U)
#define EINT_IPEND_IPEND13_Msk             (0x1UL << EINT_IPEND_IPEND13_Pos)             /*!< 0x00002000 */
#define EINT_IPEND_IPEND13                 EINT_IPEND_IPEND13_Msk                        /*!< Pending bit for line 13 */
#define EINT_IPEND_IPEND14_Pos             (14U)
#define EINT_IPEND_IPEND14_Msk             (0x1UL << EINT_IPEND_IPEND14_Pos)             /*!< 0x00004000 */
#define EINT_IPEND_IPEND14                 EINT_IPEND_IPEND14_Msk                        /*!< Pending bit for line 14 */
#define EINT_IPEND_IPEND15_Pos             (15U)
#define EINT_IPEND_IPEND15_Msk             (0x1UL << EINT_IPEND_IPEND15_Pos)             /*!< 0x00008000 */
#define EINT_IPEND_IPEND15                 EINT_IPEND_IPEND15_Msk                        /*!< Pending bit for line 15 */
#define EINT_IPEND_IPEND16_Pos             (16U)
#define EINT_IPEND_IPEND16_Msk             (0x1UL << EINT_IPEND_IPEND16_Pos)             /*!< 0x00010000 */
#define EINT_IPEND_IPEND16                 EINT_IPEND_IPEND16_Msk                        /*!< Pending bit for line 16 */
#define EINT_IPEND_IPEND17_Pos             (17U)
#define EINT_IPEND_IPEND17_Msk             (0x1UL << EINT_IPEND_IPEND17_Pos)             /*!< 0x00020000 */
#define EINT_IPEND_IPEND17                 EINT_IPEND_IPEND17_Msk                        /*!< Pending bit for line 17 */
#define EINT_IPEND_IPEND18_Pos             (18U)
#define EINT_IPEND_IPEND18_Msk             (0x1UL << EINT_IPEND_IPEND18_Pos)             /*!< 0x00040000 */
#define EINT_IPEND_IPEND18                 EINT_IPEND_IPEND18_Msk                        /*!< Pending bit for line 18 */
#define EINT_IPEND_IPEND19_Pos             (19U)
#define EINT_IPEND_IPEND19_Msk             (0x1UL << EINT_IPEND_IPEND19_Pos)             /*!< 0x00080000 */
#define EINT_IPEND_IPEND19                 EINT_IPEND_IPEND19_Msk                        /*!< Pending bit for line 19 */
#define EINT_IPEND_IPEND20_Pos             (20U)
#define EINT_IPEND_IPEND20_Msk             (0x1UL << EINT_IPEND_IPEND20_Pos)             /*!< 0x00100000 */
#define EINT_IPEND_IPEND20                 EINT_IPEND_IPEND20_Msk                        /*!< Pending bit for line 20 */
#define EINT_IPEND_IPEND21_Pos             (21U)
#define EINT_IPEND_IPEND21_Msk             (0x1UL << EINT_IPEND_IPEND21_Pos)             /*!< 0x00200000 */
#define EINT_IPEND_IPEND21                 EINT_IPEND_IPEND21_Msk                        /*!< Pending bit for line 21 */
#define EINT_IPEND_IPEND22_Pos             (22U)
#define EINT_IPEND_IPEND22_Msk             (0x1UL << EINT_IPEND_IPEND22_Pos)             /*!< 0x00400000 */
#define EINT_IPEND_IPEND22                 EINT_IPEND_IPEND22_Msk                        /*!< Pending bit for line 22 */

/*******************  Bit definition for EINT_IOSELR1 register  ***************/
#define EINT_IOSELR1_EINT0_Pos             (0U)
#define EINT_IOSELR1_EINT0_Msk             (0xFUL << EINT_IOSELR1_EINT0_Pos)             /*!< 0x00000003 */
#define EINT_IOSELR1_EINT0                 EINT_IOSELR1_EINT0_Msk
#define EINT_IOSELR1_EINT1_Pos             (4U)
#define EINT_IOSELR1_EINT1_Msk             (0xFUL << EINT_IOSELR1_EINT1_Pos)             /*!< 0x00000030 */
#define EINT_IOSELR1_EINT1                 EINT_IOSELR1_EINT1_Msk
#define EINT_IOSELR1_EINT2_Pos             (8U)
#define EINT_IOSELR1_EINT2_Msk             (0xFUL << EINT_IOSELR1_EINT2_Pos)             /*!< 0x00000300 */
#define EINT_IOSELR1_EINT2                 EINT_IOSELR1_EINT2_Msk
#define EINT_IOSELR1_EINT3_Pos             (12U)
#define EINT_IOSELR1_EINT3_Msk             (0xFUL << EINT_IOSELR1_EINT3_Pos)             /*!< 0x00003000 */
#define EINT_IOSELR1_EINT3                 EINT_IOSELR1_EINT3_Msk
#define EINT_IOSELR1_EINT4_Pos             (16U)
#define EINT_IOSELR1_EINT4_Msk             (0xFUL << EINT_IOSELR1_EINT4_Pos)             /*!< 0x00030000 */
#define EINT_IOSELR1_EINT4                 EINT_IOSELR1_EINT4_Msk
#define EINT_IOSELR1_EINT5_Pos             (20U)
#define EINT_IOSELR1_EINT5_Msk             (0xFUL << EINT_IOSELR1_EINT5_Pos)             /*!< 0x00300000 */
#define EINT_IOSELR1_EINT5                 EINT_IOSELR1_EINT5_Msk
#define EINT_IOSELR1_EINT6_Pos             (24U)
#define EINT_IOSELR1_EINT6_Msk             (0xFUL << EINT_IOSELR1_EINT6_Pos)             /*!< 0x03000000 */
#define EINT_IOSELR1_EINT6                 EINT_IOSELR1_EINT6_Msk
#define EINT_IOSELR1_EINT7_Pos             (28U)
#define EINT_IOSELR1_EINT7_Msk             (0xFUL << EINT_IOSELR1_EINT7_Pos)             /*!< 0x30000000 */
#define EINT_IOSELR1_EINT7                 EINT_IOSELR1_EINT7_Msk

/*******************  Bit definition for EINT_IOSELR2 register  ***************/
#define EINT_IOSELR2_EINT8_Pos             (0U)
#define EINT_IOSELR2_EINT8_Msk             (0xFUL << EINT_IOSELR2_EINT8_Pos)             /*!< 0x00000003 */
#define EINT_IOSELR2_EINT8                 EINT_IOSELR2_EINT8_Msk
#define EINT_IOSELR2_EINT9_Pos             (4U)
#define EINT_IOSELR2_EINT9_Msk             (0xFUL << EINT_IOSELR2_EINT9_Pos)             /*!< 0x00000030 */
#define EINT_IOSELR2_EINT9                 EINT_IOSELR2_EINT9_Msk
#define EINT_IOSELR2_EINT10_Pos            (8U)
#define EINT_IOSELR2_EINT10_Msk            (0xFUL << EINT_IOSELR2_EINT10_Pos)            /*!< 0x00000300 */
#define EINT_IOSELR2_EINT10                EINT_IOSELR2_EINT10_Msk
#define EINT_IOSELR2_EINT11_Pos            (12U)
#define EINT_IOSELR2_EINT11_Msk            (0xFUL << EINT_IOSELR2_EINT11_Pos)            /*!< 0x00003000 */
#define EINT_IOSELR2_EINT11                EINT_IOSELR2_EINT11_Msk
#define EINT_IOSELR2_EINT12_Pos            (16U)
#define EINT_IOSELR2_EINT12_Msk            (0xFUL << EINT_IOSELR2_EINT12_Pos)            /*!< 0x00030000 */
#define EINT_IOSELR2_EINT12                EINT_IOSELR2_EINT12_Msk
#define EINT_IOSELR2_EINT13_Pos            (20U)
#define EINT_IOSELR2_EINT13_Msk            (0xFUL << EINT_IOSELR2_EINT13_Pos)            /*!< 0x00300000 */
#define EINT_IOSELR2_EINT13                EINT_IOSELR2_EINT13_Msk
#define EINT_IOSELR2_EINT14_Pos            (24U)
#define EINT_IOSELR2_EINT14_Msk            (0xFUL << EINT_IOSELR2_EINT14_Pos)            /*!< 0x03000000 */
#define EINT_IOSELR2_EINT14                EINT_IOSELR2_EINT14_Msk
#define EINT_IOSELR2_EINT15_Pos            (28U)
#define EINT_IOSELR2_EINT15_Msk            (0xFUL << EINT_IOSELR2_EINT15_Pos)            /*!< 0x30000000 */
#define EINT_IOSELR2_EINT15                EINT_IOSELR2_EINT15_Msk

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_KEY register  *****************/
#define FLASH_KEY_FKEY_Pos                 (0UL)
#define FLASH_KEY_FKEY_Msk                 (0xFFFFFFFF << FLASH_KEY_FKEY_Pos)
#define FLASH_KEY_FKEY                     (FLASH_KEY_FKEY_Msk)

/*******************  Bits definition for FLASH_OPTKEY register  **************/
#define FLASH_OPTKEY_OPTKEY_Pos            (0UL)
#define FLASH_OPTKEY_OPTKEY_Msk            (0xFFFFFFFF << FLASH_OPTKEY_OPTKEY_Pos)
#define FLASH_OPTKEY_OPTKEY                (FLASH_OPTKEY_OPTKEY_Msk)

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_ERD_Pos                   (0UL)
#define FLASH_SR_ERD_Msk                   (0x1UL << FLASH_SR_ERD_Pos)                   /*!< Completion of erasing sign */
#define FLASH_SR_ERD                       (FLASH_SR_ERD_Msk)                            /*!< 0x00000001 */
#define FLASH_SR_PRD_Pos                   (1UL)
#define FLASH_SR_PRD_Msk                   (0x1UL << FLASH_SR_PRD_Pos)                   /*!< Programming Completion Flag */
#define FLASH_SR_PRD                       (FLASH_SR_PRD_Msk)                            /*!< 0x00000002 */
#define FLASH_SR_BUSY_Pos                  (2UL)
#define FLASH_SR_BUSY_Msk                  (0x1UL << FLASH_SR_BUSY_Pos)                  /*!< FLASH erase BUSY bit */
#define FLASH_SR_BUSY                      (FLASH_SR_BUSY_Msk)                           /*!< 0x00000004 */
#define FLASH_SR_KEYERR_Pos                (3UL)
#define FLASH_SR_KEYERR_Msk                (0x1UL << FLASH_SR_KEYERR_Pos)                /*!< Flash KEY error. */
#define FLASH_SR_KEYERR                    (FLASH_SR_KEYERR_Msk)                         /*!< 0x00000008 */
#define FLASH_SR_WRPRTERR_Pos              (4UL)
#define FLASH_SR_WRPRTERR_Msk              (0x1UL << FLASH_SR_WRPRTERR_Pos)              /*!< Write protection error flag (Main+Data_Flash) */
#define FLASH_SR_WRPRTERR                  (FLASH_SR_WRPRTERR_Msk)                       /*!< 0x00000010 */
#define FLASH_SR_WADRERR_Pos               (5UL)
#define FLASH_SR_WADRERR_Msk               (0x1UL << FLASH_SR_WADRERR_Pos)               /*!< When erasing or programming, if an error occurs when writing data to the target address, the erasing or programming will not take effect. */
#define FLASH_SR_WADRERR                   (FLASH_SR_WADRERR_Msk)                        /*!< 0x00000020 */
#define FLASH_SR_OPBPRD_Pos                (14UL)
#define FLASH_SR_OPBPRD_Msk                (0x1UL << FLASH_SR_OPBPRD_Pos)                /*!< Option byte programming complete flag */
#define FLASH_SR_OPBPRD                    (FLASH_SR_OPBPRD_Msk)                         /*!< 0x00004000 */
#define FLASH_SR_OPTERR_Pos                (15UL)
#define FLASH_SR_OPTERR_Msk                (0x1UL << FLASH_SR_OPTERR_Pos)                /*!< option_byte does not pass the one's complement code check. */
#define FLASH_SR_OPTERR                    (FLASH_SR_OPTERR_Msk)                         /*!< 0x00008000 */
#define FLASH_SR_TRIMERR_Pos               (16UL)
#define FLASH_SR_TRIMERR_Msk               (0x1UL << FLASH_SR_TRIMERR_Pos)               /*!< Trim check error */
#define FLASH_SR_TRIMERR                   (FLASH_SR_TRIMERR_Msk)                        /*!< 0x00010000 */
#define FLASH_SR_MAINUNLOCK_Pos            (17UL)
#define FLASH_SR_MAINUNLOCK_Msk            (0x1UL << FLASH_SR_MAINUNLOCK_Pos)            /*!< Main program area lock flag */
#define FLASH_SR_MAINUNLOCK                (FLASH_SR_MAINUNLOCK_Msk)                     /*!< 0x00020000 */
#define FLASH_SR_OPUNLOCK_Pos              (18UL)
#define FLASH_SR_OPUNLOCK_Msk              (0x1UL << FLASH_SR_OPUNLOCK_Pos)              /*!< Option Byte Area Lock Flag */
#define FLASH_SR_OPUNLOCK                  (FLASH_SR_OPUNLOCK_Msk)                       /*!< 0x00040000 */

/*******************  Bits definition for FLASH_CR1 register  *****************/
#define FLASH_CR1_EREQ_Pos                 (0UL)
#define FLASH_CR1_EREQ_Msk                 (0x1UL << FLASH_CR1_EREQ_Pos)                 /*!< Erase Request */
#define FLASH_CR1_EREQ                     (FLASH_CR1_EREQ_Msk)                          /*!< 0x00000001 */
#define FLASH_CR1_PREQ_Pos                 (1UL)
#define FLASH_CR1_PREQ_Msk                 (0x1UL << FLASH_CR1_PREQ_Pos)                 /*!< Program Request */
#define FLASH_CR1_PREQ                     (FLASH_CR1_PREQ_Msk)                          /*!< 0x00000002 */
#define FLASH_CR1_ERTYPE_Pos               (2UL)
#define FLASH_CR1_ERTYPE_Msk               (0x3UL << FLASH_CR1_ERTYPE_Pos)               /*!< Flash erase type configuration */
#define FLASH_CR1_ERTYPE                   (FLASH_CR1_ERTYPE_Msk)                        /*!< 0x0000000C */
#define FLASH_CR1_ERTYPE_0                 (0x1UL << FLASH_CR1_ERTYPE_Pos)               /*!< 0x00000004 */
#define FLASH_CR1_ERTYPE_1                 (0x2UL << FLASH_CR1_ERTYPE_Pos)               /*!< 0x00000008 */

#define FLASH_CR1_EOPIE_Pos                (4UL)
#define FLASH_CR1_EOPIE_Msk                (0x1UL << FLASH_CR1_EOPIE_Pos)                /*!< Programming or erasing end interrupt enable */
#define FLASH_CR1_EOPIE                    (FLASH_CR1_EOPIE_Msk)                         /*!< 0x00000010 */
#define FLASH_CR1_ERRIE_Pos                (5UL)
#define FLASH_CR1_ERRIE_Msk                (0x1UL << FLASH_CR1_ERRIE_Pos)                /*!< Error Interrupt Occurred */
#define FLASH_CR1_ERRIE                    (FLASH_CR1_ERRIE_Msk)                         /*!< 0x00000020 */
#define FLASH_CR1_OPRELOAD_Pos             (15UL)
#define FLASH_CR1_OPRELOAD_Msk             (0x1UL << FLASH_CR1_OPRELOAD_Pos)             /*!< Forced update of option bytes */
#define FLASH_CR1_OPRELOAD                 (FLASH_CR1_OPRELOAD_Msk)                      /*!< 0x00008000 */

/*******************  Bits definition for FLASH_CR2 register  *****************/
#define FLASH_CR2_RDWAIT_Pos               (0UL)
#define FLASH_CR2_RDWAIT_Msk               (0xFUL << FLASH_CR2_RDWAIT_Pos)               /*!< Setting the Flash wait time. */
#define FLASH_CR2_RDWAIT                   FLASH_CR2_RDWAIT_Msk                          /*!< 0x0000000F */
#define FLASH_CR2_RDWAIT_0                 (0x1UL << FLASH_CR2_RDWAIT_Pos)               /*!< 0x00000001 */
#define FLASH_CR2_RDWAIT_1                 (0x2UL << FLASH_CR2_RDWAIT_Pos)               /*!< 0x00000002 */
#define FLASH_CR2_RDWAIT_2                 (0x4UL << FLASH_CR2_RDWAIT_Pos)               /*!< 0x00000004 */
#define FLASH_CR2_RDWAIT_3                 (0x8UL << FLASH_CR2_RDWAIT_Pos)               /*!< 0x00000008 */

#define FLASH_CR2_PREFETCHEN_Pos           (8UL)
#define FLASH_CR2_PREFETCHEN_Msk           (0x1UL << FLASH_CR2_PREFETCHEN_Pos)           /*!< Prefetch Enable */
#define FLASH_CR2_PREFETCHEN               FLASH_CR2_PREFETCHEN_Msk                      /*!< 0x00000100 */
#define FLASH_CR2_CACHERST_Pos             (10UL)
#define FLASH_CR2_CACHERST_Msk             (0x1UL << FLASH_CR2_CACHERST_Pos)             /*!< Cache reset operation */
#define FLASH_CR2_CACHERST                 FLASH_CR2_CACHERST_Msk                        /*!< 0x00000400 */

/*******************  Bits definition for FLASH_TMCR register  ****************/
#define FLASH_TMCR_UNIT_Pos                (0UL)
#define FLASH_TMCR_UNIT_Msk                (0xFFUL << FLASH_TMCR_UNIT_Pos)               /*!< Flash/EEPROM 1us Unit Counter: FLASH/EEPROM erasure time base control */
#define FLASH_TMCR_UNIT                    FLASH_TMCR_UNIT_Msk                           /*!< 0x000000FF */

/*******************  Bits definition for FLASH_OBSR1 register  ***************/
#define FLASH_OBSR1_RDP_Pos                (0UL)
#define FLASH_OBSR1_RDP_Msk                (0xFFUL << FLASH_OBSR1_RDP_Pos)               /*!< Read protection */
#define FLASH_OBSR1_RDP                    FLASH_OBSR1_RDP_Msk                           /*!< 0x000000FF */
#define FLASH_OBSR1_IWDTSW_Pos             (8UL)
#define FLASH_OBSR1_IWDTSW_Msk             (0x1UL << FLASH_OBSR1_IWDTSW_Pos)             /*!< IWDT enable */
#define FLASH_OBSR1_IWDTSW                 FLASH_OBSR1_IWDTSW_Msk                        /*!< 0x00000100 */
#define FLASH_OBSR1_WWDTSW_Pos             (9UL)
#define FLASH_OBSR1_WWDTSW_Msk             (0x1UL << FLASH_OBSR1_WWDTSW_Pos)             /*!< WWDT enable */
#define FLASH_OBSR1_WWDTSW                 FLASH_OBSR1_WWDTSW_Msk                        /*!< 0x00000200 */
#define FLASH_OBSR1_WLOCKEN_Pos            (10UL)
#define FLASH_OBSR1_WLOCKEN_Msk            (0x1UL << FLASH_OBSR1_WLOCKEN_Pos)            /*!< WLOCK Write Protection Master Switch */
#define FLASH_OBSR1_WLOCKEN                FLASH_OBSR1_WLOCKEN_Msk                       /*!< 0x00000400 */
#define FLASH_OBSR1_NMIDIS_Pos             (11UL)
#define FLASH_OBSR1_NMIDIS_Msk             (0x1UL << FLASH_OBSR1_NMIDIS_Pos)             /*!< NMI Pin Enable Configuration */
#define FLASH_OBSR1_NMIDIS                 FLASH_OBSR1_NMIDIS_Msk                        /*!< 0x00000800 */
#define FLASH_OBSR1_ADTSLOAD_Pos           (15UL)
#define FLASH_OBSR1_ADTSLOAD_Msk           (0x1UL << FLASH_OBSR1_ADTSLOAD_Pos)           /*!< ADC TRIM */
#define FLASH_OBSR1_ADTSLOAD               FLASH_OBSR1_ADTSLOAD_Msk                      /*!< 0x00008000 */
#define FLASH_OBSR1_WLOCK_Pos              (16UL)
#define FLASH_OBSR1_WLOCK_Msk              (0xFFUL << FLASH_OBSR1_WLOCK_Pos)             /*!< Write lock */
#define FLASH_OBSR1_WLOCK                  FLASH_OBSR1_WLOCK_Msk                         /*!< 0x00010000 */

/*******************  Bits definition for FLASH_OBSR2 register  ***************/
#define FLASH_OBSR2_BOOTADDR_Pos           (0UL)
#define FLASH_OBSR2_BOOTADDR_Msk           (0xFFFFUL << FLASH_OBSR2_BOOTADDR_Pos)        /*!< Bootaddr */
#define FLASH_OBSR2_BOOTADDR               FLASH_OBSR2_BOOTADDR_Msk                      /*!< 0x0000FFFF */

/*******************  Bits definition for FLASH_OBCR1 register  ***************/
#define FLASH_OBCR1_RDPWBF_Pos             (0UL)
#define FLASH_OBCR1_RDPWBF_Msk             (0xFFUL << FLASH_OBCR1_RDPWBF_Pos)            /*!< RDP write cache bit */
#define FLASH_OBCR1_RDPWBF                 FLASH_OBCR1_RDPWBF_Msk                        /*!< 0x000000FF */
#define FLASH_OBCR1_IWDTSWBF_Pos           (8UL)
#define FLASH_OBCR1_IWDTSWBF_Msk           (0x1UL << FLASH_OBCR1_IWDTSWBF_Pos)           /*!< IWDTSW write cache bit */
#define FLASH_OBCR1_IWDTSWBF               FLASH_OBCR1_IWDTSWBF_Msk                      /*!< 0x00000100 */
#define FLASH_OBCR1_WWDTSWBF_Pos           (9UL)
#define FLASH_OBCR1_WWDTSWBF_Msk           (0x1UL << FLASH_OBCR1_WWDTSWBF_Pos)           /*!< WWDTSW write cache bit */
#define FLASH_OBCR1_WWDTSWBF               FLASH_OBCR1_WWDTSWBF_Msk                      /*!< 0x00000200 */
#define FLASH_OBCR1_WLOCKENBF_Pos          (10UL)
#define FLASH_OBCR1_WLOCKENBF_Msk          (0x1UL << FLASH_OBCR1_WLOCKENBF_Pos)          /*!< WLOCKEN write cache bit */
#define FLASH_OBCR1_WLOCKENBF              FLASH_OBCR1_WLOCKENBF_Msk                     /*!< 0x00000400 */
#define FLASH_OBCR1_NMIDISWBF_Pos          (11UL)
#define FLASH_OBCR1_NMIDISWBF_Msk          (0x1UL << FLASH_OBCR1_NMIDISWBF_Pos)          /*!< NMIDIS write cache bit */
#define FLASH_OBCR1_NMIDISWBF              FLASH_OBCR1_NMIDISWBF_Msk                     /*!< 0x00000800 */
#define FLASH_OBCR1_ADTSLOADWBF_Pos        (15UL)
#define FLASH_OBCR1_ADTSLOADWBF_Msk        (0x1UL << FLASH_OBCR1_ADTSLOADWBF_Pos)        /*!< ADC TRIM */
#define FLASH_OBCR1_ADTSLOADWBF            FLASH_OBCR1_ADTSLOADWBF_Msk                   /*!< 0x00008000 */
#define FLASH_OBCR1_WLOCKBF_Pos            (16UL)
#define FLASH_OBCR1_WLOCKBF_Msk            (0xFFUL << FLASH_OBCR1_WLOCKBF_Pos)           /*!< WLOCK write cache bit */
#define FLASH_OBCR1_WLOCKBF                FLASH_OBCR1_WLOCKBF_Msk                       /*!< 0x0FF00000 */
#define FLASH_OBCR1_WLOCKBF_0              (0x1UL << FLASH_OBCR1_WLOCKBF_Pos)            /*!< 0x00010000 */
#define FLASH_OBCR1_WLOCKBF_1              (0x2UL << FLASH_OBCR1_WLOCKBF_Pos)            /*!< 0x00020000 */
#define FLASH_OBCR1_WLOCKBF_2              (0x4UL << FLASH_OBCR1_WLOCKBF_Pos)            /*!< 0x00040000 */
#define FLASH_OBCR1_WLOCKBF_3              (0x8UL << FLASH_OBCR1_WLOCKBF_Pos)            /*!< 0x00080000 */
#define FLASH_OBCR1_WLOCKBF_4              (0x10UL << FLASH_OBCR1_WLOCKBF_Pos)           /*!< 0x00100000 */
#define FLASH_OBCR1_WLOCKBF_5              (0x20UL << FLASH_OBCR1_WLOCKBF_Pos)           /*!< 0x00200000 */
#define FLASH_OBCR1_WLOCKBF_6              (0x40UL << FLASH_OBCR1_WLOCKBF_Pos)           /*!< 0x00400000 */
#define FLASH_OBCR1_WLOCKBF_7              (0x80UL << FLASH_OBCR1_WLOCKBF_Pos)           /*!< 0x00800000 */

#define FLASH_OBCR1_OPBWREQ_Pos            (24UL)
#define FLASH_OBCR1_OPBWREQ_Msk            (0x1UL << FLASH_OBCR1_OPBWREQ_Pos)            /*!< OPT write cache bit */
#define FLASH_OBCR1_OPBWREQ                FLASH_OBCR1_OPBWREQ_Msk                       /*!< 0x01000000 */

/*******************  Bits definition for FLASH_OBCR2 register  ***************/
#define FLASH_OBCR2_BOOTADDRBF_Pos         (0UL)
#define FLASH_OBCR2_BOOTADDRBF_Msk         (0xFFFFUL << FLASH_OBCR2_BOOTADDRBF_Pos)
#define FLASH_OBCR2_BOOTADDRBF             FLASH_OBCR2_BOOTADDRBF_Msk                    /*!< 0x0000FFFF */

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/************************ definition for GPIO PIN *****************************/
#define GPIO_PIN0_Pos                      (0U)
#define GPIO_PIN0_Msk                      (0x1UL << GPIO_PIN0_Pos)
#define GPIO_PIN0                          GPIO_PIN0_Msk
#define GPIO_PIN1_Pos                      (1U)
#define GPIO_PIN1_Msk                      (0x1UL << GPIO_PIN1_Pos)
#define GPIO_PIN1                          GPIO_PIN1_Msk
#define GPIO_PIN2_Pos                      (2U)
#define GPIO_PIN2_Msk                      (0x1UL << GPIO_PIN2_Pos)
#define GPIO_PIN2                          GPIO_PIN2_Msk
#define GPIO_PIN3_Pos                      (3U)
#define GPIO_PIN3_Msk                      (0x1UL << GPIO_PIN3_Pos)
#define GPIO_PIN3                          GPIO_PIN3_Msk
#define GPIO_PIN4_Pos                      (4U)
#define GPIO_PIN4_Msk                      (0x1UL << GPIO_PIN4_Pos)
#define GPIO_PIN4                          GPIO_PIN4_Msk
#define GPIO_PIN5_Pos                      (5U)
#define GPIO_PIN5_Msk                      (0x1UL << GPIO_PIN5_Pos)
#define GPIO_PIN5                          GPIO_PIN5_Msk
#define GPIO_PIN6_Pos                      (6U)
#define GPIO_PIN6_Msk                      (0x1UL << GPIO_PIN6_Pos)
#define GPIO_PIN6                          GPIO_PIN6_Msk
#define GPIO_PIN7_Pos                      (7U)
#define GPIO_PIN7_Msk                      (0x1UL << GPIO_PIN7_Pos)
#define GPIO_PIN7                          GPIO_PIN7_Msk
#define GPIO_PIN8_Pos                      (8U)
#define GPIO_PIN8_Msk                      (0x1UL << GPIO_PIN8_Pos)
#define GPIO_PIN8                          GPIO_PIN8_Msk
#define GPIO_PIN9_Pos                      (9U)
#define GPIO_PIN9_Msk                      (0x1UL << GPIO_PIN9_Pos)
#define GPIO_PIN9                          GPIO_PIN9_Msk
#define GPIO_PIN10_Pos                     (10U)
#define GPIO_PIN10_Msk                     (0x1UL << GPIO_PIN10_Pos)
#define GPIO_PIN10                         GPIO_PIN10_Msk
#define GPIO_PIN11_Pos                     (11U)
#define GPIO_PIN11_Msk                     (0x1UL << GPIO_PIN11_Pos)
#define GPIO_PIN11                         GPIO_PIN11_Msk
#define GPIO_PIN12_Pos                     (12U)
#define GPIO_PIN12_Msk                     (0x1UL << GPIO_PIN12_Pos)
#define GPIO_PIN12                         GPIO_PIN12_Msk
#define GPIO_PIN13_Pos                     (13U)
#define GPIO_PIN13_Msk                     (0x1UL << GPIO_PIN13_Pos)
#define GPIO_PIN13                         GPIO_PIN13_Msk
#define GPIO_PIN14_Pos                     (14U)
#define GPIO_PIN14_Msk                     (0x1UL << GPIO_PIN14_Pos)
#define GPIO_PIN14                         GPIO_PIN14_Msk
#define GPIO_PIN15_Pos                     (15U)
#define GPIO_PIN15_Msk                     (0x1UL << GPIO_PIN15_Pos)
#define GPIO_PIN15                         GPIO_PIN15_Msk

/******************  Bits definition for GPIO_MODE register  ******************/
#define GPIO_MODE_MODE0_Pos                (0U)
#define GPIO_MODE_MODE0_Msk                (0x3UL << GPIO_MODE_MODE0_Pos)                /*!< 0x00000003 */
#define GPIO_MODE_MODE0                    GPIO_MODE_MODE0_Msk
#define GPIO_MODE_MODE0_0                  (0x1UL << GPIO_MODE_MODE0_Pos)                /*!< 0x00000001 */
#define GPIO_MODE_MODE0_1                  (0x2UL << GPIO_MODE_MODE0_Pos)                /*!< 0x00000000 */
#define GPIO_MODE_MODE1_Pos                (2U)
#define GPIO_MODE_MODE1_Msk                (0x3UL << GPIO_MODE_MODE1_Pos)                /*!< 0x0000000C */
#define GPIO_MODE_MODE1                    GPIO_MODE_MODE1_Msk
#define GPIO_MODE_MODE1_0                  (0x1UL << GPIO_MODE_MODE1_Pos)                /*!< 0x00000004 */
#define GPIO_MODE_MODE1_1                  (0x2UL << GPIO_MODE_MODE1_Pos)                /*!< 0x00000008 */
#define GPIO_MODE_MODE2_Pos                (4U)
#define GPIO_MODE_MODE2_Msk                (0x3UL << GPIO_MODE_MODE2_Pos)                /*!< 0x00000030 */
#define GPIO_MODE_MODE2                    GPIO_MODE_MODE2_Msk
#define GPIO_MODE_MODE2_0                  (0x1UL << GPIO_MODE_MODE2_Pos)                /*!< 0x00000010 */
#define GPIO_MODE_MODE2_1                  (0x2UL << GPIO_MODE_MODE2_Pos)                /*!< 0x00000020 */
#define GPIO_MODE_MODE3_Pos                (6U)
#define GPIO_MODE_MODE3_Msk                (0x3UL << GPIO_MODE_MODE3_Pos)                /*!< 0x000000C0 */
#define GPIO_MODE_MODE3                    GPIO_MODE_MODE3_Msk
#define GPIO_MODE_MODE3_0                  (0x1UL << GPIO_MODE_MODE3_Pos)                /*!< 0x00000040 */
#define GPIO_MODE_MODE3_1                  (0x2UL << GPIO_MODE_MODE3_Pos)                /*!< 0x00000080 */
#define GPIO_MODE_MODE4_Pos                (8U)
#define GPIO_MODE_MODE4_Msk                (0x3UL << GPIO_MODE_MODE4_Pos)                /*!< 0x00000300 */
#define GPIO_MODE_MODE4                    GPIO_MODE_MODE4_Msk
#define GPIO_MODE_MODE4_0                  (0x1UL << GPIO_MODE_MODE4_Pos)                /*!< 0x00000100 */
#define GPIO_MODE_MODE4_1                  (0x2UL << GPIO_MODE_MODE4_Pos)                /*!< 0x00000200 */
#define GPIO_MODE_MODE5_Pos                (10U)
#define GPIO_MODE_MODE5_Msk                (0x3UL << GPIO_MODE_MODE5_Pos)                /*!< 0x00000C00 */
#define GPIO_MODE_MODE5                    GPIO_MODE_MODE5_Msk
#define GPIO_MODE_MODE5_0                  (0x1UL << GPIO_MODE_MODE5_Pos)                /*!< 0x00000400 */
#define GPIO_MODE_MODE5_1                  (0x2UL << GPIO_MODE_MODE5_Pos)                /*!< 0x00000800 */
#define GPIO_MODE_MODE6_Pos                (12U)
#define GPIO_MODE_MODE6_Msk                (0x3UL << GPIO_MODE_MODE6_Pos)                /*!< 0x00003000 */
#define GPIO_MODE_MODE6                    GPIO_MODE_MODE6_Msk
#define GPIO_MODE_MODE6_0                  (0x1UL << GPIO_MODE_MODE6_Pos)                /*!< 0x00001000 */
#define GPIO_MODE_MODE6_1                  (0x2UL << GPIO_MODE_MODE6_Pos)                /*!< 0x00002000 */
#define GPIO_MODE_MODE7_Pos                (14U)
#define GPIO_MODE_MODE7_Msk                (0x3UL << GPIO_MODE_MODE7_Pos)                /*!< 0x0000C000 */
#define GPIO_MODE_MODE7                    GPIO_MODE_MODE7_Msk
#define GPIO_MODE_MODE7_0                  (0x1UL << GPIO_MODE_MODE7_Pos)                /*!< 0x00004000 */
#define GPIO_MODE_MODE7_1                  (0x2UL << GPIO_MODE_MODE7_Pos)                /*!< 0x00008000 */
#define GPIO_MODE_MODE8_Pos                (16U)
#define GPIO_MODE_MODE8_Msk                (0x3UL << GPIO_MODE_MODE8_Pos)                /*!< 0x00030000 */
#define GPIO_MODE_MODE8                    GPIO_MODE_MODE8_Msk
#define GPIO_MODE_MODE8_0                  (0x1UL << GPIO_MODE_MODE8_Pos)                /*!< 0x00010000 */
#define GPIO_MODE_MODE8_1                  (0x2UL << GPIO_MODE_MODE8_Pos)                /*!< 0x00020000 */
#define GPIO_MODE_MODE9_Pos                (18U)
#define GPIO_MODE_MODE9_Msk                (0x3UL << GPIO_MODE_MODE9_Pos)                /*!< 0x000C0000 */
#define GPIO_MODE_MODE9                    GPIO_MODE_MODE9_Msk
#define GPIO_MODE_MODE9_0                  (0x1UL << GPIO_MODE_MODE9_Pos)                /*!< 0x00040000 */
#define GPIO_MODE_MODE9_1                  (0x2UL << GPIO_MODE_MODE9_Pos)                /*!< 0x00080000 */
#define GPIO_MODE_MODE10_Pos               (20U)
#define GPIO_MODE_MODE10_Msk               (0x3UL << GPIO_MODE_MODE10_Pos)               /*!< 0x00300000 */
#define GPIO_MODE_MODE10                   GPIO_MODE_MODE10_Msk
#define GPIO_MODE_MODE10_1                 (0x1UL << GPIO_MODE_MODE10_Pos)               /*!< 0x00100000 */
#define GPIO_MODE_MODE10_2                 (0x2UL << GPIO_MODE_MODE10_Pos)               /*!< 0x00200000 */
#define GPIO_MODE_MODE11_Pos               (22U)
#define GPIO_MODE_MODE11_Msk               (0x3UL << GPIO_MODE_MODE11_Pos)               /*!< 0x00C00000 */
#define GPIO_MODE_MODE11                   GPIO_MODE_MODE11_Msk
#define GPIO_MODE_MODE11_1                 (0x1UL << GPIO_MODE_MODE11_Pos)               /*!< 0x00400000 */
#define GPIO_MODE_MODE11_2                 (0x2UL << GPIO_MODE_MODE11_Pos)               /*!< 0x00800000 */
#define GPIO_MODE_MODE12_Pos               (24U)
#define GPIO_MODE_MODE12_Msk               (0x3UL << GPIO_MODE_MODE12_Pos)               /*!< 0x03000000 */
#define GPIO_MODE_MODE12                   GPIO_MODE_MODE12_Msk
#define GPIO_MODE_MODE12_1                 (0x1UL << GPIO_MODE_MODE12_Pos)               /*!< 0x01000000 */
#define GPIO_MODE_MODE12_2                 (0x2UL << GPIO_MODE_MODE12_Pos)               /*!< 0x02000000 */
#define GPIO_MODE_MODE13_Pos               (26U)
#define GPIO_MODE_MODE13_Msk               (0x3UL << GPIO_MODE_MODE13_Pos)               /*!< 0x0C000000 */
#define GPIO_MODE_MODE13                   GPIO_MODE_MODE13_Msk
#define GPIO_MODE_MODE13_1                 (0x1UL << GPIO_MODE_MODE13_Pos)               /*!< 0x04000000 */
#define GPIO_MODE_MODE13_2                 (0x2UL << GPIO_MODE_MODE13_Pos)               /*!< 0x08000000 */
#define GPIO_MODE_MODE14_Pos               (28U)
#define GPIO_MODE_MODE14_Msk               (0x3UL << GPIO_MODE_MODE14_Pos)               /*!< 0x30000000 */
#define GPIO_MODE_MODE14                   GPIO_MODE_MODE14_Msk
#define GPIO_MODE_MODE14_1                 (0x1UL << GPIO_MODE_MODE14_Pos)               /*!< 0x10000000 */
#define GPIO_MODE_MODE14_2                 (0x2UL << GPIO_MODE_MODE14_Pos)               /*!< 0x20000000 */
#define GPIO_MODE_MODE15_Pos               (30U)
#define GPIO_MODE_MODE15_Msk               (0x3UL << GPIO_MODE_MODE15_Pos)               /*!< 0xC0000000 */
#define GPIO_MODE_MODE15                   GPIO_MODE_MODE15_Msk
#define GPIO_MODE_MODE15_1                 (0x1UL << GPIO_MODE_MODE15_Pos)               /*!< 0x40000000 */
#define GPIO_MODE_MODE15_2                 (0x2UL << GPIO_MODE_MODE15_Pos)               /*!< 0x80000000 */

/******************  Bits definition for GPIO_OMODE register  *****************/
#define GPIO_OMODE_OMODE0_Pos              (0U)
#define GPIO_OMODE_OMODE0_Msk              (0x1UL << GPIO_OMODE_OMODE0_Pos)              /*!< 0x00000001 */
#define GPIO_OMODE_OMODE0                  GPIO_OMODE_OMODE0_Msk
#define GPIO_OMODE_OMODE1_Pos              (1U)
#define GPIO_OMODE_OMODE1_Msk              (0x1UL << GPIO_OMODE_OMODE1_Pos)              /*!< 0x00000002 */
#define GPIO_OMODE_OMODE1                  GPIO_OMODE_OMODE1_Msk
#define GPIO_OMODE_OMODE2_Pos              (2U)
#define GPIO_OMODE_OMODE2_Msk              (0x1UL << GPIO_OMODE_OMODE2_Pos)              /*!< 0x00000004 */
#define GPIO_OMODE_OMODE2                  GPIO_OMODE_OMODE2_Msk
#define GPIO_OMODE_OMODE3_Pos              (3U)
#define GPIO_OMODE_OMODE3_Msk              (0x1UL << GPIO_OMODE_OMODE3_Pos)              /*!< 0x00000008 */
#define GPIO_OMODE_OMODE3                  GPIO_OMODE_OMODE3_Msk
#define GPIO_OMODE_OMODE4_Pos              (4U)
#define GPIO_OMODE_OMODE4_Msk              (0x1UL << GPIO_OMODE_OMODE4_Pos)              /*!< 0x00000010 */
#define GPIO_OMODE_OMODE4                  GPIO_OMODE_OMODE4_Msk
#define GPIO_OMODE_OMODE5_Pos              (5U)
#define GPIO_OMODE_OMODE5_Msk              (0x1UL << GPIO_OMODE_OMODE5_Pos)              /*!< 0x00000020 */
#define GPIO_OMODE_OMODE5                  GPIO_OMODE_OMODE5_Msk
#define GPIO_OMODE_OMODE6_Pos              (6U)
#define GPIO_OMODE_OMODE6_Msk              (0x1UL << GPIO_OMODE_OMODE6_Pos)              /*!< 0x00000040 */
#define GPIO_OMODE_OMODE6                  GPIO_OMODE_OMODE6_Msk
#define GPIO_OMODE_OMODE7_Pos              (7U)
#define GPIO_OMODE_OMODE7_Msk              (0x1UL << GPIO_OMODE_OMODE7_Pos)              /*!< 0x00000080 */
#define GPIO_OMODE_OMODE7                  GPIO_OMODE_OMODE7_Msk
#define GPIO_OMODE_OMODE8_Pos              (8U)
#define GPIO_OMODE_OMODE8_Msk              (0x1UL << GPIO_OMODE_OMODE8_Pos)              /*!< 0x00000100 */
#define GPIO_OMODE_OMODE8                  GPIO_OMODE_OMODE8_Msk
#define GPIO_OMODE_OMODE9_Pos              (9U)
#define GPIO_OMODE_OMODE9_Msk              (0x1UL << GPIO_OMODE_OMODE9_Pos)              /*!< 0x00000200 */
#define GPIO_OMODE_OMODE9                  GPIO_OMODE_OMODE9_Msk
#define GPIO_OMODE_OMODE10_Pos             (10U)
#define GPIO_OMODE_OMODE10_Msk             (0x1UL << GPIO_OMODE_OMODE10_Pos)             /*!< 0x00000400 */
#define GPIO_OMODE_OMODE10                 GPIO_OMODE_OMODE10_Msk
#define GPIO_OMODE_OMODE11_Pos             (11U)
#define GPIO_OMODE_OMODE11_Msk             (0x1UL << GPIO_OMODE_OMODE11_Pos)             /*!< 0x00000800 */
#define GPIO_OMODE_OMODE11                 GPIO_OMODE_OMODE11_Msk
#define GPIO_OMODE_OMODE12_Pos             (12U)
#define GPIO_OMODE_OMODE12_Msk             (0x1UL << GPIO_OMODE_OMODE12_Pos)             /*!< 0x00001000 */
#define GPIO_OMODE_OMODE12                 GPIO_OMODE_OMODE12_Msk
#define GPIO_OMODE_OMODE13_Pos             (13U)
#define GPIO_OMODE_OMODE13_Msk             (0x1UL << GPIO_OMODE_OMODE13_Pos)             /*!< 0x00002000 */
#define GPIO_OMODE_OMODE13                 GPIO_OMODE_OMODE13_Msk
#define GPIO_OMODE_OMODE14_Pos             (14U)
#define GPIO_OMODE_OMODE14_Msk             (0x1UL << GPIO_OMODE_OMODE14_Pos)             /*!< 0x00004000 */
#define GPIO_OMODE_OMODE14                 GPIO_OMODE_OMODE14_Msk
#define GPIO_OMODE_OMODE15_Pos             (15U)
#define GPIO_OMODE_OMODE15_Msk             (0x1UL << GPIO_OMODE_OMODE15_Pos)             /*!< 0x00008000 */
#define GPIO_OMODE_OMODE15                 GPIO_OMODE_OMODE15_Msk

/* Legacy defines */
#define GPIO_OMODE_OT_0                    GPIO_OMODE_OMODE0
#define GPIO_OMODE_OT_1                    GPIO_OMODE_OMODE1
#define GPIO_OMODE_OT_2                    GPIO_OMODE_OMODE2
#define GPIO_OMODE_OT_3                    GPIO_OMODE_OMODE3
#define GPIO_OMODE_OT_4                    GPIO_OMODE_OMODE4
#define GPIO_OMODE_OT_5                    GPIO_OMODE_OMODE5
#define GPIO_OMODE_OT_6                    GPIO_OMODE_OMODE6
#define GPIO_OMODE_OT_7                    GPIO_OMODE_OMODE7
#define GPIO_OMODE_OT_8                    GPIO_OMODE_OMODE8
#define GPIO_OMODE_OT_9                    GPIO_OMODE_OMODE9
#define GPIO_OMODE_OT_10                   GPIO_OMODE_OMODE10
#define GPIO_OMODE_OT_11                   GPIO_OMODE_OMODE11
#define GPIO_OMODE_OT_12                   GPIO_OMODE_OMODE12
#define GPIO_OMODE_OT_13                   GPIO_OMODE_OMODE13
#define GPIO_OMODE_OT_14                   GPIO_OMODE_OMODE14
#define GPIO_OMODE_OT_15                   GPIO_OMODE_OMODE15

/******************  Bits definition for GPIO_OSSEL register  *****************/
#define GPIO_OSSEL_OSSEL0_Pos              (0U)
#define GPIO_OSSEL_OSSEL0_Msk              (0x3UL << GPIO_OSSEL_OSSEL0_Pos)              /*!< 0x00000003 */
#define GPIO_OSSEL_OSSEL0                  GPIO_OSSEL_OSSEL0_Msk
#define GPIO_OSSEL_OSSEL0_0                (0x1UL << GPIO_OSSEL_OSSEL0_Pos)              /*!< 0x00000001 */
#define GPIO_OSSEL_OSSEL0_1                (0x2UL << GPIO_OSSEL_OSSEL0_Pos)              /*!< 0x00000000 */
#define GPIO_OSSEL_OSSEL1_Pos              (2U)
#define GPIO_OSSEL_OSSEL1_Msk              (0x3UL << GPIO_OSSEL_OSSEL1_Pos)              /*!< 0x0000000C */
#define GPIO_OSSEL_OSSEL1                  GPIO_OSSEL_OSSEL1_Msk
#define GPIO_OSSEL_OSSEL1_0                (0x1UL << GPIO_OSSEL_OSSEL1_Pos)              /*!< 0x00000004 */
#define GPIO_OSSEL_OSSEL1_1                (0x2UL << GPIO_OSSEL_OSSEL1_Pos)              /*!< 0x00000008 */
#define GPIO_OSSEL_OSSEL2_Pos              (4U)
#define GPIO_OSSEL_OSSEL2_Msk              (0x3UL << GPIO_OSSEL_OSSEL2_Pos)              /*!< 0x00000030 */
#define GPIO_OSSEL_OSSEL2                  GPIO_OSSEL_OSSEL2_Msk
#define GPIO_OSSEL_OSSEL2_0                (0x1UL << GPIO_OSSEL_OSSEL2_Pos)              /*!< 0x00000010 */
#define GPIO_OSSEL_OSSEL2_1                (0x2UL << GPIO_OSSEL_OSSEL2_Pos)              /*!< 0x00000020 */
#define GPIO_OSSEL_OSSEL3_Pos              (6U)
#define GPIO_OSSEL_OSSEL3_Msk              (0x3UL << GPIO_OSSEL_OSSEL3_Pos)              /*!< 0x000000C0 */
#define GPIO_OSSEL_OSSEL3                  GPIO_OSSEL_OSSEL3_Msk
#define GPIO_OSSEL_OSSEL3_0                (0x1UL << GPIO_OSSEL_OSSEL3_Pos)              /*!< 0x00000040 */
#define GPIO_OSSEL_OSSEL3_1                (0x2UL << GPIO_OSSEL_OSSEL3_Pos)              /*!< 0x00000080 */
#define GPIO_OSSEL_OSSEL4_Pos              (8U)
#define GPIO_OSSEL_OSSEL4_Msk              (0x3UL << GPIO_OSSEL_OSSEL4_Pos)              /*!< 0x00000300 */
#define GPIO_OSSEL_OSSEL4                  GPIO_OSSEL_OSSEL4_Msk
#define GPIO_OSSEL_OSSEL4_0                (0x1UL << GPIO_OSSEL_OSSEL4_Pos)              /*!< 0x00000100 */
#define GPIO_OSSEL_OSSEL4_1                (0x2UL << GPIO_OSSEL_OSSEL4_Pos)              /*!< 0x00000200 */
#define GPIO_OSSEL_OSSEL5_Pos              (10U)
#define GPIO_OSSEL_OSSEL5_Msk              (0x3UL << GPIO_OSSEL_OSSEL5_Pos)              /*!< 0x00000C00 */
#define GPIO_OSSEL_OSSEL5                  GPIO_OSSEL_OSSEL5_Msk
#define GPIO_OSSEL_OSSEL5_0                (0x1UL << GPIO_OSSEL_OSSEL5_Pos)              /*!< 0x00000400 */
#define GPIO_OSSEL_OSSEL5_1                (0x2UL << GPIO_OSSEL_OSSEL5_Pos)              /*!< 0x00000800 */
#define GPIO_OSSEL_OSSEL6_Pos              (12U)
#define GPIO_OSSEL_OSSEL6_Msk              (0x3UL << GPIO_OSSEL_OSSEL6_Pos)              /*!< 0x00003000 */
#define GPIO_OSSEL_OSSEL6                  GPIO_OSSEL_OSSEL6_Msk
#define GPIO_OSSEL_OSSEL6_0                (0x1UL << GPIO_OSSEL_OSSEL6_Pos)              /*!< 0x00001000 */
#define GPIO_OSSEL_OSSEL6_1                (0x2UL << GPIO_OSSEL_OSSEL6_Pos)              /*!< 0x00002000 */
#define GPIO_OSSEL_OSSEL7_Pos              (14U)
#define GPIO_OSSEL_OSSEL7_Msk              (0x3UL << GPIO_OSSEL_OSSEL7_Pos)              /*!< 0x0000C000 */
#define GPIO_OSSEL_OSSEL7                  GPIO_OSSEL_OSSEL7_Msk
#define GPIO_OSSEL_OSSEL7_0                (0x1UL << GPIO_OSSEL_OSSEL7_Pos)              /*!< 0x00004000 */
#define GPIO_OSSEL_OSSEL7_1                (0x2UL << GPIO_OSSEL_OSSEL7_Pos)              /*!< 0x00008000 */
#define GPIO_OSSEL_OSSEL8_Pos              (16U)
#define GPIO_OSSEL_OSSEL8_Msk              (0x3UL << GPIO_OSSEL_OSSEL8_Pos)              /*!< 0x00030000 */
#define GPIO_OSSEL_OSSEL8                  GPIO_OSSEL_OSSEL8_Msk
#define GPIO_OSSEL_OSSEL8_0                (0x1UL << GPIO_OSSEL_OSSEL8_Pos)              /*!< 0x00010000 */
#define GPIO_OSSEL_OSSEL8_1                (0x2UL << GPIO_OSSEL_OSSEL8_Pos)              /*!< 0x00020000 */
#define GPIO_OSSEL_OSSEL9_Pos              (18U)
#define GPIO_OSSEL_OSSEL9_Msk              (0x3UL << GPIO_OSSEL_OSSEL9_Pos)              /*!< 0x000C0000 */
#define GPIO_OSSEL_OSSEL9                  GPIO_OSSEL_OSSEL9_Msk
#define GPIO_OSSEL_OSSEL9_0                (0x1UL << GPIO_OSSEL_OSSEL9_Pos)              /*!< 0x00040000 */
#define GPIO_OSSEL_OSSEL9_1                (0x2UL << GPIO_OSSEL_OSSEL9_Pos)              /*!< 0x00080000 */
#define GPIO_OSSEL_OSSEL10_Pos             (20U)
#define GPIO_OSSEL_OSSEL10_Msk             (0x3UL << GPIO_OSSEL_OSSEL10_Pos)             /*!< 0x00300000 */
#define GPIO_OSSEL_OSSEL10                 GPIO_OSSEL_OSSEL10_Msk
#define GPIO_OSSEL_OSSEL10_0               (0x1UL << GPIO_OSSEL_OSSEL10_Pos)             /*!< 0x00100000 */
#define GPIO_OSSEL_OSSEL10_1               (0x2UL << GPIO_OSSEL_OSSEL10_Pos)             /*!< 0x00200000 */
#define GPIO_OSSEL_OSSEL11_Pos             (22U)
#define GPIO_OSSEL_OSSEL11_Msk             (0x3UL << GPIO_OSSEL_OSSEL11_Pos)             /*!< 0x00C00000 */
#define GPIO_OSSEL_OSSEL11                 GPIO_OSSEL_OSSEL11_Msk
#define GPIO_OSSEL_OSSEL11_0               (0x1UL << GPIO_OSSEL_OSSEL11_Pos)             /*!< 0x00400000 */
#define GPIO_OSSEL_OSSEL11_1               (0x2UL << GPIO_OSSEL_OSSEL11_Pos)             /*!< 0x00800000 */
#define GPIO_OSSEL_OSSEL12_Pos             (24U)
#define GPIO_OSSEL_OSSEL12_Msk             (0x3UL << GPIO_OSSEL_OSSEL12_Pos)             /*!< 0x03000000 */
#define GPIO_OSSEL_OSSEL12                 GPIO_OSSEL_OSSEL12_Msk
#define GPIO_OSSEL_OSSEL12_0               (0x1UL << GPIO_OSSEL_OSSEL12_Pos)             /*!< 0x01000000 */
#define GPIO_OSSEL_OSSEL12_1               (0x2UL << GPIO_OSSEL_OSSEL12_Pos)             /*!< 0x02000000 */
#define GPIO_OSSEL_OSSEL13_Pos             (26U)
#define GPIO_OSSEL_OSSEL13_Msk             (0x3UL << GPIO_OSSEL_OSSEL13_Pos)             /*!< 0x0C000000 */
#define GPIO_OSSEL_OSSEL13                 GPIO_OSSEL_OSSEL13_Msk
#define GPIO_OSSEL_OSSEL13_0               (0x1UL << GPIO_OSSEL_OSSEL13_Pos)             /*!< 0x04000000 */
#define GPIO_OSSEL_OSSEL13_1               (0x2UL << GPIO_OSSEL_OSSEL13_Pos)             /*!< 0x08000000 */
#define GPIO_OSSEL_OSSEL14_Pos             (28U)
#define GPIO_OSSEL_OSSEL14_Msk             (0x3UL << GPIO_OSSEL_OSSEL14_Pos)             /*!< 0x30000000 */
#define GPIO_OSSEL_OSSEL14                 GPIO_OSSEL_OSSEL14_Msk
#define GPIO_OSSEL_OSSEL14_0               (0x1UL << GPIO_OSSEL_OSSEL14_Pos)             /*!< 0x10000000 */
#define GPIO_OSSEL_OSSEL14_1               (0x2UL << GPIO_OSSEL_OSSEL14_Pos)             /*!< 0x20000000 */
#define GPIO_OSSEL_OSSEL15_Pos             (30U)
#define GPIO_OSSEL_OSSEL15_Msk             (0x3UL << GPIO_OSSEL_OSSEL15_Pos)             /*!< 0xC0000000 */
#define GPIO_OSSEL_OSSEL15                 GPIO_OSSEL_OSSEL15_Msk
#define GPIO_OSSEL_OSSEL15_0               (0x1UL << GPIO_OSSEL_OSSEL15_Pos)             /*!< 0x40000000 */
#define GPIO_OSSEL_OSSEL15_1               (0x2UL << GPIO_OSSEL_OSSEL15_Pos)             /*!< 0x80000000 */

/* Legacy defines */
#define GPIO_OSPEEDER_OSPEEDR0             GPIO_OSSEL_OSSEL0
#define GPIO_OSPEEDER_OSPEEDR0_0           GPIO_OSSEL_OSSEL0_0
#define GPIO_OSPEEDER_OSPEEDR0_1           GPIO_OSSEL_OSSEL0_1
#define GPIO_OSPEEDER_OSPEEDR1             GPIO_OSSEL_OSSEL1
#define GPIO_OSPEEDER_OSPEEDR1_0           GPIO_OSSEL_OSSEL1_0
#define GPIO_OSPEEDER_OSPEEDR1_1           GPIO_OSSEL_OSSEL1_1
#define GPIO_OSPEEDER_OSPEEDR2             GPIO_OSSEL_OSSEL2
#define GPIO_OSPEEDER_OSPEEDR2_0           GPIO_OSSEL_OSSEL2_0
#define GPIO_OSPEEDER_OSPEEDR2_1           GPIO_OSSEL_OSSEL2_1
#define GPIO_OSPEEDER_OSPEEDR3             GPIO_OSSEL_OSSEL3
#define GPIO_OSPEEDER_OSPEEDR3_0           GPIO_OSSEL_OSSEL3_0
#define GPIO_OSPEEDER_OSPEEDR3_1           GPIO_OSSEL_OSSEL3_1
#define GPIO_OSPEEDER_OSPEEDR4             GPIO_OSSEL_OSSEL4
#define GPIO_OSPEEDER_OSPEEDR4_0           GPIO_OSSEL_OSSEL4_0
#define GPIO_OSPEEDER_OSPEEDR4_1           GPIO_OSSEL_OSSEL4_1
#define GPIO_OSPEEDER_OSPEEDR5             GPIO_OSSEL_OSSEL5
#define GPIO_OSPEEDER_OSPEEDR5_0           GPIO_OSSEL_OSSEL5_0
#define GPIO_OSPEEDER_OSPEEDR5_1           GPIO_OSSEL_OSSEL5_1
#define GPIO_OSPEEDER_OSPEEDR6             GPIO_OSSEL_OSSEL6
#define GPIO_OSPEEDER_OSPEEDR6_0           GPIO_OSSEL_OSSEL6_0
#define GPIO_OSPEEDER_OSPEEDR6_1           GPIO_OSSEL_OSSEL6_1
#define GPIO_OSPEEDER_OSPEEDR7             GPIO_OSSEL_OSSEL7
#define GPIO_OSPEEDER_OSPEEDR7_0           GPIO_OSSEL_OSSEL7_0
#define GPIO_OSPEEDER_OSPEEDR7_1           GPIO_OSSEL_OSSEL7_1
#define GPIO_OSPEEDER_OSPEEDR8             GPIO_OSSEL_OSSEL8
#define GPIO_OSPEEDER_OSPEEDR8_0           GPIO_OSSEL_OSSEL8_0
#define GPIO_OSPEEDER_OSPEEDR8_1           GPIO_OSSEL_OSSEL8_1
#define GPIO_OSPEEDER_OSPEEDR9             GPIO_OSSEL_OSSEL9
#define GPIO_OSPEEDER_OSPEEDR9_0           GPIO_OSSEL_OSSEL9_0
#define GPIO_OSPEEDER_OSPEEDR9_1           GPIO_OSSEL_OSSEL9_1
#define GPIO_OSPEEDER_OSPEEDR10            GPIO_OSSEL_OSSEL10
#define GPIO_OSPEEDER_OSPEEDR10_0          GPIO_OSSEL_OSSEL10_0
#define GPIO_OSPEEDER_OSPEEDR10_1          GPIO_OSSEL_OSSEL10_1
#define GPIO_OSPEEDER_OSPEEDR11            GPIO_OSSEL_OSSEL11
#define GPIO_OSPEEDER_OSPEEDR11_0          GPIO_OSSEL_OSSEL11_0
#define GPIO_OSPEEDER_OSPEEDR11_1          GPIO_OSSEL_OSSEL11_1
#define GPIO_OSPEEDER_OSPEEDR12            GPIO_OSSEL_OSSEL12
#define GPIO_OSPEEDER_OSPEEDR12_0          GPIO_OSSEL_OSSEL12_0
#define GPIO_OSPEEDER_OSPEEDR12_1          GPIO_OSSEL_OSSEL12_1
#define GPIO_OSPEEDER_OSPEEDR13            GPIO_OSSEL_OSSEL13
#define GPIO_OSPEEDER_OSPEEDR13_0          GPIO_OSSEL_OSSEL13_0
#define GPIO_OSPEEDER_OSPEEDR13_1          GPIO_OSSEL_OSSEL13_1
#define GPIO_OSPEEDER_OSPEEDR14            GPIO_OSSEL_OSSEL14
#define GPIO_OSPEEDER_OSPEEDR14_0          GPIO_OSSEL_OSSEL14_0
#define GPIO_OSPEEDER_OSPEEDR14_1          GPIO_OSSEL_OSSEL14_1
#define GPIO_OSPEEDER_OSPEEDR15            GPIO_OSSEL_OSSEL15
#define GPIO_OSPEEDER_OSPEEDR15_0          GPIO_OSSEL_OSSEL15_0
#define GPIO_OSPEEDER_OSPEEDR15_1          GPIO_OSSEL_OSSEL15_1

/******************  Bits definition for GPIO_PUPD register  ******************/
#define GPIO_PUPD_PUPD0_Pos                (0U)
#define GPIO_PUPD_PUPD0_Msk                (0x3UL << GPIO_PUPD_PUPD0_Pos)                /*!< 0x00000003 */
#define GPIO_PUPD_PUPD0                    GPIO_PUPD_PUPD0_Msk
#define GPIO_PUPD_PUPD0_0                  (0x1UL << GPIO_PUPD_PUPD0_Pos)                /*!< 0x00000001 */
#define GPIO_PUPD_PUPD1_Pos                (2U)
#define GPIO_PUPD_PUPD1_Msk                (0x3UL << GPIO_PUPD_PUPD1_Pos)                /*!< 0x0000000C */
#define GPIO_PUPD_PUPD1                    GPIO_PUPD_PUPD1_Msk
#define GPIO_PUPD_PUPD1_0                  (0x1UL << GPIO_PUPD_PUPD1_Pos)                /*!< 0x00000004 */
#define GPIO_PUPD_PUPD2_Pos                (4U)
#define GPIO_PUPD_PUPD2_Msk                (0x3UL << GPIO_PUPD_PUPD2_Pos)                /*!< 0x00000030 */
#define GPIO_PUPD_PUPD2                    GPIO_PUPD_PUPD2_Msk
#define GPIO_PUPD_PUPD2_0                  (0x1UL << GPIO_PUPD_PUPD2_Pos)                /*!< 0x00000010 */
#define GPIO_PUPD_PUPD3_Pos                (6U)
#define GPIO_PUPD_PUPD3_Msk                (0x3UL << GPIO_PUPD_PUPD3_Pos)                /*!< 0x000000C0 */
#define GPIO_PUPD_PUPD3                    GPIO_PUPD_PUPD3_Msk
#define GPIO_PUPD_PUPD3_0                  (0x1UL << GPIO_PUPD_PUPD3_Pos)                /*!< 0x00000040 */
#define GPIO_PUPD_PUPD4_Pos                (8U)
#define GPIO_PUPD_PUPD4_Msk                (0x3UL << GPIO_PUPD_PUPD4_Pos)                /*!< 0x00000300 */
#define GPIO_PUPD_PUPD4                    GPIO_PUPD_PUPD4_Msk
#define GPIO_PUPD_PUPD4_0                  (0x1UL << GPIO_PUPD_PUPD4_Pos)                /*!< 0x00000100 */
#define GPIO_PUPD_PUPD5_Pos                (10U)
#define GPIO_PUPD_PUPD5_Msk                (0x3UL << GPIO_PUPD_PUPD5_Pos)                /*!< 0x00000C00 */
#define GPIO_PUPD_PUPD5                    GPIO_PUPD_PUPD5_Msk
#define GPIO_PUPD_PUPD5_0                  (0x1UL << GPIO_PUPD_PUPD5_Pos)                /*!< 0x00000400 */
#define GPIO_PUPD_PUPD6_Pos                (12U)
#define GPIO_PUPD_PUPD6_Msk                (0x3UL << GPIO_PUPD_PUPD6_Pos)                /*!< 0x00003000 */
#define GPIO_PUPD_PUPD6                    GPIO_PUPD_PUPD6_Msk
#define GPIO_PUPD_PUPD6_0                  (0x1UL << GPIO_PUPD_PUPD6_Pos)                /*!< 0x00001000 */
#define GPIO_PUPD_PUPD7_Pos                (14U)
#define GPIO_PUPD_PUPD7_Msk                (0x3UL << GPIO_PUPD_PUPD7_Pos)                /*!< 0x0000C000 */
#define GPIO_PUPD_PUPD7                    GPIO_PUPD_PUPD7_Msk
#define GPIO_PUPD_PUPD7_0                  (0x1UL << GPIO_PUPD_PUPD7_Pos)                /*!< 0x00004000 */
#define GPIO_PUPD_PUPD8_Pos                (16U)
#define GPIO_PUPD_PUPD8_Msk                (0x3UL << GPIO_PUPD_PUPD8_Pos)                /*!< 0x00030000 */
#define GPIO_PUPD_PUPD8                    GPIO_PUPD_PUPD8_Msk
#define GPIO_PUPD_PUPD8_0                  (0x1UL << GPIO_PUPD_PUPD8_Pos)                /*!< 0x00010000 */
#define GPIO_PUPD_PUPD9_Pos                (18U)
#define GPIO_PUPD_PUPD9_Msk                (0x3UL << GPIO_PUPD_PUPD9_Pos)                /*!< 0x000C0000 */
#define GPIO_PUPD_PUPD9                    GPIO_PUPD_PUPD9_Msk
#define GPIO_PUPD_PUPD9_0                  (0x1UL << GPIO_PUPD_PUPD9_Pos)                /*!< 0x00040000 */
#define GPIO_PUPD_PUPD10_Pos               (20U)
#define GPIO_PUPD_PUPD10_Msk               (0x3UL << GPIO_PUPD_PUPD10_Pos)               /*!< 0x00300000 */
#define GPIO_PUPD_PUPD10                   GPIO_PUPD_PUPD10_Msk
#define GPIO_PUPD_PUPD10_0                 (0x1UL << GPIO_PUPD_PUPD10_Pos)               /*!< 0x00100000 */
#define GPIO_PUPD_PUPD10_1                 (0x2UL << GPIO_PUPD_PUPD10_Pos)               /*!< 0x00200000 */
#define GPIO_PUPD_PUPD11_Pos               (22U)
#define GPIO_PUPD_PUPD11_Msk               (0x3UL << GPIO_PUPD_PUPD11_Pos)               /*!< 0x00C00000 */
#define GPIO_PUPD_PUPD11                   GPIO_PUPD_PUPD11_Msk
#define GPIO_PUPD_PUPD11_0                 (0x1UL << GPIO_PUPD_PUPD11_Pos)               /*!< 0x00400000 */
#define GPIO_PUPD_PUPD12_Pos               (24U)
#define GPIO_PUPD_PUPD12_Msk               (0x3UL << GPIO_PUPD_PUPD12_Pos)               /*!< 0x03000000 */
#define GPIO_PUPD_PUPD12                   GPIO_PUPD_PUPD12_Msk
#define GPIO_PUPD_PUPD12_0                 (0x1UL << GPIO_PUPD_PUPD12_Pos)               /*!< 0x01000000 */
#define GPIO_PUPD_PUPD13_Pos               (26U)
#define GPIO_PUPD_PUPD13_Msk               (0x3UL << GPIO_PUPD_PUPD13_Pos)               /*!< 0x0C000000 */
#define GPIO_PUPD_PUPD13                   GPIO_PUPD_PUPD13_Msk
#define GPIO_PUPD_PUPD13_0                 (0x1UL << GPIO_PUPD_PUPD13_Pos)               /*!< 0x04000000 */
#define GPIO_PUPD_PUPD14_Pos               (28U)
#define GPIO_PUPD_PUPD14_Msk               (0x3UL << GPIO_PUPD_PUPD14_Pos)               /*!< 0x30000000 */
#define GPIO_PUPD_PUPD14                   GPIO_PUPD_PUPD14_Msk
#define GPIO_PUPD_PUPD14_0                 (0x1UL << GPIO_PUPD_PUPD14_Pos)               /*!< 0x10000000 */
#define GPIO_PUPD_PUPD15_Pos               (30U)
#define GPIO_PUPD_PUPD15_Msk               (0x3UL << GPIO_PUPD_PUPD15_Pos)               /*!< 0xC0000000 */
#define GPIO_PUPD_PUPD15                   GPIO_PUPD_PUPD15_Msk
#define GPIO_PUPD_PUPD15_0                 (0x1UL << GPIO_PUPD_PUPD15_Pos)               /*!< 0x40000000 */

/* Legacy defines */
#define GPIO_PUPD_PUPDR0                   GPIO_PUPD_PUPD0
#define GPIO_PUPD_PUPDR0_0                 GPIO_PUPD_PUPD0_0
#define GPIO_PUPD_PUPDR1                   GPIO_PUPD_PUPD1
#define GPIO_PUPD_PUPDR1_0                 GPIO_PUPD_PUPD1_0
#define GPIO_PUPD_PUPDR2                   GPIO_PUPD_PUPD2
#define GPIO_PUPD_PUPDR2_0                 GPIO_PUPD_PUPD2_0
#define GPIO_PUPD_PUPDR3                   GPIO_PUPD_PUPD3
#define GPIO_PUPD_PUPDR3_0                 GPIO_PUPD_PUPD3_0
#define GPIO_PUPD_PUPDR4                   GPIO_PUPD_PUPD4
#define GPIO_PUPD_PUPDR4_0                 GPIO_PUPD_PUPD4_0
#define GPIO_PUPD_PUPDR5                   GPIO_PUPD_PUPD5
#define GPIO_PUPD_PUPDR5_0                 GPIO_PUPD_PUPD5_0
#define GPIO_PUPD_PUPDR6                   GPIO_PUPD_PUPD6
#define GPIO_PUPD_PUPDR6_0                 GPIO_PUPD_PUPD6_0
#define GPIO_PUPD_PUPDR7                   GPIO_PUPD_PUPD7
#define GPIO_PUPD_PUPDR7_0                 GPIO_PUPD_PUPD7_0
#define GPIO_PUPD_PUPDR8                   GPIO_PUPD_PUPD8
#define GPIO_PUPD_PUPDR8_0                 GPIO_PUPD_PUPD8_0
#define GPIO_PUPD_PUPDR9                   GPIO_PUPD_PUPD9
#define GPIO_PUPD_PUPDR9_0                 GPIO_PUPD_PUPD9_0
#define GPIO_PUPD_PUPDR10                  GPIO_PUPD_PUPD10
#define GPIO_PUPD_PUPDR10_0                GPIO_PUPD_PUPD10_0
#define GPIO_PUPD_PUPDR10_1                GPIO_PUPD_PUPD10_1
#define GPIO_PUPD_PUPDR11                  GPIO_PUPD_PUPD11
#define GPIO_PUPD_PUPDR11_0                GPIO_PUPD_PUPD11_0
#define GPIO_PUPD_PUPDR11_1                GPIO_PUPD_PUPD11_1
#define GPIO_PUPD_PUPDR12                  GPIO_PUPD_PUPD12
#define GPIO_PUPD_PUPDR12_0                GPIO_PUPD_PUPD12_0
#define GPIO_PUPD_PUPDR12_1                GPIO_PUPD_PUPD12_1
#define GPIO_PUPD_PUPDR13                  GPIO_PUPD_PUPD13
#define GPIO_PUPD_PUPDR13_0                GPIO_PUPD_PUPD13_0
#define GPIO_PUPD_PUPDR13_1                GPIO_PUPD_PUPD13_1
#define GPIO_PUPD_PUPDR14                  GPIO_PUPD_PUPD14
#define GPIO_PUPD_PUPDR14_0                GPIO_PUPD_PUPD14_0
#define GPIO_PUPD_PUPDR14_1                GPIO_PUPD_PUPD14_1
#define GPIO_PUPD_PUPDR15                  GPIO_PUPD_PUPD15
#define GPIO_PUPD_PUPDR15_0                GPIO_PUPD_PUPD15_0
#define GPIO_PUPD_PUPDR15_1                GPIO_PUPD_PUPD15_1

/******************  Bits definition for GPIO_IDATA register  *****************/
#define GPIO_IDATA_IDATA0_Pos              (0U)
#define GPIO_IDATA_IDATA0_Msk              (0x1UL << GPIO_IDATA_IDATA0_Pos)              /*!< 0x00000001 */
#define GPIO_IDATA_IDATA0                  GPIO_IDATA_IDATA0_Msk
#define GPIO_IDATA_IDATA1_Pos              (1U)
#define GPIO_IDATA_IDATA1_Msk              (0x1UL << GPIO_IDATA_IDATA1_Pos)              /*!< 0x00000000 */
#define GPIO_IDATA_IDATA1                  GPIO_IDATA_IDATA1_Msk
#define GPIO_IDATA_IDATA2_Pos              (2U)
#define GPIO_IDATA_IDATA2_Msk              (0x1UL << GPIO_IDATA_IDATA2_Pos)              /*!< 0x00000004 */
#define GPIO_IDATA_IDATA2                  GPIO_IDATA_IDATA2_Msk
#define GPIO_IDATA_IDATA3_Pos              (3U)
#define GPIO_IDATA_IDATA3_Msk              (0x1UL << GPIO_IDATA_IDATA3_Pos)              /*!< 0x00000008 */
#define GPIO_IDATA_IDATA3                  GPIO_IDATA_IDATA3_Msk
#define GPIO_IDATA_IDATA4_Pos              (4U)
#define GPIO_IDATA_IDATA4_Msk              (0x1UL << GPIO_IDATA_IDATA4_Pos)              /*!< 0x00000010 */
#define GPIO_IDATA_IDATA4                  GPIO_IDATA_IDATA4_Msk
#define GPIO_IDATA_IDATA5_Pos              (5U)
#define GPIO_IDATA_IDATA5_Msk              (0x1UL << GPIO_IDATA_IDATA5_Pos)              /*!< 0x00000020 */
#define GPIO_IDATA_IDATA5                  GPIO_IDATA_IDATA5_Msk
#define GPIO_IDATA_IDATA6_Pos              (6U)
#define GPIO_IDATA_IDATA6_Msk              (0x1UL << GPIO_IDATA_IDATA6_Pos)              /*!< 0x00000040 */
#define GPIO_IDATA_IDATA6                  GPIO_IDATA_IDATA6_Msk
#define GPIO_IDATA_IDATA7_Pos              (7U)
#define GPIO_IDATA_IDATA7_Msk              (0x1UL << GPIO_IDATA_IDATA7_Pos)              /*!< 0x00000080 */
#define GPIO_IDATA_IDATA7                  GPIO_IDATA_IDATA7_Msk
#define GPIO_IDATA_IDATA8_Pos              (8U)
#define GPIO_IDATA_IDATA8_Msk              (0x1UL << GPIO_IDATA_IDATA8_Pos)              /*!< 0x00000100 */
#define GPIO_IDATA_IDATA8                  GPIO_IDATA_IDATA8_Msk
#define GPIO_IDATA_IDATA9_Pos              (9U)
#define GPIO_IDATA_IDATA9_Msk              (0x1UL << GPIO_IDATA_IDATA9_Pos)              /*!< 0x00000200 */
#define GPIO_IDATA_IDATA9                  GPIO_IDATA_IDATA9_Msk
#define GPIO_IDATA_IDATA10_Pos             (10U)
#define GPIO_IDATA_IDATA10_Msk             (0x1UL << GPIO_IDATA_IDATA10_Pos)             /*!< 0x00000400 */
#define GPIO_IDATA_IDATA10                 GPIO_IDATA_IDATA10_Msk
#define GPIO_IDATA_IDATA11_Pos             (11U)
#define GPIO_IDATA_IDATA11_Msk             (0x1UL << GPIO_IDATA_IDATA11_Pos)             /*!< 0x00000800 */
#define GPIO_IDATA_IDATA11                 GPIO_IDATA_IDATA11_Msk
#define GPIO_IDATA_IDATA12_Pos             (12U)
#define GPIO_IDATA_IDATA12_Msk             (0x1UL << GPIO_IDATA_IDATA12_Pos)             /*!< 0x00001000 */
#define GPIO_IDATA_IDATA12                 GPIO_IDATA_IDATA12_Msk
#define GPIO_IDATA_IDATA13_Pos             (13U)
#define GPIO_IDATA_IDATA13_Msk             (0x1UL << GPIO_IDATA_IDATA13_Pos)             /*!< 0x00002000 */
#define GPIO_IDATA_IDATA13                 GPIO_IDATA_IDATA13_Msk
#define GPIO_IDATA_IDATA14_Pos             (14U)
#define GPIO_IDATA_IDATA14_Msk             (0x1UL << GPIO_IDATA_IDATA14_Pos)             /*!< 0x00004000 */
#define GPIO_IDATA_IDATA14                 GPIO_IDATA_IDATA14_Msk
#define GPIO_IDATA_IDATA15_Pos             (15U)
#define GPIO_IDATA_IDATA15_Msk             (0x1UL << GPIO_IDATA_IDATA15_Pos)             /*!< 0x00008000 */
#define GPIO_IDATA_IDATA15                 GPIO_IDATA_IDATA15_Msk

/* Legacy defines */
#define GPIO_IDATA_IDR_0                   GPIO_IDATA_IDATA0
#define GPIO_IDATA_IDR_1                   GPIO_IDATA_IDATA1
#define GPIO_IDATA_IDR_2                   GPIO_IDATA_IDATA2
#define GPIO_IDATA_IDR_3                   GPIO_IDATA_IDATA3
#define GPIO_IDATA_IDR_4                   GPIO_IDATA_IDATA4
#define GPIO_IDATA_IDR_5                   GPIO_IDATA_IDATA5
#define GPIO_IDATA_IDR_6                   GPIO_IDATA_IDATA6
#define GPIO_IDATA_IDR_7                   GPIO_IDATA_IDATA7
#define GPIO_IDATA_IDR_8                   GPIO_IDATA_IDATA8
#define GPIO_IDATA_IDR_9                   GPIO_IDATA_IDATA9
#define GPIO_IDATA_IDR_10                  GPIO_IDATA_IDATA10
#define GPIO_IDATA_IDR_11                  GPIO_IDATA_IDATA11
#define GPIO_IDATA_IDR_12                  GPIO_IDATA_IDATA12
#define GPIO_IDATA_IDR_13                  GPIO_IDATA_IDATA13
#define GPIO_IDATA_IDR_14                  GPIO_IDATA_IDATA14
#define GPIO_IDATA_IDR_15                  GPIO_IDATA_IDATA15

/******************  Bits definition for GPIO_ODATA register  *****************/
#define GPIO_ODATA_ODATA0_Pos              (0U)
#define GPIO_ODATA_ODATA0_Msk              (0x1UL << GPIO_ODATA_ODATA0_Pos)              /*!< 0x00000001 */
#define GPIO_ODATA_ODATA0                  GPIO_ODATA_ODATA0_Msk
#define GPIO_ODATA_ODATA1_Pos              (1U)
#define GPIO_ODATA_ODATA1_Msk              (0x1UL << GPIO_ODATA_ODATA1_Pos)              /*!< 0x00000002 */
#define GPIO_ODATA_ODATA1                  GPIO_ODATA_ODATA1_Msk
#define GPIO_ODATA_ODATA2_Pos              (2U)
#define GPIO_ODATA_ODATA2_Msk              (0x1UL << GPIO_ODATA_ODATA2_Pos)              /*!< 0x00000004 */
#define GPIO_ODATA_ODATA2                  GPIO_ODATA_ODATA2_Msk
#define GPIO_ODATA_ODATA3_Pos              (3U)
#define GPIO_ODATA_ODATA3_Msk              (0x1UL << GPIO_ODATA_ODATA3_Pos)              /*!< 0x00000008 */
#define GPIO_ODATA_ODATA3                  GPIO_ODATA_ODATA3_Msk
#define GPIO_ODATA_ODATA4_Pos              (4U)
#define GPIO_ODATA_ODATA4_Msk              (0x1UL << GPIO_ODATA_ODATA4_Pos)              /*!< 0x00000010 */
#define GPIO_ODATA_ODATA4                  GPIO_ODATA_ODATA4_Msk
#define GPIO_ODATA_ODATA5_Pos              (5U)
#define GPIO_ODATA_ODATA5_Msk              (0x1UL << GPIO_ODATA_ODATA5_Pos)              /*!< 0x00000020 */
#define GPIO_ODATA_ODATA5                  GPIO_ODATA_ODATA5_Msk
#define GPIO_ODATA_ODATA6_Pos              (6U)
#define GPIO_ODATA_ODATA6_Msk              (0x1UL << GPIO_ODATA_ODATA6_Pos)              /*!< 0x00000040 */
#define GPIO_ODATA_ODATA6                  GPIO_ODATA_ODATA6_Msk
#define GPIO_ODATA_ODATA7_Pos              (7U)
#define GPIO_ODATA_ODATA7_Msk              (0x1UL << GPIO_ODATA_ODATA7_Pos)              /*!< 0x00000080 */
#define GPIO_ODATA_ODATA7                  GPIO_ODATA_ODATA7_Msk
#define GPIO_ODATA_ODATA8_Pos              (8U)
#define GPIO_ODATA_ODATA8_Msk              (0x1UL << GPIO_ODATA_ODATA8_Pos)              /*!< 0x00000100 */
#define GPIO_ODATA_ODATA8                  GPIO_ODATA_ODATA8_Msk
#define GPIO_ODATA_ODATA9_Pos              (9U)
#define GPIO_ODATA_ODATA9_Msk              (0x1UL << GPIO_ODATA_ODATA9_Pos)              /*!< 0x00000200 */
#define GPIO_ODATA_ODATA9                  GPIO_ODATA_ODATA9_Msk
#define GPIO_ODATA_ODATA10_Pos             (10U)
#define GPIO_ODATA_ODATA10_Msk             (0x1UL << GPIO_ODATA_ODATA10_Pos)             /*!< 0x00000400 */
#define GPIO_ODATA_ODATA10                 GPIO_ODATA_ODATA10_Msk
#define GPIO_ODATA_ODATA11_Pos             (11U)
#define GPIO_ODATA_ODATA11_Msk             (0x1UL << GPIO_ODATA_ODATA11_Pos)             /*!< 0x00000800 */
#define GPIO_ODATA_ODATA11                 GPIO_ODATA_ODATA11_Msk
#define GPIO_ODATA_ODATA12_Pos             (12U)
#define GPIO_ODATA_ODATA12_Msk             (0x1UL << GPIO_ODATA_ODATA12_Pos)             /*!< 0x00001000 */
#define GPIO_ODATA_ODATA12                 GPIO_ODATA_ODATA12_Msk
#define GPIO_ODATA_ODATA13_Pos             (13U)
#define GPIO_ODATA_ODATA13_Msk             (0x1UL << GPIO_ODATA_ODATA13_Pos)             /*!< 0x00002000 */
#define GPIO_ODATA_ODATA13                 GPIO_ODATA_ODATA13_Msk
#define GPIO_ODATA_ODATA14_Pos             (14U)
#define GPIO_ODATA_ODATA14_Msk             (0x1UL << GPIO_ODATA_ODATA14_Pos)             /*!< 0x00004000 */
#define GPIO_ODATA_ODATA14                 GPIO_ODATA_ODATA14_Msk
#define GPIO_ODATA_ODATA15_Pos             (15U)
#define GPIO_ODATA_ODATA15_Msk             (0x1UL << GPIO_ODATA_ODATA15_Pos)             /*!< 0x00008000 */
#define GPIO_ODATA_ODATA15                 GPIO_ODATA_ODATA15_Msk
/* Legacy defines */
#define GPIO_ODATA_ODR_0                   GPIO_ODATA_ODATA0
#define GPIO_ODATA_ODR_1                   GPIO_ODATA_ODATA1
#define GPIO_ODATA_ODR_2                   GPIO_ODATA_ODATA2
#define GPIO_ODATA_ODR_3                   GPIO_ODATA_ODATA3
#define GPIO_ODATA_ODR_4                   GPIO_ODATA_ODATA4
#define GPIO_ODATA_ODR_5                   GPIO_ODATA_ODATA5
#define GPIO_ODATA_ODR_6                   GPIO_ODATA_ODATA6
#define GPIO_ODATA_ODR_7                   GPIO_ODATA_ODATA7
#define GPIO_ODATA_ODR_8                   GPIO_ODATA_ODATA8
#define GPIO_ODATA_ODR_9                   GPIO_ODATA_ODATA9
#define GPIO_ODATA_ODR_10                  GPIO_ODATA_ODATA10
#define GPIO_ODATA_ODR_11                  GPIO_ODATA_ODATA11
#define GPIO_ODATA_ODR_12                  GPIO_ODATA_ODATA12
#define GPIO_ODATA_ODR_13                  GPIO_ODATA_ODATA13
#define GPIO_ODATA_ODR_14                  GPIO_ODATA_ODATA14
#define GPIO_ODATA_ODR_15                  GPIO_ODATA_ODATA15

/****************** Bit definition for GPIO_ALF register **********************/
#define GPIO_ALF_ALFSEL0_Pos               (0U)
#define GPIO_ALF_ALFSEL0_Msk               (0x3UL << GPIO_ALF_ALFSEL0_Pos)               /*!< 0x00000003 */
#define GPIO_ALF_ALFSEL0                   GPIO_ALF_ALFSEL0_Msk
#define GPIO_ALF_ALFSEL0_0                 (0x1UL << GPIO_ALF_ALFSEL0_Pos)               /*!< 0x00000001 */
#define GPIO_ALF_ALFSEL0_1                 (0x2UL << GPIO_ALF_ALFSEL0_Pos)               /*!< 0x00000002 */
#define GPIO_ALF_ALFSEL1_Pos               (2U)
#define GPIO_ALF_ALFSEL1_Msk               (0x3UL << GPIO_ALF_ALFSEL1_Pos)               /*!< 0x0000000C */
#define GPIO_ALF_ALFSEL1                   GPIO_ALF_ALFSEL1_Msk
#define GPIO_ALF_ALFSEL1_0                 (0x1UL << GPIO_ALF_ALFSEL1_Pos)               /*!< 0x00000004 */
#define GPIO_ALF_ALFSEL1_1                 (0x2UL << GPIO_ALF_ALFSEL1_Pos)               /*!< 0x00000008 */
#define GPIO_ALF_ALFSEL2_Pos               (4U)
#define GPIO_ALF_ALFSEL2_Msk               (0x3UL << GPIO_ALF_ALFSEL2_Pos)               /*!< 0x00000030 */
#define GPIO_ALF_ALFSEL2                   GPIO_ALF_ALFSEL2_Msk
#define GPIO_ALF_ALFSEL2_0                 (0x1UL << GPIO_ALF_ALFSEL2_Pos)               /*!< 0x00000010 */
#define GPIO_ALF_ALFSEL2_1                 (0x2UL << GPIO_ALF_ALFSEL2_Pos)               /*!< 0x00000020 */
#define GPIO_ALF_ALFSEL3_Pos               (6U)
#define GPIO_ALF_ALFSEL3_Msk               (0x3UL << GPIO_ALF_ALFSEL3_Pos)               /*!< 0x000000C0 */
#define GPIO_ALF_ALFSEL3                   GPIO_ALF_ALFSEL3_Msk
#define GPIO_ALF_ALFSEL3_0                 (0x1UL << GPIO_ALF_ALFSEL3_Pos)               /*!< 0x00000040 */
#define GPIO_ALF_ALFSEL3_1                 (0x2UL << GPIO_ALF_ALFSEL3_Pos)               /*!< 0x00000080 */
#define GPIO_ALF_ALFSEL4_Pos               (8U)
#define GPIO_ALF_ALFSEL4_Msk               (0x3UL << GPIO_ALF_ALFSEL4_Pos)               /*!< 0x00000300 */
#define GPIO_ALF_ALFSEL4                   GPIO_ALF_ALFSEL4_Msk
#define GPIO_ALF_ALFSEL4_0                 (0x1UL << GPIO_ALF_ALFSEL4_Pos)               /*!< 0x00000100 */
#define GPIO_ALF_ALFSEL4_1                 (0x2UL << GPIO_ALF_ALFSEL4_Pos)               /*!< 0x00000200 */
#define GPIO_ALF_ALFSEL5_Pos               (10U)
#define GPIO_ALF_ALFSEL5_Msk               (0x3UL << GPIO_ALF_ALFSEL5_Pos)               /*!< 0x00000C00 */
#define GPIO_ALF_ALFSEL5                   GPIO_ALF_ALFSEL5_Msk
#define GPIO_ALF_ALFSEL5_0                 (0x1UL << GPIO_ALF_ALFSEL5_Pos)               /*!< 0x00000400 */
#define GPIO_ALF_ALFSEL5_1                 (0x2UL << GPIO_ALF_ALFSEL5_Pos)               /*!< 0x00000800 */
#define GPIO_ALF_ALFSEL6_Pos               (12U)
#define GPIO_ALF_ALFSEL6_Msk               (0x3UL << GPIO_ALF_ALFSEL6_Pos)               /*!< 0x00003000 */
#define GPIO_ALF_ALFSEL6                   GPIO_ALF_ALFSEL6_Msk
#define GPIO_ALF_ALFSEL6_0                 (0x1UL << GPIO_ALF_ALFSEL6_Pos)               /*!< 0x00001000 */
#define GPIO_ALF_ALFSEL6_1                 (0x2UL << GPIO_ALF_ALFSEL6_Pos)               /*!< 0x00002000 */
#define GPIO_ALF_ALFSEL7_Pos               (14U)
#define GPIO_ALF_ALFSEL7_Msk               (0x3UL << GPIO_ALF_ALFSEL7_Pos)               /*!< 0x0000C000 */
#define GPIO_ALF_ALFSEL7                   GPIO_ALF_ALFSEL7_Msk
#define GPIO_ALF_ALFSEL7_0                 (0x1UL << GPIO_ALF_ALFSEL7_Pos)               /*!< 0x00004000 */
#define GPIO_ALF_ALFSEL7_1                 (0x2UL << GPIO_ALF_ALFSEL7_Pos)               /*!< 0x00008000 */
#define GPIO_ALF_ALFSEL8_Pos               (16U)
#define GPIO_ALF_ALFSEL8_Msk               (0x3UL << GPIO_ALF_ALFSEL8_Pos)               /*!< 0x00030000 */
#define GPIO_ALF_ALFSEL8                   GPIO_ALF_ALFSEL8_Msk
#define GPIO_ALF_ALFSEL8_0                 (0x1UL << GPIO_ALF_ALFSEL8_Pos)               /*!< 0x00010000 */
#define GPIO_ALF_ALFSEL8_1                 (0x2UL << GPIO_ALF_ALFSEL8_Pos)               /*!< 0x00020000 */
#define GPIO_ALF_ALFSEL9_Pos               (18U)
#define GPIO_ALF_ALFSEL9_Msk               (0x3UL << GPIO_ALF_ALFSEL9_Pos)               /*!< 0x000C0000 */
#define GPIO_ALF_ALFSEL9                   GPIO_ALF_ALFSEL9_Msk
#define GPIO_ALF_ALFSEL9_0                 (0x1UL << GPIO_ALF_ALFSEL9_Pos)               /*!< 0x00040000 */
#define GPIO_ALF_ALFSEL9_1                 (0x2UL << GPIO_ALF_ALFSEL9_Pos)               /*!< 0x00080000 */
#define GPIO_ALF_ALFSEL10_Pos              (20U)
#define GPIO_ALF_ALFSEL10_Msk              (0x3UL << GPIO_ALF_ALFSEL10_Pos)              /*!< 0x00300000 */
#define GPIO_ALF_ALFSEL10                  GPIO_ALF_ALFSEL10_Msk
#define GPIO_ALF_ALFSEL10_0                (0x1UL << GPIO_ALF_ALFSEL10_Pos)              /*!< 0x00100000 */
#define GPIO_ALF_ALFSEL10_1                (0x2UL << GPIO_ALF_ALFSEL10_Pos)              /*!< 0x00200000 */
#define GPIO_ALF_ALFSEL11_Pos              (22U)
#define GPIO_ALF_ALFSEL11_Msk              (0x3UL << GPIO_ALF_ALFSEL11_Pos)              /*!< 0x00C00000 */
#define GPIO_ALF_ALFSEL11                  GPIO_ALF_ALFSEL11_Msk
#define GPIO_ALF_ALFSEL11_0                (0x1UL << GPIO_ALF_ALFSEL11_Pos)              /*!< 0x00400000 */
#define GPIO_ALF_ALFSEL11_1                (0x2UL << GPIO_ALF_ALFSEL11_Pos)              /*!< 0x00800000 */
#define GPIO_ALF_ALFSEL12_Pos              (24U)
#define GPIO_ALF_ALFSEL12_Msk              (0x3UL << GPIO_ALF_ALFSEL12_Pos)              /*!< 0x03000000 */
#define GPIO_ALF_ALFSEL12                  GPIO_ALF_ALFSEL12_Msk
#define GPIO_ALF_ALFSEL12_0                (0x1UL << GPIO_ALF_ALFSEL12_Pos)              /*!< 0x01000000 */
#define GPIO_ALF_ALFSEL12_1                (0x2UL << GPIO_ALF_ALFSEL12_Pos)              /*!< 0x02000000 */
#define GPIO_ALF_ALFSEL13_Pos              (26U)
#define GPIO_ALF_ALFSEL13_Msk              (0x3UL << GPIO_ALF_ALFSEL13_Pos)              /*!< 0x0C000000 */
#define GPIO_ALF_ALFSEL13                  GPIO_ALF_ALFSEL13_Msk
#define GPIO_ALF_ALFSEL13_0                (0x1UL << GPIO_ALF_ALFSEL13_Pos)              /*!< 0x04000000 */
#define GPIO_ALF_ALFSEL13_1                (0x2UL << GPIO_ALF_ALFSEL13_Pos)              /*!< 0x08000000 */
#define GPIO_ALF_ALFSEL14_Pos              (28U)
#define GPIO_ALF_ALFSEL14_Msk              (0x3UL << GPIO_ALF_ALFSEL14_Pos)              /*!< 0x30000000 */
#define GPIO_ALF_ALFSEL14                  GPIO_ALF_ALFSEL14_Msk
#define GPIO_ALF_ALFSEL14_0                (0x1UL << GPIO_ALF_ALFSEL14_Pos)              /*!< 0x10000000 */
#define GPIO_ALF_ALFSEL14_1                (0x2UL << GPIO_ALF_ALFSEL14_Pos)              /*!< 0x20000000 */
#define GPIO_ALF_ALFSEL15_Pos              (30U)
#define GPIO_ALF_ALFSEL15_Msk              (0x3UL << GPIO_ALF_ALFSEL15_Pos)              /*!< 0xC0000000 */
#define GPIO_ALF_ALFSEL15                  GPIO_ALF_ALFSEL15_Msk
#define GPIO_ALF_ALFSEL15_0                (0x1UL << GPIO_ALF_ALFSEL15_Pos)              /*!< 0x40000000 */
#define GPIO_ALF_ALFSEL15_1                (0x2UL << GPIO_ALF_ALFSEL15_Pos)              /*!< 0x80000000 */

/****************** Bit definition for GPIO_FILTER register **********************/
#define GPIO_FILTER_FLTEN0_Pos             (0U)
#define GPIO_FILTER_FLTEN0_Msk             (0x1UL << GPIO_FILTER_FLTEN0_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN0                 GPIO_FILTER_FLTEN0_Msk
#define GPIO_FILTER_FLTEN1_Pos             (1U)
#define GPIO_FILTER_FLTEN1_Msk             (0x1UL << GPIO_FILTER_FLTEN1_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN1                 GPIO_FILTER_FLTEN1_Msk
#define GPIO_FILTER_FLTEN2_Pos             (2U)
#define GPIO_FILTER_FLTEN2_Msk             (0x1UL << GPIO_FILTER_FLTEN2_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN2                 GPIO_FILTER_FLTEN2_Msk
#define GPIO_FILTER_FLTEN3_Pos             (3U)
#define GPIO_FILTER_FLTEN3_Msk             (0x1UL << GPIO_FILTER_FLTEN3_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN3                 GPIO_FILTER_FLTEN3_Msk
#define GPIO_FILTER_FLTEN4_Pos             (4U)
#define GPIO_FILTER_FLTEN4_Msk             (0x1UL << GPIO_FILTER_FLTEN4_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN4                 GPIO_FILTER_FLTEN4_Msk
#define GPIO_FILTER_FLTEN5_Pos             (5U)
#define GPIO_FILTER_FLTEN5_Msk             (0x1UL << GPIO_FILTER_FLTEN5_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN5                 GPIO_FILTER_FLTEN5_Msk
#define GPIO_FILTER_FLTEN6_Pos             (6U)
#define GPIO_FILTER_FLTEN6_Msk             (0x1UL << GPIO_FILTER_FLTEN6_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN6                 GPIO_FILTER_FLTEN6_Msk
#define GPIO_FILTER_FLTEN7_Pos             (7U)
#define GPIO_FILTER_FLTEN7_Msk             (0x1UL << GPIO_FILTER_FLTEN7_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN7                 GPIO_FILTER_FLTEN7_Msk
#define GPIO_FILTER_FLTEN8_Pos             (8U)
#define GPIO_FILTER_FLTEN8_Msk             (0x1UL << GPIO_FILTER_FLTEN8_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN8                 GPIO_FILTER_FLTEN8_Msk
#define GPIO_FILTER_FLTEN9_Pos             (9U)
#define GPIO_FILTER_FLTEN9_Msk             (0x1UL << GPIO_FILTER_FLTEN9_Pos)             /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN9                 GPIO_FILTER_FLTEN9_Msk
#define GPIO_FILTER_FLTEN10_Pos            (10U)
#define GPIO_FILTER_FLTEN10_Msk            (0x1UL << GPIO_FILTER_FLTEN10_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN10                GPIO_FILTER_FLTEN10_Msk
#define GPIO_FILTER_FLTEN11_Pos            (11U)
#define GPIO_FILTER_FLTEN11_Msk            (0x1UL << GPIO_FILTER_FLTEN11_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN11                GPIO_FILTER_FLTEN11_Msk
#define GPIO_FILTER_FLTEN12_Pos            (12U)
#define GPIO_FILTER_FLTEN12_Msk            (0x1UL << GPIO_FILTER_FLTEN12_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN12                GPIO_FILTER_FLTEN12_Msk
#define GPIO_FILTER_FLTEN13_Pos            (13U)
#define GPIO_FILTER_FLTEN13_Msk            (0x1UL << GPIO_FILTER_FLTEN13_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN13                GPIO_FILTER_FLTEN13_Msk
#define GPIO_FILTER_FLTEN14_Pos            (14U)
#define GPIO_FILTER_FLTEN14_Msk            (0x1UL << GPIO_FILTER_FLTEN14_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN14                GPIO_FILTER_FLTEN14_Msk
#define GPIO_FILTER_FLTEN15_Pos            (15U)
#define GPIO_FILTER_FLTEN15_Msk            (0x1UL << GPIO_FILTER_FLTEN15_Pos)            /*!< 0x00000003 */
#define GPIO_FILTER_FLTEN15                GPIO_FILTER_FLTEN15_Msk

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CTRL1 register  ******************/
#define I2C_CTRL1_I2CEN_Pos                (0U)
#define I2C_CTRL1_I2CEN_Msk                (0x1UL << I2C_CTRL1_I2CEN_Pos)                /*!< 0x00000001 */
#define I2C_CTRL1_I2CEN                    I2C_CTRL1_I2CEN_Msk                           /*!< Peripheral Enable */
#define I2C_CTRL1_SMBEN_Pos                (1U)
#define I2C_CTRL1_SMBEN_Msk                (0x1UL << I2C_CTRL1_SMBEN_Pos)                /*!< 0x00000002 */
#define I2C_CTRL1_SMBEN                    I2C_CTRL1_SMBEN_Msk                           /*!< SMBus Mode */
#define I2C_CTRL1_SMBTCFG_Pos              (3U)
#define I2C_CTRL1_SMBTCFG_Msk              (0x1UL << I2C_CTRL1_SMBTCFG_Pos)              /*!< 0x00000008 */
#define I2C_CTRL1_SMBTCFG                  I2C_CTRL1_SMBTCFG_Msk                         /*!< SMBus Type */
#define I2C_CTRL1_ARPEN_Pos                (4U)
#define I2C_CTRL1_ARPEN_Msk                (0x1UL << I2C_CTRL1_ARPEN_Pos)                /*!< 0x00000010 */
#define I2C_CTRL1_ARPEN                    I2C_CTRL1_ARPEN_Msk                           /*!< ARP Enable */
#define I2C_CTRL1_PECEN_Pos                (5U)
#define I2C_CTRL1_PECEN_Msk                (0x1UL << I2C_CTRL1_PECEN_Pos)                /*!< 0x00000020 */
#define I2C_CTRL1_PECEN                    I2C_CTRL1_PECEN_Msk                           /*!< PEC Enable */
#define I2C_CTRL1_SRBEN_Pos                (6U)
#define I2C_CTRL1_SRBEN_Msk                (0x1UL << I2C_CTRL1_SRBEN_Pos)                /*!< 0x00000040 */
#define I2C_CTRL1_SRBEN                    I2C_CTRL1_SRBEN_Msk                           /*!< General Call Enable */
#define I2C_CTRL1_CLKSTRETCHD_Pos          (7U)
#define I2C_CTRL1_CLKSTRETCHD_Msk          (0x1UL << I2C_CTRL1_CLKSTRETCHD_Pos)          /*!< 0x00000080 */
#define I2C_CTRL1_CLKSTRETCHD              I2C_CTRL1_CLKSTRETCHD_Msk                     /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CTRL1_START_Pos                (8U)
#define I2C_CTRL1_START_Msk                (0x1UL << I2C_CTRL1_START_Pos)                /*!< 0x00000100 */
#define I2C_CTRL1_START                    I2C_CTRL1_START_Msk                           /*!< Start Generation */
#define I2C_CTRL1_STOP_Pos                 (9U)
#define I2C_CTRL1_STOP_Msk                 (0x1UL << I2C_CTRL1_STOP_Pos)                 /*!< 0x00000200 */
#define I2C_CTRL1_STOP                     I2C_CTRL1_STOP_Msk                            /*!< Stop Generation */
#define I2C_CTRL1_ACKEN_Pos                (10U)
#define I2C_CTRL1_ACKEN_Msk                (0x1UL << I2C_CTRL1_ACKEN_Pos)                /*!< 0x00000400 */
#define I2C_CTRL1_ACKEN                    I2C_CTRL1_ACKEN_Msk                           /*!< Acknowledge Enable */
#define I2C_CTRL1_ACKPOS_Pos               (11U)
#define I2C_CTRL1_ACKPOS_Msk               (0x1UL << I2C_CTRL1_ACKPOS_Pos)               /*!< 0x00000800 */
#define I2C_CTRL1_ACKPOS                   I2C_CTRL1_ACKPOS_Msk                          /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CTRL1_PEC_Pos                  (12U)
#define I2C_CTRL1_PEC_Msk                  (0x1UL << I2C_CTRL1_PEC_Pos)                  /*!< 0x00001000 */
#define I2C_CTRL1_PEC                      I2C_CTRL1_PEC_Msk                             /*!< Packet Error Checking */
#define I2C_CTRL1_ALERTEN_Pos              (13U)
#define I2C_CTRL1_ALERTEN_Msk              (0x1UL << I2C_CTRL1_ALERTEN_Pos)              /*!< 0x00002000 */
#define I2C_CTRL1_ALERTEN                  I2C_CTRL1_ALERTEN_Msk                         /*!< SMBus Alert */
#define I2C_CTRL1_SWRST_Pos                (15U)
#define I2C_CTRL1_SWRST_Msk                (0x1UL << I2C_CTRL1_SWRST_Pos)                /*!< 0x00008000 */
#define I2C_CTRL1_SWRST                    I2C_CTRL1_SWRST_Msk                           /*!< Software Reset */

/*******************  Bit definition for I2C_CTRL2 register  ******************/
#define I2C_CTRL2_CLKFCFG_Pos              (0U)
#define I2C_CTRL2_CLKFCFG_Msk              (0xFFUL << I2C_CTRL2_CLKFCFG_Pos)             /*!< 0x000000FF */
#define I2C_CTRL2_CLKFCFG                  I2C_CTRL2_CLKFCFG_Msk                         /*!< FREQ[7:0] bits (Peripheral Clock Frequency) */
#define I2C_CTRL2_ERRIEN_Pos               (8U)
#define I2C_CTRL2_ERRIEN_Msk               (0x1UL << I2C_CTRL2_ERRIEN_Pos)               /*!< 0x00000100 */
#define I2C_CTRL2_ERRIEN                   I2C_CTRL2_ERRIEN_Msk                          /*!< Error Interrupt Enable */
#define I2C_CTRL2_EVIEN_Pos                (9U)
#define I2C_CTRL2_EVIEN_Msk                (0x1UL << I2C_CTRL2_EVIEN_Pos)                /*!< 0x00000200 */
#define I2C_CTRL2_EVIEN                    I2C_CTRL2_EVIEN_Msk                           /*!< Event Interrupt Enable */
#define I2C_CTRL2_BUFIEN_Pos               (10U)
#define I2C_CTRL2_BUFIEN_Msk               (0x1UL << I2C_CTRL2_BUFIEN_Pos)               /*!< 0x00000400 */
#define I2C_CTRL2_BUFIEN                   I2C_CTRL2_BUFIEN_Msk                          /*!< Buffer Interrupt Enable */
#define I2C_CTRL2_DMAEN_Pos                (11U)
#define I2C_CTRL2_DMAEN_Msk                (0x1UL << I2C_CTRL2_DMAEN_Pos)                /*!< 0x00000800 */
#define I2C_CTRL2_DMAEN                    I2C_CTRL2_DMAEN_Msk                           /*!< DMA Requests Enable */
#define I2C_CTRL2_LTCFG_Pos                (12U)
#define I2C_CTRL2_LTCFG_Msk                (0x1UL << I2C_CTRL2_LTCFG_Pos)                /*!< 0x00001000 */
#define I2C_CTRL2_LTCFG                    I2C_CTRL2_LTCFG_Msk                           /*!< DMA Last Transfer */

/*******************  Bit definition for I2C_SADDR1 register  *****************/
#define I2C_SADDR1_ADDR1_7                 0x000000FEU                                   /*!< Interface Address */
#define I2C_SADDR1_ADDR8_9                 0x00000300U                                   /*!< Interface Address */

#define I2C_SADDR1_ADDR0_Pos               (0U)
#define I2C_SADDR1_ADDR0_Msk               (0x1UL << I2C_SADDR1_ADDR0_Pos)               /*!< 0x00000001 */
#define I2C_SADDR1_ADDR0                   I2C_SADDR1_ADDR0_Msk                          /*!< Bit 0 */
#define I2C_SADDR1_ADDR1_Pos               (1U)
#define I2C_SADDR1_ADDR1_Msk               (0x1UL << I2C_SADDR1_ADDR1_Pos)               /*!< 0x00000000 */
#define I2C_SADDR1_ADDR1                   I2C_SADDR1_ADDR1_Msk                          /*!< Bit 1 */
#define I2C_SADDR1_ADDR2_Pos               (2U)
#define I2C_SADDR1_ADDR2_Msk               (0x1UL << I2C_SADDR1_ADDR2_Pos)               /*!< 0x00000004 */
#define I2C_SADDR1_ADDR2                   I2C_SADDR1_ADDR2_Msk                          /*!< Bit 2 */
#define I2C_SADDR1_ADDR3_Pos               (3U)
#define I2C_SADDR1_ADDR3_Msk               (0x1UL << I2C_SADDR1_ADDR3_Pos)               /*!< 0x00000008 */
#define I2C_SADDR1_ADDR3                   I2C_SADDR1_ADDR3_Msk                          /*!< Bit 3 */
#define I2C_SADDR1_ADDR4_Pos               (4U)
#define I2C_SADDR1_ADDR4_Msk               (0x1UL << I2C_SADDR1_ADDR4_Pos)               /*!< 0x00000010 */
#define I2C_SADDR1_ADDR4                   I2C_SADDR1_ADDR4_Msk                          /*!< Bit 4 */
#define I2C_SADDR1_ADDR5_Pos               (5U)
#define I2C_SADDR1_ADDR5_Msk               (0x1UL << I2C_SADDR1_ADDR5_Pos)               /*!< 0x00000020 */
#define I2C_SADDR1_ADDR5                   I2C_SADDR1_ADDR5_Msk                          /*!< Bit 5 */
#define I2C_SADDR1_ADDR6_Pos               (6U)
#define I2C_SADDR1_ADDR6_Msk               (0x1UL << I2C_SADDR1_ADDR6_Pos)               /*!< 0x00000040 */
#define I2C_SADDR1_ADDR6                   I2C_SADDR1_ADDR6_Msk                          /*!< Bit 6 */
#define I2C_SADDR1_ADDR7_Pos               (7U)
#define I2C_SADDR1_ADDR7_Msk               (0x1UL << I2C_SADDR1_ADDR7_Pos)               /*!< 0x00000080 */
#define I2C_SADDR1_ADDR7                   I2C_SADDR1_ADDR7_Msk                          /*!< Bit 7 */
#define I2C_SADDR1_ADDR8_Pos               (8U)
#define I2C_SADDR1_ADDR8_Msk               (0x1UL << I2C_SADDR1_ADDR8_Pos)               /*!< 0x00000100 */
#define I2C_SADDR1_ADDR8                   I2C_SADDR1_ADDR8_Msk                          /*!< Bit 8 */
#define I2C_SADDR1_ADDR9_Pos               (9U)
#define I2C_SADDR1_ADDR9_Msk               (0x1UL << I2C_SADDR1_ADDR9_Pos)               /*!< 0x00000200 */
#define I2C_SADDR1_ADDR9                   I2C_SADDR1_ADDR9_Msk                          /*!< Bit 9 */

#define I2C_SADDR1_ADDRLEN_Pos             (15U)
#define I2C_SADDR1_ADDRLEN_Msk             (0x1UL << I2C_SADDR1_ADDRLEN_Pos)             /*!< 0x00008000 */
#define I2C_SADDR1_ADDRLEN                 I2C_SADDR1_ADDRLEN_Msk                        /*!< Addressing Mode (Slave mode) */

/*******************  Bit definition for I2C_SADDR2 register  *****************/
#define I2C_SADDR2_ADDRNUM_Pos             (0U)
#define I2C_SADDR2_ADDRNUM_Msk             (0x1UL << I2C_SADDR2_ADDRNUM_Pos)             /*!< 0x00000001 */
#define I2C_SADDR2_ADDRNUM                 I2C_SADDR2_ADDRNUM_Msk                        /*!< Dual addressing mode enable */
#define I2C_SADDR2_ADDR2_Pos               (1U)
#define I2C_SADDR2_ADDR2_Msk               (0x7FUL << I2C_SADDR2_ADDR2_Pos)              /*!< 0x000000FE */
#define I2C_SADDR2_ADDR2                   I2C_SADDR2_ADDR2_Msk                          /*!< Interface address */

/********************  Bit definition for I2C_DATA register  ******************/
#define I2C_DATA_DATA_Pos                  (0U)
#define I2C_DATA_DATA_Msk                  (0xFFUL << I2C_DATA_DATA_Pos)                 /*!< 0x000000FF */
#define I2C_DATA_DATA                      I2C_DATA_DATA_Msk                             /*!<8-bit Data Register */

/*******************  Bit definition for I2C_STS1 register  *******************/
#define I2C_STS1_STARTFLG_Pos              (0U)
#define I2C_STS1_STARTFLG_Msk              (0x1UL << I2C_STS1_STARTFLG_Pos)              /*!< 0x00000001 */
#define I2C_STS1_STARTFLG                  I2C_STS1_STARTFLG_Msk                         /*!< Start Bit (Master mode) */
#define I2C_STS1_ADDRFLG_Pos               (1U)
#define I2C_STS1_ADDRFLG_Msk               (0x1UL << I2C_STS1_ADDRFLG_Pos)               /*!< 0x00000000 */
#define I2C_STS1_ADDRFLG                   I2C_STS1_ADDRFLG_Msk                          /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_STS1_BTCFLG_Pos                (2U)
#define I2C_STS1_BTCFLG_Msk                (0x1UL << I2C_STS1_BTCFLG_Pos)                /*!< 0x00000004 */
#define I2C_STS1_BTCFLG                    I2C_STS1_BTCFLG_Msk                           /*!< Byte Transfer Finished */
#define I2C_STS1_ADDR10FLG_Pos             (3U)
#define I2C_STS1_ADDR10FLG_Msk             (0x1UL << I2C_STS1_ADDR10FLG_Pos)             /*!< 0x00000008 */
#define I2C_STS1_ADDR10FLG                 I2C_STS1_ADDR10FLG_Msk                        /*!<10-bit header sent (Master mode) */
#define I2C_STS1_STOPFLG_Pos               (4U)
#define I2C_STS1_STOPFLG_Msk               (0x1UL << I2C_STS1_STOPFLG_Pos)               /*!< 0x00000010 */
#define I2C_STS1_STOPFLG                   I2C_STS1_STOPFLG_Msk                          /*!< Stop detection (Slave mode) */
#define I2C_STS1_RXBNEFLG_Pos              (6U)
#define I2C_STS1_RXBNEFLG_Msk              (0x1UL << I2C_STS1_RXBNEFLG_Pos)              /*!< 0x00000040 */
#define I2C_STS1_RXBNEFLG                  I2C_STS1_RXBNEFLG_Msk                         /*!< Data Register not Empty (receivers) */
#define I2C_STS1_TXBEFLG_Pos               (7U)
#define I2C_STS1_TXBEFLG_Msk               (0x1UL << I2C_STS1_TXBEFLG_Pos)               /*!< 0x00000080 */
#define I2C_STS1_TXBEFLG                   I2C_STS1_TXBEFLG_Msk                          /*!< Data Register Empty (transmitters) */
#define I2C_STS1_BERRFLG_Pos               (8U)
#define I2C_STS1_BERRFLG_Msk               (0x1UL << I2C_STS1_BERRFLG_Pos)               /*!< 0x00000100 */
#define I2C_STS1_BERRFLG                   I2C_STS1_BERRFLG_Msk                          /*!< Bus Error */
#define I2C_STS1_ALFLG_Pos                 (9U)
#define I2C_STS1_ALFLG_Msk                 (0x1UL << I2C_STS1_ALFLG_Pos)                 /*!< 0x00000200 */
#define I2C_STS1_ALFLG                     I2C_STS1_ALFLG_Msk                            /*!< Arbitration Lost (master mode) */
#define I2C_STS1_AEFLG_Pos                 (10U)
#define I2C_STS1_AEFLG_Msk                 (0x1UL << I2C_STS1_AEFLG_Pos)                 /*!< 0x00000400 */
#define I2C_STS1_AEFLG                     I2C_STS1_AEFLG_Msk                            /*!< Acknowledge Failure */
#define I2C_STS1_OVRURFLG_Pos              (11U)
#define I2C_STS1_OVRURFLG_Msk              (0x1UL << I2C_STS1_OVRURFLG_Pos)              /*!< 0x00000800 */
#define I2C_STS1_OVRURFLG                  I2C_STS1_OVRURFLG_Msk                         /*!< Overrun/Underrun */
#define I2C_STS1_PECEFLG_Pos               (12U)
#define I2C_STS1_PECEFLG_Msk               (0x1UL << I2C_STS1_PECEFLG_Pos)               /*!< 0x00001000 */
#define I2C_STS1_PECEFLG                   I2C_STS1_PECEFLG_Msk                          /*!< PEC Error in reception */
#define I2C_STS1_TTEFLG_Pos                (14U)
#define I2C_STS1_TTEFLG_Msk                (0x1UL << I2C_STS1_TTEFLG_Pos)                /*!< 0x00004000 */
#define I2C_STS1_TTEFLG                    I2C_STS1_TTEFLG_Msk                           /*!< Timeout or Tlow Error */
#define I2C_STS1_SMBALTFLG_Pos             (15U)
#define I2C_STS1_SMBALTFLG_Msk             (0x1UL << I2C_STS1_SMBALTFLG_Pos)             /*!< 0x00008000 */
#define I2C_STS1_SMBALTFLG                 I2C_STS1_SMBALTFLG_Msk                        /*!< SMBus Alert */

/*******************  Bit definition for I2C_STS2 register  *******************/
#define I2C_STS2_MSFLG_Pos                 (0U)
#define I2C_STS2_MSFLG_Msk                 (0x1UL << I2C_STS2_MSFLG_Pos)                 /*!< 0x00000001 */
#define I2C_STS2_MSFLG                     I2C_STS2_MSFLG_Msk                            /*!< Master/Slave */
#define I2C_STS2_BUSBSYFLG_Pos             (1U)
#define I2C_STS2_BUSBSYFLG_Msk             (0x1UL << I2C_STS2_BUSBSYFLG_Pos)             /*!< 0x00000000 */
#define I2C_STS2_BUSBSYFLG                 I2C_STS2_BUSBSYFLG_Msk                        /*!< Bus Busy */
#define I2C_STS2_TRFLG_Pos                 (2U)
#define I2C_STS2_TRFLG_Msk                 (0x1UL << I2C_STS2_TRFLG_Pos)                 /*!< 0x00000004 */
#define I2C_STS2_TRFLG                     I2C_STS2_TRFLG_Msk                            /*!< Transmitter/Receiver */
#define I2C_STS2_GENCALLFLG_Pos            (4U)
#define I2C_STS2_GENCALLFLG_Msk            (0x1UL << I2C_STS2_GENCALLFLG_Pos)            /*!< 0x00000010 */
#define I2C_STS2_GENCALLFLG                I2C_STS2_GENCALLFLG_Msk                       /*!< General Call Address (Slave mode) */
#define I2C_STS2_SMBDADDRFLG_Pos           (5U)
#define I2C_STS2_SMBDADDRFLG_Msk           (0x1UL << I2C_STS2_SMBDADDRFLG_Pos)           /*!< 0x00000020 */
#define I2C_STS2_SMBDADDRFLG               I2C_STS2_SMBDADDRFLG_Msk                      /*!< SMBus Device Default Address (Slave mode) */
#define I2C_STS2_SMMHADDR_Pos              (6U)
#define I2C_STS2_SMMHADDR_Msk              (0x1UL << I2C_STS2_SMMHADDR_Pos)              /*!< 0x00000040 */
#define I2C_STS2_SMMHADDR                  I2C_STS2_SMMHADDR_Msk                         /*!< SMBus Host Header (Slave mode) */
#define I2C_STS2_DUALADDRFLG_Pos           (7U)
#define I2C_STS2_DUALADDRFLG_Msk           (0x1UL << I2C_STS2_DUALADDRFLG_Pos)           /*!< 0x00000080 */
#define I2C_STS2_DUALADDRFLG               I2C_STS2_DUALADDRFLG_Msk                      /*!< Dual Flag (Slave mode) */
#define I2C_STS2_PECVALUE_Pos              (8U)
#define I2C_STS2_PECVALUE_Msk              (0xFFUL << I2C_STS2_PECVALUE_Pos)             /*!< 0x0000FF00 */
#define I2C_STS2_PECVALUE                  I2C_STS2_PECVALUE_Msk                         /*!< Packet Error Checking Register */

/*******************  Bit definition for I2C_CLKCTRL register  ****************/
#define I2C_CLKCTRL_CLKS_Pos               (0U)
#define I2C_CLKCTRL_CLKS_Msk               (0xFFFUL << I2C_CLKCTRL_CLKS_Pos)             /*!< 0x00000FFF */
#define I2C_CLKCTRL_CLKS                   I2C_CLKCTRL_CLKS_Msk                          /*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CLKCTRL_FDUTYCFG_Pos           (14U)
#define I2C_CLKCTRL_FDUTYCFG_Msk           (0x1UL << I2C_CLKCTRL_FDUTYCFG_Pos)           /*!< 0x00004000 */
#define I2C_CLKCTRL_FDUTYCFG               I2C_CLKCTRL_FDUTYCFG_Msk                      /*!< Fast Mode Duty Cycle */
#define I2C_CLKCTRL_SPEEDCFG_Pos           (15U)
#define I2C_CLKCTRL_SPEEDCFG_Msk           (0x1UL << I2C_CLKCTRL_SPEEDCFG_Pos)           /*!< 0x00008000 */
#define I2C_CLKCTRL_SPEEDCFG               I2C_CLKCTRL_SPEEDCFG_Msk                      /*!< I2C Master Mode Selection */

/******************  Bit definition for I2C_RISETMAX register  ****************/
#define I2C_RISETMAX_RISETMAX_Pos          (0U)
#define I2C_RISETMAX_RISETMAX_Msk          (0xFFUL << I2C_RISETMAX_RISETMAX_Pos)         /*!< 0x000000FF */
#define I2C_RISETMAX_RISETMAX              I2C_RISETMAX_RISETMAX_Msk                     /*!< Maximum Rise Time in Fast/Standard mode (Master mode) */

/******************  Bit definition for I2C_FILTER register  ******************/
#define I2C_FILTER_DNFCFG_Pos              (0U)
#define I2C_FILTER_DNFCFG_Msk              (0xFUL << I2C_FILTER_DNFCFG_Pos)              /*!< 0x0000000F */
#define I2C_FILTER_DNFCFG                  I2C_FILTER_DNFCFG_Msk                         /*!< Digital Noise Filter */
#define I2C_FILTER_ANFDIS_Pos              (4U)
#define I2C_FILTER_ANFDIS_Msk              (0x1UL << I2C_FILTER_ANFDIS_Pos)              /*!< 0x00000010 */
#define I2C_FILTER_ANFDIS                  I2C_FILTER_ANFDIS_Msk                         /*!< Analog Noise Filter */

/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDT_KEY register  *******************/
#define IWDT_KEY_KEY_Pos                   (0U)
#define IWDT_KEY_KEY_Msk                   (0xFFFFUL << IWDT_KEY_KEY_Pos)                /*!< 0x0000FFFF */
#define IWDT_KEY_KEY                       IWDT_KEY_KEY_Msk                              /*!< Key value (write only, read 0000h) */

/*******************  Bit definition for IWDT_PSC register  *******************/
#define IWDT_PSC_PSC_Pos                   (0U)
#define IWDT_PSC_PSC_Msk                   (0x7UL << IWDT_PSC_PSC_Pos)                   /*!< 0x00000007 */
#define IWDT_PSC_PSC                       IWDT_PSC_PSC_Msk                              /*!< PR[2:0] (Prescaler divider) */
#define IWDT_PSC_PSC_0                     (0x1UL << IWDT_PSC_PSC_Pos)                   /*!< 0x00000001 */
#define IWDT_PSC_PSC_1                     (0x2UL << IWDT_PSC_PSC_Pos)                   /*!< 0x00000002 */
#define IWDT_PSC_PSC_2                     (0x4UL << IWDT_PSC_PSC_Pos)                   /*!< 0x00000004 */

/*******************  Bit definition for IWDT_CNTRLD register  ****************/
#define IWDT_CNTRLD_CNTRLD_Pos             (0U)
#define IWDT_CNTRLD_CNTRLD_Msk             (0xFFFUL << IWDT_CNTRLD_CNTRLD_Pos)           /*!< 0x00000FFF */
#define IWDT_CNTRLD_CNTRLD                 IWDT_CNTRLD_CNTRLD_Msk                        /*!< Watchdog counter reload value */

/*******************  Bit definition for IWDT_STS register  *******************/
#define IWDT_STS_PSCUFLG_Pos               (0U)
#define IWDT_STS_PSCUFLG_Msk               (0x1UL << IWDT_STS_PSCUFLG_Pos)               /*!< 0x00000001 */
#define IWDT_STS_PSCUFLG                   IWDT_STS_PSCUFLG_Msk                          /*!< Watchdog prescaler value update */
#define IWDT_STS_CNTUFLG_Pos               (1U)
#define IWDT_STS_CNTUFLG_Msk               (0x1UL << IWDT_STS_CNTUFLG_Pos)               /*!< 0x00000000 */
#define IWDT_STS_CNTUFLG                   IWDT_STS_CNTUFLG_Msk                          /*!< Watchdog counter reload value update */

/******************************************************************************/
/*                                                                            */
/*                               Reset and Clock Manager                      */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCM_DR register  ********************/
#define RCM_KEY_LOCKKEY_Pos                (0U)
#define RCM_KEY_LOCKKEY_Msk                (0xFFFFUL << RCM_KEY_LOCKKEY_Pos)             /*!< 0x0000FFFF */
#define RCM_KEY_LOCKKEY                    RCM_KEY_LOCKKEY_Msk
#define RCM_KEY_KEYST_Pos                  (16U)
#define RCM_KEY_KEYST_Msk                  (0x1UL << RCM_KEY_KEYST_Pos)                  /*!< 0x00010000 */
#define RCM_KEY_KEYST                      RCM_KEY_KEYST_Msk
/********************  Bit definition for RCM_RCCR register  ******************/
#define RCM_RCCR_HSION_Pos                 (0U)
#define RCM_RCCR_HSION_Msk                 (0x1UL << RCM_RCCR_HSION_Pos)                 /*!< 0x00000001 */
#define RCM_RCCR_HSION                     RCM_RCCR_HSION_Msk
#define RCM_RCCR_HSIRDY_Pos                (1U)
#define RCM_RCCR_HSIRDY_Msk                (0x1UL << RCM_RCCR_HSIRDY_Pos)                /*!< 0x00000002 */
#define RCM_RCCR_HSIRDY                    RCM_RCCR_HSIRDY_Msk
#define RCM_RCCR_HSEON_Pos                 (8U)
#define RCM_RCCR_HSEON_Msk                 (0x1UL << RCM_RCCR_HSEON_Pos)                 /*!< 0x00000100 */
#define RCM_RCCR_HSEON                     RCM_RCCR_HSEON_Msk
#define RCM_RCCR_HSERDY_Pos                (9U)
#define RCM_RCCR_HSERDY_Msk                (0x1UL << RCM_RCCR_HSERDY_Pos)                /*!< 0x00000200 */
#define RCM_RCCR_HSERDY                    RCM_RCCR_HSERDY_Msk
#define RCM_RCCR_HSEBYPASS_Pos             (10U)
#define RCM_RCCR_HSEBYPASS_Msk             (0x1UL << RCM_RCCR_HSEBYPASS_Pos)             /*!< 0x00000400 */
#define RCM_RCCR_HSEBYPASS                 RCM_RCCR_HSEBYPASS_Msk
#define RCM_RCCR_CSSON_Pos                 (11U)
#define RCM_RCCR_CSSON_Msk                 (0x1UL << RCM_RCCR_CSSON_Pos)                 /*!< 0x00000800 */
#define RCM_RCCR_CSSON                     RCM_RCCR_CSSON_Msk
#define RCM_RCCR_PLLON_Pos                 (16U)
#define RCM_RCCR_PLLON_Msk                 (0x1UL << RCM_RCCR_PLLON_Pos)                 /*!< 0x00010000 */
#define RCM_RCCR_PLLON                     RCM_RCCR_PLLON_Msk
#define RCM_RCCR_PLLRDY_Pos                (17U)
#define RCM_RCCR_PLLRDY_Msk                (0x1UL << RCM_RCCR_PLLRDY_Pos)                /*!< 0x00020000 */
#define RCM_RCCR_PLLRDY                    RCM_RCCR_PLLRDY_Msk
#define RCM_RCCR_LSEON_Pos                 (24U)
#define RCM_RCCR_LSEON_Msk                 (0x1UL << RCM_RCCR_LSEON_Pos)                 /*!< 0x01000000 */
#define RCM_RCCR_LSEON                     RCM_RCCR_LSEON_Msk
#define RCM_RCCR_LSERDY_Pos                (25U)
#define RCM_RCCR_LSERDY_Msk                (0x1UL << RCM_RCCR_LSERDY_Pos)                /*!< 0x02000000 */
#define RCM_RCCR_LSERDY                    RCM_RCCR_LSERDY_Msk
#define RCM_RCCR_LSECSSON_Pos              (26U)
#define RCM_RCCR_LSECSSON_Msk              (0x1UL << RCM_RCCR_LSECSSON_Pos)              /*!< 0x04000000 */
#define RCM_RCCR_LSECSSON                  RCM_RCCR_LSECSSON_Msk
#define RCM_RCCR_LSEBYPASS_Pos             (27U)
#define RCM_RCCR_LSEBYPASS_Msk             (0x1UL << RCM_RCCR_LSEBYPASS_Pos)             /*!< 0x08000000 */
#define RCM_RCCR_LSEBYPASS                 RCM_RCCR_LSEBYPASS_Msk
/********************  Bit definition for RCM_PLLCR register  *****************/
#define RCM_PLLCR_PLLSRC_Pos               (0U)
#define RCM_PLLCR_PLLSRC_Msk               (0x3UL << RCM_PLLCR_PLLSRC_Pos)               /*!< 0x00000003 */
#define RCM_PLLCR_PLLSRC                   RCM_PLLCR_PLLSRC_Msk
#define RCM_PLLCR_PLLSRC_0                 (0x01UL << RCM_PLLCR_PLLSRC_Pos)              /*!< 0x00000001 */
#define RCM_PLLCR_PLLSRC_1                 (0x02UL << RCM_PLLCR_PLLSRC_Pos)              /*!< 0x00000002 */

#define RCM_PLLCR_PLLP_Pos                 (8U)
#define RCM_PLLCR_PLLP_Msk                 (0xFUL << RCM_PLLCR_PLLP_Pos)                 /*!< 0x00000F00 */
#define RCM_PLLCR_PLLP                     RCM_PLLCR_PLLP_Msk
#define RCM_PLLCR_PLLP_0                   (0x01UL << RCM_PLLCR_PLLP_Pos)                /*!< 0x00000100 */
#define RCM_PLLCR_PLLP_1                   (0x02UL << RCM_PLLCR_PLLP_Pos)                /*!< 0x00000200 */
#define RCM_PLLCR_PLLP_2                   (0x04UL << RCM_PLLCR_PLLP_Pos)                /*!< 0x00000400 */
#define RCM_PLLCR_PLLP_3                   (0x08UL << RCM_PLLCR_PLLP_Pos)                /*!< 0x00000800 */

#define RCM_PLLCR_PLLMUL_Pos               (16U)
#define RCM_PLLCR_PLLMUL_Msk               (0x3FUL << RCM_PLLCR_PLLMUL_Pos)              /*!< 0x003F0000 */
#define RCM_PLLCR_PLLMUL                   RCM_PLLCR_PLLMUL_Msk
/********************  Bit definition for RCM_SCCR register  ******************/
#define RCM_SCCR_SW_Pos                    (0U)
#define RCM_SCCR_SW_Msk                    (0x3UL << RCM_SCCR_SW_Pos)                    /*!< 0x00000003 */
#define RCM_SCCR_SW                        RCM_SCCR_SW_Msk
#define RCM_SCCR_HDIV_Pos                  (4U)
#define RCM_SCCR_HDIV_Msk                  (0xFUL << RCM_SCCR_HDIV_Pos)                  /*!< 0x000000F0 */
#define RCM_SCCR_HDIV                      RCM_SCCR_HDIV_Msk
#define RCM_SCCR_HDIV_0                    (0x1UL << RCM_SCCR_HDIV_Pos)                  /*!< 0x00000010 */
#define RCM_SCCR_HDIV_1                    (0x2UL << RCM_SCCR_HDIV_Pos)                  /*!< 0x00000020 */
#define RCM_SCCR_HDIV_2                    (0x4UL << RCM_SCCR_HDIV_Pos)                  /*!< 0x00000040 */
#define RCM_SCCR_HDIV_3                    (0x8UL << RCM_SCCR_HDIV_Pos)                  /*!< 0x00000080 */

#define RCM_SCCR_PDIV_Pos                  (8U)
#define RCM_SCCR_PDIV_Msk                  (0x7UL << RCM_SCCR_PDIV_Pos)                  /*!< 0x00000700 */
#define RCM_SCCR_PDIV                      RCM_SCCR_PDIV_Msk
#define RCM_SCCR_PDIV_0                    (0x1UL << RCM_SCCR_PDIV_Pos)                  /*!< 0x00000100 */
#define RCM_SCCR_PDIV_1                    (0x2UL << RCM_SCCR_PDIV_Pos)                  /*!< 0x00000200 */
#define RCM_SCCR_PDIV_2                    (0x4UL << RCM_SCCR_PDIV_Pos)                  /*!< 0x00000400 */

#define RCM_SCCR_CLKOUTSEL_Pos             (16U)
#define RCM_SCCR_CLKOUTSEL_Msk             (0x7UL << RCM_SCCR_CLKOUTSEL_Pos)             /*!< 0x00070000 */
#define RCM_SCCR_CLKOUTSEL                 RCM_SCCR_CLKOUTSEL_Msk
#define RCM_SCCR_CLKOUTSEL_0               (0x1UL << RCM_SCCR_CLKOUTSEL_Pos)             /*!< 0x00010000 */
#define RCM_SCCR_CLKOUTSEL_1               (0x2UL << RCM_SCCR_CLKOUTSEL_Pos)             /*!< 0x00020000 */
#define RCM_SCCR_CLKOUTSEL_2               (0x4UL << RCM_SCCR_CLKOUTSEL_Pos)             /*!< 0x00040000 */

#define RCM_SCCR_CLKOUTEN_Pos              (19U)
#define RCM_SCCR_CLKOUTEN_Msk              (0x1UL << RCM_SCCR_CLKOUTEN_Pos)              /*!< 0x00080000 */
#define RCM_SCCR_CLKOUTEN                  RCM_SCCR_CLKOUTEN_Msk
#define RCM_SCCR_CLKOUTDIV_Pos             (20U)
#define RCM_SCCR_CLKOUTDIV_Msk             (0x7UL << RCM_SCCR_CLKOUTDIV_Pos)             /*!< 0x00700000 */
#define RCM_SCCR_CLKOUTDIV                 RCM_SCCR_CLKOUTDIV_Msk
#define RCM_SCCR_CLKOUTDIV_0               (0x1UL << RCM_SCCR_CLKOUTDIV_Pos)             /*!< 0x00100000 */
#define RCM_SCCR_CLKOUTDIV_1               (0x2UL << RCM_SCCR_CLKOUTDIV_Pos)             /*!< 0x00200000 */
#define RCM_SCCR_CLKOUTDIV_2               (0x4UL << RCM_SCCR_CLKOUTDIV_Pos)             /*!< 0x00400000 */

/********************  Bit definition for RCM_MCCR register  ******************/
#define RCM_MCCR_CSEN_Pos                  (0U)
#define RCM_MCCR_CSEN_Msk                  (0x1UL << RCM_MCCR_CSEN_Pos)                  /*!< 0x00000001 */
#define RCM_MCCR_CSEN                      RCM_MCCR_CSEN_Msk
#define RCM_MCCR_SWST_Pos                  (1U)
#define RCM_MCCR_SWST_Msk                  (0x3UL << RCM_MCCR_SWST_Pos)                  /*!< 0x00000006 */
#define RCM_MCCR_SWST                      RCM_MCCR_SWST_Msk
#define RCM_MCCR_SWDONE_Pos                (3U)
#define RCM_MCCR_SWDONE_Msk                (0x1UL << RCM_MCCR_SWDONE_Pos)                /*!< 0x00000008 */
#define RCM_MCCR_SWDONE                    RCM_MCCR_SWDONE_Msk
#define RCM_MCCR_SWERR_Pos                 (4U)
#define RCM_MCCR_SWERR_Msk                 (0x1UL << RCM_MCCR_SWERR_Pos)                 /*!< 0x00000010 */
#define RCM_MCCR_SWERR                     RCM_MCCR_SWERR_Msk
/********************  Bit definition for RCM_CIER register  ******************/
#define RCM_CIER_LSIRDYIE_Pos              (0U)
#define RCM_CIER_LSIRDYIE_Msk              (0x1UL << RCM_CIER_LSIRDYIE_Pos)              /*!< 0x00000001 */
#define RCM_CIER_LSIRDYIE                  RCM_CIER_LSIRDYIE_Msk
#define RCM_CIER_LSERDYIE_Pos              (1U)
#define RCM_CIER_LSERDYIE_Msk              (0x1UL << RCM_CIER_LSERDYIE_Pos)              /*!< 0x00000002 */
#define RCM_CIER_LSERDYIE                  RCM_CIER_LSERDYIE_Msk
#define RCM_CIER_HSIRDYIE_Pos              (2U)
#define RCM_CIER_HSIRDYIE_Msk              (0x1UL << RCM_CIER_HSIRDYIE_Pos)              /*!< 0x00000004 */
#define RCM_CIER_HSIRDYIE                  RCM_CIER_HSIRDYIE_Msk
#define RCM_CIER_HSERDYIE_Pos              (3U)
#define RCM_CIER_HSERDYIE_Msk              (0x1UL << RCM_CIER_HSERDYIE_Pos)              /*!< 0x00000008 */
#define RCM_CIER_HSERDYIE                  RCM_CIER_HSERDYIE_Msk
#define RCM_CIER_PLLRDYIE_Pos              (4U)
#define RCM_CIER_PLLRDYIE_Msk              (0x1UL << RCM_CIER_PLLRDYIE_Pos)              /*!< 0x00000010 */
#define RCM_CIER_PLLRDYIE                  RCM_CIER_PLLRDYIE_Msk
#define RCM_CIER_HSECSSIE_Pos              (5U)
#define RCM_CIER_HSECSSIE_Msk              (0x1UL << RCM_CIER_HSECSSIE_Pos)              /*!< 0x00000020 */
#define RCM_CIER_HSECSSIE                  RCM_CIER_HSECSSIE_Msk
#define RCM_CIER_LSECSSIE_Pos              (6U)
#define RCM_CIER_LSECSSIE_Msk              (0x1UL << RCM_CIER_LSECSSIE_Pos)              /*!< 0x00000040 */
#define RCM_CIER_LSECSSIE                  RCM_CIER_LSECSSIE_Msk
/********************  Bit definition for RCM_CICR register  ******************/
#define RCM_CICR_LSIRDYF_Pos               (0U)
#define RCM_CICR_LSIRDYF_Msk               (0x1UL << RCM_CICR_LSIRDYF_Pos)               /*!< 0x00000001 */
#define RCM_CICR_LSIRDYF                   RCM_CICR_LSIRDYF_Msk
#define RCM_CICR_LSERDYF_Pos               (1U)
#define RCM_CICR_LSERDYF_Msk               (0x1UL << RCM_CICR_LSERDYF_Pos)               /*!< 0x00000002 */
#define RCM_CICR_LSERDYF                   RCM_CICR_LSERDYF_Msk
#define RCM_CICR_HSIRDYF_Pos               (2U)
#define RCM_CICR_HSIRDYF_Msk               (0x1UL << RCM_CICR_HSIRDYF_Pos)               /*!< 0x00000004 */
#define RCM_CICR_HSIRDYF                   RCM_CICR_HSIRDYF_Msk
#define RCM_CICR_HSERDYF_Pos               (3U)
#define RCM_CICR_HSERDYF_Msk               (0x1UL << RCM_CICR_HSERDYF_Pos)               /*!< 0x00000008 */
#define RCM_CICR_HSERDYF                   RCM_CICR_HSERDYF_Msk
#define RCM_CICR_PLLRDYF_Pos               (4U)
#define RCM_CICR_PLLRDYF_Msk               (0x1UL << RCM_CICR_PLLRDYF_Pos)               /*!< 0x00000010 */
#define RCM_CICR_PLLRDYF                   RCM_CICR_PLLRDYF_Msk
#define RCM_CICR_HSECSSF_Pos               (5U)
#define RCM_CICR_HSECSSF_Msk               (0x1UL << RCM_CICR_HSECSSF_Pos)               /*!< 0x00000020 */
#define RCM_CICR_HSECSSF                   RCM_CICR_HSECSSF_Msk
#define RCM_CICR_LSECSSF_Pos               (6U)
#define RCM_CICR_LSECSSF_Msk               (0x1UL << RCM_CICR_LSECSSF_Pos)               /*!< 0x00000040 */
#define RCM_CICR_LSECSSF                   RCM_CICR_LSECSSF_Msk
/********************  Bit definition for RCM_AHBRST register  ****************/
#define RCM_AHBRST_DMARST_Pos              (0U)
#define RCM_AHBRST_DMARST_Msk              (0x1UL << RCM_AHBRST_DMARST_Pos)              /*!< 0x00000001 */
#define RCM_AHBRST_DMARST                  RCM_AHBRST_DMARST_Msk
#define RCM_AHBRST_GPIORST_Pos             (1U)
#define RCM_AHBRST_GPIORST_Msk             (0x1UL << RCM_AHBRST_GPIORST_Pos)             /*!< 0x00000002 */
#define RCM_AHBRST_GPIORST                 RCM_AHBRST_GPIORST_Msk
#define RCM_AHBRST_ADC1RST_Pos             (5U)
#define RCM_AHBRST_ADC1RST_Msk             (0x1UL << RCM_AHBRST_ADC1RST_Pos)             /*!< 0x00000020 */
#define RCM_AHBRST_ADC1RST                 RCM_AHBRST_ADC1RST_Msk
#define RCM_AHBRST_ADC2RST_Pos             (6U)
#define RCM_AHBRST_ADC2RST_Msk             (0x1UL << RCM_AHBRST_ADC2RST_Pos)             /*!< 0x00000040 */
#define RCM_AHBRST_ADC2RST                 RCM_AHBRST_ADC2RST_Msk
#define RCM_AHBRST_ADC3RST_Pos             (7U)
#define RCM_AHBRST_ADC3RST_Msk             (0x1UL << RCM_AHBRST_ADC3RST_Pos)             /*!< 0x00000080 */
#define RCM_AHBRST_ADC3RST                 RCM_AHBRST_ADC3RST_Msk
#define RCM_AHBRST_FLASHRST_Pos            (8U)
#define RCM_AHBRST_FLASHRST_Msk            (0x1UL << RCM_AHBRST_FLASHRST_Pos)            /*!< 0x00000100 */
#define RCM_AHBRST_FLASHRST                RCM_AHBRST_FLASHRST_Msk
/********************  Bit definition for RCM_APBRST register  ****************/
#define RCM_APBRST_TMR1RST_Pos             (0U)
#define RCM_APBRST_TMR1RST_Msk             (0x1UL << RCM_APBRST_TMR1RST_Pos)             /*!< 0x00000001 */
#define RCM_APBRST_TMR1RST                 RCM_APBRST_TMR1RST_Msk
#define RCM_APBRST_TMR2RST_Pos             (1U)
#define RCM_APBRST_TMR2RST_Msk             (0x1UL << RCM_APBRST_TMR2RST_Pos)             /*!< 0x00000002 */
#define RCM_APBRST_TMR2RST                 RCM_APBRST_TMR2RST_Msk
#define RCM_APBRST_TMR3RST_Pos             (2U)
#define RCM_APBRST_TMR3RST_Msk             (0x1UL << RCM_APBRST_TMR3RST_Pos)             /*!< 0x00000004 */
#define RCM_APBRST_TMR3RST                 RCM_APBRST_TMR3RST_Msk
#define RCM_APBRST_TMR4RST_Pos             (3U)
#define RCM_APBRST_TMR4RST_Msk             (0x1UL << RCM_APBRST_TMR4RST_Pos)             /*!< 0x00000008 */
#define RCM_APBRST_TMR4RST                 RCM_APBRST_TMR4RST_Msk
#define RCM_APBRST_SPIRST_Pos              (4U)
#define RCM_APBRST_SPIRST_Msk              (0x1UL << RCM_APBRST_SPIRST_Pos)              /*!< 0x00000010 */
#define RCM_APBRST_SPIRST                  RCM_APBRST_SPIRST_Msk
#define RCM_APBRST_USART1RST_Pos           (5U)
#define RCM_APBRST_USART1RST_Msk           (0x1UL << RCM_APBRST_USART1RST_Pos)           /*!< 0x00000020 */
#define RCM_APBRST_USART1RST               RCM_APBRST_USART1RST_Msk
#define RCM_APBRST_USART2RST_Pos           (6U)
#define RCM_APBRST_USART2RST_Msk           (0x1UL << RCM_APBRST_USART2RST_Pos)           /*!< 0x00000040 */
#define RCM_APBRST_USART2RST               RCM_APBRST_USART2RST_Msk
#define RCM_APBRST_I2CRST_Pos              (7U)
#define RCM_APBRST_I2CRST_Msk              (0x1UL << RCM_APBRST_I2CRST_Pos)              /*!< 0x00000080 */
#define RCM_APBRST_I2CRST                  RCM_APBRST_I2CRST_Msk
#define RCM_APBRST_TSRST_Pos               (9U)
#define RCM_APBRST_TSRST_Msk               (0x1UL << RCM_APBRST_TSRST_Pos)               /*!< 0x00000200 */
#define RCM_APBRST_TSRST                   RCM_APBRST_TSRST_Msk
#define RCM_APBRST_EINTRST_Pos             (10U)
#define RCM_APBRST_EINTRST_Msk             (0x1UL << RCM_APBRST_EINTRST_Pos)             /*!< 0x00000400 */
#define RCM_APBRST_EINTRST                 RCM_APBRST_EINTRST_Msk
#define RCM_APBRST_DAC1RST_Pos             (11U)
#define RCM_APBRST_DAC1RST_Msk             (0x1UL << RCM_APBRST_DAC1RST_Pos)             /*!< 0x00000800 */
#define RCM_APBRST_DAC1RST                 RCM_APBRST_DAC1RST_Msk
#define RCM_APBRST_DAC2RST_Pos             (12U)
#define RCM_APBRST_DAC2RST_Msk             (0x1UL << RCM_APBRST_DAC2RST_Pos)             /*!< 0x00001000 */
#define RCM_APBRST_DAC2RST                 RCM_APBRST_DAC2RST_Msk
#define RCM_APBRST_COMPRST_Pos             (13U)
#define RCM_APBRST_COMPRST_Msk             (0x1UL << RCM_APBRST_COMPRST_Pos)             /*!< 0x00002000 */
#define RCM_APBRST_COMPRST                 RCM_APBRST_COMPRST_Msk
/********************  Bit definition for RCM_AHBCG register  *****************/
#define RCM_AHBCG_DMACEN_Pos               (0U)
#define RCM_AHBCG_DMACEN_Msk               (0x1UL << RCM_AHBCG_DMACEN_Pos)               /*!< 0x00000001 */
#define RCM_AHBCG_DMACEN                   RCM_AHBCG_DMACEN_Msk
#define RCM_AHBCG_GPIOCEN_Pos              (1U)
#define RCM_AHBCG_GPIOCEN_Msk              (0x1UL << RCM_AHBCG_GPIOCEN_Pos)              /*!< 0x00000002 */
#define RCM_AHBCG_GPIOCEN                  RCM_AHBCG_GPIOCEN_Msk
#define RCM_AHBCG_ADC1EN_Pos               (5U)
#define RCM_AHBCG_ADC1EN_Msk               (0x1UL << RCM_AHBCG_ADC1EN_Pos)               /*!< 0x00000020 */
#define RCM_AHBCG_ADC1EN                   RCM_AHBCG_ADC1EN_Msk
#define RCM_AHBCG_ADC2EN_Pos               (6U)
#define RCM_AHBCG_ADC2EN_Msk               (0x1UL << RCM_AHBCG_ADC2EN_Pos)               /*!< 0x00000040 */
#define RCM_AHBCG_ADC2EN                   RCM_AHBCG_ADC2EN_Msk
#define RCM_AHBCG_ADC3EN_Pos               (7U)
#define RCM_AHBCG_ADC3EN_Msk               (0x1UL << RCM_AHBCG_ADC3EN_Pos)               /*!< 0x00000080 */
#define RCM_AHBCG_ADC3EN                   RCM_AHBCG_ADC3EN_Msk
#define RCM_AHBCG_FLASHCEN_Pos             (8U)
#define RCM_AHBCG_FLASHCEN_Msk             (0x1UL << RCM_AHBCG_FLASHCEN_Pos)             /*!< 0x00000100 */
#define RCM_AHBCG_FLASHCEN                 RCM_AHBCG_FLASHCEN_Msk
#define RCM_AHBCG_ROMCEN_Pos               (9U)
#define RCM_AHBCG_ROMCEN_Msk               (0x1UL << RCM_AHBCG_ROMCEN_Pos)               /*!< 0x00000200 */
#define RCM_AHBCG_ROMCEN                   RCM_AHBCG_ROMCEN_Msk
/********************  Bit definition for RCM_APBCG register  *****************/
#define RCM_APBCG_TMR1CEN_Pos              (0U)
#define RCM_APBCG_TMR1CEN_Msk              (0x1UL << RCM_APBCG_TMR1CEN_Pos)              /*!< 0x00000001 */
#define RCM_APBCG_TMR1CEN                  RCM_APBCG_TMR1CEN_Msk
#define RCM_APBCG_TMR2CEN_Pos              (1U)
#define RCM_APBCG_TMR2CEN_Msk              (0x1UL << RCM_APBCG_TMR2CEN_Pos)              /*!< 0x00000002 */
#define RCM_APBCG_TMR2CEN                  RCM_APBCG_TMR2CEN_Msk
#define RCM_APBCG_TMR3CEN_Pos              (2U)
#define RCM_APBCG_TMR3CEN_Msk              (0x1UL << RCM_APBCG_TMR3CEN_Pos)              /*!< 0x00000004 */
#define RCM_APBCG_TMR3CEN                  RCM_APBCG_TMR3CEN_Msk
#define RCM_APBCG_TMR4CEN_Pos              (3U)
#define RCM_APBCG_TMR4CEN_Msk              (0x1UL << RCM_APBCG_TMR4CEN_Pos)              /*!< 0x00000008 */
#define RCM_APBCG_TMR4CEN                  RCM_APBCG_TMR4CEN_Msk
#define RCM_APBCG_SPICEN_Pos               (4U)
#define RCM_APBCG_SPICEN_Msk               (0x1UL << RCM_APBCG_SPICEN_Pos)               /*!< 0x00000010 */
#define RCM_APBCG_SPICEN                   RCM_APBCG_SPICEN_Msk
#define RCM_APBCG_USART1CEN_Pos            (5U)
#define RCM_APBCG_USART1CEN_Msk            (0x1UL << RCM_APBCG_USART1CEN_Pos)            /*!< 0x00000020 */
#define RCM_APBCG_USART1CEN                RCM_APBCG_USART1CEN_Msk
#define RCM_APBCG_USART2CEN_Pos            (6U)
#define RCM_APBCG_USART2CEN_Msk            (0x1UL << RCM_APBCG_USART2CEN_Pos)            /*!< 0x00000040 */
#define RCM_APBCG_USART2CEN                RCM_APBCG_USART2CEN_Msk
#define RCM_APBCG_I2CCEN_Pos               (7U)
#define RCM_APBCG_I2CCEN_Msk               (0x1UL << RCM_APBCG_I2CCEN_Pos)               /*!< 0x00000080 */
#define RCM_APBCG_I2CCEN                   RCM_APBCG_I2CCEN_Msk
#define RCM_APBCG_WWDTCEN_Pos              (8U)
#define RCM_APBCG_WWDTCEN_Msk              (0x1UL << RCM_APBCG_WWDTCEN_Pos)              /*!< 0x00000100 */
#define RCM_APBCG_WWDTCEN                  RCM_APBCG_WWDTCEN_Msk
#define RCM_APBCG_TSCEN_Pos                (9U)
#define RCM_APBCG_TSCEN_Msk                (0x1UL << RCM_APBCG_TSCEN_Pos)                /*!< 0x00000200 */
#define RCM_APBCG_TSCEN                    RCM_APBCG_TSCEN_Msk
#define RCM_APBCG_EINTCEN_Pos              (10U)
#define RCM_APBCG_EINTCEN_Msk              (0x1UL << RCM_APBCG_EINTCEN_Pos)              /*!< 0x00000400 */
#define RCM_APBCG_EINTCEN                  RCM_APBCG_EINTCEN_Msk
#define RCM_APBCG_DAC1CEN_Pos              (11U)
#define RCM_APBCG_DAC1CEN_Msk              (0x1UL << RCM_APBCG_DAC1CEN_Pos)              /*!< 0x00000800 */
#define RCM_APBCG_DAC1CEN                  RCM_APBCG_DAC1CEN_Msk
#define RCM_APBCG_DAC2CEN_Pos              (12U)
#define RCM_APBCG_DAC2CEN_Msk              (0x1UL << RCM_APBCG_DAC2CEN_Pos)              /*!< 0x00001000 */
#define RCM_APBCG_DAC2CEN                  RCM_APBCG_DAC2CEN_Msk
#define RCM_APBCG_COMPCEN_Pos              (13U)
#define RCM_APBCG_COMPCEN_Msk              (0x1UL << RCM_APBCG_COMPCEN_Pos)              /*!< 0x00002000 */
#define RCM_APBCG_COMPCEN                  RCM_APBCG_COMPCEN_Msk
#define RCM_APBCG_BKPCEN_Pos               (14U)
#define RCM_APBCG_BKPCEN_Msk               (0x1UL << RCM_APBCG_BKPCEN_Pos )              /*!< 0x00004000 */
#define RCM_APBCG_BKPCEN                   RCM_APBCG_BKPCEN_Msk
/********************  Bit definition for RCM_PWRCR register  *****************/
#define RCM_PWRCR_LPM_Pos                  (0U)
#define RCM_PWRCR_LPM_Msk                  (0x1UL << RCM_PWRCR_LPM_Pos)                  /*!< 0x00000001 */
#define RCM_PWRCR_LPM                      RCM_PWRCR_LPM_Msk
#define RCM_PWRCR_RAM1RET_Pos              (1U)
#define RCM_PWRCR_RAM1RET_Msk              (0x1UL << RCM_PWRCR_RAM1RET_Pos)              /*!< 0x00000002 */
#define RCM_PWRCR_RAM1RET                  RCM_PWRCR_RAM1RET_Msk
#define RCM_PWRCR_BKPWP_Pos                (8U)
#define RCM_PWRCR_BKPWP_Msk                (0x1UL << RCM_PWRCR_BKPWP_Pos)                /*!< 0x00000100 */
#define RCM_PWRCR_BKPWP                    RCM_PWRCR_BKPWP_Msk
/********************  Bit definition for RCM_RSTCSR register  ****************/
#define RCM_RSTCSR_OPRSTF_Pos              (0U)
#define RCM_RSTCSR_OPRSTF_Msk              (0x1UL << RCM_RSTCSR_OPRSTF_Pos)              /*!< 0x00000001 */
#define RCM_RSTCSR_OPRSTF                  RCM_RSTCSR_OPRSTF_Msk
#define RCM_RSTCSR_PINRSTF_Pos             (1U)
#define RCM_RSTCSR_PINRSTF_Msk             (0x1UL << RCM_RSTCSR_PINRSTF_Pos)             /*!< 0x00000002 */
#define RCM_RSTCSR_PINRSTF                 RCM_RSTCSR_PINRSTF_Msk
#define RCM_RSTCSR_PORRSTF_Pos             (2U)
#define RCM_RSTCSR_PORRSTF_Msk             (0x1UL << RCM_RSTCSR_PORRSTF_Pos)             /*!< 0x00000004 */
#define RCM_RSTCSR_PORRSTF                 RCM_RSTCSR_PORRSTF_Msk
#define RCM_RSTCSR_SFTRSTF_Pos             (3U)
#define RCM_RSTCSR_SFTRSTF_Msk             (0x1UL << RCM_RSTCSR_SFTRSTF_Pos)             /*!< 0x00000008 */
#define RCM_RSTCSR_SFTRSTF                 RCM_RSTCSR_SFTRSTF_Msk
#define RCM_RSTCSR_IWDTRSTF_Pos            (4U)
#define RCM_RSTCSR_IWDTRSTF_Msk            (0x1UL << RCM_RSTCSR_IWDTRSTF_Pos)            /*!< 0x00000010 */
#define RCM_RSTCSR_IWDTRSTF                RCM_RSTCSR_IWDTRSTF_Msk
#define RCM_RSTCSR_WWDTRSTF_Pos            (5U)
#define RCM_RSTCSR_WWDTRSTF_Msk            (0x1UL << RCM_RSTCSR_WWDTRSTF_Pos)            /*!< 0x00000020 */
#define RCM_RSTCSR_WWDTRSTF                RCM_RSTCSR_WWDTRSTF_Msk
/********************  Bit definition for RCM_ADCCR register  ****************/
#define RCM_ADCCR_ADC16ADIV_Pos            (0U)
#define RCM_ADCCR_ADC16ADIV_Msk            (0x3UL << RCM_ADCCR_ADC16ADIV_Pos)            /*!< 0x00000003 */
#define RCM_ADCCR_ADC16ADIV                RCM_ADCCR_ADC16ADIV_Msk
#define RCM_ADCCR_ADC16ADIV_0              (0x1UL << RCM_ADCCR_ADC16ADIV_Pos)
#define RCM_ADCCR_ADC16ADIV_1              (0x2UL << RCM_ADCCR_ADC16ADIV_Pos)

#define RCM_ADCCR_ADC16ACLKRDY_Pos         (2U)
#define RCM_ADCCR_ADC16ACLKRDY_Msk         (0x1UL << RCM_ADCCR_ADC16ACLKRDY_Pos)         /*!< 0x00000004 */
#define RCM_ADCCR_ADC16ACLKRDY             RCM_ADCCR_ADC16ACLKRDY_Msk
#define RCM_ADCCR_ADC12ADIV_Pos            (5U)
#define RCM_ADCCR_ADC12ADIV_Msk            (0x3UL << RCM_ADCCR_ADC12ADIV_Pos)            /*!< 0x00000060 */
#define RCM_ADCCR_ADC12ADIV                RCM_ADCCR_ADC12ADIV_Msk
#define RCM_ADCCR_ADC12ADIV_0              (0x1UL << RCM_ADCCR_ADC12ADIV_Pos)
#define RCM_ADCCR_ADC12ADIV_1              (0x2UL << RCM_ADCCR_ADC12ADIV_Pos)

#define RCM_ADCCR_ADC12ACLKRDY_Pos         (7U)
#define RCM_ADCCR_ADC12ACLKRDY_Msk         (0x1UL << RCM_ADCCR_ADC12ACLKRDY_Pos)         /*!< 0x00000080 */
#define RCM_ADCCR_ADC12ACLKRDY             RCM_ADCCR_ADC12ACLKRDY_Msk
#define RCM_ADCCR_ADCACLKSEL_Pos           (8U)
#define RCM_ADCCR_ADCACLKSEL_Msk           (0x1UL << RCM_ADCCR_ADCACLKSEL_Pos)           /*!< 0x00000100 */
#define RCM_ADCCR_ADCACLKSEL               RCM_ADCCR_ADCACLKSEL_Msk

/********************  Bit definition for RCM_SYS_ANACR0 register  ***********/
#define RCM_SYS_ANACR0_LSELKDTEN_Pos       (16U)
#define RCM_SYS_ANACR0_LSELKDTEN_Msk       (0x1UL << RCM_SYS_ANACR0_LSELKDTEN_Pos)       /*!< 0x00010000 */
#define RCM_SYS_ANACR0_LSELKDTEN           RCM_SYS_ANACR0_LSELKDTEN_Msk
#define RCM_SYS_ANACR0_LSEDRV_Pos          (17U)
#define RCM_SYS_ANACR0_LSEDRV_Msk          (0x1UL << RCM_SYS_ANACR0_LSEDRV_Pos)          /*!< 0x00020000 */
#define RCM_SYS_ANACR0_LSEDRV              RCM_SYS_ANACR0_LSEDRV_Msk
#define RCM_SYS_ANACR0_LSELKDTSTA_Pos      (18U)
#define RCM_SYS_ANACR0_LSELKDTSTA_Msk      (0x1UL << RCM_SYS_ANACR0_LSELKDTSTA_Pos)      /*!< 0x00040000 */
#define RCM_SYS_ANACR0_LSELKDTSTA          RCM_SYS_ANACR0_LSELKDTSTA_Msk
#define RCM_SYS_ANACR0_LSEAUTOTRIMREQ_Pos  (19U)
#define RCM_SYS_ANACR0_LSEAUTOTRIMREQ_Msk  (0x1UL << RCM_SYS_ANACR0_LSEAUTOTRIMREQ_Pos)  /*!< 0x00080000 */
#define RCM_SYS_ANACR0_LSEAUTOTRIMREQ      RCM_SYS_ANACR0_LSEAUTOTRIMREQ_Msk
#define RCM_SYS_ANACR0_LSE_LEAKTRIM_Pos    (20U)
#define RCM_SYS_ANACR0_LSE_LEAKTRIM_Msk    (0xFUL << RCM_SYS_ANACR0_LSE_LEAKTRIM_Pos)    /*!< 0x00F00000 */
#define RCM_SYS_ANACR0_LSE_LEAKTRIM        RCM_SYS_ANACR0_LSE_LEAKTRIM_Msk

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_CTRL register  *****************/
#define RTC_CTRL_SECIEN_Pos                (0U)
#define RTC_CTRL_SECIEN_Msk                (0x1UL << RTC_CTRL_SECIEN_Pos)                /*!< 0x00000001 */
#define RTC_CTRL_SECIEN                    RTC_CTRL_SECIEN_Msk
#define RTC_CTRL_ALRIEN_Pos                (1U)
#define RTC_CTRL_ALRIEN_Msk                (0x1UL << RTC_CTRL_ALRIEN_Pos)                /*!< 0x00000002 */
#define RTC_CTRL_ALRIEN                    RTC_CTRL_ALRIEN_Msk
#define RTC_CTRL_OVRIEN_Pos                (2U)
#define RTC_CTRL_OVRIEN_Msk                (0x1UL << RTC_CTRL_OVRIEN_Pos)                /*!< 0x00000004 */
#define RTC_CTRL_OVRIEN                    RTC_CTRL_OVRIEN_Msk

/********************  Bits definition for RTC_CSTS register  *****************/
#define RTC_CSTS_SECFLG_Pos                (0U)
#define RTC_CSTS_SECFLG_Msk                (0x1UL << RTC_CSTS_SECFLG_Pos)                /*!< 0x00000001 */
#define RTC_CSTS_SECFLG                    RTC_CSTS_SECFLG_Msk
#define RTC_CSTS_ALRFLG_Pos                (1U)
#define RTC_CSTS_ALRFLG_Msk                (0x1UL << RTC_CSTS_ALRFLG_Pos)                /*!< 0x00000002 */
#define RTC_CSTS_ALRFLG                    RTC_CSTS_ALRFLG_Msk
#define RTC_CSTS_OVRFLG_Pos                (2U)
#define RTC_CSTS_OVRFLG_Msk                (0x1UL << RTC_CSTS_OVRFLG_Pos)                /*!< 0x00000004 */
#define RTC_CSTS_OVRFLG                    RTC_CSTS_OVRFLG_Msk
#define RTC_CSTS_RSYNCFLG_Pos              (3U)
#define RTC_CSTS_RSYNCFLG_Msk              (0x1UL << RTC_CSTS_RSYNCFLG_Pos)              /*!< 0x00000008 */
#define RTC_CSTS_RSYNCFLG                  RTC_CSTS_RSYNCFLG_Msk
#define RTC_CSTS_CFGMFLG_Pos               (4U)
#define RTC_CSTS_CFGMFLG_Msk               (0x1UL << RTC_CSTS_CFGMFLG_Pos)               /*!< 0x00000010 */
#define RTC_CSTS_CFGMFLG                   RTC_CSTS_CFGMFLG_Msk
#define RTC_CSTS_OCFLG_Pos                 (5U)
#define RTC_CSTS_OCFLG_Msk                 (0x1UL << RTC_CSTS_OCFLG_Pos)                 /*!< 0x00000020 */
#define RTC_CSTS_OCFLG                     RTC_CSTS_OCFLG_Msk

/********************  Bits definition for RTC_PSCRLDH register  **************/
#define RTC_PSCRLD_PSCRLDH_Pos             (0U)
#define RTC_PSCRLD_PSCRLDH_Msk             (0xFUL << RTC_PSCRLD_PSCRLDH_Pos)             /*!< 0x0000000F */
#define RTC_PSCRLD_PSCRLDH                 RTC_PSCRLD_PSCRLDH_Msk

/********************  Bits definition for RTC_PSCRLDL register  **************/
#define RTC_PSCRLD_PSCRLDL_Pos             (0U)
#define RTC_PSCRLD_PSCRLDL_Msk             (0xFFFFUL << RTC_PSCRLD_PSCRLDL_Pos)          /*!< 0x0000FFFF */
#define RTC_PSCRLD_PSCRLDL                 RTC_PSCRLD_PSCRLDL_Msk

/********************  Bits definition for RTC_DIVH register  *****************/
#define RTC_DIVH_DIVH_Pos                  (0U)
#define RTC_DIVH_DIVH_Msk                  (0xFUL << RTC_DIVH_DIVH_Pos)                  /*!< 0x0000000F */
#define RTC_DIVH_DIVH                      RTC_DIVH_DIVH_Msk

/********************  Bits definition for RTC_DIVL register  *****************/
#define RTC_DIVL_DIVL_Pos                  (0U)
#define RTC_DIVL_DIVL_Msk                  (0xFFFFUL << RTC_DIVL_DIVL_Pos)               /*!< 0x0000FFFF */
#define RTC_DIVL_DIVL                      RTC_DIVL_DIVL_Msk

/********************  Bits definition for RTC_CNTH register  *****************/
#define RTC_CNT_CNTH_Pos                   (0U)
#define RTC_CNT_CNTH_Msk                   (0xFUL << RTC_CNT_CNTH_Pos)                   /*!< 0x0000000F */
#define RTC_CNT_CNTH                       RTC_CNT_CNTH_Msk

/********************  Bits definition for RTC_CNTL register  *****************/
#define RTC_CNT_CNTL_Pos                   (0U)
#define RTC_CNT_CNTL_Msk                   (0xFFFFUL << RTC_CNT_CNTL_Pos)                /*!< 0x0000FFFF */
#define RTC_CNT_CNTL                       RTC_CNT_CNTL_Msk

/********************  Bits definition for RTC_ALRH register  *****************/
#define RTC_ALRH_ALRH_Pos                  (0U)
#define RTC_ALRH_ALRH_Msk                  (0xFFFFUL << RTC_ALRH_ALRH_Pos)               /*!< 0x0000000F */
#define RTC_ALRH_ALRH                      RTC_ALRH_ALRH_Msk

/********************  Bits definition for RTC_ALRL register  *****************/
#define RTC_ALRL_ALRL_Pos                  (0U)
#define RTC_ALRL_ALRL_Msk                  (0xFFFFUL << RTC_ALRL_ALRL_Pos)               /*!< 0x0000FFFF */
#define RTC_ALRL_ALRL                      RTC_ALRL_ALRL_Msk

/******************** Number of backup registers ******************************/
#define BKP_NUMBER  0x000000010U

/******************************************************************************/
/*                                                                            */
/*                                 BKP                                        */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for BKP_DR_DATA register  *****************/
#define BKP_DR0_DATA_Pos                   (0U)
#define BKP_DR0_DATA_Msk                   (0xFFFFUL << BKP_DR0_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR0_DATA                       BKP_DR0_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR1_DATA_Pos                   (0U)
#define BKP_DR1_DATA_Msk                   (0xFFFFUL << BKP_DR1_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR1_DATA                       BKP_DR1_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR2_DATA_Pos                   (0U)
#define BKP_DR2_DATA_Msk                   (0xFFFFUL << BKP_DR2_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR2_DATA                       BKP_DR2_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR3_DATA_Pos                   (0U)
#define BKP_DR3_DATA_Msk                   (0xFFFFUL << BKP_DR3_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR3_DATA                       BKP_DR3_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR4_DATA_Pos                   (0U)
#define BKP_DR4_DATA_Msk                   (0xFFFFUL << BKP_DR4_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR4_DATA                       BKP_DR4_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR5_DATA_Pos                   (0U)
#define BKP_DR5_DATA_Msk                   (0xFFFFUL << BKP_DR5_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR5_DATA                       BKP_DR5_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR6_DATA_Pos                   (0U)
#define BKP_DR6_DATA_Msk                   (0xFFFFUL << BKP_DR6_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR6_DATA                       BKP_DR6_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR7_DATA_Pos                   (0U)
#define BKP_DR7_DATA_Msk                   (0xFFFFUL << BKP_DR7_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR7_DATA                       BKP_DR7_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR8_DATA_Pos                   (0U)
#define BKP_DR8_DATA_Msk                   (0xFFFFUL << BKP_DR8_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR8_DATA                       BKP_DR8_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR9_DATA_Pos                   (0U)
#define BKP_DR9_DATA_Msk                   (0xFFFFUL << BKP_DR9_DATA_Pos )               /*!< 0x0000FFFF */
#define BKP_DR9_DATA                       BKP_DR9_DATA_Msk                              /*!< BKP data bit */

#define BKP_DR10_DATA_Pos                  (0U)
#define BKP_DR10_DATA_Msk                  (0xFFFFUL << BKP_DR10_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR10_DATA                      BKP_DR10_DATA_Msk                             /*!< BKP data bit */

#define BKP_DR11_DATA_Pos                  (0U)
#define BKP_DR11_DATA_Msk                  (0xFFFFUL << BKP_DR11_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR11_DATA                      BKP_DR11_DATA_Msk                             /*!< BKP data bit */

#define BKP_DR12_DATA_Pos                  (0U)
#define BKP_DR12_DATA_Msk                  (0xFFFFUL << BKP_DR12_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR12_DATA                      BKP_DR12_DATA_Msk                             /*!< BKP data bit */

#define BKP_DR13_DATA_Pos                  (0U)
#define BKP_DR13_DATA_Msk                  (0xFFFFUL << BKP_DR13_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR13_DATA                      BKP_DR13_DATA_Msk                             /*!< BKP data bit */

#define BKP_DR14_DATA_Pos                  (0U)
#define BKP_DR14_DATA_Msk                  (0xFFFFUL << BKP_DR14_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR14_DATA                      BKP_DR14_DATA_Msk                             /*!< BKP data bit */

#define BKP_DR15_DATA_Pos                  (0U)
#define BKP_DR15_DATA_Msk                  (0xFFFFUL << BKP_DR15_DATA_Pos )              /*!< 0x0000FFFF */
#define BKP_DR15_DATA                      BKP_DR15_DATA_Msk                             /*!< BKP data bit */

/******************************************************************************/
/*                                                                            */
/*                                 LPTMR                                      */
/*                                                                            */
/******************************************************************************/

/******************  Bit definition for LPTMR_CR register  ********************/
#define LPTMR_CR_EN_Pos                    (0U)
#define LPTMR_CR_EN_Msk                    (0x1UL << LPTMR_CR_EN_Pos)                    /*!< 0x00000001 */
#define LPTMR_CR_EN                        LPTMR_CR_EN_Msk
#define LPTMR_CR_IREN_Pos                  (1U)
#define LPTMR_CR_IREN_Msk                  (0x1UL << LPTMR_CR_IREN_Pos)                  /*!< 0x00000002 */
#define LPTMR_CR_IREN                      LPTMR_CR_IREN_Msk
/******************  Bit definition for LPTMR_PS register  ********************/
#define LPTMR_PSC_PS_Pos                   (0U)
#define LPTMR_PSC_PS_Msk                   (0xFUL << LPTMR_PSC_PS_Pos)                   /*!< 0x0000000F */
#define LPTMR_PSC_PS                       LPTMR_PSC_PS_Msk
/******************  Bit definition for LPTMR_WVR register  ********************/
#define LPTMR_WVR_RV_Pos                   (0U)
#define LPTMR_WVR_RV_Msk                   (0xFFFFUL << LPTMR_WVR_RV_Pos)                /*!< 0x0000FFFF */
#define LPTMR_WVR_RV                       LPTMR_WVR_RV_Msk
/******************  Bit definition for LPTMR_SR register  ********************/
#define LPTMR_SR_WK_STS_Pos                (0U)
#define LPTMR_SR_WK_STS_Msk                (0x1UL << LPTMR_SR_WK_STS_Pos)                /*!< 0x00000001 */
#define LPTMR_SR_WK_STS                    LPTMR_SR_WK_STS_Msk
#define LPTMR_SR_PU_Pos                    (1U)
#define LPTMR_SR_PU_Msk                    (0x1UL << LPTMR_SR_PU_Pos)                    /*!< 0x00000002 */
#define LPTMR_SR_PU                        LPTMR_SR_PU_Msk
#define LPTMR_SR_RU_Pos                    (2U)
#define LPTMR_SR_RU_Msk                    (0x1UL << LPTMR_SR_RU_Pos)                    /*!< 0x00000003 */
#define LPTMR_SR_RU                        LPTMR_SR_RU_Msk

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/
#define SPI_I2S_FULLDUPLEX_SUPPORT                                                       /*!< I2S Full-Duplex support */

/*******************  Bit definition for SPI_CTRL1 register  ******************/
#define SPI_CTRL1_CPHA_Pos                 (0U)
#define SPI_CTRL1_CPHA_Msk                 (0x1UL << SPI_CTRL1_CPHA_Pos)                 /*!< 0x00000001 */
#define SPI_CTRL1_CPHA                     SPI_CTRL1_CPHA_Msk                            /*!< Clock Phase */
#define SPI_CTRL1_CPOL_Pos                 (1U)
#define SPI_CTRL1_CPOL_Msk                 (0x1UL << SPI_CTRL1_CPOL_Pos)                 /*!< 0x00000000 */
#define SPI_CTRL1_CPOL                     SPI_CTRL1_CPOL_Msk                            /*!< Clock Polarity */
#define SPI_CTRL1_MSMCFG_Pos               (2U)
#define SPI_CTRL1_MSMCFG_Msk               (0x1UL << SPI_CTRL1_MSMCFG_Pos)               /*!< 0x00000004 */
#define SPI_CTRL1_MSMCFG                   SPI_CTRL1_MSMCFG_Msk                          /*!< Master Selection */
#define SPI_CTRL1_BRSEL_Pos                (3U)
#define SPI_CTRL1_BRSEL_Msk                (0x7UL << SPI_CTRL1_BRSEL_Pos)                /*!< 0x00000038 */
#define SPI_CTRL1_BRSEL                    SPI_CTRL1_BRSEL_Msk                           /*!< BR[2:0] bits (Baud Rate Control) */
#define SPI_CTRL1_BRSEL_0                  (0x1UL << SPI_CTRL1_BRSEL_Pos)                /*!< 0x00000008 */
#define SPI_CTRL1_BRSEL_1                  (0x2UL << SPI_CTRL1_BRSEL_Pos)                /*!< 0x00000010 */
#define SPI_CTRL1_BRSEL_2                  (0x4UL << SPI_CTRL1_BRSEL_Pos)                /*!< 0x00000020 */

#define SPI_CTRL1_SPIEN_Pos                (6U)
#define SPI_CTRL1_SPIEN_Msk                (0x1UL << SPI_CTRL1_SPIEN_Pos)                /*!< 0x00000040 */
#define SPI_CTRL1_SPIEN                    SPI_CTRL1_SPIEN_Msk                           /*!< SPI Enable */
#define SPI_CTRL1_LSBSEL_Pos               (7U)
#define SPI_CTRL1_LSBSEL_Msk               (0x1UL << SPI_CTRL1_LSBSEL_Pos)               /*!< 0x00000080 */
#define SPI_CTRL1_LSBSEL                   SPI_CTRL1_LSBSEL_Msk                          /*!< Frame Format */
#define SPI_CTRL1_ISSEL_Pos                (8U)
#define SPI_CTRL1_ISSEL_Msk                (0x1UL << SPI_CTRL1_ISSEL_Pos)                /*!< 0x00000100 */
#define SPI_CTRL1_ISSEL                    SPI_CTRL1_ISSEL_Msk                           /*!< Internal slave select */
#define SPI_CTRL1_SSEN_Pos                 (9U)
#define SPI_CTRL1_SSEN_Msk                 (0x1UL << SPI_CTRL1_SSEN_Pos)                 /*!< 0x00000200 */
#define SPI_CTRL1_SSEN                     SPI_CTRL1_SSEN_Msk                            /*!< Software slave management */
#define SPI_CTRL1_RXOMEN_Pos               (10U)
#define SPI_CTRL1_RXOMEN_Msk               (0x1UL << SPI_CTRL1_RXOMEN_Pos)               /*!< 0x00000400 */
#define SPI_CTRL1_RXOMEN                   SPI_CTRL1_RXOMEN_Msk                          /*!< Receive only */
#define SPI_CTRL1_DFLSEL_Pos               (11U)
#define SPI_CTRL1_DFLSEL_Msk               (0x1UL << SPI_CTRL1_DFLSEL_Pos)               /*!< 0x00000800 */
#define SPI_CTRL1_DFLSEL                   SPI_CTRL1_DFLSEL_Msk                          /*!< Data Frame Format */
#define SPI_CTRL1_CRCNXT_Pos               (12U)
#define SPI_CTRL1_CRCNXT_Msk               (0x1UL << SPI_CTRL1_CRCNXT_Pos)               /*!< 0x00001000 */
#define SPI_CTRL1_CRCNXT                   SPI_CTRL1_CRCNXT_Msk                          /*!< Transmit CRC next */
#define SPI_CTRL1_CRCEN_Pos                (13U)
#define SPI_CTRL1_CRCEN_Msk                (0x1UL << SPI_CTRL1_CRCEN_Pos)                /*!< 0x00002000 */
#define SPI_CTRL1_CRCEN                    SPI_CTRL1_CRCEN_Msk                           /*!< Hardware CRC calculation enable */
#define SPI_CTRL1_BMOEN_Pos                (14U)
#define SPI_CTRL1_BMOEN_Msk                (0x1UL << SPI_CTRL1_BMOEN_Pos)                /*!< 0x00004000 */
#define SPI_CTRL1_BMOEN                    SPI_CTRL1_BMOEN_Msk                           /*!< Output enable in bidirectional mode */
#define SPI_CTRL1_BMEN_Pos                 (15U)
#define SPI_CTRL1_BMEN_Msk                 (0x1UL << SPI_CTRL1_BMEN_Pos)                 /*!< 0x00008000 */
#define SPI_CTRL1_BMEN                     SPI_CTRL1_BMEN_Msk                            /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CTRL2 register  ******************/
#define SPI_CTRL2_RXDEN_Pos                (0U)
#define SPI_CTRL2_RXDEN_Msk                (0x1UL << SPI_CTRL2_RXDEN_Pos)                /*!< 0x00000001 */
#define SPI_CTRL2_RXDEN                    SPI_CTRL2_RXDEN_Msk                           /*!< Rx Buffer DMA Enable */
#define SPI_CTRL2_TXDEN_Pos                (1U)
#define SPI_CTRL2_TXDEN_Msk                (0x1UL << SPI_CTRL2_TXDEN_Pos)                /*!< 0x00000000 */
#define SPI_CTRL2_TXDEN                    SPI_CTRL2_TXDEN_Msk                           /*!< Tx Buffer DMA Enable */
#define SPI_CTRL2_SSOEN_Pos                (2U)
#define SPI_CTRL2_SSOEN_Msk                (0x1UL << SPI_CTRL2_SSOEN_Pos)                /*!< 0x00000004 */
#define SPI_CTRL2_SSOEN                    SPI_CTRL2_SSOEN_Msk                           /*!< SS Output Enable */
#define SPI_CTRL2_FRFCFG_Pos               (4U)
#define SPI_CTRL2_FRFCFG_Msk               (0x1UL << SPI_CTRL2_FRFCFG_Pos)               /*!< 0x00000010 */
#define SPI_CTRL2_FRFCFG                   SPI_CTRL2_FRFCFG_Msk                          /*!< Frame Format */
#define SPI_CTRL2_ERRIEN_Pos               (5U)
#define SPI_CTRL2_ERRIEN_Msk               (0x1UL << SPI_CTRL2_ERRIEN_Pos)               /*!< 0x00000020 */
#define SPI_CTRL2_ERRIEN                   SPI_CTRL2_ERRIEN_Msk                          /*!< Error Interrupt Enable */
#define SPI_CTRL2_RXBNEIEN_Pos             (6U)
#define SPI_CTRL2_RXBNEIEN_Msk             (0x1UL << SPI_CTRL2_RXBNEIEN_Pos)             /*!< 0x00000040 */
#define SPI_CTRL2_RXBNEIEN                 SPI_CTRL2_RXBNEIEN_Msk                        /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CTRL2_TXBEIEN_Pos              (7U)
#define SPI_CTRL2_TXBEIEN_Msk              (0x1UL << SPI_CTRL2_TXBEIEN_Pos)              /*!< 0x00000080 */
#define SPI_CTRL2_TXBEIEN                  SPI_CTRL2_TXBEIEN_Msk                         /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_STS register  *******************/
#define SPI_STS_RXBNEFLG_Pos               (0U)
#define SPI_STS_RXBNEFLG_Msk               (0x1UL << SPI_STS_RXBNEFLG_Pos)               /*!< 0x00000001 */
#define SPI_STS_RXBNEFLG                   SPI_STS_RXBNEFLG_Msk                          /*!< Receive buffer Not Empty */
#define SPI_STS_TXBEFLG_Pos                (1U)
#define SPI_STS_TXBEFLG_Msk                (0x1UL << SPI_STS_TXBEFLG_Pos)                /*!< 0x00000000 */
#define SPI_STS_TXBEFLG                    SPI_STS_TXBEFLG_Msk                           /*!< Transmit buffer Empty */
#define SPI_STS_CRCEFLG_Pos                (4U)
#define SPI_STS_CRCEFLG_Msk                (0x1UL << SPI_STS_CRCEFLG_Pos)                /*!< 0x00000010 */
#define SPI_STS_CRCEFLG                    SPI_STS_CRCEFLG_Msk                           /*!< CRC Error flag */
#define SPI_STS_MEFLG_Pos                  (5U)
#define SPI_STS_MEFLG_Msk                  (0x1UL << SPI_STS_MEFLG_Pos)                  /*!< 0x00000020 */
#define SPI_STS_MEFLG                      SPI_STS_MEFLG_Msk                             /*!< Mode fault */
#define SPI_STS_OVRFLG_Pos                 (6U)
#define SPI_STS_OVRFLG_Msk                 (0x1UL << SPI_STS_OVRFLG_Pos)                 /*!< 0x00000040 */
#define SPI_STS_OVRFLG                     SPI_STS_OVRFLG_Msk                            /*!< Overrun flag */
#define SPI_STS_BSYFLG_Pos                 (7U)
#define SPI_STS_BSYFLG_Msk                 (0x1UL << SPI_STS_BSYFLG_Pos)                 /*!< 0x00000080 */
#define SPI_STS_BSYFLG                     SPI_STS_BSYFLG_Msk                            /*!< Busy flag */
#define SPI_STS_FREFLG_Pos                 (8U)
#define SPI_STS_FREFLG_Msk                 (0x1UL << SPI_STS_FREFLG_Pos)                 /*!< 0x00000100 */
#define SPI_STS_FREFLG                     SPI_STS_FREFLG_Msk                            /*!< Frame format error flag */
#define SPI_STS_CDM_NE_Pos                 (9U)
#define SPI_STS_CDM_NE_Msk                 (0x1UL << SPI_STS_CDM_NE_Pos)                 /*!< 0x00000200 */
#define SPI_STS_CDM_NE                     SPI_STS_CDM_NE_Msk                            /*!< CMD no empty flag */
#define SPI_STS_BSBUSY_Pos                 (10U)
#define SPI_STS_BSBUSY_Msk                 (0x1UL << SPI_STS_BSBUSY_Pos)                 /*!< 0x00000400 */
#define SPI_STS_BSBUSY                     SPI_STS_BSBUSY_Msk                            /*!< Biss busy flag */

/********************  Bit definition for SPI_DATA register  ******************/
#define SPI_DATA_DATA_Pos                  (0U)
#define SPI_DATA_DATA_Msk                  (0xFFFFUL << SPI_DATA_DATA_Pos)               /*!< 0x0000FFFF */
#define SPI_DATA_DATA                      SPI_DATA_DATA_Msk                             /*!< Data Register */

/*******************  Bit definition for SPI_CRCPOLY register  ****************/
#define SPI_CRCPOLY_CRCPOLY_Pos            (0U)
#define SPI_CRCPOLY_CRCPOLY_Msk            (0xFFFFUL << SPI_CRCPOLY_CRCPOLY_Pos)         /*!< 0x0000FFFF */
#define SPI_CRCPOLY_CRCPOLY                SPI_CRCPOLY_CRCPOLY_Msk                       /*!< CRC polynomial register */

/******************  Bit definition for SPI_RXCRC register  *******************/
#define SPI_RXCRC_RXCRC_Pos                (0U)
#define SPI_RXCRC_RXCRC_Msk                (0xFFFFUL << SPI_RXCRC_RXCRC_Pos)             /*!< 0x0000FFFF */
#define SPI_RXCRC_RXCRC                    SPI_RXCRC_RXCRC_Msk                           /*!< Rx CRC Register */

/******************  Bit definition for SPI_TXCRC register  *******************/
#define SPI_TXCRC_TXCRC_Pos                (0U)
#define SPI_TXCRC_TXCRC_Msk                (0xFFFFUL << SPI_TXCRC_TXCRC_Pos)             /*!< 0x0000FFFF */
#define SPI_TXCRC_TXCRC                    SPI_TXCRC_TXCRC_Msk                           /*!< Tx CRC Register */

/*******************  Bit definition for SPI_BCR register  ********************/
#define SPI_BCR_BISS_EN_Pos                (0U)
#define SPI_BCR_BISS_EN_Msk                (0x1UL << SPI_BCR_BISS_EN_Pos)                /*!< 0x00000001 */
#define SPI_BCR_BISS_EN                    SPI_BCR_BISS_EN_Msk                           /*!< Biss-c Enable */
#define SPI_BCR_SSI_EN_Pos                 (1U)
#define SPI_BCR_SSI_EN_Msk                 (0x1UL << SPI_BCR_SSI_EN_Pos)                 /*!< 0x00000002 */
#define SPI_BCR_SSI_EN                     SPI_BCR_SSI_EN_Msk                            /*!< Ssi Enable */
#define SPI_BCR_STOP_EN_Pos                (2U)
#define SPI_BCR_STOP_EN_Msk                (0x1UL << SPI_BCR_STOP_EN_Pos)                /*!< 0x00000004 */
#define SPI_BCR_STOP_EN                    SPI_BCR_STOP_EN_Msk                           /*!< Stop Enable */
#define SPI_BCR_CDM_IE_Pos                 (3U)
#define SPI_BCR_CDM_IE_Msk                 (0x1UL << SPI_BCR_CDM_IE_Pos)                 /*!< 0x00000008 */
#define SPI_BCR_CDM_IE                     SPI_BCR_CDM_IE_Msk                            /*!< Biss-c Cdm Receive Interrupt Enable */
#define SPI_BCR_CDM_DMAEN_Pos              (4U)
#define SPI_BCR_CDM_DMAEN_Msk              (0x1UL << SPI_BCR_CDM_DMAEN_Pos)              /*!< 0x00000010 */
#define SPI_BCR_CDM_DMAEN                  SPI_BCR_CDM_DMAEN_Msk                         /*!< Biss-c Cdm Receive DMA Enable */

/*******************  Bit definition for SPI_BCFG register  *******************/
#define SPI_BCFG_SPISYSCLK_Pos             (0U)
#define SPI_BCFG_SPISYSCLK_Msk             (0xFFUL << SPI_BCFG_SPISYSCLK_Pos)            /*!< 0x000000FF */
#define SPI_BCFG_SPISYSCLK                 SPI_BCFG_SPISYSCLK_Msk                        /*!< SPI system clock frequency */
#define SPI_BCFG_TOPER_Pos                 (8U)
#define SPI_BCFG_TOPER_Msk                 (0x3FUL << SPI_BCFG_TOPER_Pos)                /*!< 0x00003F00 */
#define SPI_BCFG_TOPER                     SPI_BCFG_TOPER_Msk                            /*!< SPI timeout period */

/********************  Bit definition for SPI_CMDDATA register  ***************/
#define SPI_CDMDATA_DATA_Pos               (0U)
#define SPI_CDMDATA_DATA_Msk               (0x1UL << SPI_CDMDATA_DATA_Pos)               /*!< 0x00000001 */
#define SPI_CDMDATA_DATA                   SPI_CDMDATA_DATA_Msk                          /*!< CDMData Register */

/******************************************************************************/
/*                                                                            */
/*                                    TMR                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TMR_CTRL1 register  ******************/
#define TMR_CTRL1_CNTEN_Pos                (0U)
#define TMR_CTRL1_CNTEN_Msk                (0x1UL << TMR_CTRL1_CNTEN_Pos)                /*!< 0x00000001 */
#define TMR_CTRL1_CNTEN                    TMR_CTRL1_CNTEN_Msk                           /*!< Counter enable */
#define TMR_CTRL1_UD_Pos                   (1U)
#define TMR_CTRL1_UD_Msk                   (0x1UL << TMR_CTRL1_UD_Pos)                   /*!< 0x00000000 */
#define TMR_CTRL1_UD                       TMR_CTRL1_UD_Msk                              /*!< Update disable */
#define TMR_CTRL1_URSSEL_Pos               (2U)
#define TMR_CTRL1_URSSEL_Msk               (0x1UL << TMR_CTRL1_URSSEL_Pos)               /*!< 0x00000004 */
#define TMR_CTRL1_URSSEL                   TMR_CTRL1_URSSEL_Msk                          /*!< Update request source */
#define TMR_CTRL1_SPMEN_Pos                (3U)
#define TMR_CTRL1_SPMEN_Msk                (0x1UL << TMR_CTRL1_SPMEN_Pos)                /*!< 0x00000008 */
#define TMR_CTRL1_SPMEN                    TMR_CTRL1_SPMEN_Msk                           /*!< One pulse mode */
#define TMR_CTRL1_CNTDIR_Pos               (4U)
#define TMR_CTRL1_CNTDIR_Msk               (0x1UL << TMR_CTRL1_CNTDIR_Pos)               /*!< 0x00000010 */
#define TMR_CTRL1_CNTDIR                   TMR_CTRL1_CNTDIR_Msk                          /*!< Direction */
#define TMR_CTRL1_CAMSEL_Pos               (5U)
#define TMR_CTRL1_CAMSEL_Msk               (0x3UL << TMR_CTRL1_CAMSEL_Pos)               /*!< 0x00000060 */
#define TMR_CTRL1_CAMSEL                   TMR_CTRL1_CAMSEL_Msk                          /*!< CMS[1:0] bits (Center-aligned mode selection) */
#define TMR_CTRL1_CAMSEL_0                 (0x1UL << TMR_CTRL1_CAMSEL_Pos)               /*!< 0x00000020 */
#define TMR_CTRL1_CAMSEL_1                 (0x2UL << TMR_CTRL1_CAMSEL_Pos)               /*!< 0x00000040 */

#define TMR_CTRL1_ARPEN_Pos                (7U)
#define TMR_CTRL1_ARPEN_Msk                (0x1UL << TMR_CTRL1_ARPEN_Pos)                /*!< 0x00000080 */
#define TMR_CTRL1_ARPEN                    TMR_CTRL1_ARPEN_Msk                           /*!< Auto-reload preload enable */
#define TMR_CTRL1_CLKDIV_Pos               (8U)
#define TMR_CTRL1_CLKDIV_Msk               (0x3UL << TMR_CTRL1_CLKDIV_Pos)               /*!< 0x00000300 */
#define TMR_CTRL1_CLKDIV                   TMR_CTRL1_CLKDIV_Msk                          /*!< CKD[1:0] bits (clock division) */
#define TMR_CTRL1_CLKDIV_0                 (0x1UL << TMR_CTRL1_CLKDIV_Pos)               /*!< 0x00000100 */
#define TMR_CTRL1_CLKDIV_1                 (0x2UL << TMR_CTRL1_CLKDIV_Pos)               /*!< 0x00000200 */

/*******************  Bit definition for TMR_CTRL2 register  ******************/
#define TMR_CTRL2_CCPEN_Pos                (0U)
#define TMR_CTRL2_CCPEN_Msk                (0x1UL << TMR_CTRL2_CCPEN_Pos)                /*!< 0x00000001 */
#define TMR_CTRL2_CCPEN                    TMR_CTRL2_CCPEN_Msk                           /*!< Capture/Compare Preloaded Control */
#define TMR_CTRL2_CCUSEL_Pos               (2U)
#define TMR_CTRL2_CCUSEL_Msk               (0x1UL << TMR_CTRL2_CCUSEL_Pos)               /*!< 0x00000004 */
#define TMR_CTRL2_CCUSEL                   TMR_CTRL2_CCUSEL_Msk                          /*!< Capture/Compare Control Update Selection */
#define TMR_CTRL2_CCDSEL_Pos               (3U)
#define TMR_CTRL2_CCDSEL_Msk               (0x1UL << TMR_CTRL2_CCDSEL_Pos)               /*!< 0x00000008 */
#define TMR_CTRL2_CCDSEL                   TMR_CTRL2_CCDSEL_Msk                          /*!< Capture/Compare DMA Selection */
#define TMR_CTRL2_MMSEL_Pos                (4U)
#define TMR_CTRL2_MMSEL_Msk                (0x7UL << TMR_CTRL2_MMSEL_Pos)                /*!< 0x00000070 */
#define TMR_CTRL2_MMSEL                    TMR_CTRL2_MMSEL_Msk                           /*!< MMS[2:0] bits (Master Mode Selection) */
#define TMR_CTRL2_MMSEL_0                  (0x1UL << TMR_CTRL2_MMSEL_Pos)                /*!< 0x00000010 */
#define TMR_CTRL2_MMSEL_1                  (0x2UL << TMR_CTRL2_MMSEL_Pos)                /*!< 0x00000020 */
#define TMR_CTRL2_MMSEL_2                  (0x4UL << TMR_CTRL2_MMSEL_Pos)                /*!< 0x00000040 */

#define TMR_CTRL2_TI1SEL_Pos               (7U)
#define TMR_CTRL2_TI1SEL_Msk               (0x1UL << TMR_CTRL2_TI1SEL_Pos)               /*!< 0x00000080 */
#define TMR_CTRL2_TI1SEL                   TMR_CTRL2_TI1SEL_Msk                          /*!< TI1 Selection */
#define TMR_CTRL2_OC1OIS_Pos               (8U)
#define TMR_CTRL2_OC1OIS_Msk               (0x1UL << TMR_CTRL2_OC1OIS_Pos)               /*!< 0x00000100 */
#define TMR_CTRL2_OC1OIS                   TMR_CTRL2_OC1OIS_Msk                          /*!< Output Idle state 1 (OC1 output) */
#define TMR_CTRL2_OC1NOIS_Pos              (9U)
#define TMR_CTRL2_OC1NOIS_Msk              (0x1UL << TMR_CTRL2_OC1NOIS_Pos)              /*!< 0x00000200 */
#define TMR_CTRL2_OC1NOIS                  TMR_CTRL2_OC1NOIS_Msk                         /*!< Output Idle state 1 (OC1N output) */
#define TMR_CTRL2_OC2OIS_Pos               (10U)
#define TMR_CTRL2_OC2OIS_Msk               (0x1UL << TMR_CTRL2_OC2OIS_Pos)               /*!< 0x00000400 */
#define TMR_CTRL2_OC2OIS                   TMR_CTRL2_OC2OIS_Msk                          /*!< Output Idle state 2 (OC2 output) */
#define TMR_CTRL2_OC2NOIS_Pos              (11U)
#define TMR_CTRL2_OC2NOIS_Msk              (0x1UL << TMR_CTRL2_OC2NOIS_Pos)              /*!< 0x00000800 */
#define TMR_CTRL2_OC2NOIS                  TMR_CTRL2_OC2NOIS_Msk                         /*!< Output Idle state 2 (OC2N output) */
#define TMR_CTRL2_OC3OIS_Pos               (12U)
#define TMR_CTRL2_OC3OIS_Msk               (0x1UL << TMR_CTRL2_OC3OIS_Pos)               /*!< 0x00001000 */
#define TMR_CTRL2_OC3OIS                   TMR_CTRL2_OC3OIS_Msk                          /*!< Output Idle state 3 (OC3 output) */
#define TMR_CTRL2_OC3NOIS_Pos              (13U)
#define TMR_CTRL2_OC3NOIS_Msk              (0x1UL << TMR_CTRL2_OC3NOIS_Pos)              /*!< 0x00002000 */
#define TMR_CTRL2_OC3NOIS                  TMR_CTRL2_OC3NOIS_Msk                         /*!< Output Idle state 3 (OC3N output) */
#define TMR_CTRL2_OC4OIS_Pos               (14U)
#define TMR_CTRL2_OC4OIS_Msk               (0x1UL << TMR_CTRL2_OC4OIS_Pos)               /*!< 0x00004000 */
#define TMR_CTRL2_OC4OIS                   TMR_CTRL2_OC4OIS_Msk                          /*!< Output Idle state 4 (OC4 output) */

/*******************  Bit definition for TMR_SMCTRL register  *****************/
#define TMR_SMCTRL_SMFSEL_Pos              (0U)
#define TMR_SMCTRL_SMFSEL_Msk              (0x7UL << TMR_SMCTRL_SMFSEL_Pos)              /*!< 0x00000007 */
#define TMR_SMCTRL_SMFSEL                  TMR_SMCTRL_SMFSEL_Msk                         /*!< SMS[2:0] bits (Slave mode selection) */
#define TMR_SMCTRL_SMFSEL_0                (0x1UL << TMR_SMCTRL_SMFSEL_Pos)              /*!< 0x0001 */
#define TMR_SMCTRL_SMFSEL_1                (0x2UL << TMR_SMCTRL_SMFSEL_Pos)              /*!< 0x0002 */
#define TMR_SMCTRL_SMFSEL_2                (0x4UL << TMR_SMCTRL_SMFSEL_Pos)              /*!< 0x0004 */

#define TMR_SMCTRL_TRGSEL_Pos              (4U)
#define TMR_SMCTRL_TRGSEL_Msk              (0x7UL << TMR_SMCTRL_TRGSEL_Pos)              /*!< 0x00000070 */
#define TMR_SMCTRL_TRGSEL                  TMR_SMCTRL_TRGSEL_Msk                         /*!< TS[2:0] bits (Trigger selection) */
#define TMR_SMCTRL_TRGSEL_0                (0x1UL << TMR_SMCTRL_TRGSEL_Pos)              /*!< 0x0010 */
#define TMR_SMCTRL_TRGSEL_1                (0x2UL << TMR_SMCTRL_TRGSEL_Pos)              /*!< 0x0020 */
#define TMR_SMCTRL_TRGSEL_2                (0x4UL << TMR_SMCTRL_TRGSEL_Pos)              /*!< 0x0040 */

#define TMR_SMCTRL_MSMEN_Pos               (7U)
#define TMR_SMCTRL_MSMEN_Msk               (0x1UL << TMR_SMCTRL_MSMEN_Pos)               /*!< 0x00000080 */
#define TMR_SMCTRL_MSMEN                   TMR_SMCTRL_MSMEN_Msk                          /*!< Master/slave mode */
#define TMR_SMCTRL_ETFCFG_Pos              (8U)
#define TMR_SMCTRL_ETFCFG_Msk              (0xFUL << TMR_SMCTRL_ETFCFG_Pos)              /*!< 0x00000F00 */
#define TMR_SMCTRL_ETFCFG                  TMR_SMCTRL_ETFCFG_Msk                         /*!< ETF[3:0] bits (External trigger filter) */
#define TMR_SMCTRL_ETFCFG_0                (0x1UL << TMR_SMCTRL_ETFCFG_Pos)              /*!< 0x0100 */
#define TMR_SMCTRL_ETFCFG_1                (0x2UL << TMR_SMCTRL_ETFCFG_Pos)              /*!< 0x0200 */
#define TMR_SMCTRL_ETFCFG_2                (0x4UL << TMR_SMCTRL_ETFCFG_Pos)              /*!< 0x0400 */
#define TMR_SMCTRL_ETFCFG_3                (0x8UL << TMR_SMCTRL_ETFCFG_Pos)              /*!< 0x0800 */

#define TMR_SMCTRL_ETPCFG_Pos              (12U)
#define TMR_SMCTRL_ETPCFG_Msk              (0x3UL << TMR_SMCTRL_ETPCFG_Pos)              /*!< 0x00003000 */
#define TMR_SMCTRL_ETPCFG                  TMR_SMCTRL_ETPCFG_Msk                         /*!< ETPS[1:0] bits (External trigger prescaler) */
#define TMR_SMCTRL_ETPCFG_0                (0x1UL << TMR_SMCTRL_ETPCFG_Pos)              /*!< 0x1000 */
#define TMR_SMCTRL_ETPCFG_1                (0x2UL << TMR_SMCTRL_ETPCFG_Pos)              /*!< 0x2000 */

#define TMR_SMCTRL_ECEN_Pos                (14U)
#define TMR_SMCTRL_ECEN_Msk                (0x1UL << TMR_SMCTRL_ECEN_Pos)                /*!< 0x00004000 */
#define TMR_SMCTRL_ECEN                    TMR_SMCTRL_ECEN_Msk                           /*!< External clock enable */
#define TMR_SMCTRL_ETPOL_Pos               (15U)
#define TMR_SMCTRL_ETPOL_Msk               (0x1UL << TMR_SMCTRL_ETPOL_Pos)               /*!< 0x00008000 */
#define TMR_SMCTRL_ETPOL                   TMR_SMCTRL_ETPOL_Msk                          /*!< External trigger polarity */

/*******************  Bit definition for TMR_DIEN register  *******************/
#define TMR_DIEN_UIEN_Pos                  (0U)
#define TMR_DIEN_UIEN_Msk                  (0x1UL << TMR_DIEN_UIEN_Pos)                  /*!< 0x00000001 */
#define TMR_DIEN_UIEN                      TMR_DIEN_UIEN_Msk                             /*!< Update interrupt enable */
#define TMR_DIEN_CC1IEN_Pos                (1U)
#define TMR_DIEN_CC1IEN_Msk                (0x1UL << TMR_DIEN_CC1IEN_Pos)                /*!< 0x00000000 */
#define TMR_DIEN_CC1IEN                    TMR_DIEN_CC1IEN_Msk                           /*!< Capture/Compare 1 interrupt enable */
#define TMR_DIEN_CC2IEN_Pos                (2U)
#define TMR_DIEN_CC2IEN_Msk                (0x1UL << TMR_DIEN_CC2IEN_Pos)                /*!< 0x00000004 */
#define TMR_DIEN_CC2IEN                    TMR_DIEN_CC2IEN_Msk                           /*!< Capture/Compare 2 interrupt enable */
#define TMR_DIEN_CC3IEN_Pos                (3U)
#define TMR_DIEN_CC3IEN_Msk                (0x1UL << TMR_DIEN_CC3IEN_Pos)                /*!< 0x00000008 */
#define TMR_DIEN_CC3IEN                    TMR_DIEN_CC3IEN_Msk                           /*!< Capture/Compare 3 interrupt enable */
#define TMR_DIEN_CC4IEN_Pos                (4U)
#define TMR_DIEN_CC4IEN_Msk                (0x1UL << TMR_DIEN_CC4IEN_Pos)                /*!< 0x00000010 */
#define TMR_DIEN_CC4IEN                    TMR_DIEN_CC4IEN_Msk                           /*!< Capture/Compare 4 interrupt enable */
#define TMR_DIEN_COMIEN_Pos                (5U)
#define TMR_DIEN_COMIEN_Msk                (0x1UL << TMR_DIEN_COMIEN_Pos)                /*!< 0x00000020 */
#define TMR_DIEN_COMIEN                    TMR_DIEN_COMIEN_Msk                           /*!< COM interrupt enable */
#define TMR_DIEN_TRGIEN_Pos                (6U)
#define TMR_DIEN_TRGIEN_Msk                (0x1UL << TMR_DIEN_TRGIEN_Pos)                /*!< 0x00000040 */
#define TMR_DIEN_TRGIEN                    TMR_DIEN_TRGIEN_Msk                           /*!< Trigger interrupt enable */
#define TMR_DIEN_BRKIEN_Pos                (7U)
#define TMR_DIEN_BRKIEN_Msk                (0x1UL << TMR_DIEN_BRKIEN_Pos)                /*!< 0x00000080 */
#define TMR_DIEN_BRKIEN                    TMR_DIEN_BRKIEN_Msk                           /*!< Break interrupt enable */
#define TMR_DIEN_UDIEN_Pos                 (8U)
#define TMR_DIEN_UDIEN_Msk                 (0x1UL << TMR_DIEN_UDIEN_Pos)                 /*!< 0x00000100 */
#define TMR_DIEN_UDIEN                     TMR_DIEN_UDIEN_Msk                            /*!< Update DMA request enable */
#define TMR_DIEN_CC1DEN_Pos                (9U)
#define TMR_DIEN_CC1DEN_Msk                (0x1UL << TMR_DIEN_CC1DEN_Pos)                /*!< 0x00000200 */
#define TMR_DIEN_CC1DEN                    TMR_DIEN_CC1DEN_Msk                           /*!< Capture/Compare 1 DMA request enable */
#define TMR_DIEN_CC2DEN_Pos                (10U)
#define TMR_DIEN_CC2DEN_Msk                (0x1UL << TMR_DIEN_CC2DEN_Pos)                /*!< 0x00000400 */
#define TMR_DIEN_CC2DEN                    TMR_DIEN_CC2DEN_Msk                           /*!< Capture/Compare 2 DMA request enable */
#define TMR_DIEN_CC3DEN_Pos                (11U)
#define TMR_DIEN_CC3DEN_Msk                (0x1UL << TMR_DIEN_CC3DEN_Pos)                /*!< 0x00000800 */
#define TMR_DIEN_CC3DEN                    TMR_DIEN_CC3DEN_Msk                           /*!< Capture/Compare 3 DMA request enable */
#define TMR_DIEN_CC4DEN_Pos                (12U)
#define TMR_DIEN_CC4DEN_Msk                (0x1UL << TMR_DIEN_CC4DEN_Pos)                /*!< 0x00001000 */
#define TMR_DIEN_CC4DEN                    TMR_DIEN_CC4DEN_Msk                           /*!< Capture/Compare 4 DMA request enable */
#define TMR_DIEN_COMDEN_Pos                (13U)
#define TMR_DIEN_COMDEN_Msk                (0x1UL << TMR_DIEN_COMDEN_Pos)                /*!< 0x00002000 */
#define TMR_DIEN_COMDEN                    TMR_DIEN_COMDEN_Msk                           /*!< COM DMA request enable */
#define TMR_DIEN_TRGDEN_Pos                (14U)
#define TMR_DIEN_TRGDEN_Msk                (0x1UL << TMR_DIEN_TRGDEN_Pos)                /*!< 0x00004000 */
#define TMR_DIEN_TRGDEN                    TMR_DIEN_TRGDEN_Msk                           /*!< Trigger DMA request enable */

/********************  Bit definition for TMR_STS register  *******************/
#define TMR_STS_UIFLG_Pos                  (0U)
#define TMR_STS_UIFLG_Msk                  (0x1UL << TMR_STS_UIFLG_Pos)                  /*!< 0x00000001 */
#define TMR_STS_UIFLG                      TMR_STS_UIFLG_Msk                             /*!< Update interrupt Flag */
#define TMR_STS_CC1IFLG_Pos                (1U)
#define TMR_STS_CC1IFLG_Msk                (0x1UL << TMR_STS_CC1IFLG_Pos)                /*!< 0x00000000 */
#define TMR_STS_CC1IFLG                    TMR_STS_CC1IFLG_Msk                           /*!< Capture/Compare 1 interrupt Flag */
#define TMR_STS_CC2IFLG_Pos                (2U)
#define TMR_STS_CC2IFLG_Msk                (0x1UL << TMR_STS_CC2IFLG_Pos)                /*!< 0x00000004 */
#define TMR_STS_CC2IFLG                    TMR_STS_CC2IFLG_Msk                           /*!< Capture/Compare 2 interrupt Flag */
#define TMR_STS_CC3IFLG_Pos                (3U)
#define TMR_STS_CC3IFLG_Msk                (0x1UL << TMR_STS_CC3IFLG_Pos)                /*!< 0x00000008 */
#define TMR_STS_CC3IFLG                    TMR_STS_CC3IFLG_Msk                           /*!< Capture/Compare 3 interrupt Flag */
#define TMR_STS_CC4IFLG_Pos                (4U)
#define TMR_STS_CC4IFLG_Msk                (0x1UL << TMR_STS_CC4IFLG_Pos)                /*!< 0x00000010 */
#define TMR_STS_CC4IFLG                    TMR_STS_CC4IFLG_Msk                           /*!< Capture/Compare 4 interrupt Flag */
#define TMR_STS_COMIFLG_Pos                (5U)
#define TMR_STS_COMIFLG_Msk                (0x1UL << TMR_STS_COMIFLG_Pos)                /*!< 0x00000020 */
#define TMR_STS_COMIFLG                    TMR_STS_COMIFLG_Msk                           /*!< COM interrupt Flag */
#define TMR_STS_TRGIFLG_Pos                (6U)
#define TMR_STS_TRGIFLG_Msk                (0x1UL << TMR_STS_TRGIFLG_Pos)                /*!< 0x00000040 */
#define TMR_STS_TRGIFLG                    TMR_STS_TRGIFLG_Msk                           /*!< Trigger interrupt Flag */
#define TMR_STS_BRKIFLG_Pos                (7U)
#define TMR_STS_BRKIFLG_Msk                (0x1UL << TMR_STS_BRKIFLG_Pos)                /*!< 0x00000080 */
#define TMR_STS_BRKIFLG                    TMR_STS_BRKIFLG_Msk                           /*!< Break interrupt Flag */
#define TMR_STS_CC1RCFLG_Pos               (9U)
#define TMR_STS_CC1RCFLG_Msk               (0x1UL << TMR_STS_CC1RCFLG_Pos)               /*!< 0x00000200 */
#define TMR_STS_CC1RCFLG                   TMR_STS_CC1RCFLG_Msk                          /*!< Capture/Compare 1 Overcapture Flag */
#define TMR_STS_CC2RCFLG_Pos               (10U)
#define TMR_STS_CC2RCFLG_Msk               (0x1UL << TMR_STS_CC2RCFLG_Pos)               /*!< 0x00000400 */
#define TMR_STS_CC2RCFLG                   TMR_STS_CC2RCFLG_Msk                          /*!< Capture/Compare 2 Overcapture Flag */
#define TMR_STS_CC3RCFLG_Pos               (11U)
#define TMR_STS_CC3RCFLG_Msk               (0x1UL << TMR_STS_CC3RCFLG_Pos)               /*!< 0x00000800 */
#define TMR_STS_CC3RCFLG                   TMR_STS_CC3RCFLG_Msk                          /*!< Capture/Compare 3 Overcapture Flag */
#define TMR_STS_CC4RCFLG_Pos               (12U)
#define TMR_STS_CC4RCFLG_Msk               (0x1UL << TMR_STS_CC4RCFLG_Pos)               /*!< 0x00001000 */
#define TMR_STS_CC4RCFLG                   TMR_STS_CC4RCFLG_Msk                          /*!< Capture/Compare 4 Overcapture Flag */

/*******************  Bit definition for TMR_CEG register  ********************/
#define TMR_CEG_UEG_Pos                    (0U)
#define TMR_CEG_UEG_Msk                    (0x1UL << TMR_CEG_UEG_Pos)                    /*!< 0x00000001 */
#define TMR_CEG_UEG                        TMR_CEG_UEG_Msk                               /*!< Update Generation */
#define TMR_CEG_CC1EG_Pos                  (1U)
#define TMR_CEG_CC1EG_Msk                  (0x1UL << TMR_CEG_CC1EG_Pos)                  /*!< 0x00000000 */
#define TMR_CEG_CC1EG                      TMR_CEG_CC1EG_Msk                             /*!< Capture/Compare 1 Generation */
#define TMR_CEG_CC2EG_Pos                  (2U)
#define TMR_CEG_CC2EG_Msk                  (0x1UL << TMR_CEG_CC2EG_Pos)                  /*!< 0x00000004 */
#define TMR_CEG_CC2EG                      TMR_CEG_CC2EG_Msk                             /*!< Capture/Compare 2 Generation */
#define TMR_CEG_CC3EG_Pos                  (3U)
#define TMR_CEG_CC3EG_Msk                  (0x1UL << TMR_CEG_CC3EG_Pos)                  /*!< 0x00000008 */
#define TMR_CEG_CC3EG                      TMR_CEG_CC3EG_Msk                             /*!< Capture/Compare 3 Generation */
#define TMR_CEG_CC4EG_Pos                  (4U)
#define TMR_CEG_CC4EG_Msk                  (0x1UL << TMR_CEG_CC4EG_Pos)                  /*!< 0x00000010 */
#define TMR_CEG_CC4EG                      TMR_CEG_CC4EG_Msk                             /*!< Capture/Compare 4 Generation */
#define TMR_CEG_COMG_Pos                   (5U)
#define TMR_CEG_COMG_Msk                   (0x1UL << TMR_CEG_COMG_Pos)                   /*!< 0x00000020 */
#define TMR_CEG_COMG                       TMR_CEG_COMG_Msk                              /*!< Capture/Compare Control Update Generation */
#define TMR_CEG_TEG_Pos                    (6U)
#define TMR_CEG_TEG_Msk                    (0x1UL << TMR_CEG_TEG_Pos)                    /*!< 0x00000040 */
#define TMR_CEG_TEG                        TMR_CEG_TEG_Msk                               /*!< Trigger Generation */
#define TMR_CEG_BEG_Pos                    (7U)
#define TMR_CEG_BEG_Msk                    (0x1UL << TMR_CEG_BEG_Pos)                    /*!< 0x00000080 */
#define TMR_CEG_BEG                        TMR_CEG_BEG_Msk                               /*!< Break Generation */

/******************  Bit definition for TMR_CCM1 register  ********************/
#define TMR_CCM1_CC1SEL_Pos                (0U)
#define TMR_CCM1_CC1SEL_Msk                (0x3UL << TMR_CCM1_CC1SEL_Pos)                /*!< 0x00000003 */
#define TMR_CCM1_CC1SEL                    TMR_CCM1_CC1SEL_Msk                           /*!< CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TMR_CCM1_CC1SEL_0                  (0x1UL << TMR_CCM1_CC1SEL_Pos)                /*!< 0x00000001 */
#define TMR_CCM1_CC1SEL_1                  (0x2UL << TMR_CCM1_CC1SEL_Pos)                /*!< 0x00000002 */

#define TMR_CCM1_OC1FEN_Pos                (2U)
#define TMR_CCM1_OC1FEN_Msk                (0x1UL << TMR_CCM1_OC1FEN_Pos)                /*!< 0x00000004 */
#define TMR_CCM1_OC1FEN                    TMR_CCM1_OC1FEN_Msk                           /*!< Output Compare 1 Fast enable */
#define TMR_CCM1_OC1PEN_Pos                (3U)
#define TMR_CCM1_OC1PEN_Msk                (0x1UL << TMR_CCM1_OC1PEN_Pos)                /*!< 0x00000008 */
#define TMR_CCM1_OC1PEN                    TMR_CCM1_OC1PEN_Msk                           /*!< Output Compare 1 Preload enable */

#define TMR_CCM1_OC1MOD_Pos                (4U)
#define TMR_CCM1_OC1MOD_Msk                (0x7UL << TMR_CCM1_OC1MOD_Pos)                /*!< 0x00000070 */
#define TMR_CCM1_OC1MOD                    TMR_CCM1_OC1MOD_Msk                           /*!< OC1M[2:0] bits (Output Compare 1 Mode) */
#define TMR_CCM1_OC1MOD_0                  (0x1UL << TMR_CCM1_OC1MOD_Pos)                /*!< 0x00000010 */
#define TMR_CCM1_OC1MOD_1                  (0x2UL << TMR_CCM1_OC1MOD_Pos)                /*!< 0x00000020 */
#define TMR_CCM1_OC1MOD_2                  (0x4UL << TMR_CCM1_OC1MOD_Pos)                /*!< 0x00000040 */

#define TMR_CCM1_OC1CEN_Pos                (7U)
#define TMR_CCM1_OC1CEN_Msk                (0x1UL << TMR_CCM1_OC1CEN_Pos)                /*!< 0x00000080 */
#define TMR_CCM1_OC1CEN                    TMR_CCM1_OC1CEN_Msk                           /*!< Output Compare 1Clear Enable */
#define TMR_CCM1_CC2SEL_Pos                (8U)
#define TMR_CCM1_CC2SEL_Msk                (0x3UL << TMR_CCM1_CC2SEL_Pos)                /*!< 0x00000300 */
#define TMR_CCM1_CC2SEL                    TMR_CCM1_CC2SEL_Msk                           /*!< CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TMR_CCM1_CC2SEL_0                  (0x1UL << TMR_CCM1_CC2SEL_Pos)                /*!< 0x00000100 */
#define TMR_CCM1_CC2SEL_1                  (0x2UL << TMR_CCM1_CC2SEL_Pos)                /*!< 0x00000200 */

#define TMR_CCM1_OC2FEN_Pos                (10U)
#define TMR_CCM1_OC2FEN_Msk                (0x1UL << TMR_CCM1_OC2FEN_Pos)                /*!< 0x00000400 */
#define TMR_CCM1_OC2FEN                    TMR_CCM1_OC2FEN_Msk                           /*!< Output Compare 2 Fast enable */
#define TMR_CCM1_OC2PEN_Pos                (11U)
#define TMR_CCM1_OC2PEN_Msk                (0x1UL << TMR_CCM1_OC2PEN_Pos)                /*!< 0x00000800 */
#define TMR_CCM1_OC2PEN                    TMR_CCM1_OC2PEN_Msk                           /*!< Output Compare 2 Preload enable */
#define TMR_CCM1_OC2MOD_Pos                (12U)
#define TMR_CCM1_OC2MOD_Msk                (0x7UL << TMR_CCM1_OC2MOD_Pos)                /*!< 0x00007000 */
#define TMR_CCM1_OC2MOD                    TMR_CCM1_OC2MOD_Msk                           /*!< OC2M[2:0] bits (Output Compare 2 Mode) */
#define TMR_CCM1_OC2MOD_0                  (0x1UL << TMR_CCM1_OC2MOD_Pos)                /*!< 0x00001000 */
#define TMR_CCM1_OC2MOD_1                  (0x2UL << TMR_CCM1_OC2MOD_Pos)                /*!< 0x00002000 */
#define TMR_CCM1_OC2MOD_2                  (0x4UL << TMR_CCM1_OC2MOD_Pos)                /*!< 0x00004000 */

#define TMR_CCM1_OC2CEN_Pos                (15U)
#define TMR_CCM1_OC2CEN_Msk                (0x1UL << TMR_CCM1_OC2CEN_Pos)                /*!< 0x00008000 */
#define TMR_CCM1_OC2CEN                    TMR_CCM1_OC2CEN_Msk                           /*!< Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define TMR_CCM1_IC1PSC_Pos                (2U)
#define TMR_CCM1_IC1PSC_Msk                (0x3UL << TMR_CCM1_IC1PSC_Pos)                /*!< 0x0000000C */
#define TMR_CCM1_IC1PSC                    TMR_CCM1_IC1PSC_Msk                           /*!< IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TMR_CCM1_IC1PSC_0                  (0x1UL << TMR_CCM1_IC1PSC_Pos)                /*!< 0x00000004 */
#define TMR_CCM1_IC1PSC_1                  (0x2UL << TMR_CCM1_IC1PSC_Pos)                /*!< 0x00000008 */

#define TMR_CCM1_IC1F_Pos                  (4U)
#define TMR_CCM1_IC1F_Msk                  (0xFUL << TMR_CCM1_IC1F_Pos)                  /*!< 0x000000F0 */
#define TMR_CCM1_IC1F                      TMR_CCM1_IC1F_Msk                             /*!< IC1F[3:0] bits (Input Capture 1 Filter) */
#define TMR_CCM1_IC1F_0                    (0x1UL << TMR_CCM1_IC1F_Pos)                  /*!< 0x00000010 */
#define TMR_CCM1_IC1F_1                    (0x2UL << TMR_CCM1_IC1F_Pos)                  /*!< 0x00000020 */
#define TMR_CCM1_IC1F_2                    (0x4UL << TMR_CCM1_IC1F_Pos)                  /*!< 0x00000040 */
#define TMR_CCM1_IC1F_3                    (0x8UL << TMR_CCM1_IC1F_Pos)                  /*!< 0x00000080 */

#define TMR_CCM1_IC2PSC_Pos                (10U)
#define TMR_CCM1_IC2PSC_Msk                (0x3UL << TMR_CCM1_IC2PSC_Pos)                /*!< 0x00000C00 */
#define TMR_CCM1_IC2PSC                    TMR_CCM1_IC2PSC_Msk                           /*!< IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define TMR_CCM1_IC2PSC_0                  (0x1UL << TMR_CCM1_IC2PSC_Pos)                /*!< 0x00000400 */
#define TMR_CCM1_IC2PSC_1                  (0x2UL << TMR_CCM1_IC2PSC_Pos)                /*!< 0x00000800 */

#define TMR_CCM1_IC2F_Pos                  (12U)
#define TMR_CCM1_IC2F_Msk                  (0xFUL << TMR_CCM1_IC2F_Pos)                  /*!< 0x0000F000 */
#define TMR_CCM1_IC2F                      TMR_CCM1_IC2F_Msk                             /*!< IC2F[3:0] bits (Input Capture 2 Filter) */
#define TMR_CCM1_IC2F_0                    (0x1UL << TMR_CCM1_IC2F_Pos)                  /*!< 0x00001000 */
#define TMR_CCM1_IC2F_1                    (0x2UL << TMR_CCM1_IC2F_Pos)                  /*!< 0x00002000 */
#define TMR_CCM1_IC2F_2                    (0x4UL << TMR_CCM1_IC2F_Pos)                  /*!< 0x00004000 */
#define TMR_CCM1_IC2F_3                    (0x8UL << TMR_CCM1_IC2F_Pos)                  /*!< 0x00008000 */

/******************  Bit definition for TMR_CCM2 register  ********************/
#define TMR_CCM2_CC3SEL_Pos                (0U)
#define TMR_CCM2_CC3SEL_Msk                (0x3UL << TMR_CCM2_CC3SEL_Pos)                /*!< 0x00000003 */
#define TMR_CCM2_CC3SEL                    TMR_CCM2_CC3SEL_Msk                           /*!< CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TMR_CCM2_OC3FEN_Pos                (2U)
#define TMR_CCM2_OC3FEN_Msk                (0x1UL << TMR_CCM2_OC3FEN_Pos)                /*!< 0x00000004 */
#define TMR_CCM2_OC3FEN                    TMR_CCM2_OC3FEN_Msk                           /*!< Output Compare 3 Fast enable */
#define TMR_CCM2_OC3PEN_Pos                (3U)
#define TMR_CCM2_OC3PEN_Msk                (0x1UL << TMR_CCM2_OC3PEN_Pos)                /*!< 0x00000008 */
#define TMR_CCM2_OC3PEN                    TMR_CCM2_OC3PEN_Msk                           /*!< Output Compare 3 Preload enable */
#define TMR_CCM2_OC3MOD_Pos                (4U)
#define TMR_CCM2_OC3MOD_Msk                (0x7UL << TMR_CCM2_OC3MOD_Pos)                /*!< 0x00000070 */
#define TMR_CCM2_OC3MOD                    TMR_CCM2_OC3MOD_Msk                           /*!< OC3M[2:0] bits (Output Compare 3 Mode) */
#define TMR_CCM2_OC3CEN_Pos                (7U)
#define TMR_CCM2_OC3CEN_Msk                (0x1UL << TMR_CCM2_OC3CEN_Pos)                /*!< 0x00000080 */
#define TMR_CCM2_OC3CEN                    TMR_CCM2_OC3CEN_Msk                           /*!< Output Compare 3 Clear Enable */
#define TMR_CCM2_CC4SEL_Pos                (8U)
#define TMR_CCM2_CC4SEL_Msk                (0x3UL << TMR_CCM2_CC4SEL_Pos)                /*!< 0x00000300 */
#define TMR_CCM2_CC4SEL                    TMR_CCM2_CC4SEL_Msk                           /*!< CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TMR_CCM2_OC4FEN_Pos                (10U)
#define TMR_CCM2_OC4FEN_Msk                (0x1UL << TMR_CCM2_OC4FEN_Pos)                /*!< 0x00000400 */
#define TMR_CCM2_OC4FEN                    TMR_CCM2_OC4FEN_Msk                           /*!< Output Compare 4 Fast enable */
#define TMR_CCM2_OC4PEN_Pos                (11U)
#define TMR_CCM2_OC4PEN_Msk                (0x1UL << TMR_CCM2_OC4PEN_Pos)                /*!< 0x00000800 */
#define TMR_CCM2_OC4PEN                    TMR_CCM2_OC4PEN_Msk                           /*!< Output Compare 4 Preload enable */
#define TMR_CCM2_OC4MOD_Pos                (12U)
#define TMR_CCM2_OC4MOD_Msk                (0x7UL << TMR_CCM2_OC4MOD_Pos)                /*!< 0x00007000 */
#define TMR_CCM2_OC4MOD                    TMR_CCM2_OC4MOD_Msk                           /*!< OC4M[2:0] bits (Output Compare 4 Mode) */
#define TMR_CCM2_OC4CEN_Pos                (15U)
#define TMR_CCM2_OC4CEN_Msk                (0x1UL << TMR_CCM2_OC4CEN_Pos)                /*!< 0x00008000 */
#define TMR_CCM2_OC4CEN                    TMR_CCM2_OC4CEN_Msk                           /*!< Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define TMR_CCM2_IC3PSC_Pos                (2U)
#define TMR_CCM2_IC3PSC_Msk                (0x3UL << TMR_CCM2_IC3PSC_Pos)                /*!< 0x0000000C */
#define TMR_CCM2_IC3PSC                    TMR_CCM2_IC3PSC_Msk                           /*!< IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TMR_CCM2_IC3F_Pos                  (4U)
#define TMR_CCM2_IC3F_Msk                  (0xFUL << TMR_CCM2_IC3F_Pos)                  /*!< 0x000000F0 */
#define TMR_CCM2_IC3F                      TMR_CCM2_IC3F_Msk                             /*!< IC3F[3:0] bits (Input Capture 3 Filter) */
#define TMR_CCM2_IC4PSC_Pos                (10U)
#define TMR_CCM2_IC4PSC_Msk                (0x3UL << TMR_CCM2_IC4PSC_Pos)                /*!< 0x00000C00 */
#define TMR_CCM2_IC4PSC                    TMR_CCM2_IC4PSC_Msk                           /*!< IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TMR_CCM2_IC4F_Pos                  (12U)
#define TMR_CCM2_IC4F_Msk                  (0xFUL << TMR_CCM2_IC4F_Pos)                  /*!< 0x0000F000 */
#define TMR_CCM2_IC4F                      TMR_CCM2_IC4F_Msk                             /*!< IC4F[3:0] bits (Input Capture 4 Filter) */

/*******************  Bit definition for TMR_CCEN register  *******************/
#define TMR_CCEN_CC1EN_Pos                 (0U)
#define TMR_CCEN_CC1EN_Msk                 (0x1UL << TMR_CCEN_CC1EN_Pos)                 /*!< 0x00000001 */
#define TMR_CCEN_CC1EN                     TMR_CCEN_CC1EN_Msk                            /*!< Capture/Compare 1 output enable */
#define TMR_CCEN_CC1POL_Pos                (1U)
#define TMR_CCEN_CC1POL_Msk                (0x1UL << TMR_CCEN_CC1POL_Pos)                /*!< 0x00000000 */
#define TMR_CCEN_CC1POL                    TMR_CCEN_CC1POL_Msk                           /*!< Capture/Compare 1 output Polarity */
#define TMR_CCEN_CC1NEN_Pos                (2U)
#define TMR_CCEN_CC1NEN_Msk                (0x1UL << TMR_CCEN_CC1NEN_Pos)                /*!< 0x00000004 */
#define TMR_CCEN_CC1NEN                    TMR_CCEN_CC1NEN_Msk                           /*!< Capture/Compare 1 Complementary output enable */
#define TMR_CCEN_CC1NPOL_Pos               (3U)
#define TMR_CCEN_CC1NPOL_Msk               (0x1UL << TMR_CCEN_CC1NPOL_Pos)               /*!< 0x00000008 */
#define TMR_CCEN_CC1NPOL                   TMR_CCEN_CC1NPOL_Msk                          /*!< Capture/Compare 1 Complementary output Polarity */
#define TMR_CCEN_CC2EN_Pos                 (4U)
#define TMR_CCEN_CC2EN_Msk                 (0x1UL << TMR_CCEN_CC2EN_Pos)                 /*!< 0x00000010 */
#define TMR_CCEN_CC2EN                     TMR_CCEN_CC2EN_Msk                            /*!< Capture/Compare 2 output enable */
#define TMR_CCEN_CC2POL_Pos                (5U)
#define TMR_CCEN_CC2POL_Msk                (0x1UL << TMR_CCEN_CC2POL_Pos)                /*!< 0x00000020 */
#define TMR_CCEN_CC2POL                    TMR_CCEN_CC2POL_Msk                           /*!< Capture/Compare 2 output Polarity */
#define TMR_CCEN_CC2NEN_Pos                (6U)
#define TMR_CCEN_CC2NEN_Msk                (0x1UL << TMR_CCEN_CC2NEN_Pos)                /*!< 0x00000040 */
#define TMR_CCEN_CC2NEN                    TMR_CCEN_CC2NEN_Msk                           /*!< Capture/Compare 2 Complementary output enable */
#define TMR_CCEN_CC2NPOL_Pos               (7U)
#define TMR_CCEN_CC2NPOL_Msk               (0x1UL << TMR_CCEN_CC2NPOL_Pos)               /*!< 0x00000080 */
#define TMR_CCEN_CC2NPOL                   TMR_CCEN_CC2NPOL_Msk                          /*!< Capture/Compare 2 Complementary output Polarity */
#define TMR_CCEN_CC3EN_Pos                 (8U)
#define TMR_CCEN_CC3EN_Msk                 (0x1UL << TMR_CCEN_CC3EN_Pos)                 /*!< 0x00000100 */
#define TMR_CCEN_CC3EN                     TMR_CCEN_CC3EN_Msk                            /*!< Capture/Compare 3 output enable */
#define TMR_CCEN_CC3POL_Pos                (9U)
#define TMR_CCEN_CC3POL_Msk                (0x1UL << TMR_CCEN_CC3POL_Pos)                /*!< 0x00000200 */
#define TMR_CCEN_CC3POL                    TMR_CCEN_CC3POL_Msk                           /*!< Capture/Compare 3 output Polarity */
#define TMR_CCEN_CC3NEN_Pos                (10U)
#define TMR_CCEN_CC3NEN_Msk                (0x1UL << TMR_CCEN_CC3NEN_Pos)                /*!< 0x00000400 */
#define TMR_CCEN_CC3NEN                    TMR_CCEN_CC3NEN_Msk                           /*!< Capture/Compare 3 Complementary output enable */
#define TMR_CCEN_CC3NPOL_Pos               (11U)
#define TMR_CCEN_CC3NPOL_Msk               (0x1UL << TMR_CCEN_CC3NPOL_Pos)               /*!< 0x00000800 */
#define TMR_CCEN_CC3NPOL                   TMR_CCEN_CC3NPOL_Msk                          /*!< Capture/Compare 3 Complementary output Polarity */
#define TMR_CCEN_CC4EN_Pos                 (12U)
#define TMR_CCEN_CC4EN_Msk                 (0x1UL << TMR_CCEN_CC4EN_Pos)                 /*!< 0x00001000 */
#define TMR_CCEN_CC4EN                     TMR_CCEN_CC4EN_Msk                            /*!< Capture/Compare 4 output enable */
#define TMR_CCEN_CC4POL_Pos                (13U)
#define TMR_CCEN_CC4POL_Msk                (0x1UL << TMR_CCEN_CC4POL_Pos)                /*!< 0x00002000 */
#define TMR_CCEN_CC4POL                    TMR_CCEN_CC4POL_Msk                           /*!< Capture/Compare 4 output Polarity */

/*******************  Bit definition for TMR_CNT register  ********************/
#define TMR_CNT_CNT_Pos                    (0U)
#define TMR_CNT_CNT_Msk                    (0xFFFFUL << TMR_CNT_CNT_Pos)                 /*!< 0x0000FFFF */
#define TMR_CNT_CNT                        TMR_CNT_CNT_Msk                               /*!< Counter Value */

/*******************  Bit definition for TMR_PSC register  ********************/
#define TMR_PSC_PSC_Pos                    (0U)
#define TMR_PSC_PSC_Msk                    (0xFFFFUL << TMR_PSC_PSC_Pos)                 /*!< 0x0000FFFF */
#define TMR_PSC_PSC                        TMR_PSC_PSC_Msk                               /*!< Prescaler Value */

/*******************  Bit definition for TMR_AUTORLD register  ****************/
#define TMR_AUTORLD_AUTORLD_Pos            (0U)
#define TMR_AUTORLD_AUTORLD_Msk            (0xFFFFUL << TMR_AUTORLD_AUTORLD_Pos)         /*!< 0x0000FFFF */
#define TMR_AUTORLD_AUTORLD                TMR_AUTORLD_AUTORLD_Msk                       /*!< actual auto-reload Value */

/*******************  Bit definition for TMR_REPCNT register  *****************/
#define TMR_REPCNT_REPCNT_Pos              (0U)
#define TMR_REPCNT_REPCNT_Msk              (0xFFUL << TMR_REPCNT_REPCNT_Pos)             /*!< 0x000000FF */
#define TMR_REPCNT_REPCNT                  TMR_REPCNT_REPCNT_Msk                         /*!< Repetition Counter Value */

/*******************  Bit definition for TMR_CC1 register  ********************/
#define TMR_CC1_CC1_Pos                    (0U)
#define TMR_CC1_CC1_Msk                    (0xFFFFUL << TMR_CC1_CC1_Pos)                 /*!< 0x0000FFFF */
#define TMR_CC1_CC1                        TMR_CC1_CC1_Msk                               /*!< Capture/Compare 1 Value */

/*******************  Bit definition for TMR_CC2 register  ********************/
#define TMR_CC2_CC2_Pos                    (0U)
#define TMR_CC2_CC2_Msk                    (0xFFFFUL << TMR_CC2_CC2_Pos)                 /*!< 0x0000FFFF */
#define TMR_CC2_CC2                        TMR_CC2_CC2_Msk                               /*!< Capture/Compare 2 Value */

/*******************  Bit definition for TMR_CC3 register  *******************/
#define TMR_CC3_CC3_Pos                    (0U)
#define TMR_CC3_CC3_Msk                    (0xFFFFUL << TMR_CC3_CC3_Pos)                 /*!< 0x0000FFFF */
#define TMR_CC3_CC3                        TMR_CC3_CC3_Msk                               /*!< Capture/Compare 3 Value */

/*******************  Bit definition for TMR_CC4 register  ********************/
#define TMR_CC4_CC4_Pos                    (0U)
#define TMR_CC4_CC4_Msk                    (0xFFFFUL << TMR_CC4_CC4_Pos)                 /*!< 0x0000FFFF */
#define TMR_CC4_CC4                        TMR_CC4_CC4_Msk                               /*!< Capture/Compare 4 Value */

/*******************  Bit definition for TMR_BDT register  ********************/
#define TMR_BDT_DTS_Pos                    (0U)
#define TMR_BDT_DTS_Msk                    (0xFFUL << TMR_BDT_DTS_Pos)                   /*!< 0x000000FF */
#define TMR_BDT_DTS                        TMR_BDT_DTS_Msk                               /*!< DTG[0:7] bits (Dead-Time Generator set-up) */
#define TMR_BDT_LOCKCFG_Pos                (8U)
#define TMR_BDT_LOCKCFG_Msk                (0x3UL << TMR_BDT_LOCKCFG_Pos)                /*!< 0x00000300 */
#define TMR_BDT_LOCKCFG                    TMR_BDT_LOCKCFG_Msk                           /*!< LOCK[1:0] bits (Lock Configuration) */
#define TMR_BDT_LOCKCFG_0                  (0x1UL << TMR_BDT_LOCKCFG_Pos)                /*!< 0x0100 */
#define TMR_BDT_LOCKCFG_1                  (0x2UL << TMR_BDT_LOCKCFG_Pos)                /*!< 0x0200 */

#define TMR_BDT_IMOS_Pos                   (10U)
#define TMR_BDT_IMOS_Msk                   (0x1UL << TMR_BDT_IMOS_Pos)                   /*!< 0x00000400 */
#define TMR_BDT_IMOS                       TMR_BDT_IMOS_Msk                              /*!< Off-State Selection for Idle mode */
#define TMR_BDT_RMOS_Pos                   (11U)
#define TMR_BDT_RMOS_Msk                   (0x1UL << TMR_BDT_RMOS_Pos)                   /*!< 0x00000800 */
#define TMR_BDT_RMOS                       TMR_BDT_RMOS_Msk                              /*!< Off-State Selection for Run mode  */
#define TMR_BDT_BRKEN_Pos                  (12U)
#define TMR_BDT_BRKEN_Msk                  (0x1UL << TMR_BDT_BRKEN_Pos)                  /*!< 0x00001000 */
#define TMR_BDT_BRKEN                      TMR_BDT_BRKEN_Msk                             /*!< Break enable */
#define TMR_BDT_BRKPOL_Pos                 (13U)
#define TMR_BDT_BRKPOL_Msk                 (0x1UL << TMR_BDT_BRKPOL_Pos)                 /*!< 0x00002000 */
#define TMR_BDT_BRKPOL                     TMR_BDT_BRKPOL_Msk                            /*!< Break Polarity */
#define TMR_BDT_AOEN_Pos                   (14U)
#define TMR_BDT_AOEN_Msk                   (0x1UL << TMR_BDT_AOEN_Pos)                   /*!< 0x00004000 */
#define TMR_BDT_AOEN                       TMR_BDT_AOEN_Msk                              /*!< Automatic Output enable */
#define TMR_BDT_MOEN_Pos                   (15U)
#define TMR_BDT_MOEN_Msk                   (0x1UL << TMR_BDT_MOEN_Pos)                   /*!< 0x00008000 */
#define TMR_BDT_MOEN                       TMR_BDT_MOEN_Msk                              /*!< Main Output enable */

/*******************  Bit definition for TMR_DCTRL register  ******************/
#define TMR_DCTRL_DBADDR_Pos               (0U)
#define TMR_DCTRL_DBADDR_Msk               (0x1FUL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x0000001F */
#define TMR_DCTRL_DBADDR                   TMR_DCTRL_DBADDR_Msk                          /*!< DBA[4:0] bits (DMA Base Address) */
#define TMR_DCTRL_DBADDR_0                 (0x01UL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x00000001 */
#define TMR_DCTRL_DBADDR_1                 (0x02UL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x00000002 */
#define TMR_DCTRL_DBADDR_2                 (0x04UL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x00000004 */
#define TMR_DCTRL_DBADDR_3                 (0x08UL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x00000008 */
#define TMR_DCTRL_DBADDR_4                 (0x10UL << TMR_DCTRL_DBADDR_Pos)              /*!< 0x00000010 */

#define TMR_DCTRL_DBLEN_Pos                (8U)
#define TMR_DCTRL_DBLEN_Msk                (0x1FUL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00001F00 */
#define TMR_DCTRL_DBLEN                    TMR_DCTRL_DBLEN_Msk                           /*!< DBL[4:0] bits (DMA Burst Length) */
#define TMR_DCTRL_DBLEN_0                  (0x01UL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00000100 */
#define TMR_DCTRL_DBLEN_1                  (0x02UL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00000200 */
#define TMR_DCTRL_DBLEN_2                  (0x04UL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00000400 */
#define TMR_DCTRL_DBLEN_3                  (0x08UL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00000800 */
#define TMR_DCTRL_DBLEN_4                  (0x10UL << TMR_DCTRL_DBLEN_Pos)               /*!< 0x00001000 */

/*******************  Bit definition for TMR_DMADDR register  *****************/
/* Note: Mask is 32-bit for TMR1; other TMR instances use the lower 16 bits only. */
#define TMR_DMADDR_DMADDR_Pos              (0U)
#define TMR_DMADDR_DMADDR_Msk              (0xFFFFFFFFUL << TMR_DMADDR_DMADDR_Pos)       /*!< 0xFFFFFFFF */
#define TMR_DMADDR_DMADDR                  TMR_DMADDR_DMADDR_Msk                         /*!< DMA register for burst accesses */

/******************************************************************************/
/*                                                                            */
/*         Universal Synchronous Asynchronous Receiver Transmitter            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for USART_STS register  ******************/
#define USART_STS_PEFLG_Pos                (0U)
#define USART_STS_PEFLG_Msk                (0x1UL << USART_STS_PEFLG_Pos)                /*!< 0x00000001 */
#define USART_STS_PEFLG                    USART_STS_PEFLG_Msk                           /*!< Parity Error */
#define USART_STS_FEFLG_Pos                (1U)
#define USART_STS_FEFLG_Msk                (0x1UL << USART_STS_FEFLG_Pos)                /*!< 0x00000000 */
#define USART_STS_FEFLG                    USART_STS_FEFLG_Msk                           /*!< Framing Error */
#define USART_STS_NEFLG_Pos                (2U)
#define USART_STS_NEFLG_Msk                (0x1UL << USART_STS_NEFLG_Pos)                /*!< 0x00000004 */
#define USART_STS_NEFLG                    USART_STS_NEFLG_Msk                           /*!< Noise Error Flag */
#define USART_STS_OVREFLG_Pos              (3U)
#define USART_STS_OVREFLG_Msk              (0x1UL << USART_STS_OVREFLG_Pos)              /*!< 0x00000008 */
#define USART_STS_OVREFLG                  USART_STS_OVREFLG_Msk                         /*!< OverRun Error */
#define USART_STS_IDLEFLG_Pos              (4U)
#define USART_STS_IDLEFLG_Msk              (0x1UL << USART_STS_IDLEFLG_Pos)              /*!< 0x00000010 */
#define USART_STS_IDLEFLG                  USART_STS_IDLEFLG_Msk                         /*!< IDLE line detected */
#define USART_STS_RXBNEFLG_Pos             (5U)
#define USART_STS_RXBNEFLG_Msk             (0x1UL << USART_STS_RXBNEFLG_Pos)             /*!< 0x00000020 */
#define USART_STS_RXBNEFLG                 USART_STS_RXBNEFLG_Msk                        /*!< Read Data Register Not Empty */
#define USART_STS_TXCFLG_Pos               (6U)
#define USART_STS_TXCFLG_Msk               (0x1UL << USART_STS_TXCFLG_Pos)               /*!< 0x00000040 */
#define USART_STS_TXCFLG                   USART_STS_TXCFLG_Msk                          /*!< Transmission Complete */
#define USART_STS_TXBEFLG_Pos              (7U)
#define USART_STS_TXBEFLG_Msk              (0x1UL << USART_STS_TXBEFLG_Pos)              /*!< 0x00000080 */
#define USART_STS_TXBEFLG                  USART_STS_TXBEFLG_Msk                         /*!< Transmit Data Register Empty */
#define USART_STS_LBDFLG_Pos               (8U)
#define USART_STS_LBDFLG_Msk               (0x1UL << USART_STS_LBDFLG_Pos)               /*!< 0x00000100 */
#define USART_STS_LBDFLG                   USART_STS_LBDFLG_Msk                          /*!< LIN Break Detection Flag */
#define USART_STS_CTSFLG_Pos               (9U)
#define USART_STS_CTSFLG_Msk               (0x1UL << USART_STS_CTSFLG_Pos)               /*!< 0x00000200 */
#define USART_STS_CTSFLG                   USART_STS_CTSFLG_Msk                          /*!< CTS Flag */

/*******************  Bit definition for USART_DATA register  *****************/
#define USART_DATA_DATA_Pos                (0U)
#define USART_DATA_DATA_Msk                (0x1FFUL << USART_DATA_DATA_Pos)              /*!< 0x000001FF */
#define USART_DATA_DATA                    USART_DATA_DATA_Msk                           /*!< Data value */

/*******************  Bit definition for USART_BR register  *******************/
#define USART_BR_FBR_Pos                   (0U)
#define USART_BR_FBR_Msk                   (0xFUL << USART_BR_FBR_Pos)                   /*!< 0x0000000F */
#define USART_BR_FBR                       USART_BR_FBR_Msk                              /*!< Fraction of USARTDIV */
#define USART_BR_IBR_Pos                   (4U)
#define USART_BR_IBR_Msk                   (0xFFFUL << USART_BR_IBR_Pos)                 /*!< 0x0000FFF0 */
#define USART_BR_IBR                       USART_BR_IBR_Msk                              /*!< Mantissa of USARTDIV */

/*******************  Bit definition for USART_CTRL1 register  ****************/
#define USART_CTRL1_TXBF_Pos               (0U)
#define USART_CTRL1_TXBF_Msk               (0x1UL << USART_CTRL1_TXBF_Pos)               /*!< 0x00000001 */
#define USART_CTRL1_TXBF                   USART_CTRL1_TXBF_Msk                          /*!< Send Break */
#define USART_CTRL1_RXMUTEEN_Pos           (1U)
#define USART_CTRL1_RXMUTEEN_Msk           (0x1UL << USART_CTRL1_RXMUTEEN_Pos)           /*!< 0x00000000 */
#define USART_CTRL1_RXMUTEEN               USART_CTRL1_RXMUTEEN_Msk                      /*!< Receiver wakeup */
#define USART_CTRL1_RXEN_Pos               (2U)
#define USART_CTRL1_RXEN_Msk               (0x1UL << USART_CTRL1_RXEN_Pos)               /*!< 0x00000004 */
#define USART_CTRL1_RXEN                   USART_CTRL1_RXEN_Msk                          /*!< Receiver Enable */
#define USART_CTRL1_TXEN_Pos               (3U)
#define USART_CTRL1_TXEN_Msk               (0x1UL << USART_CTRL1_TXEN_Pos)               /*!< 0x00000008 */
#define USART_CTRL1_TXEN                   USART_CTRL1_TXEN_Msk                          /*!< Transmitter Enable */
#define USART_CTRL1_IDLEIEN_Pos            (4U)
#define USART_CTRL1_IDLEIEN_Msk            (0x1UL << USART_CTRL1_IDLEIEN_Pos)            /*!< 0x00000010 */
#define USART_CTRL1_IDLEIEN                USART_CTRL1_IDLEIEN_Msk                       /*!< IDLE Interrupt Enable */
#define USART_CTRL1_RXBNEIEN_Pos           (5U)
#define USART_CTRL1_RXBNEIEN_Msk           (0x1UL << USART_CTRL1_RXBNEIEN_Pos)           /*!< 0x00000020 */
#define USART_CTRL1_RXBNEIEN               USART_CTRL1_RXBNEIEN_Msk                      /*!< RXNE Interrupt Enable */
#define USART_CTRL1_TXCIEN_Pos             (6U)
#define USART_CTRL1_TXCIEN_Msk             (0x1UL << USART_CTRL1_TXCIEN_Pos)             /*!< 0x00000040 */
#define USART_CTRL1_TXCIEN                 USART_CTRL1_TXCIEN_Msk                        /*!< Transmission Complete Interrupt Enable */
#define USART_CTRL1_TXBEIEN_Pos            (7U)
#define USART_CTRL1_TXBEIEN_Msk            (0x1UL << USART_CTRL1_TXBEIEN_Pos)            /*!< 0x00000080 */
#define USART_CTRL1_TXBEIEN                USART_CTRL1_TXBEIEN_Msk                       /*!< TXE Interrupt Enable */
#define USART_CTRL1_PEIEN_Pos              (8U)
#define USART_CTRL1_PEIEN_Msk              (0x1UL << USART_CTRL1_PEIEN_Pos)              /*!< 0x00000100 */
#define USART_CTRL1_PEIEN                  USART_CTRL1_PEIEN_Msk                         /*!< PE Interrupt Enable */
#define USART_CTRL1_PCFG_Pos               (9U)
#define USART_CTRL1_PCFG_Msk               (0x1UL << USART_CTRL1_PCFG_Pos)               /*!< 0x00000200 */
#define USART_CTRL1_PCFG                   USART_CTRL1_PCFG_Msk                          /*!< Parity Selection */
#define USART_CTRL1_PCEN_Pos               (10U)
#define USART_CTRL1_PCEN_Msk               (0x1UL << USART_CTRL1_PCEN_Pos)               /*!< 0x00000400 */
#define USART_CTRL1_PCEN                   USART_CTRL1_PCEN_Msk                          /*!< Parity Control Enable */
#define USART_CTRL1_WUPMCFG_Pos            (11U)
#define USART_CTRL1_WUPMCFG_Msk            (0x1UL << USART_CTRL1_WUPMCFG_Pos)            /*!< 0x00000800 */
#define USART_CTRL1_WUPMCFG                USART_CTRL1_WUPMCFG_Msk                       /*!< Wakeup method */
#define USART_CTRL1_DBLCFG_Pos             (12U)
#define USART_CTRL1_DBLCFG_Msk             (0x1UL << USART_CTRL1_DBLCFG_Pos)             /*!< 0x00001000 */
#define USART_CTRL1_DBLCFG                 USART_CTRL1_DBLCFG_Msk                        /*!< Word length */
#define USART_CTRL1_UEN_Pos                (13U)
#define USART_CTRL1_UEN_Msk                (0x1UL << USART_CTRL1_UEN_Pos)                /*!< 0x00002000 */
#define USART_CTRL1_UEN                    USART_CTRL1_UEN_Msk                           /*!< USART Enable */
#define USART_CTRL1_OSMCFG_Pos             (15U)
#define USART_CTRL1_OSMCFG_Msk             (0x1UL << USART_CTRL1_OSMCFG_Pos)             /*!< 0x00008000 */
#define USART_CTRL1_OSMCFG                 USART_CTRL1_OSMCFG_Msk                        /*!< USART Oversampling by 8 enable */
#define USART_CTRL1_DEDT_Pos               (16U)
#define USART_CTRL1_DEDT_Msk               (0x1FUL << USART_CTRL1_DEDT_Pos)              /*!< 0x001F0000 */
#define USART_CTRL1_DEDT                   USART_CTRL1_DEDT_Msk                          /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CTRL1_DEDT_0                 (0x01UL << USART_CTRL1_DEDT_Pos)              /*!< 0x00010000 */
#define USART_CTRL1_DEDT_1                 (0x02UL << USART_CTRL1_DEDT_Pos)              /*!< 0x00020000 */
#define USART_CTRL1_DEDT_2                 (0x04UL << USART_CTRL1_DEDT_Pos)              /*!< 0x00040000 */
#define USART_CTRL1_DEDT_3                 (0x08UL << USART_CTRL1_DEDT_Pos)              /*!< 0x00080000 */
#define USART_CTRL1_DEDT_4                 (0x10UL << USART_CTRL1_DEDT_Pos)              /*!< 0x00100000 */

#define USART_CTRL1_DEAT_Pos               (21U)
#define USART_CTRL1_DEAT_Msk               (0x1FUL << USART_CTRL1_DEAT_Pos)              /*!< 0x03E00000 */
#define USART_CTRL1_DEAT                   USART_CTRL1_DEAT_Msk                          /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define USART_CTRL1_DEAT_0                 (0x01UL << USART_CTRL1_DEAT_Pos)              /*!< 0x00200000 */
#define USART_CTRL1_DEAT_1                 (0x02UL << USART_CTRL1_DEAT_Pos)              /*!< 0x00400000 */
#define USART_CTRL1_DEAT_2                 (0x04UL << USART_CTRL1_DEAT_Pos)              /*!< 0x00800000 */
#define USART_CTRL1_DEAT_3                 (0x08UL << USART_CTRL1_DEAT_Pos)              /*!< 0x01000000 */
#define USART_CTRL1_DEAT_4                 (0x10UL << USART_CTRL1_DEAT_Pos)              /*!< 0x02000000 */

/*******************  Bit definition for USART_CTRL2 register  ****************/
#define USART_CTRL2_ADDR_Pos               (0U)
#define USART_CTRL2_ADDR_Msk               (0xFUL << USART_CTRL2_ADDR_Pos)               /*!< 0x0000000F */
#define USART_CTRL2_ADDR                   USART_CTRL2_ADDR_Msk                          /*!< Address of the USART node */
#define USART_CTRL2_LBDLCFG_Pos            (5U)
#define USART_CTRL2_LBDLCFG_Msk            (0x1UL << USART_CTRL2_LBDLCFG_Pos)            /*!< 0x00000020 */
#define USART_CTRL2_LBDLCFG                USART_CTRL2_LBDLCFG_Msk                       /*!< LIN Break Detection Length */
#define USART_CTRL2_LBDIEN_Pos             (6U)
#define USART_CTRL2_LBDIEN_Msk             (0x1UL << USART_CTRL2_LBDIEN_Pos)             /*!< 0x00000040 */
#define USART_CTRL2_LBDIEN                 USART_CTRL2_LBDIEN_Msk                        /*!< LIN Break Detection Interrupt Enable */
#define USART_CTRL2_LBCPOEN_Pos            (8U)
#define USART_CTRL2_LBCPOEN_Msk            (0x1UL << USART_CTRL2_LBCPOEN_Pos)            /*!< 0x00000100 */
#define USART_CTRL2_LBCPOEN                USART_CTRL2_LBCPOEN_Msk                       /*!< Last Bit Clock pulse */
#define USART_CTRL2_CPHA_Pos               (9U)
#define USART_CTRL2_CPHA_Msk               (0x1UL << USART_CTRL2_CPHA_Pos)               /*!< 0x00000200 */
#define USART_CTRL2_CPHA                   USART_CTRL2_CPHA_Msk                          /*!< Clock Phase */
#define USART_CTRL2_CPOL_Pos               (10U)
#define USART_CTRL2_CPOL_Msk               (0x1UL << USART_CTRL2_CPOL_Pos)               /*!< 0x00000400 */
#define USART_CTRL2_CPOL                   USART_CTRL2_CPOL_Msk                          /*!< Clock Polarity */
#define USART_CTRL2_CLKEN_Pos              (11U)
#define USART_CTRL2_CLKEN_Msk              (0x1UL << USART_CTRL2_CLKEN_Pos)              /*!< 0x00000800 */
#define USART_CTRL2_CLKEN                  USART_CTRL2_CLKEN_Msk                         /*!< Clock Enable */
#define USART_CTRL2_STOPCFG_Pos            (12U)
#define USART_CTRL2_STOPCFG_Msk            (0x3UL << USART_CTRL2_STOPCFG_Pos)            /*!< 0x00003000 */
#define USART_CTRL2_STOPCFG                USART_CTRL2_STOPCFG_Msk                       /*!< STOP[1:0] bits (STOP bits) */
#define USART_CTRL2_STOPCFG_0              (0x1UL << USART_CTRL2_STOPCFG_Pos)            /*!< 0x1000 */
#define USART_CTRL2_STOPCFG_1              (0x2UL << USART_CTRL2_STOPCFG_Pos)            /*!< 0x2000 */

#define USART_CTRL2_LINMEN_Pos             (14U)
#define USART_CTRL2_LINMEN_Msk             (0x1UL << USART_CTRL2_LINMEN_Pos)             /*!< 0x00004000 */
#define USART_CTRL2_LINMEN                 USART_CTRL2_LINMEN_Msk                        /*!< LIN mode enable */

/*******************  Bit definition for USART_CTRL3 register  ****************/
#define USART_CTRL3_ERRIEN_Pos             (0U)
#define USART_CTRL3_ERRIEN_Msk             (0x1UL << USART_CTRL3_ERRIEN_Pos)             /*!< 0x00000001 */
#define USART_CTRL3_ERRIEN                 USART_CTRL3_ERRIEN_Msk                        /*!< Error Interrupt Enable */
#define USART_CTRL3_IREN_Pos               (1U)
#define USART_CTRL3_IREN_Msk               (0x1UL << USART_CTRL3_IREN_Pos)               /*!< 0x00000000 */
#define USART_CTRL3_IREN                   USART_CTRL3_IREN_Msk                          /*!< IrDA mode Enable */
#define USART_CTRL3_IRLPEN_Pos             (2U)
#define USART_CTRL3_IRLPEN_Msk             (0x1UL << USART_CTRL3_IRLPEN_Pos)             /*!< 0x00000004 */
#define USART_CTRL3_IRLPEN                 USART_CTRL3_IRLPEN_Msk                        /*!< IrDA Low-Power */
#define USART_CTRL3_HDEN_Pos               (3U)
#define USART_CTRL3_HDEN_Msk               (0x1UL << USART_CTRL3_HDEN_Pos)               /*!< 0x00000008 */
#define USART_CTRL3_HDEN                   USART_CTRL3_HDEN_Msk                          /*!< Half-Duplex Selection */
#define USART_CTRL3_SCNACKEN_Pos           (4U)
#define USART_CTRL3_SCNACKEN_Msk           (0x1UL << USART_CTRL3_SCNACKEN_Pos)           /*!< 0x00000010 */
#define USART_CTRL3_SCNACKEN               USART_CTRL3_SCNACKEN_Msk                      /*!< Smartcard NACK enable */
#define USART_CTRL3_SCEN_Pos               (5U)
#define USART_CTRL3_SCEN_Msk               (0x1UL << USART_CTRL3_SCEN_Pos)               /*!< 0x00000020 */
#define USART_CTRL3_SCEN                   USART_CTRL3_SCEN_Msk                          /*!< Smartcard mode enable */
#define USART_CTRL3_DMARXEN_Pos            (6U)
#define USART_CTRL3_DMARXEN_Msk            (0x1UL << USART_CTRL3_DMARXEN_Pos)            /*!< 0x00000040 */
#define USART_CTRL3_DMARXEN                USART_CTRL3_DMARXEN_Msk                       /*!< DMA Enable Receiver */
#define USART_CTRL3_DMATXEN_Pos            (7U)
#define USART_CTRL3_DMATXEN_Msk            (0x1UL << USART_CTRL3_DMATXEN_Pos)            /*!< 0x00000080 */
#define USART_CTRL3_DMATXEN                USART_CTRL3_DMATXEN_Msk                       /*!< DMA Enable Transmitter */
#define USART_CTRL3_RTSEN_Pos              (8U)
#define USART_CTRL3_RTSEN_Msk              (0x1UL << USART_CTRL3_RTSEN_Pos)              /*!< 0x00000100 */
#define USART_CTRL3_RTSEN                  USART_CTRL3_RTSEN_Msk                         /*!< RTS Enable */
#define USART_CTRL3_CTSEN_Pos              (9U)
#define USART_CTRL3_CTSEN_Msk              (0x1UL << USART_CTRL3_CTSEN_Pos)              /*!< 0x00000200 */
#define USART_CTRL3_CTSEN                  USART_CTRL3_CTSEN_Msk                         /*!< CTS Enable */
#define USART_CTRL3_CTSIEN_Pos             (10U)
#define USART_CTRL3_CTSIEN_Msk             (0x1UL << USART_CTRL3_CTSIEN_Pos)             /*!< 0x00000400 */
#define USART_CTRL3_CTSIEN                 USART_CTRL3_CTSIEN_Msk                        /*!< CTS Interrupt Enable */
#define USART_CTRL3_SAMCFG_Pos             (11U)
#define USART_CTRL3_SAMCFG_Msk             (0x1UL << USART_CTRL3_SAMCFG_Pos)             /*!< 0x00000800 */
#define USART_CTRL3_SAMCFG                 USART_CTRL3_SAMCFG_Msk                        /*!< Sample Method Configuration */
#define USART_CTRL3_DEM_Pos                (12U)
#define USART_CTRL3_DEM_Msk                (0x1UL << USART_CTRL3_DEM_Pos)                /*!< 0x00001000 */
#define USART_CTRL3_DEM                    USART_CTRL3_DEM_Msk                           /*!< Driver Enable Mode */

/******************  Bit definition for USART_GTPSC register  *****************/
#define USART_GTPSC_PSC_Pos                (0U)
#define USART_GTPSC_PSC_Msk                (0xFFUL << USART_GTPSC_PSC_Pos)               /*!< 0x000000FF */
#define USART_GTPSC_PSC                    USART_GTPSC_PSC_Msk                           /*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPSC_GRDT_Pos               (8U)
#define USART_GTPSC_GRDT_Msk               (0xFFUL << USART_GTPSC_GRDT_Pos)              /*!< 0x0000FF00 */
#define USART_GTPSC_GRDT                   USART_GTPSC_GRDT_Msk                          /*!< Guard time value */

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDT_CTRL register  ******************/
#define WWDT_CTRL_CNT_Pos                  (0U)
#define WWDT_CTRL_CNT_Msk                  (0x7FUL << WWDT_CTRL_CNT_Pos)                 /*!< 0x0000007F */
#define WWDT_CTRL_CNT                      WWDT_CTRL_CNT_Msk                             /*!< T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDT_CTRL_WWDTEN_Pos               (7U)
#define WWDT_CTRL_WWDTEN_Msk               (0x1UL << WWDT_CTRL_WWDTEN_Pos)               /*!< 0x00000080 */
#define WWDT_CTRL_WWDTEN                   WWDT_CTRL_WWDTEN_Msk                          /*!< Activation bit */

/*******************  Bit definition for WWDT_CFG register  *******************/
#define WWDT_CFG_WIN_Pos                   (0U)
#define WWDT_CFG_WIN_Msk                   (0x7FUL << WWDT_CFG_WIN_Pos)                  /*!< 0x0000007F */
#define WWDT_CFG_WIN                       WWDT_CFG_WIN_Msk                              /*!< W[6:0] bits (7-bit window value) */
#define WWDT_CFG_TBPSC_Pos                 (7U)
#define WWDT_CFG_TBPSC_Msk                 (0x3UL << WWDT_CFG_TBPSC_Pos)                 /*!< 0x00000180 */
#define WWDT_CFG_TBPSC                     WWDT_CFG_TBPSC_Msk                            /*!< WDGTB[1:0] bits (Timer Base) */
#define WWDT_CFG_TBPSC_0                   (0x1UL << WWDT_CFG_TBPSC_Pos)                 /*!< 0x00000080 */
#define WWDT_CFG_TBPSC_1                   (0x2UL << WWDT_CFG_TBPSC_Pos)                 /*!< 0x00000100 */

#define WWDT_CFG_EWIEN_Pos                 (9U)
#define WWDT_CFG_EWIEN_Msk                 (0x1UL << WWDT_CFG_EWIEN_Pos)                 /*!< 0x00000200 */
#define WWDT_CFG_EWIEN                     WWDT_CFG_EWIEN_Msk                            /*!< Early Wakeup Interrupt */

/*******************  Bit definition for WWDT_STS register  *******************/
#define WWDT_STS_EWIFLG_Pos                (0U)
#define WWDT_STS_EWIFLG_Msk                (0x1UL << WWDT_STS_EWIFLG_Pos)                /*!< 0x00000001 */
#define WWDT_STS_EWIFLG                    WWDT_STS_EWIFLG_Msk                           /*!< Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                                DBG                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_ID register  *************/
#define DBGMCU_ID_DEV_ID_Pos               (0U)
#define DBGMCU_ID_DEV_ID_Msk               (0xFFFFUL << DBGMCU_ID_DEV_ID_Pos)            /*!< 0x0000FFFF */
#define DBGMCU_ID_DEV_ID                   DBGMCU_ID_DEV_ID_Msk
#define DBGMCU_ID_REV_ID_Pos               (16U)
#define DBGMCU_ID_REV_ID_Msk               (0xFFFFUL << DBGMCU_ID_REV_ID_Pos)            /*!< 0xFFFF0000 */
#define DBGMCU_ID_REV_ID                   DBGMCU_ID_REV_ID_Msk

/********************  Bit definition for DBGMCU_APB register  ****************/
#define DBGMCU_APB_DBG_TMR1_STOP_Pos       (0U)
#define DBGMCU_APB_DBG_TMR1_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_TMR1_STOP_Pos)       /*!< 0x00000001 */
#define DBGMCU_APB_DBG_TMR1_STOP           DBGMCU_APB_DBG_TMR1_STOP_Msk
#define DBGMCU_APB_DBG_TMR2_STOP_Pos       (4U)
#define DBGMCU_APB_DBG_TMR2_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_TMR2_STOP_Pos)       /*!< 0x00000010 */
#define DBGMCU_APB_DBG_TMR2_STOP           DBGMCU_APB_DBG_TMR2_STOP_Msk
#define DBGMCU_APB_DBG_TMR3_STOP_Pos       (5U)
#define DBGMCU_APB_DBG_TMR3_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_TMR3_STOP_Pos)       /*!< 0x00000020 */
#define DBGMCU_APB_DBG_TMR3_STOP           DBGMCU_APB_DBG_TMR3_STOP_Msk
#define DBGMCU_APB_DBG_TMR4_STOP_Pos       (6U)
#define DBGMCU_APB_DBG_TMR4_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_TMR4_STOP_Pos)       /*!< 0x00000040 */
#define DBGMCU_APB_DBG_TMR4_STOP           DBGMCU_APB_DBG_TMR4_STOP_Msk
#define DBGMCU_APB_DBG_LPTMR_STOP_Pos      (12U)
#define DBGMCU_APB_DBG_LPTMR_STOP_Msk      (0x1UL << DBGMCU_APB_DBG_LPTMR_STOP_Pos)      /*!< 0x00001000 */
#define DBGMCU_APB_DBG_LPTMR_STOP          DBGMCU_APB_DBG_LPTMR_STOP_Msk
#define DBGMCU_APB_DBG_RTC_STOP_Pos        (15U)
#define DBGMCU_APB_DBG_RTC_STOP_Msk        (0x1UL << DBGMCU_APB_DBG_RTC_STOP_Pos)        /*!< 0x00008000 */
#define DBGMCU_APB_DBG_RTC_STOP            DBGMCU_APB_DBG_RTC_STOP_Msk
#define DBGMCU_APB_DBG_WWDT_STOP_Pos       (16U)
#define DBGMCU_APB_DBG_WWDT_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_WWDT_STOP_Pos)       /*!< 0x00010000 */
#define DBGMCU_APB_DBG_WWDT_STOP           DBGMCU_APB_DBG_WWDT_STOP_Msk
#define DBGMCU_APB_DBG_IWDT_STOP_Pos       (17U)
#define DBGMCU_APB_DBG_IWDT_STOP_Msk       (0x1UL << DBGMCU_APB_DBG_IWDT_STOP_Pos)       /*!< 0x00020000 */
#define DBGMCU_APB_DBG_IWDT_STOP           DBGMCU_APB_DBG_IWDT_STOP_Msk

/******************************************************************************/
/*                                                                            */
/*                                 COMP                                       */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for COMP_CSTS register  *******************/
#define COMP_CSTS_EN_Pos                   (0U)
#define COMP_CSTS_EN_Msk                   (0x1UL << COMP_CSTS_EN_Pos)                   /*!< 0x00000001 */
#define COMP_CSTS_EN                       COMP_CSTS_EN_Msk                              /*!< Comparator enable bit */
#define COMP_CSTS_FILTER_Pos               (1U)
#define COMP_CSTS_FILTER_Msk               (0x7UL << COMP_CSTS_FILTER_Pos)               /*!< 0x0000000E */
#define COMP_CSTS_FILTER                   COMP_CSTS_FILTER_Msk                          /*!< Comparator VN source bit */
#define COMP_CSTS_FILTER_0                 (0x1UL << COMP_CSTS_FILTER_Pos)               /*!< 0x00000002 */
#define COMP_CSTS_FILTER_1                 (0x2UL << COMP_CSTS_FILTER_Pos)               /*!< 0x00000004 */
#define COMP_CSTS_FILTER_2                 (0x4UL << COMP_CSTS_FILTER_Pos)               /*!< 0x00000008 */

#define COMP_CSTS_VN_SEL_Pos               (4U)
#define COMP_CSTS_VN_SEL_Msk               (0x3UL << COMP_CSTS_VN_SEL_Pos)               /*!< 0x00000030 */
#define COMP_CSTS_VN_SEL                   COMP_CSTS_VN_SEL_Msk                          /*!< Comparator VN source bit */
#define COMP_CSTS_VN_SEL_0                 (0x1UL << COMP_CSTS_VN_SEL_Pos)               /*!< 0x00000010 */
#define COMP_CSTS_VN_SEL_1                 (0x2UL << COMP_CSTS_VN_SEL_Pos)               /*!< 0x00000020 */

#define COMP_CSTS_VP_SEL_Pos               (6U)
#define COMP_CSTS_VP_SEL_Msk               (0x3UL << COMP_CSTS_VP_SEL_Pos)               /*!< 0x000000C0 */
#define COMP_CSTS_VP_SEL                   COMP_CSTS_VP_SEL_Msk                          /*!< Comparator VP source bit */
#define COMP_CSTS_VP_SEL_0                 (0x1UL << COMP_CSTS_VP_SEL_Pos)               /*!< 0x00000040 */
#define COMP_CSTS_VP_SEL_1                 (0x2UL << COMP_CSTS_VP_SEL_Pos)               /*!< 0x00000080 */

#define COMP_CSTS_TMR_SEL_Pos              (8U)
#define COMP_CSTS_TMR_SEL_Msk              (0xFUL << COMP_CSTS_TMR_SEL_Pos)              /*!< 0x00000F00 */
#define COMP_CSTS_TMR_SEL                  COMP_CSTS_TMR_SEL_Msk                         /*!< Comparator output to TMR select bit */
#define COMP_CSTS_TMR_SEL_0                (0x1UL << COMP_CSTS_TMR_SEL_Pos)              /*!< 0x00000040 */
#define COMP_CSTS_TMR_SEL_1                (0x2UL << COMP_CSTS_TMR_SEL_Pos)              /*!< 0x00000080 */
#define COMP_CSTS_TMR_SEL_2                (0x4UL << COMP_CSTS_TMR_SEL_Pos)              /*!< 0x00000080 */
#define COMP_CSTS_TMR_SEL_3                (0x8UL << COMP_CSTS_TMR_SEL_Pos)              /*!< 0x00000080 */

#define COMP_CSTS_POL_Pos                  (15U)
#define COMP_CSTS_POL_Msk                  (0x1UL << COMP_CSTS_POL_Pos)                  /*!< 0x00008000 */
#define COMP_CSTS_POL                      COMP_CSTS_POL_Msk                             /*!< Window mode selection bit Only for Comparator 1 */
#define COMP_CSTS_HYS_Pos                  (16U)
#define COMP_CSTS_HYS_Msk                  (0x3UL << COMP_CSTS_HYS_Pos)                  /*!< 0x00030000 */
#define COMP_CSTS_HYS                      COMP_CSTS_HYS_Msk                             /*!< Comparator hysteresis select bit */
#define COMP_CSTS_HYS_0                    (0x1UL << COMP_CSTS_HYS_Pos)                  /*!< 0x00010000 */
#define COMP_CSTS_HYS_1                    (0x2UL << COMP_CSTS_HYS_Pos)                  /*!< 0x00020000 */

#define COMP_CSTS_BLANKSEL_Pos             (18U)
#define COMP_CSTS_BLANKSEL_Msk             (0x7UL << COMP_CSTS_BLANKSEL_Pos)             /*!< 0x001C0000 */
#define COMP_CSTS_BLANKSEL                 COMP_CSTS_BLANKSEL_Msk                        /*!< BLANKSEL[2:0] bits (Comparator output blank selection) */
#define COMP_CSTS_BLANKSEL_0               (0x1UL << COMP_CSTS_BLANKSEL_Pos)             /*!< 0x00020000 */
#define COMP_CSTS_BLANKSEL_1               (0x2UL << COMP_CSTS_BLANKSEL_Pos)             /*!< 0x00040000 */
#define COMP_CSTS_BLANKSEL_2               (0x4UL << COMP_CSTS_BLANKSEL_Pos)             /*!< 0x00080000 */

#define COMP_CSTS_OUTVAL_Pos               (30U)
#define COMP_CSTS_OUTVAL_Msk               (0x1UL << COMP_CSTS_OUTVAL_Pos)               /*!< 0x40000000 */
#define COMP_CSTS_OUTVAL                   COMP_CSTS_OUTVAL_Msk                          /*!< Comparator output status bit */
#define COMP_CSTS_LOCK_Pos                 (31U)
#define COMP_CSTS_LOCK_Msk                 (0x1UL << COMP_CSTS_LOCK_Pos)                 /*!< 0x80000000 */
#define COMP_CSTS_LOCK                     COMP_CSTS_LOCK_Msk                            /*!< COMP_CSTS register lock bit */

/******************************************************************************/
/*                                                                            */
/*                                 Temperature sensor                         */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for TS_CR register  ***********************/
#define TS_CR_TS_EN_Pos                    (0U)
#define TS_CR_TS_EN_Msk                    (0x1UL << TS_CR_TS_EN_Pos)                    /*!< 0x00000001 */
#define TS_CR_TS_EN                        TS_CR_TS_EN_Msk                               /*!< Temperature enable bit */
#define TS_CR_OSR_SEL_Pos                  (1U)
#define TS_CR_OSR_SEL_Msk                  (0x3UL << TS_CR_OSR_SEL_Pos)                  /*!< 0x00000006 */
#define TS_CR_OSR_SEL                      TS_CR_OSR_SEL_Msk                             /*!< Temperature sampling rate select bit */
#define TS_CR_OSR_SEL_0                    (0x1UL << TS_CR_OSR_SEL_Pos)                  /*!< 0x00000002 */
#define TS_CR_OSR_SEL_1                    (0x2UL << TS_CR_OSR_SEL_Pos)                  /*!< 0x00000004 */

#define TS_CR_OVRMOD_Pos                   (4U)
#define TS_CR_OVRMOD_Msk                   (0x1UL << TS_CR_OVRMOD_Pos)                   /*!< 0x00000010 */
#define TS_CR_OVRMOD                       TS_CR_OVRMOD_Msk                              /*!< Temperature data overflow control bit */
#define TS_CR_TS_IE_Pos                    (16U)
#define TS_CR_TS_IE_Msk                    (0x1UL << TS_CR_TS_IE_Pos)                    /*!< 0x00010000 */
#define TS_CR_TS_IE                        TS_CR_TS_IE_Msk                               /*!< Temperature interrupt enable bit */
#define TS_CR_OVRIE_Pos                    (17U)
#define TS_CR_OVRIE_Msk                    (0x1UL << TS_CR_OVRIE_Pos)                    /*!< 0x00020010 */
#define TS_CR_OVRIE                        TS_CR_OVRIE_Msk                               /*!< Temperature data overflow interrupt enable bit */

/******************  Bit definition for TS_DR register  ***********************/
#define TS_DR_DATA_Pos                     (0U)
#define TS_DR_DATA_Msk                     (0xFFFFUL << TS_DR_DATA_Pos)                  /*!< 0x0000FFFF */
#define TS_DR_DATA                         TS_DR_DATA_Msk                                /*!< Temperature data bit */

/******************  Bit definition for TS_SR register  ***********************/
#define TS_SR_RDY_Pos                      (0U)
#define TS_SR_RDY_Msk                      (0x1UL << TS_SR_RDY_Pos)                      /*!< 0x00000001 */
#define TS_SR_RDY                          TS_SR_RDY_Msk                                 /*!< Temperature ready status bit */
#define TS_SR_OVR_Pos                      (1U)
#define TS_SR_OVR_Msk                      (0x1UL << TS_SR_OVR_Pos)                      /*!< 0x00000002 */
#define TS_SR_OVR                          TS_SR_OVR_Msk                                 /*!< Temperature overflow status bit */

/******************************************************************************/
/*                                                                            */
/*                              Power manager unit                            */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for PMU_CR register  **********************/
#define PMU_CR_LSION_Pos                   (5U)
#define PMU_CR_LSION_Msk                   (0x1UL << PMU_CR_LSION_Pos)                   /*!< 0x00000020 */
#define PMU_CR_LSION                       PMU_CR_LSION_Msk                              /*!< LSI enable bit */
#define PMU_CR_LSIRDY_Pos                  (6U)
#define PMU_CR_LSIRDY_Msk                  (0x1UL << PMU_CR_LSIRDY_Pos)                  /*!< 0x00000040 */
#define PMU_CR_LSIRDY                      PMU_CR_LSIRDY_Msk                             /*!< LSI ready status bit */
#define PMU_CR_RTCSEL_Pos                  (8U)
#define PMU_CR_RTCSEL_Msk                  (0x3UL << PMU_CR_RTCSEL_Pos)                  /*!< 0x00000300 */
#define PMU_CR_RTCSEL                      PMU_CR_RTCSEL_Msk                             /*!< RTC clock source select bit */
#define PMU_CR_RTCSEL_0                    (0x1UL << PMU_CR_RTCSEL_Pos)                  /*!< 0x00000100 */
#define PMU_CR_RTCSEL_1                    (0x2UL << PMU_CR_RTCSEL_Pos)                  /*!< 0x00000200 */

#define PMU_CR_RTCEN_Pos                   (10U)
#define PMU_CR_RTCEN_Msk                   (0x1UL << PMU_CR_RTCEN_Pos)                   /*!< 0x00000400 */
#define PMU_CR_RTCEN                       PMU_CR_RTCEN_Msk                              /*!< RTC clock source select bit */
#define PMU_CR_LPTMRCEN_Pos                (11U)
#define PMU_CR_LPTMRCEN_Msk                (0x1UL << PMU_CR_LPTMRCEN_Pos)                /*!< 0x00000800 */
#define PMU_CR_LPTMRCEN                    PMU_CR_LPTMRCEN_Msk                           /*!< LSTMR clock enable bit */
#define PMU_CR_NRSTOUTDIS_Pos              (13U)
#define PMU_CR_NRSTOUTDIS_Msk              (0x1UL << PMU_CR_NRSTOUTDIS_Pos)              /*!< 0x00002000 */
#define PMU_CR_NRSTOUTDIS                  PMU_CR_NRSTOUTDIS_Msk                         /*!< Prohibit internal reset pulse output to NRST bit */
#define PMU_CR_BDRST_Pos                   (15U)
#define PMU_CR_BDRST_Msk                   (0x1UL << PMU_CR_BDRST_Pos)                   /*!< 0x00008000 */
#define PMU_CR_BDRST                       PMU_CR_BDRST_Msk                              /*!< Back up reset bit */

/******************  Bit definition for PMU_WKPCR register  *******************/
#define PMU_WKPCR_WKUPEN0_Pos              (0U)
#define PMU_WKPCR_WKUPEN0_Msk              (0x1UL << PMU_WKPCR_WKUPEN0_Pos)              /*!< 0x00000001 */
#define PMU_WKPCR_WKUPEN0                  PMU_WKPCR_WKUPEN0_Msk                         /*!< Wakeup IO0 enable bit */
#define PMU_WKPCR_WKUPEN1_Pos              (1U)
#define PMU_WKPCR_WKUPEN1_Msk              (0x1UL << PMU_WKPCR_WKUPEN1_Pos)              /*!< 0x00000002 */
#define PMU_WKPCR_WKUPEN1                  PMU_WKPCR_WKUPEN1_Msk                         /*!< Wakeup IO1 enable bit */
#define PMU_WKPCR_WKUPEN2_Pos              (2U)
#define PMU_WKPCR_WKUPEN2_Msk              (0x1UL << PMU_WKPCR_WKUPEN2_Pos)              /*!< 0x00000004 */
#define PMU_WKPCR_WKUPEN2                  PMU_WKPCR_WKUPEN2_Msk                         /*!< Wakeup IO2 enable bit */
#define PMU_WKPCR_WKUPEN3_Pos              (3U)
#define PMU_WKPCR_WKUPEN3_Msk              (0x1UL << PMU_WKPCR_WKUPEN3_Pos)              /*!< 0x00000008 */
#define PMU_WKPCR_WKUPEN3                  PMU_WKPCR_WKUPEN3_Msk                         /*!< Wakeup IO3 enable bit */
#define PMU_WKPCR_WKUPPOL0_Pos             (4U)
#define PMU_WKPCR_WKUPPOL0_Msk             (0x3UL << PMU_WKPCR_WKUPPOL0_Pos)             /*!< 0x00000030 */
#define PMU_WKPCR_WKUPPOL0                 PMU_WKPCR_WKUPPOL0_Msk                        /*!< Wakeup IO0 polarity select bit */
#define PMU_WKPCR_WKUPPOL1_Pos             (6U)
#define PMU_WKPCR_WKUPPOL1_Msk             (0x3UL << PMU_WKPCR_WKUPPOL1_Pos)             /*!< 0x000000C0 */
#define PMU_WKPCR_WKUPPOL1                 PMU_WKPCR_WKUPPOL1_Msk                        /*!< Wakeup IO1 polarity select bit */
#define PMU_WKPCR_WKUPPOL2_Pos             (8U)
#define PMU_WKPCR_WKUPPOL2_Msk             (0x3UL << PMU_WKPCR_WKUPPOL2_Pos)             /*!< 0x00000300 */
#define PMU_WKPCR_WKUPPOL2                 PMU_WKPCR_WKUPPOL2_Msk                        /*!< Wakeup IO2 polarity select bit */
#define PMU_WKPCR_WKUPPOL3_Pos             (10U)
#define PMU_WKPCR_WKUPPOL3_Msk             (0x3UL << PMU_WKPCR_WKUPPOL3_Pos)             /*!< 0x00000C00 */
#define PMU_WKPCR_WKUPPOL3                 PMU_WKPCR_WKUPPOL3_Msk                        /*!< Wakeup IO3 polarity select bit */
#define PMU_WKPCR_APC_Pos                  (15U)
#define PMU_WKPCR_APC_Msk                  (0x1UL << PMU_WKPCR_APC_Pos)                  /*!< 0x00008000 */
#define PMU_WKPCR_APC                      PMU_WKPCR_APC_Msk                             /*!< GPIO status in standby mode select bit */

/******************  Bit definition for PMU_SR register  **********************/
#define PMU_SR_WKUPF0_Pos                  (0U)
#define PMU_SR_WKUPF0_Msk                  (0x1UL << PMU_SR_WKUPF0_Pos)                  /*!< 0x00000001 */
#define PMU_SR_WKUPF0                      PMU_SR_WKUPF0_Msk                             /*!< IO0 wakeup flag bit */
#define PMU_SR_WKUPF1_Pos                  (1U)
#define PMU_SR_WKUPF1_Msk                  (0x1UL << PMU_SR_WKUPF1_Pos)                  /*!< 0x00000002 */
#define PMU_SR_WKUPF1                      PMU_SR_WKUPF1_Msk                             /*!< IO1 wakeup flag bit */
#define PMU_SR_WKUPF2_Pos                  (2U)
#define PMU_SR_WKUPF2_Msk                  (0x1UL << PMU_SR_WKUPF2_Pos)                  /*!< 0x00000004 */
#define PMU_SR_WKUPF2                      PMU_SR_WKUPF2_Msk                             /*!< IO2 wakeup flag bit */
#define PMU_SR_WKUPF3_Pos                  (3U)
#define PMU_SR_WKUPF3_Msk                  (0x1UL << PMU_SR_WKUPF3_Pos)                  /*!< 0x00000008 */
#define PMU_SR_WKUPF3                      PMU_SR_WKUPF3_Msk                             /*!< IO3 wakeup flag bit */
#define PMU_SR_SBF_Pos                     (4U)
#define PMU_SR_SBF_Msk                     (0x1UL << PMU_SR_SBF_Pos)                     /*!< 0x00000010 */
#define PMU_SR_SBF                         PMU_SR_SBF_Msk                                /*!< Entered standby flag bit */
#define PMU_SR_EVSWKF_Pos                  (5U)
#define PMU_SR_EVSWKF_Msk                  (0x1UL << PMU_SR_EVSWKF_Pos)                  /*!< 0x00000020 */
#define PMU_SR_EVSWKF                      PMU_SR_EVSWKF_Msk                             /*!< EVS wakeup flag bit */
#define PMU_SR_PVDO_Pos                    (6U)
#define PMU_SR_PVDO_Msk                    (0x1UL << PMU_SR_PVDO_Pos)                    /*!< 0x00000040 */
#define PMU_SR_PVDO                        PMU_SR_PVDO_Msk                               /*!< PVD output flag bit */

/******************  Bit definition for PMU_PUCRA register  *******************/
#define PMU_PUCRA_WKPU0_Pos                (0U)
#define PMU_PUCRA_WKPU0_Msk                (0x1UL << PMU_PUCRA_WKPU0_Pos)                /*!< 0x00000001 */
#define PMU_PUCRA_WKPU0                    PMU_PUCRA_WKPU0_Msk                           /*!< Wakeup IO0 pull up status bit */
#define PMU_PUCRA_WKPU1_Pos                (1U)
#define PMU_PUCRA_WKPU1_Msk                (0x1UL << PMU_PUCRA_WKPU1_Pos)                /*!< 0x00000002 */
#define PMU_PUCRA_WKPU1                    PMU_PUCRA_WKPU1_Msk                           /*!< Wakeup IO1 pull up status bit */
#define PMU_PUCRA_WKPU2_Pos                (2U)
#define PMU_PUCRA_WKPU2_Msk                (0x1UL << PMU_PUCRA_WKPU2_Pos)                /*!< 0x00000004 */
#define PMU_PUCRA_WKPU2                    PMU_PUCRA_WKPU2_Msk                           /*!< Wakeup IO2 pull up status bit */
#define PMU_PUCRA_WKPU3_Pos                (3U)
#define PMU_PUCRA_WKPU3_Msk                (0x1UL << PMU_PUCRA_WKPU3_Pos)                /*!< 0x00000008 */
#define PMU_PUCRA_WKPU3                    PMU_PUCRA_WKPU3_Msk                           /*!< Wakeup IO3 pull up status bit */

/******************  Bit definition for PMU_PDCRA register  *******************/
#define PMU_PDCRA_WKPD0_Pos                (0U)
#define PMU_PDCRA_WKPD0_Msk                (0x1UL << PMU_PDCRA_WKPD0_Pos)                /*!< 0x00000001 */
#define PMU_PDCRA_WKPD0                    PMU_PDCRA_WKPD0_Msk                           /*!< Wakeup IO0 pull down status bit */
#define PMU_PDCRA_WKPD1_Pos                (1U)
#define PMU_PDCRA_WKPD1_Msk                (0x1UL << PMU_PDCRA_WKPD1_Pos)                /*!< 0x00000002 */
#define PMU_PDCRA_WKPD1                    PMU_PDCRA_WKPD1_Msk                           /*!< Wakeup IO1 pull down status bit */
#define PMU_PDCRA_WKPD2_Pos                (2U)
#define PMU_PDCRA_WKPD2_Msk                (0x1UL << PMU_PDCRA_WKPD2_Pos)                /*!< 0x00000004 */
#define PMU_PDCRA_WKPD2                    PMU_PDCRA_WKPD2_Msk                           /*!< Wakeup IO2 pull down status bit */
#define PMU_PDCRA_WKPD3_Pos                (3U)
#define PMU_PDCRA_WKPD3_Msk                (0x1UL << PMU_PDCRA_WKPD3_Pos)                /*!< 0x00000008 */
#define PMU_PDCRA_WKPD3                    PMU_PDCRA_WKPD3_Msk                           /*!< Wakeup IO3 pull down status bit */

/******************  Bit definition for PMU_EVSCR register  *******************/
#define PMU_EVSCR_VDCPVDSEL_Pos            (0U)
#define PMU_EVSCR_VDCPVDSEL_Msk            (0x3UL << PMU_EVSCR_VDCPVDSEL_Pos)            /*!< 0x00000003 */
#define PMU_EVSCR_VDCPVDSEL                PMU_EVSCR_VDCPVDSEL_Msk                       /*!< VDC-PVD threshold value select bit */
#define PMU_EVSCR_VDCPVDFILTER_Pos         (2U)
#define PMU_EVSCR_VDCPVDFILTER_Msk         (0x3UL << PMU_EVSCR_VDCPVDFILTER_Pos)         /*!< 0x0000000C */
#define PMU_EVSCR_VDCPVDFILTER             PMU_EVSCR_VDCPVDFILTER_Msk                    /*!< EVS pin filter select bit */
#define PMU_EVSCR_VDCPVDFILTER_0           (0x1UL << PMU_EVSCR_VDCPVDFILTER_Pos)         /*!< 0x00000004 */
#define PMU_EVSCR_VDCPVDFILTER_1           (0x2UL << PMU_EVSCR_VDCPVDFILTER_Pos)         /*!< 0x00000008 */

#define PMU_EVSCR_VDCPVDEN_Pos             (4U)
#define PMU_EVSCR_VDCPVDEN_Msk             (0x1UL << PMU_EVSCR_VDCPVDEN_Pos)             /*!< 0x00000010 */
#define PMU_EVSCR_VDCPVDEN                 PMU_EVSCR_VDCPVDEN_Msk                        /*!< EVS pin wakeup enable bit */
#define PMU_EVSCR_VDCPVDWKPEN_Pos          (5U)
#define PMU_EVSCR_VDCPVDWKPEN_Msk          (0x1UL << PMU_EVSCR_VDCPVDWKPEN_Pos)          /*!< 0x00000020 */
#define PMU_EVSCR_VDCPVDWKPEN              PMU_EVSCR_VDCPVDWKPEN_Msk                     /*!< EVS pin standby mode wakeup enable bit */

/******************  Bit definition for PMU_PVDCR register  *******************/
#define PMU_PVDCR_PVDEN_Pos                (4U)
#define PMU_PVDCR_PVDEN_Msk                (0x1UL << PMU_PVDCR_PVDEN_Pos)                /*!< 0x00000010 */
#define PMU_PVDCR_PVDEN                    PMU_PVDCR_PVDEN_Msk                           /*!< PVD enable bit */
#define PMU_PVDCR_PVDTHSEL_Pos             (5U)
#define PMU_PVDCR_PVDTHSEL_Msk             (0x7UL << PMU_PVDCR_PVDTHSEL_Pos)             /*!< 0x000000E0 */
#define PMU_PVDCR_PVDTHSEL                 PMU_PVDCR_PVDTHSEL_Msk                        /*!< PVD threshold select bit */

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup Exported_macros
  * @{
  */

/******************************* ADC Instances ********************************/
#define IS_ADC16_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == ADC1) || \
                                          ((INSTANCE) == ADC2))

#define IS_ADC12_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == ADC3)

/******************************** DMA Instances *******************************/
#define IS_DMA_STREAM_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == DMA1_Stream0) || \
                                              ((INSTANCE) == DMA1_Stream1) || \
                                              ((INSTANCE) == DMA1_Stream2) || \
                                              ((INSTANCE) == DMA1_Stream3) || \
                                              ((INSTANCE) == DMA1_Stream4) || \
                                              ((INSTANCE) == DMA1_Stream5) || \
                                              ((INSTANCE) == DMA1_Stream6) || \
                                              ((INSTANCE) == DMA1_Stream7))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == GPIO))

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == I2C1))

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == SPI1))

/****************** TMR Instances : All supported instances *******************/
#define IS_TMR_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                   ((INSTANCE) == TMR2) || \
                                   ((INSTANCE) == TMR3) || \
                                   ((INSTANCE) == TMR4))

/************* TMR Instances : at least 1 capture/compare channel *************/
#define IS_TMR_CC1_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/************ TMR Instances : at least 2 capture/compare channels *************/
#define IS_TMR_CC2_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/************ TMR Instances : at least 3 capture/compare channels *************/
#define IS_TMR_CC3_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/************ TMR Instances : at least 4 capture/compare channels *************/
#define IS_TMR_CC4_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/******************** TMR Instances : Advanced-control timers *****************/
#define IS_TMR_ADVANCED_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1))

/******************* TMR Instances : Timer input XOR function *****************/
#define IS_TMR_XOR_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/****************** TMR Instances : DMA requests generation (UDE) *************/
#define IS_TMR_DMA_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                       ((INSTANCE) == TMR2) || \
                                       ((INSTANCE) == TMR3) || \
                                       ((INSTANCE) == TMR4))

/************ TMR Instances : DMA requests generation (CCxDE) *****************/
#define IS_TMR_DMA_CC_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                          ((INSTANCE) == TMR2) || \
                                          ((INSTANCE) == TMR3) || \
                                          ((INSTANCE) == TMR4))

/************ TMR Instances : DMA requests generation (COMDE) *****************/
#define IS_TMR_CCDMA_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                          ((INSTANCE) == TMR2) || \
                                          ((INSTANCE) == TMR3) || \
                                          ((INSTANCE) == TMR4))

/******************** TMR Instances : DMA burst feature ***********************/
#define IS_TMR_DMABURST_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                             ((INSTANCE) == TMR2) || \
                                             ((INSTANCE) == TMR3) || \
                                             ((INSTANCE) == TMR4))

/****** TMR Instances : master mode available (TMRx_CR2.MMS available )********/
#define IS_TMR_MASTER_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1)  || \
                                          ((INSTANCE) == TMR2)  || \
                                          ((INSTANCE) == TMR3)  || \
                                          ((INSTANCE) == TMR4))

/*********** TMR Instances : Slave mode available (TMRx_SMCR available )*******/
#define IS_TMR_SLAVE_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                         ((INSTANCE) == TMR2) || \
                                         ((INSTANCE) == TMR3) || \
                                         ((INSTANCE) == TMR4))

/***************** TMR Instances : external trigger input available ************/
#define IS_TMR_ETR_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                        ((INSTANCE) == TMR2) || \
                                        ((INSTANCE) == TMR3) || \
                                        ((INSTANCE) == TMR4))

/****************** TMR Instances : remapping capability **********************/
#define IS_TMR_REMAP_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1))

/******************* TMR Instances : output(s) available **********************/
#define IS_TMR_CCX_INSTANCE(INSTANCE,  CHANNEL) \
    ((((INSTANCE) == TMR1) &&                  \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR2) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR3) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4)))           \
    ||                                         \
    (((INSTANCE) == TMR4) &&                   \
     (((CHANNEL) == TMR_CHANNEL_1) ||          \
      ((CHANNEL) == TMR_CHANNEL_2) ||          \
      ((CHANNEL) == TMR_CHANNEL_3) ||          \
      ((CHANNEL) == TMR_CHANNEL_4))))

/************ TMR Instances : complementary output(s) available ***************/
#define IS_TMR_CCXN_INSTANCE(INSTANCE,  CHANNEL) \
   ((((INSTANCE) == TMR1) &&                    \
     (((CHANNEL) == TMR_CHANNEL_1) ||           \
      ((CHANNEL) == TMR_CHANNEL_2) ||           \
      ((CHANNEL) == TMR_CHANNEL_3))))

/****************** TMR Instances : supporting counting mode selection ********/
#define IS_TMR_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                        ((INSTANCE) == TMR2) || \
                                                        ((INSTANCE) == TMR3) || \
                                                        ((INSTANCE) == TMR4))

/****************** TMR Instances : supporting clock division *****************/
#define IS_TMR_CLOCK_DIVISION_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1)  || \
                                                  ((INSTANCE) == TMR2) || \
                                                  ((INSTANCE) == TMR3) || \
                                                  ((INSTANCE) == TMR4))

/****************** TMR Instances : supporting commutation event generation ***/
#define IS_TMR_COMMUTATION_EVENT_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1))

/****************** TMR Instances : supporting OCxREF clear *******************/
#define IS_TMR_OCXREF_CLEAR_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                       ((INSTANCE) == TMR2) || \
                                                       ((INSTANCE) == TMR3) || \
                                                       ((INSTANCE) == TMR4))

/****** TMR Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TMR_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                        ((INSTANCE) == TMR2) || \
                                                        ((INSTANCE) == TMR3) || \
                                                        ((INSTANCE) == TMR4))

/****** TMR Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TMR_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                        ((INSTANCE) == TMR2) || \
                                                        ((INSTANCE) == TMR3) || \
                                                        ((INSTANCE) == TMR4))

/****** TMR Instances : supporting external clock mode 1 for TIX inputs ******/
#define IS_TMR_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                        ((INSTANCE) == TMR2) || \
                                                        ((INSTANCE) == TMR3) || \
                                                        ((INSTANCE) == TMR4))

/********** TMR Instances : supporting internal trigger inputs(ITRX) *********/
#define IS_TMR_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                        ((INSTANCE) == TMR2) || \
                                                        ((INSTANCE) == TMR3) || \
                                                        ((INSTANCE) == TMR4))

/****************** TMR Instances : supporting repetition counter *************/
#define IS_TMR_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1))

/****************** TMR Instances : supporting encoder interface **************/
#define IS_TMR_ENCODER_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                      ((INSTANCE) == TMR2) || \
                                                      ((INSTANCE) == TMR3) || \
                                                      ((INSTANCE) == TMR4))

/****************** TMR Instances : supporting Hall sensor interface **********/
#define IS_TMR_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1) || \
                                                          ((INSTANCE) == TMR2) || \
                                                          ((INSTANCE) == TMR3) || \
                                                          ((INSTANCE) == TMR4))

/****************** TMR Instances : supporting the break function *************/
#define IS_TMR_BREAK_INSTANCE(INSTANCE)  (((INSTANCE) == TMR1))

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                     ((INSTANCE) == USART2))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                               ((INSTANCE) == USART2))

/* Legacy defines */
#define IS_UART_INSTANCE  IS_UART_HALFDUPLEX_INSTANCE

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                           ((INSTANCE) == USART2))
/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE  IS_UART_HALFDUPLEX_INSTANCE

/********************* UART Instances : Smart card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                         ((INSTANCE) == USART2))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE)  (((INSTANCE) == USART1) || \
                                    ((INSTANCE) == USART2))

/****************************** IWDT Instances ********************************/
#define IS_IWDT_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDT)

/****************************** WWDT Instances ********************************/
#define IS_WWDT_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == WWDT)

/****************************** COMP Instances ********************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == COMP1) || \
                                            ((INSTANCE) == COMP2) || \
                                            ((INSTANCE) == COMP3) || \
                                            ((INSTANCE) == COMP4))

/****************************** DAC Instances ********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == DAC1) || \
                                           ((INSTANCE) == DAC2))

/*
 * @brief Specific devices reset values definitions
 */
#define RCM_PLLCR_RST_VALUE                0x0000000U

#define RCM_MAX_FREQUENCY                  120000000U                                    /*!< Max frequency of family in Hz*/
#define RCM_MAX_FREQUENCY_SCALE1           RCM_MAX_FREQUENCY                             /*!< Maximum frequency for system clock at power scale1, in Hz */
#define RCM_MAX_FREQUENCY_SCALE2           84000000U                                     /*!< Maximum frequency for system clock at power scale2, in Hz */
#define RCM_MAX_FREQUENCY_SCALE3           64000000U                                     /*!< Maximum frequency for system clock at power scale3, in Hz */
#define RCM_PLLVCO_OUTPUT_MIN              100000000U                                    /*!< Frequency min for PLLVCO output, in Hz */
#define RCM_PLLVCO_INPUT_MIN               950000U                                       /*!< Frequency min for PLLVCO input, in Hz  */
#define RCM_PLLVCO_INPUT_MAX               2100000U                                      /*!< Frequency max for PLLVCO input, in Hz  */
#define RCM_PLLVCO_OUTPUT_MAX              432000000U                                    /*!< Frequency max for PLLVCO output, in Hz */

#define RCM_PLL1A_MIN_VALUE                50U
#define RCM_PLL1A_MAX_VALUE                432U

#define FLASH_SCALE1_LATENCY1_FREQ         30000000U                                     /*!< HCLK frequency to set FLASH latency 1 in power scale 1  */
#define FLASH_SCALE1_LATENCY2_FREQ         64000000U                                     /*!< HCLK frequency to set FLASH latency 2 in power scale 1  */
#define FLASH_SCALE1_LATENCY3_FREQ         90000000U                                     /*!< HCLK frequency to set FLASH latency 3 in power scale 1  */
#define FLASH_SCALE1_LATENCY4_FREQ         120000000U                                    /*!< HCLK frequency to set FLASH latency 4 in power scale 1  */

#define FLASH_SCALE2_LATENCY1_FREQ         30000000U                                     /*!< HCLK frequency to set FLASH latency 1 in power scale 2  */
#define FLASH_SCALE2_LATENCY2_FREQ         64000000U                                     /*!< HCLK frequency to set FLASH latency 2 in power scale 2  */

#define FLASH_SCALE3_LATENCY1_FREQ         30000000U                                     /*!< HCLK frequency to set FLASH latency 1 in power scale 2  */
#define FLASH_SCALE3_LATENCY2_FREQ         64000000U                                     /*!< HCLK frequency to set FLASH latency 2 in power scale 2  */

/******************************************************************************/
/*  For a painless codes migration between the G32R430 device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same G32R4 Family                              */
/******************************************************************************/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __G32R430_H */

