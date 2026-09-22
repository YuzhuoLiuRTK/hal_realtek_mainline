/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPPWM_H
#define RTL_LPPWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pwm/src/device/rtl87x2j/rtl_lppwm_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "pwm/src/device/rtl87x3k/rtl_lppwm_def.h"
#endif

/**
 * @defgroup LPPWM_DRIVER DRIVER
 * @ingroup LPPWM
 * @brief Low Power Pulse Width Modulation (LPPWM) driver.
 * @{
 */

/**
 * @defgroup LPPWM_Exported_Constants LPPWM Exported Constants
 * @{
 */

/**
 * @defgroup LPPWM_OUTPUT_POLARITY LPPWM Output Polarity
 * @{
 * @ingroup LPPWM_Exported_Constants
 */

/**
 * @brief LPPWM output polarity.
 *
 * @ingroup LPPWM_Exported_Constants
 */
typedef enum
{
    LPPWM_POLARITY_NORMAL = 0x0,    /**< Normal polarity. */
    LPPWM_POLARITY_INVERT = 0x1,    /**< Inverted polarity. */
} LPPWMPolarity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPPWM_POLARITY(POLARITY)   (((POLARITY) == LPPWM_POLARITY_NORMAL ) || \
                                       ((POLARITY) == LPPWM_POLARITY_INVERT))

/** @} */ /* End of group LPPWM_OUTPUT_POLARITY */


/** @brief Check if the period count is valid. @hideinitializer */
#define IS_LPPWM_PERIOD(PERIOD)       ((PERIOD) <= LPPWM_PERIOD_MAX)

/** @} */ /* End of group LPPWM_Exported_Constants */

/**
 * @defgroup LPPWM_Exported_Types LPPWM Exported Types
 * @{
 */

/**
 * @brief LPPWM init structure definition.
 *
 * @ingroup LPPWM_Exported_Types
 */
typedef struct
{
    uint32_t LPPWM_Polarity;             /**< Specifies the LPPWM Output pin polarity.
                                              This parameter can be a value of @ref LPPWMPolarity_TypeDef. */

    uint32_t LPPWM_PeriodHigh;            /**< Specifies the LPPWM High Count.
                                               High period = LPPWM_PeriodHigh / CLK, where CLK is 32 kHz
                                               or 32.768 kHz. Must not exceed 0xFFFF. */

    uint32_t LPPWM_PeriodLow;             /**< Specifies the LPPWM Low Count.
                                               Low period = LPPWM_PeriodLow / CLK, where CLK is 32 kHz
                                               or 32.768 kHz. Must not exceed 0xFFFF. */

#if (LPPWM_SUPPORT_GPIO_SELECT == 1)
    uint32_t LPPWM_GPIOSel;               /**< Specifies the dedicated output pin.
                                               This parameter can be a value of @ref LPPWMGPIOSel_TypeDef. */
#endif

} LPPWM_InitTypeDef;

/** @} */ /* End of group LPPWM_Exported_Types */

/**
 * @defgroup LPPWM_Exported_Functions LPPWM Exported Functions
 * @{
 */
/**
 * @brief Deinitializes the LPPWM peripheral registers to their default values.
 *
 * @note  Asserts the channel register reset, which clears LPPWM_CH0_EN,
 *        LPPWM_CH0_POLARITY, LPPWM_CH0_P0_H and LPPWM_CH0_P0_L, then releases it
 *        so the registers are writable again.
 *
 * @param[in] LPPWMx Pointer to the LPPWM peripheral registers.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_deinit(void)
 * {
 *     LPPWM_DeInit(LPPWM);
 * }
 * @endcode
 */
void LPPWM_DeInit(LPPWM_TypeDef *LPPWMx);

