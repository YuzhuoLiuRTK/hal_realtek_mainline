/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_i2c.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
/* I2C Data Cmd Mask */
#define I2C_CMD_READ_BIT                             (BIT8)
#define I2C_CMD_STOP_BIT                             (BIT9)
#define I2C_CMD_RESTART_BIT                          (BIT10)

/* SDA Setup Time */
#define I2C_SDA_SETUP_TIME_VALUE                     (2)

/* SCL Low/High Period Time */
#define I2C_SCL_HIGH_PERIOD_COMPENSATE               (7)
#define I2C_SCL_LOW_PERIOD_COMPENSATE                (1)

#define NS_PER_SECOND                                (1000000000)
/* I2C SCL High/Low min period according to spec */
#define I2C_FAST_MODE_PLUS_SCL_LOW_PERIOD_MIN_NS     (500)
#define I2C_FAST_MODE_PLUS_SCL_HIGH_PERIOD_MIN_NS    (260)
#define I2C_FAST_MODE_SCL_LOW_PERIOD_MIN_NS          (1300)
#define I2C_FAST_MODE_SCL_HIGH_PERIOD_MIN_NS         (600)
#define I2C_STANDARD_MODE_SCL_LOW_PERIOD_MIN_NS      (4700)
#define I2C_STANDARD_MODE_SCL_HIGH_PERIOD_MIN_NS     (4000)
/* SDA Hold Time */
#define I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS      (600)
#define I2C_FAST_MODE_PLUS_SDA_HOLD_TIME_NS          (300)
#define I2C_TIMEOUT_SCALE                            (256)
#define I2C_TIMEOUT_MIN_US                           (20000)

#define ROUNDUP(a, b)                                (((a + b - 1) / b))

/* I2C Abort Check timeout etc */
uint32_t I2C_TimeOutUs[CHIP_I2C_NUMBER];

