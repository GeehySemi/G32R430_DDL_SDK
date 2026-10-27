/*!
 * @file       board.h
 *
 * @brief      Header file for Board
 *
 * @version     V1.0.3
 *
 * @date        2026-07-31
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

/* Define to prevent recursive inclusion */
#ifndef BOARD_H
#define BOARD_H

/* Includes */
#if defined (G32R430_TINY)
#include "Board_G32R430_TINY/inc/board_g32r430_tiny.h"

#else
#error "Please select first the G32R4 board to be used (in board.c)"
#endif

/** @addtogroup Board
  @{
*/

#endif

/**@} end of group Board */
