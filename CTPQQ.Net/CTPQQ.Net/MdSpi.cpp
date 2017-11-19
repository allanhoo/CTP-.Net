#include "stdafx.h"
#include "MdSpi.h"

#include "Util.h"
#include "Delegates.h"


namespace Native
{
	CMdSpi::CMdSpi(CTPMDAdapter^ pAdapter) {
		m_pAdapter = pAdapter;
	};

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CMdSpi::OnFrontConnected(){
		m_pAdapter->OnCtpFrontEvent(m_pAdapter, gcnew CtpFrontEventArgs(CtpEnumFrontType::FrontConnected, 0));
	};

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	void CMdSpi::OnFrontDisconnected(int nReason){
		m_pAdapter->OnCtpFrontEvent(m_pAdapter, gcnew CtpFrontEventArgs(CtpEnumFrontType::FrontDisconnected, nReason));
	};

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void CMdSpi::OnHeartBeatWarning(int nTimeLapse){
		//m_pAdapter->OnHeartBeatWarning(nTimeLapse);
	};


	///登录请求响应
	void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		ThostFtdcRspUserLoginField^ field = MNConv<ThostFtdcRspUserLoginField^, CThostFtdcRspUserLoginField>::N2M(pRspUserLogin);
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogin, field, RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///登出请求响应
	void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogout, MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::N2M(pUserLogout), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///错误应答
	void CMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspError, nullptr, RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///订阅行情应答
	void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspSubMarketData, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M(pSpecificInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///取消订阅行情应答
	void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUnSubMarketData, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M(pSpecificInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///订阅询价应答
	void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspSubForQuoteRsp, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M(pSpecificInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///取消订阅询价应答
	void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUnSubForQuoteRsp, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M(pSpecificInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};


	///深度行情通知
	void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData){
		ThostFtdcDepthMarketDataField^ field = MNConv<ThostFtdcDepthMarketDataField^, CThostFtdcDepthMarketDataField>::N2M(pDepthMarketData);
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnDepthMarketData, field));
	};

	///询价通知
	void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {
		ThostFtdcForQuoteRspField^ field = MNConv<ThostFtdcForQuoteRspField^, CThostFtdcForQuoteRspField>::N2M(pForQuoteRsp);
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnForQuoteRsp, field));
	};

}