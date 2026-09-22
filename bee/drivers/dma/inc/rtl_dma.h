/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_DMA_H
#define RTL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X2G)
#include "dma/src/device/rtl87x2g/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3D)
#include "dma/src/device/rtl87x3d/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "dma/src/device/rtl87x2j/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "dma/src/device/rtl87x3j/rtl_dma_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "dma/src/device/rtl87x3k/rtl_dma_def.h"
#endif

/**
  * @defgroup DMA_DRIVER DRIVER
  * @ingroup DMA
  * @brief DMA driver.
  * @{
  */

/**
  * @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/**
 * @defgroup    DMA_CHANNEL_NUM DMA Channel Num
 * @{
 * @ingroup     DMA_Exported_Constants
 */

#define DMA_CH_NUM0             (0)       /**< DMA channel number0. */
#define DMA_CH_NUM1             (1)       /**< DMA channel number1. */
#define DMA_CH_NUM2             (2)       /**< DMA channel number2. */
#define DMA_CH_NUM3             (3)       /**< DMA channel number3. */
#define DMA_CH_NUM4             (4)       /**< DMA channel number4. */
#define DMA_CH_NUM5             (5)       /**< DMA channel number5. */
#if (CHIP_DMA_CHANNEL_NUM >= 9)
#define DMA_CH_NUM6             (6)       /**< DMA channel number6. */
#define DMA_CH_NUM7             (7)       /**< DMA channel number7. */
#define DMA_CH_NUM8             (8)       /**< DMA channel number8. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 10)
#define DMA_CH_NUM9             (9)       /**< DMA channel number9. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 12)
#define DMA_CH_NUM10            (10)       /**< DMA channel number10. */
#define DMA_CH_NUM11            (11)       /**< DMA channel number11. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 16)
#define DMA_CH_NUM12            (12)       /**< DMA channel number12. */
#define DMA_CH_NUM13            (13)       /**< DMA channel number13. */
#define DMA_CH_NUM14            (14)       /**< DMA channel number14. */
#define DMA_CH_NUM15            (15)       /**< DMA channel number15. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 24)
#define DMA_CH_NUM16            (16)       /**< DMA channel number16. */
#define DMA_CH_NUM17            (17)       /**< DMA channel number17. */
#define DMA_CH_NUM18            (18)       /**< DMA channel number18. */
#define DMA_CH_NUM19            (19)       /**< DMA channel number19. */
#define DMA_CH_NUM20            (20)       /**< DMA channel number20. */
#define DMA_CH_NUM21            (21)       /**< DMA channel number21. */
#define DMA_CH_NUM22            (22)       /**< DMA channel number22. */
#define DMA_CH_NUM23            (23)       /**< DMA channel number23. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 27)
#define DMA_CH_NUM24            (24)       /**< DMA channel number24. */
#define DMA_CH_NUM25            (25)       /**< DMA channel number25. */
#define DMA_CH_NUM26            (26)       /**< DMA channel number26. */
#endif
#if (CHIP_DMA_CHANNEL_NUM >= 33)
#define DMA_CH_NUM27            (27)       /**< DMA channel number27. */
#define DMA_CH_NUM28            (28)       /**< DMA channel number28. */
#define DMA_CH_NUM29            (29)       /**< DMA channel number29. */
#define DMA_CH_NUM30            (30)       /**< DMA channel number30. */
#define DMA_CH_NUM31            (31)       /**< DMA channel number31. */
#define DMA_CH_NUM32            (32)       /**< DMA channel number32. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_ChannelNum(NUM)  ((NUM) < CHIP_DMA_CHANNEL_NUM)

/** @} */ /* End of group DMA_CHANNEL_NUM */

/**
 * @defgroup   DMA_DATA_TRANSFER_DIRECTION DMA Data Transfer Direction
 * @{
 * @ingroup    DMA_Exported_Constants
 */

typedef enum
{
    DMA_DIR_MEMORY_TO_MEMORY = 0x0,             /**< Configure the direction as memory to memory. */
    DMA_DIR_MEMORY_TO_PERIPHERAL = 0x1,         /**< Configure the direction as memory to peripheral. */
    DMA_DIR_PERIPHERAL_TO_MEMORY = 0x2,         /**< Configure the direction as peripheral to memory. */
    DMA_DIR_PERIPHERAL_TO_PERIPHERAL = 0x3,     /**< Configure the direction as peripheral to peripheral. */
#if (DMA_SUPPORT_PERIPHERAL_FLOW_CONTROL == 1)
    DMA_DIR_PERIPHERAL_TO_MEMORY_FLOW_CTRL = 0x4,   /**< Configure the direction as peripheral to memory with flow control. */
    DMA_DIR_MEMORY_TO_PERIPHERAL_FLOW_CTRL = 0x6,   /**< Configure the direction as memory to peripheral with flow control. */
#endif
} DMADirection_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_DIR(DIR) (((DIR) == DMA_DIR_MEMORY_TO_MEMORY) || \
                         ((DIR) == DMA_DIR_MEMORY_TO_PERIPHERAL) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_MEMORY) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_PERIPHERAL) || \
                         ((DIR) == DMA_DIR_PERIPHERAL_TO_MEMORY_FLOW_CTRL) || \
                         ((DIR) == DMA_DIR_MEMORY_TO_PERIPHERAL_FLOW_CTRL))

