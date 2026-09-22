/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_pinmux.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define MAX_PINMUX_NUM      ((PCC_REG_PMUX_GPIO_SPIC_2 - PCC_r_PMUX_GPIO_P0_0to3 + 4) >> 2) /* pinmux Register number: 13 */

#if (PAD_SUPPORT_GET_PIN_NAME == 1)
static const char *const pad_name_table[] =
{
    "P0_0",     "P0_1",      "P0_2",      "P0_3",      "P0_4",    "P0_5",      "P0_6",      "P0_7",
    "P1_0",     "P1_1",      "P1_6",      "P1_7",
    "P2_0",     "P2_1",      "P2_2",      "P2_3",      "P2_4",    "P2_5",      "P2_6",      "P2_7",
    "P3_0",     "P3_1",      "P3_2",      "P3_3",      "P3_4",    "P3_5",      "P3_6",
    "P4_0",     "P4_1",      "P4_2",      "P4_3",
    "MICBIAS",  "P5_1",      "P5_2",
    "P6_0",     "P6_1",      "P6_2",      "P6_3",      "P6_4",    "P6_5",      "P6_6",      "P6_7",
    "P7_0",     "P7_1",      "SPIC_CSN",  "SPIC_SCK",  "SPIC_SI", "SPIC_SO",   "SPIC_WEN",  "SPIC_HOLDEN",
};
#endif

const PADAddrTable_TypeDef pad_addr_table =
{
    .reg[P0_0] =     0x120,
    .reg[P0_1] =     0x122,
    .reg[P0_2] =     0x124,
    .reg[P0_3] =     0x126,
    .reg[P0_4] =     0x128,
    .reg[P0_5] =     0x12a,
    .reg[P0_6] =     0x12C,
    .reg[P0_7] =     0x12e,
    .reg[P1_0] =     0x130,
    .reg[P1_1] =     0x132,
    .reg[P1_6] =     0x134,
    .reg[P1_7] =     0x136,
    .reg[P2_0] =     0x138,
    .reg[P2_1] =     0x13a,
    .reg[P2_2] =     0x13C,
    .reg[P2_3] =     0x13e,
    .reg[P2_4] =     0x140,
    .reg[P2_5] =     0x142,
    .reg[P2_6] =     0x144,
    .reg[P2_7] =     0x146,
    .reg[P3_0] =     0x148,
    .reg[P3_1] =     0x14a,
    .reg[P3_2] =     0x14C,
    .reg[P3_3] =     0x14e,
    .reg[P3_4] =     0x150,
    .reg[P3_5] =     0x152,
    .reg[P3_6] =     0x154,
    .reg[P4_0] =     0x158,
    .reg[P4_1] =     0x15a,
    .reg[P4_2] =     0x15C,
    .reg[P4_3] =     0x15e,
    .reg[MICBIAS] =  0x178,
    .reg[P5_1] =     0x160,
    .reg[P5_2] =     0x162,
    .reg[P6_0] =     0x164,
    .reg[P6_1] =     0x166,
    .reg[P6_2] =     0x168,
    .reg[P6_3] =     0x16a,
    .reg[P6_4] =     0x16C,
    .reg[P6_5] =     0x16e,
    .reg[P6_6] =     0x170,
    .reg[P6_7] =     0x172,
    .reg[P7_0] =     0x174,
    .reg[P7_1] =     0x176,
    .reg[SPIC_CSN] = 0x18E,
    .reg[SPIC_SCK] = 0x18C,
    .reg[SPIC_SI] =  0x192,
    .reg[SPIC_SO] =  0x190,
    .reg[SPIC_WEN] = 0x196,    /*!< P1_4 */
    .reg[SPIC_HOLDEN] = 0x194, /*!< P1_3 */
};

