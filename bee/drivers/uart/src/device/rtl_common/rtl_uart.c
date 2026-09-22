/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_uart.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
/* UART Immediate Number */
#define FCR_CLEAR_RX_FIFO_SET           ((uint32_t)(1 << 1))
#define FCR_CLEAR_RX_FIFO_RESET         ((uint32_t)~(1 << 1))
#define FCR_CLEAR_TX_FIFO_SET           ((uint32_t)(1 << 2))
#define FCR_CLEAR_TX_FIFO_RESET         ((uint32_t)~(1 << 2))

#if (UART_SUPPORT_RAP_FUNCTION == 1)
bool UART_IsSupportRAP(UART_TypeDef *UARTx);
#endif
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitialize the specified UART registers to their default reset values.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 */
void UART_DeInit(UART_TypeDef *UARTx)
{
    assert_param(IS_UART_PERIPH(UARTx));

#ifdef UART0
    if (UARTx == UART0)
    {
        RCC_ClockCmd(UART0_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART1
    if (UARTx == UART1)
    {
        RCC_ClockCmd(UART1_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART2
    if (UARTx == UART2)
    {
        RCC_ClockCmd(UART2_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART3
    if (UARTx == UART3)
    {
        RCC_ClockCmd(UART3_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART4
    if (UARTx == UART4)
    {
        RCC_ClockCmd(UART4_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART5
    if (UARTx == UART5)
    {
        RCC_ClockCmd(UART5_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef UART6
    if (UARTx == UART6)
    {
        RCC_ClockCmd(UART6_CLOCK, DISABLE);
        return;
    }
#endif
}

/**
 * @brief Initialize the UART peripheral according to the specified parameters in the UART_InitStruct.
 * @param UARTx            Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param UART_InitStruct  Pointer to a UART_InitTypeDef structure which will be initialized.
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct)
{
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLen));
    assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
    assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
    assert_param(IS_UART_RX_FIFO_TRIGGER_LEVEL(UART_InitStruct->UART_RxThdLevel));
    assert_param(IS_UART_IDLE_TIME(UART_InitStruct->UART_IdleTime));
    assert_param(IS_UART_DMA_CFG(UART_InitStruct->UART_DMAEn));
    assert_param(IS_UART_AUTO_FLOW_CTRL(UART_InitStruct->UART_HardwareFlowControl));

    /* Set tx only mode */
    UART_STSR_TypeDef uart_0x20 = {.d32 = UARTx->UART_STSR};
    uart_0x20.b.reset_rcv = UART_InitStruct->UART_TxOnlyEn;
    UARTx->UART_STSR = uart_0x20.d32;

    /* Clear DLAB bit */
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Disable all interrupt */
    UARTx->UART_DLM_IER = 0x0;

    /* Read to clear Line Status Reg */
    (void) UARTx->UART_LSR;

    /* Clear FIFO */
    UART_FCR_TypeDef uart_0x08 = {.d32 = 0x0};
    uart_0x08.b.clear_rxfifo = 0x1;
#if (UART_SUPPORT_CLEAR_TX_FIFO == 1)
    uart_0x08.b.clear_txfifo = 0x1;
#endif
    UARTx->UART_IIR_FCR = uart_0x08.d32;

    /* Set baudrate, firstly set DLAB bit */
    uart_0x0c.b.dlab = 0x1;
    UARTx->UART_LCR = uart_0x0c.d32;
    /* Set calibration parameters(OVSR) */
    uart_0x20.b.xfactor = UART_InitStruct->UART_Ovsr;
    UARTx->UART_STSR = uart_0x20.d32;
    /* Set calibration parameters(OVSR_adj) */
    UART_SCR_TypeDef uart_0x1c = {.d32 = UARTx->UART_SCR};
    uart_0x1c.b.xfactor_adj = UART_InitStruct->UART_OvsrAdj;
    UARTx->UART_SCR = uart_0x1c.d32;
    /* Set DLL and DLH */
    UARTx->UART_DLL = (UART_InitStruct->UART_Div & 0x00FF);
    UARTx->UART_DLM_IER = ((UART_InitStruct->UART_Div & 0xFF00) >> 8);
    /* After set baudrate, clear DLAB bit */
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set LCR reg */
    uart_0x0c.b.wls0 = UART_InitStruct->UART_WordLen;
    uart_0x0c.b.stb = UART_InitStruct->UART_StopBits;
    uart_0x0c.b.parity_sel = UART_InitStruct->UART_Parity;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set FCR reg, FIFO must enable */
    uart_0x08.d32 = 0x0;
    uart_0x08.b.rxfifo_error_en = ENABLE;
    uart_0x08.b.dma_mode = UART_InitStruct->UART_DMAEn;
    uart_0x08.b.rxfifo_trigger_level = UART_InitStruct->UART_RxThdLevel;
    uart_0x08.b.tx_fifo_th = UART_InitStruct->UART_TxThdLevel;
    UARTx->UART_IIR_FCR = uart_0x08.d32;

    /* Harware flow control */
    UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
    uart_0x10.b.rts = UART_InitStruct->UART_HardwareFlowControl;
    uart_0x10.b.autoflow_en = UART_InitStruct->UART_HardwareFlowControl;
    UARTx->UART_CTRL0 = uart_0x10.d32;

    /* Set rx idle time */
    UARTx->UART_RX_TIMEOUT = UART_InitStruct->UART_IdleTime;

    if (UART_InitStruct->UART_DMAEn == ENABLE)
    {
        /* Config UART Tx dma parameter */
        UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
        if (UART_InitStruct->UART_TxDMAEn != DISABLE)
        {
            /* Mask uart TX threshold value */
            uart_0x28.b.txdma_en = ENABLE;
            uint8_t tx_water_level = UART_InitStruct->UART_TxWaterLevel;
            tx_water_level = (tx_water_level > UART_TX_FIFO_SIZE - 1) ? (UART_TX_FIFO_SIZE - 1) :
                             (tx_water_level < 1) ? 1 : tx_water_level;
            UART_InitStruct->UART_TxWaterLevel = tx_water_level;
            uart_0x28.b.txdma_burstsize = UART_TX_FIFO_SIZE - UART_InitStruct->UART_TxWaterLevel;
        }
        /* Config UART Rx dma parameter */
        if (UART_InitStruct->UART_RxDMAEn != DISABLE)
        {
            /* Mask uart RX threshold value */
            uart_0x28.b.rxdma_en = ENABLE;
            uart_0x28.b.rxdma_burstsize = UART_InitStruct->UART_RxWaterLevel;
        }
        UARTx->UART_MISCR = uart_0x28.d32;
    }

#if (UART_SUPPORT_AUTO_CLOCK == 1)
    UART_QACTIVE_CTRL_TypeDef uart_qactive = {.d32 = UARTx->UART_QACTIVE_CTRL};
    uart_qactive.b.rx_qact_auto_en = UART_InitStruct->UART_AutoModeEn;
    uart_qactive.b.rx_qact_auto_timeout_val_sel = UART_InitStruct->UART_AutoModeTime;
    uart_qactive.b.qact_pclk_icg_en = 1;
    UARTx->UART_QACTIVE_CTRL = uart_qactive.d32;
#endif

    return;
}

/**
 * @brief Fills each UART_InitStruct member with its default value.
 * @param UART_InitStruct  Pointer to a UART_InitTypeDef structure which will be initialized.
 */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct)
{
    //115200 default
    UART_InitStruct->UART_Div                 = 20;
    UART_InitStruct->UART_Ovsr                = 12;
    UART_InitStruct->UART_OvsrAdj             = 0x252;

    UART_InitStruct->UART_WordLen             = UART_WORD_LENGTH_8BIT;
    UART_InitStruct->UART_StopBits            = UART_STOP_BITS_1;
    UART_InitStruct->UART_Parity              = UART_PARITY_NO_PARTY;
    UART_InitStruct->UART_TxThdLevel          = 16; //1~29
    UART_InitStruct->UART_RxThdLevel          = 16; //1~29
    UART_InitStruct->UART_IdleTime            = UART_RX_IDLE_2BYTE; //idle interrupt wait time
    UART_InitStruct->UART_HardwareFlowControl = DISABLE;
    UART_InitStruct->UART_DMAEn               = DISABLE;
    UART_InitStruct->UART_TxDMAEn             = DISABLE;
    UART_InitStruct->UART_RxDMAEn             = DISABLE;
    UART_InitStruct->UART_TxWaterLevel        = 15; //Better to equal TX_FIFO_SIZE(16)- DMA_MSize
    UART_InitStruct->UART_RxWaterLevel        = 1; //Better to equal DMA_MSize
    UART_InitStruct->UART_TxOnlyEn            = DISABLE;
#if (UART_SUPPORT_AUTO_CLOCK == 1)
    UART_InitStruct->UART_AutoModeEn          = ENABLE;
    UART_InitStruct->UART_AutoModeTime        = 20;
#endif

    return;
}

/**
 * @brief Mask or unmask the specified UART interrupt.
 * @param UARTx          Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param UART_INT_MASK  Specifies the UART interrupt to be masked or unmasked.
 *                       This parameter can be any combination of @ref UART_INTERRUPTS_MASK.
 *                       - UART_INT_MASK_RD_AVA: UART Rx data available interrupt mask.
 *                       - UART_INT_MASK_FIFO_EMPTY: UART Tx FIFO empty interrupt mask.
 *                       - UART_INT_MASK_LINE_STS: UART Rx line status interrupt mask.
 *                       - UART_INT_MASK_RX_IDLE: UART RX idle interrupt mask.
 *                       - UART_INT_MASK_TX_DONE: UART TX done (TX shift register empty and TX FIFO empty) interrupt mask.
 *                       - UART_INT_MASK_TX_THD: UART TX FIFO threshold interrupt mask.
 *                       - UART_INT_MASK_CTS_TOGGLE: UART CTS toggle interrupt mask.
 * @param NewState       Enable or disable the specified UART interrupt.
 */
void UART_MaskINTConfig(UART_TypeDef *UARTx, uint32_t UART_INT_MASK, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_INT_MASK(UART_INT_MASK));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        UARTx->UART_INT_MASK |= UART_INT_MASK;
    }
    else
    {
        UARTx->UART_INT_MASK &= ~(UART_INT_MASK);
    }
}

/**
 * @brief Enable or disable the specified UART interrupts.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param UART_INT  Specifies the UART interrupts to be enabled or disabled.
 *                  This parameter can be any combination of @ref UART_INTERRUPTS.
 *                  - UART_INT_RD_AVA: UART Rx data available interrupt.
 *                  - UART_INT_TX_FIFO_EMPTY: UART Tx FIFO empty interrupt.
 *                  - UART_INT_RX_LINE_STS: UART Rx line status interrupt.
 *                  - UART_INT_TX_DONE: UART Tx done interrupt.
 *                  - UART_INT_TX_THD: UART Tx threshold interrupt.
 *                  - UART_INT_RX_IDLE: UART Rx idle interrupt.
 *                  - UART_INT_CTS_TOGGLE: UART CTS toggle interrupt.
 * @param NewState  Enable or disable the specified UART interrupts.
 */
void UART_INTConfig(UART_TypeDef *UARTx, uint32_t UART_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_INT(UART_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (UART_INT & UART_INT_RX_IDLE)
    {
        UART_RX_TIMEOUT_TypeDef uart_0x40 = {.d32 = UARTx->UART_RX_TIMEOUT};
        UART_RX_TIMEOUT_STS_TypeDef uart_0x44 = {.d32 = UARTx->UART_RX_TIMEOUT_STS};
        UART_RX_TIMEOUT_EN_TypeDef uart_0x48 = {.d32 = UARTx->UART_RX_TIMEOUT_EN};
        if (NewState == ENABLE)
        {
            uart_0x48.b.rxidle_timeout_int_en = 1;
            UARTx->UART_RX_TIMEOUT_EN = uart_0x48.d32;
            uart_0x40.b.rxidle_timeout_en = 1;
            UARTx->UART_RX_TIMEOUT = uart_0x40.d32;
        }
        else
        {
            uart_0x40.b.rxidle_timeout_en = 0;
            UARTx->UART_RX_TIMEOUT = uart_0x40.d32;
            uart_0x44.b.rxidle_timeout_int_sts = 1;
            UARTx->UART_RX_TIMEOUT_STS = uart_0x44.d32;
            uart_0x48.b.rxidle_timeout_int_en = 0;
            UARTx->UART_RX_TIMEOUT_EN = uart_0x48.d32;
        }
    }

#if (UART_SUPPORT_CTS_TOGGLE == 1)
    if (UART_INT & UART_INT_CTS_TOGGLE)
    {
        UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
        uart_0x10.b.cts_tog_int_en = NewState;
        UARTx->UART_CTRL0 = uart_0x10.d32;
    }
#endif
    if (UART_INT & 0x3F)
    {

        if (NewState == ENABLE)
        {
            /* Enable the selected UARTx interrupts */
            UARTx->UART_DLM_IER |= UART_INT;
        }
        else
        {
            /* Disable the selected UARTx interrupts */
            UARTx->UART_DLM_IER &= (uint32_t)~UART_INT;
        }
    }
    return;
}

/**
 * @brief Clear the specified UART interrupt flag.
 * @note Only UART_FLAG_RX_IDLE and UART_FLAG_CTS_TOGGLE need to be cleared manually, other interrupt flags cannot be cleared.
 * @param UARTx      Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param UART_FLAG  Specifies the UART interrupt flag to clear.
 *                   This parameter can be only one of the following values:
 *                   - UART_FLAG_RX_IDLE: UART Rx idle interrupt flag.
 *                   - UART_FLAG_CTS_TOGGLE: UART CTS toggle interrupt flag.
 */
void UART_ClearINT(UART_TypeDef *UARTx, uint32_t UART_FLAG)
{
    if (UART_FLAG == UART_FLAG_RX_IDLE)
    {
        UART_RX_TIMEOUT_TypeDef uart_0x40 = {.d32 = UARTx->UART_RX_TIMEOUT};
        UART_RX_TIMEOUT_STS_TypeDef uart_0x44 = {.d32 = UARTx->UART_RX_TIMEOUT_STS};

        uart_0x44.b.rxidle_timeout_int_sts = 1;
        UARTx->UART_RX_TIMEOUT_STS = uart_0x44.d32;

        uart_0x40.b.rxidle_timeout_en = 1;
        UARTx->UART_RX_TIMEOUT = uart_0x40.d32;
    }

#if (UART_SUPPORT_CTS_TOGGLE == 1)
    if (UART_FLAG == UART_FLAG_CTS_TOGGLE)
    {
        UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
        uart_0x10.b.cts_tog_int_sts = 1;
        UARTx->UART_CTRL0 = uart_0x10.d32;
    }
#endif
}


/**
 * @brief Get the specified UART interrupt flag.
 * @param UARTx      Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param UART_FLAG  Specifies the UART interrupt flag to check.
 *                   This parameter can be any of @ref UART_FLAG.
 *                   - UART_FLAG_RX_DATA_AVA: UART Rx data available interrupt flag.
 *                   - UART_FLAG_RX_OVERRUN: UART Rx FIFO overrun interrupt flag.
 *                   - UART_FLAG_RX_PARITY_ERR: UART Rx parity error interrupt flag.
 *                   - UART_FLAG_RX_FRAME_ERR: UART Rx frame error interrupt flag.
 *                   - UART_FLAG_RX_BREAK_ERR: UART Rx break error interrupt flag.
 *                   - UART_FLAG_TX_FIFO_EMPTY: UART Tx FIFO empty interrupt flag.
 *                   - UART_FLAG_TX_EMPTY: UART Tx empty (TX shift register empty and TX FIFO empty) interrupt flag.
 *                   - UART_FLAG_RX_FIFO_ERR: UART Rx FIFO error interrupt flag.
 *                   - UART_FLAG_RX_IDLE: UART Rx idle interrupt flag.
 *                   - UART_FLAG_TX_DONE: UART Tx done (TX shift register empty and TX FIFO empty) interrupt flag.
 *                   - UART_FLAG_TX_THD: UART Tx threshold interrupt flag.
 *                   - UART_FLAG_CTS_TOGGLE: UART CTS toggle interrupt flag.
 * @return The specified UART interrupt status. Refer to @ref FlagStatus.
 * @retval SET    The interrupt status is set.
 * @retval RESET  The interrupt status is not set.
 */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint32_t UART_FLAG)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));
    assert_param(IS_UART_GET_FLAG(UART_FLAG));

    FlagStatus bitstatus = RESET;

    if (UART_FLAG == UART_FLAG_RX_IDLE)
    {
        if (UARTx->UART_RX_TIMEOUT_STS & BIT(0))
        {
            bitstatus = SET;
        }
    }
#if (UART_SUPPORT_TX_THRESHOLD == 1)
    else if (UART_FLAG == UART_FLAG_TX_THD)
    {
        if (UARTx->UART_TX_THD_INT & BIT(0))
        {
            bitstatus = SET;
        }
    }
#endif
#if (UART_SUPPORT_TX_DONE == 1)
    else if (UART_FLAG == UART_FLAG_TX_DONE)
    {
        if (UARTx->UART_TXDONE_INT & BIT(0))
        {
            bitstatus = SET;
        }
    }
#endif
#if (UART_SUPPORT_CTS_TOGGLE == 1)
    else if (UART_FLAG == UART_FLAG_CTS_TOGGLE)
    {
        if (UARTx->UART_CTRL0 & BIT(8))
        {
            bitstatus = SET;
        }
    }
#endif
    else
    {
        if (UART_GetLineStatus(UARTx) & UART_FLAG)
        {
            bitstatus = SET;
        }
    }

    return bitstatus;
}

/**
 * @brief Get the specified UART line status.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return The specified UART line status.
 *         This parameter can be the mask of the following values:
 *         - UART_FLAG_RX_DATA_AVA, UART Rx data available interrupt flag.
 *         - UART_FLAG_RX_OVERRUN, UART Rx FIFO overrun interrupt flag.
 *         - UART_FLAG_RX_PARITY_ERR, UART Rx parity error interrupt flag.
 *         - UART_FLAG_RX_FRAME_ERR, UART Rx frame error interrupt flag.
 *         - UART_FLAG_RX_BREAK_ERR, UART Rx break error interrupt flag.
 *         - UART_FLAG_TX_FIFO_EMPTY, UART Tx FIFO empty interrupt flag.
 *         - UART_FLAG_TX_EMPTY, UART Tx empty (TX shift register empty and TX FIFO empty) interrupt flag.
 *         - UART_FLAG_RX_FIFO_ERR, UART Rx FIFO error interrupt flag.
 * @note   Reading the LSR may clear certain error flags (OE, PE, FE, BI)
 *         as a side effect on some implementations. Read it only once per
 *         check and cache the result if multiple bits need to be evaluated.
 */
uint8_t UART_GetLineStatus(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_LSR & (0x000000FF));
}

/**
 * @brief Get the specified UART interrupt identifier.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return Specifies the UART interrupts to check.
 *         This parameter can be any of the following values:
 *         - UART_INT_ID_LINE_STATUS: UART interrupt ID is Rx line status.
 *         - UART_INT_ID_RX_LEVEL_REACH: UART interrupt ID is Rx data level reached.
 *         - UART_INT_ID_RX_DATA_TIMEOUT: UART interrupt ID: Rx data timeout.
 *         - UART_INT_ID_TX_FIFO_EMPTY: UART interrupt ID: Tx FIFO empty.
 */
uint16_t UART_GetIID(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint16_t)(UARTx->UART_IIR_FCR & (0x0000000E));
}

/**
 * @brief Send one byte data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param Data   One byte data to send.
 */
void UART_SendByte(UART_TypeDef *UARTx, uint8_t Data)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_RBR_THR = Data;

    return;
}

/**
 * @brief Send data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param InBuf  Pointer to the buffer to send.
 * @param Count  Numbers of byte to send.
 */
void UART_SendData(UART_TypeDef *UARTx, const uint8_t *InBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        UARTx->UART_RBR_THR = *InBuf++;
    }

    return;
}

#if (UART_SUPPORT_HALF_WORD == 1)
/**
 * @brief Send one half-word data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param Data   One half-word data to send.
 */
void UART_SendHalfWord(UART_TypeDef *UARTx, uint16_t Data)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_RBR_THR = Data;

    return;
}

