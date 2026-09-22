/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_KEYSCAN_H
#define RTL_KEYSCAN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "keyscan/src/device/rtl87x2g/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "keyscan/src/device/rtl87x3d/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "keyscan/src/device/rtl87x2j/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "keyscan/src/device/rtl87x3j/rtl_keyscan_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "keyscan/src/device/rtl87x3k/rtl_keyscan_def.h"
#endif

/**
 * @defgroup KEYSCAN_DRIVER DRIVER
 * @ingroup KEYSCAN
 * @brief Keyboard Scanner (KeyScan) driver.
 * @{
 */

/**
 * @defgroup KEYSCAN_Exported_Constants KEYSCAN Exported Constants
 * @{
 */

/**
 * @defgroup KEYSCAN_ROW_NUMBER KEYSCAN Row Number
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_ROW_NUM(ROW) ((ROW) <= KEYSCAN_MAX_ROW_NUM)
/** @} */ /* End of group KEYSCAN_ROW_NUMBER */

/**
 * @defgroup KEYSCAN_COLUMN_NUMBER KEYSCAN Column Number
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_COL_NUM(COL) ((COL) <= KEYSCAN_MAX_COL_NUM)
/** @} */ /* End of group KEYSCAN_COLUMN_NUMBER */

/**
 * @defgroup KEYSCAN_SCAN_MODE KEYSCAN Scan Mode
 * @{
 */

/**
 * @brief KEYSCAN scan mode.
 */
typedef enum
{
    KEYSCAN_MANUAL_SCAN_MODE = 0x00,   /**< The KEYSCAN manual scan mode. */
    KEYSCAN_AUTO_SCAN_MODE = 0x01,     /**< The KEYSCAN auto scan mode. */
} KEYSCANScanMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_SCAN_MODE(MODE)  (((MODE) == KEYSCAN_MANUAL_SCAN_MODE) || ((MODE) == KEYSCAN_AUTO_SCAN_MODE))
/** @} */ /* End of group KEYSCAN_SCAN_MODE */

/**
 * @defgroup KEYSCAN_DETECT_MODE KEYSCAN Detect Mode
 * @{
 */

/**
 * @brief KEYSCAN press detect mode.
 */
typedef enum
{
    KEYSCAN_DETECT_MODE_EDGE = 0x00,   /**< The key detection mode is edge-triggered. */
    KEYSCAN_DETECT_MODE_LEVEL = 0x01,  /**< The key detection mode is level-triggered. */
} KEYSCANDetectMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_DETECT_MODE(MODE)    (((MODE) == KEYSCAN_DETECT_MODE_EDGE) || ((MODE) == KEYSCAN_DETECT_MODE_LEVEL))
/** @} */ /* End of group KEYSCAN_DETECT_MODE */

/**
 * @defgroup KEYSCAN_FIFO_OVERFLOW_CONTROL KEYSCAN FIFO Overflow Control
 * @{
 */

/**
 * @brief KEYSCAN FIFO overflow control.
 */
typedef enum
{
    KEYSCAN_FIFO_OVFL_CTRL_DIS_NEWEST = 0x00,   /**< Discard the new scan data when FIFO is full. */
    KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST = 0x01,   /**< Discard the oldest scan data when FIFO is full. */
} KEYSCANFIFOvflCtl_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_FIFO_OVFL_CTRL(CTRL)  (((CTRL) == KEYSCAN_FIFO_OVFL_CTRL_DIS_NEWEST) || ((CTRL) == KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST))
/** @} */ /* End of group KEYSCAN_FIFO_OVERFLOW_CONTROL */

/**
 * @defgroup KEYSCAN_MANUAL_SEL KEYSCAN Manual Sel
 * @{
 */

/**
 * @brief KEYSCAN manual mode selection.
 */
typedef enum
{
    KEYSCAN_MANUAL_SEL_BIT = 0x00,     /**< KEYSCAN manual trigger register (Call API KEYSCAN_Cmd). */
    KEYSCAN_MANUAL_SEL_KEY = 0x01,     /**< KEYSCAN manual trigger by key. */
} KEYSCANManualSel_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_MANUAL_SELECT(SEL)  (((SEL) == KEYSCAN_MANUAL_SEL_BIT) || ((SEL) == KEYSCAN_MANUAL_SEL_KEY))
/** @} */ /* End of group KEYSCAN_MANUAL_SEL */

