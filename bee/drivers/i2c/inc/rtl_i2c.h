/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_I2C_H
#define RTL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "i2c/src/device/rtl87x2g/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "i2c/src/device/rtl87x3d/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "i2c/src/device/rtl87x2j/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "i2c/src/device/rtl87x3j/rtl_i2c_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "i2c/src/device/rtl87x3k/rtl_i2c_def.h"
#endif

/**
 * @defgroup I2C_DRIVER DRIVER
 * @ingroup I2C
 * @brief Inter-Integrated Circuit (I2C) driver.
 * @{
 */

/**
 * @defgroup I2C_Exported_Constants I2C Exported Constants
 * @{
 */

/**
 * @defgroup I2C_CLOCK_SPEED I2C Clock Speed
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x01) && ((SPEED) <= I2C_CLOCK_MAX_SPEED))
/** @} */ /* End of group I2C_CLOCK_SPEED */

/**
 * @defgroup I2C_DEVICE_MODE I2C Device Mode
 * @{
 */

/**
 * @brief I2C device mode.
 */
typedef enum
{
    I2C_DEVICE_MODE_SLAVE = 0x00,       /**< I2C slave device. */
    I2C_DEVICE_MODE_MASTER = 0x01,      /**< I2C master device. */
} I2CDeviceMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_DEVICE_MODE(MODE) (((MODE) == I2C_DEVICE_MODE_SLAVE) || ((MODE) == I2C_DEVICE_MODE_MASTER))
/** @} */ /* End of group I2C_DEVICE_MODE */

/**
 * @defgroup I2C_ADDRESS_MODE I2C Address Mode
 * @{
 */

/**
 * @brief I2C address mode.
 */
typedef enum
{
    I2C_ADDRESS_MODE_7BIT = 0x00,       /**< I2C 7-bit address mode. */
    I2C_ADDRESS_MODE_10BIT = 0x01,      /**< I2C 10-bit address mode. */
} I2CAddressMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_ADDRESS_MODE(ADDR) (((ADDR) == I2C_ADDRESS_MODE_7BIT) || ((ADDR) == I2C_ADDRESS_MODE_10BIT))
/** @} */ /* End of group I2C_ADDRESS_MODE */

/**
 * @defgroup I2C_SEND_COMMAND I2C Send Command
 * @{
 */

/**
 * @brief I2C send command.
 */
typedef enum
{
    I2C_WRITE_CMD = 0x00,       /**< Data write command. */
    I2C_READ_CMD = 0x01,        /**< Data read command. */
} I2CSendCommand_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_CMD(CMD) (((CMD) == I2C_WRITE_CMD) || ((CMD) == I2C_READ_CMD))
/** @} */ /* End of group I2C_SEND_COMMAND */

/**
 * @defgroup I2C_DMA_REQUESTS I2C DMA Requests
 * @{
 */

/**
 * @brief I2C DMA transfer requests.
 */
typedef enum
{
    I2C_DMA_REQ_RX = 0x01,      /**< DMA transfer receiving request. */
    I2C_DMA_REQ_TX = 0x02,      /**< DMA transfer sending request. */
} I2CDMARequests_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_DMAREQ(DMAREQ) (((DMAREQ) == I2C_DMA_REQ_RX) || ((DMAREQ) == I2C_DMA_REQ_TX))
/** @} */ /* End of group I2C_DMA_REQUESTS */

/**
 * @defgroup I2C_STATUS I2C Status
 * @{
 */

/**
 * @brief I2C transfer status.
 */
typedef enum
{
    I2C_SUCCESS,                        /**< I2C transfer success. */
    I2C_ARB_LOST,                       /**< Master has lost arbitration or the slave transmitter has lost arbitration. */
    I2C_ABRT_MASTER_DIS,                /**< User tries to initiate a master operation with the master mode disabled. */
    I2C_ABRT_TXDATA_NOACK,              /**< Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave. Only for master. */
    I2C_ABRT_10ADDR2_NOACK,             /**< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave. */
    I2C_ABRT_10ADDR1_NOACK,             /**< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave. */
    I2C_ABRT_7B_ADDR_NOACK,             /**< Master is in 7-bit address mode and the address sent was not acknowledged by any slave. */
    I2C_ERR_TIMEOUT                     /**< I2C transfer time out error. */
} I2C_Status;

/** @} */ /* End of group I2C_STATUS */

/**
 * @defgroup I2C_INTERRUPTS I2C Interrupts
 * @{
 */