/** @} */ /* End of group DMA_DATA_TRANSFER_DIRECTION */

/**
 * @defgroup    DMA_SOURCE_MODE DMA Source Mode
 * @{
 * @ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_SOURCE_INC = 0x0,        /**< Configure the source address to increment. */
#if (DMA_SUPPORT_ADDRESS_DECREASE == 1)
    DMA_SOURCE_DEC = 0x1,        /**< Configure the source address to decrement. */
#endif
    DMA_SOURCE_FIX = 0x2,        /**< Configure the source address to be fixed. */
} DMASrcMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_SOURCE_MODE(MODE) (((MODE) == DMA_SOURCE_INC) || \
                                  ((MODE) == DMA_SOURCE_DEC) || \
                                  ((MODE) == DMA_SOURCE_FIX))

/** @} */ /* End of group DMA_SOURCE_MODE */

/**
 * @defgroup    DMA_DESTINATION_MODE DMA Destination Mode
 * @{
 * @ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_DESTINATION_INC = 0x0,    /**< Configure the destination address to increment. */
#if (DMA_SUPPORT_ADDRESS_DECREASE == 1)
    DMA_DESTINATION_DEC = 0x1,    /**< Configure the destination address to decrement. */
#endif
    DMA_DESTINATION_FIX = 0x2,    /**< Configure the destination address to be fixed. */
} DMADestMode_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_DESTINATION_MODE(MODE) (((MODE) == DMA_DESTINATION_INC) || \
                                       ((MODE) == DMA_DESTINATION_DEC) || \
                                       ((MODE) == DMA_DESTINATION_FIX))

/** @} */ /* End of group DMA_DESTINATION_MODE */

/**
 * @defgroup    DMA_DATA_SIZE DMA Data Size
 * @{
 * @ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_DATA_SIZE_BYTE           = 0x0,    /**< Configure the source or destination data size as byte. */
    DMA_DATA_SIZE_HALFWORD       = 0x1,    /**< Configure the source or destination data size as half word. */
    DMA_DATA_SIZE_WORD           = 0x2,    /**< Configure the source or destination data size as word. */
#if (DMA_SUPPORT_DATA_SIZE_DOUBLE_WORD == 1)
    DMA_DATA_SIZE_DOUBLEWORD     = 0x3,    /**< Configure the source or destination data size as double word. */
#endif
    DMA_DATA_SIZE_MAX,                     /**< Maximum value of data size. */
} DMADataSize_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_DATA_SIZE(SIZE) ((SIZE) < DMA_DATA_SIZE_MAX)

/** @} */ /* End of group DMA_DATA_SIZE */

/**
 * @defgroup    DMA_MSIZE DMA Msize
 * @{
 * @ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_MSIZE_1   = 0x0,          /**< Configure the number of data items to be transferred as 1. */
    DMA_MSIZE_4   = 0x1,          /**< Configure the number of data items to be transferred as 4. */
    DMA_MSIZE_8   = 0x2,          /**< Configure the number of data items to be transferred as 8. */
    DMA_MSIZE_16  = 0x3,          /**< Configure the number of data items to be transferred as 16. */
    DMA_MSIZE_32  = 0x4,          /**< Configure the number of data items to be transferred as 32. */
#if (DMA_SUPPORT_MSIZE_64 == 1)
    DMA_MSIZE_64  = 0x5,          /**< Configure the number of data items to be transferred as 64. */
#endif
#if (DMA_SUPPORT_MSIZE_128 == 1)
    DMA_MSIZE_128 = 0x6,          /**< Configure the number of data items to be transferred as 128. */
#endif
#if (DMA_SUPPORT_MSIZE_256 == 1)
    DMA_MSIZE_256 = 0x7,          /**< Configure the number of data items to be transferred as 256. */
#endif
    DMA_MSIZE_MAX,                /**< Maximum value of Msize. */
} DMAMSize_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_MSIZE(SIZE) ((SIZE) < DMA_MSIZE_MAX)

/** @} */ /* End of group DMA_MSIZE */

#if (DMA_SUPPORT_AUTO_SLOW_CONFIG == 1)
/**
 * @defgroup    DMA_AUTO_SLOW DMA Auto Slow
 * @{
 * @ingroup     DMA_Exported_Constants
 */

typedef enum
{
    DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE  = 0x0,  /**< DMA not allow auto slow when DMA enable but in idle state. */
    DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE = 0x1,       /**< DMA allow auto slow when DMA enable but in idle state. */
} DMAAutoSlow_TypeDef;

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_AUTO_SLOW(MODE) (((MODE) == DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE) || \
                                ((MODE) == DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE))

/** @} */ /* End of group DMA_AUTO_SLOW */
#endif
/**
 * @defgroup    DMA_INTERRUPTS  DMA Interrupts
 * @{
 * @ingroup     DMA_Exported_Constants
 */

