/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_ADC_H
#define RTL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "adc/src/device/rtl87x2g/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "adc/src/device/rtl87x3d/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "adc/src/device/rtl87x2j/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "adc/src/device/rtl87x3j/rtl_adc_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "adc/src/device/rtl87x3k/rtl_adc_def.h"
#endif

/**
 * @defgroup ADC_DRIVER DRIVER
 * @ingroup ADC
 * @brief Analog to Digital Converter (ADC) driver.
 * @{
 */

/**
 * @defgroup ADC_Exported_Constants ADC Exported Constants
 * @{
 */

/**
 * @defgroup    ADC_CHANNEL_INDEX ADC Channel Index
 * @{
 */
#define ADC_Channel_Index_0           0   /**< ADC channel 0. */
#define ADC_Channel_Index_1           1   /**< ADC channel 1. */
#define ADC_Channel_Index_2           2   /**< ADC channel 2. */
#define ADC_Channel_Index_3           3   /**< ADC channel 3. */
#define ADC_Channel_Index_4           4   /**< ADC channel 4. */
#if (CHIP_ADC_CHANNEL_NUM > 4)
#define ADC_Channel_Index_5           5   /**< ADC channel 5. */
#define ADC_Channel_Index_6           6   /**< ADC channel 6. */
#define ADC_Channel_Index_7           7   /**< ADC channel 7. */
#endif
#if (CHIP_ADC_CHANNEL_NUM > 8)
#define ADC_Channel_Index_8           8   /**< ADC channel 8. */
#define ADC_Channel_Index_9           9   /**< ADC channel 9. */
#define ADC_Channel_Index_10          10  /**< ADC channel 10. */
#define ADC_Channel_Index_11          11  /**< ADC channel 11. */
#define ADC_Channel_Index_12          12  /**< ADC channel 12. */
#define ADC_Channel_Index_13          13  /**< ADC channel 13. */
#define ADC_Channel_Index_14          14  /**< ADC channel 14. */
#define ADC_Channel_Index_15          15  /**< ADC channel 15. */
#endif
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_CHANNEL(ch)      ((ch) < CHIP_ADC_CHANNEL_NUM)

/** @} */ /* End of group ADC_CHANNEL_INDEX */

/**
 * @defgroup    ADC_SCHEDULE_INDEX ADC Schedule Index
 * @{
 */
#define ADC_Schedule_Index_0          0    /**< ADC schedule index 0. */
#define ADC_Schedule_Index_1          1    /**< ADC schedule index 1. */
#define ADC_Schedule_Index_2          2    /**< ADC schedule index 2. */
#define ADC_Schedule_Index_3          3    /**< ADC schedule index 3. */
#define ADC_Schedule_Index_4          4    /**< ADC schedule index 4. */
#define ADC_Schedule_Index_5          5    /**< ADC schedule index 5. */
#define ADC_Schedule_Index_6          6    /**< ADC schedule index 6. */
#define ADC_Schedule_Index_7          7    /**< ADC schedule index 7. */
#define ADC_Schedule_Index_8          8    /**< ADC schedule index 8. */
#define ADC_Schedule_Index_9          9    /**< ADC schedule index 9. */
#define ADC_Schedule_Index_10         10   /**< ADC schedule index 10. */
#define ADC_Schedule_Index_11         11   /**< ADC schedule index 11. */
#define ADC_Schedule_Index_12         12   /**< ADC schedule index 12. */
#define ADC_Schedule_Index_13         13   /**< ADC schedule index 13. */
#define ADC_Schedule_Index_14         14   /**< ADC schedule index 14. */
#define ADC_Schedule_Index_15         15   /**< ADC schedule index 15. */
#if (CHIP_ADC_SCHEDULE_NUM > 16)
#define ADC_Schedule_Index_16         16   /**< ADC schedule index 16. */
#define ADC_Schedule_Index_17         17   /**< ADC schedule index 17. */
#define ADC_Schedule_Index_18         18   /**< ADC schedule index 18. */
#define ADC_Schedule_Index_19         19   /**< ADC schedule index 19. */
#endif
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_SCH_INDEX(IDEX) ((IDEX) < CHIP_ADC_SCHEDULE_NUM)

