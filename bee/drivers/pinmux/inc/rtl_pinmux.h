/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_PINMUX_H
#define RTL_PINMUX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#include "pinmux/inc/rtl_wakeup.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "pinmux/src/device/rtl87x2g/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "pinmux/src/device/rtl87x3d/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pinmux/src/device/rtl87x2j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "pinmux/src/device/rtl87x3j/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "pinmux/src/device/rtl87x3k/rtl_pinmux_def.h"
#include "pinmux/inc/rtl87x3k/pin_def.h"
#endif

/**
 * @defgroup PINMUX_DRIVER DRIVER
 * @ingroup PINMUX
 * @brief Pinmux and PAD driver.
 * @{
 */

/**
 * @defgroup PINMUX_Exported_Constants PINMUX Exported Constants
 * @{
 */

/**
 * @defgroup PAD_POWER_MODE PAD Power Mode
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_NOT_PWRON,     /**< Disable pad power mode. */
    PAD_IS_PWRON = 1   /**< Enable pad power mode. */
} PADPowerMode_TypeDef;

/** @} */ /* End of group PAD_POWER_MODE */

/**
 * @defgroup PAD_OUTPUT_DIRECTION PAD Output Direction
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_OUT_DISABLE,   /**< Disable pad output. */
    PAD_OUT_ENABLE     /**< Enable pad output. */
} PADOutputMode_TypeDef;

/** @} */ /* End of group PAD_OUTPUT_DIRECTION */

/**
 * @defgroup PAD_OUTPUT_VALUE PAD Output Value
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_OUT_LOW,     /**< The pad outputs a low level. */
    PAD_OUT_HIGH     /**< The pad outputs a high level. */
} PADOutputValue_TypeDef;

/** @} */ /* End of group PAD_OUTPUT_VALUE */

/**
 * @defgroup PAD_PULL_MODE PAD Pull Mode
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_PULL_DOWN,     /**< Enable the pull-down resistor function for the pad. */
    PAD_PULL_UP,       /**< Enable the pull-up resistor function for the pad. */
    PAD_PULL_NONE,     /**< Pad is in a floating state. */
} PADPullMode_TypeDef;

/** @} */ /* End of group PAD_PULL_MODE */

/**
 * @defgroup PAD_PULL_STRENGTH_MODE PAD Pull Strength Mode
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_PULL_WEAK,       /**< PAD pull mode is weak pull mode. */
    PAD_PULL_STRONG,     /**< PAD pull mode is strong pull mode. */
} PADPullStrengthMode_TypeDef;

/** @} */ /* End of group PAD_PULL_STRENGTH_MODE */

/**
 * @defgroup PAD_MODE PAD Mode
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_SW_MODE,            /**< PAD is configured in software mode. */
#if (PAD_SUPPORT_CONFIG_PON_DOMAIN == 1)
    PAD_PON_MODE,           /**< PAD is configured in pon domain mode. */
#endif
    PAD_PINMUX_MODE,        /**< PAD is configured in pinmux mode. */
} PADMode_TypeDef;

/** @} */ /* End of group PAD_MODE */

#if (PAD_SUPPORT_ANALOG_MODE == 1)
/**
 * @defgroup PAD_ANALOG_MODE PAD Analog Mode
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum
{
    PAD_ANALOG_MODE,     /**< Config Hybrid pad analog function. */
    PAD_DIGITAL_MODE,    /**< Config Hybrid pad digital function. */
} PADAnalog_TypeDef;

/** @} */ /* End of group PAD_ANALOG_MODE */
#endif

#if (PAD_SUPPORT_GET_OUTPUT_CTRL == 1)
/**
 * @defgroup PAD_AON_STATUS PAD AON Status
 * @{
 * @ingroup PINMUX_Exported_Constants
 */
typedef enum _PAD_AON_Status
{
    PAD_AON_OUTPUT_LOW,        /**< Pad AON output low level. */
    PAD_AON_OUTPUT_HIGH,       /**< Pad AON output high level. */
    PAD_AON_OUTPUT_DISABLE,    /**< Pad AON output disable. */
    PAD_AON_PINMUX_ON,         /**< Pad AON pinmux on. */
    PAD_AON_PIN_ERR            /**< Pad AON pin error. */
} PAD_AON_Status;