static uint32_t I2C_RisingTimeNs;
extern uint32_t I2C_GetClock(I2C_TypeDef *I2Cx);
extern uint8_t I2C_GetIndex(I2C_TypeDef *I2Cx);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitialize the I2Cx peripheral registers to their default reset values.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 */
void I2C_DeInit(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /*Disable I2C IP*/
#ifdef I2C0
    if (I2Cx == I2C0)
    {
        RCC_ClockCmd(I2C0_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef I2C1
    if (I2Cx == I2C1)
    {
        RCC_ClockCmd(I2C1_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef I2C2
    if (I2Cx == I2C2)
    {
        RCC_ClockCmd(I2C2_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef I2C3
    if (I2Cx == I2C3)
    {
        RCC_ClockCmd(I2C3_CLOCK, DISABLE);
        return;
    }
#endif
}

/**
 * @brief Initialize the I2Cx peripheral according to the specified parameters in the I2C_InitStruct.
 *
 * @param[in] I2Cx            Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_InitStruct  Pointer to an I2C_InitTypeDef structure that contains the configuration information for the I2C peripheral.
 */
void I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_CLOCK_SPEED(I2C_InitStruct->I2C_ClockSpeed));
    assert_param(IS_I2C_DEVICE_MODE(I2C_InitStruct->I2C_DeviceMode));
    assert_param(IS_I2C_ADDRESS_MODE(I2C_InitStruct->I2C_AddressMode));

    /* Disable I2C device before change configuration */
    IC_ENABLE_TypeDef i2c_0x6c = {.d32 = I2Cx->IC_ENABLE};
    i2c_0x6c.b.ic_enable = 0x0;
    I2Cx->IC_ENABLE = i2c_0x6c.d32;

    /* Config sda tx hold time in different clock speed */
    uint8_t sda_tx_hold = 0;
    uint32_t I2CSrcClk = I2C_GetClock(I2Cx);
    uint32_t i2c_source_clock_ns = NS_PER_SECOND / I2CSrcClk;

    if ((I2CSrcClk == 40000000) && (I2C_InitStruct->I2C_ClockSpeed > 400000))
    {
        sda_tx_hold = I2C_FAST_MODE_PLUS_SDA_HOLD_TIME_NS / i2c_source_clock_ns;
    }
    else
    {
        sda_tx_hold = (I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / i2c_source_clock_ns == 0) ? 1 :
                      (I2C_STANDARD_FAST_MODE_SDA_HOLD_TIME_NS / i2c_source_clock_ns);
    }

    /* ------------------------------ Initialize I2C device ------------------------------*/
    if (I2C_DEVICE_MODE_MASTER == I2C_InitStruct->I2C_DeviceMode)
    {
        /* Configure I2C device mode which can be selected for master or slave */
        IC_CON_TypeDef i2c_0x00 = {.d32 = I2Cx->IC_CON};
        i2c_0x00.b.master_mode = 0x1;
        i2c_0x00.b.ic_slave_disable = 0x1;
        i2c_0x00.b.ic_restart_en = 0x1;
        I2Cx->IC_CON = i2c_0x00.d32;

        /* Set target address */
        IC_TAR_TypeDef i2c_0x04 = {.d32 = I2Cx->IC_TAR};
        i2c_0x04.b.ic_10bitaddr_master = I2C_InitStruct->I2C_AddressMode;
        i2c_0x04.b.ic_tar = I2C_InitStruct->I2C_SlaveAddress;
        I2Cx->IC_TAR = i2c_0x04.d32;

        /* Set SDA hold time in master mode */
        IC_SDA_HOLD_TypeDef i2c_0x7c = {.d32 = I2Cx->IC_SDA_HOLD};
        i2c_0x7c.b.ic_sda_tx_hold = sda_tx_hold;
        i2c_0x7c.b.ic_sda_rx_hold = 0x1;
        I2Cx->IC_SDA_HOLD = i2c_0x7c.d32;

        I2C_RisingTimeNs = I2C_InitStruct->I2C_RisingTimeNs;
        /* Configure I2C speed */
        I2C_SetClockSpeed(I2Cx, I2C_InitStruct->I2C_ClockSpeed);
    }
    else
    {
        /* Set to slave mode */
        IC_CON_TypeDef i2c_0x00 = {.d32 = I2Cx->IC_CON};
        i2c_0x00.b.master_mode = 0x0;
        i2c_0x00.b.ic_10bitaddr_slave = I2C_InitStruct->I2C_AddressMode;
        i2c_0x00.b.ic_slave_disable = 0x0;
        I2Cx->IC_CON = i2c_0x00.d32;

        /* Set slave address */
        IC_SAR_TypeDef i2c_0x08 = {.d32 = I2Cx->IC_SAR};
        i2c_0x08.b.ic_sar = I2C_InitStruct->I2C_SlaveAddress;
        I2Cx->IC_SAR = i2c_0x08.d32;

        /* Set Ack in slave mode */
        IC_ACK_GENERAL_CALL_TypeDef i2c_0x98 = {.d32 = I2Cx->IC_ACK_GENERAL_CALL};
        i2c_0x98.b.ack_gen_call &= I2C_InitStruct->I2C_Ack;
        I2Cx->IC_ACK_GENERAL_CALL = i2c_0x98.d32;

        /* Set SDA hold time in slave mode */
        IC_SDA_HOLD_TypeDef i2c_0x7c = {.d32 = I2Cx->IC_SDA_HOLD};
        i2c_0x7c.b.ic_sda_tx_hold = sda_tx_hold;
        i2c_0x7c.b.ic_sda_rx_hold = 0x08;
        I2Cx->IC_SDA_HOLD = i2c_0x7c.d32;

        /* Set SDA setup time delay only in slave transmitter mode(greater than 2) ,delay time:[(IC_SDA_SETUP - 1) * (ic_clk_period)]*/
        IC_SDA_SETUP_TypeDef i2c_0x94 = {.d32 = I2Cx->IC_SDA_SETUP};
        i2c_0x94.b.sda_setup = I2C_SDA_SETUP_TIME_VALUE;
        I2Cx->IC_SDA_SETUP = i2c_0x94.d32;
    }

    /* Set Tx empty level */
    IC_TX_TL_TypeDef i2c_0x3c = {.d32 = I2Cx->IC_TX_TL};
    i2c_0x3c.b.tx_tl = I2C_InitStruct->I2C_TxThresholdLevel;
    I2Cx->IC_TX_TL = i2c_0x3c.d32;

    /*set Rx full level*/
    IC_RX_TL_TypeDef i2c_0x40 = {.d32 = I2Cx->IC_RX_TL};
    i2c_0x40.b.rx_tl = I2C_InitStruct->I2C_RxThresholdLevel;
    I2Cx->IC_RX_TL = i2c_0x40.d32;

    /* Config I2C dma mode */
    IC_DMA_CR_TypeDef i2c_0x88 = {.d32 = I2Cx->IC_DMA_CR};
    i2c_0x88.b.rdmae = I2C_InitStruct->I2C_RxDMAEn;
    i2c_0x88.b.tdmae = I2C_InitStruct->I2C_TxDMAEn;
    I2Cx->IC_DMA_CR = i2c_0x88.d32;

    /* Config I2C waterlevel */
    IC_DMA_TDLR_TypeDef i2c_0x8c = {.d32 = I2Cx->IC_DMA_TDLR};
    IC_DMA_RDLR_TypeDef i2c_0x90 = {.d32 = I2Cx->IC_DMA_RDLR};
    i2c_0x8c.b.dmatdl = I2C_InitStruct->I2C_TxWaterlevel;
    i2c_0x90.b.dmardl = I2C_InitStruct->I2C_RxWaterlevel;
    I2Cx->IC_DMA_TDLR = i2c_0x8c.d32;
    I2Cx->IC_DMA_RDLR = i2c_0x90.d32;

    /* Mask all interrupt */
    I2Cx->IC_INTR_MASK = 0x0;

    uint8_t index = I2C_GetIndex(I2Cx);
    uint64_t timeout_us = (uint64_t)9000000 * I2C_TIMEOUT_SCALE / (I2C_InitStruct->I2C_ClockSpeed);
    if (timeout_us < I2C_TIMEOUT_MIN_US)
    {
        timeout_us = I2C_TIMEOUT_MIN_US;
    }
    I2C_TimeOutUs[index] = (uint32_t)timeout_us;
}

/**
 * @brief Fill each I2C_InitStruct member with its default value.
 *
 * @param[in] I2C_InitStruct  Pointer to a I2C_InitTypeDef structure which will be initialized.
 */
void I2C_StructInit(I2C_InitTypeDef *I2C_InitStruct)
{
    /* I2C source clock is 40MHz, depending on clock divider */
    I2C_InitStruct->I2C_Clock             = 40000000;
    /* I2C SCK freqency is 400KHz */
    I2C_InitStruct->I2C_ClockSpeed        = 400000;
    /* Master mode */
    I2C_InitStruct->I2C_DeviceMode        = I2C_DEVICE_MODE_MASTER;
    /* 7-bit address mode */
    I2C_InitStruct->I2C_AddressMode       = I2C_ADDRESS_MODE_7BIT;
    /* Set slave address */
    I2C_InitStruct->I2C_SlaveAddress      = 0;
    /* Enable acknowledge in slave mode */
    I2C_InitStruct->I2C_Ack               = ENABLE;
    /* Tx fifo depth: 24 * 8bits */
    I2C_InitStruct->I2C_TxThresholdLevel  = 0;
    /* Rx fifo depth: 24 * 8bits */
    I2C_InitStruct->I2C_RxThresholdLevel  = 0;
    /* Disable dma */
    I2C_InitStruct->I2C_TxDMAEn           = DISABLE;
    I2C_InitStruct->I2C_RxDMAEn           = DISABLE;
    /* I2C Tx waterlevel, should be less than fifo threshold.
       The best value is I2C FIFO Depth - DMA Msize */
    I2C_InitStruct->I2C_TxWaterlevel      = 23;
    /* I2C Rx waterlevel, should be less than fifo threshold.
       The best value is DMA Msize */
    I2C_InitStruct->I2C_RxWaterlevel      = 1;
    /* Specify I2C scl rising time with 2.2K ohm pull up resistor, the unit is ns*/
    I2C_InitStruct->I2C_RisingTimeNs     = 50;

}

/**
 * @brief Enable or disable the specified I2C peripheral.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the I2Cx peripheral.
 *                      This parameter can be: ENABLE or DISABLE.
 */
void I2C_Cmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Enable or disable the selected I2C peripheral */
    IC_ENABLE_TypeDef i2c_0x6c = {.d32 = I2Cx->IC_ENABLE};
    i2c_0x6c.b.ic_enable = NewState;
    I2Cx->IC_ENABLE = i2c_0x6c.d32;
}


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
 */
I2C_Status I2C_CheckAbortStatus(I2C_TypeDef *I2Cx)
{
    uint32_t abort_status = 0;

    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /* Get abort status */
    abort_status = I2Cx->IC_TX_ABRT_SOURCE;

    if (abort_status & MS_ALL_ABORT)
    {
        /* Clear abort status */
        (void)I2Cx->IC_CLR_TX_ABRT;

        /* Check abort type */
        if (abort_status & ABRT_TXDATA_NOACK)
        {
            return I2C_ABRT_TXDATA_NOACK;
        }

        if (abort_status & ABRT_7B_ADDR_NOACK)
        {
            return I2C_ABRT_7B_ADDR_NOACK;
        }

        if (abort_status & ARB_LOST)
        {
            return I2C_ARB_LOST;
        }

        if (abort_status & ABRT_MASTER_DIS)
        {
            return I2C_ABRT_MASTER_DIS;
        }

        if (abort_status & ABRT_10ADDR1_NOACK)
        {
            return I2C_ABRT_10ADDR1_NOACK;
        }

        if (abort_status & ABRT_10ADDR2_NOACK)
        {
            return I2C_ABRT_10ADDR2_NOACK;
        }
    }

    return I2C_SUCCESS;
}

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
 */
void I2C_INTConfig(I2C_TypeDef *I2Cx, uint16_t I2C_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(I2C_GET_INT(I2C_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected I2C interrupts */
        I2Cx->IC_INTR_MASK |= I2C_INT;
    }
    else
    {
        /* Disable the selected I2C interrupts */
        I2Cx->IC_INTR_MASK &= (uint16_t)~I2C_INT;
    }
}

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
 */
void I2C_ClearINTPendingBit(I2C_TypeDef *I2Cx, uint16_t I2C_IT)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(I2C_GET_INT(I2C_IT));

    switch (I2C_IT)
    {
    case I2C_INT_RX_UNDER:
        {
            (void)I2Cx->IC_CLR_RX_UNDER;
            break;
        }
    case I2C_INT_RX_OVER:
        {
            (void)I2Cx->IC_CLR_RX_OVER;
            break;
        }
    case I2C_INT_TX_OVER:
        {
            (void)I2Cx->IC_CLR_TX_OVER;
            break;
        }
    case I2C_INT_RD_REQ:
        {
            (void)I2Cx->IC_CLR_RD_REQ;
            break;
        }
    case I2C_INT_TX_ABRT:
        {
            (void)I2Cx->IC_CLR_TX_ABRT;
            break;
        }
    case I2C_INT_RX_DONE:
        {
            (void)I2Cx->IC_CLR_RX_DONE;
            break;
        }
    case I2C_INT_ACTIVITY:
        {
            (void)I2Cx->IC_CLR_ACTIVITY;
            break;
        }
    case I2C_INT_STOP_DET:
        {
            (void)I2Cx->IC_CLR_STOP_DET;
            break;
        }
    case I2C_INT_START_DET:
        {
            (void)I2Cx->IC_CLR_START_DET;
            break;
        }
    case I2C_INT_GEN_CALL:
        {
            (void)I2Cx->IC_CLR_GEN_CALL;
            break;
        }
    default:
        {
            break;
        }
    }
}

/**
 * @brief Set slave device address.
 *
 * @param[in] I2Cx     Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] Address  Specifies the target address in master mode, or the device's own address in slave mode.
 */
void I2C_SetSlaveAddress(I2C_TypeDef *I2Cx, uint16_t Address)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /* Configure new target address */
    IC_TAR_TypeDef i2c_0x04 = {.d32 = I2Cx->IC_TAR};
    i2c_0x04.b.ic_tar = Address;
    I2Cx->IC_TAR = i2c_0x04.d32;
}

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
 */
void I2C_SendCmd(I2C_TypeDef *I2Cx, I2CSendCommand_TypeDef command, uint8_t data,
                 FunctionalState StopState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_CMD(command));
    assert_param(IS_FUNCTIONAL_STATE(StopState));

    IC_DATA_CMD_TypeDef i2c_0x10 = {.d32 = 0};
    i2c_0x10.d32 = 0;
    i2c_0x10.b.cmd = command;
    i2c_0x10.b.stop = StopState;
    i2c_0x10.b.dat = data;
    I2Cx->IC_DATA_CMD = i2c_0x10.d32;
}

/**
 * @brief Receive data by the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The most recent received data.
 */
uint8_t I2C_ReceiveData(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /* Return the data in the DR register */
    return (uint8_t)I2Cx->IC_DATA_CMD;
}

/**
 * @brief Get data length in Rx FIFO of the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Rx FIFO.
 */
uint8_t I2C_GetRxFIFOLen(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    return (uint8_t)I2Cx->IC_RXFLR;
}

/**
 * @brief Get data length in Tx FIFO of the I2Cx peripheral.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Tx FIFO.
 */
uint8_t I2C_GetTxFIFOLen(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    return (uint8_t)I2Cx->IC_TXFLR;
}

/**
 * @brief Clear all I2C interrupt.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 */
void I2C_ClearAllINT(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    (void)I2Cx->IC_CLR_INTR;
}

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
 */
FlagStatus I2C_GetFlagState(I2C_TypeDef *I2Cx, uint32_t I2C_FLAG)
{
    FlagStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_GET_FLAG(I2C_FLAG));

    if ((I2Cx->IC_STATUS & I2C_FLAG) != (uint32_t)RESET)
    {
        /* I2C_FLAG is set */
        bit_status = SET;
    }

    /* Return the I2C_FLAG status */
    return  bit_status;
}

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
 */
