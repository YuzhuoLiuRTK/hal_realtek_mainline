/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_I2S_H
#define RTL_I2S_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "i2s/src/device/rtl87x2g/rtl_i2s_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "i2s/src/device/rtl87x2j/rtl_i2s_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "i2s/src/device/rtl87x3j/rtl_i2s_def.h"
#endif

/**
 * @defgroup I2S_DRIVER DRIVER
 * @ingroup I2S
 * @brief I2S (Inter-IC Sound) module.
 * @{
 */

/**
 * @defgroup I2S_Exported_Constants I2S Exported Constants
 * @{
 */

#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
 * @defgroup I2S_Scheme  I2S Scheme
 * @{
 */
typedef enum
{
    I2S_SCHEME_SEPARATE,      /**< I2S scheme separate. */
    I2S_SCHEME_DEPENDENT,     /**< I2S scheme dependent. */
} I2SScheme_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_SCHEME(SCHEME) (((SCHEME) == I2S_SCHEME_SEPARATE) || \
                               ((SCHEME) == I2S_SCHEME_DEPENDENT))

/** @} */ /* End of group I2S_Scheme */

#endif

/**
 * @defgroup I2S_Data_Format  I2S Data Format
 * @{
 */
typedef enum
{
    I2S_DATA_FORMAT_I2S,              /**< I2S mode. */
    I2S_DATA_FORMAT_LEFT_JUSTIFIED,   /**< Left justified mode. */
    I2S_DATA_FORMAT_PCM_A,            /**< PCM mode A. */
    I2S_DATA_FORMAT_PCM_B,            /**< PCM mode B. */
} I2SDataFormat_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_DATA_FORMAT(FORMAT)      (((FORMAT) == I2S_DATA_FORMAT_I2S) || ((FORMAT) == I2S_DATA_FORMAT_LEFT_JUSTIFIED) || \
                                         ((FORMAT) == I2S_DATA_FORMAT_PCM_A) || ((FORMAT) == I2S_DATA_FORMAT_PCM_B))

/** @} */ /* End of group I2S_Data_Format */

/**
 * @defgroup I2S_Channel_Type I2S Channel Type
 * @{
 */
typedef enum
{
    I2S_CHANNEL_STEREO,       /**< The channel format of the I2S is stereo. */
    I2S_CHANNEL_MONO,         /**< The channel format of the I2S is mono. */
} I2SChannelType_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_CHANNEL_TYPE(TYPE)       (((TYPE) == I2S_CHANNEL_MONO) || ((TYPE) == I2S_CHANNEL_STEREO))

/** @} */ /* End of group I2S_Channel_Type */

/**
 * @defgroup I2S_Width I2S Width
 * @{
 */
typedef enum
{
    I2S_WIDTH_16BITS = 0x00,      /**< The I2S data width is 16 bits. */
    I2S_WIDTH_24BITS = 0x02,      /**< The I2S data width is 24 bits. */
    I2S_WIDTH_8BITS = 0x03,       /**< The I2S data width is 8 bits. */
#if I2S_SUPPORT_DATE_WIDTH_32BIT
    I2S_WIDTH_20BITS = 0x01,      /**< The I2S data width is 20 bits. */
    I2S_WIDTH_32BITS = 0x04,      /**< The I2S data width is 32 bits. */
#endif
} I2SWidth_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_WIDTH(WIDTH)        (((WIDTH) == I2S_WIDTH_16BITS) || \
                                    ((WIDTH) == I2S_WIDTH_8BITS)  || \
                                    ((WIDTH) == I2S_WIDTH_24BITS) || \
                                    ((WIDTH) == I2S_WIDTH_20BITS) || \
                                    ((WIDTH) == I2S_WIDTH_32BITS))

/** @} */ /* End of group I2S_Width */

#if I2S_SUPPORT_TDM_MODE
/**
 * @defgroup I2S_TDM_Mode I2S TDM Mode
 * @{
 */
typedef enum
{
    I2S_TDM_DISABLE = 0x00,         /**< Configure the TDM mode as non-TDM. */
    I2S_TDM_MODE_4 = 0x01,          /**< Configure the TDM mode as TDM4. */
    I2S_TDM_MODE_6 = 0x02,          /**< Configure the TDM mode as TDM6. */
    I2S_TDM_MODE_8 = 0x03,          /**< Configure the TDM mode as TDM8. */
} I2STDM_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_TDM_MODE(MODE)                       (((MODE) == I2S_TDM_DISABLE) || \
                                                     ((MODE) == I2S_TDM_MODE_4)  || \
                                                     ((MODE) == I2S_TDM_MODE_6)  || \
                                                     ((MODE) == I2S_TDM_MODE_8))
/** @} */ /* End of group I2S_TDM_Mode */
#endif

/**
 * @defgroup I2S_Device_Mode I2S Device Mode
 * @{
 */
typedef enum
{
    I2S_DEVICE_MODE_MASTER,       /**< I2S master mode. */
    I2S_DEVICE_MODE_SLAVE,        /**< I2S slave mode. */
} I2SDeviceMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_DEVICE_MODE(DEVICE)      (((DEVICE) == I2S_DEVICE_MODE_MASTER) || ((DEVICE) == I2S_DEVICE_MODE_SLAVE))

/** @} */ /* End of group I2S_Device_Mode */

/**
 * @defgroup I2S_Ch_Seq I2S Ch Seq
 * @{
 */
typedef enum
{
    I2S_CH_SEQ_L_R,       /**< I2S channel sequence from left to right. */
    I2S_CH_SEQ_R_L,       /**< I2S channel sequence from right to left. */
    I2S_CH_SEQ_L_L,       /**< I2S channel sequence from left to left. */
    I2S_CH_SEQ_R_R,       /**< I2S channel sequence from right to right. */
} I2SChSeq_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_CH_SEQ(SEQ)       (((SEQ) == I2S_CH_SEQ_L_R) || ((SEQ) == I2S_CH_SEQ_R_L) || \
                                  ((SEQ) == I2S_CH_SEQ_L_L) || ((SEQ) == I2S_CH_SEQ_R_R))

/** @} */ /* End of group I2S_Ch_Seq */

/**
 * @defgroup I2S_Bit_Seq I2S Bit Seq
 * @{
 */
typedef enum
{
    I2S_MSB_FIRST,        /**< I2S bit sequence MSB first. */
    I2S_LSB_FIRST,        /**< I2S bit sequence LSB first. */
} I2SBitSeq_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_BIT_SEQ(SEQ)      (((SEQ) == I2S_MSB_FIRST) || ((SEQ) == I2S_LSB_FIRST))

/** @} */ /* End of group I2S_Bit_Seq */
#if I2S_SUPPORT_TRX_FIFO
/**
 * @defgroup I2S_FIFO_Sel I2S FIFO Sel
 * @{
 */
typedef enum
{
    I2S_FIFO_USE_0_REG_0 = BIT0,      /**< Enable first two channel of I2S FIFO. */
    I2S_FIFO_USE_0_REG_1 = BIT1,      /**< Enable last two channel of I2S FIFO. */
} I2SFIFOSel_TypeDef;

/** @} */ /* End of group I2S_FIFO_Sel */
#endif
#if I2S_SUPPORT_MCLK_OUTPUT
/**
 * @defgroup I2S_MCLK_Output I2S MCLK Output
 * @{
 */

typedef enum
{
    I2S_MCLK_128FS,       /**< I2S MCLK output 128fs. */
    I2S_MCLK_256FS,       /**< I2S MCLK output 256fs. */
} I2SMClkOutput_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_MCLK_OUTPUT(TYPE)       (((TYPE) == I2S_MCLK_128FS) || ((TYPE) == I2S_MCLK_256FS))

/** @} */ /* End of group I2S_MCLK_Output */

#endif

/**
 * @defgroup I2S_Register_Definitions I2S Register Definitions
 * @{
 */
/*  I2S_CLR_RX_ERR_CNT. */
#define I2S_CLR_RX_ERR_CNT_MSK          (0x1 << 13)   /**< Bitmask for the RX error counter clear bit (bit 13). */
#define I2S_CLR_RX_ERR_CNT_CLR          (~I2S_CLR_RX_ERR_CNT_MSK) /**< Inverted bitmask to deassert the RX error counter clear bit. */
/* I2S_CLR_TX_ERR_CNT. */
#define I2S_CLR_TX_ERR_CNT_MSK          (0x1 << 12)   /**< Bitmask for the TX error counter clear bit (bit 12). */
#define I2S_CLR_TX_ERR_CNT_CLR          (~I2S_CLR_TX_ERR_CNT_MSK) /**< Inverted bitmask to deassert the TX error counter clear bit. */

#define I2S_RX_FIFO_DEPTH_CNT_0_POS       (8)    /**< Bit position of the RX FIFO depth count 0 field. */
#define I2S_RX_ERR_CNT_POS                (15)   /**< Bit position of the RX error counter field. */
#define I2S_MI_NI_UPDATE_MSK             ((uint32_t)0x1 << 31) /**< Bitmask to trigger MI/NI parameter update (bit 31). */

#define I2S_FRAME_SYNC_OFFSET_DEFAULT    (0x81)  /**< Default value for the frame sync offset. */
/** @} */ /* End of group I2S_Register_Definitions */

/**
 * @defgroup I2S_Mode I2S Mode
 * @{
 */
typedef enum
{
    I2S_MODE_TX,      /**< I2S TX mode. */
    I2S_MODE_RX,      /**< I2S RX mode. */
} I2SMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_MODE(MODE)      (((MODE) == I2S_MODE_TX) || ((MODE) == I2S_MODE_RX))

/** @} */ /* End of group I2S_Mode */

#if I2S_SUPPORT_TRX_FIFO
/**
 * @defgroup I2S_Tx_FIFO_Sel I2S Tx FIFO Sel
 * @{
 */
typedef enum
{
    I2S_TX_FIFO_0_REG_0_L,                        /**< I2S left channel FIFO data storage selects the REG_0 register. */
    I2S_TX_FIFO_0_REG_0_R,                        /**< I2S right channel FIFO data storage selects the REG_0 register. */
    I2S_TX_FIFO_0_REG_1_L,                        /**< I2S left channel FIFO data storage selects the REG_1 register. */
    I2S_TX_FIFO_0_REG_1_R,                        /**< I2S right channel FIFO data storage selects the REG_1 register. */
    I2S_TX_SEL_MAX,                               /**< Maximum I2S TX selection. */
} I2STxFIFOSel_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_TX_FIFO_SEL(FIFO)       (((FIFO) == I2S_TX_FIFO_0_REG_0_L) || ((FIFO) == I2S_TX_FIFO_0_REG_0_R) || \
                                        ((FIFO) == I2S_TX_FIFO_0_REG_1_L) || ((FIFO) == I2S_TX_FIFO_0_REG_1_R))

/** @} */ /* End of group I2S_Tx_FIFO_Sel */

/**
 * @defgroup I2S_Rx_Channel_Sel I2S Rx Channel Sel
 * @{
 */
typedef enum
{
    I2S_RX_CHANNEL_0,                             /**< I2S RX channel 0. */
    I2S_RX_CHANNEL_1,                             /**< I2S RX channel 1. */
    I2S_RX_CHANNEL_2,                             /**< I2S RX channel 2. */
    I2S_RX_CHANNEL_3,                             /**< I2S RX channel 3. */
    I2S_RX_SEL_MAX,                               /**< Maximum I2S RX channel selection. */
} I2SRxChannel_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_RX_CHANNEL(CHANNEL)       (((CHANNEL) == I2S_RX_CHANNEL_0) || ((CHANNEL) == I2S_RX_CHANNEL_1) || \
                                          ((CHANNEL) == I2S_RX_CHANNEL_2) || ((CHANNEL) == I2S_RX_CHANNEL_3))
/** @} */ /* End of group I2S_Rx_Channel_Sel */

#endif

/**
 * @defgroup I2S_Interrupt_Definition   I2S Interrupt Definition
 * @{
 */
#if I2S_SUPPORT_INT_TX_VALID
#define I2S_INT_TX_VALID                            BIT7  /**< The I2S interrupt for TX valid. */
#endif
#define I2S_INT_TX_IDLE                             BIT6  /**< The I2S interrupt for TX is working, but FIFO_0 is empty. */
#define I2S_INT_RF_EMPTY                            BIT5  /**< The I2S interrupt for RX FIFO_0 is empty (MIC path). */
#define I2S_INT_TF_EMPTY                            BIT4  /**< The I2S interrupt for TX FIFO_0 is empty (SPK path). */
#define I2S_INT_RF_FULL                             BIT3  /**< The I2S interrupt for RX FIFO_0 is full (MIC path). */
#define I2S_INT_TF_FULL                             BIT2  /**< The I2S interrupt for TX FIFO_0 is full (SPK path). */
#define I2S_INT_RX_READY                            BIT1  /**< The I2S interrupt is ready to receive data (MIC path). */
#define I2S_INT_TX_READY                            BIT0  /**< The I2S interrupt is ready to send data out (SPK path). */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_INT_CONFIG(INT)          (((INT) == I2S_INT_TX_IDLE) || ((INT) == I2S_INT_RF_EMPTY) || \
                                         ((INT) == I2S_INT_TF_EMPTY) || ((INT) == I2S_INT_RF_FULL) || \
                                         ((INT) == I2S_INT_TF_FULL) || ((INT) == I2S_INT_RX_READY) || \
                                         ((INT) == I2S_INT_TX_READY))

