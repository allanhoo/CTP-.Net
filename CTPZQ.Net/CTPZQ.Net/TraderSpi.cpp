#include "stdafx.h"
#include "TraderSpi.h"
#include "Delegates.h"
#include "Util.h"

namespace Native
{

	CTraderSpi::CTraderSpi(CTPTraderAdapter^ pAdapter) {
		m_pAdapter = pAdapter;
	};

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CTraderSpi::OnFrontConnected(){
		m_pAdapter->OnCtpFrontEvent(m_pAdapter, gcnew CtpFrontEventArgs(CtpEnumFrontType::FrontConnected, 0));
	};

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	void CTraderSpi::OnFrontDisconnected(int nReason){
		m_pAdapter->OnCtpFrontEvent(m_pAdapter, gcnew CtpFrontEventArgs(CtpEnumFrontType::FrontDisconnected, nReason));
	};

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void CTraderSpi::OnHeartBeatWarning(int nTimeLapse){
		//m_pAdapter->OnHeartBeatWarning(nTimeLapse);
	};

	///客户端认证响应
	void CTraderSpi::OnRspAuthenticate(CZQThostFtdcRspAuthenticateField *pRspAuthenticateField, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspAuthenticate, MNConv<ThostFtdcRspAuthenticateField^, CZQThostFtdcRspAuthenticateField>::N2M(pRspAuthenticateField), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///登录请求响应
	void CTraderSpi::OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogin, MNConv<ThostFtdcRspUserLoginField^, CZQThostFtdcRspUserLoginField>::N2M(pRspUserLogin), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///登出请求响应
	void CTraderSpi::OnRspUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogout, MNConv<ThostFtdcUserLogoutField^, CZQThostFtdcUserLogoutField>::N2M(pUserLogout), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///用户口令更新请求响应
	void CTraderSpi::OnRspUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserPasswordUpdate, MNConv<ThostFtdcUserPasswordUpdateField^, CZQThostFtdcUserPasswordUpdateField>::N2M(pUserPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///资金账户口令更新请求响应
	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CZQThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspTradingAccountPasswordUpdate, MNConv<ThostFtdcTradingAccountPasswordUpdateField^, CZQThostFtdcTradingAccountPasswordUpdateField>::N2M(pTradingAccountPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单录入请求响应
	void CTraderSpi::OnRspOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspOrderInsert, MNConv<ThostFtdcInputOrderField^, CZQThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单操作请求响应
	void CTraderSpi::OnRspOrderAction(CZQThostFtdcInputOrderActionField *pInputOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspOrderAction, MNConv<ThostFtdcInputOrderActionField^, CZQThostFtdcInputOrderActionField>::N2M(pInputOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询报单响应
	void CTraderSpi::OnRspQryOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryOrder, MNConv<ThostFtdcOrderField^, CZQThostFtdcOrderField>::N2M(pOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询成交响应
	void CTraderSpi::OnRspQryTrade(CZQThostFtdcTradeField *pTrade, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTrade, MNConv<ThostFtdcTradeField^, CZQThostFtdcTradeField>::N2M(pTrade), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者持仓响应
	void CTraderSpi::OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField *pInvestorPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorPosition, MNConv<ThostFtdcInvestorPositionField^, CZQThostFtdcInvestorPositionField>::N2M(pInvestorPosition), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询资金账户响应
	void CTraderSpi::OnRspQryTradingAccount(CZQThostFtdcTradingAccountField *pTradingAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTradingAccount, MNConv<ThostFtdcTradingAccountField^, CZQThostFtdcTradingAccountField>::N2M(pTradingAccount), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者响应
	void CTraderSpi::OnRspQryInvestor(CZQThostFtdcInvestorField *pInvestor, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestor, MNConv<ThostFtdcInvestorField^, CZQThostFtdcInvestorField>::N2M(pInvestor), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易编码响应
	void CTraderSpi::OnRspQryTradingCode(CZQThostFtdcTradingCodeField *pTradingCode, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTradingCode, MNConv<ThostFtdcTradingCodeField^, CZQThostFtdcTradingCodeField>::N2M(pTradingCode), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询合约手续费率响应
	void CTraderSpi::OnRspQryInstrumentCommissionRate(CZQThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInstrumentCommissionRate, MNConv<ThostFtdcInstrumentCommissionRateField^, CZQThostFtdcInstrumentCommissionRateField>::N2M(pInstrumentCommissionRate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易所响应
	void CTraderSpi::OnRspQryExchange(CZQThostFtdcExchangeField *pExchange, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryExchange, MNConv<ThostFtdcExchangeField^, CZQThostFtdcExchangeField>::N2M(pExchange), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询合约响应
	void CTraderSpi::OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInstrument, MNConv<ThostFtdcInstrumentField^, CZQThostFtdcInstrumentField>::N2M(pInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询行情响应
	void CTraderSpi::OnRspQryDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryDepthMarketData, MNConv<ThostFtdcDepthMarketDataField^, CZQThostFtdcDepthMarketDataField>::N2M(pDepthMarketData), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionDetail(CZQThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorPositionDetail, MNConv<ThostFtdcInvestorPositionDetailField^, CZQThostFtdcInvestorPositionDetailField>::N2M(pInvestorPositionDetail), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	void CTraderSpi::OnRspQryBondInterest(CZQThostFtdcBondInterestField *pBondInterest, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryBondInterest, MNConv<ThostFtdcBondInterestField^, CZQThostFtdcBondInterestField>::N2M(pBondInterest), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	void CTraderSpi::OnRspQrySubscribingSharesOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQrySubscribingSharesOrder, MNConv<ThostFtdcOrderField^, CZQThostFtdcOrderField>::N2M(pOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///错误应答
	void CTraderSpi::OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspError, nullptr, RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单通知
	void CTraderSpi::OnRtnOrder(CZQThostFtdcOrderField *pOrder) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnOrder, MNConv<ThostFtdcOrderField^, CZQThostFtdcOrderField>::N2M(pOrder)));
	};

	///成交通知
	void CTraderSpi::OnRtnTrade(CZQThostFtdcTradeField *pTrade) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnTrade, MNConv<ThostFtdcTradeField^, CZQThostFtdcTradeField>::N2M(pTrade)));
	};

	///报单录入错误回报
	void CTraderSpi::OnErrRtnOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnOrderInsert, MNConv<ThostFtdcInputOrderField^, CZQThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo)));
	};

	///报单操作错误回报
	void CTraderSpi::OnErrRtnOrderAction(CZQThostFtdcOrderActionField *pOrderAction, CZQThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnOrderAction, MNConv<ThostFtdcOrderActionField^, CZQThostFtdcOrderActionField>::N2M(pOrderAction), RspInfoField(pRspInfo)));
	};

	///合约交易状态通知
	void CTraderSpi::OnRtnInstrumentStatus(CZQThostFtdcInstrumentStatusField *pInstrumentStatus) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnInstrumentStatus, MNConv<ThostFtdcInstrumentStatusField^, CZQThostFtdcInstrumentStatusField>::N2M(pInstrumentStatus)));
	};

	///投资者新股申购额度通知
	void CTraderSpi::OnRtnInvestorSubscribingSharesQuota(CZQThostFtdcInvestorSubscribingSharesQuotaField *pInvestorSubscribingSharesQuota) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnInvestorSubscribingSharesQuota, MNConv<ThostFtdcInvestorSubscribingSharesQuotaField^, CZQThostFtdcInvestorSubscribingSharesQuotaField>::N2M(pInvestorSubscribingSharesQuota)));
	};

	///资金转入CTP通知
	void CTraderSpi::OnRtnFundIntoCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFundIntoCTPAccount, MNConv<ThostFtdcFundIOCTPAccountField^, CZQThostFtdcFundIOCTPAccountField>::N2M(pFundIOCTPAccount)));
	};

	///资金转出CTP请求应答
	void CTraderSpi::OnRspFundOutCTPAccount(CZQThostFtdcRspFundIOCTPAccountField *pRspFundIOCTPAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspFundOutCTPAccount, MNConv<ThostFtdcRspFundIOCTPAccountField^, CZQThostFtdcRspFundIOCTPAccountField>::N2M(pRspFundIOCTPAccount), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///资金转出CTP通知
	void CTraderSpi::OnRtnFundOutCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFundOutCTPAccount, MNConv<ThostFtdcFundIOCTPAccountField^, CZQThostFtdcFundIOCTPAccountField>::N2M(pFundIOCTPAccount)));
	};

	///资金转入转出CTP查询应答
	void CTraderSpi::OnRspQryFundIOCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryFundIOCTPAccount, MNConv<ThostFtdcFundIOCTPAccountField^, CZQThostFtdcFundIOCTPAccountField>::N2M(pFundIOCTPAccount), RspInfoField(pRspInfo), nRequestID, bIsLast));
	
	};


}// end of namespace