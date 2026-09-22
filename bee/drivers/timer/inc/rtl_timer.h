/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef RTL_TIMER_H
#define RTL_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "timer/src/device/rtl87x2g/rtl_timer_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "timer/src/device/rtl87x3d/rtl_tim_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "timer/src/device/rtl87x2j/rtl_timer_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "timer/src/device/rtl87x3j/rtl_timer_def.h"
#include "timer/src/device/rtl87x3j/rtl_timer_cc.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "timer/src/device/rtl87x3k/rtl_timer_def.h"
#include "timer/src/device/rtl87x3k/rtl_timer_cc.h"
#endif

/**
 * @defgroup TIMER_DRIVER DRIVER
 * @ingroup TIMER
 * @brief Timer (TIMER) driver.
 * @{
 */

/**
 * @defgroup TIMER_Exported_Constants TIMER Exported Constants
 * @{
 */

/**
 * @defgroup TIMER_MODE TIMER Mode
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
#if (TIMER_SUPPORT_FREERUN_MODE == 1)
    TIMER_MODE_FREERUN,                         /**< Free-running mode. */
#endif
    TIMER_MODE_USERDEFINE = 0x2,                /**< User-defined PWM manual mode. */
#if (TIMER_SUPPORT_USERDEFINE_AUTO_MODE == 1)
    TIMER_MODE_USERDEFINE_AUTO = 0x1,           /**< User-defined PWM auto mode. */
#endif
} TIMERMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_MODE(MODE) (((MODE) == TIMER_MODE_FREERUN) || \
                             ((MODE) == TIMER_MODE_USERDEFINE) || \
                             ((MODE) == TIMER_MODE_USERDEFINE_AUTO))
/** @} */ /* End of group TIMER_MODE */

#if (TIMER_SUPPORT_DIRECTION == 1)
/**
 * @defgroup TIMER_DIRECTION TIMER Direction
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_DIRECTION_UP_COUNTING = 0x0,          /**< Timer counts up. */
    TIMER_DIRECTION_DOWN_COUNTING = 0x1,        /**< Timer counts down. */
} TIMERDirection_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_Direction(DIRECTION) (((DIRECTION) == TIMER_DIRECTION_UP_COUNTING) || \
                                       ((DIRECTION) == TIMER_DIRECTION_DOWN_COUNTING))
/** @} */ /* End of group TIMER_DIRECTION */
#endif

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
/**
 * @defgroup PWM_POLARITY PWM Polarity
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_POLARITY_LOW = 0x00,                    /**< PWM start with output low. */
    PWM_POLARITY_HIGH = 0x01,                   /**< PWM start with output high. */
} PWMPolarity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_POLARITY(POL) (((POL) == PWM_POLARITY_LOW) || \
                              ((POL) == PWM_POLARITY_HIGH))
/** @} */ /* End of group PWM_POLARITY */

/**
 * @defgroup PWM_OUTPUT_MODE PWM Output Mode
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_PUSH_PULL = 0x0,                        /**< PWM push-pull output mode. */
    PWM_OPEN_DRAIN = 0x1,                       /**< PWM open-drain output mode. */
}
PWMOutputMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_OUTPUT_MODE(MODE) (((MODE) == PWM_PUSH_PULL) || \
                                  ((MODE) == PWM_OPEN_DRAIN))
/** @} */ /* End of group PWM_OUTPUT_MODE */

#if (TIMER_SUPPORT_PWM_MODE == 1)
/**
 * @defgroup PWM_MODE PWM Mode
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_MODE_OUTPUT_HIGH_CNT_BELOW_CMP = 0x0,  /**< PWM output high when counter below compare value. */
    PWM_MODE_OUTPUT_LOW_CNT_BELOW_CMP = 0x1,   /**< PWM output low when counter below compare value. */
    PWM_MODE_FIX_LOW = 0x2,                     /**< PWM fixed low output. */
    PWM_MODE_FIX_HIGH = 0x3,                    /**< PWM fixed high output. */
} PWMMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_MODE(MODE)    (((MODE) == PWM_MODE_OUTPUT_HIGH_CNT_BELOW_CMP) || \
                              ((MODE) == PWM_MODE_OUTPUT_LOW_CNT_BELOW_CMP) || \
                              ((MODE) == PWM_MODE_FIX_LOW) || \
                              ((MODE) == PWM_MODE_FIX_HIGH))
/** @} */ /* End of group PWM_MODE */
#endif

