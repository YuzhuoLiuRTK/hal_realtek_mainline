/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_gpio.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Macros
 *============================================================================*/

/*============================================================================*
 *                           Private Functions
 *============================================================================*/
extern void GPIO_ExtPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
 * @brief Deinitialize the GPIO port registers to their default reset values.
 * @param GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 */
void GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
#ifdef GPIOA
    if (GPIOx == GPIOA)
    {
        RCC_ClockCmd(GPIOA_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOB
    if (GPIOx == GPIOB)
    {
        RCC_ClockCmd(GPIOB_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOC
    if (GPIOx == GPIOC)
    {
        RCC_ClockCmd(GPIOC_CLOCK, DISABLE);
        return;
    }
#endif
#ifdef GPIOD
    if (GPIOx == GPIOD)
    {
        RCC_ClockCmd(GPIOD_CLOCK, DISABLE);
        return;
    }
#endif
}

/**
 * @brief Initialize the GPIO port according to the specified parameters in the GPIO_InitStruct.
 * @param GPIOx            Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
    assert_param(IS_GPIO_DIR(GPIO_InitStruct->GPIO_Dir));
#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    assert_param(IS_GPIO_OUTPUT_MODE(GPIO_InitStruct->GPIO_OutPutMode));
#endif
    assert_param(IS_GPIO_TRIGGER_TYPE(GPIO_InitStruct->GPIO_Trigger));
    assert_param(IS_GPIO_POLARITY_TYPE(GPIO_InitStruct->GPIO_Polarity));
    assert_param(IS_FUNCTIONAL_STATE(GPIO_InitStruct->GPIO_DebounceEn));

    /* GPIO configure */
    if (GPIO_InitStruct->GPIO_Dir == GPIO_DIR_OUT)
    {
        GPIOx->GPIO_DDR |= GPIO_InitStruct->GPIO_Pin;

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
        if (GPIO_InitStruct->GPIO_OutPutMode == GPIO_OUTPUT_OPENDRAIN)
        {
            GPIOx->GPIO_OUT_MODE |= GPIO_InitStruct->GPIO_Pin;
        }
        else
        {
            GPIOx->GPIO_OUT_MODE &= ~(GPIO_InitStruct->GPIO_Pin);
        }
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
        if (GPIO_InitStruct->GPIO_ControlMode == GPIO_SOFTWARE_MODE)
        {
            /* Config GPIOx control software mode */
            GPIOx->GPIO_SRC &= (~GPIO_InitStruct->GPIO_Pin);
        }
        else
        {
            /* Config GPIOx hardware control mode */
            GPIOx->GPIO_SRC |= (GPIO_InitStruct->GPIO_Pin);
        }
#endif
    }
    else
    {
        /*Configure GPIO input mode */
        GPIOx->GPIO_DDR = GPIOx->GPIO_DDR & (~GPIO_InitStruct->GPIO_Pin);

        if (GPIO_InitStruct->GPIO_INTEventEn == ENABLE)
        {
            GPIOx->GPIO_INT_MASK = ~GPIO_Pin_All;

            /* configure GPIO interrupt trigger type */
#if GPIO_SUPPORT_BOTHEDGE
            if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_BOTH_EDGE)
            {
                GPIOx->GPIO_INT_BOTHEDGE |= GPIO_InitStruct->GPIO_Pin;
            }
            else
            {
                GPIOx->GPIO_INT_BOTHEDGE &= ~GPIO_InitStruct->GPIO_Pin;
            }
#endif

            if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_LEVEL)
            {
                GPIOx->GPIO_INT_LV &= ~GPIO_InitStruct->GPIO_Pin;

#if (GPIO_SUPPORT_LS_SYNC == 1)
                /* Level-sensitive synchronization enable register */
                GPIOx->GPIO_LS_SYNC = 0x1;
#endif
            }
            else if (GPIO_InitStruct->GPIO_Trigger == GPIO_TRIGGER_EDGE)
            {
                GPIOx->GPIO_INT_LV |= GPIO_InitStruct->GPIO_Pin;
            }

            /* configure Interrupt polarity register */
            GPIO_ExtPolarity(GPIOx, GPIO_InitStruct->GPIO_Pin, GPIO_InitStruct->GPIO_Polarity);

            /* configure Debounce enable register */
            if (GPIO_InitStruct->GPIO_DebounceEn == ENABLE)
            {
                GPIO_ExtDebUpdate(GPIOx, GPIO_InitStruct->GPIO_Pin,
                                  GPIO_InitStruct->GPIO_DebClockSrc,
                                  GPIO_InitStruct->GPIO_DebClockDiv,
                                  GPIO_InitStruct->GPIO_DebCountLimit);
            }
            GPIO_ExtDebCmd(GPIOx, GPIO_InitStruct->GPIO_Pin,
                           (FunctionalState) GPIO_InitStruct->GPIO_DebounceEn);
        }
    }
}

