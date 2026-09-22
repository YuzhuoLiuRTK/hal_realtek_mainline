/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_WAKEUP_H
#define RTL_WAKEUP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pinmux/src/device/rtl87x2j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "pinmux/src/device/rtl87x3d/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "pinmux/src/device/rtl87x2g/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "pinmux/src/device/rtl87x3j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "pinmux/src/device/rtl87x3k/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3k/pin_def.h"
#endif


/**
 * @addtogroup PINMUX
 * @brief    Pinmux and PAD driver.
 * @{
 */

/**
 * @defgroup WAKEUP_Exported_Constants WAKEUP Exported Constants
 * @{
 * @ingroup  PINMUX
 */

/**
 * @defgroup    WAKEUP_POLARITY Wakeup Polarity
 * @{
 * @ingroup     WAKEUP_Exported_Constants
 */
typedef enum
{
    SYSTEM_WAKEUP_POLARITY_HIGH, /**< Wake up the system on a high level. */
    SYSTEM_WAKEUP_POLARITY_LOW,  /**< Wake up the system on a low level. */
} SystemWakeUpPolarity_TypeDef;

/** @} */ /* End of group WAKEUP_POLARITY */

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1 | PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * @defgroup    WAKEUP_ENABLE_MODE Wakeup Enable Mode
 * @{
 * @ingroup     WAKEUP_Exported_Constants
 */
typedef enum
{
    ADP_MODE, /**< Wake up by adapter. */
    BAT_MODE, /**< Wake up by battery. */
    MFB_MODE, /**< Wake up by MFB. */
#if (PAD_SUPPORT_USB_WAKEUP == 1)
    USB_MODE, /**< Wake up by USB. */
#endif
} SystemWakeUpMode_TypeDef;

/** @} */ /* End of group WAKEUP_ENABLE_MODE */
#endif

/**
 * @brief PAD wake-up callback function type.
 *
 * @param[in] context Context passed to the callback function.
 */
typedef void (*P_PAD_CBACK)(uint32_t context);

/** @} */ /* End of group WAKEUP_Exported_Constants */

/**
 * @defgroup WAKEUP_Exported_Functions WAKEUP Exported Functions
 * @{
 * @ingroup  PINMUX
 */

/**
 * @brief Enable the wake-up system function of the specified pin.
 *
 * @param[in] Pin_Num           Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Polarity          Specifies the polarity of the wake-up system. Refer to @ref WAKEUP_POLARITY.
 * @param[in] DebounceNewState  Enable or disable the hardware debounce function.
 *
 * @note  DebounceNewState is available only when PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE is enabled.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pm_uart_enter(void)
 * {
 *     Pad_SetControlMode(P0_0, PAD_SW_MODE); // TX pin.
 *     Pad_SetControlMode(P0_1, PAD_SW_MODE); // RX pin.
 *
 * #if (PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE == 1)
 *     System_WakeUpPinEnable(P0_1, SYSTEM_WAKEUP_POLARITY_LOW, DISABLE);
 * #else
 *     System_WakeUpPinEnable(P0_1, SYSTEM_WAKEUP_POLARITY_LOW);
 * #endif
 * }
 * @endcode
 */
#if (PAD_SUPPORT_WAKEUP_ENABLE_WITH_DEBOUNCE == 1)
void System_WakeUpPinEnable(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef Polarity,
                            FunctionalState DebounceNewState);
#else
void System_WakeUpPinEnable(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef Polarity);
#endif

/**
 * @brief Disable the wake-up system function of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(P0_1) == SET)
 *     {
 *         System_WakeUpClearINTPendingBit(P0_1);
 *         System_WakeUpPinDisable(P0_1);
 *     }
 * }
 * @endcode
 */
void System_WakeUpPinDisable(uint8_t Pin_Num);

/**
 * @brief Get the wake-up status of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The wake-up status of the specified pin.
 * @retval SET    The pin wakes up the system.
 * @retval RESET  The pin does not wake up the system.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(P0_1) == SET)
 *     {
 *         System_WakeUpClearINTPendingBit(P0_1);
 *     }
 * }
 * @endcode
 */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num);

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE == 1)
/**
 * @brief Enable or disable the wake-up debounce function.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the wake-up debounce function.
 *
 * @return The execution result of configuring the wake-up debounce function.
 * @retval true  The wake-up debounce is configured successfully.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpDebounceCmd(P0_0, ENABLE);
 * }
 * @endcode
 */
