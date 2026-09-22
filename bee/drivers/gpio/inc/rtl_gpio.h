/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GPIO_H
#define RTL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "gpio/src/device/rtl87x2g/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x2g/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "gpio/src/device/rtl87x3d/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3d/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "gpio/src/device/rtl87x2j/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x2j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "gpio/src/device/rtl87x3j/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3j/pin_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "gpio/src/device/rtl87x3k/rtl_gpio_def.h"
#include "pinmux/inc/rtl87x3k/pin_def.h"
#endif

/**
 * @defgroup GPIO_DRIVER DRIVER
 * @ingroup GPIO
 * @brief General Purpose Input/Output (GPIO) driver.
 * @{
 */

/**
 * @defgroup GPIO_Exported_Constants GPIO Exported Constants
 * @{
 */

/**
 * @defgroup GPIO_NUMBER GPIO Number
 * @{
 * @ingroup GPIO_Exported_Constants
 */
#ifdef GPIOA
#define GPIOA0   0     /**< GPIOA0 corresponding number is 0. */
#define GPIOA1   1     /**< GPIOA1 corresponding number is 1. */
#define GPIOA2   2     /**< GPIOA2 corresponding number is 2. */
#define GPIOA3   3     /**< GPIOA3 corresponding number is 3. */
#define GPIOA4   4     /**< GPIOA4 corresponding number is 4. */
#define GPIOA5   5     /**< GPIOA5 corresponding number is 5. */
#define GPIOA6   6     /**< GPIOA6 corresponding number is 6. */
#define GPIOA7   7     /**< GPIOA7 corresponding number is 7. */
#define GPIOA8   8     /**< GPIOA8 corresponding number is 8. */
#define GPIOA9   9     /**< GPIOA9 corresponding number is 9. */
#define GPIOA10  10    /**< GPIOA10 corresponding number is 10. */
#define GPIOA11  11    /**< GPIOA11 corresponding number is 11. */
#define GPIOA12  12    /**< GPIOA12 corresponding number is 12. */
#define GPIOA13  13    /**< GPIOA13 corresponding number is 13. */
#define GPIOA14  14    /**< GPIOA14 corresponding number is 14. */
#define GPIOA15  15    /**< GPIOA15 corresponding number is 15. */
#define GPIOA16  16    /**< GPIOA16 corresponding number is 16. */
#define GPIOA17  17    /**< GPIOA17 corresponding number is 17. */
#define GPIOA18  18    /**< GPIOA18 corresponding number is 18. */
#define GPIOA19  19    /**< GPIOA19 corresponding number is 19. */
#define GPIOA20  20    /**< GPIOA20 corresponding number is 20. */
#define GPIOA21  21    /**< GPIOA21 corresponding number is 21. */
#define GPIOA22  22    /**< GPIOA22 corresponding number is 22. */
#define GPIOA23  23    /**< GPIOA23 corresponding number is 23. */
#define GPIOA24  24    /**< GPIOA24 corresponding number is 24. */
#define GPIOA25  25    /**< GPIOA25 corresponding number is 25. */
#define GPIOA26  26    /**< GPIOA26 corresponding number is 26. */
#define GPIOA27  27    /**< GPIOA27 corresponding number is 27. */
#define GPIOA28  28    /**< GPIOA28 corresponding number is 28. */
#define GPIOA29  29    /**< GPIOA29 corresponding number is 29. */
#define GPIOA30  30    /**< GPIOA30 corresponding number is 30. */
#define GPIOA31  31    /**< GPIOA31 corresponding number is 31. */
#endif
#ifdef GPIOB
#define GPIOB0   32    /**< GPIOB0 corresponding number is 32. */
#define GPIOB1   33    /**< GPIOB1 corresponding number is 33. */
#define GPIOB2   34    /**< GPIOB2 corresponding number is 34. */
#define GPIOB3   35    /**< GPIOB3 corresponding number is 35. */
#define GPIOB4   36    /**< GPIOB4 corresponding number is 36. */
#define GPIOB5   37    /**< GPIOB5 corresponding number is 37. */
#define GPIOB6   38    /**< GPIOB6 corresponding number is 38. */
#define GPIOB7   39    /**< GPIOB7 corresponding number is 39. */
#define GPIOB8   40    /**< GPIOB8 corresponding number is 40. */
#define GPIOB9   41    /**< GPIOB9 corresponding number is 41. */
#define GPIOB10  42    /**< GPIOB10 corresponding number is 42. */
#define GPIOB11  43    /**< GPIOB11 corresponding number is 43. */
#define GPIOB12  44    /**< GPIOB12 corresponding number is 44. */
#define GPIOB13  45    /**< GPIOB13 corresponding number is 45. */
#define GPIOB14  46    /**< GPIOB14 corresponding number is 46. */
#define GPIOB15  47    /**< GPIOB15 corresponding number is 47. */
#define GPIOB16  48    /**< GPIOB16 corresponding number is 48. */
#define GPIOB17  49    /**< GPIOB17 corresponding number is 49. */
#define GPIOB18  50    /**< GPIOB18 corresponding number is 50. */
#define GPIOB19  51    /**< GPIOB19 corresponding number is 51. */
#define GPIOB20  52    /**< GPIOB20 corresponding number is 52. */
#define GPIOB21  53    /**< GPIOB21 corresponding number is 53. */
#define GPIOB22  54    /**< GPIOB22 corresponding number is 54. */
#define GPIOB23  55    /**< GPIOB23 corresponding number is 55. */
#define GPIOB24  56    /**< GPIOB24 corresponding number is 56. */
#define GPIOB25  57    /**< GPIOB25 corresponding number is 57. */
#define GPIOB26  58    /**< GPIOB26 corresponding number is 58. */
#define GPIOB27  59    /**< GPIOB27 corresponding number is 59. */
#define GPIOB28  60    /**< GPIOB28 corresponding number is 60. */
#define GPIOB29  61    /**< GPIOB29 corresponding number is 61. */
#define GPIOB30  62    /**< GPIOB30 corresponding number is 62. */
#define GPIOB31  63    /**< GPIOB31 corresponding number is 63. */
#endif
#ifdef GPIOC
#define GPIOC0   64    /**< GPIOC0 corresponding number is 64. */
#define GPIOC1   65    /**< GPIOC1 corresponding number is 65. */
#define GPIOC2   66    /**< GPIOC2 corresponding number is 66. */
#define GPIOC3   67    /**< GPIOC3 corresponding number is 67. */
#define GPIOC4   68    /**< GPIOC4 corresponding number is 68. */
#define GPIOC5   69    /**< GPIOC5 corresponding number is 69. */
#define GPIOC6   70    /**< GPIOC6 corresponding number is 70. */
#define GPIOC7   71    /**< GPIOC7 corresponding number is 71. */
#define GPIOC8   72    /**< GPIOC8 corresponding number is 72. */
#define GPIOC9   73    /**< GPIOC9 corresponding number is 73. */
#define GPIOC10  74    /**< GPIOC10 corresponding number is 74. */
#define GPIOC11  75    /**< GPIOC11 corresponding number is 75. */
#define GPIOC12  76    /**< GPIOC12 corresponding number is 76. */
#define GPIOC13  77    /**< GPIOC13 corresponding number is 77. */
#define GPIOC14  78    /**< GPIOC14 corresponding number is 78. */
#define GPIOC15  79    /**< GPIOC15 corresponding number is 79. */
#define GPIOC16  80    /**< GPIOC16 corresponding number is 80. */
#define GPIOC17  81    /**< GPIOC17 corresponding number is 81. */
#define GPIOC18  82    /**< GPIOC18 corresponding number is 82. */
#define GPIOC19  83    /**< GPIOC19 corresponding number is 83. */
#define GPIOC20  84    /**< GPIOC20 corresponding number is 84. */
#define GPIOC21  85    /**< GPIOC21 corresponding number is 85. */
#define GPIOC22  86    /**< GPIOC22 corresponding number is 86. */
#define GPIOC23  87    /**< GPIOC23 corresponding number is 87. */
#define GPIOC24  88    /**< GPIOC24 corresponding number is 88. */
#define GPIOC25  89    /**< GPIOC25 corresponding number is 89. */
#define GPIOC26  90    /**< GPIOC26 corresponding number is 90. */
#define GPIOC27  91    /**< GPIOC27 corresponding number is 91. */
#define GPIOC28  92    /**< GPIOC28 corresponding number is 92. */
#define GPIOC29  93    /**< GPIOC29 corresponding number is 93. */
#define GPIOC30  94    /**< GPIOC30 corresponding number is 94. */
#define GPIOC31  95    /**< GPIOC31 corresponding number is 95. */
#endif
#ifdef GPIOD
#define GPIOD0   96    /**< GPIOD0 corresponding number is 96. */
#define GPIOD1   97    /**< GPIOD1 corresponding number is 97. */
#define GPIOD2   98    /**< GPIOD2 corresponding number is 98. */
#define GPIOD3   99    /**< GPIOD3 corresponding number is 99. */
#define GPIOD4   100   /**< GPIOD4 corresponding number is 100. */
#define GPIOD5   101   /**< GPIOD5 corresponding number is 101. */
#define GPIOD6   102   /**< GPIOD6 corresponding number is 102. */
#define GPIOD7   103   /**< GPIOD7 corresponding number is 103. */
#define GPIOD8   104   /**< GPIOD8 corresponding number is 104. */
#define GPIOD9   105   /**< GPIOD9 corresponding number is 105. */
#define GPIOD10  106   /**< GPIOD10 corresponding number is 106. */
#define GPIOD11  107   /**< GPIOD11 corresponding number is 107. */
#define GPIOD12  108   /**< GPIOD12 corresponding number is 108. */
#define GPIOD13  109   /**< GPIOD13 corresponding number is 109. */
#define GPIOD14  110   /**< GPIOD14 corresponding number is 110. */
#define GPIOD15  111   /**< GPIOD15 corresponding number is 111. */
#define GPIOD16  112   /**< GPIOD16 corresponding number is 112. */
#define GPIOD17  113   /**< GPIOD17 corresponding number is 113. */
#define GPIOD18  114   /**< GPIOD18 corresponding number is 114. */
#define GPIOD19  115   /**< GPIOD19 corresponding number is 115. */
#define GPIOD20  116   /**< GPIOD20 corresponding number is 116. */
#define GPIOD21  117   /**< GPIOD21 corresponding number is 117. */
#define GPIOD22  118   /**< GPIOD22 corresponding number is 118. */
#define GPIOD23  119   /**< GPIOD23 corresponding number is 119. */
#define GPIOD24  120   /**< GPIOD24 corresponding number is 120. */
#define GPIOD25  121   /**< GPIOD25 corresponding number is 121. */
#define GPIOD26  122   /**< GPIOD26 corresponding number is 122. */
#define GPIOD27  123   /**< GPIOD27 corresponding number is 123. */
#define GPIOD28  124   /**< GPIOD28 corresponding number is 124. */
#define GPIOD29  125   /**< GPIOD29 corresponding number is 125. */
#define GPIOD30  126   /**< GPIOD30 corresponding number is 126. */
#define GPIOD31  127   /**< GPIOD31 corresponding number is 127. */
#endif

