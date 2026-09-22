/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_UART_H
#define RTL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "uart/src/device/rtl87x2g/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "uart/src/device/rtl87x3d/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "uart/src/device/rtl87x2j/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "uart/src/device/rtl87x3j/rtl_uart_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "uart/src/device/rtl87x3k/rtl_uart_def.h"
#endif

/**
 * @defgroup UART_DRIVER DRIVER
 * @ingroup UART
 * @brief UART driver.
 * @{
 */
/**
 * @defgroup UART_Exported_Constants UART Exported Constants
 * @{
 */

/**
 * @defgroup    UART_FIFO_SIZE UART FIFO Size
 * @{
 * @ingroup     UART_Exported_Constants
 */
#define UART_TX_FIFO_SIZE           16      /**< UART TX FIFO size is 16. */
#define UART_RX_FIFO_SIZE           32      /**< UART RX FIFO size is 32. */

/** @} */ /* End of group UART_FIFO_SIZE */

/**
 * @defgroup    UART_BAUDRATE UART Baudrate
 * @{
 * @ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_BAUD_RATE_1200,      /**< UART baudrate is 1200Hz. */
    UART_BAUD_RATE_4800,      /**< UART baudrate is 4800Hz. */
    UART_BAUD_RATE_7200,      /**< UART baudrate is 7200Hz. */
    UART_BAUD_RATE_9600,      /**< UART baudrate is 9600Hz. */
    UART_BAUD_RATE_14400,     /**< UART baudrate is 14400Hz. */
    UART_BAUD_RATE_19200,     /**< UART baudrate is 19200Hz. */
    UART_BAUD_RATE_28800,     /**< UART baudrate is 28800Hz. */
    UART_BAUD_RATE_38400,     /**< UART baudrate is 38400Hz. */
    UART_BAUD_RATE_57600,     /**< UART baudrate is 57600Hz. */
    UART_BAUD_RATE_76800,     /**< UART baudrate is 76800Hz. */
    UART_BAUD_RATE_115200,    /**< UART baudrate is 115200Hz. */
    UART_BAUD_RATE_128000,    /**< UART baudrate is 128000Hz. */
    UART_BAUD_RATE_153600,    /**< UART baudrate is 153600Hz. */
    UART_BAUD_RATE_230400,    /**< UART baudrate is 230400Hz. */
    UART_BAUD_RATE_460800,    /**< UART baudrate is 460800Hz. */
    UART_BAUD_RATE_500000,    /**< UART baudrate is 500000Hz. */
    UART_BAUD_RATE_921600,    /**< UART baudrate is 921600Hz. */
    UART_BAUD_RATE_1000000,   /**< UART baudrate is 1000000Hz. */
    UART_BAUD_RATE_1382400,   /**< UART baudrate is 1382400Hz. */
    UART_BAUD_RATE_1444400,   /**< UART baudrate is 1444400Hz. */
    UART_BAUD_RATE_1500000,   /**< UART baudrate is 1500000Hz. */
    UART_BAUD_RATE_1843200,   /**< UART baudrate is 1843200Hz. */
    UART_BAUD_RATE_2000000,   /**< UART baudrate is 2000000Hz. */
    UART_BAUD_RATE_3000000,   /**< UART baudrate is 3000000Hz. */
    UART_BAUD_RATE_4000000,   /**< UART baudrate is 4000000Hz. */
    UART_BAUD_RATE_MAXIMUM,   /**< UART baudrate maximum value. */
} UARTBaudrate_TypeDef;

/** @} */ /* End of group UART_BAUDRATE */

/**
 * @defgroup    UART_PARITY UART Parity
 * @{
 * @ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_PARITY_NO_PARTY   = 0x0,    /**< UART parity is none. */
    UART_PARITY_ODD        = 0x1,    /**< UART parity is odd. */
    UART_PARITY_EVEN       = 0x3,    /**< UART parity is even. */
    UART_PARITY_STICK_HIGH = 0x5,    /**< UART parity is stick high. */
    UART_PARITY_STICK_LOW  = 0x7,    /**< UART parity is stick low. */
} UARTParity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NO_PARTY) || \
                                ((PARITY) == UART_PARITY_ODD) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_STICK_HIGH) || \
                                ((PARITY) == UART_PARITY_STICK_LOW))

/** @} */ /* End of group UART_PARITY */

/**
 * @defgroup    UART_STOP_BITS UART Stop Bits
 * @{
 * @ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_STOP_BITS_1 = 0x0,      /**< UART stop bits is 1 stop bit. */
    UART_STOP_BITS_2 = 0x1,      /**< UART stop bits is 2 stop bits. */
} UARTStopBits_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_STOPBITS(STOP) (((STOP) == UART_STOP_BITS_1) || \
                                ((STOP) == UART_STOP_BITS_2))

/** @} */ /* End of group UART_STOP_BITS */

/**
 * @defgroup    UART_WORD_LENGTH UART Word Length
 * @{
 * @ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_WORD_LENGTH_7BIT = 0x0,     /**< UART word length is 7 data bits. */
    UART_WORD_LENGTH_8BIT = 0x1,     /**< UART word length is 8 data bits. */
} UARTWordLen_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_WORD_LENGTH(LEN) ((((LEN)) == UART_WORD_LENGTH_7BIT) || \
                                  (((LEN)) == UART_WORD_LENGTH_8BIT))

/** @} */ /* End of group UART_WORD_LENGTH */

/**
 * @defgroup    UART_RX_IDLE_TIME UART RX Idle Time
 * @{
 * @ingroup     UART_Exported_Constants
 */