#if (KEYSCAN_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup KEYSCAN_ACTION KEYSCAN Action
 * @{
 */

/**
 * @brief KEYSCAN action type.
 */
typedef enum
{
    KEYSCAN_ACTION_MANUAL = 0,   /**< KEYSCAN manual scan action. */
} KEYSCANAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_ACTION(ACTION) ((ACTION) == KEYSCAN_ACTION_MANUAL)

/** @} */ /* End of group KEYSCAN_ACTION */
#endif

/**
 * @defgroup KEYSCAN_KEY_LIMIT KEYSCAN Key Limit
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_KEY_LIMIT(DATA_NUM) ((DATA_NUM) <= KEYSCAN_FIFO_DEPTH)
/** @} */ /* End of group KEYSCAN_KEY_LIMIT */

/**
 * @defgroup KEYSCAN_INTERRUPT KEYSCAN Interrupt
 * @{
 */
#define KEYSCAN_INT_THRESHOLD                    BIT4   /**< KEYSCAN FIFO data over threshold interrupt. */
#define KEYSCAN_INT_OVER_READ                    BIT3   /**< KEYSCAN over read interrupt. */
#define KEYSCAN_INT_SCAN_END                     BIT2   /**< KEYSCAN scan end interrupt. */
#define KEYSCAN_INT_FIFO_NOT_EMPTY               BIT1   /**< KEYSCAN FIFO not empty interrupt. */
#define KEYSCAN_INT_ALL_RELEASE                  BIT0   /**< KEYSCAN all key release interrupt. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_CONFIG_INT(INT) ((((INT) & (uint32_t)0xFFF8) == 0x00) && ((INT) != 0x00))
/** @} */ /* End of group KEYSCAN_INTERRUPT */

/**
 * @defgroup KEYSCAN_FLAG KEYSCAN Flag
 * @{
 */
#define KEYSCAN_FLAG_FIFOLIMIT                       BIT20   /**< FIFO limit status. The FIFO limit can be configured to limit the max allowable key data in one scan. */
#define KEYSCAN_INT_FLAG_THRESHOLD                   BIT19   /**< FIFO threshold interrupt status. */
#define KEYSCAN_INT_FLAG_OVER_READ                   BIT18   /**< FIFO over read interrupt status. */
#define KEYSCAN_INT_FLAG_SCAN_END                    BIT17   /**< Scan finish interrupt status. */
#define KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY              BIT16   /**< FIFO not empty interrupt status. */
#define KEYSCAN_INT_FLAG_ALL_RELEASE                 BIT15   /**< All release interrupt status. */
#define KEYSCAN_FLAG_DATAFILTER                      BIT3    /**< FIFO data filter status. */
#define KEYSCAN_FLAG_OVR                             BIT2    /**< FIFO overflow status. */
#define KEYSCAN_FLAG_FULL                            BIT1    /**< FIFO full status. */
#define KEYSCAN_FLAG_EMPTY                           BIT0    /**< FIFO empty status. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_FLAG(FLAG)       ((((FLAG) & (uint32_t)0x01FF) == 0x00) && ((FLAG) != (uint32_t)0x00))
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_KEYSCAN_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0x00C0) == 0x00) && ((FLAG) != (uint32_t)0x00))
/** @} */ /* End of group KEYSCAN_FLAG */

/** @} */ /* End of group KEYSCAN_Exported_Constants */

/**
 * @defgroup KEYSCAN_Exported_Types KEYSCAN Exported Types
 * @{
 */

/**
 * @brief KEYSCAN initialize parameters.
 *
 */
