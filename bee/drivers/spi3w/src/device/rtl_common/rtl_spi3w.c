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
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitialize the SPI3W peripheral registers to their default reset values.
 */
void SPI3W_DeInit(void)
{
    RCC_ClockCmd(SPI3W_CLOCK, DISABLE);
}

/**
 * @brief Initialize the SPI3W peripheral according to the specified parameters in SPI3W_InitStruct.
 *
 * @param[in] SPI3W_InitStruct  Pointer to a SPI3W_InitTypeDef structure which will be initialized.
 */
void SPI3W_Init(SPI3W_InitTypeDef *SPI3W_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_MODE(SPI3W_InitStruct->SPI3W_Mode));
    assert_param(IS_SPI3W_OE_DELAY_CFG(SPI3W_InitStruct->SPI3W_OutputDelay));
    assert_param(IS_SPI3W_END_EXTEND_MODE(SPI3W_InitStruct->SPI3W_ExtMode));
    assert_param(IS_SPI3W_READ_CYCLE_DELAY(SPI3W_InitStruct->SPI3W_ReadDelay));

    uint32_t divValue = 0;

    divValue = (((SPI3W_InitStruct->SPI3W_SysClock) / (SPI3W_InitStruct->SPI3W_Speed * 2) - 1)) & 0xFF;

    /* Initialize the parameters */
    SPI3W_CONFIG_TypeDef spi3w_0x30 = {.d32 = SPI3W->SPI3W_CONFIG};
    spi3w_0x30.b.spi3w_cs_en = SPI3W_InitStruct->SPI3W_Mode;
    spi3w_0x30.b.spi3w_oe_dly_en = SPI3W_InitStruct->SPI3W_OutputDelay;
    spi3w_0x30.b.spi3w_end_ext_en = SPI3W_InitStruct->SPI3W_ExtMode;
    spi3w_0x30.b.spi3w_div_num = divValue;
    spi3w_0x30.b.spi3w_dly_cycle = SPI3W_InitStruct->SPI3W_ReadDelay;
    spi3w_0x30.b.spi3w_burst_read_num = 0;
    SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

    /* Clear all read data registers,  read number and interrupt */
    SPI3W->SPI3W_CLR |= 0x7;
}

/**
 * @brief Fills each SPI3W_InitStruct member with its default value.
 *
 * @param[in] SPI3W_InitStruct  Pointer to a SPI3W_InitTypeDef structure which will be initialized.
 */
void SPI3W_StructInit(SPI3W_InitTypeDef *SPI3W_InitStruct)
{
    SPI3W_InitStruct->SPI3W_SysClock      = 20000000;
    SPI3W_InitStruct->SPI3W_Speed         = 1000000;
    SPI3W_InitStruct->SPI3W_Mode          = SPI3W_2WIRE_MODE;
    SPI3W_InitStruct->SPI3W_ReadDelay     = 0; /* Delay time = (SPI3W_ReadDelay+1)/(2*SPI3W_Speed) */
    SPI3W_InitStruct->SPI3W_OutputDelay   = SPI3W_OE_DELAY_1T;
    SPI3W_InitStruct->SPI3W_ExtMode       = SPI3W_NORMAL_MODE;
}

/**
 * @brief Enable or disable the specified SPI3W peripheral.
 *
 * @param[in] NewState  New state of the SPI3W peripheral.
 *                      - ENABLE: Enable the SPI3W peripheral.
 *                      - DISABLE: Disable the SPI3W peripheral.
 */
void SPI3W_Cmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI3W_CONFIG_TypeDef spi3w_0x30 = {.d32 = SPI3W->SPI3W_CONFIG};
    if (NewState != DISABLE)
    {
        /* Enable the selected SPI3W peripheral */
        spi3w_0x30.b.spi3w_en = 1;
    }
    else
    {
        /* Disable the selected SPI3W peripheral */
        spi3w_0x30.b.spi3w_en = 0;
    }
    SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

    return;
}

/**
 * @brief Enable or disable the specified SPI3W interrupts.
 *
 * @param[in] SPI3W_INT  Specify the SPI3W interrupt to be enabled or disabled, refer to @ref SPI3W_INTERRUPT_DEFINITION.
 *                       This parameter can only be the following value:
 *                       - SPI3W_INT_BIT: SPI3W interrupt.
 * @param[in] newState   New state of the specified SPI3W interrupts.
 *                       - ENABLE: Enable the specified SPI3W interrupt.
 *                       - DISABLE: Disable the specified SPI3W interrupt.
 */
void SPI3W_INTConfig(uint32_t SPI3W_INT, FunctionalState newState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(newState));
    assert_param(IS_SPI3W_INT(SPI3W_INT));

    if (newState == ENABLE)
    {
        /* Enable the selected SPI_3W interrupts */
        SPI3W->SPI3W_CONFIG |= SPI3W_INT;
    }
    else
    {
        /* Disable the selected SPI_3W interrupts */
        SPI3W->SPI3W_CONFIG &= (uint32_t)(~SPI3W_INT);
    }
}

