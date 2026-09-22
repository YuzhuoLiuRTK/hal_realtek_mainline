/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_ir.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
/* IR Immediate Number */
#define IR_RX_EXTENSION_INT_OFFSET                  6
#define IR_RX_EXTENSION_MASK_INT_OFFSET             4
#define IR_RX_EXTENSION_INT_STS_OFFSET              2
#define IR_RX_MSK_TO_EN_POS                         14
#define IR_TX_FIFO_OVER_MSK_TO_EN_POS               1
#define IR_TX_FINISH_MSK_TO_EN_POS                  1
#define IR_TX_MSK_TO_EN_POS                         2
#define IR_TX_STATUS_TO_EN_POS                      2

#define IR_DATA_TYPE_MSK                            BIT31
#define IR_TX_LAST_PACKEET_MSK                      BIT30

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitializes the IR peripheral registers to their default values.
 */
void IR_DeInit(void)
{
    RCC_ClockCmd(IR_CLOCK, DISABLE);
}

/**
 * @brief Initializes the IR peripheral according to the specified parameters in IR_InitStruct.
 *
 * @param[in] IR_InitStruct Pointer to a IR_InitTypeDef structure that contains the configuration information for the specified IR peripheral.
 */
void IR_Init(IR_InitTypeDef *IR_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_IR_CLOCK(IR_InitStruct->IR_Clock));

    if (IR_InitStruct->IR_Clock == 40000000)
    {
        assert_param(IS_IR_FREQUENCY_40M(IR_InitStruct->IR_Freq));
    }
#if  IR_SUPPORT_CLOCK_SOURCE_80M
    else if (IR_InitStruct->IR_Clock == 80000000)
    {
        assert_param(IS_IR_FREQUENCY_80M(IR_InitStruct->IR_Freq));
    }
#endif
#if IR_SUPPORT_CLOCK_SOURCE_90M
    else if (IR_InitStruct->IR_Clock == 90000000)
    {
        assert_param(IS_IR_FREQUENCY_90M(IR_InitStruct->IR_Freq));
    }
#endif
#if  IR_SUPPORT_CLOCK_SOURCE_100M
    else if (IR_InitStruct->IR_Clock == 100000000)
    {
        assert_param(IS_IR_FREQUENCY_100M(IR_InitStruct->IR_Freq));
    }
