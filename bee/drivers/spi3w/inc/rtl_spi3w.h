/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_SPI3W_H
#define RTL_SPI3W_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "spi3w/src/device/rtl87x2j/rtl_spi3w_def.h"
#endif

/**
 * @defgroup SPI3W SPI3W
 * @ingroup PERIPH_DRIVER
 * @brief Serial Peripheral Interface 3-Wire (SPI3W) driver.
 * @{
 */

/**
 * @defgroup SPI3W_Exported_Constants SPI3W Exported Constants
 * @{
 */

/**
 * @defgroup SPI3W_MODE SPI3W Mode
 * @{
 */

/**
 * @brief SPI3W operation mode.
 */
typedef enum
{
    SPI3W_2WIRE_MODE,   /**< 2-wire mode. */
    SPI3W_3WIRE_MODE,   /**< 3-wire mode. */
} SPI3WMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_MODE(MODE) ((MODE) == SPI3W_2WIRE_MODE || (MODE) == SPI3W_3WIRE_MODE)
/** @} */ /* End of group SPI3W_MODE */

/**
 * @defgroup SPI3W_OE_DELAY_CONFIG SPI3W OE Delay Config
 * @{
 */

/**
 * @brief SPI3W output enable delay configuration.
 *        This field extends SPI3W_SDIO's turnaround time (output to input) for (SPI3W_DLY_CYCLE + 1) T.
 *        The T time is 1/(2*SPI3W_CLK_OUT).
 */
typedef enum
{
    SPI3W_OE_DELAY_NONE,   /**< Disable the turnaround time extension. */
    SPI3W_OE_DELAY_1T,     /**< Enable the turnaround time extension. */
} SPI3WDelay_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_OE_DELAY_CFG(CFG) ((CFG) == SPI3W_OE_DELAY_1T || (CFG) == SPI3W_OE_DELAY_NONE)
/** @} */ /* End of group SPI3W_OE_DELAY_CONFIG */

/**
 * @defgroup SPI3W_END_EXTEND_MODE SPI3W End Extend Mode
 * @{
 */

/**
 * @brief SPI3W end extend mode.
 *        This field extends SPI3W_CS for 1/(2*SPI3W_CLK_OUT) after a R/W operation.
 */
typedef enum
{
    SPI3W_NORMAL_MODE,    /**< Normal mode. */
    SPI3W_EXTEND_MODE,    /**< Extend mode. */
} SPI3WExtMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_END_EXTEND_MODE(MODE) ((MODE) == SPI3W_EXTEND_MODE || (MODE) == SPI3W_NORMAL_MODE)
/** @} */ /* End of group SPI3W_END_EXTEND_MODE */

/**
 * @defgroup SPI3W_READ_CYCLE_DELAY SPI3W Read Cycle Delay
 * @{
 */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_READ_CYCLE_DELAY(DELAY) (DELAY <= 0x1f)
/** @} */ /* End of group SPI3W_READ_CYCLE_DELAY */

/**
 * @defgroup SPI3W_FLAG SPI3W Flag
 * @{
 */
#define SPI3W_FLAG_BUSY                       BIT4     /**< SPI3W busy status. */
#define SPI3W_FLAG_INT_IND                    BIT5     /**< SPI3W interrupt status. */
#define SPI3W_FLAG_RESYNC_BUSY                BIT6     /**< SPI3W resync busy status. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_FLAG(FLAG) (((FLAG) == SPI3W_FLAG_BUSY) || \
                             ((FLAG) == SPI3W_FLAG_INT_IND) || \
                             ((FLAG) == SPI3W_FLAG_RESYNC_BUSY))
/** @} */ /* End of group SPI3W_FLAG */

/**
 * @defgroup SPI3W_INTERRUPT_DEFINITION SPI3W Interrupt Definition
 * @{
 */