bool System_WakeUpDebounceCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
 * @brief Configure the wake-up debounce time in milliseconds.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] TimeMs   Specifies the debounce time in milliseconds which range from 1 to 255 milliseconds.
 *
 * @return The execution result of configuring the wake-up debounce time.
 * @retval true  The wake-up debounce is configured successfully.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpDebounceTime(P0_0, 10);
 * }
 * @endcode
 */
bool System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t TimeMs);

/**
 * @brief Configure the wake-up debounce time in microseconds.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] TimeUs   Specifies the debounce time in microseconds which range from 32 to 256000
 *                     microseconds with a step of 32 microseconds.
 *
 * @return The execution result of configuring the wake-up debounce time.
 * @retval true  The wake-up debounce is configured successfully.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpDebounceTimeUs(P0_0, 1000);
 * }
 * @endcode
 */
bool System_WakeUpDebounceTimeUs(uint8_t Pin_Num, uint32_t TimeUs);

/**
 * @brief Get the wake-up debounce status of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The wake-up debounce status of the specified pin.
 * @retval SET    The wake-up debounce status of the specified pin is SET.
 * @retval RESET  The wake-up debounce status of the specified pin is RESET.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     if (System_WakeUpDebounceStatus(P0_0) == SET)
 *     {
 *         System_WakeUpDebounceClear(P0_0);
 *     }
 * }
 * @endcode
 */
uint8_t System_WakeUpDebounceStatus(uint8_t Pin_Num);

/**
 * @brief Clear the wake-up debounce status of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     if (System_WakeUpDebounceStatus(P0_0) == SET)
 *     {
 *         System_WakeUpDebounceClear(P0_0);
 *     }
 * }
 * @endcode
 */
void System_WakeUpDebounceClear(uint8_t Pin_Num);

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE_INTERRUPT == 1)
/**
 * @brief Enable or disable the wake-up system debounce interrupt.
 *
 * @note  Pin_Num is an invalid parameter for the RTL87x2G series, so any pin can be filled in.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the interrupt.
 *                      - ENABLE: Enable the interrupt.
 *                      - DISABLE: Disable the interrupt.
 *
 * @return The result of the setting.
 * @retval true   Configure the interrupt successfully.
 * @retval false  Failed to configure the interrupt due to an invalid pin number or
 *                because this pin does not have a debounce function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpDebounceINTConfig(P0_0, ENABLE);
 * }
 * @endcode
 */
bool System_WakeUpDebounceINTConfig(uint8_t Pin_Num, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_WAKEUP_DEBOUNCE_MULTI_GROUP == 1)
/**
 * @brief Allocate an independent debounce group of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The result of the allocation.
 * @retval true   A debounce group is allocated to the pin, or the pin already owns one.
 * @retval false  Allocation failed because all debounce groups are already in use.
 */
bool System_WakeUpDebounceMultiGroupEnable(uint8_t Pin_Num);

/**
 * @brief Release the debounce group of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The result of the release.
 * @retval true   The debounce group of the pin is released.
 * @retval false  The pin is not allocated to any debounce group.
 */
bool System_WakeUpDebounceMultiGroupDisable(uint8_t Pin_Num);
#endif
#endif

/**
 * @brief Clear the wake-up status of the specified pin.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(P0_1) == SET)
 *     {
 *         System_WakeUpClearINTPendingBit(P0_1);
 *     }
 * }
 * @endcode
 */
void System_WakeUpClearINTPendingBit(uint8_t Pin_Num);

/**
 * @brief Clear the wake-up status of all pins.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void System_Handler(void)
 * {
 *     System_WakeUpClearAllINT();
 * }
 * @endcode
 */
void System_WakeUpClearAllINT(void);

