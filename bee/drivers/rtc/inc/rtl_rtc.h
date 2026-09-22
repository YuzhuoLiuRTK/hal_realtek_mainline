/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_RTC_H
#define RTL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "rtc/src/device/rtl87x2g/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "rtc/src/device/rtl87x3d/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "rtc/src/device/rtl87x2j/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "rtc/src/device/rtl87x3j/rtl_rtc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "rtc/src/device/rtl87x3k/rtl_rtc_def.h"
#endif

/**
 * @defgroup RTC_DRIVER DRIVER
 * @ingroup RTC
 * @brief Real Time Counter (RTC) driver.
 * @{
 */

/**
 * @defgroup RTC_Exported_Constants RTC Exported Constants
 * @{
 */

/**
 * @defgroup RTC_COMPARE_INDEX RTC Compare Index
 * @{
 * @ingroup RTC_Exported_Constants
 */
typedef enum
{
    RTC_COMP0 = 0x00,    /**< RTC comparator index0. */
    RTC_COMP1 = 0x01,    /**< RTC comparator index1. */
    RTC_COMP2 = 0x02,    /**< RTC comparator index2. */
    RTC_COMP3 = 0x03,    /**< RTC comparator index3. */
} RTCCompIndex_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_COMPARE(COMP) (((COMP) == RTC_COMP0) || \
                              ((COMP) == RTC_COMP1) || \
                              ((COMP) == RTC_COMP2) || \
                              ((COMP) == RTC_COMP3))

/** @} */ /* End of group RTC_COMPARE_INDEX */

/**
 * @defgroup RTC_INTERRUPTS RTC Interrupts
 * @{
 * @ingroup RTC_Exported_Constants
 */
#define RTC_INT_TICK                (BIT8)      /**< RTC tick interrupt. */
#define RTC_INT_OVERFLOW            (BIT9)      /**< RTC overflow interrupt. */
#define RTC_INT_PRECOMP             (BIT10)     /**< RTC PRECOMP interrupt. */
#define RTC_INT_PRECOMP_COMP3       (BIT11)     /**< RTC PRECOMP&CMP3 interrupt. */
#define RTC_INT_COMP0               (BIT16)     /**< RTC CMP0 interrupt. */
#define RTC_INT_COMP1               (BIT17)     /**< RTC CMP1 interrupt. */
#define RTC_INT_COMP2               (BIT18)     /**< RTC CMP2 interrupt. */
#define RTC_INT_COMP3               (BIT19)     /**< RTC CMP3 interrupt. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_INTERRUPT(INT)       (((INT) == RTC_INT_TICK) || \
                                     ((INT) == RTC_INT_OVERFLOW) || \
                                     ((INT) == RTC_INT_PRECOMP) || \
                                     ((INT) == RTC_INT_PRECOMP_COMP3) || \
                                     ((INT) == RTC_INT_COMP0) || \
                                     ((INT) == RTC_INT_COMP1) || \
                                     ((INT) == RTC_INT_COMP2) || \
                                     ((INT) == RTC_INT_COMP3))

/** @} */ /* End of group RTC_INTERRUPTS */

/**
 * @defgroup RTC_WAKEUP RTC WakeUp
 * @{
 * @ingroup RTC_Exported_Constants
 */
#if (RTC_SUPPORT_WAKEUP_MORE_SOURCE == 1)
#define RTC_WAKEUP_TICK             (BIT8)      /**< RTC tick wakeup interrupt. */
#define RTC_WAKEUP_OVERFLOW         (BIT9)      /**< RTC overflow wakeup interrupt. */
#define RTC_WAKEUP_PRECOMP          (BIT10)     /**< RTC PRECOMP wakeup interrupt. */
#define RTC_WAKEUP_PRECOMP_COMP3    (BIT11)     /**< RTC PRECOMP&CMP3 wakeup interrupt. */
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
#define RTC_WAKEUP_COMP0GT          (BIT12)     /**< RTC CMP0 GT wakeup interrupt. */
#define RTC_WAKEUP_COMP1GT          (BIT13)     /**< RTC CMP1 GT wakeup interrupt. */
#define RTC_WAKEUP_COMP2GT          (BIT14)     /**< RTC CMP2 GT wakeup interrupt. */
#define RTC_WAKEUP_COMP3GT          (BIT15)     /**< RTC CMP3 GT wakeup interrupt. */
#endif