typedef enum
{
    UART_RX_IDLE_1BYTE     = 0x0,    /**< UART Rx idle time is 1 byte. */
    UART_RX_IDLE_2BYTE     = 0x1,    /**< UART Rx idle time is 2 bytes. */
    UART_RX_IDLE_4BYTE     = 0x2,    /**< UART Rx idle time is 4 bytes. */
    UART_RX_IDLE_8BYTE     = 0x3,    /**< UART Rx idle time is 8 bytes. */
    UART_RX_IDLE_16BYTE    = 0x4,    /**< UART Rx idle time is 16 bytes. */
    UART_RX_IDLE_32BYTE    = 0x5,    /**< UART Rx idle time is 32 bytes. */
    UART_RX_IDLE_64BYTE    = 0x6,    /**< UART Rx idle time is 64 bytes. */
    UART_RX_IDLE_128BYTE   = 0x7,    /**< UART Rx idle time is 128 bytes. */
    UART_RX_IDLE_256BYTE   = 0x8,    /**< UART Rx idle time is 256 bytes. */
    UART_RX_IDLE_512BYTE   = 0x9,    /**< UART Rx idle time is 512 bytes. */
    UART_RX_IDLE_1024BYTE  = 0xA,    /**< UART Rx idle time is 1024 bytes. */
    UART_RX_IDLE_2048BYTE  = 0xB,    /**< UART Rx idle time is 2048 bytes. */
    UART_RX_IDLE_4096BYTE  = 0xC,    /**< UART Rx idle time is 4096 bytes. */
    UART_RX_IDLE_8192BYTE  = 0xD,    /**< UART Rx idle time is 8192 bytes. */
    UART_RX_IDLE_16384BYTE = 0xE,    /**< UART Rx idle time is 16384 bytes. */
    UART_RX_IDLE_32768BYTE = 0xF,    /**< UART Rx idle time is 32768 bytes. */
} UARTRXIdleTime_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_RX_IDLE_TIME(TIME) ((TIME) <= 0x0F)

/** @} */ /* End of group UART_RX_IDLE_TIME */

/**
 * @defgroup    UART_INTERRUPTS UART Interrupts
 * @{
 * @ingroup     UART_Exported_Constants
 */
#define UART_INT_RD_AVA                 (BIT0)     /**< UART Rx data available interrupt. */
#define UART_INT_TX_FIFO_EMPTY          (BIT1)     /**< UART Tx FIFO empty interrupt. */
#define UART_INT_RX_LINE_STS            (BIT2)     /**< UART Rx line status interrupt. */
#if (UART_SUPPORT_TX_DONE == 1)
#define UART_INT_TX_DONE                (BIT4)     /**< UART Tx done (TX shift register empty and TX FIFO empty) interrupt. */
#endif
#if (UART_SUPPORT_TX_THRESHOLD == 1)
#define UART_INT_TX_THD                 (BIT5)     /**< UART Tx threshold interrupt. */
#endif
#define UART_INT_RX_IDLE                (BIT7)     /**< UART Rx idle interrupt. */
#if (UART_SUPPORT_CTS_TOGGLE == 1)
#define UART_INT_CTS_TOGGLE             (BIT8)     /**< UART CTS toggle interrupt. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_INTERRUPT(INT)          (((INT) == UART_INT_RD_AVA) || \
                                         ((INT) == UART_INT_TX_FIFO_EMPTY) || \
                                         ((INT) == UART_INT_RX_LINE_STS) || \
                                         ((INT) == UART_INT_TX_DONE) || \
                                         ((INT) == UART_INT_TX_THD) || \
                                         ((INT) == UART_INT_RX_IDLE) || \
                                         ((INT) == UART_INT_CTS_TOGGLE))

/** @} */ /* End of group UART_INTERRUPTS */

/**
 * @defgroup    UART_INTERRUPTS_IDENTIFIER UART Interrupts Identifier
 * @{
 * @ingroup     UART_Exported_Constants
 */
#define UART_INT_PENDING                ((uint16_t)(0x01 << 0))     /**< UART interrupt is pending. */
#define UART_INT_ID_LINE_STATUS         ((uint16_t)(0x03 << 1))     /**< UART interrupt ID is Rx line status . */
#define UART_INT_ID_RX_LEVEL_REACH      ((uint16_t)(0x02 << 1))     /**< UART interrupt ID is Rx data level reached. */
#define UART_INT_ID_RX_DATA_TIMEOUT     ((uint16_t)(0x06 << 1))     /**< UART interrupt ID is Rx data timeout. */
#define UART_INT_ID_TX_FIFO_EMPTY       ((uint16_t)(0x01 << 1))     /**< UART interrupt ID is Tx FIFO empty. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_INT_ID(ID)              (((ID) == UART_INT_ID_LINE_STATUS) || \
                                         ((ID) == UART_INT_ID_RX_LEVEL_REACH) || \
                                         ((ID) == UART_INT_ID_RX_DATA_TIMEOUT) || \
                                         ((ID) == UART_INT_ID_TX_FIFO_EMPTY))

/** @} */ /* End of group UART_INTERRUPTS_IDENTIFIER */

/**
 * @defgroup    UART_FLAG UART Flag
 * @{
 * @ingroup     UART_Exported_Constants
 */
