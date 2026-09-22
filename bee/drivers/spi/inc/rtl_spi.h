/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_SPI_H
#define RTL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "spi/src/device/rtl87x2g/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "spi/src/device/rtl87x3d/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "spi/src/device/rtl87x2j/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "spi/src/device/rtl87x3j/rtl_spi_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "spi/src/device/rtl87x3k/rtl_spi_def.h"
#endif

/**
 * @defgroup SPI_DRIVER DRIVER
 * @ingroup SPI
 * @brief Serial Peripheral Interface (SPI) driver.
 * @{
 */
/**
 * @defgroup SPI_Exported_Constants SPI Exported Constants
 * @{
 */

/**
 * @defgroup SPI_CLOCK_SPEED SPI Clock Speed
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && \
                                   ((SPEED) <= 40000000))
/** @} */ /* End of group SPI_CLOCK_SPEED */

/**
 * @defgroup SPI_DIRECTION SPI Direction
 * @{
 */

/**
 * @brief SPI data direction mode.
 */
typedef enum
{
    SPI_DIRECTION_FULLDUPLEX = 0x00, /**< Data can be transmitted and received at the same time. */
    SPI_DIRECTION_TXONLY     = 0x01, /**< Data can only be transmitted at a time. */
    SPI_DIRECTION_RXONLY     = 0x02, /**< Data can only be received at a time. */
    SPI_DIRECTION_EEPROM     = 0x03, /**< Send data first to read target numbers of data. */
} SPIDirection_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_DIRECTION_FULLDUPLEX) || \
                                     ((MODE) == SPI_DIRECTION_TXONLY) || \
                                     ((MODE) == SPI_DIRECTION_RXONLY) || \
                                     ((MODE) == SPI_DIRECTION_EEPROM))
/** @} */ /* End of group SPI_DIRECTION */

/**
 * @defgroup SPI_DATA_SIZE SPI Data Size
 * @{
 */

/**
 * @brief SPI data size.
 */
typedef enum
{
    SPI_DATA_SIZE_4b  = 0x03,     /**< The data frame size is programmed to 4bits. */
    SPI_DATA_SIZE_5b  = 0x04,     /**< The data frame size is programmed to 5bits. */
    SPI_DATA_SIZE_6b  = 0x05,     /**< The data frame size is programmed to 6bits. */
    SPI_DATA_SIZE_7b  = 0x06,     /**< The data frame size is programmed to 7bits. */
    SPI_DATA_SIZE_8b  = 0x07,     /**< The data frame size is programmed to 8bits. */
    SPI_DATA_SIZE_9b  = 0x08,     /**< The data frame size is programmed to 9bits. */
    SPI_DATA_SIZE_10b = 0x09,     /**< The data frame size is programmed to 10bits. */
    SPI_DATA_SIZE_11b = 0x0a,     /**< The data frame size is programmed to 11bits. */
    SPI_DATA_SIZE_12b = 0x0b,     /**< The data frame size is programmed to 12bits. */
    SPI_DATA_SIZE_13b = 0x0c,     /**< The data frame size is programmed to 13bits. */
    SPI_DATA_SIZE_14b = 0x0d,     /**< The data frame size is programmed to 14bits. */
    SPI_DATA_SIZE_15b = 0x0e,     /**< The data frame size is programmed to 15bits. */
    SPI_DATA_SIZE_16b = 0x0f,     /**< The data frame size is programmed to 16bits. */
#if (SPI_SUPPORT_DFS_4BIT_TO_16BIT == 0)
    SPI_DATA_SIZE_17b = 0x10,     /**< The data frame size is programmed to 17bits. */
    SPI_DATA_SIZE_18b = 0x11,     /**< The data frame size is programmed to 18bits. */
    SPI_DATA_SIZE_19b = 0x12,     /**< The data frame size is programmed to 19bits. */
    SPI_DATA_SIZE_20b = 0x13,     /**< The data frame size is programmed to 20bits. */
    SPI_DATA_SIZE_21b = 0x14,     /**< The data frame size is programmed to 21bits. */
    SPI_DATA_SIZE_22b = 0x15,     /**< The data frame size is programmed to 22bits. */
    SPI_DATA_SIZE_23b = 0x16,     /**< The data frame size is programmed to 23bits. */
    SPI_DATA_SIZE_24b = 0x17,     /**< The data frame size is programmed to 24bits. */
    SPI_DATA_SIZE_25b = 0x18,     /**< The data frame size is programmed to 25bits. */
    SPI_DATA_SIZE_26b = 0x19,     /**< The data frame size is programmed to 26bits. */
    SPI_DATA_SIZE_27b = 0x1A,     /**< The data frame size is programmed to 27bits. */
    SPI_DATA_SIZE_28b = 0x1B,     /**< The data frame size is programmed to 28bits. */
    SPI_DATA_SIZE_29b = 0x1C,     /**< The data frame size is programmed to 29bits. */
    SPI_DATA_SIZE_30b = 0x1D,     /**< The data frame size is programmed to 30bits. */
    SPI_DATA_SIZE_31b = 0x1E,     /**< The data frame size is programmed to 31bits. */
    SPI_DATA_SIZE_32b = 0x1F,     /**< The data frame size is programmed to 32bits. */
#endif
} SPIDataSize_TypeDef;

#if (SPI_SUPPORT_DFS_4BIT_TO_16BIT == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DATA_SIZE_4b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_5b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_6b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_7b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_8b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_9b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_10b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_11b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_12b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_13b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_14b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_15b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_16b))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DATA_SIZE_4b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_5b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_6b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_7b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_8b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_9b)  || \
                                   ((DATASIZE) == SPI_DATA_SIZE_10b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_11b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_12b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_13b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_14b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_15b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_16b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_17b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_18b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_19b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_20b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_21b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_22b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_23b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_24b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_25b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_26b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_27b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_28b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_29b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_30b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_31b) || \
                                   ((DATASIZE) == SPI_DATA_SIZE_32b))
