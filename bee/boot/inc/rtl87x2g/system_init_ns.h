/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                      Define to prevent recursive inclusion
 *============================================================================*/
#ifndef SYSTEM_INIT_NS_H
#define SYSTEM_INIT_NS_H

/*============================================================================*
 *                      Headers
 *============================================================================*/
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                      Variables
 *============================================================================*/

extern uint32_t SystemCoreClock;
extern void (*hal_setup_hardware)(void);
extern void (*hal_setup_cpu)(void);
extern void (*hal_setup_fpu)(void);
extern bool (*mpu_setup)(void);
extern void (*system_restore)(void);
extern void (*dvfs_init)(void);
extern void (*phy_hw_control_init)(bool);
extern void (*phy_init)(uint8_t);
extern void (*thermal_tracking_timer_init)(void);
extern void (*ft_paras_apply)(void);
extern void (*si_flow_data_init)(void);
extern void (*secure_os_func_ptr_init)(void);
extern void (*secure_platform_func_ptr_init)(void);
extern bool (*log_buffer_init)(void);
extern void (*log_gdma_init)(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_INIT_NS_H */