#endif
    assert_param(IS_IR_MODE(IR_InitStruct->IR_Mode));


    /* Configure IR clock divider. Formula: IR_CLK = IO_CLK/(1+IR_CLK_DIV) */
    uint32_t ir_clk_div_num = (IR_InitStruct->IR_Clock / IR_InitStruct->IR_Freq) - 1;
    uint32_t duty_cycle_num = ((double)(ir_clk_div_num + 1.0)) / (double)(IR_InitStruct->IR_DutyCycle);

    IR_CLK_DIV_TypeDef ir_0x00 = {.d32 = IR->IR_CLK_DIV};
    ir_0x00.b.ir_clk_div = ir_clk_div_num;
    IR->IR_CLK_DIV = ir_0x00.d32;
    if (IR_InitStruct->IR_Mode == IR_MODE_TX)
    {
        /* Check the parameters in TX mode */
        assert_param(IS_IR_IDLE_STATUS(IR_InitStruct->IR_TxIdleLevel));
        assert_param(IS_IR_TX_DEF_INVERSE(IR_InitStruct->IR_TxInverse));
        assert_param(IS_IR_TX_THRESHOLD(IR_InitStruct->IR_TxFIFOThrLevel));

        /* Stop Transmission mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_tx_start = 0;

        /* Configure TX mode parameters and disable all TX interrupt */
        ir_0x04.b.ir_mode_sel = IR_InitStruct->IR_Mode;
        ir_0x04.b.ir_tx_idel_state = IR_InitStruct->IR_TxIdleLevel;
        ir_0x04.b.ir_tx_de_inverse = IR_InitStruct->IR_TxInverse;
        ir_0x04.b.ir_tx_fifo_level_th = IR_InitStruct->IR_TxFIFOThrLevel;
        ir_0x04.b.ir_tx_duty_num = duty_cycle_num & 0x3FFF;
#if IR_SUPPORT_TX_MODE_CONFIG
        ir_0x04.b.ir_tx_output_mode = IR_InitStruct->IR_TxOutputMode;
#endif
        IR->IR_TX_CONFIG = ir_0x04.d32;

        /* Clear all TX interrupt and TX FIFO */
        IR->IR_TX_INT_CLR = IR_TX_INT_ALL_CLR | IR_TF_CLR;

        /* Config dma tx */
        IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
        ir_0x50.d32 = 0;
        ir_0x50.b.reg_dma_tx_en = IR_InitStruct->IR_TxDMAEn;
        ir_0x50.b.reg_dma_tx_fifo_th = IR_InitStruct->IR_TxWaterLevel;
        IR->IR_DMA_CONFIG = ir_0x50.d32;
    }
    else
    {
        /* Check the parameters in RX mode */
        assert_param(IS_RX_START_MODE(IR_InitStruct->IR_RxStartMode));
        assert_param(IS_IR_RX_THRESHOLD(IR_InitStruct->IR_RxFIFOThrLevel));
        assert_param(IS_IR_RX_FIFO_FULL_DISCARD(IR_InitStruct->IR_RxFIFOFullCtrl));
        assert_param(IS_RX_RX_TRIGGER_EDGE(IR_InitStruct->IR_RxTriggerMode));
        assert_param(IS_IR_RX_FILTER_TIME_CTRL(IR_InitStruct->IR_RxFilterTime));
        assert_param(IS_IR_RX_COUNT_POLARITY(IR_InitStruct->IR_RxCntThrType));
        assert_param(IS_IR_RX_COUNTER_THRESHOLD(IR_InitStruct->IR_RxCntThr));

        /* Stop Receiving mode */
        IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
        ir_0x18.b.ir_rx_start = 0;
        IR->IR_RX_CONFIG = ir_0x18.d32;

        /* Enable RX mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_mode_sel = IR_InitStruct->IR_Mode;
        IR->IR_TX_CONFIG = ir_0x04.d32;

        /* Configure RX mode parameters and disable all RX interrupt */
        ir_0x18.b.ir_rx_start_mode = IR_InitStruct->IR_RxStartMode;
        ir_0x18.b.ir_rx_trigger_mode = IR_InitStruct->IR_RxTriggerMode;
        ir_0x18.b.ir_rx_filter_stage = IR_InitStruct->IR_RxFilterTime;
        ir_0x18.b.ir_rx_fifo_discard_set = IR_InitStruct->IR_RxFIFOFullCtrl;
        ir_0x18.b.ir_rx_fifo_level_th = IR_InitStruct->IR_RxFIFOThrLevel;
        IR->IR_RX_CONFIG = ir_0x18.d32;

        /* Configure IR RX counter threshold parameters */
        IR_RX_CNT_INT_SEL_TypeDef ir_0x24 = {.d32 = IR->IR_RX_CNT_INT_SEL};
        ir_0x24.b.ir_rx_cnt_thr_trigger_lv = IR_InitStruct->IR_RxCntThrType;
        ir_0x24.b.ir_rx_cnt_thr = IR_InitStruct->IR_RxCntThr;
        IR->IR_RX_CNT_INT_SEL = ir_0x24.d32;

        /* Clear all RX interrupt and RX FIFO */
        IR->IR_RX_INT_CLR = IR_RX_INT_ALL_CLR | IR_RF_CLR;

        /* Config dma rx */
        IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
        ir_0x50.b.reg_dma_rx_en = IR_InitStruct->IR_RxDMAEn;
        ir_0x50.b.reg_dma_rx_fifo_th = IR_InitStruct->IR_RxWaterLevel;
        IR->IR_DMA_CONFIG = ir_0x50.d32;
    }
}

/**
 * @brief Fills each IR_InitStruct member with its default value.
 *
 * @param[in] IR_InitStruct Pointer to an IR_InitTypeDef structure which will be initialized.
 */
