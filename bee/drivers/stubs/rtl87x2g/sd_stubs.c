/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file sd_stubs.c
 * @brief Stub implementations for SDHC (rtl_sdhc.h) library functions.
 *        Used when building without binary blobs (CONFIG_BUILD_ONLY_NO_BLOBS).
 *        These symbols are normally provided by librtl87x2g_sd.a and are the
 *        ones the sdhc_bee driver links in.
 */

#include <stdint.h>
#include <rtl_sdhc.h>

/* SDHC per-controller semaphore handle, normally allocated by the blob. */
void *gSDHC0Sem;

/* Stub implementations for SDHC functions */
void ResetAll(SDHC_TypeDef *SDHCx)
{
	(void)SDHCx;
}

void InitClk(SDHC_TypeDef *SDHCx)
{
	(void)SDHCx;
}

uint32_t SDHC_SetClkOutFreq(SDHC_TypeDef *SDHCx, uint32_t Freq_kHz)
{
	(void)SDHCx;
	return Freq_kHz;
}

uint32_t SDHC_GetClkOutFreq_kHz(SDHC_TypeDef *SDHCx)
{
	(void)SDHCx;
	return 0;
}

void SDHC_SetHostDataWidth(SDHC_TypeDef *SDHCx, DataWidth_t Width)
{
	(void)SDHCx;
	(void)Width;
}

SDHCRes_t SDHC_SendNoDataCmd(SDHC_TypeDef *SDHCx, const CmdInfo_t *pCmdInfo,
			     void *pRspBuf)
{
	(void)SDHCx;
	(void)pCmdInfo;
	(void)pRspBuf;
	return SDHCRES_OK;
}

SDHCRes_t SDHC_SendCmdWithRxData(SDHC_TypeDef *SDHCx, const CmdInfo_t *pCmdInfo,
				 void *pRspBuf, const DataInfo_t *pDataInfo,
				 void *pRxDataBuf)
{
	(void)SDHCx;
	(void)pCmdInfo;
	(void)pRspBuf;
	(void)pDataInfo;
	(void)pRxDataBuf;
	return SDHCRES_OK;
}

SDHCRes_t SDHC_SendCmdWithTxData(SDHC_TypeDef *SDHCx, const CmdInfo_t *pCmdInfo,
				 void *pRspBuf, const DataInfo_t *pDataInfo,
				 const void *pDataToTx)
{
	(void)SDHCx;
	(void)pCmdInfo;
	(void)pRspBuf;
	(void)pDataInfo;
	(void)pDataToTx;
	return SDHCRES_OK;
}

SDHCRes_t SDHC_WaitData0Idle(SDHC_TypeDef *SDHCx, uint32_t Timeout_ms)
{
	(void)SDHCx;
	(void)Timeout_ms;
	return SDHCRES_OK;
}
