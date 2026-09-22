/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_keyscan.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern void KEYSCAN_FIFOConfig(KEYSCAN_TypeDef *KeyScan, uint32_t FIFOTriggerLevel,
                               uint32_t KeyLimit);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitializes the KEYSCAN peripheral registers to their default reset values.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 */
void KEYSCAN_DeInit(KEYSCAN_TypeDef *KEYSCANx)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    RCC_ClockCmd(KEYSCAN_CLOCK, DISABLE);
}

/**
 * @brief Initializes the KEYSCAN peripheral according to the specified
 *        parameters in the KEYSCAN_InitStruct.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_InitStruct Pointer to a KEYSCAN_InitTypeDef structure that
 *            contains the configuration information for the specified KEYSCAN peripheral.
 */
void KEYSCAN_Init(KEYSCAN_TypeDef *KEYSCANx, KEYSCAN_InitTypeDef *KEYSCAN_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_ROW_NUM(KEYSCAN_InitStruct->KEYSCAN_RowSize));
    assert_param(IS_KEYSCAN_COL_NUM(KEYSCAN_InitStruct->KEYSCAN_ColSize));
    assert_param(IS_FUNCTIONAL_STATE(KEYSCAN_InitStruct->KEYSCAN_DebounceEn));
    assert_param(IS_FUNCTIONAL_STATE(KEYSCAN_InitStruct->KEYSCAN_ScanTimerEn));
    assert_param(IS_FUNCTIONAL_STATE(KEYSCAN_InitStruct->KEYSCAN_DetectTimerEn));
    assert_param(IS_KEYSCAN_DETECT_MODE(KEYSCAN_InitStruct->KEYSCAN_DetectMode));
    assert_param(IS_KEYSCAN_FIFO_OVFL_CTRL(KEYSCAN_InitStruct->KEYSCAN_FIFOOvflCtrl));
    assert_param(IS_KEYSCAN_SCAN_MODE(KEYSCAN_InitStruct->KEYSCAN_ScanMode));
    assert_param(IS_KEYSCAN_KEY_LIMIT(KEYSCAN_InitStruct->KEYSCAN_KeyLimit));

    /* Mask all keyscan interrupt */
    KEYSCAN->KEYSCAN_INT_MASK |= 0x1f;

    /* Set FSM to idle state */
    KEYSCAN_CONFIG2_TypeDef keyscan_0x08 = {.d32 = KEYSCAN->KEYSCAN_CONFIG2};
    keyscan_0x08.b.keyscan_run_enable = 0;
    /* Auto scan mode should set manual_sel to 1(key trigger) */
    if (KEYSCAN_InitStruct->KEYSCAN_ScanMode == KEYSCAN_AUTO_SCAN_MODE)
    {
        keyscan_0x08.b.keyscan_manual_sel = KEYSCAN_MANUAL_SEL_KEY;
    }
    else
    {
        keyscan_0x08.b.keyscan_manual_sel = KEYSCAN_InitStruct->KEYSCAN_ManualSel;
    }

    KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;

    /* Clock divider config */
    KEYSCAN_CLK_DIV_TypeDef keyscan_0x00 = {.d32 = KEYSCAN->KEYSCAN_CLK_DIV};
    keyscan_0x00.b.keyscan_clk_div = KEYSCAN_InitStruct->KEYSCAN_ClockDiv;
    keyscan_0x00.b.keyscan_delay_div = KEYSCAN_InitStruct->KEYSCAN_ClockDelayDiv;
    /* preguard time and postguard time config */
    keyscan_0x00.b.keyscan_gt_pre_sel = KEYSCAN_InitStruct->KEYSCAN_PreGuardCnt;
    keyscan_0x00.b.keyscan_gt_post_sel = KEYSCAN_InitStruct->KEYSCAN_PostGuardCnt;
    KEYSCAN->KEYSCAN_CLK_DIV = keyscan_0x00.d32;

    /* Config scan mode and detect mode*/
    keyscan_0x08.b.keyscan_work_mode = KEYSCAN_InitStruct->KEYSCAN_ScanMode;
    keyscan_0x08.b.keyscan_trig_sel = KEYSCAN_InitStruct->KEYSCAN_DetectMode;
    keyscan_0x08.b.keyscan_fifo_ov_ctrl = KEYSCAN_InitStruct->KEYSCAN_FIFOOvflCtrl;
    KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;

    /* Config fifo threshold and key limit */
    KEYSCAN_FIFOConfig(KEYSCAN,
                       KEYSCAN_InitStruct->KEYSCAN_FIFOTriggerLevel,
                       KEYSCAN_InitStruct->KEYSCAN_KeyLimit);
    /* Time config */
    KEYSCAN_CONFIG1_TypeDef keyscan_0x04 = {.d32 = KEYSCAN->KEYSCAN_CONFIG1};
    keyscan_0x04.b.keyscan_deb_timer_en = KEYSCAN_InitStruct->KEYSCAN_DebounceEn;
    keyscan_0x04.b.keyscan_interval_timer_en = KEYSCAN_InitStruct->KEYSCAN_ScanTimerEn;
    keyscan_0x04.b.keyscan_release_timer_en = KEYSCAN_InitStruct->KEYSCAN_DetectTimerEn;
    /* Time count config */
    keyscan_0x04.b.keyscan_deb_timer_cnt = KEYSCAN_InitStruct->KEYSCAN_DebounceCnt;
    keyscan_0x04.b.keyscan_interval_timer_cnt = KEYSCAN_InitStruct->KEYSCAN_ScanInterval;
    keyscan_0x04.b.keyscan_release_timer_cnt = KEYSCAN_InitStruct->KEYSCAN_ReleaseCnt;