FlagStatus I2C_CheckEvent(I2C_TypeDef *I2Cx, uint32_t I2C_EVENT)
{
    FlagStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_EVENT(I2C_EVENT));

    if ((I2Cx->IC_TX_ABRT_SOURCE & I2C_EVENT) != (uint32_t)RESET)
    {

        bit_status = SET;
    }

    /* Return the I2C event status */
    return  bit_status;
}

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
 */
ITStatus I2C_GetINTStatus(I2C_TypeDef *I2Cx, uint32_t I2C_IT)
{
    ITStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(I2C_GET_INT(I2C_IT));

    if ((I2Cx->IC_INTR_STAT & I2C_IT) != (uint32_t)RESET)
    {
        bit_status = SET;
    }

    /* Return the I2C_IT status */
    return  bit_status;
}

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
 */
void I2C_DMACmd(I2C_TypeDef *I2Cx, I2CDMARequests_TypeDef I2C_DMAReq,
                FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_I2C_DMAREQ(I2C_DMAReq));

    if (NewState != DISABLE)
    {
        /* Enable the selected I2C DMA request */
        I2Cx->IC_DMA_CR |= I2C_DMAReq;
    }
    else
    {
        /* Disable the selected I2C DMA request */
        I2Cx->IC_DMA_CR &= (uint16_t)~(I2C_DMAReq);
    }
}

