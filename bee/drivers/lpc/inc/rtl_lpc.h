/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPC_H
#define RTL_LPC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "lpc/src/device/rtl87x2j/rtl_lpc_def.h"
#endif

/**
 * @defgroup LPC LPC
 * @ingroup PERIPH_DRIVER
 * @brief Low Power Comparator (LPC) driver.
 * @{
 */

/**
 * @defgroup LPC_Exported_Constants LPC Exported Constants
 * @{
 */

/**
 * @defgroup    LPC_CHANNEL LPC Channel
 * @{
 */
typedef enum
{
    LPC_CHANNEL_ADC0,       /**< LPC channel is ADC0. */
    LPC_CHANNEL_ADC1,       /**< LPC channel is ADC1. */
    LPC_CHANNEL_ADC2,       /**< LPC channel is ADC2. */
    LPC_CHANNEL_ADC3,       /**< LPC channel is ADC3. */
    LPC_CHANNEL_ADC4,       /**< LPC channel is ADC4. */
    LPC_CHANNEL_ADC5,       /**< LPC channel is ADC5. */
    LPC_CHANNEL_ADC6,       /**< LPC channel is ADC6. */
    LPC_CHANNEL_ADC7,       /**< LPC channel is ADC7. */
#if (LPC_SUPPORT_VBAT_CHANNEL == 1)
    LPC_CHANNEL_VBAT,       /**< LPC channel is VBAT. */
#endif
    LPC_CHANNEL_MAX,        /**< LPC channel maximum number. */
} LPCChannel_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_CHANNEL(CHANNEL) (((CHANNEL) < LPC_CHANNEL_MAX))

/** @} */ /* End of group LPC_CHANNEL */

/**
 * @defgroup    LPC_EDGE LPC Edge
 * @{
 */
typedef enum
{
    LPC_VIN_BELOW_VTH,      /**< The input voltage is below threshold voltage. */
    LPC_VIN_OVER_VTH,       /**< The input voltage is above threshold voltage. */
} LPCEdge_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_EDGE(EDGE) (((EDGE) == LPC_VIN_BELOW_VTH) || \
                           ((EDGE) == LPC_VIN_OVER_VTH))

/** @} */ /* End of group LPC_EDGE */

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
/**
 * @defgroup    LPC_MODE LPC Mode
 * @{
 */
typedef enum
{
    LPC_DIVIDE_MODE,        /**< LPC divide mode. */
    LPC_BYPASS_MODE,        /**< LPC bypass mode. */
} LPCMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_MODE(MODE) (((MODE) == LPC_BYPASS_MODE) || \
                           ((MODE) == LPC_DIVIDE_MODE))

/** @} */ /* End of group LPC_MODE */
#endif

#if (LPC_SUPPORT_TRIGGER_MODE == 1)
/**
 * @defgroup    LPC_TRIGGER_MODE LPC Trigger Mode
 * @{
 */
typedef enum
{
    LPC_SINGLE_OUTPUT,      /**< LPC single output. */
#if (LPC_SUPPORT_VOLTAGE_DETECT_L == 1)
    LPC_SINGLE_L_OUTPUT,    /**< LPC single L output. */
#endif
    LPC_DUAL_OUTPUT,        /**< LPC dual output. */
} LPCTriggerMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_TRIGGER_MODE(MODE) (((MODE) == LPC_SINGLE_OUTPUT) || \
                                   ((MODE) == LPC_SINGLE_L_OUTPUT) || \
                                   ((MODE) == LPC_DUAL_OUTPUT))

/** @} */ /* End of group LPC_TRIGGER_MODE */

#endif

#if (LPC_SUPPORT_DEBOUNCE_MODE == 1)
/**
 * @defgroup    LPC_DEBOUNCE_DIV LPC Debounce Div
 * @{
 */
typedef enum
{
    LPC_DEBOUNCE_DIV_1,     /**< The debounce divider is 1. */
    LPC_DEBOUNCE_DIV_2,     /**< The debounce divider is 2. */
    LPC_DEBOUNCE_DIV_4,     /**< The debounce divider is 4. */
    LPC_DEBOUNCE_DIV_8,     /**< The debounce divider is 8. */
    LPC_DEBOUNCE_DIV_16,    /**< The debounce divider is 16. */
    LPC_DEBOUNCE_DIV_32,    /**< The debounce divider is 32. */
    LPC_DEBOUNCE_DIV_40,    /**< The debounce divider is 40. */
    LPC_DEBOUNCE_DIV_64,    /**< The debounce divider is 64. */
} LPCDebDiv_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_DEB_DIV(DIV) (((DIV) == LPC_DEBOUNCE_DIV_1) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_2) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_4) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_8) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_16) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_32) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_40) || \
                             ((DIV) == LPC_DEBOUNCE_DIV_64))