void IR_StructInit(IR_InitTypeDef *IR_InitStruct)
{
    /* IR source clock is 40MHz */
    IR_InitStruct->IR_Clock             = IR_CLOCK_40M;
    /* IR carrier freqency is 38KHz */
    IR_InitStruct->IR_Freq              = 38000;
    IR_InitStruct->IR_DutyCycle         = 3;
    /* IR transmitting mode */
    IR_InitStruct->IR_Mode              = IR_MODE_TX;
    /* Tx pin output low when tx is idle */
    IR_InitStruct->IR_TxIdleLevel       = IR_IDLE_OUTPUT_LOW;
    /* Do not inverse tx data */
    IR_InitStruct->IR_TxInverse         = IR_TX_DATA_NORMAL;
    /* Configure RX FIFO threshold level to trigger IR_INT_RF_LEVEL interrupt */
    /* Tx fifo depth: 32 bytes */
    IR_InitStruct->IR_TxFIFOThrLevel    = 0;
    /* Rx auto start */
    IR_InitStruct->IR_RxStartMode       = IR_RX_AUTO_MODE;
    /* Rx fifo depth: 32 bytes */
    IR_InitStruct->IR_RxFIFOThrLevel    = 0;
    /* Discard the oldest received dta if RX FIFO is full */
    IR_InitStruct->IR_RxFIFOFullCtrl    = IR_RX_FIFO_FULL_DISCARD_NEWEST;
    /* Falling edge will trigger rx */
    IR_InitStruct->IR_RxTriggerMode     = IR_RX_FALL_EDGE;
    /* If high to low or low to high transition time <= 50ns,Filter out it. */
    IR_InitStruct->IR_RxFilterTime      = IR_RX_FILTER_TIME_50NS;
    /* Configure trigger type */
    IR_InitStruct->IR_RxCntThrType      = IR_RX_COUNT_LOW_LEVEL;
    /* Configure RX counter threshold.You can use it to decide to stop receiving IR data
       This value can be 0 to 0x7fffffff */
    IR_InitStruct->IR_RxCntThr          = 0x23a;
    /* Disable tx dma */
    IR_InitStruct->IR_TxDMAEn           = DISABLE;
    /* IR Tx waterlevel, should be less than fifo threshold.
       The best value is IR FIFO Depth - DMA Msize */
    IR_InitStruct->IR_TxWaterLevel      = 31;
    /* Disable rx dma */
    IR_InitStruct->IR_RxDMAEn           = DISABLE;
    /* IR Rx waterlevel, should be less than fifo threshold.
       The best value is DMA Msize */
    IR_InitStruct->IR_RxWaterLevel      = 1;

#if IR_SUPPORT_TX_MODE_CONFIG
    IR_InitStruct->IR_TxOutputMode      = IR_TX_PUSH_PULL;
#endif
}

/**
 * @brief Enable or disable the selected IR mode.
 *
 * @param[in] mode Selected IR operation mode.
 *            This parameter can be one of the following values:
 *            - IR_MODE_TX: Transmission mode.
 *            - IR_MODE_RX: Receiving mode.
 * @param[in] NewState New state of the operation mode.
 *            - ENABLE: Enable the selected IR mode.
 *            - DISABLE: Disable the selected IR mode.
 */
void IR_Cmd(uint32_t mode, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_MODE(mode));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (mode == IR_MODE_TX)
    {
        /* Start or stop Transmission mode */
        IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
        ir_0x04.b.ir_tx_start = NewState;
        IR->IR_TX_CONFIG = ir_0x04.d32;
    }
    else
    {
        /* Start or stop Receiving mode */
        IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
        ir_0x18.b.ir_rx_start = NewState;
        IR->IR_RX_CONFIG = ir_0x18.d32;
    }
}

/**
 * @brief Mask or unmask the specified IR interrupt.
 *
 * @param[in] IR_INT Specifies the IR interrupt to be masked or unmasked, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 * @param[in] NewState New state of the specified IR interrupt.
 *            - ENABLE: Mask the specified IR interrupt.
 *            - DISABLE: Unmask the specified IR interrupt.
 */
