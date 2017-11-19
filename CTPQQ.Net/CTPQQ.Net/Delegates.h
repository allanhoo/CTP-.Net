/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20120420
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "Struct.h"
#include "ThostFtdcUserApiStruct.h"

namespace CTPQQ
{
	public enum struct CtpEnumFrontType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该事件发生
		/// </summary>
		FrontConnected,
		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该事件发生。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		FrontDisconnected,
	};

	/// <summary>
	/// 所有的OnErrRtn****回调事件，不含None共7
	/// </summary>
	public enum struct CtpEnumErrRtnType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 期货发起银行资金转期货错误回报，ThostFtdcReqTransferField
		/// </summary>
		ErrRtnBankToFutureByFuture,
		/// <summary>
		/// 期货发起期货资金转银行错误回报，ThostFtdcReqTransferField
		/// </summary>
		ErrRtnFutureToBankByFuture,
		/// <summary>
		/// 报单操作错误回报，ThostFtdcOrderActionField
		/// </summary>
		ErrRtnOrderAction,
		/// <summary>
		/// 报单录入错误回报，ThostFtdcInputOrderField
		/// </summary>
		ErrRtnOrderInsert,
		/// <summary>
		/// 期货发起查询银行余额错误回报，ThostFtdcReqQueryAccountField
		/// </summary>
		ErrRtnQueryBankBalanceByFuture,
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报，ThostFtdcReqRepealField
		/// </summary>
		ErrRtnRepealBankToFutureByFutureManual,
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报，ThostFtdcReqRepealField
		/// </summary>
		ErrRtnRepealFutureToBankByFutureManual,
		/// <summary>
		/// 执行宣告录入错误回报, ThostFtdcInputExecOrderField
		/// </summary>
		ErrRtnExecOrderInsert,
		/// <summary>
		/// 执行宣告操作错误回报, ThostFtdcExecOrderActionField
		/// </summary>
		ErrRtnExecOrderAction,
		/// <summary>
		/// 询价录入错误回报, ThostFtdcInputForQuoteField
		/// </summary>
		ErrRtnForQuoteInsert,
		/// <summary>
		/// 报价录入错误回报, ThostFtdcInputQuoteField
		/// </summary>
		ErrRtnQuoteInsert,
		/// <summary>
		/// 报价操作错误回报, ThostFtdcQuoteActionField
		/// </summary>
		ErrRtnQuoteAction,
	};


	/// <summary>
	/// 所有的OnRtn****回调事件, 交易接口不含None共19个，行情接口不含None共1个RtnDepthMarketData
	/// </summary>
	public enum struct CtpEnumRtnType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 深度行情通知，仅用于行情接口，ThostFtdcDepthMarketDataField
		/// </summary>
		RtnDepthMarketData,
		/// <summary>
		/// 询价通知，仅用于行情接口，ThostFtdcForQuoteRspField
		/// </summary>
		RtnForQuoteRsp,
		/// <summary>
		/// 银行发起银期销户通知，ThostFtdcCancelAccountField
		/// </summary>
		RtnCancelAccountByBank,
		/// <summary>
		/// 银行发起变更银行账号通知，ThostFtdcChangeAccountField
		/// </summary>
		RtnChangeAccountByBank,
		/// <summary>
		/// 提示条件单校验错误，ThostFtdcErrorConditionalOrderField
		/// </summary>
		RtnErrorConditionalOrder,
		/// <summary>
		/// 执行宣告通知, ThostFtdcExecOrderField
		/// </summary>
		RtnExecOrder,
		/// <summary>
		/// 报价通知, ThostFtdcQuoteField
		/// </summary>
		RtnQuote,
		/// <summary>
		/// 银行发起银行资金转期货通知，ThostFtdcRspTransferField
		/// </summary>
		RtnFromBankToFutureByBank,
		/// <summary>
		/// 期货发起银行资金转期货通知，ThostFtdcRspTransferField
		/// </summary>
		RtnFromBankToFutureByFuture,
		/// <summary>
		/// 银行发起期货资金转银行通知，ThostFtdcRspTransferField
		/// </summary>
		RtnFromFutureToBankByBank,
		/// <summary>
		/// 期货发起期货资金转银行通知，ThostFtdcRspTransferField
		/// </summary>
		RtnFromFutureToBankByFuture,
		/// <summary>
		/// 合约交易状态通知，ThostFtdcInstrumentStatusField
		/// </summary>
		RtnInstrumentStatus,
		/// <summary>
		/// 银行发起银期开户通知，ThostFtdcOpenAccountField
		/// </summary>
		RtnOpenAccountByBank,
		/// <summary>
		/// 报单通知，ThostFtdcOrderField
		/// </summary>
		RtnOrder,
		/// <summary>
		/// 期货发起查询银行余额通知，ThostFtdcNotifyQueryAccountField
		/// </summary>
		RtnQueryBankBalanceByFuture,
		/// <summary>
		/// 银行发起冲正银行转期货通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromBankToFutureByBank,
		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromBankToFutureByFuture,
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromBankToFutureByFutureManual,
		/// <summary>
		/// 银行发起冲正期货转银行通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromFutureToBankByBank,
		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromFutureToBankByFuture,
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知，ThostFtdcRspRepealField
		/// </summary>
		RtnRepealFromFutureToBankByFutureManual,
		/// <summary>
		/// 成交通知，ThostFtdcTradeField
		/// </summary>
		RtnTrade,
		/// <summary>
		/// 交易通知，ThostFtdcTradingNoticeInfoField
		/// </summary>
		RtnTradingNotice,
	};

	/// <summary>
	/// 所有的OnRspQry****回调事件,不含None共35
	/// </summary>
	public enum struct CtpEnumRspQryType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 请求查询银期签约关系响应，ThostFtdcAccountregisterField
		/// </summary>
		RspQryAccountregister,
		/// <summary>
		/// 请求查询经纪公司交易算法响应，ThostFtdcBrokerTradingAlgosField
		/// </summary>
		RspQryBrokerTradingAlgos,
		/// <summary>
		/// 请求查询经纪公司交易参数响应，ThostFtdcBrokerTradingParamsField
		/// </summary>
		RspQryBrokerTradingParams,
		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应，ThostFtdcCFMMCTradingAccountKeyField
		/// </summary>
		RspQryCFMMCTradingAccountKey,
		/// <summary>
		/// 请求查询签约银行响应，ThostFtdcContractBankField
		/// </summary>
		RspQryContractBank,
		/// <summary>
		/// 请求查询行情响应，ThostFtdcDepthMarketDataField
		/// </summary>
		RspQryDepthMarketData,
		/// <summary>
		/// 请求查询仓单折抵信息响应，ThostFtdcEWarrantOffsetField
		/// </summary>
		RspQryEWarrantOffset,
		/// <summary>
		/// 请求查询交易所响应，ThostFtdcExchangeField
		/// </summary>
		RspQryExchange,
		/// <summary>
		/// 请求查询交易所保证金率响应，ThostFtdcExchangeMarginRateField
		/// </summary>
		RspQryExchangeMarginRate,
		/// <summary>
		/// 请求查询交易所调整保证金率响应，ThostFtdcExchangeMarginRateAdjustField
		/// </summary>
		RspQryExchangeMarginRateAdjust,
		/// <summary>
		/// 请求查询汇率响应，ThostFtdcExchangeRateField
		/// </summary>
		RspQryExchangeRate,
		/// <summary>
		/// 请求查询合约响应，ThostFtdcInstrumentField
		/// </summary>
		RspQryInstrument,
		/// <summary>
		/// 请求查询合约手续费率响应，ThostFtdcInstrumentCommissionRateField
		/// </summary>
		RspQryInstrumentCommissionRate,
		/// <summary>
		/// 请求查询合约保证金率响应，ThostFtdcInstrumentMarginRateField
		/// </summary>
		RspQryInstrumentMarginRate,
		/// <summary>
		/// 请求查询投资者响应，ThostFtdcInvestorField
		/// </summary>
		RspQryInvestor,
		/// <summary>
		/// 请求查询投资者持仓响应，ThostFtdcInvestorPositionField
		/// </summary>
		RspQryInvestorPosition,
		/// <summary>
		/// 请求查询投资者持仓明细响应，ThostFtdcInvestorPositionCombineDetailField
		/// </summary>
		RspQryInvestorPositionCombineDetail,
		/// <summary>
		/// 请求查询投资者持仓明细响应，ThostFtdcInvestorPositionDetailField
		/// </summary>
		RspQryInvestorPositionDetail,
		/// <summary>
		/// 请求查询投资者品种 / 跨品种保证金响应，ThostFtdcInvestorProductGroupMarginField
		/// </summary>
		RspQryInvestorProductGroupMargin,
		/// <summary>
		/// 请求查询客户通知响应，ThostFtdcNoticeField
		/// </summary>
		RspQryNotice,
		/// <summary>
		/// 请求查询报单响应，ThostFtdcOrderField
		/// </summary>
		RspQryOrder,
		/// <summary>
		/// 请求查询预埋单响应，ThostFtdcParkedOrderField
		/// </summary>
		RspQryParkedOrder,
		/// <summary>
		/// 请求查询预埋撤单响应，ThostFtdcParkedOrderActionField
		/// </summary>
		RspQryParkedOrderAction,
		/// <summary>
		/// 请求查询产品响应，ThostFtdcProductField
		/// </summary>
		RspQryProduct,
		/// <summary>
		/// 请求查询二级代理操作员银期权限响应，ThostFtdcSecAgentACIDMapField
		/// </summary>
		RspQrySecAgentACIDMap,
		/// <summary>
		/// 请求查询期权交易成本响应, ThostFtdcOptionInstrTradeCostField
		/// </summary>
		RspQryOptionInstrTradeCost,
		/// <summary>
		/// 请求查询期权合约手续费响应, ThostFtdcOptionInstrCommRateField
		/// </summary>
		RspQryOptionInstrCommRate,
		/// <summary>
		/// 请求查询执行宣告响应, ThostFtdcExecOrderField
		/// </summary>
		RspQryExecOrder,
		/// <summary>
		/// 请求查询询价响应, ThostFtdcForQuoteField
		/// </summary>
		RspQryForQuote,
		/// <summary>
		/// 请求查询报价响应, ThostFtdcQuoteField
		/// </summary>
		RspQryQuote,
		/// <summary>
		/// 请求查询投资者结算结果响应，ThostFtdcSettlementInfoField
		/// </summary>
		RspQrySettlementInfo,
		/// <summary>
		/// 请求查询结算信息确认响应，ThostFtdcSettlementInfoConfirmField
		/// </summary>
		RspQrySettlementInfoConfirm,
		/// <summary>
		/// 请求查询成交响应，ThostFtdcTradeField
		/// </summary>
		RspQryTrade,
		/// <summary>
		/// 请求查询资金账户响应，ThostFtdcTradingAccountField
		/// </summary>
		RspQryTradingAccount,
		/// <summary>
		/// 请求查询交易编码响应，ThostFtdcTradingCodeField
		/// </summary>
		RspQryTradingCode,
		/// <summary>
		/// 请求查询交易通知响应，ThostFtdcTradingNoticeField
		/// </summary>
		RspQryTradingNotice,
		/// <summary>
		/// 请求查询转帐银行响应，ThostFtdcTransferBankField
		/// </summary>
		RspQryTransferBank,
		/// <summary>
		/// 请求查询转帐流水响应，ThostFtdcTransferSerialField
		/// </summary>
		RspQryTransferSerial,
		/// <summary>
		/// 期货发起查询银行余额应答，ThostFtdcReqQueryAccountField
		/// </summary>
		RspQryBankAccountMoneyByFuture,
		/// <summary>
		/// 查询最大报单数量响应，ThostFtdcQueryMaxOrderVolumeField
		/// </summary>
		RspQryMaxOrderVolume,
	};


	/// <summary>
	/// 除了OnRspQry****之外，其他OnRsp****回调函数，其中RspError的Param参数为空，交易接口不含None共15个，行情接口不含None共5个
	/// </summary>
	public enum struct CtpEnumRspType
	{
		/// <summary>
		/// 未使用
		/// </summary>
		None,
		/// <summary>
		/// 错误应答，Param参数为空
		/// </summary>
		RspError,
		/// <summary>
		/// 客户端认证响应，ThostFtdcRspAuthenticateField
		/// </summary>
		RspAuthenticate,
		/// <summary>
		/// 期货发起银行资金转期货应答，ThostFtdcReqTransferField
		/// </summary>
		RspFromBankToFutureByFuture,
		/// <summary>
		/// 期货发起期货资金转银行应答，ThostFtdcReqTransferField
		/// </summary>
		RspFromFutureToBankByFuture,
		/// <summary>
		/// 报单操作请求响应，ThostFtdcInputOrderActionField
		/// </summary>
		RspOrderAction,
		/// <summary>
		/// 报单录入请求响应，ThostFtdcInputOrderField
		/// </summary>
		RspOrderInsert,
		/// <summary>
		/// 预埋撤单录入请求响应，ThostFtdcParkedOrderActionField
		/// </summary>
		RspParkedOrderAction,
		/// <summary>
		/// 预埋单录入请求响应，ThostFtdcParkedOrderField
		/// </summary>
		RspParkedOrderInsert,
		/// <summary>
		/// 删除预埋单响应，ThostFtdcRemoveParkedOrderField
		/// </summary>
		RspRemoveParkedOrder,
		/// <summary>
		/// 删除预埋撤单响应，ThostFtdcRemoveParkedOrderActionField
		/// </summary>
		RspRemoveParkedOrderAction,
		/// <summary>
		/// 执行宣告录入请求响应, ThostFtdcInputExecOrderField, 
		/// </summary>
		RspExecOrderInsert,

		/// <summary>
		/// 执行宣告操作请求响应, ThostFtdcInputExecOrderActionField
		/// </summary> 
		RspExecOrderAction,

		/// <summary>
		/// 询价录入请求响应, ThostFtdcInputForQuoteField
		/// </summary> 
		RspForQuoteInsert,

		/// <summary>
		/// 报价录入请求响应, ThostFtdcInputQuoteField
		/// </summary> 
		RspQuoteInsert,

		/// <summary>
		/// 报价操作请求响应, ThostFtdcInputQuoteActionField
		/// </summary> 
		RspQuoteAction,

		/// <summary>
		/// 投资者结算结果确认响应，ThostFtdcSettlementInfoConfirmField
		/// </summary>
		RspSettlementInfoConfirm,
		/// <summary>
		/// 资金账户口令更新请求响应，ThostFtdcTradingAccountPasswordUpdateField
		/// </summary>
		RspTradingAccountPasswordUpdate,
		/// <summary>
		/// 登录请求响应，ThostFtdcRspUserLoginField
		/// </summary>
		RspUserLogin,
		/// <summary>
		/// 登出请求响应，ThostFtdcUserLogoutField
		/// </summary>
		RspUserLogout,
		/// <summary>
		/// 用户口令更新请求响应，ThostFtdcUserPasswordUpdateField
		/// </summary>
		RspUserPasswordUpdate,
		/// <summary>
		/// 订阅行情应答，ThostFtdcSpecificInstrumentField
		/// </summary>
		RspSubMarketData,
		/// <summary>
		/// 订阅询价应答，ThostFtdcSpecificInstrumentField
		/// </summary>
		RspSubForQuoteRsp,
		/// <summary>
		/// 取消订阅行情应答，ThostFtdcSpecificInstrumentField
		/// </summary>
		RspUnSubMarketData,
		/// <summary>
		/// 取消订阅询价应答，ThostFtdcSpecificInstrumentField
		/// </summary>
		RspUnSubForQuoteRsp,
	};

	public ref class CtpFrontEventArgs : EventArgs
	{
	public:
		property CtpEnumFrontType EventType;
		property int Reason;

		CtpFrontEventArgs(CtpEnumFrontType EventType, int Reason)
		{
			this->EventType = EventType;
			this->Reason = Reason;
		}
	};

	public ref class CtpErrRtnEventArgs : EventArgs
	{
	public:
		property CtpEnumErrRtnType EventType;
		property ThostFtdcRspInfoField^ RspInfo;
		property Object^ Param;

		CtpErrRtnEventArgs(CtpEnumErrRtnType EventType, Object^ Param, ThostFtdcRspInfoField^ pRspInfo)
		{
			this->EventType = EventType;
			this->Param = Param;
			this->RspInfo = pRspInfo;
		}
	};

	public ref class CtpRtnEventArgs : EventArgs
	{
	public:
		property CtpEnumRtnType EventType;
		property Object^ Param;

		CtpRtnEventArgs(CtpEnumRtnType EventType, Object^ Param)
		{
			this->EventType = EventType;
			this->Param = Param;
		}
	};

	public ref class CtpRspQryEventArgs : EventArgs
	{
	public:
		property CtpEnumRspQryType EventType;
		property Object^ Param;
		property ThostFtdcRspInfoField^ RspInfo;
		property int RequestID;
		property bool IsLast;

		CtpRspQryEventArgs(CtpEnumRspQryType EventType, Object^ Param, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
		{
			this->EventType = EventType;
			this->Param = Param;
			this->RspInfo = pRspInfo;
			this->RequestID = nRequestID;
			this->IsLast = bIsLast;
		}
	};

	public ref class CtpRspEventArgs : EventArgs
	{
	public:
		property CtpEnumRspType EventType;
		property Object^ Param;
		property ThostFtdcRspInfoField^ RspInfo;
		property int RequestID;
		property bool IsLast;

		CtpRspEventArgs(CtpEnumRspType EventType, Object^ Param, ThostFtdcRspInfoField^ pRspInfo, int nRequestID, bool bIsLast)
		{
			this->EventType = EventType;
			this->Param = Param;
			this->RspInfo = pRspInfo;
			this->RequestID = nRequestID;
			this->IsLast = bIsLast;
		}
	};

	public delegate void CtpErrRtnEventHandler(Object^ sender, CtpErrRtnEventArgs^ e);
	public delegate void CtpFrontEventHandler(Object^ sender, CtpFrontEventArgs^ e);
	public delegate void CtpRspEventHandler(Object^ sender, CtpRspEventArgs^ e);
	public delegate void CtpRspQryEventHandler(Object^ sender, CtpRspQryEventArgs^ e);
	public delegate void CtpRtnEventHandler(Object^ sender, CtpRtnEventArgs^ e);

};