/** @} */ /* End of group I2S_Interrupt_Definition */

/**
 * @defgroup I2S_Clear_Interrupt_Definition     I2S Clear Interrupt Definition
 * @{
 */
#define I2S_CLEAR_INT_TX_VALID                      BIT14 /**< Clear the I2S interrupt for TX valid. */
#define I2S_CLEAR_INT_TX_IDLE                       BIT6  /**< Clear the I2S interrupt for TX is working, but FIFO_0 is empty. */
#define I2S_CLEAR_INT_RF_EMPTY                      BIT5  /**< Clear the I2S interrupt for RX FIFO_0 is empty (MIC path). */
#define I2S_CLEAR_INT_TF_EMPTY                      BIT4  /**< Clear the I2S interrupt for TX FIFO_0 is empty (SPK path). */
#define I2S_CLEAR_INT_RF_FULL                       BIT3  /**< Clear the I2S interrupt for RX FIFO_0 is full (MIC path). */
#define I2S_CLEAR_INT_TF_FULL                       BIT2  /**< Clear the I2S interrupt for TX FIFO_0 is full (SPK path). */
#define I2S_CLEAR_INT_RX_READY                      BIT1  /**< Clear the I2S interrupt is ready to receive data (MIC path). */
#define I2S_CLEAR_INT_TX_READY                      BIT0  /**< Clear the I2S interrupt is ready to send data out (SPK path). */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2S_CLEAR_INT(CLEAR)          (((CLEAR) == I2S_CLEAR_INT_RX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_RX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TX_READY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_RF_EMPTY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TF_EMPTY) || \
                                          ((CLEAR) == I2S_CLEAR_INT_RF_FULL) || \
                                          ((CLEAR) == I2S_CLEAR_INT_TF_FULL))

