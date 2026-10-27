/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
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

&par Example Description

This example also describes a polling-based mode,
where the program repeatedly checks the I2C status in the main loop instead,
again allowing selection of Master or Slave roles through project tags.
The SCL and SDA lines (PD5 and PD9) with external pull-ups remain the same,
but now the software directly manages sending and receiving data without interrupts or DMA.
Upon receiving data, the program likewise prints it over UART (printf)
for easy observation and debugging.

&par Hardware Description

   I2C     BOARD1       BOARD2
   SCL      PD5         PD5         (External Pull up resistance)
   SDA      PD9         PD9         (External Pull up resistance)

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

  - I2C/I2C_TwoBoardspolling/Source/main.c                         Main program implementing the test
  - I2C/I2C_TwoBoardspolling/Source/g32r4xx_int.c                  Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 &  clang version 19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