#if KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE
    keyscan_0x04.b.keyscan_pull_high_en = KEYSCAN_InitStruct->KEYSCAN_RowPullHighEn;
#endif
#if KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE
    keyscan_0x04.b.keyscan_column_output_high_en = KEYSCAN_InitStruct->KEYSCAN_ColunmOutputHighEn;
#endif
    KEYSCAN->KEYSCAN_CONFIG1 = keyscan_0x04.d32;

    /* Set column map, config which column to work */
    KEYSCAN_COLUMN_CONFIG_TypeDef keyscan_0x0c = {.d32 = KEYSCAN->KEYSCAN_COLUMN_CONFIG};
    keyscan_0x0c.b.keyscan_col_num = KEYSCAN_InitStruct->KEYSCAN_ColSize - 1;
    keyscan_0x0c.b.keyscan_col_sel = (1 << KEYSCAN_InitStruct->KEYSCAN_ColSize) - 1;
    KEYSCAN->KEYSCAN_COLUMN_CONFIG = keyscan_0x0c.d32;

    /* Set row map, config which col row work */
    KEYSCAN_ROW_CONFIG_TypeDef keyscan_0x10 = {.d32 = KEYSCAN->KEYSCAN_ROW_CONFIG};
    keyscan_0x10.b.keyscan_row_num = KEYSCAN_InitStruct->KEYSCAN_RowSize - 1;
    keyscan_0x10.b.keyscan_row_sel = (1 << KEYSCAN_InitStruct->KEYSCAN_RowSize) - 1;
    KEYSCAN->KEYSCAN_ROW_CONFIG = keyscan_0x10.d32;

    /* Clear all interrupt status and status flag */
    KEYSCAN->KEYSCAN_INT_CLR |= 0x1ff;
    /* Unmask all keyscan interrupt */
    KEYSCAN->KEYSCAN_INT_MASK &= ~0x1f;

    return;
}

/**
 * @brief Fills each KEYSCAN_InitStruct member with its default value.
 *
 * @param[in] KEYSCAN_InitStruct Pointer to a KEYSCAN_InitTypeDef structure which will be initialized.
 */
