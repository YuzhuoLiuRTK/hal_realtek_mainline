/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_rtc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
extern void RTC_CompAutoReloadCmd(RTCCompIndex_TypeDef Index, FunctionalState NewState);
#endif

/**
 * 1.5T @32K spacing required between two accesses to a comparator register.
 */
#define DELAY_BETWEEN_SET_COMP()          platform_delay_us(47)   //1.5T 32K

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * @brief  Deinitialize the RTC peripheral registers to their default reset values(turn off clock).
  */
void RTC_DeInit(void)
{
#if (RTC_SUPPORT_RESET_REGISTER_TO_DEFAULT == 1)
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = 0};
    rtc_0x00.b.rtc_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    RTC_WRITE(RTC_CR0, 0);
#else
    /* Stop RTC counter */
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_start = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);

    /* Disable wakeup signal */
    rtc_0x00.b.rtc_nv_ie = 0;
    rtc_0x00.b.rtc_wk_ie = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);

    /* Clear all RTC interrupt & wakeup. */
    RTC_WRITE_DELAY(RTC_INT_CLEAR, 0xFFFF);

    /* Clear prescale and prescale comparator register. */
    RTC_WRITE(RTC_PRESCALER0, 0);
    RTC_WRITE(RTC_PRESCALE_CMP0, 0);

    /* Clear all comparator register. */
    RTC_WRITE(RTC_COMP_0, 0);
    RTC_WRITE(RTC_COMP_1, 0);
    RTC_WRITE(RTC_COMP_2, 0);
    RTC_WRITE(RTC_COMP_3, 0);

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
    RTC_WRITE(RTC_COMP0_GT, 0);
    RTC_WRITE(RTC_COMP1_GT, 0);
    RTC_WRITE(RTC_COMP2_GT, 0);
    RTC_WRITE(RTC_COMP3_GT, 0);
#endif

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
    RTC_WRITE(RTC_RELOAD_CTRL, 0);
    RTC_WRITE(RTC_COMP_0_RELOAD, 0);
    RTC_WRITE(RTC_COMP_1_RELOAD, 0);
    RTC_WRITE(RTC_COMP_2_RELOAD, 0);
    RTC_WRITE(RTC_COMP_3_RELOAD, 0);
#endif

    /* Reset prescale counter and counter */
    rtc_0x00.d32 = 0;
    rtc_0x00.b.rtc_cnt_rst = 1;
    rtc_0x00.b.rtc_pre_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    RTC_WRITE(RTC_CR0, 0);
#endif

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * @brief  Set RTC prescaler value.
  * @param  Value: The prescaler value to be set. Should be no more than 12 bits.
  */
void RTC_SetPrescaler(uint16_t Value)
{
    RTC_WRITE(RTC_PRESCALER0, Value & 0xFFF);
}

/**
  * @brief  Start or stop RTC peripheral.
  * @param  NewState: New state of RTC peripheral.
  *         This parameter can be the following values:
  *         @arg ENABLE: Start RTC.
  *         @arg DISABLE: Stop RTC.
  */
void RTC_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* Start or stop RTC */
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_start = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Enable or disable the specified RTC interrupt source.
  * @param  RTC_INT: specifies the RTC interrupt source to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_INT_TICK: tick interrupt
  *         @arg RTC_INT_OVERFLOW: counter overflow interrupt
  *         @arg RTC_INT_PRECOMP: prescale compare interrupt
  *         @arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt
  *         @arg RTC_INT_COMP0: compare 0 interrupt
  *         @arg RTC_INT_COMP1: compare 1 interrupt
  *         @arg RTC_INT_COMP2: compare 2 interrupt
  *         @arg RTC_INT_COMP3: compare 3 interrupt
  * @param  NewState: New state of the specified RTC interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  */