#define UART_FLAG_RX_DATA_AVA           (BIT0)     /**< UART Rx data available interrupt flag. */
#define UART_FLAG_RX_OVERRUN            (BIT1)     /**< UART Rx FIFO overrun interrupt flag. */
#define UART_FLAG_RX_PARITY_ERR         (BIT2)     /**< UART Rx parity error interrupt flag. */
#define UART_FLAG_RX_FRAME_ERR          (BIT3)     /**< UART Rx frame error interrupt flag. */
#define UART_FLAG_RX_BREAK_ERR          (BIT4)     /**< UART Rx break error interrupt flag. */
#define UART_FLAG_TX_FIFO_EMPTY         (BIT5)     /**< UART Tx FIFO empty interrupt flag. */
#define UART_FLAG_TX_EMPTY              (BIT6)     /**< UART Tx empty (TX shift register empty and TX FIFO empty) interrupt flag. */
#define UART_FLAG_RX_FIFO_ERR           (BIT7)     /**< UART Rx FIFO error interrupt flag. */
#define UART_FLAG_RX_IDLE               (BIT9)     /**< UART Rx idle interrupt flag. */
#if (UART_SUPPORT_TX_DONE == 1)
#define UART_FLAG_TX_DONE               (BIT10)    /**< UART Tx done (TX shift register empty and TX FIFO empty) interrupt flag. */
#endif
#if (UART_SUPPORT_TX_THRESHOLD == 1)
#define UART_FLAG_TX_THD                (BIT11)    /**< UART Tx threshold interrupt flag. */
#endif
#if (UART_SUPPORT_CTS_TOGGLE == 1)
#define UART_FLAG_CTS_TOGGLE            (BIT12)    /**< UART CTS toggle interrupt flag. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_GET_FLAG(FLAG)        (((FLAG) == UART_FLAG_RX_DATA_AVA) || \
                                       ((FLAG) == UART_FLAG_RX_OVERRUN) || \
                                       ((FLAG) == UART_FLAG_RX_PARITY_ERR) || \
                                       ((FLAG) == UART_FLAG_RX_FRAME_ERR) || \
                                       ((FLAG) == UART_FLAG_RX_BREAK_ERR) || \
                                       ((FLAG) == UART_FLAG_TX_FIFO_EMPTY) || \
                                       ((FLAG) == UART_FLAG_TX_EMPTY) || \
                                       ((FLAG) == UART_FLAG_RX_FIFO_ERR) || \
                                       ((FLAG) == UART_FLAG_RX_IDLE) || \
                                       ((FLAG) == UART_FLAG_TX_DONE) || \
                                       ((FLAG) == UART_FLAG_TX_THD) || \
                                       ((FLAG) == UART_FLAG_CTS_TOGGLE))

/** @} */ /* End of group UART_FLAG */

/**
 * @defgroup    UART_INTERRUPTS_MASK UART Interrupts Mask
 * @{
 * @ingroup     UART_Exported_Constants
 */
#define UART_INT_MASK_RD_AVA            (BIT0)     /**< UART Rx data available interrupt mask. */
#define UART_INT_MASK_TX_FIFO_EMPTY     (BIT1)     /**< UART Tx FIFO empty interrupt mask. */
#define UART_INT_MASK_RX_LINE_STS       (BIT2)     /**< UART Rx line status interrupt mask. */
#define UART_INT_MASK_RX_IDLE           (BIT5)     /**< UART RX idle interrupt mask. */
#if (UART_SUPPORT_TX_DONE == 1)
#define UART_INT_MASK_TX_DONE           (BIT6)     /**< UART TX done (TX shift register empty and TX FIFO empty) interrupt mask. */
#endif
#if (UART_SUPPORT_TX_THRESHOLD == 1)
#define UART_INT_MASK_TX_THD            (BIT7)     /**< UART TX FIFO threshold interrupt mask. */
#endif
#if (UART_SUPPORT_CTS_TOGGLE == 1)
#define UART_INT_MASK_CTS_TOGGLE        (BIT8)     /**< UART CTS toggle interrupt mask. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_UART_INT_MASK(INT) ((INT) & (UART_INT_MASK_RD_AVA | \
                                        UART_INT_MASK_TX_FIFO_EMPTY | \
                                        UART_INT_MASK_RX_LINE_STS | \
                                        UART_INT_MASK_RX_IDLE | \
                                        UART_INT_MASK_TX_DONE | \
                                        UART_INT_MASK_TX_THD  | \
                                        UART_INT_MASK_CTS_TOGGLE))

/** @} */ /* End of group UART_INTERRUPTS_MASK */

/** @} */ /* End of group UART_Exported_Constants */

/**
 * @defgroup UART_Exported_Types UART Exported Types
 * @{
 */

/**
 * @defgroup    UART_INIT_STRUCTURE UART Init Structure
 * @{
 * @ingroup     UART_Exported_Types
 */
