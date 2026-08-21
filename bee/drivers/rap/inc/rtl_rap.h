/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_RAP_H
#define RTL_RAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "rap/src/device/rtl87x2j/rtl_rap_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "rap/src/device/rtl87x3j/rtl_rap_def.h"
#endif

/**
 * @defgroup RAP RAP
 * @ingroup PERIPH_DRIVER
 * @brief Real Autonomous Peripheral (RAP) driver.
 *
 * @details The RAP is a hardware routing engine that links peripheral Events to
 *          peripheral Actions through a set of hardware Channels, without CPU intervention.
 * @{
 */

/**
 * @defgroup RAP_Exported_Constants RAP Exported Constants
 * @{
 */

/**
 * @defgroup    RAP_CHANNEL RAP Channel
 * @{
 * @ingroup     RAP_Exported_Constants
 */
typedef enum
{
    RAP_CHANNEL0,   /**< RAP channel 0. */
    RAP_CHANNEL1,   /**< RAP channel 1. */
    RAP_CHANNEL2,   /**< RAP channel 2. */
    RAP_CHANNEL3,   /**< RAP channel 3. */
    RAP_CHANNEL4,   /**< RAP channel 4. */
    RAP_CHANNEL5,   /**< RAP channel 5. */
    RAP_CHANNEL6,   /**< RAP channel 6. */
    RAP_CHANNEL7,   /**< RAP channel 7. */
    RAP_CHANNEL8,   /**< RAP channel 8. */
    RAP_CHANNEL9,   /**< RAP channel 9. */
    RAP_CHANNEL10,  /**< RAP channel 10. Reserved or pre-allocated by default. */
    RAP_CHANNEL11,  /**< RAP channel 11. Reserved or pre-allocated by default. */
    RAP_CHANNEL_MAX /**< RAP channel maximum value. */
} RAP_ChannelTypedef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RAP_CHANNEL(CHANNEL) (((CHANNEL) == RAP_CHANNEL0) || \
                                 ((CHANNEL) == RAP_CHANNEL1) || \
                                 ((CHANNEL) == RAP_CHANNEL2) || \
                                 ((CHANNEL) == RAP_CHANNEL3) || \
                                 ((CHANNEL) == RAP_CHANNEL4) || \
                                 ((CHANNEL) == RAP_CHANNEL5) || \
                                 ((CHANNEL) == RAP_CHANNEL6) || \
                                 ((CHANNEL) == RAP_CHANNEL7) || \
                                 ((CHANNEL) == RAP_CHANNEL8) || \
                                 ((CHANNEL) == RAP_CHANNEL9) || \
                                 ((CHANNEL) == RAP_CHANNEL10) || \
                                 ((CHANNEL) == RAP_CHANNEL11))

/** @} */ /* End of group RAP_CHANNEL */

/**
 * @defgroup    RAP_INTERRUPTS RAP Interrupts
 * @{
 * @ingroup     RAP_Exported_Constants
 */
#define RAP_INT_TRIGGER                   BIT9     /**< RAP channel trigger interrupt. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RAP_INT(INT) (((INT) == RAP_INT_TRIGGER))

/** @} */ /* End of group RAP_INTERRUPTS */

/**
 * @defgroup    RAP_WAKEUP RAP WakeUp
 * @{
 * @ingroup     RAP_Exported_Constants
 */
#define RAP_WAKEUP_TRIGGER                BIT8     /**< RAP channel trigger wakeup. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_RAP_WAKEUP(WAKEUP) (((WAKEUP) == RAP_WAKEUP_TRIGGER))

/** @} */ /* End of group RAP_WAKEUP */


