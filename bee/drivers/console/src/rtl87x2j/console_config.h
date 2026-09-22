/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef CONSOLE_CONFIG_H
#define CONSOLE_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          CONSOLE UART Defines
 *============================================================================*/
#define CONSOLE_UART_SUPPORT_DYNAMIC_DMA_CHANNEL    0

/*============================================================================*
 *                          CONSOLE UART Config
 *============================================================================*/
#define CONSOLE_UART                                UART0
#define CONSOLE_UART_IRQn                           UART0_IRQn
#define CONSOLE_UART_CLOCK                          UART0_CLOCK
#define DMA_HANDSHAKE_CONSOLE_UART_TX               DMA_HANDSHAKE_UART0_TX
#define DMA_HANDSHAKE_CONSOLE_UART_RX               DMA_HANDSHAKE_UART0_RX

#define uart_tx_dma_ch_num                          DMA_CH_NUM0
#define UART_TX_DMA_CHANNEL_NUM                     uart_tx_dma_ch_num
#define UART_TX_DMA_CHANNEL                         DMA_GetDMAChannelx(UART_TX_DMA_CHANNEL_NUM)
#define UART_TX_DMA_IRQ                             DMA_GetDMAIRQx(UART_TX_DMA_CHANNEL_NUM)

#define uart_rx_dma_ch_num                          DMA_CH_NUM1
#define UART_RX_DMA_CHANNEL_NUM                     uart_rx_dma_ch_num
#define UART_RX_DMA_CHANNEL                         DMA_GetDMAChannelx(UART_RX_DMA_CHANNEL_NUM)
#define UART_RX_DMA_IRQ                             DMA_GetDMAIRQx(UART_RX_DMA_CHANNEL_NUM)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CONSOLE_CONFIG_H */
