/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
 *
 * @version     V1.0.1
 *
 * @date        2026-08-16
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

&par Example Description

This example demonstrates I2C master page write/read to the onboard EEPROM
on G32R430 Tiny Board.

Flow:
  1. Fill a 32-byte buffer (0..31) and write one page at word address 0x0000.
  2. After STOP, poll device address ACK to wait for EEPROM internal write (tWR).
  3. Read the same page back and compare.
  4. Success: LED2 on, UART prints "Read/Write Success".
     Failure: LED1 on (write ACK timeout / read fail / compare mismatch).

I2C is configured for Fast mode 400 kHz (PCLK = 120 MHz).

&par Hardware Description

  Board: G32R430 Tiny
  EEPROM: ZD24C64A (IC6), 64-Kbit (8K x 8)
  - Device address (8-bit write): 0xA0 (7-bit 0x50)
  - Word address: 2 bytes (A12..A0)
  - Page size: 32 bytes (do not exceed one page per WritePage STOP)

  I2C1
  SCL      PD5 (AF0)
  SDA      PD9 (AF0)

USART2_TX(PD0)
USART2_RX(PC12)

  - USART2 configured as follow:
  - BaudRate = 115200
  - Word Length = USART_WordLength_8b
  - Stop Bit = USART_StopBits_1
  - Parity = USART_Parity_No
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled

&par Directory contents

  - I2C/I2C_EEPROM/Source/main.c                                   Main program implementing the test
  - I2C/I2C_EEPROM/Source/g32r4xx_int.c                            Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 &  clang version 19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1/PA2 connect to
    LED1/LED2 or the external header. Check the J10 jumper before use.

