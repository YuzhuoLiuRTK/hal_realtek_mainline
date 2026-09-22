/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_keyscan.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define KEYSCAN_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define KEYSCAN_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F)

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

/**
 * @brief Enable or disable KEYSCAN clock auto mode.
 * @param KEYSCANx Selected KEYSCAN peripheral.
 * @param NewState New state of the KEYSCAN clock auto mode.
 *        - ENABLE: Enable the KEYSCAN clock auto mode.
 *        - DISABLE: Disable the KEYSCAN clock auto mode.
 */
void KEYSCAN_ClockAutoModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_ADC_ALL_PERIPH(KEYSCANx));

    if (Newstate == ENABLE)
    {
        KEYSCANx->KEYSCAN_QACTIVE_CTRL = KEYSCAN_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        KEYSCANx->KEYSCAN_QACTIVE_CTRL = KEYSCAN_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

void KEYSCAN_FIFOConfig(KEYSCAN_TypeDef *KEYSCANx, uint32_t FIFOTriggerLevel, uint32_t KeyLimit)
{
    KEYSCAN_CONFIG3_TypeDef keyscan_0x40 = {.d32 = KEYSCANx->KEYSCAN_CONFIG3};
    /* fifo threshold setting */
    keyscan_0x40.b.keyscan_fifo_th_level = FIFOTriggerLevel;
    /* Key limit setting */
    keyscan_0x40.b.keyscan_fifo_limit = KeyLimit;
    KEYSCANx->KEYSCAN_CONFIG3 =  keyscan_0x40.d32;

    return;
}