#define I2C_INT_MST_ON_HOLD                     BIT13           /**< When master Tx FIFO is empty and no stop bit command is issued, master will hold the SCL low. */
#define I2C_INT_GEN_CALL                        BIT11           /**< Set only when a general call address is received and it is acknowledged. */
#define I2C_INT_START_DET                       BIT10           /**< Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether I2C is operating in slave or master mode. */
#define I2C_INT_STOP_DET                        BIT9            /**< Indicates whether a STOP condition has occurred on the I2C interface regardless of whether I2C is operating in slave or master mode. */
#define I2C_INT_ACTIVITY                        BIT8            /**< This bit captures I2C activity and stays set until it is cleared. */
#define I2C_INT_RX_DONE                         BIT7            /**< When the I2C is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge a transmitted byte. This occurs on the last byte of the transmission, indicating that the transmission is done. */
#define I2C_INT_TX_ABRT                         BIT6            /**< This bit indicates if I2C as an I2C transmitter, is unable to complete the intended actions on the contents of the transmit FIFO. */
#define I2C_INT_RD_REQ                          BIT5            /**< This bit is set to 1 when acting as a slave and another I2C master is attempting to read data. */
#define I2C_INT_TX_EMPTY                        BIT4            /**< This bit is set to 1 when the transmit buffer is at or below the threshold value. */
#define I2C_INT_TX_OVER                         BIT3            /**< Set during transmit if the transmit buffer is filled to Tx FIFO depth and the processor attempts to issue another I2C command. */
#define I2C_INT_RX_FULL                         BIT2            /**< Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register. */
#define I2C_INT_RX_OVER                         BIT1            /**< Set if the receive buffer is completely filled to Rx FIFO depth and an additional byte is received from an external I2C device. */
#define I2C_INT_RX_UNDER                        BIT0            /**< Set if the processor attempts to read the receive buffer when it is empty by reading. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define I2C_GET_INT(INT)    (((INT) == I2C_INT_GEN_CALL) || \
                             ((INT) == I2C_INT_START_DET) || \
                             ((INT) == I2C_INT_STOP_DET) || \
                             ((INT) == I2C_INT_ACTIVITY) || \
                             ((INT) == I2C_INT_RX_DONE)  || \
                             ((INT) == I2C_INT_TX_ABRT) || \
                             ((INT) == I2C_INT_RD_REQ)   || \
                             ((INT) == I2C_INT_TX_EMPTY) || \
                             ((INT) == I2C_INT_TX_OVER)  || \
                             ((INT) == I2C_INT_RX_FULL) || \
                             ((INT) == I2C_INT_RX_OVER)  || \
                             ((INT) == I2C_INT_RX_UNDER) || \
                             ((INT) == I2C_INT_MST_ON_HOLD))
/** @} */ /* End of group I2C_INTERRUPTS */

/**
 * @defgroup I2C_FLAGS I2C Flags
 * @{
 */

#define I2C_FLAG_SLV_HOLD_RX_FIFO_FULL          BIT10           /**< The BUS hold in slave mode due to the Rx FIFO being full and an additional byte being received. */
#define I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY         BIT9            /**< The BUS hold in slave mode for the read request when the Tx FIFO is empty. */
#define I2C_FLAG_MST_HOLD_RX_FIFO_FULL          BIT8            /**< The BUS hold in master mode due to Rx FIFO is full and additional byte has been received. */
#define I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY         BIT7            /**< The BUS hold when the master holds the bus because of the Tx FIFO being empty. */
#define I2C_FLAG_SLV_ACTIVITY                   BIT6            /**< Slave FSM activity status. */
#define I2C_FLAG_MST_ACTIVITY                   BIT5            /**< Master FSM activity status. */
#define I2C_FLAG_RFF                            BIT4            /**< Receive FIFO completely full. */
#define I2C_FLAG_RFNE                           BIT3            /**< Receive FIFO not empty. */
#define I2C_FLAG_TFE                            BIT2            /**< Transmit FIFO completely empty. */
#define I2C_FLAG_TFNF                           BIT1            /**< Transmit FIFO not full. */
#define I2C_FLAG_ACTIVITY                       BIT0            /**< I2C activity status. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_SLV_HOLD_RX_FIFO_FULL) || \
                               ((FLAG) == I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_MST_HOLD_RX_FIFO_FULL) || \
                               ((FLAG) == I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY) || \
                               ((FLAG) == I2C_FLAG_SLV_ACTIVITY) || \
                               ((FLAG) == I2C_FLAG_MST_ACTIVITY) || \
                               ((FLAG) == I2C_FLAG_RFF) || \
                               ((FLAG) == I2C_FLAG_RFNE) || \
                               ((FLAG) == I2C_FLAG_TFE) || \
                               ((FLAG) == I2C_FLAG_TFNF) || \
                               ((FLAG) == I2C_FLAG_ACTIVITY))
/** @} */ /* End of group I2C_FLAGS */

/**
 * @defgroup I2C_TRANSMIT_ABORT_SOURCE I2C Transmit Abort Source
 * @{
 */