/** @} */ /* End of group LPC_DEBOUNCE_DIV */
#endif

/**
 * @defgroup    LPC_DIVIDE_THRESHOLD LPC Divide Threshold
 * @{
 */
typedef enum
{
    LPC_INPUT_RANGE         /**< LPC divide input range. */
} LPCThreshold_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_THRESHOLD(THRESHOLD) ((THRESHOLD) <= LPC_THRESHOLD_MAX)

/** @} */ /* End of group LPC_DIVIDE_THRESHOLD */

/**
 * @defgroup    LPC_BYPASS_THRESHOLD LPC Bypass Threshold
 * @{
 */

typedef enum
{
    LPC_BYPASS_INPUT_RANGE  /**< LPC bypass input range. */
}
LPCBypassThreshold_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_BYPASS_THRESHOLD(THRESHOLD) ((THRESHOLD) <= LPC_BYPASS_THRESHOLD_MAX)

/** @} */ /* End of group LPC_BYPASS_THRESHOLD */

/**
 * @defgroup    LPC_INTERRUPTS LPC Interrupts
 * @{
 */
#define LPC_INT_VOLTAGE_DETECT              (BIT0)     /**< Voltage detection interrupt. */
#define LPC_INT_COUNTER_COMPARE             (BIT1)     /**< Counter compare interrupt. */
#if (LPC_SUPPORT_VOLTAGE_DETECT_L == 1)
#define LPC_INT_VOLTAGE_DETECT_L            (BIT2)     /**< Voltage detection L interrupt. */
#endif
#if (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1)
#define LPC_INT_HYSTERESIS                  (BIT3)     /**< Hysteresis interrupt. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_LPC_INTERRUPT(INT)               (((INT) == LPC_INT_VOLTAGE_DETECT) || \
                                             ((INT) == LPC_INT_COUNTER_COMPARE) || \
                                             ((INT) == LPC_INT_VOLTAGE_DETECT_L) || \
                                             ((INT) == LPC_INT_HYSTERESIS))

/** @} */ /* End of group LPC_INTERRUPTS */

#if (LPC_SUPPORT_RAP_MODE == 1)
/**
 * @defgroup    LPC_ACTION LPC Action
 * @{
 */
typedef enum
{
    LPC_ACTION_START = 0,   /**< LPC action start. */
    LPC_ACTION_STOP = 1,    /**< LPC action stop. */
} LPCAction_TypeDef;

/** @} */ /* End of group LPC_ACTION */

/**
 * @defgroup    LPC_EVENT LPC Event
 * @{
 */
typedef enum
{
    LPC_EVENT_STATUS = 0,   /**< LPC event status. */
} LPCEvent_TypeDef;

/** @} */ /* End of group LPC_EVENT */

#endif
/** @} */ /* End of group LPC_Exported_Constants */

/**
 * @defgroup LPC_Exported_Types LPC Exported Types
 * @{
 */

/**
 * @brief LPC init structure definition.
 */
