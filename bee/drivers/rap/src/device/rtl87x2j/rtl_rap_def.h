/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_RAP_DEF_H
#define RTL_RAP_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "stddef.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          RAP Defines
 *============================================================================*/
#define RAP_SUPPORT_DISABE_RAP_FUNCTION              (0)

/*============================================================================*
 *                          RAP Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t RAP_CTRL;                                         /*!< 0x00 */
    __IO uint32_t DLPS_CH_EN;                                       /*!< 0x04 */
    __IO uint32_t INTR_EN;                                          /*!< 0x08 */
    __IO uint32_t INTR_O_EN;                                        /*!< 0x0C */
    __IO uint32_t RESERVED_10_1C[4];
    __IO uint32_t AON_PAD_EVNT_PUB_EN;                              /*!< 0x20 */
    __IO uint32_t RESERVED_24_2C[3];
    __IO uint32_t TIM2_CH0_EVNT_ACTIVE_PUB_EN;                      /*!< 0x30 */
    __IO uint32_t TIM2_CH0_EVNT_LATCH_CNT0_FIFO_FULL_PUB_EN;        /*!< 0x34 */
    __IO uint32_t TIM2_CH0_EVNT_LATCH_CNT0_FIFO_MET_TH_PUB_EN;      /*!< 0x38 */
    __IO uint32_t TIM2_CH0_EVNT_STOP_PUB_EN;                        /*!< 0x3C */
    __IO uint32_t TIM2_CH0_EVNT_TIMEOUT_PUB_EN;                     /*!< 0x40 */
    __IO uint32_t TIM2_CH0_TASK_DISABLE_SUB_EN;                     /*!< 0x44 */
    __IO uint32_t TIM2_CH0_TASK_PAUSE_SUB_EN;                       /*!< 0x48 */
    __IO uint32_t TIM2_CH0_TASK_START_SUB_EN;                       /*!< 0x4C */
    __IO uint32_t RESERVED_50;
    __IO uint32_t KEYSCAN_EVNT_MANUAL_DONE_PUB_EN;                  /*!< 0x54 */
    __IO uint32_t KEYSCAN_TASK_MANUAL_SUB_EN;                       /*!< 0x58 */
    __IO uint32_t RESERVED_5C_118[13];
    __IO uint32_t TIM1_CH0_EVNT_ACTIVE_PUB_EN;                      /*!< 0x90 */
    __IO uint32_t TIM1_CH0_EVNT_STOP_PUB_EN;                        /*!< 0x94 */
    __IO uint32_t TIM1_CH0_EVNT_TIMEOUT_PUB_EN;                     /*!< 0x98 */
    __IO uint32_t TIM1_CH1_EVNT_ACTIVE_PUB_EN;                      /*!< 0x9C */
    __IO uint32_t TIM1_CH1_EVNT_STOP_PUB_EN;                        /*!< 0xA0 */
    __IO uint32_t TIM1_CH1_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xA4 */
    __IO uint32_t TIM1_CH2_EVNT_ACTIVE_PUB_EN;                      /*!< 0xA8 */
    __IO uint32_t TIM1_CH2_EVNT_STOP_PUB_EN;                        /*!< 0xAC */
    __IO uint32_t TIM1_CH2_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xB0 */
    __IO uint32_t TIM1_CH3_EVNT_ACTIVE_PUB_EN;                      /*!< 0xB4 */
    __IO uint32_t TIM1_CH3_EVNT_STOP_PUB_EN;                        /*!< 0xB8 */
    __IO uint32_t TIM1_CH3_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xBC */
    __IO uint32_t TIM1_CH4_EVNT_ACTIVE_PUB_EN;                      /*!< 0xC0 */
    __IO uint32_t TIM1_CH4_EVNT_STOP_PUB_EN;                        /*!< 0xC4 */
    __IO uint32_t TIM1_CH4_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xC8 */
    __IO uint32_t TIM1_CH5_EVNT_ACTIVE_PUB_EN;                      /*!< 0xCC */
    __IO uint32_t TIM1_CH5_EVNT_STOP_PUB_EN;                        /*!< 0xD0 */
    __IO uint32_t TIM1_CH5_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xD4 */
    __IO uint32_t TIM1_CH6_EVNT_ACTIVE_PUB_EN;                      /*!< 0xD8 */
    __IO uint32_t TIM1_CH6_EVNT_STOP_PUB_EN;                        /*!< 0xDC */
    __IO uint32_t TIM1_CH6_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xE0 */
    __IO uint32_t TIM1_CH7_EVNT_ACTIVE_PUB_EN;                      /*!< 0xE4 */
    __IO uint32_t TIM1_CH7_EVNT_STOP_PUB_EN;                        /*!< 0xE8 */
    __IO uint32_t TIM1_CH7_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xEC */
    __IO uint32_t TIM1_CH8_EVNT_ACTIVE_PUB_EN;                      /*!< 0xF0 */
    __IO uint32_t TIM1_CH8_EVNT_STOP_PUB_EN;                        /*!< 0xF4 */
    __IO uint32_t TIM1_CH8_EVNT_TIMEOUT_PUB_EN;                     /*!< 0xF8 */
    __IO uint32_t RESERVED_FC_10C[5];
    __IO uint32_t TIM1_CH0_TASK_DISABLE_SUB_EN;                     /*!< 0x110 */
    __IO uint32_t TIM1_CH0_TASK_PAUSE_SUB_EN;                       /*!< 0x114 */
    __IO uint32_t TIM1_CH0_TASK_START_SUB_EN;                       /*!< 0x118 */
    __IO uint32_t TIM1_CH1_TASK_DISABLE_SUB_EN;                     /*!< 0x11C */
    __IO uint32_t TIM1_CH1_TASK_PAUSE_SUB_EN;                       /*!< 0x120 */
    __IO uint32_t TIM1_CH1_TASK_START_SUB_EN;                       /*!< 0x124 */
    __IO uint32_t TIM1_CH2_TASK_DISABLE_SUB_EN;                     /*!< 0x128 */
    __IO uint32_t TIM1_CH2_TASK_PAUSE_SUB_EN;                       /*!< 0x12C */
    __IO uint32_t TIM1_CH2_TASK_START_SUB_EN;                       /*!< 0x130 */
    __IO uint32_t TIM1_CH3_TASK_DISABLE_SUB_EN;                     /*!< 0x134 */
    __IO uint32_t TIM1_CH3_TASK_PAUSE_SUB_EN;                       /*!< 0x138 */
    __IO uint32_t TIM1_CH3_TASK_START_SUB_EN;                       /*!< 0x13C */
    __IO uint32_t TIM1_CH4_TASK_DISABLE_SUB_EN;                     /*!< 0x140 */
    __IO uint32_t TIM1_CH4_TASK_PAUSE_SUB_EN;                       /*!< 0x144 */
    __IO uint32_t TIM1_CH4_TASK_START_SUB_EN;                       /*!< 0x148 */
    __IO uint32_t TIM1_CH5_TASK_DISABLE_SUB_EN;                     /*!< 0x14C */
    __IO uint32_t TIM1_CH5_TASK_PAUSE_SUB_EN;                       /*!< 0x150 */
    __IO uint32_t TIM1_CH5_TASK_START_SUB_EN;                       /*!< 0x154 */
    __IO uint32_t TIM1_CH6_TASK_DISABLE_SUB_EN;                     /*!< 0x158 */
    __IO uint32_t TIM1_CH6_TASK_PAUSE_SUB_EN;                       /*!< 0x15C */
    __IO uint32_t TIM1_CH6_TASK_START_SUB_EN;                       /*!< 0x160 */
    __IO uint32_t TIM1_CH7_TASK_DISABLE_SUB_EN;                     /*!< 0x164 */
    __IO uint32_t TIM1_CH7_TASK_PAUSE_SUB_EN;                       /*!< 0x168 */
    __IO uint32_t TIM1_CH7_TASK_START_SUB_EN;                       /*!< 0x16C */
    __IO uint32_t TIM1_CH8_TASK_DISABLE_SUB_EN;                     /*!< 0x170 */
    __IO uint32_t TIM1_CH8_TASK_PAUSE_SUB_EN;                       /*!< 0x174 */
    __IO uint32_t TIM1_CH8_TASK_START_SUB_EN;                       /*!< 0x178 */
    __IO uint32_t RESERVED_17C_18C[5];
    __IO uint32_t GPIO0_0_EVNT_PUB_EN;                              /*!< 0x190 */
    __IO uint32_t GPIO0_1_EVNT_PUB_EN;                              /*!< 0x194 */
    __IO uint32_t GPIO0_2_EVNT_PUB_EN;                              /*!< 0x198 */
    __IO uint32_t GPIO0_3_EVNT_PUB_EN;                              /*!< 0x19C */
    __IO uint32_t GPIO0_4_EVNT_PUB_EN;                              /*!< 0x1A0 */
    __IO uint32_t GPIO0_5_EVNT_PUB_EN;                              /*!< 0x1A4 */
    __IO uint32_t GPIO0_6_EVNT_PUB_EN;                              /*!< 0x1A8 */
    __IO uint32_t GPIO0_7_EVNT_PUB_EN;                              /*!< 0x1AC */
    __IO uint32_t GPIO0_8_EVNT_PUB_EN;                              /*!< 0x1B0 */
    __IO uint32_t GPIO0_9_EVNT_PUB_EN;                              /*!< 0x1B4 */
    __IO uint32_t GPIO0_10_EVNT_PUB_EN;                             /*!< 0x1B8 */
    __IO uint32_t GPIO0_11_EVNT_PUB_EN;                             /*!< 0x1BC */
    __IO uint32_t GPIO0_12_EVNT_PUB_EN;                             /*!< 0x1C0 */
    __IO uint32_t GPIO0_13_EVNT_PUB_EN;                             /*!< 0x1C4 */
    __IO uint32_t GPIO0_14_EVNT_PUB_EN;                             /*!< 0x1C8 */
    __IO uint32_t GPIO0_15_EVNT_PUB_EN;                             /*!< 0x1CC */
    __IO uint32_t GPIO0_16_EVNT_PUB_EN;                             /*!< 0x1D0 */
    __IO uint32_t GPIO0_17_EVNT_PUB_EN;                             /*!< 0x1D4 */
    __IO uint32_t GPIO0_18_EVNT_PUB_EN;                             /*!< 0x1D8 */
    __IO uint32_t GPIO0_19_EVNT_PUB_EN;                             /*!< 0x1DC */
    __IO uint32_t GPIO0_20_EVNT_PUB_EN;                             /*!< 0x1E0 */
    __IO uint32_t GPIO0_21_EVNT_PUB_EN;                             /*!< 0x1E4 */
    __IO uint32_t GPIO0_22_EVNT_PUB_EN;                             /*!< 0x1E8 */
    __IO uint32_t GPIO0_23_EVNT_PUB_EN;                             /*!< 0x1EC */
    __IO uint32_t GPIO0_24_EVNT_PUB_EN;                             /*!< 0x1F0 */
    __IO uint32_t GPIO0_25_EVNT_PUB_EN;                             /*!< 0x1F4 */
    __IO uint32_t GPIO0_26_EVNT_PUB_EN;                             /*!< 0x1F8 */
    __IO uint32_t GPIO0_27_EVNT_PUB_EN;                             /*!< 0x1FC */
    __IO uint32_t GPIO0_28_EVNT_PUB_EN;                             /*!< 0x200 */
    __IO uint32_t GPIO0_29_EVNT_PUB_EN;                             /*!< 0x204 */
    __IO uint32_t GPIO0_30_EVNT_PUB_EN;                             /*!< 0x208 */
    __IO uint32_t GPIO0_31_EVNT_PUB_EN;                             /*!< 0x20C */
    __IO uint32_t GPIO0_32_EVNT_PUB_EN;                             /*!< 0x210 */
    __IO uint32_t GPIO0_33_EVNT_PUB_EN;                             /*!< 0x214 */
    __IO uint32_t GPIO0_34_EVNT_PUB_EN;                             /*!< 0x218 */
    __IO uint32_t GPIO0_35_EVNT_PUB_EN;                             /*!< 0x21C */
    __IO uint32_t GPIO0_36_EVNT_PUB_EN;                             /*!< 0x220 */
    __IO uint32_t GPIO0_37_EVNT_PUB_EN;                             /*!< 0x224 */
    __IO uint32_t GPIO0_38_EVNT_PUB_EN;                             /*!< 0x228 */
    __IO uint32_t GPIO0_39_EVNT_PUB_EN;                             /*!< 0x22C */
    __IO uint32_t GPIO0_40_EVNT_PUB_EN;                             /*!< 0x230 */
    __IO uint32_t GPIO0_41_EVNT_PUB_EN;                             /*!< 0x234 */
    __IO uint32_t GPIO0_42_EVNT_PUB_EN;                             /*!< 0x238 */
    __IO uint32_t GPIO0_43_EVNT_PUB_EN;                             /*!< 0x23C */
    __IO uint32_t GPIO0_44_EVNT_PUB_EN;                             /*!< 0x240 */
    __IO uint32_t GPIO0_45_EVNT_PUB_EN;                             /*!< 0x244 */
    __IO uint32_t GPIO0_46_EVNT_PUB_EN;                             /*!< 0x248 */
    __IO uint32_t GPIO0_47_EVNT_PUB_EN;                             /*!< 0x24C */
    __IO uint32_t GPIO0_48_EVNT_PUB_EN;                             /*!< 0x250 */
    __IO uint32_t GPIO0_49_EVNT_PUB_EN;                             /*!< 0x254 */
    __IO uint32_t RESERVED_258_42C[118];
    __IO uint32_t GPIO0_0_TASK_DRCLR_SUB_EN;                        /*!< 0x430 */
    __IO uint32_t GPIO0_1_TASK_DRCLR_SUB_EN;                        /*!< 0x434 */
    __IO uint32_t GPIO0_2_TASK_DRCLR_SUB_EN;                        /*!< 0x438 */
    __IO uint32_t GPIO0_3_TASK_DRCLR_SUB_EN;                        /*!< 0x43C */
    __IO uint32_t GPIO0_4_TASK_DRCLR_SUB_EN;                        /*!< 0x440 */
    __IO uint32_t GPIO0_5_TASK_DRCLR_SUB_EN;                        /*!< 0x444 */
    __IO uint32_t GPIO0_6_TASK_DRCLR_SUB_EN;                        /*!< 0x448 */
    __IO uint32_t GPIO0_7_TASK_DRCLR_SUB_EN;                        /*!< 0x44C */
    __IO uint32_t GPIO0_8_TASK_DRCLR_SUB_EN;                        /*!< 0x450 */
    __IO uint32_t GPIO0_9_TASK_DRCLR_SUB_EN;                        /*!< 0x454 */
    __IO uint32_t GPIO0_10_TASK_DRCLR_SUB_EN;                       /*!< 0x458 */
    __IO uint32_t GPIO0_11_TASK_DRCLR_SUB_EN;                       /*!< 0x45C */
    __IO uint32_t GPIO0_12_TASK_DRCLR_SUB_EN;                       /*!< 0x460 */
    __IO uint32_t GPIO0_13_TASK_DRCLR_SUB_EN;                       /*!< 0x464 */
    __IO uint32_t GPIO0_14_TASK_DRCLR_SUB_EN;                       /*!< 0x468 */
    __IO uint32_t GPIO0_15_TASK_DRCLR_SUB_EN;                       /*!< 0x46C */
    __IO uint32_t GPIO0_16_TASK_DRCLR_SUB_EN;                       /*!< 0x470 */
    __IO uint32_t GPIO0_17_TASK_DRCLR_SUB_EN;                       /*!< 0x474 */
    __IO uint32_t GPIO0_18_TASK_DRCLR_SUB_EN;                       /*!< 0x478 */
    __IO uint32_t GPIO0_19_TASK_DRCLR_SUB_EN;                       /*!< 0x47C */
    __IO uint32_t GPIO0_20_TASK_DRCLR_SUB_EN;                       /*!< 0x480 */
    __IO uint32_t GPIO0_21_TASK_DRCLR_SUB_EN;                       /*!< 0x484 */
    __IO uint32_t GPIO0_22_TASK_DRCLR_SUB_EN;                       /*!< 0x488 */
    __IO uint32_t GPIO0_23_TASK_DRCLR_SUB_EN;                       /*!< 0x48C */
    __IO uint32_t GPIO0_24_TASK_DRCLR_SUB_EN;                       /*!< 0x490 */
    __IO uint32_t GPIO0_25_TASK_DRCLR_SUB_EN;                       /*!< 0x494 */
    __IO uint32_t GPIO0_26_TASK_DRCLR_SUB_EN;                       /*!< 0x498 */
    __IO uint32_t GPIO0_27_TASK_DRCLR_SUB_EN;                       /*!< 0x49C */
    __IO uint32_t GPIO0_28_TASK_DRCLR_SUB_EN;                       /*!< 0x4A0 */
    __IO uint32_t GPIO0_29_TASK_DRCLR_SUB_EN;                       /*!< 0x4A4 */
    __IO uint32_t GPIO0_30_TASK_DRCLR_SUB_EN;                       /*!< 0x4A8 */
    __IO uint32_t GPIO0_31_TASK_DRCLR_SUB_EN;                       /*!< 0x4AC */
    __IO uint32_t GPIO0_32_TASK_DRCLR_SUB_EN;                       /*!< 0x4B0 */
    __IO uint32_t GPIO0_33_TASK_DRCLR_SUB_EN;                       /*!< 0x4B4 */
    __IO uint32_t GPIO0_34_TASK_DRCLR_SUB_EN;                       /*!< 0x4B8 */
    __IO uint32_t GPIO0_35_TASK_DRCLR_SUB_EN;                       /*!< 0x4BC */
    __IO uint32_t GPIO0_36_TASK_DRCLR_SUB_EN;                       /*!< 0x4C0 */
    __IO uint32_t GPIO0_37_TASK_DRCLR_SUB_EN;                       /*!< 0x4C4 */
    __IO uint32_t GPIO0_38_TASK_DRCLR_SUB_EN;                       /*!< 0x4C8 */
    __IO uint32_t GPIO0_39_TASK_DRCLR_SUB_EN;                       /*!< 0x4CC */
    __IO uint32_t GPIO0_40_TASK_DRCLR_SUB_EN;                       /*!< 0x4D0 */
    __IO uint32_t GPIO0_41_TASK_DRCLR_SUB_EN;                       /*!< 0x4D4 */
    __IO uint32_t GPIO0_42_TASK_DRCLR_SUB_EN;                       /*!< 0x4D8 */
    __IO uint32_t GPIO0_43_TASK_DRCLR_SUB_EN;                       /*!< 0x4DC */
    __IO uint32_t GPIO0_44_TASK_DRCLR_SUB_EN;                       /*!< 0x4E0 */
    __IO uint32_t GPIO0_45_TASK_DRCLR_SUB_EN;                       /*!< 0x4E4 */
    __IO uint32_t GPIO0_46_TASK_DRCLR_SUB_EN;                       /*!< 0x4E8 */
    __IO uint32_t GPIO0_47_TASK_DRCLR_SUB_EN;                       /*!< 0x4EC */
    __IO uint32_t GPIO0_48_TASK_DRCLR_SUB_EN;                       /*!< 0x4F0 */
    __IO uint32_t GPIO0_49_TASK_DRCLR_SUB_EN;                       /*!< 0x4F4 */
    __IO uint32_t RESERVED_4F8_50C[6];
    __IO uint32_t GPIO0_0_TASK_DRSET_SUB_EN;                        /*!< 0x510 */
    __IO uint32_t GPIO0_1_TASK_DRSET_SUB_EN;                        /*!< 0x514 */
    __IO uint32_t GPIO0_2_TASK_DRSET_SUB_EN;                        /*!< 0x518 */
    __IO uint32_t GPIO0_3_TASK_DRSET_SUB_EN;                        /*!< 0x51C */
    __IO uint32_t GPIO0_4_TASK_DRSET_SUB_EN;                        /*!< 0x520 */
    __IO uint32_t GPIO0_5_TASK_DRSET_SUB_EN;                        /*!< 0x524 */
    __IO uint32_t GPIO0_6_TASK_DRSET_SUB_EN;                        /*!< 0x528 */
    __IO uint32_t GPIO0_7_TASK_DRSET_SUB_EN;                        /*!< 0x52C */
    __IO uint32_t GPIO0_8_TASK_DRSET_SUB_EN;                        /*!< 0x530 */
    __IO uint32_t GPIO0_9_TASK_DRSET_SUB_EN;                        /*!< 0x534 */
    __IO uint32_t GPIO0_10_TASK_DRSET_SUB_EN;                       /*!< 0x538 */
    __IO uint32_t GPIO0_11_TASK_DRSET_SUB_EN;                       /*!< 0x53C */
    __IO uint32_t GPIO0_12_TASK_DRSET_SUB_EN;                       /*!< 0x540 */
    __IO uint32_t GPIO0_13_TASK_DRSET_SUB_EN;                       /*!< 0x544 */
    __IO uint32_t GPIO0_14_TASK_DRSET_SUB_EN;                       /*!< 0x548 */
    __IO uint32_t GPIO0_15_TASK_DRSET_SUB_EN;                       /*!< 0x54C */
    __IO uint32_t GPIO0_16_TASK_DRSET_SUB_EN;                       /*!< 0x550 */
    __IO uint32_t GPIO0_17_TASK_DRSET_SUB_EN;                       /*!< 0x554 */
    __IO uint32_t GPIO0_18_TASK_DRSET_SUB_EN;                       /*!< 0x558 */
    __IO uint32_t GPIO0_19_TASK_DRSET_SUB_EN;                       /*!< 0x55C */
    __IO uint32_t GPIO0_20_TASK_DRSET_SUB_EN;                       /*!< 0x560 */
    __IO uint32_t GPIO0_21_TASK_DRSET_SUB_EN;                       /*!< 0x564 */
    __IO uint32_t GPIO0_22_TASK_DRSET_SUB_EN;                       /*!< 0x568 */
    __IO uint32_t GPIO0_23_TASK_DRSET_SUB_EN;                       /*!< 0x56C */
    __IO uint32_t GPIO0_24_TASK_DRSET_SUB_EN;                       /*!< 0x570 */
    __IO uint32_t GPIO0_25_TASK_DRSET_SUB_EN;                       /*!< 0x574 */
    __IO uint32_t GPIO0_26_TASK_DRSET_SUB_EN;                       /*!< 0x578 */
    __IO uint32_t GPIO0_27_TASK_DRSET_SUB_EN;                       /*!< 0x57C */
    __IO uint32_t GPIO0_28_TASK_DRSET_SUB_EN;                       /*!< 0x580 */
    __IO uint32_t GPIO0_29_TASK_DRSET_SUB_EN;                       /*!< 0x584 */
    __IO uint32_t GPIO0_30_TASK_DRSET_SUB_EN;                       /*!< 0x588 */
    __IO uint32_t GPIO0_31_TASK_DRSET_SUB_EN;                       /*!< 0x58C */
    __IO uint32_t GPIO0_32_TASK_DRSET_SUB_EN;                       /*!< 0x590 */
    __IO uint32_t GPIO0_33_TASK_DRSET_SUB_EN;                       /*!< 0x594 */
    __IO uint32_t GPIO0_34_TASK_DRSET_SUB_EN;                       /*!< 0x598 */
    __IO uint32_t GPIO0_35_TASK_DRSET_SUB_EN;                       /*!< 0x59C */
    __IO uint32_t GPIO0_36_TASK_DRSET_SUB_EN;                       /*!< 0x5A0 */
    __IO uint32_t GPIO0_37_TASK_DRSET_SUB_EN;                       /*!< 0x5A4 */
    __IO uint32_t GPIO0_38_TASK_DRSET_SUB_EN;                       /*!< 0x5A8 */
    __IO uint32_t GPIO0_39_TASK_DRSET_SUB_EN;                       /*!< 0x5AC */
    __IO uint32_t GPIO0_40_TASK_DRSET_SUB_EN;                       /*!< 0x5B0 */
    __IO uint32_t GPIO0_41_TASK_DRSET_SUB_EN;                       /*!< 0x5B4 */
    __IO uint32_t GPIO0_42_TASK_DRSET_SUB_EN;                       /*!< 0x5B8 */
    __IO uint32_t GPIO0_43_TASK_DRSET_SUB_EN;                       /*!< 0x5BC */
    __IO uint32_t GPIO0_44_TASK_DRSET_SUB_EN;                       /*!< 0x5C0 */
    __IO uint32_t GPIO0_45_TASK_DRSET_SUB_EN;                       /*!< 0x5C4 */
    __IO uint32_t GPIO0_46_TASK_DRSET_SUB_EN;                       /*!< 0x5C8 */
    __IO uint32_t GPIO0_47_TASK_DRSET_SUB_EN;                       /*!< 0x5CC */
    __IO uint32_t GPIO0_48_TASK_DRSET_SUB_EN;                       /*!< 0x5D0 */
    __IO uint32_t GPIO0_49_TASK_DRSET_SUB_EN;                       /*!< 0x5D4 */
    __IO uint32_t RESERVED_5D8_5EC[6];
    __IO uint32_t GPIO0_0_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x5F0 */
    __IO uint32_t GPIO0_1_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x5F4 */
    __IO uint32_t GPIO0_2_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x5F8 */
    __IO uint32_t GPIO0_3_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x5FC */
    __IO uint32_t GPIO0_4_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x600 */
    __IO uint32_t GPIO0_5_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x604 */
    __IO uint32_t GPIO0_6_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x608 */
    __IO uint32_t GPIO0_7_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x60C */
    __IO uint32_t GPIO0_8_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x610 */
    __IO uint32_t GPIO0_9_TASK_DRTOGGLE_SUB_EN;                     /*!< 0x614 */
    __IO uint32_t GPIO0_10_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x618 */
    __IO uint32_t GPIO0_11_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x61C */
    __IO uint32_t GPIO0_12_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x620 */
    __IO uint32_t GPIO0_13_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x624 */
    __IO uint32_t GPIO0_14_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x628 */
    __IO uint32_t GPIO0_15_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x62C */
    __IO uint32_t GPIO0_16_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x630 */
    __IO uint32_t GPIO0_17_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x634 */
    __IO uint32_t GPIO0_18_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x638 */
    __IO uint32_t GPIO0_19_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x63C */
    __IO uint32_t GPIO0_20_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x640 */
    __IO uint32_t GPIO0_21_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x644 */
    __IO uint32_t GPIO0_22_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x648 */
    __IO uint32_t GPIO0_23_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x64C */
    __IO uint32_t GPIO0_24_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x650 */
    __IO uint32_t GPIO0_25_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x654 */
    __IO uint32_t GPIO0_26_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x658 */
    __IO uint32_t GPIO0_27_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x65C */
    __IO uint32_t GPIO0_28_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x660 */
    __IO uint32_t GPIO0_29_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x664 */
    __IO uint32_t GPIO0_30_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x668 */
    __IO uint32_t GPIO0_31_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x66C */
    __IO uint32_t GPIO0_32_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x670 */
    __IO uint32_t GPIO0_33_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x674 */
    __IO uint32_t GPIO0_34_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x678 */
    __IO uint32_t GPIO0_35_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x67C */
    __IO uint32_t GPIO0_36_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x680 */
    __IO uint32_t GPIO0_37_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x684 */
    __IO uint32_t GPIO0_38_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x688 */
    __IO uint32_t GPIO0_39_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x68C */
    __IO uint32_t GPIO0_40_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x690 */
    __IO uint32_t GPIO0_41_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x694 */
    __IO uint32_t GPIO0_42_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x698 */
    __IO uint32_t GPIO0_43_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x69C */
    __IO uint32_t GPIO0_44_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6A0 */
    __IO uint32_t GPIO0_45_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6A4 */
    __IO uint32_t GPIO0_46_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6A8 */
    __IO uint32_t GPIO0_47_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6AC */
    __IO uint32_t GPIO0_48_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6B0 */
    __IO uint32_t GPIO0_49_TASK_DRTOGGLE_SUB_EN;                    /*!< 0x6B4 */
    __IO uint32_t GPIO0_TASK_NOP_SUB_EN;                            /*!< 0x6B8 */
    __IO uint32_t RESERVED_6BC_96C[173];
    __IO uint32_t GIRDA_EVNT_TXDONE_PUB_EN;                         /*!< 0x970 */
    __IO uint32_t GIRDA_EVNT_RXDONE_PUB_EN;                         /*!< 0x974 */
    __IO uint32_t GIRDA_TASK_START_TX_SUB_EN;                       /*!< 0x978 */
    __IO uint32_t GIRDA_TASK_START_RX_SUB_EN;                       /*!< 0x97C */
    __IO uint32_t RESERVED_980_98C[4];
    __IO uint32_t I2C0_EVNT_ERROR_PUB_EN;                           /*!< 0x990 */
    __IO uint32_t I2C0_EVNT_STARTED_PUB_EN;                         /*!< 0x994 */
    __IO uint32_t I2C0_EVNT_STOPPED_PUB_EN;                         /*!< 0x998 */
    __IO uint32_t I2C0_TASK_START_SUB_EN;                           /*!< 0x99C */
    __IO uint32_t RESERVED_9A0_9AC[4];
    __IO uint32_t I2C1_EVNT_ERROR_PUB_EN;                           /*!< 0x9B0 */
    __IO uint32_t I2C1_EVNT_STARTED_PUB_EN;                         /*!< 0x9B4 */
    __IO uint32_t I2C1_EVNT_STOPPED_PUB_EN;                         /*!< 0x9B8 */
    __IO uint32_t I2C1_TASK_START_SUB_EN;                           /*!< 0x9BC */
    __IO uint32_t RESERVED_9C0_9CC[4];
    __IO uint32_t AUXADC_EVNT_DONE_PUB_EN;                          /*!< 0x9D0 */
    __IO uint32_t AUXADC_EVNT_RESULTDONE_PUB_EN;                    /*!< 0x9D4 */
    __IO uint32_t AUXADC_TASK_ONE_SHOT_SAMPLE_SUB_EN;               /*!< 0x9D8 */
    __IO uint32_t RESERVED_9DC_9EC[5];
    __IO uint32_t SPI3WIRE_EVNT_END_PUB_EN;                         /*!< 0x9F0 */
    __IO uint32_t SPI3WIRE_TASK_START_SUB_EN;                       /*!< 0x9F4 */
    __IO uint32_t RESERVED_9F8_A0C[6];
    __IO uint32_t SPI0_EVNT_START_PUB_EN;                           /*!< 0xA10 */
    __IO uint32_t SPI0_EVNT_END_PUB_EN;                             /*!< 0xA14 */
    __IO uint32_t SPI0_TASK_START_SUB_EN;                           /*!< 0xA18 */
    __IO uint32_t RESERVED_A1C_A2C[5];
    __IO uint32_t SPI1_EVNT_START_PUB_EN;                           /*!< 0xA30 */
    __IO uint32_t SPI1_EVNT_END_PUB_EN;                             /*!< 0xA34 */
    __IO uint32_t SPI1_TASK_START_SUB_EN;                           /*!< 0xA38 */
    __IO uint32_t RESERVED_A3C_A6C[13];
    __IO uint32_t RTC_EVNT_TICK_PUB_EN;                             /*!< 0xA70 */
    __IO uint32_t RTC_EVNT_OVRFLW_PUB_EN;                           /*!< 0xA74 */
    __IO uint32_t RTC_EVNT_COMPARE0_PUB_EN;                         /*!< 0xA78 */
    __IO uint32_t RTC_EVNT_COMPARE1_PUB_EN;                         /*!< 0xA7C */
    __IO uint32_t RTC_EVNT_COMPARE2_PUB_EN;                         /*!< 0xA80 */
    __IO uint32_t RTC_EVNT_COMPARE3_PUB_EN;                         /*!< 0xA84 */
    __IO uint32_t RTC_TASK_CLEAR_SUB_EN;                            /*!< 0xA88 */
    __IO uint32_t RTC_TASK_STOP_SUB_EN;                             /*!< 0xA8C */
    __IO uint32_t RTC_TASK_START_SUB_EN;                            /*!< 0xA90 */
    __IO uint32_t RTC_TASK_RELOAD_CMP0_SUB_EN;                      /*!< 0xA94 */
    __IO uint32_t RTC_TASK_RELOAD_CMP1_SUB_EN;                      /*!< 0xA98 */
    __IO uint32_t RTC_TASK_RELOAD_CMP2_SUB_EN;                      /*!< 0xA9C */
    __IO uint32_t RTC_TASK_RELOAD_CMP3_SUB_EN;                      /*!< 0xAA0 */
    __IO uint32_t RESERVED_AA4_AAC[3];
    __IO uint32_t LPC_EVNT_STATUS_PUB_EN;                           /*!< 0xAB0 */
    __IO uint32_t LPC_TASK_START_SUB_EN;                            /*!< 0xAB4 */
    __IO uint32_t LPC_TASK_STOP_SUB_EN;                             /*!< 0xAB8 */
    __IO uint32_t RESERVED_ABC_AF8[16];
    __IO uint32_t DMA_EVNT_INT_TFR3_PUB_EN;                         /*!< 0xAFC */
    __IO uint32_t DMA_EVNT_INT_TFR4_PUB_EN;                         /*!< 0xB00 */
    __IO uint32_t RESERVED_B04_B18[6];
    __IO uint32_t DMA_EVNT_INT_BLK3_PUB_EN;                         /*!< 0xB1C */
    __IO uint32_t DMA_EVNT_INT_BLK4_PUB_EN;                         /*!< 0xB20 */
    __IO uint32_t RESERVED_B24_B38[6];
    __IO uint32_t DMA_TASK_CHN_EN3_SUB_EN;                          /*!< 0xB3C */
    __IO uint32_t DMA_TASK_CHN_EN4_SUB_EN;                          /*!< 0xB40 */
    __IO uint32_t RESERVED_B44_B4C[3];
    __IO uint32_t GRTC_EVNT_COMPARE0_PUB_EN;                        /*!< 0xB50 */
    __IO uint32_t GRTC_EVNT_COMPARE1_PUB_EN;                        /*!< 0xB54 */
    __IO uint32_t GRTC_EVNT_COMPARE2_PUB_EN;                        /*!< 0xB58 */
    __IO uint32_t GRTC_EVNT_COMPARE3_PUB_EN;                        /*!< 0xB5C */
    __IO uint32_t GRTC_EVNT_COMPARE4_PUB_EN;                        /*!< 0xB60 */
    __IO uint32_t GRTC_EVNT_COMPARE5_PUB_EN;                        /*!< 0xB64 */
    __IO uint32_t GRTC_EVNT_COMPARE6_PUB_EN;                        /*!< 0xB68 */
    __IO uint32_t GRTC_EVNT_COMPARE7_PUB_EN;                        /*!< 0xB6C */
    __IO uint32_t RESERVED_B70_B74[2];
    __IO uint32_t GRTC_TASK_RELOAD_CMP0_SUB_EN;                     /*!< 0xB78 */
    __IO uint32_t GRTC_TASK_RELOAD_CMP1_SUB_EN;                     /*!< 0xB7C */
    __IO uint32_t GRTC_TASK_RELOAD_CMP2_SUB_EN;                     /*!< 0xB80 */
    __IO uint32_t GRTC_TASK_RELOAD_CMP3_SUB_EN;                     /*!< 0xB84 */
    __IO uint32_t GRTC_TASK_RELOAD_CMP4_SUB_EN;                     /*!< 0xB88 */
    __IO uint32_t GRTC_TASK_RELOAD_CMP5_SUB_EN;                     /*!< 0xB8C */
    __IO uint32_t GRTC_TASK_RELOAD_CMP6_SUB_EN;                     /*!< 0xB90 */
    __IO uint32_t GRTC_TASK_RELOAD_CMP7_SUB_EN;                     /*!< 0xB94 */
    __IO uint32_t RESERVED_B98_B9C[2];
    __IO uint32_t SDMK_EVNT_DONE_PUB_EN;                            /*!< 0xBA0 */
    __IO uint32_t SDMK_TASK_START_SUB_EN;                           /*!< 0xBA4 */
    __IO uint32_t RESERVED_BA8_BAC[2];
    __IO uint32_t OSC10M_EVNT_CAL_DONE_PUB_EN;                      /*!< 0xBB0 */
    __IO uint32_t OSC10M_TASK_CAL_SUB_EN;                           /*!< 0xBB4 */
    __IO uint32_t RESERVED_BB8_BBC[2];
    __IO uint32_t OSC80M_EVNT_CAL_DONE_PUB_EN;                      /*!< 0xBC0 */
    __IO uint32_t OSC80M_TASK_CAL_SUB_EN;                           /*!< 0xBC4 */
    __IO uint32_t TMETER_EVNT_DATARDY_PUB_EN;                       /*!< 0xBC8 */
    __IO uint32_t TMETER_EVNT_ABS_CMP0_PUB_EN;                      /*!< 0xBCC */
    __IO uint32_t TMETER_EVNT_ABS_CMP1_PUB_EN;                      /*!< 0xBD0 */
    __IO uint32_t TMETER_EVNT_ABS_CMP2_PUB_EN;                      /*!< 0xBD4 */
    __IO uint32_t TMETER_EVNT_ABS_CMP3_PUB_EN;                      /*!< 0xBD8 */
    __IO uint32_t TMETER_EVNT_REL_CMP0_PUB_EN;                      /*!< 0xBDC */
    __IO uint32_t TMETER_EVNT_REL_CMP1_PUB_EN;                      /*!< 0xBE0 */
    __IO uint32_t TMETER_EVNT_REL_CMP2_PUB_EN;                      /*!< 0xBE4 */
    __IO uint32_t TMETER_EVNT_REL_CMP3_PUB_EN;                      /*!< 0xBE8 */
    __IO uint32_t TMETER_EVNT_FW_REL_COMP3_PUB_EN;                  /*!< 0xBEC */
    __IO uint32_t TMETER_TASK_ONESHOT_SUB_EN;                       /*!< 0xBF0 */
    __IO uint32_t RESERVED_BF0_EFC[195];
    __IO uint32_t DEBUG_SIG;                                        /*!< 0xF00 */
} RAP_TypeDef;

