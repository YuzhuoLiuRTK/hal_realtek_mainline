/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPC_DEF_H
#define RTL_LPC_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          LPC Defines
 *============================================================================*/
#define LPC_SUPPORT_POWER_OFF                          (0)
#define LPC_SUPPORT_POWER_ON                           (0)
#define LPC_SUPPORT_NOMAL_FLOW                         (0)
#define LPC_SUPPORT_TRIGGER_MODE                       (0)
#define LPC_SUPPORT_COMP_CNT                           (1)
#define LPC_SUPPORT_INT_LPCOMP_AON                     (0)
#define LPC_SUPPORT_DEBOUNCE_MODE                      (0)
#define LPC_SUPPORT_VBAT_CHANNEL                       (1)
#define LPC_SUPPORT_RAP_MODE                           (1)
#define LPC_SUPPORT_AUTO_CLOCK                         (1)
#define LPC_SUPPORT_BYPASS_DIVIDE_MODE                 (1)
#define LPC_SUPPORT_VOLTAGE_DETECT_L                   (0)
#define LPC_SUPPORT_HYSTERESIS_FUNCTION                (1)

/*============================================================================*
 *                          LPC Registers Memory Map
 *============================================================================*/
/* LPC Registers Memory Map */
typedef struct
{
    __I  uint32_t LPC_VERSION;              /*!< 0x00 */
    __IO uint32_t LPC_CR0;                  /*!< 0x04 */
    __I  uint32_t LPC_SR;                   /*!< 0x08 */
    __IO uint32_t LPC_CMP;                  /*!< 0x0C */
    __I  uint32_t LPC_CNT;                  /*!< 0x10 */
    __IO uint32_t LPC_TASK_CTRL;            /*!< 0x14 */
    __IO uint32_t LPC_SHOT_CTRL;            /*!< 0x18 */
    __IO uint32_t LPC_QACTIVE_CTRL;         /*!< 0x1C */
    __IO uint32_t LPC_REG0X_SD;             /*!< 0x20 */
} LPC_TypeDef;

/*============================================================================*
 *                          LPC Declaration
 *============================================================================*/
/**
 * @defgroup LPC_DECLARATION LPC Declaration
 * @{
 * @ingroup  LPC_Exported_Constants
 */

#define LPC0                ((LPC_TypeDef *)(SYSON_BASE + AON_REG_LPC_VERSION))
#define LPC_REF             (*(volatile uint32_t *)(SYSON_BASE + AON_REG_MBIAS_REG0X))

/** @} */ /* End of group LPC_DECLARATION */

/**
 * @defgroup LPC_DIVIDE_THRESHOLD LPC Divide Threshold
 * @{
 * @ingroup  LPC_Exported_Constants
 */