/**
 * @defgroup    RAP_ACTION_EVENT RAP Action Event
 * @brief       Definitions of all supported peripheral Events and Actions.
 * @{
 * @ingroup     RAP_Exported_Constants
 *
 * @details
 * These macros generate the specific register-offset values required by the RAP routing APIs
 * (e.g., @ref RAP_EventRouteSet, @ref RAP_ActionBindSet).
 *
 * <b>Parameterized Macros:</b>
 * Many peripherals have multiple instances or channels. For these macros, `n` represents
 * the peripheral instance index, and `ch` represents the channel or pin index.
 *
 * <b>Valid Parameter Ranges:</b>
 * | Peripheral | Instance (`n`) | Channel / Pin (`ch`)                  |
 * |:-----------|:---------------|:--------------------------------------|
 * |    TIMER   | 1, 2           | 0 ~ 8 (for TIMER1), 0 (for TIMER2)    |
 * |    GPIO    | N/A            | 0 ~ 31 (for GPIOA), 0 ~ 17 (for GPIOB)|
 * |    DMA     | N/A            | 3, 4 (DMA channel index)              |
 * |    I2C     | 0, 1           | N/A                                   |
 * |    SPI     | 0, 1           | N/A                                   |
 */

/* KEYSCAN */
#define RAP_EVENT_KEYSCAN_MANUAL_DONE           (RAP_KEYSCAN_EVENT_MANUAL_DONE)        /**< Event: KeyScan manual scan done. */
#define RAP_ACTION_KEYSCAN_MANUAL               (RAP_KEYSCAN_ACTION_MANUAL)            /**< Action: start a KeyScan manual scan. */

/* TIMER */
#define RAP_EVENT_TIMER_ACTIVE(n, ch)           (RAP_TIMER##n##_CH##ch##_EVENT_ACTIVE)                  /**< Event: Timer n channel ch active. */
#define RAP_EVENT_TIMER_STOP(n, ch)             (RAP_TIMER##n##_CH##ch##_EVENT_STOP)                    /**< Event: Timer n channel ch stopped. */
#define RAP_EVENT_TIMER_TIMEOUT(n, ch)          (RAP_TIMER##n##_CH##ch##_EVENT_TIMEOUT)                 /**< Event: Timer n channel ch timeout. */
#define RAP_EVENT_TIMER_LATCH_FIFO_FULL(n, ch)  (RAP_TIMER##n##_CH##ch##_EVENT_LATCH_CNT0_FIFO_FULL)    /**< Event: Timer n channel ch latch FIFO full. */
#define RAP_EVENT_TIMER_LATCH_FIFO_THRD(n, ch)  (RAP_TIMER##n##_CH##ch##_EVENT_LATCH_CNT0_FIFO_MET_TH)  /**< Event: Timer n channel ch latch FIFO met threshold. */
#define RAP_ACTION_TIMER_STOP(n, ch)            (RAP_TIMER##n##_CH##ch##_ACTION_DISABLE)                /**< Action: disable (stop) Timer n channel ch. */
#define RAP_ACTION_TIMER_PAUSE(n, ch)           (RAP_TIMER##n##_CH##ch##_ACTION_PAUSE)                  /**< Action: pause Timer n channel ch. */
#define RAP_ACTION_TIMER_START(n, ch)           (RAP_TIMER##n##_CH##ch##_ACTION_START)                  /**< Action: start Timer n channel ch. */

/* GPIO */
#define RAP_EVENT_GPIOA(ch)                     (RAP_GPIOA_##ch##_EVENT)                /**< Event: GPIOA pin ch triggered. */
#define RAP_EVENT_GPIOB(ch)                     (RAP_GPIOB_##ch##_EVENT)                /**< Event: GPIOB pin ch triggered. */
#define RAP_ACTION_GPIOA_DRCLR(ch)              (RAP_GPIOA_##ch##_ACTION_DRCLR)         /**< Action: clear GPIOA pin ch output. */
#define RAP_ACTION_GPIOB_DRCLR(ch)              (RAP_GPIOB_##ch##_ACTION_DRCLR)         /**< Action: clear GPIOB pin ch output. */
#define RAP_ACTION_GPIOA_DRSET(ch)              (RAP_GPIOA_##ch##_ACTION_DRSET)         /**< Action: set GPIOA pin ch output. */
#define RAP_ACTION_GPIOB_DRSET(ch)              (RAP_GPIOB_##ch##_ACTION_DRSET)         /**< Action: set GPIOB pin ch output. */
#define RAP_ACTION_GPIOA_DRTOGGLE(ch)           (RAP_GPIOA_##ch##_ACTION_DRTOGGLE)      /**< Action: toggle GPIOA pin ch output. */
#define RAP_ACTION_GPIOB_DRTOGGLE(ch)           (RAP_GPIOB_##ch##_ACTION_DRTOGGLE)      /**< Action: toggle GPIOB pin ch output. */