/**
 * @brief Send half word data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param InBuf  Pointer to the buffer to send.
 * @param Count  Numbers of half-word to send.
 */
void UART_SendHalfWordData(UART_TypeDef *UARTx, const uint16_t *InBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        UARTx->UART_RBR_THR = *InBuf++;
    }

    return;
}
#endif

/**
 * @brief Receive one byte data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return One byte data to receive.
 */
uint8_t UART_ReceiveByte(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_RBR_THR);
}

/**
 * @brief Receive data over UART.
 * @param UARTx   Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param OutBuf  Pointer to the buffer to receive.
 * @param Count   Numbers of byte to receive.
 */
void UART_ReceiveData(UART_TypeDef *UARTx, uint8_t *OutBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        *OutBuf++ = (uint8_t)UARTx->UART_RBR_THR;
    }

    return;
}

#if (UART_SUPPORT_HALF_WORD == 1)
/**
 * @brief Receive one half-word data over UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return One half-word data to receive.
 */
uint8_t UART_ReceiveHalfWord(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint16_t)(UARTx->UART_RBR_THR);
}

/**
 * @brief Receive half word data over UART.
 * @param UARTx   Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param OutBuf  Pointer to the buffer to receive.
 * @param Count   Numbers of half-word to receive.
 */
void UART_ReceiveHalfWordData(UART_TypeDef *UARTx, uint16_t *OutBuf, uint16_t Count)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    while (Count--)
    {
        *OutBuf++ = (uint16_t)UARTx->UART_RBR_THR;
    }

    return;
}
#endif

