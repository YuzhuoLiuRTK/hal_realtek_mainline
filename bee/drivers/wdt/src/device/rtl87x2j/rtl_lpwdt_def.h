/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_LPWDT_DEF_H
#define RTL_LPWDT_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "aon_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          LPWDT Defines
 *============================================================================*/
#define LPWDT_SUPPORT_GET_CURRENT_COUNTER              (1)

/*============================================================================*
 *                          LPWDT Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t WDT_REG0X;            /*!< 0x00 */
    __IO uint32_t WDT_REG1X;            /*!< 0x04 */
    __IO uint32_t WDT_REG2X;            /*!< 0x08 */
    __IO uint32_t WDT_REG3X;            /*!< 0x0C */
    __IO uint32_t WDT_REG4X;            /*!< 0x10 */
    __IO uint32_t WDT_REG5X;            /*!< 0x14 */
    __IO uint32_t WDT_REG6X;            /*!< 0x18 */
    __IO uint32_t WDT_REG7X;            /*!< 0x1C */
    __IO uint32_t WDT_REG8X;            /*!< 0x20 */
    __IO uint32_t WDT_REG9X;            /*!< 0x24 */
    __IO uint32_t WDT_REG10X;           /*!< 0x28 */
    __IO uint32_t WDT_REG11X;           /*!< 0x2C */
    __IO uint32_t WDT_REG12X;           /*!< 0x30 */
    __IO uint32_t WDT_REG13X;           /*!< 0x34 */
    __IO uint32_t WDT_REG14X;           /*!< 0x38 */
    __IO uint32_t WDT_REG15X;           /*!< 0x3C */
    __IO uint32_t WDT_REG16X;           /*!< 0x40 */
    __IO uint32_t WDT_REG17X;           /*!< 0x44 */
    __IO uint32_t WDT_REG18X;           /*!< 0x48 */
    __IO uint32_t WDT_REG19X;           /*!< 0x4C */
    __IO uint32_t WDT_REG20X;           /*!< 0x50 */
    __IO uint32_t IO_WDT_REG0X;         /*!< 0x58 */
    __IO uint32_t IO_WDT_REG1X;         /*!< 0x5C */
} LPWDT_TypeDef;

/*============================================================================*
 *                          LPWDT Declaration
 *============================================================================*/
/** \defgroup LPWDT         LPWDT
  * \brief
  * \{
  */

/** \defgroup LPWDT_Exported_Constants LPWDT Exported Constants
  * \brief
  * \{
  */

/** \defgroup LPWDT_Declaration LPWDT Declaration
  * \brief
  * \{
  */

#define LPWDT_REG_BASE       (SYSON_BASE + AON_REG_WDT_REG0X)
#define LPWDT                ((LPWDT_TypeDef *) LPWDT_REG_BASE)


/** End of LPWDT_Declaration
  * \}
  */

/** End of LPWDT_Exported_Constants
  * \}
  */

/** End of LPWDT
  * \}
  */
/*============================================================================*
 *                          LPWDT Private Types
 *============================================================================*/

