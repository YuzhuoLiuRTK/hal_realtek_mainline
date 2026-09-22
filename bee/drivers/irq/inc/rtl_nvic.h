/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_NVIC_H
#define RTL_NVIC_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "irq/src/device/rtl87x2g/rtl_nvic_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "irq/src/device/rtl87x2j/rtl_nvic_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "irq/src/device/rtl87x3d/rtl_nvic_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "irq/src/device/rtl87x3j/rtl_nvic_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "irq/src/device/rtl87x3k/rtl_nvic_def.h"
#endif

/**
 * @defgroup NVIC_DRIVER DRIVER
 * @ingroup NVIC
 * @brief Nested Vectored Interrupt Controller (NVIC) driver.
 * @{
 */
/*============================================================================*
 *                         Types
 *============================================================================*/
/**
 * @defgroup NVIC_Exported_Types NVIC Exported Types
 * @{
 * @ingroup  NVIC
 */

/**
 * @brief       NVIC init structure definition.
 *
 * @ingroup     NVIC_Exported_Types
 */

typedef struct
{
    int NVIC_IRQChannel;                    /*!< Specify the IRQ channel.
                                                 This parameter can be a value of @ref IRQn_Type and @ref GPIO_IRQn. */
    uint32_t NVIC_IRQChannelPriority;       /*!< Specify the priority for the IRQ channel.
                                                 This parameter can be a value between 0 and x as described in the table.*/
    FunctionalState NVIC_IRQChannelCmd;     /*!< Specify the IRQ channel to be enabled or disabled.*/
} NVIC_InitTypeDef;

/** @} */ /* End of group NVIC_Exported_Types */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/**
 * @defgroup NVIC_Exported_Functions NVIC Exported Functions
 * @{
 * @ingroup  NVIC
 */

/**
 * @brief   Initialize the NVIC peripheral according to the specified
 *          parameters in NVIC_InitStruct.
 *
 * @param[in]   NVIC_InitStruct Pointer to a NVIC_InitTypeDef structure that contains
 *              the configuration information for the specified NVIC peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void nvic_config(void)
 * {
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = RTC_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * @endcode
 */
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct);

/** @} */ /* End of group NVIC_Exported_Functions */

/** @} */ /* End of group NVIC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_NVIC_H */