/**
 * @brief Set UART baudrate.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param div       Parameter of the specified UART baudrate.
 * @param ovsr      Parameter of the specified UART baudrate.
 * @param ovsr_adj  Parameter of the specified UART baudrate.
 */
void UART_SetBaudRate(UART_TypeDef *UARTx, uint16_t div, uint16_t ovsr, uint16_t ovsr_adj)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* Set baudrate, firstly set DLAB bit */
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.dlab = 0x1;
    UARTx->UART_LCR = uart_0x0c.d32;

    /* Set calibration parameters(OVSR) */
    UART_STSR_TypeDef uart_0x20 = {.d32 = UARTx->UART_STSR};
    uart_0x20.b.xfactor = ovsr;
    UARTx->UART_STSR = uart_0x20.d32;

    /* Set calibration parameters(OVSR_adj) */
    UART_SCR_TypeDef uart_0x1c = {.d32 = UARTx->UART_SCR};
    uart_0x1c.b.xfactor_adj = ovsr_adj;
    UARTx->UART_SCR = uart_0x1c.d32;

    /* Set DLL and DLH */
    UARTx->UART_DLL = (div & 0x00FF);
    UARTx->UART_DLM_IER = ((div & 0xFF00) >> 8);

    /* After set baudrate, clear DLAB bit */
    uart_0x0c.b.dlab = 0x0;
    UARTx->UART_LCR = uart_0x0c.d32;
}