#endif

/** @} */ /* End of group SPI_DATA_SIZE */

/**
 * @defgroup SPI_CLOCK_POLARITY SPI Clock Polarity
 * @{
 */

/**
 * @brief SPI clock polarity.
 */
typedef enum
{
    SPI_CPOL_LOW = 0x00,  /**< Inactive state of serial clock is low. */
    SPI_CPOL_HIGH = 0x01, /**< Inactive state of serial clock is high. */
} SPIClockPolarity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_LOW) || \
                           ((CPOL) == SPI_CPOL_HIGH))
/** @} */ /* End of group SPI_CLOCK_POLARITY */

/**
 * @defgroup SPI_CLOCK_PHASE SPI Clock Phase
 * @{
 */

/**
 * @brief SPI clock phase.
 */
typedef enum
{
    SPI_CPHA_1EDGE = 0x00, /**< Serial clock toggles in middle of first data bit. */
    SPI_CPHA_2EDGE = 0x01, /**< Serial clock toggles at start of first data bit. */
} SPIClockPhase_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1EDGE) || \
                           ((CPHA) == SPI_CPHA_2EDGE))
/** @} */ /* End of group SPI_CLOCK_PHASE */

/**
 * @defgroup SPI_BAUDRATE_PRESCALER SPI BaudRate Prescaler
 * @{
 */

/**
 * @brief SPI baudrate prescaler value.
 */
typedef enum
{
    SPI_BAUDRATE_PRESCALER_2   = 0x02,   /**< SPI baudrate prescaler is 2. */
    SPI_BAUDRATE_PRESCALER_4   = 0x04,   /**< SPI baudrate prescaler is 4. */
    SPI_BAUDRATE_PRESCALER_6   = 0x06,   /**< SPI baudrate prescaler is 6. */
    SPI_BAUDRATE_PRESCALER_8   = 0x08,   /**< SPI baudrate prescaler is 8. */
    SPI_BAUDRATE_PRESCALER_10  = 0x0A,   /**< SPI baudrate prescaler is 10. */
    SPI_BAUDRATE_PRESCALER_12  = 0x0C,   /**< SPI baudrate prescaler is 12. */
    SPI_BAUDRATE_PRESCALER_14  = 0x0E,   /**< SPI baudrate prescaler is 14. */
    SPI_BAUDRATE_PRESCALER_16  = 0x10,   /**< SPI baudrate prescaler is 16. */
    SPI_BAUDRATE_PRESCALER_32  = 0x20,   /**< SPI baudrate prescaler is 32. */
    SPI_BAUDRATE_PRESCALER_64  = 0x40,   /**< SPI baudrate prescaler is 64. */
    SPI_BAUDRATE_PRESCALER_128 = 0x80,   /**< SPI baudrate prescaler is 128. */
    SPI_BAUDRATE_PRESCALER_256 = 0x100,  /**< SPI baudrate prescaler is 256. */
} SPIBaudRatePrescaler_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFFF)
/** @} */ /* End of group SPI_BAUDRATE_PRESCALER */

#if (SPI_FIXED_FRAME_FORMAT == 0)
/**
 * @defgroup SPI_FRAME_FORMAT SPI Frame Format
 * @{
 */

/**
 * @brief SPI frame format.
 */
typedef enum
{
    SPI_FRAME_MOTOROLA      = 0x00, /**< Standard SPI frame format. */
    SPI_FRAME_TI_SSP        = 0x01, /**< Texas instruments SSP frame format. */
    SPI_FRAME_NS_MICROWIRE  = 0x02, /**< National microwire frame format. */
    SPI_FRAME_RESERVE       = 0x03, /**< Reserved value. */
} SPIFrameFormat_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_FRAME_FORMAT(FRAME) (((FRAME) == SPI_FRAME_MOTOROLA) || \
                                    ((FRAME) == SPI_FRAME_TI_SSP) || \
                                    ((FRAME) == SPI_FRAME_NS_MICROWIRE) || \
                                    ((FRAME) == SPI_FRAME_RESERVE))
/** @} */ /* End of group SPI_FRAME_FORMAT */
#endif

/**
 * @defgroup SPI_DMA_TRANSFER_REQUEST SPI DMA Transfer Request
 * @{
 */

/**
 * @brief SPI DMA transfer request.
 */
typedef enum
{
    SPI_DMA_REQ_RX = 0x01, /**< RX FIFO DMA transfer request. */
    SPI_DMA_REQ_TX = 0x02, /**< TX FIFO DMA transfer request. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
    SPI_WRAP_DMA_REQ_TX = 0x03, /**< Wrap mode TX FIFO DMA transfer request. */
#endif
} SPIDMARequests_TypeDef;

#if (SPI_SUPPORT_WRAP_MODE == 0)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_DMAREQ(REQ) (((REQ) == SPI_DMA_REQ_RX) || \
                            ((REQ) == SPI_DMA_REQ_TX))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_DMAREQ(REQ) (((REQ) == SPI_DMA_REQ_RX) || \
                            ((REQ) == SPI_DMA_REQ_TX) || \
                            ((REQ) == SPI_WRAP_DMA_REQ_TX))
#endif

/** @} */ /* End of group SPI_DMA_TRANSFER_REQUEST */

/**
 * @defgroup SPI_FLAGS SPI Flags
 * @{
 */
