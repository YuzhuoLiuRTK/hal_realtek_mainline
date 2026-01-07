/*
 * Copyright (c) 2026 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef SYSTEM_RTL876X_H
#define SYSTEM_RTL876X_H


/*============================================================================*
 *                      Headers
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup SYSTEM_RTL876X  System RTL876X
  * @brief System Level API sets for RTL876x Device Series
  * @{
  */

/*============================================================================*
 *                      Types
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Types System RTL876X Exported Types
  * @{
  */

typedef enum
{
    LOG_TIMESTAMP_OS        = 0,
    LOG_TIMESTAMP_HW_TIMER  = 1,
    LOG_TIMESTAMP_RSVD      = 2,
    LOG_TIMESTAMP_MAX       = 3
} T_LOG_TIMESTAMP_TYPE;

typedef bool (*APP_MAIN_FUNC)();
typedef void (*USER_CALL_BACK)();

/** @} */ /* End of group SYSTEM_RTL876X_Exported_types */

/*============================================================================*
 *                      Variables
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Variables System RTL876X Exported Variables
    * @brief
    * @{
    */
extern APP_MAIN_FUNC upperstack_entry;
extern APP_MAIN_FUNC app_pre_main;
extern APP_MAIN_FUNC app_main;
extern USER_CALL_BACK app_pre_main_cb;
/** @} */ /* End of group SYSTEM_RTL876X_Exported_Variables */

/*============================================================================*
 *                      Functions
 *============================================================================*/
/** @defgroup SYSTEM_RTL876X_Exported_Functions System RTL876X Exported Functions
    * @brief
    * @{
    */

/**
 * @brief  Call the system service.
 * @param  opcode: operation code.
 * @param  parm: parameter.
 * @return none
 */
extern void SystemCall(uint32_t opcode, uint32_t parm);

/**
 * @brief  update ram layout for app.
 * @param  app_global_size: app global ram size.
 * @param  data_heap_size: data on heap total size.
 * @param  share_cache_ram_size: the size of share cache to ram.
 * @return none
 */
extern void update_ram_layout(uint32_t app_global_size, uint32_t data_heap_size,
                              uint32_t share_cache_ram_size);


/**
 * @brief  Call the system service by stack.
 * @param  opcode: operation code.
 * @param  parm: parameter.
 * @return none
 */
extern void SystemCall_Stack(uint32_t opcode, ...);


extern void (*si_flow_data_init)(void);
extern void (*ft_paras_apply)(void);
extern void hal_setup_hardware(void);
extern void hal_setup_cpu(void);

/** @} */ /* End of group SYSTEM_RTL876X_Exported_Functions */

/** @} */ /* End of group SYSTEM_RTL876X */

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_RTL876X_H */

