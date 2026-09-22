/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_CODEC_H
#define RTL_CODEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "codec/src/device/rtl87x2g/rtl_codec_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "codec/src/device/rtl87x2j/rtl_codec_def.h"
#endif

/**
 * @defgroup CODEC_DRIVER DRIVER
 * @ingroup CODEC
 * @brief CODEC driver module.
 * @{
 */

/**
 * @defgroup CODEC_Exported_Constants CODEC Exported Constants
 * @{
 */

/**
 * @defgroup CODEC_I2S_DATA_WIDTH CODEC I2S Data Width
 * @{
 */
typedef enum
{
    CODEC_I2S_DATA_WIDTH_16BITS,            /**< I2S data width is 16 bits. */
    CODEC_I2S_DATA_WIDTH_24BITS = 0x2,      /**< I2S data width is 24 bits. */
    CODEC_I2S_DATA_WIDTH_8BITS = 0x3,       /**< I2S data width is 8 bits. */
    CODEC_I2S_DATA_WIDTH_MAX,               /**< Maximum value of I2S data width. */
} CODECI2SDataWidth_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_I2S_DATA_WIDTH(WIDTH) (((WIDTH) == CODEC_I2S_DATA_WIDTH_16BITS) || \
                                        ((WIDTH) == CODEC_I2S_DATA_WIDTH_24BITS) || \
                                        ((WIDTH) == CODEC_I2S_DATA_WIDTH_8BITS))


/** @} */ /* End of group CODEC_I2S_DATA_WIDTH */

/**
 * @defgroup CODEC_I2S_DATA_FORMAT CODEC I2S Data Format
 * @{
 */
typedef enum
{
    CODEC_I2S_DATA_FORMAT_I2S,              /**< I2S format. */
    CODEC_I2S_DATA_FORMAT_LEFT_JUSTIFIED,   /**< Left justified format. */
    CODEC_I2S_DATA_FORMAT_PCM_A,            /**< PCM A format. */
    CODEC_I2S_DATA_FORMAT_PCM_B,            /**< PCM B format. */
    CODEC_I2S_DATA_FORMAT_MAX,              /**< Maximum value of I2S data format. */
} CODECI2SDataFormat_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_I2S_DATA_FORMAT(FORMAT) (((FORMAT) == CODEC_I2S_DATA_FORMAT_I2S) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_LEFT_JUSTIFIED) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_PCM_A) || \
                                          ((FORMAT) == CODEC_I2S_DATA_FORMAT_PCM_B))

/** @} */ /* End of group CODEC_I2S_DATA_FORMAT */

/**
 * @defgroup CODEC_I2S_CH_SEQ CODEC I2S Channel Sequence
 * @{
 */
typedef enum
{
    CODEC_I2S_CH_SEQ_L_R,                   /**< Left channel then right channel. */
    CODEC_I2S_CH_SEQ_R_L,                   /**< Right channel then left channel. */
    CODEC_I2S_CH_SEQ_L_L,                   /**< Left channel only. */
    CODEC_I2S_CH_SEQ_R_R,                   /**< Right channel only. */
    CODEC_I2S_CH_SEQ_SEL_MAX,               /**< Maximum value of I2S channel sequence selection. */
} CODECI2SChSeq_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_I2S_CH_SEQ(CH) (((CH) == CODEC_I2S_CH_SEQ_L_R) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_R_L) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_L_L) || \
                                 ((CH) == CODEC_I2S_CH_SEQ_R_R))

/** @} */ /* End of group CODEC_I2S_CH_SEQ */

/**
 * @defgroup CODEC_SAMPLE_RATE CODEC Sample Rate
 * @{
 */