void KEYSCAN_StructInit(KEYSCAN_InitTypeDef *KEYSCAN_InitStruct)
{
    KEYSCAN_InitStruct->KEYSCAN_ColSize       = 2;
    KEYSCAN_InitStruct->KEYSCAN_RowSize       = 2;

    KEYSCAN_InitStruct->KEYSCAN_ClockDiv      = 0x1f8;
    KEYSCAN_InitStruct->KEYSCAN_ClockDelayDiv = 0x01;

    KEYSCAN_InitStruct->KEYSCAN_DebounceEn    = ENABLE;
    KEYSCAN_InitStruct->KEYSCAN_ScanTimerEn   = ENABLE;
    KEYSCAN_InitStruct->KEYSCAN_DetectTimerEn = ENABLE;

    KEYSCAN_InitStruct->KEYSCAN_DebounceCnt   = 0x10;
    KEYSCAN_InitStruct->KEYSCAN_ScanInterval  = 0x10;
    KEYSCAN_InitStruct->KEYSCAN_ReleaseCnt    = 0x1;

    KEYSCAN_InitStruct->KEYSCAN_ScanMode      = KEYSCAN_AUTO_SCAN_MODE;
    KEYSCAN_InitStruct->KEYSCAN_DetectMode    = KEYSCAN_DETECT_MODE_EDGE;
    KEYSCAN_InitStruct->KEYSCAN_ManualSel     = KEYSCAN_MANUAL_SEL_KEY;

    KEYSCAN_InitStruct->KEYSCAN_FIFOTriggerLevel = 1;
    KEYSCAN_InitStruct->KEYSCAN_FIFOOvflCtrl     = KEYSCAN_FIFO_OVFL_CTRL_DIS_OLDEST;
    KEYSCAN_InitStruct->KEYSCAN_KeyLimit         = 0x03;

    KEYSCAN_InitStruct->KEYSCAN_PreGuardCnt    = 3;
    KEYSCAN_InitStruct->KEYSCAN_PostGuardCnt   = 3;

#if KEYSCAN_SUPPORT_ROW_LEVEL_CONFIGURE
    KEYSCAN_InitStruct->KEYSCAN_RowPullHighEn      = ENABLE;
#endif
#if KEYSCAN_SUPPORT_COLUNM_LEVEL_CONFIGURE
    KEYSCAN_InitStruct->KEYSCAN_ColunmOutputHighEn = DISABLE;
#endif
    return;
}

/**
 * @brief Enables or disables the specified KEYSCAN interrupt.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * @param[in] NewState New state of the specified KEYSCAN interrupts.
 *            - ENABLE: Enable the specified KEYSCAN interrupts.
 *            - DISABLE: Disable the specified KEYSCAN interrupts.
 */
void KEYSCAN_INTConfig(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    assert_param(IS_KEYSCAN_CONFIG_INT(KEYSCAN_INT));

    if (NewState == ENABLE)
    {
        /* Enable the selected KEYSCAN interrupts */
        KEYSCAN->KEYSCAN_CONFIG2 |= KEYSCAN_INT;
    }
    else
    {
        /* Disable the selected KEYSCAN interrupts */
        KEYSCAN->KEYSCAN_CONFIG2 &= (uint32_t)~KEYSCAN_INT;
    }
}

/**
 * @brief Mask the specified KEYSCAN interrupt.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the KEYSCAN interrupts sources to be enabled or disabled.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 * @param[in] NewState New state of the specified KEYSCAN interrupts mask.
 *            - ENABLE: Mask the specified KEYSCAN interrupts.
 *            - DISABLE: Unmask the specified KEYSCAN interrupts.
 */
void KEYSCAN_INTMask(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        /* Mask KEYSCAN interrupts */
        KEYSCAN->KEYSCAN_INT_MASK |= KEYSCAN_INT;
    }
    else
    {
        /* Enable KEYSCAN interrupts */
        KEYSCAN->KEYSCAN_INT_MASK &= (~KEYSCAN_INT);
    }
}