typedef struct
{
    uint16_t UART_OvsrAdj;              /**< Specifies the baudrate setting of ovsr_adj.
                                             Fractional oversampling adjustment that fine-tunes the baudrate
                                             between integer oversampling steps.
                                             This parameter can be calculated by calling @ref UART_GetBaudSettings. */

    uint16_t UART_Div;                  /**< Specifies the baudrate setting of div.
                                             Divisor latch that divides the UART source clock.
                                             This parameter can be calculated by calling @ref UART_GetBaudSettings. */

    uint16_t UART_Ovsr;                 /**< Specifies the baudrate setting of ovsr.
                                             Integer oversampling that divides the UART source clock.
                                             The actual baudrate is calculated as Baudrate = SourceClock / (Div * Ovsr),
                                             and can be refined by ovsr_adj.
                                             This parameter can be calculated by calling @ref UART_GetBaudSettings. */

    UARTWordLen_TypeDef UART_WordLen;   /**< Specifies the word length.
                                             The word length is the number of data bits transmitted or received in a frame.
                                             This parameter can be any value of @ref UART_WORD_LENGTH. */

    UARTStopBits_TypeDef UART_StopBits; /**< Specifies the stop bit.
                                             This parameter can be any value of @ref UART_STOP_BITS. */

    UARTParity_TypeDef UART_Parity;     /**< Specifies the parity.
                                             This parameter can be any value of @ref UART_PARITY. */

    uint8_t UART_TxThdLevel;            /**< Specifies the Tx threshold level.
                                             The TX_THD interrupt is triggered when the number of entries in
                                             the TX FIFO is less than or equal to this value (TX FIFO depth = 16).
                                             This parameter must range from 1 to 15.  */

    uint8_t UART_RxThdLevel;            /**< Specifies the Rx threshold level.
                                             The RX interrupt is triggered when the number of entries in the
                                             RX FIFO is greater than or equal to this value (RX FIFO depth = 32).
                                             This parameter must range from 1 to 31. */

    UARTRXIdleTime_TypeDef UART_IdleTime; /**< Specifies the Rx idle time.
                                             The RX_IDLE interrupt is triggered after the Rx line stays
                                             idle for this duration, used to detect the end of a reception.
                                             This parameter can be any value of @ref UART_RX_IDLE_TIME. */

    FunctionalState UART_HardwareFlowControl; /**< Enable or Disable hardware flow control.
                                             When enabled, RTS/CTS auto flow control gates transmission and
                                             reception by the FIFO state.
                                             This parameter can be any value of ENABLE and DISABLE. */

    FunctionalState UART_DMAEn;         /**< Enable or Disable DMA mode.
                                             This parameter can be any value of ENABLE and DISABLE. */

    FunctionalState UART_TxDMAEn;       /**< Enable or Disable Tx DMA mode.
                                             This parameter can be any value of ENABLE and DISABLE. */

    FunctionalState UART_RxDMAEn;       /**< Enable or Disable Rx DMA mode.
                                             This parameter can be any value of ENABLE and DISABLE. */

    uint8_t UART_TxWaterLevel;          /**< Specifies the DMA Tx water level.
                                             The Tx DMA request is triggered when the Tx FIFO reaches @ref UART_TxWaterLevel.
                                             This parameter must range from 1 to 16. */

    uint8_t UART_RxWaterLevel;          /**< Specifies the DMA Rx water level.
                                             The Rx DMA request is triggered when the Rx FIFO reaches @ref UART_RxWaterLevel.
                                             This parameter must range from 1 to 31. */

    FunctionalState UART_TxOnlyEn;      /**< Enable or Disable Tx only mode.
                                             When enabled, the receiver is held in reset so the UART transmits only.
                                             This parameter can be any value of ENABLE and DISABLE. */

#if (UART_SUPPORT_AUTO_CLOCK == 1)
    FunctionalState UART_AutoModeEn;    /**< Enable or disable the UART auto mode.
                                             When the UART automatic mode is enabled, the UART clock automatically
                                             activates when detected a start bit of the received data and goes idle
                                             when no more data is received for the duration specified by @ref UART_AutoModeTime. */

    uint16_t UART_AutoModeTime;         /**< Specifies the UART auto mode time.
                                             UART_AutoModeTime is the period after which the UART clock will go idle
                                             when no further data is received. */
#endif
} UART_InitTypeDef;

/** @} */ /* End of group UART_INIT_STRUCTURE */

/** @} */ /* End of group UART_Exported_Types */

/**
 * @defgroup UART_Exported_Functions UART Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the specified UART registers to their default reset values.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *    UART_DeInit(UART0);
 * }
 * @endcode
 */
void UART_DeInit(UART_TypeDef *UARTx);

/**
 * @brief Initialize the UART peripheral according to the specified parameters in the UART_InitStruct.
 *
 * @param[in] UARTx            Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] UART_InitStruct  Pointer to a UART_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     RCC_ClockCmd(UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_WordLen    = UART_WORD_LENGTH_8BIT;
 *     UART_InitStruct.UART_Parity     = UART_PARITY_NO_PARTY;
 *     UART_InitStruct.UART_StopBits   = UART_STOP_BITS_1;
 *     UART_InitStruct.UART_RxThdLevel = 16;
 *     UART_InitStruct.UART_IdleTime   = UART_RX_IDLE_2BYTE;
 *     // Calculate baud rate settings (Div, Ovsr, OvsrAdj) based on frame length.
 *     UART_GetBaudSettings(115200,
 *                          UART_InitStruct.UART_WordLen,
 *                          UART_InitStruct.UART_Parity,
 *                          UART_InitStruct.UART_StopBits,
 *                          &UART_InitStruct.UART_Div,
 *                          &UART_InitStruct.UART_Ovsr,
 *                          &UART_InitStruct.UART_OvsrAdj);
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * @endcode
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct);

/**
 * @brief Fills each UART_InitStruct member with its default value.
 *
 * @note   The default settings for the UART_InitStruct member are shown in the following table:
 *         | UART_InitStruct member     | Default value                  |
 *         |:--------------------------:|:------------------------------:|
 *         | UART_Div                   | 20                             |
 *         | UART_Ovsr                  | 12                             |
 *         | UART_OvsrAdj               | 0x252                          |
 *         | UART_Parity                | @ref UART_PARITY_NO_PARTY      |
 *         | UART_StopBits              | @ref UART_STOP_BITS_1          |
 *         | UART_WordLen               | @ref UART_WORD_LENGTH_8BIT     |
 *         | UART_TxThdLevel            | 16                             |
 *         | UART_RxThdLevel            | 16                             |
 *         | UART_IdleTime              | @ref UART_RX_IDLE_2BYTE        |
 *         | UART_HardwareFlowControl   | DISABLE                        |
 *         | UART_DMAEn                 | DISABLE                        |
 *         | UART_TxDMAEn               | DISABLE                        |
 *         | UART_RxDMAEn               | DISABLE                        |
 *         | UART_TxWaterLevel          | 15                             |
 *         | UART_RxWaterLevel          | 1                              |
 *         | UART_TxOnlyEn              | DISABLE                        |
 *
 * @param[in] UART_InitStruct  Pointer to a UART_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     RCC_ClockCmd(UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     UART_InitStruct.UART_WordLen    = UART_WORD_LENGTH_8BIT;
 *     UART_InitStruct.UART_Parity     = UART_PARITY_NO_PARTY;
 *     UART_InitStruct.UART_StopBits   = UART_STOP_BITS_1;
 *     UART_InitStruct.UART_RxThdLevel = 16;
 *     UART_InitStruct.UART_IdleTime   = UART_RX_IDLE_2BYTE;
 *     // Calculate baud rate settings (Div, Ovsr, OvsrAdj) based on frame length.
 *     UART_GetBaudSettings(115200,
 *                          UART_InitStruct.UART_WordLen,
 *                          UART_InitStruct.UART_Parity,
 *                          UART_InitStruct.UART_StopBits,
 *                          &UART_InitStruct.UART_Div,
 *                          &UART_InitStruct.UART_Ovsr,
 *                          &UART_InitStruct.UART_OvsrAdj);
 *     UART_Init(UART0, &UART_InitStruct);
 * }
 * @endcode
 */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct);