typedef enum
{
    CODEC_SAMPLE_RATE_48KHz = 0,    /**< The CODEC sample rate is 48 kHz. */
    CODEC_SAMPLE_RATE_32KHz = 3,    /**< The CODEC sample rate is 32 kHz. */
    CODEC_SAMPLE_RATE_16KHz = 5,    /**< The CODEC sample rate is 16 kHz. */
    CODEC_SAMPLE_RATE_8KHz = 7,     /**< The CODEC sample rate is 8 kHz. */
    CODEC_SAMPLE_RATE_44100Hz = 8,  /**< The CODEC sample rate is 44.1 kHz. */
    CODEC_SAMPLE_RATE_24KHz = 10,   /**< The CODEC sample rate is 24 kHz. */
    CODEC_SAMPLE_RATE_12KHz = 11,   /**< The CODEC sample rate is 12 kHz. */
    CODEC_SAMPLE_RATE_22050Hz = 12, /**< The CODEC sample rate is 22.05 kHz. */
    CODEC_SAMPLE_RATE_11025Hz = 13, /**< The CODEC sample rate is 11.025 kHz. */
    CODEC_SAMPLE_RATE_NUM,          /**< Number of sample rate configurations. */
} CODECSampleRate_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SAMPLE_RATE(RATE) (((RATE) == CODEC_SAMPLE_RATE_48KHz)   ||((RATE) == CODEC_SAMPLE_RATE_32KHz)    || \
                              ((RATE) == CODEC_SAMPLE_RATE_16KHz)   || ((RATE) == CODEC_SAMPLE_RATE_8KHz)   || \
                              ((RATE) == CODEC_SAMPLE_RATE_44100Hz) || ((RATE) == CODEC_SAMPLE_RATE_24KHz) || \
                              ((RATE) == CODEC_SAMPLE_RATE_12KHz)   || ((RATE) == CODEC_SAMPLE_RATE_22050Hz) || \
                              ((RATE) == CODEC_SAMPLE_RATE_11025Hz))

/** @} */ /* End of group CODEC_SAMPLE_RATE */


/**
 * @defgroup CODEC_DMIC_CLOCK CODEC DMIC Clock
 * @{
 */
typedef enum
{
    CODEC_DMIC_CLOCK_5MHz,                  /**< DMIC clock is 5 MHz. */
    CODEC_DMIC_CLOCK_2500KHz,               /**< DMIC clock is 2500 kHz. */
    CODEC_DMIC_CLOCK_1250KHz,               /**< DMIC clock is 1250 kHz. */
    CODEC_DMIC_CLOCK_625KHz,                /**< DMIC clock is 625 kHz. */
    CODEC_DMIC_CLOCK_312500Hz,              /**< DMIC clock is 312500 Hz. */
    CODEC_DMIC_CLOCK_SEL_MAX,               /**< Maximum value of DMIC clock selection. */
} CODECDmicClock_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_DMIC_CLOCK(CLOCK) (((CLOCK) == CODEC_DMIC_CLOCK_5MHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_2500KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_1250KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_625KHz) || \
                                    ((CLOCK) == CODEC_DMIC_CLOCK_312500Hz))

/** @} */ /* End of group CODEC_DMIC_CLOCK */

/**
 * @defgroup CODEC_MICBIAS_VOLTAGE CODEC MicBias Voltage
 * @{
 */
typedef enum
{
    CODEC_MICBIAS_VOLTAGE_1_507,            /**< MicBias Vref voltage is 1.507 V. */
    CODEC_MICBIAS_VOLTAGE_1_62,             /**< MicBias Vref voltage is 1.62 V. */
    CODEC_MICBIAS_VOLTAGE_1_705,            /**< MicBias Vref voltage is 1.705 V. */
    CODEC_MICBIAS_VOLTAGE_1_8,              /**< MicBias Vref voltage is 1.8 V. */
    CODEC_MICBIAS_VOLTAGE_1_906,            /**< MicBias Vref voltage is 1.906 V. */
    CODEC_MICBIAS_VOLTAGE_2_025,            /**< MicBias Vref voltage is 2.025 V. */
    CODEC_MICBIAS_VOLTAGE_2_16,             /**< MicBias Vref voltage is 2.16 V. */
    CODEC_MICBIAS_VOLTAGE_2_314,            /**< MicBias Vref voltage is 2.314 V. */
} CODECMicBiasVoltage_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_MICBIAS_VOLTAGE(VOLTAGE) (((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_507) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_62)  || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_705) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_8)   || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_1_906) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_025) || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_16)  || \
                                           ((VOLTAGE) == CODEC_MICBIAS_VOLTAGE_2_314))

