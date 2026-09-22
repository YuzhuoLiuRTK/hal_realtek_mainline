/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GRTC_H
#define RTL_GRTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "rtc/src/device/rtl87x2j/rtl_grtc_def.h"
#endif
#if defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "rtc/src/device/rtl87x3j/rtl_grtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "rtc/src/device/rtl87x3k/rtl_grtc_def.h"
#endif

/**
 * @defgroup GRTC_DRIVER DRIVER
 * @ingroup GRTC
 * @brief Global Real Time Counter (GRTC) driver.
 * @{
 */

/**
 * @defgroup GRTC_Exported_Constants GRTC Exported Constants
 * @{
 */

/**
 * @defgroup GRTC_COMPARATOR GRTC Comparator
 * @{
 * @ingroup GRTC_Exported_Constants
 */
typedef enum
{
    GRTC_COMP0 = 0x00,            /**< GRTC comparator index 0. */
#if (GRTC_COMP_NUM > 1)
    GRTC_COMP1 = 0x01,            /**< GRTC comparator index 1. */
#endif
#if (GRTC_COMP_NUM > 2)
    GRTC_COMP2 = 0x02,            /**< GRTC comparator index 2. */
#endif
#if (GRTC_COMP_NUM > 3)
    GRTC_COMP3 = 0x03,            /**< GRTC comparator index 3. */
#endif
#if (GRTC_COMP_NUM > 4)
    GRTC_COMP4 = 0x04,            /**< GRTC comparator index 4. */
#endif
#if (GRTC_COMP_NUM > 5)
    GRTC_COMP5 = 0x05,            /**< GRTC comparator index 5. */
#endif
#if (GRTC_COMP_NUM > 6)
    GRTC_COMP6 = 0x06,            /**< GRTC comparator index 6. */
#endif
#if (GRTC_COMP_NUM > 7)
    GRTC_COMP7 = 0x07,            /**< GRTC comparator index 7. */
#endif
#if (GRTC_COMP_NUM > 8)
    GRTC_COMP8 = 0x08,            /**< GRTC comparator index 8. */
#endif
#if (GRTC_COMP_NUM > 9)
    GRTC_COMP9 = 0x09,            /**< GRTC comparator index 9. */
#endif
} GRTCCompIndex_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GRTC_COMP(COMP)  ((COMP) < GRTC_COMP_NUM)

/** @} */ /* End of group GRTC_COMPARATOR */


/**
 * @defgroup GRTC_INTERRUPTS GRTC Interrupts
 * @{
 * @ingroup GRTC_Exported_Constants
 */
#define GRTC_INT_COMP0          BIT0            /**< GRTC CMP0 interrupt. */
#if (GRTC_COMP_NUM > 1)
#define GRTC_INT_COMP1          BIT1            /**< GRTC CMP1 interrupt. */
#endif
#if (GRTC_COMP_NUM > 2)
#define GRTC_INT_COMP2          BIT2            /**< GRTC CMP2 interrupt. */
#endif
#if (GRTC_COMP_NUM > 3)
#define GRTC_INT_COMP3          BIT3            /**< GRTC CMP3 interrupt. */
#endif
#if (GRTC_COMP_NUM > 4)
#define GRTC_INT_COMP4          BIT4            /**< GRTC CMP4 interrupt. */
#endif
#if (GRTC_COMP_NUM > 5)
#define GRTC_INT_COMP5          BIT5            /**< GRTC CMP5 interrupt. */
#endif
#if (GRTC_COMP_NUM > 6)
#define GRTC_INT_COMP6          BIT6            /**< GRTC CMP6 interrupt. */
#endif
#if (GRTC_COMP_NUM > 7)
#define GRTC_INT_COMP7          BIT7            /**< GRTC CMP7 interrupt. */
#endif
#if (GRTC_COMP_NUM > 8)
#define GRTC_INT_COMP8          BIT8            /**< GRTC CMP8 interrupt. */
#endif
#if (GRTC_COMP_NUM > 9)
#define GRTC_INT_COMP9          BIT9            /**< GRTC CMP9 interrupt. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GRTC_INT(INT)  ((INT) & (BIT(GRTC_COMP_NUM)  -1))

/** @} */ /* End of group GRTC_INTERRUPTS */

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup GRTC_ACTION GRTC Action
 * @{
 * @ingroup GRTC_Exported_Constants
 */
typedef enum
{
    GRTC_ACTION_RELOAD_COMP = 0,    /**< GRTC action reload comparator. */
} GRTCAction_TypeDef;

/** @} */ /* End of group GRTC_ACTION */
#endif

#if (GRTC_SUPPORT_RELOAD_MODE == 1)
/**
 * @defgroup GRTC_RELOAD_MODE GRTC Reload Mode
 * @{
 * @ingroup GRTC_Exported_Constants
 */
typedef enum
{
    GRTC_RELOAD_WITH_CURRENT_COMPARE = 0,    /**< Reload with current compare value. */
    GRTC_RELOAD_WITH_CURRENT_COUNTER = 1,    /**< Reload with current counter value. */
} GRTCReloadMode_TypeDef;

#define IS_GRTC_RELOAD_MODE(MODE)  (((MODE) == GRTC_RELOAD_WITH_CURRENT_COMPARE) || \
                                    ((MODE) == GRTC_RELOAD_WITH_CURRENT_COUNTER))   /**< Check if the reload mode is valid. @hideinitializer */
