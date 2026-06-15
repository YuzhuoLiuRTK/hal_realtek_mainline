/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
*============================================================================*/
#include "rtl_wdt.h"
#include "rtl_rcc.h"
#include "stdio.h"
/*============================================================================*
 *                           Private Constants
 *============================================================================*/
#define WDT_CLOCK_FREQUENCY        (32000)
#define WDT_MAX_TIMEOUT_MS         (((1 << 28) - 1) / (WDT_CLOCK_FREQUENCY / 1000))

#define WDT_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define WDT_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x03)//Force off 0x02

/*============================================================================*
*                           Private Functions
*============================================================================*/
static void WDT_ClockEnable(void)
{
    RCC_ClockCmd(WDT_CLOCK, ENABLE);
}

static bool WDT_CalculateConfig(uint32_t timeout_ms, uint32_t *cnt_limit)
{
    if (timeout_ms > WDT_MAX_TIMEOUT_MS)
    {
        return false;
    }

    *cnt_limit = timeout_ms * (WDT_CLOCK_FREQUENCY / 1000);

    return true;
}

static void WDT_Config(uint32_t cnt_limit, WDTMode_TypeDef wdt_mode)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_cnt_limit = cnt_limit;
    wdt_ctl.b.wdt_mode = wdt_mode;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Start Watchdog. This function will enable watchdog clock, set and start watchdog.
  * \param  Time_ms.
  * \param  WDT_Mode \ref WDTMode_TypeDef.
  * \return true or false.
  */
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    uint32_t cnt_limit;
    printf("WDT start with timeout %u ms, mode %u\n", TimeMs, Mode);
    if (WDT_CalculateConfig(TimeMs, &cnt_limit))
    {
        WDT_ClockEnable();
        WDT_Config(cnt_limit, Mode);
        WDT_Kick();
        WDT_Enable();
        return true;
    }
    return false;
}

/**
  * \brief  Enable Watchdog.
  * \return None.
  */
void WDT_Enable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_en = 1;
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * \brief  Disable Watchdog.
  * \return None.
  */
void WDT_Disable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_en = 0;
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * \brief  Kick Watchdog to restart watchdog timer.
  * \return None.
  */
void WDT_Kick(void)
{
    WDT->WDT_KICK = 0x5A5A;
}

/**
  * \brief  Clear WDT interrupt pending bit.
  * \return None
  */
void WDT_ClearINTPendingBit(void)
{

    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * \brief  Is watchdog enable.
  * \return Is watchdog enable or not
  */
bool WDT_IsEnable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    return (wdt_ctl.b.wdt_en == 1);
}

/**
  * \brief  Get WDT timeout_ms.
  * \return WDT timeout_ms
  */
uint32_t WDT_GetTimeoutMs(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    uint32_t timeout_ms = (wdt_ctl.b.wdt_cnt_limit / (WDT_CLOCK_FREQUENCY / 1000));

    return timeout_ms;
}

/**
  * \brief  Get WDT current count.
  * \return Current count
  */
uint32_t WDT_GetCurrentCount(void)
{
    return WDT->WDT_CURRENT;
}

/**
  * \brief  Get WDT mode.
  * \return WDT mode
  */
WDTMode_TypeDef WDT_GetMode(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    return (WDTMode_TypeDef)(wdt_ctl.b.wdt_mode);
}

/**
  * \brief  Set Clock auto mode.
  * \param  AutoMode: This parameter can ref to \ref Clock_Auto_Mode.
  * \return Current count
  */
void WDT_ClockAutoModeCmd(FunctionalState Newstate)
{
    if (Newstate == ENABLE)
    {
        WDT->WDT_CLK_QACTIVE_CTL = WDT_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        WDT->WDT_CLK_QACTIVE_CTL = WDT_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}
