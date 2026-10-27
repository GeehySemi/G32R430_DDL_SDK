/**
 * @file        g32r430xx_flash.ld
 *
 * @brief       Linker script for G32R430xx series
 *              128Kbytes FLASH, 48KByte RAM
 *
 * @version     V1.0.0
 *
 * @date        2025-12-30
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

/*--------------------- Flash Configuration ----------------------------------
; <h> Flash Configuration
;   <o0> Flash Base Address <0x0-0xFFFFFFFF:8>
;   <o1> Flash Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
----------------------------------------------------------------------------*/
__ROM_BASE = 0x08000000;
__ROM_SIZE = 0x00020000;

/*--------------------- Embedded RAM Configuration ---------------------------
; <h> ITCM Configuration
;   <o0> ITCM Base Address    <0x0-0xFFFFFFFF:8>
;   <o1> ITCM Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

; <h> DTCM Configuration
;   <o3> DTCM Base Address    <0x0-0xFFFFFFFF:8>
;   <o4> DTCM Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
----------------------------------------------------------------------------*/
__ITCM_BASE = 0x00000000;
__ITCM_SIZE = 0x00008000;  /* 32KB ITCM */

__DTCM_BASE = 0x20000000;
__DTCM_SIZE = 0x00004000;  /* 16KB DTCM */

/*--------------------- Stack / Heap Configuration ---------------------------
; <h> Stack / Heap Configuration
;   <o0> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;   <o1> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>
----------------------------------------------------------------------------*/
__STACK_SIZE = 0x00001000;
__HEAP_SIZE = 0x00000200;

/*
 *-------------------- <<< end of configuration section >>> -------------------
 */

__VECTOR_SIZE = 0x00000100;

/* ARMv8-M stack sealing:
   to use ARMv8-M stack sealing set __STACKSEAL_SIZE to 8 otherwise keep 0
 */
__STACKSEAL_SIZE = 8;

MEMORY
{
  FLASH (rx)     : ORIGIN = __ROM_BASE, LENGTH =  __ROM_SIZE

  /*
   * If the interrupt vector table is placed in FLASH,
   * uncomment the lines below:
   *
   *  ITCM_RAM (rwx) : ORIGIN = __ITCM_BASE, LENGTH = __ITCM_SIZE
   *  DTCM_RAM (rwx) : ORIGIN = __DTCM_BASE, LENGTH = __DTCM_SIZE
   *
   * and comment out the following lines for splitting DTCM/ITCM.
   */
/*
  ITCM_RAM (rwx) : ORIGIN = __ITCM_BASE, LENGTH = __ITCM_SIZE
  DTCM_RAM (rwx) : ORIGIN = __DTCM_BASE, LENGTH = __DTCM_SIZE
*/

  /*
   * By default, we split DTCM into two parts:
   *  1) VECTOR_RAM (0x100 bytes)
   *  2) DTCM_RAM (the remaining space)
   *
   * Note: If the interrupt vector table is placed in DTCM,
   *       uncomment the lines below and modify your startup code
   *       to set VTOR = VECTOR_RAM base address.
   */
  ITCM_RAM (rwx) : ORIGIN = __ITCM_BASE, LENGTH = __ITCM_SIZE
  DTCM_RAM (rwx) : ORIGIN = __DTCM_BASE + __VECTOR_SIZE, LENGTH = __DTCM_SIZE -__VECTOR_SIZE
  VECTOR_RAM (rwx) : ORIGIN = __DTCM_BASE , LENGTH = __VECTOR_SIZE

  /*
   *  If the interrupt vector table is placed in ITCM,
   *  we split ITCM into two parts:
   *  1) VECTOR_RAM (0x100 bytes)
   *  2) ITCM_RAM (the remaining space)
   *
   * Note: If the interrupt vector table is placed in ITCM,
   *       uncomment the lines below and modify your startup code
   *       to set VTOR = VECTOR_RAM base address.
   */
/*
  ITCM_RAM (rwx) : ORIGIN = __ITCM_BASE + __VECTOR_SIZE, LENGTH = __ITCM_SIZE - __VECTOR_SIZE
  DTCM_RAM (rwx) : ORIGIN = __DTCM_BASE, LENGTH = __DTCM_SIZE
  VECTOR_RAM (rwx) : ORIGIN = __ITCM_BASE , LENGTH = __VECTOR_SIZE
 */
}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __copy_table_start__
 *   __copy_table_end__
 *   __zero_table_start__
 *   __zero_table_end__
 *   __etext          (deprecated)
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 *   __StackSeal      (only if ARMv8-M stack sealing is used)
 */