/**
 * @brief Set the I2C clock speed, the function needs to be called when I2C disabled.
 *
 * @param[in] I2Cx            Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] I2C_ClockSpeed  Specifies the I2C clock speed.
 *                          This parameter must be set to a value lower than or equal to 1000000.
 */
void I2C_SetClockSpeed(I2C_TypeDef *I2Cx, uint32_t I2C_ClockSpeed)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_CLOCK_SPEED(I2C_ClockSpeed));

    uint32_t I2CSrcClk = 0;
    uint32_t tick_clksrc_ns = 0;
    uint32_t allowedSpeed = 0;
    uint32_t spklen = 0;
    uint32_t scl_low_period_spec_min_ns = 0;
    uint32_t scl_high_period_spec_min_ns = 0;
    uint32_t scl_lcnt_min = 0;
    uint32_t scl_hcnt_min = 0;
    uint32_t scl_low_period_min_ns = 0;
    uint32_t scl_high_period_min_ns = 0;
    uint32_t tick_clkspeed_ns = 0;
    uint32_t total_period_ns = 0;
    uint32_t total_hcnt_lcnt = 0;
    int32_t remaining = 0;
    uint32_t scl_lcnt = 0;
    uint32_t scl_hcnt = 0;

    /* Obtain the I2C Clock source based on the I2C divider. */
    I2CSrcClk = I2C_GetClock(I2Cx);

    /* Tick of I2C clock source in ns. */
    tick_clksrc_ns = NS_PER_SECOND / I2CSrcClk;

    /* Limit the maximum I2C speed according to the I2C clock source. */
    if (I2CSrcClk == 40000000)
    {
        allowedSpeed = 1000000;
    }
    else if (I2CSrcClk == 20000000)
    {
        allowedSpeed = 400000;
    }
    else
    {
        allowedSpeed = 100000;
    }
    /* Set Max I2C Clock speed. */
    I2C_ClockSpeed = (I2C_ClockSpeed > allowedSpeed) ? allowedSpeed : I2C_ClockSpeed;

    /* Set the spike time according to SPEC */
    /* For Standard mode, there is no limit on spike suppression time, use default value. */
    if (I2C_ClockSpeed <= 100000)
    {
        spklen = 0x05;
    }
    /* For Fast mode (plus), the max spike suppression time is 50ns. */
    else
    {
        spklen = 0x01;
    }

    /* Set suppression limit */
    I2Cx->IC_FS_SPKLEN = spklen & 0xFFFF;

    /******************* Calulate the SCL low high count based on SPEC *******************/
    /* Get the minimum of scl low high period specified in the spec */
    if (I2C_ClockSpeed <= 100000)
    {
        scl_low_period_spec_min_ns = I2C_STANDARD_MODE_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_STANDARD_MODE_SCL_HIGH_PERIOD_MIN_NS;
    }
    else if (I2C_ClockSpeed <= 400000)
    {
        scl_low_period_spec_min_ns = I2C_FAST_MODE_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_FAST_MODE_SCL_HIGH_PERIOD_MIN_NS;
    }
    else
    {
        scl_low_period_spec_min_ns = I2C_FAST_MODE_PLUS_SCL_LOW_PERIOD_MIN_NS;
        scl_high_period_spec_min_ns = I2C_FAST_MODE_PLUS_SCL_HIGH_PERIOD_MIN_NS;
    }


    /* Calulate the minimum of scl low high period based on LCNT/HCNT specified in hardware:
     *
     * Firstly, get the minimum LCNT HCNT specified in hardware.
     * - LCNT: IC_SS_SCL_LCNT and IC_FS_SCL_LCNT register values must be larger than IC_FS_SPKLEN + 7.
     * - HCNT: IC_SS_SCL_HCNT and IC_FS_SCL_HCNT register values must be larger than IC_FS_SPKLEN + 5.
     * Use +1 to enforce strictly greater with integer registers.
     *
     * Secondly, calulate the minimum of scl high/low period based on the LCNT/HCNT.
     */

    scl_lcnt_min = spklen + 7 + 1;
    scl_hcnt_min = spklen + 5 + 1;
    scl_low_period_min_ns = (scl_lcnt_min + I2C_SCL_LOW_PERIOD_COMPENSATE) * tick_clksrc_ns;
    scl_high_period_min_ns = (scl_hcnt_min + spklen + I2C_SCL_HIGH_PERIOD_COMPENSATE) *
                             tick_clksrc_ns;

    /* Final minimum: satisfy both spec and hardware. */
    scl_low_period_min_ns = (scl_low_period_min_ns > scl_low_period_spec_min_ns) ?
                            scl_low_period_min_ns : scl_low_period_spec_min_ns;
    scl_high_period_min_ns = (scl_high_period_min_ns > scl_high_period_spec_min_ns) ?
                             scl_high_period_min_ns : scl_high_period_spec_min_ns;

    scl_lcnt_min = ROUNDUP(scl_low_period_min_ns, tick_clksrc_ns) - I2C_SCL_LOW_PERIOD_COMPENSATE;
    scl_hcnt_min = ROUNDUP(scl_high_period_min_ns,
                           tick_clksrc_ns) - spklen - I2C_SCL_HIGH_PERIOD_COMPENSATE;

    /*************** Calulate the SCL low high count based on I2C_Clock_Speed ***************/

    /* Calculate target total (high+low) counter based on the desired frequency of I2C SCL.
     * Firstly, calulate the total period: tick_clkspeed_ns minus I2C_RisingTimeNs.
     *   - Notes: I2C_RisingTimeNs should be below the range.
     * Secondly, total_period_ns div tick_clksrc_ns, round up.
     * Then subtract SPKLEN and path compensations to get pure HCNT+LCNT sum.
     */

    tick_clkspeed_ns = NS_PER_SECOND / I2C_ClockSpeed;
    total_period_ns = tick_clkspeed_ns - I2C_RisingTimeNs;
    total_hcnt_lcnt = (ROUNDUP(total_period_ns, tick_clksrc_ns)
                       - spklen - I2C_SCL_HIGH_PERIOD_COMPENSATE - I2C_SCL_LOW_PERIOD_COMPENSATE);

    /***************** Distibute the remaining count to the SCL low high *****************/

    /* Calculate the remaining as total_hcnt_lcnt - (scl_lcnt_min + scl_hcnt_min),
     * distribute the remaining counts between low and high count.
     */

    remaining = total_hcnt_lcnt - scl_lcnt_min - scl_hcnt_min;
    scl_lcnt = scl_lcnt_min;
    scl_hcnt = scl_hcnt_min;
    if (remaining > 0)
    {
        scl_lcnt = scl_lcnt_min + (uint32_t)(remaining / 2);
        scl_hcnt = total_hcnt_lcnt - scl_lcnt;
    }

    /* Set speed mode and write counters to responsing registers */
    IC_CON_TypeDef i2c_ctrl = {.d32 = I2Cx->IC_CON};
    if (I2C_ClockSpeed <= 100000)
    {
        /*Configure I2C speed in standard mode*/
        i2c_ctrl.b.speed = 0x1;
        I2Cx->IC_CON = i2c_ctrl.d32;
        I2Cx->IC_SS_SCL_LCNT = scl_lcnt & 0xFFFF;
        I2Cx->IC_SS_SCL_HCNT = scl_hcnt & 0xFFFF;
    }
    else
    {
        /* Configure I2C speed in fast mode or fast mode plus*/
        i2c_ctrl.b.speed = 0x2;
        I2Cx->IC_CON = i2c_ctrl.d32;
        I2Cx->IC_FS_SCL_LCNT = scl_lcnt & 0xFFFF;
        I2Cx->IC_FS_SCL_HCNT = scl_hcnt & 0xFFFF;
    }

}

