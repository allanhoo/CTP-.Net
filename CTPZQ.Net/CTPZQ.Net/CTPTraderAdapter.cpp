#include "stdafx.h"
#include "CTPTraderAdapter.h"
#include "Util.h"
#include "TraderSpi.h"
#include "CTPMDAdapter.h"

namespace CTPZQ
{

	CTPTraderAdapter::CTPTraderAdapter()
		: CTPTraderAdapter("")
	{
	}

	CTPTraderAdapter::CTPTraderAdapter(String^ pszFlowPath)
	{
		CAutoStrPtr asp(pszFlowPath);
		m_pApi = CZQThostFtdcTraderApi::CreateFtdcTraderApi(asp.m_pChar);
		m_pSpi = new CTraderSpi(this);
		m_pApi->RegisterSpi(m_pSpi);
	}

	CTPTraderAdapter::~CTPTraderAdapter()
	{
		Release();
	}

	String^ CTPTraderAdapter::GetCtpVersionDate()
	{
		return CTPMDAdapter::_CTPVersionDate;
	}

	void CTPTraderAdapter::Release(void)
	{
		if (m_pApi)
		{
			m_pApi->RegisterSpi(0);
			m_pApi->Release();
			m_pApi = nullptr;
			delete m_pSpi;
			m_pSpi = nullptr;
		}
	}

