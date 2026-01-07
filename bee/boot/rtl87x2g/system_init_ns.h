/*
 * Copyright (c) 2026 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef SYSTEM_INIT_H
#define SYSTEM_INIT_H


/*============================================================================*
 *                      Headers
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>


/** @defgroup SYSTEM_RTL876X_API  System Rtl876x
  * @brief CMSIS API sets for RTL876x Device Series
  * @{
  */

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                      Types
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_types SYSTEM RTL876X Exported types
  * @{
  */


/** @} */ /* End of group SYSTEM_RTL876X_Exported_types */


/*============================================================================*
 *                      Variables
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Variables SYSTEM RTL876X Exported Variables
  * @{
  */
extern uint32_t SystemCoreClock;
extern void (*hal_setup_hardware)(void);
extern void (*hal_setup_cpu)(void);
extern void (*hal_setup_fpu)(void);
extern bool (*mpu_setup)(void);
extern void (*system_restore)(void);

/** @} */ /* End of group SYSTEM_RTL876X_Exported_Variables */

/*============================================================================*
 *                      Functions
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Functions SYSTEM RTL876X Sets Exported Functions
    * @brief
    * @{
    */
bool SystemInit_ns(void);
void cache_restore(bool i_cache_en, bool d_cache_en);

/** @} */ /* End of group SYSTEM_RTL876X_Exported_Functions */

#ifdef __cplusplus
}
#endif


/** @} */ /* End of group SYSTEM_RTL876X_API */



#endif /* SYSTEM_INIT_H */