#define LPC_INPUT_RANGE \
    LPC_60_mV         = 0,  \
                        LPC_120_mV        = 1,  \
                                            LPC_180_mV        = 2,  \
                                                                LPC_240_mV        = 3,  \
                                                                                    LPC_300_mV        = 4,  \
                                                                                            LPC_360_mV        = 5,  \
                                                                                                    LPC_420_mV        = 6,  \
                                                                                                            LPC_480_mV        = 7,  \
                                                                                                                    LPC_540_mV        = 8,  \
                                                                                                                            LPC_600_mV        = 9,  \
                                                                                                                                    LPC_660_mV        = 10, \
                                                                                                                                            LPC_720_mV        = 11, \
                                                                                                                                                    LPC_780_mV        = 12, \
                                                                                                                                                            LPC_840_mV        = 13, \
                                                                                                                                                                    LPC_900_mV        = 14, \
                                                                                                                                                                            LPC_960_mV        = 15, \
                                                                                                                                                                                    LPC_1020_mV       = 16, \
                                                                                                                                                                                            LPC_1080_mV       = 17, \
                                                                                                                                                                                                    LPC_1140_mV       = 18, \
                                                                                                                                                                                                            LPC_1200_mV       = 19, \
                                                                                                                                                                                                                    LPC_1260_mV       = 20, \
                                                                                                                                                                                                                            LPC_1320_mV       = 21, \
                                                                                                                                                                                                                                    LPC_1380_mV       = 22, \
                                                                                                                                                                                                                                            LPC_1440_mV       = 23, \
                                                                                                                                                                                                                                                    LPC_1500_mV       = 24, \
                                                                                                                                                                                                                                                            LPC_1560_mV       = 25, \
                                                                                                                                                                                                                                                                    LPC_1620_mV       = 26, \
                                                                                                                                                                                                                                                                            LPC_1680_mV       = 27, \
                                                                                                                                                                                                                                                                                    LPC_1740_mV       = 28, \
                                                                                                                                                                                                                                                                                            LPC_1800_mV       = 29, \
                                                                                                                                                                                                                                                                                                    LPC_1860_mV       = 30, \
                                                                                                                                                                                                                                                                                                            LPC_1920_mV       = 31, \
                                                                                                                                                                                                                                                                                                                    LPC_1980_mV       = 32, \
                                                                                                                                                                                                                                                                                                                            LPC_2040_mV       = 33, \
                                                                                                                                                                                                                                                                                                                                    LPC_2100_mV       = 34, \
                                                                                                                                                                                                                                                                                                                                            LPC_2160_mV       = 35, \
                                                                                                                                                                                                                                                                                                                                                    LPC_2220_mV       = 36, \
                                                                                                                                                                                                                                                                                                                                                            LPC_2280_mV       = 37, \
                                                                                                                                                                                                                                                                                                                                                                    LPC_2340_mV       = 38, \
                                                                                                                                                                                                                                                                                                                                                                            LPC_2400_mV       = 39, \
                                                                                                                                                                                                                                                                                                                                                                                    LPC_2460_mV       = 40, \
                                                                                                                                                                                                                                                                                                                                                                                            LPC_2520_mV       = 41, \
                                                                                                                                                                                                                                                                                                                                                                                                    LPC_1580_mV       = 42, \
                                                                                                                                                                                                                                                                                                                                                                                                            LPC_2640_mV       = 43, \
                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_2700_mV       = 44, \
                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_2760_mV       = 45, \
                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_2820_mV       = 46, \
                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_2880_mV       = 47, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_2940_mV       = 48, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3000_mV       = 49, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_3060_mV       = 50, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3120_mV       = 51, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_3180_mV       = 52, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3240_mV       = 53, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_3300_mV       = 54, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3360_mV       = 55, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_3420_mV       = 56, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3480_mV       = 57, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_3540_mV       = 58, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            LPC_3600_mV       = 59, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    LPC_THRDSHOD_MAX  = 59,

/** @} */ /* End of group LPC_DIVIDE_THRESHOLD */

/**
 * @defgroup LPC_BYPASS_THRESHOLD LPC Bypass Threshold
 * @{
 * @ingroup  LPC_Exported_Constants
 */

