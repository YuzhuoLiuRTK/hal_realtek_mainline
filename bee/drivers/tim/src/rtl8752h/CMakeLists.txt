# Copyright (c) 2026 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

if(CONFIG_REALTEK_BEE_TIM)
zephyr_library_sources(rtl876x_tim.c)
zephyr_library_sources(rtl8752h_tim.c)
endif()

if(CONFIG_REALTEK_BEE_ENHTIM)
zephyr_library_sources(rtl876x_enh_tim.c)
zephyr_library_sources(rtl8752h_enh_tim.c)
endif()