#define RTC_WAKEUP_COMP0            (BIT20)     /**< RTC CMP0 wakeup interrupt. */
#define RTC_WAKEUP_COMP1            (BIT21)     /**< RTC CMP1 wakeup interrupt. */
#define RTC_WAKEUP_COMP2            (BIT22)     /**< RTC CMP2 wakeup interrupt. */
#define RTC_WAKEUP_COMP3            (BIT23)     /**< RTC CMP3 wakeup interrupt. */

#if (RTC_SUPPORT_WAKEUP_MORE_SOURCE == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP) (((WAKEUP) == RTC_WAKEUP_TICK) || \
                                           ((WAKEUP) == RTC_WAKEUP_OVERFLOW) || \
                                           ((WAKEUP) == RTC_WAKEUP_PRECOMP) || \
                                           ((WAKEUP) == RTC_WAKEUP_PRECOMP_COMP3))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP) (0)
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_WAKEUP_COMPGT(WAKEUP)      (((WAKEUP) == RTC_WAKEUP_COMP0GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP1GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP2GT) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP3GT))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_WAKEUP_COMPGT(WAKEUP)      (0)
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_WAKUP(WAKEUP)              (((WAKEUP) == RTC_WAKEUP_COMP0) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP1) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP2) || \
                                           ((WAKEUP) == RTC_WAKEUP_COMP3) || \
                                           (IS_RTC_WAKEUP_MORE_SOURCE(WAKEUP)) || \
                                           (IS_RTC_WAKEUP_COMPGT(WAKEUP)))
/** @} */ /* End of group RTC_WAKEUP */