/** @} */ /* End of group GPIO_NUMBER */

/**
 * @defgroup GPIO_PINS_DEFINE GPIO Pins Define
 * @{
 * @ingroup GPIO_Exported_Constants
 */
#define GPIO_Pin_0                 (BIT0)   /**< GPIO Pin 0 selected. */
#define GPIO_Pin_1                 (BIT1)   /**< GPIO Pin 1 selected. */
#define GPIO_Pin_2                 (BIT2)   /**< GPIO Pin 2 selected. */
#define GPIO_Pin_3                 (BIT3)   /**< GPIO Pin 3 selected. */
#define GPIO_Pin_4                 (BIT4)   /**< GPIO Pin 4 selected. */
#define GPIO_Pin_5                 (BIT5)   /**< GPIO Pin 5 selected. */
#define GPIO_Pin_6                 (BIT6)   /**< GPIO Pin 6 selected. */
#define GPIO_Pin_7                 (BIT7)   /**< GPIO Pin 7 selected. */
#define GPIO_Pin_8                 (BIT8)   /**< GPIO Pin 8 selected. */
#define GPIO_Pin_9                 (BIT9)   /**< GPIO Pin 9 selected. */
#define GPIO_Pin_10                (BIT10)  /**< GPIO Pin 10 selected. */
#define GPIO_Pin_11                (BIT11)  /**< GPIO Pin 11 selected. */
#define GPIO_Pin_12                (BIT12)  /**< GPIO Pin 12 selected. */
#define GPIO_Pin_13                (BIT13)  /**< GPIO Pin 13 selected. */
#define GPIO_Pin_14                (BIT14)  /**< GPIO Pin 14 selected. */
#define GPIO_Pin_15                (BIT15)  /**< GPIO Pin 15 selected. */
#define GPIO_Pin_16                (BIT16)  /**< GPIO Pin 16 selected. */
#define GPIO_Pin_17                (BIT17)  /**< GPIO Pin 17 selected. */
#define GPIO_Pin_18                (BIT18)  /**< GPIO Pin 18 selected. */
#define GPIO_Pin_19                (BIT19)  /**< GPIO Pin 19 selected. */
#define GPIO_Pin_20                (BIT20)  /**< GPIO Pin 20 selected. */
#define GPIO_Pin_21                (BIT21)  /**< GPIO Pin 21 selected. */
#define GPIO_Pin_22                (BIT22)  /**< GPIO Pin 22 selected. */
#define GPIO_Pin_23                (BIT23)  /**< GPIO Pin 23 selected. */
#define GPIO_Pin_24                (BIT24)  /**< GPIO Pin 24 selected. */
#define GPIO_Pin_25                (BIT25)  /**< GPIO Pin 25 selected. */
#define GPIO_Pin_26                (BIT26)  /**< GPIO Pin 26 selected. */
#define GPIO_Pin_27                (BIT27)  /**< GPIO Pin 27 selected. */
#define GPIO_Pin_28                (BIT28)  /**< GPIO Pin 28 selected. */
#define GPIO_Pin_29                (BIT29)  /**< GPIO Pin 29 selected. */
#define GPIO_Pin_30                (BIT30)  /**< GPIO Pin 30 selected. */
#define GPIO_Pin_31                (BIT31)  /**< GPIO Pin 31 selected. */
#define GPIO_Pin_All               ((uint32_t)0xFFFFFFFF)  /**< All pins selected. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GET_GPIO_PIN(PIN)       (((PIN) == GPIO_Pin_0) || \
                                    ((PIN) == GPIO_Pin_1) || \
                                    ((PIN) == GPIO_Pin_2) || \
                                    ((PIN) == GPIO_Pin_3) || \
                                    ((PIN) == GPIO_Pin_4) || \
                                    ((PIN) == GPIO_Pin_5) || \
                                    ((PIN) == GPIO_Pin_6) || \
                                    ((PIN) == GPIO_Pin_7) || \
                                    ((PIN) == GPIO_Pin_8) || \
                                    ((PIN) == GPIO_Pin_9) || \
                                    ((PIN) == GPIO_Pin_10) || \
                                    ((PIN) == GPIO_Pin_11) || \
                                    ((PIN) == GPIO_Pin_12) || \
                                    ((PIN) == GPIO_Pin_13) || \
                                    ((PIN) == GPIO_Pin_14) || \
                                    ((PIN) == GPIO_Pin_15) || \
                                    ((PIN) == GPIO_Pin_16) || \
                                    ((PIN) == GPIO_Pin_17) || \
                                    ((PIN) == GPIO_Pin_18) || \
                                    ((PIN) == GPIO_Pin_19) || \
                                    ((PIN) == GPIO_Pin_20) || \
                                    ((PIN) == GPIO_Pin_21) || \
                                    ((PIN) == GPIO_Pin_22) || \
                                    ((PIN) == GPIO_Pin_23) || \
                                    ((PIN) == GPIO_Pin_24) || \
                                    ((PIN) == GPIO_Pin_25) || \
                                    ((PIN) == GPIO_Pin_26) || \
                                    ((PIN) == GPIO_Pin_27) || \
                                    ((PIN) == GPIO_Pin_28) || \
                                    ((PIN) == GPIO_Pin_29) || \
                                    ((PIN) == GPIO_Pin_30) || \
                                    ((PIN) == GPIO_Pin_31) || \
                                    ((PIN) == GPIO_Pin_All))

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_PIN(PIN)          ((PIN) != (uint32_t)0x00)