#define ABRT_SLVRD_INTX                         BIT15           /**< When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command. */
#define ABRT_SLV_ARBLOST                        BIT14           /**< Slave lost the bus while transmitting data to a remote master. */
#define ABRT_SLVFLUSH_TXFIFO                    BIT13           /**< Slave has received a read command and some data exists in the Tx FIFO so the slave issues an I2C_INT_TX_ABRT interrupt to flush old data in Tx FIFO. */
#define ARB_LOST                                BIT12           /**< Master has lost arbitration or the slave transmitter has lost arbitration. */
#define ABRT_MASTER_DIS                         BIT11           /**< User tries to initiate a master operation with the master mode disabled. */
#define ABRT_10B_RD_NORSTRT                     BIT10           /**< The restart is disabled and the master sends a read command in 10-bit address mode. */
#define ABRT_SBYTE_NORSTRT                      BIT9            /**< The restart is disabled and the user is trying to send a START byte. */
#define ABRT_HS_NORSTRT                         BIT8            /**< The restart is disabled and the user is trying to use the master to transfer data in high speed mode. */
#define ABRT_SBYTE_ACKDET                       BIT7            /**< Master has sent a START byte and the START byte was acknowledged (wrong behavior). */
#define ABRT_HS_ACKDET                          BIT6            /**< Master is in High Speed mode and the High Speed master code was acknowledged (wrong behavior). */
#define ABRT_GCALL_READ                         BIT5            /**< Sent a general call but the user programmed the byte following the general call to be a read from the bus. */
#define ABRT_GCALL_NOACK                        BIT4            /**< Sent a general call and no slave on the bus acknowledged the general call. */
#define ABRT_TXDATA_NOACK                       BIT3            /**< Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave. */
#define ABRT_10ADDR2_NOACK                      BIT2            /**< Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave. */
#define ABRT_10ADDR1_NOACK                      BIT1            /**< Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave. */
#define ABRT_7B_ADDR_NOACK                      BIT0            /**< Master is in 7-bit address mode and the address sent was not acknowledged by any slave. */
#define MS_ALL_ABORT                            (ARB_LOST | ABRT_MASTER_DIS | ABRT_TXDATA_NOACK | \
                                                 ABRT_10ADDR2_NOACK | ABRT_10ADDR1_NOACK | ABRT_7B_ADDR_NOACK) /**< All types of ABORT. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_EVENT(EVENT) (((EVENT) == ABRT_SLVRD_INTX) || \
                             ((EVENT) == ABRT_SLV_ARBLOST) || \
                             ((EVENT) == ABRT_SLVFLUSH_TXFIFO) || \
                             ((EVENT) == ARB_LOST) || \
                             ((EVENT) == ABRT_MASTER_DIS) || \
                             ((EVENT) == ABRT_10B_RD_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_NORSTRT) || \
                             ((EVENT) == ABRT_HS_NORSTRT) || \
                             ((EVENT) == ABRT_SBYTE_ACKDET) || \
                             ((EVENT) == ABRT_HS_ACKDET) || \
                             ((EVENT) == ABRT_GCALL_READ) || \
                             ((EVENT) == ABRT_GCALL_NOACK) || \
                             ((EVENT) == ABRT_TXDATA_NOACK) || \
                             ((EVENT) == ABRT_10ADDR2_NOACK) || \
                             ((EVENT) == ABRT_10ADDR1_NOACK) || \
                             ((EVENT) == ABRT_7B_ADDR_NOACK))
/** @} */ /* End of group I2C_TRANSMIT_ABORT_SOURCE */

#if (I2C_SUPPORT_WRAPPER_MODE == 1)
/**
 * @defgroup I2C_WRAPPER_TRANS_MODE I2C Wrapper Trans Mode
 * @{
 */

/**
 * @brief I2C wrapper transfer mode.
 */
typedef enum
{
    I2C_WRAPPER_TRANS_MODE_WRITE       = 0,    /**< Write mode in wrapper mode. */
    I2C_WRAPPER_TRANS_MODE_READ        = 1,    /**< Read mode in wrapper mode. */
    I2C_WRAPPER_TRANS_MODE_REPEAT_READ = 2,    /**< Repeat read mode in wrapper mode. */
    I2C_WRAPPER_TRANS_MODE_DMA_READ    = 3,    /**< DMA read mode in wrapper mode. */
} I2CWrapperTransMode_TypeDef;

/** @} */ /* End of group I2C_WRAPPER_TRANS_MODE */
#endif