#if (TIMER_SUPPORT_PWM_STOP_STATE_CONTROL == 1)
/**
 * @defgroup PWM_STOP_STATE PWM Stop State
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_STOP_STATE_POLARITY_CONTROLLED = 0x0,   /**< PWM stop state is polarity controlled. */
    PWM_STOP_STATE_KEEP_LAST = 0x1,             /**< PWM stop state keeps last level. */
} PWMStopState_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_STOP_STATE(STATE) (((STATE) == PWM_STOP_STATE_POLARITY_CONTROLLED) || \
                                  ((STATE) == PWM_STOP_STATE_KEEP_LAST))
/** @} */ /* End of group PWM_STOP_STATE */
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
/**
 * @defgroup PWM_DEADZONE_STOP_STATE PWM DeadZone Stop State
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_DZ_STOP_AT_LOW = 0x0,                  /**< PWM deadzone mergence stop state at low. */
    PWM_DZ_STOP_AT_HIGH = 0x1,                 /**< PWM deadzone mergence stop state at high. */
} PWMDZStopState_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_DEADZONE_STOP_STATE(STATE) (((STATE) == PWM_DZ_STOP_AT_LOW) || \
                                           ((STATE) == PWM_DZ_STOP_AT_HIGH))
/** @} */ /* End of group PWM_DEADZONE_STOP_STATE */

#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
/**
 * @defgroup PWM_DEADZONE_REFERENCE PWM DeadZone Reference
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    PWM_DZ_REF_PWMPN = 0x0,                    /**< PWM P waveform is PWM_P, PWM N waveform is PWM_N. */
    PWM_DZ_REF_PWMNN = 0x1,                    /**< PWM P waveform is PWM_N, PWM N waveform is PWM_N. */
    PWM_DZ_REF_PWMPP = 0x2,                    /**< PWM P waveform is PWM_P, PWM N waveform is PWM_P. */
    PWM_DZ_REF_PWMNP = 0x3,                    /**< PWM P waveform is PWM_N, PWM N waveform is PWM_P. */
} PWMDZRef_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_PWM_DEADZONE_REFERENCE(STATE) (((STATE) == PWM_DZ_REF_PWMPN) || \
                                          ((STATE) == PWM_DZ_REF_PWMNN) || \
                                          ((STATE) == PWM_DZ_REF_PWMPP) || \
                                          ((STATE) == PWM_DZ_REF_PWMNP))
/** @} */ /* End of group PWM_DEADZONE_REFERENCE */
#endif
#endif
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * @defgroup TIMER_LATCH_TRIGGER_MODE TIMER Latch Trigger Mode
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_LATCH_TRIGGER_RISING_EDGE = 0x00,     /**< Latch trigger mode is rising edge. */
    TIMER_LATCH_TRIGGER_FALLING_EDGE = 0x01,    /**< Latch trigger mode is falling edge. */
    TIMER_LATCH_TRIGGER_BOTH_EDGE = 0x02,       /**< Latch trigger mode is both rising and falling edge. */
} TIMERLatchTriggerMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_LATCH_TRIGGER_MODE(MODE) (((MODE) == TIMER_LATCH_TRIGGER_RISING_EDGE) || \
                                           ((MODE) == TIMER_LATCH_TRIGGER_FALLING_EDGE) || \
                                           ((MODE) == TIMER_LATCH_TRIGGER_BOTH_EDGE))
/** @} */ /* End of group TIMER_LATCH_TRIGGER_MODE */
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
/**
 * @defgroup TIMER_DMA_TARGET TIMER DMA TARGET
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_DMA_CCR_FIFO = 0x00,                  /**< DMA target is CCR FIFO. */
    TIMER_DMA_LATCH_FIFO = 0x01,                /**< DMA target is latch FIFO. */
} TIMERDMATarget_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_DMA_TARGET(MODE) (((MODE) == TIMER_DMA_CCR_FIFO) || \
                                   ((MODE) == TIMER_DMA_LATCH_FIFO))
/** @} */ /* End of group TIMER_DMA_TARGET */
#endif
/**
 * @defgroup TIMER_INTERRUPTS TIMER Interrupts
 * @{
 * @ingroup TIMER_Exported_Constants
 */