#if (I2C_SUPPORT_WRAPPER_MODE == 1)
/**
 * @brief Enable or disable the I2C wrapper mode.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the wrapper mode.
 *                      This parameter can be: ENABLE or DISABLE.
 */
void I2C_WrapperModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    WRAP_CR_TypeDef i2c_0x10c = {.d32 = I2Cx->WRAP_CR};
    i2c_0x10c.b.wrapper_clk_en = NewState;
    I2Cx->WRAP_CR = i2c_0x10c.d32;
}

/**
 * @brief Set the I2C wrapper transfer mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] mode  Transfer mode to set. Refer to @ref I2C_WRAPPER_TRANS_MODE.
 *
 * @return The status of set transfer mode.
 * @retval true   Set successfully.
 * @retval false  Set failed.
 */
bool I2C_WrapperSetTransMode(I2C_TypeDef *I2Cx, uint32_t mode)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    WRAP_CR_TypeDef i2c_0x10c = {.d32 = I2Cx->WRAP_CR};
    i2c_0x10c.b.trans_mode = mode;
    I2Cx->WRAP_CR = i2c_0x10c.d32;
    return i2c_0x10c.b.wrapper_busy;
}

/**
 * @brief Set the I2C wrapper write data number.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] num   Number of bytes to write.
 *                  This parameter must be set to a value between 1 and 24.
 */
