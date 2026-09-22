/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#include <string.h>
#include <stdlib.h>
#include "os_sync.h"
#include "common_header.h"
#include "console_uart.h"
#include "os_mem.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "soc_log.h"
#include "console/src/rtl87x2j/console_config.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "soc_log.h"
#include "console/src/rtl87x2g/console_config.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "soc_log.h"
#include "console/src/rtl87x3d/console_config.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "soc_log.h"
#include "console/src/rtl87x3j/console_config.h"
#endif


void console_uart_handle_tx_done(void);
bool uart_send_by_cpu_action(uint8_t *buf, uint32_t len);
extern IRQn_Type DMA_GetDMAIRQx(uint8_t DMA_ChannelNum);

uint8_t *uart_rx_buf_addr = NULL;
uint16_t uart_tx_count = 0;

T_CONSOLE_CBACK p_console_callback = NULL;
static void *uart_context = &p_console_callback;

static uint8_t *uart_tx_curr_addr;
static uint32_t uart_tx_len;
static uint8_t tx_empty_need_handle = 0;

T_CONSOLE_UART_CONFIG g_console_uart;

/**
 * @brief  Uart interface process received data according to interrupt.
 *         If enable DMA, DMA will carry data from UART peripheral. DMA only need idle interrupt.
 *         DMA can trigger data uart interrupt every receive 128 bytes data, and
 *         the number has been setting in uart driver init.
 *         When uart rx timeout interrupt cause, app will read UART peripheral data until
 *         UART FIFO is empty.
 * @param  void
 * @return void
 */
void Data_Uart_Handler(void)
{
    uint32_t int_status = 0;
    uint16_t rx_count = 0;
    uint16_t fifo_count;

    UART_MaskINTConfig(CONSOLE_UART, UART_INT_MASK_TX_FIFO_EMPTY, ENABLE);

    int_status = UART_GetIID(CONSOLE_UART);

    if (UART_GetFlagStatus(CONSOLE_UART, UART_FLAG_RX_IDLE) == SET)
    {
        //clear Flag
        UART_INTConfig(CONSOLE_UART, UART_INT_RX_IDLE, DISABLE);

        if (g_console_uart.uart_rx_dma_enable)
        {
            //suspend will cause FIFO length + 1
            //read DMA FIFO length before suspend
            DMA_SuspendCmd(UART_RX_DMA_CHANNEL, ENABLE);
            /*should waiting or fifo_count will not right when rx one byte or three byte*/
            while (DMA_GetFIFOStatus(UART_RX_DMA_CHANNEL) != SET);
            //read DMA FIFO length before suspend
            fifo_count = DMA_GetTransferLen(UART_RX_DMA_CHANNEL);
            DMA_Cmd(UART_RX_DMA_CHANNEL_NUM, DISABLE);
            rx_count = fifo_count;
            if (p_console_callback)
            {
                p_console_callback(uart_context, CONSOLE_EVT_DATA_IND, uart_rx_buf_addr, rx_count);
            }

            DMA_SetDestinationAddress(UART_RX_DMA_CHANNEL, (uint32_t)uart_rx_buf_addr);
            DMA_SuspendCmd(UART_RX_DMA_CHANNEL, DISABLE);
            DMA_Cmd(UART_RX_DMA_CHANNEL_NUM, ENABLE);
            UART_INTConfig(CONSOLE_UART, UART_INT_RX_IDLE, ENABLE);
        }
    }

    if ((int_status == UART_INT_ID_RX_DATA_TIMEOUT) || (int_status == UART_INT_ID_RX_LEVEL_REACH))
    {
        rx_count = UART_GetRxFIFODataLen(CONSOLE_UART);
        UART_ReceiveData(CONSOLE_UART, uart_rx_buf_addr, rx_count);
        if (p_console_callback)
        {
            p_console_callback(uart_context, CONSOLE_EVT_DATA_IND, uart_rx_buf_addr, rx_count);
        }
    }
    else if (int_status == UART_INT_ID_TX_FIFO_EMPTY)
    {
        UART_INTConfig(CONSOLE_UART, UART_INT_TX_FIFO_EMPTY, (FunctionalState)DISABLE);
        UART_GetIID(CONSOLE_UART);
        if (uart_tx_len)
        {
            uart_send_by_cpu_action(uart_tx_curr_addr, uart_tx_len);
        }
        else
        {
            if (tx_empty_need_handle)
            {
                tx_empty_need_handle = 0;
                console_uart_handle_tx_done();
            }
        }
    }
    UART_MaskINTConfig(CONSOLE_UART, UART_INT_MASK_TX_FIFO_EMPTY, DISABLE);
}