/** @} */ /* End of group ADC_SCHEDULE_INDEX */

/**
 * @defgroup    ADC_SCHEDULE_TABLE ADC Channel and Mode
 * @{
 */
#define SCHEDULE_TABLE(Index)         (Index) /**< ADC schedule table index. */
#define EXT_SINGLE_ENDED(Index)       ((uint16_t)((ADC_MODE_SINGLE_ENDED_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_EXTERNAL_CH_NUM(Index))) /**< External single-ended mode. Index refers to @ref ADC_Channel_Index. */
#if ADC_SUPPORT_EXT_DIFFERENTIAL_MODE
#define EXT_DIFFERENTIAL(Index)       ((uint16_t)((ADC_MODE_DIFFERENTIAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_EXTERNAL_CH_NUM(Index))) /**< External differential mode. Index refers to @ref ADC_Channel_Index. */
#endif

#define INTERNAL_VBAT_MODE            ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_INTERNAL_VBAT_CH_NUM)) /**< Internal VBAT mode. */
#if ADC_SUPPORT_VADPIN_MODE
#define INTERNAL_VADPIN_MODE          ((uint16_t)((ADC_MODE_INTERNAL_VALUE << CHIP_ADC_MODE_OFFSET) | ADC_MODE_INTERNAL_VADPIN_CH_NUM)) /**< Internal VADPIN mode. */
#endif


#if ADC_SUPPORT_VADPIN_MODE
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE || \
                                               (CONFIG) == INTERNAL_VADPIN_MODE))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_SCHEDULE_INDEX_CONFIG(CONFIG) (((CONFIG) & (0xffff << 2 << CHIP_ADC_MODE_OFFSET)) == 0 && \
                                              ((IS_ADC_SCH_INDEX((CONFIG) & (~(0xffff << CHIP_ADC_MODE_OFFSET))) && \
                                                (CONFIG & BIT(CHIP_ADC_MODE_OFFSET + 1) == 0)) || \
                                               (CONFIG) == INTERNAL_VBAT_MODE))
#endif

/** @} */ /* End of group ADC_SCHEDULE_TABLE */

/**
 * @defgroup    ADC_CONVERT_TIME ADC Convert Time
 * @{
 */
typedef enum
{
    ADC_CONVERT_TIME,  /**< ADC convert time. */
} ADCConvertTime_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_CONVERT_TIME(TIME) (((TIME) == ADC_CONVERT_TIME))

/** @} */ /* End of group ADC_CONVERT_TIME */

/**
 * @defgroup    ADC_DATA_LATCH ADC Data Latch
 * @{
 */
typedef enum
{
    ADC_DATA_LATCH_POSITIVE, /**< ADC latch data at positive clock edge. */
    ADC_DATA_LATCH_NEGATIVE, /**< ADC latch data at negative clock edge. */
} ADCDataLatch_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_DATA_LATCH(DATA_LATCH) (((DATA_LATCH) == ADC_DATA_LATCH_POSITIVE) || ((DATA_LATCH) == ADC_DATA_LATCH_NEGATIVE))

/** @} */ /* End of group ADC_DATA_LATCH */

/**
 * @defgroup    ADC_DATA_ALIGN ADC Data Align
 * @{
 */
typedef enum
{
    ADC_DATA_ALIGN_LSB, /**< ADC data storage format is LSB. */
    ADC_DATA_ALIGN_MSB, /**< ADC data storage format is MSB. */
} ADCDataAlign_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_DATA_ALIGN(DATA_ALIGN) (((DATA_ALIGN) == ADC_DATA_ALIGN_LSB) || ((DATA_ALIGN) == ADC_DATA_ALIGN_MSB))

/** @} */ /* End of group ADC_DATA_ALIGN */


/**
 * @defgroup    ADC_DATA_AVERAGE ADC Data Average
 * @{
 */
