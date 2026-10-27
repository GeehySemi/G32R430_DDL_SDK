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

The program demonstrates how to use DMA-Burst to transfer six 16-bit words
from memory to the TMR1 Auto-Reload Register (ARR) so that the PWM
frequency changes automatically on every Update event while the CPU
stays idle.

After each Update request, the next ARR value is loaded and the output
frequency steps through six levels while the duty-cycle changes
accordingly:

  ┌─────────┬────────────┬────────────┐
  │   ARR   │ Frequency  │ Duty Cycle │
  ├─────────┼────────────┼────────────┤
  │  9999   │  100 Hz    │   0.50 %   │
  │  4999   │  200 Hz    │   1.00 %   │
  │  2499   │  400 Hz    │   2.00 %   │
  │  1249   │  800 Hz    │   4.00 %   │
  │   624   │  1.6 kHz   │   8.00 %   │
  │   311   │  3.2 kHz   │  16.00 %   │
  └─────────┴────────────┴────────────┘

Duty-cycle (%) = CCR / (ARR + 1) × 100  ➜ because CCR is fixed (50),
a lower ARR leads to a higher duty-cycle.

Display the complementary outputs with an oscilloscope to observe the
six-step sequence.

&par Hardware Description

  - TMR1 Channel 1   (PD1)   ➜ PWM high side
  - TMR1 Channel 1N  (PD2)   ➜ PWM low  side
  - TMR1 Channel 2   (PD5)   ➜ PWM high side
  - TMR1 Channel 2N  (PD8)   ➜ PWM low  side
  - TMR1 Channel 3   (PD9)   ➜ PWM high side
  - TMR1 Channel 3N  (PD10)  ➜ PWM low  side
  - TMR1 Channel 4   (PD3)   ➜ PWM high side
  

&par Directory contents

  - TMR/TMR_DMABurst/Source/main.c                                 Main program implementing the test
  - TMR/TMR_DMABurst/Source/g32r4xx_int.c                          Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.