const PINMUXIndexTable_TypeDef pinmux_index_table =
{
    .reg[P0_0] =    0,
    .reg[P0_1] =    1,
    .reg[P0_2] =    2,
    .reg[P0_3] =    3,
    .reg[P0_4] =    4,
    .reg[P0_5] =    5,
    .reg[P0_6] =    6,
    .reg[P0_7] =    7,
    .reg[P1_0] =    8,
    .reg[P1_1] =    9,
    .reg[P1_6] =    10,
    .reg[P1_7] =    11,
    .reg[P2_0] =    12,
    .reg[P2_1] =    13,
    .reg[P2_2] =    14,
    .reg[P2_3] =    15,
    .reg[P2_4] =    16,
    .reg[P2_5] =    17,
    .reg[P2_6] =    18,
    .reg[P2_7] =    19,
    .reg[P3_0] =    20,
    .reg[P3_1] =    21,
    .reg[P3_2] =    22,
    .reg[P3_3] =    23,
    .reg[P3_4] =    24,
    .reg[P3_5] =    25,
    .reg[P3_6] =    26,
    .reg[P4_0] =    28,
    .reg[P4_1] =    29,
    .reg[P4_2] =    30,
    .reg[P4_3] =    31,
    .reg[MICBIAS] = 32,
    .reg[P5_1] =    33,
    .reg[P5_2] =    34,
    .reg[P6_0] =    36,
    .reg[P6_1] =    37,
    .reg[P6_2] =    38,
    .reg[P6_3] =    39,
    .reg[P6_4] =    40,
    .reg[P6_5] =    41,
    .reg[P6_6] =    42,
    .reg[P6_7] =    43,
    .reg[P7_0] =    44,
    .reg[P7_1] =    45,
    .reg[SPIC_CSN] = 46,
    .reg[SPIC_SCK] = 47,
    .reg[SPIC_SI]  = 48,
    .reg[SPIC_SO]  = 49,
    .reg[SPIC_WEN] = 50,
    .reg[SPIC_HOLDEN] = 51,
};


/*============================================================================*
 *                        Private Functions
 *============================================================================*/

/*============================================================================*
 *                        Public Functions
 *============================================================================*/
/**
 * @brief Reset the PINMUX settings to idle mode of all pins.
 * @note  The two SWD pins will also be reset. Please use this function carefully.
 */
void Pinmux_Reset(void)
{
    for (uint8_t i = 0; i < MAX_PINMUX_NUM; i++)
    {
        PINMUX->CFG[i] = 0x00;
    }

    return;
}

/**
 * @brief Configure the PINMUX settings to idle mode of the specified pad.
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 */
void Pinmux_Deinit(uint8_t Pin_Num)
{
    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    uint8_t pinmux_index = pinmux_index_table.reg[Pin_Num];
    uint8_t pinmux_reg_num = pinmux_index >> 2;
    PINMUX->CFG[pinmux_reg_num] &= ~(0xff << ((pinmux_index % 4) << 3));

    return;
}

/**
 * @brief Configure the specified pad to its corresponding peripheral function.
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Pin_Func  Specifies the peripheral function. Refer to @ref PIN_FUNCTION.
 */
void Pinmux_Config(uint8_t Pin_Num, uint32_t Pin_Func)
{
    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    uint8_t pinmux_index = pinmux_index_table.reg[Pin_Num];
    uint8_t pinmux_reg_num = pinmux_index >> 2;
    uint8_t reg_offset = (pinmux_index & 0x03) << 3;

    PINMUX->CFG[pinmux_reg_num] = (PINMUX->CFG[pinmux_reg_num] & ~(0xFF << reg_offset))
                                  | Pin_Func << reg_offset;

    return;
}

/**
 * @brief Configure the PAD settings to the default state of all pads.
 */
