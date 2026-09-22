/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_IR_H
#define RTL_IR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "ir/src/device/rtl87x2g/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "ir/src/device/rtl87x3d/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "ir/src/device/rtl87x2j/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "ir/src/device/rtl87x3j/rtl_ir_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "ir/src/device/rtl87x3k/rtl_ir_def.h"
#endif

/**
 * @defgroup IR_DRIVER DRIVER
 * @ingroup IR
 * @brief Infrared Radiation (IR) driver.
 * @{
 */

/**
 * @defgroup IR_Exported_Constants IR Exported Constants
 * @{
 */

/**
 * @defgroup IR_FIFO_SIZE IR FIFO Size
 * @{
 */
#define IR_TX_FIFO_SIZE                   32  /**< IR TX FIFO size is 32. */
#define IR_RX_FIFO_SIZE                   32  /**< IR RX FIFO size is 32. */
/** @} */ /* End of group IR_FIFO_SIZE */

/**
 * @defgroup IR_MODE IR Mode
 * @{
 */
typedef enum
{
    IR_MODE_TX = 0x00, /**< IR TX mode. */
    IR_MODE_RX = 0x01, /**< IR RX mode. */
} IRMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_MODE(MODE) (((MODE) == IR_MODE_TX) || ((MODE) == IR_MODE_RX))
/** @} */ /* End of group IR_MODE */

/**
 * @defgroup IR_IDLE_STATUS IR Idle Status
 * @{
 */
typedef enum
{
    IR_IDLE_OUTPUT_LOW = 0x00,  /**< TX output low level in idle. */
    IR_IDLE_OUTPUT_HIGH = 0x01, /**< TX output high level in idle. */
} IRIdleStatus_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_IDLE_STATUS(LEVEL) (((LEVEL) == IR_IDLE_OUTPUT_HIGH) || ((LEVEL) == IR_IDLE_OUTPUT_LOW))
/** @} */ /* End of group IR_IDLE_STATUS */

/**
 * @defgroup IR_TX_DEF_INVERSE IR TX Definition Inverse
 * @{
 */
typedef enum
{
    IR_TX_DATA_NORMAL = 0x00,  /**< Not inverse the TX waveform definition. */
    IR_TX_DATA_INVERSE = 0x01, /**< Inverse the TX waveform definition: mark changes to space and space changes to mark. */
} IRTxDefInverse_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_TX_DEF_INVERSE(INV) (((INV) == IR_TX_DATA_NORMAL) || ((INV) == IR_TX_DATA_INVERSE))
/** @} */ /* End of group IR_TX_DEF_INVERSE */

/**
 * @defgroup IR_THRESHOLD IR Threshold
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_TX_THRESHOLD(THD)  ((THD) <= IR_TX_FIFO_SIZE)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_THRESHOLD(THD) ((THD) <= IR_RX_FIFO_SIZE)
/** @} */ /* End of group IR_THRESHOLD */

/**
 * @defgroup IR_RX_START_MODE IR RX Start Mode
 * @{
 */
typedef enum
{
    IR_RX_MANUAL_MODE = 0x00, /**< Manual mode. Call IR_StartManualRxTrigger to start receiving. */
    IR_RX_AUTO_MODE = 0x01,   /**< Auto mode. Start receiving when the IR RX trigger condition is met. The trigger condition is specified by @ref IRRxTriggerMode_TypeDef. */
} IRRxStartMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RX_START_MODE(MODE) (((MODE) == IR_RX_AUTO_MODE) || ((MODE) == IR_RX_MANUAL_MODE))
/** @} */ /* End of group IR_RX_START_MODE */

/**
 * @defgroup IR_RX_FIFO_DISCARD_SETTING IR RX FIFO Discard Setting
 * @{
 */
typedef enum
{
    IR_RX_FIFO_FULL_DISCARD_NEWEST = 0x00, /**< Discard the newest received data when RX FIFO is full. */
    IR_RX_FIFO_FULL_DISCARD_OLDEST = 0x01, /**< Discard the oldest data in FIFO when RX FIFO is full. */
} IRRxFIFODiscard_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_FIFO_FULL_DISCARD(CTRL)  (((CTRL) == IR_RX_FIFO_FULL_DISCARD_NEWEST) || ((CTRL) == IR_RX_FIFO_FULL_DISCARD_OLDEST))
/** @} */ /* End of group IR_RX_FIFO_DISCARD_SETTING */

/**
 * @defgroup IR_RX_TRIGGER_MODE IR RX Trigger Mode
 * @{
 */
