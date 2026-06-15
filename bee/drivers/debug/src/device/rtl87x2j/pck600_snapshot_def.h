/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PCK600_SNAPSHOT_DEF_H
#define PCK600_SNAPSHOT_DEF_H

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#include "pcc_reg.h"

/*============================================================================*
 *                        PCK600 SNAPSHOT TYPE
 *============================================================================*/

typedef enum
{
    PCK600_SNAPSHOT_I2S        = 0,
    PCK600_SNAPSHOT_ADC        = 1,
    PCK600_SNAPSHOT_UART3      = 2,
    PCK600_SNAPSHOT_UART2      = 3,
    PCK600_SNAPSHOT_UART1      = 4,
    PCK600_SNAPSHOT_UART0      = 5,
    PCK600_SNAPSHOT_TMETER     = 6,
    PCK600_SNAPSHOT_TIMER1_CH8 = 7,
    PCK600_SNAPSHOT_TIMER1_CH7 = 8,
    PCK600_SNAPSHOT_TIMER1_CH6 = 9,
    PCK600_SNAPSHOT_TIMER1_CH5 = 10,
    PCK600_SNAPSHOT_TIMER1_CH4 = 11,
    PCK600_SNAPSHOT_TIMER1_CH3 = 12,
    PCK600_SNAPSHOT_TIMER1_CH2 = 13,
    PCK600_SNAPSHOT_TIMER1_CH1 = 14,
    PCK600_SNAPSHOT_TIMER1_CH0 = 15,
    PCK600_SNAPSHOT_TIMER0_CH1 = 16,
    PCK600_SNAPSHOT_TIMER0_CH0 = 17,
    PCK600_SNAPSHOT_SPI3W      = 18,
    PCK600_SNAPSHOT_SPI2       = 19,
    PCK600_SNAPSHOT_SPI1       = 20,
    PCK600_SNAPSHOT_SPI0       = 21,
    PCK600_SNAPSHOT_KEYSCAN    = 22,
    PCK600_SNAPSHOT_IR         = 23,
    PCK600_SNAPSHOT_I2C1       = 24,
    PCK600_SNAPSHOT_I2C0       = 25,
    PCK600_SNAPSHOT_GPIO       = 26,
    PCK600_SNAPSHOT_DMA        = 27,
    PCK600_SNAPSHOT_TIMER2_CH0 = 28,
    PCK600_SNAPSHOT_CAN        = 29,
    PCK600_SNAPSHOT_USB        = 30,

    PCK600_SNAPSHOT_RFC        = 31,
    PCK600_SNAPSHOT_PRO24G     = 32,
    PCK600_SNAPSHOT_PCC        = 33,
    PCK600_SNAPSHOT_MODEM      = 34,
    PCK600_SNAPSHOT_CAL80M     = 35,
    PCK600_SNAPSHOT_CAL32K     = 36,
    PCK600_SNAPSHOT_CAL10M     = 37,
    PCK600_SNAPSHOT_BTMAC      = 38,
    PCK600_SNAPSHOT_BT_VEN     = 39,
    PCK600_SNAPSHOT_AUDIO      = 40,
    PCK600_SNAPSHOT_AACK       = 41,
    PCK600_SNAPSHOT_AES        = 42,
    PCK600_SNAPSHOT_SHA256     = 43,
    PCK600_SNAPSHOT_CPU        = 44,
    PCK600_SNAPSHOT_SPIC0      = 45,
    PCK600_SNAPSHOT_RNG        = 46,
    PCK600_SNAPSHOT_VDREG      = 47,

    PCK600_SNAPSHOT_DEVICE_MAX,

} PCK600_SNAPSHOT_DEVICE_T;

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* PCK600_SNAPSHOT_DEF_H */
