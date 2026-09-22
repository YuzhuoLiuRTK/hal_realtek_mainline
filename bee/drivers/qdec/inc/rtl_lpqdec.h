/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPQDEC_H
#define RTL_LPQDEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "qdec/src/device/rtl87x2j/rtl_lpqdec_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "qdec/src/device/rtl87x3j/rtl_lpqdec_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "qdec/src/device/rtl87x3k/rtl_lpqdec_def.h"
#endif

/**
 * @defgroup LPQDEC_DRIVER DRIVER
 * @ingroup LPQDEC
 * @brief Low Power Quadrature Decoder (LPQDEC) driver.
 * @{
 */

/**
 * @defgroup LPQDEC_Exported_Constants LPQDEC Exported Constants
 * @{
 */

/**
 * @defgroup LPQDEC_COUNTER_SCALE LPQDEC Counter Scale
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_COUNTER_SCALE_1_PHASE = 0x00,    /**< LPQDEC update counter when 1 phase change. */
    LPQDEC_COUNTER_SCALE_2_PHASE = 0x01,    /**< LPQDEC update counter when 2 phases change. */
} LPQDECCounterScale_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_COUNTER_SCALE_PHASE(PHASE) ((PHASE) <= 0x01)
/** @} */ /* End of group LPQDEC_COUNTER_SCALE */

/**
 * @defgroup LPQDEC_PHASE LPQDEC Phase
 *
 * A phase is written PHA/PHB: PHA is the high bit and PHB the low bit.
 *
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_PHASE_MODE0 = 0x00,    /**< LPQDEC phase 00, PHA = 0, PHB = 0. */
    LPQDEC_PHASE_MODE1 = 0x01,    /**< LPQDEC phase 01, PHA = 0, PHB = 1. */
    LPQDEC_PHASE_MODE2 = 0x02,    /**< LPQDEC phase 10, PHA = 1, PHB = 0. */
    LPQDEC_PHASE_MODE3 = 0x03,    /**< LPQDEC phase 11, PHA = 1, PHB = 1. */
} LPQDECPhase_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_PHSAE(PHSAE) ((PHSAE) <= 0x03)
/** @} */ /* End of group LPQDEC_PHASE */

/**
 * @defgroup LPQDEC_AXIS_DIRECTION LPQDEC Axis Direction
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_AXIS_DIR_DOWN = 0x00,      /**< The direction for x-axis is decreasing. */
    LPQDEC_AXIS_DIR_UP = 0x01,        /**< The direction for x-axis is increasing. */
} LPQDECAxisDir_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_AXIS_DIRECTION(DIRECTION) ((DIRECTION) <= 0x01)
/** @} */ /* End of group LPQDEC_AXIS_DIRECTION */

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
/**
 * @defgroup LPQDEC_LED_POLARITY LPQDEC LED Polarity
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_LED_POLARITY_LOW = 0x0,     /**< LED output pin polarity low. */
    LPQDEC_LED_POLARITY_HIGH = 0x1,    /**< LED output pin polarity high. */
} LPQDECLedPolarity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_LED_POLARITY(POLARITY) ((POLARITY) <= 0x01)
/** @} */ /* End of group LPQDEC_LED_POLARITY */

/**
 * @defgroup LPQDEC_LED_PERIOD LPQDEC LED Period
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
typedef enum
{
    LPQDEC_LED_PERIOD_0US      = 0x0,   /**< LED ON period 0 us. */
    LPQDEC_LED_PERIOD_31P25US  = 0x1,   /**< LED ON period 31.25 us. */
    LPQDEC_LED_PERIOD_62P5US   = 0x2,   /**< LED ON period 62.5 us. */
    LPQDEC_LED_PERIOD_93P75US  = 0x3,   /**< LED ON period 93.75 us. */
    LPQDEC_LED_PERIOD_125US    = 0x4,   /**< LED ON period 125 us. */
    LPQDEC_LED_PERIOD_156P25US = 0x5,   /**< LED ON period 156.25 us. */
    LPQDEC_LED_PERIOD_187P5US  = 0x6,   /**< LED ON period 187.5 us. */
    LPQDEC_LED_PERIOD_218P75US = 0x7,   /**< LED ON period 218.75 us. */
} LPQDECLedPeriod_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_LED_PERIOD(PERIOD) ((PERIOD) <= 0x7)
/** @} */ /* End of group LPQDEC_LED_PERIOD */
#endif