/**
 * @brief Read data from KEYSCAN FIFO.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[out] outBuf Buffer to save data read from KEYSCAN FIFO.
 * @param[in] count Data length to be read.
 */
void KEYSCAN_Read(KEYSCAN_TypeDef *KEYSCANx, uint16_t *outBuf, uint16_t count)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    for (uint16_t i = 0; i < count; i++)
    {
        *outBuf++ = (uint16_t)KEYSCAN->KEYSCAN_FIFO_ENTRY;
    }

    return;
}

/**
 * @brief Enable or disable the KEYSCAN peripheral.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] NewState New state of the KEYSCAN peripheral.
 *            - ENABLE: Enable the KEYSCAN peripheral.
 *            - DISABLE: Disable the KEYSCAN peripheral.
 */
void KEYSCAN_Cmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    KEYSCAN_CONFIG2_TypeDef keyscan_0x08 = {.d32 = KEYSCAN->KEYSCAN_CONFIG2};
    keyscan_0x08.b.keyscan_run_enable = NewState;
    keyscan_0x08.b.keyscan_manual_trigger = NewState &&
                                            (!keyscan_0x08.b.keyscan_work_mode) &&
                                            (!keyscan_0x08.b.keyscan_manual_sel);
    KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;
}

/**
 * @brief Set filter data.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] data Config the data to be filtered.
 *            This parameter should not be more than 9 bits.
 * @param[in] NewState New state of the data filter.
 *            - ENABLE: Enable the data filter.
 *            - DISABLE: Disable the data filter.
 */
void KEYSCAN_FilterDataConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t data, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == ENABLE)
    {
        KEYSCAN_CONFIG2_TypeDef keyscan_0x08 = {.d32 = KEYSCAN->KEYSCAN_CONFIG2};
        keyscan_0x08.b.keyscan_fifo_data_filter_en = 0;
        KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;

        keyscan_0x08.b.keyscan_fifo_filter_data = data;
        keyscan_0x08.b.keyscan_fifo_data_filter_en = 1;
        KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;
    }
    else
    {
        KEYSCAN_CONFIG2_TypeDef keyscan_0x08 = {.d32 = KEYSCAN->KEYSCAN_CONFIG2};
        keyscan_0x08.b.keyscan_fifo_data_filter_en = 0;
        KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;
    }

    return;
}

/**
 * @brief KEYSCAN debounce time config.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] time KEYSCAN hardware debounce time.
 *            Debounce time = delay clock * time.
 *            This parameter can be a value of 0 to 0x1FF.
 * @param[in] NewState New state of the KEYSCAN debounce function.
 *            - ENABLE: Enable the KEYSCAN debounce function.
 *            - DISABLE: Disable the KEYSCAN debounce function.
 */
void KEYSCAN_DebounceConfig(KEYSCAN_TypeDef *KEYSCANx, uint16_t time,
                            FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    KEYSCAN_CONFIG1_TypeDef keyscan_0x04 = {.d32 = KEYSCAN->KEYSCAN_CONFIG1};
    keyscan_0x04.b.keyscan_deb_timer_en = NewState;
    keyscan_0x04.b.keyscan_deb_timer_cnt = time;
    KEYSCAN->KEYSCAN_CONFIG1 = keyscan_0x04.d32;
}

/**
 * @brief Get KEYSCAN FIFO data num.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 *
 * @return Data length in FIFO.
 */
uint16_t KEYSCAN_GetFIFODataNum(KEYSCAN_TypeDef *KEYSCANx)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    KEYSCAN_INT_STS_TypeDef keyscan_0x20 = {.d32 = KEYSCAN->KEYSCAN_INT_STS};
    return (uint16_t)(keyscan_0x20.b.keyscan_fifo_data_level);
}

