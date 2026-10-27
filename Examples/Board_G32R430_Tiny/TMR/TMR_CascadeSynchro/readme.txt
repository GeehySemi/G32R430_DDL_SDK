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

- cascade mode:
  - TMR2 Master for TMR3,Config PWM Mode and TMR2 Update event is used as Trigger Output
  - TMR3 is slave for TMR2 and Master for TMR4,
  - Config PWM Mode and TMR3 Update event is used as Trigger Output
  - The ITR1(TMR2) is used as input trigger 
  - TMR4 is slave for TMR3,
  - Config PWM Mode
  - The ITR2(TMR3) is used as input trigger

  - The Master Timer TMR2 frequency :
  - duty cycle = 64/(127 + 1) = 50%.

  - The TMR3 is running at:
  - duty cycle = 2/(3 + 1) = 50%

  - The TMR4 is running at:
  - duty cycle = 1/(1 + 1) = 50%  

&par Hardware Description

  - using TMR2 CHANNEL1(PC4) to output PWM
  - using TMR3 CHANNEL1(PB2) to output PWM
  - using TMR4 CHANNEL1(PC6) to output PWM

&par Directory contents

  - TMR/TMR_CascadeSynchro/Source/main.c                           Main program implementing the test
  - TMR/TMR_CascadeSynchro/Source/g32r4xx_int.c                    Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.