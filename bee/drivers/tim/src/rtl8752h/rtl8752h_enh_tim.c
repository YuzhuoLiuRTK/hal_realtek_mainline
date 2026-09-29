/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_enh_tim.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/
#define PWM_EMG_STOP        BIT8

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store ENHTIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the ENHTIM peripheral.
  * \param  StoreBuf: Store buffer to store ENHTIM register data.
  * \return None.
  */
void ENHTIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    ENHTIM_TypeDef *ENHTIMx = (ENHTIM_TypeDef *)PeriReg;
    ENHTIMStoreReg_TypeDef *store_buf = (ENHTIMStoreReg_TypeDef *)StoreBuf;

    store_buf->enhtim_reg[0] = ENHTIMx->CR;
    store_buf->enhtim_reg[1] = ENHTIMx->MAX_CNT;
    store_buf->enhtim_reg[2] = ENHTIMx->CCR;
    store_buf->enhtim_reg[3] = ENHTIMx->CCR_FIFO;
}

/**
  * \brief  Store ENHTIM share register values when system enter DLPS.
  * \param  StoreBuf: Store buffer to store ENHTIM share register data.
  * \return None.
  */
void ENHTIMSHARE_DLPSEnter(void *StoreBuf)
{
    ENHTIMShareStoreReg_TypeDef *store_buf = (ENHTIMShareStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);

    store_buf->enhtimshare_reg[0]  = ENH_TIM_SHARE->FIFO_CLR;
    store_buf->enhtimshare_reg[1]  = ENH_TIM_SHARE->CMD;
    store_buf->enhtimshare_reg[2]  = ENH_TIM_SHARE->INT_CMD;
    store_buf->enhtimshare_reg[3]  = ENH_TIM_SHARE->INT_SR;
    store_buf->enhtimshare_reg[4]  = ENH_TIM_SHARE->LC_INT_CMD0;
    store_buf->enhtimshare_reg[5]  = ENH_TIM_SHARE->LC_INT_CMD2;
    store_buf->enhtimshare_reg[6]  = ENH_TIM_SHARE->LC_FIFO_LEVEL0;
    store_buf->enhtimshare_reg[7]  = ENH_TIM_SHARE->LC_FIFO_LEVEL1;
    store_buf->enhtimshare_reg[8]  = *((volatile uint32_t *)0x4000035CUL);
    store_buf->enhtimshare_reg[9]  = *((volatile uint32_t *)0x40000360UL);
    store_buf->enhtimshare_reg[10] = *((volatile uint32_t *)0x40000368UL);
    store_buf->enhtimshare_reg[11] = ENHTIM_PWM_DEADZONE_CR;
}

/**
  * \brief  Restore ENHTIM register values when system exit DLPS.
  * \param  PeriReg: Specifies to select the ENHTIM peripheral.
  * \param  StoreBuf: Restore buffer to restore ENHTIM register data.
  * \return None.
  */
void ENHTIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    ENHTIM_TypeDef *ENHTIMx = (ENHTIM_TypeDef *)PeriReg;
    ENHTIMStoreReg_TypeDef *store_buf = (ENHTIMStoreReg_TypeDef *)StoreBuf;

    ENHTIMx->CR             = store_buf->enhtim_reg[0];
    ENHTIMx->MAX_CNT        = store_buf->enhtim_reg[1];
    ENHTIMx->CCR            = store_buf->enhtim_reg[2];
    ENHTIMx->CCR_FIFO       = store_buf->enhtim_reg[3];
}

/**
  * \brief  Restore ENHTIM share register values when system exit DLPS.
  * \param  StoreBuf: Restore buffer to restore ENHTIM share register data.
  * \return None.
  */
void ENHTIMSHARE_DLPSExit(void *StoreBuf)
{
    ENHTIMShareStoreReg_TypeDef *store_buf = (ENHTIMShareStoreReg_TypeDef *)StoreBuf;

    RCC_PeriphClockCmd(APBPeriph_ENHTIMER, APBPeriph_ENHTIMER_CLOCK, ENABLE);

    *((volatile uint32_t *)0x4000035CUL) = store_buf->enhtimshare_reg[8];
    *((volatile uint32_t *)0x40000360UL) = store_buf->enhtimshare_reg[9];
    *((volatile uint32_t *)0x40000368UL) = store_buf->enhtimshare_reg[10];
    ENH_TIM_SHARE->FIFO_CLR              = store_buf->enhtimshare_reg[0];
    ENH_TIM_SHARE->CMD                   = store_buf->enhtimshare_reg[1] ;
    ENH_TIM_SHARE->INT_CMD               = store_buf->enhtimshare_reg[2];
    ENH_TIM_SHARE->INT_SR                = store_buf->enhtimshare_reg[3];
    ENH_TIM_SHARE->LC_INT_CMD0           = store_buf->enhtimshare_reg[4];
    ENH_TIM_SHARE->LC_INT_CMD2           = store_buf->enhtimshare_reg[5];
    ENH_TIM_SHARE->LC_FIFO_LEVEL0        = store_buf->enhtimshare_reg[6];
    ENH_TIM_SHARE->LC_FIFO_LEVEL1        = store_buf->enhtimshare_reg[7];
    ENHTIM_PWM_DEADZONE_CR               = store_buf->enhtimshare_reg[11];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