/** @} */ /* End of group GPIO_PINS_DEFINE */

/**
 * @defgroup GPIO_BIT_ACTION GPIO Bit Action
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    Bit_RESET = 0, /**< Reset the GPIO bit. */
    Bit_SET        /**< Set the GPIO bit. */
} BitAction;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))

/** @} */ /* End of group GPIO_BIT_ACTION */

/**
 * @defgroup GPIO_DIRECTION GPIO Direction
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_DIR_IN   = 0x0, /**< GPIO input direction. */
    GPIO_DIR_OUT  = 0x1, /**< GPIO output direction. */
} GPIODir_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_DIR(DIR) (((DIR) == GPIO_DIR_IN) || ((DIR) == GPIO_DIR_OUT))

/** @} */ /* End of group GPIO_DIRECTION */

/**
 * @defgroup GPIO_OUTPUT_MODE GPIO Output Mode
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_OUTPUT_PUSHPULL  = 0x0, /**< GPIO output push-pull mode. */
    GPIO_OUTPUT_OPENDRAIN = 0x1, /**< GPIO output open-drain mode. */
} GPIOOutputMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_OUTPUT_MODE(MODE) (((MODE) == GPIO_OUTPUT_PUSHPULL)|| \
                                   ((MODE) == GPIO_OUTPUT_OPENDRAIN))