#if (I2C_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup I2C_ACTION I2C Action
 * @{
 */

/**
 * @brief I2C action.
 */
typedef enum
{
    I2C_ACTION_START = 0,       /**< I2C action start. */
} I2CAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_I2C_ACTION(ACTION) ((ACTION) == I2C_ACTION_START)

/** @} */ /* End of group I2C_ACTION */

#endif

/** @} */ /* End of group I2C_Exported_Constants */

/**
 * @defgroup I2C_Exported_Types I2C Exported Types
 * @{
 */

/**
 * @brief I2C Init structure definition.
 */
typedef struct
{
    uint32_t I2C_Clock;                    /**< Specifies the I2C source clock frequency in Hz, default 40000000.
                                                This parameter provides the base frequency for I2C clock speed calculation. */

    uint32_t I2C_ClockSpeed;               /**< Specifies SCK speed on the I2C bus.
                                                This parameter must be set to a value lower than or equal to 1MHz. */

    I2CDeviceMode_TypeDef I2C_DeviceMode;  /**< Specifies the I2C device mode.
                                                This parameter can be a value of @ref I2C_DEVICE_MODE. */

    I2CAddressMode_TypeDef I2C_AddressMode;/**< Specifies the I2C address mode.
                                                This parameter can be a value of @ref I2C_ADDRESS_MODE. */

    uint16_t I2C_SlaveAddress;             /**< Specifies the target address in master mode,
                                                or the device's own address in slave mode.
                                                This parameter can be a 7-bit or 10-bit address. */

    FunctionalState I2C_Ack;               /**< Enables or disables the general call acknowledgement.
                                                This parameter is only applicable in slave mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint32_t I2C_TxThresholdLevel;         /**< Specifies the transmit FIFO Threshold
                                                to trigger interrupt @ref I2C_INT_TX_EMPTY.
                                                This parameter can be a value less than I2C_TX_FIFO_SIZE. */

    uint32_t I2C_RxThresholdLevel;         /**< Specifies the receive FIFO Threshold
                                                to trigger interrupt @ref I2C_INT_RX_FULL.
                                                This parameter can be a value less than I2C_RX_FIFO_SIZE. */

    FunctionalState I2C_TxDMAEn;           /**< Specifies the Tx DMA mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState I2C_RxDMAEn;           /**< Specifies the Rx DMA mode.
                                                This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  I2C_TxWaterlevel;             /**< Specifies the DMA tx water level.
                                                The best value is I2C Tx FIFO depth - Tx DMA MSize. */

    uint8_t  I2C_RxWaterlevel;             /**< Specifies the DMA rx water level.
                                                The best value is I2C Rx DMA MSize - 1. */

    uint8_t  I2C_RisingTimeNs;             /**< Specifies the I2C SDA/SCL rising time in ns. */

} I2C_InitTypeDef;

/** @} */ /* End of group I2C_Exported_Types */

/**
 * @defgroup I2C_Exported_Functions I2C Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the I2Cx peripheral registers to their default reset values.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_i2c0_init(void)
 * {
 *     I2C_DeInit(I2C0);
 * }
 * @endcode
 */
void I2C_DeInit(I2C_TypeDef *I2Cx);

/**
 * @brief Initialize the I2Cx peripheral according to the specified parameters in the I2C_InitStruct.
 *
 * @param[in] I2Cx            Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_InitStruct  Pointer to an I2C_InitTypeDef structure that contains the configuration information for the I2C peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_i2c0_init(void)
 * {
 *     RCC_ClockCmd(I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviceMode    = I2C_DEVICE_MODE_MASTER;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_ADDRESS_MODE_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = 0x50;
 *     I2C_InitStruct.I2C_Ack           = ENABLE;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct);

/**
 * @brief Enable or disable the specified I2C peripheral.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the I2Cx peripheral.
 *                      This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_i2c0_init(void)
 * {
 *     RCC_ClockCmd(I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviceMode    = I2C_DEVICE_MODE_MASTER;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_ADDRESS_MODE_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = 0x50;
 *     I2C_InitStruct.I2C_Ack           = ENABLE;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

/**
 * @brief Check if I2C has an abort status.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The status of I2Cx, refer to @ref I2C_STATUS.
 * @retval I2C_SUCCESS              I2C transfer success.
 * @retval I2C_ARB_LOST             Master or slave transmitter has lost arbitration.
 * @retval I2C_ABRT_MASTER_DIS      Master operation initiated with the master mode disabled.
 * @retval I2C_ABRT_TXDATA_NOACK    Transmitted data byte was not acknowledged by the slave.
 * @retval I2C_ABRT_10ADDR2_NOACK   Second byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_10ADDR1_NOACK   First byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_7B_ADDR_NOACK   7-bit address was not acknowledged by any slave.
 * @retval I2C_ERR_TIMEOUT          I2C transfer timeout error.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_CheckAbortStatus(I2C0);
 * }
 * @endcode
 */
I2C_Status I2C_CheckAbortStatus(I2C_TypeDef *I2Cx);

/**
 * @brief Fill each I2C_InitStruct member with its default value.
 *
 * @note The default settings for the I2C_InitStruct member are shown in the following table:
 *         | I2C_InitStruct member | Default value                    |
 *         |:---------------------:|:--------------------------------:|
 *         | I2C_Clock             | 40000000                         |
 *         | I2C_ClockSpeed        | 400000                           |
 *         | I2C_DeviceMode        | @ref I2C_DEVICE_MODE_MASTER      |
 *         | I2C_AddressMode       | @ref I2C_ADDRESS_MODE_7BIT       |
 *         | I2C_SlaveAddress      | 0                                |
 *         | I2C_Ack               | ENABLE                           |
 *         | I2C_TxThresholdLevel  | 0                                |
 *         | I2C_RxThresholdLevel  | 0                                |
 *         | I2C_TxDMAEn           | DISABLE                          |
 *         | I2C_RxDMAEn           | DISABLE                          |
 *         | I2C_TxWaterlevel      | 23                               |
 *         | I2C_RxWaterlevel      | 1                                |
 *         | I2C_RisingTimeNs      | 50                               |
 *
 * @param[in] I2C_InitStruct  Pointer to a I2C_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_i2c0_init(void)
 * {
 *     RCC_ClockCmd(I2C0_CLOCK, ENABLE);
 *
 *     I2C_InitTypeDef  I2C_InitStruct;
 *     I2C_StructInit(&I2C_InitStruct);
 *
 *     I2C_InitStruct.I2C_ClockSpeed    = 100000;
 *     I2C_InitStruct.I2C_DeviceMode    = I2C_DEVICE_MODE_MASTER;
 *     I2C_InitStruct.I2C_AddressMode   = I2C_ADDRESS_MODE_7BIT;
 *     I2C_InitStruct.I2C_SlaveAddress  = 0x50;
 *     I2C_InitStruct.I2C_Ack           = ENABLE;
 *
 *     I2C_Init(I2C0, &I2C_InitStruct);
 *     I2C_Cmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct);

/**
 * @brief Send data in master mode through the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] pBuf  Pointer to the data buffer to be transmitted.
 * @param[in] len   Data length to send.
 *
 * @return The status of I2Cx, refer to @ref I2C_STATUS.
 * @retval I2C_SUCCESS              I2C transfer success.
 * @retval I2C_ARB_LOST             Master or slave transmitter has lost arbitration.
 * @retval I2C_ABRT_MASTER_DIS      Master operation initiated with the master mode disabled.
 * @retval I2C_ABRT_TXDATA_NOACK    Transmitted data byte was not acknowledged by the slave.
 * @retval I2C_ABRT_10ADDR2_NOACK   Second byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_10ADDR1_NOACK   First byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_7B_ADDR_NOACK   7-bit address was not acknowledged by any slave.
 * @retval I2C_ERR_TIMEOUT          I2C transfer timeout error.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01, 0x02, 0x03, 0x04};
 *     I2C_MasterWrite(I2C0, data, 4);
 * }
 * @endcode
 */
I2C_Status I2C_MasterWrite(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 * @brief Send data from two buffers in master mode through the I2Cx peripheral.
 *
 * @param[in] I2Cx   Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] pBuf   Pointer to the first data buffer to be transmitted.
 * @param[in] len    First data buffer length to send.
 * @param[in] pbuf2  Pointer to the second data buffer to be transmitted.
 * @param[in] len2   Second data buffer length to send.
 *
 * @return The status of I2Cx, refer to @ref I2C_STATUS.
 * @retval I2C_SUCCESS              I2C transfer success.
 * @retval I2C_ARB_LOST             Master or slave transmitter has lost arbitration.
 * @retval I2C_ABRT_MASTER_DIS      Master operation initiated with the master mode disabled.
 * @retval I2C_ABRT_TXDATA_NOACK    Transmitted data byte was not acknowledged by the slave.
 * @retval I2C_ABRT_10ADDR2_NOACK   Second byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_10ADDR1_NOACK   First byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_7B_ADDR_NOACK   7-bit address was not acknowledged by any slave.
 * @retval I2C_ERR_TIMEOUT          I2C transfer timeout error.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0x01, 0x02, 0x03, 0x04};
 *     uint8_t data1[10] = {0x01, 0x02, 0x03, 0x04};
 *     I2C_MasterWriteDevice(I2C0, data, 4, data1, 4);
 * }
 * @endcode
 */
