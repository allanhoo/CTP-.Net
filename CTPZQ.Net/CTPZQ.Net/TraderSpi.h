/////////////////////////////////////////////////////////////////////////
/// CTP证券 C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20140906
/////////////////////////////////////////////////////////////////////////
#pragma once

#include <vcclr.h>
#include "CTPTraderAdapter.h"
#include "ThostFtdcTraderApiSSE.h"


namespace Native
{
	using namespace CTPZQ;

	class CTraderSpi : public CZQThostFtdcTraderSpi
	{
	public:
		/// 构造函数
		CTraderSpi(CTPTraderAdapter^ pAdapter);

		///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		virtual void OnFrontConnected();

		///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		virtual void OnFrontDisconnected(int nReason);

		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		virtual void OnHeartBeatWarning(int nTimeLapse);

		///客户端认证响应
		virtual void OnRspAuthenticate(CZQThostFtdcRspAuthenticateField *pRspAuthenticateField, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///登录请求响应
		virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///登出请求响应
		virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///用户口令更新请求响应
		virtual void OnRspUserPasswordUpdate(CZQThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///资金账户口令更新请求响应
		virtual void OnRspTradingAccountPasswordUpdate(CZQThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///报单录入请求响应
		virtual void OnRspOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///报单操作请求响应
		virtual void OnRspOrderAction(CZQThostFtdcInputOrderActionField *pInputOrderAction, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询报单响应
		virtual void OnRspQryOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询成交响应
		virtual void OnRspQryTrade(CZQThostFtdcTradeField *pTrade, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询投资者持仓响应
		virtual void OnRspQryInvestorPosition(CZQThostFtdcInvestorPositionField *pInvestorPosition, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询资金账户响应
		virtual void OnRspQryTradingAccount(CZQThostFtdcTradingAccountField *pTradingAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询投资者响应
		virtual void OnRspQryInvestor(CZQThostFtdcInvestorField *pInvestor, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询交易编码响应
		virtual void OnRspQryTradingCode(CZQThostFtdcTradingCodeField *pTradingCode, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询合约手续费率响应
		virtual void OnRspQryInstrumentCommissionRate(CZQThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询交易所响应
		virtual void OnRspQryExchange(CZQThostFtdcExchangeField *pExchange, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询合约响应
		virtual void OnRspQryInstrument(CZQThostFtdcInstrumentField *pInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询行情响应
		virtual void OnRspQryDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询投资者持仓明细响应
		virtual void OnRspQryInvestorPositionDetail(CZQThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询债券利息响应
		virtual void OnRspQryBondInterest(CZQThostFtdcBondInterestField *pBondInterest, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///请求查询新股申购报单响应
		virtual void OnRspQrySubscribingSharesOrder(CZQThostFtdcOrderField *pOrder, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///错误应答
		virtual void OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///报单通知
		virtual void OnRtnOrder(CZQThostFtdcOrderField *pOrder);

		///成交通知
		virtual void OnRtnTrade(CZQThostFtdcTradeField *pTrade);

		///报单录入错误回报
		virtual void OnErrRtnOrderInsert(CZQThostFtdcInputOrderField *pInputOrder, CZQThostFtdcRspInfoField *pRspInfo);

		///报单操作错误回报
		virtual void OnErrRtnOrderAction(CZQThostFtdcOrderActionField *pOrderAction, CZQThostFtdcRspInfoField *pRspInfo);

		///合约交易状态通知
		virtual void OnRtnInstrumentStatus(CZQThostFtdcInstrumentStatusField *pInstrumentStatus);

		///投资者新股申购额度通知
		virtual void OnRtnInvestorSubscribingSharesQuota(CZQThostFtdcInvestorSubscribingSharesQuotaField *pInvestorSubscribingSharesQuota);

		///资金转入CTP通知
		virtual void OnRtnFundIntoCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount);

		///资金转出CTP请求应答
		virtual void OnRspFundOutCTPAccount(CZQThostFtdcRspFundIOCTPAccountField *pRspFundIOCTPAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///资金转出CTP通知
		virtual void OnRtnFundOutCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount);

		///资金转入转出CTP查询应答
		virtual void OnRspQryFundIOCTPAccount(CZQThostFtdcFundIOCTPAccountField *pFundIOCTPAccount, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	protected:
		gcroot<CTPTraderAdapter^> m_pAdapter;
	};

};// end of namespace