void Pad_AllConfigDefault(void)
{
    uint16_t i = 0;
    for (i = 0; i < TOTAL_PIN_NUM; i++)
    {
        Pad_TableConfig(OUTPUT_VAL, i, DISABLE);
        Pad_TableConfig(OUTPUT_EN, i, DISABLE);
        Pad_TableConfig(PULL_EN, i, DISABLE);
        Pad_TableConfig(PULL_DIR, i, DISABLE);
        Pad_TableConfig(PULL_RES, i, DISABLE);
        Pad_TableConfig(WAKEUP_EN, i, DISABLE);
        Pad_TableConfig(WAKEUP_POL, i, DISABLE);
        Pad_TableConfig(POWER_SHDN, i, DISABLE);
        Pad_TableConfig(PAD_DEB, i, DISABLE);
        Pad_TableConfig(WAKEUP_RAP, i, DISABLE);
        Pad_TableConfig(WAKEUP_PPU, i, DISABLE);
        Pad_TableConfig(AON_MUX, i, DISABLE);
    }

}

/**
 * @brief Configure the operation mode which includes pad mode, power mode,
 *        pull resistor, and output behavior of a specified pad.
 * @param[in] Pin_Num        Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] AON_PAD_Mode   Specifies the pad mode of the specified pin. Refer to @ref PAD_MODE.
 * @param[in] AON_PAD_PwrOn  Specifies the power mode of the specified pin. Refer to @ref PAD_POWER_MODE.
 * @param[in] AON_PAD_Pull   Specifies the pull mode of the specified pin. Refer to @ref PAD_PULL_MODE.
 * @param[in] AON_PAD_E      Specifies the output direction of the specified pin. Refer to @ref PAD_OUTPUT_DIRECTION.
 * @param[in] AON_PAD_O      Specifies the output value of the specified pin. Refer to @ref PAD_OUTPUT_VALUE.
 */
void Pad_Config(uint8_t                Pin_Num,
                PADMode_TypeDef        AON_PAD_Mode,
                PADPowerMode_TypeDef   AON_PAD_PwrOn,
                PADPullMode_TypeDef    AON_PAD_Pull,
                PADOutputMode_TypeDef  AON_PAD_E,
                PADOutputValue_TypeDef AON_PAD_O)
{
    if (!IS_PIN_NUMBER(Pin_Num))
    {
        return;
    }

    uint32_t temp_value = 0;
    uint32_t reg_addr_offset = PAD_REG_BASE + pad_addr_table.reg[Pin_Num];
    uint32_t reg_high_offset = (reg_addr_offset & BIT1) ? 16 : 0;
    reg_addr_offset &= ~BIT1;

    /* AON MUX */
    if (AON_PAD_Mode)
    {
        temp_value |= AON_PAD_Mode << BITOFFSET(AON_MUX);
    }

    /* Pull config */
    if (AON_PAD_Pull == PAD_PULL_UP)
    {
        temp_value |= PULL_EN;
        temp_value &= ~PULL_DIR;
    }
    else if (AON_PAD_Pull == PAD_PULL_DOWN)
    {
        temp_value |= PULL_EN;
        temp_value |= PULL_DIR;
    }
    else if (AON_PAD_Pull == PAD_PULL_NONE)
    {
        temp_value &= ~PULL_EN;
    }

    /* Output Config */
    if (AON_PAD_E == PAD_OUT_ENABLE)
    {
        temp_value |= (OUTPUT_EN) | (AON_PAD_O << BITOFFSET(OUTPUT_VAL));
    }

    /* Get reg value from register */
    uint32_t reg_value = PAD_REG_READ(reg_addr_offset);

    /* Clear reg value first. */
    reg_value &= ~(PAD_CONFIG_MASK << reg_high_offset);

    /* Set reg value to register and need power on first*/
    reg_value |= (temp_value | POWER_SHDN) << reg_high_offset;
    PAD_REG_WRITE(reg_addr_offset, reg_value);

    /* Pad control mode */
    if (AON_PAD_PwrOn == PAD_NOT_PWRON)
    {
        reg_value &= ~(POWER_SHDN << reg_high_offset);
        PAD_REG_WRITE(reg_addr_offset, reg_value);
    }

    Pad_ModeAutoSwitchCmd(Pin_Num, AON_PAD_Mode == PAD_PINMUX_MODE);
}

/**
 * @brief Enables or disables the automatic pad mode switching during DLPS entry/exit.
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  ENABLE to allow automatic mode switching,
 *                      DISABLE to hold the current mode/state during DLPS.
 */
