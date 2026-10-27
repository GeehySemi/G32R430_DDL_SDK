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

This example demonstrates how to synchronize TMR1, TMR2, and TMR3 peripherals in
cascade mode with an external trigger. The configuration details are as follows:

    TMR1:
    - Configured as the master timer for TMR2.
    - Operates in Toggle Mode.
    - Generates a trigger output event when enabled.
    - The output waveform frequency is 500 kHz with a 50% duty cycle.
    - The output is active only when the input signal on PD5 is high.

    TMR2:
    - Configured as a slave for TMR1 and a master for TMR3.
    - Operates in Toggle Mode.
    - Generates a trigger output event when enabled.
    - Uses ITR0 (TMR1) as the input trigger.
    - The output waveform frequency is 250 kHz with a 50% duty cycle.

    TMR3:
    - Configured as a slave for TMR2.
    - Operates in Toggle Mode.
    - Uses ITR1 (TMR2) as the input trigger.
    - The output waveform frequency is 125 kHz with a 50% duty cycle.

The synchronization ensures that TMR2 and TMR3 operate in a cascaded manner, with TMR1
as the primary trigger source. The output waveforms are generated only when the input
signal on PD5 is high.

&par Hardware Description
  - TMR1 Channel 1  (PD1)
  - TMR1 Channel 2  (PD5)
  - TMR2 Channel 1  (PC4)
  - TMR3 Channel 2  (PC1)

&par Directory contents

  - TMR/TMR_ExtTriggerSynchro/Source/main.c                        Main program implementing the test
  - TMR/TMR_ExtTriggerSynchro/Source/g32r4xx_int.c                 Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.