/*
 * Copyright (c) 2026 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_keyscan.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Store buffer to store KEYSCAN register data.
  * \return None.
  */
void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    KEYSCAN_TypeDef *KSCANx = (KEYSCAN_TypeDef *)PeriReg;
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    store_buf->keyscan_reg[0] = KSCANx->CLKDIV;               /* 0x00 */
    store_buf->keyscan_reg[1] = KSCANx->TIMERCR;              /* 0x04 */
    store_buf->keyscan_reg[2] = KSCANx->CR;                   /* 0x08 */
    store_buf->keyscan_reg[3] = KSCANx->COLCR;                /* 0x0C */
    store_buf->keyscan_reg[4] = KSCANx->ROWCR;                /* 0x10 */
    store_buf->keyscan_reg[6] = KSCANx->INTMASK;              /* 0x18 */

    return;
}

/**
  * \brief  Restore KEYSCAN register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the KEYSCAN peripheral.
  * \param  StoreBuf: Restore buffer to restore KEYSCAN register data.
  * \return None
  */
void KEYSCAN_DLPSExit(void *PeriReg, void *StoreBuf, uint32_t scanmode, uint32_t manual_sel)
{
    KEYSCAN_TypeDef *KSCANx = (KEYSCAN_TypeDef *)PeriReg;
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    /* Set FSM to idle state */
    KSCANx->CR &= ~BIT31;
    KSCANx->CLKDIV = store_buf->keyscan_reg[0];
    KSCANx->CR      = (store_buf->keyscan_reg[2] & (~(BIT31 | BIT11 | BIT30))) | scanmode | manual_sel;
    KSCANx->TIMERCR = store_buf->keyscan_reg[1];
    KSCANx->COLCR = store_buf->keyscan_reg[3];
    KSCANx->ROWCR = store_buf->keyscan_reg[4];
    KSCANx->INTMASK = store_buf->keyscan_reg[6];
    KSCANx->CR |= (store_buf->keyscan_reg[2] & (~(BIT11 | BIT30))) | scanmode | manual_sel;

    if (((KSCANx->CR & BIT30) == 0) && ((KSCANx->CR & BIT11) == 0))
    {
        KSCANx->CR |= BIT22;
        KSCANx->CR |= BIT31;
    }


    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