#define SPI_FLAG_BUSY                   BIT0  /**< SPI Busy flag. Set if it is actively transferring data. Reset if it is idle or disabled. */
#define SPI_FLAG_TFNF                   BIT1  /**< Transmit FIFO not full flag. Set if transmit FIFO is not full. */
#define SPI_FLAG_TFE                    BIT2  /**< Transmit FIFO empty flag. Set if transmit FIFO is empty. */
#define SPI_FLAG_RFNE                   BIT3  /**< Receive FIFO not empty flag. Set if receive FIFO is not empty. */
#define SPI_FLAG_RFF                    BIT4  /**< Receive FIFO full flag. Set if the receive FIFO is completely full. */
#define SPI_FLAG_TXE                    BIT5  /**< Transmission error flag. Set if the transmit FIFO is empty when a transfer is started in slave mode. */
#define SPI_FLAG_DCOL                   BIT6  /**< Data collision error flag. Set if it is actively transmitting in master mode when another master selects this device as a slave. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
#define SPI_FLAG_WRAP_CS_EN             BIT8  /**< Wrap mode CS enable flag. */
#define SPI_FLAG_WRAP_TFNF              BIT9  /**< Wrap mode transmit FIFO not full flag. */
#define SPI_FLAG_WRAP_TFE               BIT10 /**< Wrap mode transmit FIFO empty flag. */
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY) || \
                                 ((FLAG) == SPI_FLAG_WRAP_CS_EN) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFNF) || \
                                 ((FLAG) == SPI_FLAG_WRAP_TFE))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_GET_FLAG(FLAG)   (((FLAG) == SPI_FLAG_DCOL) || \
                                 ((FLAG) == SPI_FLAG_TXE) || \
                                 ((FLAG) == SPI_FLAG_RFF) || \
                                 ((FLAG) == SPI_FLAG_RFNE) || \
                                 ((FLAG) == SPI_FLAG_TFE) || \
                                 ((FLAG) == SPI_FLAG_TFNF) || \
                                 ((FLAG) == SPI_FLAG_BUSY))
#endif

/** @} */ /* End of group SPI_FLAGS */

/**
 * @defgroup SPI_INTERRUPT SPI Interrupt
 * @{
 */
#define SPI_INT_TXE                    BIT0 /**< Transmit FIFO threshold interrupt. Triggered when the transmit FIFO level is less than or equal to the threshold. */
#define SPI_INT_TXO                    BIT1 /**< Transmit FIFO overflow interrupt. */
#define SPI_INT_RXU                    BIT2 /**< Receive FIFO underflow interrupt. */
#define SPI_INT_RXO                    BIT3 /**< Receive FIFO overflow interrupt. */
#define SPI_INT_RXF                    BIT4 /**< Receive FIFO threshold interrupt. Triggered when the receive FIFO level is greater than or equal to the threshold. */
#define SPI_INT_MST                    BIT5 /**< Multi-master contention interrupt. (master only) */
#define SPI_INT_FAE                    BIT5 /**< The data of slave RX does not match DFS. (slave only) */
#define SPI_INT_TUF                    BIT6 /**< Transmit FIFO underflow interrupt. (slave only) */
#define SPI_INT_RIG                    BIT7 /**< CS rising edge detect interrupt. (slave only) */
#if (SPI_SUPPORT_WRAP_MODE == 1)
#define SPI_INT_WRAP_TXE               BIT8 /**< Wrap mode transmit FIFO empty interrupt. */
#define SPI_INT_WRAP_TXO               BIT9 /**< Wrap mode transmit FIFO overflow interrupt. */
#define SPI_INT_WRAP_TXD               BIT10 /**< Wrap mode transmit done interrupt. */
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) || \
                              ((IT) == SPI_INT_WRAP_TXE) || \
                              ((IT) == SPI_INT_WRAP_TXO) || \
                              ((IT) == SPI_INT_WRAP_TXD))
#else
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_CONFIG_IT(IT) (((IT) == SPI_INT_TXE) || \
                              ((IT) == SPI_INT_TXO) || \
                              ((IT) == SPI_INT_RXU) || \
                              ((IT) == SPI_INT_RXO) || \
                              ((IT) == SPI_INT_RXF) || \
                              ((IT) == SPI_INT_MST) || \
                              ((IT) == SPI_INT_FAE) || \
                              ((IT) == SPI_INT_TUF) || \
                              ((IT) == SPI_INT_RIG) )
#endif

/** @} */ /* End of group SPI_INTERRUPT */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)

/**
 * @defgroup SPI_MODE SPI Mode
 * @{
 */

/**
 * @brief SPI operating mode.
 */
typedef enum
{
    SPI_MODE_MASTER = ((uint16_t)0x0104), /**< SPI device operating mode as master. */
    SPI_MODE_SLAVE  = ((uint16_t)0x0000)  /**< SPI device operating mode as slave. */
} SPIMode_Typedef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_MODE(MODE) (((MODE) == SPI_MODE_MASTER) || \
                           ((MODE) == SPI_MODE_SLAVE))
/** @} */ /* End of group SPI_MODE */
#endif

#if (SPI_SUPPORT_WRAP_MODE == 1)
/**
 * @defgroup SPI_WRAP_CS_CLOCK_DIVIDER SPI Wrap CS Clock Divider
 * @{
 */

/**
 * @brief SPI wrap mode CS clock divider.
 */
typedef enum
{
    SPI_WRAP_CS_CLOCK_DIV_1 = 0x0,   /**< Wrap CS clock divider is 1. */
    SPI_WRAP_CS_CLOCK_DIV_2 = 0x1,   /**< Wrap CS clock divider is 2. */
    SPI_WRAP_CS_CLOCK_DIV_4 = 0x2,   /**< Wrap CS clock divider is 4. */
    SPI_WRAP_CS_CLOCK_DIV_8 = 0x3,   /**< Wrap CS clock divider is 8. */
    SPI_WRAP_CS_CLOCK_DIV_16 = 0x4,  /**< Wrap CS clock divider is 16. */
    SPI_WRAP_CS_CLOCK_DIV_32 = 0x5,  /**< Wrap CS clock divider is 32. */
    SPI_WRAP_CS_CLOCK_DIV_64 = 0x6,  /**< Wrap CS clock divider is 64. */
    SPI_WRAP_CS_CLOCK_DIV_128 = 0x7, /**< Wrap CS clock divider is 128. */
    SPI_WRAP_CS_CLOCK_DIV_256 = 0x8, /**< Wrap CS clock divider is 256. */
} SPIWrapCSClockDiv_TypeDef;