/** @} */ /* End of group I2S_Clear_Interrupt_Definition */

/** @} */ /* End of group I2S_Exported_Constants */

/**
 * @defgroup I2S_Exported_Types I2S Exported Types
 * @{
 */

/**
 * @brief I2S initialize parameters.
 */
typedef struct
{
    I2SClockSrc_TypeDef I2S_ClockSource;          /**< Specify the I2S clock source.
                                                       This parameter can be a value of @ref I2S_Clock_Source. */

#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
    I2SScheme_TypeDef I2S_Scheme;                 /**< Specify the I2S scheme.
                                                       This parameter can be a value of @ref I2S_Scheme. */

    uint32_t I2S_TxBClockMi;                      /**< Specify the BCLK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                       This parameter must range from 1 to 0xffff. */

    uint32_t I2S_TxBClockNi;                      /**< Specify the BCLK clock speed.
                                                       This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_TxBClockDiv;                     /**< Specify the BCLK clock divider. The actual BCLK clock divider = I2S_TxBClockDiv + 1.
                                                       This parameter must range from 1 to 0xFF. */

    uint32_t I2S_RxBClockMi;                      /**< Specify the BCLK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                       This parameter must range from 1 to 0xffff. */

    uint32_t I2S_RxBClockNi;                      /**< Specify the BCLK clock speed.
                                                       This parameter must range from 1 to 0x7FFF. */

    uint32_t I2S_RxBClockDiv;                     /**< Specify the BCLK clock divider. The actual BCLK clock divider = I2S_RxBClockDiv + 1.
                                                       This parameter must range from 1 to 0xFF. */

    I2SChannelType_TypeDef
    I2S_TxChannelType;     /**< Specify the channel type used for the I2S communication.
                                                       This parameter can be a value of @ref I2S_Channel_Type. */

    I2SChannelType_TypeDef
    I2S_RxChannelType;     /**< Specify the channel type used for the I2S communication.
                                                       This parameter can be a value of @ref I2S_Channel_Type. */

    I2SDataFormat_TypeDef I2S_TxDataFormat;       /**< Specify the I2S Data format mode.
                                                       This parameter can be a value of @ref I2S_Data_Format. */

    I2SDataFormat_TypeDef I2S_RxDataFormat;       /**< Specify the I2S Data format mode.
                                                       This parameter can be a value of @ref I2S_Data_Format. */

    I2SWidth_TypeDef I2S_TxDataWidth;             /**< Specify the I2S Tx Data width.
                                                       This parameter can be a value of @ref I2S_Width. */

    I2SWidth_TypeDef I2S_RxDataWidth;             /**< Specify the I2S Rx Data width.
                                                       This parameter can be a value of @ref I2S_Width. */

    I2SWidth_TypeDef I2S_TxChannelWidth;          /**< Specify the I2S Tx channel width.
                                                       This parameter can be a value of @ref I2S_Width. */

    I2SWidth_TypeDef I2S_RxChannelWidth;          /**< Specify the I2S Rx channel width.
                                                       This parameter can be a value of @ref I2S_Width. */

    FunctionalState I2S_BClockFixEn;              /**< Specify the I2S BCLK fix.
                                                       If ENABLE, BCLK is fixed as 40M/4. */
#if I2S_SUPPORT_TDM_MODE
    I2STDM_TypeDef I2S_TxTdmMode;                 /**< Specifies the I2S Tx TDM mode.
                                                       This parameter can be a value of @ref I2S_TDM_Mode. */

    I2STDM_TypeDef I2S_RxTdmMode;                 /**< Specifies the I2S Rx TDM mode.
                                                       This parameter can be a value of @ref I2S_TDM_Mode. */
#endif
#else
    uint32_t I2S_BClockMi;                        /**< Specify the BCLK clock speed. BCLK = 40MHz*(I2S_BClockNi/I2S_BClockMi).
                                                       This parameter must range from 1 to 0xffff. */

    uint32_t I2S_BClockNi;                        /**< Specify the BCLK clock speed.
                                                       This parameter must range from 1 to 0x7FFF. */

    I2SChannelType_TypeDef
    I2S_ChannelType;       /**< Specify the channel type used for the I2S communication.
                                                       This parameter can be a value of @ref I2S_Channel_Type. */

    I2SDataFormat_TypeDef I2S_DataFormat;         /**< Specify the I2S Data format mode.
                                                       This parameter can be a value of @ref I2S_Data_Format. */

    I2SWidth_TypeDef I2S_DataWidth;               /**< Specify the I2S Data width.
                                                       This parameter can be a value of @ref I2S_Width. */
#endif

#if I2S_SUPPORT_TRX_FIFO
    I2SFIFOSel_TypeDef I2S_TxFIFOSel;             /**< Specify the I2S Tx FIFO.
                                                       This parameter can be a value of @ref I2S_FIFO_Sel. */

    I2SFIFOSel_TypeDef I2S_RxFIFOSel;             /**< Specify the I2S Rx FIFO.
                                                       This parameter can be a value of @ref I2S_FIFO_Sel. */
#endif

    I2SDeviceMode_TypeDef I2S_DeviceMode;         /**< Specify the I2S device mode.
                                                       This parameter can be a value of @ref I2S_Device_Mode. */

    I2SChSeq_TypeDef
    I2S_RxChannelSequence;       /**< Specify the Rx channel sequence used for the I2S communication.
                                                       This parameter can be a value of @ref I2S_Ch_Seq. */

    I2SChSeq_TypeDef
    I2S_TxChannelSequence;       /**< Specify the Tx channel sequence used for the I2S communication.
                                                       This parameter can be a value of @ref I2S_Ch_Seq. */

    I2SBitSeq_TypeDef I2S_TxBitSequence;          /**< Specify the I2S Tx Data bits sequences.
                                                       This parameter can be a value of @ref I2S_Bit_Seq. */

    I2SBitSeq_TypeDef I2S_RxBitSequence;          /**< Specify the I2S Rx Data bits sequences.
                                                       This parameter can be a value of @ref I2S_Bit_Seq. */

    uint32_t I2S_TxWaterlevel;                    /**< Specify the DMA watermark level in Tx mode.
                                                       This parameter must range from 1 to 63. */

    uint32_t I2S_RxWaterlevel;                    /**< Specify the DMA watermark level in Rx mode.
                                                       This parameter must range from 1 to 63. */

#if I2S_SUPPORT_MCLK_OUTPUT
    I2SMClkOutput_TypeDef I2S_MClockOutput;       /**< Specify the I2S MCLK output frequency.
                                                       This parameter can be a value of @ref I2S_MCLK_Output. */
#endif
} I2S_InitTypeDef;