typedef enum
{
    ADC_DATA_AVERAGE_OF_2,    /**< 2 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_4,    /**< 4 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_8,    /**< 8 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_16,   /**< 16 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_32,   /**< 32 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_64,   /**< 64 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_128,  /**< 128 data used to calculate average. */
    ADC_DATA_AVERAGE_OF_256,  /**< 256 data used to calculate average. */
    ADC_DATA_AVERAGE_MAX,     /**< The largest enumeration value. */
} ADCDataAverage_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_DATA_AVERAGE(_DATA_AVERAGE) (((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_2) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_4) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_8) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_16) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_32) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_64) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_128) || \
                                            ((_DATA_AVERAGE) == ADC_DATA_AVERAGE_OF_256))

/** @} */ /* End of group ADC_DATA_AVERAGE */


/**
 * @defgroup    ADC_FIFO_THRESHOLD ADC FIFO Threshold
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_FIFO_THRESHOLD(THD) ((THD) <= 0x3F)

/** @} */ /* End of group ADC_FIFO_THRESHOLD */

/**
 * @defgroup    ADC_BURST_SIZE ADC Burst Size
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_BURST_SIZE(SIZE) ((SIZE) <= 0x3F)

/** @} */ /* End of group ADC_BURST_SIZE */

/**
 * @defgroup    ADC_OPERATION_MODE ADC Operation Mode
 * @{
 */
typedef enum
{
    ADC_CONTINUOUS_MODE, /**< ADC continuous mode. */
    ADC_ONE_SHOT_MODE,   /**< ADC one shot mode. */
} ADCOperationMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_OPERATION_MODE(MODE) (((MODE) == ADC_CONTINUOUS_MODE) || ((MODE) == ADC_ONE_SHOT_MODE))

/** @} */ /* End of group ADC_OPERATION_MODE */

/**
 * @defgroup    ADC_POWER_ON_MODE  ADC Power On Mode
 * @{
 */
typedef enum
{
    ADC_POWER_ON_AUTO,     /**< The power mode of ADC is auto mode. */
#ifdef ADC_POWER_MODE_CTRL_EN
    ADC_POWER_ON_MANUAL,   /**< The power mode of ADC is manual mode. */
#endif
} ADCPowerOnMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_POWER_ON_MODE(MODE) (((MODE) == ADC_POWER_ON_AUTO) || ((MODE) == ADC_POWER_ON_MANUAL))

/** @} */ /* End of group ADC_POWER_ON_MODE */

/**
 * @defgroup    ADC_INTERRUPTS_DEFINITION ADC Interrupts Definition
 * @{
 */
#define ADC_INT_FIFO_RD_REQ           ((uint32_t)(1 << 0)) /**< ADC GDMA request interrupt. When FIFO data level reaches the GDMA threshold level (ADC_WaterLevel), this interrupt is triggered. */
#define ADC_INT_FIFO_RD_ERR           ((uint32_t)(1 << 1)) /**< ADC FIFO read error interrupt. When read the empty FIFO, this interrupt is triggered. */
#define ADC_INT_FIFO_THD              ((uint32_t)(1 << 2)) /**< ADC FIFO threshold interrupt. When FIFO data number is more than or equal to the threshold level (ADC_FifoThdLevel), this interrupt is triggered. */
#define ADC_INT_ONE_SHOT_DONE         ((uint32_t)(1 << 4)) /**< ADC one shot mode done interrupt. When ADC conversion done, this interrupt is triggered. */
#if (ADC_SUPPORT_INT_FIFO_FULL == 1)
#define ADC_INT_FIFO_FULL             ((uint32_t)(1 << 3)) /**< ADC FIFO full interrupt. When FIFO full, this interrupt is triggered. */
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 5)) /**< ADC FIFO overflow interrupt. When FIFO overflow, this interrupt is triggered. */
#else
#define ADC_INT_FIFO_OVERFLOW         ((uint32_t)(1 << 3)) /**< ADC FIFO overflow interrupt. When FIFO overflow, this interrupt is triggered. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_ADC_INT(INT) (((INT) == ADC_INT_FIFO_RD_REQ) || \
                         ((INT) == ADC_INT_FIFO_RD_ERR) || \
                         ((INT) == ADC_INT_FIFO_THD) || \
                         ((INT) == ADC_INT_FIFO_OVERFLOW) || \
                         ((INT) == ADC_INT_ONE_SHOT_DONE) || \
                         ((INT) == ADC_INT_FIFO_FULL))

/** @} */ /* End of group ADC_INTERRUPTS_DEFINITION */