typedef struct
{
    uint16_t KEYSCAN_RowSize;                 /**< Specifies KEYSCAN row size.
                                                   This parameter can be a value <=12. */

    uint16_t KEYSCAN_ColSize;                 /**< Specifies KEYSCAN column size.
                                                   This parameter can be a value <=20. */

    uint16_t KEYSCAN_ClockDiv;                /**< Specifies KEYSCAN clock divider.
                                                   Scan clock = system clock/(SCAN_DIV+1). */

    uint8_t KEYSCAN_ClockDelayDiv;            /**< Specifies KEYSCAN clock delay divider.
                                                   Delay clock = scan clock/(DELAY_DIV+1). */

    FunctionalState KEYSCAN_DebounceEn;       /**< Enable or disable debounce.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    FunctionalState KEYSCAN_ScanTimerEn;      /**< Enable or disable scan interval timer.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    FunctionalState KEYSCAN_DetectTimerEn;    /**< Enable or disable all release timer.
                                                   This parameter can be a value of DISABLE or ENABLE. */

    uint16_t KEYSCAN_DebounceCnt;             /**< Specifies KEYSCAN debounce time.
                                                   Debounce time = delay clock * debouncecnt.
                                                   This parameter can be a value of 0 ~ 0x1FF. */

    uint16_t KEYSCAN_ScanInterval;            /**< Specifies KEYSCAN scan interval.
                                                   Scan interval time = delay clock * scanInterval.
                                                   This parameter can be a value of 0 ~ 0x1FF. */

    uint16_t KEYSCAN_ReleaseCnt;              /**< Specifies KEYSCAN release time.
                                                   Release time = delay clock * releasecnt.
                                                   This parameter can be a value of 0 ~ 0x1FF. */

    KEYSCANScanMode_TypeDef KEYSCAN_ScanMode; /**< Specifies KEYSCAN scan mode.
                                                   This parameter can be a value of @ref KEYSCAN_SCAN_MODE. */

    KEYSCANDetectMode_TypeDef
    KEYSCAN_DetectMode; /**< Specifies the edge state that triggers the KEYSCAN scan.
                                                       This parameter can be a value of @ref KEYSCAN_DETECT_MODE. */

    uint16_t KEYSCAN_FIFOTriggerLevel;        /**< Specifies KEYSCAN FIFO threshold to trigger interrupt
                                                   @ref KEYSCAN_INT_THRESHOLD.
                                                   This parameter can be a value of 0 to KEYSCAN_FIFO_DEPTH (108). */

    KEYSCANFIFOvflCtl_TypeDef KEYSCAN_FIFOOvflCtrl; /**< Specifies KEYSCAN FIFO overflow control.
                                                          This parameter can be a value of @ref KEYSCAN_FIFO_OVERFLOW_CONTROL. */

    uint8_t KEYSCAN_KeyLimit;                 /**< Specifies the maximum allowable scan data for each scan.
                                                   This parameter can be a value of 0 to KEYSCAN_FIFO_DEPTH (108). */

    KEYSCANManualSel_TypeDef KEYSCAN_ManualSel; /**< Specifies trigger mode in manual scan mode.
                                                     This parameter can be a value of @ref KEYSCAN_MANUAL_SEL. */

    uint8_t KEYSCAN_PreGuardCnt;              /**< Specifies KEYSCAN preguard time.
                                                   This parameter can be a value of 0 ~ 7. */

    uint8_t KEYSCAN_PostGuardCnt;             /**< Specifies KEYSCAN postguard time.
                                                   This parameter can be a value of 0 ~ 7. */

#if KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE
    FunctionalState KEYSCAN_RowPullHighEn;    /**< Enable or disable the function of row pull high.
                                                   This parameter can be a value of DISABLE or ENABLE. */
#endif

#if KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE
    FunctionalState
    KEYSCAN_ColunmOutputHighEn;   /**< Enable or disable the function of column output high.
                                                       This parameter can be a value of DISABLE or ENABLE. */
#endif

} KEYSCAN_InitTypeDef;

/** @} */ /* End of group KEYSCAN_Exported_Types */

/**
 * @defgroup KEYSCAN_Exported_Functions KEYSCAN Exported Functions
 * @{
 */

/**
 * @brief Deinitializes the KEYSCAN peripheral registers to their default reset values.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_keyscan_init(void)
 * {
 *     KEYSCAN_DeInit(KEYSCAN);
 * }
 * @endcode
 */