#define DMA_INT_TRANSFER               (BIT0)  /**< The interrupt is generated on DMA transfer completion to the destination. */
#define DMA_INT_BLOCK                  (BIT1)  /**< The interrupt is generated on DMA block transfer completion to the destination. */
#define DMA_INT_ERROR                  (BIT4)  /**< The interrupt is generated when an ERROR response is received from the slave on the SRESP bus during a DMA transfer. */
#if (DMA_SUPPORT_INT_HALF_BLOCK == 1)
#define DMA_INT_HALF_BLOCK             (BIT5)  /**< The interrupt is generated on DMA half block transfer completion to the destination. */
#endif
#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
#define DMA_INT_BLOCK_COUNTER          (BIT6)  /**< The interrupt is generated on DMA block counter completion. */
#endif

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_CONFIG_INT(INT) ((((INT) & 0xFFFFFFE0) == 0x00) && ((INT) != 0x00))

/** @} */ /* End of group DMA_INTERRUPTS */

/**
 * @defgroup    DMA_MULTI_BLOCK_MODE DMA Multi-block Mode
 * @{
 * @ingroup     DMA_Exported_Constants
 */
#define AUTO_RELOAD_WITH_CONTIGUOUS_SAR (BIT31)          /**< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to auto-reload. */
#define AUTO_RELOAD_WITH_CONTIGUOUS_DAR (BIT30)          /**< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to continuous. */
#define AUTO_RELOAD_TRANSFER            (BIT30 | BIT31)  /**< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to auto-reload. */
#define LLI_WITH_CONTIGUOUS_SAR         (BIT27)          /**< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to LLI. */
#define LLI_WITH_AUTO_RELOAD_SAR        (BIT27 | BIT30)  /**< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to LLI. */
#define LLI_WITH_CONTIGUOUS_DAR         (BIT28)          /**< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to continuous. */
#define LLI_WITH_AUTO_RELOAD_DAR        (BIT28 | BIT31)  /**< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to auto-reload. */
#define LLI_TRANSFER                    (BIT27 | BIT28)  /**< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to LLI. */

/** @brief Check if the input parameter is valid. @hideinitializer */
#define IS_DMA_MULTIBLOCKMODE(MODE)     (((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_SAR) || \
                                         ((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_DAR) || \
                                         ((MODE) == AUTO_RELOAD_TRANSFER) || \
                                         ((MODE) == LLI_WITH_CONTIGUOUS_SAR) || \
                                         ((MODE) == LLI_WITH_AUTO_RELOAD_SAR) || \
                                         ((MODE) == LLI_WITH_CONTIGUOUS_DAR) || \
                                         ((MODE) == LLI_WITH_AUTO_RELOAD_DAR) || \
                                         ((MODE) == LLI_TRANSFER))

/** @} */ /* End of group DMA_MULTI_BLOCK_MODE */

/**
 * @defgroup    DMA_MULTI_BLOCK_SELECT_BIT DMA Multi-Block Specifies Bit
 * @{
 * @ingroup     DMA_Exported_Constants
 */
#define AUTO_RELOAD_SELECTED_BIT        (BIT30 | BIT31)   /**< The bit for DMA auto-reload. */
#define LLP_SELECTED_BIT                (BIT27 | BIT28)   /**< The bit for DMA LLI. */

/** @} */ /* End of group DMA_MULTI_BLOCK_SELECT_BIT */

/** @} */ /* End of group DMA_Exported_Constants */

/**
  * @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */

typedef struct
{
    uint8_t DMA_ChannelNum;                 /**< Specifies the channel number.
                                                 This parameter can be any value of @ref DMA_CHANNEL_NUM. */

    DMADirection_TypeDef DMA_Direction;     /**< Specifies the transfer direction.
                                                 This parameter can be any value of @ref DMA_DATA_TRANSFER_DIRECTION. */

    uint32_t DMA_BufferSize;                /**< Specifies the transfer size.
                                                 The number of single transactions in one block. The unit of this size
                                                 is the data width set in @ref DMA_DATA_SIZE of @ref DMA_SourceDataSize
                                                 or @ref DMA_DestinationDataSize depending on the transfer direction.
                                                 This parameter can range from 1 to 65535. */

    DMASrcMode_TypeDef DMA_SourceInc;       /**< Specifies the source address mode.
                                                 Use fixed mode when reading from a peripheral FIFO at a constant address.
                                                 This parameter can be any value of @ref DMA_SOURCE_MODE. */

    DMADestMode_TypeDef DMA_DestinationInc; /**< Specifies the destination address mode.
                                                 Use fixed mode when writing to a peripheral FIFO at a constant address.
                                                 This parameter can be any value of @ref DMA_DESTINATION_MODE. */

    DMADataSize_TypeDef DMA_SourceDataSize; /**< Specifies the source transfer width.
                                                 This parameter can be any value of @ref DMA_DATA_SIZE. */

    DMADataSize_TypeDef DMA_DestinationDataSize; /**< Specifies the destination transfer width.
                                                 This parameter can be any value of @ref DMA_DATA_SIZE. */

    DMAMSize_TypeDef DMA_SourceMsize;       /**< Specifies the source burst size.
                                                 The source burst size is the number of data items read from the source
                                                 for each burst transaction request.
                                                 This parameter can be any value of @ref DMA_MSIZE. */

    DMAMSize_TypeDef DMA_DestinationMsize;  /**< Specifies the destination burst size.
                                                 The destination burst size is the number of data items written to the
                                                 destination for each burst transaction request.
                                                 This parameter can be any value of @ref DMA_MSIZE. */

    uint32_t DMA_SourceAddr;                /**< Specifies the source base address. */

    uint32_t DMA_DestinationAddr;           /**< Specifies the destination base address. */

    uint32_t DMA_ChannelPriority;           /**< Specifies the software priority.
                                                 Priority 0 is the highest priority (effective only when programmable priority is built in).
                                                 This parameter ranges according to the number of channels. */

    uint32_t DMA_MultiBlockMode;            /**< Specifies the multi-block transfer mode.
                                                 It is used to chain blocks without CPU intervention.
                                                 This parameter can be any value of @ref DMA_MULTI_BLOCK_MODE. */

    uint32_t DMA_MultiBlockStruct;          /**< Pointer to the first linked list item (LLI).
                                                 It is used when the linked-list multi-block mode is selected. */

    uint8_t DMA_MultiBlockEn;               /**< Enable or disable multi-block function.
                                                 This parameter can be any value of DISABLE or ENABLE. */

    uint8_t DMA_SourceHandshake;            /**< Specifies the source hardware handshake interface.
                                                 Which peripheral request line drives source transactions.
                                                 This parameter can be any value of @ref DMA_Handshake_Type. */

    uint8_t DMA_DestHandshake;              /**< Specifies the destination hardware handshake interface.
                                                 Which peripheral request line drives destination transactions.
                                                 This parameter can be any value of @ref DMA_Handshake_Type. */

#if (DMA_SUPPORT_SECURE_MODE == 1)
    uint8_t DMA_SecureEn;                   /**< Enable or disable Secure function. */
#endif

#if (DMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    uint8_t  DMA_GatherEn;                  /**< Enable or disable Gather function. NOTE:4 bytes ALIGN.*/

    uint32_t DMA_GatherCount;               /**< Specifies the GatherCount.NOTE:4 bytes ALIGN.*/

    uint32_t DMA_GatherInterval;            /**< Specifies the GatherInterval. */

    uint8_t  DMA_ScatterEn;                 /**< Enable or disable Scatter function. */

    uint32_t DMA_ScatterCount;              /**< Specifies the ScatterCount. */

    uint32_t DMA_ScatterInterval;           /**< Specifies the ScatterInterval. */

    uint32_t DMA_GatherCircularStreamingNum;  /**< Specifies the GatherCircularStreamingNum. */

    uint32_t DMA_ScatterCircularStreamingNum; /**< Specifies the ScatterCircularStreamingNum. */
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
    FunctionalState DMA_ContSarEn;          /**< Enable or disable continuous source address
                                                 across single blocks. When enabled, the source address keeps advancing
                                                 between consecutive single-block transfers instead of reloading the base
                                                 address. Not available together with gather, scatter or multi-block. */

    FunctionalState DMA_ContDarEn;          /**< Enable or disable continuous destination address
                                                 across single blocks. When enabled, the destination address keeps advancing
                                                 between consecutive single-block transfers instead of reloading the base
                                                 address. Not available together with gather, scatter or multi-block. */
#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
    uint32_t DMA_BlockCounter;              /**< Specifies the initial value of the block counter.
                                                 The block counter is decremented by 1 after each block transfer completes
                                                 and saturates at 0, so it tracks the number of remaining blocks. */
#endif

} DMA_InitTypeDef;

typedef struct
{
    __IO uint32_t SAR;          /**< Specifies the source base address for LLI. */
    __IO uint32_t DAR;          /**< Specifies the destination base address for LLI. */
    __IO uint32_t LLP;          /**< Specifies the next pointer to the struct of LLI. */
    __IO uint32_t CTL_LOW;      /**< Specifies the CTL_LOW register for LLI. */
    __IO uint32_t CTL_HIGH;     /**< Specifies the CTL_HIGH register for LLI. */
} DMA_LLIDef;

/** @} */ /* End of group DMA_Exported_Types */

/**
  * @defgroup DMA_Exported_Functions DMA Exported Functions
  * @{
  */

/**
 * @brief Deinitialize the DMA registers to their default reset values.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     DMA_DeInit();
 * }
 * @endcode
 */
void DMA_DeInit(void);

/**
 * @brief Initialize the DMA Channelx according to the specified parameters in the DMA_InitStruct.
 *
 * @param[in] DMA_Channelx    Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] DMA_InitStruct  Pointer to a DMA_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCE_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATION_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * @endcode
 */
void DMA_Init(DMA_ChannelTypeDef *DMA_Channelx, DMA_InitTypeDef *DMA_InitStruct);

