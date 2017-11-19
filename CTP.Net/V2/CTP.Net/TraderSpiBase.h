#pragma once

#include <vcclr.h>
#include "Callbacks.h"
#include "CTPTraderAdapter.h"

namespace Native
{
	/// 非托管类
	class CTraderSpiBase : public CThostFtdcTraderSpi
	{
#ifdef __CTP_MA__
		// 回调函数
	public:
		Callback_OnErrRtnEvent p_OnErrRtnEvent;
		Callback_OnFrontConnEvent p_OnFrontConnEvent;
		Callback_OnRspEvent p_OnRspEvent;
		Callback_OnRspQryEvent p_OnRspQryEvent;
		Callback_OnRtnEvent p_OnRtnEvent;

		// 回调函数对应的delegate，必须保持一份对该deleage的引用，否则GC会自动回收该deleage并导致上面的回调函数失效
		gcroot<Internal_ErrRtnEvent^> d_ErrRtnEvent;
		gcroot<Internal_FrontEvent^> d_FrontConnEvent;
		gcroot<Internal_RspEvent^> d_RspOthersEvent;
		gcroot<Internal_RspQryEvent^> d_RspQryEvent;
		gcroot<Internal_RtnEvent^> d_RtnEvent;
#else
	protected:
		gcroot<CTPTraderAdapter^> m_pAdapter;
#endif
	};
};