/** @} */ /* End of group SPI_WRAP_CS_CLOCK_DIVIDER */

#endif

/**
 * @defgroup SPI_ACTION_EVENT SPI Action Event
 * @{
 */
#if (SPI_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief SPI action/event type definition.
 */
typedef enum
{
    SPI_ACTION_START  = 0, /**< SPI action start. */
    SPI_EVENT_START = 1,   /**< SPI event start. */
    SPI_EVENT_END   = 2,   /**< SPI event end. */
} SPIActionEvent_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI_ACTION_EVENT(AE) (((AE) == SPI_ACTION_START) || \
                                 ((AE) == SPI_EVENT_START) || \
                                 ((AE) == SPI_EVENT_END))
#endif

/** @} */ /* End of group SPI_ACTION_EVENT */

#if (SPI_SUPPORT_REPEAT_MODE == 1)
/**
 * @defgroup SPI_REPEAT_REG_MODE SPI Repeat Register Mode
 * @{
 */

/**
 * @brief SPI repeat mode type definition.
 */
typedef enum
{
    SPI_REPEAT_WRAPPER_FIFO = 0x00, /**< Repeat data output from wrapper FIFO. */
    SPI_REPEAT_NORMAL_FIFO = 0x01,  /**< Repeat data output from SPI data register. */
} SPIRepeatMode_TypeDef;

/** @} */ /* End of group SPI_REPEAT_REG_MODE */

/**
 * @defgroup SPI_REPEAT_TRANSFER_SIZE SPI Repeat Transfer Size
 * @{
 */

/**
 * @brief SPI repeat transfer size type definition.
 */
typedef enum
{
    SPI_REPEAT_SIZE_8BIT = 0x00,  /**< 8bit mode. */
    SPI_REPEAT_SIZE_16BIT = 0x01, /**< 16bit mode. */
} SPIRepeatSize_TypeDef;

/** @} */ /* End of group SPI_REPEAT_TRANSFER_SIZE */

#endif

/** @} */ /* End of group SPI_Exported_Constants */

/**
 * @defgroup SPI_Exported_Types SPI Exported Types
 * @{
 */

/**
 * @brief SPI init structure definition.
 *
 */
typedef struct
{
    SPIDirection_TypeDef SPI_Direction;        /**< Specifies the SPI data transfer direction.
                                                    This parameter can be a value of @ref SPI_DIRECTION. */
#if (SPI_SUPPORT_WRAP_MODE == 1)
    uint32_t SPI_TXNDF;                        /**< Specifies the number of data frames to be continuously transmitted
                                                    in TxOnly or FullDuplex mode, from 1 to 65536.
                                                    This parameter is only valid in wrap mode. */

    FunctionalState SPI_CSHighActiveEn;        /**< Specifies whether to enable CS high active.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_WrapModeEn;           /**< Specifies whether to enable SPI wrap mode.
                                                   Only SPI0 and SPI1 support wrap mode.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_WrapModeDMAEn;      /**< Specifies whether to enable SPI wrap mode TX DMA.
                                                 This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  SPI_WrapTxThresholdLevel;      /**< Specifies the wrapper transmit FIFO Threshold.
                                                This parameter can be a value equal or less than SPI_WRAPPER_TX_FIFO_SIZE. */

    uint8_t  SPI_WrapTxWaterlevel;           /**< Specifies the DMA TX water level in wrap mode.
                                                  The best value is SPI_WRAPPER_TX_FIFO_SIZE - Tx DMA MSize. */

    SPIWrapCSClockDiv_TypeDef SPI_WrapCSClockDiv;  /**< Specifies the CS clock divider.
                                                  This parameter can be a value of @ref SPI_WRAP_CS_CLOCK_DIVIDER. */

    uint8_t SPI_WrapCSHoldDlyCount;             /**< Specifies the CS hold delay count.
                                                     The hold delay time = cs_divider * (hold_delay_count + 2.5) * 25ns.
                                                     This parameter can be a value from 0 to 15. */
    uint8_t SPI_WrapCSSetupDlyCount;            /**< Specifies the CS setup delay count.
                                                     The setup delay time = cs_divider * (setup_delay_count + 1) * 25ns.
                                                     This parameter can be a value from 0 to 15. */
#endif

    uint32_t SPI_RXNDF;                        /**< Specifies the number of data frames to be received
                                                    in RxOnly or EEPROM mode, from 1 to 65536. */

#if (SPI0_SUPPORT_MASTER_SLAVE == 1)
    SPIMode_Typedef           SPI_Mode;        /**< Specifies the SPI master or slave mode.
                                                    This parameter can be a value of @ref SPI_MODE. */
#endif

    SPIDataSize_TypeDef SPI_DataSize;          /**< Specifies the SPI data size. */

    SPIClockPolarity_TypeDef SPI_CPOL;         /**< Specifies the serial clock steady state. */

    SPIClockPhase_TypeDef SPI_CPHA;            /**< Specifies clock active edge for bit capture. */
#if (SPI_FIXED_FRAME_FORMAT == 0)
    SPIFrameFormat_TypeDef SPI_FrameFormat;    /**< Specifies frame format which serial
                                                    protocol transfers the data. */
#endif
    /**
     * Specifies the speed of SCK clock.
     * SPI Clock Speed = clk source / SPI_ClkDIV.
     * This parameter must be an even number and the minimum value is 2.
     *
     * @note The communication clock is derived from the master clock.
     *       The slave clock does not need to be set.
     */
    uint32_t SPI_BaudRatePrescaler;

#if (SPI_SUPPORT_SWAP == 1)
    FunctionalState SPI_SwapTxBitEn;           /**< Specifies whether to swap SPI Tx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxBitEn;           /**< Specifies whether to swap SPI Rx data bit.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapTxByteEn;          /**< Specifies whether to swap SPI Tx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_SwapRxByteEn;          /**< Specifies whether to swap SPI Rx data byte.
                                                    This parameter can be a value of ENABLE or DISABLE. */
#endif

    FunctionalState
    SPI_ToggleEn;              /**< Enables or disables the Slave Select (CS) line toggle between
                                                    consecutive data frames (valid only when CPHA=0).
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint32_t SPI_TxThresholdLevel;             /**< Specifies the transmit FIFO threshold to trigger interrupt @ref SPI_INT_TXE.
                                                    This parameter can be a value equal or less than SPI_TX_FIFO_SIZE. */

    uint32_t SPI_RxThresholdLevel;             /**< Specifies the receive FIFO threshold to trigger interrupt @ref SPI_INT_RXF.
                                                    This parameter can be a value equal or less than SPI_RX_FIFO_SIZE. */

    FunctionalState SPI_TxDMAEn;               /**< Specifies the Tx DMA mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState SPI_RxDMAEn;               /**< Specifies the Rx DMA mode.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t SPI_TxWaterlevel;                  /**< Specifies the DMA tx water level.
                                                    The best value is SPI_TX_FIFO_SIZE - Tx DMA MSize. */

    uint8_t SPI_RxWaterlevel;                  /**< Specifies the DMA RX water level.
                                                    The best value is Rx DMA MSize - 1. */
} SPI_InitTypeDef;