#if I2S_SUPPORT_TRX_FIFO
/**
 * @brief I2S Data Select.
 */
typedef struct
{
    uint8_t tx_channel_map[4];     /**< I2S Tx channel map. */
    uint8_t rx_fifo_map[4];        /**< I2S Rx FIFO map. */
} I2S_DataSelTypeDef;
#endif

/** @} */ /* End of group I2S_Exported_Types */

/**
 * @defgroup I2S_Exported_Functions I2S Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the I2S peripheral registers to their default reset values.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     I2S_DeInit(I2S0);
 * }
 * @endcode
 */
void I2S_DeInit(I2S_TypeDef *I2Sx);

/**
 * @brief Initialize the I2S peripheral according to the specified parameters in the I2S_InitStruct.
 *
 * @param[in] I2Sx            Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] I2S_InitStruct  Pointer to a I2S_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLOCK_SRC_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_CHANNEL_STEREO;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * @endcode
 */
void I2S_Init(I2S_TypeDef *I2Sx, I2S_InitTypeDef *I2S_InitStruct);

/**
 * @brief Fill each I2S_InitStruct member with its default value.
 *
 * @param[in] I2S_InitStruct  Pointer to an I2S_InitTypeDef structure which will be initialized.
 *
 * @note The default settings for the I2S_InitStruct member are shown in the following table:
 *         | I2S_InitStruct member        | Default value                        |
 *         |:----------------------------:|:------------------------------------:|
 *         | I2S_ClockSource              | @ref I2S_CLOCK_SRC_40M               |
 *         | I2S_Scheme                   | @ref I2S_SCHEME_SEPARATE             |
 *         | I2S_TxBClockMi               | 0x271                                |
 *         | I2S_TxBClockNi               | 0x10                                 |
 *         | I2S_TxBClockDiv              | 0x3F                                 |
 *         | I2S_RxBClockMi               | 0x271                                |
 *         | I2S_RxBClockNi               | 0x10                                 |
 *         | I2S_RxBClockDiv              | 0x3F                                 |
 *         | I2S_DeviceMode               | @ref I2S_DEVICE_MODE_MASTER          |
 *         | I2S_TxChannelType            | @ref I2S_CHANNEL_MONO                |
 *         | I2S_RxChannelType            | @ref I2S_CHANNEL_MONO                |
 *         | I2S_TxChannelSequence        | @ref I2S_CH_SEQ_L_R                  |
 *         | I2S_RxChannelSequence        | @ref I2S_CH_SEQ_L_R                  |
 *         | I2S_TxDataFormat             | @ref I2S_DATA_FORMAT_I2S             |
 *         | I2S_RxDataFormat             | @ref I2S_DATA_FORMAT_I2S             |
 *         | I2S_TxBitSequence            | @ref I2S_MSB_FIRST                   |
 *         | I2S_RxBitSequence            | @ref I2S_MSB_FIRST                   |
 *         | I2S_TxDataWidth              | @ref I2S_WIDTH_16BITS                |
 *         | I2S_RxDataWidth              | @ref I2S_WIDTH_16BITS                |
 *         | I2S_TxChannelWidth           | @ref I2S_WIDTH_32BITS                |
 *         | I2S_RxChannelWidth           | @ref I2S_WIDTH_32BITS                |
 *         | I2S_TxFIFOSel                | @ref I2S_FIFO_USE_0_REG_0            |
 *         | I2S_RxFIFOSel                | @ref I2S_FIFO_USE_0_REG_0            |
 *         | I2S_TxWaterlevel             | 16                                   |
 *         | I2S_RxWaterlevel             | 16                                   |
 *         | I2S_BClockFixEn              | DISABLE                              |
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLOCK_SRC_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_CHANNEL_STEREO;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * @endcode
 */