/**
 * @brief Fill each GPIO_InitStruct member with its default value.
 * @param GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStruct->GPIO_Pin         = GPIO_Pin_All;
    GPIO_InitStruct->GPIO_Dir         = GPIO_DIR_IN;
#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    GPIO_InitStruct->GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
#endif
#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIO_InitStruct->GPIO_ControlMode = GPIO_SOFTWARE_MODE;
#endif
    GPIO_InitStruct->GPIO_INTEventEn  = DISABLE;
    GPIO_InitStruct->GPIO_Trigger     = GPIO_TRIGGER_LEVEL;
    GPIO_InitStruct->GPIO_Polarity    = GPIO_POLARITY_ACTIVE_LOW;

    /* Set GPIO doubonce parameters: set doubonce time is 1ms,
     * debounce time = (CntLimit + 1) * DEB_CLK = 32 / 32000 = 1ms */
    GPIO_InitStruct->GPIO_DebounceEn  = DISABLE;
    GPIO_InitStruct->GPIO_DebClockSrc = GPIO_DEFAULT_DEB_CLOCK_SRC;
    GPIO_InitStruct->GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
    GPIO_InitStruct->GPIO_DebCountLimit = 32;
}

/**
 * @brief Enable or disable the specified GPIO pin interrupt.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param NewState  Enable or disable the specified GPIO pin interrupt.
 */
void GPIO_INTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        /* Enable the selected GPIO pin interrupts */
        GPIOx->GPIO_INT_EN |= GPIO_Pin;
    }
    else
    {
        /* Disable the selected GPIO pin interrupts */
        GPIOx->GPIO_INT_EN &= ~GPIO_Pin;
    }
}

/**
 * @brief Clear the specified GPIO pin interrupt pending bit.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 */
void GPIO_ClearINTPendingBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_INT_CLR = GPIO_Pin;
}

/**
 * @brief Mask or unmask the specified GPIO pin interrupt.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param NewState  Mask or unmask interrupt.
 */
void GPIO_MaskINTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        GPIOx->GPIO_INT_MASK |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_INT_MASK &= ~(GPIO_Pin);
    }
}

/**
 * @brief Get the specified GPIO pin interrupt status.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 * @return The interrupt status of the specified GPIO pin.
 *         - SET    The interrupt status is set.
 *         - RESET  The interrupt status has not been set.
 */
ITStatus GPIO_GetINTStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->GPIO_INT_STS & GPIO_Pin) == GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
 * @brief Read the input value of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 * @return The input value of the specified GPIO pin.
 */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if (GPIOx->GPIO_PAD_STATE & GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
 * @brief Read the input value of the specified GPIO port.
 * @param GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @return The input value of the specified GPIO port.
 */
uint32_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx)
{
    return ((uint32_t)GPIOx->GPIO_PAD_STATE);
}

/**
 * @brief Read the output value of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 * @return The output value of the specified GPIO pin.
 */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if (GPIOx->GPIO_DR & GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/**
 * @brief Read the output value of the specified GPIO port.
 * @param GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @return The output value of the specified GPIO port.
 */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx)
{
    return ((uint32_t)GPIOx->GPIO_DR);
}