/** @} */ /* End of group SPI_Exported_Types */

/**
 * @defgroup SPI_Exported_Functions SPI Exported Functions
 * @{
 */

/**
 * @brief Deinitializes the SPIx peripheral registers to their default reset values.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi_init(void)
 * {
 *     SPI_DeInit(SPI0);
 * }
 * @endcode
 */
void SPI_DeInit(SPI_TypeDef *SPIx);

/**
 * @brief Initializes the SPIx peripheral according to the specified
 *          parameters in the SPI_InitStruct.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_InitStruct  Pointer to a SPI_InitTypeDef structure that
 *            contains the configuration information for the specified SPI peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi_init(void)
 * {
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_DIRECTION_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DATA_SIZE_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_HIGH;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2EDGE;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_RXNDF             = 8;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_FRAME_MOTOROLA;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * @endcode
 */
void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct);

/**
 * @brief Fills each SPI_InitStruct member with its default value.
 *
 * @note   The default settings for the SPI_InitStruct member are shown in the following table:
 *         | SPI_InitStruct member      | Default value                  |
 *         |:--------------------------:|:------------------------------:|
 *         | SPI_Direction              | @ref SPI_DIRECTION_FULLDUPLEX  |
 *         | SPI_RXNDF                  | 1                              |
 *         | SPI_Mode                   | @ref SPI_MODE_MASTER           |
 *         | SPI_DataSize               | @ref SPI_DATA_SIZE_8b           |
 *         | SPI_CPOL                   | @ref SPI_CPOL_HIGH             |
 *         | SPI_CPHA                   | @ref SPI_CPHA_2EDGE            |
 *         | SPI_FrameFormat            | @ref SPI_FRAME_MOTOROLA        |
 *         | SPI_BaudRatePrescaler      | 128                            |
 *         | SPI_ToggleEn               | DISABLE                        |
 *         | SPI_TxThresholdLevel       | 1                              |
 *         | SPI_RxThresholdLevel       | 0                              |
 *         | SPI_TxDMAEn                | DISABLE                        |
 *         | SPI_RxDMAEn                | DISABLE                        |
 *         | SPI_TxWaterlevel           | SPI_TX_FIFO_SIZE - 1           |
 *         | SPI_RxWaterlevel           | 1                              |
 *
 * @param[in] SPI_InitStruct  Pointer to a SPI_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi_init(void)
 * {
 *
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_DIRECTION_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DATA_SIZE_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_HIGH;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2EDGE;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_RXNDF             = 8;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_FRAME_MOTOROLA;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 * }
 * @endcode
 */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct);

/**
 * @brief Enables or disables the selected SPI peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPIx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi_init(void)
 * {
 *
 *     RCC_ClockCmd(SPI0_CLOCK, ENABLE);
 *
 *     SPI_InitTypeDef  SPI_InitStruct;
 *     SPI_StructInit(&SPI_InitStruct);
 *
 *     SPI_InitStruct.SPI_Direction   = SPI_DIRECTION_EEPROM;
 *     SPI_InitStruct.SPI_DataSize    = SPI_DATA_SIZE_8b;
 *     SPI_InitStruct.SPI_CPOL        = SPI_CPOL_HIGH;
 *     SPI_InitStruct.SPI_CPHA        = SPI_CPHA_2EDGE;
 *     SPI_InitStruct.SPI_BaudRatePrescaler  = 100;
 *     SPI_InitStruct.SPI_RxThresholdLevel  = 1 - 1;
 *     SPI_InitStruct.SPI_RXNDF             = 8;
 *     SPI_InitStruct.SPI_FrameFormat = SPI_FRAME_MOTOROLA;
 *
 *     SPI_Init(SPI0, &SPI_InitStruct);
 *     SPI_Cmd(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_Cmd(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Transmits the specified number of bytes through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Bytes to be transmitted.
 * @param[in] len  Byte length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint8_t data_buf[] = {0x01,0x02,0x03};
 *     SPI_SendBuffer(SPI0, data_buf, sizeof(data_buf));
 * }
 * @endcode
 */
void SPI_SendBuffer(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len);