/** @} */ /* End of group GPIO_OUTPUT_MODE */

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
/**
 * @defgroup GPIO_CONTROL_MODE GPIO Control Mode
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_SOFTWARE_MODE = 0x0,  /**< GPIO software control mode. */
    GPIO_HARDWARE_MODE  = 0x1, /**< GPIO hardware control mode. */
} GPIOControlMode_Typedef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_CONTROL_MODDE(MODE) (((MODE) == GPIO_SOFTWARE_MODE) || \
                                     ((MODE) == GPIO_HARDWARE_MODE))

/** @} */ /* End of group GPIO_CONTROL_MODE */
#endif

/**
 * @defgroup GPIO_TRIGGER GPIO Trigger
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_TRIGGER_LEVEL = 0x0,     /**< GPIO trigger mode is level trigger. */
    GPIO_TRIGGER_EDGE  = 0x1,     /**< GPIO trigger mode is edge trigger. */
#if (GPIO_SUPPORT_BOTHEDGE == 1)
    GPIO_TRIGGER_BOTH_EDGE = 0x2, /**< GPIO trigger mode is both edge trigger. */
#endif
} GPIOTrigger_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_TRIGGER_TYPE(TYPE) (((TYPE) == GPIO_TRIGGER_LEVEL) || \
                                    ((TYPE) == GPIO_TRIGGER_EDGE))

