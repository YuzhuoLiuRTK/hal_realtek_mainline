/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file can_stubs.c
 * @brief Stub implementations for CAN (rtl_can.h) library functions.
 *        Used when building without binary blobs (CONFIG_BUILD_ONLY_NO_BLOBS).
 */

#include <stdbool.h>
#include <stdint.h>
#include <rtl_can.h>

/* Stub implementations for CAN functions */
void CAN_DeInit(CAN_TypeDef *CANx)
{
	(void)CANx;
}

void CAN_Init(CAN_TypeDef *CANx, CAN_InitTypeDef *CAN_InitStruct)
{
	(void)CANx;
	(void)CAN_InitStruct;
}

void CAN_StructInit(CAN_InitTypeDef *CAN_InitStruct)
{
	(void)CAN_InitStruct;
}

void CAN_Cmd(CAN_TypeDef *CANx, FunctionalState NewState)
{
	(void)CANx;
	(void)NewState;
}

void CAN_INTConfig(CAN_TypeDef *CANx, uint32_t CAN_INT, FunctionalState newState)
{
	(void)CANx;
	(void)CAN_INT;
	(void)newState;
}

#if (CAN_SUPPORT_INT_MSK_STS == 1)
void CAN_MaskINTConfig(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG,
		       FunctionalState NewState)
{
	(void)CANx;
	(void)CAN_INT_FLAG;
	(void)NewState;
}
#endif

ITStatus CAN_GetINTRawStatus(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG)
{
	(void)CANx;
	(void)CAN_INT_FLAG;
	return 0;
}

ITStatus CAN_GetINTStatus(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG)
{
	(void)CANx;
	(void)CAN_INT_FLAG;
	return 0;
}

void CAN_ClearINTPendingBit(CAN_TypeDef *CANx, uint32_t CAN_INT_FLAG)
{
	(void)CANx;
	(void)CAN_INT_FLAG;
}

FlagStatus CAN_GetErrorStatus(CAN_TypeDef *CANx, uint32_t CAN_ERR_STAT)
{
	(void)CANx;
	(void)CAN_ERR_STAT;
	return 0;
}

void CAN_CLearErrorStatus(CAN_TypeDef *CANx, uint32_t CAN_ERR_STAT)
{
	(void)CANx;
	(void)CAN_ERR_STAT;
}

CANError_TypeDef CAN_SetMsgBufTxMode(CAN_TypeDef *CANx,
				     CANTxFrame_TypeDef *p_tx_frame_params,
				     const uint8_t *p_frame_data,
				     uint8_t data_len)
{
	(void)CANx;
	(void)p_tx_frame_params;
	(void)p_frame_data;
	(void)data_len;
	return CAN_RAM_STATE_ERR;
}

CANError_TypeDef CAN_SetMsgBufRxMode(CAN_TypeDef *CANx,
				     CANRxFrame_TypeDef *p_rx_frame_params)
{
	(void)CANx;
	(void)p_rx_frame_params;
	return CAN_RAM_STATE_ERR;
}

CANError_TypeDef CAN_GetMsgBufInfo(CAN_TypeDef *CANx, uint8_t msg_buf_id,
				   CANMsgBufInfo_TypeDef *p_mb_info)
{
	(void)CANx;
	(void)msg_buf_id;
	(void)p_mb_info;
	return CAN_RAM_STATE_ERR;
}

CANError_TypeDef CAN_GetRamData(CAN_TypeDef *CANx, uint8_t data_len,
				uint8_t *p_data)
{
	(void)CANx;
	(void)data_len;
	(void)p_data;
	return CAN_RAM_STATE_ERR;
}

CANDataFrameSel_TypeDef CAN_CheckFrameType(uint8_t rtr_bit, uint8_t ide_bit)
{
	(void)rtr_bit;
	(void)ide_bit;
	return CAN_INVALID_DATA_FRAME;
}

void CAN_MBTxINTConfig(CAN_TypeDef *CANx, uint8_t message_buffer_index,
		       FunctionalState newState)
{
	(void)CANx;
	(void)message_buffer_index;
	(void)newState;
}

void CAN_MBRxINTConfig(CAN_TypeDef *CANx, uint8_t message_buffer_index,
		       FunctionalState newState)
{
	(void)CANx;
	(void)message_buffer_index;
	(void)newState;
}