/* IR */
#define RAP_EVENT_IR_TX_DONE                    (RAP_IR_EVENT_TXDONE)                   /**< Event: IR transmission done. */
#define RAP_EVENT_IR_RX_DONE                    (RAP_IR_EVENT_RXDONE)                   /**< Event: IR reception done. */
#define RAP_ACTION_IR_START_TX                  (RAP_IR_ACTION_START_TX)                /**< Action: start IR transmission. */
#define RAP_ACTION_IR_START_RX                  (RAP_IR_ACTION_START_RX)                /**< Action: start IR reception. */

/* I2C */
#define RAP_EVENT_I2C_ERROR(n)                  (RAP_I2C##n##_EVENT_ERROR)              /**< Event: I2C n error occurred. */
#define RAP_EVENT_I2C_STARTED(n)                (RAP_I2C##n##_EVENT_STARTED)            /**< Event: I2C n start condition detected. */
#define RAP_EVENT_I2C_STOPPED(n)                (RAP_I2C##n##_EVENT_STOPPED)            /**< Event: I2C n stop condition detected. */
#define RAP_ACTION_I2C_START(n)                 (RAP_I2C##n##_ACTION_START)             /**< Action: start I2C n transfer. */

/* ADC */
#define RAP_EVENT_ADC_DONE                      (RAP_ADC_EVENT_DONE)                    /**< Event: ADC conversion done. */
#define RAP_EVENT_ADC_RESULTDONE                (RAP_ADC_EVENT_RESULTDONE)              /**< Event: ADC result ready. */
#define RAP_ACTION_ADC_SAMPLE                   (RAP_ADC_ACTION_ONE_SHOT_SAMPLE)        /**< Action: trigger a one-shot ADC sample. */

/* SPI3W */
#define RAP_EVENT_SPI3W_END                     (RAP_SPI3WIRE_EVENT_END)                /**< Event: 3-wire SPI transfer end. */
#define RAP_ACTION_SPI3W_START                  (RAP_SPI3WIRE_ACTION_START)             /**< Action: start 3-wire SPI transfer. */

/* SPI */
#define RAP_EVENT_SPI_START(n)                  (RAP_SPI##n##_EVENT_START)              /**< Event: SPI n transfer start. */
#define RAP_EVENT_SPI_END(n)                    (RAP_SPI##n##_EVENT_END)                /**< Event: SPI n transfer end. */
#define RAP_ACTION_SPI_START(n)                 (RAP_SPI##n##_ACTION_START)             /**< Action: start SPI n transfer. */

/* RTC */
#define RAP_EVENT_RTC_TICK                      (RAP_RTC_EVENT_TICK)                    /**< Event: RTC tick. */
#define RAP_EVENT_RTC_OVERFLOW                  (RAP_RTC_EVENT_OVERFLOW)                /**< Event: RTC counter overflow. */
#define RAP_EVENT_RTC_COMPARE(ch)               (RAP_RTC_EVENT_COMPARE##ch)             /**< Event: RTC comparator ch matched. */
#define RAP_ACTION_RTC_CLEAR                    (RAP_RTC_ACTION_CLEAR)                  /**< Action: clear the RTC counter. */
#define RAP_ACTION_RTC_STOP                     (RAP_RTC_ACTION_STOP)                   /**< Action: stop the RTC counter. */
#define RAP_ACTION_RTC_START                    (RAP_RTC_ACTION_START)                  /**< Action: start the RTC counter. */
#define RAP_ACTION_RTC_RELOAD_COMP(ch)          (RAP_RTC_ACTION_RELOAD_CMP##ch)         /**< Action: reload RTC comparator ch. */

/* LPC */
#define RAP_EVENT_LPC_STATUS                    (RAP_LPC_EVENT_STATUS)                  /**< Event: LPC (low-power comparator) status met. */
#define RAP_ACTION_LPC_START                    (RAP_LPC_ACTION_START)                  /**< Action: start the LPC. */
#define RAP_ACTION_LPC_STOP                     (RAP_LPC_ACTION_STOP)                   /**< Action: stop the LPC. */