void KEYSCAN_DeInit(KEYSCAN_TypeDef *KEYSCANx);

/**
 * @brief Initializes the KEYSCAN peripheral according to the specified
 *        parameters in the KEYSCAN_InitStruct.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_InitStruct Pointer to a KEYSCAN_InitTypeDef structure that
 *             contains the configuration information for the specified KEYSCAN peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_keyscan_init(void)
 * {
 *     RCC_ClockCmd(KEYSCAN_CLOCK, ENABLE);
 *
 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KEYSCAN_StructInit(&KEYSCAN_InitStruct);
 *
 *     KEYSCAN_InitStruct.KEYSCAN_RowSize    = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.KEYSCAN_ColSize    = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.KEYSCAN_ScanMode   = KEYSCAN_MANUAL_SCAN_MODE;
 *     KEYSCAN_InitStruct.KEYSCAN_DebounceEn = ENABLE;
 *
 *     KEYSCAN_Init(KEYSCAN, &KEYSCAN_InitStruct);
 *
 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);  // Unmask keyscan interrupt
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_Init(KEYSCAN_TypeDef *KEYSCANx, KEYSCAN_InitTypeDef *KEYSCAN_InitStruct);

/**
 * @brief Fills each KEYSCAN_InitStruct member with its default value.
 *
 * @note The default settings for the KEYSCAN_InitStruct member are shown in the following table:
 *       | KEYSCAN_InitStruct member   | Default value                       |
 *       |:---------------------------:|:----------------------------------:|
 *       | KEYSCAN_RowSize             | 2                                  |
 *       | KEYSCAN_ColSize             | 2                                  |
 *       | KEYSCAN_ClockDiv            | 0x1f8                              |
 *       | KEYSCAN_ClockDelayDiv       | 0x01                               |
 *       | KEYSCAN_DebounceEn          | ENABLE                             |
 *       | KEYSCAN_ScanTimerEn         | ENABLE                             |
 *       | KEYSCAN_DetectTimerEn       | ENABLE                             |
 *       | KEYSCAN_DebounceCnt         | 0x10                               |
 *       | KEYSCAN_ScanInterval        | 0x10                               |
 *       | KEYSCAN_ReleaseCnt          | 0x1                                |
 *       | KEYSCAN_ScanMode            | @ref KEYSCAN_AUTO_SCAN_MODE        |
 *       | KEYSCAN_DetectMode          | @ref KEYSCAN_DETECT_MODE_EDGE      |
 *       | KEYSCAN_FIFOTriggerLevel    | 1                                  |
 *       | KEYSCAN_FIFOOvflCtrl        | @ref KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST |
 *       | KEYSCAN_KeyLimit            | 0x03                               |
 *       | KEYSCAN_ManualSel           | @ref KEYSCAN_MANUAL_SEL_KEY        |
 *       | KEYSCAN_PreGuardCnt         | 3                                  |
 *       | KEYSCAN_PostGuardCnt        | 3                                  |
 *       | KEYSCAN_RowPullHighEn       | ENABLE                             |
 *       | KEYSCAN_ColunmOutputHighEn  | DISABLE                            |
 *
 * @param[in] KEYSCAN_InitStruct Pointer to a KEYSCAN_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_keyscan_init(void)
 * {
 *     RCC_ClockCmd(KEYSCAN_CLOCK, ENABLE);
 *
 *     KEYSCAN_InitTypeDef KEYSCAN_InitStruct;
 *     KEYSCAN_StructInit(&KEYSCAN_InitStruct);
 *
 *     KEYSCAN_InitStruct.KEYSCAN_RowSize    = KEYBOARD_ROW_SIZE;
 *     KEYSCAN_InitStruct.KEYSCAN_ColSize    = KEYBOARD_COLUMN_SIZE;
 *     KEYSCAN_InitStruct.KEYSCAN_ScanMode   = KEYSCAN_MANUAL_SCAN_MODE;
 *     KEYSCAN_InitStruct.KEYSCAN_DebounceEn = ENABLE;
 *
 *     KEYSCAN_Init(KEYSCAN, &KEYSCAN_InitStruct);
 *
 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);  // Unmask keyscan interrupt
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_StructInit(KEYSCAN_InitTypeDef *KEYSCAN_InitStruct);

/**
 * @brief Enables or disables the specified KEYSCAN interrupt.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * @param[in] NewState New state of the specified KEYSCAN interrupts.
 *            - ENABLE: Enable the specified KEYSCAN interrupts.
 *            - DISABLE: Disable the specified KEYSCAN interrupts.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_INTConfig(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, DISABLE);
 * }
 * @endcode
 */