void I2C_WrapperSetWriteNum(I2C_TypeDef *I2Cx, uint8_t num)
{
    /* num should be less than 24 */
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    I2Cx->RAP_WCMD_NUM = num - 1;
}

/**
 * @brief Set the I2C wrapper write data.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] buf   Pointer to the data buffer to be written.
 * @param[in] num   Number of bytes in the data buffer.
 */
void I2C_WrapperSetWriteData(I2C_TypeDef *I2Cx, const uint8_t *buf, uint8_t num)
{
    /* num should be less than 24 */
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    for (uint8_t i = 0; i < num; i++)
    {
        I2Cx->RAP_WCMD_DATA = *buf++;
    }
}

/**
 * @brief Get data length in Tx FIFO via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Tx FIFO.
 */
uint8_t I2C_WrapperGetTxFIFOLen(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    RAP_BUF_CR_TypeDef i2c_0x114 = {.d32 = I2Cx->RAP_BUF_CR};
    return i2c_0x114.b.wrap_buf_amount;
}

/**
 * @brief Clear the I2C wrapper Tx FIFO.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 */
void I2C_WrapperClearTxFIFO(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    RAP_BUF_CR_TypeDef i2c_0x114 = {.d32 = I2Cx->RAP_BUF_CR};
    i2c_0x114.b.wrap_buf_clear = 1;
    I2Cx->RAP_BUF_CR = i2c_0x114.d32;
}