typedef enum
{
    IR_RX_FALL_EDGE = 0x00,   /**< IR RX trigger mode is falling edge trigger. */
    IR_RX_RISING_EDGE = 0x01, /**< IR RX trigger mode is rising edge trigger. */
    IR_RX_DOUBLE_EDGE = 0x02, /**< IR RX trigger mode is double edge trigger. */
} IRRxTriggerMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RX_RX_TRIGGER_EDGE(EDGE) (((EDGE) == IR_RX_FALL_EDGE) || ((EDGE) == IR_RX_RISING_EDGE) || ((EDGE) == IR_RX_DOUBLE_EDGE))
/** @} */ /* End of group IR_RX_TRIGGER_MODE */

/**
 * @defgroup IR_RX_FILTER_TIME IR RX Filter Time
 * @{
 */
typedef enum
{
    IR_RX_FILTER_TIME_50NS  = 0x00, /**< IR RX filter time is 50ns. */
    IR_RX_FILTER_TIME_75NS  = 0x01, /**< IR RX filter time is 75ns. */
    IR_RX_FILTER_TIME_100NS = 0x02, /**< IR RX filter time is 100ns. */
    IR_RX_FILTER_TIME_125NS = 0x03, /**< IR RX filter time is 125ns. */
    IR_RX_FILTER_TIME_150NS = 0x04, /**< IR RX filter time is 150ns. */
    IR_RX_FILTER_TIME_175NS = 0x05, /**< IR RX filter time is 175ns. */
    IR_RX_FILTER_TIME_200NS = 0x06, /**< IR RX filter time is 200ns. */
    IR_RX_FILTER_TIME_225NS = 0x07, /**< IR RX filter time is 225ns. */
} IRRxFilterTime_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_FILTER_TIME_CTRL(CTRL)  (((CTRL) == IR_RX_FILTER_TIME_50NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_75NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_100NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_125NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_150NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_175NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_200NS) || \
                                          ((CTRL) == IR_RX_FILTER_TIME_225NS))
/** @} */ /* End of group IR_RX_FILTER_TIME */

/**
 * @defgroup IR_RX_COUNT_POLARITY IR RX Count Polarity
 * @{
 */
typedef enum
{
    IR_RX_COUNT_LOW_LEVEL  = 0x00,  /**< The level polarity that triggers the IR_INT_RX_CNT_THR interrupt is low level. */
    IR_RX_COUNT_HIGH_LEVEL  = 0x01, /**< The level polarity that triggers the IR_INT_RX_CNT_THR interrupt is high level. */
} IRRxCountPol_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_COUNT_POLARITY(CTRL)  (((CTRL) == IR_RX_COUNT_LOW_LEVEL) || ((CTRL) == IR_RX_COUNT_HIGH_LEVEL))
/** @} */ /* End of group IR_RX_COUNT_POLARITY */

/**
 * @defgroup IR_COMPENSATION_FLAG IR Compensation Flag
 * @{
 */
typedef enum
{
    IR_COMPEN_NONE = (0UL << 27),  /**< No compensation, 0/8 carrier cycle. */
    IR_COMPEN_1_8  = (1UL << 27),  /**< 1/8 carrier cycle. */
    IR_COMPEN_1_4  = (2UL << 27),  /**< 2/8 = 1/4 carrier cycle. */
    IR_COMPEN_3_8  = (3UL << 27),  /**< 3/8 carrier cycle. */
    IR_COMPEN_1_2  = (4UL << 27),  /**< 4/8 = 1/2 carrier cycle. */
    IR_COMPEN_5_8  = (5UL << 27),  /**< 5/8 carrier cycle. */
    IR_COMPEN_3_4  = (6UL << 27),  /**< 6/8 = 3/4 carrier cycle. */
    IR_COMPEN_7_8  = (7UL << 27),  /**< 7/8 carrier cycle. */
} IRTxCompen_TypeDef;

/** @} */ /* End of group IR_COMPENSATION_FLAG */

#if IR_SUPPORT_TX_MODE_CONFIG
/**
 * @defgroup IR_TX_OUTPUT_MODE IR TX Output Mode
 * @{
 */
typedef enum
{
    IR_TX_PUSH_PULL,  /**< IR TX push-pull output mode. */
    IR_TX_OPEN_DRAIN, /**< IR TX open-drain output mode. */
} IRTXMode_TypeDef;

/** @} */ /* End of group IR_TX_OUTPUT_MODE */
#endif

/**
 * @defgroup IR_RX_COUNTER_THRESHOLD IR RX Counter Threshold
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_COUNTER_THRESHOLD(THD) ((THD) <= 0x7fffffffUL)
/** @} */ /* End of group IR_RX_COUNTER_THRESHOLD */

