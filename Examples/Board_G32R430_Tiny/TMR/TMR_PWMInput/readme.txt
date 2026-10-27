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

This demonstration generates a 10 kHz / 50 % PWM signal on TMR1_CH1 (PD1) 
and measures its frequency and duty-cycle with TMR2 in PWM-Input mode (PA1).

TMR2_CC2Isr Function to calculate:
DutyCycle =  (TMR2_CC1*100)/(TMR2_CC2)  %.
Frequency = (RCM_Clocks.HCLK_Frequency/2) / (TMR2_CC2) Hz.
The minimum frequency value to measure is 1 Hz. 

Reminder: When using PA1, ensure that the corresponding jumpers on the J10
header of the TINY board are properly connected.

&par Hardware Description
  - using TMR1 Channel_1 (PD1) to output PWM
  - using TMR2 Channel_2 (PA1) to input PWM

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

  - TMR/TMR_PWMInput/Source/main.c                                 Main program implementing the test
  - TMR/TMR_PWMInput/Source/g32r4xx_int.c                          Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1 connects to
    LED1 or the external header. Check the J10 jumper before use.
