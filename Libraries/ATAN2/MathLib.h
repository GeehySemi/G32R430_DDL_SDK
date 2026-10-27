/**
 * @file        MathLib.h
 *
 * @brief       Math library header file.
 *
 * @version     V1.0.0
 *
 * @date        2025-10-31
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
 *
 */

/** @addtogroup MATH_LIB
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef _MATH_LIB_H_
#define _MATH_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup MATH_LIB_Includes
  * @{
  */
#include <stdint.h>

/**
  * @}
  */


/** @addtogroup MATH_LIB_Exported_Functions
  * @{
  */

/**
  * @brief   Computes the angle of a point (nX, nY) on a two-dimensional plane in Q32 format.
  * @param:  nX              X-axis coordinate
  * @param:  nY              Y-axis coordinate
  * @param:  nPrecisionLevel Specifies the precision level from 1 to 8;
  *                          higher precision increases accuracy but slows computation.
  *                          Recommended values: 6, 7, 8
  * @return  The angle value in the range (-1, 1], Q31 format, corresponding to (-π, π].
  */
int32_t ATAN2(int32_t nX, int32_t nY, int32_t nPrecisionLevel);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* _MATH_LIB_H_ */

/**
  * @}
  */