#define SPI3W_INT_BIT                          BIT0     /**< SPI3W interrupt. Triggered after a read operation ends. */
/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_INT(INT) ((INT) == SPI3W_INT_BIT)
/** @} */ /* End of group SPI3W_INTERRUPT_DEFINITION */

#if (SPI3W_SUPPORT_RAP_FUNCTION == 1)

/**
 * @defgroup SPI3W_ACTION SPI3W Action
 * @{
 */

/**
 * @brief SPI3W action type.
 */
typedef enum
{
    SPI3W_ACTION_START = 0,   /**< Start action. */
} SPI3WAction_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_SPI3W_ACTION(ACTION) ((ACTION) == SPI3W_ACTION_START)

/** @} */ /* End of group SPI3W_ACTION */

#endif

/** @} */ /* End of group SPI3W_Exported_Constants */

/**
 * @defgroup SPI3W_Exported_Types SPI3W Exported Types
 * @{
 */

/**
 * @brief SPI3W initialize parameters.
 */
typedef struct
{
    uint32_t SPI3W_SysClock;              /**< Specify the SPI3W clock source.
                                               This parameter must be 20MHz. */

    uint32_t SPI3W_Speed;                 /**< Specify SPI3W clock.
                                               This parameter can be a value of 20/512MHz ~ 2MHz. */

    SPI3WMode_TypeDef SPI3W_Mode;         /**< Specify SPI3W operation mode.
                                               This parameter can be a value of @ref SPI3W_MODE. */

    uint32_t SPI3W_ReadDelay;             /**< Specify the delay time from the end of address phase to the start of read data phase.
                                               This parameter can be a value of 0x0 to 0x1f.
                                               Delay time = (SPI3W_ReadDelay+1)/(2*SPI3W_Speed). */

    SPI3WDelay_TypeDef
    SPI3W_OutputDelay; /**< This field extends SPI3W_SDIO's turnaround time (output to input) for (SPI3W_DLY_CYCLE + 1) T.
                                               The T time is 1/(2*SPI3W_CLK_OUT).
                                               This parameter can be a value of @ref SPI3W_OE_DELAY_CONFIG. */

    SPI3WExtMode_TypeDef
    SPI3W_ExtMode;   /**< This field extends SPI3W_CS for 1/(2*SPI3W_CLK_OUT) after a R/W operation.
                                               This parameter can be a value of @ref SPI3W_END_EXTEND_MODE. */
} SPI3W_InitTypeDef;

/** @} */ /* End of group SPI3W_Exported_Types */

/**
 * @defgroup SPI3W_Exported_Functions SPI3W Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the SPI3W peripheral registers to their default reset values.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi3wire_init(void)
 * {
 *     SPI3W_DeInit();
 * }
 * @endcode
 */
void SPI3W_DeInit(void);

/**
 * @brief Initialize the SPI3W peripheral according to the specified parameters in SPI3W_InitStruct.
 *
 * @param[in] SPI3W_InitStruct  Pointer to a SPI3W_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi3wire_init(void)
 * {
 *     RCC_ClockCmd(SPI3W_CLOCK, ENABLE);
 *     SPI3W_InitTypeDef SPI3W_InitStruct;
 *     SPI3W_StructInit(&SPI3W_InitStruct);
 *     SPI3W_InitStruct.SPI3W_Speed = 2000000;
 *     SPI3W_InitStruct.SPI3W_Mode  = SPI3W_3WIRE_MODE;
 *     SPI3W_InitStruct.SPI3W_ReadDelay = 0x1f;
 *     SPI3W_InitStruct.SPI3W_OutputDelay = SPI3W_OE_DELAY_1T;
 *     SPI3W_InitStruct.SPI3W_ExtMode = SPI3W_EXTEND_MODE;
 *     SPI3W_Init(&SPI3W_InitStruct);
 * }
 * @endcode
 */
void SPI3W_Init(SPI3W_InitTypeDef *SPI3W_InitStruct);