/**
 * @defgroup IR_INTERRUPT IR Interrupt
 * @{
 */
/* All interrupts in transmission mode */
#define IR_INT_TF_EMPTY                             BIT0 /**< TX FIFO empty interrupt. */
#define IR_INT_TF_LEVEL                             BIT1 /**< TX FIFO threshold interrupt. */
#define IR_INT_TF_OF                                BIT4 /**< TX FIFO overflow interrupt. */
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH                            BIT5 /**< TX finish interrupt. */
#endif

/* All interrupts in receiving mode */
#define IR_INT_RF_FULL                              BIT0 /**< RX FIFO full interrupt. */
#define IR_INT_RF_LEVEL                             BIT1 /**< RX FIFO threshold interrupt. */
#define IR_INT_RX_CNT_OF                            BIT2 /**< RX counter overflow interrupt. */
#define IR_INT_RF_OF                                BIT3 /**< RX FIFO overflow interrupt. */
#define IR_INT_RX_CNT_THR                           BIT4 /**< RX counter threshold interrupt. */
#define IR_INT_RF_ERROR                             BIT5 /**< RX FIFO error read interrupt. Triggered when RX FIFO empty and read RX FIFO. */
#define IR_INT_FALLING_EDGE                         BIT6 /**< RX falling edge interrupt. */
#define IR_INT_RISING_EDGE                          BIT7 /**< RX rising edge interrupt. */
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF)      || \
                                       ((CONFIG) == IR_INT_TX_FINISH))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_TX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_TF_EMPTY)   || \
                                       ((CONFIG) == IR_INT_TF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_TF_OF))
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_RX_INT_CONFIG(CONFIG)   (((CONFIG) == IR_INT_RF_FULL)     || \
                                       ((CONFIG) == IR_INT_RF_LEVEL)   || \
                                       ((CONFIG) == IR_INT_RX_CNT_OF)  || \
                                       ((CONFIG) == IR_INT_RF_OF)      || \
                                       ((CONFIG) == IR_INT_RX_CNT_THR) || \
                                       ((CONFIG) == IR_INT_RF_ERROR)      || \
                                       ((CONFIG) == IR_INT_RISING_EDGE) || \
                                       ((CONFIG) == IR_INT_FALLING_EDGE))
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_INT_CONFIG(CONFIG)      (IS_IR_TX_INT_CONFIG(CONFIG) || IS_IR_RX_INT_CONFIG(CONFIG))
/** @} */ /* End of group IR_INTERRUPT */

/**
 * @defgroup IR_INTERRUPTS_CLEAR_FLAG IR Interrupts Clear Flag
 * @{
 */
/* Clear all interrupts in transmission mode */
#define IR_TF_CLR                                   BIT0  /**< Clear TX FIFO interrupt status. */
#define IR_INT_TF_EMPTY_CLR                         BIT1  /**< Clear TX FIFO empty interrupt status. */
#define IR_INT_TF_LEVEL_CLR                         BIT2  /**< Clear TX FIFO threshold interrupt status. */
#define IR_INT_TF_OF_CLR                            BIT3  /**< Clear TX FIFO overflow interrupt status. */
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_INT_TX_FINISH_CLR                        BIT4  /**< Clear TX finish interrupt status. */
#endif

#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR    | \
                                            IR_INT_TX_FINISH_CLR) /**< Combination of all TX interrupt clear flags. */
#else
#define IR_TX_INT_ALL_CLR                  (IR_INT_TF_EMPTY_CLR | \
                                            IR_INT_TF_LEVEL_CLR | \
                                            IR_INT_TF_OF_CLR) /**< Combination of all TX interrupt clear flags. */
#endif