void Pad_ModeAutoSwitchCmd(uint8_t Pin_Num, FunctionalState NewState)
{
    volatile uint32_t *aonmux_as_register = (volatile uint32_t *)(PAD_AONMUX_AS_BASE + 4 *
                                                                  (Pin_Num > MICBIAS));

    if (NewState == ENABLE)
    {
        /* Enable Auto Switch which is switched to aon when enter dlps and to pinmux when exit dlps */
        *aonmux_as_register |= BIT(Pin_Num & 0x1F);
    }
    else
    {
        /* Disable Auto Switch which is hold on pinmux mode when enter dlps */
        *aonmux_as_register &= ~BIT(Pin_Num & 0x1F);
    }
}

/**
 * @brief  Configures the pull-up/pull-down resistor of the specified pad specifically for DLPS.
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] AON_PAD_Pull  Specifies the desired pull state during DLPS.
 * @param[in] NewState      ENABLE to apply this low power configuration, DISABLE to ignore it.
 */
void Pad_LPConfig(uint8_t Pin_Num, PADPullMode_TypeDef AON_PAD_Pull, FunctionalState NewState)
{
    uint8_t supported_pin_table[] = {P0_2, P0_4, P0_0, P0_1, \
                                     P1_0, P1_1, P0_5, P0_6, \
                                     P2_2, P2_3, P2_0, P2_1, \
                                     P2_6, P2_7, P2_4, P2_5, \
                                     P3_2, P3_3, P3_0, P3_1, \
                                     P4_2, P4_3, P4_0, P4_1, \
                                     SPIC_SO, SPIC_SI, SPIC_SCK, SPIC_CSN, \
                                     0xFF, 0xFF, SPIC_HOLDEN, SPIC_WEN
                                    };
    /* If PIN_Num is not in supported_pin_table, return early */
    if (memchr(supported_pin_table, Pin_Num, sizeof(supported_pin_table)) == NULL)
    {
        return;
    }

    uint32_t reg_addr_offset = PAD_REG_BASE + pad_addr_table.reg[Pin_Num];
    uint32_t reg_high_offset = (reg_addr_offset & BIT1) ? 16 : 0;
    reg_addr_offset &= ~BIT1;
    uint32_t reg_value = PAD_REG_READ(reg_addr_offset);

    for (uint8_t i = 0; i < sizeof(supported_pin_table); i++)
    {
        if (supported_pin_table[i] == Pin_Num)
        {
            PADMUXAS_TypeDef pull_as_aon_address = {.d32 = (*((volatile uint32_t *) PAD_PULL_AON_AS_BASE + i / 4))};
            PADMUXAS_TypeDef pull_as_core_address = {.d32 = (*((volatile uint32_t *) PAD_PULL_CORE_AS_BASE + i / 4))};
            if (NewState)
            {
                pull_as_aon_address.b[i % 4].as_en = ENABLE;
                if (AON_PAD_Pull == PAD_PULL_UP)
                {
                    pull_as_aon_address.b[i % 4].pu_en = 1;
                    pull_as_aon_address.b[i % 4].pd = 0;
                }
                else if (AON_PAD_Pull == PAD_PULL_DOWN)
                {
                    pull_as_aon_address.b[i % 4].pu_en = 1;
                    pull_as_aon_address.b[i % 4].pd = 1;
                }
                else if (AON_PAD_Pull == PAD_PULL_NONE)
                {
                    pull_as_aon_address.b[i % 4].pu_en = 0;
                    pull_as_aon_address.b[i % 4].pd = 0;
                }

                pull_as_core_address.b[i % 4].pu_en = (((reg_value >> reg_high_offset) & PULL_EN) == PULL_EN);
                pull_as_core_address.b[i % 4].pd = (((reg_value >> reg_high_offset) & PULL_DIR) == PULL_DIR);
            }
            else
            {
                pull_as_aon_address.d32 &= ~(0xFF << ((i % 4) << 3));
                pull_as_core_address.d32 &= ~(0xFF << ((i % 4) << 3));
            }
            (*((volatile uint32_t *) PAD_PULL_AON_AS_BASE + i / 4)) = pull_as_aon_address.d32;
            (*((volatile uint32_t *) PAD_PULL_CORE_AS_BASE + i / 4)) = pull_as_core_address.d32;
        }
    }

    /* Check all Pin Auto Switch En is Disabled */
    bool all_auto_switch_disabled = true;
    for (uint8_t i = 0; i < sizeof(supported_pin_table); i++)
    {
        PADMUXAS_TypeDef pull_as_aon_address = {.d32 = (*((volatile uint32_t *) PAD_PULL_AON_AS_BASE + i / 4))};
        if (pull_as_aon_address.b[i % 4].as_en == ENABLE)
        {
            all_auto_switch_disabled = false;
            break;
        }
    }
    if (all_auto_switch_disabled == true)
    {
        (*((volatile uint32_t *) PAD_PULL_AON_AS_BASE + 7)) &= ~BIT0;
    }
    else
    {
        (*((volatile uint32_t *) PAD_PULL_AON_AS_BASE + 7)) |= BIT0;
    }
}