/** @} */ /* End of group GPIO_TRIGGER */

/**
 * @defgroup GPIO_POLARITY GPIO Polarity
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_POLARITY_ACTIVE_LOW  = 0x0, /**< GPIO polarity is low active. */
    GPIO_POLARITY_ACTIVE_HIGH = 0x1, /**< GPIO polarity is high active. */
} GPIOPolarity_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_POLARITY_TYPE(TYPE) (((TYPE) == GPIO_POLARITY_ACTIVE_LOW) || \
                                     ((TYPE) == GPIO_POLARITY_ACTIVE_HIGH))

/** @} */ /* End of group GPIO_POLARITY */

#if (GPIO_SUPPORT_RAP_FUNCTION == 1)
/**
 * @defgroup GPIO_ACTION GPIO Action
 * @{
 * @ingroup GPIO_Exported_Constants
 */
typedef enum
{
    GPIO_ACTION_DRSET = 0,    /**< GPIO action data register set. */
    GPIO_ACTION_DRCLR = 1,    /**< GPIO action data register clear. */
    GPIO_ACTION_DRTOGGLE = 2, /**< GPIO action data register toggle. */
} GPIOAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_GPIO_ACTION_TYPE(TYPE) (((TYPE) == GPIO_ACTION_DRSET) || \
                                   ((TYPE) == GPIO_ACTION_DRCLR) || \
                                   ((TYPE) == GPIO_ACTION_DRTOGGLE))

/** @} */ /* End of group GPIO_ACTION */
#endif

/** @} */ /* End of group GPIO_Exported_Constants */

/**
 * @defgroup GPIO_Exported_Types GPIO Exported Types
 * @{
 */

/**
 * @defgroup GPIO_INIT_STRUCT GPIO Init Structure
 * @{
 * @ingroup GPIO_Exported_Types
 */
typedef struct
{

    uint32_t                GPIO_Pin;           /**< Specifies the GPIO pins to be configured.
                                                     This parameter can be any value of @ref GPIO_PINS_DEFINE. */

    GPIODir_TypeDef         GPIO_Dir;           /**< Specifies the GPIO direction.
                                                     This parameter can be any value of @ref GPIO_DIRECTION. */

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
    GPIOOutputMode_TypeDef  GPIO_OutPutMode;    /**< Specifies the GPIO output mode.
                                                     This parameter can be any value of @ref GPIO_OUTPUT_MODE. */
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIOControlMode_Typedef GPIO_ControlMode;   /**< Specifies the GPIO control mode.
                                                     This parameter can be any value of @ref GPIO_CONTROL_MODE. */
#endif

    FunctionalState         GPIO_INTEventEn;    /**< Enable or disable GPIO interrupt.
                                                     This parameter can be any value of ENABLE or DISABLE. */

    GPIOTrigger_TypeDef     GPIO_Trigger;       /**< Specifies the GPIO trigger.
                                                     This parameter can be any value of @ref GPIO_TRIGGER. */

    GPIOPolarity_TypeDef    GPIO_Polarity;      /**< Specifies the GPIO polarity.
                                                     This parameter can be any value of @ref GPIO_POLARITY. */

    FunctionalState         GPIO_DebounceEn;    /**< Enable or disable debounce.
                                                     This parameter can be any value of ENABLE or DISABLE. */

    GPIODebClockSrc_TypeDef GPIO_DebClockSrc;   /**< Specifies the debounce clock source.
                                                     This parameter can be any value of @ref GPIO_DEBOUNCE_SOURCE. */

    GPIODebClockDiv_TypeDef GPIO_DebClockDiv;   /**< Specifies the debounce clock divider.
                                                     This parameter can be any value of @ref GPIO_DEBOUNCE_DIVIDE. */

    uint8_t                 GPIO_DebCountLimit; /**< Specifies the debounce count limit.
                                                     This parameter valid value range is from 0 to 255.

                                                     This value is used to configure the GPIO debounce time, which is calculated as:
                                                     T_debounce = 2 * T2 + (CountLimit + 1) * T2,
                                                     where T2 is the debounce clock period after division, given by:
                                                     T2 = (1 / GPIO_DebClockSrc) * GPIO_DebClockDiv. */


} GPIO_InitTypeDef;