/**
 * @brief Set UART communication parameters.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param WordLen   Specifies the UART data width. Refer to @ref UART_WORD_LENGTH.
 * @param Parity    Specifies the UART parity. Refer to @ref UART_PARITY.
 * @param StopBits  Specifies the UART stop bits. Refer to @ref UART_STOP_BITS.
 */
void UART_SetParams(UART_TypeDef *UARTx, uint16_t WordLen, uint16_t Parity, uint16_t StopBits)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    /* set LCR reg */
    UART_LCR_TypeDef uart_0x0c = {.d32 = UARTx->UART_LCR};
    uart_0x0c.b.wls0 = WordLen;
    uart_0x0c.b.stb = StopBits;
    uart_0x0c.b.parity_sel = Parity;
    UARTx->UART_LCR = uart_0x0c.d32;
}

/**
 * @brief Enable or disable the UART loopback function.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param NewState  Enable or disable the UART loopback function.
 */
void UART_LoopBackCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_CTRL0_TypeDef uart_0x10 = {.d32 = UARTx->UART_CTRL0};
    uart_0x10.b.loopback_en = NewState;
    UARTx->UART_CTRL0 = uart_0x10.d32;
}

#if (UART_SUPPORT_CLEAR_TX_FIFO == 1)
/**
 * @brief Clear the specified UART Tx FIFO.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 */