void KEYSCAN_INTConfig(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT,
                       FunctionalState NewState);

/**
 * @brief Mask the specified KEYSCAN interrupt.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * @param[in] NewState New state of the specified KEYSCAN interrupts mask.
 *            - ENABLE: Mask the specified KEYSCAN interrupts.
 *            - DISABLE: Unmask the specified KEYSCAN interrupts.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_INTMask(KEYSCAN, KEYSCAN_INT_SCAN_END, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_INTMask(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT,
                     FunctionalState NewState);

/**
 * @brief Read data from KEYSCAN FIFO.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[out] outBuf Buffer to save data read from KEYSCAN FIFO.
 * @param[in] count Data length to be read.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     uint16_t data[3] = {0};
 *     KEYSCAN_Read(KEYSCAN, data, 3);
 * }
 * @endcode
 */
void KEYSCAN_Read(KEYSCAN_TypeDef *KEYSCANx, uint16_t *outBuf, uint16_t count);

/**
 * @brief Enable or disable the KEYSCAN peripheral.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] NewState New state of the KEYSCAN peripheral.
 *            - ENABLE: Enable the KEYSCAN peripheral.
 *            - DISABLE: Disable the KEYSCAN peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_Cmd(KEYSCAN, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_Cmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState);

/**
 * @brief Set filter data.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] data Config the data to be filtered.
 *            This parameter should not be more than 9 bits.
 * @param[in] NewState New state of the data filter.
 *            - ENABLE: Enable the data filter.
 *            - DISABLE: Disable the data filter.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_FilterDataConfig(KEYSCAN, 0x01, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_FilterDataConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t data,
                              FunctionalState NewState);

/**
 * @brief KEYSCAN debounce time config.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] time KEYSCAN hardware debounce time.
 *            Debounce time = delay clock * time.
 *            This parameter can be a value of 0 to 0x1FF.
 * @param[in] NewState New state of the KEYSCAN debounce function.
 *            - ENABLE: Enable the KEYSCAN debounce function.
 *            - DISABLE: Disable the KEYSCAN debounce function.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_DebounceConfig(KEYSCAN, 10, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_DebounceConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t time,
                            FunctionalState NewState);

/**
 * @brief Get KEYSCAN FIFO data num.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 *
 * @return Data length in FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     uint16_t data_len = KEYSCAN_GetFIFODataNum(KEYSCAN);
 * }
 * @endcode
 */
uint16_t KEYSCAN_GetFIFODataNum(KEYSCAN_TypeDef *KEYSCANx);

/**
 * @brief Clear the KEYSCAN interrupt pending bit.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ClearINTPendingBit(KEYSCAN, KEYSCAN_INT_SCAN_END);
 * }
 * @endcode
 */
void KEYSCAN_ClearINTPendingBit(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT);

/**
 * @brief Clear the specified KEYSCAN flag.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_FLAG Specifies the flag to clear.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: FIFO limit status. The FIFO limit can be configured to limit the max allowable key data in one scan.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 *
 * @note KEYSCAN_FLAG_FULL and KEYSCAN_FLAG_EMPTY can't be cleared manually.
 *       They are cleared by hardware automatically.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ClearFlags(KEYSCAN, KEYSCAN_FLAG_FIFOLIMIT);
 * }
 * @endcode
 */
void KEYSCAN_ClearFlags(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG);