/**
 * @defgroup LPQDEC_INTERRUPTS LPQDEC Interrupts
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_NEW_DATA               BIT6     /**< The counter interrupt triggered by new data on x-axis. */
#define LPQDEC_X_INT_ILLEGAL                BIT5     /**< The illegal interrupt on x-axis. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_INT_CONFIG(CONFIG)        (((CONFIG) == LPQDEC_X_INT_NEW_DATA) || \
                                             ((CONFIG) == LPQDEC_X_INT_ILLEGAL))

/** @} */ /* End of group LPQDEC_INTERRUPTS */

/**
 * @defgroup LPQDEC_INTERRUPTS_MASK LPQDEC Interrupts Mask
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */

#define LPQDEC_X_INT_MASK_NEW_DATA          BIT8      /**< LPQDEC counter interrupt mask triggered by new data. */
#define LPQDEC_X_INT_MASK_ILLEGAL           BIT7      /**< LPQDEC illegal interrupt mask. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_INT_MASK_CONFIG(CONFIG)   (((CONFIG) == LPQDEC_X_INT_MASK_NEW_DATA) || \
                                             ((CONFIG) == LPQDEC_X_INT_MASK_ILLEGAL))

/** @} */ /* End of group LPQDEC_INTERRUPTS_MASK */

/**
 * @defgroup LPQDEC_INTERRUPTS_CLEAR LPQDEC Interrupts Clear
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_CLEAR_ILLEGAL          BIT4      /**< Clear the illegal interrupt flag. */
#define LPQDEC_X_INT_CLEAR_UNDERFLOW        BIT3      /**< Clear the underflow flag. */
#define LPQDEC_X_INT_CLEAR_OVERFLOW         BIT2      /**< Clear the overflow flag. */
#define LPQDEC_X_INT_CLEAR_NEW_DATA         BIT1      /**< Clear the new data flag. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_INT_CLEAR_CONFIG(CONFIG)  (((CONFIG) == LPQDEC_X_INT_CLEAR_ILLEGAL) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_UNDERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_OVERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_CLEAR_NEW_DATA))

/** @} */ /* End of group LPQDEC_INTERRUPTS_CLEAR */

/**
 * @defgroup LPQDEC_COUNTER_CLEAR LPQDEC Counter Clear
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
#define LPQDEC_X_CLEAR_ILLEGAL_COUNTER      BIT5      /**< Clear the counter of illegal interrupts. */
#define LPQDEC_X_CLEAR_ACC_COUNTER          BIT0      /**< Clear the ACC counter flag. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_CNT_CLEAR_CONFIG(CONFIG)  (((CONFIG) == LPQDEC_X_CLEAR_ILLEGAL_COUNTER) || \
                                             ((CONFIG) == LPQDEC_X_CLEAR_ACC_COUNTER))

/** @} */ /* End of group LPQDEC_COUNTER_CLEAR */

/**
 * @defgroup LPQDEC_INTERRUPTS_FLAG LPQDEC Interrupts Flag
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
#define LPQDEC_X_INT_FLAG_NEW_DATA          BIT18     /**< The new data flag. */
#define LPQDEC_X_INT_FLAG_OVERFLOW          BIT16     /**< The overflow flag. */
#define LPQDEC_X_INT_FLAG_UNDERFLOW         BIT17     /**< The underflow flag. */
#define LPQDEC_X_INT_FLAG_ILLEGAL           BIT19     /**< The illegal counting flag. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_INT_FLAG_CONFIG(CONFIG)   (((CONFIG) == LPQDEC_X_INT_FLAG_NEW_DATA) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_OVERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_UNDERFLOW) || \
                                             ((CONFIG) == LPQDEC_X_INT_FLAG_ILLEGAL))

