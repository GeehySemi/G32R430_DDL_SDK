/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
 *
 * @version     V1.0.0
 *
 * @date        2025-11-01
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

This example demonstrates RS485 communication using USART1, supporting both data transmission and reception.
During execution, the development board sends a prompt message via USART1, asking the user to input content.
The user sends data from the PC, and the development board echoes the received content back.

&par Hardware Description

USART1_TX (PB9): Used for data transmission
USART1_RX (PB6): Used for data reception
USART1_DE (PB11): Used to control RS485 transmit/receive mode

  - USART1 configured as follow:
  - BaudRate = 115200
  - Word Length = USART_WordLength_8b
  - Stop Bit = USART_StopBits_1
  - Parity = USART_Parity_No
  - Hardware flow control disabled (RTS and CTS signals)
  - Receive and transmit enabled

PC (USB) ----> USB-to-RS485 Module ----> Development Board
                A (RS485)         ---->   A (RS485)
                B (RS485)         ---->   B (RS485)
                GND (RS485)       ---->   GND (RS485)

&par Directory contents

  - USART/USART_RS485/Source/main.c                                Main program implementing the test
  - USART/USART_RS485/Source/g32r4xx_int.c                         Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.