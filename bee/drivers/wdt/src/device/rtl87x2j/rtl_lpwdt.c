/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
*============================================================================*/
#include "rtl_lpwdt.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Constants
 *============================================================================*/
#define LPWDT_CLOCK_FREQUENCY        (32000)
#define LPWDT_MAX_TIMEOUT_MS         (((1 << 28) - 1) / (LPWDT_CLOCK_FREQUENCY / 1000))
#define LPWDT_VPON_ADDR              0x400003E0

/*============================================================================*
*                           Private Functions
*============================================================================*/
static bool LPWDT_CalculateConfig(uint32_t timeout_ms, uint32_t *cnt_limit)
{
    if (timeout_ms > LPWDT_MAX_TIMEOUT_MS)
    {
        return false;
    }

    *cnt_limit = timeout_ms * (LPWDT_CLOCK_FREQUENCY / 1000);

    return true;
}

static void LPWDT_Config(uint32_t cnt_limit, WDTMode_TypeDef wdt_mode)
{
    /* LPWDT function enable*/
    RCC_ClockCmd(LPWDT_CLOCK, ENABLE);

    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDT->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_mode = wdt_mode;
    lpwdt_reg0.b.lpwdt_cnt_limit = cnt_limit;

    /* counter will go on and counter value is reload from active when enter low power mode*/
    lpwdt_reg0.b.lpwdt_cnt_ctl = 1;
    lpwdt_reg0.b.lpwdt_cnt_reload = 1;
    LPWDT->WDT_REG0X = lpwdt_reg0.d32;
}

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Start Watchdog. This function will enable watchdog clock, set and start watchdog.
  * \param  Time_ms.
  * \param  LPWDT_Mode \ref LPWDTMode_TypeDef.
  * \return true or false.
  */
bool LPWDT_Start(LPWDT_TypeDef *LPWDTx, uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    uint32_t cnt_limit;
    if (LPWDT_CalculateConfig(TimeMs, &cnt_limit))
    {
        LPWDT_Config(cnt_limit, Mode);
        LPWDT_Kick(LPWDTx);
        LPWDT_Enable(LPWDTx);
        return true;
    }
    return false;
}

/**
  * \brief  Enable Watchdog.
  * \return None.
  */
void LPWDT_Enable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_enable = 1;
    LPWDTx->WDT_REG0X = lpwdt_reg0.d32;
}

/**
  * \brief  Disable Watchdog.
  * \return None.
  */
void LPWDT_Disable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_enable = 0;
    LPWDTx->WDT_REG0X = lpwdt_reg0.d32;
}

/**
  * \brief  Kick Watchdog to restart watchdog timer.
  * \return None.
  */
void LPWDT_Kick(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG1X_TypeDef lpwdt_reg1 = {.d32 = LPWDTx->WDT_REG1X};
    lpwdt_reg1.b.lpwdt_cnt_reset = 0x5A5A;
    LPWDTx->WDT_REG1X = lpwdt_reg1.d32;
}

/**
  * \brief  Is watchdog enable.
  * \return Is watchdog enable or not
  */
bool LPWDT_IsEnable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};

    return (lpwdt_reg0.b.lpwdt_enable == 1);
}

/**
  * \brief  Get LPWDT timeout_ms.
  * \return LPWDT timeout_ms
  */
uint32_t LPWDT_GetTimeoutMs(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};

    uint32_t timeout_ms = (lpwdt_reg0.b.lpwdt_cnt_limit / (LPWDT_CLOCK_FREQUENCY / 1000));

    return timeout_ms;
}

/**
  * \brief  Get LPWDT mode.
  * \return LPWDT mode
  */
WDTMode_TypeDef LPWDT_GetMode(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDT->WDT_REG0X};

    return (WDTMode_TypeDef)(lpwdt_reg0.b.lpwdt_mode);
}

/**
  * \brief  Get LPWDT current Count.
  * \return Current Count
  */
uint32_t LPWDT_GetCurrentCount(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG19X_TypeDef lpwdt_reg19 = {.d32 = LPWDT->WDT_REG19X};

    return (uint32_t)lpwdt_reg19.b.lpwdt_current;
}
