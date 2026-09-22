/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                         Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_DRIVER_ENTRY_H
#define RTL_DRIVER_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                         Header Files
 *============================================================================*/

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup DRIVER_ENTRY_Exported_Functions Driver entry Exported Functions
  * \brief
  * \{
  */
#if defined (CONFIG_SOC_CORE_APPPROCESSOR)
void driver_entry(void);
#else
__WEAK void driver_entry(void);
#endif
//void driver_entry(void);

/** End of DRIVER_ENTRY_Exported_Functions
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_DRIVER_ENTRY_H */