/** @} */ /* End of group LPQDEC_INTERRUPTS_FLAG */

/**
 * @defgroup LPQDEC_AXIS LPQDEC Axis
 * @{
 * @ingroup LPQDEC_Exported_Constants
 */
#define LPQDEC_AXIS_X                      (0)       /**< The LPQDEC X axis. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPQDEC_AXIS(AXIS)               ((AXIS) == LPQDEC_AXIS_X)

/** @} */ /* End of group LPQDEC_AXIS */

/** @} */ /* End of group LPQDEC_Exported_Constants */

/**
 * @defgroup LPQDEC_Exported_Types LPQDEC Exported Types
 * @{
 */

/**
 * @brief LPQDEC init structure definition.
 *
 * @ingroup LPQDEC_Exported_Types
 */
typedef struct
{
#if (LPQDEC_SUPPORT_CLK_SRC_DIV == 1)
    uint16_t LPQDEC_ScanClockDiv;              /**< Specifies DIV for Scan clock. */
#endif

    FunctionalState LPQDEC_AxisConfigX;        /**< Specifies the axis X function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState LPQDEC_ManualLoadInitPhase;/**< Specifies manual-load Initphase function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    LPQDECPhase_TypeDef LPQDEC_InitPhaseX;     /**< Specify the x-axis initial phase.
                                                    This parameter can be a value of @ref LPQDEC_PHASE. */

    FunctionalState LPQDEC_DebounceEnableX;    /**< Specifies the axis X debounce.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint16_t LPQDEC_DebounceCountX;            /**< Specifies the axis X debounce time. */

    LPQDECCounterScale_TypeDef LPQDEC_CounterScaleX; /**< Specify the x-axis counter scale.
                                                    This parameter can be a value of @ref LPQDEC_COUNTER_SCALE. */

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
    FunctionalState LPQDEC_LedEn;              /**< Specifies LED output status.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    LPQDECLedPolarity_TypeDef LPQDEC_LedPolarity; /**< Specifies LED output pin polarity. */

    LPQDECLedPeriod_TypeDef LPQDEC_LedPeriod;  /**< Time period the LED is switched ON
                                                    prior to sampling. When setting LEDPRE,
                                                    make sure sample period > LEDPRE. */
#endif
} LPQDEC_InitTypeDef;

/** @} */ /* End of group LPQDEC_Exported_Types */

/**
 * @defgroup LPQDEC_Exported_Functions LPQDEC Exported Functions
 * @{
 */

/**
 * @brief Deinitializes the LPQDEC peripheral registers to their default reset values.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_DeInit(LPQDEC);
 * }
 * @endcode
 */
void LPQDEC_DeInit(LPQDEC_TypeDef *LPQDECx);