I2C_Status I2C_MasterWriteDevice(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len, uint8_t *pbuf2,
                                 uint32_t len2);

/**
 * @brief Read data in master mode through the I2Cx peripheral.
 *
 * @param[in] I2Cx   Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[out] pBuf  Data buffer to receive data.
 * @param[in] len    Read data length.
 *
 * @return The status of I2Cx, refer to @ref I2C_STATUS.
 * @retval I2C_SUCCESS              I2C transfer success.
 * @retval I2C_ARB_LOST             Master or slave transmitter has lost arbitration.
 * @retval I2C_ABRT_MASTER_DIS      Master operation initiated with the master mode disabled.
 * @retval I2C_ABRT_TXDATA_NOACK    Transmitted data byte was not acknowledged by the slave.
 * @retval I2C_ABRT_10ADDR2_NOACK   Second byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_10ADDR1_NOACK   First byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_7B_ADDR_NOACK   7-bit address was not acknowledged by any slave.
 * @retval I2C_ERR_TIMEOUT          I2C transfer timeout error.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data[10] = {0};
 *     I2C_MasterRead(I2C0, data, 10);
 * }
 * @endcode
 */
I2C_Status I2C_MasterRead(I2C_TypeDef *I2Cx, uint8_t *pBuf, uint16_t len);

/**
 * @brief Send and read data in master mode through the I2Cx peripheral.
 *
 * @note Read data with a timeout mechanism.
 *
 * @param[in] I2Cx       Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] pWriteBuf  Data buffer to send before read.
 * @param[in] Writelen   Send data length.
 * @param[out] pReadBuf  Data buffer to receive.
 * @param[in] Readlen    Receive data length.
 *
 * @return The status of I2Cx, refer to @ref I2C_STATUS.
 * @retval I2C_SUCCESS              I2C transfer success.
 * @retval I2C_ARB_LOST             Master or slave transmitter has lost arbitration.
 * @retval I2C_ABRT_MASTER_DIS      Master operation initiated with the master mode disabled.
 * @retval I2C_ABRT_TXDATA_NOACK    Transmitted data byte was not acknowledged by the slave.
 * @retval I2C_ABRT_10ADDR2_NOACK   Second byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_10ADDR1_NOACK   First byte of the 10-bit address was not acknowledged by any slave.
 * @retval I2C_ABRT_7B_ADDR_NOACK   7-bit address was not acknowledged by any slave.
 * @retval I2C_ERR_TIMEOUT          I2C transfer timeout error.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t tx_data[10] = {0x01, 0x02, 0x03, 0x04};
 *     uint8_t rx_data[10] = {0};
 *     I2C_RepeatRead(I2C0, tx_data, 4, rx_data, 10);
 * }
 * @endcode
 */
I2C_Status I2C_RepeatRead(I2C_TypeDef *I2Cx, uint8_t *pWriteBuf, uint16_t Writelen,
                          uint8_t *pReadBuf, uint16_t Readlen);

/**
 * @brief Configure the specified I2C interrupt.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_IT    This parameter can be one of the following values, refer to @ref I2C_INTERRUPTS.
 *                      - I2C_INT_MST_ON_HOLD: When master Tx FIFO is empty and no stop bit command is issued, master will hold the SCL low.
 *                      - I2C_INT_GEN_CALL: Set only when a general call address is received and it is acknowledged.
 *                      - I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                           interface regardless of whether I2C is operating in slave or master mode.
 *                      - I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface
 *                           regardless of whether I2C is operating in slave or master mode.
 *                      - I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *                      - I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                           master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                           transmission, indicating that the transmission is done.
 *                      - I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                           intended actions on the contents of the transmit FIFO.
 *                      - I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                           attempting to read data.
 *                      - I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value.
 *                      - I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to Tx FIFO depth and
 *                           the processor attempts to issue another I2C command.
 *                      - I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                           IC_RX_TL register.
 *                      - I2C_INT_RX_OVER: Set if the receive buffer is completely filled to Rx FIFO depth and an
 *                           additional byte is received from an external I2C device.
 *                      - I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 * @param[in] NewState  Enable or disable the specified I2C interrupt.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the specified I2C interrupt.
 *                      - DISABLE: Disable the specified I2C interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     I2C_INTConfig(I2C0, I2C_INT_STOP_DET, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = I2C0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * @endcode
 */