#if (RTC_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup RTC_ACTION RTC Action
 * @{
 * @ingroup RTC_Exported_Constants
 */
typedef enum
{
    RTC_ACTION_START = 0,           /**< RTC action start. */
    RTC_ACTION_STOP  = 1,           /**< RTC action stop. */
    RTC_ACTION_CLEAR = 2,           /**< RTC action clear. */
    RTC_ACTION_RELOAD_COMP0 = 3,    /**< RTC action reload comparator 0. */
    RTC_ACTION_RELOAD_COMP1 = 4,    /**< RTC action reload comparator 1. */
    RTC_ACTION_RELOAD_COMP2 = 5,    /**< RTC action reload comparator 2. */
    RTC_ACTION_RELOAD_COMP3 = 6,    /**< RTC action reload comparator 3. */
} RTCAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_ACTION(ACTION)   (((ACTION) == RTC_ACTION_START) || \
                                 ((ACTION) == RTC_ACTION_STOP) || \
                                 ((ACTION) == RTC_ACTION_CLEAR) || \
                                 ((ACTION) == RTC_ACTION_RELOAD_COMP0) || \
                                 ((ACTION) == RTC_ACTION_RELOAD_COMP1) || \
                                 ((ACTION) == RTC_ACTION_RELOAD_COMP2) || \
                                 ((ACTION) == RTC_ACTION_RELOAD_COMP3))

/** @} */ /* End of group RTC_ACTION */

/**
 * @defgroup RTC_EVENT RTC Event
 * @{
 * @ingroup RTC_Exported_Constants
 */
typedef enum
{
    RTC_EVENT_COMP0 = 0,    /**< RTC event comparator 0. */
    RTC_EVENT_COMP1 = 1,    /**< RTC event comparator 1. */
    RTC_EVENT_COMP2 = 2,    /**< RTC event comparator 2. */
    RTC_EVENT_COMP3 = 3,    /**< RTC event comparator 3. */
} RTCEvent_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RTC_EVENT(EVENT)     (((EVENT) == RTC_EVENT_COMP0) || \
                                 ((EVENT) == RTC_EVENT_COMP1) || \
                                 ((EVENT) == RTC_EVENT_COMP2) || \
                                 ((EVENT) == RTC_EVENT_COMP3))

/** @} */ /* End of group RTC_EVENT */
#endif

/** @} */ /* End of group RTC_Exported_Constants */

/**
 * @defgroup RTC_Exported_Functions RTC Exported Functions
 * @{
 */
/**
 * @brief Deinitialize the RTC peripheral registers to their default reset values (turn off clock).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 * }
 * @endcode
 */
void RTC_DeInit(void);

/**
 * @brief Set RTC prescaler value.
 *
 * @param[in] Value  The prescaler value to be set. Should be no more than 12 bits.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_SetPrescaler(uint16_t Value);

/**
 * @brief Start or stop RTC peripheral.
 *
 * @param[in] NewState  New state of RTC peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Start RTC.
 *                      - DISABLE: Stop RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_Cmd(FunctionalState NewState);

/**
 * @brief Enable or disable the specified RTC interrupt source.
 *
 * @param[in] RTC_INT   Specifies the RTC interrupt source to be enabled or disabled.
 *                      This parameter can be any combination of the following values, refer to @ref RTC_INTERRUPTS.
 *                      - RTC_INT_TICK: Tick interrupt source.
 *                      - RTC_INT_OVERFLOW: Counter overflow interrupt.
 *                      - RTC_INT_COMP0: Compare 0 interrupt source.
 *                      - RTC_INT_COMP1: Compare 1 interrupt source.
 *                      - RTC_INT_COMP2: Compare 2 interrupt source.
 *                      - RTC_INT_COMP3: Compare 3 interrupt source.
 *                      - RTC_INT_PRECOMP: Prescale compare interrupt source.
 *                      - RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 * @param[in] NewState  New state of the specified RTC interrupt.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified interrupt of RTC.
 *                      - DISABLE: Disable the specified interrupt of RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_INTConfig(uint32_t RTC_INT, FunctionalState NewState);

/**
 * @brief Enable or disable the specified RTC wakeup function.
 *
 * @param[in] RTC_WAKEUP  Specifies the RTC wakeup function to be enabled or disabled.
 *                        This parameter can be any combination of the following values, refer to @ref RTC_WAKEUP.
 *                        - RTC_WAKEUP_TICK: Tick wakeup function.
 *                        - RTC_WAKEUP_OVERFLOW: Overflow wakeup function.
 *                        - RTC_WAKEUP_PRECOMP: Prescale compare wakeup function.
 *                        - RTC_WAKEUP_PRECOMP_COMP3: Prescale & compare 3 wakeup function.
 *                        - RTC_WAKEUP_COMP0: Compare 0 wakeup function.
 *                        - RTC_WAKEUP_COMP1: Compare 1 wakeup function.
 *                        - RTC_WAKEUP_COMP2: Compare 2 wakeup function.
 *                        - RTC_WAKEUP_COMP3: Compare 3 wakeup function.
 * @param[in] NewState  New state of the specified RTC wakeup function.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified interrupt of RTC wakeup.
 *                      - DISABLE: Disable the specified interrupt of RTC wakeup.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_WakeUpConfig(uint32_t RTC_WAKEUP, FunctionalState NewState);

/**
 * @brief Enable RTC interrupt signal to CPU NVIC.
 *
 * @param[in] NewState  Enable or disable RTC interrupt signal to MCU.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the interrupt of CPU NVIC.
 *                      - DISABLE: Disable the interrupt of CPU NVIC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_NVICCmd(FunctionalState NewState);

/**
 * @brief Enable or disable system wake up function of RTC.
 *
 * @param[in] NewState  New state of the wake up function.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the system wake up function.
 *                      - DISABLE: Disable the system wake up function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_WakeUpCmd(ENABLE);
 * }
 * @endcode
 */
void RTC_WakeUpCmd(FunctionalState NewState);

/**
 * @brief Get the specified RTC interrupt status.
 *
 * @param[in] RTC_INT  Specifies the RTC interrupt source.
 *                     This parameter can be any combination of the following values, refer to @ref RTC_INTERRUPTS.
 *                     - RTC_INT_TICK: RTC tick interrupt source.
 *                     - RTC_INT_OVERFLOW: RTC counter overflow interrupt source.
 *                     - RTC_INT_COMP0: Compare 0 interrupt source.
 *                     - RTC_INT_COMP1: Compare 1 interrupt source.
 *                     - RTC_INT_COMP2: Compare 2 interrupt source.
 *                     - RTC_INT_COMP3: Compare 3 interrupt source.
 *                     - RTC_INT_PRECOMP: Prescale compare interrupt source.
 *                     - RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 *
 * @return The status of @ref RTC_INTERRUPTS.
 * @retval SET    The RTC interrupt has occurred.
 * @retval RESET  The RTC interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     ITStatus int_status = RTC_GetINTStatus(RTC_INT_COMP0);
 * }
 * @endcode
 */
ITStatus RTC_GetINTStatus(uint32_t RTC_INT);

/**
 * @brief Get the specified RTC wakeup interrupt status.
 *
 * @param[in] RTC_WAKEUP  Specifies the RTC wakeup interrupt sources.
 *                        This parameter can be any combination of the following values, refer to @ref RTC_WAKEUP.
 *                        - RTC_WAKEUP_TICK: Tick wakeup function.
 *                        - RTC_WAKEUP_OVERFLOW: Overflow wakeup function.
 *                        - RTC_WAKEUP_PRECOMP: Prescale compare wakeup function.
 *                        - RTC_WAKEUP_PRECOMP_COMP3: Prescale & compare 3 wakeup function.
 *                        - RTC_WAKEUP_COMP0: Compare 0 wakeup function.
 *                        - RTC_WAKEUP_COMP1: Compare 1 wakeup function.
 *                        - RTC_WAKEUP_COMP2: Compare 2 wakeup function.
 *                        - RTC_WAKEUP_COMP3: Compare 3 wakeup function.
 *
 * @return The status of @ref RTC_WAKEUP.
 * @retval SET    The RTC wakeup interrupt has occurred.
 * @retval RESET  The RTC wakeup interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     ITStatus status = RTC_GetWakeUpStatus(RTC_WAKEUP_COMP0);
 * }
 * @endcode
 */
ITStatus RTC_GetWakeUpStatus(uint32_t RTC_WAKEUP);

/**
 * @brief Clear the interrupt pending bit of RTC.
 *
 * @param[in] RTC_INT  Specifies the RTC interrupt status bits.
 *                     This parameter can be any combination of the following values, refer to @ref RTC_INTERRUPTS.
 *                     - RTC_INT_TICK: RTC tick interrupt source.
 *                     - RTC_INT_OVERFLOW: RTC counter overflow interrupt source.
 *                     - RTC_INT_COMP0: Compare 0 interrupt source.
 *                     - RTC_INT_COMP1: Compare 1 interrupt source.
 *                     - RTC_INT_COMP2: Compare 2 interrupt source.
 *                     - RTC_INT_COMP3: Compare 3 interrupt source.
 *                     - RTC_INT_PRECOMP: Prescale compare interrupt source.
 *                     - RTC_INT_PRECOMP_COMP3: Prescale & compare 3 interrupt source.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearINTPendingBit(RTC_INT_COMP0);
 * }
 * @endcode
 */
void RTC_ClearINTPendingBit(uint32_t RTC_INT);

/**
 * @brief Clear the wakeup interrupt pending bit of RTC.
 *
 * @param[in] RTC_WAKEUP  Specifies the RTC wakeup flag to clear.
 *                        This parameter can be any combination of the following values, refer to @ref RTC_WAKEUP.
 *                        - RTC_WAKEUP_TICK: Tick wakeup function.
 *                        - RTC_WAKEUP_OVERFLOW: Overflow wakeup function.
 *                        - RTC_WAKEUP_PRECOMP: Prescale compare wakeup function.
 *                        - RTC_WAKEUP_PRECOMP_COMP3: Prescale & compare 3 wakeup function.
 *                        - RTC_WAKEUP_COMP0: Compare 0 wakeup function.
 *                        - RTC_WAKEUP_COMP1: Compare 1 wakeup function.
 *                        - RTC_WAKEUP_COMP2: Compare 2 wakeup function.
 *                        - RTC_WAKEUP_COMP3: Compare 3 wakeup function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearWakeUpStatusBit(RTC_WAKEUP_COMP0);
 * }
 * @endcode
 */
void RTC_ClearWakeUpStatusBit(uint32_t RTC_WAKEUP);

/**
 * @brief Clear the interrupt pending bit of the specified RTC comparator.
 *
 * @param[in] Index  The comparator number, Refer to @ref RTC_COMPARE_INDEX.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearCompINT(RTC_COMP0);
 * }
 * @endcode
 */
void RTC_ClearCompINT(RTCCompIndex_TypeDef Index);

/**
 * @brief Clear the overflow interrupt pending bit of RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearOverFlowINT();
 * }
 * @endcode
 */
void RTC_ClearOverFlowINT(void);

/**
 * @brief Clear the tick interrupt pending bit of RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClearTickINT();
 * }
 * @endcode
 */
void RTC_ClearTickINT(void);

/**
 * @brief Set RTC comparator value.
 *
 * @param[in] Index  The comparator number can range from 0 to 3, Refer to @ref RTC_COMPARE_INDEX.
 * @param[in] Value  The comparator value to be set. Should be no more than 24 bits.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_SetCompValue(RTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * @brief Get RTC comparator value.
 *
 * @param[in] Index  The comparator number, Refer to @ref RTC_COMPARE_INDEX.
 *
 * @return The comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompValue(RTC_COMP0);
 * }
 * @endcode
 */
uint32_t RTC_GetCompValue(RTCCompIndex_TypeDef Index);

/**
 * @brief Set RTC prescaler comparator value.
 *
 * @param[in] Value  The prescaler comparator value to be set. Should be no more than 12 bits.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     (3200 - 1)//max 4095
 * #define RTC_PRECOMP_VALUE       (320)//max 4095
 * #define RTC_COMP3_VALUE         (10)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetPreCompValue(RTC_PRECOMP_VALUE);
 *     RTC_SetCompValue(RTC_COMP3, RTC_COMP3_VALUE);
 *
 *     RTC_INTConfig(RTC_INT_PRECOMP_COMP3, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_SetPreCompValue(uint32_t Value);

/**
 * @brief Get RTC prescaler comparator value.
 *
 * @return The prescaler comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetPreCompValue();
 * }
 * @endcode
 */
uint32_t RTC_GetPreCompValue(void);

/**
 * @brief Reset counter value of RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetCounter();
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_ResetCounter(void);

/**
 * @brief Get counter value of RTC.
 *
 * @return The counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t counter = RTC_GetCounter();
 * }
 * @endcode
 */
uint32_t RTC_GetCounter(void);

/**
 * @brief Reset prescaler counter value of RTC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ResetPrescalerCounter();
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_ResetPrescalerCounter(void);

/**
 * @brief Get prescaler counter value of RTC.
 *
 * @return The prescaler counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t pre_counter = RTC_GetPreCounter();
 * }
 * @endcode
 */
uint32_t RTC_GetPreCounter(void);

/**
 * @brief Set backup register for store time information.
 *
 * @param[in] Value  Value to write to backup register.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_SetBackupReg(0x01020304);
 * }
 * @endcode
 */
void RTC_SetBackupReg(uint32_t Value);

/**
 * @brief Get backup register.
 *
 * @return Register value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t reg_data = RTC_GetBackupReg();
 * }
 * @endcode
 */
uint32_t RTC_GetBackupReg(void);

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
/**
 * @brief Set RTC comparator auto reload value.
 *
 * @param[in] Index   The comparator number, can be 0 ~ 3, Refer to @ref RTC_COMPARE_INDEX.
 * @param[in] Value   The comparator value to be set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_COMP_INDEX          RTC_COMP3
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_SetCompReloadValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 * }
 * @endcode
 */
void RTC_SetCompReloadValue(RTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * @brief Get RTC comparator auto reload value.
 *
 * @param[in] Index  The comparator number, Refer to @ref RTC_COMPARE_INDEX.
 *
 * @return The comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompReloadValue(RTC_COMP0);
 * }
 * @endcode
 */
uint32_t RTC_GetCompReloadValue(RTCCompIndex_TypeDef Index);

/**
 * @brief Enable RTC comparator auto reload.
 *        When the counter value reaches the value of comparator, it automatically adds the compare value,
 *        which equals Current Compare + Reload Value.
 *
 * @param[in] Index          The comparator number, Refer to @ref RTC_COMPARE_INDEX.
 * @param[in] Comp_Value     The initialize value of comparator.
 * @param[in] Reload_Value   The comparator auto reload value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_EnableCompAutoReload(RTC_COMP0, 1000, 1000);
 * }
 * @endcode
 */
void RTC_EnableCompAutoReload(RTCCompIndex_TypeDef Index, uint32_t Comp_Value,
                              uint32_t Reload_Value);

/**
 * @brief Disable RTC comparator auto reload.
 *
 * @param[in] Index  The comparator number, Refer to @ref RTC_COMPARE_INDEX.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DisableCompAutoReload(RTC_COMP0);
 * }
 * @endcode
 */
void RTC_DisableCompAutoReload(RTCCompIndex_TypeDef Index);
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
/**
 * @brief Set RTC comparator GT value.
 *
 * @param[in] Index  The comparator gt number, can be 0 ~ 3.
 * @param[in] Value  The comparator value to be set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define RTC_PRESCALER_VALUE     49
 * #define RTC_COMP_INDEX          RTC_COMP3
 * #define RTC_COMP_INDEX_INT      RTC_INT_COMP3
 * #define RTC_COMP_VALUE          (1000)
 *
 * void driver_rtc_init(void)
 * {
 *     RTC_DeInit();
 *
 *     RTC_SetPrescaler(RTC_PRESCALER_VALUE);
 *     RTC_SetCompValue(RTC_COMP_INDEX, RTC_COMP_VALUE);
 *
 *     RTC_INTConfig(RTC_COMP_INDEX_INT, ENABLE);
 *     RTC_NVICCmd(ENABLE);
 *
 *     RTC_Cmd(ENABLE);
 * }
 * @endcode
 */
void RTC_SetCompGTValue(RTCCompIndex_TypeDef Index, uint32_t Value);

/**
 * @brief Get RTC comparator GT value.
 *
 * @param[in] Index  The comparator number 0~3.
 *
 * @return The comparator value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     uint32_t data = RTC_GetCompGTValue(0);
 * }
 * @endcode
 */
uint32_t RTC_GetCompGTValue(RTCCompIndex_TypeDef Index);
#endif

#if (RTC_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable RTC RAP mode.
 *
 * @param[in] NewState  New state of RTC RAP mode.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable RTC RAP mode.
 *                      - DISABLE: Disable RTC RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_RAPModeCmd(ENABLE);
 * }
 * @endcode
 */