/* Clear all interrupts in receiving mode */
#define IR_INT_RF_FULL_CLR                         BIT0  /**< Clear RX FIFO full interrupt status. */
#define IR_INT_RF_LEVEL_CLR                        BIT1  /**< Clear RX FIFO threshold interrupt status. */
#define IR_INT_RX_CNT_OF_CLR                       BIT2  /**< Clear RX counter overflow interrupt status. */
#define IR_INT_RF_OF_CLR                           BIT3  /**< Clear RX FIFO overflow interrupt status. */
#define IR_INT_RX_CNT_THR_CLR                      BIT4  /**< Clear RX counter threshold interrupt status. */
#define IR_INT_RF_ERROR_CLR                        BIT5  /**< Clear RX FIFO error read interrupt status. */
#define IR_INT_RX_FALLING_EDGE_CLR                 BIT6  /**< Clear RX falling edge interrupt status. */
#define IR_INT_RX_RISING_EDGE_CLR                  BIT7  /**< Clear RX rising edge interrupt status. */
#define IR_RF_CLR                                  BIT8  /**< Clear RX FIFO interrupt status. */
#define IR_RX_INT_ALL_CLR                (IR_INT_RF_FULL_CLR | IR_INT_RF_LEVEL_CLR | \
                                          IR_INT_RX_CNT_OF_CLR | IR_INT_RF_OF_CLR | \
                                          IR_INT_RX_CNT_THR_CLR | IR_INT_RF_ERROR_CLR | \
                                          IR_INT_RX_RISING_EDGE_CLR|IR_INT_RX_FALLING_EDGE_CLR) /**< Combination of all RX interrupt clear flags. */
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_TX_FINISH_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_INT_CLEAR(INT)            (((INT) == IR_INT_TF_EMPTY_CLR) || ((INT) == IR_INT_TF_LEVEL_CLR) || \
                                         ((INT) == IR_INT_TF_OF_CLR) || ((INT) == IR_INT_RF_FULL_CLR) || \
                                         ((INT) == IR_INT_RF_LEVEL_CLR) || ((INT) == IR_INT_RX_CNT_OF_CLR) || \
                                         ((INT) == IR_INT_RF_OF_CLR) || ((INT) == IR_INT_RX_CNT_THR_CLR) || \
                                         ((INT) == IR_INT_RX_RISING_EDGE_CLR) || ((INT) == IR_INT_RX_FALLING_EDGE_CLR) || \
                                         ((INT) == IR_INT_RF_ERROR_CLR))
#endif

/** @} */ /* End of group IR_INTERRUPTS_CLEAR_FLAG */

/**
 * @defgroup IR_FLAG IR Flag
 * @{
 */
#define IR_FLAG_TF_EMPTY                       BIT15 /**< TX FIFO empty flag. */
#define IR_FLAG_TF_FULL                        BIT14 /**< TX FIFO full flag. */
#define IR_FLAG_TX_RUN                         BIT4  /**< TX running flag. */
#define IR_FLAG_RF_EMPTY                       BIT17 /**< RX FIFO empty flag. */
#define IR_FLAG_RF_FULL                        BIT16 /**< RX FIFO full flag. */
#define IR_FLAG_RX_RUN                         BIT7  /**< RX running flag. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_FLAG(FLAG)                (((FLAG) == IR_FLAG_TF_EMPTY) || ((FLAG) == IR_FLAG_TF_FULL) || \
                                         ((FLAG) == IR_FLAG_TX_RUN) || ((FLAG) == IR_FLAG_RF_EMPTY) || \
                                         ((FLAG) == IR_FLAG_RF_FULL) || ((FLAG) == IR_FLAG_RX_RUN))
/** @} */ /* End of group IR_FLAG */