/** @} */ /* End of group PAD_AON_STATUS */
#endif

/** @} */ /* End of group PINMUX_Exported_Constants */

/**
 * @defgroup PINMUX_Exported_Functions PINMUX Exported Functions
 * @{
 * @ingroup PINMUX
 */

/**
 * @brief Reset the PINMUX settings to idle mode of all pins.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pinmux_Reset();
 * }
 * @endcode
 */
void Pinmux_Reset(void);

/**
 * @brief Configure the PINMUX settings to idle mode of the specified pad.
 *
 * @param[in] Pin_Num Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pinmux_Deinit(P2_2);
 * }
 * @endcode
 */
void Pinmux_Deinit(uint8_t Pin_Num);

/**
 * @brief Configure the specified pad to its corresponding peripheral function.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Pin_Func  Specifies the peripheral function. Refer to @ref PIN_FUNCTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     Pinmux_Config(P0_0, UART0_TX);
 *     Pinmux_Config(P0_1, UART0_RX);
 * }
 * @endcode
 */
void Pinmux_Config(uint8_t Pin_Num, uint32_t Pin_Func);

/**
 * @brief Configure the operation mode which includes pad mode, power mode,
 *        pull resistor, and output behavior of a specified pad.
 *
 * @note The output level (AON_PAD_O) is only effective when the pad is configured
 *       in Software Mode (PAD_SW_MODE) with Output Enabled (PAD_OUT_ENABLE).
 *       When using Pinmux Mode, the output behavior is driven by the peripheral.
 *
 * @param[in] Pin_Num        Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] AON_PAD_Mode   Specifies the pad mode of the specified pin. Refer to @ref PAD_MODE.
 * @param[in] AON_PAD_PwrOn  Specifies the power mode of the specified pin. Refer to @ref PAD_POWER_MODE.
 * @param[in] AON_PAD_Pull   Specifies the pull mode of the specified pin. Refer to @ref PAD_PULL_MODE.
 * @param[in] AON_PAD_E      Specifies the output direction of the specified pin. Refer to @ref PAD_OUTPUT_DIRECTION.
 * @param[in] AON_PAD_O      Specifies the output value of the specified pin. Refer to @ref PAD_OUTPUT_VALUE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     Pad_Config(P0_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
 *     Pad_Config(P0_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
 * }
 * @endcode
 */
void Pad_Config(uint8_t                 Pin_Num,
                PADMode_TypeDef         AON_PAD_Mode,
                PADPowerMode_TypeDef    AON_PAD_PwrOn,
                PADPullMode_TypeDef     AON_PAD_Pull,
                PADOutputMode_TypeDef   AON_PAD_E,
                PADOutputValue_TypeDef  AON_PAD_O);

#if (PAD_SUPPORT_CONFIG_EXT == 1)
/**
 * @brief Configure the operation mode which includes pad mode, power mode,
 *        pull resistor, and output behavior of a specified pad.
 *
 * @param[in] Pin_Num        Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] AON_PAD_Mode   Specifies the pad mode of the specified pin. Refer to @ref PAD_MODE.
 * @param[in] AON_PAD_PwrOn  Specifies the power mode of the specified pin. Refer to @ref PAD_POWER_MODE.
 * @param[in] AON_PAD_Pull   Specifies the pull mode of the specified pin. Refer to @ref PAD_PULL_MODE.
 * @param[in] AON_PAD_E      Specifies the output direction of the specified pin. Refer to @ref PAD_OUTPUT_DIRECTION.
 * @param[in] AON_PAD_O      Specifies the output value of the specified pin. Refer to @ref PAD_OUTPUT_VALUE.
 * @param[in] AON_PAD_P      Specifies the pull resistor of the specified pin. Refer to @ref PAD_PULL_STRENGTH_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *     Pad_ConfigExt(P0_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_150K_PULL);
 *     Pad_ConfigExt(P0_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_150K_PULL);
 * }
 * @endcode
 */