void CAN_GetFifoStatus(CAN_TypeDef *CANx, CANFifoStatus_TypeDef *CAN_FifoStatus)
{
	(void)CANx;
	(void)CAN_FifoStatus;
}

void CAN_TxTriggerConfig(CAN_TypeDef *CANx, FunctionalState newState,
			 uint16_t trigger_timestamp_begin,
			 uint16_t close_offset)
{
	(void)CANx;
	(void)newState;
	(void)trigger_timestamp_begin;
	(void)close_offset;
}

uint32_t CAN_GetBusState(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

uint32_t CAN_GetRamState(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

FlagStatus CAN_GetMBnTxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

void CAN_ClearMBnTxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
}

FlagStatus CAN_GetMBnTxErrorFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

void CAN_ClearMBnTxErrorFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
}

FlagStatus CAN_GetMBnStatusTxFinishFlag(CAN_TypeDef *CANx,
					uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

FlagStatus CAN_GetMBnStatusTxReqFlag(CAN_TypeDef *CANx,
				     uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

FlagStatus CAN_GetMBnRxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

void CAN_ClearMBnRxDoneFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
}

FlagStatus CAN_GetMBnStatusRxValidFlag(CAN_TypeDef *CANx,
				       uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

FlagStatus CAN_GetMBnStatusRxReadyFlag(CAN_TypeDef *CANx,
				       uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

void CAN_TimeStampConfig(CAN_TypeDef *CANx, FunctionalState newState)
{
	(void)CANx;
	(void)newState;
}

uint16_t CAN_GetTimeStampCount(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

uint32_t CAN_GetRxDMAMsize(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

FlagStatus CAN_GetMBnRxDMAEnFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index)
{
	(void)CANx;
	(void)message_buffer_index;
	return 0;
}

void CAN_SetMBnRxDMAEnFlag(CAN_TypeDef *CANx, uint8_t message_buffer_index,
			   FunctionalState newState)
{
	(void)CANx;
	(void)message_buffer_index;
	(void)newState;
}

void CAN_SetClockDiv(CAN_TypeDef *CANx, CANClockDiv_TypeDef div)
{
	(void)CANx;
	(void)div;
}

bool CAN_GetClock(CAN_TypeDef *CANx, CANClockSrc_TypeDef *ClockSrc,
		  CANClockDiv_TypeDef *ClockDiv)
{
	(void)CANx;
	(void)ClockSrc;
	(void)ClockDiv;
	return false;
}

void CAN_SetTestMode(CAN_TypeDef *CANx, uint8_t CAN_TestModeSel)
{
	(void)CANx;
	(void)CAN_TestModeSel;
}

void CAN_AutoReTxCmd(CAN_TypeDef *CANx, FunctionalState NewState)
{
	(void)CANx;
	(void)NewState;
}

void CAN_SetTiming(CAN_TypeDef *CANx, CAN_0x0C_TYPE_TypeDef *CAN_BitTiming)
{
	(void)CANx;
	(void)CAN_BitTiming;
}

FlagStatus CAN_GetErrorPassiveStatus(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

FlagStatus CAN_GetErrorWarningStatus(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

int CAN_GetTxErrorCnt(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

int CAN_GetRxErrorCnt(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

void CAN_ClockAutoModeCmd(CAN_TypeDef *CANx, FunctionalState Newstate)
{
	(void)CANx;
	(void)Newstate;
}

#if (CAN_SUPPORT_SLEEP_MODE == 1)
FlagStatus CAN_CheckSleepStatus(CAN_TypeDef *CANx)
{
	(void)CANx;
	return 0;
}

void CAN_LowPowerClkCmd(CAN_TypeDef *CANx, FunctionalState newState,
			CANLowPowerClkDIV_TypeDef div)
{
	(void)CANx;
	(void)newState;
	(void)div;
}

void CAN_SetWakeUpPinFltFunction(CAN_TypeDef *CANx, FunctionalState newState,
				 uint8_t flt_length)
{
	(void)CANx;
	(void)newState;
	(void)flt_length;
}

void CAN_RequestToSleepMode(CAN_TypeDef *CANx)
{
	(void)CANx;
}

void CAN_ManualWakeup(CAN_TypeDef *CANx)
{
	(void)CANx;
}
#endif /* CAN_SUPPORT_SLEEP_MODE */
