/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_rap.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define RAP_CHANNEL_USED_MASK                      (0xC00)

static uint32_t rap_channel_allocated_mask = RAP_CHANNEL_USED_MASK;

/*============================================================================*
 *                           Public Functions
 *============================================================================*/

/**
 * @brief Deinitialize the RAP peripheral registers to their default reset values.
 */
void RAP_DeInit(void)
{
#if (RAP_SUPPORT_DISABE_RAP_FUNCTION == 1)
    RCC_ClockCmd(RAP_CLOCK, DISABLE);
#endif
}

/**
 * @brief Enable or disable the RAP peripheral (routing engine).
 * @param NewState  Enable or disable the RAP peripheral.
 *                  This parameter can be ENABLE or DISABLE.
 */
void RAP_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

#if (RAP_SUPPORT_DISABE_RAP_FUNCTION == 1)
    RAP_CTRL_TypeDef rap_ctrl = {.d32 = RAP->RAP_CTRL};
    rap_ctrl.b.r_en_rap_ctrl = NewState;
    RAP->RAP_CTRL = rap_ctrl.d32;
#endif

    return;
}

/**
 * @brief Enable or disable the specified RAP interrupt for a specific channel.
 * @param RAP_INT    Specifies the RAP interrupt source to be enabled or disabled.
 *                   This parameter can be any of @ref RAP_INTERRUPTS.
 *                   - RAP_INT_TRIGGER: RAP channel trigger interrupt.
 * @param Channel    Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 * @param NewState   Enable or disable the specified RAP interrupt for the channel.
 *                   This parameter can be ENABLE or DISABLE.
 */
void RAP_INTConfig(uint32_t RAP_INT, uint8_t Channel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RAP_INT(RAP_INT));
    assert_param(IS_RAP_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (RAP_INT & RAP_INT_TRIGGER)
    {
        /* Enable: set the channel bit; Disable: clear the channel bit. */
        RAP->INTR_O_EN = NewState ? (RAP->INTR_O_EN | BIT(Channel)) : (RAP->INTR_O_EN & ~BIT(Channel));
    }

    return;
}

/**
 * @brief Enable or disable the RAP wakeup function for a specific channel.
 * @param RAP_WAKEUP  Specifies the RAP wakeup source.
 *                    This parameter can be any of @ref RAP_WAKEUP.
 *                    - RAP_WAKEUP_TRIGGER: RAP channel trigger wakeup.
 * @param Channel     Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 * @param NewState    Enable or disable the specified RAP wakeup function.
 *                    This parameter can be ENABLE or DISABLE.
 */
void RAP_WakeUpConfig(uint32_t RAP_WAKEUP, uint8_t Channel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_RAP_WAKEUP(RAP_WAKEUP));
    assert_param(IS_RAP_CHANNEL(Channel));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (RAP_WAKEUP & RAP_WAKEUP_TRIGGER)
    {
        RAP->INTR_EN = NewState ? (RAP->INTR_EN | BIT(Channel)) : (RAP->INTR_EN & ~BIT(Channel));
    }

    return;
}

/**
 * @brief Check whether the specified RAP interrupt has occurred.
 * @param RAP_INT  Specifies the RAP interrupt source to check.
 *                 This parameter can be any of @ref RAP_INTERRUPTS.
 *                 - RAP_INT_TRIGGER: RAP channel trigger interrupt.
 * @return  The new state of RAP_INT.
 *          - true   The specified RAP interrupt has occurred.
 *          - false  The specified RAP interrupt has not occurred.
 */
bool RAP_GetINTStatus(uint32_t RAP_INT)
{
    /* Check the parameters */
    assert_param(IS_RAP_INT(RAP_INT));

    return ((RAP->RAP_CTRL & RAP_INT) == RAP_INT);
}

/**
 * @brief Clear the RAP interrupt pending bit.
 * @note  This clears the global RAP interrupt pending status by setting the
 *        hardware clear bit. It clears all pending channel interrupts at once;
 *        no per-channel/per-source argument is needed.
 */
void RAP_ClearINTPendingBit(void)
{
    RAP_CTRL_TypeDef rap_ctrl = {.d32 = RAP->RAP_CTRL};
    rap_ctrl.b.r_intr_clr = 1;
    RAP->RAP_CTRL = rap_ctrl.d32;

    return;
}

/**
 * @brief Enable or disable the core wakeup action for a specific channel.
 * @param Channel   Specifies the RAP channel to configure. Refer to @ref RAP_CHANNEL.
 * @param NewState  Enable or disable the core wakeup action for the channel.
 *                  - ENABLE : Allow this channel to wake up the core.
 *                  - DISABLE: Do not wake up the core on this channel.
 */
