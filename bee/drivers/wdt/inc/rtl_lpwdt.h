/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_LPWDT_H
#define RTL_LPWDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "utils/rtl_utils.h"
#include "wdt/inc/rtl_wdt.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "wdt/src/device/rtl87x2j/rtl_lpwdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "wdt/src/device/rtl87x3d/rtl_lpwdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3E)
#include "wdt/src/device/rtl87x3e/rtl_lpwdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "wdt/src/device/rtl87x3j/rtl_lpwdt_def.h"
#endif

/** \defgroup LPWDT         LPWDT
  * \brief
  * \{
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup LPWDT_Exported_Functions LPWDT Exported Functions
  * \{
  */

/**
  * \brief  Start LPWDT.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \param  TimeMs
  * \param  Mode \ref WDTMode_Typedef
  * \return true or false.
  */
bool LPWDT_Start(LPWDT_TypeDef *LPWDTx, uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
  * \brief  Enable LPWDT.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return None.
  */
void LPWDT_Enable(LPWDT_TypeDef *LPWDTx);

/**
  * \brief  Disable LPWDT.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return None.
  */
void LPWDT_Disable(LPWDT_TypeDef *LPWDTx);

/**
  * \brief  Kick LPWDT to restart WDT.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return None.
  */
void LPWDT_Kick(LPWDT_TypeDef *LPWDTx);

/**
  * \brief  Is LPWDT enable.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return Is LPWDT enable or not
  */
bool LPWDT_IsEnable(LPWDT_TypeDef *LPWDTx);

/**
  * \brief  Get LPWDT timeout.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return LPWDT timeout
  */
uint32_t LPWDT_GetTimeoutMs(LPWDT_TypeDef *LPWDTx);

/**
  * \brief  Get LPWDT mode.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return LPWDT mode
  */
WDTMode_TypeDef LPWDT_GetMode(LPWDT_TypeDef *LPWDTx);

#if (LPWDT_SUPPORT_GET_CURRENT_COUNTER == 1)
/**
  * \brief  Get LPWDT current Count.
  * \param  LPWDTx \ref LPWDT_Declaration
  * \return Current Count
  */
uint32_t LPWDT_GetCurrentCount(LPWDT_TypeDef *LPWDTx);
#endif

/** End of LPWDT_Exported_Functions
  * \}
  */

/** End of LPWDT
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPWDT_H */