/**
 * @brief Set the I2C wrapper read data number.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] num   Number of bytes to read.
 */
void I2C_WrapperSetReadNum(I2C_TypeDef *I2Cx, uint16_t num)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    I2Cx->RAP_RCMD_NUM = num - 1;
}

/**
 * @brief Receive data via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The received data.
 */
uint8_t I2C_WrapperReceiveData(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    /* Return the data in the DR register */
    return I2C_ReceiveData(I2Cx);
}

/**
 * @brief Get data length in Rx FIFO via wrapper mode.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return Current data number in Rx FIFO.
 */
uint8_t I2C_WrapperGetRxFIFOLen(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    return I2C_GetRxFIFOLen(I2Cx);
}

/**
 * @brief Start I2C wrapper transfer.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 */
void I2C_WrapperTransStart(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    WRAP_CR_TypeDef i2c_0x10c = {.d32 = I2Cx->WRAP_CR};
    i2c_0x10c.b.start_wrapper = 1;
    I2Cx->WRAP_CR = i2c_0x10c.d32;
}

/**
 * @brief Check whether I2C wrapper mode is busy.
 *
 * @param[in] I2Cx  Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 *
 * @return The status of busy.
 * @retval true   Busy.
 * @retval false  Not busy.
 */
bool I2C_WrapperBusyCheck(I2C_TypeDef *I2Cx)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));

    WRAP_CR_TypeDef i2c_0x10c = {.d32 = I2Cx->WRAP_CR};
    return i2c_0x10c.b.wrapper_busy;
}
#endif

#if (I2C_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the I2C RAP mode.
 *
 * @param[in] I2Cx      Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] NewState  New state of the RAP mode.
 *                      This parameter can be: ENABLE or DISABLE.
 */
void I2C_RAPModeCmd(I2C_TypeDef *I2Cx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    WRAP_CR_TypeDef i2c_0x10c = {.d32 = I2Cx->WRAP_CR};
    i2c_0x10c.b.rap_mode = NewState;
    I2Cx->WRAP_CR = i2c_0x10c.d32;
}

/**
 * @brief Trigger the specified I2C action.
 *
 * @param[in] I2Cx    Select the I2C peripheral, refer to @ref I2C_DECLARATION.
 * @param[in] Action  Action to be triggered. Refer to @ref I2C_ACTION.
 */
void I2C_ActionTrigger(I2C_TypeDef *I2Cx, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_I2C_ALL_PERIPH(I2Cx));
    assert_param(IS_I2C_ACTION(Action));

    I2Cx->RAP_TASK |= BIT(Action);
}

#endif