/**
 * @brief Configures a specific peripheral function of a specified pad.
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] Pad_Func  Specifies the target peripheral function. Refer to @ref PAD_FUNCTION_CONFIG.
 * @return The execution result of configuring the pad function.
 * @retval true   Configuration successful.
 * @retval false  Invalid pin number. The specified Pad_Func is disabled in this case.
 */
bool Pad_FunctionConfig(uint8_t Pin_Num, PADFuncConfig_TypeDef Pad_Func)
{
    if (!IS_PIN_NUMBER(Pin_Num))
    {
        /* Disable the PAD function when the pin number is invalid by setting the XXX_SEL_EN to 0. */
        PAD_FUNCTION &= ~(0xFF << (Pad_Func << 3));
        return false;
    }

    for (uint8_t i = 0; i < 4; i++)
    {
        /* If the pin is already set to a different function, setting the XXX_SEL_EN to 0. */
        if ((PAD_FUNCTION & (BIT7 << (i << 3))) && (Pad_Func != i) &&
            (Pin_Num == ((PAD_FUNCTION >> (i << 3)) & 0x3F)))
        {
            PAD_FUNCTION &= ~(0xFF << (i << 3));
        }
    }

    /* Set the PAD function for the specified pin number. */
    PAD_FUNCTION &= ~(0xFF << (Pad_Func << 3));
    PAD_FUNCTION |= (Pin_Num << (Pad_Func << 3));
    PAD_FUNCTION |= (BIT7 << (Pad_Func << 3));

    return true;
}

/**
 * @brief Enables or disables the dedicated high-speed function for specific peripherals.
 * @param[in] Pin_Group      Pointer to an array of pins for the high-speed configuration.
 * @param[in] Pin_GroupLen   The number of pins in the Pin_Group array.
 * @param[in] Pad_HighSpeed  Specifies the high-speed peripheral. Refer to @ref PAD_HIGH_SPEED_CONFIG.
 * @param[in] NewState       ENABLE or DISABLE to activate the high-speed path.
 * @return The execution result of configuring the high-speed function.
 * @retval true   Configuration successful.
 * @retval false  Configuration failed.
 */
bool Pad_HighSpeedConfig(uint8_t *Pin_Group, uint8_t Pin_GroupLen,
                         PADHSConfig_Typedef Pad_HighSpeed, FunctionalState NewState)
{
    if (Pad_HighSpeed == PAD_HIGH_SPEED_SPI0)
    {
        AON_REG_WRITE_BITFIELD(AON_REG_SPI_PAD_REG30X, SPI0M_AON_PATH_EN, NewState);
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG24X, PAD_P4_0_O_EN, !NewState);
    }
    else if (Pad_HighSpeed == PAD_HIGH_SPEED_SPI1)
    {
        AON_REG_WRITE_BITFIELD(AON_REG_SPI_PAD_REG30X, SPI1M_AON_PATH_EN, NewState);
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_4_O_EN, !NewState);
    }
    else if (Pad_HighSpeed == PAD_HIGH_SPEED_SPI2)
    {
        AON_REG_WRITE_BITFIELD(AON_REG_SPI_PAD_REG30X, SPI2M_AON_PATH_EN, NewState);
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG23X, PAD_P0_1_O_EN, !NewState);
    }

    return true;
}