void RTC_INTConfig(uint32_t RTC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_INTERRUPT(RTC_INT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    if (NewState == ENABLE)
    {
        rtc_0x00.d32 |= RTC_INT;
    }
    else
    {
        rtc_0x00.d32 &= ~RTC_INT;
    }
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Enable or disable the specified RTC wakeup function.
  * @param  RTC_WAKEUP: specifies the RTC wakeup function to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_WAKEUP_TICK: tick wakeup function
  *         @arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         @arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         @arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
  *         @arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         @arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         @arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         @arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  * @param  NewState: New state of the specified RTC wakeup function.
  *         This parameter can be: ENABLE or DISABLE.
  */
void RTC_WakeUpConfig(uint32_t RTC_WAKEUP, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_WAKUP(RTC_WAKEUP));
    assert_param(IS_FUNCTIONAL_STATE(NewState));


    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    if (NewState == ENABLE)
    {
        rtc_0x00.d32 |= RTC_WAKEUP;
    }
    else
    {
        rtc_0x00.d32 &= ~RTC_WAKEUP;
    }
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Enable RTC interrupt signal to CPU NVIC.
  * @param  NewState: Enable or disable RTC interrupt signal to MCU.
  *         This parameter can be: ENABLE or DISABLE.
  */
void RTC_NVICCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_nv_ie = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
 * @brief  Enable or disable system wake up function of RTC.
 * @param  NewState: New state of the wake up function.
 *         This parameter can be: ENABLE or DISABLE.
 */
void RTC_WakeUpCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_wk_ie = NewState;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Get the specified RTC interrupt status.
  * @param  RTC_INT: specifies the RTC interrupt source to check.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_INT_TICK: RTC tick interrupt source
  *         @arg RTC_INT_PRECOMP: prescale compare interrupt source
  *         @arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt source
  *         @arg RTC_INT_COMP0: compare 0 interrupt source
  *         @arg RTC_INT_COMP1: compare 1 interrupt source
  *         @arg RTC_INT_COMP2: compare 2 interrupt source
  *         @arg RTC_INT_COMP3: compare 3 interrupt source
  * @return  The status of @ref RTC_INTERRUPTS.
  * @retval SET    The RTC interrupt has occurred.
  * @retval RESET  The RTC interrupt has not occurred.
  */
ITStatus RTC_GetINTStatus(uint32_t RTC_INT)
{
    /* Check the parameters */
    assert_param(IS_RTC_INTERRUPT(RTC_INT));

    if ((RTC->RTC_INT_SR & (RTC_INT >> 8)) != (uint32_t)RESET)
    {
        return SET;
    }
    return  RESET;
}

/**
  * @brief  Get the specified RTC wakeup interrupt status.
  * @param  RTC_WAKEUP: specifies the RTC wakeup interrupt sources to check.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_WAKEUP_TICK: tick wakeup function
  *         @arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         @arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         @arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
  *         @arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         @arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         @arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         @arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  * @return  The status of @ref RTC_WAKEUP.
  * @retval SET    The RTC wakeup interrupt has occurred.
  * @retval RESET  The RTC wakeup interrupt has not occurred.
  */
ITStatus RTC_GetWakeUpStatus(uint32_t RTC_WAKEUP)
{
    /* Check the parameters */
    assert_param(IS_RTC_WAKUP(RTC_WAKEUP));

    if ((RTC->RTC_INT_SR & (RTC_WAKEUP >> 8)) != (uint32_t)RESET)
    {
        return SET;
    }
    return  RESET;
}

/**
  * @brief  Clear the interrupt pending bit of RTC.
  * @param  RTC_INT: specifies the RTC interrupt flag to clear.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_INT_TICK: RTC tick interrupt source
  *         @arg RTC_INT_OVERFLOW: RTC counter overflow interrupt source
  *         @arg RTC_INT_PRECOMP: prescale compare interrupt source
  *         @arg RTC_INT_PRECOMP_COMP3: prescale & compare 3 interrupt source
  *         @arg RTC_INT_COMP0: compare 0 interrupt source
  *         @arg RTC_INT_COMP1: compare 1 interrupt source
  *         @arg RTC_INT_COMP2: compare 2 interrupt source
  *         @arg RTC_INT_COMP3: compare 3 interrupt source
  */
void RTC_ClearINTPendingBit(uint32_t RTC_INT)
{
    /* Check the parameters */
    assert_param(IS_RTC_INTERRUPT(RTC_INT));

    /* W1C: write only the requested bit. */
    RTC_WRITE_DELAY(RTC_INT_CLEAR, RTC_INT >> 8);
}

/**
  * @brief  Clear the wakeup interrupt pending bit of RTC.
  * @param  RTC_WAKEUP: specifies the RTC wakeup flag to clear.
  *         This parameter can be any combination of the following values:
  *         @arg RTC_WAKEUP_TICK: tick wakeup function
  *         @arg RTC_WAKEUP_OVERFLOW: tick wakeup function
  *         @arg RTC_WAKEUP_PRECOMP: prescale compare wakeup function
  *         @arg RTC_WAKEUP_PRECOMP_COMP3: prescale & compare 3 wakeup function
  *         @arg RTC_WAKEUP_COMP0: compare 0 wakeup function
  *         @arg RTC_WAKEUP_COMP1: compare 1 wakeup function
  *         @arg RTC_WAKEUP_COMP2: compare 2 wakeup function
  *         @arg RTC_WAKEUP_COMP3: compare 3 wakeup function
  */
void RTC_ClearWakeUpStatusBit(uint32_t RTC_WAKEUP)
{
    /* Check the parameters */
    assert_param(IS_RTC_WAKUP(RTC_WAKEUP));

    /* W1C: write only the requested bit. */
    RTC_WRITE_DELAY(RTC_INT_CLEAR, RTC_WAKEUP >> 8);
}

/**
  * @brief  Clear the interrupt pending bit of the specified RTC comparator.
  * @param  Index: The comparator number, Refer to @ref RTC_COMPARE_INDEX.
  */
void RTC_ClearCompINT(RTCCompIndex_TypeDef Index)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMPARE(Index));

    /* W1C: write only the requested bit. */
    RTC_WRITE_DELAY(RTC_INT_CLEAR, ((RTC_INT_COMP0 >> 8) << (uint32_t)Index));
}

