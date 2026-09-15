/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_SPI3W_DEF_H
#define RTL_SPI3W_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          SPI3W Defines
 *============================================================================*/
#define SPI3W_SUPPORT_RAP_FUNCTION                    (1)
#define SPI3W_SUPPORT_AUTO_CLOCK                      (1)
#define SPI3W_SUPPORT_DATA_PAD_PULL_CONFIG            (1)

/*============================================================================*
 *                          SPI3W Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t SPI3W_RSVD0[12];                      /*!< 0x00 -- 0x2C*/
    __IO uint32_t SPI3W_CONFIG;                         /*!< 0x30 */
    __IO uint32_t SPI3W_WDATA;                          /*!< 0x34 */
    __IO uint32_t SPI3W_CLR;                            /*!< 0x38 */
    __I  uint32_t SPI3W_STS;                            /*!< 0x3C */
    __IO uint32_t SPI3W_RDATA0;                         /*!< 0x40 */
    __IO uint32_t SPI3W_RDATA4;                         /*!< 0x44 */
    __IO uint32_t SPI3W_RDATA8;                         /*!< 0x48 */
    __IO uint32_t SPI3W_RDATA12;                        /*!< 0x4C */
    __IO uint32_t SPI3W_VERSION;                        /*!< 0x50 */
    __IO uint32_t SPI3W_RSVD1[3];                       /*!< 0x54 - 0x5C*/
    __IO uint32_t SPI3W_QACTIVE_MANUAL_CTRL;            /*!< 0x60 */
    __IO uint32_t SPI3W_RSVD2[7];                       /*!< 0x64 - 0x7C*/
    __IO uint32_t SPI3W_QB_START;                       /*!< 0x80 */
    __IO uint32_t SPI3W_RSVD3[3];                       /*!< 0x84 - 0x8C*/
    __IO uint32_t SPI3W_QB_PW;                          /*!< 0x90 */
    __IO uint32_t SPI3W_RSVD4[27];                      /*!< 0x94 - 0xFC*/
    __IO uint32_t SPI3W_RAP_MODE;                       /*!< 0x100 */
    __IO uint32_t SPI3W_RSVD5[3];                       /*!< 0x104 - 0x10C*/
    __IO uint32_t SPI3W_TASKS_START;                    /*!< 0x110 */
} SPI3W_TypeDef;

/*============================================================================*
 *                          SPI3W Declaration
 *============================================================================*/
/**
 * @defgroup SPI3W_DECLARATION SPI3W Declaration
 * @{
 * @ingroup  SPI3W_Exported_Constants
 */

#define SPI3W                   ((SPI3W_TypeDef *) SPI3W_BASE)   /**< SPI3W peripheral instance. */

/** @} */ /* End of group SPI3W_DECLARATION */

/*============================================================================*
 *                          SPI3W Private Types
 *============================================================================*/

/*============================================================================*
 *                          SPI3W Registers and Field Descriptions
 *============================================================================*/