/**
 * @brief Initializes the LPPWM peripheral according to the specified parameters.
 *
 * @param[in] LPPWMx           Pointer to the LPPWM peripheral registers.
 * @param[in] LPPWM_InitStruct Pointer to the LPPWM initialization structure.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_InitTypeDef LPPWM_InitStruct;
 *     LPPWM_StructInit(&LPPWM_InitStruct);
 *     LPPWM_InitStruct.LPPWM_Polarity   = LPPWM_POLARITY_NORMAL;
 *     LPPWM_InitStruct.LPPWM_PeriodHigh = 100;
 *     LPPWM_InitStruct.LPPWM_PeriodLow  = 100;
 *     LPPWM_Init(LPPWM, &LPPWM_InitStruct);
 *     LPPWM_Cmd(LPPWM, ENABLE);
 * }
 * @endcode
 */
void LPPWM_Init(LPPWM_TypeDef *LPPWMx, LPPWM_InitTypeDef *LPPWM_InitStruct);

/**
 * @brief Fills each LPPWM_InitStruct member with its default value.
 *
 * @param[in] LPPWM_InitStruct Pointer to the LPPWM initialization structure.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_InitTypeDef LPPWM_InitStruct;
 *     LPPWM_StructInit(&LPPWM_InitStruct);
 *     LPPWM_InitStruct.LPPWM_PeriodHigh = 100;
 *     LPPWM_InitStruct.LPPWM_PeriodLow  = 100;
 *     LPPWM_Init(LPPWM, &LPPWM_InitStruct);
 * }
 * @endcode
 */
void LPPWM_StructInit(LPPWM_InitTypeDef *LPPWM_InitStruct);

/**
 * @brief Enable or disable LPPWM peripheral.
 *
 * @param[in] LPPWMx   Pointer to the LPPWM peripheral registers.
 * @param[in] NewState New state of the LPPWM peripheral.
 *                     - ENABLE: Enable LPPWM.
 *                     - DISABLE: Disable LPPWM.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_enable(void)
 * {
 *     LPPWM_Cmd(LPPWM, ENABLE);
 * }
 * @endcode
 */
void LPPWM_Cmd(LPPWM_TypeDef *LPPWMx, FunctionalState NewState);

#if (LPPWM_SUPPORT_GPIO_SELECT == 1)
/**
 * @brief Select the dedicated LPPWM output pin.
 *
 * @param[in] LPPWMx   Pointer to the LPPWM peripheral registers.
 * @param[in] GPIOSel  Output pin. This parameter can be a value of @ref LPPWMGPIOSel_TypeDef;
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_select_pin(void)
 * {
 *     LPPWM_GPIOSelect(LPPWM, LPPWM_GPIO_P2_0);
 * }
 * @endcode
 */
void LPPWM_GPIOSelect(LPPWM_TypeDef *LPPWMx, uint32_t GPIOSel);
#endif /* LPPWM_SUPPORT_GPIO_SELECT */

/**
 * @brief Change LPPWM output frequency and duty cycle.
 *
 * @param[in] LPPWMx      Pointer to the LPPWM peripheral registers.
 * @param[in] period_high LPPWM high period count. Must not exceed @ref LPPWM_PERIOD_MAX.
 * @param[in] period_low  LPPWM low period count. Must not exceed @ref LPPWM_PERIOD_MAX.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_change_freq_and_duty(void)
 * {
 *     LPPWM_ChangeFreqAndDuty(LPPWM, 100, 100);
 * }
 * @endcode
 */
void LPPWM_ChangeFreqAndDuty(LPPWM_TypeDef *LPPWMx, uint32_t period_high, uint32_t period_low);

/**
 * @brief Get LPPWM current counter value.
 *
 * @param[in] LPPWMx Pointer to the LPPWM peripheral registers.
 *
 * @return The current counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lppwm_get_current_value(void)
 * {
 *     uint32_t current_value = LPPWM_GetCurrentValue(LPPWM);
 * }
 * @endcode
 */
uint32_t LPPWM_GetCurrentValue(LPPWM_TypeDef *LPPWMx);

/** @} */ /* End of group LPPWM_Exported_Functions */

/** @} */ /* End of group LPPWM_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPPWM_H */