/*============================================================================*
 *                          LPWDT Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   27:0    R/W    lpwdt_cnt_limit                 28'h55F00
   28      R/W    lpwdt_mode                      1'b0
   29      R/W    lpwdt_cnt_ctl                   1'b0
   30      R/W    lpwdt_cnt_reload                1'b0
   31      R/W    lpwdt_enable                    1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpwdt_cnt_limit: 28;
        uint32_t lpwdt_mode: 1;
        uint32_t lpwdt_cnt_ctl: 1;
        uint32_t lpwdt_cnt_reload: 1;
        uint32_t lpwdt_enable: 1;
    } b;
} WDT_REG0X_TypeDef;


/* 0x04
   15:0    R/WAC  lpwdt_cnt_reset                 16'h0
   16      R/W    lpwdt_clk32k_qactive_man_data   1'b0
   17      R/W    lpwdt_clk32k_qactive_man_en     1'b0
   31:18   R/W    reserved                        14'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpwdt_cnt_reset: 16;
        uint32_t lpwdt_clk32k_qactive_man_data: 1;
        uint32_t lpwdt_clk32k_qactive_man_en: 1;
        uint32_t reserved_0: 14;
    } b;
} WDT_REG1X_TypeDef;


/* 0x08
   15:0    R      corewdt_cpu_pc_lsb              16'b0
   31:16   R      corewdt_cpu_pc_msb              16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_pc_lsb: 16;
        const uint32_t corewdt_cpu_pc_msb: 16;
    } b;
} WDT_REG2X_TypeDef;


/* 0x0C
   15:0    R      corewdt_cpu_xpsr_lsb            16'b0
   31:16   R      corewdt_cpu_xpsr_msb            16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_xpsr_lsb: 16;
        const uint32_t corewdt_cpu_xpsr_msb: 16;
    } b;
} WDT_REG3X_TypeDef;


/* 0x10
   15:0    R      corewdt_cpu_lr_lsb              16'b0
   31:16   R      corewdt_cpu_lr_msb              16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_lr_lsb: 16;
        const uint32_t corewdt_cpu_lr_msb: 16;
    } b;
} WDT_REG4X_TypeDef;


/* 0x14
   15:0    R      corewdt_cpu_r00_q_lsb           16'b0
   31:16   R      corewdt_cpu_r00_q_msb           16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_r00_q_lsb: 16;
        const uint32_t corewdt_cpu_r00_q_msb: 16;
    } b;
} WDT_REG5X_TypeDef;


/* 0x18
   15:0    R      corewdt_cpu_r01_q_lsb           16'b0
   31:16   R      corewdt_cpu_r01_q_msb           16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_r01_q_lsb: 16;
        const uint32_t corewdt_cpu_r01_q_msb: 16;
    } b;
} WDT_REG6X_TypeDef;


/* 0x1C
   15:0    R      corewdt_cpu_r02_q_lsb           16'b0
   31:16   R      corewdt_cpu_r02_q_msb           16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_r02_q_lsb: 16;
        const uint32_t corewdt_cpu_r02_q_msb: 16;
    } b;
} WDT_REG7X_TypeDef;


/* 0x20
   15:0    R      corewdt_cpu_r03_q_lsb           16'b0
   31:16   R      corewdt_cpu_r03_q_msb           16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_cpu_r03_q_lsb: 16;
        const uint32_t corewdt_cpu_r03_q_msb: 16;
    } b;
} WDT_REG8X_TypeDef;


/* 0x24
   0       R      corewdt_flag                    1'b0
   2:1     R      corewdt_mode                    2'b0
   31:3    R      reserved                        29'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t corewdt_flag: 1;
        const uint32_t corewdt_mode: 2;
        const uint32_t reserved_0: 29;
    } b;
} WDT_REG9X_TypeDef;


/* 0x28
   0       R/WAC  corewdt_flag_clr                1'b0
   1       R/WAC  corewdt_mode_clr                1'b0
   15:2    R      reserved                        14'b0
   16      R/WAC  corewdt_cpu_reg_clr             1'b0
   31:17   R      reserved                        15'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t corewdt_flag_clr: 1;
        uint32_t corewdt_mode_clr: 1;
        const uint32_t reserved_1: 14;
        uint32_t corewdt_cpu_reg_clr: 1;
        const uint32_t reserved_0: 15;
    } b;
} WDT_REG10X_TypeDef;


/* 0x2C
   31:0    R      reserved                        32'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t reserved_0: 32;
    } b;
} WDT_REG11X_TypeDef;


/* 0x30
   15:0    R      lpwdt_cpu_pc_lsb                16'b0
   31:16   R      lpwdt_cpu_pc_msb                16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_pc_lsb: 16;
        const uint32_t lpwdt_cpu_pc_msb: 16;
    } b;
} WDT_REG12X_TypeDef;


/* 0x34
   15:0    R      lpwdt_cpu_xpsr_lsb              16'b0
   31:16   R      lpwdt_cpu_xpsr_msb              16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_xpsr_lsb: 16;
        const uint32_t lpwdt_cpu_xpsr_msb: 16;
    } b;
} WDT_REG13X_TypeDef;


/* 0x38
   15:0    R      lpwdt_cpu_lr_lsb                16'b0
   31:16   R      lpwdt_cpu_lr_msb                16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_lr_lsb: 16;
        const uint32_t lpwdt_cpu_lr_msb: 16;
    } b;
} WDT_REG14X_TypeDef;


/* 0x3C
   15:0    R      lpwdt_cpu_r00_q_lsb             16'b0
   31:16   R      lpwdt_cpu_r00_q_msb             16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_r00_q_lsb: 16;
        const uint32_t lpwdt_cpu_r00_q_msb: 16;
    } b;
} WDT_REG15X_TypeDef;


/* 0x40
   15:0    R      lpwdt_cpu_r01_q_lsb             16'b0
   31:16   R      lpwdt_cpu_r01_q_msb             16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_r01_q_lsb: 16;
        const uint32_t lpwdt_cpu_r01_q_msb: 16;
    } b;
} WDT_REG16X_TypeDef;


/* 0x44
   15:0    R      lpwdt_cpu_r02_q_lsb             16'b0
   31:16   R      lpwdt_cpu_r02_q_msb             16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_r02_q_lsb: 16;
        const uint32_t lpwdt_cpu_r02_q_msb: 16;
    } b;
} WDT_REG17X_TypeDef;


/* 0x48
   15:0    R      lpwdt_cpu_r03_q_lsb             16'b0
   31:16   R      lpwdt_cpu_r03_q_msb             16'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_cpu_r03_q_lsb: 16;
        const uint32_t lpwdt_cpu_r03_q_msb: 16;
    } b;
} WDT_REG18X_TypeDef;


/* 0x4C
   0       R      lpwdt_flag                      1'b0
   2:1     R      lpwdt_mode_record               2'b0
   30:3    R      lpwdt_current                   28'b0
   31      R      reserved                        1'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t lpwdt_flag: 1;
        const uint32_t lpwdt_mode_record: 2;
        const uint32_t lpwdt_current: 28;
        const uint32_t reserved_0: 1;
    } b;
} WDT_REG19X_TypeDef;


/* 0x50
   0       R/WAC  lpwdt_flag_clr                  1'b0
   1       R/WAC  lpwdt_mode_clr                  1'b0
   15:2    R      reserved                        14'b0
   16      R/WAC  lpwdt_cpu_reg_clr               1'b0
   31:17   R      reserved                        15'b0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t lpwdt_flag_clr: 1;
        uint32_t lpwdt_mode_clr: 1;
        const uint32_t reserved_1: 14;
        uint32_t lpwdt_cpu_reg_clr: 1;
        const uint32_t reserved_0: 15;
    } b;
} WDT_REG20X_TypeDef;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_LPWDT_DEF_H */
