#include "stdafx.h"
#include "TraderSpi.h"
#include "CTPTraderAdapter.h"


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

	void CTPTraderAdapter::cbk_OnFrontEvent(CtpEnumFrontType EventType, int nReason){
		this->OnCtpFrontEvent(this, gcnew CtpFrontEventArgs(EventType, nReason));
	}


	void CTPTraderAdapter::cbk_OnErrRtnEvent(CtpEnumErrRtnType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo)
	{
		switch (EventType)
		{
		case CTP::CtpEnumErrRtnType::ErrRtnBankToFutureByFuture:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M((CThostFtdcReqTransferField*)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnFutureToBankByFuture:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M((CThostFtdcReqTransferField*)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnOrderAction:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcOrderActionField^, CThostFtdcOrderActionField>::N2M((CThostFtdcOrderActionField*)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnOrderInsert:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcInputOrderField^, CThostFtdcInputOrderField>::N2M((CThostFtdcInputOrderField*)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnRepealBankToFutureByFutureManual:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcReqRepealField^, CThostFtdcReqRepealField>::N2M((CThostFtdcReqRepealField*)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnQueryBankBalanceByFuture:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcReqQueryAccountField^, CThostFtdcReqQueryAccountField>::N2M((CThostFtdcReqQueryAccountField *)pParam), RspInfoField(pRspInfo)));
			break;
		case CTP::CtpEnumErrRtnType::ErrRtnRepealFutureToBankByFutureManual:
			OnCtpErrRtnEvent(this, gcnew CtpErrRtnEventArgs(EventType, MNConv<ThostFtdcReqRepealField^, CThostFtdcReqRepealField>::N2M((CThostFtdcReqRepealField *)pParam), RspInfoField(pRspInfo)));
			break;
		default:
			break;
		}
	}

	void CTPTraderAdapter::cbk_OnRspEvent(CtpEnumRspType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		switch (EventType)
		{
		case CTP::CtpEnumRspType::RspError:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, nullptr, RspInfoField(pRspInfo), nRequestID, bIsLast));
		case CTP::CtpEnumRspType::RspAuthenticate:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcRspAuthenticateField^, CThostFtdcRspAuthenticateField>::N2M((CThostFtdcRspAuthenticateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspFromBankToFutureByFuture:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M((CThostFtdcReqTransferField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspFromFutureToBankByFuture:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::N2M((CThostFtdcReqTransferField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspOrderAction:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcInputOrderActionField^, CThostFtdcInputOrderActionField>::N2M((CThostFtdcInputOrderActionField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspOrderInsert:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcInputOrderField^, CThostFtdcInputOrderField>::N2M((CThostFtdcInputOrderField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspParkedOrderAction:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcParkedOrderActionField^, CThostFtdcParkedOrderActionField>::N2M((CThostFtdcParkedOrderActionField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspParkedOrderInsert:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcParkedOrderField^, CThostFtdcParkedOrderField>::N2M((CThostFtdcParkedOrderField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspRemoveParkedOrder:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcRemoveParkedOrderField^, CThostFtdcRemoveParkedOrderField>::N2M((CThostFtdcRemoveParkedOrderField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspRemoveParkedOrderAction:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcRemoveParkedOrderActionField^, CThostFtdcRemoveParkedOrderActionField>::N2M((CThostFtdcRemoveParkedOrderActionField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspSettlementInfoConfirm:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcSettlementInfoConfirmField^, CThostFtdcSettlementInfoConfirmField>::N2M((CThostFtdcSettlementInfoConfirmField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspTradingAccountPasswordUpdate:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcTradingAccountPasswordUpdateField^, CThostFtdcTradingAccountPasswordUpdateField>::N2M((CThostFtdcTradingAccountPasswordUpdateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUserLogin:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcRspUserLoginField^, CThostFtdcRspUserLoginField>::N2M((CThostFtdcRspUserLoginField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUserLogout:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::N2M((CThostFtdcUserLogoutField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUserPasswordUpdate:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(EventType, MNConv<ThostFtdcUserPasswordUpdateField^, CThostFtdcUserPasswordUpdateField>::N2M((CThostFtdcUserPasswordUpdateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		default:
			break;
		}
	}

	void CTPTraderAdapter::cbk_OnRspQryEvent(CtpEnumRspQryType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		switch (EventType)
		{
		case CTP::CtpEnumRspQryType::RspQryAccountregister:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcAccountregisterField^, CThostFtdcAccountregisterField>::N2M((CThostFtdcAccountregisterField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryBrokerTradingAlgos:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcBrokerTradingAlgosField^, CThostFtdcBrokerTradingAlgosField>::N2M((CThostFtdcBrokerTradingAlgosField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQueryCFMMCTradingAccountToken:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcQueryCFMMCTradingAccountTokenField^, CThostFtdcQueryCFMMCTradingAccountTokenField>::N2M((CThostFtdcQueryCFMMCTradingAccountTokenField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryBrokerTradingParams:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcBrokerTradingParamsField^, CThostFtdcBrokerTradingParamsField>::N2M((CThostFtdcBrokerTradingParamsField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryCFMMCTradingAccountKey:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcCFMMCTradingAccountKeyField^, CThostFtdcCFMMCTradingAccountKeyField>::N2M((CThostFtdcCFMMCTradingAccountKeyField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryContractBank:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcContractBankField^, CThostFtdcContractBankField>::N2M((CThostFtdcContractBankField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryDepthMarketData:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcDepthMarketDataField^, CThostFtdcDepthMarketDataField>::N2M((CThostFtdcDepthMarketDataField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryEWarrantOffset:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcEWarrantOffsetField^, CThostFtdcEWarrantOffsetField>::N2M((CThostFtdcEWarrantOffsetField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryExchange:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcExchangeField^, CThostFtdcExchangeField>::N2M((CThostFtdcExchangeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryExchangeMarginRate:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcExchangeMarginRateField^, CThostFtdcExchangeMarginRateField>::N2M((CThostFtdcExchangeMarginRateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryExchangeMarginRateAdjust:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcExchangeMarginRateAdjustField^, CThostFtdcExchangeMarginRateAdjustField>::N2M((CThostFtdcExchangeMarginRateAdjustField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryExchangeRate:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcExchangeRateField^, CThostFtdcExchangeRateField>::N2M((CThostFtdcExchangeRateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInstrument:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInstrumentField^, CThostFtdcInstrumentField>::N2M((CThostFtdcInstrumentField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInstrumentCommissionRate:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInstrumentCommissionRateField^, CThostFtdcInstrumentCommissionRateField>::N2M((CThostFtdcInstrumentCommissionRateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInstrumentMarginRate:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInstrumentMarginRateField^, CThostFtdcInstrumentMarginRateField>::N2M((CThostFtdcInstrumentMarginRateField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInvestor:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInvestorField^, CThostFtdcInvestorField>::N2M((CThostFtdcInvestorField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInvestorPosition:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInvestorPositionField^, CThostFtdcInvestorPositionField>::N2M((CThostFtdcInvestorPositionField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInvestorPositionCombineDetail:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInvestorPositionCombineDetailField^, CThostFtdcInvestorPositionCombineDetailField>::N2M((CThostFtdcInvestorPositionCombineDetailField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInvestorPositionDetail:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInvestorPositionDetailField^, CThostFtdcInvestorPositionDetailField>::N2M((CThostFtdcInvestorPositionDetailField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryInvestorProductGroupMargin:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcInvestorProductGroupMarginField^, CThostFtdcInvestorProductGroupMarginField>::N2M((CThostFtdcInvestorProductGroupMarginField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryNotice:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcNoticeField^, CThostFtdcNoticeField>::N2M((CThostFtdcNoticeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryOrder:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcOrderField^, CThostFtdcOrderField>::N2M((CThostFtdcOrderField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryParkedOrder:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcParkedOrderField^, CThostFtdcParkedOrderField>::N2M((CThostFtdcParkedOrderField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryParkedOrderAction:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcParkedOrderActionField^, CThostFtdcParkedOrderActionField>::N2M((CThostFtdcParkedOrderActionField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryProduct:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcProductField^, CThostFtdcProductField>::N2M((CThostFtdcProductField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQrySecAgentACIDMap:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcSecAgentACIDMapField^, CThostFtdcSecAgentACIDMapField>::N2M((CThostFtdcSecAgentACIDMapField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQrySettlementInfo:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcSettlementInfoField^, CThostFtdcSettlementInfoField>::N2M((CThostFtdcSettlementInfoField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQrySettlementInfoConfirm:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcSettlementInfoConfirmField^, CThostFtdcSettlementInfoConfirmField>::N2M((CThostFtdcSettlementInfoConfirmField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTrade:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTradeField^, CThostFtdcTradeField>::N2M((CThostFtdcTradeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTradingAccount:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTradingAccountField^, CThostFtdcTradingAccountField>::N2M((CThostFtdcTradingAccountField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTradingCode:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTradingCodeField^, CThostFtdcTradingCodeField>::N2M((CThostFtdcTradingCodeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTradingNotice:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTradingNoticeField^, CThostFtdcTradingNoticeField>::N2M((CThostFtdcTradingNoticeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTransferBank:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTransferBankField^, CThostFtdcTransferBankField>::N2M((CThostFtdcTransferBankField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryTransferSerial:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcTransferSerialField^, CThostFtdcTransferSerialField>::N2M((CThostFtdcTransferSerialField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryBankAccountMoneyByFuture:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcReqQueryAccountField^, CThostFtdcReqQueryAccountField>::N2M((CThostFtdcReqQueryAccountField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspQryType::RspQryMaxOrderVolume:
			OnCtpRspQryEvent(this, gcnew CtpRspQryEventArgs(EventType, MNConv<ThostFtdcQueryMaxOrderVolumeField^, CThostFtdcQueryMaxOrderVolumeField>::N2M((CThostFtdcQueryMaxOrderVolumeField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		default:
			break;
		}
	}

	void CTPTraderAdapter::cbk_OnRtnEvent(CtpEnumRtnType EventType, void *pParam)
	{
		switch (EventType)
		{
		case CTP::CtpEnumRtnType::RtnCancelAccountByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcCancelAccountField^, CThostFtdcCancelAccountField>::N2M((CThostFtdcCancelAccountField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnChangeAccountByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcChangeAccountField^, CThostFtdcChangeAccountField>::N2M((CThostFtdcChangeAccountField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnErrorConditionalOrder:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcErrorConditionalOrderField^, CThostFtdcErrorConditionalOrderField>::N2M((CThostFtdcErrorConditionalOrderField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnCFMMCTradingAccountToken:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcCFMMCTradingAccountTokenField^, CThostFtdcCFMMCTradingAccountTokenField>::N2M((CThostFtdcCFMMCTradingAccountTokenField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnFromBankToFutureByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M((CThostFtdcRspTransferField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnFromBankToFutureByFuture:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M((CThostFtdcRspTransferField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnFromFutureToBankByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M((CThostFtdcRspTransferField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnFromFutureToBankByFuture:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspTransferField^, CThostFtdcRspTransferField>::N2M((CThostFtdcRspTransferField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnInstrumentStatus:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcInstrumentStatusField^, CThostFtdcInstrumentStatusField>::N2M((CThostFtdcInstrumentStatusField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnOpenAccountByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcOpenAccountField^, CThostFtdcOpenAccountField>::N2M((CThostFtdcOpenAccountField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnOrder:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcOrderField^, CThostFtdcOrderField>::N2M((CThostFtdcOrderField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnQueryBankBalanceByFuture:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcNotifyQueryAccountField^, CThostFtdcNotifyQueryAccountField>::N2M((CThostFtdcNotifyQueryAccountField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromBankToFutureByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromBankToFutureByFuture:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromBankToFutureByFutureManual:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromFutureToBankByBank:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromFutureToBankByFuture:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnRepealFromFutureToBankByFutureManual:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcRspRepealField^, CThostFtdcRspRepealField>::N2M((CThostFtdcRspRepealField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnTrade:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcTradeField^, CThostFtdcTradeField>::N2M((CThostFtdcTradeField*)pParam)));
			break;
		case CTP::CtpEnumRtnType::RtnTradingNotice:
			OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, MNConv<ThostFtdcTradingNoticeInfoField^, CThostFtdcTradingNoticeInfoField>::N2M((CThostFtdcTradingNoticeInfoField*)pParam)));
			break;
		default:
			break;
		}
	}


	// 将所有回调函数地址传递给SPI，并保存对delegate的引用
	void CTPTraderAdapter::RegisterCallbacks()
	{
		m_pSpi->d_FrontConnEvent = gcnew Internal_FrontEvent(this, &CTPTraderAdapter::cbk_OnFrontEvent);
		m_pSpi->p_OnFrontConnEvent = (Callback_OnFrontConnEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_FrontConnEvent).ToPointer();

		m_pSpi->d_ErrRtnEvent = gcnew Internal_ErrRtnEvent(this, &CTPTraderAdapter::cbk_OnErrRtnEvent);
		m_pSpi->p_OnErrRtnEvent = (Callback_OnErrRtnEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_ErrRtnEvent).ToPointer();

		m_pSpi->d_RspQryEvent = gcnew Internal_RspQryEvent(this, &CTPTraderAdapter::cbk_OnRspQryEvent);
		m_pSpi->p_OnRspQryEvent = (Callback_OnRspQryEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspQryEvent).ToPointer();

		m_pSpi->d_RtnEvent = gcnew Internal_RtnEvent(this, &CTPTraderAdapter::cbk_OnRtnEvent);
		m_pSpi->p_OnRtnEvent = (Callback_OnRtnEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnEvent).ToPointer();

		m_pSpi->d_RspOthersEvent = gcnew Internal_RspEvent(this, &CTPTraderAdapter::cbk_OnRspEvent);
		m_pSpi->p_OnRspEvent = (Callback_OnRspEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspOthersEvent).ToPointer();
	}

#else
#endif
}
