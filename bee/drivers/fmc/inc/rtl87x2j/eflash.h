/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef EFLASH_API_H
#define EFLASH_API_H

#include <stdlib.h>
#include <stdbool.h>
bool eflash_write(uint32_t addr, uint8_t *data, uint32_t len);
bool eflash_read(uint32_t addr, uint8_t *data, uint32_t len);
bool eflash_erase(uint32_t addr);
#endif