#if (IR_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup IR_ACTION IR Action
 * @{
 */
typedef enum
{
    IR_ACTION_START_RX = 0, /**< Start RX action. */
    IR_ACTION_START_TX = 1, /**< Start TX action. */
} IRAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_IR_ACTION(ACTION)            (((ACTION) == IR_ACTION_START_RX) || \
                                         ((ACTION) == IR_ACTION_START_TX))

/** @} */ /* End of group IR_ACTION */
#endif

/** @} */ /* End of group IR_Exported_Constants */

/**
 * @defgroup IR_Exported_Types IR Exported Types
 * @{
 */

/**
 * @brief IR init structure definition.
 */
typedef struct
{
    IRClock_TypeDef IR_Clock;                 /**< Specifies the source clock frequency.
                                                   This parameter can be a value of @ref IR_CLOCK. */

    uint32_t IR_Freq;                         /**< Specifies the clock frequency.
                                                   This parameter is IR carrier frequency whose unit is Hz. */

    float IR_DutyCycle;                       /**< Specifies the IR duty cycle.
                                                   The carrier duty cycle is 1/IR_DutyCycle. */

    IRMode_TypeDef IR_Mode;                   /**< Specifies the IR mode.
                                                   This parameter can be a value of @ref IR_MODE. */

    IRIdleStatus_TypeDef IR_TxIdleLevel;      /**< Specifies the IR output level in TX mode.
                                                   This parameter can be a value of @ref IR_IDLE_STATUS. */

    IRTxDefInverse_TypeDef
    IR_TxInverse;      /**< Specifies whether to inverse the TX waveform definition in TX mode.
                                                   When inversed, mark changes to space and space changes to mark.
                                                   This parameter can be a value of @ref IR_TX_DEF_INVERSE. */

    uint32_t IR_TxFIFOThrLevel;               /**< Specifies TX FIFO interrupt threshold in TX mode.
                                                   When TX FIFO depth <= threshold value, trigger the IR_INT_TF_LEVEL interrupt.
                                                   This parameter can be a value of 1 to 32. */

    IRRxStartMode_TypeDef IR_RxStartMode;     /**< Specifies Start mode in RX mode.
                                                   This parameter can be a value of @ref IR_RX_START_MODE. */

    uint32_t IR_RxFIFOThrLevel;               /**< Specifies RX FIFO interrupt threshold in RX mode.
                                                   When RX FIFO depth > threshold value, trigger the IR_INT_RF_LEVEL interrupt.
                                                   This parameter can be a value of 1 to 32. */

    IRRxFIFODiscard_TypeDef IR_RxFIFOFullCtrl; /**< Specifies data discard mode
                                                   in RX mode when RX FIFO is full and receiving new data.
                                                   This parameter can be a value of @ref IR_RX_FIFO_DISCARD_SETTING. */

    IRRxTriggerMode_TypeDef IR_RxTriggerMode; /**< Specifies trigger in RX mode.
                                                   This parameter can be a value of @ref IR_RX_TRIGGER_MODE. */

    IRRxFilterTime_TypeDef IR_RxFilterTime;   /**< Specifies filter time in RX mode.
                                                   This parameter can be a value of @ref IR_RX_FILTER_TIME. */

    IRRxCountPol_TypeDef IR_RxCntThrType;     /**< Specifies counter level type
                                                   when trigger IR_INT_RX_CNT_THR interrupt in RX mode.
                                                   This parameter can be a value of @ref IR_RX_COUNT_POLARITY. */

    uint32_t IR_RxCntThr;                     /**< Specifies counter threshold value
                                                   when trigger IR_INT_RX_CNT_THR interrupt in RX mode. */

    FunctionalState IR_TxDMAEn;               /**< Specifies the TX DMA mode.
                                                   This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_TxWaterLevel;                  /**< Specifies the DMA TX water level.
                                                   This parameter must range from 0 to 32. */

    FunctionalState IR_RxDMAEn;               /**< Specifies the RX DMA mode.
                                                   This parameter must be a value of DISABLE and ENABLE. */

    uint8_t IR_RxWaterLevel;                  /**< Specifies the DMA RX water level.
                                                   This parameter must range from 0 to 32. */

#if IR_SUPPORT_TX_MODE_CONFIG
    IRTXMode_TypeDef IR_TxOutputMode;         /**< Specifies the IR TX output mode.
                                                   This parameter can be a value of @ref IR_TX_OUTPUT_MODE. */
#endif

} IR_InitTypeDef;

/** @} */ /* End of group IR_Exported_Types */

/**
 * @defgroup IR_Exported_Functions IR Exported Functions
 * @{
 */

/**
 * @brief Deinitializes the IR peripheral registers to their default values.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_ir_init(void)
 * {
 *     IR_DeInit();
 * }
 * @endcode
 */
void IR_DeInit(void);

/**
 * @brief Initializes the IR peripheral according to the specified parameters in IR_InitStruct.
 *
 * @param[in] IR_InitStruct Pointer to a IR_InitTypeDef structure that contains the configuration information for the specified IR peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_ir_init(void)
 * {
 *     RCC_ClockCmd(IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = 2;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50NS;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_COUNT_HIGH_LEVEL;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * @endcode
 */
void IR_Init(IR_InitTypeDef *IR_InitStruct);

/**
 * @brief Fills each IR_InitStruct member with its default value.
 *
 * @note The default settings for the IR_InitStruct member are shown in the following table:
 *         | IR_InitStruct member  | Default value                            |
 *         |:---------------------:|:----------------------------------------:|
 *         | IR_Clock              | @ref IR_CLOCK_40M                        |
 *         | IR_Freq               | 38000                                    |
 *         | IR_DutyCycle          | 3                                        |
 *         | IR_Mode               | @ref IR_MODE_TX                          |
 *         | IR_TxIdleLevel        | @ref IR_IDLE_OUTPUT_LOW                  |
 *         | IR_TxInverse          | @ref IR_TX_DATA_NORMAL                   |
 *         | IR_TxFIFOThrLevel     | 0                                        |
 *         | IR_RxStartMode        | @ref IR_RX_AUTO_MODE                     |
 *         | IR_RxFIFOThrLevel     | 0                                        |
 *         | IR_RxFIFOFullCtrl     | @ref IR_RX_FIFO_FULL_DISCARD_NEWEST      |
 *         | IR_RxTriggerMode      | @ref IR_RX_FALL_EDGE                     |
 *         | IR_RxFilterTime       | @ref IR_RX_FILTER_TIME_50NS              |
 *         | IR_RxCntThrType       | @ref IR_RX_COUNT_LOW_LEVEL               |
 *         | IR_RxCntThr           | 0x23a                                    |
 *         | IR_TxDMAEn            | DISABLE                                  |
 *         | IR_TxWaterLevel       | 31                                       |
 *         | IR_RxDMAEn            | DISABLE                                  |
 *         | IR_RxWaterLevel       | 1                                        |
 *
 * @param[in] IR_InitStruct Pointer to an IR_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_ir_init(void)
 * {
 *     RCC_ClockCmd(IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = 2;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50NS;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_COUNT_HIGH_LEVEL;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * @endcode
 */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct);

