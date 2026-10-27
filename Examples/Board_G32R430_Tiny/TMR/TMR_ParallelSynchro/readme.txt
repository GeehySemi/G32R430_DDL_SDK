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

This example demonstrates how to synchronize TMR peripherals in parallel mode.

- Parallel Mode Configuration:
  - TMR2 acts as the Master Timer for TMR3 and TMR4.
  - TMR2 is configured in PWM Mode, and its Update Event is used as the Trigger Output (TRGO).
  - TMR3 and TMR4 are configured as Slave Timers for TMR2.

- TMR2 Configuration:
  - TMR2 is the Master Timer.
  - Configured in PWM Mode.
  - Generates an Update Event as the Trigger Output (TRGO).
  - The TMR2 peripheral clock frequency is 120 MHz.
  - TMR2 PWM frequency = 120 MHz / (95 + 1) = 1.25 MHz.
  - Duty cycle = 48 / (95 + 1) = 50%.

- TMR3 Configuration:
  - TMR3 is a Slave Timer triggered by TMR2's Update Event (TRGO).
  - Configured in PWM Mode.
  - The input trigger source is ITR1 (TMR2 TRGO).
  - TMR3 PWM frequency = 1.25 MHz / (3 + 1) = 312.5 kHz.
  - Duty cycle = 2 / (3 + 1) = 50%.

- TMR4 Configuration:
  - TMR4 is a Slave Timer triggered by TMR2's Update Event (TRGO).
  - Configured in PWM Mode.
  - The input trigger source is ITR1 (TMR2 TRGO).
  - TMR4 PWM frequency = 1.25 MHz / (1 + 1) = 625 kHz.
  - Duty cycle = 1 / (1 + 1) = 50%.

&par Hardware Description

  - using TMR2 CHANNEL1(PC4) to output PWM
  - using TMR3 CHANNEL1(PB2) to output PWM
  - using TMR4 CHANNEL1(PC6) to output PWM

&par Directory contents

  - TMR/TMR_ParallelSynchro/Source/main.c                          Main program implementing the test
  - TMR/TMR_ParallelSynchro/Source/g32r4xx_int.c                   Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.