#define TIMER_INT_TIMEOUT                        (1 << 0)     /**< TIMER timeout interrupt. */
#define TIMER_INT_PAUSE                          (1 << 1)     /**< TIMER pause interrupt. */
#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
#define TIMER_INT_LATCH_FIFO_FULL                (1 << 2)     /**< TIMER latch FIFO full interrupt. */
#define TIMER_INT_LATCH_FIFO_THRESHOLD           (1 << 3)     /**< TIMER latch FIFO threshold interrupt. */
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_INT(INT) (((INT) == TIMER_INT_TIMEOUT) || \
                           ((INT) == TIMER_INT_PAUSE)  || \
                           ((INT) == TIMER_INT_LATCH_FIFO_FULL)   || \
                           ((INT) == TIMER_INT_LATCH_FIFO_THRESHOLD))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_INT(INT) (((INT) == TIMER_INT_TIMEOUT) || \
                           ((INT) == TIMER_INT_PAUSE))
#endif
/** @} */ /* End of group TIMER_INTERRUPTS */

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * @defgroup TIMER_FLAG TIMER Flag
 * @{
 * @ingroup TIMER_Exported_Constants
 */
#define TIMER_FLAG_CCR_FIFO_EMPTY                (0)     /**< TIMER CCR FIFO empty flag. */
#define TIMER_FLAG_CCR_FIFO_FULL                 (1)     /**< TIMER CCR FIFO full flag. */
#define TIMER_FLAG_LATCH_FIFO_EMPTY              (2)     /**< TIMER latch FIFO empty flag. */
#define TIMER_FLAG_LATCH_FIFO_FULL               (3)     /**< TIMER latch FIFO full flag. */
#define TIMER_FLAG_LATCH_FIFO_THRESHOLD          (4)     /**< TIMER latch FIFO threshold flag. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_TIMER_FLAG(flag) (((flag) == TIMER_FLAG_CCR_FIFO_FULL) || \
                             ((flag) == TIMER_FLAG_CCR_FIFO_EMPTY) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_EMPTY) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_FULL) || \
                             ((flag) == TIMER_FLAG_LATCH_FIFO_THRESHOLD))
/** @} */ /* End of group TIMER_FLAG */

/**
 * @defgroup TIMER_CLEAR_FLAG TIMER Clear Flag
 * @{
 * @ingroup TIMER_Exported_Constants
 */
#define TIMER_CLEAR_CCR_FIFO                     (0)     /**< TIMER capture/compare FIFO clear flag. */
#define TIMER_CLEAR_LATCH_FIFO                   (1)     /**< TIMER latch count FIFO clear flag. */
/** @} */ /* End of group TIMER_CLEAR_FLAG */
#endif

#if (TIMER_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup TIMER_ACTION TIMER Action
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_ACTION_START            = 0,           /**< Start timer. */
    TIMER_ACTION_PAUSE            = 1,           /**< Pause timer. */
    TIMER_ACTION_STOP             = 2,           /**< Stop timer. */
} TIMERAction_TypeDef;

/** @} */ /* End of group TIMER_ACTION */

/**
 * @defgroup TIMER_SHORTCUT_ACTION TIMER Shortcut Action
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_SHORTCUT_ACTION_PAUSE = 1,             /**< Shortcut action to pause timer. */
    TIMER_SHORTCUT_ACTION_STOP  = 2,             /**< Shortcut action to stop timer. */
} TIMERShortcutAction_TypeDef;

/** @} */ /* End of group TIMER_SHORTCUT_ACTION */

/**
 * @defgroup TIMER_SHORTCUT_EVENT TIMER Shortcut Event
 * @{
 * @ingroup TIMER_Exported_Constants
 */
typedef enum
{
    TIMER_SHORTCUT_EVENT_TIMEOUT = 0,            /**< Shortcut event is timeout. */
} TIMERShortcutEvent_TypeDef;

/** @} */ /* End of group TIMER_SHORTCUT_EVENT */
#endif
/** @} */ /* End of group TIMER_Exported_Constants */

/**
 * @defgroup TIMER_Exported_Types TIMER Exported Types
 * @{
 */

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
/**
 * @brief PWM deadzone init structure definition.
 *
 * @ingroup TIMER_Exported_Types
 */