/**
  * @brief  Clear the overflow interrupt pending bit of RTC.
  */
void RTC_ClearOverFlowINT(void)
{
    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = 0};
    rtc_0x04.b.rtc_cnt_ov_clr = 0x1;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * @brief  Clear the tick interrupt pending bit of RTC.
  */
void RTC_ClearTickINT(void)
{
    RTC_INT_CLEAR_TypeDef rtc_0x04 = {.d32 = 0};
    rtc_0x04.b.rtc_tick_clr = 0x1;
    RTC_WRITE_DELAY(RTC_INT_CLEAR, rtc_0x04.d32);
}

/**
  * @brief  Set RTC comparator value.
  * @param  Index: The comparator number can range from 0 to 3, Refer to @ref RTC_COMPARE_INDEX.
  * @param  Value: The comparator value to be set. Should be no more than 24 bits.
  */
void RTC_SetCompValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMPARE(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP_0, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP_1, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP_2, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP_3, Value);
        break;
    default:
        break;
    }

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * @brief  Get RTC comparator value.
  * @param  Index: The comparator number, Refer to @ref RTC_COMPARE_INDEX.
  * @return The comparator value.
  */
uint32_t RTC_GetCompValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP_0) + Index));
}

/**
  * @brief  Set RTC prescaler comparator value.
  * @param  Value: The prescaler comparator value to be set. Should be no more than 12 bits.
  */
void RTC_SetPreCompValue(uint32_t Value)
{
    RTC_WRITE(RTC_PRESCALE_CMP0, Value & 0xFFF);
}

/**
  * @brief  Get RTC prescaler comparator value.
  * @return The prescaler comparator value.
  */
uint32_t RTC_GetPreCompValue(void)
{
    return (RTC->RTC_PRESCALE_CMP0 & 0xFFF);
}

/**
  * @brief  Reset counter value of RTC.
  */
void RTC_ResetCounter(void)
{
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    rtc_0x00.b.rtc_cnt_rst = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Get counter value of RTC.
  * @return The counter value.
  */
uint32_t RTC_GetCounter(void)
{
    return RTC->RTC_CNT0;
}

/**
  * @brief  Reset prescaler counter value of RTC.
  */
void RTC_ResetPrescalerCounter(void)
{
    RTC_CR0_TypeDef rtc_0x00 = {.d32 = RTC->RTC_CR0};
    rtc_0x00.b.rtc_pre_cnt_rst = 1;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
    __NOP();
    __NOP();
    rtc_0x00.b.rtc_pre_cnt_rst = 0;
    RTC_WRITE(RTC_CR0, rtc_0x00.d32);
}

/**
  * @brief  Get prescaler counter value of RTC.
  * @return The prescaler counter value.
  */
uint32_t RTC_GetPreCounter(void)
{
    return (RTC->RTC_PRESCALE_CNT0 & 0xFFF);
}

/**
  * @brief  Set backup register for store time information.
  * @param  Value: Value to write to backup register.
  */
void RTC_SetBackupReg(uint32_t Value)
{
    RTC_WRITE(RTC_BACKUP, Value);
}

/**
  * @brief  Get backup register.
  * @return Register value.
  */
uint32_t RTC_GetBackupReg(void)
{
    return RTC->RTC_BACKUP;
}

#if (RTC_SUPPORT_COMPARE_AUTO_RELOAD == 1)
/**
  * @brief  Set RTC comparator auto reload value.
  * @param  Index: The comparator number, can be 0 ~ 3, Refer to @ref RTC_COMPARE_INDEX.
  * @param  Value: The comparator value to be set.
  */
void RTC_SetCompReloadValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMPARE(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP_0_RELOAD, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP_1_RELOAD, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP_2_RELOAD, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP_3_RELOAD, Value);
        break;
    default:
        break;
    }
}

/**
  * @brief  Get RTC comparator auto reload value.
  * @param  Index: The comparator number, Refer to @ref RTC_COMPARE_INDEX.
  * @return The comparator value.
  */
uint32_t RTC_GetCompReloadValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP_0_RELOAD) + Index));
}