void I2S_StructInit(I2S_InitTypeDef *I2S_InitStruct);

/**
 * @brief Enable or disable the selected I2S mode.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] I2S_Mode  Selected I2S operation mode.
 *                      This parameter can be the following values:
 *                      - I2S_MODE_TX: Transmission mode.
 *                      - I2S_MODE_RX: Receiving mode.
 * @param[in] NewState  New state of the operation mode.
 *                      - ENABLE: Enable the specified mode of I2S.
 *                      - DISABLE: Disable the specified mode of I2S.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_i2s_init(void)
 * {
 *     RCC_ClockCmd(I2S_CLOCK, ENABLE);
 *
 *     I2S_InitTypeDef I2S_InitStruct;
 *
 *     I2S_StructInit(&I2S_InitStruct);
 *     I2S_InitStruct.I2S_ClockSource      = I2S_CLOCK_SRC_40M;
 *     I2S_InitStruct.I2S_BClockMi         = 0x271;
 *     I2S_InitStruct.I2S_BClockNi         = 0x10;
 *     I2S_InitStruct.I2S_DeviceMode       = I2S_DEVICE_MODE_MASTER;
 *     I2S_InitStruct.I2S_ChannelType      = I2S_CHANNEL_STEREO;
 *     I2S_InitStruct.I2S_DataWidth        = I2S_WIDTH_16BITS;
 *     I2S_InitStruct.I2S_DataFormat       = I2S_DATA_FORMAT_I2S;
 *     I2S_Init(I2S0, &I2S_InitStruct);
 *     I2S_Cmd(I2S0, I2S_MODE_TX, ENABLE);
 * }
 * @endcode
 */
