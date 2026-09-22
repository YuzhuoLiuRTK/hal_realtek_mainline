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
 *                           Private Defines
 *============================================================================*/
#define IR_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define IR_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x7E)//Force off 0x54

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Configure the IR clock source and divider.
 * @param ClockSrc  Specifies the IR clock source, refer to @ref IR_CLOCK_SOURCE.
 * @param ClockDiv  Specifies the IR clock divider, refer to @ref IR_CLOCK_DIVIDER.
 */
void IR_SetClock(IRClockSrc_TypeDef ClockSrc, IRClockDiv_TypeDef ClockDiv)
{
    PCC_REG_UPDATE(PCC_REG_IR,
                   3 << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos,
                   ClockSrc << PCC_REG_IR_R_SCLK_IRRC_SRC_SEL_0_Pos);
    return;
}

/**
 * @brief Enable or disable the IR clock auto mode.
 * @param NewState New state of the IR clock auto mode.
 *        - ENABLE: Enable the IR clock auto mode.
 *        - DISABLE: Disable the IR clock auto mode.
 */
void IR_ClockAutoModeCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        // ir qactive auto gating
        PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_IRRC, 0);
    }
    else
    {
        // ir qactive force on
        PCC_REG_WRITE_BITFIELD(PCC_REG_PERION_CLK_REG4X, FORCE_QACTIVE_IRRC, 1);
        // polling ir clk en ready
        while (!PCC_REG_READ_BITFIELD(PCC_REG_PERION_CLK_REG0X, CLKEN_O_IRRC));
    }

    return;
}