/**
 * @brief Check whether the specified KEYSCAN flag is set.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_FLAG Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: FIFO limit status. The FIFO limit can be configured to limit the max allowable key data in one scan.
 *            - KEYSCAN_INT_FLAG_THRESHOLD: FIFO threshold interrupt status.
 *            - KEYSCAN_INT_FLAG_OVER_READ: FIFO over read interrupt status.
 *            - KEYSCAN_INT_FLAG_SCAN_END: Scan finish interrupt status.
 *            - KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY: FIFO not empty interrupt status.
 *            - KEYSCAN_INT_FLAG_ALL_RELEASE: All release interrupt status.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 *            - KEYSCAN_FLAG_FULL: FIFO full status.
 *            - KEYSCAN_FLAG_EMPTY: FIFO empty status.
 *
 * @return The status of KEYSCAN flag (SET or RESET).
 * @retval SET    The specified KEYSCAN flag is set.
 * @retval RESET  The specified KEYSCAN flag is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     FlagStatus flag_status = KEYSCAN_GetFlagState(KEYSCAN, KEYSCAN_FLAG_OVR);
 * }
 * @endcode
 */
FlagStatus KEYSCAN_GetFlagState(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG);

/**
 * @brief Read FIFO data.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 *
 * @return KEYSCAN FIFO data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     uint16_t data = KEYSCAN_ReadFIFOData(KEYSCAN);
 * }
 * @endcode
 */
uint16_t KEYSCAN_ReadFIFOData(KEYSCAN_TypeDef *KEYSCANx);

/**
 * @brief Set manual scan trigger mode. This function is only effective when keyscan is manual scan mode.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] manual_sel Specifies the KEYSCAN manual trigger mode.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_MANUAL_SEL_BIT: Scan trigger by register (Call API KEYSCAN_Cmd).
 *            - KEYSCAN_MANUAL_SEL_KEY: Scan trigger by key.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetManualSelect(KEYSCAN, KEYSCAN_MANUAL_SEL_BIT);
 * }
 * @endcode
 */
void KEYSCAN_SetManualSelect(KEYSCAN_TypeDef *KEYSCANx, KEYSCANManualSel_TypeDef manual_sel);

/**
 * @brief Set preguard time. Preguard time = preguard_cnt * scan clock.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] preguard_cnt Specifies the preguard count. This parameter can be configured from 0 to 7.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetPreGuardTime(KEYSCAN, 3);
 * }
 * @endcode
 */
void KEYSCAN_SetPreGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t preguard_cnt);

/**
 * @brief Set postguard time. Postguard time = postguard_cnt * scan clock.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] postguard_cnt Specifies the postguard count. This parameter can be configured from 0 to 7.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_SetPostGuardTime(KEYSCAN, 3);
 * }
 * @endcode
 */
void KEYSCAN_SetPostGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t postguard_cnt);

#if (KEYSCAN_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the KEYSCAN RAP mode.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] NewState New state of the RAP mode.
 *            - ENABLE: Enable the KEYSCAN RAP mode.
 *            - DISABLE: Disable the KEYSCAN RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_RAPModeCmd(KEYSCAN, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_RAPModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState);

/**
 * @brief Trigger the specified KEYSCAN action.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] Action Specifies the KEYSCAN action to trigger.
 *            This parameter can be a value of @ref KEYSCAN_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ActionTrigger(KEYSCAN, KEYSCAN_ACTION_MANUAL);
 * }
 * @endcode
 */
void KEYSCAN_ActionTrigger(KEYSCAN_TypeDef *KEYSCANx, uint32_t Action);

#endif

#if (KEYSCAN_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable KEYSCAN clock auto mode.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] NewState New state of the KEYSCAN clock auto mode.
 *            - ENABLE: Enable the KEYSCAN clock auto mode.
 *            - DISABLE: Disable the KEYSCAN clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void keyscan_demo(void)
 * {
 *     KEYSCAN_ClockAutoModeCmd(KEYSCAN, ENABLE);
 * }
 * @endcode
 */
void KEYSCAN_ClockAutoModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState);

#endif

/** @} */ /* End of group KEYSCAN_Exported_Functions */

/** @} */ /* End of group KEYSCAN_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_KEYSCAN_H */