typedef struct
{
    __IO uint32_t TIMER2_TASK_EVNT_STS;             /*!< 0x2EC */
    __IO uint32_t KEYSCAN_TASK_EVNT_STS;            /*!< 0x2F0 */
    __IO uint32_t TIMER1_EVNT_STS;                  /*!< 0x2F4 */
    __IO uint32_t TIMER1_TASK_STS;                  /*!< 0x2F8 */
    __IO uint32_t GPIO_0_EVNT_STS;                  /*!< 0x2FC */
    __IO uint32_t GPIO_1_EVENT_STS;                 /*!< 0x300 */
    __IO uint32_t RESERVED_304_310[4];
    __IO uint32_t GPIO_0_TASK_DRCLR_STS;            /*!< 0x314 */
    __IO uint32_t GPIO_1_TASK_DRCLR_STS;            /*!< 0x318 */
    __IO uint32_t GPIO_0_TASK_DRSET_STS;            /*!< 0x31C */
    __IO uint32_t GPIO_1_TASK_DRSET_STS;            /*!< 0x320 */
    __IO uint32_t GPIO_0_TASK_DRTOGGLE_STS;         /*!< 0x324 */
    __IO uint32_t GPIO_1_TASK_DRTOGGLE_STS;         /*!< 0x328 */
    __IO uint32_t RESERVED_32C_340[6];
    __IO uint32_t GIRDA_TASK_EVNT_STS;              /*!< 0x344 */
    __IO uint32_t I2C0_TASK_EVNT_STS;               /*!< 0x348 */
    __IO uint32_t I2C1_TASK_EVNT_STS;               /*!< 0x34C */
    __IO uint32_t AUXADC_TASK_EVNT_STS;             /*!< 0x350 */
    __IO uint32_t SPI3WIRE_TASK_EVNT_STS;           /*!< 0x354 */
    __IO uint32_t SPI0DUAL_TASK_EVNT_STS;           /*!< 0x358 */
    __IO uint32_t SPI1MST_TASK_EVNT_STS;            /*!< 0x35C */
    __IO uint32_t RESERVED_360;
    __IO uint32_t TMETER_TASK_EVNT_STS;             /*!< 0x364 */
    __IO uint32_t DMA_TASK_EVNT_STS;                /*!< 0x368 */
    __IO uint32_t SDMK_TASK_EVNT_STS;               /*!< 0x36C */
    __IO uint32_t OSC10M_CAL_TASK_EVNT_STS;         /*!< 0x370 */
    __IO uint32_t OSC80M_CAL_TASK_EVNT_STS;         /*!< 0x374 */
    __IO uint32_t RESERVED_ABC_ACC[1765];           /*!< 0x6378 ~ 7F00*/
    __IO uint32_t RTC_TASK_EVNT_STS;                /*!< 0xF04 */
    __IO uint32_t LPC_TASK_EVNT_STS;                /*!< 0xF08 */
    __IO uint32_t GRTC_TASK_EVNT_STS;               /*!< 0xF0C */
    __IO uint32_t AON_PAD_TASK_EVNT_STS;            /*!< 0xF10 */
} RAPSTATUS_TypeDef;

/*============================================================================*
 *                          RAP Declaration
 *============================================================================*/
/** @addtogroup RAP
  * \brief
  * \{
  */

/** \defgroup RAP_Exported_Constants RAP Exported Constants
  * \brief
  * \{
  */

/** \defgroup RAP_Declaration RAP Declaration
  * \{
  * \ingroup  RAP_Exported_Constants
  */

#define RAP                     ((RAP_TypeDef *) RAP_BASE)

#define IS_RAP_PERIPH(PERIPH)   (((PERIPH) == RAP))

#define RAP_STATUS              ((RAPSTATUS_TypeDef *) (SOC_VENDOR_REG_BASE + 0x2EC))

/** End of RAP_Declaration
  * \}
  */

/** End of RAP_Exported_Constants
  * \}
  */

/** End of RAP
  * \}
  */
/*============================================================================*
 *                          RAP Punblic Defines
 *============================================================================*/