ENTRY(Reset_Handler)

SECTIONS
{
  .text :
  {
    KEEP(*(.vectors))
    *(.text*)

    KEEP(*(.init))
    KEEP(*(.fini))

    /* .ctors */
    *crtbegin.o(.ctors)
    *crtbegin?.o(.ctors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
    *(SORT(.ctors.*))
    *(.ctors)

    /* .dtors */
    *crtbegin.o(.dtors)
    *crtbegin?.o(.dtors)
    *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
    *(SORT(.dtors.*))
    *(.dtors)

    *(.rodata*)

    KEEP(*(.eh_frame*))
  } > FLASH

  /*
   * SG veneers:
   * All SG veneers are placed in the special output section .gnu.sgstubs. Its start address
   * must be set, either with the command line option '--section-start' or in a linker script,
   * to indicate where to place these veneers in memory.
   */
/*
  .gnu.sgstubs :
  {
    . = ALIGN(32);
  } > FLASH
*/
  .ARM.extab :
  {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > FLASH

  __exidx_start = .;
  .ARM.exidx :
  {
    *(.ARM.exidx* .gnu.linkonce.armexidx.*)
  } > FLASH
  __exidx_end = .;

  .copy.table :
  {
    . = ALIGN(4);
    __copy_table_start__ = .;

    LONG (LOADADDR(.data))
    LONG (ADDR(.data))
    LONG (SIZEOF(.data) / 4)

    LONG (LOADADDR(.itcm_custom_section))
    LONG (ADDR(.itcm_custom_section))
    LONG (SIZEOF(.itcm_custom_section) / 4)

    LONG (LOADADDR(.dtcm.data))
    LONG (ADDR(.dtcm.data))
    LONG (SIZEOF(.dtcm.data) / 4)

    /* Add each additional data section here */
/*
    LONG (LOADADDR(.data2))
    LONG (ADDR(.data2))
    LONG (SIZEOF(.data2) / 4)
*/
    __copy_table_end__ = .;
  } > FLASH

  .zero.table :
  {
    . = ALIGN(4);
    __zero_table_start__ = .;

    LONG (ADDR(.bss))
    LONG (SIZEOF(.bss) / 4)

    LONG (ADDR(.dtcm.bss))
    LONG (SIZEOF(.dtcm.bss) / 4)

    /* Add each additional bss section here */
/*
    LONG (ADDR(.bss2))
    LONG (SIZEOF(.bss2) / 4)
*/
    __zero_table_end__ = .;
  } > FLASH

  /*
   * This __etext variable is kept for backward compatibility with older,
   * ASM based startup files.
   */
  PROVIDE(__etext = LOADADDR(.data));

  .data : ALIGN(4)
  {
    __data_load__ = LOADADDR(.data);
    __data_start__ = .;
    *(vtable)
    *(.data)
    *(.data.*)

    . = ALIGN(4);
    /* preinit data */
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP(*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);

    . = ALIGN(4);
    /* init data */
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array))
    PROVIDE_HIDDEN (__init_array_end = .);

    . = ALIGN(4);
    /* finit data */
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP(*(SORT(.fini_array.*)))
    KEEP(*(.fini_array))
    PROVIDE_HIDDEN (__fini_array_end = .);

    KEEP(*(.jcr*))
    . = ALIGN(4);
    /* All data end */
    __data_end__ = .;

  } > DTCM_RAM AT > FLASH
  /*
   * Secondary data section, optional
   *
   * Remember to add each additional data section
   * to the .copy.table above to assure proper
   * initialization during startup.
   */
/*
  .data2 : ALIGN(4)
  {
    . = ALIGN(4);
    __data2_start__ = .;
    *(.data2)
    *(.data2.*)
    . = ALIGN(4);
    __data2_end__ = .;

  } > RAM2 AT > FLASH
*/

  .bss :
  {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss)
    *(.bss.*)
    *(COMMON)
    . = ALIGN(4);
    __bss_end__ = .;
  } > DTCM_RAM AT > DTCM_RAM

  /*
   * Secondary bss section, optional
   *
   * Remember to add each additional bss section
   * to the .zero.table above to assure proper
   * initialization during startup.
   */
