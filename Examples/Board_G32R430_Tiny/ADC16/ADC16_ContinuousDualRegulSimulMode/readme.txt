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

This example demonstrates how to perform simultaneous sampling and continuous
conversion on two channels using a dual ADC setup. The code configures ADC1
and ADC2 to carry out conversions in parallel, then merges both results into
a single 32-bit data. By reading and splitting this data, the individual ADC1
and ADC2 values are obtained and printed out via a serial port.

&par Hardware Description

using ADC1_Channel1(PA1)
using ADC2_Channel1(PA5)

Reminder: When using PA1/PA5, ensure that the corresponding jumpers on the J10 
header of the TINY board are properly connected.

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

  - ADC16/ADC16_ContinuousDualRegulSimulMode/Source/main.c         Main program implementing the test
  - ADC16/ADC16_ContinuousDualRegulSimulMode/Source/g32r4xx_int.c  Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1/PA2/PA5 connect to
    LED1/LED2/KEY1 or the external header. Check the J10 jumper before use.