#if (ADC_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup    ADC_ACTION ADC Action
 * @{
 */
typedef enum
{
    ADC_ACTION_ONE_SHOT_SAMPLE = 0, /**< ADC one shot sample action. */
} ADCAction_TypeDef;

/** @} */ /* End of group ADC_ACTION */
#endif

/** @} */ /* End of group ADC_Exported_Constants */

/**
 * @defgroup ADC_Exported_Types ADC Exported Types
 * @{
 */

/**
 * @brief       ADC init structure definition.
 */
typedef struct
{
    uint16_t ADC_SampleTime;                /**< Specify the ADC sample clock period.
                                                 (ADC_SampleTime + 1) cycles of 10 MHz.
                                                 @note Maximum sample rate varies by mode:
                                                 - Internal VBAT : 400 KHz, ADC_SampleTime >= 18
                                                 - External Divide: 400 KHz, ADC_SampleTime >= 18
                                                 - External Bypass: 1 MHz,   ADC_SampleTime >= 3
                                                 Maximum value is 16383 for all modes. */

    ADCConvertTime_TypeDef ADC_ConvertTime;  /**< Specify the ADC Sample convert time.
                                                 This parameter can be a value of @ref ADC_CONVERT_TIME. */

    FunctionalState ADC_DataWriteToFIFO;    /**< Write ADC one shot mode data into FIFO.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    uint8_t ADC_FIFOThdLevel;               /**< Specify the ADC FIFO threshold to trigger interrupt ADC_INT_FIFO_THD.
                                                 This parameter can be a value of 0 to 31. */

    uint8_t ADC_WaterLevel;                 /**< Specify the ADC FIFO Burst Size to trigger GDMA.
                                                 This parameter can be a value of 0 to 31. */

    FunctionalState ADC_FIFOOverWriteEn;    /**< Specify if overwrite FIFO when FIFO overflow.
                                                 This parameter can be a value of DISABLE or ENABLE. */

#if (ADC_SUPPORT_DMA_EN == 1)
    FunctionalState ADC_DMAEn;              /**< Enable or disable the DMA function of ADC.
                                                 This parameter can be a value of DISABLE or ENABLE. */
#endif

    uint16_t ADC_SchIndex[CHIP_ADC_SCHEDULE_NUM]; /**< Specify ADC mode and channel for schedule table.*/

    uint32_t ADC_Bitmap;                    /**< Specify the schedule table channel map.
                                                 This parameter is a 16-bit bitmap. */

    FunctionalState ADC_TimerTriggerEn;     /**< Enable or disable ADC one-shot mode when TIM7 toggles.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    ADCDataAlign_TypeDef ADC_DataAlign;     /**< ADC Data MSB or LSB aligned.
                                                 This parameter can be a value of @ref ADC_DATA_ALIGN. */

#if (ADC_SUPPORT_DATAMINUS==1)
    FunctionalState ADC_DataMinusEn;        /**< Enable or disable the offset subtraction
                                                 from latched ADC data before writing to FIFO. */

    uint16_t ADC_DataMinusOffset;           /**< Offset to be subtracted from the latched ADC data.
                                                 This parameter can be a value of 0 to 4095. */
#endif

    ADCDataAverage_TypeDef ADC_DataAverage;   /**< Number of data samples for calculating the average.
                                                 This parameter can be a value of @ref ADC_DATA_AVERAGE. */

    uint8_t ADC_DataAverageEn;              /**< Enable or disable the calculation of the average result for one-shot data.
                                                 This parameter can be a value of DISABLE or ENABLE. */

    FunctionalState ADC_FIFOStopWriteEn;    /**< Stop FIFO from writing data. This bit will be asserted
                                                 automatically when FIFO overflows (not automatically when
                                                 ADC_FIFO_OVER_WRITE_ENABLE), need to be cleared in order
                                                 to write data again. This will not stop overwrite mode. */
#ifdef ADC_POWER_MODE_CTRL_EN
    ADCPowerOnMode_TypeDef ADC_PowerOnMode; /**< Specify ADC power on mode.
                                                 This parameter can be a value of @ref ADC_POWER_ON_MODE. */
#endif


    FunctionalState ADC_PowerAlwaysOnEn;    /**< Enable or disable the power always on.
                                                 This parameter can be a value of DISABLE or ENABLE. */

#if (ADC_SUPPORT_POWER_ON_DELAY ==1 )
    FunctionalState ADC_PowerOnDlyEn;       /**< Enable or disable ADC 8ms delay after ADC power on.
                                                 This parameter can be a value of DISABLE or ENABLE. */
#endif

#if (ADC_SUPPORT_DATA_CLIP ==1 )
    FunctionalState
    ADC_DataClippingEn;     /**< Enable or disable ADC data clipping, the controller clips
                                                 the data with gain/offset mapping when the data value (output code) exceeds 4095. */
#endif
} ADC_InitTypeDef;

/** @} */ /* End of group ADC_Exported_Types */

/**
 * @defgroup ADC_Exported_Functions ADC Exported Functions
 * @{
 */

/**
 * @brief   Deinitializes the ADC peripheral registers to their
 *          default reset values.
 *
 * @param[in] ADCx: Specify ADC peripheral, can only be ADC.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    ADC_DeInit(ADC);
 * }
 * @endcode
 */
void ADC_DeInit(ADC_TypeDef *ADCx);

/**
 * @brief Initializes the ADC peripheral according to the specified parameters in the ADC_InitStruct.
 *
 * @param[in]  ADCx: Selected ADC peripheral.
 * @param[in]  ADC_InitStruct: Pointer to an ADC_InitTypeDef structure that contains the configuration information for the specified ADC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * @endcode
 */
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);

