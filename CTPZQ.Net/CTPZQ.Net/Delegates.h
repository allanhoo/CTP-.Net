/////////////////////////////////////////////////////////////////////////
/// CTP证券 C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20140906
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Struct.h"


namespace CTPZQ
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
	/// 所有的OnErrRtn****回调事件
	/// </summary>
	public enum struct CtpEnumErrRtnType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 报单操作错误回报，ThostFtdcOrderActionField
		/// </summary>
		ErrRtnOrderAction,
		/// <summary>
		/// 报单录入错误回报，ThostFtdcInputOrderField
		/// </summary>
		ErrRtnOrderInsert,
	};


	/// <summary>
	/// 所有的OnRtn****回调事件
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
		/// 合约交易状态通知，ThostFtdcInstrumentStatusField
		/// </summary>
		RtnInstrumentStatus,
		/// <summary>
		/// 报单通知，ThostFtdcOrderField
		/// </summary>
		RtnOrder,
		/// <summary>
		/// 成交通知，ThostFtdcTradeField
		/// </summary>
		RtnTrade,
		/// <summary>
		/// 投资者新股申购额度通知, ThostFtdcInvestorSubscribingSharesQuotaField
		/// </summary>
		RtnInvestorSubscribingSharesQuota,
		/// <summary>
		/// 资金转入CTP通知, ThostFtdcFundIOCTPAccountField
		/// </summary>
		RtnFundIntoCTPAccount,
		/// <summary>
		/// 资金转出CTP通知, ThostFtdcFundIOCTPAccountField
		/// </summary>
		RtnFundOutCTPAccount,

	};

	/// <summary>
	/// 所有的OnRspQry****回调事件
	/// </summary>
	public enum struct CtpEnumRspQryType
	{
		/// <summary>
		/// 未使用,保留
		/// </summary>
		None,
		/// <summary>
		/// 请求查询行情响应，ThostFtdcDepthMarketDataField
		/// </summary>
		RspQryDepthMarketData,
		/// <summary>
		/// 请求查询交易所响应，ThostFtdcExchangeField
		/// </summary>
		RspQryExchange,
		/// <summary>
		/// 请求查询债券利息响应，ThostFtdcBondInterestField
		/// </summary>
		RspQryBondInterest,
		/// <summary>
		/// 请求查询合约响应，ThostFtdcInstrumentField
		/// </summary>
		RspQryInstrument,
		/// <summary>
		/// 请求查询合约手续费率响应，ThostFtdcInstrumentCommissionRateField
		/// </summary>
		RspQryInstrumentCommissionRate,
		/// <summary>
		/// 请求查询投资者响应，ThostFtdcInvestorField
		/// </summary>
		RspQryInvestor,
		/// <summary>
		/// 请求查询投资者持仓响应，ThostFtdcInvestorPositionField
		/// </summary>
		RspQryInvestorPosition,
		/// <summary>
		/// 请求查询投资者持仓明细响应，ThostFtdcInvestorPositionDetailField
		/// </summary>
		RspQryInvestorPositionDetail,
		/// <summary>
		/// 请求查询报单响应，ThostFtdcOrderField
		/// </summary>
		RspQryOrder,
		/// <summary>
		/// 请求查询新股申购报单响应，ThostFtdcOrderField
		/// </summary>
		RspQrySubscribingSharesOrder,
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
		/// 资金转出CTP请求应答, ThostFtdcRspFundIOCTPAccountField
		/// </summary>
		RspFundOutCTPAccount,
		/// <summary>
		//资金转入转出CTP查询应答, ThostFtdcFundIOCTPAccountField
		/// </summary>
		RspQryFundIOCTPAccount,

	};


	/// <summary>
	/// 除了OnRspQry****之外，其他OnRsp****回调函数，其中RspError的Param参数为空
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
		/// 报单操作请求响应，ThostFtdcInputOrderActionField
		/// </summary>
		RspOrderAction,
		/// <summary>
		/// 报单录入请求响应，ThostFtdcInputOrderField
		/// </summary>
		RspOrderInsert,
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
		/// 取消订阅行情应答，ThostFtdcSpecificInstrumentField
		/// </summary>
		RspUnSubMarketData,
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


