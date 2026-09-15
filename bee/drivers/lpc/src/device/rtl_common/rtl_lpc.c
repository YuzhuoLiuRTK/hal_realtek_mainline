/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lpc.h"
#include "rtl_rcc.h"
#include "utils.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define LPC_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define LPC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F)//Force off 0x0A

/*============================================================================*
 *                           Private Functions
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Reset LPC.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \return None
  */
void LPC_DeInit(LPC_TypeDef *LPCx)
{
    LPC_CR0_TypeDef lpc_reg_0x04 = {.d32 = LPCx->LPC_CR0};
    lpc_reg_0x04.b.reg_lpcomp_src_aon_int_en = 0;
    lpc_reg_0x04.b.reg_lpcomp_src_int_en = 0;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;

    LPC_REG0X_SD_TypeDef lpc_reg_0x20 = {.d32 = LPCx->LPC_REG0X_SD};
    lpc_reg_0x20.b.pow_sd_h = 0;
    LPCx->LPC_REG0X_SD = lpc_reg_0x20.d32;

    platform_delay_us(1);

    lpc_reg_0x04.b.lpc_rst = 0x1;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;
    __NOP();
    __NOP();
    lpc_reg_0x04.b.lpc_rst = 0x0;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;
}

/**
  * \brief  Initializes LPC peripheral according to the specified parameters in the LPC_InitStruct.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  LPC_InitStruct: pointer to a LPC_InitTypeDef structure that contains the configuration information for the specified LPC peripheral.
  * \return None
  */
void LPC_Init(LPC_TypeDef *LPCx, LPC_InitTypeDef *LPC_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_LPC_CHANNEL(LPC_InitStruct->LPC_Channel));
    assert_param(IS_LPC_EDGE(LPC_InitStruct->LPC_Edge));
    assert_param(IS_LPC_THRESHOLD(LPC_InitStruct->LPC_Threshold));

    /* Set threshold votage */
    uint32_t threshold_value = 0;

    threshold_value = (LPC_InitStruct->LPC_Mode == LPC_BYPASS_MODE) ?
                      (LPC_InitStruct->LPC_BypassThreshold) : (LPC_InitStruct->LPC_Threshold);
    LPC_REF &= ~((uint32_t)0x3f << 26);
    LPC_REF |= threshold_value << 26;

#if (LPC_SUPPORT_VOLTAGE_DETECT_L == 1 || (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1))
    uint32_t threshold_l_value = (LPC_InitStruct->LPC_Mode == LPC_BYPASS_MODE) ?
                                 (LPC_InitStruct->LPC_BypassThresholdL) : (LPC_InitStruct->LPC_ThresholdL);
    LPC_REF &= ~((uint32_t)0x3f << 20);
    LPC_REF |= threshold_l_value << 20;
#endif

    /* Delay 10us after setting threshold */
    platform_delay_us(10);

    /* Configure LPC and Enable LPC */
    LPC_REG0X_SD_TypeDef lpc_reg_0x20 = {.d32 = LPCx->LPC_REG0X_SD};

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
    if (LPC_InitStruct->LPC_Mode == LPC_BYPASS_MODE)
    {
        LPC_InitStruct->LPC_Channel &= 0x7;
    }
    lpc_reg_0x20.b.en_byp = LPC_InitStruct->LPC_Mode;
#endif

#if (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1)
    lpc_reg_0x20.b.en_hys = LPC_InitStruct->LPC_HysteresisEn;
#endif

    lpc_reg_0x20.b.ch_num_h = LPC_InitStruct->LPC_Channel;
    lpc_reg_0x20.b.sd_posedge_h = LPC_InitStruct->LPC_Edge;
    lpc_reg_0x20.b.pow_sd_h = 1;

    LPCx->LPC_REG0X_SD = lpc_reg_0x20.d32;

    /* Delay 200us after configuring LPC */
    platform_delay_us(200);
}

/**
  * \brief  Fills each LPC_InitStruct member with its default value.
  * \param  LPC_InitStruct : pointer to a LPC_InitTypeDef structure which will be initialized.
  * \return None
  */
