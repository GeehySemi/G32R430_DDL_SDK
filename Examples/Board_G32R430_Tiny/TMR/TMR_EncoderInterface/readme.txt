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

This example demonstrates how to configure the TMR1 peripheral in Encoder Mode  
to obtain position and rotation direction from a standard incremental rotary encoder.

  - TMR1 is configured for Encoder Mode X4 (TI12).  
  - Channel 1 (PD1) is connected to the encoder signal “CLK/A”.  
  - Channel 2 (PD5) is connected to the encoder signal “DT/B”.  
  - The counter is pre-loaded with 32 767, then increases or decreases according
    to the encoder rotation.  
  - TMR2 is set to generate an update interrupt every 1 ms (1 kHz).  

&par Hardware Description

Rotary Encoder wiring  
  CLK / A-phase → PD1 (TMR1_CH1)  
  DT  / B-phase → PD5 (TMR1_CH2)  
  VCC → 3.3 V
  GND → GND

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

  - TMR/TMR_EncoderInterface/Source/main.c                         Main program implementing the test
  - TMR/TMR_EncoderInterface/Source/g32r4xx_int.c                  Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA2 connects to
    LED2 or the external header. Check the J10 jumper before use.
