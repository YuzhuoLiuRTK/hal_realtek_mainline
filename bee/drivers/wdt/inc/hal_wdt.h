/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef _HAL_WDT_H
#define _HAL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>

/** @addtogroup HAL_WDT HAL WDT
  * @brief HAL WDT function module
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup HAL_WDT_Exported_Types HAL WDT Exported Types
  * @{
  */

/**
 * \brief       WDT supported modes.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef enum _WDT_MODE
{
    WDT_MODE_RESET_ALL = 0,               /**< Reset all. */
    WDT_MODE_RESET_ALL_EXCEPT_AON = 1,    /**< Reset all except RTC and some AON register. */
    WDT_MODE_INTERRUPT_CPU = 2,           /**< Interrupt CPU. */
    WDT_MODE_UNKNOWN = 3                  /**< Mode unknown */
} T_WDT_MODE;

#define IS_WDT_MODE(MODE) ((MODE) < WDT_MODE_UNKNOWN)

/**
 * \brief       This enum define the API return type.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */
typedef enum
{
    HAL_WDT_STATUS_INVALID_PARAMETER = -1,       /**<  A wrong parameter is given. */
    HAL_WDT_STATUS_OK = 0                        /**<  No error occurred during the function call. */
} T_WDT_STATUS;

/**
 * \brief       This enum define WDT RESET TYPE for debug
 *
 * \ingroup     HAL_WDT_Exported_Types
 */

/**
 * \brief       Define the type of wdt reset callback.
 *
 * \ingroup     HAL_WDT_Exported_Types
 */


/** End of group HAL_WDT_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup HAL_WDT_API_Exported_Functions WDT Api
  * @{
  */

/**
 * hal_wdt.h
 *
 * \brief  Start wdt.
 *
 * \param[in] mode: wdt reset mode \ref T_WDT_MODE.
 * \param[in] timeout_ms: wdt timeout.
 *
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_start(RESET_ALL, 4000);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_start(T_WDT_MODE mode, uint32_t timeout_ms);

/**
 * hal_wdt.h
 *
 * \brief  Disable wdt.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_stop();
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_stop(void);

/**
 * hal_wdt.h
 *
 * \brief  Check whether wdt is enable.
 * \return The result of wdt.
 * \retval true: wdt is enable.
 * \retval false: wdt is disable.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     if (hal_wdt_is_enable() == true)
 *     {
 *
 *     }
 * }
 * \endcode
 */
bool hal_wdt_is_enable(void);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt reset mode.
 * \return T_WDT_MODE: wdt reset mode \ref T_WDT_MODE.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     T_WDT_MODE mode = hal_wdt_get_mode();
 * }
 * \endcode
 */
T_WDT_MODE hal_wdt_get_mode(void);

/**
 * hal_wdt.h
 *
 * \brief  Get wdt current timeout value.
 * \return current timeout value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     uint32_t timeout = hal_wdt_get_timeout_ms();
 * }
 * \endcode
 */
uint32_t hal_wdt_get_timeout_ms(void);

/**
 * hal_wdt.h
 *
 * \brief  Change wdt timeout value.
 * \param[in] timeout_ms: wdt new timeout value.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_change_timeout_period(4000);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_change_timeout_period(uint32_t timeout_ms);

/**
 * hal_wdt.h
 *
 * \brief  Change wdt mode.
 * \param[in] mode: wdt new reset mode \ref T_WDT_MODE.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_change_mode(RESET_ALL);
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_change_mode(T_WDT_MODE mode);

/**
 * hal_wdt.h
 *
 * \brief  Kick wdt.
 * \return T_WDT_STATUS: wdt status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void wdt_demo(void)
 * {
 *     hal_wdt_kick();
 * }
 * \endcode
 */
T_WDT_STATUS hal_wdt_kick(void);




#ifdef __cplusplus
}
#endif
/** @} */ /* End of group HAL_WDT_API_Exported_Functions */
/** @} */ /* End of group HAL_WDT */
#endif