/**
 * @brief Fills each SPI3W_InitStruct member with its default value.
 *
 * @note The default settings for the SPI3W_InitStruct member are shown in the following table:
 *       | SPI3W_InitStruct member      | Default value                        |
 *       |:----------------------------:|:------------------------------------:|
 *       | SPI3W_SysClock               | 20000000                             |
 *       | SPI3W_Speed                  | 1000000                              |
 *       | SPI3W_Mode                   | @ref SPI3W_2WIRE_MODE                |
 *       | SPI3W_ReadDelay              | 0                                    |
 *       | SPI3W_OutputDelay            | @ref SPI3W_OE_DELAY_1T               |
 *       | SPI3W_ExtMode                | @ref SPI3W_NORMAL_MODE               |
 *
 * @param[in] SPI3W_InitStruct  Pointer to a SPI3W_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi3wire_init(void)
 * {
 *     RCC_ClockCmd(SPI3W_CLOCK, ENABLE);
 *     SPI3W_InitTypeDef SPI3W_InitStruct;
 *     SPI3W_StructInit(&SPI3W_InitStruct);
 *     SPI3W_InitStruct.SPI3W_SysClock    = 20000000;
 *     SPI3W_InitStruct.SPI3W_Speed       = 800000;
 *     SPI3W_InitStruct.SPI3W_Mode        = SPI3W_2WIRE_MODE;
 *     SPI3W_Init(&SPI3W_InitStruct);
 * }
 * @endcode
 */
void SPI3W_StructInit(SPI3W_InitTypeDef *SPI3W_InitStruct);

/**
 * @brief Enable or disable the specified SPI3W peripheral.
 *
 * @param[in] NewState  New state of the SPI3W peripheral.
 *                      - ENABLE: Enable the SPI3W peripheral.
 *                      - DISABLE: Disable the SPI3W peripheral.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi3wire_init(void)
 * {
 *     RCC_ClockCmd(SPI3W_CLOCK, ENABLE);
 *     SPI3W_InitTypeDef SPI3W_InitStruct;
 *     SPI3W_StructInit(&SPI3W_InitStruct);
 *     SPI3W_InitStruct.SPI3W_SysClock    = 20000000;
 *     SPI3W_InitStruct.SPI3W_Speed       = 800000;
 *     SPI3W_InitStruct.SPI3W_Mode        = SPI3W_2WIRE_MODE;
 *     SPI3W_Init(&SPI3W_InitStruct);
 *     SPI3W_Cmd(ENABLE);
 * }
 * @endcode
 */
void SPI3W_Cmd(FunctionalState NewState);

/**
 * @brief Enable or disable the specified SPI3W interrupts.
 *
 * @param[in] SPI3W_INT  Specify the SPI3W interrupt to be enabled or disabled, refer to @ref SPI3W_INTERRUPT_DEFINITION.
 *                       This parameter can only be the following value:
 *                       - SPI3W_INT_BIT: SPI3W interrupt.
 * @param[in] newState   New state of the specified SPI3W interrupts.
 *                       - ENABLE: Enable the specified SPI3W interrupt.
 *                       - DISABLE: Disable the specified SPI3W interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void driver_spi3wire_init(void)
 * {
 *     RCC_ClockCmd(SPI3W_CLOCK, ENABLE);
 *     SPI3W_InitTypeDef SPI3W_InitStruct;
 *     SPI3W_StructInit(&SPI3W_InitStruct);
 *     SPI3W_InitStruct.SPI3W_SysClock    = 20000000;
 *     SPI3W_InitStruct.SPI3W_Speed       = 800000;
 *     SPI3W_InitStruct.SPI3W_Mode        = SPI3W_2WIRE_MODE;
 *     SPI3W_Init(&SPI3W_InitStruct);
 *     SPI3W_INTConfig(SPI3W_INT_BIT, ENABLE);
 * }
 * @endcode
 */
void SPI3W_INTConfig(uint32_t SPI3W_INT, FunctionalState newState);

