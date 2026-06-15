# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

set(STUB_DIR ${ZEPHYR_HAL_REALTEK_MODULE_DIR}/bee/drivers/stubs)
set(DEBUG_STUB_FILE ${STUB_DIR}/rtl87x2j/debug_stubs.c)
set(DEBUG_LIB_PATH
  ${ZEPHYR_HAL_REALTEK_MODULE_DIR}/bee/drivers/lib/rtl87x2j/libdriver.a
)

add_blob_or_stub(
    ${ZEPHYR_CURRENT_LIBRARY}
    debug
    "${DEBUG_LIB_PATH}"
    "${DEBUG_STUB_FILE}"
)
