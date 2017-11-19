/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20121027
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "TraderSpi.h"
#include "CTPTraderAdapter.h"
#include "Callbacks.h"


namespace Native
{
	CTraderSpi::CTraderSpi(CTPTraderAdapter^ pAdapter) {
#ifndef __CTP_MA__
		m_pAdapter = pAdapter;
#endif
	};

#ifdef __CTP_MA__
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CTraderSpi::OnFrontConnected(){
		p_OnFrontConnected();
	};

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	void CTraderSpi::OnFrontDisconnected(int nReason){
		p_OnFrontDisconnected(nReason);
	};

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void CTraderSpi::OnHeartBeatWarning(int nTimeLapse){
		p_OnHeartBeatWarning(nTimeLapse);
	};

	///客户端认证响应
	void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspAuthenticate(pRspAuthenticateField, pRspInfo, nRequestID, bIsLast);
	};

	///登录请求响应
	void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};

	///登出请求响应
	void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
	};

	///用户口令更新请求响应
	void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};

	///资金账户口令更新请求响应
	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};

	///报单录入请求响应
	void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspOrderInsert(pInputOrder, pRspInfo, nRequestID, bIsLast);
	};

	///预埋单录入请求响应
	void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspParkedOrderInsert(pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};

	///预埋撤单录入请求响应
	void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspParkedOrderAction(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};

	///报单操作请求响应
	void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspOrderAction(pInputOrderAction, pRspInfo, nRequestID, bIsLast);
	};

	///查询最大报单数量响应
	void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQueryMaxOrderVolume(pQueryMaxOrderVolume, pRspInfo, nRequestID, bIsLast);
	};

	///投资者结算结果确认响应
	void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspSettlementInfoConfirm(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};

	///删除预埋单响应
	void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspRemoveParkedOrder(pRemoveParkedOrder, pRspInfo, nRequestID, bIsLast);
	};

	///删除预埋撤单响应
	void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspRemoveParkedOrderAction(pRemoveParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询报单响应
	void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询成交响应
	void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者持仓响应
	void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInvestorPosition(pInvestorPosition, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询资金账户响应
	void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTradingAccount(pTradingAccount, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者响应
	void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInvestor(pInvestor, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询交易编码响应
	void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTradingCode(pTradingCode, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询合约保证金率响应
	void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInstrumentMarginRate(pInstrumentMarginRate, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询合约手续费率响应
	void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInstrumentCommissionRate(pInstrumentCommissionRate, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询交易所响应
	void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryExchange(pExchange, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询产品响应
	void CTraderSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		p_OnRspQryProduct(pProduct, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询合约响应
	void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInstrument(pInstrument, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询行情响应
	void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryDepthMarketData(pDepthMarketData, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者结算结果响应
	void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQrySettlementInfo(pSettlementInfo, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询转帐银行响应
	void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTransferBank(pTransferBank, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInvestorPositionDetail(pInvestorPositionDetail, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询客户通知响应
	void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryNotice(pNotice, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询结算信息确认响应
	void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQrySettlementInfoConfirm(pSettlementInfoConfirm, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInvestorPositionCombineDetail(pInvestorPositionCombineDetail, pRspInfo, nRequestID, bIsLast);
	};

	///查询保证金监管系统经纪公司资金账户密钥响应
	void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryCFMMCTradingAccountKey(pCFMMCTradingAccountKey, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询仓单折抵信息响应
	void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryEWarrantOffset(pEWarrantOffset, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询投资者品种/跨品种保证金响应
	void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryInvestorProductGroupMargin(pInvestorProductGroupMargin, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询交易所保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryExchangeMarginRate(pExchangeMarginRate, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询交易所调整保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryExchangeMarginRateAdjust(pExchangeMarginRateAdjust, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询汇率响应
	void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryExchangeRate(pExchangeRate, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询二级代理操作员银期权限响应
	void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQrySecAgentACIDMap(pSecAgentACIDMap, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询转帐流水响应
	void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTransferSerial(pTransferSerial, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询银期签约关系响应
	void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryAccountregister(pAccountregister, pRspInfo, nRequestID, bIsLast);
	};

	///错误应答
	void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspError(pRspInfo, nRequestID, bIsLast);
	};

	///报单通知
	void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder) {
		p_OnRtnOrder(pOrder);
	};

	///成交通知
	void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade) {
		p_OnRtnTrade(pTrade);
	};

	///报单录入错误回报
	void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnOrderInsert(pInputOrder, pRspInfo);
	};

	///报单操作错误回报
	void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnOrderAction(pOrderAction, pRspInfo);
	};

	///合约交易状态通知
	void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
		p_OnRtnInstrumentStatus(pInstrumentStatus);
	};

	///交易通知
	void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
		p_OnRtnTradingNotice(pTradingNoticeInfo);
	};

	///提示条件单校验错误
	void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
		p_OnRtnErrorConditionalOrder(pErrorConditionalOrder);
	};

	///保证金监控中心用户令牌
	void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
		p_OnRtnCFMMCTradingAccountToken(pCFMMCTradingAccountToken);
	}

	///请求查询签约银行响应
	void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryContractBank(pContractBank, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询预埋单响应
	void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryParkedOrder(pParkedOrder, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询预埋撤单响应
	void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryParkedOrderAction(pParkedOrderAction, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询交易通知响应
	void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryTradingNotice(pTradingNotice, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询经纪公司交易参数响应
	void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryBrokerTradingParams(pBrokerTradingParams, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询经纪公司交易算法响应
	void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQryBrokerTradingAlgos(pBrokerTradingAlgos, pRspInfo, nRequestID, bIsLast);
	};

	///请求查询监控中心用户令牌
	void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		p_OnRspQueryCFMMCTradingAccountToken(pQueryCFMMCTradingAccountToken, pRspInfo, nRequestID, bIsLast);
	};

	///银行发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
		p_OnRtnFromBankToFutureByBank(pRspTransfer);
	};

	///银行发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
		p_OnRtnFromFutureToBankByBank(pRspTransfer);
	};

	///银行发起冲正银行转期货通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromBankToFutureByBank(pRspRepeal);
	};

	///银行发起冲正期货转银行通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromFutureToBankByBank(pRspRepeal);
	};

	///期货发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		p_OnRtnFromBankToFutureByFuture(pRspTransfer);
	};

	///期货发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		p_OnRtnFromFutureToBankByFuture(pRspTransfer);
	};

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromBankToFutureByFutureManual(pRspRepeal);
	};

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromFutureToBankByFutureManual(pRspRepeal);
	};

	///期货发起查询银行余额通知
	void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
		p_OnRtnQueryBankBalanceByFuture(pNotifyQueryAccount);
	};

	///期货发起银行资金转期货错误回报
	void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnBankToFutureByFuture(pReqTransfer, pRspInfo);
	};

	///期货发起期货资金转银行错误回报
	void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnFutureToBankByFuture(pReqTransfer, pRspInfo);
	};

	///系统运行时期货端手工发起冲正银行转期货错误回报
	void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnRepealBankToFutureByFutureManual(pReqRepeal, pRspInfo);
	};

	///系统运行时期货端手工发起冲正期货转银行错误回报
	void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnRepealFutureToBankByFutureManual(pReqRepeal, pRspInfo);
	};

	///期货发起查询银行余额错误回报
	void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
		p_OnErrRtnQueryBankBalanceByFuture(pReqQueryAccount, pRspInfo);
	};

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromBankToFutureByFuture(pRspRepeal);
	};

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		p_OnRtnRepealFromFutureToBankByFuture(pRspRepeal);
	};

	///期货发起银行资金转期货应答
	void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspFromBankToFutureByFuture(pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};

	///期货发起期货资金转银行应答
	void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspFromFutureToBankByFuture(pReqTransfer, pRspInfo, nRequestID, bIsLast);
	};

	///期货发起查询银行余额应答
	void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		p_OnRspQueryBankAccountMoneyByFuture(pReqQueryAccount, pRspInfo, nRequestID, bIsLast);
	};

	///银行发起银期开户通知
	void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
		p_OnRtnOpenAccountByBank(pOpenAccount);
	};

	///银行发起银期销户通知
	void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
		p_OnRtnCancelAccountByBank(pCancelAccount);
	};

	///银行发起变更银行账号通知
	void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
		p_OnRtnChangeAccountByBank(pChangeAccount);
	};
