/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_tim.h"
#include "rtl876x_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Store TIM share register values when system enter DLPS.
  * \param  StoreBuf: Store buffer to store TIM share register data.
  * \return None.
  */
void TIMSHARE_DLPSEnter(void *StoreBuf)
{
    TIMSHAREStoreReg_TypeDef *store_buf = (TIMSHAREStoreReg_TypeDef *)StoreBuf;
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);

    store_buf->timshare_reg[0] = *((volatile uint32_t *)0x4000035CUL);
    store_buf->timshare_reg[1] = *((volatile uint32_t *)0x40000360UL);
    store_buf->timshare_reg[2] = *((volatile uint32_t *)0x40000364UL);
    store_buf->timshare_reg[3] = *((volatile uint32_t *)0x40000368UL);
    store_buf->timshare_reg[4] = TIMER_PWM2_CR;
}

/**
  * \brief  Store TIM register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Store buffer to store TIM register data.
  * \return None.
  */
void TIM_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    TIM_TypeDef *TIMx = (TIM_TypeDef *)PeriReg;
    uint32_t tempreg = (uint32_t)TIMx;
    uint32_t timerid = (tempreg - TIM0_REG_BASE) / 20;
    TIMStoreReg_TypeDef *store_buf = (TIMStoreReg_TypeDef *)StoreBuf;

    store_buf->tim_reg[0] = TIMx->LoadCount;
    store_buf->tim_reg[1] = TIMx->ControlReg;
    store_buf->tim_reg[2] = *(volatile uint32_t *)((uint32_t)(&TIMER0_LOAD_COUNT2) + timerid * 0x04);
}

/**
  * \brief  Restore TIM share register values when system exit DLPS.
  * \param  StoreBuf: Restore buffer to restore TIM share register data.
  * \return None
  */
void TIMSHARE_DLPSExit(void *StoreBuf)
{
    TIMSHAREStoreReg_TypeDef *store_buf = (TIMSHAREStoreReg_TypeDef *)StoreBuf;
    RCC_PeriphClockCmd(APBPeriph_TIMER, APBPeriph_TIMER_CLOCK, ENABLE);

    *((volatile uint32_t *)0x4000035CUL) = store_buf->timshare_reg[0];
    *((volatile uint32_t *)0x40000360UL) = store_buf->timshare_reg[1];
    *((volatile uint32_t *)0x40000364UL) = store_buf->timshare_reg[2];
    *((volatile uint32_t *)0x40000368UL) = store_buf->timshare_reg[3];
    TIMER_PWM2_CR                        = store_buf->timshare_reg[4];
}

/**
  * \brief  Restore TIM register values when system exit DLPS.
  * \param  PeriReg: Specifies to select the TIM peripheral.
  * \param  StoreBuf: Restore buffer to restore TIM register data.
  * \return None
  */
void TIM_DLPSExit(void *PeriReg, void *StoreBuf)
{
    TIM_TypeDef *TIMx = (TIM_TypeDef *)PeriReg;
    uint32_t tempreg = (uint32_t)TIMx;
    uint32_t timerid = (tempreg - TIM0_REG_BASE) / 20;
    TIMStoreReg_TypeDef *store_buf = (TIMStoreReg_TypeDef *)StoreBuf;

    TIMx->LoadCount  = store_buf->tim_reg[0];
    TIMx->ControlReg = store_buf->tim_reg[1] ;
    *(volatile uint32_t *)((uint32_t)(&TIMER0_LOAD_COUNT2) + timerid * 0x04) = store_buf->tim_reg[2];
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/