/**
 * @brief Mask or unmask the specified UART interrupt.
 *
 * @param[in] UARTx          Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] UART_INT_MASK  Specifies the UART interrupt to be masked or unmasked.
 *                           This parameter can be any combination of @ref UART_INTERRUPTS_MASK.
 *                           - UART_INT_MASK_RD_AVA: UART Rx data available interrupt mask.
 *                           - UART_INT_MASK_FIFO_EMPTY: UART Tx FIFO empty interrupt mask.
 *                           - UART_INT_MASK_LINE_STS: UART Rx line status interrupt mask.
 *                           - UART_INT_MASK_RX_IDLE: UART RX idle interrupt mask.
 *                           - UART_INT_MASK_TX_DONE: UART TX done (TX shift register empty and TX FIFO empty) interrupt mask.
 *                           - UART_INT_MASK_TX_THD: UART TX FIFO threshold interrupt mask.
 *                           - UART_INT_MASK_CTS_TOGGLE: UART CTS toggle interrupt mask.
 * @param[in] NewState       Enable or disable the specified UART interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     RCC_ClockCmd(UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     ...
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, ENABLE);
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 *     UART_MaskINTConfig(UART0, UART_INT_MASK_RD_AVA, DISABLE);
 * }
 * @endcode
 */
void UART_MaskINTConfig(UART_TypeDef *UARTx, uint32_t UART_INT_MASK,
                        FunctionalState NewState);
/**
 * @brief Enable or disable the specified UART interrupts.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] UART_INT  Specifies the UART interrupts to be enabled or disabled.
 *                      This parameter can be any combination of @ref UART_INTERRUPTS.
 *                      - UART_INT_RD_AVA: UART Rx data available interrupt.
 *                      - UART_INT_TX_FIFO_EMPTY: UART Tx FIFO empty interrupt.
 *                      - UART_INT_RX_LINE_STS: UART Rx line status interrupt.
 *                      - UART_INT_TX_DONE: UART Tx done interrupt.
 *                      - UART_INT_TX_THD: UART Tx threshold interrupt.
 *                      - UART_INT_RX_IDLE: UART Rx idle interrupt.
 *                      - UART_INT_CTS_TOGGLE: UART CTS toggle interrupt.
 * @param[in] NewState  Enable or disable the specified UART interrupts.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_uart_init(void)
 * {
 *     RCC_ClockCmd(UART0_CLOCK, ENABLE);
 *
 *     UART_InitTypeDef UART_InitStruct;
 *     UART_StructInit(&UART_InitStruct);
 *     ...
 *     UART_Init(UART0, &UART_InitStruct);
 *
 *     UART_INTConfig(UART0, UART_INT_RD_AVA, ENABLE);
 * }
 * @endcode
 */
void UART_INTConfig(UART_TypeDef *UARTx, uint32_t UART_INT, FunctionalState NewState);

/**
 * @brief Clear the specified UART interrupt flag.
 *
 * @note Only UART_FLAG_RX_IDLE and UART_FLAG_CTS_TOGGLE need to be cleared manually, other interrupt flags cannot be cleared.
 *
 * @param[in] UARTx      Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] UART_FLAG  Specifies the UART interrupt flag to clear.
 *                       This parameter can be only one of the following values:
 *                       - UART_FLAG_RX_IDLE: UART Rx idle interrupt flag.
 *                       - UART_FLAG_CTS_TOGGLE: UART CTS toggle interrupt flag.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void uart_handler(void)
 * {
 *     if(UART_GetFlagStatus(UART2, UART_FLAG_RX_IDLE) == SET)
 *     {
 *          UART_ClearINT(UART2, UART_FLAG_RX_IDLE);
 *     }
 * }
 * @endcode
 */
void UART_ClearINT(UART_TypeDef *UARTx, uint32_t UART_FLAG);