#if (PAD_SUPPORT_WAKEUP_SHORT_PULSE == 1)
/**
 * @brief Enable or disable the short pulse wake-up function.
 *
 * @param[in] NewState  Enable or disable the short pulse wake-up function.
 *                      - ENABLE: Enable the short pulse wake-up function.
 *                      - DISABLE: Disable the short pulse wake-up function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpShortPulseCmd(ENABLE);
 * }
 * @endcode
 */
void System_WakeUpShortPulseCmd(FunctionalState NewState);
#endif

/**
 * @brief Configure the wake-up PPU function of the specified pin.
 *
 * @details PPU is typically responsible for managing power domains. This function enables
 *          a specific pin to wake up the system from sleep states, meanwhile, the Core Domain
 *          is powered up.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Polarity  Specifies the pin wake-up polarity. Refer to @ref WAKEUP_POLARITY.
 * @param[in] NewState  Enable or disable the wake-up PPU function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpPPUCmd(P0_0, SYSTEM_WAKEUP_POLARITY_LOW, ENABLE);
 * }
 * @endcode
 */
void System_WakeUpPPUCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);

/**
 * @brief Configure the wake-up RAP function of the specified pin.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Polarity  Specifies the pin wake-up polarity. Refer to @ref WAKEUP_POLARITY.
 * @param[in] NewState  Enable or disable the wake-up RAP function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpRAPCmd(P0_0, SYSTEM_WAKEUP_POLARITY_LOW, ENABLE);
 * }
 * @endcode
 */
void System_WakeUpRAPCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);

/**
 * @brief Enable or disable the wake-up system function of the specified pin.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the PAD wake-up system.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpCmd(P0_0, ENABLE);
 * }
 * @endcode
 */
void System_WakeUpCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
 * @brief Set the polarity of the wake-up system function of the specified pin.
 *
 * @param[in] Pin_Num         Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] WakeUpPolarity  Specifies the pin wake-up polarity. Refer to @ref WAKEUP_POLARITY.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_SetWakeUpPinPolarity(P0_0, SYSTEM_WAKEUP_POLARITY_LOW);
 * }
 * @endcode
 */
void System_SetWakeUpPinPolarity(uint8_t Pin_Num, SystemWakeUpPolarity_TypeDef WakeUpPolarity);

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1 | PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * @brief Configure the system wake-up mode.
 *
 * @param[in] WakeUp_Mode     Mode to set. Refer to @ref SystemWakeUpMode_TypeDef.
 *                            - ADP_MODE: Wake up by adapter.
 *                            - BAT_MODE: Wake up by battery.
 *                            - MFB_MODE: Wake up by MFB.
 *                            - USB_MODE: Wake up by USB.
 * @param[in] WakeUpPolarity  Polarity to wake up.
 *                            - SYSTEM_WAKEUP_POLARITY_HIGH: Use high level wakeup.
 *                            - SYSTEM_WAKEUP_POLARITY_LOW: Use low level wakeup.
 * @param[in] NewState        Enable or disable the wake up.
 *                            - ENABLE: Enable the system wake up at the specified polarity.
 *                            - DISABLE: Disable the system wake up at the specified polarity.
 *
 * @return The result of configuring the system wake-up mode.
 * @retval 0  Configuration successful.
 * @retval 1  Configuration failed due to a wrong mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adapter_wake_up_enable(void)
 * {
 *     System_WakeUpModeCmd(ADP_MODE, SYSTEM_WAKEUP_POLARITY_HIGH, ENABLE);
 * }
 * @endcode
 */
uint8_t System_WakeUpModeCmd(SystemWakeUpMode_TypeDef WakeUp_Mode,
                             SystemWakeUpPolarity_TypeDef WakeUpPolarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_ADPATER_WAKEUP == 1)
/**
 * @brief Configure the adapter wake-up system function in power off (shipping) mode.
 *
 * @param[in] WakeUpPolarity  Polarity to wake up.
 *                            - SYSTEM_WAKEUP_POLARITY_HIGH: Use high level wakeup.
 *                            - SYSTEM_WAKEUP_POLARITY_LOW: Use low level wakeup.
 * @param[in] NewState        Enable or disable the adapter wake up.
 *                            - ENABLE: Enable the adapter wake-up system at the specified polarity.
 *                            - DISABLE: Disable the adapter wake-up system.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adapter_wake_up_enable(void)
 * {
 *     System_WakeUpAdapterCmd(SYSTEM_WAKEUP_POLARITY_HIGH, ENABLE);
 * }
 * @endcode
 */
