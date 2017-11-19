/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20121027
/////////////////////////////////////////////////////////////////////////
#pragma once

// CTP MA only
#ifdef __CTP_MA__

#include "Delegates.h"

namespace Native
{
	// common 
	typedef void(__stdcall *Callback_OnFrontConnEvent)(CTP::CtpEnumFrontType EventType, int nReason);

	// marketdata
	//typedef void(__stdcall *Callback_OnRtnDepthMarketData)(CThostFtdcDepthMarketDataField *pDepthMarketData);

	// trader
	typedef void(__stdcall *Callback_OnErrRtnEvent)(CTP::CtpEnumErrRtnType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo);
	typedef void(__stdcall *Callback_OnRtnEvent)(CTP::CtpEnumRtnType EventType, void *pParam);
	typedef void(__stdcall *Callback_OnRspQryEvent)(CTP::CtpEnumRspQryType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	typedef void(__stdcall *Callback_OnRspEvent)(CTP::CtpEnumRspType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

};
#endif

