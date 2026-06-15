/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file debug_stubs.c
 * @brief Stub implementations for debug port library functions.
 *        Used when building without binary blobs (CONFIG_BUILD_ONLY_NO_BLOBS).
 */

#include <debug_port.h>
#include <pck600_snapshot.h>

/* Stub implementations for debug port functions */
void debug_port_set_pin_bit_map(uint8_t *pin_group_table, uint32_t dbg_bitmap)
{
	(void)pin_group_table;
	(void)dbg_bitmap;
}

void debug_port_open(T_GROUP_CONFIG group_config)
{
	(void)group_config;
}

#if (DEBUG_PORT_SUPPORT_QACTIVE_STATUS == 1)
void debug_port_pck600_qactive_output(uint32_t group, uint8_t *pin_group_table)
{
	(void)group;
	(void)pin_group_table;
}

uint64_t debug_port_pck600_qactive_get_device_mask(void)
{
	return 0;
}

PCK600_QACTIVE_STATUS_T debug_port_pck600_qactive_get_device_status(PCK600_QACTIVE_DEVICE_T device)
{
	(void)device;
	return PCK600_QACTIVE_IDLE;
}
#endif

#if (DEBUG_PORT_SUPPORT_AON_DEBUG == 1)
void debug_port_aon_output(AON_DEBUG_PORT debug_select, FunctionalState NewState)
{
	(void)debug_select;
	(void)NewState;
}
#endif

#if (DEBUG_PORT_SUPPORT_MULTI_PLATFORM == 1)
void debug_port_set_platform(T_DEBUG_PORT_PLATFORM platform)
{
	(void)platform;
}
#endif

uint64_t pck600_snapshot_get_device_mask(void)
{
	return 0;
}

PCK600_SNAPSHOT_STATUS_T pck600_snapshot_get_device_status(PCK600_SNAPSHOT_DEVICE_T device)
{
	(void)device;

	return PCK600_SNAPSHOT_SUCCESS;
}

void pck600_snapshot_clear_all_device_status(void)
{
	return;
}