void I2S_Cmd(I2S_TypeDef *I2Sx, I2SMode_TypeDef I2S_Mode, FunctionalState NewState);

/**
 * @brief Enable or disable the specified I2S interrupt source.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] I2S_INT   Specify the specified interrupt of I2S.
 *                      This parameter can be the following values, refer to @ref I2S_Interrupt_Definition.
 *                      - I2S_INT_TX_IDLE: Transmit idle interrupt source.
 *                      - I2S_INT_RF_EMPTY: Receive FIFO empty interrupt source.
 *                      - I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt source.
 *                      - I2S_INT_RF_FULL: Receive FIFO full interrupt source.
 *                      - I2S_INT_TF_FULL: Transmit FIFO full interrupt source.
 *                      - I2S_INT_RX_READY: Ready to receive interrupt source.
 *                      - I2S_INT_TX_READY: Ready to transmit interrupt source.
 * @param[in] newState  New state of the specified I2S interrupt.
 *                      - ENABLE: Enable the specified interrupt of I2S.
 *                      - DISABLE: Disable the specified interrupt of I2S.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_INTConfig(I2S0, I2S_INT_TF_EMPTY, ENABLE);
 * }
 * @endcode
 */
void I2S_INTConfig(I2S_TypeDef *I2Sx, uint32_t I2S_INT, FunctionalState newState);

