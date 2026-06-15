/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_WDT_DEF_H
#define RTL_WDT_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"
#include "platform_reg.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          WDT Defines
 *============================================================================*/

#define WDT_SUPPORT_AUTO_CLOCK                         (1)
#define WDT_SUPPORT_GET_CURRENT_COUNTER                (1)

/*============================================================================*
 *                          WDT Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t WDT_CTL;                      /*!< 0x00 */
    __IO uint32_t WDT_KICK;                     /*!< 0x04 */
    __I  uint32_t WDT_CURRENT;                  /*!< 0x08 */
    __I  uint32_t WDT_VER;                      /*!< 0x0C */
    __IO uint32_t WDT_CLK_QACTIVE_CTL;          /*!< 0x10 */
} WDT_TypeDef;

/*============================================================================*
 *                          WDT Declaration
 *============================================================================*/
/** \defgroup WDT         WDT
  * \brief
  * \{
  */

/** \defgroup WDT_Exported_Constants WDT Exported Constants
  * \brief
  * \{
  */

/** \defgroup WDT_Declaration WDT Declaration
  * \brief
  * \{
  */

#define WDT_REG_BASE       (0x40006000 + PLATFORM_REG_WDT_CTL)
#define WDT                ((WDT_TypeDef *) WDT_REG_BASE)


/** End of WDT_Declaration
  * \}
  */

/** End of WDT_Exported_Constants
  * \}
  */

/** End of WDT
  * \}
  */

/*============================================================================*
 *                          WDT Private Types
 *============================================================================*/

/*============================================================================*
 *                          WDT Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   27:0    R/W    wdt_cnt_limit               28'h4E200
   29:28   R/W    wdt_mode                    2'h0
   30      R/W1C  wdt_to                      1'h0
   31      R/W    wdt_en                      1'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t wdt_cnt_limit: 28;
        uint32_t wdt_mode: 2;
        uint32_t wdt_to: 1;
        uint32_t wdt_en: 1;
    } b;
} WDT_CTL_TypeDef;


/* 0x04
   15:0    R/WAC  wdt_kick                    16'h0
   31:16   R      reserved                    16'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t wdt_kick: 16;
        const uint32_t reserved_0: 16;
    } b;
} WDT_KICK_TypeDef;


/* 0x08
   27:0    R      wdt_current                 28'h0
   31:28   R      reserved                    4'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t wdt_current: 28;
        const uint32_t reserved_0: 4;
    } b;
} WDT_CURRENT_TypeDef;


/* 0x0C
   31:0    R      wdt_ver                     32'h2409030A
*/
typedef union
{
    uint32_t d32;
    struct
    {
        const uint32_t wdt_ver: 32;
    } b;
} WDT_VER_TypeDef;


/* 0x10
   0       R/W    wdt_clk_qactive_man_data    1'h0
   1       R/W    wdt_clk_qactive_man_enable  1'h0
   31:2    R      reserved                    30'h0
*/
typedef union
{
    uint32_t d32;
    struct
    {
        uint32_t wdt_clk_qactive_man_data: 1;
        uint32_t wdt_clk_qactive_man_enable: 1;
        const uint32_t reserved_0: 30;
    } b;
} WDT_CLK_QACTIVE_CTL_TypeDef;



#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_WDT_DEF_H */
