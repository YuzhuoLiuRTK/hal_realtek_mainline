/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lpqdec.h"
#include "rtl_pinmux.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Get LPQDEC X-Axis direction.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter parameter can be one of the following values:
  *         \arg  LPQDEC_AXIS_X: The LPQDEC X axis.
  * \return The direction of the axis. This parameter parameter can be one of the following values:
  *         \retval LPQDEC_AXIS_DIR_UP: The axis is rolling up.
  *         \retval LPQDEC_AXIS_DIR_DOWN: The axis is rolling down.
  */
bool LPQDEC_GetAxisDirection(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS(LPQDEC_AXIS));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr1x = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    return lpqdec_sr1x.b.cnt_dir;
}

/**
  * \brief  Get current state of phase.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \return The current state of phase. \ref LPQDECPhase_TypeDef
  */
LPQDECPhase_TypeDef LPQDEC_GetPhaseState(LPQDEC_TypeDef *LPQDECx)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr_1 = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    LPQDECPhase_TypeDef phase = LPQDEC_PHASE_MODE0;

    /* PHA is the high bit and PHB the low bit, same encoding as x_initial_phase. */
    phase = (lpqdec_sr_1.b.pha_sta << 1) | lpqdec_sr_1.b.phb_sta;

    return phase;
}

/**
 * \brief  Get the NVIC IRQ number for an LPQDEC peripheral instance.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \return CMSIS IRQn_Type value, or 0 if unknown.
 */
int32_t LPQDEC_GetIRQx(LPQDEC_TypeDef *LPQDECx)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (LPQDECx == LPQDEC) { return LPQDEC_IRQn; }
    return 0;
}

/**
 * \brief  Get the LPQDEC peripheral pointer for a given IRQ number.
 *
 * \param  irqn  CMSIS IRQ number.
 * \return LPQDEC peripheral pointer, or NULL if not found.
 */
LPQDEC_TypeDef *LPQDEC_GetLPQDECByIRQx(int32_t irqn)
{
    if (irqn == LPQDEC_IRQn) { return LPQDEC; }
    return NULL;
}

/**
 * \brief  Configure PHA / PHB GPIO pads for an LPQDEC peripheral instance.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  pha_pin  PHA GPIO pin number (0 = skip).
 * \param  phb_pin  PHB GPIO pin number (0 = skip).
 */
void LPQDEC_PadConfig(LPQDEC_TypeDef *LPQDECx, uint8_t pha_pin, uint8_t phb_pin)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (pha_pin != 0)
    {
        Pad_Config(pha_pin, PAD_PON_MODE, PAD_IS_PWRON, PAD_PULL_NONE,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
        Pad_FunctionConfig(pha_pin, LPQDEC_PHA_SEL);
    }
    if (phb_pin != 0)
    {
        Pad_Config(phb_pin, PAD_PON_MODE, PAD_IS_PWRON, PAD_PULL_NONE,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
        Pad_FunctionConfig(phb_pin, LPQDEC_PHB_SEL);
    }
}

/**
 * \brief  Enable or disable the LPQDEC peripheral clock.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  state    ENABLE or DISABLE.
 */
void LPQDEC_RccConfig(LPQDEC_TypeDef *LPQDECx, FunctionalState state)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (LPQDECx == LPQDEC)
    {
        RCC_ClockCmd(LPQDEC_CLOCK, state);
    }
}
