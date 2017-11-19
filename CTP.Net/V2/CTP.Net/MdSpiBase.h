#pragma once

#include <vcclr.h>
#include "Callbacks.h"
#include "ThostFtdcMdApi.h"
#include "CTPMDAdapter.h"

namespace Native
{
	class CMdSpiBase : public CThostFtdcMdSpi
	{

#ifdef __CTP_MA__
	public:
		// 回调函数
		Callback_OnFrontConnEvent p_OnFrontConnEvent;
		Callback_OnRspEvent p_OnRspEvent;
		Callback_OnRtnEvent p_OnRtnEvent;

		// 回调函数对应的delegate，必须保持一份对该deleage的引用，否则GC会自动回收该deleage并导致上面的回调函数失效
		gcroot<Internal_FrontEvent^> d_FrontConnEvent;
		gcroot<Internal_RspEvent^> d_RspEvent;
		gcroot<Internal_RtnEvent^> d_RtnEvent;
#else
	protected:
		gcroot<CTPMDAdapter^> m_pAdapter;
#endif
	};
};

