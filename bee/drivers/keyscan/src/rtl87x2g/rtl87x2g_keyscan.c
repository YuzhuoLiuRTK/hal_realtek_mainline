/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl87x2g_keyscan.c
* \brief    This file provides all the KEYSCAN firmware internal functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_keyscan.h"
#include "rtl_rcc.h"

void KEYSCAN_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    KEYSCAN_TypeDef *KSCANx = (KEYSCAN_TypeDef *)PeriReg;
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    store_buf->keyscan_reg[0] = KSCANx->KEYSCAN_CLK_DIV;         /* 0x00 */
    store_buf->keyscan_reg[1] = KSCANx->KEYSCAN_CONFIG1;         /* 0x04 */
    store_buf->keyscan_reg[2] = KSCANx->KEYSCAN_CONFIG2;         /* 0x08 */
    store_buf->keyscan_reg[3] = KSCANx->KEYSCAN_COLUMN_CONFIG;   /* 0x0C */
    store_buf->keyscan_reg[4] = KSCANx->KEYSCAN_ROW_CONFIG;      /* 0x10 */
    store_buf->keyscan_reg[6] = KSCANx->KEYSCAN_INT_MASK;        /* 0x18 */

    return;
}

void KEYSCAN_DLPSExit(void *PeriReg, void *StoreBuf, uint32_t scanmode, uint32_t manual_sel)
{
    KEYSCAN_TypeDef *KSCANx = (KEYSCAN_TypeDef *)PeriReg;
    KEYSCANStoreReg_Typedef *store_buf = (KEYSCANStoreReg_Typedef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_KEYSCAN, APBPeriph_KEYSCAN_CLOCK, ENABLE);

    /* Set FSM to idle state */
    KSCANx->KEYSCAN_CONFIG2 &= ~BIT31;
    KSCANx->KEYSCAN_CLK_DIV = store_buf->keyscan_reg[0];
    KSCANx->KEYSCAN_CONFIG2 = (store_buf->keyscan_reg[2] & (~(BIT31 | BIT11 | BIT30))) |
                              (!!scanmode << 30) | (!!manual_sel << 11);
    KSCANx->KEYSCAN_CONFIG1 = store_buf->keyscan_reg[1];
    KSCANx->KEYSCAN_COLUMN_CONFIG = store_buf->keyscan_reg[3];
    KSCANx->KEYSCAN_ROW_CONFIG = store_buf->keyscan_reg[4];
    KSCANx->KEYSCAN_INT_MASK = store_buf->keyscan_reg[6];
    KSCANx->KEYSCAN_CONFIG2 |= (store_buf->keyscan_reg[2] & (~(BIT11 | BIT30))) |
                               (!!scanmode << 30) | (!!manual_sel << 11);

    if (((KSCANx->KEYSCAN_CONFIG2 & BIT30) == 0) && ((KEYSCAN->KEYSCAN_CONFIG2 & BIT11) == 0))
    {
        KSCANx->KEYSCAN_CONFIG2 |= BIT22;
        KSCANx->KEYSCAN_CONFIG2 |= BIT31;
    }

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