/**
 * @brief Get the specified UART interrupt flag.
 *
 * @param[in] UARTx      Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] UART_FLAG  Specifies the UART interrupt flag to check.
 *                       This parameter can be any of @ref UART_FLAG.
 *                       - UART_FLAG_RX_DATA_AVA: UART Rx data available interrupt flag.
 *                       - UART_FLAG_RX_OVERRUN: UART Rx FIFO overrun interrupt flag.
 *                       - UART_FLAG_RX_PARITY_ERR: UART Rx parity error interrupt flag.
 *                       - UART_FLAG_RX_FRAME_ERR: UART Rx frame error interrupt flag.
 *                       - UART_FLAG_RX_BREAK_ERR: UART Rx break error interrupt flag.
 *                       - UART_FLAG_TX_FIFO_EMPTY: UART Tx FIFO empty interrupt flag.
 *                       - UART_FLAG_TX_EMPTY: UART Tx empty (TX shift register empty and TX FIFO empty) interrupt flag.
 *                       - UART_FLAG_RX_FIFO_ERR: UART Rx FIFO error interrupt flag.
 *                       - UART_FLAG_RX_IDLE: UART Rx idle interrupt flag.
 *                       - UART_FLAG_TX_DONE: UART Tx done (TX shift register empty and TX FIFO empty) interrupt flag.
 *                       - UART_FLAG_TX_THD: UART Tx threshold interrupt flag.
 *                       - UART_FLAG_CTS_TOGGLE: UART CTS toggle interrupt flag.
 *
 * @return  The specified UART interrupt status. Refer to @ref FlagStatus.
 * @retval SET    The interrupt status is set.
 * @retval RESET  The interrupt status is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_senddata_continuous(UART_TypeDef *UARTx, const uint8_t *pSend_Buf, uint16_t vCount)
 * {
 *     uint8_t count;
 *
 *     while (vCount / UART_TX_FIFO_SIZE > 0)
 *     {
 *         while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *         for (count = UART_TX_FIFO_SIZE; count > 0; count--)
 *         {
 *             UARTx->UART_RBR_THR = *pSend_Buf++;
 *         }
 *         vCount -= UART_TX_FIFO_SIZE;
 *     }
 *
 *     while (UART_GetFlagStatus(UARTx, UART_FLAG_TX_FIFO_EMPTY) == 0);
 *     while (vCount--)
 *     {
 *         UARTx->UART_RBR_THR = *pSend_Buf++;
 *     }
 * }
 * @endcode
 */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint32_t UART_FLAG);

/**
 * @brief Get the specified UART line status.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return The specified UART line status, a bitmask of the following flags:
 * @retval UART_FLAG_RX_DATA_AVA    UART Rx data available interrupt flag.
 * @retval UART_FLAG_RX_OVERRUN     UART Rx FIFO overrun interrupt flag.
 * @retval UART_FLAG_RX_PARITY_ERR  UART Rx parity error interrupt flag.
 * @retval UART_FLAG_RX_FRAME_ERR   UART Rx frame error interrupt flag.
 * @retval UART_FLAG_RX_BREAK_ERR   UART Rx break error interrupt flag.
 * @retval UART_FLAG_TX_FIFO_EMPTY  UART Tx FIFO empty interrupt flag.
 * @retval UART_FLAG_TX_EMPTY       UART Tx empty (TX shift register empty and TX FIFO empty) interrupt flag.
 * @retval UART_FLAG_RX_FIFO_ERR    UART Rx FIFO error interrupt flag.
 *
 * @note   Reading the LSR may clear certain error flags (OE, PE, FE, BI)
 *         as a side effect on some implementations. Read it only once per
 *         check and cache the result if multiple bits need to be evaluated.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint32_t line_status = UART_GetLineStatus(UART0);
 *
 *     if (line_status & UART_FLAG)
 *     {
 *         //Add user code here.
 *     }
 * }
 * @endcode
 */
uint8_t UART_GetLineStatus(UART_TypeDef *UARTx);

/**
 * @brief Get the specified UART interrupt identifier.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  Specifies the UART interrupts to check.
 *          This parameter can be any of the following values:
 *          - UART_INT_ID_LINE_STATUS: UART interrupt ID is Rx line status.
 *          - UART_INT_ID_RX_LEVEL_REACH: UART interrupt ID is Rx data level reached.
 *          - UART_INT_ID_RX_DATA_TIMEOUT: UART interrupt ID: Rx data timeout.
 *          - UART_INT_ID_TX_FIFO_EMPTY: UART interrupt ID: Tx FIFO empty.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void UART0_Handler()
 * {
 *      uint16_t uart_fifo_len = 0;
 *      uint32_t int_status = UART_GetIID(UART_SAMPLE);
 *
 *      // Disable RX Available Interrupt to prevent repeated triggering during processing
 *      UART_INTConfig(UART_SAMPLE, UART_INT_RD_AVA, DISABLE);
 *
 *      switch (int_status & 0x0E)
 *      {
 *      case UART_INT_ID_RX_LEVEL_REACH:
 *      case UART_INT_ID_RX_DATA_TIMEOUT:
 *          {
 *              uart_fifo_len = UART_GetRxFIFODataLen(UART_SAMPLE);
 *              // Read data from UART RX FIFO to uart_receive_buffer
 *              UART_ReceiveData(UART_SAMPLE, &uart_receive_buffer[uart_receive_length], uart_fifo_len);
 *              uart_receive_length += uart_fifo_len;
 *              break;
 *          }
 *      case UART_INT_ID_LINE_STATUS:
 *          break;
 *      default:
 *          break;
 *      }
 * }
 * @endcode
 */
uint16_t UART_GetIID(UART_TypeDef *UARTx);

/**
 * @brief Send one byte data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] Data   One byte data to send.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = 0x55;
 *     UART_SendByte(UART0, data);
 * }
 * @endcode
 */
void UART_SendByte(UART_TypeDef *UARTx, uint8_t Data);

/**
 * @brief Send data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] InBuf  Pointer to the buffer to send.
 * @param[in] Count  Number of bytes to send.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_SendData(UART0, data, sizeof(data));
 * }
 * @endcode
 */
