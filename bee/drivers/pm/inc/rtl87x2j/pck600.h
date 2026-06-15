/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __PCK600_H
#define __PCK600_H

/*============================================================================*
 *                               Header Files
 *============================================================================*/


/*============================================================================*
 *                              Compile Checkers
 *============================================================================*/

/*============================================================================*
 *                              Types
 *============================================================================*/
typedef enum
{
    POWER_POLICY_SYSTEM_OFF                 = 0x0,
    POWER_POLICY_SYSTEM_ON_LOW_POWER        = 0x1,
    POWER_POLICY_SYSTEM_ON_CONST_LATENCY    = 0x2,
    POWER_POLICY_SYSTEM_ON_ACTIVE           = 0x3,
    POWER_POLICY_SYSTEM_MAX,

    POWER_POLICY_SYSTEM_INVALID             = 0xFF,
} POWER_POLICY_SYSTEM;

extern void (*pck600_system_set_dynamic_power_policy)(POWER_POLICY_SYSTEM);
extern uint32_t (*pck600_system_get_wakeup_count)(bool *overflow_flag);

#endif /* __PCK600_H */