/** @} */ /* End of group GRTC_RELOAD_MODE */
#endif

/** @} */ /* End of group GRTC_Exported_Constants */

/**
 * @defgroup GRTC_Exported_Functions GRTC Exported Functions
 * @{
 */

/**
 * @brief Reset all registers of GRTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_DeInit();
 * }
 * @endcode
 */
void GRTC_DeInit(void);

/**
 * @brief Enable or disable the specified GRTC interrupt.
 *
 * @param[in] GRTC_INT Specifies the GRTC interrupt source which to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            - GRTC_INT_COMP0: Compare 0 interrupt source.
 *            - GRTC_INT_COMP1: Compare 1 interrupt source.
 *            - GRTC_INT_COMP2: Compare 2 interrupt source.
 *            - GRTC_INT_COMP3: Compare 3 interrupt source.
 *            - GRTC_INT_COMP4: Compare 4 interrupt source.
 *            - GRTC_INT_COMP5: Compare 5 interrupt source.
 *            - GRTC_INT_COMP6: Compare 6 interrupt source.
 *            - GRTC_INT_COMP7: Compare 7 interrupt source.
 * @param[in] NewState New state of the specified GRTC interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_grtc_init(void)
 * {
 *     GRTC_INTConfig(GRTC_INT_COMP0, ENABLE);
 * }
 * @endcode
 */
void GRTC_INTConfig(uint32_t GRTC_INT, FunctionalState NewState);

/**
 * @brief Get the specified GRTC interrupt status.
 *
 * @param[in] GRTC_INT Specifies the GRTC interrupt source to be checked.
 *            This parameter can be any combination of the following values:
 *            - GRTC_INT_COMP0: Compare 0 interrupt source.
 *            - GRTC_INT_COMP1: Compare 1 interrupt source.
 *            - GRTC_INT_COMP2: Compare 2 interrupt source.
 *            - GRTC_INT_COMP3: Compare 3 interrupt source.
 *            - GRTC_INT_COMP4: Compare 4 interrupt source.
 *            - GRTC_INT_COMP5: Compare 5 interrupt source.
 *            - GRTC_INT_COMP6: Compare 6 interrupt source.
 *            - GRTC_INT_COMP7: Compare 7 interrupt source.
 *
 * @return The new state of GRTC_INT.
 * @retval SET    The GRTC interrupt has occurred.
 * @retval RESET  The GRTC interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     ITStatus int_status = GRTC_GetINTStatus(GRTC_INT_COMP0);
 * }
 * @endcode
 */
ITStatus GRTC_GetINTStatus(uint32_t GRTC_INT);

/**
 * @brief Clear the interrupt pending bit of GRTC.
 *
 * @param[in] GRTC_INT Specifies the GRTC interrupt flag to clear.
 *            This parameter can be any combination of the following values:
 *            - GRTC_INT_COMP0: Compare 0 interrupt source.
 *            - GRTC_INT_COMP1: Compare 1 interrupt source.
 *            - GRTC_INT_COMP2: Compare 2 interrupt source.
 *            - GRTC_INT_COMP3: Compare 3 interrupt source.
 *            - GRTC_INT_COMP4: Compare 4 interrupt source.
 *            - GRTC_INT_COMP5: Compare 5 interrupt source.
 *            - GRTC_INT_COMP6: Compare 6 interrupt source.
 *            - GRTC_INT_COMP7: Compare 7 interrupt source.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ClearINTPendingBit(GRTC_INT_COMP0);
 * }
 * @endcode
 */
void GRTC_ClearINTPendingBit(uint32_t GRTC_INT);

#if (GRTC_SUPPORT_ERROR_INTERRUPT == 1)
/**
 * @brief Get the specified GRTC error interrupt status.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 *
 * @return The new state of GRTC error interrupt.
 * @retval SET    The GRTC error interrupt has occurred.
 * @retval RESET  The GRTC error interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     ITStatus int_status = GRTC_GetErrorINTStatus(GRTC_COMP0);
 * }
 * @endcode
 */
ITStatus GRTC_GetErrorINTStatus(GRTCCompIndex_TypeDef Index);

/**
 * @brief Clear the error interrupt pending bit of GRTC.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ClearErrorINTPendingBit(GRTC_COMP0);
 * }
 * @endcode
 */
void GRTC_ClearErrorINTPendingBit(GRTCCompIndex_TypeDef Index);
#endif

#if (GRTC_SUPPORT_FORCE_QACTIVE == 1)
/**
 * @brief Enable or Disable the GRTC force qactive function.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] NewState New state of GRTC peripheral.
 *            This parameter can be the following values:
 *            - ENABLE: Enable GRTC force qactive function.
 *            - DISABLE: Disable GRTC force qactive function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ForceQactiveCmd(GRTC_COMP0, ENABLE);
 * }
 * @endcode
 */