void IR_MaskINTConfig(uint32_t IR_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (NewState == ENABLE)
    {
        /* Enable the selected IR interrupts in RX mode */
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Handle RX Edge Interrupts (Rising/Falling) specifically */
            if (IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))
            {
                IR->IR_RX_EX_INT |= ((IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)) >>
                                     IR_RX_EXTENSION_MASK_INT_OFFSET);
            }
            /* Handle Normal RX Interrupts. Exclude edge interrupts to avoid incorrect bit shifting into IR_RX_CONFIG */
            if ((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) != 0)
            {
                IR->IR_RX_CONFIG |= ((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) <<
                                     IR_RX_MSK_TO_EN_POS);
            }
        }
        /* Enable the selected IR interrupts in TX mode */
        else
        {
            /* Handle TX FIFO Overflow independently. TF_OF has a unique bit shift position regardless of other settings */
            if (IR_INT & IR_INT_TF_OF)
            {
                IR->IR_TX_CONFIG |= ((IR_INT & IR_INT_TF_OF) << IR_TX_FIFO_OVER_MSK_TO_EN_POS);
            }
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            /* Handle TX Finish Interrupt */
            if (IR_INT & IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR |= ((IR_INT & IR_INT_TX_FINISH) << IR_TX_FINISH_MSK_TO_EN_POS);
            }
            /* Handle Remaining TX Interrupts. Exclude IR_INT_TF_OF and IR_INT_TX_FINISH as they are already handled above */
            if ((IR_INT & (~(IR_INT_TF_OF | IR_INT_TX_FINISH))) != 0)
            {
                IR->IR_TX_CONFIG |= ((IR_INT & (~(IR_INT_TF_OF | IR_INT_TX_FINISH))) << IR_TX_MSK_TO_EN_POS);
            }
#else
            /* Handle Remaining TX Interrupts. Exclude IR_INT_TF_OF to prevent double configuration with incorrect shift */
            if ((IR_INT & (~IR_INT_TF_OF)) != 0)
            {
                IR->IR_TX_CONFIG |= ((IR_INT & (~IR_INT_TF_OF)) << IR_TX_MSK_TO_EN_POS);
            }
#endif
        }
    }
    else
    {
        /* Disable the selected IR interrupts in RX mode */
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Disable RX Edge Interrupts */
            if (IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))
            {
                IR->IR_RX_EX_INT &= ~((IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)) >>
                                      IR_RX_EXTENSION_MASK_INT_OFFSET);
            }
            /* Disable Normal RX Interrupts */
            if ((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) != 0)
            {
                IR->IR_RX_CONFIG &= ~((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) <<
                                      IR_RX_MSK_TO_EN_POS);
            }
        }
        /* Disable the selected IR interrupts in TX mode */
        else
        {
            /* Disable TX FIFO Overflow */
            if (IR_INT & IR_INT_TF_OF)
            {
                IR->IR_TX_CONFIG &= (~((IR_INT & IR_INT_TF_OF) << IR_TX_FIFO_OVER_MSK_TO_EN_POS));
            }
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            /* Disable TX Finish Interrupt */
            if (IR_INT & IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR &= ~((IR_INT & IR_INT_TX_FINISH) << IR_TX_FINISH_MSK_TO_EN_POS);
            }
            /* Disable Remaining TX Interrupts */
            if ((IR_INT & (~(IR_INT_TF_OF | IR_INT_TX_FINISH))) != 0)
            {
                IR->IR_TX_CONFIG &= ~((IR_INT & (~(IR_INT_TF_OF | IR_INT_TX_FINISH))) << IR_TX_MSK_TO_EN_POS);
            }
#else
            /* Disable Remaining TX Interrupts. Exclude IR_INT_TF_OF to avoid writing it to the wrong register. */
            if ((IR_INT & (~IR_INT_TF_OF)) != 0)
            {
                IR->IR_TX_CONFIG &= (~((IR_INT & (~IR_INT_TF_OF)) << IR_TX_MSK_TO_EN_POS));
            }
#endif
        }
    }
}

/**
 * @brief Enables or disables the specified IR interrupt.
 *
 * @param[in] IR_INT Specifies the IR interrupt to be enabled or disabled, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 * @param[in] NewState New state of the specified IR interrupt.
 *            - ENABLE: Enable the specified IR interrupt.
 *            - DISABLE: Disable the specified IR interrupt.
 */
void IR_INTConfig(uint32_t IR_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (NewState == ENABLE)
    {
        /* Enable the selected IR interrupts in RX mode */
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Handle RX Edge Interrupts (Rising/Falling), require specific offset shifting*/
            if (IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))
            {
                IR->IR_RX_EX_INT |= ((IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)) >>
                                     IR_RX_EXTENSION_INT_OFFSET);
            }
            /* Handle Normal RX Interrupts. Exclude edge interrupts to prevent writing incorrect bits to this register. */
            if ((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) != 0)
            {
                IR->IR_RX_CONFIG |= (IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)));
            }
        }
        /* Enable the selected IR interrupts in TX mode */
        else
        {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            /* Handle TX Finish Interrupt */
            if (IR_INT & IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR |= IR_INT_TX_FINISH;
            }
            /* Handle Normal TX Interrupts. Exclude IR_INT_TX_FINISH to avoid writing it to the wrong register. */
            if ((IR_INT & (~IR_INT_TX_FINISH)) != 0)
            {
                /* Enable the selected IR interrupts in TX mode */
                IR->IR_TX_CONFIG |= (IR_INT & (~IR_INT_TX_FINISH));
            }
#else
            /* Handle TX Interrupts. */
            IR->IR_TX_CONFIG |= IR_INT;
#endif
        }
    }
    else
    {
        /* Disable the selected IR interrupts in RX mode */
        if (ir_0x04.b.ir_mode_sel)
        {
            /* Disable RX Edge Interrupts */
            if (IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))
            {
                IR->IR_RX_EX_INT &= ~((IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)) >>
                                      IR_RX_EXTENSION_INT_OFFSET);
            }
            /* Disable Normal RX Interrupts. Exclude edge interrupts before writing to IR_RX_CONFIG */
            if ((IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))) != 0)
            {
                IR->IR_RX_CONFIG &= ~(IR_INT & (~(IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE)));
            }
        }
        /* Disable the selected IR interrupts in TX mode */
        else
        {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
            /* Disable TX Finish Interrupt */
            if (IR_INT & IR_INT_TX_FINISH)
            {
                IR->IR_TX_SR &= ~IR_INT_TX_FINISH;
            }
            /* Disable/Clear Normal TX Interrupts. Exclude IR_INT_TX_FINISH before writing to IR_TX_CONFIG */
            if ((IR_INT & (~IR_INT_TX_FINISH)) != 0)
            {
                IR->IR_TX_CONFIG &= ~(IR_INT & (~IR_INT_TX_FINISH));
            }
#else
            /* Disable TX Interrupts */
            IR->IR_TX_CONFIG &= (~IR_INT);
#endif
        }
    }
}

