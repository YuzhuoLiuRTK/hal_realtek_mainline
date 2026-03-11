/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __ADC_K_LIB_H
#define __ADC_K_LIB_H

#include <stdbool.h>
#include <stdint.h>

/** \defgroup ADC_LIB        ADC LIB
  * \brief
  * \{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** \defgroup ADC_LIB_ADC_Exported_Constants ADC Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup    ADC_Mode ADC Mode
 * \{
 * \ingroup     ADC_LIB_ADC_Exported_Constants
 */
#define USE_ADC_DIVIDE_SINGLE_MODE      1
#define USE_ADC_BYPASS_SINGLE_MODE      1
#define USE_ADC_DIVIDE_DIFF_MODE        1
#define USE_ADC_BYPASS_DIFF_MODE        1
/** End of ADC_Mode
  * \}
  */

/**
 * \defgroup   ADC_SampleMode ADC SampleMode
 * \{
 * \ingroup    ADC_LIB_ADC_Exported_Constants
 */
typedef enum
{
    DIVIDE_SINGLE_MODE = 1,
    BYPASS_SINGLE_MODE = 2,
    DIVIDE_DIFFERENTIAL_MODE = 3,
    BYPASS_DIFFERENTIAL_MODE = 4,
} ADC_SampleMode;
/** End of ADC_SampleMode
  * \}
  */

/**
 * \defgroup    ADC_ErrorStatus ADC ErrorStatus
 * \{
 * \ingroup     ADC_LIB_ADC_Exported_Constants
 */
typedef enum
{
    NO_ERROR = 0,
    PARAMETER_ERROR = -1,
    RAM_DATA_ERROR = -2,
    NO_CALIBRATION = -3,
    VERSION_ERROR = -4,
} ADC_ErrorStatus;
/** End of ADC_ErrorStatus
  * \}
  */

/** End of ADC_LIB_ADC_Exported_Constants
  * \}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup ADC_LIB_ADC_Exported_Functions ADC Exported Functions
  * \brief
  * \{
  */

/**
  * @brief  Initializes the ADC Calibration.
  * @param  Void.
  * @retval ADC Calibration result: (TRUE or FALSE).
  */
bool ADC_CalibrationInit(void);

/**
  * @brief  Get ADC voltage.
  * @param  vSampleMode: Specifies the ADC mode.
  * @param  vSampleData: Specifies the ADC rawdate.
  * @param  pErrorStatus: pointer to a ADC error.
  * @retval ADC volatge value.
  */
float ADC_GetVoltage(const ADC_SampleMode vSampleMode, int32_t vSampleData,
                     ADC_ErrorStatus *pErrorStatus);

/**
  * @brief  Get the ADC Resistance value.
  * @param  Void.
  * @retval ADC Resistance value.
  */
uint16_t ADC_GetResistance(void);
/** End of ADC_LIB_ADC_Exported_Functions
  * \}
  */

/** End of ADC_LIB
  * \}
  */

#endif /* ADC_LIB_H */
