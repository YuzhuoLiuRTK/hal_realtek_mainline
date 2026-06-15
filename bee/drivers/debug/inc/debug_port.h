/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Define to prevent recursive inclusion
 *============================================================================*/
#ifndef DEBUG_PORT_H
#define DEBUG_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "debug/src/device/rtl87x3j/debug_port_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "debug/src/device/rtl87x2j/debug_port_def.h"
#endif

/*============================================================================*
 *                        Constants
 *============================================================================*/
typedef enum
{
    PCK600_QACTIVE_IDLE = 0,
    PCK600_QACTIVE_ACTIVE = 1,
    PCK600_QACTIVE_ERROR = 2,
} PCK600_QACTIVE_STATUS_T;

/*============================================================================*
 *                         Functions
 *============================================================================*/

uint64_t debug_port_pck600_qactive_get_device_mask(void);

PCK600_QACTIVE_STATUS_T debug_port_pck600_qactive_get_device_status(PCK600_QACTIVE_DEVICE_T device);

/**
  * @brief  set debug mode on specific pin
  * @param  debug_select: can be /ref AON_DEBUG_PORT.
  * @param  NewState: Newstate of the specified peripheral.
  *
  * @retval None
    *
    * <b>Example usage</b>
  * \code{.c}
  *
  * void debug_port_sample(void)
  * {
  *     debug_port_aon(DEBUG_PCK600_OUTPUT_TO_VPON_PPU, ENABLE);
  * }
  * \endcode
  */
void debug_port_aon_output(AON_DEBUG_PORT debug_select, FunctionalState NewState);

#ifdef __cplusplus
}
#endif

#endif /* _DEBUG_PORT_H_ */

