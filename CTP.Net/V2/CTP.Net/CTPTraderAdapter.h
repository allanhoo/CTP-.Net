#pragma once

#include "Delegates.h"
#include "CTPTraderAdapterBase.h"

namespace CTP
{
	/// <summary>
	/// 托管类,TraderAPI Adapter
	/// </summary>
	public ref class CTPTraderAdapter : public CTPTraderAdapterBase
	{
	public:
		/// <summary>
		///创建CTPTraderAdapter
		///存贮订阅信息文件的目录，默认为当前目录
		/// </summary>
		CTPTraderAdapter();
		/// <summary>
		///创建CTPTraderAdapter
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录</param>
		CTPTraderAdapter(String^ pszFlowPath);
		/// <summary>
		///创建CTPTraderAdapter, 为兼容性保留此函数, bIsUsingUdp参数将被忽略
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录</param>
		CTPTraderAdapter(String^ pszFlowPath, bool bIsUsingUdp);
		// events
	public:
		/// <summary>
		/// 处理所有的OnFront****回调事件，共2
		/// </summary>
		event CtpFrontEventHandler^ OnCtpFrontEvent {
			void add(CtpFrontEventHandler^ handler) {
				CtpFront_delegate += handler;
			}
			void remove(CtpFrontEventHandler^ handler) {
				CtpFront_delegate -= handler;
			}
			void raise(Object^ sender, CtpFrontEventArgs^ e) {
				if (CtpFront_delegate)
					CtpFront_delegate(sender, e);
			}
		}

		/// <summary>
		/// 处理所有的OnErrRtn****回调事件，共7
		/// </summary>
		event CtpErrRtnEventHandler^ OnCtpErrRtnEvent{
			void add(CtpErrRtnEventHandler^ handler) { CtpErrRtn_delegate += handler; }
			void remove(CtpErrRtnEventHandler^ handler) { CtpErrRtn_delegate -= handler; }
			void raise(Object^ sender, CtpErrRtnEventArgs^ args) {
				if (CtpErrRtn_delegate) CtpErrRtn_delegate(sender, args);
			}
		}

		/// <summary>
		/// 处理所有的OnRtn****回调事件,共19
		/// </summary>
		event CtpRtnEventHandler^ OnCtpRtnEvent{
			void add(CtpRtnEventHandler^ handler) { CtpRtn_delegate += handler; }
			void remove(CtpRtnEventHandler^ handler) { CtpRtn_delegate -= handler; }
			void raise(Object^ sender, CtpRtnEventArgs^ e) {
				if (CtpRtn_delegate) CtpRtn_delegate(sender, e);
			}
		}

		/// <summary>
		/// 处理所有的OnRspQry****回调事件,共35
		/// </summary>
		event CtpRspQryEventHandler^ OnCtpRspQryEvent{
			void add(CtpRspQryEventHandler^ handler) { CtpRspQry_delegate += handler; }
			void remove(CtpRspQryEventHandler^ handler) { CtpRspQry_delegate -= handler; }
			void raise(Object^ sender, CtpRspQryEventArgs^ e) {
				if (CtpRspQry_delegate) CtpRspQry_delegate(sender, e);
			}
		}

		/// <summary>
		/// 处理除了OnRspQry****之外，其他OnRsp****回调函数，共15，TraderAPI不包括RspSubMarketData和RspUnSubMarketData
		/// </summary>
		event CtpRspEventHandler^ OnCtpRspEvent{
			void add(CtpRspEventHandler^ handler) { CtpRsp_delegate += handler; }
			void remove(CtpRspEventHandler^ handler) { CtpRsp_delegate -= handler; }
			void raise(Object^ sender, CtpRspEventArgs^ e) {
				if (CtpRsp_delegate) CtpRsp_delegate(sender, e);
			}
		}

		// delegates
	private:
		CtpErrRtnEventHandler^ CtpErrRtn_delegate;
		CtpFrontEventHandler^ CtpFront_delegate;
		CtpRspEventHandler^ CtpRsp_delegate;
		CtpRspQryEventHandler^ CtpRspQry_delegate;
		CtpRtnEventHandler^ CtpRtn_delegate;

#ifdef __CTP_MA__
		// callbacks for MA (Multiple AppDomain)
	private:
		void cbk_OnErrRtnEvent(CtpEnumErrRtnType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo);
		void cbk_OnFrontEvent(CtpEnumFrontType EventType, int nReason);
		void cbk_OnRspEvent(CtpEnumRspType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRspQryEvent(CtpEnumRspQryType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRtnEvent(CtpEnumRtnType EventType, void *pParam);
	protected:
		// 将所有回调函数地址传递给SPI
		virtual void RegisterCallbacks() override;
#endif
	};

};