void I2C_INTConfig(I2C_TypeDef *I2Cx, uint16_t I2C_IT, FunctionalState NewState);

/**
 * @brief Clear the specified I2C interrupt pending bit.
 *
 * @param[in] I2Cx    Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_IT  This parameter can be one of the following values, refer to @ref I2C_INTERRUPTS.
 *                    - I2C_INT_GEN_CALL: Set only when a general call address is received and it is acknowledged.
 *                    - I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                      interface regardless of whether I2C is operating in slave or master mode.
 *                    - I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                      of whether I2C is operating in slave or master mode.
 *                    - I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *                    - I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                      master does not acknowledge a transmitted byte. This occurs on the last byte of the
 *                      transmission, indicating that the transmission is done.
 *                    - I2C_INT_TX_ABRT: This bit indicates if I2C as an I2C transmitter, is unable to complete the
 *                      intended actions on the contents of the transmit FIFO.
 *                    - I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master is
 *                      attempting to read data.
 *                    - I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value.
 *                    - I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to Tx FIFO depth and
 *                      the processor attempts to issue another I2C command.
 *                    - I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                      IC_RX_TL register.
 *                    - I2C_INT_RX_OVER: Set if the receive buffer is completely filled to Rx FIFO depth and an
 *                      additional byte is received from an external I2C device.
 *                    - I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void I2C0_Handler(void)
 * {
 *     if (I2C_GetINTStatus(I2C0, I2C_INT_STOP_DET) == SET)
 *     {
 *         //Add user code here.
 *         I2C_ClearINTPendingBit(I2C0, I2C_INT_STOP_DET);
 *     }
 * }
 * @endcode
 */
void I2C_ClearINTPendingBit(I2C_TypeDef *I2Cx, uint16_t I2C_IT);

/**
 * @brief Set slave device address.
 *
 * @param[in] I2Cx     Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] Address  Specifies the target address in master mode, or the device's own address in slave mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_SetSlaveAddress(I2C0, 0x55);
 * }
 * @endcode
 */
void I2C_SetSlaveAddress(I2C_TypeDef *I2Cx, uint16_t Address);

/**
 * @brief Write command through the I2Cx peripheral.
 *
 * @param[in] I2Cx       Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] command    Command of write or read.
 *                       - I2C_READ_CMD: Read command. Data to be transmitted can be 0 in this situation.
 *                       - I2C_WRITE_CMD: Write command.
 * @param[in] data       Data to be transmitted.
 * @param[in] StopState  Whether to send a stop signal.
 *                       - ENABLE: Send stop signal.
 *                       - DISABLE: Do not send stop signal.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_SendCmd(I2C0, I2C_WRITE_CMD, 0xAA, ENABLE);
 * }
 * @endcode
 */
void I2C_SendCmd(I2C_TypeDef *I2Cx, I2CSendCommand_TypeDef command, uint8_t data,
                 FunctionalState StopState);

/**
 * @brief Receive data by the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The most recent received data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data = I2C_ReceiveData(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx);

/**
 * @brief Get data length in Rx FIFO of the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Rx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_GetRxFIFOLen(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_GetRxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * @brief Get data length in Tx FIFO of the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Tx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_GetTxFIFOLen(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_GetTxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * @brief Clear all I2C interrupt.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_ClearAllINT(I2C0);
 * }
 * @endcode
 */
void I2C_ClearAllINT(I2C_TypeDef *I2Cx);

/**
 * @brief Check whether the specified I2C flag is set.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_FLAG  Specify the flag to check.
 *                      This parameter can be one of the following values, refer to @ref I2C_FLAGS.
 *                      - I2C_FLAG_SLV_HOLD_RX_FIFO_FULL: The BUS hold in slave mode due to the Rx FIFO being full and an additional byte being received.
 *                      - I2C_FLAG_SLV_HOLD_TX_FIFO_EMPTY: The BUS hold in slave mode for the read request when the Tx FIFO is empty.
 *                      - I2C_FLAG_MST_HOLD_RX_FIFO_FULL: The BUS hold in master mode due to Rx FIFO is full and additional byte has been received.
 *                      - I2C_FLAG_MST_HOLD_TX_FIFO_EMPTY: The BUS hold when the master holds the bus because of the Tx FIFO being empty.
 *                      - I2C_FLAG_SLV_ACTIVITY: Slave FSM activity status.
 *                      - I2C_FLAG_MST_ACTIVITY: Master FSM activity status.
 *                      - I2C_FLAG_RFF: Receive FIFO completely full.
 *                      - I2C_FLAG_RFNE: Receive FIFO not empty.
 *                      - I2C_FLAG_TFE: Transmit FIFO completely empty.
 *                      - I2C_FLAG_TFNF: Transmit FIFO not full.
 *                      - I2C_FLAG_ACTIVITY: I2C activity status.
 *
 * @return The status of I2C flag (SET or RESET).
 * @retval SET    The specified I2C flag is set.
 * @retval RESET  The specified I2C flag is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     FlagStatus flag_status = I2C_GetFlagState(I2C0, I2C_FLAG_RFF);
 * }
 * @endcode
 */
FlagStatus I2C_GetFlagState(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG);

