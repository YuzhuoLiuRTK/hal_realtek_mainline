/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_gpio.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define GPIO_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define GPIO_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0xFF)//Force off 0xAA

/*============================================================================*
 *                           Private Constant
 *============================================================================*/
const uint8_t gpio_mapping_table[TOTAL_PIN_NUM] =
{
    0,  1,  2,  3,      /*!< P0_0 P0_1 P0_2 P0_3 */
    4,  5,  6,  7,      /*!< P0_4 P0_5 P0_6 P0_7 */
    8,  9,  10, 11,     /*!< P1_0 P1_1 P1_6 P1_7 */
    12, 13, 14, 15,     /*!< P2_0 P2_1 P2_2 P2_3 */
    16, 17, 18, 19,     /*!< P2_4 P2_5 P2_6 P2_7 */
    20, 21, 22, 23,     /*!< P3_0 P3_1 P3_2 P3_3 */
    24, 25, 26, 27,     /*!< P3_4 P3_5 P3_6 P4_0 */
    28, 29, 30, 31,     /*!< P4_1 P4_2 P4_3 MICBIAS */
    32, 33, 34, 35,     /*!< P5_1 P5_2 P6_0 P6_1 */
    36, 37, 38, 39,     /*!< P6_2 P6_3 P6_4 P6_5 */
    40, 41, 42, 43,     /*!< P6_6 P6_7 P7_0 P7_1 */
    44, 45, 46, 47,     /*!< SPIC_CSN SPIC_SCK SPIC_SI SPIC_SO */
    48, 49,             /*!< SPIC_WEN SPIC_HOLDEN */
};

const uint32_t gpio_deb_table[13][4] =
{
    {BIT0,  BIT1,  BIT2,  BIT3},
    {BIT4,  BIT8,  BIT9,  BIT7},
    {BIT12, BIT13, BIT10, BIT11},
    {BIT6,  BIT31, BIT14, BIT15},
    {BIT16, BIT17, BIT18, BIT19},
    {BIT20, BIT21, BIT22, BIT23},
    {BIT24, BIT25, BIT26, BIT5},
    {BIT28, BIT29, BIT30, BIT27},
    {BIT0,  BIT1,  BIT2,  BIT3},
    {BIT4,  BIT5,  BIT6,  BIT7},
    {BIT8,  BIT9,  BIT10, BIT11},
    {BIT12, BIT13, BIT14, BIT15},
    {BIT16, BIT17, 0,       0}
};
/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Remap a GPIO pin mask to its external-debounce bit position.
 * @note  On GPIOA the debounce hardware does not use the same bit order as the
 *        GPIO pins, so the pin mask must be swapped before indexing the
 *        debounce control registers. GPIOB needs no remapping.
 *
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The pin mask remapped to debounce bit positions.
 */
uint32_t GPIO_SwapDebPinBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    uint32_t deb_bit = GPIO_Pin;

#define SWAP_DEB_PIN_BIT(old_pin, new_pin) do {                       \
        deb_bit &= ~BIT(new_pin);                                     \
        deb_bit |= ((GPIO_Pin & BIT(old_pin)) >> old_pin) << new_pin; \
    } while (0)

    if (GPIOx == GPIOA)
    {
        SWAP_DEB_PIN_BIT(5,  27);
        SWAP_DEB_PIN_BIT(6,  12);
        SWAP_DEB_PIN_BIT(8,  5);
        SWAP_DEB_PIN_BIT(9,  6);
        SWAP_DEB_PIN_BIT(12, 8);
        SWAP_DEB_PIN_BIT(13, 9);
        SWAP_DEB_PIN_BIT(27, 31);
        SWAP_DEB_PIN_BIT(31, 13);
    }

    return deb_bit;
}

/**
 * @brief Enable or disable the debounce function and clock of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param NewState  Enable or disable GPIO debounce function and clock.
 */
