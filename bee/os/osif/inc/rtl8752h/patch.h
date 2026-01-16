/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PATCH_H_
#define _PATCH_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PATCH_POINTER_SECTION

typedef bool (*BOOL_PATCH_FUNC)();

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_H_ */