/**
 * @brief Initializes the LPQDEC peripheral according to the specified
 *        parameters in the LPQDEC_InitStruct.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_InitStruct pointer to an LPQDEC_InitStruct structure that
 *            contains the configuration information for the specified LPQDEC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_InitTypeDef LPQDEC_InitStruct;
 *     LPQDEC_StructInit(&LPQDEC_InitStruct);
 *     LPQDEC_InitStruct.LPQDEC_AxisConfigX       = ENABLE;
 *     LPQDEC_InitStruct.LPQDEC_DebounceEnableX   = DISABLE;
 *     LPQDEC_Init(LPQDEC, &LPQDEC_InitStruct);
 *
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_Init(LPQDEC_TypeDef *LPQDECx, LPQDEC_InitTypeDef *LPQDEC_InitStruct);

/**
 * @brief Fills each LPQDEC_InitStruct member with its default value.
 *
 * @param[in] LPQDEC_InitStruct pointer to an LPQDEC_InitStruct structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *
 *     LPQDEC_InitTypeDef LPQDEC_InitStruct;
 *     LPQDEC_StructInit(&LPQDEC_InitStruct);
 *     LPQDEC_InitStruct.LPQDEC_AxisConfigX       = ENABLE;
 *     LPQDEC_InitStruct.LPQDEC_DebounceEnableX   = DISABLE;
 *     LPQDEC_Init(LPQDEC, &LPQDEC_InitStruct);
 *
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_StructInit(LPQDEC_InitTypeDef *LPQDEC_InitStruct);

/**
 * @brief Enable or disable LPQDEC Function.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_AXIS Specifies the LPQDEC axis.
 *            This parameter can be one of the following values:
 *            - LPQDEC_AXIS_X: The LPQDEC X axis.
 * @param[in] NewState New state of the selected LPQDEC axis.
 *            This parameter can be one of the following values:
 *            - ENABLE: Pause.
 *            - DISABLE: Resume.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_Cmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_Cmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS, FunctionalState NewState);

/**
 * @brief Enables or disables the specified LPQDEC interrupts.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_INT Specifies the LPQDEC interrupts sources to be enabled or disabled.
 *            This parameter can be one of the following values:
 *            - LPQDEC_X_INT_NEW_DATA: The counter interrupt for X axis.
 *            - LPQDEC_X_INT_ILLEGAL: The illegal interrupt for X axis.
 * @param[in] NewState New state of the specified LPQDEC interrupt.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_lpqdec_init(void)
 * {
 *     LPQDEC_INTConfig(LPQDEC, LPQDEC_X_INT_NEW_DATA, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_INTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_INT, FunctionalState NewState);

/**
 * @brief Enables or disables mask the specified LPQDEC axis interrupts.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_MASK Specifies the LPQDEC interrupts mask.
 *            This parameter can be one or logical OR of the following values:
 *            - LPQDEC_X_INT_MASK_NEW_DATA: The LPQDEC CNT interrupt mask.
 *            - LPQDEC_X_INT_MASK_ILLEGAL: The LPQDEC illegal interrupt mask.
 * @param[in] NewState New state of the specified LPQDEC interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_MaskINTConfig(LPQDEC, LPQDEC_X_INT_MASK_NEW_DATA, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_MaskINTConfig(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_MASK, FunctionalState NewState);

/**
 * @brief Enables or disables interrupt signal to CPU NVIC.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] NewState New state of the specified LPQDEC interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_NVICCmd(LPQDEC, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_NVICCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState);

/**
 * @brief Enables or disables wakeup system.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] NewState New state of the specified LPQDEC interrupts mask.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_WakeUpCmd(LPQDEC, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_WakeUpCmd(LPQDEC_TypeDef *LPQDECx, FunctionalState NewState);

/**
 * @brief Checks whether the specified LPQDEC flag is set or not.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_FLAG Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            - LPQDEC_X_INT_FLAG_NEW_DATA: Status of the counter interrupt for X axis.
 *            - LPQDEC_X_INT_FLAG_ILLEGAL: Status of the illegal interrupt for X axis.
 *            - LPQDEC_X_INT_FLAG_OVERFLOW: The overflow flag for x-axis accumulation counter.
 *            - LPQDEC_X_INT_FLAG_UNDERFLOW: The underflow flag for x-axis accumulation counter.
 *
 * @return The new state of LPQDEC_FLAG.
 * @retval SET   The specified LPQDEC flag is set.
 * @retval RESET The specified LPQDEC flag is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     FlagStatus flag_status = LPQDEC_GetFlagState(LPQDEC, LPQDEC_X_INT_FLAG_NEW_DATA);
 * }
 * @endcode
 */
FlagStatus LPQDEC_GetFlagState(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_FLAG);