/**
 * @brief Enable or disable the selected IR mode.
 *
 * @param[in] mode Selected IR operation mode.
 *            This parameter can be one of the following values:
 *            - IR_MODE_TX: Transmission mode.
 *            - IR_MODE_RX: Receiving mode.
 * @param[in] NewState New state of the operation mode.
 *            - ENABLE: Enable the selected IR mode.
 *            - DISABLE: Disable the selected IR mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_ir_init(void)
 * {
 *     RCC_ClockCmd(IR_CLOCK, ENABLE);
 *
 *     IR_InitTypeDef IR_InitStruct;
 *     IR_StructInit(&IR_InitStruct);
 *
 *     IR_InitStruct.IR_Freq               = 38000;
 *     IR_InitStruct.IR_Mode               = IR_MODE_RX;
 *     IR_InitStruct.IR_RxStartMode        = IR_RX_AUTO_MODE;
 *     IR_InitStruct.IR_RxFIFOThrLevel     = 2;
 *     IR_InitStruct.IR_RxFIFOFullCtrl     = IR_RX_FIFO_FULL_DISCARD_NEWEST;
 *     IR_InitStruct.IR_RxFilterTime       = IR_RX_FILTER_TIME_50NS;
 *     IR_InitStruct.IR_RxTriggerMode      = IR_RX_FALL_EDGE;
 *     IR_InitStruct.IR_RxCntThrType       = IR_RX_COUNT_HIGH_LEVEL;
 *     IR_InitStruct.IR_RxCntThr           = 0x1F40;
 *     IR_Init(&IR_InitStruct);
 *     IR_Cmd(IR_MODE_RX, ENABLE);
 *     IR_ClearRxFIFO();
 * }
 * @endcode
 */
void IR_Cmd(uint32_t mode, FunctionalState NewState);

/**
 * @brief Start trigger receive, only in manual receive mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_StartManualRxTrigger();
 * }
 * @endcode
 */
void IR_StartManualRxTrigger(void);

/**
 * @brief Config counter threshold value in receiving mode. It can be used to stop receiving IR data.
 *
 * @param[in] IR_RxCntThrType Count threshold type.
 *            This parameter can be the following values:
 *            - IR_RX_COUNT_LOW_LEVEL: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 *            - IR_RX_COUNT_HIGH_LEVEL: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 * @param[in] IR_RxCntThr Configure IR Rx counter threshold value which can be 0 to 0x7fffffffUL.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SetRxCounterThreshold(IR_RX_COUNT_LOW_LEVEL, 0x100);
 * }
 * @endcode
 */
void IR_SetRxCounterThreshold(uint32_t IR_RxCntThrType, uint32_t IR_RxCntThr);

/**
 * @brief Send data.
 *
 * @param[in] pBuf Data buffer to send.
 * @param[in] len Send data length.
 * @param[in] IsLastPacket Specifies whether this buffer is the last packet of data.
 *            - ENABLE: This buffer is the last packet of data. An infrared data transmission is completed.
 *            - DISABLE: This buffer is not the last packet of data. There is data to be transmitted continuously.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendBuf(data_buf, 68, DISABLE);
 * }
 * @endcode
 */
void IR_SendBuf(uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket);

/**
 * @brief Send compensation data.
 *
 * @param[in] comp_type Compensation level applied to the space waveform only.
 *            This parameter can be a value of @ref IR_COMPENSATION_FLAG.
 * @param[in] pBuf Data buffer to send. Each element is a 32-bit IR waveform word.
 * @param[in] len Number of 32-bit elements in the buffer.
 * @param[in] IsLastPacket Specifies whether this buffer is the last packet of data.
 *            - ENABLE: This buffer is the last packet of data. An infrared data transmission is completed.
 *            - DISABLE: This buffer is not the last packet of data. There is data to be transmitted continuously.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_SendCompenBuf(IR_COMPEN_1_2, data_buf, 68, DISABLE);
 * }
 * @endcode
 */