/**
 * @brief Fill each DMA_InitStruct member with its default value.
 *
 * @param[in] DMA_InitStruct  Pointer to a DMA_InitTypeDef structure which will be initialized.
 *
 * @note The default settings for the DMA_InitStruct member are shown in the following table:
 *         | DMA_InitStruct member       | Default value                      |
 *         |:---------------------------:|:----------------------------------:|
 *         | DMA_ChannelNum              | @ref DMA_CH_NUM0                   |
 *         | DMA_Direction               | @ref DMA_DIR_PERIPHERAL_TO_MEMORY  |
 *         | DMA_BufferSize              | 200                                |
 *         | DMA_SourceInc               | @ref DMA_SOURCE_FIX                |
 *         | DMA_DestinationInc          | @ref DMA_DESTINATION_INC           |
 *         | DMA_SourceDataSize          | @ref DMA_DATA_SIZE_BYTE            |
 *         | DMA_DestinationDataSize     | @ref DMA_DATA_SIZE_BYTE            |
 *         | DMA_SourceMsize             | @ref DMA_MSIZE_1                   |
 *         | DMA_DestinationMsize        | @ref DMA_MSIZE_1                   |
 *         | DMA_SourceAddr              | 0                                  |
 *         | DMA_DestinationAddr         | 0                                  |
 *         | DMA_ChannelPriority         | 4                                  |
 *         | DMA_MultiBlockMode          | @ref LLI_TRANSFER                  |
 *         | DMA_SourceHandshake         | 0                                  |
 *         | DMA_DestHandshake           | 0                                  |
 *         | DMA_MultiBlockEn            | DISABLE                            |
 *         | DMA_ScatterEn               | DISABLE                            |
 *         | DMA_GatherEn                | DISABLE                            |
 *         | DMA_MultiBlockStruct        | 0                                  |
 *         | DMA_ScatterCount            | 0                                  |
 *         | DMA_ScatterInterval         | 0                                  |
 *         | DMA_GatherCount             | 0                                  |
 *         | DMA_GatherInterval          | 0                                  |
 *         | DMA_SecureEn                | ENABLE                             |
 *         | DMA_ContSarEn               | DISABLE                            |
 *         | DMA_ContDarEn               | DISABLE                            |
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCE_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATION_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 * }
 * @endcode
 */
void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct);

/**
 * @brief Enable or disable the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] NewState        New state of the specified DMA channel.
 *                            This parameter can be one of the following values:
 *                            - ENABLE: Enable the specified DMA channel.
 *                            - DISABLE: Disable the specified DMA channel.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCE_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATION_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * @endcode
 */
void DMA_Cmd(uint8_t DMA_ChannelNum, FunctionalState NewState);

/**
 * @brief Set the priority of the specified DMA channel.
 * @param[in] DMA_ChannelNum      Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] DMA_ChannelPriority Specifies the DMA channel priority level.
 */
void DMA_SetPriority(uint8_t DMA_ChannelNum, uint8_t DMA_ChannelPriority);

/**
 * @brief Enable or disable the specified DMA channel interrupt source.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] DMA_INT         Specifies the DMA interrupt source to be enabled or disabled.
 *                            This parameter can be any combination of the following values. Refer to @ref DMA_INTERRUPTS.
 *                            - DMA_INT_TRANSFER: Transfer complete interrupt source.
 *                            - DMA_INT_BLOCK: Block transfer interrupt source.
 *                            - DMA_INT_ERROR: Transfer error interrupt source.
 *                            - DMA_INT_HALF_BLOCK: Half block transfer interrupt source.
 *                            - DMA_INT_BLOCK_COUNTER: Block counter interrupt source.
 * @param[in] NewState        New state of the specified DMA channel interrupt source.
 *                            This parameter can be one of the following values:
 *                            - ENABLE: Enable the specified DMA channel interrupt source.
 *                            - DISABLE: Disable the specified DMA channel interrupt source.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *
 *     for (uint32_t i = 0; i < UART_TX_DMA_BUFFER_SIZE; i++)
 *     {
 *         DMA_SendData_Buffer[i] = 0x10 + i;
 *     }
 *
 *     DMA_InitTypeDef DMA_InitStruct;
 *     DMA_StructInit(&DMA_InitStruct);
 *     DMA_InitStruct.DMA_ChannelNum      = 1;
 *     DMA_InitStruct.DMA_Direction       = DMA_DIR_MEMORY_TO_PERIPHERAL;
 *     DMA_InitStruct.DMA_BufferSize      = UART_TX_DMA_BUFFER_SIZE;//determine total transfer size
 *     DMA_InitStruct.DMA_SourceInc       = DMA_SOURCE_INC;
 *     DMA_InitStruct.DMA_DestinationInc  = DMA_DESTINATION_FIX;
 *     DMA_InitStruct.DMA_SourceDataSize  = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_DestinationDataSize = DMA_DATA_SIZE_BYTE;
 *     DMA_InitStruct.DMA_SourceMsize      = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_DestinationMsize = DMA_MSIZE_1;
 *     DMA_InitStruct.DMA_SourceAddr      = (uint32_t)DMA_SendData_Buffer;
 *     DMA_InitStruct.DMA_DestinationAddr = (uint32_t)(&(UART0->UART_RBR_THR));
 *     DMA_InitStruct.DMA_DestHandshake   = DMA0_Handshake_UART0_TX;
 *     DMA_InitStruct.DMA_ChannelPriority = 2;
 *     DMA_Init(UART_TX_DMA_CHANNEL, &DMA_InitStruct);
 *
 *     DMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, DMA_INT_TRANSFER, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_CHANNEL_IRQN;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 *
 *     DMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * @endcode
 */