#define LPC_BYPASS_INPUT_RANGE \
    LPC_BYPASS_15_mV         = 0,  \
                               LPC_BYPASS_30_mV         = 1,  \
                                                          LPC_BYPASS_45_mV         = 2,  \
                                                                  LPC_BYPASS_60_mV         = 3,  \
                                                                          LPC_BYPASS_75_mV         = 4,  \
                                                                                  LPC_BYPASS_90_mV         = 5,  \
                                                                                          LPC_BYPASS_105_mV        = 6,  \
                                                                                                  LPC_BYPASS_120_mV        = 7,  \
                                                                                                          LPC_BYPASS_135_mV        = 8,  \
                                                                                                                  LPC_BYPASS_150_mV        = 9,  \
                                                                                                                          LPC_BYPASS_165_mV        = 10, \
                                                                                                                                  LPC_BYPASS_180_mV        = 11, \
                                                                                                                                          LPC_BYPASS_195_mV        = 12, \
                                                                                                                                                  LPC_BYPASS_210_mV        = 13, \
                                                                                                                                                          LPC_BYPASS_225_mV        = 14, \
                                                                                                                                                                  LPC_BYPASS_240_mV        = 15, \
                                                                                                                                                                          LPC_BYPASS_255_mV        = 16, \
                                                                                                                                                                                  LPC_BYPASS_270_mV        = 17, \
                                                                                                                                                                                          LPC_BYPASS_285_mV        = 18, \
                                                                                                                                                                                                  LPC_BYPASS_300_mV        = 19, \
                                                                                                                                                                                                          LPC_BYPASS_315_mV        = 20, \
                                                                                                                                                                                                                  LPC_BYPASS_330_mV        = 21, \
                                                                                                                                                                                                                          LPC_BYPASS_345_mV        = 22, \
                                                                                                                                                                                                                                  LPC_BYPASS_360_mV        = 23, \
                                                                                                                                                                                                                                          LPC_BYPASS_375_mV        = 24, \
                                                                                                                                                                                                                                                  LPC_BYPASS_390_mV        = 25, \
                                                                                                                                                                                                                                                          LPC_BYPASS_405_mV        = 26, \
                                                                                                                                                                                                                                                                  LPC_BYPASS_420_mV        = 27, \
                                                                                                                                                                                                                                                                          LPC_BYPASS_435_mV        = 28, \
                                                                                                                                                                                                                                                                                  LPC_BYPASS_450_mV        = 29, \
                                                                                                                                                                                                                                                                                          LPC_BYPASS_465_mV        = 30, \
                                                                                                                                                                                                                                                                                                  LPC_BYPASS_480_mV        = 31, \
                                                                                                                                                                                                                                                                                                          LPC_BYPASS_495_mV        = 32, \
                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_510_mV        = 33, \
                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_525_mV        = 34, \
                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_540_mV        = 35, \
                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_555_mV        = 36, \
                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_570_mV        = 37, \
                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_585_mV        = 38, \
                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_600_mV        = 39, \
                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_615_mV        = 40, \
                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_630_mV        = 41, \
                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_645_mV        = 42, \
                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_660_mV        = 43, \
                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_675_mV        = 44, \
                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_690_mV        = 45, \
                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_705_mV        = 46, \
                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_720_mV        = 47, \
                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_735_mV        = 48, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_750_mV        = 49, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_765_mV        = 50, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_780_mV        = 51, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_795_mV        = 52, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_810_mV        = 53, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_825_mV        = 54, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_840_mV        = 55, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_855_mV        = 56, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_870_mV        = 57, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_885_mV        = 58, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  LPC_BYPASS_900_mV        = 59, \
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          LPC_BYPASS_THRESHOLD_MAX = 59,

/** @} */ /* End of group LPC_BYPASS_THRESHOLD */

/**
  * @brief  LPC INTERRUPT TPYE
  *         This parameter can be LPC_INT_LPCOMP and LPC_INT_LPCOMP_AON.
  */
#define LPC_INT_LPCOMP            (BIT9)
#define LPC_INT_LPCOMP_AON        (BIT19)

