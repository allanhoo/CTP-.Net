#include "stdafx.h"
#include "TraderSpi.h"
#include "Struct.h"
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
	void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspAuthenticate, MNConv<ThostFtdcRspAuthenticateField^, CThostFtdcRspAuthenticateField>::N2M(pRspAuthenticateField), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///登录请求响应
	void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogin, MNConv<ThostFtdcRspUserLoginField^, CThostFtdcRspUserLoginField>::N2M(pRspUserLogin), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///登出请求响应
	void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogout, MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::N2M(pUserLogout), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///用户口令更新请求响应
	void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserPasswordUpdate, MNConv<ThostFtdcUserPasswordUpdateField^, CThostFtdcUserPasswordUpdateField>::N2M(pUserPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///资金账户口令更新请求响应
	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspTradingAccountPasswordUpdate, MNConv<ThostFtdcTradingAccountPasswordUpdateField^, CThostFtdcTradingAccountPasswordUpdateField>::N2M(pTradingAccountPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单录入请求响应
	void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspOrderInsert, MNConv<ThostFtdcInputOrderField^, CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///预埋单录入请求响应
	void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspParkedOrderInsert, MNConv<ThostFtdcParkedOrderField^, CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///预埋撤单录入请求响应
	void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspParkedOrderAction, MNConv<ThostFtdcParkedOrderActionField^, CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单操作请求响应
	void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspOrderAction, MNConv<ThostFtdcInputOrderActionField^, CThostFtdcInputOrderActionField>::N2M(pInputOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///投资者结算结果确认响应
	void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspSettlementInfoConfirm, MNConv<ThostFtdcSettlementInfoConfirmField^, CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///删除预埋单响应
	void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspRemoveParkedOrder, MNConv<ThostFtdcRemoveParkedOrderField^, CThostFtdcRemoveParkedOrderField>::N2M(pRemoveParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///删除预埋撤单响应
	void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspRemoveParkedOrderAction, MNConv<ThostFtdcRemoveParkedOrderActionField^, CThostFtdcRemoveParkedOrderActionField>::N2M(pRemoveParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	/////执行宣告录入请求响应
	//void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *p, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	//	m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspExecOrderInsert, MNConv<ThostFtdcInputExecOrderField^, CThostFtdcInputExecOrderField>::N2M(p), RspInfoField(pRspInfo), nRequestID, bIsLast));
	//};

	/////执行宣告操作请求响应
	//void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *p, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	//	m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspExecOrderAction, MNConv<ThostFtdcInputExecOrderActionField^, CThostFtdcInputExecOrderActionField>::N2M(p), RspInfoField(pRspInfo), nRequestID, bIsLast));
	//};

	/////询价录入请求响应
	//void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *p, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	//	m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspForQuoteInsert, MNConv<ThostFtdcInputForQuoteField^, CThostFtdcInputForQuoteField>::N2M(p), RspInfoField(pRspInfo), nRequestID, bIsLast));
	//};

	/////报价录入请求响应
	//void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField *p, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	//	m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspQuoteInsert, MNConv<ThostFtdcInputQuoteField^, CThostFtdcInputQuoteField>::N2M(p), RspInfoField(pRspInfo), nRequestID, bIsLast));
	//};

	/////报价操作请求响应
	//void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField *p, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
	//	m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspQuoteAction, MNConv<ThostFtdcInputQuoteActionField^, CThostFtdcInputQuoteActionField>::N2M(p), RspInfoField(pRspInfo), nRequestID, bIsLast));
	//};

	///请求查询报单响应
	void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryOrder, MNConv<ThostFtdcOrderField^, CThostFtdcOrderField>::N2M(pOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询成交响应
	void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTrade, MNConv<ThostFtdcTradeField^, CThostFtdcTradeField>::N2M(pTrade), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者持仓响应
	void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorPosition, MNConv<ThostFtdcInvestorPositionField^, CThostFtdcInvestorPositionField>::N2M(pInvestorPosition), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询资金账户响应
	void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTradingAccount, MNConv<ThostFtdcTradingAccountField^, CThostFtdcTradingAccountField>::N2M(pTradingAccount), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者响应
	void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestor, MNConv<ThostFtdcInvestorField^, CThostFtdcInvestorField>::N2M(pInvestor), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易编码响应
	void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTradingCode, MNConv<ThostFtdcTradingCodeField^, CThostFtdcTradingCodeField>::N2M(pTradingCode), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询合约保证金率响应
	void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInstrumentMarginRate, MNConv<ThostFtdcInstrumentMarginRateField^, CThostFtdcInstrumentMarginRateField>::N2M(pInstrumentMarginRate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询合约手续费率响应
	void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInstrumentCommissionRate, MNConv<ThostFtdcInstrumentCommissionRateField^, CThostFtdcInstrumentCommissionRateField>::N2M(pInstrumentCommissionRate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易所响应
	void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryExchange, MNConv<ThostFtdcExchangeField^, CThostFtdcExchangeField>::N2M(pExchange), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询产品响应
	void CTraderSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryProduct, MNConv<ThostFtdcProductField^, CThostFtdcProductField>::N2M(pProduct), RspInfoField(pRspInfo), nRequestID, bIsLast));
	}

	///请求查询合约响应
	void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInstrument, MNConv<ThostFtdcInstrumentField^, CThostFtdcInstrumentField>::N2M(pInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询行情响应
	void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryDepthMarketData, MNConv<ThostFtdcDepthMarketDataField^, CThostFtdcDepthMarketDataField>::N2M(pDepthMarketData), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者结算结果响应
	void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQrySettlementInfo, MNConv<ThostFtdcSettlementInfoField^, CThostFtdcSettlementInfoField>::N2M(pSettlementInfo), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询转帐银行响应
	void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTransferBank, MNConv<ThostFtdcTransferBankField^, CThostFtdcTransferBankField>::N2M(pTransferBank), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorPositionDetail, MNConv<ThostFtdcInvestorPositionDetailField^, CThostFtdcInvestorPositionDetailField>::N2M(pInvestorPositionDetail), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询客户通知响应
	void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryNotice, MNConv<ThostFtdcNoticeField^, CThostFtdcNoticeField>::N2M(pNotice), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询结算信息确认响应
	void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQrySettlementInfoConfirm, MNConv<ThostFtdcSettlementInfoConfirmField^, CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorPositionCombineDetail, MNConv<ThostFtdcInvestorPositionCombineDetailField^, CThostFtdcInvestorPositionCombineDetailField>::N2M(pInvestorPositionCombineDetail), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///查询保证金监管系统经纪公司资金账户密钥响应
	void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryCFMMCTradingAccountKey, MNConv<ThostFtdcCFMMCTradingAccountKeyField^, CThostFtdcCFMMCTradingAccountKeyField>::N2M(pCFMMCTradingAccountKey), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询仓单折抵信息响应
	void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryEWarrantOffset, MNConv<ThostFtdcEWarrantOffsetField^, CThostFtdcEWarrantOffsetField>::N2M(pEWarrantOffset), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询投资者品种/跨品种保证金响应
	void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryInvestorProductGroupMargin, MNConv<ThostFtdcInvestorProductGroupMarginField^, CThostFtdcInvestorProductGroupMarginField>::N2M(pInvestorProductGroupMargin), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易所保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryExchangeMarginRate, MNConv<ThostFtdcExchangeMarginRateField^, CThostFtdcExchangeMarginRateField>::N2M(pExchangeMarginRate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易所调整保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryExchangeMarginRateAdjust, MNConv<ThostFtdcExchangeMarginRateAdjustField^, CThostFtdcExchangeMarginRateAdjustField>::N2M(pExchangeMarginRateAdjust), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询汇率响应
	void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryExchangeRate, MNConv<ThostFtdcExchangeRateField^, CThostFtdcExchangeRateField>::N2M(pExchangeRate), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询二级代理操作员银期权限响应
	void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQrySecAgentACIDMap, MNConv<ThostFtdcSecAgentACIDMapField^, CThostFtdcSecAgentACIDMapField>::N2M(pSecAgentACIDMap), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询转帐流水响应
	void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTransferSerial, MNConv<ThostFtdcTransferSerialField^, CThostFtdcTransferSerialField>::N2M(pTransferSerial), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询银期签约关系响应
	void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryAccountregister, MNConv<ThostFtdcAccountregisterField^, CThostFtdcAccountregisterField>::N2M(pAccountregister), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///查询最大报单数量响应
	void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryMaxOrderVolume, MNConv<ThostFtdcQueryMaxOrderVolumeField^, CThostFtdcQueryMaxOrderVolumeField>::N2M(pQueryMaxOrderVolume), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///错误应答
	void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspError, nullptr, RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///报单通知
	void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnOrder, MNConv<ThostFtdcOrderField^, CThostFtdcOrderField>::N2M(pOrder)));
	};

	///成交通知
	void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnTrade, MNConv<ThostFtdcTradeField^, CThostFtdcTradeField>::N2M(pTrade)));
	};

	///报单录入错误回报
	void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnOrderInsert, MNConv<ThostFtdcInputOrderField^, CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo)));
	};

	///报单操作错误回报
	void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnOrderAction, MNConv<ThostFtdcOrderActionField^, CThostFtdcOrderActionField>::N2M(pOrderAction), RspInfoField(pRspInfo)));
	};

	///合约交易状态通知
	void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnInstrumentStatus, MNConv<ThostFtdcInstrumentStatusField^, CThostFtdcInstrumentStatusField>::N2M(pInstrumentStatus)));
	};

	///交易通知
	void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnTradingNotice, MNConv<ThostFtdcTradingNoticeInfoField^, CThostFtdcTradingNoticeInfoField>::N2M(pTradingNoticeInfo)));
	};

	///提示条件单校验错误
	void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnErrorConditionalOrder, MNConv<ThostFtdcErrorConditionalOrderField^, CThostFtdcErrorConditionalOrderField>::N2M(pErrorConditionalOrder)));
	};

	///请求查询签约银行响应
	void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryContractBank, MNConv<ThostFtdcContractBankField^, CThostFtdcContractBankField>::N2M(pContractBank), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询预埋单响应
	void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryParkedOrder, MNConv<ThostFtdcParkedOrderField^, CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询预埋撤单响应
	void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryParkedOrderAction, MNConv<ThostFtdcParkedOrderActionField^, CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询交易通知响应
	void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryTradingNotice, MNConv<ThostFtdcTradingNoticeField^, CThostFtdcTradingNoticeField>::N2M(pTradingNotice), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询经纪公司交易参数响应
	void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryBrokerTradingParams, MNConv<ThostFtdcBrokerTradingParamsField^, CThostFtdcBrokerTradingParamsField>::N2M(pBrokerTradingParams), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///请求查询经纪公司交易算法响应
	void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryBrokerTradingAlgos, MNConv<ThostFtdcBrokerTradingAlgosField^, CThostFtdcBrokerTradingAlgosField>::N2M(pBrokerTradingAlgos), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///银行发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFromBankToFutureByBank, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M(pRspTransfer)));
	};

	///银行发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFromFutureToBankByBank, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M(pRspTransfer)));
	};

	///银行发起冲正银行转期货通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromBankToFutureByBank, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///银行发起冲正期货转银行通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromFutureToBankByBank, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///期货发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFromBankToFutureByFuture, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M(pRspTransfer)));
	};

	///期货发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnFromFutureToBankByFuture, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M(pRspTransfer)));
	};

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromBankToFutureByFutureManual, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromFutureToBankByFutureManual, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///期货发起查询银行余额通知
	void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnQueryBankBalanceByFuture, MNConv<ThostFtdcNotifyQueryAccountField^, CThostFtdcNotifyQueryAccountField>::N2M(pNotifyQueryAccount)));
	};

	///期货发起银行资金转期货错误回报
	void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnBankToFutureByFuture, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo)));
	};

	///期货发起期货资金转银行错误回报
	void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnFutureToBankByFuture, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo)));
	};

	///系统运行时期货端手工发起冲正银行转期货错误回报
	void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnRepealBankToFutureByFutureManual, MNConv<ThostFtdcReqRepealField^, CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo)));
	};

	///系统运行时期货端手工发起冲正期货转银行错误回报
	void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnRepealFutureToBankByFutureManual, MNConv<ThostFtdcReqRepealField^, CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo)));
	};

	///期货发起查询银行余额错误回报
	void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnCtpErrRtnEvent(m_pAdapter, gcnew CtpErrRtnEventArgs(CtpEnumErrRtnType::ErrRtnQueryBankBalanceByFuture, MNConv<ThostFtdcReqQueryAccountField^, CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo)));
	};

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromBankToFutureByFuture, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnRepealFromFutureToBankByFuture, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M(pRspRepeal)));
	};

	///期货发起银行资金转期货应答
	void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspFromBankToFutureByFuture, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///期货发起期货资金转银行应答
	void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspEvent(m_pAdapter, gcnew CtpRspEventArgs(CtpEnumRspType::RspFromFutureToBankByFuture, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///期货发起查询银行余额应答
	void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnCtpRspQryEvent(m_pAdapter, gcnew CtpRspQryEventArgs(CtpEnumRspQryType::RspQryBankAccountMoneyByFuture, MNConv<ThostFtdcReqQueryAccountField^, CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo), nRequestID, bIsLast));
	};

	///银行发起银期开户通知
	void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnOpenAccountByBank, MNConv<ThostFtdcOpenAccountField^, CThostFtdcOpenAccountField>::N2M(pOpenAccount)));
	};

	///银行发起银期销户通知
	void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnCancelAccountByBank, MNConv<ThostFtdcCancelAccountField^, CThostFtdcCancelAccountField>::N2M(pCancelAccount)));
	};

	///银行发起变更银行账号通知
	void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
		m_pAdapter->OnCtpRtnEvent(m_pAdapter, gcnew CtpRtnEventArgs(CtpEnumRtnType::RtnChangeAccountByBank, MNConv<ThostFtdcChangeAccountField^, CThostFtdcChangeAccountField>::N2M(pChangeAccount)));
	};
}