void RAP_ActionWakeUpCoreCmd(uint8_t Channel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        RAP->DLPS_CH_EN |= BIT(Channel);
    }
    else
    {
        RAP->DLPS_CH_EN &= ~BIT(Channel);
    }

    return;
}

/**
 * @brief Allocate a free RAP channel.
 * @note  Channels marked as reserved/pre-allocated (e.g. @ref RAP_CHANNEL10 and
 *        @ref RAP_CHANNEL11) are never returned by this function.
 * @param p_Channel  Pointer to a variable that receives the allocated channel
 *                   number on success. On failure it is set to 0xA5
 *                   ("allocating channel failed").
 * @return  The allocation result.
 *          - true   Allocation successful, *p_Channel holds a valid channel.
 *          - false  Allocation failed (all channels are currently in use).
 */
bool RAP_ChannelAllocate(uint8_t *p_Channel)
{
    *p_Channel = 0xA5; /* Error code 0xA5: "Allocating channel failed." */

    for (uint8_t channel = RAP_CHANNEL0; channel < RAP_CHANNEL_MAX; channel++)
    {
        if (!(rap_channel_allocated_mask & BIT(channel)))
        {
            /* Mark the channel as used and return it. */
            rap_channel_allocated_mask |= BIT(channel);
            *p_Channel = channel;
            break;
        }
    }

    return (*p_Channel == 0xA5 ? false : true);
}

/**
 * @brief Free a previously allocated RAP channel.
 * @param Channel  Specifies the RAP channel to free. Refer to @ref RAP_CHANNEL.
 */
void RAP_ChannelFree(uint8_t Channel)
{
    /* Check the parameters */
    assert_param(IS_RAP_CHANNEL(Channel));
    rap_channel_allocated_mask &= ~BIT(Channel);
}

/**
 * @brief Get the current mask of allocated RAP channels.
 * @return  A bitmask in which each set bit indicates that the corresponding
 *          channel is currently allocated (BIT(n) for channel n).
 */
uint32_t RAP_ChannelAllocatedMaskGet(void)
{
    return rap_channel_allocated_mask;
}

/**
 * @brief Route a peripheral Event (source) to a specific RAP channel.
 * @param Event    Specifies the peripheral event. This is a register offset
 *                 macro relative to the RAP base address. Refer to @ref RAP_ACTION_EVENT.
 * @param Channel  Specifies the RAP channel to bind the event to.
 *                 Refer to @ref RAP_CHANNEL.
 */
void RAP_EventRouteSet(uint32_t Event, uint8_t Channel)
{
    /* Check the parameters */
    assert_param(IS_RAP_CHANNEL(Channel));

    *((volatile uint32_t *)((uint8_t *)RAP + Event)) |= BIT(Channel);
}

/**
 * @brief Clear the routing of a peripheral Event from a specific RAP channel.
 * @param Event    Specifies the peripheral event. Refer to @ref RAP_ACTION_EVENT.
 * @param Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 */
void RAP_EventRouteClear(uint32_t Event, uint8_t Channel)
{
    /* Check the parameters */
    assert_param(IS_RAP_CHANNEL(Channel));

    *((volatile uint32_t *)((uint8_t *)RAP + Event)) &= ~BIT(Channel);
}

/**
 * @brief Bind a peripheral Action to a specific RAP channel.
 * @param Action   Specifies the action to be triggered. This is a register
 *                 offset macro relative to the RAP base address. Refer to @ref RAP_ACTION_EVENT.
 * @param Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 */
void RAP_ActionBindSet(uint32_t Action, uint8_t Channel)
{
    /* Check the parameters */
    assert_param(IS_RAP_CHANNEL(Channel));

    *((volatile uint32_t *)((uint8_t *)RAP + Action)) |= BIT(Channel);
}

/**
 * @brief Clear the binding of a peripheral Action from a specific RAP channel.
 * @param Action   Specifies the action (register offset macro). Refer to @ref RAP_ACTION_EVENT.
 * @param Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 */
void RAP_ActionBindClear(uint32_t Action, uint8_t Channel)
{
    /* Check the parameters */
    assert_param(IS_RAP_CHANNEL(Channel));

    *((volatile uint32_t *)((uint8_t *)RAP + Action)) &= ~BIT(Channel);
}

/**
 * @brief Get the channel bitmask bound to a specific Action or Event.
 * @param ActionEvent  Specifies the Action or Event offset macro. Refer to @ref RAP_ACTION_EVENT.
 * @return  A bitmask in which each set bit indicates a channel bound to the
 *          specified Action/Event (BIT(n) for channel n).
 */
uint32_t RAP_ActionEventChannelGet(uint32_t ActionEvent)
{
    return (*((volatile uint32_t *)((uint8_t *)RAP + ActionEvent)));
}