/* TASK and EVENT */
#define RAP_PAD_EVENT                                    offsetof(RAP_TypeDef, AON_PAD_EVNT_PUB_EN)
#define RAP_TIMER2_CH0_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM2_CH0_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_FULL        offsetof(RAP_TypeDef, TIM2_CH0_EVNT_LATCH_CNT0_FIFO_FULL_PUB_EN)
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_MET_TH      offsetof(RAP_TypeDef, TIM2_CH0_EVNT_LATCH_CNT0_FIFO_MET_TH_PUB_EN)
#define RAP_TIMER2_CH0_EVENT_STOP                        offsetof(RAP_TypeDef, TIM2_CH0_EVNT_STOP_PUB_EN)
#define RAP_TIMER2_CH0_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM2_CH0_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER2_CH0_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM2_CH0_TASK_DISABLE_SUB_EN)
#define RAP_TIMER2_CH0_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM2_CH0_TASK_PAUSE_SUB_EN)
#define RAP_TIMER2_CH0_ACTION_START                      offsetof(RAP_TypeDef, TIM2_CH0_TASK_START_SUB_EN)
#define RAP_KEYSCAN_EVENT_MANUAL_DONE                    offsetof(RAP_TypeDef, KEYSCAN_EVNT_MANUAL_DONE_PUB_EN)
#define RAP_KEYSCAN_ACTION_MANUAL                        offsetof(RAP_TypeDef, KEYSCAN_TASK_MANUAL_SUB_EN)
#define RAP_TIMER1_CH0_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH0_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH0_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH0_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH0_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH0_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH1_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH1_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH1_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH1_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH1_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH1_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH2_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH2_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH2_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH2_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH2_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH2_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH3_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH3_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH3_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH3_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH3_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH3_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH4_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH4_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH4_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH4_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH4_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH4_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH5_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH5_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH5_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH5_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH5_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH5_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH6_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH6_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH6_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH6_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH6_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH6_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH7_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH7_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH7_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH7_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH7_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH7_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH8_EVENT_ACTIVE                      offsetof(RAP_TypeDef, TIM1_CH8_EVNT_ACTIVE_PUB_EN)
#define RAP_TIMER1_CH8_EVENT_STOP                        offsetof(RAP_TypeDef, TIM1_CH8_EVNT_STOP_PUB_EN)
#define RAP_TIMER1_CH8_EVENT_TIMEOUT                     offsetof(RAP_TypeDef, TIM1_CH8_EVNT_TIMEOUT_PUB_EN)
#define RAP_TIMER1_CH0_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH0_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH0_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH0_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH0_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH0_TASK_START_SUB_EN)
#define RAP_TIMER1_CH1_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH1_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH1_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH1_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH1_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH1_TASK_START_SUB_EN)
#define RAP_TIMER1_CH2_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH2_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH2_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH2_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH2_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH2_TASK_START_SUB_EN)
#define RAP_TIMER1_CH3_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH3_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH3_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH3_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH3_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH3_TASK_START_SUB_EN)
#define RAP_TIMER1_CH4_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH4_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH4_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH4_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH4_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH4_TASK_START_SUB_EN)
#define RAP_TIMER1_CH5_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH5_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH5_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH5_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH5_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH5_TASK_START_SUB_EN)
#define RAP_TIMER1_CH6_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH6_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH6_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH6_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH6_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH6_TASK_START_SUB_EN)
#define RAP_TIMER1_CH7_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH7_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH7_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH7_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH7_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH7_TASK_START_SUB_EN)
#define RAP_TIMER1_CH8_ACTION_DISABLE                    offsetof(RAP_TypeDef, TIM1_CH8_TASK_DISABLE_SUB_EN)
#define RAP_TIMER1_CH8_ACTION_PAUSE                      offsetof(RAP_TypeDef, TIM1_CH8_TASK_PAUSE_SUB_EN)
#define RAP_TIMER1_CH8_ACTION_START                      offsetof(RAP_TypeDef, TIM1_CH8_TASK_START_SUB_EN)
#define RAP_GPIOA_0_EVENT                                offsetof(RAP_TypeDef, GPIO0_0_EVNT_PUB_EN)
#define RAP_GPIOA_1_EVENT                                offsetof(RAP_TypeDef, GPIO0_1_EVNT_PUB_EN)
#define RAP_GPIOA_2_EVENT                                offsetof(RAP_TypeDef, GPIO0_2_EVNT_PUB_EN)
#define RAP_GPIOA_3_EVENT                                offsetof(RAP_TypeDef, GPIO0_3_EVNT_PUB_EN)
#define RAP_GPIOA_4_EVENT                                offsetof(RAP_TypeDef, GPIO0_4_EVNT_PUB_EN)
#define RAP_GPIOA_5_EVENT                                offsetof(RAP_TypeDef, GPIO0_5_EVNT_PUB_EN)
#define RAP_GPIOA_6_EVENT                                offsetof(RAP_TypeDef, GPIO0_6_EVNT_PUB_EN)
#define RAP_GPIOA_7_EVENT                                offsetof(RAP_TypeDef, GPIO0_7_EVNT_PUB_EN)
#define RAP_GPIOA_8_EVENT                                offsetof(RAP_TypeDef, GPIO0_8_EVNT_PUB_EN)
#define RAP_GPIOA_9_EVENT                                offsetof(RAP_TypeDef, GPIO0_9_EVNT_PUB_EN)
#define RAP_GPIOA_10_EVENT                               offsetof(RAP_TypeDef, GPIO0_10_EVNT_PUB_EN)
#define RAP_GPIOA_11_EVENT                               offsetof(RAP_TypeDef, GPIO0_11_EVNT_PUB_EN)
#define RAP_GPIOA_12_EVENT                               offsetof(RAP_TypeDef, GPIO0_12_EVNT_PUB_EN)
#define RAP_GPIOA_13_EVENT                               offsetof(RAP_TypeDef, GPIO0_13_EVNT_PUB_EN)
#define RAP_GPIOA_14_EVENT                               offsetof(RAP_TypeDef, GPIO0_14_EVNT_PUB_EN)
#define RAP_GPIOA_15_EVENT                               offsetof(RAP_TypeDef, GPIO0_15_EVNT_PUB_EN)
#define RAP_GPIOA_16_EVENT                               offsetof(RAP_TypeDef, GPIO0_16_EVNT_PUB_EN)
#define RAP_GPIOA_17_EVENT                               offsetof(RAP_TypeDef, GPIO0_17_EVNT_PUB_EN)
#define RAP_GPIOA_18_EVENT                               offsetof(RAP_TypeDef, GPIO0_18_EVNT_PUB_EN)
#define RAP_GPIOA_19_EVENT                               offsetof(RAP_TypeDef, GPIO0_19_EVNT_PUB_EN)
#define RAP_GPIOA_20_EVENT                               offsetof(RAP_TypeDef, GPIO0_20_EVNT_PUB_EN)
#define RAP_GPIOA_21_EVENT                               offsetof(RAP_TypeDef, GPIO0_21_EVNT_PUB_EN)
#define RAP_GPIOA_22_EVENT                               offsetof(RAP_TypeDef, GPIO0_22_EVNT_PUB_EN)
#define RAP_GPIOA_23_EVENT                               offsetof(RAP_TypeDef, GPIO0_23_EVNT_PUB_EN)
#define RAP_GPIOA_24_EVENT                               offsetof(RAP_TypeDef, GPIO0_24_EVNT_PUB_EN)
#define RAP_GPIOA_25_EVENT                               offsetof(RAP_TypeDef, GPIO0_25_EVNT_PUB_EN)
#define RAP_GPIOA_26_EVENT                               offsetof(RAP_TypeDef, GPIO0_26_EVNT_PUB_EN)
#define RAP_GPIOA_27_EVENT                               offsetof(RAP_TypeDef, GPIO0_27_EVNT_PUB_EN)
#define RAP_GPIOA_28_EVENT                               offsetof(RAP_TypeDef, GPIO0_28_EVNT_PUB_EN)
#define RAP_GPIOA_29_EVENT                               offsetof(RAP_TypeDef, GPIO0_29_EVNT_PUB_EN)
#define RAP_GPIOA_30_EVENT                               offsetof(RAP_TypeDef, GPIO0_30_EVNT_PUB_EN)
#define RAP_GPIOA_31_EVENT                               offsetof(RAP_TypeDef, GPIO0_31_EVNT_PUB_EN)
#define RAP_GPIOB_0_EVENT                                offsetof(RAP_TypeDef, GPIO0_32_EVNT_PUB_EN)
#define RAP_GPIOB_1_EVENT                                offsetof(RAP_TypeDef, GPIO0_33_EVNT_PUB_EN)
#define RAP_GPIOB_2_EVENT                                offsetof(RAP_TypeDef, GPIO0_34_EVNT_PUB_EN)
#define RAP_GPIOB_3_EVENT                                offsetof(RAP_TypeDef, GPIO0_35_EVNT_PUB_EN)
#define RAP_GPIOB_4_EVENT                                offsetof(RAP_TypeDef, GPIO0_36_EVNT_PUB_EN)
#define RAP_GPIOB_5_EVENT                                offsetof(RAP_TypeDef, GPIO0_37_EVNT_PUB_EN)
#define RAP_GPIOB_6_EVENT                                offsetof(RAP_TypeDef, GPIO0_38_EVNT_PUB_EN)
#define RAP_GPIOB_7_EVENT                                offsetof(RAP_TypeDef, GPIO0_39_EVNT_PUB_EN)
#define RAP_GPIOB_8_EVENT                                offsetof(RAP_TypeDef, GPIO0_40_EVNT_PUB_EN)
#define RAP_GPIOB_9_EVENT                                offsetof(RAP_TypeDef, GPIO0_41_EVNT_PUB_EN)
#define RAP_GPIOB_10_EVENT                               offsetof(RAP_TypeDef, GPIO0_42_EVNT_PUB_EN)
#define RAP_GPIOB_11_EVENT                               offsetof(RAP_TypeDef, GPIO0_43_EVNT_PUB_EN)
#define RAP_GPIOB_12_EVENT                               offsetof(RAP_TypeDef, GPIO0_44_EVNT_PUB_EN)
#define RAP_GPIOB_13_EVENT                               offsetof(RAP_TypeDef, GPIO0_45_EVNT_PUB_EN)
#define RAP_GPIOB_14_EVENT                               offsetof(RAP_TypeDef, GPIO0_46_EVNT_PUB_EN)
#define RAP_GPIOB_15_EVENT                               offsetof(RAP_TypeDef, GPIO0_47_EVNT_PUB_EN)
#define RAP_GPIOB_16_EVENT                               offsetof(RAP_TypeDef, GPIO0_48_EVNT_PUB_EN)
#define RAP_GPIOB_17_EVENT                               offsetof(RAP_TypeDef, GPIO0_49_EVNT_PUB_EN)
#define RAP_GPIOA_0_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_0_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_1_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_1_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_2_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_2_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_3_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_3_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_4_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_4_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_5_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_5_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_6_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_6_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_7_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_7_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_8_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_8_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_9_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_9_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_10_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_10_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_11_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_11_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_12_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_12_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_13_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_13_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_14_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_14_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_15_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_15_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_16_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_16_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_17_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_17_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_18_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_18_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_19_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_19_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_20_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_20_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_21_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_21_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_22_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_22_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_23_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_23_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_24_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_24_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_25_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_25_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_26_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_26_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_27_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_27_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_28_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_28_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_29_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_29_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_30_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_30_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_31_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_31_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_0_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_32_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_1_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_33_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_2_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_34_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_3_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_35_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_4_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_36_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_5_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_37_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_6_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_38_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_7_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_39_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_8_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_40_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_9_ACTION_DRCLR                         offsetof(RAP_TypeDef, GPIO0_41_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_10_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_42_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_11_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_43_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_12_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_44_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_13_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_45_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_14_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_46_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_15_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_47_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_16_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_48_TASK_DRCLR_SUB_EN)
#define RAP_GPIOB_17_ACTION_DRCLR                        offsetof(RAP_TypeDef, GPIO0_49_TASK_DRCLR_SUB_EN)
#define RAP_GPIOA_0_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_0_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_1_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_1_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_2_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_2_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_3_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_3_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_4_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_4_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_5_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_5_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_6_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_6_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_7_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_7_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_8_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_8_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_9_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_9_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_10_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_10_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_11_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_11_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_12_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_12_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_13_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_13_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_14_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_14_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_15_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_15_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_16_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_16_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_17_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_17_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_18_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_18_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_19_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_19_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_20_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_20_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_21_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_21_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_22_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_22_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_23_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_23_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_24_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_24_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_25_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_25_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_26_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_26_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_27_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_27_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_28_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_28_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_29_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_29_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_30_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_30_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_31_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_31_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_0_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_32_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_1_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_33_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_2_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_34_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_3_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_35_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_4_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_36_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_5_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_37_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_6_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_38_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_7_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_39_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_8_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_40_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_9_ACTION_DRSET                         offsetof(RAP_TypeDef, GPIO0_41_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_10_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_42_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_11_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_43_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_12_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_44_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_13_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_45_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_14_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_46_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_15_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_47_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_16_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_48_TASK_DRSET_SUB_EN)
#define RAP_GPIOB_17_ACTION_DRSET                        offsetof(RAP_TypeDef, GPIO0_49_TASK_DRSET_SUB_EN)
#define RAP_GPIOA_0_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_0_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_1_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_1_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_2_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_2_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_3_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_3_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_4_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_4_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_5_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_5_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_6_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_6_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_7_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_7_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_8_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_8_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_9_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_9_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_10_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_10_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_11_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_11_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_12_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_12_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_13_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_13_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_14_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_14_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_15_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_15_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_16_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_16_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_17_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_17_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_18_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_18_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_19_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_19_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_20_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_20_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_21_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_21_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_22_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_22_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_23_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_23_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_24_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_24_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_25_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_25_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_26_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_26_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_27_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_27_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_28_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_28_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_29_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_29_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_30_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_30_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOA_31_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_31_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_0_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_32_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_1_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_33_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_2_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_34_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_3_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_35_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_4_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_36_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_5_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_37_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_6_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_38_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_7_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_39_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_8_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_40_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_9_ACTION_DRTOGGLE                      offsetof(RAP_TypeDef, GPIO0_41_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_10_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_42_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_11_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_43_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_12_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_44_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_13_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_45_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_14_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_46_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_15_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_47_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_16_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_48_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIOB_17_ACTION_DRTOGGLE                     offsetof(RAP_TypeDef, GPIO0_49_TASK_DRTOGGLE_SUB_EN)
#define RAP_GPIO_ACTION_NOP                              offsetof(RAP_TypeDef, GPIO0_TASK_NOP_SUB_EN)
#define RAP_IR_EVENT_TXDONE                              offsetof(RAP_TypeDef, GIRDA_EVNT_TXDONE_PUB_EN)
#define RAP_IR_EVENT_RXDONE                              offsetof(RAP_TypeDef, GIRDA_EVNT_RXDONE_PUB_EN)
#define RAP_IR_ACTION_START_TX                           offsetof(RAP_TypeDef, GIRDA_TASK_START_TX_SUB_EN)
#define RAP_IR_ACTION_START_RX                           offsetof(RAP_TypeDef, GIRDA_TASK_START_RX_SUB_EN)
#define RAP_I2C0_EVENT_ERROR                             offsetof(RAP_TypeDef, I2C0_EVNT_ERROR_PUB_EN)
#define RAP_I2C0_EVENT_STARTED                           offsetof(RAP_TypeDef, I2C0_EVNT_STARTED_PUB_EN)
#define RAP_I2C0_EVENT_STOPPED                           offsetof(RAP_TypeDef, I2C0_EVNT_STOPPED_PUB_EN)
#define RAP_I2C0_ACTION_START                            offsetof(RAP_TypeDef, I2C0_TASK_START_SUB_EN)
#define RAP_I2C1_EVENT_ERROR                             offsetof(RAP_TypeDef, I2C1_EVNT_ERROR_PUB_EN)
#define RAP_I2C1_EVENT_STARTED                           offsetof(RAP_TypeDef, I2C1_EVNT_STARTED_PUB_EN)
#define RAP_I2C1_EVENT_STOPPED                           offsetof(RAP_TypeDef, I2C1_EVNT_STOPPED_PUB_EN)
#define RAP_I2C1_ACTION_START                            offsetof(RAP_TypeDef, I2C1_TASK_START_SUB_EN)
#define RAP_ADC_EVENT_DONE                               offsetof(RAP_TypeDef, AUXADC_EVNT_DONE_PUB_EN)
#define RAP_ADC_EVENT_RESULTDONE                         offsetof(RAP_TypeDef, AUXADC_EVNT_RESULTDONE_PUB_EN)
#define RAP_ADC_ACTION_ONE_SHOT_SAMPLE                   offsetof(RAP_TypeDef, AUXADC_TASK_ONE_SHOT_SAMPLE_SUB_EN)
#define RAP_SPI3WIRE_EVENT_END                           offsetof(RAP_TypeDef, SPI3WIRE_EVNT_END_PUB_EN)
#define RAP_SPI3WIRE_ACTION_START                        offsetof(RAP_TypeDef, SPI3WIRE_TASK_START_SUB_EN)
#define RAP_SPI0_EVENT_START                             offsetof(RAP_TypeDef, SPI0_EVNT_START_PUB_EN)
#define RAP_SPI0_EVENT_END                               offsetof(RAP_TypeDef, SPI0_EVNT_END_PUB_EN)
#define RAP_SPI0_ACTION_START                            offsetof(RAP_TypeDef, SPI0_TASK_START_SUB_EN)
#define RAP_SPI1_EVENT_START                             offsetof(RAP_TypeDef, SPI1_EVNT_START_PUB_EN)
#define RAP_SPI1_EVENT_END                               offsetof(RAP_TypeDef, SPI1_EVNT_END_PUB_EN)
#define RAP_SPI1_ACTION_START                            offsetof(RAP_TypeDef, SPI1_TASK_START_SUB_EN)
#define RAP_RTC_EVENT_TICK                               offsetof(RAP_TypeDef, RTC_EVNT_TICK_PUB_EN)
#define RAP_RTC_EVENT_OVERFLOW                           offsetof(RAP_TypeDef, RTC_EVNT_OVRFLW_PUB_EN)
#define RAP_RTC_EVENT_COMPARE0                           offsetof(RAP_TypeDef, RTC_EVNT_COMPARE0_PUB_EN)
#define RAP_RTC_EVENT_COMPARE1                           offsetof(RAP_TypeDef, RTC_EVNT_COMPARE1_PUB_EN)
#define RAP_RTC_EVENT_COMPARE2                           offsetof(RAP_TypeDef, RTC_EVNT_COMPARE2_PUB_EN)
#define RAP_RTC_EVENT_COMPARE3                           offsetof(RAP_TypeDef, RTC_EVNT_COMPARE3_PUB_EN)
#define RAP_RTC_ACTION_CLEAR                             offsetof(RAP_TypeDef, RTC_TASK_CLEAR_SUB_EN)
#define RAP_RTC_ACTION_STOP                              offsetof(RAP_TypeDef, RTC_TASK_STOP_SUB_EN)
#define RAP_RTC_ACTION_START                             offsetof(RAP_TypeDef, RTC_TASK_START_SUB_EN)
#define RAP_RTC_ACTION_RELOAD_CMP0                       offsetof(RAP_TypeDef, RTC_TASK_RELOAD_CMP0_SUB_EN)
#define RAP_RTC_ACTION_RELOAD_CMP1                       offsetof(RAP_TypeDef, RTC_TASK_RELOAD_CMP1_SUB_EN)
#define RAP_RTC_ACTION_RELOAD_CMP2                       offsetof(RAP_TypeDef, RTC_TASK_RELOAD_CMP2_SUB_EN)
#define RAP_RTC_ACTION_RELOAD_CMP3                       offsetof(RAP_TypeDef, RTC_TASK_RELOAD_CMP3_SUB_EN)
#define RAP_LPC_EVENT_STATUS                             offsetof(RAP_TypeDef, LPC_EVNT_STATUS_PUB_EN)
#define RAP_LPC_ACTION_START                             offsetof(RAP_TypeDef, LPC_TASK_START_SUB_EN)
#define RAP_LPC_ACTION_STOP                              offsetof(RAP_TypeDef, LPC_TASK_STOP_SUB_EN)
#define RAP_DMA_EVENT_INT_TRANSFER3                      offsetof(RAP_TypeDef, DMA_EVNT_INT_TFR3_PUB_EN)
#define RAP_DMA_EVENT_INT_TRANSFER4                      offsetof(RAP_TypeDef, DMA_EVNT_INT_TFR4_PUB_EN)
#define RAP_DMA_EVENT_INT_BLOCK3                         offsetof(RAP_TypeDef, DMA_EVNT_INT_BLK3_PUB_EN)
#define RAP_DMA_EVENT_INT_BLOCK4                         offsetof(RAP_TypeDef, DMA_EVNT_INT_BLK4_PUB_EN)
#define RAP_DMA_ACTION_CHANNEL_EN3                       offsetof(RAP_TypeDef, DMA_TASK_CHN_EN3_SUB_EN)
#define RAP_DMA_ACTION_CHANNEL_EN4                       offsetof(RAP_TypeDef, DMA_TASK_CHN_EN4_SUB_EN)
#define RAP_GRTC_EVENT_COMPARE0                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE0_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE1                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE1_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE2                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE2_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE3                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE3_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE4                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE4_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE5                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE5_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE6                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE6_PUB_EN)
#define RAP_GRTC_EVENT_COMPARE7                          offsetof(RAP_TypeDef, GRTC_EVNT_COMPARE7_PUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP0                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP0_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP1                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP1_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP2                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP2_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP3                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP3_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP4                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP4_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP5                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP5_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP6                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP6_SUB_EN)
#define RAP_GRTC_ACTION_RELOAD_CMP7                      offsetof(RAP_TypeDef, GRTC_TASK_RELOAD_CMP7_SUB_EN)
#define RAP_SDMK_EVENT_DONE                              offsetof(RAP_TypeDef, SDMK_EVNT_DONE_PUB_EN)
#define RAP_SDMK_ACTION_START                            offsetof(RAP_TypeDef, SDMK_TASK_START_SUB_EN)
#define RAP_OSC10M_EVENT_CAL_DONE                        offsetof(RAP_TypeDef, OSC10M_EVNT_CAL_DONE_PUB_EN)
#define RAP_OSC10M_ACTION_CAL                            offsetof(RAP_TypeDef, OSC10M_TASK_CAL_SUB_EN)
#define RAP_OSC80M_EVENT_CAL_DONE                        offsetof(RAP_TypeDef, OSC80M_EVNT_CAL_DONE_PUB_EN)
#define RAP_OSC80M_ACTION_CAL                            offsetof(RAP_TypeDef, OSC80M_TASK_CAL_SUB_EN)
#define RAP_TMETER_EVENT_DATARDY                         offsetof(RAP_TypeDef, TMETER_EVNT_DATARDY_PUB_EN)
#define RAP_TMETER_EVENT_ABS_CMP0                        offsetof(RAP_TypeDef, TMETER_EVNT_ABS_CMP0_PUB_EN)
#define RAP_TMETER_EVENT_ABS_CMP1                        offsetof(RAP_TypeDef, TMETER_EVNT_ABS_CMP1_PUB_EN)
#define RAP_TMETER_EVENT_ABS_CMP2                        offsetof(RAP_TypeDef, TMETER_EVNT_ABS_CMP2_PUB_EN)
#define RAP_TMETER_EVENT_ABS_CMP3                        offsetof(RAP_TypeDef, TMETER_EVNT_ABS_CMP3_PUB_EN)
#define RAP_TMETER_EVENT_REL_CMP0                        offsetof(RAP_TypeDef, TMETER_EVNT_REL_CMP0_PUB_EN)
#define RAP_TMETER_EVENT_REL_CMP1                        offsetof(RAP_TypeDef, TMETER_EVNT_REL_CMP1_PUB_EN)
#define RAP_TMETER_EVENT_REL_CMP2                        offsetof(RAP_TypeDef, TMETER_EVNT_REL_CMP2_PUB_EN)
#define RAP_TMETER_EVENT_REL_CMP3                        offsetof(RAP_TypeDef, TMETER_EVNT_REL_CMP3_PUB_EN)
#define RAP_TMETER_EVENT_FW_REL_COMP3                    offsetof(RAP_TypeDef, TMETER_EVNT_FW_REL_COMP3_PUB_EN)
#define RAP_TMETER_ACTION_ONESHOT                        offsetof(RAP_TypeDef, TMETER_TASK_ONESHOT_SUB_EN)