/**
 * @brief Get the specified I2S interrupt status.
 *
 * @param[in] I2Sx     Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] I2S_INT  Specify the specified interrupt of I2S.
 *                     This parameter can be one of the following values, refer to @ref I2S_Interrupt_Definition.
 *                     - I2S_INT_TX_IDLE: Transmit idle interrupt.
 *                     - I2S_INT_RF_EMPTY: Receive FIFO empty interrupt.
 *                     - I2S_INT_TF_EMPTY: Transmit FIFO empty interrupt.
 *                     - I2S_INT_RF_FULL: Receive FIFO full interrupt.
 *                     - I2S_INT_TF_FULL: Transmit FIFO full interrupt.
 *                     - I2S_INT_RX_READY: Ready to receive interrupt.
 *                     - I2S_INT_TX_READY: Ready to transmit interrupt.
 *
 * @return The status of I2S specified interrupt.
 * @retval SET  The interrupt status of I2S is set.
 * @retval RESET  The interrupt status of I2S has not been set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     ITStatus int_status = I2S_GetINTStatus(I2S0, I2S_INT_TF_EMPTY);
 * }
 * @endcode
 */
ITStatus I2S_GetINTStatus(I2S_TypeDef *I2Sx, uint32_t I2S_INT);

/**
 * @brief Clear the I2S interrupt pending bit.
 *
 * @param[in] I2Sx           Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] I2S_CLEAR_INT  Specify the interrupt pending bit to clear.
 *                           This parameter can be any combination of the following values:
 *                           - I2S_CLEAR_INT_RX_READY: Clear ready to receive interrupt.
 *                           - I2S_CLEAR_INT_TX_READY: Clear ready to transmit interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_ClearINTPendingBit(I2S0, I2S_CLEAR_INT_RX_READY);
 * }
 * @endcode
 */
void I2S_ClearINTPendingBit(I2S_TypeDef *I2Sx, uint32_t I2S_CLEAR_INT);

/**
 * @brief Transmit a data through the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] Data  Data to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SendData(I2S0, 0x02);
 * }
 * @endcode
 */
void I2S_SendData(I2S_TypeDef *I2Sx, uint32_t Data);

/**
 * @brief Receive data by the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return Return the most recent received data.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint32_t data = I2S_ReceiveFIFOData(I2S0);
 * }
 * @endcode
 */
uint32_t I2S_ReceiveFIFOData(I2S_TypeDef *I2Sx);

/**
 * @brief Get transmit FIFO free length by the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return The free length of transmit FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t data_len = I2S_GetTxFIFOFreeLen(I2S0);
 * }
 * @endcode
 */
uint8_t I2S_GetTxFIFOFreeLen(I2S_TypeDef *I2Sx);

/**
 * @brief Get receive FIFO data length by the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return The data length of the receive FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t data_len = I2S_GetRxFIFOLen(I2S0);
 * }
 * @endcode
 */
uint8_t I2S_GetRxFIFOLen(I2S_TypeDef *I2Sx);

/**
 * @brief Get the send error counter value by the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return The send error counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t conter = I2S_GetTxErrCnt(I2S0);
 * }
 * @endcode
 */
uint8_t I2S_GetTxErrCnt(I2S_TypeDef *I2Sx);

/**
 * @brief Get the reception error counter value by the I2Sx peripheral.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return The reception error counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     uint8_t conter = I2S_GetRxErrCnt(I2S0);
 * }
 * @endcode
 */
uint8_t I2S_GetRxErrCnt(I2S_TypeDef *I2Sx);

/**
 * @brief Swap audio data bytes sequence that is sent by the I2Sx peripheral.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of the bytes sequence.
 *                      - ENABLE: Enable swapping of the sent audio data byte sequence.
 *                      - DISABLE: Disable swapping of the sent audio data byte sequence.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapBytesForSend(I2S0, ENABLE);
 * }
 * @endcode
 */