/**
 * @brief   Fills each ADC_InitStruct member with its default value.
 *
 * @note   The default settings for the ADC_InitStruct member are shown in the following table:
 *         | ADC_InitStruct member   | Default value                   |
 *         |:-----------------------:|:-------------------------------:|
 *         | ADC_SampleTime          | 0x3E7                           |
 *         | ADC_ConvertTime         | ADC_CONVERT_TIME                |
 *         | ADC_DataWriteToFIFO     | DISABLE                         |
 *         | ADC_FIFOThdLevel        | 0x06                            |
 *         | ADC_WaterLevel          | 0x1                             |
 *         | ADC_FIFOOverWriteEn     | ENABLE                          |
 *         | ADC_SchIndex[16]        | 0                               |
 *         | ADC_Bitmap              | 0x0                             |
 *         | ADC_TimerTriggerEn      | DISABLE                         |
 *         | ADC_DataAlign           | @ref ADC_DATA_ALIGN_LSB         |
 *         | ADC_DataMinusEn         | DISABLE                         |
 *         | ADC_DataMinusOffset     | 0                               |
 *         | ADC_FIFOStopWriteEn     | DISABLE                         |
 *         | ADC_DataAverageEn       | DISABLE                         |
 *         | ADC_DataAverage         | @ref ADC_DATA_AVERAGE_OF_2      |
 *         | ADC_PowerAlwaysOnEn     | DISABLE                         |
 *         | ADC_PowerOnDlyEn        | DISABLE                         |
 *
 * @param[in] ADC_InitStruct: Pointer to an ADC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);

 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters that need to be configured here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 * }
 * @endcode
 * @callgraph
 *
 */
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct);

/**
 * @brief   Enables or disables the ADC peripheral.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  ADCMode: ADC operation mode selection.
 *             This parameter can be one of the following values:
 *             - ADC_ONE_SHOT_MODE: One shot mode.
 *             - ADC_CONTINUOUS_MODE: Continuous sampling mode.
 * @param[in]  NewState: New state of the ADC peripheral.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 * }
 * @endcode
 */
void ADC_Cmd(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef ADCMode, FunctionalState NewState);

/**
 * @brief   Enables or disables the specified ADC interrupts.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  ADC_INT: Specify the ADC interrupts sources to be enabled or disabled.
 *             This parameter can be any combination of the following values:
 *             Refer to @ref ADC_INTERRUPTS_DEFINITION.
 *             - ADC_INT_FIFO_RD_REQ : FIFO read request.
 *             - ADC_INT_FIFO_RD_ERR : FIFO read error.
 *             - ADC_INT_FIFO_THD : ADC FIFO data count exceeds the threshold.
 *             - ADC_INT_FIFO_OVERFLOW : ADC FIFO overflow.
 *             - ADC_INT_ONE_SHOT_DONE : ADC one shot mode done.
 * @param[in]  NewState: New state of the specified ADC interrupt.
 *             This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_FIFO_RD_ERR, ENABLE);
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 * @endcode
 *
 */