/**
 * @brief Transmits the specified number of bytes through the SPIx peripheral without polling.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Bytes to be transmitted.
 * @param[in] len  Byte length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint8_t data_buf[] = {0x01,0x02,0x03};
 *     SPI_SendBufferDirect(SPI0, data_buf, sizeof(data_buf));
 * }
 * @endcode
 */
void SPI_SendBufferDirect(SPI_TypeDef *SPIx, uint8_t *pBuf, uint16_t len);

/**
 * @brief Transmits the specified number of halfwords through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Halfwords to be transmitted.
 * @param[in] len  Halfwords length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint16_t));
 * }
 * @endcode
 */
void SPI_SendHalfWord(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

/**
 * @brief Transmits the specified number of halfwords through the SPIx peripheral without polling.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Halfwords to be transmitted.
 * @param[in] len  Halfwords length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint16_t data_buf[] = {0x0102,0x0203,0x0304};
 *     SPI_SendHalfWordDirect(SPI0, data_buf, sizeof(data_buf)/sizeof(uint16_t));
 * }
 * @endcode
 */
void SPI_SendHalfWordDirect(SPI_TypeDef *SPIx, uint16_t *pBuf, uint16_t len);

#if (SPI_SUPPORT_DFS_4BIT_TO_16BIT == 0)
/**
 * @brief Transmits the specified number of words through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Words to be transmitted.
 * @param[in] len  Word length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWord(SPI0, data_buf, sizeof(data_buf)/sizeof(uint32_t));
 * }
 * @endcode
 */
void SPI_SendWord(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);

/**
 * @brief Transmits the specified number of words through the SPIx peripheral without polling.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] pBuf  Words to be transmitted.
 * @param[in] len  Word length to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint32_t data_buf[] = {0x01020304,0x02030405,0x03040506};
 *     SPI_SendWordDirect(SPI0, data_buf, sizeof(data_buf)/sizeof(uint32_t));
 * }
 * @endcode
 */
void SPI_SendWordDirect(SPI_TypeDef *SPIx, uint32_t *pBuf, uint16_t len);
#endif

/**
 * @brief Enable or disable the specified SPI interrupt source.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_IT  Specifies the SPI interrupt source to be enabled or disabled.
 *            This parameter can be one of the following values, refer to @ref SPI_INTERRUPT.
 *            - SPI_INT_TXE: Transmit FIFO threshold interrupt. Triggered when the transmit FIFO level is less than or equal to the threshold.
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt.
 *            - SPI_INT_RXF: Receive FIFO threshold interrupt. Triggered when the receive FIFO level is greater than or equal to the threshold.
 *            - SPI_INT_MST: Multi-master contention interrupt. (master only)
 *            - SPI_INT_FAE: The data of slave RX does not match DFS. (slave only)
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt. (slave only)
 *            - SPI_INT_RIG: CS rising edge detect interrupt. (slave only)
 * @param[in] NewState  New state of the specified SPI interrupt source.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_INTConfig(SPI0, SPI_INT_RXF, ENABLE);
 * }
 * @endcode
 */
void SPI_INTConfig(SPI_TypeDef *SPIx, uint16_t SPI_IT, FunctionalState NewState);

/**
 * @brief Clear the specified SPI interrupt pending bit.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_IT  Specifies the SPI interrupt to clear.
 *            This parameter can be one of the following values, refer to @ref SPI_INTERRUPT.
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt.
 *            - SPI_INT_MST: Multi-master contention interrupt. (master only)
 *            - SPI_INT_FAE: The data of slave RX does not match DFS. (slave only)
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt. (slave only)
 *            - SPI_INT_RIG: CS rising edge detect interrupt. (slave only)
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_ClearINTPendingBit(SPI0, SPI_INT_RXF);
 * }
 * @endcode
 */
void SPI_ClearINTPendingBit(SPI_TypeDef *SPIx, uint16_t SPI_IT);

/**
 * @brief Transmits a data through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] Data  Data to be transmitted.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint32_t data = 0x01020304;
 *     SPI_SendData(SPI0, data);
 * }
 * @endcode
 */
void SPI_SendData(SPI_TypeDef *SPIx, uint32_t Data);

/**
 * @brief Received data by the SPI peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 *
 * @return The most recent received data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint32_t data = SPI_ReceiveData(SPI0);
 * }
 * @endcode
 */
uint32_t SPI_ReceiveData(SPI_TypeDef *SPIx);

/**
 * @brief Get data length in Tx FIFO through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 *
 * @return Data length in Tx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint8_t data_len = SPI_GetTxFIFOLen(SPI0);
 * }
 * @endcode
 */
uint8_t SPI_GetTxFIFOLen(SPI_TypeDef *SPIx);

/**
 * @brief Get data length in Rx FIFO through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 *
 * @return Data length in Rx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     uint8_t data_len = SPI_GetRxFIFOLen(SPI0);
 * }
 * @endcode
 */
uint8_t SPI_GetRxFIFOLen(SPI_TypeDef *SPIx);

/**
 * @brief Change SPI direction mode.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] dir  Value of direction mode, refer to @ref SPI_DIRECTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetDirection(SPI0, SPI_DIRECTION_EEPROM);
 * }
 * @endcode
 */
void SPI_SetDirection(SPI_TypeDef *SPIx, uint16_t dir);

/**
 * @brief Set read data length in EEPROM mode or RxOnly mode through the SPIx peripheral, which
 *        enables you to receive up to 64 KB of data in a continuous transfer.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] len  Length of read data which can be 1 to 65536.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetReadLen(SPI0, 100);
 * }
 * @endcode
 */
void SPI_SetReadLen(SPI_TypeDef *SPIx, uint16_t len);

/**
 * @brief Set cs number through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] number  Number can be 0 to 2.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetCSNumber(SPI1, 1);
 * }
 * @endcode
 */
void SPI_SetCSNumber(SPI_TypeDef *SPIx, uint8_t number);

/**
 * @brief Check whether the specified SPI interrupt is set.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_IT  Specifies the SPI interrupt to check.
 *            This parameter can be one of the following values, refer to @ref SPI_INTERRUPT.
 *            - SPI_INT_TXE: Transmit FIFO threshold interrupt. Triggered when the transmit FIFO level is less than or equal to the threshold.
 *            - SPI_INT_TXO: Transmit FIFO overflow interrupt.
 *            - SPI_INT_RXU: Receive FIFO underflow interrupt.
 *            - SPI_INT_RXO: Receive FIFO overflow interrupt.
 *            - SPI_INT_RXF: Receive FIFO threshold interrupt. Triggered when the receive FIFO level is greater than or equal to the threshold.
 *            - SPI_INT_MST: Multi-master contention interrupt. (master only)
 *            - SPI_INT_FAE: The data of slave RX does not match DFS. (slave only)
 *            - SPI_INT_TUF: Transmit FIFO underflow interrupt. (slave only)
 *            - SPI_INT_RIG: CS rising edge detect interrupt. (slave only)
 *            - SPI_INT_WRAP_TXE: Wrap mode transmit FIFO empty interrupt.
 *            - SPI_INT_WRAP_TXO: Wrap mode transmit FIFO overflow interrupt.
 *            - SPI_INT_WRAP_TXD: Wrap mode transmit done interrupt.
 *
 * @return The new state of SPI_IT (SET or RESET).
 * @retval SET    The specified SPI interrupt is set.
 * @retval RESET  The specified SPI interrupt is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     ITStatus int_status = SPI_GetINTStatus(SPI0, SPI_INT_RXF);
 * }
 * @endcode
 */
ITStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, uint32_t SPI_IT);