extern void Pad_ConfigExt(uint8_t Pin_Num,
                          PADMode_TypeDef             AON_PAD_Mode,
                          PADPowerMode_TypeDef        AON_PAD_PwrOn,
                          PADPullMode_TypeDef         AON_PAD_Pull,
                          PADOutputMode_TypeDef       AON_PAD_E,
                          PADOutputValue_TypeDef      AON_PAD_O,
                          PADPullStrengthMode_TypeDef AON_PAD_P);
#endif

#if (PAD_SUPPORT_LOWER_POWER_CONFIG == 1)
/**
 * @brief Configures the pull-up/pull-down resistor of the specified pad specifically for DLPS.
 *
 * @note This pull configuration is ONLY effective when the system enters DLPS.
 *       Upon waking up (exiting DLPS), the pad's pull state will automatically
 *       revert to the active state configuration set by `Pad_Config()`.
 *
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] AON_PAD_Pull  Specifies the desired pull state during DLPS.
 * @param[in] NewState      ENABLE to apply this low power configuration, DISABLE to ignore it.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_LPConfig(P0_0, PAD_PULL_UP, ENABLE);
 * }
 * @endcode
 */
void Pad_LPConfig(uint8_t Pin_Num, PADPullMode_TypeDef AON_PAD_Pull, FunctionalState NewState);

/**
 * @brief Enables or disables the automatic pad mode switching during DLPS entry/exit.
 *
 * @details - **Default Behavior**: When a pin is configured to `PAD_PINMUX_MODE` via `Pad_Config()`,
 *            this auto-switch feature is enabled by default. The hardware will automatically switch
 *            the pad to `PAD_SW_MODE` when entering DLPS, and restore it to `PAD_PINMUX_MODE` upon wake-up.
 *          - **Special Use Case (Disable)**: Firmware needs to manually disable this feature if an
 *            active GPIO needs to maintain/retain its exact output level (High or Low) during DLPS.
 *            Disabling it prevents the hardware from altering the pad's state during sleep transition.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  ENABLE to allow automatic mode switching,
 *                      DISABLE to hold the current mode/state during DLPS.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_ModeAutoSwitchCmd(P0_0, DISABLE);
 * }
 * @endcode
 */
void Pad_ModeAutoSwitchCmd(uint8_t Pin_Num, FunctionalState NewState);

#endif

/**
 * @brief Configure the PAD settings to the default state of all pads.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_AllConfigDefault();
 * }
 * @endcode
 */
void Pad_AllConfigDefault(void);

#if (PAD_SUPPORT_FUNCTION_CONFIG == 1)
/**
 * @brief Configures a specific peripheral function of a specified pad.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Pad_Func  Specifies the target peripheral function. Refer to @ref PAD_FUNCTION_CONFIG.
 *
 * @return The execution result of configuring the pad function.
 * @retval true   Configuration successful.
 * @retval false  Invalid pin number. The specified Pad_Func is disabled in this case.
 */
bool Pad_FunctionConfig(uint8_t Pin_Num, PADFuncConfig_TypeDef Pad_Func);
#endif

#if (PAD_SUPPORT_HIGH_SPEED_CONFIG == 1)
/**
 * @brief Enables or disables the dedicated high-speed function for specific peripherals.
 *
 * @details High-speed mode bypasses the normal path to support high-frequency signals (e.g., SPI0/1/2).
 *          When enabled, the corresponding normal path is automatically disabled to prevent signal conflict.
 *
 * @param[in] Pin_Group      Pointer to an array of pins for the high-speed configuration.
 * @param[in] Pin_GroupLen   The number of pins in the Pin_Group array.
 * @param[in] Pad_HighSpeed  Specifies the high-speed peripheral. Refer to @ref PAD_HIGH_SPEED_CONFIG.
 * @param[in] NewState       ENABLE or DISABLE to activate the high-speed path.
 *
 * @return The execution result of configuring the high-speed function.
 * @retval true   Configuration successful.
 * @retval false  Configuration failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     // RTL87x2J SPI High-Speed function is available on fixed pins.
 *     uint8_t spi_pins[] = {P4_0, P4_1, P4_2, P4_3};
 *     Pad_HighSpeedConfig(spi_pins, sizeof(spi_pins), PAD_HIGH_SPEED_SPI0, ENABLE);
 * }
 * @endcode
 */