void ADC_INTConfig(ADC_TypeDef *ADCx, uint32_t ADC_INT, FunctionalState NewState);

/**
 * @brief  Check whether the specified ADC interrupt flag is set.
 *
 * @param[in]  ADCx: Selected ADC peripheral.
 * @param[in]  ADC_INT_FLAG: Specifies the interrupt flag to check.
 *             This parameter can be one of the following values.
 *             Refer to @ref ADC_INTERRUPTS_DEFINITION.
 *             - ADC_INT_ONE_SHOT_DONE: ADC one-shot conversion done interrupt.
 *             - ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *             - ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *             - ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *             - ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
 *
 * @return The new state of ADC_INT.
 * @retval SET  The ADC interrupt status is set.
 * @retval RESET  The ADC interrupt status is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *     ITStatus int_status = RESET;
 *     int_status = ADC_GetINTStatus(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * @endcode
 */
ITStatus ADC_GetINTStatus(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * @brief   Get all ADC interrupt flag status.
 *
 * @param[in] ADCx: Specify ADC peripheral.
 *
 * @return  All ADC interrupt status.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint8_t all_flag_status = 0;
 *   all_flag_status = ADC_GetAllFlagStatus(ADC);
 * }
 * @endcode
 *
 */
uint8_t ADC_GetAllFlagStatus(ADC_TypeDef *ADCx);

/**
 * @brief  Clear the ADC interrupt pending bit.
 *
 * @param[in] ADCx: Specify ADC peripheral.
 * @param[in] ADC_INT: Specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values.
 *            Refer to @ref ADC_INTERRUPTS_DEFINITION.
 *            - ADC_INT_ONE_SHOT_DONE: ADC once convert end interrupt.
 *            - ADC_INT_FIFO_OVERFLOW: ADC FIFO overflow interrupt.
 *            - ADC_INT_FIFO_THD: FIFO larger than threshold interrupt.
 *            - ADC_INT_FIFO_RD_ERR: ADC read FIFO error interrupt.
 *            - ADC_INT_FIFO_RD_REQ: ADC read FIFO request interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearINTPendingBit(ADC,ADC_INT_FIFO_OVERFLOW);
 * }
 * @endcode
 */
void ADC_ClearINTPendingBit(ADC_TypeDef *ADCx, uint32_t ADC_INT);

/**
 * @brief      Read ADC data according to specific channel.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  Index: Can be 0 to 15.
 *
 * @return     The 12-bit converted ADC raw data.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 *
 *     Pad_Config(P2_1, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_SchIndex[1] = EXT_SINGLE_ENDED(1);
 *    ADC_InitStruct.ADC_Bitmap = 0x03;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data_0 = ADC_ReadRawData(ADC, 0);
 *    uint16_t raw_data_1 = ADC_ReadRawData(ADC, 1);
 * }
 * @endcode
 */
ADCDataWidth ADC_ReadRawData(ADC_TypeDef *ADCx, uint8_t Index);

/**
 * @brief   Get ADC average data from ADC schedule table0.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[out] OutBuf: Buffer to save data read from ADC FIFO.
 *
 * @return  The 12-bit converted ADC raw data.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataAverageEn = ENABLE;
 *    ADC_InitStruct.ADC_DataAverage   = ADC_DATA_AVERAGE_OF_2;
 *    //Add other initialization parameters here.
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadAvgRawData(ADC);
 * }
 * @endcode
 *
 */
ADCDataWidth ADC_ReadAvgRawData(ADC_TypeDef *ADCx);