/* 0x30
   0       R/W    spi3w_int_en                    1'h0
   1       R/W    spi3w_int_mask                  1'h0
   2       R      reserved14                      1'h0
   7:3     R/W    spi3w_dly_cycle                 5'h7
   15:8    R/W    spi3w_div_num                   8'h13
   19:16   R/W    spi3w_burst_read_num            4'h7
   20      R/W    spi3w_burst_read_en             1'h0
   24:21   R/W    spi3w_resync_timer              4'h0
   27:25   R      reserved8                       3'h0
   28      R/W    spi3w_oe_dly_en                 1'h0
   29      R/W    spi3w_end_ext_en                1'h0
   30      R/W    spi3w_cs_en                     1'h1
   31      R/W    spi3w_en                        1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_int_en: 1;
        uint32_t spi3w_int_mask: 1;
        const uint32_t reserved_1: 1;
        uint32_t spi3w_dly_cycle: 5;
        uint32_t spi3w_div_num: 8;
        uint32_t spi3w_burst_read_num: 4;
        uint32_t spi3w_burst_read_en: 1;
        uint32_t spi3w_resync_timer: 4;
        const uint32_t reserved_0: 3;
        uint32_t spi3w_oe_dly_en: 1;
        uint32_t spi3w_end_ext_en: 1;
        uint32_t spi3w_cs_en: 1;
        uint32_t spi3w_en: 1;
    } b;
} SPI3W_CONFIG_TypeDef;


/* 0x34
   7:0     R/W    spi3w_data_data                 8'h0
   14:8    R/W    spi3w_data_addr                 7'h0
   15      R/W    spi3w_data_mode                 1'h0
   31:16   R      reserved18                      16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_data_data: 8;
        uint32_t spi3w_data_addr: 7;
        uint32_t spi3w_data_mode: 1;
        const uint32_t reserved_0: 16;
    } b;
} SPI3W_WDATA_TypeDef;


/* 0x38
   0       W1C    spi3w_int_clr                   1'h0
   1       W1C    spi3w_rd_num_clr                1'h0
   2       W1C    spi3w_rd_data_clr               1'h0
   29:3    R      reserved25                      27'h0
   30      R/W    spi3w_resync_en                 1'h0
   31      R      reserved23                      1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_int_clr: 1;
        uint32_t spi3w_rd_num_clr: 1;
        uint32_t spi3w_rd_data_clr: 1;
        const uint32_t reserved_1: 27;
        uint32_t spi3w_resync_en: 1;
        const uint32_t reserved_0: 1;
    } b;
} SPI3W_CLR_TypeDef;


/* 0x3C
   3:0     R      spi3w_rdata_num                 4'h0
   4       R      spi3w_busy                      1'h0
   5       R      spi3w_int_status                1'h0
   6       R      spi3w_resync_busy               1'h0
   31:7    R      reserved30                      25'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rdata_num: 4;
        const uint32_t spi3w_busy: 1;
        const uint32_t spi3w_int_status: 1;
        const uint32_t spi3w_resync_busy: 1;
        const uint32_t reserved_0: 25;
    } b;
} SPI3W_STS_TypeDef;


/* 0x40
   7:0     R      spi3w_rdata_0                   8'h0
   15:8    R      spi3w_rdata_1                   8'h0
   23:16   R      spi3w_rdata_2                   8'h0
   31:24   R      spi3w_rdata_3                   8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rdata_0: 8;
        const uint32_t spi3w_rdata_1: 8;
        const uint32_t spi3w_rdata_2: 8;
        const uint32_t spi3w_rdata_3: 8;
    } b;
} SPI3W_RDATA0_TypeDef;


/* 0x44
   7:0     R      spi3w_rdata_4                   8'h0
   15:8    R      spi3w_rdata_5                   8'h0
   23:16   R      spi3w_rdata_6                   8'h0
   31:24   R      spi3w_rdata_7                   8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rdata_4: 8;
        const uint32_t spi3w_rdata_5: 8;
        const uint32_t spi3w_rdata_6: 8;
        const uint32_t spi3w_rdata_7: 8;
    } b;
} SPI3W_RDATA4_TypeDef;


/* 0x48
   7:0     R      spi3w_rdata_8                   8'h0
   15:8    R      spi3w_rdata_9                   8'h0
   23:16   R      spi3w_rdata_10                  8'h0
   31:24   R      spi3w_rdata_11                  8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rdata_8: 8;
        const uint32_t spi3w_rdata_9: 8;
        const uint32_t spi3w_rdata_10: 8;
        const uint32_t spi3w_rdata_11: 8;
    } b;
} SPI3W_RDATA8_TypeDef;


/* 0x4C
   7:0     R      spi3w_rdata_12                  8'h0
   15:8    R      spi3w_rdata_13                  8'h0
   23:16   R      spi3w_rdata_14                  8'h0
   31:24   R      reserved51                      8'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rdata_12: 8;
        const uint32_t spi3w_rdata_13: 8;
        const uint32_t spi3w_rdata_14: 8;
        const uint32_t reserved_0: 8;
    } b;
} SPI3W_RDATA12_TypeDef;


/* 0x50
   31:0    R      spi3w_rtl_ver                   32'h2412110A
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t spi3w_rtl_ver: 32;
    } b;
} SPI3W_VERSION_TypeDef;


/* 0x60
   0       R/W    spi3w_clk_qactive_man_data      1'h0
   1       R/W    spi3w_clk_qactive_man_enable    1'h0
   2       R/W    spi3w_pclk_qactive_man_data     1'h0
   3       R/W    spi3w_pclk_qactive_man_enable   1'h0
   31:4    R      reserved58                      28'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_clk_qactive_man_data: 1;
        uint32_t spi3w_clk_qactive_man_enable: 1;
        uint32_t spi3w_pclk_qactive_man_data: 1;
        uint32_t spi3w_pclk_qactive_man_enable: 1;
        const uint32_t reserved_0: 28;
    } b;
} SPI3W_QACTIVE_MANUAL_CTRL_TypeDef;


/* 0x80
   0       R/WAC  spi3w_qb_start                  1'h0
   31:1    R      reserved64                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_qb_start: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI3W_QB_START_TypeDef;


/* 0x90
   4:0     R/W    spi3w_qb_pw                     5'h1
   31:5    R      reserved67                      27'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_qb_pw: 5;
        const uint32_t reserved_0: 27;
    } b;
} SPI3W_QB_PW_TypeDef;


/* 0x100
   0       R/W    spi3w_rap_mode                  1'h0
   31:1    R      reserved70                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_rap_mode: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI3W_RAP_MODE_TypeDef;


/* 0x110
   0       R/WAC  spi3w_tasks_start               1'h0
   31:1    R      reserved73                      31'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t spi3w_tasks_start: 1;
        const uint32_t reserved_0: 31;
    } b;
} SPI3W_TASKS_START_TypeDef;


/*============================================================================*
 *                         SPI3W Constant
 *============================================================================*/