void UART_ClearTxFIFO(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_IIR_FCR = (((UARTx->UART_STSR & BIT24) >> 21) | \
                           ((UARTx->UART_STSR & 0x7C000000) >> 18) | \
                           ((UARTx->UART_STSR & BIT25) >> 25) | \
                           FCR_CLEAR_TX_FIFO_SET);

    return;
}
#endif

/**
 * @brief Clear the specified UART Rx FIFO.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 */
void UART_ClearRxFIFO(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UARTx->UART_IIR_FCR = (((UARTx->UART_STSR & BIT24) >> 21) | \
                           ((UARTx->UART_STSR & 0x7C000000) >> 18) | \
                           ((UARTx->UART_STSR & BIT25) >> 25) | \
                           FCR_CLEAR_RX_FIFO_SET);

    return;
}

/**
 * @brief Get the data length in Tx FIFO of the specified UART peripheral.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return Data length in TX FIFO of the specified UART peripheral.
 */
uint8_t UART_GetTxFIFODataLen(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)(UARTx->UART_RXTX_FIFO_WL & 0x1F);
}

/**
 * @brief Get the data length in Rx FIFO of the specified UART peripheral.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return Data length in RX FIFO of the specified UART peripheral.
 */
uint8_t UART_GetRxFIFODataLen(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    return (uint8_t)((UARTx->UART_RXTX_FIFO_WL >> 8) & 0x3F);
}