/* DMA */
#define RAP_EVENT_DMA_TRANSFER(ch)              (RAP_DMA_EVENT_INT_TRANSFER##ch)        /**< Event: DMA channel ch transfer-complete interrupt. */
#define RAP_EVENT_DMA_BLOCK(ch)                 (RAP_DMA_EVENT_INT_BLOCK##ch)           /**< Event: DMA channel ch block-complete interrupt. */
#define RAP_ACTION_DMA_CHANNEL_EN(ch)           (RAP_DMA_ACTION_CHANNEL_EN##ch)         /**< Action: enable DMA channel ch. */

/* GRTC */
#define RAP_EVENT_GRTC_COMPARE(ch)              (RAP_GRTC_EVENT_COMPARE##ch)            /**< Event: GRTC comparator ch matched. */
#define RAP_ACTION_GRTC_RELOAD_COMP(ch)         (RAP_GRTC_ACTION_RELOAD_CMP##ch)        /**< Action: reload GRTC comparator ch. */

/* SDMK */
#define RAP_EVENT_SDMK_DONE                     (RAP_SDMK_EVENT_DONE)                   /**< Event: SDMK done. */
#define RAP_ACTION_SDMK_START                   (RAP_SDMK_ACTION_START)                 /**< Action: start SDMK. */

/* OSC10M */
#define RAP_EVENT_OSC10M_CAL_DONE               (RAP_OSC10M_EVENT_CAL_DONE)             /**< Event: 10 MHz oscillator calibration done. */
#define RAP_ACTION_OSC10M_CAL                   (RAP_OSC10M_ACTION_CAL)                 /**< Action: start 10 MHz oscillator calibration. */

/* OSC80M */
#define RAP_EVENT_OSC80M_CAL_DONE               (RAP_OSC80M_EVENT_CAL_DONE)             /**< Event: 80 MHz oscillator calibration done. */
#define RAP_ACTION_OSC80M_CAL                   (RAP_OSC80M_ACTION_CAL)                 /**< Action: start 80 MHz oscillator calibration. */

/* TMETER */
#define RAP_EVENT_TMETER_DATARDY                (RAP_TMETER_EVENT_DATARDY)              /**< Event: Thermal meter data ready. */
#define RAP_EVENT_TMETER_ABS_COMP(ch)           (RAP_TMETER_EVENT_ABS_CMP##ch)          /**< Event: Thermal meter absolute comparator ch matched. */
#define RAP_EVENT_TMETER_REL_COMP(ch)           (RAP_TMETER_EVENT_REL_CMP##ch)          /**< Event: Thermal meter relative comparator ch matched. */
#define RAP_EVENT_TMETER_FW_REL_COMP3           (RAP_TMETER_EVENT_FW_REL_COMP3)         /**< Event: Thermal meter firmware relative comparator 3 matched. */
#define RAP_ACTION_TMETER_ONESHOT               (RAP_TMETER_ACTION_ONESHOT)             /**< Action: trigger a one-shot thermal meter measurement. */

/** @} */ /* End of group RAP_ACTION_EVENT */

/**
 * @defgroup    RAP_ACTION_EVENT_STATUS RAP Action Event Status
 * @{
 * @ingroup     RAP_Exported_Constants
 */
#define RAP_GetActionEventStatus(n)              ((n##_OFFSET & n##_BIT) == n##_BIT)    /**< Get the trigger status of the specified Action/Event. */
#define RAP_ClearActionEventStatus(n)            (n##_OFFSET = n##_BIT)                 /**< Clear the trigger status of the specified Action/Event. */

/** @} */ /* End of group RAP_ACTION_EVENT_STATUS */

/** @} */ /* End of group RAP_Exported_Constants */

/**
 * @defgroup RAP_Exported_Functions RAP Exported Functions
 * @{
 */

/**
 * @brief Deinitialize the RAP peripheral registers to their default reset values.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     RAP_DeInit();
 * }
 * @endcode
 */