/**
 * @defgroup SPI3W_DATA_OUT_PULL_STATUS SPI3W Data Out Pull Status
 * @{
 * @ingroup  SPI3W_Exported_Constants
 */
typedef enum
{
    SPI3W_DATA_OUT_PULL_PAD_CONFIG = 0x0, /**< Controlled by the pad's registers. */
    SPI3W_DATA_OUT_PULL_NONE       = 0x1  /**< Pull none. */
} SPI3W_DataOutPull_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_DATA_OUT_PULL(PULL) (((PULL) == SPI3W_DATA_OUT_PULL_PAD_CONFIG) || \
                                      ((PULL) == SPI3W_DATA_OUT_PULL_NONE))

/** @} */ /* End of group SPI3W_DATA_OUT_PULL_STATUS */


/**
 * @defgroup SPI3W_DATA_IN_PULL_STATUS SPI3W Data In Pull Status
 * @{
 * @ingroup  SPI3W_Exported_Constants
 */
typedef enum
{
    SPI3W_DATA_IN_PULL_PAD_CONFIG  = 0x0, /**< Controlled by the pad's registers. */
    SPI3W_DATA_IN_PULL_NONE        = 0x1, /**< Pull none. */
    SPI3W_DATA_IN_PULL_DOWN        = 0x2, /**< Pull down. */
    SPI3W_DATA_IN_PULL_UP          = 0x3  /**< Pull up. */
} SPI3W_DataInPull_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_DATA_IN_PULL(PULL) (((PULL) == SPI3W_DATA_IN_PULL_PAD_CONFIG) || \
                                     ((PULL) == SPI3W_DATA_IN_PULL_NONE) || \
                                     ((PULL) == SPI3W_DATA_IN_PULL_DOWN) || \
                                     ((PULL) == SPI3W_DATA_IN_PULL_UP))

/** @} */ /* End of group SPI3W_DATA_IN_PULL_STATUS */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_SPI3W_DEF_H */