/**
 * @brief Configure resync signal time value.
 *
 * @param[in] value  Resync signal time value whose unit is 1/(2*SPI3W_Speed).
 *                   This parameter can only be a value of 0x0 ~ 0xf.
 */
void SPI3W_SetResyncTime(uint32_t value)
{
    SPI3W_CONFIG_TypeDef spi3w_0x30 = {.d32 = SPI3W->SPI3W_CONFIG};
    spi3w_0x30.b.spi3w_resync_timer = value & 0xF;
    SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

    return;
}

/**
 * @brief Enable or disable sending the resync signal. Must send when SPI3W is disable.
 *
 * @param[in] NewState  New state of the SPI3W peripheral.
 *                      This parameter can only be the following value:
 *                      - ENABLE: Trigger resync signal.
 *                      - DISABLE: Disable resync signal.
 */
void SPI3W_ResyncSignalCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    SPI3W_CLR_TypeDef spi3w_0x38 = {.d32 = SPI3W->SPI3W_CLR};

    if (NewState != DISABLE)
    {
        spi3w_0x38.b.spi3w_resync_en = 1;
    }
    else
    {
        spi3w_0x38.b.spi3w_resync_en = 0;
    }
    SPI3W->SPI3W_CLR = spi3w_0x38.d32;
}

/**
 * @brief Get total number of data byte.
 *
 * @return The total number of data byte.
 */
uint8_t SPI3W_GetRxDataLen(void)
{
    return (uint8_t)(SPI3W->SPI3W_STS & 0xF);
}

/**
 * @brief Clear read data number status.
 */
void SPI3W_ClearRxDataLen(void)
{
    SPI3W_CLR_TypeDef spi3w_0x38 = {.d32 = SPI3W->SPI3W_CLR};
    spi3w_0x38.b.spi3w_rd_num_clr = 1;
    SPI3W->SPI3W_CLR = spi3w_0x38.d32;
}

/**
 * @brief Clear all read data registers.
 */
void SPI3W_ClearRxFIFO(void)
{
    SPI3W_CLR_TypeDef spi3w_0x38 = {.d32 = SPI3W->SPI3W_CLR};
    spi3w_0x38.b.spi3w_rd_data_clr = 1;
    SPI3W->SPI3W_CLR = spi3w_0x38.d32;
}

/**
 * @brief Write a data.
 *
 * @param[in] address  Write address.
 * @param[in] data     Write data.
 */
void SPI3W_StartWrite(uint8_t address, uint8_t data)
{
    SPI3W_WDATA_TypeDef spi3w_0x34 = {.d32 = 0};
    spi3w_0x34.b.spi3w_data_mode = 1;
    spi3w_0x34.b.spi3w_data_addr = address & 0x7F;
    spi3w_0x34.b.spi3w_data_data = data & 0xFF;
    SPI3W->SPI3W_WDATA = spi3w_0x34.d32;
}

/**
 * @brief Start reading data.
 *
 * @param[in] address  Read address.
 * @param[in] len      Number of data to read. This value can be 0x1 to 0xf.
 */
void SPI3W_StartRead(uint8_t address, uint32_t len)
{
    SPI3W_CONFIG_TypeDef spi3w_0x30 = {.d32 = SPI3W->SPI3W_CONFIG};
    SPI3W_WDATA_TypeDef spi3w_0x34 = {.d32 = 0};
    if (len == 1)
    {
        /* Disable burst read */
        spi3w_0x30.b.spi3w_burst_read_en = 0;
        SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

        /* Read address */
        spi3w_0x34.b.spi3w_data_addr = address;
        SPI3W->SPI3W_WDATA = spi3w_0x34.d32;
    }
    else
    {
        /* Enable burst read */
        spi3w_0x30.b.spi3w_burst_read_en = 1;
        SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

        /* Read num */
        spi3w_0x30.b.spi3w_burst_read_num = 0;
        SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;
        spi3w_0x30.b.spi3w_burst_read_num = len;
        SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

        /* Set read command and read address */
        spi3w_0x34.b.spi3w_data_addr = address;
        SPI3W->SPI3W_WDATA = spi3w_0x34.d32;
    }
}

/**
 * @brief Read data.
 *
 * @param[out] pBuf    Buffer to store read data.
 * @param[in] readNum  Read number.
 */
void SPI3W_ReadBuf(uint8_t *pBuf, uint8_t readNum)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint32_t regVal = 0;
    uint8_t regIndex =  readNum / 4;

    for (i = 0; i < regIndex; i++)
    {
        regVal = *((volatile uint32_t *)(&(SPI3W->SPI3W_RDATA0) + i));

        for (j = 0; j < 4; j++)
        {
            *pBuf++ = (uint8_t)(regVal >> (8 * j));
        }
    }

    if (readNum > regIndex * 4)
    {
        regVal = *((volatile uint32_t *)(&(SPI3W->SPI3W_RDATA0) + regIndex));

        for (j = 0; j < (readNum - regIndex * 4); j++)
        {
            *pBuf++ = (uint8_t)(regVal >> (8 * j));
        }
    }
}