void LPC_StructInit(LPC_InitTypeDef *LPC_InitStruct)
{
    LPC_InitStruct->LPC_Channel           = LPC_CHANNEL_ADC0;
    LPC_InitStruct->LPC_Edge              = LPC_VIN_BELOW_VTH;
    LPC_InitStruct->LPC_Threshold         = LPC_480_mV;
    LPC_InitStruct->LPC_BypassThreshold   = LPC_BYPASS_450_mV;
#if (LPC_SUPPORT_VOLTAGE_DETECT_L == 1 || (LPC_SUPPORT_HYSTERESIS_FUNCTION == 1))
    LPC_InitStruct->LPC_ThresholdL        = LPC_300_mV;
    LPC_InitStruct->LPC_BypassThresholdL  = LPC_BYPASS_150_mV;
    LPC_InitStruct->LPC_HysteresisEn      = DISABLE;
#endif

#if (LPC_SUPPORT_BYPASS_DIVIDE_MODE == 1)
    LPC_InitStruct->LPC_Mode              = LPC_DIVIDE_MODE;
#endif

#if LPC_SUPPORT_TRIGGER_MODE
    LPC_InitStruct->LPC_TriggerMode        = LPC_SINGLE_OUTPUT;
#endif
}

/**
  * \brief  Enables or disables LPC voltage detect function.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  NewState: new state of LPC peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPC_Cmd(LPC_TypeDef *LPCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPC_CR0_TypeDef lpc_reg_0x04 = {.d32 = LPCx->LPC_CR0};
    lpc_reg_0x04.b.reg_lpcomp_output_en = NewState;
    lpc_reg_0x04.b.reg_lpcomp_ie = 0;
    LPCx->LPC_CR0 =  lpc_reg_0x04.d32;
}

/**
  * \brief  Enables or disables the specified LPC interrupts.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  NewState: new state of the specified LPC interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None
  */
void LPC_INTConfig(LPC_TypeDef *LPCx, uint32_t LPC_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        LPCx->LPC_CR0 |= LPC_INT_LPCOMP;
    }
    else
    {
        LPCx->LPC_CR0 &= ~LPC_INT_LPCOMP;
    }
}

/**
  * \brief  Enable wakeup signal to power sequence.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void LPC_WakeUpConfig(LPC_TypeDef *LPCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        LPCx->LPC_CR0 |= LPC_INT_LPCOMP_AON;
    }
    else
    {
        LPCx->LPC_CR0 &= ~LPC_INT_LPCOMP_AON;
    }
}

/**
  * \brief  Clear the specified LPC interrupt.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  LPC_INT: specifies the LPC interrupt to clear.
  *         This parameter can be one of the following values:
  *         \arg LPC_INT_COUNTER_COMPARE: counter compare interrupt.
  * \return None
  */
void LPC_ClearINTStatus(LPC_TypeDef *LPCx, uint32_t LPC_INT)
{
    /* Check the parameters */
    assert_param(IS_LPC_INTERRUPT(LPC_INT));

    LPCx->LPC_CR0 |= BIT2;
    platform_delay_us(200);
}

/**
  * \brief  Checks whether the specified LPC interrupt is set or not.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  LPC_INT: specifies the LPC interrupt to check.
  *         This parameter can be one of the following values:
  *         \arg LPC_INT_VOLTAGE_DETECT: voltage detection interrupt.
  *         \arg LPC_INT_COUNTER_COMPARE: counter compare interrupt.
  * \return The new state of LPC_INT (SET or RESET).
  */
