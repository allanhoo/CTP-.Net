/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20120420
/////////////////////////////////////////////////////////////////////////

#pragma once

#include <vcclr.h>
#include "util.h"
#include "Callbacks.h"
#include "ThostFtdcMdApi.h"
#include "CTPMDAdapter.h"

namespace Native
{
	/// 非托管类
	class CMdSpiBase : public CThostFtdcMdSpi
	{
	
#ifdef __CTP_MA__
	public:
		// 回调函数
		Callback_OnFrontConnected p_OnFrontConnected;
		Callback_OnFrontDisconnected p_OnFrontDisconnected;
		Callback_OnHeartBeatWarning p_OnHeartBeatWarning;
		Callback_OnRspUserLogin p_OnRspUserLogin;
		Callback_OnRspUserLogout p_OnRspUserLogout;
		Callback_OnRspError p_OnRspError;
		Callback_OnRspSubMarketData p_OnRspSubMarketData;
		Callback_OnRspUnSubMarketData p_OnRspUnSubMarketData;
		Callback_OnRtnDepthMarketData p_OnRtnDepthMarketData;

		// 回调函数对应的delegate，必须保持一份对该deleage的引用，否则GC会自动回收该deleage并导致上面的回调函数失效
		gcroot<Internal_FrontConnected^> d_FrontConnected;
		gcroot<Internal_FrontDisconnected^> d_FrontDisconnected;
		gcroot<Internal_HeartBeatWarning^> d_HeartBeatWarning;
		gcroot<Internal_RspUserLogin^> d_RspUserLogin;
		gcroot<Internal_RspUserLogout^> d_RspUserLogout;
		gcroot<Internal_RspError^> d_RspError;

		gcroot<Internal_RspSubMarketData^> d_RspSubMarketData;
		gcroot<Internal_RspUnSubMarketData^> d_RspUnSubMarketData;
		gcroot<Internal_RtnDepthMarketData^> d_RtnDepthMarketData;
#else
	protected:
		gcroot<CTPMDAdapter^> m_pAdapter;
#endif

	};
};