/**
 * @brief Configure resync signal time value.
 *
 * @param[in] value  Resync signal time value whose unit is 1/(2*SPI3W_Speed).
 *                   This parameter can only be a value of 0x0 ~ 0xf.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     SPI3W_SetResyncTime(10);
 * }
 * @endcode
 */
void SPI3W_SetResyncTime(uint32_t value);

/**
 * @brief Enable or disable sending the resync signal. Must send when SPI3W is disable.
 *
 * @param[in] NewState  New state of the SPI3W peripheral.
 *                      This parameter can only be the following value:
 *                      - ENABLE: Trigger resync signal.
 *                      - DISABLE: Disable resync signal.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     SPI3W_ResyncSignalCmd(ENABLE);
 * }
 * @endcode
 */
void SPI3W_ResyncSignalCmd(FunctionalState NewState);

/**
 * @brief Get total number of data byte.
 *
 * @return The total number of data byte.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *    uint8_t data_len = 0;
 *    data_len = SPI3W_GetRxDataLen();
 * }
 * @endcode
 */
uint8_t SPI3W_GetRxDataLen(void);

/**
 * @brief Clear read data number status.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *    SPI3W_ClearRxDataLen();
 * }
 * @endcode
 */
void SPI3W_ClearRxDataLen(void);

/**
 * @brief Clear all read data registers.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *    SPI3W_ClearRxFIFO();
 * }
 * @endcode
 */
void SPI3W_ClearRxFIFO(void);

/**
 * @brief Write a data.
 *
 * @param[in] address  Write address.
 * @param[in] data     Write data.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     uint8_t address = 0x10;
 *     uint8_t data = 0x10;
 *     SPI3W_StartWrite(address, data);
 * }
 * @endcode
 */
void SPI3W_StartWrite(uint8_t address, uint8_t data);

/**
 * @brief Start reading data.
 *
 * @param[in] address  Read address.
 * @param[in] len      Number of data to read. This value can be 0x1 to 0xf.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     uint8_t address = 0x10;
 *     uint8_t len = 0x1;
 *     SPI3W_StartRead(address, len);
 * }
 * @endcode
 */
void SPI3W_StartRead(uint8_t address, uint32_t len);

/**
 * @brief Read data.
 *
 * @param[out] pBuf    Buffer to store read data.
 * @param[in] readNum  Read number.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     uint8_t data_buf[10] = {0};
 *     uint8_t data_len = 10;
 *     SPI3W_ReadBuf(data_buf, data_len);
 * }
 * @endcode
 */
void SPI3W_ReadBuf(uint8_t *pBuf, uint8_t readNum);

/**
 * @brief Get the specified SPI3W flag status.
 *
 * @param[in] SPI3W_FLAG  Specify flags to check.
 *                        This parameter can be one of the following values, refer to @ref SPI3W_FLAG.
 *                        - SPI3W_FLAG_BUSY: SPI3W busy status.
 *                        - SPI3W_FLAG_INT_IND: SPI3W interrupt status.
 *                        - SPI3W_FLAG_RESYNC_BUSY: SPI3W resync busy status.
 *
 * @return The new state of the specified SPI3W flag.
 * @retval SET    The specified SPI3W flag state is pending.
 * @retval RESET  The specified SPI3W flag state is not pending.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *    FlagStatus flag_status = RESET;
 *    flag_status = SPI3W_GetFlagStatus(SPI3W_FLAG_BUSY);
 * }
 * @endcode
 */
FlagStatus SPI3W_GetFlagStatus(uint32_t SPI3W_FLAG);

/**
 * @brief Clear the SPI3W interrupt pending bit.
 *
 * @param[in] SPI3W_INT  Specify the SPI3W interrupt, refer to @ref SPI3W_INTERRUPT_DEFINITION.
 *                       This parameter can only be the following value:
 *                       - SPI3W_INT_BIT: SPI3W interrupt.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *    SPI3W_ClearINTPendingBit(SPI3W_INT_BIT);
 * }
 * @endcode
 */