typedef struct
{
    PWMDZClockSrc_TypeDef PWM_DZClockSrc;     /**< Specify the PWM deadzone clock source. */

    PWMDZClockDiv_TypeDef PWM_DZClockDiv;     /**< Specify the PWM deadzone clock divider. */

    uint32_t PWM_DZSize;                      /**< Specify the PWM deadzone size.
                                                   Deadzone time = deadzone size * dead zone clock period.
                                                   This parameter must range from 1 to 0xFF. */

    FunctionalState PWM_DZEn;                 /**< Enable or disable the PWM deadzone function.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    PWMDZStopState_TypeDef PWM_DZStopStateP;  /**< Specify the PWM deadzone P stop state.
                                                   This parameter can be a value of @ref PWM_DEADZONE_STOP_STATE. */

    PWMDZStopState_TypeDef PWM_DZStopStateN;  /**< Specify the PWM deadzone N stop state.
                                                   This parameter can be a value of @ref PWM_DEADZONE_STOP_STATE. */

#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
    FunctionalState PWM_DZInvertP;            /**< Specify the PWM P inversion.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    FunctionalState PWM_DZInvertN;            /**< Specify the PWM N inversion.
                                                   This parameter can be a value of DISABLE or ENABLE. */
#endif
} PWMDeadZone_TypeDef;
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * @brief TIMER latch structure definition.
 *
 * @ingroup TIMER_Exported_Types
 */
typedef struct
{
    FunctionalState TIMER_LatchEn[3];         /**< Enable or disable TIMER latch function.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    uint16_t        TIMER_LatchThreshold;     /**< Specify the TIMER latch count FIFO threshold.
                                                   This parameter can be a value of 0 to 8. */

    TIMERLatchTriggerMode_TypeDef TIMER_LatchTriggerMode[3]; /**< Specify the TIMER latch
                                                   trigger mode. This parameter can be a
                                                   value of @ref TIMER_LATCH_TRIGGER_MODE. */

    uint16_t        TIMER_LatchTriggerPad;    /**< Specify the TIMER latch trigger pad.
                                                   This parameter can be a value of @ref Pin_Number. */

    FunctionalState TIMER_LatchDebEn;         /**< Enable or disable TIMER latch debounce function.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    TIMERClockDiv_TypeDef TIMER_LatchDebClockDiv; /**< Specify the TIMER latch debounce
                                                   clock divider. This parameter can be a value
                                                   of @ref TIMER_CLOCK_DIVIDER. */

    uint16_t       TIMER_LatchDebCountLimit;  /**< Specify the TIMER latch debounce count limit.
                                                   This parameter must range from 0 to 65535. */
} TIMERLatch_TypeDef;
#endif
/**
 * @brief TIMER time base init structure definition.
 *
 * @ingroup TIMER_Exported_Types
 */