/** @} */ /* End of group GPIO_INIT_STRUCT */

/** @} */ /* End of group GPIO_Exported_Types */

/**
 * @defgroup GPIO_Exported_Functions GPIO Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the GPIO port registers to their default reset values.
 *
 * @param[in] GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     GPIO_DeInit(GPIOA);
 * }
 * @endcode
 */
void GPIO_DeInit(GPIO_TypeDef *GPIOx);

/**
 * @brief Initialize the GPIO port according to the specified parameters in the GPIO_InitStruct.
 *
 * @param[in] GPIOx            Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_ClockCmd(GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_INTEventEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_Trigger     = GPIO_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_Polarity    = GPIO_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_DebounceEn  = ENABLE;
 *     GPIO_InitStruct.GPIO_DebClockSrc = GPIO_DEB_CLOCK_SRC_32K;
 *     GPIO_InitStruct.GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
 *     GPIO_InitStruct.GPIO_DebCountLimit = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = GPIOA0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 * }
 * @endcode
 */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * @brief Fill each GPIO_InitStruct member with its default value.
 *
 * @note The default settings for the GPIO_InitStruct member are shown in the following table:
 *       | GPIO_InitStruct member          | Default value                         |
 *       |:-------------------------------:|:-------------------------------------:|
 *       | GPIO_Pin                        | @ref GPIO_Pin_All                     |
 *       | GPIO_Dir                        | @ref GPIO_DIR_IN                      |
 *       | GPIO_OutPutMode                 | @ref GPIO_OUTPUT_PUSHPULL             |
 *       | GPIO_INTEventEn                 | DISABLE                               |
 *       | GPIO_Trigger                    | @ref GPIO_TRIGGER_LEVEL               |
 *       | GPIO_Polarity                   | @ref GPIO_POLARITY_ACTIVE_LOW         |
 *       | GPIO_DebounceEn                 | DISABLE                               |
 *       | GPIO_DebClockSrc                | @ref GPIO_DEB_CLOCK_SRC_32K           |
 *       | GPIO_DebClockDiv                | @ref GPIO_DEB_CLOCK_DIV_1             |
 *       | GPIO_DebCountLimit              | 32                                    |
 *
 * @param[in] GPIO_InitStruct  Pointer to a GPIO_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_ClockCmd(GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin        = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir        = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_INTEventEn = ENABLE;
 *     GPIO_InitStruct.GPIO_Trigger    = GPIO_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_Polarity   = GPIO_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_DebounceEn = ENABLE;
 *     GPIO_InitStruct.GPIO_DebClockSrc = GPIO_DEB_CLOCK_SRC_32K;
 *     GPIO_InitStruct.GPIO_DebClockDiv = GPIO_DEB_CLOCK_DIV_1;
 *     GPIO_InitStruct.GPIO_DebCountLimit = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 * }
 * @endcode
 */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * @brief Enable or disable the specified GPIO pin interrupt.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable the specified GPIO pin interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void GPIO_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     // User Code
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_INTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Clear the specified GPIO pin interrupt pending bit.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void GPIO_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     // User Code
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_ClearINTPendingBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Mask or unmask the specified GPIO pin interrupt.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Mask or unmask interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void GPIO_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     // User Code
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_MaskINTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Get the specified GPIO pin interrupt status.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The interrupt status of the specified GPIO pin.
 * @retval SET    The interrupt status is set.
 * @retval RESET  The interrupt status is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     ITStatus int_status = GPIO_GetINTStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
ITStatus GPIO_GetINTStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Read the input value of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The input value of the specified GPIO pin.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t input_bit_value = GPIO_ReadInputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Read the input value of the specified GPIO port.
 *
 * @param[in] GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 *
 * @return The input value of the specified GPIO port.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t input_value = GPIO_ReadInputData(GPIOA);
 * }
 * @endcode
 */
uint32_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx);

