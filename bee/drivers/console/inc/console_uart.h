/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _CONSOLE_UART_H_
#define _CONSOLE_UART_H_

#include <stdint.h>
#include <stdbool.h>
#include "console.h"
#include "rtl_uart.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * @defgroup APP_RWS_CONSOLE APP Console
 * @brief App console UART.
 * @{
 */

/**
 * @defgroup APP_RWS_CONSOLE_Exported_Types App Console Exported Types
 * @brief App console UART exported types.
 * @{
 */

/**
 * @brief Console UART event type.
 */
typedef enum
{
    CONSOLE_UART_EVENT_WAKE_UP, /**< Console UART wake-up event. */
} T_CONSOLE_UART_EVENT;

/** @brief Console UART callback used to notify console UART events. */
typedef void (*P_APP_CONSOLE_UART_CALLBACK)(T_CONSOLE_UART_EVENT);

/** @brief Console UART configuration. */
typedef struct
{
    bool        uart_tx_dma_enable;       /**< Enable or disable UART TX DMA. */
    bool        uart_rx_dma_enable;       /**< Enable or disable UART RX DMA. */
    uint8_t     one_wire_uart_support;    /**< One-wire UART support. */
    uint8_t     uart_tx_pinmux;           /**< UART TX pinmux. */
    uint8_t     uart_rx_pinmux;           /**< UART RX pinmux. */
    uint8_t     rx_wake_up_pinmux;        /**< UART RX wake-up pinmux. */
    uint8_t     enable_rx_wake_up;        /**< Enable or disable UART RX wake-up. */
    uint32_t    data_uart_baud_rate;      /**< Console UART baud rate. */
    uint16_t    uart_dma_rx_buffer_size;  /**< UART DMA RX buffer size. */
    P_APP_CONSOLE_UART_CALLBACK callback; /**< Console UART event callback. */
    UART_TypeDef *uart_id;                /**< UART peripheral. */
} T_CONSOLE_UART_CONFIG;

/** @} */ /* End of group APP_RWS_CONSOLE_Exported_Types */

/**
 * @defgroup APP_RWS_CONSOLE_Exported_Functions App Console Exported Functions
 * @brief App console UART exported functions.
 * @{
 */

/**
 * @brief Transmit data through the console UART.
 *
 * @param[in] handle Console UART handle created by @ref console_uart_create.
 * @param[in] buf    Pointer to the buffer to be transmitted.
 * @param[in] len    Length of the buffer in bytes.
 *
 * @return The result of the write operation.
 * @retval true  Write success.
 * @retval false Write failed.
 */
bool console_uart_write(void *handle, uint8_t *buf, uint32_t len);

/**
 * @brief Initialize the console UART with a callback.
 *
 * @param[in] handle     Console UART handle created by @ref console_uart_create.
 * @param[in] p_callback Callback used in the console UART module to notify registered events.
 *
 * @return The result of the initialization.
 * @retval true  Initialization success.
 * @retval false Initialization failed.
 */
bool console_uart_init(void *handle, T_CONSOLE_CBACK p_callback);

/**
 * @brief Delete the console UART.
 *
 * @param[in] handle Console UART handle to be deinitialized.
 *
 * @return The result of the deletion.
 * @retval true  Deletion success.
 * @retval false Deletion failed.
 */
bool console_uart_delete(void *handle);

/**
 * @brief Set the APP console UART configuration.
 *
 * @param[in]  cfg    Pointer to the console UART configuration parameters.
 * @param[out] handle Pointer to the created console UART handle.
 */
void console_uart_create(T_CONSOLE_UART_CONFIG *cfg, void **handle);

/**
 * @brief Initialize the APP console UART driver.
 *
 * @param[in] handle Console UART handle created by @ref console_uart_create.
 */
void console_uart_driver_init(void *handle);

/** @} */ /* End of group APP_RWS_CONSOLE_Exported_Functions */

/** @} */ /* End of group APP_RWS_CONSOLE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _CONSOLE_UART_H_ */