typedef struct
{
    TIMERClockSrc_TypeDef TIMER_ClockSrc;   /**< Specify the TIMER clock source.
                                                 This parameter can be a value of @ref TIMER_CLOCK_SOURCE. */

    TIMERClockDiv_TypeDef TIMER_ClockDiv;   /**< Specify the TIMER clock source divider.
                                                 This parameter can be a value of @ref TIMER_CLOCK_DIVIDER. */

    TIMERMode_TypeDef TIMER_Mode;           /**< Specify the operating mode.
                                                 This parameter can be a value of @ref TIMER_MODE. */

#if (TIMER_SUPPORT_DIRECTION == 1)
    TIMERDirection_TypeDef TIMER_Direction; /**< Specify the timer direction.
                                                 This parameter can be a value of @ref TIMER_DIRECTION. */
#endif

    uint32_t TIMER_Period;                  /**< Specify the period value to be loaded into the active
                                                 Auto-Reload Register at the next update event.
                                                 This parameter must range from 0x0 to 0xFFFFFFFF.
                                                 Period = PWM_HighCount + PWM_LowCount. */

    FunctionalState TIMER_OneShotEn;        /**< Enable or disable the one shot mode.
                                                 This parameter can be a value of DISABLE or ENABLE. */

#if (TIMER_SUPPORT_PERIOD_IMMEDIATELY_UPDATE == 1)
    FunctionalState
    TIMER_PeriodImmediatelyUpdateEn;    /**< Enable or disable immediately update period.
                                             This parameter can be a value of ENABLE or DISABLE. */
#endif

#if (TIMER_SUPPORT_TOGGLE_OUTPUT == 1)
    FunctionalState TIMER_ToggleOutputEn;   /**< Enable or disable timer toggle output.
                                                 This parameter can be a value of ENABLE or DISABLE. */
#endif

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
    FunctionalState PWM_En;                 /**< Enable or disable the PWM function.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    uint32_t PWM_HighCount;                 /**< Specify the PWM high count.
                                                 This parameter must range from 0x0 to 0xFFFFFFFF. */

    PWMPolarity_TypeDef
    PWM_Polarity;       /**< Specify the PWM start polarity for user-define PWM mode.
                             This parameter can be a value of @ref PWM_POLARITY. */

    PWMOutputMode_TypeDef PWM_OutputMode;   /**< Specify the PWM output mode.
                                                 This parameter can be a value of @ref PWM_OUTPUT_MODE. */

#if (TIMER_SUPPORT_PWM_MODE == 1)
    PWMMode_TypeDef PWM_Mode;       /**< Specify the PWM mode.
                                         This parameter can be a value of @ref PWM_MODE. */
#endif

#if (TIMER_SUPPORT_PWM_STOP_STATE_CONTROL == 1)
    PWMStopState_TypeDef PWM_StopState;     /**< Specify the PWM stop state.
                                                 This parameter can be a value of @ref PWM_STOP_STATE. */
#endif
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
    PWMDeadZone_TypeDef PWM_DZ;             /**< Specify the PWM deadzone configuration.
                                                 This parameter can be a value of @ref PWMDeadZone_TypeDef. */
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
    TIMERLatch_TypeDef TIMER_Latch;        /**< Specify the TIMER latch count configuration.
                                                 This parameter can be a value of @ref TIMERLatch_TypeDef. */
#endif

#if (TIMER_SUPPORT_DMA_FUNCTION == 1)
    FunctionalState TIMER_DMAEn;            /**< Enable or disable TIMER DMA.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    TIMERDMATarget_TypeDef TIMER_DMATarget; /**< Specify the TIMER DMA target.
                                                 This parameter can be a value of @ref TIMER_DMA_TARGET. */
#endif

#if (TIMER_COMPARE_CHANNEL_NUM > 0)
    TIMERCompare_TypeDef TIMER_Compare;     /**< Specify the timer compare configuration.
                                                 This parameter can be a value of @ref TIMERCompare_TypeDef. */
#endif

#if (TIMER_CAPTURE_CHANNEL_NUM > 0)
    TIMERCapture_TypeDef TIMER_Capture;        /**< Specify the TIMER capture configuration.
                                                     This parameter can be a value of @ref TIMERCapture_TypeDef. */
#endif

#if (TIMER_SUPPORT_CC_FIFO == 1)
    TIMERCCFIFO_TypeDef TIMER_CCFIFO;       /**< Specify the timer CC FIFO configuration.
                                                 This parameter can be a value of @ref TIMERCCFIFO_TypeDef. */
#endif

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)
    FunctionalState TIMER_DynConfigEn;      /**< Enable or disable the function to dynamically adjust
                                                 CCR and MAX_CNT. When this feature is enabled,
                                                 dynamic adjustment is supported. When this feature
                                                 is disabled, dynamic adjustment is not supported,
                                                 resulting in lower power consumption. */
#endif
} TIMER_TimeBaseInitTypeDef;

/** @} */ /* End of group TIMER_Exported_Types */

/**
 * @defgroup TIMER_Exported_Functions TIMER Exported Functions
 * @{
 */
/**
 * @brief Deinitialize the TIMERx peripheral registers to their default reset values.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 */
void TIMER_DeInit(TIMER_TypeDef *TIMERx);

/**
 * @brief Initialize the TIMERx time base unit peripheral according to
 *        the specified parameters in TIMER_InitStruct.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] TIMER_InitStruct Pointer to a TIMER_TimeBaseInitTypeDef
 *            structure that contains the configuration information for the selected TIMER peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER1_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_MODE_USERDEFINE;
 *     TIMER_TimeBaseInit(TIMER1_CH0, &TIMER_InitStruct);
 * }
 * @endcode
 */
void TIMER_TimeBaseInit(TIMER_TypeDef *TIMERx, TIMER_TimeBaseInitTypeDef *TIMER_InitStruct);

/**
 * @brief Fills each TIMER_InitStruct member with its default value.
 *
 * @param[in] TIMER_InitStruct Pointer to a TIMER_TimeBaseInitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER1_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_MODE_USERDEFINE;
 *     TIMER_TimeBaseInit(TIMER1_CH0, &TIMER_InitStruct);
 * }
 * @endcode
 */
void TIMER_StructInit(TIMER_TimeBaseInitTypeDef *TIMER_InitStruct);

