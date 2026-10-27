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

This example demonstrates how to use the Low-Power Timer (LPTMR) for timeout-based 
wake-up. The program initializes the LPTMR, setting a suitable prescaler and timeout 
value so that the system can automatically wake up from low power mode via an LPTMR 
interrupt. In the code, the system first prints a message and then calls __WFI() 
to enter low power mode. Once the LPTMR times out, it triggers an interrupt that 
wakes the system, after which the program prints a follow-up message to confirm 
the wake-up process.

Note: After downloading the program, please power cycle the system before testing
this example to ensure correct behavior.

&par Hardware Description

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

  - LPTMR/LPTMR_Timeout/Source/main.c                              Main program implementing the test
  - LPTMR/LPTMR_Timeout/Source/g32r4xx_int.c                       Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.