void SPI3W_ClearINTPendingBit(uint32_t SPI3W_INT);

#if (SPI3W_SUPPORT_RAP_FUNCTION == 1)

/**
 * @brief Start the quick burst read. This API can only be used in non-RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_rap_demo(void)
 * {
 *     SPI3W_QuickBurstStart();
 * }
 * @endcode
 */
void SPI3W_QuickBurstStart(void);

/**
 * @brief Set quick burst read length.
 *
 * @param[in] len       Read length.
 * @param[in] NewState  New state of the quick burst read function.
 *                      - ENABLE: Enable the quick burst read function.
 *                      - DISABLE: Disable the quick burst read function.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_rap_demo(void)
 * {
 *     SPI3W_SetQuickBurstRead(16, ENABLE);
 * }
 * @endcode
 */
void SPI3W_SetQuickBurstRead(uint32_t len, FunctionalState NewState);

/**
 * @brief Set quick burst pulse width.
 *
 * @param[in] pulse_width  Pulse width value.
 *                         The pulse width time is (1 / 2) * (1 / SPI3W_CLK_OUT) * (SPI3W_QB_PW + 1).
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_rap_demo(void)
 * {
 *     SPI3W_SetQuickBurstPulseWidth(0x1);
 * }
 * @endcode
 */
void SPI3W_SetQuickBurstPulseWidth(uint8_t pulse_width);

/**
 * @brief Enable or disable the RAP mode.
 *
 * @param[in] NewState  New state of the RAP mode.
 *                      - ENABLE: Enable the RAP mode.
 *                      - DISABLE: Disable the RAP mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_rap_demo(void)
 * {
 *     SPI3W_RAPModeCmd(ENABLE);
 * }
 * @endcode
 */
void SPI3W_RAPModeCmd(FunctionalState NewState);

/**
 * @brief Trigger the specified action.
 *
 * @param[in] Action  Action to trigger.
 *                    This parameter can be a value of @ref SPI3W_ACTION.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_rap_demo(void)
 * {
 *     SPI3W_ActionTrigger(SPI3W_ACTION_START);
 * }
 * @endcode
 */
void SPI3W_ActionTrigger(uint32_t Action);

#endif

#if (SPI3W_SUPPORT_AUTO_CLOCK == 1)

/**
 * @brief Enable or disable the SPI3W clock auto mode.
 *
 * @param[in] Newstate  New state of the SPI3W clock auto mode.
 *                      - ENABLE: Enable the SPI3W clock auto mode.
 *                      - DISABLE: Disable the SPI3W clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     SPI3W_ClockAutoModeCmd(ENABLE);
 * }
 * @endcode
 */
void SPI3W_ClockAutoModeCmd(FunctionalState Newstate);

#endif

#if (SPI3W_SUPPORT_DATA_PAD_PULL_CONFIG == 1)

/**
 * @brief Set data input PAD pull configuration.
 *
 * @param[in] InPull  Data input pull configuration.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     SPI3W_SetDataInPADPull(SPI3W_DATA_IN_PULL_UP);
 * }
 * @endcode
 */
void SPI3W_SetDataInPADPull(SPI3W_DataInPull_TypeDef InPull);

/**
 * @brief Set data output PAD pull configuration.
 *
 * @param[in] OutPull  Data output pull configuration.
 *
 * <b>Example usage</b>
 * @code{.c}
 * void spi3wire_demo(void)
 * {
 *     SPI3W_SetDataOutPADPull(SPI3W_DATA_OUT_PULL_NONE);
 * }
 * @endcode
 */
void SPI3W_SetDataOutPADPull(SPI3W_DataOutPull_TypeDef OutPull);

#endif

/** @} */ /* End of group SPI3W_Exported_Functions */

/** @} */ /* End of group SPI3W */

#ifdef __cplusplus
}
#endif

#endif /* RTL_SPI3W_H */