/*============================================================================*
 *                          RAP Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   6:0     R/W    r_debug_mux_sel[6:0]                                7'd0
   7       R      reserved_0_7                                        1'b0
   8       R      r_rap_intr                                          1'b0
   9       R      r_rap_gated_intr                                    1'b0
   10      R      reserved_0_10                                       1'b0
   11      W      r_intr_clr                                          1'b0
   12      R/W    r_en_rap_ctrl                                       1'b1
   15:13   R      reserved_0_15_13                                    3'h0
   16      R/W    r_rap_qactive_manual_data                           1'b0
   17      R/W    r_rap_qactive_manual_en                             1'b0
   18      R/W    r_rap_qactive_core_manual_data                      1'b0
   19      R/W    r_rap_qactive_core_manual_en                        1'b0
   20      R/W    r_rap_bus_qactive_manual_data                       1'b0
   21      R/W    r_rap_bus_qactive_manual_en                         1'b0
   31:22   R/W    r_rap_ctrl_dmy[31:22]                               10'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_debug_mux_sel_6_0: 7;
        const uint32_t reserved_2: 1;
        const uint32_t r_rap_intr: 1;
        const uint32_t r_rap_gated_intr: 1;
        const uint32_t reserved_1: 1;
        uint32_t r_intr_clr: 1;
        uint32_t r_en_rap_ctrl: 1;
        const uint32_t reserved_0: 3;
        uint32_t r_rap_qactive_manual_data: 1;
        uint32_t r_rap_qactive_manual_en: 1;
        uint32_t r_rap_qactive_core_manual_data: 1;
        uint32_t r_rap_qactive_core_manual_en: 1;
        uint32_t r_rap_bus_qactive_manual_data: 1;
        uint32_t r_rap_bus_qactive_manual_en: 1;
        uint32_t r_rap_ctrl_dmy_31_22: 10;
    } b;
} RAP_CTRL_TypeDef;



/* 0x04
   11:0    R/W    r_dlps_ch_en[11:0]                                  12'h3FF
   31:12   R      reserved_8_31_12                                    20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dlps_ch_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DLPS_CH_EN_TypeDef;



/* 0x08
   11:0    R/W    r_intr_en[11:0]                                     12'h000
   31:12   R      reserved_8_31_12                                    20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_intr_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} INTR_EN_TypeDef;


/* 0x0C
   11:0    R/W    r_intr_o_en[11:0]                                   12'h000
   31:12   R      reserved_c_31_12                                    20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_intr_o_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} INTR_O_EN_TypeDef;



/* 0x20
   11:0    R/W    r_aon_pad_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_20_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_aon_pad_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} AON_PAD_EVNT_PUB_EN_TypeDef;



/* 0x30
   11:0    R/W    r_enhtim_evnt_active_pub_en[11:0]                   12'h000
   31:12   R      reserved_30_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0x34
   11:0    R/W    r_enhtim_evnt_latch_cnt0_fifo_full_pub_en[11:0]     12'h000
   31:12   R      reserved_34_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_evnt_latch_cnt0_fifo_full_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_EVNT_LATCH_CNT0_FIFO_FULL_PUB_EN_TypeDef;


/* 0x38
   11:0    R/W    r_enhtim_evnt_latch_cnt0_fifo_met_th_pub_en[11:0]   12'h000
   31:12   R      reserved_38_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_evnt_latch_cnt0_fifo_met_th_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_EVNT_LATCH_CNT0_FIFO_MET_TH_PUB_EN_TypeDef;


/* 0x3C
   11:0    R/W    r_enhtim_evnt_stop_pub_en[11:0]                     12'h000
   31:12   R      reserved_3c_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_EVNT_STOP_PUB_EN_TypeDef;


/* 0x40
   11:0    R/W    r_enhtim_evnt_timeout_pub_en[11:0]                  12'h000
   31:12   R      reserved_40_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0x44
   11:0    R/W    r_enhtim_task_disable_sub_en[11:0]                  12'h000
   31:12   R      reserved_44_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x48
   11:0    R/W    r_enhtim_task_pause_sub_en[11:0]                    12'h000
   31:12   R      reserved_48_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x4C
   11:0    R/W    r_enhtim_task_start_sub_en[11:0]                    12'h000
   31:12   R      reserved_4c_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtim_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} ENHTIM_TASK_START_SUB_EN_TypeDef;



/* 0x54
   11:0    R/W    r_keyscan_evnt_manual_done_pub_en[11:0]             12'h000
   31:12   R      reserved_54_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_keyscan_evnt_manual_done_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} KEYSCAN_EVNT_MANUAL_DONE_PUB_EN_TypeDef;


/* 0x58
   11:0    R/W    r_keyscan_task_manual_sub_en[11:0]                  12'h000
   31:12   R      reserved_58_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_keyscan_task_manual_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} KEYSCAN_TASK_MANUAL_SUB_EN_TypeDef;



/* 0x60
   31:0    R      reserved_60_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_D0_TypeDef;


/* 0x64
   31:0    R      reserved_64_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_D4_TypeDef;


/* 0x68
   31:0    R      reserved_68_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_D8_TypeDef;


/* 0x6C
   31:0    R      reserved_6c_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_E0_TypeDef;


/* 0x70
   31:0    R      reserved_70_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_E4_TypeDef;


/* 0x74
   31:0    R      reserved_74_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_E8_TypeDef;


/* 0x78
   31:0    R      reserved_78_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_100_TypeDef;


/* 0x7C
   31:0    R      reserved_7c_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_104_TypeDef;


/* 0x80
   31:0    R      reserved_80_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_108_TypeDef;


/* 0x84
   31:0    R      reserved_84_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_110_TypeDef;


/* 0x88
   31:0    R      reserved_88_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_114_TypeDef;


/* 0x8C
   31:0    R      reserved_8c_31_0                                    32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} RESERVED_118_TypeDef;


/* 0x90
   11:0    R/W    r_tim1_ch0_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_90_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0x94
   11:0    R/W    r_tim1_ch0_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_94_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_EVNT_STOP_PUB_EN_TypeDef;


/* 0x98
   11:0    R/W    r_tim1_ch0_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_98_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0x9C
   11:0    R/W    r_tim1_ch1_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_9c_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xA0
   11:0    R/W    r_tim1_ch1_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_a0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_EVNT_STOP_PUB_EN_TypeDef;


/* 0xA4
   11:0    R/W    r_tim1_ch1_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_a4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xA8
   11:0    R/W    r_tim1_ch2_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_a8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xAC
   11:0    R/W    r_tim1_ch2_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_ac_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_EVNT_STOP_PUB_EN_TypeDef;


/* 0xB0
   11:0    R/W    r_tim1_ch2_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_b0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xB4
   11:0    R/W    r_tim1_ch3_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_b4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xB8
   11:0    R/W    r_tim1_ch3_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_b8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_EVNT_STOP_PUB_EN_TypeDef;


/* 0xBC
   11:0    R/W    r_tim1_ch3_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_bc_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xC0
   11:0    R/W    r_tim1_ch4_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_c0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xC4
   11:0    R/W    r_tim1_ch4_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_c4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_EVNT_STOP_PUB_EN_TypeDef;


/* 0xC8
   11:0    R/W    r_tim1_ch4_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_c8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xCC
   11:0    R/W    r_tim1_ch5_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_cc_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xD0
   11:0    R/W    r_tim1_ch5_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_d0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_EVNT_STOP_PUB_EN_TypeDef;


/* 0xD4
   11:0    R/W    r_tim1_ch5_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_d4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xD8
   11:0    R/W    r_tim1_ch6_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_d8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xDC
   11:0    R/W    r_tim1_ch6_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_dc_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_EVNT_STOP_PUB_EN_TypeDef;


/* 0xE0
   11:0    R/W    r_tim1_ch6_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_e0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xE4
   11:0    R/W    r_tim1_ch7_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_e4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xE8
   11:0    R/W    r_tim1_ch7_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_e8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_EVNT_STOP_PUB_EN_TypeDef;


/* 0xEC
   11:0    R/W    r_tim1_ch7_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_ec_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_EVNT_TIMEOUT_PUB_EN_TypeDef;


/* 0xF0
   11:0    R/W    r_tim1_ch8_evnt_active_pub_en[11:0]                 12'h000
   31:12   R      reserved_f0_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_evnt_active_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_EVNT_ACTIVE_PUB_EN_TypeDef;


/* 0xF4
   11:0    R/W    r_tim1_ch8_evnt_stop_pub_en[11:0]                   12'h000
   31:12   R      reserved_f4_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_evnt_stop_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_EVNT_STOP_PUB_EN_TypeDef;


/* 0xF8
   11:0    R/W    r_tim1_ch8_evnt_timeout_pub_en[11:0]                12'h000
   31:12   R      reserved_f8_31_12                                   20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_evnt_timeout_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_EVNT_TIMEOUT_PUB_EN_TypeDef;



/* 0x110
   11:0    R/W    r_tim1_ch0_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_110_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x114
   11:0    R/W    r_tim1_ch0_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_114_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x118
   11:0    R/W    r_tim1_ch0_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_118_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch0_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH0_TASK_START_SUB_EN_TypeDef;


/* 0x11C
   11:0    R/W    r_tim1_ch1_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_11c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x120
   11:0    R/W    r_tim1_ch1_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_120_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x124
   11:0    R/W    r_tim1_ch1_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_124_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch1_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH1_TASK_START_SUB_EN_TypeDef;


/* 0x128
   11:0    R/W    r_tim1_ch2_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_128_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x12C
   11:0    R/W    r_tim1_ch2_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_12c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x130
   11:0    R/W    r_tim1_ch2_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_130_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch2_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH2_TASK_START_SUB_EN_TypeDef;


/* 0x134
   11:0    R/W    r_tim1_ch3_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_134_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x138
   11:0    R/W    r_tim1_ch3_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_138_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x13C
   11:0    R/W    r_tim1_ch3_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_13c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch3_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH3_TASK_START_SUB_EN_TypeDef;


/* 0x140
   11:0    R/W    r_tim1_ch4_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_140_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x144
   11:0    R/W    r_tim1_ch4_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_144_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x148
   11:0    R/W    r_tim1_ch4_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_148_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch4_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH4_TASK_START_SUB_EN_TypeDef;


/* 0x14C
   11:0    R/W    r_tim1_ch5_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_14c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x150
   11:0    R/W    r_tim1_ch5_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_150_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x154
   11:0    R/W    r_tim1_ch5_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_154_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch5_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH5_TASK_START_SUB_EN_TypeDef;


/* 0x158
   11:0    R/W    r_tim1_ch6_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_158_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x15C
   11:0    R/W    r_tim1_ch6_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_15c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x160
   11:0    R/W    r_tim1_ch6_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_160_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch6_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH6_TASK_START_SUB_EN_TypeDef;


/* 0x164
   11:0    R/W    r_tim1_ch7_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_164_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x168
   11:0    R/W    r_tim1_ch7_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_168_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x16C
   11:0    R/W    r_tim1_ch7_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_16c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch7_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH7_TASK_START_SUB_EN_TypeDef;


/* 0x170
   11:0    R/W    r_tim1_ch8_task_disable_sub_en[11:0]                12'h000
   31:12   R      reserved_170_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_task_disable_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_TASK_DISABLE_SUB_EN_TypeDef;


/* 0x174
   11:0    R/W    r_tim1_ch8_task_pause_sub_en[11:0]                  12'h000
   31:12   R      reserved_174_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_task_pause_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_TASK_PAUSE_SUB_EN_TypeDef;


/* 0x178
   11:0    R/W    r_tim1_ch8_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_178_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tim1_ch8_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TIM1_CH8_TASK_START_SUB_EN_TypeDef;



/* 0x190
   11:0    R/W    r_gpio0_0_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_190_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_0_EVNT_PUB_EN_TypeDef;


/* 0x194
   11:0    R/W    r_gpio0_1_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_194_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_1_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_1_EVNT_PUB_EN_TypeDef;


/* 0x198
   11:0    R/W    r_gpio0_2_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_198_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_2_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_2_EVNT_PUB_EN_TypeDef;


/* 0x19C
   11:0    R/W    r_gpio0_3_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_19c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_3_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_3_EVNT_PUB_EN_TypeDef;


/* 0x1A0
   11:0    R/W    r_gpio0_4_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1a0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_4_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_4_EVNT_PUB_EN_TypeDef;


/* 0x1A4
   11:0    R/W    r_gpio0_5_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1a4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_5_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_5_EVNT_PUB_EN_TypeDef;


/* 0x1A8
   11:0    R/W    r_gpio0_6_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1a8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_6_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_6_EVNT_PUB_EN_TypeDef;


/* 0x1AC
   11:0    R/W    r_gpio0_7_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1ac_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_7_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_7_EVNT_PUB_EN_TypeDef;


/* 0x1B0
   11:0    R/W    r_gpio0_8_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1b0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_8_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_8_EVNT_PUB_EN_TypeDef;


/* 0x1B4
   11:0    R/W    r_gpio0_9_evnt_pub_en[11:0]                         12'h000
   31:12   R      reserved_1b4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_9_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_9_EVNT_PUB_EN_TypeDef;


/* 0x1B8
   11:0    R/W    r_gpio0_10_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1b8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_10_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_10_EVNT_PUB_EN_TypeDef;


/* 0x1BC
   11:0    R/W    r_gpio0_11_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1bc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_11_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_11_EVNT_PUB_EN_TypeDef;


/* 0x1C0
   11:0    R/W    r_gpio0_12_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1c0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_12_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_12_EVNT_PUB_EN_TypeDef;


/* 0x1C4
   11:0    R/W    r_gpio0_13_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1c4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_13_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_13_EVNT_PUB_EN_TypeDef;


/* 0x1C8
   11:0    R/W    r_gpio0_14_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1c8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_14_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_14_EVNT_PUB_EN_TypeDef;


/* 0x1CC
   11:0    R/W    r_gpio0_15_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1cc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_15_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_15_EVNT_PUB_EN_TypeDef;


/* 0x1D0
   11:0    R/W    r_gpio0_16_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1d0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_16_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_16_EVNT_PUB_EN_TypeDef;


/* 0x1D4
   11:0    R/W    r_gpio0_17_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1d4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_17_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_17_EVNT_PUB_EN_TypeDef;


/* 0x1D8
   11:0    R/W    r_gpio0_18_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1d8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_18_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_18_EVNT_PUB_EN_TypeDef;


/* 0x1DC
   11:0    R/W    r_gpio0_19_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1dc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_19_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_19_EVNT_PUB_EN_TypeDef;


/* 0x1E0
   11:0    R/W    r_gpio0_20_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1e0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_20_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_20_EVNT_PUB_EN_TypeDef;


/* 0x1E4
   11:0    R/W    r_gpio0_21_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1e4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_21_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_21_EVNT_PUB_EN_TypeDef;


/* 0x1E8
   11:0    R/W    r_gpio0_22_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1e8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_22_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_22_EVNT_PUB_EN_TypeDef;


/* 0x1EC
   11:0    R/W    r_gpio0_23_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1ec_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_23_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_23_EVNT_PUB_EN_TypeDef;


/* 0x1F0
   11:0    R/W    r_gpio0_24_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1f0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_24_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_24_EVNT_PUB_EN_TypeDef;


/* 0x1F4
   11:0    R/W    r_gpio0_25_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1f4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_25_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_25_EVNT_PUB_EN_TypeDef;


/* 0x1F8
   11:0    R/W    r_gpio0_26_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1f8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_26_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_26_EVNT_PUB_EN_TypeDef;


/* 0x1FC
   11:0    R/W    r_gpio0_27_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_1fc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_27_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_27_EVNT_PUB_EN_TypeDef;


/* 0x200
   11:0    R/W    r_gpio0_28_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_200_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_28_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_28_EVNT_PUB_EN_TypeDef;


/* 0x204
   11:0    R/W    r_gpio0_29_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_204_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_29_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_29_EVNT_PUB_EN_TypeDef;


/* 0x208
   11:0    R/W    r_gpio0_30_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_208_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_30_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_30_EVNT_PUB_EN_TypeDef;


/* 0x20C
   11:0    R/W    r_gpio0_31_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_20c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_31_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_31_EVNT_PUB_EN_TypeDef;


/* 0x210
   11:0    R/W    r_gpio0_32_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_210_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_32_EVNT_PUB_EN_TypeDef;


/* 0x214
   11:0    R/W    r_gpio0_33_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_214_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_33_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_33_EVNT_PUB_EN_TypeDef;


/* 0x218
   11:0    R/W    r_gpio0_34_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_218_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_34_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_34_EVNT_PUB_EN_TypeDef;


/* 0x21C
   11:0    R/W    r_gpio0_35_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_21c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_35_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_35_EVNT_PUB_EN_TypeDef;


/* 0x220
   11:0    R/W    r_gpio0_36_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_220_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_36_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_36_EVNT_PUB_EN_TypeDef;


/* 0x224
   11:0    R/W    r_gpio0_37_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_224_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_37_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_37_EVNT_PUB_EN_TypeDef;


/* 0x228
   11:0    R/W    r_gpio0_38_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_228_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_38_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_38_EVNT_PUB_EN_TypeDef;


/* 0x22C
   11:0    R/W    r_gpio0_39_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_22c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_39_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_39_EVNT_PUB_EN_TypeDef;


/* 0x230
   11:0    R/W    r_gpio0_40_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_230_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_40_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_40_EVNT_PUB_EN_TypeDef;


/* 0x234
   11:0    R/W    r_gpio0_41_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_234_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_41_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_41_EVNT_PUB_EN_TypeDef;


/* 0x238
   11:0    R/W    r_gpio0_42_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_238_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_42_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_42_EVNT_PUB_EN_TypeDef;


/* 0x23C
   11:0    R/W    r_gpio0_43_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_23c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_43_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_43_EVNT_PUB_EN_TypeDef;


/* 0x240
   11:0    R/W    r_gpio0_44_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_240_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_44_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_44_EVNT_PUB_EN_TypeDef;


/* 0x244
   11:0    R/W    r_gpio0_45_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_244_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_45_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_45_EVNT_PUB_EN_TypeDef;


/* 0x248
   11:0    R/W    r_gpio0_46_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_248_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_46_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_46_EVNT_PUB_EN_TypeDef;


/* 0x24C
   11:0    R/W    r_gpio0_47_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_24c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_47_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_47_EVNT_PUB_EN_TypeDef;


/* 0x250
   11:0    R/W    r_gpio0_48_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_250_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_48_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_48_EVNT_PUB_EN_TypeDef;


/* 0x254
   11:0    R/W    r_gpio0_49_evnt_pub_en[11:0]                        12'h000
   31:12   R      reserved_254_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_49_evnt_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_49_EVNT_PUB_EN_TypeDef;



/* 0x430
   11:0    R/W    r_gpio0_0_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_430_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_0_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x434
   11:0    R/W    r_gpio0_1_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_434_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_1_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_1_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x438
   11:0    R/W    r_gpio0_2_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_438_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_2_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_2_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x43C
   11:0    R/W    r_gpio0_3_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_43c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_3_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_3_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x440
   11:0    R/W    r_gpio0_4_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_440_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_4_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_4_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x444
   11:0    R/W    r_gpio0_5_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_444_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_5_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_5_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x448
   11:0    R/W    r_gpio0_6_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_448_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_6_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_6_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x44C
   11:0    R/W    r_gpio0_7_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_44c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_7_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_7_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x450
   11:0    R/W    r_gpio0_8_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_450_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_8_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_8_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x454
   11:0    R/W    r_gpio0_9_task_drclr_sub_en[11:0]                   12'h000
   31:12   R      reserved_454_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_9_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_9_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x458
   11:0    R/W    r_gpio0_10_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_458_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_10_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_10_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x45C
   11:0    R/W    r_gpio0_11_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_45c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_11_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_11_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x460
   11:0    R/W    r_gpio0_12_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_460_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_12_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_12_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x464
   11:0    R/W    r_gpio0_13_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_464_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_13_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_13_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x468
   11:0    R/W    r_gpio0_14_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_468_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_14_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_14_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x46C
   11:0    R/W    r_gpio0_15_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_46c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_15_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_15_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x470
   11:0    R/W    r_gpio0_16_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_470_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_16_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_16_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x474
   11:0    R/W    r_gpio0_17_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_474_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_17_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_17_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x478
   11:0    R/W    r_gpio0_18_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_478_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_18_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_18_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x47C
   11:0    R/W    r_gpio0_19_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_47c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_19_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_19_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x480
   11:0    R/W    r_gpio0_20_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_480_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_20_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_20_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x484
   11:0    R/W    r_gpio0_21_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_484_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_21_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_21_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x488
   11:0    R/W    r_gpio0_22_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_488_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_22_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_22_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x48C
   11:0    R/W    r_gpio0_23_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_48c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_23_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_23_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x490
   11:0    R/W    r_gpio0_24_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_490_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_24_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_24_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x494
   11:0    R/W    r_gpio0_25_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_494_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_25_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_25_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x498
   11:0    R/W    r_gpio0_26_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_498_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_26_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_26_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x49C
   11:0    R/W    r_gpio0_27_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_49c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_27_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_27_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4A0
   11:0    R/W    r_gpio0_28_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4a0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_28_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_28_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4A4
   11:0    R/W    r_gpio0_29_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4a4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_29_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_29_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4A8
   11:0    R/W    r_gpio0_30_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4a8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_30_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_30_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4AC
   11:0    R/W    r_gpio0_31_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4ac_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_31_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_31_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4B0
   11:0    R/W    r_gpio0_32_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4b0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_32_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4B4
   11:0    R/W    r_gpio0_33_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4b4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_33_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_33_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4B8
   11:0    R/W    r_gpio0_34_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4b8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_34_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_34_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4BC
   11:0    R/W    r_gpio0_35_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4bc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_35_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_35_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4C0
   11:0    R/W    r_gpio0_36_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4c0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_36_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_36_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4C4
   11:0    R/W    r_gpio0_37_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4c4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_37_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_37_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4C8
   11:0    R/W    r_gpio0_38_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4c8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_38_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_38_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4CC
   11:0    R/W    r_gpio0_39_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4cc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_39_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_39_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4D0
   11:0    R/W    r_gpio0_40_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4d0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_40_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_40_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4D4
   11:0    R/W    r_gpio0_41_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4d4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_41_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_41_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4D8
   11:0    R/W    r_gpio0_42_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4d8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_42_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_42_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4DC
   11:0    R/W    r_gpio0_43_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4dc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_43_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_43_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4E0
   11:0    R/W    r_gpio0_44_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4e0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_44_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_44_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4E4
   11:0    R/W    r_gpio0_45_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4e4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_45_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_45_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4E8
   11:0    R/W    r_gpio0_46_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4e8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_46_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_46_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4EC
   11:0    R/W    r_gpio0_47_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4ec_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_47_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_47_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4F0
   11:0    R/W    r_gpio0_48_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4f0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_48_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_48_TASK_DRCLR_SUB_EN_TypeDef;


/* 0x4F4
   11:0    R/W    r_gpio0_49_task_drclr_sub_en[11:0]                  12'h000
   31:12   R      reserved_4f4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_49_task_drclr_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_49_TASK_DRCLR_SUB_EN_TypeDef;



/* 0x510
   11:0    R/W    r_gpio0_0_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_510_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_0_TASK_DRSET_SUB_EN_TypeDef;


/* 0x514
   11:0    R/W    r_gpio0_1_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_514_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_1_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_1_TASK_DRSET_SUB_EN_TypeDef;


/* 0x518
   11:0    R/W    r_gpio0_2_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_518_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_2_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_2_TASK_DRSET_SUB_EN_TypeDef;


/* 0x51C
   11:0    R/W    r_gpio0_3_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_51c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_3_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_3_TASK_DRSET_SUB_EN_TypeDef;


/* 0x520
   11:0    R/W    r_gpio0_4_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_520_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_4_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_4_TASK_DRSET_SUB_EN_TypeDef;


/* 0x524
   11:0    R/W    r_gpio0_5_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_524_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_5_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_5_TASK_DRSET_SUB_EN_TypeDef;


/* 0x528
   11:0    R/W    r_gpio0_6_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_528_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_6_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_6_TASK_DRSET_SUB_EN_TypeDef;


/* 0x52C
   11:0    R/W    r_gpio0_7_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_52c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_7_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_7_TASK_DRSET_SUB_EN_TypeDef;


/* 0x530
   11:0    R/W    r_gpio0_8_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_530_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_8_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_8_TASK_DRSET_SUB_EN_TypeDef;


/* 0x534
   11:0    R/W    r_gpio0_9_task_drset_sub_en[11:0]                   12'h000
   31:12   R      reserved_534_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_9_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_9_TASK_DRSET_SUB_EN_TypeDef;


/* 0x538
   11:0    R/W    r_gpio0_10_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_538_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_10_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_10_TASK_DRSET_SUB_EN_TypeDef;


/* 0x53C
   11:0    R/W    r_gpio0_11_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_53c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_11_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_11_TASK_DRSET_SUB_EN_TypeDef;


/* 0x540
   11:0    R/W    r_gpio0_12_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_540_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_12_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_12_TASK_DRSET_SUB_EN_TypeDef;


/* 0x544
   11:0    R/W    r_gpio0_13_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_544_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_13_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_13_TASK_DRSET_SUB_EN_TypeDef;


/* 0x548
   11:0    R/W    r_gpio0_14_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_548_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_14_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_14_TASK_DRSET_SUB_EN_TypeDef;


/* 0x54C
   11:0    R/W    r_gpio0_15_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_54c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_15_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_15_TASK_DRSET_SUB_EN_TypeDef;


/* 0x550
   11:0    R/W    r_gpio0_16_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_550_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_16_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_16_TASK_DRSET_SUB_EN_TypeDef;


/* 0x554
   11:0    R/W    r_gpio0_17_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_554_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_17_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_17_TASK_DRSET_SUB_EN_TypeDef;


/* 0x558
   11:0    R/W    r_gpio0_18_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_558_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_18_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_18_TASK_DRSET_SUB_EN_TypeDef;


/* 0x55C
   11:0    R/W    r_gpio0_19_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_55c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_19_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_19_TASK_DRSET_SUB_EN_TypeDef;


/* 0x560
   11:0    R/W    r_gpio0_20_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_560_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_20_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_20_TASK_DRSET_SUB_EN_TypeDef;


/* 0x564
   11:0    R/W    r_gpio0_21_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_564_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_21_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_21_TASK_DRSET_SUB_EN_TypeDef;


/* 0x568
   11:0    R/W    r_gpio0_22_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_568_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_22_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_22_TASK_DRSET_SUB_EN_TypeDef;


/* 0x56C
   11:0    R/W    r_gpio0_23_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_56c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_23_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_23_TASK_DRSET_SUB_EN_TypeDef;


/* 0x570
   11:0    R/W    r_gpio0_24_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_570_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_24_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_24_TASK_DRSET_SUB_EN_TypeDef;


/* 0x574
   11:0    R/W    r_gpio0_25_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_574_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_25_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_25_TASK_DRSET_SUB_EN_TypeDef;


/* 0x578
   11:0    R/W    r_gpio0_26_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_578_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_26_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_26_TASK_DRSET_SUB_EN_TypeDef;


/* 0x57C
   11:0    R/W    r_gpio0_27_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_57c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_27_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_27_TASK_DRSET_SUB_EN_TypeDef;


/* 0x580
   11:0    R/W    r_gpio0_28_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_580_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_28_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_28_TASK_DRSET_SUB_EN_TypeDef;


/* 0x584
   11:0    R/W    r_gpio0_29_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_584_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_29_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_29_TASK_DRSET_SUB_EN_TypeDef;


/* 0x588
   11:0    R/W    r_gpio0_30_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_588_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_30_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_30_TASK_DRSET_SUB_EN_TypeDef;


/* 0x58C
   11:0    R/W    r_gpio0_31_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_58c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_31_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_31_TASK_DRSET_SUB_EN_TypeDef;


/* 0x590
   11:0    R/W    r_gpio0_32_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_590_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_32_TASK_DRSET_SUB_EN_TypeDef;


/* 0x594
   11:0    R/W    r_gpio0_33_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_594_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_33_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_33_TASK_DRSET_SUB_EN_TypeDef;


/* 0x598
   11:0    R/W    r_gpio0_34_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_598_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_34_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_34_TASK_DRSET_SUB_EN_TypeDef;


/* 0x59C
   11:0    R/W    r_gpio0_35_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_59c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_35_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_35_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5A0
   11:0    R/W    r_gpio0_36_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5a0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_36_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_36_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5A4
   11:0    R/W    r_gpio0_37_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5a4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_37_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_37_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5A8
   11:0    R/W    r_gpio0_38_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5a8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_38_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_38_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5AC
   11:0    R/W    r_gpio0_39_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5ac_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_39_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_39_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5B0
   11:0    R/W    r_gpio0_40_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5b0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_40_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_40_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5B4
   11:0    R/W    r_gpio0_41_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5b4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_41_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_41_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5B8
   11:0    R/W    r_gpio0_42_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5b8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_42_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_42_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5BC
   11:0    R/W    r_gpio0_43_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5bc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_43_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_43_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5C0
   11:0    R/W    r_gpio0_44_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5c0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_44_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_44_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5C4
   11:0    R/W    r_gpio0_45_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5c4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_45_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_45_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5C8
   11:0    R/W    r_gpio0_46_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5c8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_46_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_46_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5CC
   11:0    R/W    r_gpio0_47_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5cc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_47_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_47_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5D0
   11:0    R/W    r_gpio0_48_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5d0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_48_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_48_TASK_DRSET_SUB_EN_TypeDef;


/* 0x5D4
   11:0    R/W    r_gpio0_49_task_drset_sub_en[11:0]                  12'h000
   31:12   R      reserved_5d4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_49_task_drset_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_49_TASK_DRSET_SUB_EN_TypeDef;



/* 0x5F0
   11:0    R/W    r_gpio0_0_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_5f0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_0_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x5F4
   11:0    R/W    r_gpio0_1_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_5f4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_1_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_1_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x5F8
   11:0    R/W    r_gpio0_2_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_5f8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_2_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_2_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x5FC
   11:0    R/W    r_gpio0_3_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_5fc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_3_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_3_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x600
   11:0    R/W    r_gpio0_4_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_600_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_4_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_4_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x604
   11:0    R/W    r_gpio0_5_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_604_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_5_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_5_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x608
   11:0    R/W    r_gpio0_6_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_608_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_6_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_6_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x60C
   11:0    R/W    r_gpio0_7_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_60c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_7_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_7_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x610
   11:0    R/W    r_gpio0_8_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_610_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_8_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_8_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x614
   11:0    R/W    r_gpio0_9_task_drtoggle_sub_en[11:0]                12'h000
   31:12   R      reserved_614_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_9_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_9_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x618
   11:0    R/W    r_gpio0_10_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_618_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_10_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_10_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x61C
   11:0    R/W    r_gpio0_11_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_61c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_11_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_11_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x620
   11:0    R/W    r_gpio0_12_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_620_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_12_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_12_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x624
   11:0    R/W    r_gpio0_13_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_624_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_13_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_13_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x628
   11:0    R/W    r_gpio0_14_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_628_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_14_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_14_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x62C
   11:0    R/W    r_gpio0_15_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_62c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_15_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_15_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x630
   11:0    R/W    r_gpio0_16_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_630_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_16_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_16_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x634
   11:0    R/W    r_gpio0_17_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_634_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_17_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_17_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x638
   11:0    R/W    r_gpio0_18_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_638_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_18_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_18_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x63C
   11:0    R/W    r_gpio0_19_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_63c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_19_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_19_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x640
   11:0    R/W    r_gpio0_20_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_640_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_20_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_20_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x644
   11:0    R/W    r_gpio0_21_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_644_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_21_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_21_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x648
   11:0    R/W    r_gpio0_22_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_648_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_22_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_22_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x64C
   11:0    R/W    r_gpio0_23_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_64c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_23_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_23_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x650
   11:0    R/W    r_gpio0_24_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_650_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_24_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_24_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x654
   11:0    R/W    r_gpio0_25_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_654_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_25_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_25_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x658
   11:0    R/W    r_gpio0_26_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_658_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_26_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_26_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x65C
   11:0    R/W    r_gpio0_27_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_65c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_27_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_27_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x660
   11:0    R/W    r_gpio0_28_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_660_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_28_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_28_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x664
   11:0    R/W    r_gpio0_29_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_664_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_29_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_29_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x668
   11:0    R/W    r_gpio0_30_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_668_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_30_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_30_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x66C
   11:0    R/W    r_gpio0_31_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_66c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_31_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_31_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x670
   11:0    R/W    r_gpio0_32_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_670_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_32_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x674
   11:0    R/W    r_gpio0_33_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_674_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_33_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_33_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x678
   11:0    R/W    r_gpio0_34_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_678_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_34_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_34_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x67C
   11:0    R/W    r_gpio0_35_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_67c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_35_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_35_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x680
   11:0    R/W    r_gpio0_36_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_680_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_36_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_36_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x684
   11:0    R/W    r_gpio0_37_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_684_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_37_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_37_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x688
   11:0    R/W    r_gpio0_38_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_688_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_38_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_38_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x68C
   11:0    R/W    r_gpio0_39_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_68c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_39_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_39_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x690
   11:0    R/W    r_gpio0_40_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_690_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_40_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_40_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x694
   11:0    R/W    r_gpio0_41_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_694_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_41_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_41_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x698
   11:0    R/W    r_gpio0_42_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_698_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_42_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_42_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x69C
   11:0    R/W    r_gpio0_43_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_69c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_43_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_43_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6A0
   11:0    R/W    r_gpio0_44_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6a0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_44_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_44_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6A4
   11:0    R/W    r_gpio0_45_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6a4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_45_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_45_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6A8
   11:0    R/W    r_gpio0_46_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6a8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_46_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_46_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6AC
   11:0    R/W    r_gpio0_47_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6ac_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_47_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_47_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6B0
   11:0    R/W    r_gpio0_48_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6b0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_48_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_48_TASK_DRTOGGLE_SUB_EN_TypeDef;


/* 0x6B4
   11:0    R/W    r_gpio0_49_task_drtoggle_sub_en[11:0]               12'h000
   31:12   R      reserved_6b4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_49_task_drtoggle_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_49_TASK_DRTOGGLE_SUB_EN_TypeDef;



/* 0x6B8
   11:0    R/W    r_gpio0_task_nop_sub_en[11:0]                       12'h000
   31:12   R      reserved_6b8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_task_nop_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GPIO0_TASK_NOP_SUB_EN_TypeDef;



/* 0x970
   11:0    R/W    r_girda_evnt_txdone_pub_en[11:0]                    12'h000
   31:12   R      reserved_970_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_girda_evnt_txdone_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GIRDA_EVNT_TXDONE_PUB_EN_TypeDef;


/* 0x974
   11:0    R/W    r_girda_evnt_rxdone_pub_en[11:0]                    12'h000
   31:12   R      reserved_974_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_girda_evnt_rxdone_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GIRDA_EVNT_RXDONE_PUB_EN_TypeDef;


/* 0x978
   11:0    R/W    r_girda_task_start_tx_sub_en[11:0]                  12'h000
   31:12   R      reserved_978_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_girda_task_start_tx_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GIRDA_TASK_START_TX_SUB_EN_TypeDef;


/* 0x97C
   11:0    R/W    r_girda_task_start_rx_sub_en[11:0]                  12'h000
   31:12   R      reserved_97c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_girda_task_start_rx_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GIRDA_TASK_START_RX_SUB_EN_TypeDef;



/* 0x990
   11:0    R/W    r_i2c0_evnt_error_pub_en[11:0]                      12'h000
   31:12   R      reserved_990_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c0_evnt_error_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C0_EVNT_ERROR_PUB_EN_TypeDef;


/* 0x994
   11:0    R/W    r_i2c0_evnt_started_pub_en[11:0]                    12'h000
   31:12   R      reserved_994_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c0_evnt_started_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C0_EVNT_STARTED_PUB_EN_TypeDef;


/* 0x998
   11:0    R/W    r_i2c0_evnt_stopped_pub_en[11:0]                    12'h000
   31:12   R      reserved_998_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c0_evnt_stopped_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C0_EVNT_STOPPED_PUB_EN_TypeDef;


/* 0x99C
   11:0    R/W    r_i2c0_task_start_sub_en[11:0]                      12'h000
   31:12   R      reserved_99c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c0_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C0_TASK_START_SUB_EN_TypeDef;



/* 0x9B0
   11:0    R/W    r_i2c1_evnt_error_pub_en[11:0]                      12'h000
   31:12   R      reserved_9b0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c1_evnt_error_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C1_EVNT_ERROR_PUB_EN_TypeDef;


/* 0x9B4
   11:0    R/W    r_i2c1_evnt_started_pub_en[11:0]                    12'h000
   31:12   R      reserved_9b4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c1_evnt_started_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C1_EVNT_STARTED_PUB_EN_TypeDef;


/* 0x9B8
   11:0    R/W    r_i2c1_evnt_stopped_pub_en[11:0]                    12'h000
   31:12   R      reserved_9b8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c1_evnt_stopped_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C1_EVNT_STOPPED_PUB_EN_TypeDef;


/* 0x9BC
   11:0    R/W    r_i2c1_task_start_sub_en[11:0]                      12'h000
   31:12   R      reserved_9bc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c1_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} I2C1_TASK_START_SUB_EN_TypeDef;



/* 0x9D0
   11:0    R/W    r_auxadc_evnt_done_pub_en[11:0]                     12'h000
   31:12   R      reserved_9d0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_auxadc_evnt_done_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} AUXADC_EVNT_DONE_PUB_EN_TypeDef;


/* 0x9D4
   11:0    R/W    r_auxadc_evnt_resultdone_pub_en[11:0]               12'h000
   31:12   R      reserved_9d4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_auxadc_evnt_resultdone_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} AUXADC_EVNT_RESULTDONE_PUB_EN_TypeDef;


/* 0x9D8
   11:0    R/W    r_auxadc_task_one_shot_sample_sub_en[11:0]          12'h000
   31:12   R      reserved_9d8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_auxadc_task_one_shot_sample_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} AUXADC_TASK_ONE_SHOT_SAMPLE_SUB_EN_TypeDef;



/* 0x9F0
   11:0    R/W    r_spi3wire_evnt_end_pub_en[11:0]                    12'h000
   31:12   R      reserved_9f0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi3wire_evnt_end_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI3WIRE_EVNT_END_PUB_EN_TypeDef;


/* 0x9F4
   11:0    R/W    r_spi3wire_task_start_sub_en[11:0]                  12'h000
   31:12   R      reserved_9f4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi3wire_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI3WIRE_TASK_START_SUB_EN_TypeDef;



/* 0xA10
   11:0    R/W    r_spi0_evnt_start_pub_en[11:0]                      12'h000
   31:12   R      reserved_a10_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi0_evnt_start_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI0_EVNT_START_PUB_EN_TypeDef;


/* 0xA14
   11:0    R/W    r_spi0_evnt_end_pub_en[11:0]                        12'h000
   31:12   R      reserved_a14_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi0_evnt_end_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI0_EVNT_END_PUB_EN_TypeDef;


/* 0xA18
   11:0    R/W    r_spi0_task_start_sub_en[11:0]                      12'h000
   31:12   R      reserved_a18_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi0_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI0_TASK_START_SUB_EN_TypeDef;



/* 0xA30
   11:0    R/W    r_spi1_evnt_start_pub_en[11:0]                      12'h000
   31:12   R      reserved_a30_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi1_evnt_start_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI1_EVNT_START_PUB_EN_TypeDef;


/* 0xA34
   11:0    R/W    r_spi1_evnt_end_pub_en[11:0]                        12'h000
   31:12   R      reserved_a34_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi1_evnt_end_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI1_EVNT_END_PUB_EN_TypeDef;


/* 0xA38
   11:0    R/W    r_spi1_task_start_sub_en[11:0]                      12'h000
   31:12   R      reserved_a38_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi1_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SPI1_TASK_START_SUB_EN_TypeDef;



/* 0xA70
   11:0    R/W    r_rtc_evnt_tick_pub_en[11:0]                        12'h000
   31:12   R      reserved_a70_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_tick_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_TICK_PUB_EN_TypeDef;


/* 0xA74
   11:0    R/W    r_rtc_evnt_ovrflw_pub_en[11:0]                      12'h000
   31:12   R      reserved_a74_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_ovrflw_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_OVRFLW_PUB_EN_TypeDef;


/* 0xA78
   11:0    R/W    r_rtc_evnt_compare0_pub_en[11:0]                    12'h000
   31:12   R      reserved_a78_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_compare0_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_COMPARE0_PUB_EN_TypeDef;


/* 0xA7C
   11:0    R/W    r_rtc_evnt_compare1_pub_en[11:0]                    12'h000
   31:12   R      reserved_a7c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_compare1_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_COMPARE1_PUB_EN_TypeDef;


/* 0xA80
   11:0    R/W    r_rtc_evnt_compare2_pub_en[11:0]                    12'h000
   31:12   R      reserved_a80_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_compare2_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_COMPARE2_PUB_EN_TypeDef;


/* 0xA84
   11:0    R/W    r_rtc_evnt_compare3_pub_en[11:0]                    12'h000
   31:12   R      reserved_a84_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_compare3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_EVNT_COMPARE3_PUB_EN_TypeDef;


/* 0xA88
   11:0    R/W    r_rtc_task_clear_sub_en[11:0]                       12'h000
   31:12   R      reserved_a88_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_clear_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_CLEAR_SUB_EN_TypeDef;


/* 0xA8C
   11:0    R/W    r_rtc_task_stop_sub_en[11:0]                        12'h000
   31:12   R      reserved_a8c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_stop_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_STOP_SUB_EN_TypeDef;


/* 0xA90
   11:0    R/W    r_rtc_task_start_sub_en[11:0]                       12'h000
   31:12   R      reserved_a90_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_START_SUB_EN_TypeDef;


/* 0xA94
   11:0    R/W    r_rtc_task_reload_cmp0_sub_en[11:0]                 12'h000
   31:12   R      reserved_a94_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_reload_cmp0_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_RELOAD_CMP0_SUB_EN_TypeDef;


/* 0xA98
   11:0    R/W    r_rtc_task_reload_cmp1_sub_en[11:0]                 12'h000
   31:12   R      reserved_a98_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_reload_cmp1_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_RELOAD_CMP1_SUB_EN_TypeDef;


/* 0xA9C
   11:0    R/W    r_rtc_task_reload_cmp2_sub_en[11:0]                 12'h000
   31:12   R      reserved_a9c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_reload_cmp2_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_RELOAD_CMP2_SUB_EN_TypeDef;


/* 0xAA0
   11:0    R/W    r_rtc_task_reload_cmp3_sub_en[11:0]                 12'h000
   31:12   R      reserved_aa0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_task_reload_cmp3_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} RTC_TASK_RELOAD_CMP3_SUB_EN_TypeDef;



/* 0xAB0
   11:0    R/W    r_lpc_evnt_status_pub_en[11:0]                      12'h000
   31:12   R      reserved_ab0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_lpc_evnt_status_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} LPC_EVNT_STATUS_PUB_EN_TypeDef;


/* 0xAB4
   11:0    R/W    r_lpc_task_start_sub_en[11:0]                       12'h000
   31:12   R      reserved_ab4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_lpc_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} LPC_TASK_START_SUB_EN_TypeDef;


/* 0xAB8
   11:0    R/W    r_lpc_task_stop_sub_en[11:0]                        12'h000
   31:12   R      reserved_ab8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_lpc_task_stop_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} LPC_TASK_STOP_SUB_EN_TypeDef;



/* 0xAFC
   11:0    R/W    r_dma_evnt_int_tfr3_pub_en[11:0]                    12'h000
   31:12   R      reserved_afc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_evnt_int_tfr3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_EVNT_INT_TFR3_PUB_EN_TypeDef;


/* 0xB00
   11:0    R/W    r_dma_evnt_int_tfr4_pub_en[11:0]                    12'h000
   31:12   R      reserved_b00_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_evnt_int_tfr4_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_EVNT_INT_TFR4_PUB_EN_TypeDef;



/* 0xB1C
   11:0    R/W    r_dma_evnt_int_blk3_pub_en[11:0]                    12'h000
   31:12   R      reserved_b1c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_evnt_int_blk3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_EVNT_INT_BLK3_PUB_EN_TypeDef;


/* 0xB20
   11:0    R/W    r_dma_evnt_int_blk4_pub_en[11:0]                    12'h000
   31:12   R      reserved_b20_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_evnt_int_blk4_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_EVNT_INT_BLK4_PUB_EN_TypeDef;



/* 0xB3C
   11:0    R/W    r_dma_task_chn_en3_sub_en[11:0]                     12'h000
   31:12   R      reserved_b3c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_task_chn_en3_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_TASK_CHN_EN3_SUB_EN_TypeDef;


/* 0xB40
   11:0    R/W    r_dma_task_chn_en4_sub_en[11:0]                     12'h000
   31:12   R      reserved_b40_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_task_chn_en4_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} DMA_TASK_CHN_EN4_SUB_EN_TypeDef;



/* 0xB50
   11:0    R/W    r_grtc_evnt_compare0_pub_en[11:0]                   12'h000
   31:12   R      reserved_b50_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare0_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE0_PUB_EN_TypeDef;


/* 0xB54
   11:0    R/W    r_grtc_evnt_compare1_pub_en[11:0]                   12'h000
   31:12   R      reserved_b54_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare1_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE1_PUB_EN_TypeDef;


/* 0xB58
   11:0    R/W    r_grtc_evnt_compare2_pub_en[11:0]                   12'h000
   31:12   R      reserved_b58_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare2_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE2_PUB_EN_TypeDef;


/* 0xB5C
   11:0    R/W    r_grtc_evnt_compare3_pub_en[11:0]                   12'h000
   31:12   R      reserved_b5c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE3_PUB_EN_TypeDef;


/* 0xB60
   11:0    R/W    r_grtc_evnt_compare4_pub_en[11:0]                   12'h000
   31:12   R      reserved_b60_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare4_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE4_PUB_EN_TypeDef;


/* 0xB64
   11:0    R/W    r_grtc_evnt_compare5_pub_en[11:0]                   12'h000
   31:12   R      reserved_b64_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare5_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE5_PUB_EN_TypeDef;


/* 0xB68
   11:0    R/W    r_grtc_evnt_compare6_pub_en[11:0]                   12'h000
   31:12   R      reserved_b68_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare6_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE6_PUB_EN_TypeDef;


/* 0xB6C
   11:0    R/W    r_grtc_evnt_compare7_pub_en[11:0]                   12'h000
   31:12   R      reserved_b6c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare7_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_EVNT_COMPARE7_PUB_EN_TypeDef;



/* 0xB78
   11:0    R/W    r_grtc_task_reload_cmp0_sub_en[11:0]                12'h000
   31:12   R      reserved_b78_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp0_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP0_SUB_EN_TypeDef;


/* 0xB7C
   11:0    R/W    r_grtc_task_reload_cmp1_sub_en[11:0]                12'h000
   31:12   R      reserved_b7c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp1_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP1_SUB_EN_TypeDef;


/* 0xB80
   11:0    R/W    r_grtc_task_reload_cmp2_sub_en[11:0]                12'h000
   31:12   R      reserved_b80_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp2_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP2_SUB_EN_TypeDef;


/* 0xB84
   11:0    R/W    r_grtc_task_reload_cmp3_sub_en[11:0]                12'h000
   31:12   R      reserved_b84_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp3_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP3_SUB_EN_TypeDef;


/* 0xB88
   11:0    R/W    r_grtc_task_reload_cmp4_sub_en[11:0]                12'h000
   31:12   R      reserved_b88_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp4_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP4_SUB_EN_TypeDef;


/* 0xB8C
   11:0    R/W    r_grtc_task_reload_cmp5_sub_en[11:0]                12'h000
   31:12   R      reserved_b8c_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp5_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP5_SUB_EN_TypeDef;


/* 0xB90
   11:0    R/W    r_grtc_task_reload_cmp6_sub_en[11:0]                12'h000
   31:12   R      reserved_b90_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp6_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP6_SUB_EN_TypeDef;


/* 0xB94
   11:0    R/W    r_grtc_task_reload_cmp7_sub_en[11:0]                12'h000
   31:12   R      reserved_b94_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_task_reload_cmp7_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} GRTC_TASK_RELOAD_CMP7_SUB_EN_TypeDef;



/* 0xBA0
   11:0    R/W    r_sdmk_evnt_done_pub_en[11:0]                       12'h000
   31:12   R      reserved_ba0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_sdmk_evnt_done_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SDMK_EVNT_DONE_PUB_EN_TypeDef;


/* 0xBA4
   11:0    R/W    r_sdmk_task_start_sub_en[11:0]                      12'h000
   31:12   R      reserved_ba4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_sdmk_task_start_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} SDMK_TASK_START_SUB_EN_TypeDef;



/* 0xBB0
   11:0    R/W    r_osc10m_evnt_cal_done_pub_en[11:0]                 12'h000
   31:12   R      reserved_bb0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc10m_evnt_cal_done_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} OSC10M_EVNT_CAL_DONE_PUB_EN_TypeDef;


/* 0xBB4
   11:0    R/W    r_osc10m_task_cal_sub_en[11:0]                      12'h000
   31:12   R      reserved_bb4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc10m_task_cal_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} OSC10M_TASK_CAL_SUB_EN_TypeDef;



/* 0xBC0
   11:0    R/W    r_osc80m_evnt_cal_done_pub_en[11:0]                 12'h000
   31:12   R      reserved_bc0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc80m_evnt_cal_done_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} OSC80M_EVNT_CAL_DONE_PUB_EN_TypeDef;


/* 0xBC4
   11:0    R/W    r_osc80m_task_cal_sub_en[11:0]                      12'h000
   31:12   R      reserved_bc4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc80m_task_cal_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} OSC80M_TASK_CAL_SUB_EN_TypeDef;



/* 0xBC8
   11:0    R/W    r_tmeter_evnt_datardy_pub_en[11:0]                  12'h000
   31:12   R      reserved_bc8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_datardy_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_DATARDY_PUB_EN_TypeDef;


/* 0xBCC
   11:0    R/W    r_tmeter_evnt_abs_comp0_pub_en[11:0]                12'h000
   31:12   R      reserved_bcc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_abs_comp0_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_ABS_CMP0_PUB_EN_TypeDef;


/* 0xBD0
   11:0    R/W    r_tmeter_evnt_abs_comp1_pub_en[11:0]                12'h000
   31:12   R      reserved_bd0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_abs_comp1_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_ABS_CMP1_PUB_EN_TypeDef;


/* 0xBD4
   11:0    R/W    r_tmeter_evnt_abs_comp2_pub_en[11:0]                12'h000
   31:12   R      reserved_bd4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_abs_comp2_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_ABS_CMP2_PUB_EN_TypeDef;


/* 0xBD8
   11:0    R/W    r_tmeter_evnt_abs_comp3_pub_en[11:0]                12'h000
   31:12   R      reserved_bd8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_abs_comp3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_ABS_CMP3_PUB_EN_TypeDef;


/* 0xBDC
   11:0    R/W    r_tmeter_evnt_rel_comp0_pub_en[11:0]                12'h000
   31:12   R      reserved_bdc_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_rel_comp0_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_REL_CMP0_PUB_EN_TypeDef;


/* 0xBE0
   11:0    R/W    r_tmeter_evnt_rel_comp1_pub_en[11:0]                12'h000
   31:12   R      reserved_be0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_rel_comp1_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_REL_CMP1_PUB_EN_TypeDef;


/* 0xBE4
   11:0    R/W    r_tmeter_evnt_rel_comp2_pub_en[11:0]                12'h000
   31:12   R      reserved_be4_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_rel_comp2_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_REL_CMP2_PUB_EN_TypeDef;


/* 0xBE8
   11:0    R/W    r_tmeter_evnt_rel_comp3_pub_en[11:0]                12'h000
   31:12   R      reserved_be8_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_rel_comp3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_REL_CMP3_PUB_EN_TypeDef;


/* 0xBEC
   11:0    R/W    r_tmeter_evnt_fw_rel_comp3_pub_en[11:0]             12'h000
   31:12   R      reserved_bec_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_evnt_fw_rel_comp3_pub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_EVNT_FW_REL_COMP3_PUB_EN_TypeDef;


/* 0xBF0
   11:0    R/W    r_tmeter_task_oneshot_sub_en[11:0]                  12'h000
   31:12   R      reserved_bf0_31_12                                  20'h0_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_tmeter_task_oneshot_sub_en_11_0: 12;
        const uint32_t reserved_0: 20;
    } b;
} TMETER_TASK_ONESHOT_SUB_EN_TypeDef;



/* 0xF00
   31:0    R      debug_mux_din[31:0]                                 32'h0000_0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t debug_mux_din_31_0: 32;
    } b;
} DEBUG_SIG_TypeDef;


/*============================================================================*
 *                          RAP Status and Field Descriptions
 *============================================================================*/