/** @} */ /* End of group CODEC_MICBIAS_VOLTAGE */

/**
 * @defgroup CODEC_MICBST_GAIN CODEC MicBst Gain
 * @{
 */
typedef enum
{
    CODEC_MICBST_GAIN_0dB,                  /**< MicBst gain is 0 dB. */
    CODEC_MICBST_GAIN_3dB,                  /**< MicBst gain is 3 dB. */
    CODEC_MICBST_GAIN_6dB,                  /**< MicBst gain is 6 dB. */
    CODEC_MICBST_GAIN_9dB,                  /**< MicBst gain is 9 dB. */
    CODEC_MICBST_GAIN_12dB,                 /**< MicBst gain is 12 dB. */
    CODEC_MICBST_GAIN_18dB,                 /**< MicBst gain is 18 dB. */
    CODEC_MICBST_GAIN_24dB,                 /**< MicBst gain is 24 dB. */
    CODEC_MICBST_GAIN_30dB,                 /**< MicBst gain is 30 dB. */
} CODECMicBstGain_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_MICBST_GAIN(GAIN) (((GAIN) == CODEC_MICBST_GAIN_0dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_3dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_6dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_9dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_12dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_18dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_24dB) || \
                                    ((GAIN) == CODEC_MICBST_GAIN_30dB))

/** @} */ /* End of group CODEC_MICBST_GAIN */

/**
 * @defgroup CODEC_CH0_BOOST_GAIN CODEC Ch0 Boost Gain
 * @{
 */
typedef enum
{
    CODEC_CH0_BOOST_GAIN_0dB,               /**< Channel 0 boost gain is 0 dB. */
    CODEC_CH0_BOOST_GAIN_12dB,              /**< Channel 0 boost gain is 12 dB. */
    CODEC_CH0_BOOST_GAIN_24dB,              /**< Channel 0 boost gain is 24 dB. */
    CODEC_CH0_BOOST_GAIN_36dB,              /**< Channel 0 boost gain is 36 dB. */
} CODECCH0_Boost_Gain_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CH0_BOOST_GAIN(GAIN) (((GAIN) == CODEC_CH0_BOOST_GAIN_0dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_12dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_24dB) || \
                                 ((GAIN) == CODEC_CH0_BOOST_GAIN_36dB))

/** @} */ /* End of group CODEC_CH0_BOOST_GAIN */

/**
 * @defgroup CODEC_MICBST_MODE CODEC MicBst Mode
 * @{
 */
typedef enum
{
    CODEC_MICBST_MODE_SINGLE,               /**< Single-ended mode. */
    CODEC_MICBST_MODE_DIFFERENTIAL,         /**< Differential mode. */
} CODECMicBstMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_MICBST_MODE(MODE) (((MODE) == CODEC_MICBST_MODE_SINGLE) || \
                                    ((MODE) == CODEC_MICBST_MODE_DIFFERENTIAL))

/** @} */ /* End of group CODEC_MICBST_MODE */

/**
 * @defgroup CODEC_CH_MUTE CODEC Ch Mute
 * @{
 */
typedef enum
{
    CODEC_CH_UNMUTE,                        /**< Channel unmute. */
    CODEC_CH_MUTE,                          /**< Channel mute. */
} CODECChMute_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_CH_MUTE(MUTE) (((MUTE) == CODEC_CH_MUTE) || \
                                ((MUTE) == CODEC_CH_UNMUTE))

/** @} */ /* End of group CODEC_CH_MUTE */

/**
 * @defgroup CODEC_CH_MIC CODEC Ch Mic
 * @{
 */
typedef enum
{
    CODEC_CH_DMIC,                          /**< Digital microphone. */
    CODEC_CH_AMIC,                          /**< Analog microphone. */
} CODECChMic_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_CH_MIC(MIC) (((MIC) == CODEC_CH_AMIC) || \
                              ((MIC) == CODEC_CH_DMIC))