typedef struct
{
    LPCChannel_TypeDef LPC_Channel;     /**< Specifies the LPC input channel.
                                             This parameter can be a value of @ref LPC_CHANNEL. */

    LPCEdge_TypeDef LPC_Edge;           /**< Specifies the LPC trigger edge.
                                             This parameter can be a value of @ref LPC_EDGE. */

    LPCThreshold_TypeDef LPC_Threshold; /**< Specifies the voltage threshold in divide mode.
                                             This parameter can be a value of @ref LPC_DIVIDE_THRESHOLD. */

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
    LPCBypassThreshold_TypeDef LPC_BypassThreshold; /**< Specifies the voltage threshold in bypass mode.
                                             This parameter can be a value of @ref LPC_BYPASS_THRESHOLD. */
#endif

#if (LPC_SUPPORT_DEBOUNCE_MODE == 1)
    FunctionalState LPC_DebouncEn;      /**< Enable or disable the LPC debounce function.
                                             This parameter can be a value of DISABLE or ENABLE. */

    LPCDebDiv_TypeDef LPC_DebouncDiv;   /**< Specifies the LPC Debounce Divider.
                                             This parameter can be a value of @ref LPC_DEBOUNCE_DIV. */

    uint32_t LPC_DebouncCnt;            /**< Specifies the LPC debounce count.
                                             This value is used to configure the LPC debounce time, which is calculated as:
                                             T_debounce = (1 / (LPC_CLOCK / LPC_DebouncDiv)) * (LPC_DebouncCnt + 1).
                                             This parameter can be a value of 0 to 255. */
#endif

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
    LPCMode_TypeDef LPC_Mode;           /**< Specifies the LPC mode.
                                             If using @ref LPC_DIVIDE_MODE, please configure @ref LPC_Threshold or @ref LPC_ThresholdL.
                                             If using @ref LPC_BYPASS_MODE, please configure @ref LPC_BypassThreshold or @ref LPC_BypassThresholdL.
                                             This parameter can be a value of @ref LPC_MODE. */
#endif

#if ((LPC_SUPPORT_VOLTAGE_DETECT_L == 1) || (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1))
    LPCThreshold_TypeDef LPC_ThresholdL; /**< Specifies the voltage threshold in divide mode.
                                             This parameter can be a value of @ref LPC_DIVIDE_THRESHOLD. */

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
    LPCBypassThreshold_TypeDef LPC_BypassThresholdL; /**< Specifies the voltage threshold
                                             in bypass mode. This parameter can be a value of @ref LPC_BYPASS_THRESHOLD. */
#endif
#endif

#if (LPC_SUPPORT_TRIGGER_MODE == 1)
    LPCTriggerMode_TypeDef LPC_TriggerMode; /**< Specifies the LPC trigger mode.
                                             This parameter can be a value of @ref LPC_TRIGGER_MODE. */
#endif

#if (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1)
    FunctionalState LPC_HysteresisEn;   /**< Specifies the hysteresis function.
                                             This parameter can be a value of DISABLE or ENABLE. */
#endif
} LPC_InitTypeDef;

/** @} */ /* End of group LPC_Exported_Types */

/**
 * @defgroup LPC_Exported_Functions LPC Exported Functions
 * @{
 */

/**
 * @brief Reset LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_DeInit(LPC0);
 * }
 * @endcode
 */
void LPC_DeInit(LPC_TypeDef *LPCx);

/**
 * @brief Initializes LPC peripheral according to the specified parameters in LPC_InitStruct.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] LPC_InitStruct Pointer to a LPC_InitTypeDef structure that contains
 *            the configuration information for the specified LPC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_InitTypeDef LPC_InitStruct;
 *     LPC_StructInit(&LPC_InitStruct);
 *     LPC_InitStruct.LPC_Channel   = LPC_CHANNEL_ADC0;
 *     LPC_InitStruct.LPC_Edge      = LPC_VIN_BELOW_VTH;
 *     LPC_InitStruct.LPC_Threshold = LPC_480_mV;
 *     LPC_Init(LPC0,&LPC_InitStruct);
 * }
 * @endcode
 */
void LPC_Init(LPC_TypeDef *LPCx, LPC_InitTypeDef *LPC_InitStruct);

/**
 * @brief Fills each LPC_InitStruct member with its default value.
 *
 * @note The default settings for the LPC_InitStruct member are shown in the following table:
 *       | LPC_InitStruct member        | Default value                        |
 *       |:----------------------------:|:------------------------------------:|
 *       | LPC_Channel                  | @ref LPC_CHANNEL_ADC0                |
 *       | LPC_Edge                     | @ref LPC_VIN_BELOW_VTH               |
 *       | LPC_DebouncEn                | DISABLE                              |
 *       | LPC_DebouncDiv               | @ref LPC_DEBOUNCE_DIV_1              |
 *       | LPC_DebouncCnt               | 0                                    |
 *       | LPC_Threshold                | LPC_480_mV                           |
 *
 * @param[in]  LPC_InitStruct Pointer to a LPC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_InitTypeDef LPC_InitStruct;
 *     LPC_StructInit(&LPC_InitStruct);
 *     LPC_InitStruct.LPC_Channel   = LPC_CHANNEL_ADC0;
 *     LPC_InitStruct.LPC_Edge      = LPC_VIN_BELOW_VTH;
 *     LPC_InitStruct.LPC_Threshold = LPC_480_mV;
 *     LPC_Init(LPC0,&LPC_InitStruct);
 * }
 * @endcode
 */
void LPC_StructInit(LPC_InitTypeDef *LPC_InitStruct);

