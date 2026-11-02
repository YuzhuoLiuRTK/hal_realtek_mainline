/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_WDT_H
#define RTL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "wdt/src/device/rtl87x2g/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "wdt/src/device/rtl87x2j/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "wdt/src/device/rtl87x3j/rtl_wdt_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "wdt/src/device/rtl87x3k/rtl_wdt_def.h"
#endif

/**
 * @defgroup WDT_DRIVER Driver
 * @ingroup WDT
 * @brief Watchdog Timer (WDT) driver.
 * @{
 */

/**
 * @brief WDT Mode structure definition.
 *
 */
typedef enum
{
    RESET_ALL = 0,               /**< Reset all. */
    RESET_ALL_EXCEPT_AON = 1,    /**< Reset all except RTC and some AON register. */
    INTERRUPT_CPU = 2,           /**< Interrupt CPU. */
    WDT_MODE_NUM = 3,            /**< The maximum selectable value for WDT mode. */
} WDTMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_WDT_Mode(MODE) (((MODE) == RESET_ALL) || \
                           ((MODE) == RESET_ALL_EXCEPT_AON) || \
                           ((MODE) == INTERRUPT_CPU))

/**
 * @brief Start WDT. This function will enable WDT clock, set and start WDT.
 *
 * @param[in]  TimeMs  WDT Timeout Time. Unit: ms.
 * @param[in]  Mode    Refer to @ref WDTMode_TypeDef. If the Reset WDT operation is not performed within the Timeout period,
 *                     the configured mode operation will be executed.
 *
 * @return WDT operating status.
 * @retval true   WDT mode set successfully, enabling the function.
 * @retval false  WDT setting failed.
 */
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode);

/**
 * @brief Enable WDT.
 */
void WDT_Enable(void);

/**
 * @brief Disable WDT.
 */
void WDT_Disable(void);

/**
 * @brief Kick Watchdog to restart WDT.
 */
void WDT_Kick(void);

/**
 * @brief Check if the WDT is working.
 *
 * @return WDT operating status.
 * @retval true   WDT is enabled.
 * @retval false  WDT is not enabled.
 */
bool WDT_IsEnable(void);

/**
 * @brief Get the current WDT timeout value in milliseconds.
 *
 * @return WDT timeout duration in milliseconds.
 */
uint32_t WDT_GetTimeoutMs(void);

/**
 * @brief Get WDT mode.
 *
 * @return WDT mode.
 * @retval RESET_ALL               Reset all.
 * @retval RESET_ALL_EXCEPT_AON    Reset all except RTC and some AON register.
 * @retval INTERRUPT_CPU           Interrupt CPU.
 * @retval WDT_MODE_NUM            The maximum selectable value for WDT mode.
 */
WDTMode_TypeDef WDT_GetMode(void);

#if (WDT_SUPPORT_AUTO_CLOCK == 1)
/**
 * @brief Enable or disable WDT clock auto mode.
 *
 * @param[in]  Newstate  Enable or disable WDT clock auto mode.
 */
void WDT_ClockAutoModeCmd(FunctionalState Newstate);
#endif

#if (WDT_SUPPORT_GET_CURRENT_COUNTER == 1)
/**
 * @brief Get WDT current count.
 *
 * @return Current count.
 */
uint32_t WDT_GetCurrentCount(void);
#endif

/**
 * @brief Clear WDT interrupt pending bit.
 */
void WDT_ClearINTPendingBit(void);

#if (WDT_SUPPORT_CNT_LIMIT2 == 1)
/**
 * @brief Set WDT reset time.
 *
 * @param[in]  TimeMs  WDT reset time. Unit: ms.
 *
 * @return true or false.
 * @retval true   Reset time set successfully.
 * @retval false  Reset time setting failed.
 */
bool WDT_SetResetTime(uint32_t TimeMs);

/**
 * @brief Get reset time (ms).
 *
 * @return Reset time.
 */
uint32_t WDT_GetResetTimeMs(void);

/**
 * @brief Start WDT with interrupt time and reset time.
 *
 * @param[in]  InterruptTimeMs  WDT interrupt time. Unit: ms.
 * @param[in]  ResetTimeMs      WDT reset time. Unit: ms.
 * @param[in]  Mode             Refer to @ref WDTMode_TypeDef.
 *
 * @return true or false.
 * @retval true   WDT start successfully.
 * @retval false  WDT start failed.
 */
bool WDT_StartWithResetTime(uint32_t InterruptTimeMs, uint32_t ResetTimeMs, WDTMode_TypeDef Mode);
#endif

#if (WDT_SUPPORT_RECORD_TIMEOUT == 1)
/**
 * @brief Get last WDT timeout mode.
 *
 * @return Last WDT timeout mode.
 * @retval RESET_ALL               Reset all.
 * @retval RESET_ALL_EXCEPT_AON    Reset all except RTC and some AON register.
 * @retval INTERRUPT_CPU           Interrupt CPU.
 * @retval WDT_MODE_NUM            The maximum selectable value for WDT mode.
 */
WDTMode_TypeDef WDT_GetLastTimeoutMode(void);

/**
 * @brief Clear last WDT timeout mode.
 */
void WDT_ClearLastTimeoutMode(void);

/**
 * @brief Get WDT timeout flag.
 *
 * @return WDT timeout status.
 * @retval true   WDT timeout.
 * @retval false  WDT not timeout.
 */
bool WDT_GetTimeoutFlag(void);

/**
 * @brief Clear WDT timeout flag.
 */
void WDT_ClearTimeoutFlag(void);
#endif
/** @} */ /* End of group WDT_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_WDT_H */
