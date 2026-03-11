# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(rtl876x_adc.c)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libadc.a)