/**
 * @brief Check whether the last I2Cx event is equal to the one passed as parameter.
 *
 * @param[in] I2Cx       Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_EVENT  Specify the event to be checked about I2C transmit abort status.
 *                       This parameter can be one of the following values, refer to @ref I2C_TRANSMIT_ABORT_SOURCE.
 *                       - ABRT_SLVRD_INTX: When the processor side responds to a slave mode request for data to be transmitted to a remote master and user send read command.
 *                       - ABRT_SLV_ARBLOST: Slave lost the bus while transmitting data to a remote master.
 *                       - ABRT_SLVFLUSH_TXFIFO: Slave has received a read command and some data exists in the Tx FIFO so the slave issues an I2C_INT_TX_ABRT interrupt to flush old data in Tx FIFO.
 *                       - ARB_LOST: Master has lost arbitration or the slave transmitter has lost arbitration.
 *                       - ABRT_MASTER_DIS: User tries to initiate a master operation with the master mode disabled.
 *                       - ABRT_10B_RD_NORSTRT: The restart is disabled and the master sends a read command in 10-bit address mode.
 *                       - ABRT_SBYTE_NORSTRT: The restart is disabled and the user is trying to send a START byte.
 *                       - ABRT_HS_NORSTRT: The restart is disabled and the user is trying to use the master to transfer data in High Speed mode.
 *                       - ABRT_SBYTE_ACKDET: Master has sent a START byte and the START byte was acknowledged (wrong behavior).
 *                       - ABRT_HS_ACKDET: Master is in High Speed mode and the High Speed master code was acknowledged (wrong behavior).
 *                       - ABRT_GCALL_READ: Sent a general call but the user programmed the byte following the general call to be a read from the bus.
 *                       - ABRT_GCALL_NOACK: Sent a general call and no slave on the bus acknowledged the general call.
 *                       - ABRT_TXDATA_NOACK: Master sent data byte(s) following the address, it did not receive an acknowledge from the remote slave.
 *                       - ABRT_10ADDR2_NOACK: Master is in 10-bit address mode and the second address byte of the 10-bit address was not acknowledged by any slave.
 *                       - ABRT_10ADDR1_NOACK: Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave.
 *                       - ABRT_7B_ADDR_NOACK: Master is in 7-bit address mode and the address sent was not acknowledged by any slave.
 *
 * @return The status of I2C event (SET or RESET).
 * @retval SET    The last I2C event matches the specified event.
 * @retval RESET  The last I2C event does not match the specified event.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     FlagStatus flag_status = I2C_CheckEvent(I2C0, ABRT_SLVRD_INTX);
 * }
 * @endcode
 */
FlagStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT);

/**
 * @brief Get the specified I2C interrupt status.
 *
 * @param[in] I2Cx    Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_IT  This parameter can be one of the following values, refer to @ref I2C_INTERRUPTS.
 *                    - I2C_INT_MST_ON_HOLD: When master Tx FIFO is empty and no stop bit command is issued, master will hold the SCL low.
 *                    - I2C_INT_GEN_CALL: Set only when a general call address is received and it is acknowledged.
 *                    - I2C_INT_START_DET: Indicates whether a START or RESTART condition has occurred on the I2C
 *                         interface regardless of whether I2C is operating in slave or master mode.
 *                    - I2C_INT_STOP_DET: Indicates whether a STOP condition has occurred on the I2C interface regardless
 *                         of whether I2C is operating in slave or master mode.
 *                    - I2C_INT_ACTIVITY: This bit captures I2C activity and stays set until it is cleared.
 *                    - I2C_INT_RX_DONE: When the I2C is acting as a slave-transmitter, this bit is set to 1 if the
 *                         master does not acknowledge a transmitted byte. This occurs on the last byte of
 *                         the transmission, indicating that the transmission is done.
 *                    - I2C_INT_TX_ABRT: This bit indicates if I2C, as an I2C transmitter, is unable to complete the
 *                         intended actions on the contents of the transmit FIFO.
 *                    - I2C_INT_RD_REQ: This bit is set to 1 when acting as a slave and another I2C master
 *                         is attempting to read data.
 *                    - I2C_INT_TX_EMPTY: This bit is set to 1 when the transmit buffer is at or below the threshold value.
 *                    - I2C_INT_TX_OVER: Set during transmit if the transmit buffer is filled to Tx FIFO depth and
 *                         the processor attempts to issue another I2C command.
 *                    - I2C_INT_RX_FULL: Set when the receive buffer reaches or goes above the RX_TL threshold in the
 *                         IC_RX_TL register.
 *                    - I2C_INT_RX_OVER: Set if the receive buffer is completely filled to Rx FIFO depth and an
 *                         additional byte is received from an external I2C device.
 *                    - I2C_INT_RX_UNDER: Set if the processor attempts to read the receive buffer when it is empty by reading.
 *
 * @return The status of I2C interrupt (SET or RESET).
 * @retval SET    The specified I2C interrupt is set.
 * @retval RESET  The specified I2C interrupt is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     ITStatus int_status = I2C_GetINTStatus(I2C0, I2C_INT_RD_REQ);
 * }
 * @endcode
 */
ITStatus I2C_GetINTStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT);

/**
 * @brief Enable or disable the I2Cx DMA interface.
 *
 * @param[in] I2Cx         Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_DMAReq   Specify the I2C DMA transfer request to be enabled or disabled.
 *                         This parameter can be one of the following values, refer to @ref I2C_DMA_REQUESTS.
 *                         - I2C_DMA_REQ_TX: DMA transfer sending request.
 *                         - I2C_DMA_REQ_RX: DMA transfer receiving request.
 * @param[in] NewState     New state of the selected I2C DMA transfer request.
 *                         This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_DMACmd(I2C0, I2C_DMA_REQ_TX, ENABLE);
 * }
 * @endcode
 */
