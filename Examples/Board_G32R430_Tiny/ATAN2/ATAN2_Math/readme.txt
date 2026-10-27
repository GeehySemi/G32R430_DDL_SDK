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

This example demonstrates how to compare a hardware-accelerated custom ATAN2
function with the standard atan2 function in terms of performance and accuracy.
An Atan2CompareResult structure stores angles, reference angles, absolute error,
and cycle counts for both CDE (hardware) and reference approaches.
In RunArctan2Comparison, various angles are generated and converted into Q30
fixed-point format. Both the standard atan2 and a hardware-accelerated ATAN2
calculation (with precision level) are performed, and their floating-point
results are compared. This benchmark quantifies the speed and precision of the
hardware-accelerated solution for angle computations.

&par Directory contents

  - ATAN2/ATAN2_Math/Source/main.c                                 Main program implementing the test
  - ATAN2/ATAN2_Math/Source/g32r4xx_int.c                          Interrupt handlers

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 &  clang version 19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.