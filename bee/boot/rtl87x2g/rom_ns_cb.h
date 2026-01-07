/*
 * Copyright (c) 2026 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
  *                   Define to prevent recursive inclusion
  *============================================================================*/

#ifndef _ROM_NS_CB_H_
#define _ROM_NS_CB_H_

/*============================================================================*
  *                               Header Files
  *============================================================================*/


#ifdef  __cplusplus
extern  "C" {
#endif

extern void (*secure_os_func_ptr_init)(void);
extern void (*secure_platform_func_ptr_init)(void);


#ifdef  __cplusplus
}
#endif

#endif // _FTL_ROM_H_
