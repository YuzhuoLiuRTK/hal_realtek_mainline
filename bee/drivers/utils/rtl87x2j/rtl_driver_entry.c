/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
__attribute__((weak, used)) void driver_entry(void)
{
#ifdef CONFIG_REALTEK_DRIVER_GPIO
    extern void GPIO_IRQInit(void);
    GPIO_IRQInit();
#endif

#ifdef CONFIG_REALTEK_DRIVER_TIMER
    extern void TIMER_IRQInit(void);
    TIMER_IRQInit();
#endif
}