/*============================================================================*
 *                          LPC Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R      lpcomp_version              32'h20240329
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpcomp_version: 32;
    } b;
} LPC_VERSION_TypeDef;


/* 0x04
   0       R/W    reg_lpcomp_counter_rst      1'h0
   1       R/W    reg_lpcomp_counter_start    1'h0
   2       R/WAC  reg_lpcomp_flag_clr         1'h0
   7:3     R      reserver080_7_3             5'h0
   8       R/W    reg_lpcomp_ie               1'h0
   9       R/W    reg_lpcomp_src_int_en       1'h0
   18:10   R/W    reserver080_18_10           9'h0
   19      R/W    reg_lpcomp_src_aon_int_en   1'h0
   20      R/W    reg_lpcomp_output_en        1'h0
   30:21   R      reserver080_30_21           10'h0
   31      R/W    lpc_rst                     1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reg_lpcomp_counter_rst: 1;
        uint32_t reg_lpcomp_counter_start: 1;
        uint32_t reg_lpcomp_flag_clr: 1;
        const uint32_t reserver080_7_3: 5;
        uint32_t reg_lpcomp_ie: 1;
        uint32_t reg_lpcomp_src_int_en: 1;
        uint32_t reserver080_18_10: 9;
        uint32_t reg_lpcomp_src_aon_int_en: 1;
        uint32_t reg_lpcomp_output_en: 1;
        const uint32_t reserver080_30_21: 10;
        uint32_t lpc_rst: 1;
    } b;
} LPC_CR0_TypeDef;


/* 0x08
   0       R      reg_lpcomp_flag             1'h0
   1       R      reg_lpcomp_out_aon          1'h0
   31:2    R      reserver084_31_22           30'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reg_lpcomp_flag: 1;
        const uint32_t reg_lpcomp_out_aon: 1;
        const uint32_t reserver084_31_22: 30;
    } b;
} LPC_SR_TypeDef;


/* 0x0C
   11:0    R/W    reg_lpcomp_comp             12'h0
   31:12   R      reserver088_31_12           20'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t reg_lpcomp_comp: 12;
        const uint32_t reserver088_31_12: 20;
    } b;
} LPC_CMP_TypeDef;


/* 0x10
   11:0    R      reg_lpcomp_counter          12'h0
   31:12   R      reserver08c_31_12           20'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reg_lpcomp_counter: 12;
        const uint32_t reserver08c_31_12: 20;
    } b;
} LPC_CNT_TypeDef;


/* 0x14
   0       R/W    lpc_rap_mode                1'h0
   1       R/WAC  lpc_fw_task_start           1'h0
   2       R/WAC  lpc_fw_task_stop            1'h0
   31:3    R      reserver090_31_3            29'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpc_rap_mode: 1;
        uint32_t lpc_fw_task_start: 1;
        uint32_t lpc_fw_task_stop: 1;
        const uint32_t reserver090_31_3: 29;
    } b;
} LPC_TASK_CTRL_TypeDef;


/* 0x18
   0       R/W    lpc_task_stop_sub_en        1'h0
   15:1    R      reserver094_15_1            15'h0
   16      R/W    lpc_event_status_pub_en     1'h0
   31:17   R      reserver094_31_17           15'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpc_task_stop_sub_en: 1;
        const uint32_t reserver094_15_1: 15;
        uint32_t lpc_event_status_pub_en: 1;
        const uint32_t reserver094_31_17: 15;
    } b;
} LPC_SHOT_CTRL_TypeDef;


/* 0x1C
   0       R/W    lpc_qact_sclk_man_data      1'h0
   1       R/W    lpc_qact_sclk_man_en        1'h0
   2       R/W    lpc_qact_pclk_man_data      1'h0
   3       R/W    lpc_qact_pclk_man_en        1'h0
   31:4    R      reserver098_31_4            28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpc_qact_sclk_man_data: 1;
        uint32_t lpc_qact_sclk_man_en: 1;
        uint32_t lpc_qact_pclk_man_data: 1;
        uint32_t lpc_qact_pclk_man_en: 1;
        const uint32_t reserver098_31_4: 28;
    } b;
} LPC_QACTIVE_CTRL_TypeDef;


/* 0x20
   0       R/W    pow_sd_h                    1'h0
   4:1     R/W    ch_num_h                    4'h0
   5       R/W    sd_posedge_h                1'h1
   6       R/W    en_hys                      1'h0
   7       R/W    en_byp                      1'h0
   8       R      en_ad_lpc_comp_out_dbg      1'b0
   31:9    R      reserver094_31_9            23'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t pow_sd_h: 1;
        uint32_t ch_num_h: 4;
        uint32_t sd_posedge_h: 1;
        uint32_t en_hys: 1;
        uint32_t en_byp: 1;
        const uint32_t en_ad_lpc_comp_out_dbg: 1;
        const uint32_t reserver094_31_9: 23;
    } b;
} LPC_REG0X_SD_TypeDef;

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_LPC_DEF_H */
