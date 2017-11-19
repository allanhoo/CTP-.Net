/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20120422
/////////////////////////////////////////////////////////////////////////

#pragma once

#include <vcclr.h>
#include "util.h"
#include "Callbacks.h"
#include "ThostFtdcMdApi.h"
#include "CTPTraderAdapter.h"

namespace Native
{
	/// 非托管类
	class CTraderSpiBase : public CThostFtdcTraderSpi
	{

#ifdef __CTP_MA__
	// 回调函数
	public:
		Callback_OnFrontConnected p_OnFrontConnected;
		Callback_OnFrontDisconnected p_OnFrontDisconnected;
		Callback_OnHeartBeatWarning p_OnHeartBeatWarning;
		Callback_OnRspAuthenticate p_OnRspAuthenticate;
		Callback_OnRspUserLogin p_OnRspUserLogin;
		Callback_OnRspUserLogout p_OnRspUserLogout;
		Callback_OnRspUserPasswordUpdate p_OnRspUserPasswordUpdate;
		Callback_OnRspTradingAccountPasswordUpdate p_OnRspTradingAccountPasswordUpdate;
		Callback_OnRspOrderInsert p_OnRspOrderInsert;
		Callback_OnRspParkedOrderInsert p_OnRspParkedOrderInsert;
		Callback_OnRspParkedOrderAction p_OnRspParkedOrderAction;
		Callback_OnRspOrderAction p_OnRspOrderAction;
		Callback_OnRspQueryMaxOrderVolume p_OnRspQueryMaxOrderVolume;
		Callback_OnRspSettlementInfoConfirm p_OnRspSettlementInfoConfirm;
		Callback_OnRspRemoveParkedOrder p_OnRspRemoveParkedOrder;
		Callback_OnRspRemoveParkedOrderAction p_OnRspRemoveParkedOrderAction;
		Callback_OnRspQryOrder p_OnRspQryOrder;
		Callback_OnRspQryTrade p_OnRspQryTrade;
		Callback_OnRspQryInvestorPosition p_OnRspQryInvestorPosition;
		Callback_OnRspQryTradingAccount p_OnRspQryTradingAccount;
		Callback_OnRspQryInvestor p_OnRspQryInvestor;
		Callback_OnRspQryTradingCode p_OnRspQryTradingCode;
		Callback_OnRspQryInstrumentMarginRate p_OnRspQryInstrumentMarginRate;
		Callback_OnRspQryInstrumentCommissionRate p_OnRspQryInstrumentCommissionRate;
		Callback_OnRspQryExchange p_OnRspQryExchange;
		Callback_OnRspQryProduct p_OnRspQryProduct;
		Callback_OnRspQryInstrument p_OnRspQryInstrument;
		Callback_OnRspQryDepthMarketData p_OnRspQryDepthMarketData;
		Callback_OnRspQrySettlementInfo p_OnRspQrySettlementInfo;
		Callback_OnRspQryTransferBank p_OnRspQryTransferBank;
		Callback_OnRspQryInvestorPositionDetail p_OnRspQryInvestorPositionDetail;
		Callback_OnRspQryNotice p_OnRspQryNotice;
		Callback_OnRspQrySettlementInfoConfirm p_OnRspQrySettlementInfoConfirm;
		Callback_OnRspQryInvestorPositionCombineDetail p_OnRspQryInvestorPositionCombineDetail;
		Callback_OnRspQryCFMMCTradingAccountKey p_OnRspQryCFMMCTradingAccountKey;
		Callback_OnRspQryEWarrantOffset p_OnRspQryEWarrantOffset;
		Callback_OnRspQryInvestorProductGroupMargin p_OnRspQryInvestorProductGroupMargin;
		Callback_OnRspQryExchangeMarginRate p_OnRspQryExchangeMarginRate;
		Callback_OnRspQryExchangeMarginRateAdjust p_OnRspQryExchangeMarginRateAdjust;
		Callback_OnRspQryExchangeRate p_OnRspQryExchangeRate;
		Callback_OnRspQrySecAgentACIDMap p_OnRspQrySecAgentACIDMap;
		Callback_OnRspQryTransferSerial p_OnRspQryTransferSerial;
		Callback_OnRspQryAccountregister p_OnRspQryAccountregister;
		Callback_OnRspError p_OnRspError;
		Callback_OnRtnOrder p_OnRtnOrder;
		Callback_OnRtnTrade p_OnRtnTrade;
		Callback_OnErrRtnOrderInsert p_OnErrRtnOrderInsert;
		Callback_OnErrRtnOrderAction p_OnErrRtnOrderAction;
		Callback_OnRtnInstrumentStatus p_OnRtnInstrumentStatus;
		Callback_OnRtnTradingNotice p_OnRtnTradingNotice;
		Callback_OnRtnErrorConditionalOrder p_OnRtnErrorConditionalOrder;
		Callback_OnRtnCFMMCTradingAccountToken p_OnRtnCFMMCTradingAccountToken;
		Callback_OnRspQryContractBank p_OnRspQryContractBank;
		Callback_OnRspQryParkedOrder p_OnRspQryParkedOrder;
		Callback_OnRspQryParkedOrderAction p_OnRspQryParkedOrderAction;
		Callback_OnRspQryTradingNotice p_OnRspQryTradingNotice;
		Callback_OnRspQryBrokerTradingParams p_OnRspQryBrokerTradingParams;
		Callback_OnRspQryBrokerTradingAlgos p_OnRspQryBrokerTradingAlgos;
		Callback_OnRspQueryCFMMCTradingAccountToken p_OnRspQueryCFMMCTradingAccountToken;
		Callback_OnRtnFromBankToFutureByBank p_OnRtnFromBankToFutureByBank;
		Callback_OnRtnFromFutureToBankByBank p_OnRtnFromFutureToBankByBank;
		Callback_OnRtnRepealFromBankToFutureByBank p_OnRtnRepealFromBankToFutureByBank;
		Callback_OnRtnRepealFromFutureToBankByBank p_OnRtnRepealFromFutureToBankByBank;
		Callback_OnRtnFromBankToFutureByFuture p_OnRtnFromBankToFutureByFuture;
		Callback_OnRtnFromFutureToBankByFuture p_OnRtnFromFutureToBankByFuture;
		Callback_OnRtnRepealFromBankToFutureByFutureManual p_OnRtnRepealFromBankToFutureByFutureManual;
		Callback_OnRtnRepealFromFutureToBankByFutureManual p_OnRtnRepealFromFutureToBankByFutureManual;
		Callback_OnRtnQueryBankBalanceByFuture p_OnRtnQueryBankBalanceByFuture;
		Callback_OnErrRtnBankToFutureByFuture p_OnErrRtnBankToFutureByFuture;
		Callback_OnErrRtnFutureToBankByFuture p_OnErrRtnFutureToBankByFuture;
		Callback_OnErrRtnRepealBankToFutureByFutureManual p_OnErrRtnRepealBankToFutureByFutureManual;
		Callback_OnErrRtnRepealFutureToBankByFutureManual p_OnErrRtnRepealFutureToBankByFutureManual;
		Callback_OnErrRtnQueryBankBalanceByFuture p_OnErrRtnQueryBankBalanceByFuture;
		Callback_OnRtnRepealFromBankToFutureByFuture p_OnRtnRepealFromBankToFutureByFuture;
		Callback_OnRtnRepealFromFutureToBankByFuture p_OnRtnRepealFromFutureToBankByFuture;
		Callback_OnRspFromBankToFutureByFuture p_OnRspFromBankToFutureByFuture;
		Callback_OnRspFromFutureToBankByFuture p_OnRspFromFutureToBankByFuture;
		Callback_OnRspQueryBankAccountMoneyByFuture p_OnRspQueryBankAccountMoneyByFuture;
		Callback_OnRtnOpenAccountByBank p_OnRtnOpenAccountByBank;
		Callback_OnRtnCancelAccountByBank p_OnRtnCancelAccountByBank;
		Callback_OnRtnChangeAccountByBank p_OnRtnChangeAccountByBank;