/**
 * @brief Enables or disables the specified TIMER peripheral.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] NewState New state of the TIMERx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER1_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_MODE_USERDEFINE;
 *     TIMER_TimeBaseInit(TIMER1_CH0, &TIMER_InitStruct);
 *     TIMER_Cmd(TIMER1_CH0, ENABLE);
 * }
 * @endcode
 */
void TIMER_Cmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

#if (TIMER_SUPPORT_CLEAR_COUNTER == 1)
/**
 * @brief Clear counter of the specified TIMER peripheral.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 */
void TIMER_ClearCounter(TIMER_TypeDef *TIMERx);
#endif
/**
 * @brief Enables or disables the specified TIMERx interrupt.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] TIMER_INT Specify the TIMERx interrupt source to be enabled or disabled.
 * @param[in] NewState New state of the TIMERx interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_ClockCmd(TIMER1_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.PWM_En = DISABLE;
 *     TIMER_InitStruct.TIMER_Period = 1000000 - 1;
 *     TIMER_InitStruct.TIMER_Mode = TIMER_MODE_USERDEFINE;
 *     TIMER_TimeBaseInit(TIMER1_CH0, &TIMER_InitStruct);
 *     TIMER_ClearINT(TIMER1_CH0, TIMER_INT_TIMEOUT);
 *     TIMER_INTConfig(TIMER1_CH0, TIMER_INT_TIMEOUT, ENABLE);
 * }
 * @endcode
 */
void TIMER_INTConfig(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT, FunctionalState NewState);

/**
 * @brief Check whether the TIMER interrupt has occurred or not.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] TIMER_INT Specify the TIMERx interrupt source to check.
 *
 * @return The new state of the TIMER interrupt (SET or RESET).
 * @retval SET   The TIMER interrupt has occurred.
 * @retval RESET The TIMER interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus int_status = TIMER_GetINTStatus(TIMER1_CH0, TIMER_INT_TIMEOUT);
 * }
 * @endcode
 */
ITStatus TIMER_GetINTStatus(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT);

/**
 * @brief Clear TIMER interrupt.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] TIMER_INT Specify the TIMERx interrupt source to clear.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIMER_ClearINT(TIMER1_CH0, TIMER_INT_TIMEOUT);
 * }
 * @endcode
 */
void TIMER_ClearINT(TIMER_TypeDef *TIMERx, uint8_t TIMER_INT);

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1) || (TIMER_SUPPORT_CC_FIFO == 1)
/**
 * @brief Get the specified TIMER FIFO flag status.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] TIMER_FLAG Specifies the flag to check.
 *            This parameter can be a value of @ref TIMER_FLAG.
 *
 * @return The new state of TIMER_FLAG (SET or RESET).
 * @retval SET   The specified flag is set.
 * @retval RESET The specified flag is not set.
 */
FlagStatus TIMER_GetFIFOFlagStatus(TIMER_TypeDef *TIMERx, uint32_t TIMER_FLAG);
#endif
/**
 * @brief Change TIMER period value.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] period Period value to be changed.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t new_period = 1000000 - 1;
 *     TIMER_Cmd(TIMER1_CH0, DISABLE);
 *     TIMER_ChangePeriod(TIMER1_CH0, new_period);
 *
 * }
 * @endcode
 */
void TIMER_ChangePeriod(TIMER_TypeDef *TIMERx, uint32_t period);

/**
 * @brief Get TIMERx period value.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return TIMER period value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t period = TIMER_GetPeriod(TIMER1_CH0);
 * }
 * @endcode
 */
uint32_t TIMER_GetPeriod(TIMER_TypeDef *TIMERx);

/**
 * @brief Get TIMERx current value when timer is running.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return The counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t cur_value = TIMER_GetCurrentValue(TIMER1_CH0);
 * }
 * @endcode
 */
uint32_t TIMER_GetCurrentValue(TIMER_TypeDef *TIMERx);

/**
 * @brief Get TIMERx elapsed value when timer is running.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return The elapsed counter value.
 */
uint32_t TIMER_GetElapsedValue(TIMER_TypeDef *TIMERx);

/**
 * @brief Get the specified TIMER operation status.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return The new state of the timer operation status (SET or RESET).
 * @retval SET   The timer is in operation.
 * @retval RESET The timer is not in operation.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void timer_demo(void)
 * {
 *     FlagStatus intstatus = TIMER_GetOperationStatus(TIMER1_CH0);
 * }
 * @endcode
 */