/**
 * @brief Read the output value of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be read. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The output value of the specified GPIO pin.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t output_bit_value = GPIO_ReadOutputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Read the output value of the specified GPIO port.
 *
 * @param[in] GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 *
 * @return The output value of the specified GPIO port.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t output_value = GPIO_ReadOutputData(GPIOA);
 * }
 * @endcode
 */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx);

/**
 * @brief Set the output value of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Reset the output value of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ResetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Set or reset the output value of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be written. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] BitVal    Specifies the value of the specified GPIO pin.
 *                      This parameter can be any value of @ref BitAction.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_WriteBit(GPIOA, GPIO_GetPinBit(P0_0), Bit_SET);
 * }
 * @endcode
 */
void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, BitAction BitVal);

/**
 * @brief Set or reset the output value of the specified GPIO port.
 *
 * @param[in] GPIOx    Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] PortVal  Specifies the value of the specified GPIO port.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_Write(GPIOA, 0xFFFFFFFF);
 * }
 * @endcode
 */
void GPIO_Write(GPIO_TypeDef *GPIOx, uint32_t PortVal);

/**
 * @brief Set the GPIO direction of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] GPIO_Dir  Specifies the GPIO direction. Refer to @ref GPIO_DIRECTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetDirection(GPIOA, GPIO_GetPinBit(P0_0), GPIO_DIR_IN);
 * }
 * @endcode
 */
void GPIO_SetDirection(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIODir_TypeDef GPIO_Dir);

/**
 * @brief Set the GPIO polarity of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] Polarity  Specifies the GPIO polarity. Refer to @ref GPIO_POLARITY.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetPolarity(GPIOA, GPIO_GetPinBit(P0_0), GPIO_POLARITY_ACTIVE_LOW);
 * }
 * @endcode
 */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIOPolarity_TypeDef Polarity);

#if (GPIO_SUPPORT_OUTPUT_MODE_SELECT == 1)
/**
 * @brief Set the GPIO output mode of the specified GPIO pin.
 *
 * @param[in] GPIOx            Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin         Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] GPIO_OutputMode  Specifies the GPIO output mode. Refer to @ref GPIO_OUTPUT_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetOutputMode(GPIOA, GPIO_GetPinBit(P0_0), GPIO_OUTPUT_OPENDRAIN);
 * }
 * @endcode
 */
void GPIO_SetOutputMode(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                        GPIOOutputMode_TypeDef GPIO_OutputMode);
#endif

/**
 * @brief Get the PAD status of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The PAD status of the specified GPIO pin.
 * @retval SET    The PAD status is set.
 * @retval RESET  The PAD status is not set.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus pad_status = GPIO_GetPadStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * @endcode
 */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Enable or disable the debounce function and clock of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable GPIO debounce function and clock.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebCmd(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_ExtDebCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Set the GPIO debounce parameters of the specified GPIO pin.
 *
 * @param[in]  GPIOx               Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in]  GPIO_Pin            Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in]  GPIO_DebClockSrc    Specifies the GPIO debounce clock source. Refer to @ref GPIO_DEBOUNCE_SOURCE.
 * @param[in]  GPIO_DebClockDiv    Specifies the GPIO debounce clock divider. Refer to @ref GPIO_DEBOUNCE_DIVIDE.
 * @param[in]  GPIO_DebCountLimit  Specifies the debounce count limit.
 *                                 This parameter valid value range is from 0 to 255.
 *                                 This value is used to configure the GPIO debounce time, which is calculated as:
 *                                 T_debounce = 2 * T2 + (CountLimit + 1) * T2,
 *                                 where T2 is the debounce clock period after division, given by:
 *                                 T2 = (1 / GPIO_DebClockSrc) * GPIO_DebClockDiv.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebUpdate(GPIOA, GPIO_GetPinBit(P0_0), GPIO_DEB_CLOCK_SRC_32K, GPIO_DEB_CLOCK_DIV_1, 20);
 * }
 * @endcode
 */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebClockSrc_TypeDef GPIO_DebClockSrc,
                       GPIODebClockDiv_TypeDef GPIO_DebClockDiv,
                       uint8_t                 GPIO_DebCountLimit);

/**
 * @brief Get the GPIO port through the given PAD.
 *
 * @param[in] Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The GPIO port (e.g. GPIOA, GPIOB). Refer to @ref GPIO_DECLARATION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *      GPIO_TypeDef *gpio_port = GPIO_GetPort(P0_0);
 * }
 *
 * @endcode
 */
GPIO_TypeDef *GPIO_GetPort(uint8_t Pin_num);

