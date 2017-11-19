
#include "StdAfx.h"
#include "TraderSpi.h"
#include "CTPTraderAdapter.h"


using namespace Native;

namespace CTP
{
	CTPTraderAdapter::CTPTraderAdapter()
		: CTPTraderAdapterBase("")
	{
	}
	CTPTraderAdapter::CTPTraderAdapter(String^ pszFlowPath)
		: CTPTraderAdapterBase(pszFlowPath)
	{
	}
	CTPTraderAdapter::CTPTraderAdapter(String^ pszFlowPath, bool bIsUsingUdp)
		: CTPTraderAdapterBase(pszFlowPath)
	{
	}

#ifdef __CTP_MA__

	//------------------------------------ Callbacks ------------------------------------

	void CTPTraderAdapter::cbk_OnFrontConnected(){
		this->OnFrontConnected();
	}
	void CTPTraderAdapter::cbk_OnFrontDisconnected(int nReason){
		this->OnFrontDisconnected(nReason);
	}
	void CTPTraderAdapter::cbk_OnHeartBeatWarning(int nTimeLapse){
		this->OnHeartBeatWarning(nTimeLapse);
	}
	void CTPTraderAdapter::cbk_OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspAuthenticate(MNConv<ThostFtdcRspAuthenticateField^,CThostFtdcRspAuthenticateField>::N2M(pRspAuthenticateField), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspUserLogin(MNConv<ThostFtdcRspUserLoginField^,CThostFtdcRspUserLoginField>::N2M(pRspUserLogin), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspUserLogout(MNConv<ThostFtdcUserLogoutField^,CThostFtdcUserLogoutField>::N2M(pUserLogout), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspUserPasswordUpdate(MNConv<ThostFtdcUserPasswordUpdateField^,CThostFtdcUserPasswordUpdateField>::N2M(pUserPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspTradingAccountPasswordUpdate(MNConv<ThostFtdcTradingAccountPasswordUpdateField^,CThostFtdcTradingAccountPasswordUpdateField>::N2M(pTradingAccountPasswordUpdate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspOrderInsert(MNConv<ThostFtdcInputOrderField^,CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspParkedOrderInsert(MNConv<ThostFtdcParkedOrderField^,CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspParkedOrderAction(MNConv<ThostFtdcParkedOrderActionField^,CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspOrderAction(MNConv<ThostFtdcInputOrderActionField^,CThostFtdcInputOrderActionField>::N2M(pInputOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQueryMaxOrderVolume(MNConv<ThostFtdcQueryMaxOrderVolumeField^,CThostFtdcQueryMaxOrderVolumeField>::N2M(pQueryMaxOrderVolume), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspSettlementInfoConfirm(MNConv<ThostFtdcSettlementInfoConfirmField^,CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspRemoveParkedOrder(MNConv<ThostFtdcRemoveParkedOrderField^,CThostFtdcRemoveParkedOrderField>::N2M(pRemoveParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspRemoveParkedOrderAction(MNConv<ThostFtdcRemoveParkedOrderActionField^,CThostFtdcRemoveParkedOrderActionField>::N2M(pRemoveParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryOrder(MNConv<ThostFtdcOrderField^,CThostFtdcOrderField>::N2M(pOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTrade(MNConv<ThostFtdcTradeField^,CThostFtdcTradeField>::N2M(pTrade), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInvestorPosition(MNConv<ThostFtdcInvestorPositionField^,CThostFtdcInvestorPositionField>::N2M(pInvestorPosition), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTradingAccount(MNConv<ThostFtdcTradingAccountField^,CThostFtdcTradingAccountField>::N2M(pTradingAccount), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInvestor(MNConv<ThostFtdcInvestorField^,CThostFtdcInvestorField>::N2M(pInvestor), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTradingCode(MNConv<ThostFtdcTradingCodeField^,CThostFtdcTradingCodeField>::N2M(pTradingCode), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInstrumentMarginRate(MNConv<ThostFtdcInstrumentMarginRateField^,CThostFtdcInstrumentMarginRateField>::N2M(pInstrumentMarginRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInstrumentCommissionRate(MNConv<ThostFtdcInstrumentCommissionRateField^,CThostFtdcInstrumentCommissionRateField>::N2M(pInstrumentCommissionRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryExchange(MNConv<ThostFtdcExchangeField^,CThostFtdcExchangeField>::N2M(pExchange), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryProduct(MNConv<ThostFtdcProductField^, CThostFtdcProductField>::N2M(pProduct), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInstrument(MNConv<ThostFtdcInstrumentField^,CThostFtdcInstrumentField>::N2M(pInstrument), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryDepthMarketData(MNConv<ThostFtdcDepthMarketDataField^,CThostFtdcDepthMarketDataField>::N2M(pDepthMarketData), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQrySettlementInfo(MNConv<ThostFtdcSettlementInfoField^,CThostFtdcSettlementInfoField>::N2M(pSettlementInfo), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTransferBank(MNConv<ThostFtdcTransferBankField^,CThostFtdcTransferBankField>::N2M(pTransferBank), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInvestorPositionDetail(MNConv<ThostFtdcInvestorPositionDetailField^,CThostFtdcInvestorPositionDetailField>::N2M(pInvestorPositionDetail), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryNotice(MNConv<ThostFtdcNoticeField^,CThostFtdcNoticeField>::N2M(pNotice), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQrySettlementInfoConfirm(MNConv<ThostFtdcSettlementInfoConfirmField^,CThostFtdcSettlementInfoConfirmField>::N2M(pSettlementInfoConfirm), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryInvestorPositionCombineDetail(MNConv<ThostFtdcInvestorPositionCombineDetailField^,CThostFtdcInvestorPositionCombineDetailField>::N2M(pInvestorPositionCombineDetail), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryCFMMCTradingAccountKey(MNConv<ThostFtdcCFMMCTradingAccountKeyField^,CThostFtdcCFMMCTradingAccountKeyField>::N2M(pCFMMCTradingAccountKey), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryEWarrantOffset(MNConv<ThostFtdcEWarrantOffsetField^,CThostFtdcEWarrantOffsetField>::N2M(pEWarrantOffset), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		this->OnRspQryInvestorProductGroupMargin(MNConv<ThostFtdcInvestorProductGroupMarginField^, CThostFtdcInvestorProductGroupMarginField>::N2M(pInvestorProductGroupMargin), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		this->OnRspQryExchangeMarginRate(MNConv<ThostFtdcExchangeMarginRateField^, CThostFtdcExchangeMarginRateField>::N2M(pExchangeMarginRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		this->OnRspQryExchangeMarginRateAdjust(MNConv<ThostFtdcExchangeMarginRateAdjustField^, CThostFtdcExchangeMarginRateAdjustField>::N2M(pExchangeMarginRateAdjust), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		this->OnRspQryExchangeRate(MNConv<ThostFtdcExchangeRateField^, CThostFtdcExchangeRateField>::N2M(pExchangeRate), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		this->OnRspQrySecAgentACIDMap(MNConv<ThostFtdcSecAgentACIDMapField^, CThostFtdcSecAgentACIDMapField>::N2M(pSecAgentACIDMap), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTransferSerial(MNConv<ThostFtdcTransferSerialField^,CThostFtdcTransferSerialField>::N2M(pTransferSerial), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryAccountregister(MNConv<ThostFtdcAccountregisterField^,CThostFtdcAccountregisterField>::N2M(pAccountregister), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspError(RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRtnOrder(CThostFtdcOrderField *pOrder) {
		this->OnRtnOrder(MNConv<ThostFtdcOrderField^,CThostFtdcOrderField>::N2M(pOrder));
	}
	void CTPTraderAdapter::cbk_OnRtnTrade(CThostFtdcTradeField *pTrade) {
		this->OnRtnTrade(MNConv<ThostFtdcTradeField^,CThostFtdcTradeField>::N2M(pTrade));
	}
	void CTPTraderAdapter::cbk_OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnOrderInsert(MNConv<ThostFtdcInputOrderField^,CThostFtdcInputOrderField>::N2M(pInputOrder), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnOrderAction(MNConv<ThostFtdcOrderActionField^,CThostFtdcOrderActionField>::N2M(pOrderAction), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
		this->OnRtnInstrumentStatus(MNConv<ThostFtdcInstrumentStatusField^,CThostFtdcInstrumentStatusField>::N2M(pInstrumentStatus));
	}
	void CTPTraderAdapter::cbk_OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
		this->OnRtnTradingNotice(MNConv<ThostFtdcTradingNoticeInfoField^,CThostFtdcTradingNoticeInfoField>::N2M(pTradingNoticeInfo));
	}
	void CTPTraderAdapter::cbk_OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {
		this->OnRtnErrorConditionalOrder(MNConv<ThostFtdcErrorConditionalOrderField^,CThostFtdcErrorConditionalOrderField>::N2M(pErrorConditionalOrder));
	}
	void CTPTraderAdapter::cbk_OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {
		this->OnRtnCFMMCTradingAccountToken(MNConv<ThostFtdcCFMMCTradingAccountTokenField^,CThostFtdcCFMMCTradingAccountTokenField>::N2M(pCFMMCTradingAccountToken));
	}
	void CTPTraderAdapter::cbk_OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryContractBank(MNConv<ThostFtdcContractBankField^,CThostFtdcContractBankField>::N2M(pContractBank), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryParkedOrder(MNConv<ThostFtdcParkedOrderField^,CThostFtdcParkedOrderField>::N2M(pParkedOrder), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryParkedOrderAction(MNConv<ThostFtdcParkedOrderActionField^,CThostFtdcParkedOrderActionField>::N2M(pParkedOrderAction), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryTradingNotice(MNConv<ThostFtdcTradingNoticeField^,CThostFtdcTradingNoticeField>::N2M(pTradingNotice), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryBrokerTradingParams(MNConv<ThostFtdcBrokerTradingParamsField^,CThostFtdcBrokerTradingParamsField>::N2M(pBrokerTradingParams), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQryBrokerTradingAlgos(MNConv<ThostFtdcBrokerTradingAlgosField^,CThostFtdcBrokerTradingAlgosField>::N2M(pBrokerTradingAlgos), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQueryCFMMCTradingAccountToken(MNConv<ThostFtdcQueryCFMMCTradingAccountTokenField^,CThostFtdcQueryCFMMCTradingAccountTokenField>::N2M(pQueryCFMMCTradingAccountToken), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {
		this->OnRtnFromBankToFutureByBank(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	}
	void CTPTraderAdapter::cbk_OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {
		this->OnRtnFromFutureToBankByBank(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromBankToFutureByBank(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromFutureToBankByBank(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		this->OnRtnFromBankToFutureByFuture(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	}
	void CTPTraderAdapter::cbk_OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {
		this->OnRtnFromFutureToBankByFuture(MNConv<ThostFtdcRspTransferField^,CThostFtdcRspTransferField>::N2M(pRspTransfer));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromBankToFutureByFutureManual(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromFutureToBankByFutureManual(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {
		this->OnRtnQueryBankBalanceByFuture(MNConv<ThostFtdcNotifyQueryAccountField^,CThostFtdcNotifyQueryAccountField>::N2M(pNotifyQueryAccount));
	}
	void CTPTraderAdapter::cbk_OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnBankToFutureByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnFutureToBankByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnRepealBankToFutureByFutureManual(MNConv<ThostFtdcReqRepealField^,CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnRepealFutureToBankByFutureManual(MNConv<ThostFtdcReqRepealField^,CThostFtdcReqRepealField>::N2M(pReqRepeal), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {
		this->OnErrRtnQueryBankBalanceByFuture(MNConv<ThostFtdcReqQueryAccountField^,CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromBankToFutureByFuture(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {
		this->OnRtnRepealFromFutureToBankByFuture(MNConv<ThostFtdcRspRepealField^,CThostFtdcRspRepealField>::N2M(pRspRepeal));
	}
	void CTPTraderAdapter::cbk_OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspFromBankToFutureByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspFromFutureToBankByFuture(MNConv<ThostFtdcReqTransferField^,CThostFtdcReqTransferField>::N2M(pReqTransfer), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
		this->OnRspQueryBankAccountMoneyByFuture(MNConv<ThostFtdcReqQueryAccountField^,CThostFtdcReqQueryAccountField>::N2M(pReqQueryAccount), RspInfoField(pRspInfo), nRequestID, bIsLast);
	}
	void CTPTraderAdapter::cbk_OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {
		this->OnRtnOpenAccountByBank(MNConv<ThostFtdcOpenAccountField^,CThostFtdcOpenAccountField>::N2M(pOpenAccount));
	}
	void CTPTraderAdapter::cbk_OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {
		this->OnRtnCancelAccountByBank(MNConv<ThostFtdcCancelAccountField^,CThostFtdcCancelAccountField>::N2M(pCancelAccount));
	}
	void CTPTraderAdapter::cbk_OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {
		this->OnRtnChangeAccountByBank(MNConv<ThostFtdcChangeAccountField^,CThostFtdcChangeAccountField>::N2M(pChangeAccount));
	}

	// 将所有回调函数地址传递给SPI，并保存对delegate的引用
	void CTPTraderAdapter::RegisterCallbacks()
	{
		m_pSpi->d_FrontConnected = gcnew Internal_FrontConnected(this, &CTPTraderAdapter::cbk_OnFrontConnected);
		m_pSpi->p_OnFrontConnected = (Callback_OnFrontConnected)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_FrontConnected).ToPointer();

		m_pSpi->d_FrontDisconnected = gcnew Internal_FrontDisconnected(this, &CTPTraderAdapter::cbk_OnFrontDisconnected);
		m_pSpi->p_OnFrontDisconnected = (Callback_OnFrontDisconnected)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_FrontDisconnected).ToPointer();

		m_pSpi->d_HeartBeatWarning = gcnew Internal_HeartBeatWarning(this, &CTPTraderAdapter::cbk_OnHeartBeatWarning);
		m_pSpi->p_OnHeartBeatWarning = (Callback_OnHeartBeatWarning)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_HeartBeatWarning).ToPointer();

		m_pSpi->d_RspAuthenticate = gcnew Internal_RspAuthenticate(this, &CTPTraderAdapter::cbk_OnRspAuthenticate);
		m_pSpi->p_OnRspAuthenticate = (Callback_OnRspAuthenticate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspAuthenticate).ToPointer();

		m_pSpi->d_RspUserLogin = gcnew Internal_RspUserLogin(this, &CTPTraderAdapter::cbk_OnRspUserLogin);
		m_pSpi->p_OnRspUserLogin = (Callback_OnRspUserLogin)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspUserLogin).ToPointer();

		m_pSpi->d_RspUserLogout = gcnew Internal_RspUserLogout(this, &CTPTraderAdapter::cbk_OnRspUserLogout);
		m_pSpi->p_OnRspUserLogout = (Callback_OnRspUserLogout)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspUserLogout).ToPointer();

		m_pSpi->d_RspUserPasswordUpdate = gcnew Internal_RspUserPasswordUpdate(this, &CTPTraderAdapter::cbk_OnRspUserPasswordUpdate);
		m_pSpi->p_OnRspUserPasswordUpdate = (Callback_OnRspUserPasswordUpdate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspUserPasswordUpdate).ToPointer();

		m_pSpi->d_RspTradingAccountPasswordUpdate = gcnew Internal_RspTradingAccountPasswordUpdate(this, &CTPTraderAdapter::cbk_OnRspTradingAccountPasswordUpdate);
		m_pSpi->p_OnRspTradingAccountPasswordUpdate = (Callback_OnRspTradingAccountPasswordUpdate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspTradingAccountPasswordUpdate).ToPointer();

		m_pSpi->d_RspOrderInsert = gcnew Internal_RspOrderInsert(this, &CTPTraderAdapter::cbk_OnRspOrderInsert);
		m_pSpi->p_OnRspOrderInsert = (Callback_OnRspOrderInsert)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspOrderInsert).ToPointer();

		m_pSpi->d_RspParkedOrderInsert = gcnew Internal_RspParkedOrderInsert(this, &CTPTraderAdapter::cbk_OnRspParkedOrderInsert);
		m_pSpi->p_OnRspParkedOrderInsert = (Callback_OnRspParkedOrderInsert)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspParkedOrderInsert).ToPointer();

		m_pSpi->d_RspParkedOrderAction = gcnew Internal_RspParkedOrderAction(this, &CTPTraderAdapter::cbk_OnRspParkedOrderAction);
		m_pSpi->p_OnRspParkedOrderAction = (Callback_OnRspParkedOrderAction)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspParkedOrderAction).ToPointer();

		m_pSpi->d_RspOrderAction = gcnew Internal_RspOrderAction(this, &CTPTraderAdapter::cbk_OnRspOrderAction);
		m_pSpi->p_OnRspOrderAction = (Callback_OnRspOrderAction)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspOrderAction).ToPointer();

		m_pSpi->d_RspQueryMaxOrderVolume = gcnew Internal_RspQueryMaxOrderVolume(this, &CTPTraderAdapter::cbk_OnRspQueryMaxOrderVolume);
		m_pSpi->p_OnRspQueryMaxOrderVolume = (Callback_OnRspQueryMaxOrderVolume)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQueryMaxOrderVolume).ToPointer();

		m_pSpi->d_RspSettlementInfoConfirm = gcnew Internal_RspSettlementInfoConfirm(this, &CTPTraderAdapter::cbk_OnRspSettlementInfoConfirm);
		m_pSpi->p_OnRspSettlementInfoConfirm = (Callback_OnRspSettlementInfoConfirm)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspSettlementInfoConfirm).ToPointer();

		m_pSpi->d_RspRemoveParkedOrder = gcnew Internal_RspRemoveParkedOrder(this, &CTPTraderAdapter::cbk_OnRspRemoveParkedOrder);
		m_pSpi->p_OnRspRemoveParkedOrder = (Callback_OnRspRemoveParkedOrder)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspRemoveParkedOrder).ToPointer();

		m_pSpi->d_RspRemoveParkedOrderAction = gcnew Internal_RspRemoveParkedOrderAction(this, &CTPTraderAdapter::cbk_OnRspRemoveParkedOrderAction);
		m_pSpi->p_OnRspRemoveParkedOrderAction = (Callback_OnRspRemoveParkedOrderAction)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspRemoveParkedOrderAction).ToPointer();

		m_pSpi->d_RspQryOrder = gcnew Internal_RspQryOrder(this, &CTPTraderAdapter::cbk_OnRspQryOrder);
		m_pSpi->p_OnRspQryOrder = (Callback_OnRspQryOrder)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryOrder).ToPointer();

		m_pSpi->d_RspQryTrade = gcnew Internal_RspQryTrade(this, &CTPTraderAdapter::cbk_OnRspQryTrade);
		m_pSpi->p_OnRspQryTrade = (Callback_OnRspQryTrade)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTrade).ToPointer();

		m_pSpi->d_RspQryInvestorPosition = gcnew Internal_RspQryInvestorPosition(this, &CTPTraderAdapter::cbk_OnRspQryInvestorPosition);
		m_pSpi->p_OnRspQryInvestorPosition = (Callback_OnRspQryInvestorPosition)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInvestorPosition).ToPointer();

		m_pSpi->d_RspQryTradingAccount = gcnew Internal_RspQryTradingAccount(this, &CTPTraderAdapter::cbk_OnRspQryTradingAccount);
		m_pSpi->p_OnRspQryTradingAccount = (Callback_OnRspQryTradingAccount)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTradingAccount).ToPointer();

		m_pSpi->d_RspQryInvestor = gcnew Internal_RspQryInvestor(this, &CTPTraderAdapter::cbk_OnRspQryInvestor);
		m_pSpi->p_OnRspQryInvestor = (Callback_OnRspQryInvestor)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInvestor).ToPointer();

		m_pSpi->d_RspQryTradingCode = gcnew Internal_RspQryTradingCode(this, &CTPTraderAdapter::cbk_OnRspQryTradingCode);
		m_pSpi->p_OnRspQryTradingCode = (Callback_OnRspQryTradingCode)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTradingCode).ToPointer();

		m_pSpi->d_RspQryInstrumentMarginRate = gcnew Internal_RspQryInstrumentMarginRate(this, &CTPTraderAdapter::cbk_OnRspQryInstrumentMarginRate);
		m_pSpi->p_OnRspQryInstrumentMarginRate = (Callback_OnRspQryInstrumentMarginRate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInstrumentMarginRate).ToPointer();

		m_pSpi->d_RspQryInstrumentCommissionRate = gcnew Internal_RspQryInstrumentCommissionRate(this, &CTPTraderAdapter::cbk_OnRspQryInstrumentCommissionRate);
		m_pSpi->p_OnRspQryInstrumentCommissionRate = (Callback_OnRspQryInstrumentCommissionRate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInstrumentCommissionRate).ToPointer();

		m_pSpi->d_RspQryExchange = gcnew Internal_RspQryExchange(this, &CTPTraderAdapter::cbk_OnRspQryExchange);
		m_pSpi->p_OnRspQryExchange = (Callback_OnRspQryExchange)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryExchange).ToPointer();

		m_pSpi->d_RspQryProduct = gcnew Internal_RspQryProduct(this, &CTPTraderAdapter::cbk_OnRspQryProduct);
		m_pSpi->p_OnRspQryProduct = (Callback_OnRspQryProduct)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryProduct).ToPointer();

		m_pSpi->d_RspQryInstrument = gcnew Internal_RspQryInstrument(this, &CTPTraderAdapter::cbk_OnRspQryInstrument);
		m_pSpi->p_OnRspQryInstrument = (Callback_OnRspQryInstrument)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInstrument).ToPointer();

		m_pSpi->d_RspQryDepthMarketData = gcnew Internal_RspQryDepthMarketData(this, &CTPTraderAdapter::cbk_OnRspQryDepthMarketData);
		m_pSpi->p_OnRspQryDepthMarketData = (Callback_OnRspQryDepthMarketData)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryDepthMarketData).ToPointer();

		m_pSpi->d_RspQrySettlementInfo = gcnew Internal_RspQrySettlementInfo(this, &CTPTraderAdapter::cbk_OnRspQrySettlementInfo);
		m_pSpi->p_OnRspQrySettlementInfo = (Callback_OnRspQrySettlementInfo)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQrySettlementInfo).ToPointer();

		m_pSpi->d_RspQryTransferBank = gcnew Internal_RspQryTransferBank(this, &CTPTraderAdapter::cbk_OnRspQryTransferBank);
		m_pSpi->p_OnRspQryTransferBank = (Callback_OnRspQryTransferBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTransferBank).ToPointer();

		m_pSpi->d_RspQryInvestorPositionDetail = gcnew Internal_RspQryInvestorPositionDetail(this, &CTPTraderAdapter::cbk_OnRspQryInvestorPositionDetail);
		m_pSpi->p_OnRspQryInvestorPositionDetail = (Callback_OnRspQryInvestorPositionDetail)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInvestorPositionDetail).ToPointer();

		m_pSpi->d_RspQryNotice = gcnew Internal_RspQryNotice(this, &CTPTraderAdapter::cbk_OnRspQryNotice);
		m_pSpi->p_OnRspQryNotice = (Callback_OnRspQryNotice)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryNotice).ToPointer();

		m_pSpi->d_RspQrySettlementInfoConfirm = gcnew Internal_RspQrySettlementInfoConfirm(this, &CTPTraderAdapter::cbk_OnRspQrySettlementInfoConfirm);
		m_pSpi->p_OnRspQrySettlementInfoConfirm = (Callback_OnRspQrySettlementInfoConfirm)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQrySettlementInfoConfirm).ToPointer();

		m_pSpi->d_RspQryInvestorPositionCombineDetail = gcnew Internal_RspQryInvestorPositionCombineDetail(this, &CTPTraderAdapter::cbk_OnRspQryInvestorPositionCombineDetail);
		m_pSpi->p_OnRspQryInvestorPositionCombineDetail = (Callback_OnRspQryInvestorPositionCombineDetail)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInvestorPositionCombineDetail).ToPointer();

		m_pSpi->d_RspQryCFMMCTradingAccountKey = gcnew Internal_RspQryCFMMCTradingAccountKey(this, &CTPTraderAdapter::cbk_OnRspQryCFMMCTradingAccountKey);
		m_pSpi->p_OnRspQryCFMMCTradingAccountKey = (Callback_OnRspQryCFMMCTradingAccountKey)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryCFMMCTradingAccountKey).ToPointer();

		m_pSpi->d_RspQryEWarrantOffset = gcnew Internal_RspQryEWarrantOffset(this, &CTPTraderAdapter::cbk_OnRspQryEWarrantOffset);
		m_pSpi->p_OnRspQryEWarrantOffset = (Callback_OnRspQryEWarrantOffset)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryEWarrantOffset).ToPointer();

		m_pSpi->d_RspQryInvestorProductGroupMargin = gcnew Internal_RspQryInvestorProductGroupMargin(this, &CTPTraderAdapter::cbk_OnRspQryInvestorProductGroupMargin);
		m_pSpi->p_OnRspQryInvestorProductGroupMargin = (Callback_OnRspQryInvestorProductGroupMargin)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryInvestorProductGroupMargin).ToPointer();

		m_pSpi->d_RspQryExchangeMarginRate = gcnew Internal_RspQryExchangeMarginRate(this, &CTPTraderAdapter::cbk_OnRspQryExchangeMarginRate);
		m_pSpi->p_OnRspQryExchangeMarginRate = (Callback_OnRspQryExchangeMarginRate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryExchangeMarginRate).ToPointer();

		m_pSpi->d_RspQryExchangeMarginRateAdjust = gcnew Internal_RspQryExchangeMarginRateAdjust(this, &CTPTraderAdapter::cbk_OnRspQryExchangeMarginRateAdjust);
		m_pSpi->p_OnRspQryExchangeMarginRateAdjust = (Callback_OnRspQryExchangeMarginRateAdjust)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryExchangeMarginRateAdjust).ToPointer();

		m_pSpi->d_RspQryExchangeRate = gcnew Internal_RspQryExchangeRate(this, &CTPTraderAdapter::cbk_OnRspQryExchangeRate);
		m_pSpi->p_OnRspQryExchangeRate = (Callback_OnRspQryExchangeRate)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryExchangeRate).ToPointer();

		m_pSpi->d_RspQrySecAgentACIDMap = gcnew Internal_RspQrySecAgentACIDMap(this, &CTPTraderAdapter::cbk_OnRspQrySecAgentACIDMap);
		m_pSpi->p_OnRspQrySecAgentACIDMap = (Callback_OnRspQrySecAgentACIDMap)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQrySecAgentACIDMap).ToPointer();

		m_pSpi->d_RspQryTransferSerial = gcnew Internal_RspQryTransferSerial(this, &CTPTraderAdapter::cbk_OnRspQryTransferSerial);
		m_pSpi->p_OnRspQryTransferSerial = (Callback_OnRspQryTransferSerial)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTransferSerial).ToPointer();

		m_pSpi->d_RspQryAccountregister = gcnew Internal_RspQryAccountregister(this, &CTPTraderAdapter::cbk_OnRspQryAccountregister);
		m_pSpi->p_OnRspQryAccountregister = (Callback_OnRspQryAccountregister)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryAccountregister).ToPointer();

		m_pSpi->d_RspError = gcnew Internal_RspError(this, &CTPTraderAdapter::cbk_OnRspError);
		m_pSpi->p_OnRspError = (Callback_OnRspError)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspError).ToPointer();

		m_pSpi->d_RtnOrder = gcnew Internal_RtnOrder(this, &CTPTraderAdapter::cbk_OnRtnOrder);
		m_pSpi->p_OnRtnOrder = (Callback_OnRtnOrder)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnOrder).ToPointer();

		m_pSpi->d_RtnTrade = gcnew Internal_RtnTrade(this, &CTPTraderAdapter::cbk_OnRtnTrade);
		m_pSpi->p_OnRtnTrade = (Callback_OnRtnTrade)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnTrade).ToPointer();

		m_pSpi->d_ErrRtnOrderInsert = gcnew Internal_ErrRtnOrderInsert(this, &CTPTraderAdapter::cbk_OnErrRtnOrderInsert);
		m_pSpi->p_OnErrRtnOrderInsert = (Callback_OnErrRtnOrderInsert)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnOrderInsert).ToPointer();

		m_pSpi->d_ErrRtnOrderAction = gcnew Internal_ErrRtnOrderAction(this, &CTPTraderAdapter::cbk_OnErrRtnOrderAction);
		m_pSpi->p_OnErrRtnOrderAction = (Callback_OnErrRtnOrderAction)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnOrderAction).ToPointer();

		m_pSpi->d_RtnInstrumentStatus = gcnew Internal_RtnInstrumentStatus(this, &CTPTraderAdapter::cbk_OnRtnInstrumentStatus);
		m_pSpi->p_OnRtnInstrumentStatus = (Callback_OnRtnInstrumentStatus)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnInstrumentStatus).ToPointer();

		m_pSpi->d_RtnTradingNotice = gcnew Internal_RtnTradingNotice(this, &CTPTraderAdapter::cbk_OnRtnTradingNotice);
		m_pSpi->p_OnRtnTradingNotice = (Callback_OnRtnTradingNotice)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnTradingNotice).ToPointer();

		m_pSpi->d_RtnErrorConditionalOrder = gcnew Internal_RtnErrorConditionalOrder(this, &CTPTraderAdapter::cbk_OnRtnErrorConditionalOrder);
		m_pSpi->p_OnRtnErrorConditionalOrder = (Callback_OnRtnErrorConditionalOrder)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnErrorConditionalOrder).ToPointer();

		m_pSpi->d_RtnCFMMCTradingAccountToken = gcnew Internal_RtnCFMMCTradingAccountToken(this, &CTPTraderAdapter::cbk_OnRtnCFMMCTradingAccountToken);
		m_pSpi->p_OnRtnCFMMCTradingAccountToken = (Callback_OnRtnCFMMCTradingAccountToken)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnCFMMCTradingAccountToken).ToPointer();

		m_pSpi->d_RspQryContractBank = gcnew Internal_RspQryContractBank(this, &CTPTraderAdapter::cbk_OnRspQryContractBank);
		m_pSpi->p_OnRspQryContractBank = (Callback_OnRspQryContractBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryContractBank).ToPointer();

		m_pSpi->d_RspQryParkedOrder = gcnew Internal_RspQryParkedOrder(this, &CTPTraderAdapter::cbk_OnRspQryParkedOrder);
		m_pSpi->p_OnRspQryParkedOrder = (Callback_OnRspQryParkedOrder)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryParkedOrder).ToPointer();

		m_pSpi->d_RspQryParkedOrderAction = gcnew Internal_RspQryParkedOrderAction(this, &CTPTraderAdapter::cbk_OnRspQryParkedOrderAction);
		m_pSpi->p_OnRspQryParkedOrderAction = (Callback_OnRspQryParkedOrderAction)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryParkedOrderAction).ToPointer();

		m_pSpi->d_RspQryTradingNotice = gcnew Internal_RspQryTradingNotice(this, &CTPTraderAdapter::cbk_OnRspQryTradingNotice);
		m_pSpi->p_OnRspQryTradingNotice = (Callback_OnRspQryTradingNotice)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryTradingNotice).ToPointer();

		m_pSpi->d_RspQryBrokerTradingParams = gcnew Internal_RspQryBrokerTradingParams(this, &CTPTraderAdapter::cbk_OnRspQryBrokerTradingParams);
		m_pSpi->p_OnRspQryBrokerTradingParams = (Callback_OnRspQryBrokerTradingParams)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryBrokerTradingParams).ToPointer();

		m_pSpi->d_RspQryBrokerTradingAlgos = gcnew Internal_RspQryBrokerTradingAlgos(this, &CTPTraderAdapter::cbk_OnRspQryBrokerTradingAlgos);
		m_pSpi->p_OnRspQryBrokerTradingAlgos = (Callback_OnRspQryBrokerTradingAlgos)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryBrokerTradingAlgos).ToPointer();

		m_pSpi->d_RspQueryCFMMCTradingAccountToken = gcnew Internal_RspQueryCFMMCTradingAccountToken(this, &CTPTraderAdapter::cbk_OnRspQueryCFMMCTradingAccountToken);
		m_pSpi->p_OnRspQueryCFMMCTradingAccountToken = (Callback_OnRspQueryCFMMCTradingAccountToken)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQueryCFMMCTradingAccountToken).ToPointer();

		m_pSpi->d_RtnFromBankToFutureByBank = gcnew Internal_RtnFromBankToFutureByBank(this, &CTPTraderAdapter::cbk_OnRtnFromBankToFutureByBank);
		m_pSpi->p_OnRtnFromBankToFutureByBank = (Callback_OnRtnFromBankToFutureByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnFromBankToFutureByBank).ToPointer();

		m_pSpi->d_RtnFromFutureToBankByBank = gcnew Internal_RtnFromFutureToBankByBank(this, &CTPTraderAdapter::cbk_OnRtnFromFutureToBankByBank);
		m_pSpi->p_OnRtnFromFutureToBankByBank = (Callback_OnRtnFromFutureToBankByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnFromFutureToBankByBank).ToPointer();

		m_pSpi->d_RtnRepealFromBankToFutureByBank = gcnew Internal_RtnRepealFromBankToFutureByBank(this, &CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByBank);
		m_pSpi->p_OnRtnRepealFromBankToFutureByBank = (Callback_OnRtnRepealFromBankToFutureByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromBankToFutureByBank).ToPointer();

		m_pSpi->d_RtnRepealFromFutureToBankByBank = gcnew Internal_RtnRepealFromFutureToBankByBank(this, &CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByBank);
		m_pSpi->p_OnRtnRepealFromFutureToBankByBank = (Callback_OnRtnRepealFromFutureToBankByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromFutureToBankByBank).ToPointer();

		m_pSpi->d_RtnFromBankToFutureByFuture = gcnew Internal_RtnFromBankToFutureByFuture(this, &CTPTraderAdapter::cbk_OnRtnFromBankToFutureByFuture);
		m_pSpi->p_OnRtnFromBankToFutureByFuture = (Callback_OnRtnFromBankToFutureByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnFromBankToFutureByFuture).ToPointer();

		m_pSpi->d_RtnFromFutureToBankByFuture = gcnew Internal_RtnFromFutureToBankByFuture(this, &CTPTraderAdapter::cbk_OnRtnFromFutureToBankByFuture);
		m_pSpi->p_OnRtnFromFutureToBankByFuture = (Callback_OnRtnFromFutureToBankByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnFromFutureToBankByFuture).ToPointer();

		m_pSpi->d_RtnRepealFromBankToFutureByFutureManual = gcnew Internal_RtnRepealFromBankToFutureByFutureManual(this, &CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByFutureManual);
		m_pSpi->p_OnRtnRepealFromBankToFutureByFutureManual = (Callback_OnRtnRepealFromBankToFutureByFutureManual)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromBankToFutureByFutureManual).ToPointer();

		m_pSpi->d_RtnRepealFromFutureToBankByFutureManual = gcnew Internal_RtnRepealFromFutureToBankByFutureManual(this, &CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByFutureManual);
		m_pSpi->p_OnRtnRepealFromFutureToBankByFutureManual = (Callback_OnRtnRepealFromFutureToBankByFutureManual)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromFutureToBankByFutureManual).ToPointer();

		m_pSpi->d_RtnQueryBankBalanceByFuture = gcnew Internal_RtnQueryBankBalanceByFuture(this, &CTPTraderAdapter::cbk_OnRtnQueryBankBalanceByFuture);
		m_pSpi->p_OnRtnQueryBankBalanceByFuture = (Callback_OnRtnQueryBankBalanceByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnQueryBankBalanceByFuture).ToPointer();

		m_pSpi->d_ErrRtnBankToFutureByFuture = gcnew Internal_ErrRtnBankToFutureByFuture(this, &CTPTraderAdapter::cbk_OnErrRtnBankToFutureByFuture);
		m_pSpi->p_OnErrRtnBankToFutureByFuture = (Callback_OnErrRtnBankToFutureByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnBankToFutureByFuture).ToPointer();

		m_pSpi->d_ErrRtnFutureToBankByFuture = gcnew Internal_ErrRtnFutureToBankByFuture(this, &CTPTraderAdapter::cbk_OnErrRtnFutureToBankByFuture);
		m_pSpi->p_OnErrRtnFutureToBankByFuture = (Callback_OnErrRtnFutureToBankByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnFutureToBankByFuture).ToPointer();

		m_pSpi->d_ErrRtnRepealBankToFutureByFutureManual = gcnew Internal_ErrRtnRepealBankToFutureByFutureManual(this, &CTPTraderAdapter::cbk_OnErrRtnRepealBankToFutureByFutureManual);
		m_pSpi->p_OnErrRtnRepealBankToFutureByFutureManual = (Callback_OnErrRtnRepealBankToFutureByFutureManual)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnRepealBankToFutureByFutureManual).ToPointer();

		m_pSpi->d_ErrRtnRepealFutureToBankByFutureManual = gcnew Internal_ErrRtnRepealFutureToBankByFutureManual(this, &CTPTraderAdapter::cbk_OnErrRtnRepealFutureToBankByFutureManual);
		m_pSpi->p_OnErrRtnRepealFutureToBankByFutureManual = (Callback_OnErrRtnRepealFutureToBankByFutureManual)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnRepealFutureToBankByFutureManual).ToPointer();

		m_pSpi->d_ErrRtnQueryBankBalanceByFuture = gcnew Internal_ErrRtnQueryBankBalanceByFuture(this, &CTPTraderAdapter::cbk_OnErrRtnQueryBankBalanceByFuture);
		m_pSpi->p_OnErrRtnQueryBankBalanceByFuture = (Callback_OnErrRtnQueryBankBalanceByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnQueryBankBalanceByFuture).ToPointer();

		m_pSpi->d_RtnRepealFromBankToFutureByFuture = gcnew Internal_RtnRepealFromBankToFutureByFuture(this, &CTPTraderAdapter::cbk_OnRtnRepealFromBankToFutureByFuture);
		m_pSpi->p_OnRtnRepealFromBankToFutureByFuture = (Callback_OnRtnRepealFromBankToFutureByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromBankToFutureByFuture).ToPointer();

		m_pSpi->d_RtnRepealFromFutureToBankByFuture = gcnew Internal_RtnRepealFromFutureToBankByFuture(this, &CTPTraderAdapter::cbk_OnRtnRepealFromFutureToBankByFuture);
		m_pSpi->p_OnRtnRepealFromFutureToBankByFuture = (Callback_OnRtnRepealFromFutureToBankByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnRepealFromFutureToBankByFuture).ToPointer();

		m_pSpi->d_RspFromBankToFutureByFuture = gcnew Internal_RspFromBankToFutureByFuture(this, &CTPTraderAdapter::cbk_OnRspFromBankToFutureByFuture);
		m_pSpi->p_OnRspFromBankToFutureByFuture = (Callback_OnRspFromBankToFutureByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspFromBankToFutureByFuture).ToPointer();

		m_pSpi->d_RspFromFutureToBankByFuture = gcnew Internal_RspFromFutureToBankByFuture(this, &CTPTraderAdapter::cbk_OnRspFromFutureToBankByFuture);
		m_pSpi->p_OnRspFromFutureToBankByFuture = (Callback_OnRspFromFutureToBankByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspFromFutureToBankByFuture).ToPointer();

		m_pSpi->d_RspQueryBankAccountMoneyByFuture = gcnew Internal_RspQueryBankAccountMoneyByFuture(this, &CTPTraderAdapter::cbk_OnRspQueryBankAccountMoneyByFuture);
		m_pSpi->p_OnRspQueryBankAccountMoneyByFuture = (Callback_OnRspQueryBankAccountMoneyByFuture)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQueryBankAccountMoneyByFuture).ToPointer();

		m_pSpi->d_RtnOpenAccountByBank = gcnew Internal_RtnOpenAccountByBank(this, &CTPTraderAdapter::cbk_OnRtnOpenAccountByBank);
		m_pSpi->p_OnRtnOpenAccountByBank = (Callback_OnRtnOpenAccountByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnOpenAccountByBank).ToPointer();

		m_pSpi->d_RtnCancelAccountByBank = gcnew Internal_RtnCancelAccountByBank(this, &CTPTraderAdapter::cbk_OnRtnCancelAccountByBank);
		m_pSpi->p_OnRtnCancelAccountByBank = (Callback_OnRtnCancelAccountByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnCancelAccountByBank).ToPointer();

		m_pSpi->d_RtnChangeAccountByBank = gcnew Internal_RtnChangeAccountByBank(this, &CTPTraderAdapter::cbk_OnRtnChangeAccountByBank);
		m_pSpi->p_OnRtnChangeAccountByBank = (Callback_OnRtnChangeAccountByBank)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnChangeAccountByBank).ToPointer();
	}

#else
#endif

} // end of namespace