void GRTC_ForceQactiveCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);
#endif

/**
 * @brief Set GRTC comparator value.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] Value The comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define GRTC_COMP_INDEX          GRTC_COMP3
 * #define GRTC_COMP_VALUE          (1000)
 *
 * void driver_grtc_init(void)
 * {
 *     GRTC_SetCompValue(GRTC_COMP_INDEX, GRTC_COMP_VALUE);
 * }
 * @endcode
 */
void GRTC_SetCompValue(GRTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * @brief Get GRTC comparator value.
 *
 * @param[in] Index The comparator number.
 *
 * @return The comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     uint32_t data = GRTC_GetCompValue(GRTC_COMP0);
 * }
 * @endcode
 */
uint32_t GRTC_GetCompValue(GRTCCompIndex_TypeDef Index);

/**
 * @brief Enable or Disable the GRTC comparator reload function.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] NewState New state of GRTC peripheral.
 *            This parameter can be the following values:
 *            - ENABLE: Enable comparator reload function.
 *            - DISABLE: Disable comparator reload function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_CompReloadCmd(GRTC_COMP0, ENABLE);
 * }
 * @endcode
 */
void GRTC_CompReloadCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

#if (GRTC_SUPPORT_RELOAD_MODE == 1)
/**
 * @brief Config GRTC reload mode.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] Mode Reload mode.
 *         This parameter can be the following values:
 *         - GRTC_RELOAD_WITH_CURRENT_COMPARE: CMP = current compare + CMP_RELOAD.
 *         - GRTC_RELOAD_WITH_CURRENT_COUNTER: CMP = current counter + CMP_RELOAD.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_ReloadModeConfig(GRTC_COMP0, GRTC_RELOAD_WITH_CURRENT_COMPARE);
 * }
 * @endcode
 */
void GRTC_ReloadModeConfig(GRTCCompIndex_TypeDef Index, GRTCReloadMode_TypeDef Mode);
#endif
/**
 * @brief Set GRTC comparator reload value.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] Value The comparator reload value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_SetCompReloadValue(GRTC_COMP0, 1000);
 * }
 * @endcode
 */
void GRTC_SetCompReloadValue(GRTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * @brief Get GRTC comparator reload value.
 *
 * @param[in] Index The comparator number.
 *
 * @return The comparator reload value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     uint32_t data = GRTC_GetCompReloadValue(GRTC_COMP0);
 * }
 * @endcode
 */
uint32_t GRTC_GetCompReloadValue(GRTCCompIndex_TypeDef Index);

/**
 * @brief Enable or Disable the GRTC function of sleep control.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] NewState New state of GRTC peripheral.
 *            This parameter can be the following values:
 *            - ENABLE: Enable sleep control function.
 *            - DISABLE: Disable sleep control function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     GRTC_SleepCmd(GRTC_COMP0, ENABLE);
 * }
 * @endcode
 */
void GRTC_SleepCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

/**
 * @brief Get GRTC sleep counter.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 *
 * @return The sleep counter.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     uint32_t counter = GRTC_GetSleepCounter(GRTC_COMP0);
 * }
 * @endcode
 */
uint32_t GRTC_GetSleepCounter(GRTCCompIndex_TypeDef Index);

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or Disable the GRTC RAP mode function.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] NewState New state of GRTC peripheral.
 *            This parameter can be the following values:
 *            - ENABLE: Enable GRTC RAP mode function.
 *            - DISABLE: Disable GRTC RAP mode function.
 *
 * @return The result of config GRTC RAP mode function.
 * @retval true  Config GRTC RAP mode function success.
 * @retval false The GRTC comp is not support RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     bool ret = GRTC_RAPModeCmd(GRTC_COMP0, ENABLE);
 * }
 * @endcode
 */
bool GRTC_RAPModeCmd(GRTCCompIndex_TypeDef Index, FunctionalState NewState);

/**
 * @brief Trigger a GRTC task.
 *
 * @param[in] Index Specifies the comparator number. Refer to @ref GRTC_COMPARATOR
 * @param[in] Action The task to be triggered.
 *            This parameter can be the following values:
 *            - GRTC_ACTION_RELOAD_COMP: GRTC action reload comparator.
 *
 * @return The result of trigger a GRTC task.
 * @retval true  Config trigger a GRTC task success.
 * @retval false The GRTC comp is not support to trigger a GRTC task.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void grtc_demo(void)
 * {
 *     bool ret = GRTC_ActionTrigger(GRTC_COMP0, GRTC_ACTION_RELOAD_COMP);
 * }
 * @endcode
 */
bool GRTC_ActionTrigger(GRTCCompIndex_TypeDef Index, uint32_t Action);

#endif

/** @} */ /* End of group GRTC_Exported_Functions */

/** @} */ /* End of group GRTC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GRTC_H */