/**
 * @brief Get the GPIO pin bit through the given PAD.
 *
 * @param[in]  Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The GPIO pin bit (e.g. GPIO_Pin_0). Refer to @ref GPIO_PINS_DEFINE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t gpio_pin_bit = GPIO_GetPinBit(P0_0);
 * }
 * @endcode
 */
uint32_t GPIO_GetPinBit(uint8_t Pin_num);

/**
 * @brief Get the GPIO number through the given PAD.
 *
 * @param[in] Pin_num  Specifies the pin number to be configured. Refer to @ref Pin_Number.
 *
 * @return The GPIO number (e.g. GPIOA0, GPIOA1). Refer to @ref GPIO_NUMBER.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t gpio_num = GPIO_GetNum(P0_0);
 * }
 * @endcode
 */
uint8_t GPIO_GetNum(uint8_t Pin_num);


#if (GPIO_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Enable or disable the RAP mode of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable the RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_RAPModeCmd(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_RAPModeCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Trigger the GPIO action of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] Action    Specifies the action to be triggered. Refer to @ref GPIO_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ActionTrigger(GPIOA, GPIO_GetPinBit(P0_0), GPIO_ACTION_DRSET);
 * }
 * @endcode
 */
void GPIO_ActionTrigger(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, uint32_t Action);

#if (GPIO_SUPPORT_RAP_EVENT_CONTROL == 1)
/**
 * @brief Enable or disable the RAP event of the specified GPIO pin.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable RAP event.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_RAPEventCmd(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * @endcode
 */
void GPIO_RAPEventCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);
#endif
#endif

#if (GPIO_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable GPIO clock auto mode of the specified GPIO port.
 *
 * @param[in] GPIOx    Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] Newstate Enable or disable the clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ClockAutoModeCmd(GPIOA, ENABLE);
 * }
 * @endcode
 */
void GPIO_ClockAutoModeCmd(GPIO_TypeDef *GPIOx, FunctionalState Newstate);

#endif

#if (GPIO_SUPPORT_WAKE_UP_FUNCTION == 1)
/**
 * @brief Enable or disable the GPIO wake up function.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable the wake up function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_WakeUpConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 *
 * @endcode
 */
void GPIO_WakeUpConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Check whether the specified input GPIO pin is in debounce.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The new state of debounce status.
 * @retval SET    The specified GPIO pin is in debounce.
 * @retval RESET  The specified GPIO pin is not in debounce.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus flag = GPIO_GetDebStatusBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 *
 * @endcode
 */
FlagStatus GPIO_GetDebStatusBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Check whether any pin under the GPIO is in debounce.
 *
 * @param[in] GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 *
 * @return The new state of debounce status.
 * @retval SET    Any pin under the GPIO is in debounce.
 * @retval RESET  No pin under the GPIO is in debounce.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus flag = GPIO_GetDebStatus(GPIOA);
 * }
 *
 * @endcode
 */
FlagStatus GPIO_GetDebStatus(GPIO_TypeDef *GPIOx);
#endif

#if (GPIO_SUPPORT_SELF_TRIGGER_FUNCTION == 1)
/**
 * @brief Enable or disable the GPIO self-trigger function.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable the self-trigger function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SelfTriggerConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 *
 * @endcode
 */
void GPIO_SelfTriggerConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);
#endif

#if (GPIO_SUPPORT_INPUT_GATE_FUNCTION == 1)
/**
 * @brief Enable or disable the GPIO input gate function.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 * @param[in] NewState  Enable or disable the input gate function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     GPIO_InputGateConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 * }
 *
 * @endcode
 */
void GPIO_InputGateConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * @brief Check whether input is gate.
 *
 * @param[in] GPIOx     Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 * @param[in] GPIO_Pin  Specifies the GPIO pins to be configured. Refer to @ref GPIO_PINS_DEFINE.
 *
 * @return The new state of input gate.
 * @retval SET    Input is gated.
 * @retval RESET  Input is not gated.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus ret = GPIO_IsInputGate(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 *
 * @endcode
 */
FlagStatus GPIO_IsInputGate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
#endif

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
/**
 * @brief Get the GPIO hardware port address.
 *
 * @param[in] GPIOx  Specifies the GPIO port. Refer to @ref GPIO_DECLARATION.
 *
 * @return The GPIO hardware port address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     uint32_t address = GPIO_GetHWPortAddress(GPIOA);
 * }
 *
 * @endcode
 */
uint32_t GPIO_GetHWPortAddress(GPIO_TypeDef *GPIOx);
#endif

/** @} */ /* End of group GPIO_Exported_Functions */

/** @} */ /* End of group GPIO_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GPIO_H */
