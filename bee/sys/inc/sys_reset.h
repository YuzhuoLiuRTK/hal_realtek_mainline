/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Constants
 *============================================================================*/
#ifndef __SYS_RESET_H__
#define __SYS_RESET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#if defined(CONFIG_SOC_SERIES_RTL87X2G)
#include "wdt/inc/rtl_wdt.h"
#elif defined(CONFIG_SOC_SERIES_RTL8752H)
#include "rtl876x_wdg.h"
#endif
/*============================================================================*
 *                             Constants
 *============================================================================*/

/* Definitions of system reset reasons */
#define    RESET_REASON_HW                          0x0  /* HW reset */
#define    RESET_REASON_WDG_TIMEOUT                 0x1  /* WDT reset */
#define    RESET_REASON_BOOT_EFUSE_INVALID          0x2
#define    RESET_REASON_BOOT_FLASH_INVALID          0x3
#define    RESET_REASON_BOOT_RETRY_COUNT_LIMIT      0x4
#define    RESET_REASON_HARD_FAULT                  0x5
#define    RESET_REASON_PASSWORD_DEBUG              0x6
#define    RESET_REASON_CHIP_RESET                  0x7
#define    RESET_REASON_ENTER_FT_MODE               0x8
#define    RESET_REASON_SWITCH_TO_HCI_MODE          0x9
#define    RESET_REASON_SWITCH_TO_OTA_MODE          0xA
#define    RESET_REASON_DFU_TIMEOUT                 0xB
#define    RESET_REASON_DFU_LINK_LOST               0xC
#define    RESET_REASON_DFU_UPDATE_IMG              0xD
#define    RESET_REASON_DFU_UPDATE_COMP_IMG         0xE
#define    RESET_REASON_DFU_UPDATE_IMG_FAIL         0xF
#define    RESET_REASON_DFU_ACTIVE_RESET            0x10
#define    RESET_REASON_DFU_FAIL_RESET              0x11
#define    RESET_REASON_FEATURE_CHECK_FAIL          0x12
#define    RESET_REASON_FLASH_LAYOUT_OVERFLOW       0x13
#define    RESET_REASON_MP_RESET                    0x14
#define    RESET_REASON_POWER_DOWN_RESET            0x15
#define    RESET_REASON_FLASH_IOCTL                 0x16
#define    RESET_REASON_BT_CONTROLLER               0x17
#define    RESET_REASON_RESET_WRAPPER               0x18
#define    RESET_REASON_BT_IMG_MISMATCH             0x19
#define    RESET_REASON_ZEPHYR                      0x1A

/*
 * Keep RTL87x2G reset reason definitions aligned with the reset reason values
 * stored by the RTL87x2G ROM and platform code.
 */
#if defined(CONFIG_SOC_SERIES_RTL87X2G)
#undef RESET_REASON_WDG_TIMEOUT
#undef RESET_REASON_PASSWORD_DEBUG
#undef RESET_REASON_CHIP_RESET
#undef RESET_REASON_ENTER_FT_MODE
#undef RESET_REASON_SWITCH_TO_HCI_MODE
#undef RESET_REASON_SWITCH_TO_OTA_MODE
#undef RESET_REASON_DFU_TIMEOUT
#undef RESET_REASON_DFU_LINK_LOST
#undef RESET_REASON_DFU_UPDATE_IMG_FAIL
#undef RESET_REASON_DFU_UPDATE_COMP_IMG
#undef RESET_REASON_DFU_ACTIVE_RESET
#undef RESET_REASON_DFU_FAIL_RESET
#undef RESET_REASON_FEATURE_CHECK_FAIL
#undef RESET_REASON_FLASH_LAYOUT_OVERFLOW
#undef RESET_REASON_POWER_DOWN_RESET
#undef RESET_REASON_FLASH_IOCTL
#undef RESET_REASON_ZEPHYR

#define    RESET_REASON_WDT_TIMEOUT                 0x1
#define    RESET_REASON_FLASH_IOCTL                 0x6
#define    RESET_REASON_LOWER_STACK                 0x7
#define    RESET_REASON_PASSWORD_DEBUG              0x8
#define    RESET_REASON_ENTER_FT_MODE               0x9
#define    RESET_REASON_SWITCH_TO_HCI_MODE          0xA
#define    RESET_REASON_SWITCH_TO_OTA_MODE          0xB
#define    RESET_REASON_DFU_FW_RESET                0xC
#define    RESET_REASON_DFU_UPDATE_IMG_FAIL         0xE
#define    RESET_REASON_DFU_DISCONN_RSP             0xF
#define    RESET_REASON_DFU_DISCONN_IND             0x10
#define    RESET_REASON_ROM_DFU_OPCODE_SYSTEM_RESET 0x11
#define    RESET_REASON_DATATRANS_PATCH_ACTIVE      0x12
#define    RESET_REASON_DATATRANS_SYSTEM_RESET      0x13
#define    RESET_REASON_MP_RESET                    0x14
#define    RESET_REASON_FEATURE_CHECK_FAIL          0x15
#define    RESET_REASON_FLASH_LAYOUT_OVERFLOW       0x16
#define    RESET_REASON_DFU_UPDATE_COMPRESSED_IMG   0x17
#define    RESET_REASON_BRANCH_TO_NS_FAIL           0x18
#define    RESET_REASON_BRANCH_TO_S_FAIL            0x19
#define    RESET_REASON_DLPS                        0x1A
#define    RESET_REASON_POWER_DOWN                  0x1B
#define    RESET_REASON_ZEPHYR                      0x1C
#endif