void GPIO_ExtDebCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    uint8_t GPIO_Port_Offset = GPIOx == GPIOA ? 0 : 8;
    uint32_t GPIO_Pin_Swap = GPIO_SwapDebPinBit(GPIOx, GPIO_Pin);

    for (uint8_t i = 0; i < 8; i++)
    {
        if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
        {
            if (NewState == ENABLE)
            {
                GPIOx->GPIO_EXT_DEB_FUNC_CTL &= ~(gpio_deb_table[i + GPIO_Port_Offset][0] |
                                                  gpio_deb_table[i + GPIO_Port_Offset][1] |
                                                  gpio_deb_table[i + GPIO_Port_Offset][2] |
                                                  gpio_deb_table[i + GPIO_Port_Offset][3]);

                for (uint8_t j = 0; j < 4; j++)
                {
                    if ((GPIO_Pin_Swap & (BIT(j) << (i * 4))) != 0)
                    {
                        GPIOx->GPIO_EXT_DEB_FUNC_CTL |= gpio_deb_table[i + GPIO_Port_Offset][j];
                        break;
                    }
                }
            }
            else
            {
                for (uint8_t j = 0; j < 4; j++)
                {
                    if ((GPIO_Pin_Swap & (BIT(j) << (i * 4))) != 0)
                    {
                        GPIOx->GPIO_EXT_DEB_FUNC_CTL &= ~gpio_deb_table[i + GPIO_Port_Offset][j];
                    }
                }
            }
        }
    }
}

/**
 * @brief Set the GPIO debounce parameters of the specified GPIO pin.
 * @param GPIOx               Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin            Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param GPIO_DebClockSrc    Specifies the GPIO debounce clock source. Refer to @ref GPIO_DEBOUNCE_SOURCE.
 * @param GPIO_DebClockDiv    Specifies the GPIO debounce clock divider. Refer to @ref GPIO_DEBOUNCE_DIVIDE.
 * @param GPIO_DebCountLimit  Specifies the debounce count limit.
 *                            This parameter valid value range is from 0 to 255.

 *                            This value is used to configure the GPIO debounce time, which is calculated as:
 *                            T_debounce = 2 * T2 + (CountLimit + 1) * T2,
 *                            where T2 is the debounce clock period after division, given by:
 *                            T2 = (1 / GPIO_DebClockSrc) * GPIO_DebClockDiv.
 */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebClockSrc_TypeDef GPIO_DebClockSrc,
                       GPIODebClockDiv_TypeDef GPIO_DebClockDiv,
                       uint8_t                 GPIO_DebCountLimit)
{
    uint32_t GPIO_Pin_Swap = GPIO_SwapDebPinBit(GPIOx, GPIO_Pin);

    for (uint8_t i = 0; i < 8; i++)
    {
        if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
        {
            GPIO_EXT_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx->GPIO_EXT_DEB_CLK_CTL[i / 2]};
            if (i % 2)
            {
                gpio_deb.b.gpio_h_cnt_limit = GPIO_DebCountLimit & 0xFF;
                gpio_deb.b.gpio_h_deb_clk_div = GPIO_DebClockDiv;
            }
            else
            {
                gpio_deb.b.gpio_l_cnt_limit = GPIO_DebCountLimit & 0xFF;
                gpio_deb.b.gpio_l_deb_clk_div = GPIO_DebClockDiv;
            }
            GPIOx->GPIO_EXT_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
        }
    }
}

/**
 * @brief Get the GPIO port through the given PAD.
 * @param Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @return The GPIO port (e.g. GPIOA, GPIOB). Refer to @ref GPIO_DECLARATION.
 */