bool Pad_HighSpeedConfig(uint8_t *Pin_Group, uint8_t Pin_GroupLen,
                         PADHSConfig_Typedef Pad_HighSpeed, FunctionalState NewState);
#endif

/**
 * @brief Configure the driving current of the specified pad.
 *
 * @param[in] Pin_Num             Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_DrivingCurrent  The desired driving current. Refer to @ref PAD_DRIVING_CURRENT.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_SetDrivingCurrent(P0_0, PAD_DRIVING_CURRENT_4mA);
 * }
 * @endcode
 */
void Pad_SetDrivingCurrent(uint8_t Pin_Num, PADDrivingCurrent_TypeDef PAD_DrivingCurrent);

/**
 * @brief Configure the pad control mode of the specified pad.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_Mode  Specifies the control mode. Refer to @ref PAD_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_SetControlMode(P0_0, PAD_SW_MODE);
 * }
 * @endcode
 */
void Pad_SetControlMode(uint8_t Pin_Num, PADMode_TypeDef PAD_Mode);

/**
 * @brief Enable or disable the output mode of the specified pad.
 *
 * @note This setting only takes effect when the pad configured as in `PAD_SW_MODE`.
 *
 * @param[in] Pin_Num    Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_OutEn  Enable or disable the output mode. Refer to @ref PAD_OUTPUT_DIRECTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_OutputCmd(P0_0, PAD_OUT_ENABLE);
 * }
 * @endcode
 */
void Pad_OutputCmd(uint8_t Pin_Num, PADOutputMode_TypeDef PAD_OutEn);

/**
 * @brief Configure the output level of the specified pad.
 *
 * @note This setting only takes effect when the pad is configured as `PAD_SW_MODE`
 *       and output mode is configured as `PAD_OUT_ENABLE`.
 *
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_OutValue  The desired output logic level. Refer to @ref PAD_OUTPUT_VALUE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_SetOutputLevel(P0_0, PAD_OUT_HIGH);
 * }
 * @endcode
 */
void Pad_SetOutputLevel(uint8_t Pin_Num, PADOutputValue_TypeDef PAD_OutValue);

/**
 * @brief Enable or disable the internal pull-up / pull-down resistor of the specified pad.
 *
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the internal pull-up / pull-down resistor. Refer to @ref FunctionalState.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_PullCmd(P0_0, ENABLE);
 * }
 * @endcode
 */
void Pad_PullCmd(uint8_t Pin_Num, FunctionalState NewState);

/**
 * @brief Configure the pull mode of the specified pad.
 *
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PullMode  The desired pull state. Refer to @ref PAD_PULL_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_SetPullMode(P0_0, PAD_PULL_UP);
 * }
 * @endcode
 */
void Pad_SetPullMode(uint8_t Pin_Num, PADPullMode_TypeDef PAD_PullMode);

/**
 * @brief Configure the resistance strength of the internal pull-up/pull-down.
 *
 * @param[in] Pin_Num               Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PullStrengthMode  The desired pull strength. Refer to @ref PAD_PULL_STRENGTH_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_SetPullStrength(P0_0, PAD_PULL_STRONG);
 * }
 * @endcode
 */
void Pad_SetPullStrength(uint8_t Pin_Num, PADPullStrengthMode_TypeDef PAD_PullStrengthMode);

/**
 * @brief Configure the power mode of the specified pad.
 *
 * @param[in] Pin_Num        Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PowerMode  Specifies the power mode. Refer to @ref PAD_POWER_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_init(void)
 * {
 *     Pad_PowerCmd(P0_0, PAD_NOT_PWRON);
 * }
 * @endcode
 */
