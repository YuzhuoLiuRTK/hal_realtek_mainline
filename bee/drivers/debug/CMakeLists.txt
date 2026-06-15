# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_SERIES_RTL87X2J)
    zephyr_include_directories(inc)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_DEBUG src)