/**
 * @brief Check whether the specified SPI flag is set.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_FLAG  Specifies the SPI flag to check.
 *            This parameter can be one of the following values, refer to @ref SPI_FLAGS.
 *            - SPI_FLAG_DCOL: Data collision error flag. Set if it is actively transmitting in master mode when another master selects this device as a slave.
 *            - SPI_FLAG_TXE: Transmission error flag. Set if the transmit FIFO is empty when a transfer is started in slave mode.
 *            - SPI_FLAG_RFF: Receive FIFO full flag. Set if the receive FIFO is completely full.
 *            - SPI_FLAG_RFNE: Receive FIFO not empty flag. Set if receive FIFO is not empty.
 *            - SPI_FLAG_TFE: Transmit FIFO empty flag. Set if transmit FIFO is empty.
 *            - SPI_FLAG_TFNF: Transmit FIFO not full flag. Set if transmit FIFO is not full.
 *            - SPI_FLAG_BUSY: SPI busy flag. Set if it is actively transferring data. Reset if it is idle or disabled.
 *            - SPI_FLAG_WRAP_CS_EN: Wrap mode CS enable flag.
 *            - SPI_FLAG_WRAP_TFNF: Wrap mode transmit FIFO not full flag.
 *            - SPI_FLAG_WRAP_TFE: Wrap mode transmit FIFO empty flag.
 *
 * @return The new state of SPI_FLAG (SET or RESET).
 * @retval SET    The specified SPI flag is set.
 * @retval RESET  The specified SPI flag is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     FlagStatus flag_status = SPI_GetFlagState(SPI0, SPI_FLAG_TXE);
 *
 * }
 * @endcode
 */
FlagStatus SPI_GetFlagState(SPI_TypeDef *SPIx, uint16_t SPI_FLAG);

/**
 * @brief Enables or disables the SPIx DMA interface.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] SPI_DMAReq  Specifies the SPI DMA transfer request to be enabled or disabled.
 *            This parameter can be one of the following values, refer to @ref SPI_DMA_TRANSFER_REQUEST.
 *            - SPI_DMA_REQ_TX: TX FIFO DMA transfer request.
 *            - SPI_DMA_REQ_RX: RX FIFO DMA transfer request.
 * @param[in] NewState  New state of the selected SPI DMA transfer request.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_DMACmd(SPI0, SPI_DMA_REQ_TX, ENABLE);
 * }
 * @endcode
 */
void SPI_DMACmd(SPI_TypeDef *SPIx, SPIDMARequests_TypeDef SPI_DMAReq,
                FunctionalState NewState);

/**
 * @brief Change SPI speed dynamically.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] prescaler  Value of prescaler.
 *            This parameter must be an even number and the minimum value is 2.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetPrescaler(SPI0, SPI_BAUDRATE_PRESCALER_2);
 * }
 * @endcode
 */
void SPI_SetPrescaler(SPI_TypeDef *SPIx, uint32_t prescaler);

/**
 * @brief Set SPI Rx sample delay.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] delay  Specifies the Rx sample delay, in units of 40 MHz clock cycles. This parameter can be 0 to 255.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetRxSampleDly(SPI0, 1);
 * }
 * @endcode
 */
void SPI_SetRxSampleDly(SPI_TypeDef *SPIx, uint32_t delay);

#if (SPI_SUPPORT_WRAP_MODE == 1)

/**
 * @brief Enables or disables the specified SPI wrap mode start transfer.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPI wrap mode TX transfer.
 *            This parameter can be one of the following values:
 *            - ENABLE: Active the TX FIFO to transfer data.
 *            - DISABLE: Disable the TX FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_WrapModeStartTx(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_WrapModeStartTx(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Whether inverse CS active polarity.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            -  ENABLE: Inverse CS active polarity, which means CS is high active.
 *            -  DISABLE: Not inverse CS active polarity, which means CS is low active.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_InverseCSActivePolarity(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_InverseCSActivePolarity(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Whether drive MOSI low in idle state.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            -  ENABLE: Drive MOSI low in idle state.
 *            -  DISABLE: Not drive MOSI low in idle state, which means MOSI is Hi-Z in idle state.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_DriveMOSILow(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_DriveMOSILow(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Whether enable MOSI pull in idle state.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPIx peripheral.
 *            This parameter can be one of the following values:
 *            -  ENABLE: MOSI is pull down in idle state.
 *            -  DISABLE: MOSI is pull none in idle state.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_PullMOSIEn(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_PullMOSIEn(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Set the TX NDF value for wrap mode.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] tx_ndf  Specifies the number of data frames to be continuously transmitted, from 1 to 65536.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_WrapModeSetTxNdf(SPI0, 100);
 * }
 * @endcode
 */