void DMA_INTConfig(uint8_t DMA_ChannelNum, uint32_t DMA_INT, FunctionalState NewState);

/**
 * @brief Get the transfer complete interrupt status of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return The transfer complete interrupt status of the specified DMA channel.
 * @retval SET    The transfer complete interrupt status is set.
 * @retval RESET  The transfer complete interrupt status is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     ITStatus int_status = DMA_GetTransferINTStatus(DMA_CH_NUM0);
 * }
 * @endcode
 */
ITStatus DMA_GetTransferINTStatus(uint8_t DMA_ChannelNum);

/**
 * @brief Get the specified interrupt status of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] DMA_INT         Specifies the DMA interrupt status to get.
 *                            This parameter can be any combination of the following values. Refer to @ref DMA_INTERRUPTS.
 *                            - DMA_INT_TRANSFER: Transfer complete interrupt status.
 *                            - DMA_INT_BLOCK: Block transfer interrupt status.
 *                            - DMA_INT_ERROR: Transfer error interrupt status.
 *                            - DMA_INT_HALF_BLOCK: Half block transfer interrupt status.
 *                            - DMA_INT_BLOCK_COUNTER: Block counter interrupt status.
 *
 * @return The specified interrupt status of the specified DMA channel.
 * @retval SET    The specified interrupt status is set.
 * @retval RESET  The specified interrupt status is reset.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     ITStatus int_status = DMA_GetINTStatus(DMA_CH_NUM0, DMA_INT_TRANSFER);
 * }
 * @endcode
 */
ITStatus DMA_GetINTStatus(uint8_t DMA_ChannelNum, uint32_t DMA_INT);

/**
 * @brief Clear the specified interrupt pending bit of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] DMA_INT         Specifies the DMA interrupt source to be cleared.
 *                            This parameter can be any combination of the following values. Refer to @ref DMA_INTERRUPTS.
 *                            - DMA_INT_TRANSFER: Transfer complete interrupt source.
 *                            - DMA_INT_BLOCK: Block transfer interrupt source.
 *                            - DMA_INT_ERROR: Transfer error interrupt source.
 *                            - DMA_INT_HALF_BLOCK: Half block transfer interrupt source.
 *                            - DMA_INT_BLOCK_COUNTER: Block counter interrupt source.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     driver_dma_init();
 * }
 *
 * void UART_TX_DMA_Handler(void)
 * {
 *     DMA_ClearINTPendingBit(DMA_CH_NUM1, DMA_INT_TRANSFER);
 *     //Add user code here.
 * }
 * @endcode
 */
void DMA_ClearINTPendingBit(uint8_t DMA_ChannelNum, uint32_t DMA_INT);

/**
 * @brief Clear all interrupt pending bits of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_ClearAllTypeINT(DMA_CH_NUM2);
 * }
 * @endcode
 */
void DMA_ClearAllTypeINT(uint8_t DMA_ChannelNum);

/**
 * @brief Get the channel status of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return The channel status of the specified DMA channel.
 * @retval SET    The DMA channel is in use.
 * @retval RESET  The DMA channel is not in use.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     FlagStatus flag_status = DMA_GetChannelStatus(DMA_CH_NUM3);
 * }
 * @endcode
 */
FlagStatus DMA_GetChannelStatus(uint8_t DMA_ChannelNum);

/**
 * @brief Get the FIFO status of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 *
 * @return The FIFO status of the specified DMA channel.
 * @retval SET    The DMA FIFO is empty.
 * @retval RESET  The DMA FIFO is not empty.
 *
 * @note The SET state indicates the FIFO is empty, which is typically used to
 *            confirm that all data has been flushed after a suspend operation.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     FlagStatus flag_status = DMA_GetFIFOStatus(DMA_Channel0);
 * }
 * @endcode
 */
FlagStatus DMA_GetFIFOStatus(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Enable or disable to suspend transmission of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the suspend operation.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Suspend transmission of the specified DMA channel.
 *                          - DISABLE: Resume transmission of the specified DMA channel.
 *
 * @note To prevent data loss, it is necessary to check whether the FIFO data transmission is completed
 *            after suspend, by checking whether the DMA FIFO is empty.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SuspendCmd(DMA_Channel0, ENABLE);
 * }
 * @endcode
 */
void DMA_SuspendCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