void System_WakeUpAdapterCmd(SystemWakeUpPolarity_TypeDef WakeUpPolarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_MFB_WAKEUP == 1)
/**
 * @brief Configure the MFB wake-up system function in power off (shipping) mode.
 *
 * @param[in] NewState  Enable or disable the MFB wake up.
 *                      - ENABLE: Enable the MFB wake-up system.
 *                      - DISABLE: Disable the MFB wake-up system.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void mfb_wake_up_enable(void)
 * {
 *     System_WakeUpMFBCmd(ENABLE);
 * }
 * @endcode
 */
void System_WakeUpMFBCmd(FunctionalState NewState);
#endif

#if (PAD_SUPPORT_SHIP_MODE_PAD_CONFIG == 1)
/**
 * @brief Enable or disable the pad pull-down function in ship mode of the specified pin.
 *
 * @note  Only the following pins support this function:
 *        P0_2, P0_4, P3_2, P3_3, P4_0, P4_1, P4_2, P4_3, P6_0, SPIC_WEN and SPIC_HOLDEN.
 *        Calling this function for any other pins will be safely ignored.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the pad pull-down function in ship mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_ShipModePadPullDownCmd(P4_0, ENABLE);
 *     System_ShipModePadPullDownCmd(P4_1, ENABLE);
 * }
 * @endcode
 */
void System_ShipModePadPullDownCmd(uint8_t Pin_Num, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_DETECT_MODE == 1)
/**
 * @brief Select the DETECT mode of the PAD interrupt.
 *
 * @param[in] is_ldetect  Enable or disable the LDETECT.
 *                        - true: Enable the LDETECT.
 *                        - false: Disable the LDETECT.
 */
void System_SelectLDETECT(bool is_ldetect);
#endif

#if (PAD_SUPPORT_WAKEUP_POWER_DOWN == 1)
/**
 * @brief Enable or disable the wake-up Power Down (PD) function of the specified pin.
 *
 * @details Power Down (PD) mode disables most internal power domains. This function configures
 *          the PAD to monitor external signals and wake up the system from this ultra-low power state.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Polarity  Specifies the pin wake-up polarity. Refer to @ref WAKEUP_POLARITY.
 * @param[in] NewState  Enable or disable the wake-up Power Down function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     System_WakeUpPDCmd(P0_0, SYSTEM_WAKEUP_POLARITY_LOW, ENABLE);
 * }
 * @endcode
 */
void System_WakeUpPDCmd(uint8_t Pin_Num, uint8_t Polarity, FunctionalState NewState);
#endif

#if (PAD_SUPPORT_WAKEUP_PAD_SUB_IRQ == 1)
/**
 * @brief Register or unregister the wake-up callback function of the specified pin.
 *
 * @note  Calls with an invalid `Pin_Num` or a pin that lacks wake-up hardware capability
 *        will be silently ignored.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Callback  Function pointer to the user callback. Pass NULL to unregister.
 * @param[in] Context   User-defined context parameter passed to the callback function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void app_wakeup_callback(uint32_t context)
 * {
 *     uint8_t pin = (uint8_t)context;
 *     APP_PRINT_INFO1("System awoken by pin: %d", pin);
 * }
 *
 * void board_wakeup_init(void)
 * {
 *     System_WakeUpPinEnable(P0_0, SYSTEM_WAKEUP_POLARITY_LOW, ENABLE);
 *     System_RegisterPadWakeupCallback(P0_0, app_wakeup_callback, (uint32_t)P0_0);
 * }
 * @endcode
 */
void System_RegisterPadWakeupCallback(uint8_t Pin_Num, P_PAD_CBACK Callback, uint32_t Context);
#endif

/** @} */ /* End of group WAKEUP_Exported_Functions */

/** @} */ /* End of group PINMUX */

#ifdef __cplusplus
}
#endif

#endif /* RTL_WAKEUP_H */