/**
 * @brief Enables or disables LPC voltage detect function.
 *
 * @param[in]  LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in]  NewState New state of LPC peripheral.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_Cmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_Cmd(LPC_TypeDef *LPCx, FunctionalState NewState);

/**
  * \brief  Configure LPC trigger edge.
  *
  * \param[in] LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param[in] LPC_Edge: Specifies the LPC trigger edge.
  *            This parameter can be one of the following values:
  *            \arg LPC_VIN_BELOW_VTH: The input voltage is below the threshold voltage.
  *            \arg LPC_VIN_OVER_VTH: The input voltage is above the threshold voltage.
  *
  * \return None.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void lpc_sample(void)
  * {
  *     LPC_InitTypeDef LPC_InitStruct;
  *     LPC_StructInit(&LPC_InitStruct);
  *     LPC_InitStruct.LPC_Channel   = LPC_CAPTURE_CHANNEL;
  *     LPC_InitStruct.LPC_Edge      = LPC_VOLTAGE_DETECT_EDGE;
  *     LPC_InitStruct.LPC_Threshold = LPC_VOLTAGE_DETECT_THRESHOLD;
  *     LPC_Init(LPC0,&LPC_InitStruct);
  *
  *     NVIC_InitTypeDef NVIC_InitStruct;
  *     NVIC_InitStruct.NVIC_IRQChannel = LPC0_IRQn;
  *     NVIC_InitStruct.NVIC_IRQChannelPriority = 2;
  *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  *     NVIC_Init(&NVIC_InitStruct);
  *
  *     LPC_SetTriggerEdge(LPC0, LPC_VIN_OVER_VTH);
  *     LPC_Cmd(LPC0, ENABLE);
  * }
  * \endcode
  */
void LPC_SetTriggerEdge(LPC_TypeDef *LPCx, LPCEdge_TypeDef LPC_Edge);

/**
 * @brief Enables or disables the specified LPC interrupts.
 *
 * @param[in]  LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in]  LPC_INT Specifies the LPC interrupt. Refer to @ref LPC_INTERRUPT.
 *             This parameter can be one of the following values:
 *             - LPC_INT_VOLTAGE_DETECT: Voltage detection interrupt.
 *             - LPC_INT_COUNTER_COMPARE: Counter compare interrupt.
 * @param[in]  NewState New state of the specified LPC interrupt.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_InitTypeDef LPC_InitStruct;
 *     LPC_StructInit(&LPC_InitStruct);
 *     LPC_InitStruct.LPC_Channel   = LPC_CHANNEL_ADC0;
 *     LPC_InitStruct.LPC_Edge      = LPC_VIN_BELOW_VTH;
 *     LPC_InitStruct.LPC_Threshold = LPC_480_mV;
 *     LPC_Init(LPC0, &LPC_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = LPC0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 2;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     LPC_NVICCmd(LPC0, LPC_INT_VOLTAGE_DETECT, ENABLE);
 *     LPC_Cmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_INTConfig(LPC_TypeDef *LPCx, uint32_t LPC_INT, FunctionalState NewState);

/**
 * @brief Enable or disable LPC wakeup function.
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] NewState Enable or disable LPC wakeup function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_InitTypeDef LPC_InitStruct;
 *     LPC_StructInit(&LPC_InitStruct);
 *     LPC_InitStruct.LPC_Channel   = LPC_CHANNEL_ADC0;
 *     LPC_InitStruct.LPC_Edge      = LPC_VIN_BELOW_VTH;
 *     LPC_InitStruct.LPC_Threshold = LPC_480_mV;
 *     LPC_Init(LPC0,&LPC_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = LPC0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 2;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     LPC_WakeUpConfig(LPC0, ENABLE);
 *     LPC_Cmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_WakeUpConfig(LPC_TypeDef *LPCx, FunctionalState NewState);

/**
 * @brief Clear the specified LPC interrupt.
 *
 * @param[in]  LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in]  LPC_INT Specifies the LPC interrupt to clear. Refer to @ref LPC_INTERRUPT.
 *             This parameter can be one of the following values:
 *             - LPC_INT_COUNTER_COMPARE: Counter compare interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_ClearINTStatus(LPC0, LPC_INT_COUNTER_COMPARE);
 * }
 * @endcode
 */
void LPC_ClearINTStatus(LPC_TypeDef *LPCx, uint32_t LPC_INT);