/**
 * @brief Set the output value of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_DR |= GPIO_Pin;
}

/**
 * @brief Reset the output value of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    GPIOx->GPIO_DR &= ~(GPIO_Pin);
}

/**
 * @brief Set or reset the output value of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 * @param BitVal    Specifies the value of the specified GPIO pin.
 *                   This parameter can be any value of @ref BitAction.
 */
void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, BitAction BitVal)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));
    assert_param(IS_GPIO_BIT_ACTION(BitVal));

    if (BitVal != Bit_RESET)
    {
        GPIOx->GPIO_DR |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_DR &= ~(GPIO_Pin);
    }
}

/**
 * @brief Set or reset the output value of the specified GPIO port.
 * @param GPIOx    Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param PortVal  Specifies the value of the specified GPIO port.
 */
void GPIO_Write(GPIO_TypeDef *GPIOx, uint32_t PortVal)
{
    GPIOx->GPIO_DR = PortVal;
}

/**
 * @brief Set the GPIO direction of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param GPIO_Dir  Specifies the GPIO direction. Refer to @ref GPIO_DIRECTION.
 */
void GPIO_SetDirection(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODir_TypeDef GPIO_Dir)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (GPIO_Dir == GPIO_DIR_OUT)
    {
        GPIOx->GPIO_DDR |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_DDR &= ~GPIO_Pin;
    }
}

/**
 * @brief Set the GPIO polarity of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param Polarity  Specifies the GPIO polarity. Refer to @ref GPIO_POLARITY.
 */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity)
{
    /* Check the parameters */
    assert_param(IS_GPIO_POLARITY_TYPE(Polarity));

    GPIO_ExtPolarity(GPIOx, GPIO_Pin, Polarity);
}

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
/**
 * @brief Set the GPIO output mode of the specified GPIO pin.
 * @param GPIOx            Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin         Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param GPIO_OutputMode  Specifies the GPIO output mode. Refer to @ref GPIO_OUTPUT_MODE.
 */
void GPIO_SetOutputMode(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                        GPIOOutputMode_TypeDef GPIO_OutputMode)
{
    /* Check the parameters */
    assert_param(IS_GPIO_OUTPUT_MODE(GPIO_OutputMode));

    /* configure Interrupt polarity register */
    if (GPIO_OutputMode == GPIO_OUTPUT_OPENDRAIN)
    {
        GPIOx->GPIO_OUT_MODE = (GPIOx->GPIO_OUT_MODE & (~GPIO_Pin)) | GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_OUT_MODE &= (~GPIO_Pin);
    }
}
#endif

/**
 * @brief Get the PAD status of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @return The PAD status of the specified GPIO pin.
 */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    /* Check the parameters */
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->GPIO_PAD_STATE & GPIO_Pin) == GPIO_Pin)
    {
        return SET;
    }
    else
    {
        return RESET;
    }
}

/*============================================================================*
 *                        RAP Functions
 *============================================================================*/
#if (GPIO_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the RAP mode of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param NewState  Enable or disable the RAP mode.
 */
void GPIO_RAPModeCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (NewState != DISABLE)
    {
        GPIOx->GPIO_RAP_CTL |= GPIO_Pin;
    }
    else
    {
        GPIOx->GPIO_RAP_CTL &= ~GPIO_Pin;
    }
    return;
}

/**
 * @brief Trigger the GPIO action of the specified GPIO pin.
 * @param GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param Action    Specifies the action to be triggered. Refer to @ref GPIO_ACTION.
 */
void GPIO_ActionTrigger(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint32_t Action)
{
    /* Check the parameters */
    assert_param(IS_GPIO_PIN(GPIO_Pin));

    if (Action == GPIO_ACTION_DRSET)
    {
        GPIOx->GPIO_RAP_TASK_DRSET |= GPIO_Pin;
    }
    else if (Action == GPIO_ACTION_DRCLR)
    {
        GPIOx->GPIO_RAP_TASK_DRCLR |= GPIO_Pin;
    }
    else if (Action == GPIO_ACTION_DRTOGGLE)
    {
        GPIOx->GPIO_RAP_TASK_DRTOGGLE |= GPIO_Pin;
    }
    return;
}
#endif


