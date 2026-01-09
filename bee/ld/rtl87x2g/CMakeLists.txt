# Copyright (c) 2026 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/liblowerstack.a)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libROM_S.a)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libROM_NS.a)