/**
 * @brief Get the interrupt status of the specified LPC.
 *
 * @param[in]  LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in]  LPC_INT specifies the LPC interrupt to check. Refer to @ref LPC_INTERRUPT.
 *             This parameter can be one of the following values:
 *             - LPC_INT_VOLTAGE_DETECT: Voltage detection interrupt.
 *             - LPC_INT_COUNTER_COMPARE: Counter compare interrupt.
 *
 * @return The interrupt status of the specified LPC.
 * @retval SET  The interrupt flag is set.
 * @retval RESET  The interrupt flag is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_GetINTStatus(LPC0, LPC_INT_VOLTAGE_DETECT);
 * }
 * @endcode
 */
ITStatus LPC_GetINTStatus(LPC_TypeDef *LPCx, uint32_t LPC_INT);

/**
 * @brief Get the wakeup status of the specified LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 *
 * @return The wakeup status of the specified LPC.
 * @retval SET  The wakeup status is set.
 * @retval RESET  The wakeup status is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_GetWakeUpStatus(LPC0);
 * }
 * @endcode
 */
ITStatus LPC_GetWakeUpStatus(LPC_TypeDef *LPCx);

/**
 * @brief Set the comparator counter value of the specified LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] data Specifies the comparator counter value.
 *                 This parameter can be 0 to 0xfff.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_SetComparator(LPC0, 10);
 * }
 * @endcode
 */
void LPC_SetComparator(LPC_TypeDef *LPCx, uint32_t data);

/**
 * @brief Get the comparator counter value of the specified LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 *
 * @return The comparator counter value of the specified LPC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     uint16_t current_comparator = LPC_GetComparator(LPC0);
 * }
 * @endcode
 */
uint16_t LPC_GetComparator(LPC_TypeDef *LPCx);

/**
 * @brief Get the current counter of the specified LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 *
 * @return The current counter of the specified LPC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     uint16_t current_counter = LPC_GetCounter(LPC0);
 * }
 * @endcode
 */
uint16_t LPC_GetCounter(LPC_TypeDef *LPCx);

/**
 * @brief Reset the LPC counter.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_CounterReset(LPC0);
 * }
 * @endcode
 */
void LPC_CounterReset(LPC_TypeDef *LPCx);

/**
 * @brief Start or stop the LPC counter.
 *
 * @param[in]  LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in]  NewState New state of the LPC counter.
 *             This parameter can be one of the following values:
 *             - ENABLE: Start LPCOMP counter.
 *             - DISABLE: Stop LPCOMP counter.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_sample(void)
 * {
 *     LPC_CounterCmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_CounterCmd(LPC_TypeDef *LPCx, FunctionalState NewState);

#if (LPC_SUPPORT_RAP_MODE == 1)

/**
 * @brief Enable or disable RAP mode.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] NewState New state of RAP mode.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_demo(void)
 * {
 *     LPC_RAPModeCmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_RAPModeCmd(LPC_TypeDef *LPCx, FunctionalState NewState);

/**
 * @brief Trigger an LPC action.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] LPC_Action Specify the LPC action.
 *            This parameter can be a value of @ref LPC_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_demo(void)
 * {
 *     LPC_ActionTrigger(LPC0, LPC_ACTION_START);
 * }
 * @endcode
 */
void LPC_ActionTrigger(LPC_TypeDef *LPCx, LPCAction_TypeDef LPC_Action);

/**
 * @brief Enable or disable the shortcut function for the specified Action and Event.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] Action Specify the shortcut action.
 *            This parameter can be only LPC_ACTION_STOP.
 * @param[in] Event Specify the shortcut event.
 *            This parameter can be only LPC_EVENT_STATUS.
 * @param[in] NewState New state of the shortcut function.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_demo(void)
 * {
 *     LPC_ShortcutCmd(LPC0, LPC_ACTION_STOP, LPC_EVENT_STATUS, ENABLE);
 * }
 * @endcode
 */
void LPC_ShortcutCmd(LPC_TypeDef *LPCx, uint32_t Action, uint32_t Event, FunctionalState NewState);

#endif

#if (LPC_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable GPIO clock auto mode of the specified LPC.
 *
 * @param[in] LPCx Specifies the LPC peripheral. Refer to @ref LPC_DECLARATION.
 * @param[in] Newstate Enable or disable the clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void lpc_demo(void)
 * {
 *     LPC_ClockAutoModeCmd(LPC0, ENABLE);
 * }
 * @endcode
 */
void LPC_ClockAutoModeCmd(LPC_TypeDef *LPCx, FunctionalState ENABLE);

#endif

/** @} */ /* End of group LPC_Exported_Functions */

/** @} */ /* End of group LPC */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPC_H */
