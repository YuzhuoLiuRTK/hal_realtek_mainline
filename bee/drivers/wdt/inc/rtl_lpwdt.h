/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPWDT_H
#define RTL_LPWDT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#include "wdt/inc/rtl_wdt.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "wdt/src/device/rtl87x2j/rtl_lpwdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "wdt/src/device/rtl87x3j/rtl_lpwdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "wdt/src/device/rtl87x3k/rtl_lpwdt_def.h"
#endif

/**
 * @defgroup LPWDT_DRIVER DRIVER
 * @ingroup LPWDT
 * @brief Low Power Watchdog Timer (LPWDT) driver.
 * @{
 */

/**
 * @defgroup LPWDT_Exported_Functions LPWDT Exported Functions
 * @{
 */

/**
 * @brief Start LPWDT. This function will enable LPWDT clock, set and start LPWDT.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 * @param[in]  TimeMs  LPWDT Timeout Time. Unit: ms.
 * @param[in]  Mode    Refer to @ref WDTMode_TypeDef. If the Reset LPWDT operation is not performed within the Timeout period,
 *                     the configured mode operation will be executed.
 *
 * @return LPWDT operating status.
 * @retval true   LPWDT started successfully.
 * @retval false  LPWDT start failed.
 */
bool LPWDT_Start(LPWDT_TypeDef *LPWDTx, uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
 * @brief Enable LPWDT.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 */
void LPWDT_Enable(LPWDT_TypeDef *LPWDTx);

/**
 * @brief Disable LPWDT.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 */
void LPWDT_Disable(LPWDT_TypeDef *LPWDTx);

/**
 * @brief Kick Watchdog to restart LPWDT.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 */
void LPWDT_Kick(LPWDT_TypeDef *LPWDTx);

/**
 * @brief Check if the LPWDT is working.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 *
 * @return LPWDT operating status.
 * @retval true   LPWDT is enabled.
 * @retval false  LPWDT is not enabled.
 */
bool LPWDT_IsEnable(LPWDT_TypeDef *LPWDTx);

/**
 * @brief Get the current LPWDT timeout value in milliseconds.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 *
 * @return LPWDT timeout duration in milliseconds.
 */
uint32_t LPWDT_GetTimeoutMs(LPWDT_TypeDef *LPWDTx);

/**
 * @brief Get LPWDT mode.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 *
 * @return LPWDT mode.
 * @retval RESET_ALL               Reset all.
 * @retval RESET_ALL_EXCEPT_AON    Reset all except RTC and some AON register.
 * @retval INTERRUPT_CPU           Interrupt CPU.
 * @retval WDT_MODE_NUM            The maximum selectable value for WDT mode.
 */
WDTMode_TypeDef LPWDT_GetMode(LPWDT_TypeDef *LPWDTx);

#if (LPWDT_SUPPORT_GET_CURRENT_COUNTER == 1)
/**
 * @brief Get LPWDT current count.
 *
 * @param[in]  LPWDTx  Refer to @ref LPWDT_Declaration
 *
 * @return Current count.
 */
uint32_t LPWDT_GetCurrentCount(LPWDT_TypeDef *LPWDTx);
#endif

/** @} */ /* End of group LPWDT_Exported_Functions */

/** @} */ /* End of group LPWDT_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPWDT_H */