void RAP_DeInit(void);

/**
 * @brief Enable or disable the RAP peripheral.
 *
 * @param[in] NewState  Enable or disable the RAP peripheral.
 *                      This parameter can be ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     // Enable the RAP routing engine after event/actions are configured.
 *     RAP_Cmd(ENABLE);
 * }
 * @endcode
 */
void RAP_Cmd(FunctionalState NewState);

/**
 * @brief Enable or disable the specified RAP interrupt for a specified channel.
 *
 * @param[in] RAP_INT    Specifies the RAP interrupt source to be enabled or disabled.
 *                       This parameter can be any of @ref RAP_INTERRUPTS.
 *                       - RAP_INT_TRIGGER: RAP channel trigger interrupt.
 * @param[in] Channel    Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 * @param[in] NewState   Enable or disable the specified RAP interrupt for the channel.
 *                       This parameter can be ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     // Generate an interrupt when this channel is triggered.
 *     RAP_INTConfig(RAP_INT_TRIGGER, channel, ENABLE);
 * }
 * @endcode
 */
void RAP_INTConfig(uint32_t RAP_INT, uint8_t Channel, FunctionalState NewState);

/**
 * @brief Enable or disable the specified RAP wakeup for a specified channel.
 *
 * @param[in] RAP_WAKEUP  Specifies the RAP wakeup source to be enabled or disabled.
 *                        This parameter can be any of @ref RAP_WAKEUP.
 *                        - RAP_WAKEUP_TRIGGER: RAP channel trigger wakeup.
 * @param[in] Channel     Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 * @param[in] NewState    Enable or disable the specified RAP wakeup for the channel.
 *                        This parameter can be ENABLE or DISABLE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     // Allow this channel to wake up the system from low power.
 *     RAP_WakeUpConfig(RAP_WAKEUP_TRIGGER, channel, ENABLE);
 * }
 * @endcode
 */
void RAP_WakeUpConfig(uint32_t RAP_WAKEUP, uint8_t Channel, FunctionalState NewState);

/**
 * @brief Clear the RAP interrupt pending bit for a specified channel.
 *
 * @note This clears the global RAP interrupt pending status by setting the
 *       hardware clear bit. It clears all pending channel interrupts at once;
 *       no per-channel/per-source argument is needed.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void RAP_Handler(void)
 * {
 *     if (RAP_GetINTStatus(RAP_INT_TRIGGER) == true)
 *     {
 *         // Add user code here.
 *         RAP_ClearINTPendingBit();
 *     }
 * }
 * @endcode
 */
void RAP_ClearINTPendingBit(void);

/**
 * @brief Get the interrupt status of the specified RAP channel.
 *
 * @param[in] RAP_INT  Specifies the RAP interrupt source to check.
 *                     This parameter can be any of @ref RAP_INTERRUPTS.
 *                     - RAP_INT_TRIGGER: RAP channel trigger interrupt.
 *
 * @return The new state of RAP_INT.
 * @retval true   The specified RAP interrupt has occurred.
 * @retval false  The specified RAP interrupt has not occurred.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void RAP_Handler(void)
 * {
 *     if (RAP_GetINTStatus(RAP_INT_TRIGGER) == true)
 *     {
 *         RAP_ClearINTPendingBit();
 *     }
 * }
 * @endcode
 */
bool RAP_GetINTStatus(uint32_t RAP_INT);

/**
 * @brief Enable or disable the core wakeup action for a specified channel.
 *
 * @param[in] Channel   Specifies the RAP channel to configure. Refer to @ref RAP_CHANNEL.
 * @param[in] NewState  Enable or disable the core wakeup action for the channel.
 *                      - ENABLE : Allow this channel to wake up the core.
 *                      - DISABLE: Do not wake up the core on this channel.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     RAP_ActionWakeUpCoreCmd(channel, ENABLE);
 * }
 * @endcode
 */
void RAP_ActionWakeUpCoreCmd(uint8_t Channel, FunctionalState NewState);