void IR_SendCompenBuf(IRTxCompen_TypeDef comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket);

/**
 * @brief Read data from RX FIFO.
 *
 * @param[out] pBuf Buffer address to receive data.
 * @param[in] len Read data length.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t data_buf[80] = {0};
 *     IR_ReceiveBuf(data_buf, 68);
 * }
 * @endcode
 */
void IR_ReceiveBuf(uint32_t *pBuf, uint32_t len);

/**
 * @brief Enables or disables the specified IR interrupt.
 *
 * @param[in] IR_INT Specifies the IR interrupt to be enabled or disabled, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 * @param[in] NewState New state of the specified IR interrupt.
 *            - ENABLE: Enable the specified IR interrupt.
 *            - DISABLE: Disable the specified IR interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_INTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * @endcode
 */
void IR_INTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 * @brief Mask or unmask the specified IR interrupt.
 *
 * @param[in] IR_INT Specifies the IR interrupt to be masked or unmasked, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 * @param[in] NewState New state of the specified IR interrupt.
 *            - ENABLE: Mask the specified IR interrupt.
 *            - DISABLE: Unmask the specified IR interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_MaskINTConfig(IR_INT_TF_EMPTY, ENABLE);
 * }
 * @endcode
 */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState NewState);

/**
 * @brief Get the specified IR interrupt status.
 *
 * @param[in] IR_INT The specified IR interrupt, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 *
 * @return The new state of IR_INT.
 * @retval SET    The specified IR interrupt status is set.
 * @retval RESET  The specified IR interrupt status is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     ITStatus int_status = IR_GetINTStatus(IR_INT_TF_EMPTY);
 * }
 * @endcode
 */
ITStatus IR_GetINTStatus(uint32_t IR_INT);

/**
 * @brief Clear the IR interrupt pending bit.
 *
 * @param[in] IR_CLEAR_INT Specifies the interrupt pending bit to clear, refer to @ref IR_INTERRUPTS_CLEAR_FLAG.
 *            This parameter can be any combination of the following values:
 *            - IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH_CLR: Clear TX finish interrupt.
 *            - IR_INT_RF_FULL_CLR: Clear RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *            - IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RX_RISING_EDGE_CLR: Clear RX rising edge interrupt.
 *            - IR_INT_RX_FALLING_EDGE_CLR: Clear RX falling edge interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_ClearINTPendingBit(IR_INT_RX_CNT_OF_CLR);
 * }
 * @endcode
 */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT);

/**
 * @brief Get free size of TX FIFO.
 *
 * @return The free size of TX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetTxFIFOFreeLen();
 * }
 * @endcode
 */
uint16_t IR_GetTxFIFOFreeLen(void);

/**
 * @brief Get data size in RX FIFO.
 *
 * @return Current data size in RX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint16_t data_len = IR_GetRxDataLen();
 * }
 * @endcode
 */
uint16_t IR_GetRxDataLen(void);

/**
 * @brief Send one data.
 *
 * @param[in] data Send data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SendData(0x80000100);
 * }
 * @endcode
 */
void IR_SendData(uint32_t data);

/**
 * @brief Read one data.
 *
 * @return Data which read from RX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t data = IR_ReceiveData();
 * }
 * @endcode
 */
uint32_t IR_ReceiveData(void);

/**
 * @brief Set TX threshold, when TX FIFO depth <= threshold value trigger the IR_INT_TF_LEVEL interrupt.
 *
 * @param[in] thd TX threshold.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SetTxThreshold(30);
 * }
 * @endcode
 */
void IR_SetTxThreshold(uint8_t thd);

/**
 * @brief Set RX threshold, when RX FIFO depth >= threshold value trigger the IR_INT_RF_LEVEL interrupt.
 *
 * @param[in] thd RX threshold.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SetRxThreshold(2);
 * }
 * @endcode
 */
void IR_SetRxThreshold(uint8_t thd);

/**
 * @brief Get IR RX current count.
 *
 * @return Current counter.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t count = IR_GetRxCurrentCount();
 * }
 * @endcode
 */
uint32_t IR_GetRxCurrentCount(void);

/**
 * @brief Clear IR TX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_ClearTxFIFO();
 * }
 * @endcode
 */
void IR_ClearTxFIFO(void);

/**
 * @brief Clear IR RX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_ClearRxFIFO();
 * }
 * @endcode
 */
void IR_ClearRxFIFO(void);