void I2C_DMACmd(I2C_TypeDef *I2Cx, I2CDMARequests_TypeDef I2C_DMAReq,
                FunctionalState NewState);

/**
 * @brief Set the I2C clock speed, the function needs to be called when I2C disabled.
 *
 * @param[in] I2Cx            Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_ClockSpeed  Specifies the I2C clock speed.
 *                          This parameter must be set to a value lower than or equal to 1000000.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c_demo(void)
 * {
 *     I2C_SetClockSpeed(I2C0, 400000);
 * }
 * @endcode
 */
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed);

/**
 * @brief I2C clock divider config.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] ClockSrc  Specifies the I2C clock source, refer to @ref I2C_CLOCK_SOURCE.
 * @param[in] ClockDiv  Specifies the I2C clock divider.
 *                      This parameter can refer to @ref I2C_CLOCK_DIVIDER.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_i2c_init(void)
 * {
 *     I2C_SetClock(I2C0, I2C_CLOCK_SRC_40M, I2C_CLOCK_DIV_1);
 * }
 * @endcode
 */
void I2C_SetClock(I2C_TypeDef *I2Cx, uint16_t ClockSrc, uint16_t ClockDiv);


#if (I2C_SUPPORT_WRAPPER_MODE == 1)

/**
 * @brief Enable or disable the I2C wrapper mode.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the wrapper mode.
 *                      This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_WrapperModeCmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_WrapperModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

/**
 * @brief Set the I2C wrapper transfer mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] mode  Transfer mode to set. Refer to @ref I2C_WRAPPER_TRANS_MODE.
 *
 * @return The status of set transfer mode.
 * @retval true   Set successfully.
 * @retval false  Set failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     bool result = I2C_WrapperSetTransMode(I2C0, I2C_WRAPPER_TRANS_MODE_WRITE);
 * }
 * @endcode
 */
bool I2C_WrapperSetTransMode(I2C_TypeDef *I2Cx, uint32_t mode);

/**
 * @brief Set the I2C wrapper write data number.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] num   Number of bytes to write.
 *                  This parameter must be set to a value between 1 and 24.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_WrapperSetWriteNum(I2C0, 4);
 * }
 * @endcode
 */
void I2C_WrapperSetWriteNum(I2C_TypeDef *I2Cx, uint8_t num);

/**
 * @brief Set the I2C wrapper write data.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] buf   Pointer to the data buffer to be written.
 * @param[in] num   Number of bytes in the data buffer.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data[4] = {0x01, 0x02, 0x03, 0x04};
 *     I2C_WrapperSetWriteData(I2C0, data, 4);
 * }
 * @endcode
 */
void I2C_WrapperSetWriteData(I2C_TypeDef *I2Cx, const uint8_t *buf, uint8_t num);

/**
 * @brief Get data length in Tx FIFO via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Tx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_WrapperGetTxFIFOLen(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_WrapperGetTxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * @brief Clear the I2C wrapper Tx FIFO.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_WrapperClearTxFIFO(I2C0);
 * }
 * @endcode
 */
void I2C_WrapperClearTxFIFO(I2C_TypeDef *I2Cx);

/**
 * @brief Set the I2C wrapper read data number.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] num   Number of bytes to read.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_WrapperSetReadNum(I2C0, 10);
 * }
 * @endcode
 */
void I2C_WrapperSetReadNum(I2C_TypeDef *I2Cx, uint16_t num);

/**
 * @brief Receive data via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The received data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data = I2C_WrapperReceiveData(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_WrapperReceiveData(I2C_TypeDef *I2Cx);

/**
 * @brief Get data length in Rx FIFO via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Rx FIFO.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     uint8_t data_len = I2C_WrapperGetRxFIFOLen(I2C0);
 * }
 * @endcode
 */
uint8_t I2C_WrapperGetRxFIFOLen(I2C_TypeDef *I2Cx);

/**
 * @brief Start I2C wrapper transfer.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_WrapperTransStart(I2C0);
 * }
 * @endcode
 */
void I2C_WrapperTransStart(I2C_TypeDef *I2Cx);

/**
 * @brief Check whether I2C wrapper mode is busy.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The status of busy.
 * @retval true   Busy.
 * @retval false  Not busy.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     bool busy = I2C_WrapperBusyCheck(I2C0);
 * }
 * @endcode
 */
bool I2C_WrapperBusyCheck(I2C_TypeDef *I2Cx);
#endif

#if (I2C_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the I2C RAP mode.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the RAP mode.
 *                      This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_RAPModeCmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_RAPModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

/**
 * @brief Trigger the specified I2C action.
 *
 * @param[in] I2Cx    Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] Action  Action to be triggered. Refer to @ref I2C_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_ActionTrigger(I2C0, I2C_ACTION_START);
 * }
 * @endcode
 */
void I2C_ActionTrigger(I2C_TypeDef *I2Cx, uint32_t Action);

#endif

#if (I2C_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable the I2C auto clock mode.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the auto clock mode.
 *                      This parameter can be: ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void i2c0_demo(void)
 * {
 *     I2C_ClockAutoModeCmd(I2C0, ENABLE);
 * }
 * @endcode
 */
void I2C_ClockAutoModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState);

#endif

/** @} */ /* End of group I2C_Exported_Functions */

/** @} */ /* End of group I2C_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /*RTL_I2C_H*/