/**
 * @brief  Read one data from ADC FIFO.
 *
 * @param[in]  ADCx: Selected ADC peripheral.
 *
 * @return ADC FIFO data.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void board_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE,
 *                PAD_OUT_LOW);
 * }
 *
 * void driver_adc_init(void)
 * {
 *    //Turn on the clock.
 *    RCC_ClockCmd(ADC_CLOCK, ENABLE);
 *
 *    ADC_InitTypeDef ADC_InitStruct;
 *    ADC_StructInit(&ADC_InitStruct);
 *    ADC_InitStruct.ADC_SchIndex[0] = EXT_SINGLE_ENDED(0);
 *    ADC_InitStruct.ADC_Bitmap = 0x01;
 *    ADC_InitStruct.ADC_DataWriteToFIFO = DISABLE;
 *    ADC_Init(ADC, &ADC_InitStruct);
 *
 *    ADC_INTConfig(ADC, ADC_INT_ONE_SHOT_DONE, ENABLE);
 * }
 *
 * void adc_demo(void)
 * {
 *    board_adc_init();
 *    driver_adc_init();
 *    ADC_Cmd(ADC, ADC_ONE_SHOT_MODE, ENABLE);
 *    while(ADC_GetINTStatus(ADC, ADC_INT_ONE_SHOT_DONE) == RESET);
 *    uint16_t raw_data = 0;
 *    raw_data = ADC_ReadFIFO(ADC);
 * }
 * @endcode
 */
ADCDataWidth ADC_ReadFIFO(ADC_TypeDef *ADCx);

/**
 * @brief   Get data from ADC FIFO.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[out] outBuf: Buffer to save data read from ADC FIFO.
 * @param[in]  Num: Number of data to be read.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * @endcode
 *
 */
void ADC_ReadFIFOData(ADC_TypeDef *ADCx, ADCDataWidth *outBuf, uint16_t Num);

/**
 * @brief   Get ADC current data number in ADC FIFO.
 *
 * @param[in] ADCx: Selected ADC peripheral.
 *
 * @return  Current data number in ADC FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *    //ADC already start
 *    uint16_t raw_data[32] = {0};
 *    uint8_t data_len = ADC_GetFIFODataLen(ADC);
 *    ADC_ReadFIFOData(ADC,raw_data,data_len);
 * }
 * @endcode
 *
 */
uint8_t ADC_GetFIFODataLen(ADC_TypeDef *ADCx);

/**
 * @brief   Config ADC schedule table.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  ADCMode: ADC operation mode.
 *             This parameter can be one of the following values:
 *             - EXT_SINGLE_ENDED(index): Single-ended mode, the input is external channel index.
 *             - EXT_DIFFERENTIAL(index): Differential mode, the positive input is external channel index,
 *             the negative input is external channel (index + 1).
 *             - INTERNAL_VBAT_MODE: The input is internal battery voltage detection channel.
 * @param[in]  Index: Schedule table index.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_SchIndexConfig(ADC,INTERNAL_VBAT_MODE,0);
 * }
 * @endcode
 *
 */
void ADC_SchIndexConfig(ADC_TypeDef *ADCx, uint8_t ADCMode, uint16_t Index);

/**
 * @brief   Configure ADC schedule table bitmap.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  BitMap: ADC bit map.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   uint16_t bit_map = 0x03;
 *   ADC_BitMapConfig(ADC,bit_map);
 * }
 * @endcode
 */
void ADC_BitMapConfig(ADC_TypeDef *ADCx, uint16_t BitMap);

/**
 * @brief   Enable or disable stop FIFO from writing data.
 *
 * @param[in]  ADCx: Specify ADC peripheral.
 * @param[in]  NewState: New state of the ADC FIFO write.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the stop of FIFO writing data.
 *             - DISABLE: Disable the stop of FIFO writing data.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_WriteFIFOCmd(ADC, ENABLE);
 * }
 * @endcode
 */
void ADC_WriteFIFOCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
 * @brief     Config ADC bypass resistor.
 *
 * @param[in] ChannelNum: External channel number, can be 0~7.
 * @param[in] NewState: Specifies whether the channel enables bypass mode.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * @attention The input voltage of channel pin using bypass mode cannot exceed 0.9V!
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_BypassCmd(0,ENABLE);
 * }
 * @endcode
 */
void ADC_BypassCmd(uint8_t ChannelNum, FunctionalState NewState);