void SPI_WrapModeSetTxNdf(SPI_TypeDef *SPIx, uint16_t tx_ndf);

/**
 * @brief Clear the wrap mode TX FIFO.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_WrapModeResetTxFIFO(SPI0);
 * }
 * @endcode
 */
void SPI_WrapModeResetTxFIFO(SPI_TypeDef *SPIx);
#endif

#if SPI_SUPPORT_CLOCK_SOURCE_CONFIG
/**
 * @brief Configure the SPI clock.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] ClockSrc  Specifies the SPI clock source, refer to @ref SPI_CLOCK_SOURCE.
 * @param[in] ClockDiv  Specifies the SPI clock divider, refer to @ref SPI_CLOCK_DIVIDER.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetClock(SPI0, SPI_CLOCK_SRC_40M, SPI_CLOCK_DIV_1);
 * }
 * @endcode
 */
void SPI_SetClock(SPI_TypeDef *SPIx, SPIClockSrc_TypeDef ClockSrc, SPIClockDiv_TypeDef ClockDiv);
#endif

#if (SPI_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the SPI RAP mode.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPIx peripheral.
 *            This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_RAPModeCmd(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_RAPModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState);

/**
 * @brief Set the number of command bytes for action.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] num  The number of commands required to transmit.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetActionCmdNum(SPI0, 1);
 * }
 * @endcode
 */
void SPI_SetActionCmdNum(SPI_TypeDef *SPIx, uint8_t num);

/**
 * @brief Set the wait count for action.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] num  The number of SSI clock cycles delayed as wait time between command and data. The unit is 40 MHz clock cycle.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetActionWaitNum(SPI0, 1);
 * }
 * @endcode
 */
void SPI_SetActionWaitNum(SPI_TypeDef *SPIx, uint16_t num);

/**
 * @brief Set the transfer count for action.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] num  The number of RX data to transfer after the command.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetActionTransferNum(SPI0, 1);
 * }
 * @endcode
 */
void SPI_SetActionTransferNum(SPI_TypeDef *SPIx, uint16_t num);

/**
 * @brief Trigger an SPI action.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] action  Action to trigger, refer to @ref SPI_ACTION_EVENT.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_ActionTrigger(SPI0, SPI_ACTION_START);
 * }
 * @endcode
 */
void SPI_ActionTrigger(SPI_TypeDef *SPIx, uint32_t action);

/**
 * @brief Check the SPI action/event status.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] ae  Action/event to check, refer to @ref SPI_ACTION_EVENT.
 *
 * @return The status of the action/event.
 * @retval true   The action/event status is set.
 * @retval false  The action/event status is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     bool status = SPI_ActionEventStsCheck(SPI0, SPI_EVENT_END);
 * }
 * @endcode
 */
bool SPI_ActionEventStsCheck(SPI_TypeDef *SPIx, uint32_t ae);

/**
 * @brief Clear the SPI action/event status.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] ae  Action/event to clear, refer to @ref SPI_ACTION_EVENT.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_ActionEventStsClear(SPI0, SPI_EVENT_END);
 * }
 * @endcode
 */
void SPI_ActionEventStsClear(SPI_TypeDef *SPIx, uint32_t ae);

/**
 * @brief Set the SPI action transfer parameters.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] cmd_len  Command byte length.
 * @param[in] wait_cnt  Wait cycle count.
 * @param[in] dummy_len  Dummy cycle length.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_SetActionTransfer(SPI0, 1, 10, 6);
 * }
 * @endcode
 */
void SPI_SetActionTransfer(SPI_TypeDef *SPIx, uint8_t cmd_len, uint16_t wait_cnt,
                           uint16_t dummy_len);

#endif

#if (SPI_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable the SPI clock auto mode.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] NewState  New state of the SPI clock auto mode.
 *            This parameter can be one of the following values:
 *            - ENABLE: The SPI clock is gated automatically.
 *            - DISABLE: The SPI clock always runs.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi_demo(void)
 * {
 *     SPI_ClockAutoModeCmd(SPI0, ENABLE);
 * }
 * @endcode
 */
void SPI_ClockAutoModeCmd(SPI_TypeDef *SPIx, FunctionalState NewState);

#endif

#if (SPI_SUPPORT_REPEAT_MODE == 1)

/**
 * @brief Set the SPI repeat mode.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] mode  Repeat mode. Refer to @ref SPIRepeatMode_TypeDef.
 *
 */
void SPI_SetRepeatMode(SPI_TypeDef *SPIx, SPIRepeatMode_TypeDef mode);

/**
 * @brief Set the SPI repeat transfer size.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] size  Repeat transfer size. Refer to @ref SPIRepeatSize_TypeDef.
 *
 */
void SPI_SetRepeatSize(SPI_TypeDef *SPIx, SPIRepeatSize_TypeDef size);

/**
 * @brief Send repeat data through the SPIx peripheral.
 *
 * @param[in] SPIx  Select the SPI peripheral, refer to @ref SPI_DECLARATION.
 * @param[in] data_l  Lower data to be repeated.
 * @param[in] data_h  Higher data to be repeated.
 *
 */
void SPI_SendRepeatData(SPI_TypeDef *SPIx, uint32_t data_l, uint32_t data_h);

#endif

/** @} */ /* End of group SPI_Exported_Functions */

/** @} */ /* End of group SPI_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_SPI_H */