void RTC_RAPModeCmd(FunctionalState NewState);

/**
 * @brief Trigger RTC action.
 *
 * @param[in] Action  The RTC action to be triggered, Refer to @ref RTC_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ActionTrigger(RTC_ACTION_START);
 * }
 * @endcode
 */
void RTC_ActionTrigger(uint32_t Action);

/**
 * @brief Enable or disable RTC shortcut.
 *
 * @param[in] Action    The RTC action, Refer to @ref RTC_ACTION.
 * @param[in] Event     The RTC event, Refer to @ref RTC_EVENT.
 * @param[in] NewState  New state of the RTC shortcut.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the RTC shortcut.
 *                      - DISABLE: Disable the RTC shortcut.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ShortcutCmd(RTC_ACTION_RELOAD_COMP0, RTC_EVENT_COMP0, ENABLE);
 * }
 * @endcode
 */
void RTC_ShortcutCmd(uint32_t Action, uint32_t Event, FunctionalState NewState);

#endif

#if (RTC_SUPPORT_CLOCK_IN_FROM_OUTSIDE_PAD == 1)
/**
 * @brief Enable or disable using external clock for RTC.
 *
 * @param[in] ClockIn   Select which external pad as RTC clock in.
 * @param[in] NewState  New state of RTC peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable external clock input.
 *                      - DISABLE: Disable external clock input.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockInCmd(RTC_CLOCK_IN_P5_1, ENABLE);
 * }
 * @endcode
 */
void RTC_ClockInCmd(RTCClockIn_TypeDef ClockIn, FunctionalState NewState);
#endif

#if (RTC_SUPPORT_CLOCK_OUT_TO_OUTSIDE_PAD == 1)
/**
 * @brief Enable or disable the clock output to the pad for RTC.
 *
 * @param[in] ClockOut  Select RTC clock output pad and type.
 * @param[in] NewState  New state of RTC peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable clock output.
 *                      - DISABLE: Disable clock output.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rtc_demo(void)
 * {
 *     RTC_ClockOutCmd(RTC_CLOCK_OUT_P0_1_OSC, ENABLE);
 * }
 * @endcode
 */
void RTC_ClockOutCmd(RTCClockOut_TypeDef ClockOut, FunctionalState NewState);
#endif

/** @} */ /* End of group RTC_Exported_Functions */

/** @} */ /* End of group RTC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_RTC_H */