FlagStatus TIMER_GetOperationStatus(TIMER_TypeDef *TIMERx);

/**
 * @brief Enable or disable to pause timer counter.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] NewState New state of the TIMERx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 */
void TIMER_PauseCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

#if (TIMER_SUPPORT_CCR_FIFO == 1) || (TIMER_SUPPORT_CC_FIFO == 1)
/**
 * @brief Set the value to adjust the duty cycle in the compare FIFO.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] value Value to be written to compare FIFO.
 */
void TIMER_SetCompareFIFO(TIMER_TypeDef *TIMERx, uint32_t value);
#endif

#if (TIMER_SUPPORT_CCR_FIFO == 1 || TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * @brief Clear capture/compare or latch count FIFO.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] FIFO_CLR Specifies the FIFO type to be cleared.
 *            This parameter can be a value of @ref TIMER_CLEAR_FLAG.
 */
void TIMER_ClearFIFO(TIMER_TypeDef *TIMERx, uint8_t FIFO_CLR);
#endif

#if (TIMER_SUPPORT_LATCH_CNT_0 == 1)
/**
 * @brief Get the specified TIMER latch count value.
 *
 * @param[in]  TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[out] pBuf FIFO data out buffer.
 * @param[in]  length Latch count FIFO length, max 8.
 */
void TIMER_GetLatchFIFO(TIMER_TypeDef *TIMERx, uint32_t *pBuf, uint8_t length);

/**
 * @brief Get the specified TIMER latch count FIFO length.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return FIFO data length.
 */
uint8_t TIMER_GetLatchFIFOLength(TIMER_TypeDef *TIMERx);
#endif
/**
 * @brief Get TIMER toggle state.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 *
 * @return The new state of toggle state.
 * @retval true  The toggle state is set.
 * @retval false The toggle state is reset.
 */
bool TIMER_GetToggleState(TIMER_TypeDef *TIMERx);

#if (TIMER_SUPPORT_PWM_FUNCTION == 1)
/**
 * @brief Change PWM frequency and duty cycle.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] period This parameter can be 0x00 to 0xFFFFFFFF.
 * @param[in] high_count This parameter can be 0x00 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * #define TIMER_DEMO TIMER1_CH0
 *
 * void timer_demo(void)
 * {
 *     uint32_t high_count = 1000000 - 1;
 *     uint32_t period = 1000000 - 1;
 *     TIMER_Cmd(TIMER_DEMO, DISABLE);
 *     TIMER_PWMChangeFreqAndDuty(TIMER_DEMO, period, high_count);
 * }
 * @endcode
 */
void TIMER_PWMChangeFreqAndDuty(TIMER_TypeDef *TIMERx, uint32_t period, uint32_t high_count);

#if (TIMER_SUPPORT_PWM_PHASE_SHIFT == 1)
/**
 * @brief Change TIMER PWM phase shift count.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] ShiftCount This parameter can be 0 to CCR value.
 */
void TIMER_SetShiftCount(TIMER_TypeDef *TIMERx, uint32_t ShiftCount);
#endif

#if (TIMER_SUPPORT_PWM_DEADZONE == 1)
#if (TIMER_SUPPORT_PWM_DEADZONE_REFERENCE == 1)
/**
 * @brief TIMER PWMP/N source select.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] PWMDZRef State of the TIMERx PWMP/N.
 *            This parameter can be a value of @ref PWM_DEADZONE_REFERENCE.
 */