/**
 * @brief  Get the string representation of the pin name.
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @return Pointer to a constant string containing the pin name.
 *         - Valid string pointer (e.g., "P0_0").
 *         - NULL: Invalid pin index.
 */
const char *Pad_GetPinName(uint8_t Pin_Num)
{
    return pad_name_table[Pin_Num];
}

/**
 * @brief Retrieve the hardware power group for the specified pad.
 * @param[in] Pin_Num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @return The corresponding power group of the pin. Refer to @ref PAD_POWER_GROUP.
 */
static PADPowerGroup_TypeDef Pad_GetPowerGroup(uint8_t Pin_Num)
{
    if ((Pin_Num >= P0_0 && Pin_Num <= P0_1) ||
        (Pin_Num >= P0_7 && Pin_Num <= P1_7) ||
        (Pin_Num >= P3_0 && Pin_Num <= P3_3) ||
        (Pin_Num >= P7_0 && Pin_Num <= P7_1))
    {
        return PAD_POWER_GROUP_RIGHT;
    }
    else if ((Pin_Num == P0_2) || (Pin_Num >= P0_4 && Pin_Num <= P0_6) ||
             (Pin_Num >= P2_0 && Pin_Num <= P2_7) ||
             (Pin_Num >= P3_4 && Pin_Num <= P3_6) ||
             (Pin_Num >= MICBIAS && Pin_Num <= P5_2) ||
             (Pin_Num >= SPIC_CSN && Pin_Num <= SPIC_WEN))
    {
        return PAD_POWER_GROUP_LEFT;
    }
    else if ((Pin_Num == P0_3) ||
             (Pin_Num >= P4_0 && Pin_Num <= P4_3) ||
             (Pin_Num >= P6_0 && Pin_Num <= P6_7))
    {
        return PAD_POWER_GROUP_BOTTOM;
    }

    return PAD_POWER_GROUP_INVALID;
}

/**
 * @brief Configure the driving current of the specified pad.
 * @param[in] Pin_Num             Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_DrivingCurrent  The desired driving current. Refer to @ref PAD_DRIVING_CURRENT.
 */
void Pad_SetDrivingCurrent(uint8_t Pin_Num, PADDrivingCurrent_TypeDef PAD_DrivingCurrent)
{
    if (Pin_Num == P0_5) /* P0_5 only support 8/18/28mA */
    {
        Pad_TableConfig(CUR_DRIVING, Pin_Num, (PAD_DrivingCurrent >> 1) & BIT0);
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG26X, LEFT_PAD_E2, (PAD_DrivingCurrent == 3));
        return;
    }
    else if (Pin_Num == P6_0) /* P6_0 only support 8/18/28mA */
    {
        Pad_TableConfig(CUR_DRIVING, Pin_Num, (PAD_DrivingCurrent >> 1) & BIT0);
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG26X, BOTTOM_PAD_E2, (PAD_DrivingCurrent == 3));
        return;
    }

    /* Others only support 4/8mA only */
    PADPowerGroup_TypeDef power_group = Pad_GetPowerGroup(Pin_Num);
    if (power_group == PAD_POWER_GROUP_LEFT)
    {
        if ((Pin_Num >= SPIC_CSN && Pin_Num <= SPIC_WEN))
        {
            AON_REG_WRITE_BITFIELD(AON_REG_SPI_PAD_REG30X, SPIC_PAD_E2, (PAD_DrivingCurrent > 0));
        }
        else
        {
            AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG26X, LEFT_PAD_E2, (PAD_DrivingCurrent > 0));
        }
    }
    else if (power_group == PAD_POWER_GROUP_RIGHT)
    {
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG26X, RIGHT_PAD_E2, (PAD_DrivingCurrent > 0));
    }
    else if (power_group == PAD_POWER_GROUP_BOTTOM)
    {
        AON_REG_WRITE_BITFIELD(AON_REG_PAD_REG26X, BOTTOM_PAD_E2, (PAD_DrivingCurrent > 0));
    }
}