/**
 * @brief   Clear ADC FIFO.
 *
 * @param[in] ADCx: Specify ADC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void adc_demo(void)
 * {
 *   ADC_ClearFIFO(ADC);
 * }
 * @endcode
 */
void ADC_ClearFIFO(ADC_TypeDef *ADCx);

/**
  * @brief  Enables or disables the ADC power always on.
  *
  * @param[in]  ADCx: Selected ADC peripheral.
  * @param[in]  NewState: New state of the specified ADC power always on.
  *             This parameter can be: ENABLE or DISABLE.
  *
  * <b>Example usage</b>
  * @code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_PowerAlwaysOnCmd(ADC, ENABLE);
  * }
  * @endcode
  */
void ADC_PowerAlwaysOnCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

#if (ADC_SUPPORT_RAP_FUNCTION == 1)
/**
  * @brief  Enables or disables RAP Mode.
  *
  * @param[in]  ADCx: Pointer to the Selected ADC peripheral. @ref ADC Declaration
  * @param[in]  NewState: New state of the RAP mode.
  *             This parameter can be: ENABLE or DISABLE.
  *
  * <b>Example usage</b>
  * @code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_RAPModeCmd(ADC, ENABLE);
  * }
  * @endcode
  */
void ADC_RAPModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

/**
  * @brief  Trigger an action specified by firmware.
  *
  * @param[in]  ADCx: Pointer to the Selected ADC peripheral. @ref ADC Declaration
  * @param[in]  Action: ADC action to be triggered. @ref ADC_ACTION.
  *
  * <b>Example usage</b>
  * @code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_ActionTrigger(ADC, ADC_ACTION_ONE_SHOT_SAMPLE);
  * }
  * @endcode
  */
void ADC_ActionTrigger(ADC_TypeDef *ADCx, uint32_t Action);

#endif

#if (ADC_SUPPORT_AUTO_CLOCK == 1)
/**
  * @brief  Enable or disable ADC auto clock gating mode.
  *
  * @param[in]  ADCx: Pointer to the Selected ADC peripheral. @ref ADC Declaration
  * @param[in]  NewState: New state of the auto clock mode. This parameter can be:
  *             - ENABLE:  Enable ADC auto mode which allows the ADC to auto clock gate.
  *             - DISABLE: Disable ADC auto mode, the ADC clock is always on.
  *
  * <b>Example usage</b>
  * @code{.c}
  *
  * void adc_demo(void)
  * {
  *   ADC_ClockAutoModeCmd(ADC, ENABLE);
  * }
  * @endcode
  */
void ADC_ClockAutoModeCmd(ADC_TypeDef *ADCx, FunctionalState NewState);

#endif
#if (ADC_SUPPORT_GET_VOTAGE_API == 1)
/**
  * @brief  Converts ADC sample data to voltage based on the selected sampling mode.
  *
  * @param[in]  SampleMode: ADC sampling mode that determines the voltage conversion formula.
  *             For valid values, refer to @ref ADC_CONSTANT_PRIVATE.
  * @param[in]  SampleData: ADC raw sample data to be converted.
  * @param[out] ErrorStatus: Pointer to a variable to store error information. @ref ADCStatus_TypeDef
  *
  * @return Converted voltage value in millivolts (mV).
  *
  * <b>Example usage</b>
  * @code{.c}
  *
  * void adc_demo(void)
  * {
  *      ADCStatus_TypeDef adc_error = 0;
  *      float adc_voltage = ADC_GetVoltage(ADC_SAMPLE_DIVIDE_SINGLE_MODE, sample_data, &adc_error);
  * }
  * @endcode
  */

float ADC_GetVoltage(const ADCSampleMode_TypeDef SampleMode, ADCDataWidth SampleData,
                     ADCStatus_TypeDef *ErrorStatus);
#endif

#if (ADC_SUPPORT_GET_FT_ADC_PARA ==1)
/**
  * @brief  Initialize the ADC calibration process.
  *
  * @return A boolean value indicating the success of the calibration operation.
  * @retval true   Calibration initialization succeeded.
  * @retval false  Calibration initialization failed.
  */
bool ADC_CalibrationInit(void);
#endif
/** @} */ /* End of group ADC_Exported_Functions */

/** @} */ /* End of group ADC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_ADC_H */