/**
 * @brief Start trigger receive, only in manual receive mode.
 */
void IR_StartManualRxTrigger(void)
{
    /* Start Rx manual mode */
    IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
    ir_0x18.b.ir_rx_man_start = 0x01;
    IR->IR_RX_CONFIG = ir_0x18.d32;
}

/**
 * @brief Config counter threshold value in receiving mode. It can be used to stop receiving IR data.
 *
 * @param[in] IR_RxCntThrType Count threshold type.
 *            This parameter can be the following values:
 *            - IR_RX_COUNT_LOW_LEVEL: Low level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 *            - IR_RX_COUNT_HIGH_LEVEL: High level counter value >= IR_RxCntThr, trigger IR_INT_RX_CNT_THR interrupt.
 * @param[in] IR_RxCntThr Configure IR Rx counter threshold value which can be 0 to 0x7fffffffUL.
 */
void IR_SetRxCounterThreshold(uint32_t IR_RxCntThrType, uint32_t IR_RxCntThr)
{
    /* Check the parameters */
    assert_param(IS_IR_RX_COUNT_POLARITY(IR_RxCntThrType));
    assert_param(IS_IR_RX_COUNTER_THRESHOLD(IR_RxCntThr));

    /* Configure IR RX counter threshold parameters */
    IR_RX_CNT_INT_SEL_TypeDef ir_0x24 = {.d32 = IR->IR_RX_CNT_INT_SEL};
    ir_0x24.b.ir_rx_cnt_thr = IR_RxCntThr;
    ir_0x24.b.ir_rx_cnt_thr_trigger_lv = IR_RxCntThrType;
    IR->IR_RX_CNT_INT_SEL = ir_0x24.d32;
}

/**
 * @brief Send data.
 *
 * @param[in] pBuf Data buffer to send.
 * @param[in] len Send data length.
 * @param[in] IsLastPacket Specifies whether this buffer is the last packet of data.
 *            - ENABLE: This buffer is the last packet of data. An infrared data transmission is completed.
 *            - DISABLE: This buffer is not the last packet of data. There is data to be transmitted continuously.
 */
void IR_SendBuf(uint32_t *pBuf, uint32_t len, FunctionalState IsLastPacket)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(IsLastPacket));

    uint32_t i = 0;
    if (len > 0)
    {
        i = len - 1;
        while (i--)
        {
            IR->IR_TX_FIFO = *pBuf++;
        }

        /* If send the last IR packet, SET the following bit */
        if (IsLastPacket == ENABLE)
        {
            IR->IR_TX_FIFO = (IR_TX_LAST_PACKEET_MSK | *pBuf);
        }
        else
        {
            IR->IR_TX_FIFO = *pBuf;
        }
    }
}

/**
 * @brief Send compensation data.
 *
 * @param[in] comp_type Compensation level applied to the space waveform only.
 *            This parameter can be a value of @ref IR_COMPENSATION_FLAG.
 * @param[in] pBuf Data buffer to send. Each element is a 32-bit IR waveform word.
 * @param[in] len Number of 32-bit elements in the buffer.
 * @param[in] IsLastPacket Specifies whether this buffer is the last packet of data.
 *            - ENABLE: This buffer is the last packet of data. An infrared data transmission is completed.
 *            - DISABLE: This buffer is not the last packet of data. There is data to be transmitted continuously.
 */