/**
 * @brief Clear the KEYSCAN interrupt pending bit.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_INT Specifies the interrupt pending bit to clear.
 *            This parameter can be any combination of the following values:
 *            - KEYSCAN_INT_THRESHOLD: KEYSCAN FIFO data over threshold interrupt.
 *            - KEYSCAN_INT_OVER_READ: KEYSCAN over read interrupt.
 *            - KEYSCAN_INT_SCAN_END: KEYSCAN scan end interrupt.
 *            - KEYSCAN_INT_FIFO_NOT_EMPTY: KEYSCAN FIFO not empty interrupt.
 *            - KEYSCAN_INT_ALL_RELEASE: KEYSCAN all key release interrupt.
 */
void KEYSCAN_ClearINTPendingBit(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_INT)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_CONFIG_INT(KEYSCAN_INT));

    KEYSCAN->KEYSCAN_INT_CLR |= KEYSCAN_INT;

    return;
}

/**
 * @brief Clear the specified KEYSCAN flag.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_FLAG Specifies the flag to clear.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: FIFO limit status. The FIFO limit can be configured to limit the max allowable key data in one scan.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 */
void KEYSCAN_ClearFlags(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_CLEAR_FLAG(KEYSCAN_FLAG));

    KEYSCAN_INT_CLR_TypeDef keyscan_0x1c = {.d32 = KEYSCAN->KEYSCAN_INT_CLR};
    if (KEYSCAN_FLAG & KEYSCAN_FLAG_FIFOLIMIT)
    {
        keyscan_0x1c.b.keyscan_fifo_limit_st_clr = 0x01;
    }
    if (KEYSCAN_FLAG & KEYSCAN_FLAG_DATAFILTER)
    {
        keyscan_0x1c.b.keyscan_fifo_data_filter_st_clr = 0x01;
    }
    if (KEYSCAN_FLAG & KEYSCAN_FLAG_OVR)
    {
        keyscan_0x1c.b.keyscan_fifo_ov_st_clr = 0x01;
    }
    KEYSCAN->KEYSCAN_INT_CLR = keyscan_0x1c.d32;

    return;
}

/**
 * @brief Check whether the specified KEYSCAN flag is set.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] KEYSCAN_FLAG Specifies the flag to check.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_FLAG_FIFOLIMIT: FIFO limit status. The FIFO limit can be configured to limit the max allowable key data in one scan.
 *            - KEYSCAN_INT_FLAG_THRESHOLD: FIFO threshold interrupt status.
 *            - KEYSCAN_INT_FLAG_OVER_READ: FIFO over read interrupt status.
 *            - KEYSCAN_INT_FLAG_SCAN_END: Scan finish interrupt status.
 *            - KEYSCAN_INT_FLAG_FIFO_NOT_EMPTY: FIFO not empty interrupt status.
 *            - KEYSCAN_INT_FLAG_ALL_RELEASE: All release interrupt status.
 *            - KEYSCAN_FLAG_DATAFILTER: FIFO data filter status.
 *            - KEYSCAN_FLAG_OVR: FIFO overflow status.
 *            - KEYSCAN_FLAG_FULL: FIFO full status.
 *            - KEYSCAN_FLAG_EMPTY: FIFO empty status.
 *
 * @return The status of KEYSCAN flag (SET or RESET).
 * @retval SET    The specified KEYSCAN flag is set.
 * @retval RESET  The specified KEYSCAN flag is reset.
 */
FlagStatus KEYSCAN_GetFlagState(KEYSCAN_TypeDef *KEYSCANx, uint32_t KEYSCAN_FLAG)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_FLAG(KEYSCAN_FLAG));

    if ((KEYSCAN->KEYSCAN_INT_STS & KEYSCAN_FLAG) != 0)
    {
        return SET;
    }
    return RESET;
}

/**
 * @brief Read FIFO data.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 *
 * @return KEYSCAN FIFO data.
 */
uint16_t KEYSCAN_ReadFIFOData(KEYSCAN_TypeDef *KEYSCANx)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    return (uint16_t)(KEYSCAN->KEYSCAN_FIFO_ENTRY);
}