void Pad_PowerCmd(uint8_t Pin_Num, PADPowerMode_TypeDef PAD_PowerMode);

#if (PAD_SUPPORT_ANALOG_MODE == 1)
/**
 * @brief Configure the hybrid pad analog/digital function.
 *
 * @param[in] pin             Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_AnalogMode  Analog or digital mode. Refer to @ref PADAnalog_TypeDef.
 *                            - PAD_ANALOG_MODE: Configure pad analog function.
 *                            - PAD_DIGITAL_MODE: Configure pad digital function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_AnalogMode(P0_0, PAD_ANALOG_MODE);
 * }
 * @endcode
 */
void Pad_AnalogMode(uint8_t pin, PADAnalog_TypeDef PAD_AnalogMode);
#endif

#if (PAD_SUPPORT_GET_OUTPUT_CTRL == 1)
/**
 * @brief Get pad current output/input setting.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return Current output/input setting of the pad. Refer to @ref PAD_AON_Status.
 * @retval PAD_AON_OUTPUT_LOW     Pad AON output low level.
 * @retval PAD_AON_OUTPUT_HIGH    Pad AON output high level.
 * @retval PAD_AON_OUTPUT_DISABLE Pad AON output disable.
 * @retval PAD_AON_PINMUX_ON      Pad AON pinmux on.
 * @retval PAD_AON_PIN_ERR        Pad AON pin error.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     if (Pad_GetOutputCtrl(P0_0) == PAD_AON_OUTPUT_LOW)
 *     {
 *         // Add user code here.
 *     }
 * }
 * @endcode
 */
uint8_t Pad_GetOutputCtrl(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_GET_POWER_GROUP == 1)
/**
 * @brief Retrieve the hardware power group for the specified pad.
 *
 * @details This function determines which power domain (Left, Right, or Bottom) the
 *          specified pin belongs to. This is particularly useful when configuring
 *          hardware features that operate at the group level.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The corresponding power group of the pin. Refer to @ref PAD_POWER_GROUP.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     PADPowerGroup_TypeDef power_group = Pad_GetPowerGroup(P0_0);
 * }
 * @endcode
 */
PADPowerGroup_TypeDef  Pad_GetPowerGroup(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_GET_PIN_NAME == 1)
/**
 * @brief Get the string representation of the pin name.
 *
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return Pointer to a constant string containing the pin name.
 * @retval Valid pin index Corresponding pin name string (e.g. "P0_0").
 * @retval NULL            Invalid pin index.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     const char *pin_name = Pad_GetPinName(P0_0);
 * }
 * @endcode
 */
const char *Pad_GetPinName(uint8_t Pin_Num);
#endif

#if (PAD_SUPPORT_SELECT_CONTROL_CORE == 1)
/**
 * @brief Select the PAD pinmux VCORE domain.
 *
 * @param[in] pin              Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] pad_core_domain  VCORE domain selection. Refer to @ref PADCoreSelect_TypeDef.
 *                             This parameter can be @ref PAD_VCORE_Select.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     Pad_SelectCore(P0_1, PAD_CORE_SEL_APP);
 * }
 * @endcode
 */
void Pad_SelectCore(uint8_t pin, PADCoreSelect_TypeDef pad_core_domain);
#endif

#if (PAD_SUPPORT_GET_SELECT_CONTROL_CORE == 1)
/**
 * @brief Get the selected VCORE domain.
 *
 * @param[in] pin  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The selected VCORE domain. Refer to @ref PADCoreSelect_TypeDef.
 *         This parameter can be @ref PAD_VCORE_Select.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void pad_demo(void)
 * {
 *     PADCoreSelect_TypeDef pad_core = Pad_GetSelectCore(P0_1);
 * }
 * @endcode
 */
PADCoreSelect_TypeDef Pad_GetSelectCore(uint8_t pin);
#endif

/** @} */ /* End of group PINMUX_Exported_Functions */

/** @} */ /* End of group PINMUX_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_PINMUX_H */