void IR_SendCompenBuf(IRTxCompen_TypeDef comp_type, uint32_t *pBuf, uint32_t len,
                      FunctionalState IsLastPacket)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(IsLastPacket));

    if ((pBuf == NULL) || (len == 0))
    {
        return;
    }

    for (uint32_t i = 0; i < len; i++)
    {
        uint32_t data = pBuf[i];

        /* Space waveform */
        if ((data & IR_DATA_TYPE_MSK) == 0)
        {
            data |= (uint32_t)comp_type;
        }
        else
        {
            /* Mark waveform: compensation field [29:27] must be cleared */
            data &= ~(0x7 << 27);
        }

        /* Set the TX end-waveform bit on the last data of the packet */
        if ((i == (len - 1)) && (IsLastPacket == ENABLE))
        {
            data |= IR_TX_LAST_PACKEET_MSK;
        }

        IR->IR_TX_FIFO = data;
    }
}

/**
 * @brief Read data from RX FIFO.
 *
 * @param[out] pBuf Buffer address to receive data.
 * @param[in] len Read data length.
 */
void IR_ReceiveBuf(uint32_t *pBuf, uint32_t len)
{
    while (len--)
    {
        *pBuf++ = IR->IR_RX_FIFO;
    }
}

/**
 * @brief Get the specified IR interrupt status.
 *
 * @param[in] IR_INT The specified IR interrupt, refer to @ref IR_INTERRUPT.
 *            This parameter can be one of the following values:
 *            - IR_INT_TF_EMPTY: TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL: TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF: TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH: TX finish interrupt.
 *            - IR_INT_RF_FULL: RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL: RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF: RX counter overflow interrupt.
 *            - IR_INT_RF_OF: RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR: RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR: RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RISING_EDGE: IR RX rising edge interrupt.
 *            - IR_INT_FALLING_EDGE: IR RX falling edge interrupt.
 *
 * @return The new state of IR_INT.
 * @retval SET    The specified IR interrupt status is set.
 * @retval RESET  The specified IR interrupt status is not set.
 */
ITStatus IR_GetINTStatus(uint32_t IR_INT)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CONFIG(IR_INT));

    ITStatus bit_status = RESET;

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (ir_0x04.b.ir_mode_sel)
    {
        /* Get the selected IR interrupts in RX mode */
        if (IR_INT & (IR_INT_RISING_EDGE | IR_INT_FALLING_EDGE))
        {
            if (IR->IR_RX_EX_INT & (IR_INT >> IR_RX_EXTENSION_INT_STS_OFFSET))
            {
                bit_status = SET;
            }
        }
        else
        {
            if (IR->IR_RX_SR & IR_INT)
            {
                bit_status = SET;
            }
        }
    }
    /* Get the selected IR interrupts in TX mode */
    else
    {
#if (IR_SUPPORT_TX_FINISH_INTERRUPT == 1)
        /* Check Normal TX Interrupts (TF_EMPTY, TF_LEVEL) */
        if (IR_INT != IR_INT_TF_OF && IR_INT != IR_INT_TX_FINISH)
#else
        if (IR_INT != IR_INT_TF_OF)
#endif
        {
            if (IR->IR_TX_SR & IR_INT)
            {
                bit_status = SET;
            }
        }
        /* Check Special TX Interrupts */
        else
        {
            if (IR->IR_TX_SR & (IR_INT >> IR_TX_STATUS_TO_EN_POS))
            {
                bit_status = SET;
            }
        }
    }

    /* Return the IR_INT status */
    return  bit_status;
}

/**
 * @brief Clear the IR interrupt pending bit.
 *
 * @param[in] IR_CLEAR_INT Specifies the interrupt pending bit to clear, refer to @ref IR_INTERRUPTS_CLEAR_FLAG.
 *            This parameter can be any combination of the following values:
 *            - IR_INT_TF_EMPTY_CLR: Clear TX FIFO empty interrupt.
 *            - IR_INT_TF_LEVEL_CLR: Clear TX FIFO threshold interrupt.
 *            - IR_INT_TF_OF_CLR: Clear TX FIFO overflow interrupt.
 *            - IR_INT_TX_FINISH_CLR: Clear TX finish interrupt.
 *            - IR_INT_RF_FULL_CLR: Clear RX FIFO full interrupt.
 *            - IR_INT_RF_LEVEL_CLR: Clear RX FIFO threshold interrupt.
 *            - IR_INT_RX_CNT_OF_CLR: Clear RX counter overflow interrupt.
 *            - IR_INT_RF_OF_CLR: Clear RX FIFO overflow interrupt.
 *            - IR_INT_RX_CNT_THR_CLR: Clear RX counter threshold interrupt.
 *            - IR_INT_RF_ERROR_CLR: Clear RX FIFO error read interrupt. Trigger when RX FIFO empty and read RX FIFO.
 *            - IR_INT_RX_RISING_EDGE_CLR: Clear RX rising edge interrupt.
 *            - IR_INT_RX_FALLING_EDGE_CLR: Clear RX falling edge interrupt.
 */
