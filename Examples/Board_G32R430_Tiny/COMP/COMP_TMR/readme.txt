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

This example demonstrates hardware-based signal monitoring by linking a comparator (COMP)
with a timer (TMR1). The comparator is configured to compare two analog input voltages,
with its inverted output routed to the timer's external trigger input (ETR). When the
comparator detects a condition (e.g., the positive input voltage is greater or less than
the negative input voltage), it automatically controls the timer's operation. Additionally,
LEDs are toggled based on the comparator's output state, providing a visual indication of
the comparison result. The timer counter value is also periodically printed for monitoring
purposes.

&par Hardware Description

using COMP1+(PD12) COMP1-(PD11)

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

  - COMP/COMP_TMR/Source/main.c                                    Main program implementing the test
  - COMP/COMP_TMR/Source/g32r4xx_int.c                             Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 &  clang version 19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1/PA2 connect to
    LED1/LED2 or the external header. Check the J10 jumper before use.