/* Customized reset reasons start from 0x80 */
#define    RESET_REASON_APP_START                   0x80
#define    SW_RESET_APP_END                         0xFF

#if defined(CONFIG_SOC_SERIES_RTL87X2G)
typedef uint32_t T_SW_RESET_REASON;
#endif

/* Global variable holding the last reset reason */
extern uint32_t sys_reset_reason;

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup SYS_RESET_Exported_Types SYS RESET Exported Types
  * @{
  */

/**
 * \brief       Define the type of sys reset callback.
 *
 * \ingroup     RESET_REASON_Exported_Types
 */
typedef void (*P_SYS_RESET_CB)(uint32_t reset_reason);

extern P_SYS_RESET_CB sys_reset_callback;

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** \defgroup SYS_RESET_Exported_Functions SYS RESET Exported Functions
  * \{
  */

/**
 * sys_reset.h
 *
 * \brief  Init reset callback queue.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void sys_reset_demo(void)
 * {
 *     sys_reset_callback_queue_init();
 * }
 * \endcode
 */
extern void sys_reset_callback_queue_init(void);

/**
 * sys_reset.h
 *
 * \brief  Register sys reset callback.
 * \param[in] new_callback: sys reset callback to be registered.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void user_callback(uint32_t sys_reset_reason)
 * {
 * }
 * void sys_reset_demo(void)
 * {
 *     sys_reset_callback_register(user_callback);
 * }
 * \endcode
 */
extern void sys_reset_callback_register(P_SYS_RESET_CB callback);

/**
 * sys_reset.h
 *
 * \brief  Get sys reset reason.
 * \return Reset reason.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void sys_reset_demo(void)
 * {
 *     uint8_t reason = sys_reset_reason_get();
 * }
 * \endcode
 */
extern uint32_t sys_reset_reason_get(void);

/**
 * sys_reset.h
 *
 * \brief  Update reset_reason to the specified register.
 * \param[in] reset_reason: reset reason.
 */
extern void sys_reset_reason_update(uint32_t reset_reason);

/**
 * sys_reset.h
 *
 * \brief  Reset the mcu with specified reason.
 * \param[in] reset_reason: reset reason.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void sys_reset_demo(void)
 * {
 *     sys_reset(RESET_REASON_HARD_FAULT);
 * }
 * \endcode
 */
extern void sys_reset(uint32_t reset_reason);

/**
 * sys_reset.h
 *
 * \brief  Reset the mcu with specified reason and some aon register values are preserved.
 * \param[in] reset_reason: reset reason.
 * \return none.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void sys_reset_demo(void)
 * {
 *     sys_reset_aon_preserve(RESET_REASON_HARD_FAULT);
 * }
 * \endcode
 */
extern void sys_reset_aon_preserve(uint32_t reset_reason);


/**
 * sys_reset.h
 *
 * \brief  Reset the mcu.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void sys_reset_demo(void)
 * {
 *     chip_reset();
 * }
 * \endcode
 */
#define chip_reset()    sys_reset(RESET_REASON_CHIP_RESET)

/** \} */ /* End of group SYS_RESET_Exported_Functions */

/** End of group SYS_RESET_Exported_Types
  * @}
  */

/**
 * @brief Execute a system reset via the watchdog.
 *
 * This function performs a system reboot using the specified watchdog mode
 * `wdt_mode`, and optionally logs the reason for the reset as `reset_reason`.
 *
 * @param wdt_mode Specifies the watchdog mode for the reset.
 * @param reset_reason Provides the reason for the system reset, useful for further diagnostics and tracking.
 */
#if defined(CONFIG_SOC_SERIES_RTL87X2G)
extern void WDG_SystemReset(WDTMode_TypeDef wdt_mode, int reset_reason);
#elif defined(CONFIG_SOC_SERIES_RTL8752H)
extern void WDG_SystemReset(T_WDG_MODE wdt_mode, int reset_reason);
#endif

#if defined(CONFIG_SOC_SERIES_RTL87X2G)
/**
 * @brief Retrieve the reason for the system reset.
 *
 * This function returns the reason for the most recent system reset, useful for diagnosing reboot events.
 *
 * @param none
 * @return Returns the reason for the system reset, type T_SW_RESET_REASON.
 */

static inline T_SW_RESET_REASON reset_reason_get()
{
    extern T_SW_RESET_REASON sw_reset_reason;
    return sw_reset_reason;
}
#endif
#ifdef __cplusplus
}
#endif
/** @} */ /* End of group __SYS_RESET_H__ */
#endif