void IR_ClearINTPendingBit(uint32_t IR_CLEAR_INT)
{
    /* Check the parameters */
    assert_param(IS_IR_INT_CLEAR(IR_CLEAR_INT));
    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};

    if (ir_0x04.b.ir_mode_sel)
    {
        /* Clear the selected IR interrupts in RX mode */
        IR->IR_RX_INT_CLR |= IR_CLEAR_INT;
    }
    else
    {
        /* Clear the selected IR interrupts in TX mode */
        IR->IR_TX_INT_CLR |= IR_CLEAR_INT;
    }
}

/**
 * @brief Get free size of TX FIFO.
 *
 * @return The free size of TX FIFO.
 */
uint16_t IR_GetTxFIFOFreeLen(void)
{
    IR_TX_SR_TypeDef ir_0x08 = {.d32 = IR->IR_TX_SR};
    return (uint16_t)(IR_TX_FIFO_SIZE - ir_0x08.b.ir_tx_fifo_offset);
}

/**
 * @brief Get data size in RX FIFO.
 *
 * @return Current data size in RX FIFO.
 */
uint16_t IR_GetRxDataLen(void)
{
    IR_RX_SR_TypeDef ir_0x1c = {.d32 = IR->IR_RX_SR};
    return ((uint16_t)(ir_0x1c.b.ir_rx_fifo_offset));
}

/**
 * @brief Send one data.
 *
 * @param[in] data Send data.
 */
void IR_SendData(uint32_t data)
{
    IR->IR_TX_FIFO = data;
}

/**
 * @brief Read one data.
 *
 * @return Data which read from RX FIFO.
 */
uint32_t IR_ReceiveData(void)
{
    return IR->IR_RX_FIFO;
}

/**
 * @brief Set TX threshold, when TX FIFO depth <= threshold value trigger the IR_INT_TF_LEVEL interrupt.
 *
 * @param[in] thd TX threshold.
 */