void TIMER_SetPWMDZRef(TIMER_TypeDef *TIMERx, PWMDZRef_TypeDef PWMDZRef);
#endif
/**
 * @brief PWM complementary output emergency stop and resume.
 *        PWM_P emergency stop level state is configured by PWM_DZStopStateP,
 *        PWM_N emergency stop level state is configured by PWM_DZStopStateN.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] NewState New state of complementary output.
 *            - DISABLE: Resume PWM complementary output.
 *            - ENABLE: PWM complementary output emergency stop.
 *
 * @note To use this function, need to configure the corresponding timer.
 *       PWM2 ->> TIMER2, PWM3 ->> TIMER3.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_pwm_init(void)
 * {
 *     Pad_Config(P0_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE, PAD_OUT_HIGH);
 *     Pad_Config(P0_2, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE,
 *                PAD_OUT_HIGH);
 *     Pad_Config(P2_2, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_ENABLE,
 *                PAD_OUT_HIGH);
 *
 *     Pinmux_Config(P0_1, PWM_OUT_PIN_PINMUX);
 *     Pinmux_Config(P0_2, PWM_OUT_P_PIN_PINMUX);
 *     Pinmux_Config(P2_2, PWM_OUT_N_PIN_PINMUX);
 * }
 *
 * void driver_pwm_init(void)
 * {
 *     RCC_ClockCmd(TIMER1_CLOCK, ENABLE);
 *
 *     TIMER_TimeBaseInitTypeDef TIMER_InitStruct;
 *     TIMER_StructInit(&TIMER_InitStruct);
 *     TIMER_InitStruct.TIMER_Mode             = TIMER_MODE_USERDEFINE;
 *     TIMER_InitStruct.PWM_En                 = ENABLE;
 *     TIMER_InitStruct.TIMER_Period           = PWM_PERIOD;
 *     TIMER_InitStruct.PWM_HighCount          = PWM_HIGH_COUNT;
 *     TIMER_InitStruct.PWM_DZ.PWM_DZStopStateP = PWM_DZ_STOP_AT_HIGH;
 *     TIMER_InitStruct.PWM_DZ.PWM_DZStopStateN = PWM_DZ_STOP_AT_LOW;
 *     TIMER_InitStruct.PWM_DZ.PWM_DZEn        = ENABLE;
 *     TIMER_InitStruct.PWM_DZ.PWM_DZSize      = 255;
 *     TIMER_TimeBaseInit(TIMER1_CH6, &TIMER_InitStruct);
 *
 *     TIMER_Cmd(TIMER1_CH6, ENABLE);
 * }
 *
 * void pwm_demo(void)
 * {
 *    board_pwm_init();
 *    driver_pwm_init();
 *    //Add delay.
 *    TIMER_PWMComplOutputEMCmd(TIMER1_CH6, ENABLE);
 * }
 * @endcode
 */
void TIMER_PWMComplOutputEMCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);
#endif
#endif
/**
 * @brief TIMER clock config.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] ClockSrc Specifies the PLL clock source.
 * @param[in] ClockDiv Specifies the APB peripheral to gate its clock.
 */
void TIMER_SetClock(TIMER_TypeDef *TIMERx, uint32_t ClockSrc, uint16_t ClockDiv);

/**
 * @brief Get TIMER clock.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[out] ClockSrc Specifies the clock source.
 * @param[out] ClockDiv Specifies the clock divider.
 *
 * @return The result of getting TIMER clock.
 * @retval true  TIMER clock parameters retrieved successfully.
 * @retval false Failed to get TIMER clock parameters.
 */
bool TIMER_GetClock(TIMER_TypeDef *TIMERx, uint32_t *ClockSrc, uint16_t *ClockDiv);

#if (TIMER_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the TIMERx RAP mode.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] NewState New state of the TIMERx RAP mode.
 *            This parameter can be: ENABLE or DISABLE.
 */
void TIMER_RAPModeCmd(TIMER_TypeDef *TIMERx, FunctionalState NewState);

/**
 * @brief Trigger the specified TIMERx action.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] Action The action to trigger.
 *            This parameter can be a value of @ref TIMER_ACTION.
 */
void TIMER_ActionTrigger(TIMER_TypeDef *TIMERx, uint32_t Action);

/**
 * @brief Enable or disable the shortcut function for TIMERx.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] Action The shortcut action.
 *            This parameter can be a value of @ref TIMER_SHORTCUT_ACTION.
 * @param[in] Event The shortcut event.
 *            This parameter can be a value of @ref TIMER_SHORTCUT_EVENT.
 * @param[in] NewState New state of the shortcut function.
 *            This parameter can be: ENABLE or DISABLE.
 */
void TIMER_ShortcutCmd(TIMER_TypeDef *TIMERx, uint32_t Action, uint32_t Event,
                       FunctionalState NewState);

#endif

#if (TIMER_SUPPORT_AUTO_CLOCK == 1)
/**
 * @brief Set TIMER clock auto mode.
 *
 * @param[in] TIMERx Select the TIMER peripheral. @ref TIMER_DECLARATION.
 * @param[in] AutoMode The auto mode to set.
 */
void TIMER_SetClockAutoMode(TIMER_TypeDef *TIMERx, uint32_t AutoMode);

#endif
/** @} */ /* End of group TIMER_Exported_Functions */
/** @} */ /* End of group TIMER_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_TIMER_H */
