# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_REALTEK_BEE_ADC rtl87x2g_adc.c)
zephyr_include_directories(.)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/librtl87x2g_adc.a)