/**
 * @brief Suspend transmission safely of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 *
 * @return The result of the safe suspend operation.
 * @retval true   Suspend DMA transmission successfully.
 * @retval false  Suspend DMA transmission failed.
 *
 * @note To prevent data loss, it is necessary to check whether the FIFO data transmission is completed
 *            after suspend, by checking whether the DMA FIFO is empty.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * uint8_t uart_rx_dma_ch_num = 0xa5;
 * #define UART_RX_DMA_CHANNEL_NUM   uart_rx_dma_ch_num
 * #define UART_RX_DMA_CHANNEL       DMA_CH_BASE(uart_rx_dma_ch_num)
 *
 * void dma_demo(void)
 * {
 *     DMA_SafeSuspend(UART_RX_DMA_CHANNEL);
 *     //Add user code here.
 * }
 * @endcode
 */
bool DMA_SafeSuspend(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Set the source address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] Address       Source address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     DMA_SetSourceAddress(DMA_Channel0, (uint32_t)data_buf);
 * }
 * @endcode
 */
void DMA_SetSourceAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address);

/**
 * @brief Set the destination address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] Address       Destination address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     DMA_SetDestinationAddress(DMA_Channel0, (uint32_t)data_buf);
 * }
 * @endcode
 */
void DMA_SetDestinationAddress(DMA_ChannelTypeDef *DMA_Channelx,
                               uint32_t Address);

/**
 * @brief Set the LLP structure address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] Address       LLP structure address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_LLIDef DMA_LLIStruct[4000];
 *     DMA_SetLLPAddress(DMA_Channel0, (uint32_t)DMA_LLIStruct);
 * }
 * @endcode
 */
void DMA_SetLLPAddress(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Address);

/**
 * @brief Set the transfer size of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] BufferSize    Specifies the transfer size, which is the number of single transactions in one block.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t data_buf_size = 4095;
 *     DMA_SetBufferSize(DMA_Channel0, data_buf_size);
 * }
 * @endcode
 */
void DMA_SetBufferSize(DMA_ChannelTypeDef *DMA_Channelx, uint32_t BufferSize);

/**
 * @brief Get the source transfer address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 *
 * @return Source transfer address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetSrcTransferAddress(DMA_Channel0);
 * }
 * @endcode
 */
uint32_t DMA_GetSrcTransferAddress(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Get the destination transfer address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 *
 * @return Destination transfer address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetDstTransferAddress(DMA_Channel0);
 * }
 * @endcode
 */
uint32_t DMA_GetDstTransferAddress(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Get current source address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Select the DMA peripheral. Refer to @ref DMA_Declaration.
 *
 * @return Current source address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetCurrSrcAddr(DMA_Channel0);
 * }
 * @endcode
 */
uint32_t DMA_GetCurrSrcAddr(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Get current destination address of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Select the DMA peripheral. Refer to @ref DMA_Declaration.
 *
 * @return Current destination address.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint32_t address = DMA_GetCurrDstAddr(DMA_Channel0);
 * }
 * @endcode
 */
uint32_t DMA_GetCurrDstAddr(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Get the transfer data length of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 *
 * @return DMA transfer data length.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint16_t data_len = DMA_GetTransferLen(DMA_Channel0);
 * }
 * @endcode
 */
uint16_t DMA_GetTransferLen(DMA_ChannelTypeDef *DMA_Channelx);

/**
 * @brief Update the LLP mode of the specified DMA channel in multi-block transfer.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] Mode          Specifies the DMA LLP mode. Refer to @ref DMA_MULTI_BLOCK_MODE.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetLLPMode(DMA_Channel0, LLI_TRANSFER);
 * }
 * @endcode
 */
void DMA_SetLLPMode(DMA_ChannelTypeDef *DMA_Channelx, uint32_t Mode);

/**
 * @brief Get the DMA Channelx of the specified DMA channel number.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return DMA_Channelx.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     uint8_t channel_num = DMA_CH_NUM0;
 *     DMA_ChannelTypeDef *DMA_Channelx = DMA_GetDMAChannelx(channel_num);
 * }
 * @endcode
 */
DMA_ChannelTypeDef *DMA_GetDMAChannelx(uint8_t DMA_ChannelNum);

/**
 * @brief Get the DMA IRQx of the specified DMA channel number.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return DMA_IRQx.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     uint8_t channel_num = DMA_CH_NUM0;
 *     IRQn_Type irqx = DMA_GetDMAIRQx(channel_num);
 * }
 * @endcode
 */
IRQn_Type DMA_GetDMAIRQx(uint8_t DMA_ChannelNum);

/**
 * @brief Get the DMA channel number of the specified DMA IRQx.
 *
 * @param[in] Irq  Specifies the DMA IRQx.
 *
 * @return DMA channel number.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void driver_dma_init(void)
 * {
 *     uint8_t dma_num;
 *     dma_num = DMA_GetDMANumByIRQx(DMA1_CH0_IRQn);
 * }
 * @endcode
 */
uint8_t DMA_GetDMANumByIRQx(IRQn_Type Irq);

#if (DMA_SUPPORT_SECURE_MODE == 1)
/**
 * @brief Enable or disable the secure function of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the DMA channel secure function.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Enable the secure function of the specified DMA channel.
 *                          - DISABLE: Disable the secure function of the specified DMA channel.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SecureCmd(DMA_Channel3, ENABLE);
 * }
 * @endcode
 */
