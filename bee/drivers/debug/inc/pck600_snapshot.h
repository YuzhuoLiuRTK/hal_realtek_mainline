/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Define to prevent recursive inclusion
 *============================================================================*/
#ifndef PCK600_SNAPSHOT_H
#define PCK600_SNAPSHOT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "debug/src/device/rtl87x3j/pck600_snapshot_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "debug/src/device/rtl87x2j/pck600_snapshot_def.h"
#endif

/*============================================================================*
 *                        Constants
 *============================================================================*/

typedef enum
{
    PCK600_SNAPSHOT_SUCCESS          = 0,
    PCK600_SNAPSHOT_FAIL_KEEP_ACTIVE = 1,
    PCK600_SNAPSHOT_FAIL_RE_WAKEUP   = 2,
    PCK600_SNAPSHOT_FAIL_MAX         = 3,
} PCK600_SNAPSHOT_STATUS_T;

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * \brief  Get the status of all module when entering lpm.
 *
 * \retval The status of all module.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     uint64_t mask = pck600_snapshot_get_device_mask();
 * }
 * \endcode
 */
uint64_t pck600_snapshot_get_device_mask(void);

/**
 * \brief  Get the status of the specified module when entering lpm.
 * \param  device: Can be \ref PCK600_SNAPSHOT_DEVICE_T.
 *
 * \retval The status of module \ref PCK600_SNAPSHOT_STATUS_T.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     pck600_snapshot_get_device_status(PCK600_SNAPSHOT_UART0);
 * }
 * \endcode
 */
PCK600_SNAPSHOT_STATUS_T pck600_snapshot_get_device_status(PCK600_SNAPSHOT_DEVICE_T device);

/**
 * \brief  Clear all the status of the qch.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     pck600_snapshot_clear_all_device_status();
 * }
 * \endcode
 */
void pck600_snapshot_clear_all_device_status(void);

#ifdef __cplusplus
}
#endif

#endif /* PCK600_SNAPSHOT_H */