/**
 * @brief Set manual scan trigger mode. This function is only effective when keyscan is manual scan mode.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] manual_sel Specifies the KEYSCAN manual trigger mode.
 *            This parameter can be one of the following values:
 *            - KEYSCAN_MANUAL_SEL_BIT: Scan trigger by register (Call API KEYSCAN_Cmd).
 *            - KEYSCAN_MANUAL_SEL_KEY: Scan trigger by key.
 */
void KEYSCAN_SetManualSelect(KEYSCAN_TypeDef *KEYSCANx, KEYSCANManualSel_TypeDef manual_sel)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_MANUAL_SELECT(manual_sel));

    KEYSCAN_CONFIG2_TypeDef keyscan_0x08 = {.d32 = KEYSCAN->KEYSCAN_CONFIG2};

    /* Only manual mode can change manual select */
    if (keyscan_0x08.b.keyscan_work_mode == KEYSCAN_MANUAL_SCAN_MODE)
    {
        keyscan_0x08.b.keyscan_manual_sel = manual_sel;
        KEYSCAN->KEYSCAN_CONFIG2 = keyscan_0x08.d32;
    }

}

/**
 * @brief Set preguard time. Preguard time = preguard_cnt * scan clock.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] preguard_cnt Specifies the preguard count. This parameter can be configured from 0 to 7.
 */
void KEYSCAN_SetPreGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t preguard_cnt)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    KEYSCAN_CLK_DIV_TypeDef keyscan_0x00 = {.d32 = KEYSCAN->KEYSCAN_CLK_DIV};
    keyscan_0x00.b.keyscan_gt_pre_sel = preguard_cnt;
    KEYSCAN->KEYSCAN_CLK_DIV = keyscan_0x00.d32;
}

/**
 * @brief Set postguard time. Postguard time = postguard_cnt * scan clock.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] postguard_cnt Specifies the postguard count. This parameter can be configured from 0 to 7.
 */
void KEYSCAN_SetPostGuardTime(KEYSCAN_TypeDef *KEYSCANx, uint8_t postguard_cnt)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));

    KEYSCAN_CLK_DIV_TypeDef keyscan_0x00 = {.d32 = KEYSCAN->KEYSCAN_CLK_DIV};
    keyscan_0x00.b.keyscan_gt_post_sel = postguard_cnt;
    KEYSCAN->KEYSCAN_CLK_DIV = keyscan_0x00.d32;
}

#if (KEYSCAN_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the KEYSCAN RAP mode.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] NewState New state of the RAP mode.
 *            - ENABLE: Enable the KEYSCAN RAP mode.
 *            - DISABLE: Disable the KEYSCAN RAP mode.
 */
void KEYSCAN_RAPModeCmd(KEYSCAN_TypeDef *KEYSCANx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    KEYSCAN_TASK_CTRL_TypeDef keyscan_0x38 = {.d32 = KEYSCAN->KEYSCAN_TASK_CTRL};
    keyscan_0x38.b.rap_mode = NewState;
    KEYSCAN->KEYSCAN_TASK_CTRL = keyscan_0x38.d32;

    return;
}

/**
 * @brief Trigger the specified KEYSCAN action.
 *
 * @param[in] KEYSCANx Selected KEYSCAN peripheral.
 * @param[in] Action Specifies the KEYSCAN action to trigger.
 *            This parameter can be a value of @ref KEYSCAN_ACTION.
 */
void KEYSCAN_ActionTrigger(KEYSCAN_TypeDef *KEYSCANx, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_KEYSCAN_PERIPH(KEYSCANx));
    assert_param(IS_KEYSCAN_ACTION(Action));

    KEYSCAN_TASK_CTRL_TypeDef keyscan_0x38 = {.d32 = KEYSCAN->KEYSCAN_TASK_CTRL};
    if (Action == KEYSCAN_ACTION_MANUAL)
    {
        keyscan_0x38.b.task_manual = 0x1;
    }
    KEYSCAN->KEYSCAN_TASK_CTRL = keyscan_0x38.d32;

    return;
}

#endif