/**
 * @brief Get the specified SPI3W flag status.
 *
 * @param[in] SPI3W_FLAG  Specify flags to check.
 *                        This parameter can be one of the following values, refer to @ref SPI3W_FLAG.
 *                        - SPI3W_FLAG_BUSY: SPI3W busy status.
 *                        - SPI3W_FLAG_INT_IND: SPI3W interrupt status.
 *                        - SPI3W_FLAG_RESYNC_BUSY: SPI3W resync busy status.
 *
 * @return The new state of the specified SPI3W flag.
 * @retval SET    The specified SPI3W flag state is pending.
 * @retval RESET  The specified SPI3W flag state is not pending.
 */
FlagStatus SPI3W_GetFlagStatus(uint32_t SPI3W_FLAG)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_FLAG(SPI3W_FLAG));

    FlagStatus bitstatus = RESET;

    if (SPI3W->SPI3W_STS & SPI3W_FLAG)
    {
        bitstatus = SET;
    }

    return bitstatus;
}

/**
 * @brief Clear the SPI3W interrupt pending bit.
 *
 * @param[in] SPI3W_INT  Specify the SPI3W interrupt, refer to @ref SPI3W_INTERRUPT_DEFINITION.
 *                       This parameter can only be the following value:
 *                       - SPI3W_INT_BIT: SPI3W interrupt.
 */
void SPI3W_ClearINTPendingBit(uint32_t SPI3W_INT)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_INT(SPI3W_INT));

    SPI3W->SPI3W_CLR |= SPI3W_INT;
}

#if (SPI3W_SUPPORT_RAP_FUNCTION ==1)

/**
 * @brief Start the quick burst read. This API can only be used in non-RAP mode.
 */
void SPI3W_QuickBurstStart()
{
    SPI3W_QB_START_TypeDef spi3w_0x80 = {.d32 = SPI3W->SPI3W_QB_START};
    spi3w_0x80.b.spi3w_qb_start = 1;
    SPI3W->SPI3W_QB_START = spi3w_0x80.d32;
}

/**
 * @brief Set quick burst pulse width.
 *
 * @param[in] pulse_width  Pulse width value.
 *                         The pulse width time is (1 / 2) * (1 / SPI3W_CLK_OUT) * (SPI3W_QB_PW + 1).
 */
void SPI3W_SetQuickBurstPulseWidth(uint8_t pulse_width)
{
    SPI3W_QB_PW_TypeDef spi3w_0x90 = {.d32 = SPI3W->SPI3W_QB_PW};
    spi3w_0x90.b.spi3w_qb_pw = pulse_width;
    SPI3W->SPI3W_QB_PW = spi3w_0x90.d32;
}

/**
 * @brief Set quick burst read length.
 *
 * @param[in] len       Read length.
 * @param[in] NewState  New state of the quick burst read function.
 *                      - ENABLE: Enable the quick burst read function.
 *                      - DISABLE: Disable the quick burst read function.
 */
void SPI3W_SetQuickBurstRead(uint32_t len, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI3W_CONFIG_TypeDef spi3w_0x30 = {.d32 = SPI3W->SPI3W_CONFIG};
    SPI3W_WDATA_TypeDef spi3w_0x34 = {.d32 = 0};

    spi3w_0x30.b.spi3w_burst_read_en = NewState;
    spi3w_0x30.b.spi3w_burst_read_num = len;
    SPI3W->SPI3W_CONFIG = spi3w_0x30.d32;

    spi3w_0x34.b.spi3w_data_mode = 0; // read mode
    SPI3W->SPI3W_WDATA = spi3w_0x34.d32;
}

/**
 * @brief Enable or disable the RAP mode.
 *
 * @param[in] NewState  New state of the RAP mode.
 *                      - ENABLE: Enable the RAP mode.
 *                      - DISABLE: Disable the RAP mode.
 */
void SPI3W_RAPModeCmd(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    SPI3W_RAP_MODE_TypeDef spi3w_0x100 = {.d32 = SPI3W->SPI3W_RAP_MODE};
    spi3w_0x100.b.spi3w_rap_mode = NewState;
    SPI3W->SPI3W_RAP_MODE = spi3w_0x100.d32;
}

/**
 * @brief Trigger the specified action.
 *
 * @param[in] Action  Action to trigger.
 *                    This parameter can be a value of @ref SPI3W_ACTION.
 */
void SPI3W_ActionTrigger(uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_SPI3W_ACTION(Action));

    SPI3W->SPI3W_TASKS_START |= BIT(Action);
}

#endif