GPIO_TypeDef *GPIO_GetPort(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    uint8_t gpio_number = gpio_mapping_table[Pin_num];

    if (gpio_number <= 31)
    {
        return GPIOA;
    }
    else if (gpio_number <= 63)
    {
        return GPIOB;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Get the GPIO pin bit through the given PAD.
 * @param Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @return The GPIO pin bit (e.g. GPIO_Pin_0). Refer to @ref GPIO_PINS_DEFINE.
 */
uint32_t GPIO_GetPinBit(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    uint8_t gpio_number = gpio_mapping_table[Pin_num];

    return BIT((gpio_number) & 0x1F);
}


/**
 * @brief Get the GPIO number through the given PAD.
 * @param Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 * @return The GPIO number (e.g. GPIOA0, GPIOA1). Refer to @ref GPIO_NUMBER.
 */
uint8_t GPIO_GetNum(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    return gpio_mapping_table[Pin_num];
}

/**
 * @brief Set the interrupt/debounce polarity for the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param Polarity  Specifies the GPIO polarity. Refer to @ref GPIO_POLARITY.
 */
void GPIO_ExtPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity)
{
    bool isRAPEnabled = ((GPIOx->GPIO_RAP_CTL & GPIO_Pin) == GPIO_Pin);

    if (isRAPEnabled)
    {
        GPIO_RAPModeCmd(GPIOx, GPIO_Pin, DISABLE);
    }
    if (Polarity == GPIO_POLARITY_ACTIVE_LOW)
    {
        GPIOx->GPIO_EXT_DEB_POL_CTL &= (~GPIO_Pin);
    }
    else
    {
        GPIOx->GPIO_EXT_DEB_POL_CTL = (GPIOx->GPIO_EXT_DEB_POL_CTL & (~GPIO_Pin)) | GPIO_Pin;
    }
    if (isRAPEnabled)
    {
        GPIO_RAPModeCmd(GPIOx, GPIO_Pin, ENABLE);
    }
}

/**
 * @brief Enable or disable GPIO clock auto mode of the specified GPIO port.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param Newstate  Enable or disable the clock auto mode.
 */
void GPIO_ClockAutoModeCmd(GPIO_TypeDef *GPIOx, FunctionalState Newstate)
{
    if (Newstate == ENABLE)
    {
        GPIOx->GPIO_QACTIVE_MANUAL_CTRL = GPIO_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        GPIOx->GPIO_QACTIVE_MANUAL_CTRL = GPIO_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

/**
 * @brief Convert a debounce time in microseconds into the count limit and
 *        clock divider settings used by the debounce hardware.
 * @param time_us                Desired debounce time, in microseconds.
 * @param GPIO_DebounceCntLimit  The computed debounce count limit.
 * @param GPIO_DebounceSrcDiv    The computed debounce clock divider.
 */
void GPIO_DebounceTimeUs(uint32_t time_us, uint8_t *GPIO_DebounceCntLimit,
                         uint8_t *GPIO_DebounceSrcDiv)
{
    uint8_t deb_div = 0;
    for (deb_div = 0; deb_div <= 6 /* 0x7 is bypass divide */; deb_div++)
    {
        if (time_us <= ((1 << deb_div) * 8000))  /* (1 << 8) / (32000 / 1000 / 1000) = 8000 */
        {
            break;
        }
    }

    *GPIO_DebounceCntLimit = time_us * 32 / 1000 / (1 << deb_div) - 1;
    if (deb_div == 6)
    {
        deb_div = 7;
    }
    *GPIO_DebounceSrcDiv = deb_div;//deb_div;
}

/*============================================================================*
 *                           EXTI Functions
 *============================================================================*/
static struct
{
    IRQ_Fun gpio_callback[64];
} gpio_isr;

/**
 * @brief Register a per-pin interrupt callback into the GPIO ISR table.
 * @param irqn         GPIO interrupt number; its low 8 bits select the
 *                     entry (0 to 63) in the callback table.
 * @param isr_handler  Callback to invoke when the corresponding pin
 *                     interrupt fires.
 */
static void GPIO_ISRUpdate(uint32_t irqn, IRQ_Fun isr_handler)
{
    gpio_isr.gpio_callback[irqn & 0xFF] = isr_handler;
}

/**
 * @brief Dispatch GPIOA pin interrupts to their registered callbacks.
 * @param mask  Bit mask selecting which GPIOA pins (0 to 31) to service.
 */
void GPIOA_Handler(uint32_t mask)
{
    uint32_t real_interrupt_status = GPIOA->GPIO_INT_RAW_STS & mask ;
    while (real_interrupt_status)
    {
        uint8_t idx = 31 - __builtin_clz(real_interrupt_status);
        if (gpio_isr.gpio_callback[idx])
        {
            gpio_isr.gpio_callback[idx]();
        }
        real_interrupt_status &= ~BIT(idx);
    }
}

/**
 * @brief Dispatch GPIOB pin interrupts to their registered callbacks.
 * @param mask  Bit mask selecting which GPIOB pins (0 to 31) to service.
 */
void GPIOB_Handler(uint32_t mask)
{
    uint32_t real_interrupt_status = GPIOB->GPIO_INT_RAW_STS & mask;
    while (real_interrupt_status)
    {
        uint8_t idx = 31 - __builtin_clz(real_interrupt_status);
        if (gpio_isr.gpio_callback[idx + 32])
        {
            gpio_isr.gpio_callback[idx + 32]();
        }
        real_interrupt_status &= ~BIT(idx);
    }
}

/**
 * @brief Interrupt vector entry for GPIOA pins 0 to 7.
 */
void GPIO0_7_ISR(void)
{
    GPIOA_Handler(0xFF);
}

/**
 * @brief Interrupt vector entry for GPIOA pins 8 to 15.
 */
void GPIO8_15_ISR(void)
{
    GPIOA_Handler(0xFF00);
}

/**
 * @brief Interrupt vector entry for GPIOA pins 16 to 23.
 */
void GPIO16_23_ISR(void)
{
    GPIOA_Handler(0xFF0000);
}

/**
 * @brief Interrupt vector entry for GPIOA pins 24 to 31.
 */
void GPIO24_31_ISR(void)
{
    GPIOA_Handler(0xFF000000);
}

/**
 * @brief Interrupt vector entry for GPIOB pins 0 to 7 (table entries 32 to 39).
 */
void GPIO32_39_ISR(void)
{
    GPIOB_Handler(0xFF);
}

/**
 * @brief Interrupt vector entry for GPIOB pins 8 to 15 (table entries 40 to 47).
 */
void GPIO40_47_ISR(void)
{
    GPIOB_Handler(0xFF00);
}

/**
 * @brief Interrupt vector entry for GPIOB pins 16 to 23 (table entries 48 to 55).
 */
void GPIO48_55_ISR(void)
{
    GPIOB_Handler(0xFF0000);
}

/**
 * @brief Interrupt vector entry for GPIOB pins 24 to 31 (table entries 56 to 63).
 */
void GPIO56_63_ISR(void)
{
    GPIOB_Handler(0xFF000000);
}

/**
 * @brief Install the GPIO interrupt service routines into the RAM vector table.
 */
void GPIO_IRQInit(void)
{
    ram_vector_table_register(GPIOA0_7_IRQn, GPIO_ISRUpdate);
    ram_vector_table_update(GPIOA0_7_IRQn,   GPIO0_7_ISR);
    ram_vector_table_update(GPIOA8_15_IRQn,  GPIO8_15_ISR);
    ram_vector_table_update(GPIOA16_23_IRQn, GPIO16_23_ISR);
    ram_vector_table_update(GPIOA24_31_IRQn, GPIO24_31_ISR);
    ram_vector_table_update(GPIOA32_39_IRQn, GPIO32_39_ISR);
    ram_vector_table_update(GPIOA40_47_IRQn, GPIO40_47_ISR);
    ram_vector_table_update(GPIOA48_55_IRQn, GPIO48_55_ISR);
}



