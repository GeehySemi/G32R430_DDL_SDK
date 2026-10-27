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

This example demonstrates how to perform a single-conversion mode using two 
ADC modules simultaneously. Both ADC1 and ADC2 are triggered via software to 
start conversion at the same time. The results from both ADCs are merged into 
a 32-bit register on ADC1, where the lower 16 bits represent ADC1's result 
and the upper 16 bits represent ADC2's result.

In the main loop, the 32-bit result is read, split into two 16-bit values 
corresponding to ADC1 and ADC2, and displayed. Afterward, a new conversion 
is triggered via software to enable repeated sampling. This example is 
designed to showcase single-shot dual ADC sampling.

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

  - ADC16/ADC16_DualRegulSimulMode/Source/main.c                   Main program implementing the test
  - ADC16/ADC16_DualRegulSimulMode/Source/g32r4xx_int.c            Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1/PA2/PA5 connect to
    LED1/LED2/KEY1 or the external header. Check the J10 jumper before use.