	///注册前置机网络地址
	void CTPTraderAdapter::RegisterFront(String^  pszFrontAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszFrontAddress);
		m_pApi->RegisterFront(asp.m_pChar);
	}

	///订阅私有流。
	void CTPTraderAdapter::SubscribePrivateTopic(EnumTeResumeType nResumeType)
	{
		m_pApi->SubscribePrivateTopic((ZQTHOST_TE_RESUME_TYPE)nResumeType);
	}
	///订阅公共流
	void CTPTraderAdapter::SubscribePublicTopic(EnumTeResumeType nResumeType)
	{
		m_pApi->SubscribePublicTopic((ZQTHOST_TE_RESUME_TYPE)nResumeType);
	}

	void CTPTraderAdapter::Init(void)
	{
		m_pApi->Init();
	}

	int CTPTraderAdapter::Join(void)
	{
		return m_pApi->Join();
	}

	String^ CTPTraderAdapter::GetTradingDay()
	{
		return gcnew String(m_pApi->GetTradingDay());
	}
	///客户端认证请求
	int CTPTraderAdapter::ReqAuthenticate(ThostFtdcReqAuthenticateField^ pReqAuthenticateField, int nRequestID){
		CZQThostFtdcReqAuthenticateField native;
		MNConv<ThostFtdcReqAuthenticateField^, CZQThostFtdcReqAuthenticateField>::M2N(pReqAuthenticateField, &native);
		return m_pApi->ReqAuthenticate(&native, nRequestID);
	}
	///用户登录请求
	int CTPTraderAdapter::ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		CZQThostFtdcReqUserLoginField native;
		MNConv<ThostFtdcReqUserLoginField^, CZQThostFtdcReqUserLoginField>::M2N(pReqUserLoginField, &native);
		return m_pApi->ReqUserLogin(&native, nRequestID);
	}
	///登出请求
	int CTPTraderAdapter::ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID)
	{
		CZQThostFtdcUserLogoutField native;
		MNConv<ThostFtdcUserLogoutField^, CZQThostFtdcUserLogoutField>::M2N(pUserLogout, &native);
		return m_pApi->ReqUserLogout(&native, nRequestID);
	}
	///用户口令更新请求
	int CTPTraderAdapter::ReqUserPasswordUpdate(ThostFtdcUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID)
	{
		CZQThostFtdcUserPasswordUpdateField native;
		MNConv<ThostFtdcUserPasswordUpdateField^, CZQThostFtdcUserPasswordUpdateField>::M2N(pUserPasswordUpdate, &native);
		return m_pApi->ReqUserPasswordUpdate(&native, nRequestID);
	}
	///资金账户口令更新请求
	int CTPTraderAdapter::ReqTradingAccountPasswordUpdate(ThostFtdcTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID)
	{
		CZQThostFtdcTradingAccountPasswordUpdateField native;
		MNConv<ThostFtdcTradingAccountPasswordUpdateField^, CZQThostFtdcTradingAccountPasswordUpdateField>::M2N(pTradingAccountPasswordUpdate, &native);
		return m_pApi->ReqTradingAccountPasswordUpdate(&native, nRequestID);
	}
	///报单录入请求
	int CTPTraderAdapter::ReqOrderInsert(ThostFtdcInputOrderField^ pInputOrder, int nRequestID)
	{
		CZQThostFtdcInputOrderField native;
		MNConv<ThostFtdcInputOrderField^, CZQThostFtdcInputOrderField>::M2N(pInputOrder, &native);
		return m_pApi->ReqOrderInsert(&native, nRequestID);
	}
	///报单操作请求
	int CTPTraderAdapter::ReqOrderAction(ThostFtdcInputOrderActionField^ pInputOrderAction, int nRequestID)
	{
		CZQThostFtdcInputOrderActionField native;
		MNConv<ThostFtdcInputOrderActionField^, CZQThostFtdcInputOrderActionField>::M2N(pInputOrderAction, &native);
		return m_pApi->ReqOrderAction(&native, nRequestID);
	}
	///请求查询报单
	int CTPTraderAdapter::ReqQryOrder(ThostFtdcQryOrderField^ pQryOrder, int nRequestID)
	{
		CZQThostFtdcQryOrderField native;
		MNConv<ThostFtdcQryOrderField^, CZQThostFtdcQryOrderField>::M2N(pQryOrder, &native);
		return m_pApi->ReqQryOrder(&native, nRequestID);
	}
	///请求查询成交
	int CTPTraderAdapter::ReqQryTrade(ThostFtdcQryTradeField^ pQryTrade, int nRequestID)
	{
		CZQThostFtdcQryTradeField native;
		MNConv<ThostFtdcQryTradeField^, CZQThostFtdcQryTradeField>::M2N(pQryTrade, &native);
		return m_pApi->ReqQryTrade(&native, nRequestID);
	}
	///请求查询投资者持仓
	int CTPTraderAdapter::ReqQryInvestorPosition(ThostFtdcQryInvestorPositionField^ pQryInvestorPosition, int nRequestID)
	{
		CZQThostFtdcQryInvestorPositionField native;
		MNConv<ThostFtdcQryInvestorPositionField^, CZQThostFtdcQryInvestorPositionField>::M2N(pQryInvestorPosition, &native);
		return m_pApi->ReqQryInvestorPosition(&native, nRequestID);
	}
	///请求查询资金账户
	int CTPTraderAdapter::ReqQryTradingAccount(ThostFtdcQryTradingAccountField^ pQryTradingAccount, int nRequestID)
	{
		CZQThostFtdcQryTradingAccountField native;
		MNConv<ThostFtdcQryTradingAccountField^, CZQThostFtdcQryTradingAccountField>::M2N(pQryTradingAccount, &native);
		return m_pApi->ReqQryTradingAccount(&native, nRequestID);
	}
	///请求查询投资者
	int CTPTraderAdapter::ReqQryInvestor(ThostFtdcQryInvestorField^ pQryInvestor, int nRequestID)
	{
		CZQThostFtdcQryInvestorField native;
		MNConv<ThostFtdcQryInvestorField^, CZQThostFtdcQryInvestorField>::M2N(pQryInvestor, &native);
		return m_pApi->ReqQryInvestor(&native, nRequestID);
	}
	///请求查询交易编码
	int CTPTraderAdapter::ReqQryTradingCode(ThostFtdcQryTradingCodeField^ pQryTradingCode, int nRequestID)
	{
		CZQThostFtdcQryTradingCodeField native;
		MNConv<ThostFtdcQryTradingCodeField^, CZQThostFtdcQryTradingCodeField>::M2N(pQryTradingCode, &native);
		return m_pApi->ReqQryTradingCode(&native, nRequestID);
	}
	///请求查询合约手续费率
	int CTPTraderAdapter::ReqQryInstrumentCommissionRate(ThostFtdcQryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID)
	{
		CZQThostFtdcQryInstrumentCommissionRateField native;
		MNConv<ThostFtdcQryInstrumentCommissionRateField^, CZQThostFtdcQryInstrumentCommissionRateField>::M2N(pQryInstrumentCommissionRate, &native);
		return m_pApi->ReqQryInstrumentCommissionRate(&native, nRequestID);
	}
	///请求查询交易所
	int CTPTraderAdapter::ReqQryExchange(ThostFtdcQryExchangeField^ pQryExchange, int nRequestID)
	{
		CZQThostFtdcQryExchangeField native;
		MNConv<ThostFtdcQryExchangeField^, CZQThostFtdcQryExchangeField>::M2N(pQryExchange, &native);
		return m_pApi->ReqQryExchange(&native, nRequestID);
	}
	///请求查询合约
	int CTPTraderAdapter::ReqQryInstrument(ThostFtdcQryInstrumentField^ pQryInstrument, int nRequestID)
	{
		CZQThostFtdcQryInstrumentField native;
		MNConv<ThostFtdcQryInstrumentField^, CZQThostFtdcQryInstrumentField>::M2N(pQryInstrument, &native);
		return m_pApi->ReqQryInstrument(&native, nRequestID);
	}
	///请求查询行情
	int CTPTraderAdapter::ReqQryDepthMarketData(ThostFtdcQryDepthMarketDataField^ pQryDepthMarketData, int nRequestID)
	{
		CZQThostFtdcQryDepthMarketDataField native;
		MNConv<ThostFtdcQryDepthMarketDataField^, CZQThostFtdcQryDepthMarketDataField>::M2N(pQryDepthMarketData, &native);
		return m_pApi->ReqQryDepthMarketData(&native, nRequestID);
	}
	///请求查询投资者持仓明细
	int CTPTraderAdapter::ReqQryInvestorPositionDetail(ThostFtdcQryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID)
	{
		CZQThostFtdcQryInvestorPositionDetailField native;
		MNConv<ThostFtdcQryInvestorPositionDetailField^, CZQThostFtdcQryInvestorPositionDetailField>::M2N(pQryInvestorPositionDetail, &native);
		return m_pApi->ReqQryInvestorPositionDetail(&native, nRequestID);
	}

	///请求查询债券利息
	int CTPTraderAdapter::ReqQryBondInterest(ThostFtdcQryBondInterestField^ pQryBondInterest, int nRequestID)
	{
		CZQThostFtdcQryBondInterestField native;
		MNConv<ThostFtdcQryBondInterestField^, CZQThostFtdcQryBondInterestField>::M2N(pQryBondInterest, &native);
		return m_pApi->ReqQryBondInterest(&native, nRequestID);
	}

	///请求查询新股申购报单
	int CTPTraderAdapter::ReqQrySubscribingSharesOrder(ThostFtdcQryOrderField^ pQryOrder, int nRequestID)
	{
		CZQThostFtdcQryOrderField native;
		MNConv<ThostFtdcQryOrderField^, CZQThostFtdcQryOrderField>::M2N(pQryOrder, &native);
		return m_pApi->ReqQrySubscribingSharesOrder(&native, nRequestID);
	}
	///资金转出CTP请求请求
	int CTPTraderAdapter::ReqFundOutCTPAccount(ThostFtdcReqFundIOCTPAccountField^ pReqFundIOCTPAccount, int nRequestID)
	{
		CZQThostFtdcReqFundIOCTPAccountField native;
		MNConv<ThostFtdcReqFundIOCTPAccountField^, CZQThostFtdcReqFundIOCTPAccountField>::M2N(pReqFundIOCTPAccount, &native);
		return m_pApi->ReqFundOutCTPAccount(&native, nRequestID);
	}

	///资金转入转出CTP查询请求
	int CTPTraderAdapter::ReqQryFundIOCTPAccount(ThostFtdcQryFundIOCTPAccountField^ pQryFundIOCTPAccount, int nRequestID)
	{
		CZQThostFtdcQryFundIOCTPAccountField native;
		MNConv<ThostFtdcQryFundIOCTPAccountField^, CZQThostFtdcQryFundIOCTPAccountField>::M2N(pQryFundIOCTPAccount, &native);
		return m_pApi->ReqQryFundIOCTPAccount(&native, nRequestID);
	}

} //end of  namespace