/**
 * @brief Enable or disable the DMA mode of the specified UART peripheral.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param NewState  Enable or disable the DMA mode of the specified UART peripheral.
 */
void UART_TxDMACmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
    uart_0x28.b.txdma_en = NewState;
    UARTx->UART_MISCR = uart_0x28.d32;
}

/**
 * @brief Enable or disable the DMA mode of the specified UART peripheral.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param NewState  Enable or disable the DMA mode of the specified UART peripheral.
 */
void UART_RxDMACmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    UART_MISCR_TypeDef uart_0x28 = {.d32 = UARTx->UART_MISCR};
    uart_0x28.b.rxdma_en = NewState;
    UARTx->UART_MISCR = uart_0x28.d32;
}

#if (UART_SUPPORT_CTS_TOGGLE == 1)
/**
 * @brief Get the CTS level of UART.
 * @param UARTx  Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @return Level of CTS.
 * @retval SET    CTS is high.
 * @retval RESET  CTS is low.
 */
uint8_t UART_GetCTSLevel(UART_TypeDef *UARTx)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    if (UARTx->UART_CTRL0 & BIT(6))
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}
#endif

#if (UART_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the RAP mode of the specified UART peripheral.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param NewState  Enable or disable the RAP mode of the specified UART peripheral.
 * @return The execution result when config RAP mode.
 * @retval true   Config RAP mode successfully.
 * @retval false  Config RAP mode failed, which means the UART does not support RAP mode.
 */