/**
  * @brief  Enable RTC comparator auto reload.
  *         When the counter value reaches the value of comparator, it automatically adds the compare value,
  *         which equals Current Compare + Reload Value.
  * @param  Index: The comparator number, Refer to @ref RTC_COMPARE_INDEX.
  * @param  Comp_Value: The initialize value of comparator.
  * @param  Reload_Value: The comparator auto reload value.
  */
void RTC_EnableCompAutoReload(RTCCompIndex_TypeDef Index, uint32_t Comp_Value,
                              uint32_t Reload_Value)
{
    /* Set comp value before enable auto reload */
    RTC_SetCompValue(Index, Comp_Value);
    RTC_SetCompReloadValue(Index, Reload_Value);

    RTC_CompAutoReloadCmd(Index, ENABLE);
}

/**
  * @brief  Disable RTC comparator auto reload.
  * @param  Index: The comparator number, Refer to @ref RTC_COMPARE_INDEX.
  */
void RTC_DisableCompAutoReload(RTCCompIndex_TypeDef Index)
{
    RTC_CompAutoReloadCmd(Index, DISABLE);
}
#endif

#if (RTC_SUPPORT_WAKEUP_COMPARE_GUARDTIME == 1)
/**
  * @brief  Set RTC comparator GT value.
  * @param  Index: The comparator gt number, can be 0 ~ 3.
  * @param  Value: The comparator value to be set.
  */
void RTC_SetCompGTValue(RTCCompIndex_TypeDef Index, uint32_t Value)
{
    /* Check the parameters */
    assert_param(IS_RTC_COMPARE(Index));

    switch (Index)
    {
    case RTC_COMP0:
        RTC_WRITE(RTC_COMP0_GT, Value);
        break;
    case RTC_COMP1:
        RTC_WRITE(RTC_COMP1_GT, Value);
        break;
    case RTC_COMP2:
        RTC_WRITE(RTC_COMP2_GT, Value);
        break;
    case RTC_COMP3:
        RTC_WRITE(RTC_COMP3_GT, Value);
        break;
    default:
        break;
    }

    /* Accessing comp registers requires 1.5T 32K delay between each access.
       Use one delay for overlapping delays at the last access. */
    DELAY_BETWEEN_SET_COMP();
}

/**
  * @brief  Get RTC comparator GT value.
  * @param  Index: The comparator number 0~3.
  * @return The comparator value.
  */
uint32_t RTC_GetCompGTValue(RTCCompIndex_TypeDef Index)
{
    return (*((volatile uint32_t *)(&RTC->RTC_COMP0_GT) + Index));
}
#endif

#if (RTC_SUPPORT_RAP_FUNCTION == 1)

/**
  * @brief  Enable or disable RTC RAP mode.
  * @param  NewState: New state of RTC RAP mode.
  *         This parameter can be: ENABLE or DISABLE.
  */
void RTC_RAPModeCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    RTC_TASK_CTRL_TypeDef rtc_ctrl = {.d32 = RTC->RTC_TASK_CTRL};
    rtc_ctrl.b.rtc_rap_mode = NewState;
    RTC_WRITE_DELAY(RTC_TASK_CTRL, rtc_ctrl.d32);

    return;
}

/**
  * @brief  Trigger RTC action.
  * @param  Action: The RTC action to be triggered, Refer to @ref RTC_ACTION.
  */
void RTC_ActionTrigger(uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_RTC_ACTION(Action));

    /* The task bits are write-auto-clear and read back as 0, so this
       read-modify-write only serves to preserve rtc_rap_mode in bit 0. */
    RTC->RTC_TASK_CTRL |= BIT(Action + 1);

    return;
}

/**
  * @brief  Enable or disable RTC shortcut.
  * @param  Action: The RTC action, Refer to @ref RTC_ACTION.
  * @param  Event: The RTC event, Refer to @ref RTC_EVENT.
  * @param  NewState: New state of the RTC shortcut.
  *         This parameter can be: ENABLE or DISABLE.
  */
void RTC_ShortcutCmd(uint32_t Action, uint32_t Event, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RTC_ACTION(Action));
    assert_param(IS_RTC_EVENT(Event));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    /* RTC_SHOT_CTRL has no subscribe bit for the start task, so a shortcut to
       RTC_ACTION_START cannot be expressed. */
    if (Action == RTC_ACTION_START)
    {
        return;
    }

    if (NewState == ENABLE)
    {
        RTC->RTC_SHOT_CTRL |= (BIT(Action - 1) | BIT(Event + 16));
    }
    else
    {
        RTC->RTC_SHOT_CTRL &= ~(BIT(Action - 1) | BIT(Event + 16));
    }

    return;
}
#endif