/**
 * @brief Allocate a free RAP channel.
 *
 * @param[out] p_Channel  Pointer to a variable that receives the allocated channel
 *                        number on success. On failure it is set to 0xA5.
 *
 * @return The allocation result.
 * @retval true   Allocation successful, *p_Channel holds a valid channel.
 * @retval false  Allocation failed (all channels are currently in use).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     if (RAP_ChannelAllocate(&channel))
 *     {
 *         // Use 'channel' to route events / bind actions.
 *     }
 * }
 * @endcode
 */
bool RAP_ChannelAllocate(uint8_t *p_Channel);

/**
 * @brief Free a previously allocated RAP channel.
 *
 * @param[in] Channel  Specifies the RAP channel to free. Refer to @ref RAP_CHANNEL.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     // ... use the channel ...
 *     RAP_ChannelFree(channel);
 * }
 * @endcode
 */
void RAP_ChannelFree(uint8_t Channel);

/**
 * @brief Get the current mask of allocated RAP channels.
 *
 * @return  A bitmask in which each set bit indicates that the corresponding
 *          channel is currently allocated (BIT(n) for channel n).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint32_t mask = RAP_ChannelAllocatedMaskGet();
 * }
 * @endcode
 */
uint32_t RAP_ChannelAllocatedMaskGet(void);

/**
 * @brief Route a peripheral Event (source) to a specified RAP channel.
 *
 * @param[in] Event    Specifies the peripheral event. This is a register offset
 *                     macro relative to the RAP base address. Refer to @ref RAP_ACTION_EVENT.
 * @param[in] Channel  Specifies the RAP channel to bind the event to. Refer to @ref RAP_CHANNEL.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     RAP_EventRouteSet(RAP_EVENT_TIMER_TIMEOUT, channel);
 * }
 * @endcode
 */
void RAP_EventRouteSet(uint32_t Event, uint8_t Channel);

/**
 * @brief Clear the routing of a peripheral Event from a specified RAP channel.
 *
 * @param[in] Event    Specifies the peripheral event. Refer to @ref RAP_ACTION_EVENT.
 * @param[in] Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     RAP_EventRouteClear(RAP_EVENT_TIMER_TIMEOUT, channel);
 * }
 * @endcode
 */
void RAP_EventRouteClear(uint32_t Event, uint8_t Channel);

/**
 * @brief Bind a peripheral Action to a specified RAP channel.
 *
 * @param[in] Action   Specifies the action to be triggered. This is a register
 *                     offset macro relative to the RAP base address. Refer to @ref RAP_ACTION_EVENT.
 * @param[in] Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint8_t channel;
 *     RAP_ChannelAllocate(&channel);
 *     RAP_EventRouteSet(RAP_EVENT_TIMER_TIMEOUT, channel);
 *     RAP_ActionBindSet(RAP_ACTION_ADC_SAMPLE, channel);
 * }
 * @endcode
 */
void RAP_ActionBindSet(uint32_t Action, uint8_t Channel);

/**
 * @brief Clear the binding of a peripheral Action from a specified RAP channel.
 *
 * @param[in] Action   Specifies the action. Refer to @ref RAP_ACTION_EVENT.
 * @param[in] Channel  Specifies the RAP channel. Refer to @ref RAP_CHANNEL.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     RAP_ActionBindClear(RAP_ACTION_ADC_SAMPLE, channel);
 * }
 * @endcode
 */
void RAP_ActionBindClear(uint32_t Action, uint8_t Channel);

/**
 * @brief Get the channel bitmask bound to a specified Action or Event.
 *
 * @param[in] ActionEvent  Specifies the Action or Event offset macro. Refer to @ref RAP_ACTION_EVENT.
 *
 * @return  A bitmask in which each set bit indicates a channel bound to the
 *          specified Action/Event (BIT(n) for channel n).
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void rap_demo(void)
 * {
 *     uint32_t mask = RAP_ActionEventChannelGet(RAP_ACTION_ADC_SAMPLE);
 * }
 * @endcode
 */
uint32_t RAP_ActionEventChannelGet(uint32_t ActionEvent);

/** @} */ /* End of group RAP_Exported_Functions */

/** @} */ /* End of group RAP */

#ifdef __cplusplus
}
#endif

#endif /* RTL_RAP_H */
