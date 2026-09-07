# Copyright (c) 2026, Realtek Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)

set(STUB_DIR ${ZEPHYR_HAL_REALTEK_MODULE_DIR}/bee/drivers/stubs)
set(SDHC_STUB_FILE ${STUB_DIR}/rtl87x2g/sd_stubs.c)
set(SDHC_LIB_PATH
    ${ZEPHYR_HAL_REALTEK_MODULE_DIR}/zephyr/blobs/bee/drivers/rtl87x2g/sd/librtl87x2g_sd.a
)
set(SD_SDK_LIB_PATH
    ${ZEPHYR_HAL_REALTEK_MODULE_DIR}/zephyr/blobs/bee/drivers/rtl87x2g/sdk/librtl87x2g_sdk.a
)

add_blob_or_stub(
    ${ZEPHYR_CURRENT_LIBRARY}
    sdhc
    "${SDHC_LIB_PATH}"
    "${SDHC_STUB_FILE}"
)

if(NOT CONFIG_BUILD_ONLY_NO_BLOBS AND EXISTS "${SD_SDK_LIB_PATH}")
    target_link_libraries(${ZEPHYR_CURRENT_LIBRARY} PUBLIC "${SD_SDK_LIB_PATH}")
endif()