/** @} */ /* End of group CODEC_CH_MIC */

/**
 * @defgroup CODEC_CH_DMIC_DATA_LATCH DMIC Data Latch
 * @{
 */
typedef enum
{
    CODEC_CH_DMIC_DATA_LATCH_RISING,        /**< Data latched on rising edge. */
    CODEC_CH_DMIC_DATA_LATCH_FALLING,       /**< Data latched on falling edge. */
} CODECChDmicDataLatch_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_DMIC_DATA_LATCH(EDGE) (((EDGE) == CODEC_CH_DMIC_DATA_LATCH_RISING) || \
                                        ((EDGE) == CODEC_CH_DMIC_DATA_LATCH_FALLING))

/** @} */ /* End of group CODEC_CH_DMIC_DATA_LATCH */

/**
 * @defgroup CODEC_CH_DETECTION_TIMEOUT CODEC Ch Detection Timeout
 * @{
 */
typedef enum
{
    CODEC_CH_DETTIMEOUT_1024_16_SAMPLE,     /**< The CODEC channel detection timeout is 1024/16 samples. */
    CODEC_CH_DETTIMEOUT_1024_32_SAMPLE,     /**< The CODEC channel detection timeout is 1024/32 samples. */
    CODEC_CH_DETTIMEOUT_1024_64_SAMPLE,     /**< The CODEC channel detection timeout is 1024/64 samples. */
    CODEC_CH_DETTIMEOUT_64_SAMPLE,          /**< The CODEC channel detection timeout is 64 samples. */
} CODECChDetTimeout_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_CH_DET_TIMEOUT(TIMEOUT) (((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_16_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_32_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_1024_64_SAMPLE) || \
                                          ((TIMEOUT) == CODEC_CH_DETTIMEOUT_64_SAMPLE))

/** @} */ /* End of group CODEC_CH_DETECTION_TIMEOUT */

/**
 * @defgroup CODEC_AD_GAIN CODEC AD Gain
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_AD_GAIN(GAIN)            (((GAIN)<= 0x7F))

/** @} */ /* End of group CODEC_AD_GAIN */

/**
 * @defgroup CODEC_INTERRUPT_DEFINITION CODEC Interrupt Definition
 * @{
 */
#if CODEC_SUPPORT_INT
#define CODEC_INT_POF_READY                            BIT1    /**< CODEC power off ready interrupt. */
#define CODEC_INT_PON_READY                            BIT0    /**< CODEC power on ready interrupt. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_CODEC_INT_CONFIG(INT)          (((INT) == CODEC_INT_POF_READY) || ((INT) == CODEC_INT_PON_READY))

#endif
/** @} */ /* End of group CODEC_INTERRUPT_DEFINITION */

/** @} */ /* End of group CODEC_Exported_Constants */

/**
 * @defgroup CODEC_Exported_Types CODEC Exported Types
 * @{
 */

/** @brief CODEC initialize parameters. */
typedef struct
{
    /* Basic parameters section */
    CODECSampleRate_TypeDef CODEC_SampleRate;       /**< Specifies the sample rate. */

    CODECDmicClock_TypeDef CODEC_DmicClock;         /**< Specifies the DMIC clock. */

    CODECI2SDataFormat_TypeDef
    CODEC_I2SDataFormat;                            /**< Specifies the I2S Tx/Rx format of CODEC port. */

    CODECI2SDataWidth_TypeDef CODEC_I2SDataWidth;   /**< Specifies the I2S data width of CODEC port. */

    CODECI2SChSeq_TypeDef CODEC_I2SChSequence;      /**< Specifies the I2S Tx/Rx channel sequence. */

    CODECMicBiasVoltage_TypeDef CODEC_MicBiasVolt;  /**< Specifies the MICBIAS voltage. */

    CODECMicBstGain_TypeDef CODEC_MicBstGain;       /**< Specifies the MicBst gain. */

    CODECMicBstMode_TypeDef CODEC_MicBstMode;       /**< Specifies the MicBst mode. */

    /* MIC channel 0 initialization parameters section */
    CODECChMute_TypeDef CODEC_Ch0Mute;              /**< Specifies the channel 0 mute status. */

    CODECChMic_TypeDef
    CODEC_Ch0Mic;                                   /**< Specifies the channel 0 mic type, which can be DMIC or AMIC. */

    CODECChDmicDataLatch_TypeDef
    CODEC_Ch0DmicDataLatch;                         /**< Specifies the channel 0 DMIC data latch type. */

    uint32_t CODEC_Ch0AdGain;                       /**< Specifies the channel 0 ADC digital volume.
                                                         -17.625 dB to +30 dB in 0.375 dB step. */

    CODECChDetTimeout_TypeDef
    CODEC_Ch0DetTimeout;                            /**< Specifies the channel 0 zero detection timeout mode. */
    CODECCH0_Boost_Gain_TypeDef CODEC_Ch0BoostGain; /**< Specifies the channel 0 boost gain. */
} CODEC_InitTypeDef;


/** @brief CODEC EQ part initialize parameters. */
typedef struct
{
    uint32_t CODEC_EQChCmd;             /**< Specifies the EQ channel status. */

    uint32_t CODEC_EQCoefH0;            /**< Specifies the EQ coefficient h0.
                                             This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of -8 to 7.99. */

    uint32_t CODEC_EQCoefB1;            /**< Specifies the EQ coefficient b1.
                                             This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of -8 to 7.99. */

    uint32_t CODEC_EQCoefB2;            /**< Specifies the EQ coefficient b2.
                                             This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of -8 to 7.99. */

    uint32_t CODEC_EQCoefA1;            /**< Specifies the EQ coefficient a1.
                                             This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of -8 to 7.99. */

    uint32_t CODEC_EQCoefA2;            /**< Specifies the EQ coefficient a2.
                                             This value can be 0 to 0x7FFFF,
                                             whose physical meaning represents a range of -8 to 7.99. */
} CODEC_EQInitTypeDef;

/** @} */ /* End of group CODEC_Exported_Types */

/**
 * @defgroup CODEC_Exported_Functions CODEC Exported Functions
 * @{
 */

/**
 * @brief Deinitializes the CODEC peripheral registers to their default reset values (turn off CODEC clock).
 * @param[in] CODECx CODEC peripheral selected.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     CODEC_DeInit(CODEC);
 * }
 * @endcode
 */
void CODEC_DeInit(CODEC_TypeDef *CODECx);

/**
 * @brief Initializes the CODEC analog registers in AON area.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *     CODEC_AnalogCircuitInit();
 *     CODEC_InitTypeDef CODEC_InitStruct;
 *
 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0Mic           = CODEC_CH_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = CODEC_MICBST_MODE_DIFFERENTIAL;
 *     CODEC_InitStruct.CODEC_SampleRate       = CODEC_SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * @endcode
 */
void CODEC_AnalogCircuitInit(void);

/**
 * @brief Initializes the CODEC peripheral according to the specified
 *        parameters in the CODEC_InitStruct.
 * @param[in] CODECx CODEC peripheral selected.
 * @param[in] CODEC_InitStruct Pointer to a CODEC_InitTypeDef structure that
 *            contains the configuration information for the specified CODEC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;
 *
 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0Mic           = CODEC_CH_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = CODEC_MICBST_MODE_DIFFERENTIAL;
 *     CODEC_InitStruct.CODEC_SampleRate       = CODEC_SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * @endcode
 */
void CODEC_Init(CODEC_TypeDef *CODECx, CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * @brief Fills each CODEC_InitStruct member with its default value.
 * @param[in] CODEC_InitStruct Pointer to a CODEC_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_init(void)
 * {
 *     RCC_ClockCmd(CODEC_CLOCK, ENABLE);
 *
 *     CODEC_InitTypeDef CODEC_InitStruct;
 *
 *     CODEC_StructInit(&CODEC_InitStruct);
 *     CODEC_InitStruct.CODEC_Ch0Mic           = CODEC_CH_AMIC;
 *     CODEC_InitStruct.CODEC_MicBstMode       = CODEC_MICBST_MODE_DIFFERENTIAL;
 *     CODEC_InitStruct.CODEC_SampleRate       = CODEC_SAMPLE_RATE_16KHz;
 *     CODEC_InitStruct.CODEC_I2SDataFormat    = CODEC_I2S_DATA_FORMAT_I2S;
 *     CODEC_InitStruct.CODEC_I2SDataWidth     = CODEC_I2S_DATA_WIDTH_16BITS;
 *     CODEC_Init(CODEC, &CODEC_InitStruct);
 * }
 * @endcode
 */
void CODEC_StructInit(CODEC_InitTypeDef *CODEC_InitStruct);

/**
 * @brief Initializes the CODEC EQ module according to the specified
 *        parameters in the CODEC_EQInitStruct.
 * @param[in] CODEC_EQx CODEC EQ channel selected.
 * @param[in] CODEC_EQInitStruct Pointer to a CODEC_EQInitTypeDef structure that
 *            contains the configuration information for the specified CODEC EQ channel.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_EQStructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct.CODEC_EQChCmd    = ENABLE;
 *     CODEC_EQInitStruct.CODEC_EQCoefH0    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB2    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA2    = 0xFF;
 *     CODEC_EQInit(CODEC_ADC_CH0_EQ0, &CODEC_EQInitStruct);
 * }
 * @endcode
 */
void CODEC_EQInit(CODEC_EQTypeDef *CODEC_EQx, CODEC_EQInitTypeDef *CODEC_EQInitStruct);

/**
 * @brief Fills each CODEC_EQInitStruct member with its default value.
 * @param[in] CODEC_EQInitStruct Pointer to a CODEC_EQInitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_codec_eq_init(void)
 * {
 *     CODEC_EQInitTypeDef  CODEC_EQInitStruct;
 *     CODEC_EQStructInit(&CODEC_EQInitStruct);
 *     CODEC_EQInitStruct.CODEC_EQChCmd    = ENABLE;
 *     CODEC_EQInitStruct.CODEC_EQCoefH0    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefB2    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA1    = 0xFF;
 *     CODEC_EQInitStruct.CODEC_EQCoefA2    = 0xFF;
 *     CODEC_EQInit(CODEC_ADC_CH0_EQ0, &CODEC_EQInitStruct);
 * }
 * @endcode
 */
void CODEC_EQStructInit(CODEC_EQInitTypeDef *CODEC_EQInitStruct);

/**
 * @brief Resets the CODEC peripheral.
 * @param[in] CODECx CODEC peripheral selected.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_Reset(CODEC);
 * }
 * @endcode
 */
void CODEC_Reset(CODEC_TypeDef *CODECx);

/**
 * @brief Configures the MIC BIAS Vref voltage.
 * @param[in] CODECx CODEC peripheral selected.
 * @param[in] Data New value of MIC BIAS.
 *            This parameter can be one of the following values:
 *            - CODEC_MICBIAS_VOLTAGE_1_507: Vref voltage is 1.507 V.
 *            - CODEC_MICBIAS_VOLTAGE_1_62:  Vref voltage is 1.62 V.
 *            - CODEC_MICBIAS_VOLTAGE_1_705: Vref voltage is 1.705 V.
 *            - CODEC_MICBIAS_VOLTAGE_1_8:   Vref voltage is 1.8 V.
 *            - CODEC_MICBIAS_VOLTAGE_1_906: Vref voltage is 1.906 V.
 *            - CODEC_MICBIAS_VOLTAGE_2_025: Vref voltage is 2.025 V.
 *            - CODEC_MICBIAS_VOLTAGE_2_16:  Vref voltage is 2.16 V.
 *            - CODEC_MICBIAS_VOLTAGE_2_314: Vref voltage is 2.314 V.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_SetMicBias(CODEC, CODEC_MICBIAS_VOLTAGE_1_507);
 * }
 * @endcode
 */
void CODEC_SetMicBias(CODEC_TypeDef *CODECx, uint16_t Data);

/**
 * @brief Enables or disables MICBIAS output.
 * @param[in] CODECx CODEC peripheral selected.
 * @param[in] NewState New state of MICBIAS.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_MicBiasCmd(CODEC, ENABLE);
 * }
 * @endcode
 */
void CODEC_MicBiasCmd(CODEC_TypeDef *CODECx, FunctionalState NewState);

/**
 * @brief Enables or disables the specified CODEC interrupts.
 * @param[in] CODECx Selected CODEC peripheral.
 * @param[in] CODEC_INT Specifies the CODEC interrupts sources to be enabled or disabled.
 *            This parameter can be the following values:
 *            - CODEC_INT_POF_READY: CODEC power off ready interrupt.
 *            - CODEC_INT_PON_READY: CODEC power on ready interrupt.
 * @param[in] NewState New state of the specified CODEC interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_INTConfig(CODEC, CODEC_INT_PON_READY, ENABLE);
 * }
 * @endcode
 */
void CODEC_INTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState);

/**
 * @brief Masks the specified CODEC interrupt.
 * @param[in] CODECx Selected CODEC peripheral.
 * @param[in] CODEC_INT Specifies the CODEC interrupts sources to be enabled or disabled.
 *            This parameter can be the following values:
 *            - CODEC_INT_POF_READY: CODEC power off ready interrupt.
 *            - CODEC_INT_PON_READY: CODEC power on ready interrupt.
 * @param[in] NewState New state of the specified CODEC interrupts.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_MaskINTConfig(CODEC, CODEC_INT_PON_READY, ENABLE);
 * }
 * @endcode
 */
void CODEC_MaskINTConfig(CODEC_TypeDef *CODECx, uint32_t CODEC_INT, FunctionalState NewState);

/**
 * @brief Gets the specified CODEC flag status.
 * @param[in] CODECx Selected CODEC peripheral.
 * @param[in] CODEC_INT The specified CODEC interrupt.
 *            This parameter can be one of the following values:
 *            - CODEC_INT_POF_READY: CODEC power off ready interrupt.
 *            - CODEC_INT_PON_READY: CODEC power on ready interrupt.
 * @return The new state of FLAG.
 * @retval SET  The flag is set.
 * @retval RESET  The flag is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     ITStatus Status;
 *     Status = CODEC_GetINTStatus(CODEC, CODEC_INT_PON_READY);
 * }
 * @endcode
 */
ITStatus CODEC_GetINTStatus(CODEC_TypeDef *CODECx, uint32_t CODEC_INT);

/**
 * @brief Clears the CODEC interrupt pending bits.
 * @param[in] CODECx Selected CODEC peripheral.
 * @param[in] CODEC_CLEAR_INT Specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            - CODEC_INT_POF_READY: CODEC power off ready interrupt.
 *            - CODEC_INT_PON_READY: CODEC power on ready interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     CODEC_ClearINTPendingBit(CODEC, CODEC_INT_PON_READY);
 * }
 * @endcode
 */
void CODEC_ClearINTPendingBit(CODEC_TypeDef *CODECx, uint32_t CODEC_CLEAR_INT);

/**
 * @brief Enables or disables the CODEC clock auto mode.
 * @param[in] CODECx CODEC peripheral selected.
 * @param[in] NewState New state of clock auto mode.
 *            This parameter can be: ENABLE or DISABLE.
 *            - ENABLE: Enable auto mode, hardware controls PCLK/SCLK qactive automatically.
 *            - DISABLE: Disable auto mode, PCLK/SCLK qactive is held active via manual control.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void codec_demo(void)
 * {
 *     Codec_ClockAutoModeCmd(CODEC, DISABLE);
 * }
 * @endcode
 */
void Codec_ClockAutoModeCmd(CODEC_TypeDef *CODECx, FunctionalState NewState);

/** @} */ /* End of group CODEC_Exported_Functions */

/** @} */ /* End of group CODEC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_CODEC_H */