/**
 * @brief Check whether the specified IR flag is set.
 *
 * @param[in] IR_FLAG Specifies the flag to check, refer to @ref IR_FLAG.
 *            This parameter can be one of the following values:
 *            - IR_FLAG_TF_EMPTY: TX FIFO empty flag. If SET, TX FIFO is empty.
 *            - IR_FLAG_TF_FULL: TX FIFO full flag. If SET, TX FIFO is full.
 *            - IR_FLAG_TX_RUN: TX running flag. If SET, TX is running.
 *            - IR_FLAG_RF_EMPTY: RX FIFO empty flag. If SET, RX FIFO is empty.
 *            - IR_FLAG_RF_FULL: RX FIFO full flag. If SET, RX FIFO is full.
 *            - IR_FLAG_RX_RUN: RX running flag. If SET, RX is running.
 *
 * @return The new state of IR_FLAG.
 * @retval SET    The specified IR flag is set.
 * @retval RESET  The specified IR flag is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     FlagStatus flag_status = IR_GetFlagStatus(IR_FLAG_TF_EMPTY);
 * }
 * @endcode
 */
FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG);

/**
 * @brief Set whether to inverse the space/mark waveform definition in TX mode.
 *
 * @param[in] NewState New state of the TX waveform definition inverse.
 *            - ENABLE: Inverse the waveform definition. Mark changes to space and space changes to mark.
 *            - DISABLE: Do not inverse the waveform definition.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_TxWaveDefInverseCmd(ENABLE);
 * }
 * @endcode
 */
void IR_TxWaveDefInverseCmd(FunctionalState NewState);

/**
 * @brief Set whether to inverse the high/low level polarity of the TX output.
 *
 * @param[in] NewState New state of the TX output polarity inverse.
 *            - ENABLE: Inverse the TX output level polarity. High level changes to low and low changes to high.
 *            - DISABLE: Do not inverse the TX output level polarity.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_TxPolarityInverseCmd(ENABLE);
 * }
 * @endcode
 */
void IR_TxPolarityInverseCmd(FunctionalState NewState);

/**
 * @brief Get IR RX Level.
 *
 * @return Current Level.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     uint32_t level = IR_GetRxCurrentLevel();
 * }
 * @endcode
 */
uint32_t IR_GetRxCurrentLevel(void);

/**
 * @brief Set TX DMA water level.
 *        DMA request is triggered when TX FIFO free space >= water level.
 *        Should be less than TX FIFO depth (32).
 *
 * @param[in] water_level TX DMA water level.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SetTxWaterLevel(31);
 * }
 * @endcode
 */
void IR_SetTxWaterLevel(uint8_t water_level);

/**
 * @brief Set RX DMA water level.
 *        DMA request is triggered when RX FIFO data count >= water level.
 *        Should be less than RX FIFO depth (32).
 *
 * @param[in] water_level RX DMA water level.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_SetRxWaterLevel(1);
 * }
 * @endcode
 */
void IR_SetRxWaterLevel(uint8_t water_level);

#if (IR_SUPPORT_CLOCK_SOURCE_DIV_CONFIG == 1)
/**
 * @brief Configure the IR clock source and divider.
 *
 * @param[in] ClockSrc  Specifies the IR clock source, refer to @ref IR_CLOCK_SOURCE.
 * @param[in] ClockDiv  Specifies the IR clock divider, refer to @ref IR_CLOCK_DIVIDER.
 */
void IR_SetClock(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv);
#endif

#if (IR_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the IR RAP mode.
 *
 * @param[in] NewState New state of the IR RAP mode.
 *            - ENABLE: Enable the IR RAP mode.
 *            - DISABLE: Disable the IR RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_RAPModeCmd(ENABLE);
 * }
 * @endcode
 */
void IR_RAPModeCmd(FunctionalState NewState);

/**
 * @brief Trigger the specified IR action.
 *
 * @param[in] Action  Specifies the IR action to trigger.
 *                    This parameter can be one of the following values:
 *                    - IR_ACTION_START_RX: Start RX action.
 *                    - IR_ACTION_START_TX: Start TX action.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_ActionTrigger(IR_ACTION_START_RX);
 * }
 * @endcode
 */
void IR_ActionTrigger(uint32_t Action);

#endif

#if (IR_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable the IR clock auto mode.
 *
 * @param[in] NewState New state of the IR clock auto mode.
 *            - ENABLE: Enable the IR clock auto mode.
 *            - DISABLE: Disable the IR clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void ir_demo(void)
 * {
 *     IR_ClockAutoModeCmd(ENABLE);
 * }
 * @endcode
 */
void IR_ClockAutoModeCmd(FunctionalState NewState);

#endif

/** @} */ /* End of group IR_Exported_Functions */

/** @} */ /* End of group IR_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_IR_H */
