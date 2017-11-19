/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ ==> .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20120420
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "CTPMDAdapterBase.h"
#include "Delegates.h"


namespace  Native{
	class CMdSpi;
};


namespace CTP {

	/// <summary>
	/// 托管类,Marcket Data Adapter
	/// </summary>
	public ref class CTPMDAdapter : public CTPMDAdapterBase
	{
	public:
		/// <summary>
		///创建CTPMDAdapter
		///存贮订阅信息文件的目录，默认为当前目录
		/// </summary>
		CTPMDAdapter();
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp);
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast);
		// Events
	public:
		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		event FrontConnected^ OnFrontConnected {
			void add(FrontConnected^ handler ) {
				OnFrontConnected_delegate += handler;
			}
			void remove(FrontConnected^ handler) {
				OnFrontConnected_delegate -= handler;
			}
			void raise() {
				if(OnFrontConnected_delegate)
					OnFrontConnected_delegate();
			}
		}

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// 错误原因
		/// 0x1001 网络读失败
		/// 0x1002 网络写失败
		/// 0x2001 接收心跳超时
		/// 0x2002 发送心跳失败
		/// 0x2003 收到错误报文
		/// </summary>
		event FrontDisconnected^ OnFrontDisconnected {
			void add(FrontDisconnected^ handler ) {
				OnFrontDisconnected_delegate += handler;
			}
			void remove(FrontDisconnected^ handler) {
				OnFrontDisconnected_delegate -= handler;
			}
			void raise(int nReason) {
				if(OnFrontDisconnected_delegate)
					OnFrontDisconnected_delegate(nReason);
			}
		}

		/// <summary>
		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		/// </summary>
		event HeartBeatWarning^ OnHeartBeatWarning {
			void add(HeartBeatWarning^ handler ) {
				OnHeartBeatWarning_delegate += handler;
			}
			void remove(HeartBeatWarning^ handler) {
				OnHeartBeatWarning_delegate -= handler;
			}
			void raise(int nTimeLapse) {
				if(OnHeartBeatWarning_delegate)
					OnHeartBeatWarning_delegate(nTimeLapse);
			}
		}

		/// <summary>
		/// 登录请求响应
		/// </summary>
		event RspUserLogin^ OnRspUserLogin {
			void add(RspUserLogin^ handler ) {
				OnRspUserLogin_delegate += handler;
			}
			void remove(RspUserLogin^ handler) {
				OnRspUserLogin_delegate -= handler;
			}
			void raise(ThostFtdcRspUserLoginField^ pRspUserLogin, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast) { 
				if(OnRspUserLogin_delegate)
					OnRspUserLogin_delegate(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
			}
		}

		/// <summary>
		/// 登出请求响应
		/// </summary>
		event RspUserLogout^ OnRspUserLogout {
			void add(RspUserLogout^ handler ) {
				OnRspUserLogout_delegate += handler;
			}
			void remove(RspUserLogout^ handler) {
				OnRspUserLogout_delegate -= handler;
			}
			void raise(ThostFtdcUserLogoutField^ pUserLogout, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast) { 
				if(OnRspUserLogout_delegate)
					OnRspUserLogout_delegate(pUserLogout, pRspInfo, nRequestID, bIsLast);
			}
		}

		/// <summary>
		/// 错误应答
		/// </summary>
		event RspError^ OnRspError {
			void add(RspError^ handler ) {
				OnRspError_delegate += handler;
			}
			void remove(RspError^ handler) {
				OnRspError_delegate -= handler;
			}
			void raise(ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast) { 
				if(OnRspError_delegate)
					OnRspError_delegate(pRspInfo, nRequestID, bIsLast);
			}
		}

		/// <summary>
		/// 订阅行情应答
		/// </summary>
		event RspSubMarketData^ OnRspSubMarketData {
			void add(RspSubMarketData^ handler ) {
				OnRspSubMarketData_delegate += handler;
			}
			void remove(RspSubMarketData^ handler) {
				OnRspSubMarketData_delegate -= handler;
			}
			void raise(ThostFtdcSpecificInstrumentField^ pSpecificInstrument, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast) { 
				if(OnRspSubMarketData_delegate)
					OnRspSubMarketData_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
			}
		}
		/// <summary>
		/// 取消订阅行情应答
		/// </summary>
		event RspUnSubMarketData^ OnRspUnSubMarketData {
			void add(RspUnSubMarketData^ handler ) {
				OnRspUnSubMarketData_delegate += handler;
			}
			void remove(RspUnSubMarketData^ handler) {
				OnRspUnSubMarketData_delegate -= handler;
			}
			void raise(ThostFtdcSpecificInstrumentField^ pSpecificInstrument, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast) { 
				if(OnRspUnSubMarketData_delegate)
					OnRspUnSubMarketData_delegate(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
			}
		}
		/// <summary>
		/// 深度行情通知
		/// </summary>
		event RtnDepthMarketData^ OnRtnDepthMarketData {
			void add(RtnDepthMarketData^ handler ) {
				OnRtnDepthMarketData_delegate += handler;
			}
			void remove(RtnDepthMarketData^ handler) {
				OnRtnDepthMarketData_delegate -= handler;
			}
			void raise(ThostFtdcDepthMarketDataField^ pDepthMarketData) { 
				if(OnRtnDepthMarketData_delegate)
					OnRtnDepthMarketData_delegate(pDepthMarketData);
			}
		}

		// delegates
	private:
		FrontConnected^ OnFrontConnected_delegate;
		FrontDisconnected^ OnFrontDisconnected_delegate;
		HeartBeatWarning^ OnHeartBeatWarning_delegate;
		RspUserLogin^  OnRspUserLogin_delegate;
		RspUserLogout^ OnRspUserLogout_delegate;
		RspError^ OnRspError_delegate;
		RspSubMarketData^ OnRspSubMarketData_delegate;
		RspUnSubMarketData^ OnRspUnSubMarketData_delegate;
		RtnDepthMarketData^ OnRtnDepthMarketData_delegate;

#ifdef __CTP_MA__
		// Callbacks for MA (Multiple AppDomain)
	private:
		void cbk_OnFrontConnected();
		void cbk_OnFrontDisconnected(int nReason);
		void cbk_OnHeartBeatWarning(int nTimeLapse);
		void cbk_OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cbk_OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	protected:
		// 将所有回调函数地址传递给SPI
		virtual void RegisterCallbacks() override;	
#endif

	};
}