/**
 * @brief Configure the pad control mode of the specified pad.
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_Mode  Specifies the control mode. Refer to @ref PAD_MODE.
 */
void Pad_SetControlMode(uint8_t Pin_Num, PADMode_TypeDef PAD_Mode)
{
    Pad_TableConfig(AON_MUX, Pin_Num, PAD_Mode);
}

/**
 * @brief Enable or disable the output mode of the specified pad.
 * @param[in] Pin_Num    Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_OutEn  Enable or disable the output mode. Refer to @ref PAD_OUTPUT_DIRECTION.
 */
void Pad_OutputCmd(uint8_t Pin_Num, PADOutputMode_TypeDef PAD_OutEn)
{
    Pad_TableConfig(OUTPUT_EN, Pin_Num, PAD_OutEn);
}

/**
 * @brief Configure the output level of the specified pad.
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_OutValue  The desired output logic level. Refer to @ref PAD_OUTPUT_VALUE.
 */
void Pad_SetOutputLevel(uint8_t Pin_Num, PADOutputValue_TypeDef PAD_OutValue)
{
    Pad_TableConfig(OUTPUT_VAL, Pin_Num, PAD_OutValue);
}

/**
 * @brief Enable or disable the internal pull-up / pull-down resistor of the specified pad.
 * @param[in] Pin_Num   Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] NewState  Enable or disable the internal pull-up / pull-down resistor. Refer to @ref FunctionalState.
 */
void Pad_PullCmd(uint8_t Pin_Num, FunctionalState NewState)
{
    Pad_TableConfig(PULL_EN, Pin_Num, NewState);
}

/**
 * @brief Configure the pull mode of the specified pad.
 * @param[in] Pin_Num       Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PullMode  The desired pull state. Refer to @ref PAD_PULL_MODE.
 */
void Pad_SetPullMode(uint8_t Pin_Num, PADPullMode_TypeDef PAD_PullMode)
{
    if (PAD_PullMode == PAD_PULL_NONE)
    {
        Pad_TableConfig(PULL_EN, Pin_Num, DISABLE);
    }
    else if (PAD_PullMode == PAD_PULL_UP)
    {
        Pad_TableConfig(PULL_EN, Pin_Num, ENABLE);
        Pad_TableConfig(PULL_DIR, Pin_Num, DISABLE);
    }
    else if (PAD_PullMode == PAD_PULL_DOWN)
    {
        Pad_TableConfig(PULL_EN, Pin_Num, ENABLE);
        Pad_TableConfig(PULL_DIR, Pin_Num, ENABLE);
    }
}

/**
 * @brief Configure the resistance strength of the internal pull-up/pull-down.
 * @param[in] Pin_Num               Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PullStrengthMode  The desired pull strength. Refer to @ref PAD_PULL_STRENGTH_MODE.
 */
void Pad_SetPullStrength(uint8_t Pin_Num, PADPullStrengthMode_TypeDef PAD_PullStrengthMode)
{
    Pad_TableConfig(PULL_RES, Pin_Num, PAD_PullStrengthMode);
}

/**
 * @brief Configure the power mode of the specified pad.
 * @param[in] Pin_Num        Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @param[in] PAD_PowerMode  Specifies the power mode. Refer to @ref PAD_POWER_MODE.
 */
void Pad_PowerCmd(uint8_t Pin_Num, PADPowerMode_TypeDef PAD_PowerMode)
{
    Pad_TableConfig(POWER_SHDN, Pin_Num, PAD_PowerMode);
}