void UART_SendData(UART_TypeDef *UARTx, const uint8_t *InBuf, uint16_t Count);

#if (UART_SUPPORT_HALF_WORD == 1)
/**
 * @brief Send one half-word data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] Data   One half-word data to send.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t data = 0x5555;
 *     UART_SendHalfWord(UART0, data);
 * }
 * @endcode
 */
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t Data);

/**
 * @brief Send half word data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] InBuf  Pointer to the buffer to send.
 * @param[in] Count  Number of half-words to send.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_SendHalfWordData(UART0, data, sizeof(data));
 * }
 * @endcode
 */
void UART_SendHalfWordData(UART_TypeDef *UARTx, const uint16_t *InBuf, uint16_t Count);
#endif

#if (UART_SUPPORT_TXDATA_API == 1)
/**
 * @brief Send a specified length of data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] InBuf  Pointer to the buffer to send.
 * @param[in] Count  Number of bytes to send.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[] = "UART demo";
 *     UART_TxData(UART0, data, sizeof(data));
 * }
 * @endcode
 */
void UART_TxData(UART_TypeDef *UARTx, const uint8_t *InBuf, uint16_t Count);
#endif

/**
 * @brief Receive one byte data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  One byte data to receive.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data = UART_ReceiveByte(UART0);
 *
 * }
 * @endcode
 */
uint8_t UART_ReceiveByte(UART_TypeDef *UARTx);

/**
 * @brief Receive data over UART.
 *
 * @param[in]  UARTx   Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[out] OutBuf  Pointer to the buffer to receive.
 * @param[in]  Count   Number of bytes to receive.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[32] = {10};
 *     UART_ReceiveData(UART0, data, sizeof(data));
 * }
 * @endcode
 */
void UART_ReceiveData(UART_TypeDef *UARTx, uint8_t *OutBuf, uint16_t Count);

#if (UART_SUPPORT_HALF_WORD == 1)
/**
 * @brief Receive one half-word data over UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  One half-word data to receive.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t data = UART_ReceiveHalfWord(UART0);
 *
 * }
 * @endcode
 */
uint8_t UART_ReceiveHalfWord(UART_TypeDef *UARTx);

/**
 * @brief Receive half word data over UART.
 *
 * @param[in]  UARTx   Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[out] OutBuf  Pointer to the buffer to receive.
 * @param[in]  Count   Number of half-words to receive.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data[32] = {10};
 *     UART_ReceiveData(UART0, data, 10);
 * }
 * @endcode
 */
void UART_ReceiveHalfWordData(UART_TypeDef *UARTx, uint16_t *OutBuf, uint16_t Count);
#endif

/**
 * @brief Set UART baudrate.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] div       Parameter of the specified UART baudrate.
 * @param[in] ovsr      Parameter of the specified UART baudrate.
 * @param[in] ovsr_adj  Parameter of the specified UART baudrate.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t div, ovsr, ovsr_adj;
 *     // Calculate baud rate settings (Div, Ovsr, OvsrAdj) based on frame length.
 *     UART_GetBaudSettings(115200,
 *                          UART_WORD_LENGTH_8BIT,
 *                          UART_PARITY_NO_PARTY,
 *                          UART_STOP_BITS_1,
 *                          &div, &ovsr, &ovsr_adj);
 *     UART_SetBaudRate(UART0, div, ovsr, ovsr_adj);
 * }
 *
 * @endcode
 */
void UART_SetBaudRate(UART_TypeDef *UARTx, uint16_t div, uint16_t ovsr, uint16_t ovsr_adj);

/**
 * @brief Set UART communication parameters.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] WordLen   Specifies the UART data width. Refer to @ref UART_WORD_LENGTH.
 * @param[in] Parity    Specifies the UART parity. Refer to @ref UART_PARITY.
 * @param[in] StopBits  Specifies the UART stop bits. Refer to @ref UART_STOP_BITS.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t word_len = UART_WORD_LENGTH_8BIT;
 *     uint16_t parity = UART_PARITY_NO_PARTY;
 *     uint16_t stop_bits = UART_STOP_BITS_1;
 *     UART_SetParams(UART0, word_len, parity, stop_bits);
 * }
 * @endcode
 */
void UART_SetParams(UART_TypeDef *UARTx, uint16_t WordLen, uint16_t Parity, uint16_t StopBits);

/**
 * @brief Enable or disable the UART loopback function.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the UART loopback function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_LoopBackCmd(UART0, ENABLE);
 * }
 * @endcode
 */
void UART_LoopBackCmd(UART_TypeDef *UARTx, FunctionalState NewState);

#if (UART_SUPPORT_CLEAR_TX_FIFO == 1)
/**
 * @brief Clear the specified UART Tx FIFO.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearTxFIFO(UART0);
 * }
 * @endcode
 */
void UART_ClearTxFIFO(UART_TypeDef *UARTx);
#endif

/**
 * @brief Clear the specified UART Rx FIFO.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClearRxFIFO(UART0);
 * }
 * @endcode
 */
void UART_ClearRxFIFO(UART_TypeDef *UARTx);

/**
 * @brief Get the data length in Tx FIFO of the specified UART peripheral.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  Data length in TX FIFO of the specified UART peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetTxFIFODataLen(UART0);
 * }
 * @endcode
 */
uint8_t UART_GetTxFIFODataLen(UART_TypeDef *UARTx);

/**
 * @brief Get the data length in Rx FIFO of the specified UART peripheral.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  Data length in RX FIFO of the specified UART peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint8_t data_len = UART_GetRxFIFODataLen(UART0);
 * }
 * @endcode
 */
