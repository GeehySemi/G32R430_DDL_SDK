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

The example aims to show how to configure a bootloader firmware to IAP.
When device connect to HyperTerminal right, a usart menu will show to user.
The menu as follow:

***************************************************************
*      G32R430 In-Application Programming Application         *
*                                              (Version 1.0.0)*
***************************************************************

** Please select an operation item
*  1.Download Flash application 1 -----------------------> 1  *
*  2.Upload Flash application 1   -----------------------> 2  *
*  3.Jump to user application 1   -----------------------> 3  *
*  4.Download Flash application 2 -----------------------> 4  *
*  5.Upload Flash application 2   -----------------------> 5  *
*  6.Jump to user application 2   -----------------------> 6  *
***************************************************************

Flash ROM Space:
 - IAP_Bootloader       0x08000000 - 0x08005FFF
 - IAP_Application1     0x08006000 - 0x08007FFF
 - IAP_Application2     0x08008000 - 0x08009FFF

note:

Before using the IAP function, you must download the bootloader program to the target board.  
Then compile the "IAP_Application1" or "IAP_Application2" project, and update the generated bin  
firmware file to the target board using the IAP function through the HyperTerminal tool.  
The firmware file transfer is performed using the YMODEM protocol.

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

  - IAP/IAP_Bootloader/Source/main.c                                Main program implementing the test
  - IAP/IAP_Bootloader/Source/g32r4xx_int.c                         Interrupt handlers
  - IAP/IAP_Bootloader/Source/iap_common.c                          Common module for IAP, providing utility functions and shared logic
  - IAP/IAP_Bootloader/Source/iap_flash.c                           Flash operation module for IAP, handling Flash read/write operations
  - IAP/IAP_Bootloader/Source/iap_menu.c                            Menu module for IAP, managing user interaction and menu logic
  - IAP/IAP_Bootloader/Source/iap_usart.c                           USART module for IAP, responsible for serial communication
  - IAP/IAP_Bootloader/Source/iap_ymodem.c                          YMODEM protocol module for IAP, implementing file transfer functionality

&par IDE environment

  - MDK-ARM V5.40
  - EWARM V9.60.2.5599
  - Eclipse V4.35.0 RC1 & clang V19.1.1

&par Hardware and Software environment

  - This example runs on G32R430 TINY Devices.