/**
 * @brief Clear LPQDEC interrupt pending bit.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_CLR_INT Specifies the flag to clear.
 *            This parameter can be one of the following values:
 *            - LPQDEC_X_INT_CLEAR_ILLEGAL: The illegal interrupt for X axis.
 *            - LPQDEC_X_INT_CLEAR_UNDERFLOW: The underflow flag for x-axis accumulation counter.
 *            - LPQDEC_X_INT_CLEAR_OVERFLOW: The overflow flag for x-axis accumulation counter.
 *            - LPQDEC_X_INT_CLEAR_NEW_DATA: The counter interrupt for X axis.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_ClearINTPendingBit(LPQDEC, LPQDEC_X_INT_CLEAR_NEW_DATA);
 * }
 * @endcode
 */
void LPQDEC_ClearINTPendingBit(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLR_INT);

/**
 * @brief Clear LPQDEC counter.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_CLEAR Specifies the counter to clear.
 *            This parameter can be one of the following values:
 *            - LPQDEC_X_CLEAR_ILLEGAL_COUNTER: The illegal counter for X axis.
 *            - LPQDEC_X_CLEAR_ACC_COUNTER: The acc counter for X axis.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_ClearCounter(LPQDEC, LPQDEC_X_CLEAR_ILLEGAL_COUNTER);
 * }
 * @endcode
 */
void LPQDEC_ClearCounter(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_CLEAR);

/**
 * @brief Get LPQDEC X-Axis direction.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_AXIS Specifies the LPQDEC axis.
 *            This parameter can be one of the following values:
 *            - LPQDEC_AXIS_X: The LPQDEC X axis.
 *
 * @return The direction of the axis.
 * @retval true: The axis is rolling up (@ref LPQDEC_AXIS_DIR_UP).
 * @retval false: The axis is rolling down (@ref LPQDEC_AXIS_DIR_DOWN).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     bool dir = LPQDEC_GetAxisDirection(LPQDEC, LPQDEC_AXIS_X);
 * }
 * @endcode
 */
bool LPQDEC_GetAxisDirection(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS);

/**
 * @brief Get LPQDEC X-Axis count.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_AXIS Specifies the LPQDEC axis.
 *            This parameter can be one of the following values:
 *            - LPQDEC_AXIS_X: The LPQDEC X axis.
 *
 * @return The count of the axis.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     uint16_t counter = LPQDEC_GetAxisCount(LPQDEC, LPQDEC_AXIS_X);
 * }
 * @endcode
 */
uint16_t LPQDEC_GetAxisCount(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS);

/**
 * @brief Pause or resume LPQDEC Axis x.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 * @param[in] LPQDEC_AXIS Specifies the LPQDEC axis.
 *            This parameter can be one of the following values:
 *            - LPQDEC_AXIS_X: The LPQDEC X axis.
 * @param[in] NewState New state of the specified LPQDEC Axis.
 *            This parameter can be one of the following values:
 *            - ENABLE: Pause.
 *            - DISABLE: Resume.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDEC_CounterPauseCmd(LPQDEC, LPQDEC_AXIS_X, ENABLE);
 * }
 * @endcode
 */
void LPQDEC_CounterPauseCmd(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS,
                            FunctionalState NewState);

/**
 * @brief Get current state of phase.
 *
 * @param[in] LPQDECx Select the LPQDEC peripheral. @ref LPQDEC_Declaration.
 *
 * @return The current state of phase, refer to @ref LPQDECPhase_TypeDef.
 * @retval LPQDEC_PHASE_MODE0 Phase 00.
 * @retval LPQDEC_PHASE_MODE1 Phase 01.
 * @retval LPQDEC_PHASE_MODE2 Phase 10.
 * @retval LPQDEC_PHASE_MODE3 Phase 11.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpqdec_demo(void)
 * {
 *     LPQDECPhase_TypeDef phase = LPQDEC_GetPhaseState(LPQDEC);
 * }
 * @endcode
 */
LPQDECPhase_TypeDef LPQDEC_GetPhaseState(LPQDEC_TypeDef *LPQDECx);

/** @} */ /* End of group LPQDEC_Exported_Functions */

/** @} */ /* End of group LPQDEC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPQDEC_H */