/**
 * @brief  DMA0 channel 2 used for receive UART peripheral data.
 *         First clear rx DMA interrupt mask and disable rx DMA channel interrupt.
 *         Save data to UART rx buffer and set DMA destination address.
 *         Then enable rx DMA channel interrupt.
 *         Send IO_MSG_UART_RX event to app task.
 * @param  void
 * @return void
 */
void console_rx_dma_handler(void)
{
    uint16_t rx_count;

    DMA_INTConfig(UART_RX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, DISABLE);
    DMA_ClearINTPendingBit(UART_RX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER);
    DMA_Cmd(UART_RX_DMA_CHANNEL_NUM, DISABLE);

    rx_count = DMA_GetTransferLen(UART_RX_DMA_CHANNEL);

    //DBG_DIRECT("console_rx_dma_handler: rx_count %d", rx_count);

    if (p_console_callback)
    {
        p_console_callback(uart_context, CONSOLE_EVT_DATA_IND, uart_rx_buf_addr, rx_count);
    }

    DMA_SetDestinationAddress(UART_RX_DMA_CHANNEL, (uint32_t)uart_rx_buf_addr);
    DMA_INTConfig(UART_RX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
    DMA_Cmd(UART_RX_DMA_CHANNEL_NUM, ENABLE);
}

/**
 * @brief  DMA0 channel 1 used for send UART peripheral data.
 *         When DMA has been finished send all data, this interrupt will be cause.
 *         Clear tx DMA channel all interrupt mask.
 *         Send IO_MSG_UART_TX event to app task, notify app to next tx action.
 * @param  void
 * @return void
 */
void console_tx_dma_handler(void)
{
    DMA_ClearAllTypeINT(UART_TX_DMA_CHANNEL_NUM);

    console_uart_handle_tx_done();
}

/**
    * @brief  UART tx channel start send data.
    *         Set DMA source address and buffer size according to incoming parameters.
    *         Command DMA tx channel to send data with os lock.
    * @param  void
    * @return void
    */
bool console_uart_dma_write(uint8_t *buf, uint32_t len)
{
    uint32_t s;

    DMA_SetSourceAddress(UART_TX_DMA_CHANNEL, (uint32_t)buf);
    DMA_SetBufferSize(UART_TX_DMA_CHANNEL, len);
    s = os_lock();
    DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
    os_unlock(s);

    return true;
}

/**
  * @brief  UART send data by cpu action.
  * @param  void
  * @return void
  */
bool uart_send_by_cpu_action(uint8_t *buf, uint32_t len)
{
    uint32_t tx_len = len > UART_TX_FIFO_SIZE ? UART_TX_FIFO_SIZE : len;

    UART_SendData(CONSOLE_UART, buf, tx_len);

    uart_tx_curr_addr = buf + tx_len;
    uart_tx_len = len - tx_len;

    tx_empty_need_handle = 1;
    UART_INTConfig(CONSOLE_UART, UART_INT_TX_FIFO_EMPTY, ENABLE);

    return true;
}


/**
  * @brief  UART send data by cpu action.
  * @param  void
  * @return void
  */
bool console_uart_write(void *handle, uint8_t *buf, uint32_t len)
{
    //DBG_DIRECT("console_uart_write: %p, %d", buf, len);

    uart_tx_count = len;

    if (g_console_uart.uart_tx_dma_enable)
    {
        return console_uart_dma_write(buf, len);
    }
    else
    {
        return uart_send_by_cpu_action(buf, len);
    }
}

/**
 * @brief  console uart handle tx data done, static function.
 * @param  void
 * @return void
 */
void console_uart_handle_tx_done(void)
{
    uint16_t tx_count;

    /* DMA_GetTransferLen(UART_TX_DMA_CHANNEL) is cleared when Channel disabled,
     * we just use the global variable to save it.
     * Let hardware to fix the DMA issue.
     */
    tx_count = uart_tx_count;

    if (p_console_callback)
    {
        p_console_callback(uart_context, CONSOLE_EVT_DATA_XMIT, NULL, tx_count);
    }
}

/**
 * @brief  UART driver initial.
 *         Include APB peripheral clock config, UART parameter config
 * @param  void
 * @return void
 */
void console_uart_driver_init(void *handle)
{
    UART_InitTypeDef uart_init;
    NVIC_InitTypeDef uart_nvic;

    /* Turn on UART clock */
    RCC_ClockCmd(CONSOLE_UART_CLOCK, ENABLE);

    UART_StructInit(&uart_init);
    uart_init.UART_DMAEn = ENABLE;
    uart_init.UART_TxDMAEn = g_console_uart.uart_tx_dma_enable ? ENABLE : DISABLE;
    uart_init.UART_TxWaterLevel = 15;
    uart_init.UART_RxDMAEn = g_console_uart.uart_rx_dma_enable ? ENABLE : DISABLE;
    uart_init.UART_RxWaterLevel = 1;

    UART_GetBaudSettings(g_console_uart.data_uart_baud_rate,
                         uart_init.UART_WordLen,
                         uart_init.UART_Parity,
                         uart_init.UART_StopBits,
                         &uart_init.UART_Div,
                         &uart_init.UART_Ovsr,
                         &uart_init.UART_OvsrAdj);

    UART_Init(CONSOLE_UART, &uart_init);

    if (!g_console_uart.uart_rx_dma_enable)
    {
        UART_INTConfig(CONSOLE_UART, UART_INT_RD_AVA | UART_INT_RX_IDLE, ENABLE);
    }
    else
    {
        UART_INTConfig(CONSOLE_UART, UART_INT_RX_IDLE, ENABLE);
    }

    ram_vector_table_update(CONSOLE_UART_IRQn, Data_Uart_Handler);

    /* Enable UART IRQ */
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
    uart_nvic.NVIC_IRQChannel = AUTO_TEST_UART_IRQN;
#else
    uart_nvic.NVIC_IRQChannel = CONSOLE_UART_IRQn;
#endif
    uart_nvic.NVIC_IRQChannelPriority = 5;
    uart_nvic.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
    NVIC_Init(&uart_nvic);
}

/**
 * @brief  UART tx dma driver initial.
 *         Include APB peripheral clock config, DMA parameter config
 * @param  void
 * @return void
 */
void console_uart_tx_dma_init(void)
{
    DMA_InitTypeDef tx_gdma;
    NVIC_InitTypeDef tx_nvic;

    /*-------DMA clock enable-------*/
#ifdef IS_DMA_PERIPH
    RCC_ClockCmd(DMA_CLOCK, ENABLE);
#endif
#ifdef IS_DMA1_PERIPH
    RCC_ClockCmd(DMA1_CLOCK, ENABLE);
#endif

#if (CONSOLE_UART_SUPPORT_DYNAMIC_DMA_CHANNEL == 1)
    if (!hal_dma_channel_alloc(&uart_tx_dma_ch_num, console_tx_dma_handler,
                               HAL_DMA_FIFO_DEPTH_32))
    {
        char *temp_buf = "hal_dma_channel_alloc fail\r\n";
        console_write((uint8_t *)temp_buf, strlen(temp_buf));
        return;
    }
#endif

    /*-------UART Tx DMA configuration -------*/
    DMA_StructInit(&tx_gdma);
    tx_gdma.DMA_ChannelNum = UART_TX_DMA_CHANNEL_NUM;
    tx_gdma.DMA_Direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
    tx_gdma.DMA_BufferSize = 0;
    tx_gdma.DMA_SourceInc = DMA_SOURCE_INC;
    tx_gdma.DMA_DestinationInc  = DMA_DESTINATION_FIX;
    tx_gdma.DMA_DestinationAddr = (uint32_t)(&(CONSOLE_UART->UART_RBR_THR));
    tx_gdma.DMA_DestHandshake   = DMA_HANDSHAKE_CONSOLE_UART_TX;
    tx_gdma.DMA_ChannelPriority = 5; //channel priority between 0 to 6
    DMA_Init(UART_TX_DMA_CHANNEL, &tx_gdma);

    ram_vector_table_update(UART_TX_DMA_IRQ, console_tx_dma_handler);

    /*-------DMA Tx IRQ init-------*/
    tx_nvic.NVIC_IRQChannel = UART_TX_DMA_IRQ;
    tx_nvic.NVIC_IRQChannelPriority = 5;
    tx_nvic.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
    NVIC_Init(&tx_nvic);
    DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
}


/**
 * @brief  UART rx dma driver initial.
 *         Include APB peripheral clock config, DMA parameter config
 * @param  void
 * @return void
 */
void console_uart_rx_dma_init(void)
{
    DMA_InitTypeDef rx_gdma;
    NVIC_InitTypeDef rx_nvic;

    /*-------DMA clock enable-------*/
#ifdef IS_DMA_PERIPH
    RCC_ClockCmd(DMA_CLOCK, ENABLE);
#endif
#ifdef IS_DMA1_PERIPH
    RCC_ClockCmd(DMA1_CLOCK, ENABLE);
#endif

#if (CONSOLE_UART_SUPPORT_DYNAMIC_DMA_CHANNEL == 1)
    if (!hal_dma_channel_alloc(&uart_rx_dma_ch_num, console_rx_dma_handler,
                               HAL_DMA_FIFO_DEPTH_32))
    {
        char *temp_buf = "hal_dma_channel_alloc fail\r\n";
        console_write((uint8_t *)temp_buf, strlen(temp_buf));
        return;
    }
#endif

    /*-------UART Rx DMA configuration -------*/
    DMA_StructInit(&rx_gdma);
    rx_gdma.DMA_ChannelNum      = UART_RX_DMA_CHANNEL_NUM;
    rx_gdma.DMA_Direction       = DMA_DIR_PERIPHERAL_TO_MEMORY;
    rx_gdma.DMA_BufferSize      = g_console_uart.uart_dma_rx_buffer_size;
    rx_gdma.DMA_SourceInc       = DMA_SOURCE_FIX;
    rx_gdma.DMA_DestinationInc  = DMA_DESTINATION_INC;
    rx_gdma.DMA_SourceDataSize  = DMA_DATA_SIZE_BYTE;
    rx_gdma.DMA_DestinationDataSize = DMA_DATA_SIZE_BYTE;
    rx_gdma.DMA_SourceMsize     = DMA_MSIZE_1;
    rx_gdma.DMA_DestinationMsize = DMA_MSIZE_1;
    rx_gdma.DMA_SourceAddr   = (uint32_t)(&(CONSOLE_UART->UART_RBR_THR));
    rx_gdma.DMA_DestinationAddr = (uint32_t)uart_rx_buf_addr;
    rx_gdma.DMA_SourceHandshake = DMA_HANDSHAKE_CONSOLE_UART_RX;
    rx_gdma.DMA_ChannelPriority = 5; //channel priority between 0 to 6
    DMA_Init(UART_RX_DMA_CHANNEL, &rx_gdma);

    ram_vector_table_update(UART_RX_DMA_IRQ, console_rx_dma_handler);

    /*-------DMA Rx IRQ init-------*/
    rx_nvic.NVIC_IRQChannel = UART_RX_DMA_IRQ;
    rx_nvic.NVIC_IRQChannelPriority = 5;
    rx_nvic.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
    NVIC_Init(&rx_nvic);
    DMA_INTConfig(UART_RX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);

    DMA_Cmd(UART_RX_DMA_CHANNEL_NUM, ENABLE);
}

/**
 * @brief  UART driver initial.
 *         Include APB peripheral clock config, UART GPIO parameter config and
 *         DMA channel parameter config. Enable UART GPIO and DMA channel interrupt.
 *         Create UART rx queue for communication between UART and app task.
 * @param  void
 * @return void
 */
bool console_uart_init(void *handle, T_CONSOLE_CBACK p_callback)
{
    p_console_callback = p_callback;

    if (uart_rx_buf_addr != NULL)
    {
        free(uart_rx_buf_addr);
    }

    if (g_console_uart.uart_rx_dma_enable)
    {
        uart_rx_buf_addr = (uint8_t *)malloc(g_console_uart.uart_dma_rx_buffer_size);
    }
    else
    {
        uart_rx_buf_addr = (uint8_t *)malloc(UART_RX_FIFO_SIZE);
    }

    if (uart_rx_buf_addr == NULL)
    {
        DBG_DIRECT("console_uart_init: rx buffer malloc failed");
        return false;
    }

    if (!g_console_uart.one_wire_uart_support)
    {
        console_uart_driver_init(handle);
    }

    if (g_console_uart.uart_tx_dma_enable)
    {
        console_uart_tx_dma_init();
    }

    if (g_console_uart.uart_rx_dma_enable)
    {
        console_uart_rx_dma_init();
    }

    p_console_callback(uart_context, CONSOLE_EVT_OPENED, NULL, 0);
    return true;
}

/**
 * @brief  APP console uart configure set.
 * @param  cfg the pointer for console uart parameter.
 * @return void
 */
void console_uart_create(T_CONSOLE_UART_CONFIG *cfg, void **handle)
{
    *handle = uart_context;
    memcpy(&g_console_uart, cfg, sizeof(T_CONSOLE_UART_CONFIG));
}

bool console_uart_delete(void *handle)
{
    return true;
}