		// 回调函数对应的delegate，必须保持一份对该deleage的引用，否则GC会自动回收该deleage并导致上面的回调函数失效
		gcroot<Internal_FrontConnected^> d_FrontConnected;
		gcroot<Internal_FrontDisconnected^> d_FrontDisconnected;
		gcroot<Internal_HeartBeatWarning^> d_HeartBeatWarning;
		gcroot<Internal_RspUserLogin^> d_RspUserLogin;
		gcroot<Internal_RspUserLogout^> d_RspUserLogout;
		gcroot<Internal_RspError^> d_RspError;

		gcroot<Internal_RspAuthenticate^> d_RspAuthenticate;
		gcroot<Internal_RspUserPasswordUpdate^> d_RspUserPasswordUpdate;
		gcroot<Internal_RspTradingAccountPasswordUpdate^> d_RspTradingAccountPasswordUpdate;
		gcroot<Internal_RspOrderInsert^> d_RspOrderInsert;
		gcroot<Internal_RspParkedOrderInsert^> d_RspParkedOrderInsert;
		gcroot<Internal_RspParkedOrderAction^> d_RspParkedOrderAction;
		gcroot<Internal_RspOrderAction^> d_RspOrderAction;
		gcroot<Internal_RspQueryMaxOrderVolume^> d_RspQueryMaxOrderVolume;
		gcroot<Internal_RspSettlementInfoConfirm^> d_RspSettlementInfoConfirm;
		gcroot<Internal_RspRemoveParkedOrder^> d_RspRemoveParkedOrder;
		gcroot<Internal_RspRemoveParkedOrderAction^> d_RspRemoveParkedOrderAction;
		gcroot<Internal_RspQryOrder^> d_RspQryOrder;
		gcroot<Internal_RspQryTrade^> d_RspQryTrade;
		gcroot<Internal_RspQryInvestorPosition^> d_RspQryInvestorPosition;
		gcroot<Internal_RspQryTradingAccount^> d_RspQryTradingAccount;
		gcroot<Internal_RspQryInvestor^> d_RspQryInvestor;
		gcroot<Internal_RspQryTradingCode^> d_RspQryTradingCode;
		gcroot<Internal_RspQryInstrumentMarginRate^> d_RspQryInstrumentMarginRate;
		gcroot<Internal_RspQryInstrumentCommissionRate^> d_RspQryInstrumentCommissionRate;
		gcroot<Internal_RspQryExchange^> d_RspQryExchange;
		gcroot<Internal_RspQryProduct^> d_RspQryProduct;
		gcroot<Internal_RspQryInstrument^> d_RspQryInstrument;
		gcroot<Internal_RspQryDepthMarketData^> d_RspQryDepthMarketData;
		gcroot<Internal_RspQrySettlementInfo^> d_RspQrySettlementInfo;
		gcroot<Internal_RspQryTransferBank^> d_RspQryTransferBank;
		gcroot<Internal_RspQryInvestorPositionDetail^> d_RspQryInvestorPositionDetail;
		gcroot<Internal_RspQryNotice^> d_RspQryNotice;
		gcroot<Internal_RspQrySettlementInfoConfirm^> d_RspQrySettlementInfoConfirm;
		gcroot<Internal_RspQryInvestorPositionCombineDetail^> d_RspQryInvestorPositionCombineDetail;
		gcroot<Internal_RspQryCFMMCTradingAccountKey^> d_RspQryCFMMCTradingAccountKey;
		gcroot<Internal_RspQryEWarrantOffset^> d_RspQryEWarrantOffset;
		gcroot<Internal_RspQryInvestorProductGroupMargin^> d_RspQryInvestorProductGroupMargin;
		gcroot<Internal_RspQryExchangeMarginRate^> d_RspQryExchangeMarginRate;
		gcroot<Internal_RspQryExchangeMarginRateAdjust^> d_RspQryExchangeMarginRateAdjust;
		gcroot<Internal_RspQryExchangeRate^> d_RspQryExchangeRate;
		gcroot<Internal_RspQrySecAgentACIDMap^> d_RspQrySecAgentACIDMap;
		gcroot<Internal_RspQryTransferSerial^> d_RspQryTransferSerial;
		gcroot<Internal_RspQryAccountregister^> d_RspQryAccountregister;
		gcroot<Internal_RtnOrder^> d_RtnOrder;
		gcroot<Internal_RtnTrade^> d_RtnTrade;
		gcroot<Internal_ErrRtnOrderInsert^> d_ErrRtnOrderInsert;
		gcroot<Internal_ErrRtnOrderAction^> d_ErrRtnOrderAction;
		gcroot<Internal_RtnInstrumentStatus^> d_RtnInstrumentStatus;
		gcroot<Internal_RtnTradingNotice^> d_RtnTradingNotice;
		gcroot<Internal_RtnErrorConditionalOrder^> d_RtnErrorConditionalOrder;
		gcroot<Internal_RtnCFMMCTradingAccountToken^> d_RtnCFMMCTradingAccountToken;
		gcroot<Internal_RspQryContractBank^> d_RspQryContractBank;
		gcroot<Internal_RspQryParkedOrder^> d_RspQryParkedOrder;
		gcroot<Internal_RspQryParkedOrderAction^> d_RspQryParkedOrderAction;
		gcroot<Internal_RspQryTradingNotice^> d_RspQryTradingNotice;
		gcroot<Internal_RspQryBrokerTradingParams^> d_RspQryBrokerTradingParams;
		gcroot<Internal_RspQryBrokerTradingAlgos^> d_RspQryBrokerTradingAlgos;
		gcroot<Internal_RspQueryCFMMCTradingAccountToken^> d_RspQueryCFMMCTradingAccountToken;
		gcroot<Internal_RtnFromBankToFutureByBank^> d_RtnFromBankToFutureByBank;
		gcroot<Internal_RtnFromFutureToBankByBank^> d_RtnFromFutureToBankByBank;
		gcroot<Internal_RtnRepealFromBankToFutureByBank^> d_RtnRepealFromBankToFutureByBank;
		gcroot<Internal_RtnRepealFromFutureToBankByBank^> d_RtnRepealFromFutureToBankByBank;
		gcroot<Internal_RtnFromBankToFutureByFuture^> d_RtnFromBankToFutureByFuture;
		gcroot<Internal_RtnFromFutureToBankByFuture^> d_RtnFromFutureToBankByFuture;
		gcroot<Internal_RtnRepealFromBankToFutureByFutureManual^> d_RtnRepealFromBankToFutureByFutureManual;
		gcroot<Internal_RtnRepealFromFutureToBankByFutureManual^> d_RtnRepealFromFutureToBankByFutureManual;
		gcroot<Internal_RtnQueryBankBalanceByFuture^> d_RtnQueryBankBalanceByFuture;
		gcroot<Internal_ErrRtnBankToFutureByFuture^> d_ErrRtnBankToFutureByFuture;
		gcroot<Internal_ErrRtnFutureToBankByFuture^> d_ErrRtnFutureToBankByFuture;
		gcroot<Internal_ErrRtnRepealBankToFutureByFutureManual^> d_ErrRtnRepealBankToFutureByFutureManual;
		gcroot<Internal_ErrRtnRepealFutureToBankByFutureManual^> d_ErrRtnRepealFutureToBankByFutureManual;
		gcroot<Internal_ErrRtnQueryBankBalanceByFuture^> d_ErrRtnQueryBankBalanceByFuture;
		gcroot<Internal_RtnRepealFromBankToFutureByFuture^> d_RtnRepealFromBankToFutureByFuture;
		gcroot<Internal_RtnRepealFromFutureToBankByFuture^> d_RtnRepealFromFutureToBankByFuture;
		gcroot<Internal_RspFromBankToFutureByFuture^> d_RspFromBankToFutureByFuture;
		gcroot<Internal_RspFromFutureToBankByFuture^> d_RspFromFutureToBankByFuture;
		gcroot<Internal_RspQueryBankAccountMoneyByFuture^> d_RspQueryBankAccountMoneyByFuture;
		gcroot<Internal_RtnOpenAccountByBank^> d_RtnOpenAccountByBank;
		gcroot<Internal_RtnCancelAccountByBank^> d_RtnCancelAccountByBank;
		gcroot<Internal_RtnChangeAccountByBank^> d_RtnChangeAccountByBank;
#else
protected:
		gcroot<CTPTraderAdapter^> m_pAdapter;
#endif

	};

};