#else

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
	void CTraderSpi::OnFrontConnected(){
		m_pAdapter->OnFrontConnected();
	};

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
	///@param nReason 错误原因
	///        0x1001 网络读失败
	///        0x1002 网络写失败
	///        0x2001 接收心跳超时
	///        0x2002 发送心跳失败
	///        0x2003 收到错误报文
	void CTraderSpi::OnFrontDisconnected(int nReason){
		m_pAdapter->OnFrontDisconnected(nReason);
	};

	///心跳超时警告。当长时间未收到报文时，该方法被调用。
	///@param nTimeLapse 距离上次接收报文的时间
	void CTraderSpi::OnHeartBeatWarning(int nTimeLapse){
		m_pAdapter->OnHeartBeatWarning(nTimeLapse);
	};

	///客户端认证响应
	void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspAuthenticate(MNConv<ThostFtdcRspAuthenticateField^,CThostFtdcRspAuthenticateField>::N2M(pRspAuthenticateField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///登录请求响应
	void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {

		m_pAdapter->OnRspUserLogin(MNConv<ThostFtdcRspUserLoginField^,CThostFtdcRspUserLoginField>::N2M(pRspUserLogin), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///登出请求响应
	void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspUserLogout(MNConv<ThostFtdcUserLogoutField^,CThostFtdcUserLogoutField>::N2M(pUserLogout), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///用户口令更新请求响应
	void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspUserPasswordUpdate(MNConv<ThostFtdcUserPasswordUpdateField^,CThostFtdcUserPasswordUpdateField>::N2M(pUserPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///资金账户口令更新请求响应
	void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspTradingAccountPasswordUpdate(MNConv<ThostFtdcTradingAccountPasswordUpdateField^,CThostFtdcTradingAccountPasswordUpdateField>::N2M(pTradingAccountPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///报单录入请求响应
	void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspOrderInsert(MNConv<ThostFtdcInputOrderField^,CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///预埋单录入请求响应
	void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspParkedOrderInsert(MNConv<ThostFtdcParkedOrderField^,CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///预埋撤单录入请求响应
	void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspParkedOrderAction(MNConv<ThostFtdcParkedOrderActionField^,CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///报单操作请求响应
	void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspOrderAction(MNConv<ThostFtdcInputOrderActionField^,CThostFtdcInputOrderActionField>::N2M(pInputOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///查询最大报单数量响应
	void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQueryMaxOrderVolume(MNConv<ThostFtdcQueryMaxOrderVolumeField^,CThostFtdcQueryMaxOrderVolumeField>::N2M(pQueryMaxOrderVolume), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///投资者结算结果确认响应
	void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspSettlementInfoConfirm(MNConv<ThostFtdcSettlementInfoConfirmField^,CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///删除预埋单响应
	void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspRemoveParkedOrder(MNConv<ThostFtdcRemoveParkedOrderField^,CThostFtdcRemoveParkedOrderField>::N2M(pRemoveParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///删除预埋撤单响应
	void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspRemoveParkedOrderAction(MNConv<ThostFtdcRemoveParkedOrderActionField^,CThostFtdcRemoveParkedOrderActionField>::N2M(pRemoveParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询报单响应
	void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryOrder(MNConv<ThostFtdcOrderField^,CThostFtdcOrderField>::N2M(pOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询成交响应
	void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTrade(MNConv<ThostFtdcTradeField^,CThostFtdcTradeField>::N2M(pTrade), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者持仓响应
	void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInvestorPosition(MNConv<ThostFtdcInvestorPositionField^,CThostFtdcInvestorPositionField>::N2M(pInvestorPosition), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询资金账户响应
	void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTradingAccount(MNConv<ThostFtdcTradingAccountField^,CThostFtdcTradingAccountField>::N2M(pTradingAccount), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者响应
	void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInvestor(MNConv<ThostFtdcInvestorField^,CThostFtdcInvestorField>::N2M(pInvestor), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询交易编码响应
	void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTradingCode(MNConv<ThostFtdcTradingCodeField^,CThostFtdcTradingCodeField>::N2M(pTradingCode), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询合约保证金率响应
	void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInstrumentMarginRate(MNConv<ThostFtdcInstrumentMarginRateField^,CThostFtdcInstrumentMarginRateField>::N2M(pInstrumentMarginRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询合约手续费率响应
	void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInstrumentCommissionRate(MNConv<ThostFtdcInstrumentCommissionRateField^,CThostFtdcInstrumentCommissionRateField>::N2M(pInstrumentCommissionRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询交易所响应
	void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryExchange(MNConv<ThostFtdcExchangeField^,CThostFtdcExchangeField>::N2M(pExchange), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询产品响应
	void CTraderSpi::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryProduct(MNConv<ThostFtdcProductField^, CThostFtdcProductField>::N2M(pProduct), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	///请求查询合约响应
	void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInstrument(MNConv<ThostFtdcInstrumentField^,CThostFtdcInstrumentField>::N2M(pInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询行情响应
	void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryDepthMarketData(MNConv<ThostFtdcDepthMarketDataField^,CThostFtdcDepthMarketDataField>::N2M(pDepthMarketData), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者结算结果响应
	void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQrySettlementInfo(MNConv<ThostFtdcSettlementInfoField^,CThostFtdcSettlementInfoField>::N2M(pSettlementInfo), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询转帐银行响应
	void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTransferBank(MNConv<ThostFtdcTransferBankField^,CThostFtdcTransferBankField>::N2M(pTransferBank), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInvestorPositionDetail(MNConv<ThostFtdcInvestorPositionDetailField^,CThostFtdcInvestorPositionDetailField>::N2M(pInvestorPositionDetail), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询客户通知响应
	void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryNotice(MNConv<ThostFtdcNoticeField^,CThostFtdcNoticeField>::N2M(pNotice), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询结算信息确认响应
	void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQrySettlementInfoConfirm(MNConv<ThostFtdcSettlementInfoConfirmField^,CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者持仓明细响应
	void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInvestorPositionCombineDetail(MNConv<ThostFtdcInvestorPositionCombineDetailField^,CThostFtdcInvestorPositionCombineDetailField>::N2M(pInvestorPositionCombineDetail), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///查询保证金监管系统经纪公司资金账户密钥响应
	void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryCFMMCTradingAccountKey(MNConv<ThostFtdcCFMMCTradingAccountKeyField^,CThostFtdcCFMMCTradingAccountKeyField>::N2M(pCFMMCTradingAccountKey), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询仓单折抵信息响应
	void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryEWarrantOffset(MNConv<ThostFtdcEWarrantOffsetField^,CThostFtdcEWarrantOffsetField>::N2M(pEWarrantOffset), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询投资者品种/跨品种保证金响应
	void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryInvestorProductGroupMargin(MNConv<ThostFtdcInvestorProductGroupMarginField^, CThostFtdcInvestorProductGroupMarginField>::N2M(pField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};
	///请求查询交易所保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryExchangeMarginRate(MNConv<ThostFtdcExchangeMarginRateField^, CThostFtdcExchangeMarginRateField>::N2M(pField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};
	///请求查询交易所调整保证金率响应
	void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryExchangeMarginRateAdjust(MNConv<ThostFtdcExchangeMarginRateAdjustField^, CThostFtdcExchangeMarginRateAdjustField>::N2M(pField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};
	///请求查询汇率响应
	void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryExchangeRate(MNConv<ThostFtdcExchangeRateField^, CThostFtdcExchangeRateField>::N2M(pField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};
	///请求查询二级代理操作员银期权限响应
	void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQrySecAgentACIDMap(MNConv<ThostFtdcSecAgentACIDMapField^, CThostFtdcSecAgentACIDMapField>::N2M(pField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询转帐流水响应
	void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTransferSerial(MNConv<ThostFtdcTransferSerialField^,CThostFtdcTransferSerialField>::N2M(pTransferSerial), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询银期签约关系响应
	void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryAccountregister(MNConv<ThostFtdcAccountregisterField^,CThostFtdcAccountregisterField>::N2M(pAccountregister), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///错误应答
	void CTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspError(RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///报单通知
	void CTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder) {
		m_pAdapter->OnRtnOrder(MNConv<ThostFtdcOrderField^,CThostFtdcOrderField>::N2M(pOrder));
	};

	///成交通知
	void CTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade) {
		m_pAdapter->OnRtnTrade(MNConv<ThostFtdcTradeField^,CThostFtdcTradeField>::N2M(pTrade));
	};

	///报单录入错误回报
	void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnOrderInsert(MNConv<ThostFtdcInputOrderField^,CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo));
	};

	///报单操作错误回报
	void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnOrderAction(MNConv<ThostFtdcOrderActionField^,CThostFtdcOrderActionField>::N2M(pOrderAction), RspInfoField(pRspInfo));
	};

	///合约交易状态通知
	void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
		m_pAdapter->OnRtnInstrumentStatus(MNConv<ThostFtdcInstrumentStatusField^,CThostFtdcInstrumentStatusField>::N2M(pInstrumentStatus));
	};

	///交易通知
	void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
		m_pAdapter->OnRtnTradingNotice(MNConv<ThostFtdcTradingNoticeInfoField^,CThostFtdcTradingNoticeInfoField>::N2M(pTradingNoticeInfo));
	};

	///提示条件单校验错误
	void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
		m_pAdapter->OnRtnErrorConditionalOrder(MNConv<ThostFtdcErrorConditionalOrderField^,CThostFtdcErrorConditionalOrderField>::N2M(pErrorConditionalOrder));
	};

	///保证金监控中心用户令牌
	void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
		m_pAdapter->OnRtnCFMMCTradingAccountToken(MNConv<ThostFtdcCFMMCTradingAccountTokenField^, CThostFtdcCFMMCTradingAccountTokenField>::N2M(pCFMMCTradingAccountToken));
	}

	///请求查询签约银行响应
	void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryContractBank(MNConv<ThostFtdcContractBankField^,CThostFtdcContractBankField>::N2M(pContractBank), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询预埋单响应
	void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryParkedOrder(MNConv<ThostFtdcParkedOrderField^,CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询预埋撤单响应
	void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryParkedOrderAction(MNConv<ThostFtdcParkedOrderActionField^,CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询交易通知响应
	void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryTradingNotice(MNConv<ThostFtdcTradingNoticeField^,CThostFtdcTradingNoticeField>::N2M(pTradingNotice), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询经纪公司交易参数响应
	void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryBrokerTradingParams(MNConv<ThostFtdcBrokerTradingParamsField^,CThostFtdcBrokerTradingParamsField>::N2M(pBrokerTradingParams), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询经纪公司交易算法响应
	void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQryBrokerTradingAlgos(MNConv<ThostFtdcBrokerTradingAlgosField^,CThostFtdcBrokerTradingAlgosField>::N2M(pBrokerTradingAlgos), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///请求查询监控中心用户令牌
	void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		m_pAdapter->OnRspQueryCFMMCTradingAccountToken(MNConv<ThostFtdcQueryCFMMCTradingAccountTokenField^, CThostFtdcQueryCFMMCTradingAccountTokenField>::N2M(pQueryCFMMCTradingAccountToken), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}

	///银行发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnRtnFromBankToFutureByBank(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	};

	///银行发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnRtnFromFutureToBankByBank(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	};

	///银行发起冲正银行转期货通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromBankToFutureByBank(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///银行发起冲正期货转银行通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromFutureToBankByBank(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///期货发起银行资金转期货通知
	void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnRtnFromBankToFutureByFuture(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	};

	///期货发起期货资金转银行通知
	void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		m_pAdapter->OnRtnFromFutureToBankByFuture(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	};

	///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromBankToFutureByFutureManual(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromFutureToBankByFutureManual(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///期货发起查询银行余额通知
	void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
		m_pAdapter->OnRtnQueryBankBalanceByFuture(MNConv<ThostFtdcNotifyQueryAccountField^,CThostFtdcNotifyQueryAccountField>::N2M(pNotifyQueryAccount));
	};

	///期货发起银行资金转期货错误回报
	void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnBankToFutureByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo));
	};

	///期货发起期货资金转银行错误回报
	void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnFutureToBankByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo));
	};

	///系统运行时期货端手工发起冲正银行转期货错误回报
	void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnRepealBankToFutureByFutureManual(MNConv<ThostFtdcReqRepealField^,CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo));
	};

	///系统运行时期货端手工发起冲正期货转银行错误回报
	void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnRepealFutureToBankByFutureManual(MNConv<ThostFtdcReqRepealField^,CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo));
	};

	///期货发起查询银行余额错误回报
	void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
		m_pAdapter->OnErrRtnQueryBankBalanceByFuture(MNConv<ThostFtdcReqQueryAccountField^,CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo));
	};

	///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromBankToFutureByFuture(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		m_pAdapter->OnRtnRepealFromFutureToBankByFuture(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	};

	///期货发起银行资金转期货应答
	void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspFromBankToFutureByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///期货发起期货资金转银行应答
	void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspFromFutureToBankByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///期货发起查询银行余额应答
	void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		m_pAdapter->OnRspQueryBankAccountMoneyByFuture(MNConv<ThostFtdcReqQueryAccountField^,CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo), nRequestID, bIsLast);
	};

	///银行发起银期开户通知
	void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
		m_pAdapter->OnRtnOpenAccountByBank(MNConv<ThostFtdcOpenAccountField^,CThostFtdcOpenAccountField>::N2M(pOpenAccount));
	};

	///银行发起银期销户通知
	void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
		m_pAdapter->OnRtnCancelAccountByBank(MNConv<ThostFtdcCancelAccountField^,CThostFtdcCancelAccountField>::N2M(pCancelAccount));
	};

	///银行发起变更银行账号通知
	void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
		m_pAdapter->OnRtnChangeAccountByBank(MNConv<ThostFtdcChangeAccountField^,CThostFtdcChangeAccountField>::N2M(pChangeAccount));
	};
#endif

};