void DMA_SecureCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);
#endif

#if (DMA_SUPPORT_OSW_OSR_CHANGE == 1)
/**
 * @brief Set the outstanding write count (OSW) of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] OswCount        Outstanding write count.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetOSW(DMA_CH_NUM0, 10);
 * }
 * @endcode
 */
void DMA_SetOSW(uint8_t DMA_ChannelNum, uint8_t OswCount);

/**
 * @brief Set the outstanding read count (OSR) of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] OsrCount        Outstanding read count.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetOSR(DMA_CH_NUM0, 10);
 * }
 * @endcode
 */
void DMA_SetOSR(uint8_t DMA_ChannelNum, uint8_t OsrCount);

/**
 * @brief Get the outstanding write count (OSW) of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return Outstanding write count.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint8_t osw_count = DMA_GetOSWCount(DMA_CH_NUM0);
 * }
 * @endcode
 */
uint8_t DMA_GetOSWCount(uint8_t DMA_ChannelNum);

/**
 * @brief Get the outstanding read count (OSR) of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 *
 * @return Outstanding read count.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     uint8_t osr_count = DMA_GetOSRCount(DMA_CH_NUM0);
 * }
 * @endcode
 */
uint8_t DMA_GetOSRCount(uint8_t DMA_ChannelNum);
#endif

#if (DMA_SUPPORT_CONTINUOUS_BLOCK_ADDRESS == 1)
/**
 * @brief Enable or disable the continuous source address function between single-block interrupts.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the continuous source address function.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Enable the continuous source address function.
 *                          - DISABLE: Disable the continuous source address function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_ContSarCmd(DMA_Channel0, ENABLE);
 * }
 * @endcode
 */
void DMA_ContSarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

/**
 * @brief Enable or disable the continuous destination address function between single-block interrupts.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the continuous destination address function.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Enable the continuous destination address function.
 *                          - DISABLE: Disable the continuous destination address function.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_ContDarCmd(DMA_Channel0, ENABLE);
 * }
 * @endcode
 */
void DMA_ContDarCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

#endif

#if (DMA_SUPPORT_BLOCK_COUNTER == 1)
/**
 * @brief Set the block counter of the specified DMA channel.
 *
 * @param[in] DMA_Channelx   Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] BlockCounter   Block counter value. The block counter is decremented by 1 after each block
 *                           transfer completes and saturates at 0.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_SetBlockCounter(DMA_Channel0, 10);
 * }
 * @endcode
 */
void DMA_SetBlockCounter(DMA_ChannelTypeDef *DMA_Channelx, uint32_t BlockCounter);

#endif

#if (DMA_SUPPORT_RAP_FUNCTION == 1)
/**
 * @brief Enable or disable the RAP mode of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the DMA RAP mode.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Enable the DMA RAP mode.
 *                          - DISABLE: Disable the DMA RAP mode.
 *
 * @return The result of the RAP mode command.
 * @retval true   RAP mode command success.
 * @retval false  RAP mode command failed.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     bool result = DMA_RAPModeCmd(DMA_Channel0, ENABLE);
 * }
 * @endcode
 */
bool DMA_RAPModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

#endif

#if (DMA_SUPPORT_AUTO_CLOCK == 1)
/**
 * @brief Enable or disable the clock auto mode of the specified DMA channel.
 *
 * @param[in] DMA_Channelx  Specifies the DMA channel. Refer to @ref DMA_DECLARATION.
 * @param[in] NewState      New state of the DMA clock auto mode.
 *                          This parameter can be one of the following values:
 *                          - ENABLE: Enable the DMA clock auto mode.
 *                          - DISABLE: Disable the DMA clock auto mode.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_ClockAutoModeCmd(DMA_Channel0, ENABLE);
 * }
 * @endcode
 */
void DMA_ClockAutoModeCmd(DMA_ChannelTypeDef *DMA_Channelx, FunctionalState NewState);

#endif

#if (DMA_SUPPORT_AUTO_SLOW_CONFIG == 1)
/**
 * @brief Configure the auto slow mode of the specified DMA channel.
 *
 * @param[in] DMA_ChannelNum  Specifies the DMA channel number. Refer to @ref DMA_CHANNEL_NUM.
 * @param[in] AutoSlowMode    Specifies the DMA auto slow mode. Refer to @ref DMAAutoSlow_TypeDef.
 *                            This parameter can be one of the following values:
 *                            - DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE: DMA not allow auto slow when DMA enable but in idle state.
 *                            - DMA_ALLOW_AUTO_SLOW_WHEN_ENABLE: DMA allow auto slow when DMA enable but in idle state.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void dma_demo(void)
 * {
 *     DMA_AutoSlowConfig(DMA_CH_NUM0, DMA_NOT_ALLOW_AUTO_SLOW_WHEN_ENABLE);
 * }
 * @endcode
 */
void DMA_AutoSlowConfig(uint8_t DMA_ChannelNum, DMAAutoSlow_TypeDef AutoSlowMode);
#endif
/** @} */ /* End of group DMA_Exported_Functions */

/** @} */ /* End of group DMA_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_DMA_H */
