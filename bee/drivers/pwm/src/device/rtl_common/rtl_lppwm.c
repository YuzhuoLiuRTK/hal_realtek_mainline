/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lppwm.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/


/**
  * @brief  Deinitializes the LPPWM peripheral registers to their default values.
  * @param  LPPWMx Pointer to the LPPWM peripheral registers.
  */
void LPPWM_DeInit(LPPWM_TypeDef *LPPWMx)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = 0};
    lppwm_ctrl.b.lppwm_ch0_reg_rst_n = 0x0;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    lppwm_ctrl.b.lppwm_ch0_reg_rst_n = 0x1;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    return;
}

/**
  * @brief  Initializes the LPPWM peripheral according to the specified parameters.
  * @param  LPPWMx           Pointer to the LPPWM peripheral registers.
  * @param  LPPWM_InitStruct Pointer to the LPPWM initialization structure.
  */
void LPPWM_Init(LPPWM_TypeDef *LPPWMx, LPPWM_InitTypeDef *LPPWM_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));
    assert_param(IS_LPPWM_POLARITY(LPPWM_InitStruct->LPPWM_Polarity));
    assert_param(IS_LPPWM_PERIOD(LPPWM_InitStruct->LPPWM_PeriodHigh));
    assert_param(IS_LPPWM_PERIOD(LPPWM_InitStruct->LPPWM_PeriodLow));

#if (LPPWM_SUPPORT_GPIO_SELECT == 1)
    /* Route the output pin first. */
    assert_param(IS_LPPWM_GPIO_SEL(LPPWM_InitStruct->LPPWM_GPIOSel));

    LPPWM_CH0_GPIO_SEL_TypeDef lppwm_gpio_sel = {.d32 = LPPWMx->LPPWM_CH0_GPIO_SEL};
    lppwm_gpio_sel.b.lppwm_ch0_gpio_sel = LPPWM_InitStruct->LPPWM_GPIOSel;
    LPPWMx->LPPWM_CH0_GPIO_SEL = lppwm_gpio_sel.d32;
#endif

    /* Release reset signal and disable lppwm. */
    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = 0};
    lppwm_ctrl.b.lppwm_ch0_reg_rst_n = 0x1;
    lppwm_ctrl.b.lppwm_ch0_en = 0x0;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    /* Polarity is applied even while the channel is disabled, so this also sets
     * the idle level the pin holds until LPPWM_Cmd() enables the counter. */
    lppwm_ctrl.b.lppwm_ch0_polarity = LPPWM_InitStruct->LPPWM_Polarity;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    LPPWMx->LPPWM_CH0_P0_H = LPPWM_InitStruct->LPPWM_PeriodHigh & 0xFFFF;
    LPPWMx->LPPWM_CH0_P0_L = LPPWM_InitStruct->LPPWM_PeriodLow & 0xFFFF;

    return;
}

/**
  * @brief  Fills each LPPWM_InitStruct member with its default value.
  * @param  LPPWM_InitStruct Pointer to the LPPWM initialization structure.
  */
void LPPWM_StructInit(LPPWM_InitTypeDef *LPPWM_InitStruct)
{
    /* High Polarity is selected as default polarity */
    LPPWM_InitStruct->LPPWM_Polarity = LPPWM_POLARITY_NORMAL;

    /* Set default high & low count  */
    LPPWM_InitStruct->LPPWM_PeriodHigh = 0;
    LPPWM_InitStruct->LPPWM_PeriodLow = 0;

#if (LPPWM_SUPPORT_GPIO_SELECT == 1)
    LPPWM_InitStruct->LPPWM_GPIOSel = LPPWM_GPIO_DISABLE;
#endif

    return;
}

/**
  * @brief  Enable or disable LPPWM peripheral.
  * @param  LPPWMx   Pointer to the LPPWM peripheral registers.
  * @param  NewState New state of the LPPWM peripheral.
  *         - ENABLE: Enable LPPWM.
  *         - DISABLE: Disable LPPWM.
  */
void LPPWM_Cmd(LPPWM_TypeDef *LPPWMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    /* Disabling resets the internal counter but keeps the polarity setting, so
     * the pin falls back to the idle level that polarity selects. */
    LPPWM_CH0_CTL_TypeDef lppwm_ctrl = {.d32 = LPPWMx->LPPWM_CH0_CTL};
    lppwm_ctrl.b.lppwm_ch0_en = NewState;
    LPPWMx->LPPWM_CH0_CTL = lppwm_ctrl.d32;

    return;
}

#if (LPPWM_SUPPORT_GPIO_SELECT == 1)
/**
  * @brief  Select the dedicated LPPWM output pin.
  * @param  LPPWMx  Pointer to the LPPWM peripheral registers.
  * @param  GPIOSel Output pin. @ref LPPWMGPIOSel_TypeDef.
  */
void LPPWM_GPIOSelect(LPPWM_TypeDef *LPPWMx, uint32_t GPIOSel)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));
    assert_param(IS_LPPWM_GPIO_SEL(GPIOSel));

    LPPWM_CH0_GPIO_SEL_TypeDef lppwm_gpio_sel = {.d32 = LPPWMx->LPPWM_CH0_GPIO_SEL};
    lppwm_gpio_sel.b.lppwm_ch0_gpio_sel = GPIOSel;
    LPPWMx->LPPWM_CH0_GPIO_SEL = lppwm_gpio_sel.d32;

    return;
}
#endif /* LPPWM_SUPPORT_GPIO_SELECT */

/**
  * @brief  Change LPPWM output frequency and duty cycle.
  * @param  LPPWMx      Pointer to the LPPWM peripheral registers.
  * @param  period_high LPPWM high period count.
  * @param  period_low  LPPWM low period count.
  */
void LPPWM_ChangeFreqAndDuty(LPPWM_TypeDef *LPPWMx, uint32_t period_high, uint32_t period_low)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));
    assert_param(IS_LPPWM_PERIOD(period_high));
    assert_param(IS_LPPWM_PERIOD(period_low));

    LPPWMx->LPPWM_CH0_P0_H = period_high & 0xFFFF;
    LPPWMx->LPPWM_CH0_P0_L = period_low & 0xFFFF;
}

/**
  * @brief  Get LPPWM current counter value.
  * @param  LPPWMx Pointer to the LPPWM peripheral registers.
  * @return The current counter value.
  */
uint32_t LPPWM_GetCurrentValue(LPPWM_TypeDef *LPPWMx)
{
    /* Check the parameters */
    assert_param(IS_LPPWM_PERIPH(LPPWMx));

    return LPPWMx->LPPWM_CH0_CURRENT & 0xFFFF;
}


