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

The program to show how to configure the TMR2 peripheral to generate 4 different 
signals with four different delays.

  - TMR2 frequency = 120 MHz / (119 + 1) = 1 MHz
  - TMR2 CH1 pulse = 800
  - TMR2 CH1 delay = 800/1MHz = 800us
  - TMR2 CH2 pulse = 600
  - TMR2 CH2 delay = 600/1MHz = 600us
  - TMR2 CH3 pulse = 400
  - TMR2 CH3 delay = 400/1MHz = 400us
  - TMR2 CH4 pulse = 200
  - TMR2 CH4 delay = 200/1MHz = 200us

While the counter is lower than the Output Compare Register (CCR) values, 
the PC1, PC2, PC3, and PC4 pins remain unchanged.

When the counter value matches the Output Compare Register (CCR) values, 
an interrupt is triggered, and the corresponding PC1, PC2, PC3, or PC4 pin toggles its state.

The CHx delay corresponds to the time difference between the rising edge and the falling edge of the PCx pin, 
which is determined by the configured delay (800 μs for PC1, 600 μs for PC2, 400 μs for PC3, and 200 μs for PC4).

Reset the system and observe the waveforms of PC1, PC2, PC3, and PC4 using an oscilloscope.

&par Hardware Description

  - using TMR2 Channel 1 (PA0) to output signal
  - using TMR2 Channel 2 (PA1) to output signal
  - using TMR2 Channel 3 (PA2) to output signal
  - using TMR2 Channel 4 (PA3) to output signal

&par Directory contents

  - TMR/TMR_OCInactive/Source/main.c                               Main program implementing the test
  - TMR/TMR_OCInactive/Source/g32r4xx_int.c                        Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.
  - Note: On G32R430 TINY Board, J10 selects whether PA1/PA2 connect to
    LED1/LED2 or the external header. Check the J10 jumper before use.
