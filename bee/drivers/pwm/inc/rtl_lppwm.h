/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_LPPWM_H
#define RTL_LPPWM_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "pwm/src/device/rtl87x2j/rtl_lppwm_def.h"
#endif

/** \defgroup LPPWM    LPPWM
  * \brief
  * \{
  */

/*============================================================================*
 *                        Constants
 *============================================================================*/
/** \defgroup LPPWM_Exported_Constants LPPWM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    LPPWM_Output_Polarity LPPWM Output Polarity
 * \{
 * \ingroup     LPPWM_Exported_Constants
 */
typedef enum
{
    LPPWM_POLARITY_NORMAL = 0x0,
    LPPWM_POLARITY_INVERT = 0x1,
} LPPWMPolarity_TypeDef;

#define IS_LPPWM_POLARITY(POLARITY)   (((POLARITY) == LPPWM_POLARITY_NORMAL ) || \
                                       ((POLARITY) == LPPWM_POLARITY_INVERT))

/** End of LPPWM_Output_Polarity
  * \}
  */

/** End of LPPWM_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup LPPWM_Exported_Types LPPWM Exported Types
  * \brief
  * \{
  */

/**
 * \brief       LPPWM init structure definition.
 *
 * \ingroup     LPPWM_Exported_Types
 */
typedef struct
{
    uint32_t LPPWM_Polarity;             /*!< Specifies the LPPWM Output pin polarity.
                                              This parameter can be a value of /ref LPPWM Polarity. */

    uint32_t LPPWM_PeriodHigh;            /*!< Specifies the LPPWM High Count. */

    uint32_t LPPWM_PeriodLow;             /*!< Specifies the LPPWM Low Count. */

} LPPWM_InitTypeDef;

/** End of LPPWM_Exported_Types
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup LPPWM_Exported_Functions LPPWM Exported Functions
  * \brief
  * \{
  */
void LPPWM_Init(LPPWM_TypeDef *LPPWMx, LPPWM_InitTypeDef *LPPWM_InitStruct);

void LPPWM_StructInit(LPPWM_InitTypeDef *LPPWM_InitStruct);

void LPPWM_Cmd(LPPWM_TypeDef *LPPWMx, FunctionalState NewState);

void LPPWM_Reset(LPPWM_TypeDef *LPPWMx);

void LPPWM_ChangeFreqAndDuty(LPPWM_TypeDef *LPPWMx, uint32_t period_high, uint32_t period_low);

uint32_t LPPWM_GetCurrentValue(LPPWM_TypeDef *LPPWMx);

/** End of LPPWM_Exported_Functions
  * \}
  */

/** End of LPPWM
  * \}
  */

#ifdef __cplusplus
}
#endif

#endif /* RTL_LPPWM_H */
