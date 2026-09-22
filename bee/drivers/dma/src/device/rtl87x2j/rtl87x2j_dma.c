/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_dma.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
DMA_TypeDef *DMA_GetDMAx(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return DMA;
}

DMA_TypeDef *DMA_GetDMAxByCh(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    return DMA;
}

uint8_t DMA_GetDMAChNum(DMA_ChannelTypeDef *DMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return ((uint32_t)DMA_Channelx - (uint32_t)DMA_CH_REG_BASE) / 0x58;
}

uint8_t DMA_GetDMAChNumByCh(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    return DMA_ChannelNum;
}

uint8_t DMA_GetHandshakeNum(DMA_ChannelTypeDef *DMA_Channelx, uint8_t handshake)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    return handshake;
}

/**
 * @brief Get the DMA Channelx of the specified DMA channel number.
 * @param DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @return DMA_Channelx.
 */
DMA_ChannelTypeDef *DMA_GetDMAChannelx(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    return ((DMA_ChannelTypeDef *)(DMA_CH_REG_BASE + DMA_ChannelNum * 0x0058));
}

/**
 * @brief Get the DMA IRQx of the specified DMA channel number.
 * @param DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @return DMA_IRQx.
 */
IRQn_Type DMA_GetDMAIRQx(uint8_t DMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    return ((IRQn_Type)(DMA0_CH0_IRQn + DMA_ChannelNum));
}

/**
 * @brief Get the DMA channel number of the specified DMA IRQx.
 * @param Irq  Specifies the DMA IRQx.
 * @return DMA channel number.
 */
uint8_t DMA_GetDMANumByIRQx(IRQn_Type Irq)
{
    uint8_t dma_num = 0xff;

    dma_num = Irq - DMA0_CH0_IRQn;

    return dma_num;
}

bool DMA_IsValidHandshake(uint8_t hs_src, uint8_t hs_dest)
{
    return true;
}

bool DMA_IsGatherScatterChannel(DMA_ChannelTypeDef *DMA_Channelx)
{
    return false;
}

bool DMA_IsHalfBlcokChannel(DMA_TypeDef *DMAx)
{
    return false;
}

bool DMA_IsSupportContinuousAddrChannel(DMA_ChannelTypeDef *DMA_Channelx)
{
    if (DMA_Channelx == DMA_CH3 || DMA_Channelx == DMA_CH4)
    {
        return true;
    }
    return false;
}

bool DMA_IsSupportBlockCounterChannel(DMA_ChannelTypeDef *DMA_Channelx)
{
    if (DMA_Channelx == DMA_CH3 || DMA_Channelx == DMA_CH4)
    {
        return true;
    }
    return false;
}

bool DMA_IsSupportRAPChannel(DMA_ChannelTypeDef *DMA_Channelx)
{
    if (DMA_Channelx == DMA_CH3 || DMA_Channelx == DMA_CH4)
    {
        return true;
    }
    return false;
}

/**
 * @brief Enable or disable the clock auto mode of the specified DMA channel.
 * @param DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param NewState      New state of the DMA clock auto mode.
 *                      This parameter can be one of the following values:
 *                      - ENABLE: Enable the DMA clock auto mode.
 *                      - DISABLE: Disable the DMA clock auto mode.
 */
void DMA_ClockAutoModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMA_Channelx));

    if (NewState == ENABLE)
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_DMA, GDMA0_MANU_SEL, 0);
        PCC_REG_WRITE_BITFIELD(PCC_REG_DMA, GDMA0_MANU_DAT, 0);
    }
    else
    {
        PCC_REG_WRITE_BITFIELD(PCC_REG_DMA, GDMA0_MANU_SEL, 1);
        PCC_REG_WRITE_BITFIELD(PCC_REG_DMA, GDMA0_MANU_DAT, 1);
    }

    return;
}

/**
 * @brief Set the priority of the specified DMA channel.
 * @param DMA_ChannelNum      Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param DMA_ChannelPriority Specifies the DMA channel priority level.
 */
void DMA_SetPriority(uint8_t DMA_ChannelNum, uint8_t DMA_ChannelPriority)
{
    /* Check the parameters */
    assert_param(IS_DMA_ChannelNum(DMA_ChannelNum));

    DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(DMA_ChannelNum);
    DMA_CFGx_L_TypeDef dma_cfgxl = {.d32 = DMA_Channelx->DMA_CFGx_L};

    /* Set DMA channel priority level */
    dma_cfgxl.b.ch_prior = DMA_ChannelPriority;
    DMA_Channelx->DMA_CFGx_L = dma_cfgxl.d32;
}