ITStatus LPC_GetINTStatus(LPC_TypeDef *LPCx, uint32_t LPC_INT)
{
    /* Check the parameters */
    assert_param(IS_LPC_INTERRUPT(LPC_INT));

    if (((LPCx->LPC_SR) & BIT0) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

/**
  * \brief  Checks whether the specified LPC wakeup is set or not.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \return The new state of LPC_WAKEUP (SET or RESET).
  */
ITStatus LPC_GetWakeUpStatus(LPC_TypeDef *LPCx)
{
    if (((LPCx->LPC_SR) & BIT1) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

/**
  * \brief  Configure LPC trigger edge.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  LPC_Edge: Specifies the LPC trigger edge.
  *         This parameter can be one of the following values:
  *         \arg LPC_VIN_BELOW_VTH: The input voltage is below the threshold voltage.
  *         \arg LPC_VIN_OVER_VTH: The input voltage is above the threshold voltage.
  * \return None
  */
void LPC_SetTriggerEdge(LPC_TypeDef *LPCx, LPCEdge_TypeDef LPC_Edge)
{
    /* Check the parameters */
    assert_param(IS_LPC_EDGE(LPC_Edge));

    LPC_REG0X_SD_TypeDef lpc_reg_0x20 = {.d32 = LPCx->LPC_REG0X_SD};
    lpc_reg_0x20.b.sd_posedge_h = LPC_Edge;
    LPCx->LPC_REG0X_SD = lpc_reg_0x20.d32;
}

#if (LPC_SUPPORT_COMP_CNT == 1)
/**
  * \brief  Start or stop the LPC counter.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  NewState: new state of the LPC counter.
  *         This parameter can be one of the following values:
  *         \arg ENABLE: Start LPCOMP counter.
  *         \arg DISABLE: Stop LPCOMP counter.
  * \return  None
  */
void LPC_CounterCmd(LPC_TypeDef *LPCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPC_CR0_TypeDef lpc_reg_0x04 = {.d32 = LPCx->LPC_CR0};
    lpc_reg_0x04.b.reg_lpcomp_ie = NewState;
    lpc_reg_0x04.b.reg_lpcomp_counter_start = NewState;
    lpc_reg_0x04.b.reg_lpcomp_output_en = 0;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;
}

/**
  * \brief Reset the LPC counter.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  */
void LPC_CounterReset(LPC_TypeDef *LPCx)
{
    /* Reset the LPCOMP counter */
    LPC_CR0_TypeDef lpc_reg_0x04 = {.d32 = LPCx->LPC_CR0};
    lpc_reg_0x04.b.reg_lpcomp_counter_rst = 1;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;
    lpc_reg_0x04.b.reg_lpcomp_counter_rst = 0;
    LPCx->LPC_CR0 = lpc_reg_0x04.d32;
}

/**
  * \brief  Configure LPCOMP counter's comparator value.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \param  data: LPCOMP counter's comparator value which can be 0 to 0xfff.
  * \retval None.
  */
void LPC_SetComparator(LPC_TypeDef *LPCx, uint32_t data)
{
    LPCx->LPC_CMP = (data & 0xfff) ;
}

/**
  * \brief  read LPCOMP comparator value.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  * \retval LPCOMP comparator value.
  */
uint16_t LPC_GetComparator(LPC_TypeDef *LPCx)
{
    return ((LPCx->LPC_CMP) & 0xfff);
}

/**
  * \brief  Read LPC counter value.
  * \param  LPCx: Select the LPC peripheral. \ref LPC_Declaration
  */
uint16_t LPC_GetCounter(LPC_TypeDef *LPCx)
{
    return (LPCx->LPC_CNT & 0xfff);
}
#endif


#if (LPC_SUPPORT_RAP_MODE == 1)

void LPC_RAPModeCmd(LPC_TypeDef *LPCx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPC_TASK_CTRL_TypeDef lpc_reg_0x14 = {.d32 = LPCx->LPC_TASK_CTRL};
    lpc_reg_0x14.b.lpc_rap_mode = NewState;
    LPCx->LPC_TASK_CTRL = lpc_reg_0x14.d32;

    return;
}

void LPC_ActionTrigger(LPC_TypeDef *LPCx, LPCAction_TypeDef LPC_Action)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPC_TASK_CTRL_TypeDef lpc_reg_0x14 = {.d32 = LPCx->LPC_TASK_CTRL};
    if (LPC_Action == LPC_ACTION_START)
    {
        lpc_reg_0x14.b.lpc_fw_task_start = 0x1;
    }
    else if (LPC_Action == LPC_ACTION_STOP)
    {
        lpc_reg_0x14.b.lpc_fw_task_stop = 0x1;
    }
    LPCx->LPC_TASK_CTRL = lpc_reg_0x14.d32;

    return;
}

void LPC_ShortcutCmd(LPC_TypeDef *LPCx, uint32_t Action, uint32_t Event, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    LPC_SHOT_CTRL_TypeDef lpc_reg_0x18 = {.d32 = LPCx->LPC_SHOT_CTRL};
    if (Action == LPC_ACTION_STOP)
    {
        lpc_reg_0x18.b.lpc_task_stop_sub_en =  NewState;
    }
    else
    {
        /* LPC_ACTION_START is not supported */
        return;
    }
    if (Event == LPC_EVENT_STATUS)
    {
        lpc_reg_0x18.b.lpc_event_status_pub_en = NewState;
    }
    LPCx->LPC_SHOT_CTRL = lpc_reg_0x18.d32;

    return;
}
#endif

#if (LPC_SUPPORT_AUTO_CLOCK == 1)

void LPC_ClockAutoModeCmd(LPC_TypeDef *LPCx, FunctionalState Newstate)
{
    /* Check the parameters */
    assert_param(IS_LPC_PERIPH(LPCx));

    if (Newstate == ENABLE)
    {
        LPCx->LPC_QACTIVE_CTRL = LPC_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        LPCx->LPC_QACTIVE_CTRL = LPC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}
#endif