bool UART_RAPModeCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_PERIPH(UARTx));

    if (UART_IsSupportRAP(UARTx) == 0)
    {
        return false;
    }

    UART_RAP_CTRL_TypeDef uart_0x68 = {.d32 = UARTx->UART_RAP_CTRL};
    uart_0x68.b.uart_rap_mode = NewState;
    UARTx->UART_RAP_CTRL = uart_0x68.d32;

    return true;
}

#endif

/**
 * @brief Enable or disable the TX-Only mode of the specified UART peripheral.
 * @param UARTx     Specifies the UART peripheral. Refer to @ref UART_DECLARATION.
 * @param NewState  Enable or disable the TX-Only mode of the specified UART peripheral.
 *                  This parameter can be one of the following values:
 *                  - ENABLE : Enable TX-only mode (RX function is disabled).
 *                  - DISABLE: Disable TX-only mode (Normal mode which TX/RX function is enabled).
 */
void UART_TxOnlyModeCmd(UART_TypeDef *UARTx, FunctionalState NewState)
{
    /* Set tx only mode */
    UART_STSR_TypeDef uart_0x20 = {.d32 = UARTx->UART_STSR};
    uart_0x20.b.reset_rcv = NewState;
    UARTx->UART_STSR = uart_0x20.d32;

    return;
}