void IR_SetTxThreshold(uint8_t thd)
{
    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_fifo_level_th = thd;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
 * @brief Set RX threshold, when RX FIFO depth >= threshold value trigger the IR_INT_RF_LEVEL interrupt.
 *
 * @param[in] thd RX threshold.
 */
void IR_SetRxThreshold(uint8_t thd)
{
    IR_RX_CONFIG_TypeDef ir_0x18 = {.d32 = IR->IR_RX_CONFIG};
    ir_0x18.b.ir_rx_fifo_level_th = thd;
    IR->IR_RX_CONFIG = ir_0x18.d32;
}

/**
 * @brief Set TX DMA water level. DMA request is triggered when TX FIFO free space >= water level.
 *
 * @param[in] water_level TX DMA water level. Should be less than TX FIFO depth (32).
 */
void IR_SetTxWaterLevel(uint8_t water_level)
{
    IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
    ir_0x50.b.reg_dma_tx_fifo_th = water_level;
    IR->IR_DMA_CONFIG = ir_0x50.d32;
}

/**
 * @brief Set RX DMA water level. DMA request is triggered when RX FIFO data count >= water level.
 *
 * @param[in] water_level RX DMA water level. Should be less than RX FIFO depth (32).
 */
void IR_SetRxWaterLevel(uint8_t water_level)
{
    IR_DMA_CONFIG_TypeDef ir_0x50 = {.d32 = IR->IR_DMA_CONFIG};
    ir_0x50.b.reg_dma_rx_fifo_th = water_level;
    IR->IR_DMA_CONFIG = ir_0x50.d32;
}

/**
 * @brief Get IR RX current count.
 *
 * @return Current counter.
 */
uint32_t IR_GetRxCurrentCount(void)
{
    IR_RX_CUR_CNT_TypeDef ir_0x30 = {.d32 = IR->IR_RX_CUR_CNT};
    return ir_0x30.b.ir_rx_cur_cnt;
}

/**
 * @brief Clear IR TX FIFO.
 */
void IR_ClearTxFIFO(void)
{
    IR_TX_INT_CLR_TypeDef ir_0x10 = {.d32 = IR->IR_TX_INT_CLR};
    ir_0x10.b.ir_tx_fifo_clr = 0x01;
    IR->IR_TX_INT_CLR = ir_0x10.d32;
}

/**
 * @brief Clear IR RX FIFO.
 */
void IR_ClearRxFIFO(void)
{
    IR_RX_INT_CLR_TypeDef ir_0x20 = {.d32 = IR->IR_RX_INT_CLR};
    ir_0x20.b.ir_rx_fifo_clr = 0x01;
    IR->IR_RX_INT_CLR = ir_0x20.d32;
}

/**
 * @brief Check whether the specified IR flag is set.
 *
 * @param[in] IR_FLAG Specifies the flag to check, refer to @ref IR_FLAG.
 *            This parameter can be one of the following values:
 *            - IR_FLAG_TF_EMPTY: TX FIFO empty flag. If SET, TX FIFO is empty.
 *            - IR_FLAG_TF_FULL: TX FIFO full flag. If SET, TX FIFO is full.
 *            - IR_FLAG_TX_RUN: TX running flag. If SET, TX is running.
 *            - IR_FLAG_RF_EMPTY: RX FIFO empty flag. If SET, RX FIFO is empty.
 *            - IR_FLAG_RF_FULL: RX FIFO full flag. If SET, RX FIFO is full.
 *            - IR_FLAG_RX_RUN: RX running flag. If SET, RX is running.
 *
 * @return The new state of IR_FLAG.
 * @retval SET    The specified IR flag is set.
 * @retval RESET  The specified IR flag is not set.
 */
FlagStatus IR_GetFlagStatus(uint32_t IR_FLAG)
{

    /* Check the parameters */
    assert_param(IS_IR_FLAG(IR_FLAG));

    FlagStatus bitstatus = RESET;

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    if (ir_0x04.b.ir_mode_sel)
    {
        if (IR->IR_RX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
    else
    {
        if (IR->IR_TX_SR & IR_FLAG)
        {
            bitstatus = SET;
        }
        return bitstatus;
    }
}

/**
 * @brief Set whether to inverse the space/mark waveform definition in TX mode.
 *
 * @param[in] NewState New state of the TX waveform definition inverse.
 *            - ENABLE: Inverse the waveform definition. Mark changes to space and space changes to mark.
 *            - DISABLE: Do not inverse the waveform definition.
 */
void IR_TxWaveDefInverseCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_de_inverse = NewState;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
 * @brief Set whether to inverse the high/low level polarity of the TX output.
 *
 * @param[in] NewState New state of the TX output polarity inverse.
 *            - ENABLE: Inverse the TX output level polarity. High level changes to low and low changes to high.
 *            - DISABLE: Do not inverse the TX output level polarity.
 */
void IR_TxPolarityInverseCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TX_CONFIG_TypeDef ir_0x04 = {.d32 = IR->IR_TX_CONFIG};
    ir_0x04.b.ir_tx_output_inverse = NewState;
    IR->IR_TX_CONFIG = ir_0x04.d32;
}

/**
 * @brief Get IR RX Level.
 *
 * @return Current Level.
 */
uint32_t IR_GetRxCurrentLevel(void)
{
    return (IR->IR_RX_LEVEL);

}

#if (IR_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the IR RAP mode.
 *
 * @param[in] NewState New state of the IR RAP mode.
 *            - ENABLE: Enable the IR RAP mode.
 *            - DISABLE: Disable the IR RAP mode.
 */
void IR_RAPModeCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    IR_TASK_CTRL_TypeDef ir_0x54 = {.d32 = IR->IR_TASK_CTRL};
    ir_0x54.b.ir_rap_mode = NewState;
    IR->IR_TASK_CTRL = ir_0x54.d32;

    return;
}

/**
 * @brief Trigger the specified IR action.
 *
 * @param[in] Action Specifies the IR action to trigger.
 *            This parameter can be one of the following values:
 *            - IR_ACTION_START_RX: Start RX action.
 *            - IR_ACTION_START_TX: Start TX action.
 */
void IR_ActionTrigger(uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_IR_ACTION(Action));

    IR_TASK_CTRL_TypeDef ir_0x54 = {.d32 = IR->IR_TASK_CTRL};
    if (Action == IR_ACTION_START_TX)
    {
        ir_0x54.b.ir_fw_task_start_tx = 0x1;
    }
    else if (Action == IR_ACTION_START_RX)
    {
        ir_0x54.b.ir_fw_task_start_rx = 0x1;
    }
    IR->IR_TASK_CTRL = ir_0x54.d32;

    return;
}

#endif



