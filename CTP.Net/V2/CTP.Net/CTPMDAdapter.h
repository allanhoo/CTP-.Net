#pragma once

#include "Delegates.h"
#include "CTPMDAdapterBase.h"

namespace CTP
{
	/// <summary>
	/// 托管类,Marcket Data Adapter
	/// </summary>
	public ref class CTPMDAdapter : public CTPMDAdapterBase
	{
	public:
		/// <summary>
		///创建CTPMDAdapterBase
		///存贮订阅信息文件的目录，默认为当前目录
		/// </summary>
		CTPMDAdapter();
		/// <summary>
		///创建CTPMDAdapterBase
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp">是否使用UDP协议</param>
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp);
		/// <summary>
		///创建CTPMDAdapterBase
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp">是否使用UDP协议</param>
		/// <param name="bIsMulticast">20130402版增加此参数</param>
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast);

		// Events
	public:
		/// <summary>
		/// 处理所有的OnFront****回调事件，共2
		/// </summary>
		event CtpFrontEventHandler^ OnCtpFrontEvent {
			void add(CtpFrontEventHandler^ handler) {
				CtpFrontConnEvent_delegate += handler;
			}
			void remove(CtpFrontEventHandler^ handler) {
				CtpFrontConnEvent_delegate -= handler;
			}
			void raise(Object^ sender, CtpFrontEventArgs^ e) {
				if (CtpFrontConnEvent_delegate)
					CtpFrontConnEvent_delegate(sender, e);
			}
		}
		/// <summary>
		/// 处理所有的OnRsp****回调事件，共4
		/// </summary>
		event CtpRspEventHandler^ OnCtpRspEvent {
			void add(CtpRspEventHandler^ handler) {
				CtpRspEvent_delegate += handler;
			}
			void remove(CtpRspEventHandler^ handler) {
				CtpRspEvent_delegate -= handler;
			}
			void raise(Object^ sender, CtpRspEventArgs^ e) {
				if (CtpRspEvent_delegate)
					CtpRspEvent_delegate(sender, e);
			}
		}

		/// <summary>
		/// 处理所有的OnRtn****回调事件，行情接口仅RtnDepthMarketData
		/// </summary>
		event CtpRtnEventHandler^ OnCtpRtnEvent{
			void add(CtpRtnEventHandler^ handler) { CtpRtn_delegate += handler; }
			void remove(CtpRtnEventHandler^ handler) { CtpRtn_delegate -= handler; }
			void raise(Object^ sender, CtpRtnEventArgs^ e) {
				if (CtpRtn_delegate) CtpRtn_delegate(sender, e);
			}
		}

		// delegates
	private:
		CtpFrontEventHandler^ CtpFrontConnEvent_delegate;
		CtpRspEventHandler^ CtpRspEvent_delegate;
		CtpRtnEventHandler^ CtpRtn_delegate;

#ifdef __CTP_MA__
		// Callbacks for MA (Multiple AppDomain)
	private:
		void cbk_OnFrontEvent(CtpEnumFrontType EventType, int nReason);
		void cbk_OnRspEvent(CtpEnumRspType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRtnEvent(CtpEnumRtnType EventType, void *pParam);
	protected:
		// 将所有回调函数地址传递给SPI
		virtual void RegisterCallbacks() override;
#endif

	};

};