/*
  .bss2 :
  {
    . = ALIGN(4);
    __bss2_start__ = .;
    *(.bss2)
    *(.bss2.*)
    . = ALIGN(4);
    __bss2_end__ = .;
  } > RAM2 AT > RAM2
*/

  .itcm_custom_section :
  {
    . = ALIGN(4);
    __itcm_custom_section_start__ = .;
    *(itcm.instruction)
    *(itcm.ramfunc)
    *(atan2_instruction)
    . = ALIGN(4);
    __itcm_custom_section_end__ = .;
  } > ITCM_RAM AT > FLASH

  .dtcm.data :
  {
    . = ALIGN(4);
    __dtcm_data_start__ = .;
    *(dtcm.data)
    . = ALIGN(4);
    __dtcm_data_end__ = .;
  } > DTCM_RAM AT > FLASH

  .dtcm.bss (NOLOAD) :
  {
    . = ALIGN(4);
    __dtcm_bss_start__ = .;
    *(dtcm.bss)
    . = ALIGN(4);
    __dtcm_bss_end__ = .;
  } > DTCM_RAM AT > DTCM_RAM

 /* ========================================================================
  * If the interrupt vector table is placed in ITCM or DTCM,
  * you can enable the following section (ram.intvec) by uncommenting it.
  * Also ensure that your startup code sets VTOR to this section's address.
  * ========================================================================
  */
  ram.intvec (NOLOAD) :
  {
    . = ALIGN(4);
    __ram_intvec_start__ = .;
    *(bss.ram.intvec)
    . = ALIGN(4);
    __ram_intvec_end__ = .;
  } > VECTOR_RAM AT > VECTOR_RAM

  .heap (NOLOAD) :
  {
    . = ALIGN(8);
    __end__ = .;
    __heap_start = .;
    PROVIDE(end = .);
    PROVIDE(__heap_start = .);
    . = . + __HEAP_SIZE;
    . = ALIGN(8);
    __heap_end = .;
    PROVIDE(__heap_end = .);
    __HeapLimit = .;
  } > DTCM_RAM

  .stack (ORIGIN(DTCM_RAM) + LENGTH(DTCM_RAM) - __STACK_SIZE - __STACKSEAL_SIZE) (NOLOAD) :
  {
    . = ALIGN(8);
    __StackLimit = .;
    PROVIDE(__stack_limit = .);
    . = . + __STACK_SIZE;
    . = ALIGN(8);
    __StackTop = .;
  } > DTCM_RAM
  PROVIDE(__stack = __StackTop);


  /* ARMv8-M stack sealing:
     to use ARMv8-M stack sealing uncomment '.stackseal' section
   */
/*
  .stackseal (ORIGIN(RAM) + LENGTH(RAM) - __STACKSEAL_SIZE) (NOLOAD) :
  {
    . = ALIGN(8);
    __StackSeal = .;
    . = . + 8;
    . = ALIGN(8);
  } > RAM
*/

  /* Check if data + heap + stack exceeds RAM limit */
  ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}
