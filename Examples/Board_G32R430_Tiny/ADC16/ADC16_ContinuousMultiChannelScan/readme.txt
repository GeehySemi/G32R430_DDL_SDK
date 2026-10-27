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

This example illustrates how to configure the ADC16 for multi-channel scan mode
and leverage DMA to achieve continuous sampling and rapid data retrieval of
multiple analog signals. After initializing USART for output, the DMA setup
is used to automatically transfer conversion results to a memory buffer.
In the main loop, the EOC flag indicates when each batch of conversions is complete,
and a multi-channel polling function is called to compute and display the voltage
values for each channel. 

&par Hardware Description

using ADC1_Channel 0 (ADC1_DP0)
using ADC1_Channel 1 (PA1)
using ADC1_Channel 3 (ADC1_DN0)

Reminder: When using PA1, ensure that the corresponding jumpers on the J10 header of
the TINY board are properly connected.


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

  - ADC16/ADC16_ContinuousMultiChannelScan/Source/main.c           Main program implementing the test
  - ADC16/ADC16_ContinuousMultiChannelScan/Source/g32r4xx_int.c    Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1 connects to
    LED1 or the external header. Check the J10 jumper before use.