void I2S_SwapBytesForSend(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * @brief Swap audio data bytes sequence that is read by the I2Sx peripheral.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of the bytes sequence.
 *                      - ENABLE: Enable the swapping of the audio data byte sequence that is read.
 *                      - DISABLE: Disable the swapping of the audio data byte sequence that is read.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapBytesForRead(I2S0, ENABLE);
 * }
 * @endcode
 */
void I2S_SwapBytesForRead(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * @brief Swap audio channel data that is sent by the I2Sx peripheral.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of the left and right channel data sequence.
 *                      - ENABLE: Enable swapping of the sent audio channel data sequence.
 *                      - DISABLE: Disable swapping of the sent audio channel data sequence.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapLRChDataForSend(I2S0, ENABLE);
 * }
 * @endcode
 */
void I2S_SwapLRChDataForSend(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * @brief Swap audio channel data that is read by the I2Sx peripheral.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of the left and right channel data sequence.
 *                      - ENABLE: Enable the swapping of the audio channel data sequence that is read.
 *                      - DISABLE: Disable the swapping of the audio channel data sequence that is read.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_SwapLRChDataForRead(I2S0, ENABLE);
 * }
 * @endcode
 */
void I2S_SwapLRChDataForRead(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * @brief MCLK output selection which can be from I2S0 or I2S1.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_MCLKOutputSelectCmd(I2S0);
 * }
 * @endcode
 */
void I2S_MCLKOutputSelectCmd(I2S_TypeDef *I2Sx);

/**
 * @brief I2S0 communication selection which can be from internal codec or external codec.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of I2S0 communication selection.
 *                      - ENABLE: I2S communication selects the external codec.
 *                      - DISABLE: I2S communication selects the internal codec.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_WithExtCodecCmd(ENABLE);
 * }
 * @endcode
 */
void I2S_WithExtCodecCmd(I2S_TypeDef *I2Sx, FunctionalState NewState);

/**
 * @brief Configure the BCLK frequency.
 *
 * @param[in] I2Sx          Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] dir           Selected I2S operation mode.
 *                          This parameter can be the following values:
 *                          - I2S_MODE_TX: Transmission mode.
 *                          - I2S_MODE_RX: Receiving mode.
 * @param[in] I2S_BClockMi  Mi factor for BCLK frequency calculation: BCLK = 40MHz * (Ni / Mi).
 * @param[in] I2S_BClockNi  Ni factor for BCLK frequency calculation.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_UpdateBClk(I2S0, I2S_MODE_TX, 0x271, 0x10);
 * }
 * @endcode
 */
void I2S_UpdateBClk(I2S_TypeDef *I2Sx, uint32_t dir, uint16_t I2S_BClockMi,
                    uint16_t I2S_BClockNi);
#if I2S_SUPPORT_TRX_INDEPENDENT_CONTROL
/**
 * @brief Get Tx BCLK clock status.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return Execution status.
 * @retval SET  BCLK is updating.
 * @retval RESET  BCLK update is done.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GetTxBClkStatus(I2S0);
 * }
 * @endcode
 */
FlagStatus I2S_GetTxBClkStatus(I2S_TypeDef *I2Sx);

/**
 * @brief Get Rx BCLK clock status.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return Execution status.
 * @retval SET  BCLK is updating.
 * @retval RESET  BCLK update is done.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GetRxBClkStatus(I2S0);
 * }
 * @endcode
 */
FlagStatus I2S_GetRxBClkStatus(I2S_TypeDef *I2Sx);

#else
/**
 * @brief Get BCLK clock status.
 *
 * @param[in] I2Sx  Selected I2S peripheral. Refer to @ref I2S_Declaration.
 *
 * @return Execution status.
 * @retval SET  BCLK is updating.
 * @retval RESET  BCLK update is done.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     FlagStatus status = I2S_GetBClkStatus(I2S0);
 * }
 * @endcode
 */
FlagStatus I2S_GetBClkStatus(I2S_TypeDef *I2Sx);

#if (I2S_SUPPORT_AUTO_CLOCK == 1)
/**
 * @brief Enable or disable the I2S clock auto mode.
 *
 * @param[in] I2Sx      Selected I2S peripheral. Refer to @ref I2S_Declaration.
 * @param[in] NewState  New state of the I2S clock auto mode.
 *                      - ENABLE: Enable the I2S clock auto mode.
 *                      - DISABLE: Disable the I2S clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void i2s_demo(void)
 * {
 *     I2S_ClockAutoModeCmd(I2S0, ENABLE);
 * }
 * @endcode
 */
void I2S_ClockAutoModeCmd(I2S_TypeDef *I2Sx, FunctionalState NewState);
#endif

#endif
/** @} */ /* End of group I2S_Exported_Functions */

/** @} */ /* End of group I2S_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_I2S_H */