/* 0x2EC
   0       R/W1C  r_enhtimer_evnt_active_sts              1'b0
   1       R/W1C  r_enhtimer_evnt_lch_cnt0_fifo_full_sts  1'b0
   2       R/W1C  r_enhtimer_evnt_lch_cnt0_fifo_met_th_sts1'b0
   3       R/W1C  r_enhtimer_evnt_stop_sts                1'b0
   4       R/W1C  r_enhtimer_evnt_timeout_sts             1'b0
   15:5    R      reserved                                11'h0000
   16      R/W1C  r_enhtimer_task_disable_sts             1'b0
   17      R/W1C  r_enhtimer_task_pause_sts               1'b0
   18      R/W1C  r_enhtimer_task_start_sts               1'b0
   31:19   R      reserved                                13'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_enhtimer_evnt_active_sts: 1;
        uint32_t r_enhtimer_evnt_lch_cnt0_fifo_full_sts: 1;
        uint32_t r_enhtimer_evnt_lch_cnt0_fifo_met_th_sts: 1;
        uint32_t r_enhtimer_evnt_stop_sts: 1;
        uint32_t r_enhtimer_evnt_timeout_sts: 1;
        const uint32_t reserved_1: 11;
        uint32_t r_enhtimer_task_disable_sts: 1;
        uint32_t r_enhtimer_task_pause_sts: 1;
        uint32_t r_enhtimer_task_start_sts: 1;
        const uint32_t reserved_0: 13;
    } b;
} ENHTIMER_TASK_EVNT_STS_TypeDef;


/* 0x2F0
   0       R/W1C  r_keyscan_evnt_manual_done_sts          1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_keyscan_task_manual_sts               1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_keyscan_evnt_manual_done_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_keyscan_task_manual_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} KEYSCAN_TASK_EVNT_STS_TypeDef;


/* 0x2F4
   0       R/W1C  r_timer1_ch0_evnt_active_sts            1'b0
   1       R/W1C  r_timer1_ch0_evnt_stop_sts              1'b0
   2       R/W1C  r_timer1_ch0_evnt_timeout_sts           1'b0
   3       R/W1C  r_timer1_ch1_evnt_active_sts            1'b0
   4       R/W1C  r_timer1_ch1_evnt_stop_sts              1'b0
   5       R/W1C  r_timer1_ch1_evnt_timeout_sts           1'b0
   6       R/W1C  r_timer1_ch2_evnt_active_sts            1'b0
   7       R/W1C  r_timer1_ch2_evnt_stop_sts              1'b0
   8       R/W1C  r_timer1_ch2_evnt_timeout_sts           1'b0
   9       R/W1C  r_timer1_ch3_evnt_active_sts            1'b0
   10      R/W1C  r_timer1_ch3_evnt_stop_sts              1'b0
   11      R/W1C  r_timer1_ch3_evnt_timeout_sts           1'b0
   12      R/W1C  r_timer1_ch4_evnt_active_sts            1'b0
   13      R/W1C  r_timer1_ch4_evnt_stop_sts              1'b0
   14      R/W1C  r_timer1_ch4_evnt_timeout_sts           1'b0
   15      R/W1C  r_timer1_ch5_evnt_active_sts            1'b0
   16      R/W1C  r_timer1_ch5_evnt_stop_sts              1'b0
   17      R/W1C  r_timer1_ch5_evnt_timeout_sts           1'b0
   18      R/W1C  r_timer1_ch6_evnt_active_sts            1'b0
   19      R/W1C  r_timer1_ch6_evnt_stop_sts              1'b0
   20      R/W1C  r_timer1_ch6_evnt_timeout_sts           1'b0
   21      R/W1C  r_timer1_ch7_evnt_active_sts            1'b0
   22      R/W1C  r_timer1_ch7_evnt_stop_sts              1'b0
   23      R/W1C  r_timer1_ch7_evnt_timeout_sts           1'b0
   24      R/W1C  r_timer1_ch8_evnt_active_sts            1'b0
   25      R/W1C  r_timer1_ch8_evnt_stop_sts              1'b0
   26      R/W1C  r_timer1_ch8_evnt_timeout_sts           1'b0
   31:27   R      reserved                                5'h00
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_timer1_ch0_evnt_active_sts: 1;
        uint32_t r_timer1_ch0_evnt_stop_sts: 1;
        uint32_t r_timer1_ch0_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch1_evnt_active_sts: 1;
        uint32_t r_timer1_ch1_evnt_stop_sts: 1;
        uint32_t r_timer1_ch1_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch2_evnt_active_sts: 1;
        uint32_t r_timer1_ch2_evnt_stop_sts: 1;
        uint32_t r_timer1_ch2_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch3_evnt_active_sts: 1;
        uint32_t r_timer1_ch3_evnt_stop_sts: 1;
        uint32_t r_timer1_ch3_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch4_evnt_active_sts: 1;
        uint32_t r_timer1_ch4_evnt_stop_sts: 1;
        uint32_t r_timer1_ch4_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch5_evnt_active_sts: 1;
        uint32_t r_timer1_ch5_evnt_stop_sts: 1;
        uint32_t r_timer1_ch5_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch6_evnt_active_sts: 1;
        uint32_t r_timer1_ch6_evnt_stop_sts: 1;
        uint32_t r_timer1_ch6_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch7_evnt_active_sts: 1;
        uint32_t r_timer1_ch7_evnt_stop_sts: 1;
        uint32_t r_timer1_ch7_evnt_timeout_sts: 1;
        uint32_t r_timer1_ch8_evnt_active_sts: 1;
        uint32_t r_timer1_ch8_evnt_stop_sts: 1;
        uint32_t r_timer1_ch8_evnt_timeout_sts: 1;
        const uint32_t reserved_0: 5;
    } b;
} TIMER1_EVNT_STS_TypeDef;


/* 0x2F8
   0       R/W1C  r_timer1_ch0_task_disable_sts           1'b0
   1       R/W1C  r_timer1_ch0_task_pause_sts             1'b0
   2       R/W1C  r_timer1_ch0_task_start_sts             1'b0
   3       R/W1C  r_timer1_ch1_task_disable_sts           1'b0
   4       R/W1C  r_timer1_ch1_task_pause_sts             1'b0
   5       R/W1C  r_timer1_ch1_task_start_sts             1'b0
   6       R/W1C  r_timer1_ch2_task_disable_sts           1'b0
   7       R/W1C  r_timer1_ch2_task_pause_sts             1'b0
   8       R/W1C  r_timer1_ch2_task_start_sts             1'b0
   9       R/W1C  r_timer1_ch3_task_disable_sts           1'b0
   10      R/W1C  r_timer1_ch3_task_pause_sts             1'b0
   11      R/W1C  r_timer1_ch3_task_start_sts             1'b0
   12      R/W1C  r_timer1_ch4_task_disable_sts           1'b0
   13      R/W1C  r_timer1_ch4_task_pause_sts             1'b0
   14      R/W1C  r_timer1_ch4_task_start_sts             1'b0
   15      R/W1C  r_timer1_ch5_task_disable_sts           1'b0
   16      R/W1C  r_timer1_ch5_task_pause_sts             1'b0
   17      R/W1C  r_timer1_ch5_task_start_sts             1'b0
   18      R/W1C  r_timer1_ch6_task_disable_sts           1'b0
   19      R/W1C  r_timer1_ch6_task_pause_sts             1'b0
   20      R/W1C  r_timer1_ch6_task_start_sts             1'b0
   21      R/W1C  r_timer1_ch7_task_disable_sts           1'b0
   22      R/W1C  r_timer1_ch7_task_pause_sts             1'b0
   23      R/W1C  r_timer1_ch7_task_start_sts             1'b0
   24      R/W1C  r_timer1_ch8_task_disable_sts           1'b0
   25      R/W1C  r_timer1_ch8_task_pause_sts             1'b0
   26      R/W1C  r_timer1_ch8_task_start_sts             1'b0
   31:27   R      reserved                                5'h00
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_timer1_ch0_task_disable_sts: 1;
        uint32_t r_timer1_ch0_task_pause_sts: 1;
        uint32_t r_timer1_ch0_task_start_sts: 1;
        uint32_t r_timer1_ch1_task_disable_sts: 1;
        uint32_t r_timer1_ch1_task_pause_sts: 1;
        uint32_t r_timer1_ch1_task_start_sts: 1;
        uint32_t r_timer1_ch2_task_disable_sts: 1;
        uint32_t r_timer1_ch2_task_pause_sts: 1;
        uint32_t r_timer1_ch2_task_start_sts: 1;
        uint32_t r_timer1_ch3_task_disable_sts: 1;
        uint32_t r_timer1_ch3_task_pause_sts: 1;
        uint32_t r_timer1_ch3_task_start_sts: 1;
        uint32_t r_timer1_ch4_task_disable_sts: 1;
        uint32_t r_timer1_ch4_task_pause_sts: 1;
        uint32_t r_timer1_ch4_task_start_sts: 1;
        uint32_t r_timer1_ch5_task_disable_sts: 1;
        uint32_t r_timer1_ch5_task_pause_sts: 1;
        uint32_t r_timer1_ch5_task_start_sts: 1;
        uint32_t r_timer1_ch6_task_disable_sts: 1;
        uint32_t r_timer1_ch6_task_pause_sts: 1;
        uint32_t r_timer1_ch6_task_start_sts: 1;
        uint32_t r_timer1_ch7_task_disable_sts: 1;
        uint32_t r_timer1_ch7_task_pause_sts: 1;
        uint32_t r_timer1_ch7_task_start_sts: 1;
        uint32_t r_timer1_ch8_task_disable_sts: 1;
        uint32_t r_timer1_ch8_task_pause_sts: 1;
        uint32_t r_timer1_ch8_task_start_sts: 1;
        const uint32_t reserved_0: 5;
    } b;
} TIMER1_TASK_STS_TypeDef;


/* 0x2FC
   0       R/W1C  r_gpio0_0_evnt_in_sts                   1'b0
   1       R/W1C  r_gpio0_1_evnt_in_sts                   1'b0
   2       R/W1C  r_gpio0_2_evnt_in_sts                   1'b0
   3       R/W1C  r_gpio0_3_evnt_in_sts                   1'b0
   4       R/W1C  r_gpio0_4_evnt_in_sts                   1'b0
   5       R/W1C  r_gpio0_5_evnt_in_sts                   1'b0
   6       R/W1C  r_gpio0_6_evnt_in_sts                   1'b0
   7       R/W1C  r_gpio0_7_evnt_in_sts                   1'b0
   8       R/W1C  r_gpio0_8_evnt_in_sts                   1'b0
   9       R/W1C  r_gpio0_9_evnt_in_sts                   1'b0
   10      R/W1C  r_gpio0_10_evnt_in_sts                  1'b0
   11      R/W1C  r_gpio0_11_evnt_in_sts                  1'b0
   12      R/W1C  r_gpio0_12_evnt_in_sts                  1'b0
   13      R/W1C  r_gpio0_13_evnt_in_sts                  1'b0
   14      R/W1C  r_gpio0_14_evnt_in_sts                  1'b0
   15      R/W1C  r_gpio0_15_evnt_in_sts                  1'b0
   16      R/W1C  r_gpio0_16_evnt_in_sts                  1'b0
   17      R/W1C  r_gpio0_17_evnt_in_sts                  1'b0
   18      R/W1C  r_gpio0_18_evnt_in_sts                  1'b0
   19      R/W1C  r_gpio0_19_evnt_in_sts                  1'b0
   20      R/W1C  r_gpio0_20_evnt_in_sts                  1'b0
   21      R/W1C  r_gpio0_21_evnt_in_sts                  1'b0
   22      R/W1C  r_gpio0_22_evnt_in_sts                  1'b0
   23      R/W1C  r_gpio0_23_evnt_in_sts                  1'b0
   24      R/W1C  r_gpio0_24_evnt_in_sts                  1'b0
   25      R/W1C  r_gpio0_25_evnt_in_sts                  1'b0
   26      R/W1C  r_gpio0_26_evnt_in_sts                  1'b0
   27      R/W1C  r_gpio0_27_evnt_in_sts                  1'b0
   28      R/W1C  r_gpio0_28_evnt_in_sts                  1'b0
   29      R/W1C  r_gpio0_29_evnt_in_sts                  1'b0
   30      R/W1C  r_gpio0_30_evnt_in_sts                  1'b0
   31      R/W1C  r_gpio0_31_evnt_in_sts                  1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_evnt_in_sts: 1;
        uint32_t r_gpio0_1_evnt_in_sts: 1;
        uint32_t r_gpio0_2_evnt_in_sts: 1;
        uint32_t r_gpio0_3_evnt_in_sts: 1;
        uint32_t r_gpio0_4_evnt_in_sts: 1;
        uint32_t r_gpio0_5_evnt_in_sts: 1;
        uint32_t r_gpio0_6_evnt_in_sts: 1;
        uint32_t r_gpio0_7_evnt_in_sts: 1;
        uint32_t r_gpio0_8_evnt_in_sts: 1;
        uint32_t r_gpio0_9_evnt_in_sts: 1;
        uint32_t r_gpio0_10_evnt_in_sts: 1;
        uint32_t r_gpio0_11_evnt_in_sts: 1;
        uint32_t r_gpio0_12_evnt_in_sts: 1;
        uint32_t r_gpio0_13_evnt_in_sts: 1;
        uint32_t r_gpio0_14_evnt_in_sts: 1;
        uint32_t r_gpio0_15_evnt_in_sts: 1;
        uint32_t r_gpio0_16_evnt_in_sts: 1;
        uint32_t r_gpio0_17_evnt_in_sts: 1;
        uint32_t r_gpio0_18_evnt_in_sts: 1;
        uint32_t r_gpio0_19_evnt_in_sts: 1;
        uint32_t r_gpio0_20_evnt_in_sts: 1;
        uint32_t r_gpio0_21_evnt_in_sts: 1;
        uint32_t r_gpio0_22_evnt_in_sts: 1;
        uint32_t r_gpio0_23_evnt_in_sts: 1;
        uint32_t r_gpio0_24_evnt_in_sts: 1;
        uint32_t r_gpio0_25_evnt_in_sts: 1;
        uint32_t r_gpio0_26_evnt_in_sts: 1;
        uint32_t r_gpio0_27_evnt_in_sts: 1;
        uint32_t r_gpio0_28_evnt_in_sts: 1;
        uint32_t r_gpio0_29_evnt_in_sts: 1;
        uint32_t r_gpio0_30_evnt_in_sts: 1;
        uint32_t r_gpio0_31_evnt_in_sts: 1;
    } b;
} GPIO_0_EVNT_STS_TypeDef;


/* 0x300
   0       R/W1C  r_gpio0_32_evnt_in_sts                  1'b0
   1       R/W1C  r_gpio0_33_evnt_in_sts                  1'b0
   2       R/W1C  r_gpio0_34_evnt_in_sts                  1'b0
   3       R/W1C  r_gpio0_35_evnt_in_sts                  1'b0
   4       R/W1C  r_gpio0_36_evnt_in_sts                  1'b0
   5       R/W1C  r_gpio0_37_evnt_in_sts                  1'b0
   6       R/W1C  r_gpio0_38_evnt_in_sts                  1'b0
   7       R/W1C  r_gpio0_39_evnt_in_sts                  1'b0
   8       R/W1C  r_gpio0_40_evnt_in_sts                  1'b0
   9       R/W1C  r_gpio0_41_evnt_in_sts                  1'b0
   10      R/W1C  r_gpio0_42_evnt_in_sts                  1'b0
   11      R/W1C  r_gpio0_43_evnt_in_sts                  1'b0
   12      R/W1C  r_gpio0_44_evnt_in_sts                  1'b0
   13      R/W1C  r_gpio0_45_evnt_in_sts                  1'b0
   14      R/W1C  r_gpio0_46_evnt_in_sts                  1'b0
   15      R/W1C  r_gpio0_47_evnt_in_sts                  1'b0
   16      R/W1C  r_gpio0_48_evnt_in_sts                  1'b0
   17      R/W1C  r_gpio0_49_evnt_in_sts                  1'b0
   31:18   R      reserved                                14'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_evnt_in_sts: 1;
        uint32_t r_gpio0_33_evnt_in_sts: 1;
        uint32_t r_gpio0_34_evnt_in_sts: 1;
        uint32_t r_gpio0_35_evnt_in_sts: 1;
        uint32_t r_gpio0_36_evnt_in_sts: 1;
        uint32_t r_gpio0_37_evnt_in_sts: 1;
        uint32_t r_gpio0_38_evnt_in_sts: 1;
        uint32_t r_gpio0_39_evnt_in_sts: 1;
        uint32_t r_gpio0_40_evnt_in_sts: 1;
        uint32_t r_gpio0_41_evnt_in_sts: 1;
        uint32_t r_gpio0_42_evnt_in_sts: 1;
        uint32_t r_gpio0_43_evnt_in_sts: 1;
        uint32_t r_gpio0_44_evnt_in_sts: 1;
        uint32_t r_gpio0_45_evnt_in_sts: 1;
        uint32_t r_gpio0_46_evnt_in_sts: 1;
        uint32_t r_gpio0_47_evnt_in_sts: 1;
        uint32_t r_gpio0_48_evnt_in_sts: 1;
        uint32_t r_gpio0_49_evnt_in_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} GPIO_1_EVENT_STS_TypeDef;



/* 0x314
   0       R/W1C  r_gpio0_0_task_drclr_sts                1'b0
   1       R/W1C  r_gpio0_1_task_drclr_sts                1'b0
   2       R/W1C  r_gpio0_2_task_drclr_sts                1'b0
   3       R/W1C  r_gpio0_3_task_drclr_sts                1'b0
   4       R/W1C  r_gpio0_4_task_drclr_sts                1'b0
   5       R/W1C  r_gpio0_5_task_drclr_sts                1'b0
   6       R/W1C  r_gpio0_6_task_drclr_sts                1'b0
   7       R/W1C  r_gpio0_7_task_drclr_sts                1'b0
   8       R/W1C  r_gpio0_8_task_drclr_sts                1'b0
   9       R/W1C  r_gpio0_9_task_drclr_sts                1'b0
   10      R/W1C  r_gpio0_10_task_drclr_sts               1'b0
   11      R/W1C  r_gpio0_11_task_drclr_sts               1'b0
   12      R/W1C  r_gpio0_12_task_drclr_sts               1'b0
   13      R/W1C  r_gpio0_13_task_drclr_sts               1'b0
   14      R/W1C  r_gpio0_14_task_drclr_sts               1'b0
   15      R/W1C  r_gpio0_15_task_drclr_sts               1'b0
   16      R/W1C  r_gpio0_16_task_drclr_sts               1'b0
   17      R/W1C  r_gpio0_17_task_drclr_sts               1'b0
   18      R/W1C  r_gpio0_18_task_drclr_sts               1'b0
   19      R/W1C  r_gpio0_19_task_drclr_sts               1'b0
   20      R/W1C  r_gpio0_20_task_drclr_sts               1'b0
   21      R/W1C  r_gpio0_21_task_drclr_sts               1'b0
   22      R/W1C  r_gpio0_22_task_drclr_sts               1'b0
   23      R/W1C  r_gpio0_23_task_drclr_sts               1'b0
   24      R/W1C  r_gpio0_24_task_drclr_sts               1'b0
   25      R/W1C  r_gpio0_25_task_drclr_sts               1'b0
   26      R/W1C  r_gpio0_26_task_drclr_sts               1'b0
   27      R/W1C  r_gpio0_27_task_drclr_sts               1'b0
   28      R/W1C  r_gpio0_28_task_drclr_sts               1'b0
   29      R/W1C  r_gpio0_29_task_drclr_sts               1'b0
   30      R/W1C  r_gpio0_30_task_drclr_sts               1'b0
   31      R/W1C  r_gpio0_31_task_drclr_sts               1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drclr_sts: 1;
        uint32_t r_gpio0_1_task_drclr_sts: 1;
        uint32_t r_gpio0_2_task_drclr_sts: 1;
        uint32_t r_gpio0_3_task_drclr_sts: 1;
        uint32_t r_gpio0_4_task_drclr_sts: 1;
        uint32_t r_gpio0_5_task_drclr_sts: 1;
        uint32_t r_gpio0_6_task_drclr_sts: 1;
        uint32_t r_gpio0_7_task_drclr_sts: 1;
        uint32_t r_gpio0_8_task_drclr_sts: 1;
        uint32_t r_gpio0_9_task_drclr_sts: 1;
        uint32_t r_gpio0_10_task_drclr_sts: 1;
        uint32_t r_gpio0_11_task_drclr_sts: 1;
        uint32_t r_gpio0_12_task_drclr_sts: 1;
        uint32_t r_gpio0_13_task_drclr_sts: 1;
        uint32_t r_gpio0_14_task_drclr_sts: 1;
        uint32_t r_gpio0_15_task_drclr_sts: 1;
        uint32_t r_gpio0_16_task_drclr_sts: 1;
        uint32_t r_gpio0_17_task_drclr_sts: 1;
        uint32_t r_gpio0_18_task_drclr_sts: 1;
        uint32_t r_gpio0_19_task_drclr_sts: 1;
        uint32_t r_gpio0_20_task_drclr_sts: 1;
        uint32_t r_gpio0_21_task_drclr_sts: 1;
        uint32_t r_gpio0_22_task_drclr_sts: 1;
        uint32_t r_gpio0_23_task_drclr_sts: 1;
        uint32_t r_gpio0_24_task_drclr_sts: 1;
        uint32_t r_gpio0_25_task_drclr_sts: 1;
        uint32_t r_gpio0_26_task_drclr_sts: 1;
        uint32_t r_gpio0_27_task_drclr_sts: 1;
        uint32_t r_gpio0_28_task_drclr_sts: 1;
        uint32_t r_gpio0_29_task_drclr_sts: 1;
        uint32_t r_gpio0_30_task_drclr_sts: 1;
        uint32_t r_gpio0_31_task_drclr_sts: 1;
    } b;
} GPIO_0_TASK_DRCLR_STS_TypeDef;


/* 0x318
   0       R/W1C  r_gpio0_32_task_drclr_sts               1'b0
   1       R/W1C  r_gpio0_33_task_drclr_sts               1'b0
   2       R/W1C  r_gpio0_34_task_drclr_sts               1'b0
   3       R/W1C  r_gpio0_35_task_drclr_sts               1'b0
   4       R/W1C  r_gpio0_36_task_drclr_sts               1'b0
   5       R/W1C  r_gpio0_37_task_drclr_sts               1'b0
   6       R/W1C  r_gpio0_38_task_drclr_sts               1'b0
   7       R/W1C  r_gpio0_39_task_drclr_sts               1'b0
   8       R/W1C  r_gpio0_40_task_drclr_sts               1'b0
   9       R/W1C  r_gpio0_41_task_drclr_sts               1'b0
   10      R/W1C  r_gpio0_42_task_drclr_sts               1'b0
   11      R/W1C  r_gpio0_43_task_drclr_sts               1'b0
   12      R/W1C  r_gpio0_44_task_drclr_sts               1'b0
   13      R/W1C  r_gpio0_45_task_drclr_sts               1'b0
   14      R/W1C  r_gpio0_46_task_drclr_sts               1'b0
   15      R/W1C  r_gpio0_47_task_drclr_sts               1'b0
   16      R/W1C  r_gpio0_48_task_drclr_sts               1'b0
   17      R/W1C  r_gpio0_49_task_drclr_sts               1'b0
   31:18   R      reserved                                14'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drclr_sts: 1;
        uint32_t r_gpio0_33_task_drclr_sts: 1;
        uint32_t r_gpio0_34_task_drclr_sts: 1;
        uint32_t r_gpio0_35_task_drclr_sts: 1;
        uint32_t r_gpio0_36_task_drclr_sts: 1;
        uint32_t r_gpio0_37_task_drclr_sts: 1;
        uint32_t r_gpio0_38_task_drclr_sts: 1;
        uint32_t r_gpio0_39_task_drclr_sts: 1;
        uint32_t r_gpio0_40_task_drclr_sts: 1;
        uint32_t r_gpio0_41_task_drclr_sts: 1;
        uint32_t r_gpio0_42_task_drclr_sts: 1;
        uint32_t r_gpio0_43_task_drclr_sts: 1;
        uint32_t r_gpio0_44_task_drclr_sts: 1;
        uint32_t r_gpio0_45_task_drclr_sts: 1;
        uint32_t r_gpio0_46_task_drclr_sts: 1;
        uint32_t r_gpio0_47_task_drclr_sts: 1;
        uint32_t r_gpio0_48_task_drclr_sts: 1;
        uint32_t r_gpio0_49_task_drclr_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} GPIO_1_TASK_DRCLR_STS_TypeDef;


/* 0x31C
   0       R/W1C  r_gpio0_0_task_drset_sts                1'b0
   1       R/W1C  r_gpio0_1_task_drset_sts                1'b0
   2       R/W1C  r_gpio0_2_task_drset_sts                1'b0
   3       R/W1C  r_gpio0_3_task_drset_sts                1'b0
   4       R/W1C  r_gpio0_4_task_drset_sts                1'b0
   5       R/W1C  r_gpio0_5_task_drset_sts                1'b0
   6       R/W1C  r_gpio0_6_task_drset_sts                1'b0
   7       R/W1C  r_gpio0_7_task_drset_sts                1'b0
   8       R/W1C  r_gpio0_8_task_drset_sts                1'b0
   9       R/W1C  r_gpio0_9_task_drset_sts                1'b0
   10      R/W1C  r_gpio0_10_task_drset_sts               1'b0
   11      R/W1C  r_gpio0_11_task_drset_sts               1'b0
   12      R/W1C  r_gpio0_12_task_drset_sts               1'b0
   13      R/W1C  r_gpio0_13_task_drset_sts               1'b0
   14      R/W1C  r_gpio0_14_task_drset_sts               1'b0
   15      R/W1C  r_gpio0_15_task_drset_sts               1'b0
   16      R/W1C  r_gpio0_16_task_drset_sts               1'b0
   17      R/W1C  r_gpio0_17_task_drset_sts               1'b0
   18      R/W1C  r_gpio0_18_task_drset_sts               1'b0
   19      R/W1C  r_gpio0_19_task_drset_sts               1'b0
   20      R/W1C  r_gpio0_20_task_drset_sts               1'b0
   21      R/W1C  r_gpio0_21_task_drset_sts               1'b0
   22      R/W1C  r_gpio0_22_task_drset_sts               1'b0
   23      R/W1C  r_gpio0_23_task_drset_sts               1'b0
   24      R/W1C  r_gpio0_24_task_drset_sts               1'b0
   25      R/W1C  r_gpio0_25_task_drset_sts               1'b0
   26      R/W1C  r_gpio0_26_task_drset_sts               1'b0
   27      R/W1C  r_gpio0_27_task_drset_sts               1'b0
   28      R/W1C  r_gpio0_28_task_drset_sts               1'b0
   29      R/W1C  r_gpio0_29_task_drset_sts               1'b0
   30      R/W1C  r_gpio0_30_task_drset_sts               1'b0
   31      R/W1C  r_gpio0_31_task_drset_sts               1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drset_sts: 1;
        uint32_t r_gpio0_1_task_drset_sts: 1;
        uint32_t r_gpio0_2_task_drset_sts: 1;
        uint32_t r_gpio0_3_task_drset_sts: 1;
        uint32_t r_gpio0_4_task_drset_sts: 1;
        uint32_t r_gpio0_5_task_drset_sts: 1;
        uint32_t r_gpio0_6_task_drset_sts: 1;
        uint32_t r_gpio0_7_task_drset_sts: 1;
        uint32_t r_gpio0_8_task_drset_sts: 1;
        uint32_t r_gpio0_9_task_drset_sts: 1;
        uint32_t r_gpio0_10_task_drset_sts: 1;
        uint32_t r_gpio0_11_task_drset_sts: 1;
        uint32_t r_gpio0_12_task_drset_sts: 1;
        uint32_t r_gpio0_13_task_drset_sts: 1;
        uint32_t r_gpio0_14_task_drset_sts: 1;
        uint32_t r_gpio0_15_task_drset_sts: 1;
        uint32_t r_gpio0_16_task_drset_sts: 1;
        uint32_t r_gpio0_17_task_drset_sts: 1;
        uint32_t r_gpio0_18_task_drset_sts: 1;
        uint32_t r_gpio0_19_task_drset_sts: 1;
        uint32_t r_gpio0_20_task_drset_sts: 1;
        uint32_t r_gpio0_21_task_drset_sts: 1;
        uint32_t r_gpio0_22_task_drset_sts: 1;
        uint32_t r_gpio0_23_task_drset_sts: 1;
        uint32_t r_gpio0_24_task_drset_sts: 1;
        uint32_t r_gpio0_25_task_drset_sts: 1;
        uint32_t r_gpio0_26_task_drset_sts: 1;
        uint32_t r_gpio0_27_task_drset_sts: 1;
        uint32_t r_gpio0_28_task_drset_sts: 1;
        uint32_t r_gpio0_29_task_drset_sts: 1;
        uint32_t r_gpio0_30_task_drset_sts: 1;
        uint32_t r_gpio0_31_task_drset_sts: 1;
    } b;
} GPIO_0_TASK_DRSET_STS_TypeDef;


/* 0x320
   0       R/W1C  r_gpio0_32_task_drset_sts               1'b0
   1       R/W1C  r_gpio0_33_task_drset_sts               1'b0
   2       R/W1C  r_gpio0_34_task_drset_sts               1'b0
   3       R/W1C  r_gpio0_35_task_drset_sts               1'b0
   4       R/W1C  r_gpio0_36_task_drset_sts               1'b0
   5       R/W1C  r_gpio0_37_task_drset_sts               1'b0
   6       R/W1C  r_gpio0_38_task_drset_sts               1'b0
   7       R/W1C  r_gpio0_39_task_drset_sts               1'b0
   8       R/W1C  r_gpio0_40_task_drset_sts               1'b0
   9       R/W1C  r_gpio0_41_task_drset_sts               1'b0
   10      R/W1C  r_gpio0_42_task_drset_sts               1'b0
   11      R/W1C  r_gpio0_43_task_drset_sts               1'b0
   12      R/W1C  r_gpio0_44_task_drset_sts               1'b0
   13      R/W1C  r_gpio0_45_task_drset_sts               1'b0
   14      R/W1C  r_gpio0_46_task_drset_sts               1'b0
   15      R/W1C  r_gpio0_47_task_drset_sts               1'b0
   16      R/W1C  r_gpio0_48_task_drset_sts               1'b0
   17      R/W1C  r_gpio0_49_task_drset_sts               1'b0
   31:18   R      reserved                                14'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drset_sts: 1;
        uint32_t r_gpio0_33_task_drset_sts: 1;
        uint32_t r_gpio0_34_task_drset_sts: 1;
        uint32_t r_gpio0_35_task_drset_sts: 1;
        uint32_t r_gpio0_36_task_drset_sts: 1;
        uint32_t r_gpio0_37_task_drset_sts: 1;
        uint32_t r_gpio0_38_task_drset_sts: 1;
        uint32_t r_gpio0_39_task_drset_sts: 1;
        uint32_t r_gpio0_40_task_drset_sts: 1;
        uint32_t r_gpio0_41_task_drset_sts: 1;
        uint32_t r_gpio0_42_task_drset_sts: 1;
        uint32_t r_gpio0_43_task_drset_sts: 1;
        uint32_t r_gpio0_44_task_drset_sts: 1;
        uint32_t r_gpio0_45_task_drset_sts: 1;
        uint32_t r_gpio0_46_task_drset_sts: 1;
        uint32_t r_gpio0_47_task_drset_sts: 1;
        uint32_t r_gpio0_48_task_drset_sts: 1;
        uint32_t r_gpio0_49_task_drset_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} GPIO_1_TASK_DRSET_STS_TypeDef;


/* 0x324
   0       R/W1C  r_gpio0_0_task_drtoggle_sts             1'b0
   1       R/W1C  r_gpio0_1_task_drtoggle_sts             1'b0
   2       R/W1C  r_gpio0_2_task_drtoggle_sts             1'b0
   3       R/W1C  r_gpio0_3_task_drtoggle_sts             1'b0
   4       R/W1C  r_gpio0_4_task_drtoggle_sts             1'b0
   5       R/W1C  r_gpio0_5_task_drtoggle_sts             1'b0
   6       R/W1C  r_gpio0_6_task_drtoggle_sts             1'b0
   7       R/W1C  r_gpio0_7_task_drtoggle_sts             1'b0
   8       R/W1C  r_gpio0_8_task_drtoggle_sts             1'b0
   9       R/W1C  r_gpio0_9_task_drtoggle_sts             1'b0
   10      R/W1C  r_gpio0_10_task_drtoggle_sts            1'b0
   11      R/W1C  r_gpio0_11_task_drtoggle_sts            1'b0
   12      R/W1C  r_gpio0_12_task_drtoggle_sts            1'b0
   13      R/W1C  r_gpio0_13_task_drtoggle_sts            1'b0
   14      R/W1C  r_gpio0_14_task_drtoggle_sts            1'b0
   15      R/W1C  r_gpio0_15_task_drtoggle_sts            1'b0
   16      R/W1C  r_gpio0_16_task_drtoggle_sts            1'b0
   17      R/W1C  r_gpio0_17_task_drtoggle_sts            1'b0
   18      R/W1C  r_gpio0_18_task_drtoggle_sts            1'b0
   19      R/W1C  r_gpio0_19_task_drtoggle_sts            1'b0
   20      R/W1C  r_gpio0_20_task_drtoggle_sts            1'b0
   21      R/W1C  r_gpio0_21_task_drtoggle_sts            1'b0
   22      R/W1C  r_gpio0_22_task_drtoggle_sts            1'b0
   23      R/W1C  r_gpio0_23_task_drtoggle_sts            1'b0
   24      R/W1C  r_gpio0_24_task_drtoggle_sts            1'b0
   25      R/W1C  r_gpio0_25_task_drtoggle_sts            1'b0
   26      R/W1C  r_gpio0_26_task_drtoggle_sts            1'b0
   27      R/W1C  r_gpio0_27_task_drtoggle_sts            1'b0
   28      R/W1C  r_gpio0_28_task_drtoggle_sts            1'b0
   29      R/W1C  r_gpio0_29_task_drtoggle_sts            1'b0
   30      R/W1C  r_gpio0_30_task_drtoggle_sts            1'b0
   31      R/W1C  r_gpio0_31_task_drtoggle_sts            1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_0_task_drtoggle_sts: 1;
        uint32_t r_gpio0_1_task_drtoggle_sts: 1;
        uint32_t r_gpio0_2_task_drtoggle_sts: 1;
        uint32_t r_gpio0_3_task_drtoggle_sts: 1;
        uint32_t r_gpio0_4_task_drtoggle_sts: 1;
        uint32_t r_gpio0_5_task_drtoggle_sts: 1;
        uint32_t r_gpio0_6_task_drtoggle_sts: 1;
        uint32_t r_gpio0_7_task_drtoggle_sts: 1;
        uint32_t r_gpio0_8_task_drtoggle_sts: 1;
        uint32_t r_gpio0_9_task_drtoggle_sts: 1;
        uint32_t r_gpio0_10_task_drtoggle_sts: 1;
        uint32_t r_gpio0_11_task_drtoggle_sts: 1;
        uint32_t r_gpio0_12_task_drtoggle_sts: 1;
        uint32_t r_gpio0_13_task_drtoggle_sts: 1;
        uint32_t r_gpio0_14_task_drtoggle_sts: 1;
        uint32_t r_gpio0_15_task_drtoggle_sts: 1;
        uint32_t r_gpio0_16_task_drtoggle_sts: 1;
        uint32_t r_gpio0_17_task_drtoggle_sts: 1;
        uint32_t r_gpio0_18_task_drtoggle_sts: 1;
        uint32_t r_gpio0_19_task_drtoggle_sts: 1;
        uint32_t r_gpio0_20_task_drtoggle_sts: 1;
        uint32_t r_gpio0_21_task_drtoggle_sts: 1;
        uint32_t r_gpio0_22_task_drtoggle_sts: 1;
        uint32_t r_gpio0_23_task_drtoggle_sts: 1;
        uint32_t r_gpio0_24_task_drtoggle_sts: 1;
        uint32_t r_gpio0_25_task_drtoggle_sts: 1;
        uint32_t r_gpio0_26_task_drtoggle_sts: 1;
        uint32_t r_gpio0_27_task_drtoggle_sts: 1;
        uint32_t r_gpio0_28_task_drtoggle_sts: 1;
        uint32_t r_gpio0_29_task_drtoggle_sts: 1;
        uint32_t r_gpio0_30_task_drtoggle_sts: 1;
        uint32_t r_gpio0_31_task_drtoggle_sts: 1;
    } b;
} GPIO_0_TASK_DRTOGGLE_STS_TypeDef;


/* 0x328
   0       R/W1C  r_gpio0_32_task_drtoggle_sts            1'b0
   1       R/W1C  r_gpio0_33_task_drtoggle_sts            1'b0
   2       R/W1C  r_gpio0_34_task_drtoggle_sts            1'b0
   3       R/W1C  r_gpio0_35_task_drtoggle_sts            1'b0
   4       R/W1C  r_gpio0_36_task_drtoggle_sts            1'b0
   5       R/W1C  r_gpio0_37_task_drtoggle_sts            1'b0
   6       R/W1C  r_gpio0_38_task_drtoggle_sts            1'b0
   7       R/W1C  r_gpio0_39_task_drtoggle_sts            1'b0
   8       R/W1C  r_gpio0_40_task_drtoggle_sts            1'b0
   9       R/W1C  r_gpio0_41_task_drtoggle_sts            1'b0
   10      R/W1C  r_gpio0_42_task_drtoggle_sts            1'b0
   11      R/W1C  r_gpio0_43_task_drtoggle_sts            1'b0
   12      R/W1C  r_gpio0_44_task_drtoggle_sts            1'b0
   13      R/W1C  r_gpio0_45_task_drtoggle_sts            1'b0
   14      R/W1C  r_gpio0_46_task_drtoggle_sts            1'b0
   15      R/W1C  r_gpio0_47_task_drtoggle_sts            1'b0
   16      R/W1C  r_gpio0_48_task_drtoggle_sts            1'b0
   17      R/W1C  r_gpio0_49_task_drtoggle_sts            1'b0
   30:18   R      reserved                                13'h0000
   31      R      r_gpio0_task_nop_sts                    1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_gpio0_32_task_drtoggle_sts: 1;
        uint32_t r_gpio0_33_task_drtoggle_sts: 1;
        uint32_t r_gpio0_34_task_drtoggle_sts: 1;
        uint32_t r_gpio0_35_task_drtoggle_sts: 1;
        uint32_t r_gpio0_36_task_drtoggle_sts: 1;
        uint32_t r_gpio0_37_task_drtoggle_sts: 1;
        uint32_t r_gpio0_38_task_drtoggle_sts: 1;
        uint32_t r_gpio0_39_task_drtoggle_sts: 1;
        uint32_t r_gpio0_40_task_drtoggle_sts: 1;
        uint32_t r_gpio0_41_task_drtoggle_sts: 1;
        uint32_t r_gpio0_42_task_drtoggle_sts: 1;
        uint32_t r_gpio0_43_task_drtoggle_sts: 1;
        uint32_t r_gpio0_44_task_drtoggle_sts: 1;
        uint32_t r_gpio0_45_task_drtoggle_sts: 1;
        uint32_t r_gpio0_46_task_drtoggle_sts: 1;
        uint32_t r_gpio0_47_task_drtoggle_sts: 1;
        uint32_t r_gpio0_48_task_drtoggle_sts: 1;
        uint32_t r_gpio0_49_task_drtoggle_sts: 1;
        const uint32_t reserved_0: 13;
        const uint32_t r_gpio0_task_nop_sts: 1;
    } b;
} GPIO_1_TASK_DRTOGGLE_STS_TypeDef;



/* 0x344
   0       R/W1C  r_girda_evnt_txdone_sts                 1'b0
   1       R/W1C  r_girda_evnt_rxdone_sts                 1'b0
   15:2    R      reserved                                14'h0000
   16      R/W1C  r_girda_task_start_tx_sts               1'b0
   17      R/W1C  r_girda_task_start_rx_sts               1'b0
   31:18   R      reserved                                14'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_girda_evnt_txdone_sts: 1;
        uint32_t r_girda_evnt_rxdone_sts: 1;
        const uint32_t reserved_1: 14;
        uint32_t r_girda_task_start_tx_sts: 1;
        uint32_t r_girda_task_start_rx_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} GIRDA_TASK_EVNT_STS_TypeDef;


/* 0x348
   0       R/W1C  r_i2c0_evnt_error_sts                   1'b0
   1       R/W1C  r_i2c0_evnt_started_sts                 1'b0
   2       R/W1C  r_i2c0_evnt_stopped_sts                 1'b0
   15:3    R      reserved                                13'h0000
   16      R/W1C  r_i2c0_task_start_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c0_evnt_error_sts: 1;
        uint32_t r_i2c0_evnt_started_sts: 1;
        uint32_t r_i2c0_evnt_stopped_sts: 1;
        const uint32_t reserved_1: 13;
        uint32_t r_i2c0_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} I2C0_TASK_EVNT_STS_TypeDef;


/* 0x34C
   0       R/W1C  r_i2c1_evnt_error_sts                   1'b0
   1       R/W1C  r_i2c1_evnt_started_sts                 1'b0
   2       R/W1C  r_i2c1_evnt_stopped_sts                 1'b0
   15:3    R      reserved                                13'h0000
   16      R/W1C  r_i2c1_task_start_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_i2c1_evnt_error_sts: 1;
        uint32_t r_i2c1_evnt_started_sts: 1;
        uint32_t r_i2c1_evnt_stopped_sts: 1;
        const uint32_t reserved_1: 13;
        uint32_t r_i2c1_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} I2C1_TASK_EVNT_STS_TypeDef;


/* 0x350
   0       R/W1C  r_auxadc_evnt_done_sts                  1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_auxadc_task_one_shot_sample_sts       1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_auxadc_evnt_done_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_auxadc_task_one_shot_sample_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} AUXADC_TASK_EVNT_STS_TypeDef;


/* 0x354
   0       R/W1C  r_spi3w_evnt_end_sts                    1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_spi3w_task_start_sts                  1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi3w_evnt_end_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_spi3w_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} SPI3WIRE_TASK_EVNT_STS_TypeDef;


/* 0x358
   0       R/W1C  r_spi0_evnt_start_sts                   1'b0
   1       R/W1C  r_spi0_evnt_end_sts                     1'b0
   15:2    R      reserved                                14'h0000
   16      R/W1C  r_spi0_task_start_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi0_evnt_start_sts: 1;
        uint32_t r_spi0_evnt_end_sts: 1;
        const uint32_t reserved_1: 14;
        uint32_t r_spi0_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} SPI0DUAL_TASK_EVNT_STS_TypeDef;


/* 0x35C
   0       R/W1C  r_spi1_evnt_start_sts                   1'b0
   1       R/W1C  r_spi1_evnt_end_sts                     1'b0
   15:2    R      reserved                                14'h0000
   16      R/W1C  r_spi1_task_start_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_spi1_evnt_start_sts: 1;
        uint32_t r_spi1_evnt_end_sts: 1;
        const uint32_t reserved_1: 14;
        uint32_t r_spi1_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} SPI1MST_TASK_EVNT_STS_TypeDef;


/* 0x364
   0       R/W1C  r_meter_evnt_datardy_sts                1'b0
   1       R/W1C  r_meter_evnt_abs_comp0_sts              1'b0
   2       R/W1C  r_meter_evnt_abs_comp1_sts              1'b0
   3       R/W1C  r_meter_evnt_abs_comp2_sts              1'b0
   4       R/W1C  r_meter_evnt_abs_comp3_sts              1'b0
   5       R/W1C  r_meter_evnt_rel_comp0_sts              1'b0
   6       R/W1C  r_meter_evnt_rel_comp1_sts              1'b0
   7       R/W1C  r_meter_evnt_rel_comp2_sts              1'b0
   8       R/W1C  r_meter_evnt_rel_comp3_sts              1'b0
   9       R/W1C  r_meter_evnt_fw_rel_comp_sts            1'b0
   15:10   R      reserved                                6'h0
   16      R/W1C  r_meter_task_one_shot_sts               1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_meter_evnt_datardy_sts: 1;
        uint32_t r_meter_evnt_abs_comp0_sts: 1;
        uint32_t r_meter_evnt_abs_comp1_sts: 1;
        uint32_t r_meter_evnt_abs_comp2_sts: 1;
        uint32_t r_meter_evnt_abs_comp3_sts: 1;
        uint32_t r_meter_evnt_rel_comp0_sts: 1;
        uint32_t r_meter_evnt_rel_comp1_sts: 1;
        uint32_t r_meter_evnt_rel_comp2_sts: 1;
        uint32_t r_meter_evnt_rel_comp3_sts: 1;
        uint32_t r_meter_evnt_fw_rel_comp_sts: 1;
        const uint32_t reserved_1: 6;
        uint32_t r_meter_task_one_shot_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} TMETER_TASK_EVNT_STS_TypeDef;


/* 0x368
   0       R/W1C  r_dma_evnt_int_tfr3_sts                 1'b0
   1       R/W1C  r_dma_evnt_int_tfr4_sts                 1'b0
   2       R/W1C  r_dma_evnt_int_blk3_sts                 1'b0
   3       R/W1C  r_dma_evnt_int_blk4_sts                 1'b0
   15:4    R      reserved                                12'd0
   16      R/W1C  r_dma_task_chn_en3_sts                  1'b0
   17      R/W1C  r_dma_task_chn_en4_sts                  1'b0
   31:18   R      reserved                                14'd0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_dma_evnt_int_tfr3_sts: 1;
        uint32_t r_dma_evnt_int_tfr4_sts: 1;
        uint32_t r_dma_evnt_int_blk3_sts: 1;
        uint32_t r_dma_evnt_int_blk4_sts: 1;
        const uint32_t reserved_1: 12;
        uint32_t r_dma_task_chn_en3_sts: 1;
        uint32_t r_dma_task_chn_en4_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} DMA_TASK_EVNT_STS_TypeDef;




/* 0x36C
   0       R/W1C  r_sdmk_evnt_done_sts                    1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_sdmk_task_start_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_sdmk_evnt_done_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_sdmk_task_start_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} SDMK_TASK_EVNT_STS_TypeDef;


/* 0x370
   0       R/W1C  r_osc10m_evnt_cal_done_sts              1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_osc10m_task_cal_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc10m_evnt_cal_done_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_osc10m_task_cal_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} OSC10M_CAL_TASK_EVNT_STS_TypeDef;


/* 0x374
   0       R/W1C  r_osc80m_evnt_cal_done_sts              1'b0
   15:1    R      reserved                                15'h0000
   16      R/W1C  r_osc80m_task_cal_sts                   1'b0
   31:17   R      reserved                                15'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_osc80m_evnt_cal_done_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_osc80m_task_cal_sts: 1;
        const uint32_t reserved_0: 15;
    } b;
} OSC80M_CAL_TASK_EVNT_STS_TypeDef;




/* 0xF04
   0       R/W1C  r_rtc_evnt_tick_sts                                 1'b0
   1       R/W1C  r_rtc_evnt_overflow_sts                             1'b0
   2       R/W1C  r_rtc_evnt_compare0_sts                             1'b0
   3       R/W1C  r_rtc_evnt_compare1_sts                             1'b0
   4       R/W1C  r_rtc_evnt_compare2_sts                             1'b0
   5       R/W1C  r_rtc_evnt_compare3_sts                             1'b0
   15:6    R      reserved_f04_15_6                                   10'h000
   16      R/W1C  r_rtc_task_clear_sts                                1'b0
   17      R/W1C  r_rtc_task_stop_sts                                 1'b0
   18      R/W1C  r_rtc_task_start_sts                                1'b0
   19      R/W1C  r_rtc_task_reload_cmp0_sts                          1'b0
   20      R/W1C  r_rtc_task_reload_cmp1_sts                          1'b0
   21      R/W1C  r_rtc_task_reload_cmp2_sts                          1'b0
   22      R/W1C  r_rtc_task_reload_cmp3_sts                          1'b0
   31:23   R      reserved_f04_31_23                                  9'h000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_rtc_evnt_tick_sts: 1;
        uint32_t r_rtc_evnt_overflow_sts: 1;
        uint32_t r_rtc_evnt_compare0_sts: 1;
        uint32_t r_rtc_evnt_compare1_sts: 1;
        uint32_t r_rtc_evnt_compare2_sts: 1;
        uint32_t r_rtc_evnt_compare3_sts: 1;
        const uint32_t reserved_1: 10;
        uint32_t r_rtc_task_clear_sts: 1;
        uint32_t r_rtc_task_stop_sts: 1;
        uint32_t r_rtc_task_start_sts: 1;
        uint32_t r_rtc_task_reload_cmp0_sts: 1;
        uint32_t r_rtc_task_reload_cmp1_sts: 1;
        uint32_t r_rtc_task_reload_cmp2_sts: 1;
        uint32_t r_rtc_task_reload_cmp3_sts: 1;
        const uint32_t reserved_0: 9;
    } b;
} RTC_TASK_EVNT_STS_TypeDef;


/* 0xF08
   0       R/W1C  r_lpc_evnt_status_sts                               1'b0
   15:1    R      reserved_f08_15_1                                   15'h0000
   16      R/W1C  r_lpc_task_start_sts                                1'b0
   17      R/W1C  r_lpc_task_stop_sts                                 1'b0
   31:18   R      reserved_f08_31_18                                  14'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_lpc_evnt_status_sts: 1;
        const uint32_t reserved_1: 15;
        uint32_t r_lpc_task_start_sts: 1;
        uint32_t r_lpc_task_stop_sts: 1;
        const uint32_t reserved_0: 14;
    } b;
} LPC_TASK_EVNT_STS_TypeDef;


/* 0xF0C
   0       R/W1C  r_grtc_evnt_compare0_sts                            1'b0
   1       R/W1C  r_grtc_evnt_compare1_sts                            1'b0
   2       R/W1C  r_grtc_evnt_compare2_sts                            1'b0
   3       R/W1C  r_grtc_evnt_compare3_sts                            1'b0
   4       R/W1C  r_grtc_evnt_compare4_sts                            1'b0
   5       R/W1C  r_grtc_evnt_compare5_sts                            1'b0
   6       R/W1C  r_grtc_evnt_compare6_sts                            1'b0
   7       R/W1C  r_grtc_evnt_compare7_sts                            1'b0
   15:8    R      reserved_f0c_15_8                                   8'h00
   16      R/W1C  r_grtc_task_reload_cmp0_sts                         1'b0
   17      R/W1C  r_grtc_task_reload_cmp1_sts                         1'b0
   18      R/W1C  r_grtc_task_reload_cmp2_sts                         1'b0
   19      R/W1C  r_grtc_task_reload_cmp3_sts                         1'b0
   20      R/W1C  r_grtc_task_reload_cmp4_sts                         1'b0
   21      R/W1C  r_grtc_task_reload_cmp5_sts                         1'b0
   22      R/W1C  r_grtc_task_reload_cmp6_sts                         1'b0
   23      R/W1C  r_grtc_task_reload_cmp7_sts                         1'b0
   31:24   R      reserved_f0c_31_24                                  8'h00
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_grtc_evnt_compare0_sts: 1;
        uint32_t r_grtc_evnt_compare1_sts: 1;
        uint32_t r_grtc_evnt_compare2_sts: 1;
        uint32_t r_grtc_evnt_compare3_sts: 1;
        uint32_t r_grtc_evnt_compare4_sts: 1;
        uint32_t r_grtc_evnt_compare5_sts: 1;
        uint32_t r_grtc_evnt_compare6_sts: 1;
        uint32_t r_grtc_evnt_compare7_sts: 1;
        const uint32_t reserved_1: 8;
        uint32_t r_grtc_task_reload_cmp0_sts: 1;
        uint32_t r_grtc_task_reload_cmp1_sts: 1;
        uint32_t r_grtc_task_reload_cmp2_sts: 1;
        uint32_t r_grtc_task_reload_cmp3_sts: 1;
        uint32_t r_grtc_task_reload_cmp4_sts: 1;
        uint32_t r_grtc_task_reload_cmp5_sts: 1;
        uint32_t r_grtc_task_reload_cmp6_sts: 1;
        uint32_t r_grtc_task_reload_cmp7_sts: 1;
        const uint32_t reserved_0: 8;
    } b;
} GRTC_TASK_EVNT_STS_TypeDef;



/* 0xF10
   0       R/W1C  r_lpc_evnt_status_sts                               1'b0
   31:1    R      reserved_f10_31_1                                   31'h0000
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t r_lpc_evnt_status_sts: 1;
        const uint32_t reserved_0: 31;
    } b;
} AON_PAD_TASK_EVNT_STS_TypeDef;



/* STATUS */
#define RAP_TIMER2_CH0_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_EVENT_ACTIVE_BIT                    (BIT0)
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_FULL_OFFSET   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_FULL_BIT      (BIT(1))
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_MET_TH_OFFSET (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_EVENT_LATCH_CNT0_FIFO_MET_TH_BIT    (BIT(2))
#define RAP_TIMER2_CH0_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_EVENT_STOP_BIT                      (BIT(3))
#define RAP_TIMER2_CH0_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_EVENT_TIMEOUT_BIT                   (BIT(4))
#define RAP_TIMER2_CH0_ACTION_DISABLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_ACTION_DISABLE_BIT                    (BIT(16))
#define RAP_TIMER2_CH0_ACTION_PAUSE_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_ACTION_PAUSE_BIT                      (BIT(17))
#define RAP_TIMER2_CH0_ACTION_START_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER2_TASK_EVNT_STS))))
#define RAP_TIMER2_CH0_ACTION_START_BIT                      (BIT(18))
#define RAP_KEYSCAN_EVENT_MANUAL_DONE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, KEYSCAN_TASK_EVNT_STS))))
#define RAP_KEYSCAN_EVENT_MANUAL_DONE_BIT                  (BIT(0))
#define RAP_KEYSCAN_ACTION_MANUAL_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, KEYSCAN_TASK_EVNT_STS))))
#define RAP_KEYSCAN_ACTION_MANUAL_BIT                        (BIT(16))
#define RAP_TIMER1_CH0_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH0_EVENT_ACTIVE_BIT                    (BIT(0))
#define RAP_TIMER1_CH0_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH0_EVENT_STOP_BIT                      (BIT(1))
#define RAP_TIMER1_CH0_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH0_EVENT_TIMEOUT_BIT                   (BIT(2))
#define RAP_TIMER1_CH1_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH1_EVENT_ACTIVE_BIT                    (BIT(3))
#define RAP_TIMER1_CH1_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH1_EVENT_STOP_BIT                      (BIT(4))
#define RAP_TIMER1_CH1_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH1_EVENT_TIMEOUT_BIT                   (BIT(5))
#define RAP_TIMER1_CH2_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH2_EVENT_ACTIVE_BIT                    (BIT(6))
#define RAP_TIMER1_CH2_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH2_EVENT_STOP_BIT                      (BIT(7))
#define RAP_TIMER1_CH2_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH2_EVENT_TIMEOUT_BIT                   (BIT(8))
#define RAP_TIMER1_CH3_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH3_EVENT_ACTIVE_BIT                    (BIT(9))
#define RAP_TIMER1_CH3_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH3_EVENT_STOP_BIT                      (BIT(10))
#define RAP_TIMER1_CH3_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH3_EVENT_TIMEOUT_BIT                   (BIT(11))
#define RAP_TIMER1_CH4_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH4_EVENT_ACTIVE_BIT                    (BIT(12))
#define RAP_TIMER1_CH4_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH4_EVENT_STOP_BIT                      (BIT(13))
#define RAP_TIMER1_CH4_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH4_EVENT_TIMEOUT_BIT                   (BIT(14))
#define RAP_TIMER1_CH5_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH5_EVENT_ACTIVE_BIT                    (BIT(15))
#define RAP_TIMER1_CH5_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH5_EVENT_STOP_BIT                      (BIT(16))
#define RAP_TIMER1_CH5_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH5_EVENT_TIMEOUT_BIT                   (BIT(17))
#define RAP_TIMER1_CH6_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH6_EVENT_ACTIVE_BIT                    (BIT(18))
#define RAP_TIMER1_CH6_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH6_EVENT_STOP_BIT                      (BIT(19))
#define RAP_TIMER1_CH6_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH6_EVENT_TIMEOUT_BIT                   (BIT(20))
#define RAP_TIMER1_CH7_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH7_EVENT_ACTIVE_BIT                    (BIT(21))
#define RAP_TIMER1_CH7_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH7_EVENT_STOP_BIT                      (BIT(22))
#define RAP_TIMER1_CH7_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH7_EVENT_TIMEOUT_BIT                   (BIT(23))
#define RAP_TIMER1_CH8_EVENT_ACTIVE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH8_EVENT_ACTIVE_BIT                    (BIT(24))
#define RAP_TIMER1_CH8_EVENT_STOP_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH8_EVENT_STOP_BIT                      (BIT(25))
#define RAP_TIMER1_CH8_EVENT_TIMEOUT_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_EVNT_STS))))
#define RAP_TIMER1_CH8_EVENT_TIMEOUT_BIT                   (BIT(26))
#define RAP_TIMER1_CH0_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH0_ACTION_DISABLE_BIT                  (BIT(0))
#define RAP_TIMER1_CH0_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH0_ACTION_PAUSE_BIT                    (BIT(1))
#define RAP_TIMER1_CH0_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH0_ACTION_START_BIT                    (BIT(2))
#define RAP_TIMER1_CH1_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH1_ACTION_DISABLE_BIT                  (BIT(3))
#define RAP_TIMER1_CH1_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH1_ACTION_PAUSE_BIT                    (BIT(4))
#define RAP_TIMER1_CH1_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH1_ACTION_START_BIT                    (BIT(5))
#define RAP_TIMER1_CH2_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH2_ACTION_DISABLE_BIT                  (BIT(6))
#define RAP_TIMER1_CH2_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH2_ACTION_PAUSE_BIT                    (BIT(7))
#define RAP_TIMER1_CH2_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH2_ACTION_START_BIT                    (BIT(8))
#define RAP_TIMER1_CH3_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH3_ACTION_DISABLE_BIT                  (BIT(9))
#define RAP_TIMER1_CH3_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH3_ACTION_PAUSE_BIT                    (BIT(10))
#define RAP_TIMER1_CH3_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH3_ACTION_START_BIT                    (BIT(11))
#define RAP_TIMER1_CH4_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH4_ACTION_DISABLE_BIT                  (BIT(12))
#define RAP_TIMER1_CH4_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH4_ACTION_PAUSE_BIT                    (BIT(13))
#define RAP_TIMER1_CH4_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH4_ACTION_START_BIT                    (BIT(14))
#define RAP_TIMER1_CH5_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH5_ACTION_DISABLE_BIT                  (BIT(15))
#define RAP_TIMER1_CH5_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH5_ACTION_PAUSE_BIT                    (BIT(16))
#define RAP_TIMER1_CH5_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH5_ACTION_START_BIT                    (BIT(17))
#define RAP_TIMER1_CH6_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH6_ACTION_DISABLE_BIT                  (BIT(18))
#define RAP_TIMER1_CH6_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH6_ACTION_PAUSE_BIT                    (BIT(19))
#define RAP_TIMER1_CH6_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH6_ACTION_START_BIT                    (BIT(20))
#define RAP_TIMER1_CH7_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH7_ACTION_DISABLE_BIT                  (BIT(21))
#define RAP_TIMER1_CH7_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH7_ACTION_PAUSE_BIT                    (BIT(22))
#define RAP_TIMER1_CH7_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH7_ACTION_START_BIT                    (BIT(23))
#define RAP_TIMER1_CH8_ACTION_DISABLE_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH8_ACTION_DISABLE_BIT                  (BIT(24))
#define RAP_TIMER1_CH8_ACTION_PAUSE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH8_ACTION_PAUSE_BIT                    (BIT(25))
#define RAP_TIMER1_CH8_ACTION_START_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TIMER1_TASK_STS))))
#define RAP_TIMER1_CH8_ACTION_START_BIT                    (BIT(26))

#define RAP_GPIOA_0_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_1_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_2_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_3_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_4_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_5_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_6_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_7_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_8_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_9_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_10_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_11_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_12_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_13_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_14_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_15_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_16_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_17_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_18_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_19_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_20_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_21_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_22_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_23_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_24_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_25_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_26_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_27_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_28_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_29_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_30_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOA_31_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_EVNT_STS))))
#define RAP_GPIOB_0_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_1_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_2_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_3_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_4_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_5_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_6_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_7_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_8_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_9_EVENT_OFFSET                           (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_10_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_11_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_12_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_13_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_14_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_15_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_16_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOB_17_EVENT_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_EVENT_STS))))
#define RAP_GPIOA_0_EVENT_BIT                              (BIT(0))
#define RAP_GPIOA_1_EVENT_BIT                              (BIT(1))
#define RAP_GPIOA_2_EVENT_BIT                              (BIT(2))
#define RAP_GPIOA_3_EVENT_BIT                              (BIT(3))
#define RAP_GPIOA_4_EVENT_BIT                              (BIT(4))
#define RAP_GPIOA_5_EVENT_BIT                              (BIT(5))
#define RAP_GPIOA_6_EVENT_BIT                              (BIT(6))
#define RAP_GPIOA_7_EVENT_BIT                              (BIT(7))
#define RAP_GPIOA_8_EVENT_BIT                              (BIT(8))
#define RAP_GPIOA_9_EVENT_BIT                              (BIT(9))
#define RAP_GPIOA_10_EVENT_BIT                             (BIT(10))
#define RAP_GPIOA_11_EVENT_BIT                             (BIT(11))
#define RAP_GPIOA_12_EVENT_BIT                             (BIT(12))
#define RAP_GPIOA_13_EVENT_BIT                             (BIT(13))
#define RAP_GPIOA_14_EVENT_BIT                             (BIT(14))
#define RAP_GPIOA_15_EVENT_BIT                             (BIT(15))
#define RAP_GPIOA_16_EVENT_BIT                             (BIT(16))
#define RAP_GPIOA_17_EVENT_BIT                             (BIT(17))
#define RAP_GPIOA_18_EVENT_BIT                             (BIT(18))
#define RAP_GPIOA_19_EVENT_BIT                             (BIT(19))
#define RAP_GPIOA_20_EVENT_BIT                             (BIT(20))
#define RAP_GPIOA_21_EVENT_BIT                             (BIT(21))
#define RAP_GPIOA_22_EVENT_BIT                             (BIT(22))
#define RAP_GPIOA_23_EVENT_BIT                             (BIT(23))
#define RAP_GPIOA_24_EVENT_BIT                             (BIT(24))
#define RAP_GPIOA_25_EVENT_BIT                             (BIT(25))
#define RAP_GPIOA_26_EVENT_BIT                             (BIT(26))
#define RAP_GPIOA_27_EVENT_BIT                             (BIT(27))
#define RAP_GPIOA_28_EVENT_BIT                             (BIT(28))
#define RAP_GPIOA_29_EVENT_BIT                             (BIT(29))
#define RAP_GPIOA_30_EVENT_BIT                             (BIT(30))
#define RAP_GPIOA_31_EVENT_BIT                             (BIT(31))
#define RAP_GPIOB_0_EVENT_BIT                              (BIT(0))
#define RAP_GPIOB_1_EVENT_BIT                              (BIT(1))
#define RAP_GPIOB_2_EVENT_BIT                              (BIT(2))
#define RAP_GPIOB_3_EVENT_BIT                              (BIT(3))
#define RAP_GPIOB_4_EVENT_BIT                              (BIT(4))
#define RAP_GPIOB_5_EVENT_BIT                              (BIT(5))
#define RAP_GPIOB_6_EVENT_BIT                              (BIT(6))
#define RAP_GPIOB_7_EVENT_BIT                              (BIT(7))
#define RAP_GPIOB_8_EVENT_BIT                              (BIT(8))
#define RAP_GPIOB_9_EVENT_BIT                              (BIT(9))
#define RAP_GPIOB_10_EVENT_BIT                             (BIT(10))
#define RAP_GPIOB_11_EVENT_BIT                             (BIT(11))
#define RAP_GPIOB_12_EVENT_BIT                             (BIT(12))
#define RAP_GPIOB_13_EVENT_BIT                             (BIT(13))
#define RAP_GPIOB_14_EVENT_BIT                             (BIT(14))
#define RAP_GPIOB_15_EVENT_BIT                             (BIT(15))
#define RAP_GPIOB_16_EVENT_BIT                             (BIT(16))
#define RAP_GPIOB_17_EVENT_BIT                             (BIT(17))

#define RAP_GPIOA_0_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_1_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_2_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_3_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_4_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_5_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_6_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_7_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_8_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_9_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_10_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_11_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_12_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_13_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_14_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_15_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_16_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_17_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_18_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_19_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_20_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_21_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_22_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_23_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_24_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_25_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_26_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_27_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_28_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_29_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_30_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOA_31_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRCLR_STS))))
#define RAP_GPIOB_0_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_1_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_2_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_3_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_4_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_5_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_6_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_7_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_8_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_9_ACTION_DRCLR_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_10_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_11_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_12_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_13_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_14_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_15_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_16_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOB_17_ACTION_DRCLR_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRCLR_STS))))
#define RAP_GPIOA_0_ACTION_DRCLR_BIT                       (BIT(0))
#define RAP_GPIOA_1_ACTION_DRCLR_BIT                       (BIT(1))
#define RAP_GPIOA_2_ACTION_DRCLR_BIT                       (BIT(2))
#define RAP_GPIOA_3_ACTION_DRCLR_BIT                       (BIT(3))
#define RAP_GPIOA_4_ACTION_DRCLR_BIT                       (BIT(4))
#define RAP_GPIOA_5_ACTION_DRCLR_BIT                       (BIT(5))
#define RAP_GPIOA_6_ACTION_DRCLR_BIT                       (BIT(6))
#define RAP_GPIOA_7_ACTION_DRCLR_BIT                       (BIT(7))
#define RAP_GPIOA_8_ACTION_DRCLR_BIT                       (BIT(8))
#define RAP_GPIOA_9_ACTION_DRCLR_BIT                       (BIT(9))
#define RAP_GPIOA_10_ACTION_DRCLR_BIT                      (BIT(10))
#define RAP_GPIOA_11_ACTION_DRCLR_BIT                      (BIT(11))
#define RAP_GPIOA_12_ACTION_DRCLR_BIT                      (BIT(12))
#define RAP_GPIOA_13_ACTION_DRCLR_BIT                      (BIT(13))
#define RAP_GPIOA_14_ACTION_DRCLR_BIT                      (BIT(14))
#define RAP_GPIOA_15_ACTION_DRCLR_BIT                      (BIT(15))
#define RAP_GPIOA_16_ACTION_DRCLR_BIT                      (BIT(16))
#define RAP_GPIOA_17_ACTION_DRCLR_BIT                      (BIT(17))
#define RAP_GPIOA_18_ACTION_DRCLR_BIT                      (BIT(18))
#define RAP_GPIOA_19_ACTION_DRCLR_BIT                      (BIT(19))
#define RAP_GPIOA_20_ACTION_DRCLR_BIT                      (BIT(20))
#define RAP_GPIOA_21_ACTION_DRCLR_BIT                      (BIT(21))
#define RAP_GPIOA_22_ACTION_DRCLR_BIT                      (BIT(22))
#define RAP_GPIOA_23_ACTION_DRCLR_BIT                      (BIT(23))
#define RAP_GPIOA_24_ACTION_DRCLR_BIT                      (BIT(24))
#define RAP_GPIOA_25_ACTION_DRCLR_BIT                      (BIT(25))
#define RAP_GPIOA_26_ACTION_DRCLR_BIT                      (BIT(26))
#define RAP_GPIOA_27_ACTION_DRCLR_BIT                      (BIT(27))
#define RAP_GPIOA_28_ACTION_DRCLR_BIT                      (BIT(28))
#define RAP_GPIOA_29_ACTION_DRCLR_BIT                      (BIT(29))
#define RAP_GPIOA_30_ACTION_DRCLR_BIT                      (BIT(30))
#define RAP_GPIOA_31_ACTION_DRCLR_BIT                      (BIT(31))
#define RAP_GPIOB_0_ACTION_DRCLR_BIT                       (BIT(0))
#define RAP_GPIOB_1_ACTION_DRCLR_BIT                       (BIT(1))
#define RAP_GPIOB_2_ACTION_DRCLR_BIT                       (BIT(2))
#define RAP_GPIOB_3_ACTION_DRCLR_BIT                       (BIT(3))
#define RAP_GPIOB_4_ACTION_DRCLR_BIT                       (BIT(4))
#define RAP_GPIOB_5_ACTION_DRCLR_BIT                       (BIT(5))
#define RAP_GPIOB_6_ACTION_DRCLR_BIT                       (BIT(6))
#define RAP_GPIOB_7_ACTION_DRCLR_BIT                       (BIT(7))
#define RAP_GPIOB_8_ACTION_DRCLR_BIT                       (BIT(8))
#define RAP_GPIOB_9_ACTION_DRCLR_BIT                       (BIT(9))
#define RAP_GPIOB_10_ACTION_DRCLR_BIT                      (BIT(10))
#define RAP_GPIOB_11_ACTION_DRCLR_BIT                      (BIT(11))
#define RAP_GPIOB_12_ACTION_DRCLR_BIT                      (BIT(12))
#define RAP_GPIOB_13_ACTION_DRCLR_BIT                      (BIT(13))
#define RAP_GPIOB_14_ACTION_DRCLR_BIT                      (BIT(14))
#define RAP_GPIOB_15_ACTION_DRCLR_BIT                      (BIT(15))
#define RAP_GPIOB_16_ACTION_DRCLR_BIT                      (BIT(16))
#define RAP_GPIOB_17_ACTION_DRCLR_BIT                      (BIT(17))

#define RAP_GPIOA_0_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_1_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_2_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_3_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_4_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_5_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_6_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_7_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_8_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_9_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_10_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_11_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_12_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_13_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_14_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_15_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_16_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_17_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_18_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_19_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_20_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_21_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_22_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_23_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_24_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_25_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_26_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_27_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_28_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_29_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_30_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOA_31_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRSET_STS))))
#define RAP_GPIOB_0_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_1_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_2_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_3_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_4_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_5_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_6_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_7_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_8_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_9_ACTION_DRSET_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_10_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_11_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_12_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_13_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_14_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_15_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_16_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOB_17_ACTION_DRSET_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRSET_STS))))
#define RAP_GPIOA_0_ACTION_DRSET_BIT                       (BIT(0))
#define RAP_GPIOA_1_ACTION_DRSET_BIT                       (BIT(1))
#define RAP_GPIOA_2_ACTION_DRSET_BIT                       (BIT(2))
#define RAP_GPIOA_3_ACTION_DRSET_BIT                       (BIT(3))
#define RAP_GPIOA_4_ACTION_DRSET_BIT                       (BIT(4))
#define RAP_GPIOA_5_ACTION_DRSET_BIT                       (BIT(5))
#define RAP_GPIOA_6_ACTION_DRSET_BIT                       (BIT(6))
#define RAP_GPIOA_7_ACTION_DRSET_BIT                       (BIT(7))
#define RAP_GPIOA_8_ACTION_DRSET_BIT                       (BIT(8))
#define RAP_GPIOA_9_ACTION_DRSET_BIT                       (BIT(9))
#define RAP_GPIOA_10_ACTION_DRSET_BIT                      (BIT(10))
#define RAP_GPIOA_11_ACTION_DRSET_BIT                      (BIT(11))
#define RAP_GPIOA_12_ACTION_DRSET_BIT                      (BIT(12))
#define RAP_GPIOA_13_ACTION_DRSET_BIT                      (BIT(13))
#define RAP_GPIOA_14_ACTION_DRSET_BIT                      (BIT(14))
#define RAP_GPIOA_15_ACTION_DRSET_BIT                      (BIT(15))
#define RAP_GPIOA_16_ACTION_DRSET_BIT                      (BIT(16))
#define RAP_GPIOA_17_ACTION_DRSET_BIT                      (BIT(17))
#define RAP_GPIOA_18_ACTION_DRSET_BIT                      (BIT(18))
#define RAP_GPIOA_19_ACTION_DRSET_BIT                      (BIT(19))
#define RAP_GPIOA_20_ACTION_DRSET_BIT                      (BIT(20))
#define RAP_GPIOA_21_ACTION_DRSET_BIT                      (BIT(21))
#define RAP_GPIOA_22_ACTION_DRSET_BIT                      (BIT(22))
#define RAP_GPIOA_23_ACTION_DRSET_BIT                      (BIT(23))
#define RAP_GPIOA_24_ACTION_DRSET_BIT                      (BIT(24))
#define RAP_GPIOA_25_ACTION_DRSET_BIT                      (BIT(25))
#define RAP_GPIOA_26_ACTION_DRSET_BIT                      (BIT(26))
#define RAP_GPIOA_27_ACTION_DRSET_BIT                      (BIT(27))
#define RAP_GPIOA_28_ACTION_DRSET_BIT                      (BIT(28))
#define RAP_GPIOA_29_ACTION_DRSET_BIT                      (BIT(29))
#define RAP_GPIOA_30_ACTION_DRSET_BIT                      (BIT(30))
#define RAP_GPIOA_31_ACTION_DRSET_BIT                      (BIT(31))
#define RAP_GPIOB_0_ACTION_DRSET_BIT                       (BIT(0))
#define RAP_GPIOB_1_ACTION_DRSET_BIT                       (BIT(1))
#define RAP_GPIOB_2_ACTION_DRSET_BIT                       (BIT(2))
#define RAP_GPIOB_3_ACTION_DRSET_BIT                       (BIT(3))
#define RAP_GPIOB_4_ACTION_DRSET_BIT                       (BIT(4))
#define RAP_GPIOB_5_ACTION_DRSET_BIT                       (BIT(5))
#define RAP_GPIOB_6_ACTION_DRSET_BIT                       (BIT(6))
#define RAP_GPIOB_7_ACTION_DRSET_BIT                       (BIT(7))
#define RAP_GPIOB_8_ACTION_DRSET_BIT                       (BIT(8))
#define RAP_GPIOB_9_ACTION_DRSET_BIT                       (BIT(9))
#define RAP_GPIOB_10_ACTION_DRSET_BIT                      (BIT(10))
#define RAP_GPIOB_11_ACTION_DRSET_BIT                      (BIT(11))
#define RAP_GPIOB_12_ACTION_DRSET_BIT                      (BIT(12))
#define RAP_GPIOB_13_ACTION_DRSET_BIT                      (BIT(13))
#define RAP_GPIOB_14_ACTION_DRSET_BIT                      (BIT(14))
#define RAP_GPIOB_15_ACTION_DRSET_BIT                      (BIT(15))
#define RAP_GPIOB_16_ACTION_DRSET_BIT                      (BIT(16))
#define RAP_GPIOB_17_ACTION_DRSET_BIT                      (BIT(17))

#define RAP_GPIOA_0_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_1_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_2_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_3_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_4_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_5_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_6_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_7_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_8_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_9_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_10_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_11_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_12_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_13_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_14_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_15_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_16_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_17_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_18_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_19_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_20_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_21_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_22_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_23_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_24_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_25_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_26_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_27_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_28_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_29_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_30_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_31_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_0_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_0_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_1_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_2_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_3_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_4_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_5_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_6_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_7_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_8_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_9_ACTION_DRTOGGLE_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_10_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_11_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_12_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_13_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_14_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_15_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_16_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOB_17_ACTION_DRTOGGLE_OFFSET                (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIO_ACTION_NOP_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GPIO_1_TASK_DRTOGGLE_STS))))
#define RAP_GPIOA_0_ACTION_DRTOGGLE_BIT                    (BIT(0))
#define RAP_GPIOA_1_ACTION_DRTOGGLE_BIT                    (BIT(1))
#define RAP_GPIOA_2_ACTION_DRTOGGLE_BIT                    (BIT(2))
#define RAP_GPIOA_3_ACTION_DRTOGGLE_BIT                    (BIT(3))
#define RAP_GPIOA_4_ACTION_DRTOGGLE_BIT                    (BIT(4))
#define RAP_GPIOA_5_ACTION_DRTOGGLE_BIT                    (BIT(5))
#define RAP_GPIOA_6_ACTION_DRTOGGLE_BIT                    (BIT(6))
#define RAP_GPIOA_7_ACTION_DRTOGGLE_BIT                    (BIT(7))
#define RAP_GPIOA_8_ACTION_DRTOGGLE_BIT                    (BIT(8))
#define RAP_GPIOA_9_ACTION_DRTOGGLE_BIT                    (BIT(9))
#define RAP_GPIOA_10_ACTION_DRTOGGLE_BIT                   (BIT(10))
#define RAP_GPIOA_11_ACTION_DRTOGGLE_BIT                   (BIT(11))
#define RAP_GPIOA_12_ACTION_DRTOGGLE_BIT                   (BIT(12))
#define RAP_GPIOA_13_ACTION_DRTOGGLE_BIT                   (BIT(13))
#define RAP_GPIOA_14_ACTION_DRTOGGLE_BIT                   (BIT(14))
#define RAP_GPIOA_15_ACTION_DRTOGGLE_BIT                   (BIT(15))
#define RAP_GPIOA_16_ACTION_DRTOGGLE_BIT                   (BIT(16))
#define RAP_GPIOA_17_ACTION_DRTOGGLE_BIT                   (BIT(17))
#define RAP_GPIOA_18_ACTION_DRTOGGLE_BIT                   (BIT(18))
#define RAP_GPIOA_19_ACTION_DRTOGGLE_BIT                   (BIT(19))
#define RAP_GPIOA_20_ACTION_DRTOGGLE_BIT                   (BIT(20))
#define RAP_GPIOA_21_ACTION_DRTOGGLE_BIT                   (BIT(21))
#define RAP_GPIOA_22_ACTION_DRTOGGLE_BIT                   (BIT(22))
#define RAP_GPIOA_23_ACTION_DRTOGGLE_BIT                   (BIT(23))
#define RAP_GPIOA_24_ACTION_DRTOGGLE_BIT                   (BIT(24))
#define RAP_GPIOA_25_ACTION_DRTOGGLE_BIT                   (BIT(25))
#define RAP_GPIOA_26_ACTION_DRTOGGLE_BIT                   (BIT(26))
#define RAP_GPIOA_27_ACTION_DRTOGGLE_BIT                   (BIT(27))
#define RAP_GPIOA_28_ACTION_DRTOGGLE_BIT                   (BIT(28))
#define RAP_GPIOA_29_ACTION_DRTOGGLE_BIT                   (BIT(29))
#define RAP_GPIOA_30_ACTION_DRTOGGLE_BIT                   (BIT(30))
#define RAP_GPIOA_31_ACTION_DRTOGGLE_BIT                   (BIT(31))
#define RAP_GPIOB_0_ACTION_DRTOGGLE_BIT                    (BIT(0))
#define RAP_GPIOB_1_ACTION_DRTOGGLE_BIT                    (BIT(1))
#define RAP_GPIOB_2_ACTION_DRTOGGLE_BIT                    (BIT(2))
#define RAP_GPIOB_3_ACTION_DRTOGGLE_BIT                    (BIT(3))
#define RAP_GPIOB_4_ACTION_DRTOGGLE_BIT                    (BIT(4))
#define RAP_GPIOB_5_ACTION_DRTOGGLE_BIT                    (BIT(5))
#define RAP_GPIOB_6_ACTION_DRTOGGLE_BIT                    (BIT(6))
#define RAP_GPIOB_7_ACTION_DRTOGGLE_BIT                    (BIT(7))
#define RAP_GPIOB_8_ACTION_DRTOGGLE_BIT                    (BIT(8))
#define RAP_GPIOB_9_ACTION_DRTOGGLE_BIT                    (BIT(9))
#define RAP_GPIOB_10_ACTION_DRTOGGLE_BIT                   (BIT(10))
#define RAP_GPIOB_11_ACTION_DRTOGGLE_BIT                   (BIT(11))
#define RAP_GPIOB_12_ACTION_DRTOGGLE_BIT                   (BIT(12))
#define RAP_GPIOB_13_ACTION_DRTOGGLE_BIT                   (BIT(13))
#define RAP_GPIOB_14_ACTION_DRTOGGLE_BIT                   (BIT(14))
#define RAP_GPIOB_15_ACTION_DRTOGGLE_BIT                   (BIT(15))
#define RAP_GPIOB_16_ACTION_DRTOGGLE_BIT                   (BIT(16))
#define RAP_GPIOB_17_ACTION_DRTOGGLE_BIT                   (BIT(17))
#define RAP_GPIO_ACTION_NOP_BIT                            (BIT(31))

#define RAP_IR_EVENT_TXDONE_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GIRDA_TASK_EVNT_STS))))
#define RAP_IR_EVENT_TXDONE_BIT                            (BIT(0))
#define RAP_IR_EVENT_RXDONE_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GIRDA_TASK_EVNT_STS))))
#define RAP_IR_EVENT_RXDONE_BIT                            (BIT(1))
#define RAP_IR_ACTION_START_TX_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GIRDA_TASK_EVNT_STS))))
#define RAP_IR_ACTION_START_TX_BIT                         (BIT(16))
#define RAP_IR_ACTION_START_RX_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GIRDA_TASK_EVNT_STS))))
#define RAP_IR_ACTION_START_RX_BIT                         (BIT(17))
#define RAP_I2C0_EVENT_ERROR_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C0_TASK_EVNT_STS))))
#define RAP_I2C0_EVENT_ERROR_BIT                           (BIT(0))
#define RAP_I2C0_EVENT_STARTED_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C0_TASK_EVNT_STS))))
#define RAP_I2C0_EVENT_STARTED_BIT                         (BIT(1))
#define RAP_I2C0_EVENT_STOPPED_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C0_TASK_EVNT_STS))))
#define RAP_I2C0_EVENT_STOPPED_BIT                         (BIT(2))
#define RAP_I2C0_ACTION_START_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C0_TASK_EVNT_STS))))
#define RAP_I2C0_ACTION_START_BIT                          (BIT(16))
#define RAP_I2C1_EVENT_ERROR_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C1_TASK_EVNT_STS))))
#define RAP_I2C1_EVENT_ERROR_BIT                           (BIT(0))
#define RAP_I2C1_EVENT_STARTED_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C1_TASK_EVNT_STS))))
#define RAP_I2C1_EVENT_STARTED_BIT                          (BIT(1))
#define RAP_I2C1_EVENT_STOPPED_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C1_TASK_EVNT_STS))))
#define RAP_I2C1_EVENT_STOPPED_BIT                         (BIT(2))
#define RAP_I2C1_ACTION_START_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, I2C1_TASK_EVNT_STS))))
#define RAP_I2C1_ACTION_START_BIT                          (BIT(16))
#define RAP_ADC_EVENT_DONE_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, AUXADC_TASK_EVNT_STS))))
#define RAP_ADC_EVENT_DONE_BIT                             (BIT(0))
#define RAP_ADC_ACTION_ONE_SHOT_SAMPLE_OFFSET              (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, AUXADC_TASK_EVNT_STS))))
#define RAP_ADC_ACTION_ONE_SHOT_SAMPLE_BIT                 (BIT(16))
#define RAP_SPI3WIRE_EVENT_END_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI3WIRE_TASK_EVNT_STS))))
#define RAP_SPI3WIRE_EVENT_END_BIT                         (BIT(0))
#define RAP_SPI3WIRE_ACTION_START_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI3WIRE_TASK_EVNT_STS))))
#define RAP_SPI3WIRE_ACTION_START_BIT                      (BIT(16))
#define RAP_SPI0_EVENT_START_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI0DUAL_TASK_EVNT_STS))))
#define RAP_SPI0_EVENT_START_BIT                           (BIT(0))
#define RAP_SPI0_EVENT_END_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI0DUAL_TASK_EVNT_STS))))
#define RAP_SPI0_EVENT_END_BIT                             (BIT(1))
#define RAP_SPI0_ACTION_START_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI0DUAL_TASK_EVNT_STS))))
#define RAP_SPI0_ACTION_START_BIT                          (BIT(16))
#define RAP_SPI1_EVENT_START_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI1MST_TASK_EVNT_STS))))
#define RAP_SPI1_EVENT_START_BIT                           (BIT(0))
#define RAP_SPI1_EVENT_END_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI1MST_TASK_EVNT_STS))))
#define RAP_SPI1_EVENT_END_BIT                             (BIT(1))
#define RAP_SPI1_ACTION_START_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SPI1MST_TASK_EVNT_STS))))
#define RAP_SPI1_ACTION_START_BIT                          (BIT(16))
#define RAP_TMETER_EVENT_DATARDY_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_DATARDY_BIT                       (BIT(0))
#define RAP_TMETER_EVENT_ABS_CMP0_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_ABS_CMP0_BIT                      (BIT(1))
#define RAP_TMETER_EVENT_ABS_CMP1_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_ABS_CMP1_BIT                      (BIT(2))
#define RAP_TMETER_EVENT_ABS_CMP2_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_ABS_CMP2_BIT                      (BIT(3))
#define RAP_TMETER_EVENT_ABS_CMP3_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_ABS_CMP3_BIT                      (BIT(4))
#define RAP_TMETER_EVENT_REL_CMP0_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_REL_CMP0_BIT                      (BIT(5))
#define RAP_TMETER_EVENT_REL_CMP1_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_REL_CMP1_BIT                      (BIT(6))
#define RAP_TMETER_EVENT_REL_CMP2_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_REL_CMP2_BIT                      (BIT(7))
#define RAP_TMETER_EVENT_REL_CMP3_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_REL_CMP3_BIT                      (BIT(8))
#define RAP_TMETER_EVENT_FW_REL_COMP3_OFFSET               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_EVENT_FW_REL_COMP3_BIT                  (BIT(9))
#define RAP_TMETER_ACTION_ONESHOT_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, TMETER_TASK_EVNT_STS))))
#define RAP_TMETER_ACTION_ONESHOT_BIT                      (BIT(16))
#define RAP_DMA_EVENT_INT_TRANSFER3_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_EVENT_INT_TRANSFER3_BIT                    (BIT(3))
#define RAP_DMA_EVENT_INT_TRANSFER4_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_EVENT_INT_TRANSFER4_BIT                    (BIT(4))
#define RAP_DMA_EVENT_INT_BLOCK3_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_EVENT_INT_BLOCK3_BIT                       (BIT(9))
#define RAP_DMA_EVENT_INT_BLOCK4_OFFSET                    (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_EVENT_INT_BLOCK4_BIT                       (BIT(10))
#define RAP_DMA_ACTION_CHANNEL_EN0_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN0_BIT                     (BIT(16))
#define RAP_DMA_ACTION_CHANNEL_EN1_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN1_BIT                     (BIT(17))
#define RAP_DMA_ACTION_CHANNEL_EN2_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN2_BIT                     (BIT(18))
#define RAP_DMA_ACTION_CHANNEL_EN3_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN3_BIT                     (BIT(19))
#define RAP_DMA_ACTION_CHANNEL_EN4_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN4_BIT                     (BIT(20))
#define RAP_DMA_ACTION_CHANNEL_EN5_OFFSET                  (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, DMA_TASK_EVNT_STS))))
#define RAP_DMA_ACTION_CHANNEL_EN5_BIT                     (BIT(21))
#define RAP_GRTC_EVENT_COMPARE0_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE0_BIT                        (BIT(0))
#define RAP_GRTC_EVENT_COMPARE1_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE1_BIT                        (BIT(1))
#define RAP_GRTC_EVENT_COMPARE2_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE2_BIT                        (BIT(2))
#define RAP_GRTC_EVENT_COMPARE3_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE3_BIT                        (BIT(3))
#define RAP_GRTC_EVENT_COMPARE4_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE4_BIT                        (BIT(4))
#define RAP_GRTC_EVENT_COMPARE5_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE5_BIT                        (BIT(5))
#define RAP_GRTC_EVENT_COMPARE6_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE6_BIT                        (BIT(6))
#define RAP_GRTC_EVENT_COMPARE7_OFFSET                     (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_EVENT_COMPARE7_BIT                        (BIT(7))
#define RAP_GRTC_ACTION_RELOAD_CMP0_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP0_BIT                    (BIT(16))
#define RAP_GRTC_ACTION_RELOAD_CMP1_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP1_BIT                    (BIT(17))
#define RAP_GRTC_ACTION_RELOAD_CMP2_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP2_BIT                    (BIT(18))
#define RAP_GRTC_ACTION_RELOAD_CMP3_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP3_BIT                    (BIT(19))
#define RAP_GRTC_ACTION_RELOAD_CMP4_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP4_BIT                    (BIT(20))
#define RAP_GRTC_ACTION_RELOAD_CMP5_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP5_BIT                    (BIT(21))
#define RAP_GRTC_ACTION_RELOAD_CMP6_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP6_BIT                    (BIT(22))
#define RAP_GRTC_ACTION_RELOAD_CMP7_OFFSET                 (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, GRTC_TASK_EVNT_STS))))
#define RAP_GRTC_ACTION_RELOAD_CMP7_BIT                    (BIT(23))
#define RAP_PAD_EVENT_OFFSET                               (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, AON_PAD_TASK_EVNT_STS))))
#define RAP_PAD_EVENT_BIT                                  (BIT(0))
#define RAP_SDMK_EVENT_DONE_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SDMK_TASK_EVNT_STS))))
#define RAP_SDMK_EVENT_DONE_BIT                            (BIT(0))
#define RAP_SDMK_ACTION_START_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, SDMK_TASK_EVNT_STS))))
#define RAP_SDMK_ACTION_START_BIT                          (BIT(16))
#define RAP_OSC10M_EVENT_CAL_DONE_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, OSC10M_CAL_TASK_EVNT_STS))))
#define RAP_OSC10M_EVENT_CAL_DONE_BIT                      (BIT(0))
#define RAP_OSC10M_ACTION_CAL_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, OSC10M_CAL_TASK_EVNT_STS))))
#define RAP_OSC10M_ACTION_CAL_BIT                          (BIT(16))
#define RAP_OSC80M_EVENT_CAL_DONE_OFFSET                   (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, OSC80M_CAL_TASK_EVNT_STS))))
#define RAP_OSC80M_EVENT_CAL_DONE_BIT                      (BIT(0))
#define RAP_OSC80M_ACTION_CAL_OFFSET                       (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, OSC80M_CAL_TASK_EVNT_STS))))
#define RAP_OSC80M_ACTION_CAL_BIT                          (BIT(16))
#define RAP_RTC_EVENT_TICK_OFFSET                          (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_TICK_BIT                             (BIT(0))
#define RAP_RTC_EVENT_OVERFLOW_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_OVERFLOW_BIT                         (BIT(1))
#define RAP_RTC_EVENT_COMPARE0_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_COMPARE0_BIT                         (BIT(2))
#define RAP_RTC_EVENT_COMPARE1_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_COMPARE1_BIT                         (BIT(3))
#define RAP_RTC_EVENT_COMPARE2_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_COMPARE2_BIT                         (BIT(4))
#define RAP_RTC_EVENT_COMPARE3_OFFSET                      (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_EVENT_COMPARE3_BIT                         (BIT(5))
#define RAP_RTC_ACTION_CLEAR_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_ACTION_CLEAR_BIT                           (BIT(16))
#define RAP_RTC_ACTION_STOP_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_ACTION_STOP_BIT                            (BIT(17))
#define RAP_RTC_ACTION_START_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, RTC_TASK_EVNT_STS))))
#define RAP_RTC_ACTION_START_BIT                           (BIT(18))
#define RAP_LPC_EVENT_STATUS_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, LPC_TASK_EVNT_STS))))
#define RAP_LPC_EVENT_STATUS_BIT                           (BIT(0))
#define RAP_LPC_ACTION_START_OFFSET                        (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, LPC_TASK_EVNT_STS))))
#define RAP_LPC_ACTION_START_BIT                           (BIT(16))
#define RAP_LPC_ACTION_STOP_OFFSET                         (*((volatile uint32_t *)((uint8_t *)RAP_STATUS + offsetof(RAPSTATUS_TypeDef, LPC_TASK_EVNT_STS))))
#define RAP_LPC_ACTION_STOP_BIT                            (BIT(17))

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_RAP_DEF_H */