uint8_t UART_GetRxFIFODataLen(UART_TypeDef *UARTx);

/**
 * @brief Enable or disable the DMA mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the DMA mode of the specified UART peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_TxDMACmd(UART0, ENABLE);
 * }
 * @endcode
 */
void UART_TxDMACmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * @brief Enable or disable the DMA mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the DMA mode of the specified UART peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_RxDMACmd(UART0, ENABLE);
 * }
 * @endcode
 */
void UART_RxDMACmd(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * @brief Enable or disable the one wire mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the one wire mode of the specified UART peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_OneWireConfig(UART0, true);
 * }
 * @endcode
 */
void UART_OneWireConfig(UART_TypeDef *UARTx, FunctionalState NewState);

/**
 * @brief Set the clock source and divider of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] ClockSrc  Specifies the UART clock source. Refer to @ref UART_CLOCK_SOURCE.
 * @param[in] ClockDiv  Specifies the UART clock divider. Refer to @ref UART_CLOCK_DIVIDER.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_SetClock(UART0, UART_CLOCK_SRC_40M, UART_CLOCK_DIV_1);
 * }
 * @endcode
 */
void UART_SetClock(UART_TypeDef *UARTx, uint16_t ClockSrc, uint16_t ClockDiv);

#if (UART_SUPPORT_AUTO_CLOCK == 1)
/**
 * @brief Enable or disable UART clock auto mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] Newstate  Enable or disable UART clock auto mode of the specified UART peripheral.
 *                      This parameter can be one of the following values:
 *                       - ENABLE: Enable UART clock auto mode which means the UART clock will be activated when
 *                         detected a start bit of the received data and goes idle when no more data is received
 *                         for the duration specified by @ref UART_AutoModeTime.
 *                       - DISABLE: Disable UART clock auto mode which means the UART clock will always be active.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_ClockAutoModeCmd(UART0, ENABLE);
 * }
 * @endcode
 */
void UART_ClockAutoModeCmd(UART_TypeDef *UARTx, FunctionalState Newstate);

#endif

#if (UART_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the RAP mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the RAP mode of the specified UART peripheral.
 *
 * @return  The execution result when config RAP mode.
 * @retval SET    Config RAP mode successfully.
 * @retval RESET  Config RAP mode failed, which means the UART does not support RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void uart_demo(void)
 * {
 *     UART_RAPModeCmd(UART0, ENABLE);
 * }
 * @endcode
 */
FlagStatus UART_RAPModeCmd(UART_TypeDef *UARTx, FunctionalState NewState);
#endif

#if (UART_SUPPORT_CTS_TOGGLE == 1)
/**
 * @brief Get the CTS level of UART.
 *
 * @param[in] UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 *
 * @return  Level of CTS.
 * @retval SET    CTS is high.
 * @retval RESET  CTS is low.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void uart_demo(void)
 * {
 *     UART_GetCTSStatus(UART0);
 * }
 * @endcode
 */
uint8_t UART_GetCTSLevel(UART_TypeDef *UARTx);
#endif

/**
 * @brief Get the UART baudrate settings (div, ovsr, adj) for the specified baudrate and data format.
 *
 * @param[in]  Baudrate    Target baud rate.
 *                         - If the value is less than @ref UART_BAUD_RATE_MAXIMUM,
 *                           it is treated as an index into @ref uart_baudrate_table.
 *                         - Otherwise it is treated as a raw baud rate value (in bps).
 * @param[in]  DataWidth   UART data width. Refer to @ref UART_WORD_LENGTH.
 * @param[in]  Parity      UART parity. Refer to @ref UART_PARITY.
 * @param[in]  StopBits    UART stop bits. Refer to @ref UART_STOP_BITS.
 * @param[out] div         Pointer to the calculated divisor.
 * @param[out] ovsr        Pointer to the calculated oversampling ratio.
 * @param[out] adj         Pointer to the calculated fractional adjustment mask.
 *
 * @return The relative baud rate error, expressed in units of 1/10000
 *         (i.e. returned value of 100 means 1.00% error).
 * @retval 0      A perfect match (no error).
 * @retval 10000  No valid setting was found (default).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     uint16_t div, ovsr, adj;
 *     uint32_t err;
 *
 *     // Calculate settings for 115200 bps, 8 data bits, no parity, 1 stop bit
 *     err = UART_GetBaudSettings(115200,
 *                                UART_WORD_LENGTH_8BIT,
 *                                UART_PARITY_NO_PARTY,
 *                                UART_STOP_BITS_1,
 *                                &div, &ovsr, &adj);
 *     UART_SetBaudRate(UART0, div, ovsr, adj);
 * }
 * @endcode
 */
uint32_t UART_GetBaudSettings(uint32_t Baudrate,
                              uint8_t DataWidth, uint8_t Parity, uint8_t StopBits,
                              uint16_t *div, uint16_t *ovsr, uint16_t *adj);

/**
 * @brief Enable or disable the TX-Only mode of the specified UART peripheral.
 *
 * @param[in] UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param[in] NewState  Enable or disable the TX-Only mode of the specified UART peripheral.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable TX-only mode (RX function is disabled).
 *                      - DISABLE: Disable TX-only mode (Normal mode which TX/RX function is enabled).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void uart_demo(void)
 * {
 *     UART_TxOnlyModeCmd(UART0, ENABLE);  // Enable TX-only mode
 * }
 * @endcode
 */
void UART_TxOnlyModeCmd(UART_TypeDef *UARTx, FunctionalState NewState);

/** @} */ /* End of group UART_Exported_Functions */

/** @} */ /* End of group UART_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_UART_H */
