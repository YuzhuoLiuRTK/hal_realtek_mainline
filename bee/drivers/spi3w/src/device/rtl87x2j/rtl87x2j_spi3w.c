/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_spi3w.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define SPI3W_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define SPI3W_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F)//Force off 0x0A

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Enable or disable the SPI3W clock auto mode.
 *
 * @param[in] Newstate  New state of the SPI3W clock auto mode.
 *                      - ENABLE: Enable the SPI3W clock auto mode.
 *                      - DISABLE: Disable the SPI3W clock auto mode.
 */
void SPI3W_ClockAutoModeCmd(FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(Newstate));

    if (Newstate == ENABLE)
    {
        SPI3W->SPI3W_QACTIVE_MANUAL_CTRL = SPI3W_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        SPI3W->SPI3W_QACTIVE_MANUAL_CTRL = SPI3W_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

/**
 * @brief Set data input PAD pull configuration.
 *
 * @param[in] InPull  Data input pull configuration.
 */
void SPI3W_SetDataInPADPull(SPI3W_DataInPull_TypeDef InPull)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_DATA_IN_PULL(InPull));

    AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG34X, SPI3W_SDIO_IN_PAD_PULL, InPull);
}

/**
 * @brief Set data output PAD pull configuration.
 *
 * @param[in] OutPull  Data output pull configuration.
 */
void SPI3W_SetDataOutPADPull(SPI3W_DataOutPull_TypeDef OutPull)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_DATA_OUT_PULL(OutPull));

    AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG34X, SPI3W_SDIO_OUT_PAD_PULL, OutPull);
}

