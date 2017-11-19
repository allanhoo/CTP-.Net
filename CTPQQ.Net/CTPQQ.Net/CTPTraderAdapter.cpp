#include "stdafx.h"
#include "CTPTraderAdapter.h"
#include "Util.h"
#include "TraderSpi.h"

#include "CTPMDAdapter.h"

namespace CTPQQ
{

	CTPTraderAdapter::CTPTraderAdapter()
		: CTPTraderAdapter("")
	{
	}

	CTPTraderAdapter::CTPTraderAdapter(String^ pszFlowPath)
		: CTPTraderAdapter(pszFlowPath, false)
	{
	}

	CTPTraderAdapter::CTPTraderAdapter(String^ pszFlowPath, bool bIsUsingUdp)
	{
		CAutoStrPtr asp(pszFlowPath);
		m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi(asp.m_pChar);
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
	// 注册名字服务器网络地址
	void CTPTraderAdapter::RegisterNameServer(String^  pszNsAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszNsAddress);
		m_pApi->RegisterNameServer(asp.m_pChar);
	}

	// 注册名字服务器用户信息
	void CTPTraderAdapter::RegisterFensUserInfo(ThostFtdcFensUserInfoField^  pFensUserInfo)
	{
		CThostFtdcFensUserInfoField native;
		MNConv<ThostFtdcFensUserInfoField^, CThostFtdcFensUserInfoField>::M2N(pFensUserInfo, &native);
		m_pApi->RegisterFensUserInfo(&native);
	}

	///订阅私有流。
	void CTPTraderAdapter::SubscribePrivateTopic(EnumTeResumeType nResumeType)
	{
		m_pApi->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)nResumeType);
	}
	///订阅公共流
	void CTPTraderAdapter::SubscribePublicTopic(EnumTeResumeType nResumeType)
	{
		m_pApi->SubscribePublicTopic((THOST_TE_RESUME_TYPE)nResumeType);
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
		CThostFtdcReqAuthenticateField native;
		MNConv<ThostFtdcReqAuthenticateField^, CThostFtdcReqAuthenticateField>::M2N(pReqAuthenticateField, &native);
		return m_pApi->ReqAuthenticate(&native, nRequestID);
	}
	///用户登录请求
	int CTPTraderAdapter::ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		CThostFtdcReqUserLoginField native;
		MNConv<ThostFtdcReqUserLoginField^, CThostFtdcReqUserLoginField>::M2N(pReqUserLoginField, &native);
		return m_pApi->ReqUserLogin(&native, nRequestID);
	}
	///登出请求
	int CTPTraderAdapter::ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID)
	{
		CThostFtdcUserLogoutField native;
		MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::M2N(pUserLogout, &native);
		return m_pApi->ReqUserLogout(&native, nRequestID);
	}
	///用户口令更新请求
	int CTPTraderAdapter::ReqUserPasswordUpdate(ThostFtdcUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID)
	{
		CThostFtdcUserPasswordUpdateField native;
		MNConv<ThostFtdcUserPasswordUpdateField^, CThostFtdcUserPasswordUpdateField>::M2N(pUserPasswordUpdate, &native);
		return m_pApi->ReqUserPasswordUpdate(&native, nRequestID);
	}
	///资金账户口令更新请求
	int CTPTraderAdapter::ReqTradingAccountPasswordUpdate(ThostFtdcTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID)
	{
		CThostFtdcTradingAccountPasswordUpdateField native;
		MNConv<ThostFtdcTradingAccountPasswordUpdateField^, CThostFtdcTradingAccountPasswordUpdateField>::M2N(pTradingAccountPasswordUpdate, &native);
		return m_pApi->ReqTradingAccountPasswordUpdate(&native, nRequestID);
	}
	///报单录入请求
	int CTPTraderAdapter::ReqOrderInsert(ThostFtdcInputOrderField^ pInputOrder, int nRequestID)
	{
		CThostFtdcInputOrderField native;
		MNConv<ThostFtdcInputOrderField^, CThostFtdcInputOrderField>::M2N(pInputOrder, &native);
		return m_pApi->ReqOrderInsert(&native, nRequestID);
	}
	///预埋单录入请求
	int CTPTraderAdapter::ReqParkedOrderInsert(ThostFtdcParkedOrderField^ pParkedOrder, int nRequestID)
	{
		CThostFtdcParkedOrderField native;
		MNConv<ThostFtdcParkedOrderField^, CThostFtdcParkedOrderField>::M2N(pParkedOrder, &native);
		return m_pApi->ReqParkedOrderInsert(&native, nRequestID);
	}
	///预埋撤单录入请求
	int CTPTraderAdapter::ReqParkedOrderAction(ThostFtdcParkedOrderActionField^ pParkedOrderAction, int nRequestID)
	{
		CThostFtdcParkedOrderActionField native;
		MNConv<ThostFtdcParkedOrderActionField^, CThostFtdcParkedOrderActionField>::M2N(pParkedOrderAction, &native);
		return m_pApi->ReqParkedOrderAction(&native, nRequestID);
	}
	///报单操作请求
	int CTPTraderAdapter::ReqOrderAction(ThostFtdcInputOrderActionField^ pInputOrderAction, int nRequestID)
	{
		CThostFtdcInputOrderActionField native;
		MNConv<ThostFtdcInputOrderActionField^, CThostFtdcInputOrderActionField>::M2N(pInputOrderAction, &native);
		return m_pApi->ReqOrderAction(&native, nRequestID);
	}
	///查询最大报单数量请求
	int CTPTraderAdapter::ReqQueryMaxOrderVolume(ThostFtdcQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, int nRequestID)
	{
		CThostFtdcQueryMaxOrderVolumeField native;
		MNConv<ThostFtdcQueryMaxOrderVolumeField^, CThostFtdcQueryMaxOrderVolumeField>::M2N(pQueryMaxOrderVolume, &native);
		return m_pApi->ReqQueryMaxOrderVolume(&native, nRequestID);
	}
	///投资者结算结果确认
	int CTPTraderAdapter::ReqSettlementInfoConfirm(ThostFtdcSettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID)
	{
		CThostFtdcSettlementInfoConfirmField native;
		MNConv<ThostFtdcSettlementInfoConfirmField^, CThostFtdcSettlementInfoConfirmField>::M2N(pSettlementInfoConfirm, &native);
		return m_pApi->ReqSettlementInfoConfirm(&native, nRequestID);
	}
	///请求删除预埋单
	int CTPTraderAdapter::ReqRemoveParkedOrder(ThostFtdcRemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID)
	{
		CThostFtdcRemoveParkedOrderField native;
		MNConv<ThostFtdcRemoveParkedOrderField^, CThostFtdcRemoveParkedOrderField>::M2N(pRemoveParkedOrder, &native);
		return m_pApi->ReqRemoveParkedOrder(&native, nRequestID);
	}
	///请求删除预埋撤单
	int CTPTraderAdapter::ReqRemoveParkedOrderAction(ThostFtdcRemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID)
	{
		CThostFtdcRemoveParkedOrderActionField native;
		MNConv<ThostFtdcRemoveParkedOrderActionField^, CThostFtdcRemoveParkedOrderActionField>::M2N(pRemoveParkedOrderAction, &native);
		return m_pApi->ReqRemoveParkedOrderAction(&native, nRequestID);
	}
	///执行宣告录入请求
	int CTPTraderAdapter::ReqExecOrderInsert(ThostFtdcInputExecOrderField^ pInputExecOrder, int nRequestID)
	{
		CThostFtdcInputExecOrderField native;
		MNConv<ThostFtdcInputExecOrderField^, CThostFtdcInputExecOrderField>::M2N(pInputExecOrder, &native);
		return m_pApi->ReqExecOrderInsert(&native, nRequestID);
	};

	///执行宣告操作请求
	int CTPTraderAdapter::ReqExecOrderAction(ThostFtdcInputExecOrderActionField^ pInputExecOrderAction, int nRequestID)
	{
		CThostFtdcInputExecOrderActionField native;
		MNConv<ThostFtdcInputExecOrderActionField^, CThostFtdcInputExecOrderActionField>::M2N(pInputExecOrderAction, &native);
		return m_pApi->ReqExecOrderAction(&native, nRequestID);
	};

	///询价录入请求
	int CTPTraderAdapter::ReqForQuoteInsert(ThostFtdcInputForQuoteField^ pInputForQuote, int nRequestID)
	{
		CThostFtdcInputForQuoteField native;
		MNConv<ThostFtdcInputForQuoteField^, CThostFtdcInputForQuoteField>::M2N(pInputForQuote, &native);
		return m_pApi->ReqForQuoteInsert(&native, nRequestID);
	};

	///报价录入请求
	int CTPTraderAdapter::ReqQuoteInsert(ThostFtdcInputQuoteField^ pInputQuote, int nRequestID)
	{
		CThostFtdcInputQuoteField native;
		MNConv<ThostFtdcInputQuoteField^, CThostFtdcInputQuoteField>::M2N(pInputQuote, &native);
		return m_pApi->ReqQuoteInsert(&native, nRequestID);
	};

	///报价操作请求
	int CTPTraderAdapter::ReqQuoteAction(ThostFtdcInputQuoteActionField^ pInputQuoteAction, int nRequestID)
	{
		CThostFtdcInputQuoteActionField native;
		MNConv<ThostFtdcInputQuoteActionField^, CThostFtdcInputQuoteActionField>::M2N(pInputQuoteAction, &native);
		return m_pApi->ReqQuoteAction(&native, nRequestID);
	};

	///请求查询报单
	int CTPTraderAdapter::ReqQryOrder(ThostFtdcQryOrderField^ pQryOrder, int nRequestID)
	{
		CThostFtdcQryOrderField native;
		MNConv<ThostFtdcQryOrderField^, CThostFtdcQryOrderField>::M2N(pQryOrder, &native);
		return m_pApi->ReqQryOrder(&native, nRequestID);
	}
	///请求查询成交
	int CTPTraderAdapter::ReqQryTrade(ThostFtdcQryTradeField^ pQryTrade, int nRequestID)
	{
		CThostFtdcQryTradeField native;
		MNConv<ThostFtdcQryTradeField^, CThostFtdcQryTradeField>::M2N(pQryTrade, &native);
		return m_pApi->ReqQryTrade(&native, nRequestID);
	}
	///请求查询投资者持仓
	int CTPTraderAdapter::ReqQryInvestorPosition(ThostFtdcQryInvestorPositionField^ pQryInvestorPosition, int nRequestID)
	{
		CThostFtdcQryInvestorPositionField native;
		MNConv<ThostFtdcQryInvestorPositionField^, CThostFtdcQryInvestorPositionField>::M2N(pQryInvestorPosition, &native);
		return m_pApi->ReqQryInvestorPosition(&native, nRequestID);
	}
	///请求查询资金账户
	int CTPTraderAdapter::ReqQryTradingAccount(ThostFtdcQryTradingAccountField^ pQryTradingAccount, int nRequestID)
	{
		CThostFtdcQryTradingAccountField native;
		MNConv<ThostFtdcQryTradingAccountField^, CThostFtdcQryTradingAccountField>::M2N(pQryTradingAccount, &native);
		return m_pApi->ReqQryTradingAccount(&native, nRequestID);
	}
	///请求查询投资者
	int CTPTraderAdapter::ReqQryInvestor(ThostFtdcQryInvestorField^ pQryInvestor, int nRequestID)
	{
		CThostFtdcQryInvestorField native;
		MNConv<ThostFtdcQryInvestorField^, CThostFtdcQryInvestorField>::M2N(pQryInvestor, &native);
		return m_pApi->ReqQryInvestor(&native, nRequestID);
	}
	///请求查询交易编码
	int CTPTraderAdapter::ReqQryTradingCode(ThostFtdcQryTradingCodeField^ pQryTradingCode, int nRequestID)
	{
		CThostFtdcQryTradingCodeField native;
		MNConv<ThostFtdcQryTradingCodeField^, CThostFtdcQryTradingCodeField>::M2N(pQryTradingCode, &native);
		return m_pApi->ReqQryTradingCode(&native, nRequestID);
	}
	///请求查询合约保证金率
	int CTPTraderAdapter::ReqQryInstrumentMarginRate(ThostFtdcQryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID)
	{
		CThostFtdcQryInstrumentMarginRateField native;
		MNConv<ThostFtdcQryInstrumentMarginRateField^, CThostFtdcQryInstrumentMarginRateField>::M2N(pQryInstrumentMarginRate, &native);
		return m_pApi->ReqQryInstrumentMarginRate(&native, nRequestID);
	}
	///请求查询合约手续费率
	int CTPTraderAdapter::ReqQryInstrumentCommissionRate(ThostFtdcQryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID)
	{
		CThostFtdcQryInstrumentCommissionRateField native;
		MNConv<ThostFtdcQryInstrumentCommissionRateField^, CThostFtdcQryInstrumentCommissionRateField>::M2N(pQryInstrumentCommissionRate, &native);
		return m_pApi->ReqQryInstrumentCommissionRate(&native, nRequestID);
	}
	///请求查询交易所
	int CTPTraderAdapter::ReqQryExchange(ThostFtdcQryExchangeField^ pQryExchange, int nRequestID)
	{
		CThostFtdcQryExchangeField native;
		MNConv<ThostFtdcQryExchangeField^, CThostFtdcQryExchangeField>::M2N(pQryExchange, &native);
		return m_pApi->ReqQryExchange(&native, nRequestID);
	}
	/// 请求查询产品
	int CTPTraderAdapter::ReqQryProduct(ThostFtdcQryProductField^ pQryProduct, int nRequestID){
		CThostFtdcQryProductField native;
		MNConv<ThostFtdcQryProductField^, CThostFtdcQryProductField>::M2N(pQryProduct, &native);
		return m_pApi->ReqQryProduct(&native, nRequestID);
	}
	///请求查询合约
	int CTPTraderAdapter::ReqQryInstrument(ThostFtdcQryInstrumentField^ pQryInstrument, int nRequestID)
	{
		CThostFtdcQryInstrumentField native;
		MNConv<ThostFtdcQryInstrumentField^, CThostFtdcQryInstrumentField>::M2N(pQryInstrument, &native);
		return m_pApi->ReqQryInstrument(&native, nRequestID);
	}
	///请求查询行情
	int CTPTraderAdapter::ReqQryDepthMarketData(ThostFtdcQryDepthMarketDataField^ pQryDepthMarketData, int nRequestID)
	{
		CThostFtdcQryDepthMarketDataField native;
		MNConv<ThostFtdcQryDepthMarketDataField^, CThostFtdcQryDepthMarketDataField>::M2N(pQryDepthMarketData, &native);
		return m_pApi->ReqQryDepthMarketData(&native, nRequestID);
	}
	///请求查询投资者结算结果
	int CTPTraderAdapter::ReqQrySettlementInfo(ThostFtdcQrySettlementInfoField^ pQrySettlementInfo, int nRequestID)
	{
		CThostFtdcQrySettlementInfoField native;
		MNConv<ThostFtdcQrySettlementInfoField^, CThostFtdcQrySettlementInfoField>::M2N(pQrySettlementInfo, &native);
		return m_pApi->ReqQrySettlementInfo(&native, nRequestID);
	}
	///请求查询转帐银行
	int CTPTraderAdapter::ReqQryTransferBank(ThostFtdcQryTransferBankField^ pQryTransferBank, int nRequestID)
	{
		CThostFtdcQryTransferBankField native;
		MNConv<ThostFtdcQryTransferBankField^, CThostFtdcQryTransferBankField>::M2N(pQryTransferBank, &native);
		return m_pApi->ReqQryTransferBank(&native, nRequestID);
	}
	///请求查询投资者持仓明细
	int CTPTraderAdapter::ReqQryInvestorPositionDetail(ThostFtdcQryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID)
	{
		CThostFtdcQryInvestorPositionDetailField native;
		MNConv<ThostFtdcQryInvestorPositionDetailField^, CThostFtdcQryInvestorPositionDetailField>::M2N(pQryInvestorPositionDetail, &native);
		return m_pApi->ReqQryInvestorPositionDetail(&native, nRequestID);
	}
	///请求查询客户通知
	int CTPTraderAdapter::ReqQryNotice(ThostFtdcQryNoticeField^ pQryNotice, int nRequestID)
	{
		CThostFtdcQryNoticeField native;
		MNConv<ThostFtdcQryNoticeField^, CThostFtdcQryNoticeField>::M2N(pQryNotice, &native);
		return m_pApi->ReqQryNotice(&native, nRequestID);
	}
	///请求查询结算信息确认
	int CTPTraderAdapter::ReqQrySettlementInfoConfirm(ThostFtdcQrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID)
	{
		CThostFtdcQrySettlementInfoConfirmField native;
		MNConv<ThostFtdcQrySettlementInfoConfirmField^, CThostFtdcQrySettlementInfoConfirmField>::M2N(pQrySettlementInfoConfirm, &native);
		return m_pApi->ReqQrySettlementInfoConfirm(&native, nRequestID);
	}
	///请求查询投资者持仓明细
	int CTPTraderAdapter::ReqQryInvestorPositionCombineDetail(ThostFtdcQryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID)
	{
		CThostFtdcQryInvestorPositionCombineDetailField native;
		MNConv<ThostFtdcQryInvestorPositionCombineDetailField^, CThostFtdcQryInvestorPositionCombineDetailField>::M2N(pQryInvestorPositionCombineDetail, &native);
		return m_pApi->ReqQryInvestorPositionCombineDetail(&native, nRequestID);
	}
	///请求查询保证金监管系统经纪公司资金账户密钥
	int CTPTraderAdapter::ReqQryCFMMCTradingAccountKey(ThostFtdcQryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID)
	{
		CThostFtdcQryCFMMCTradingAccountKeyField native;
		MNConv<ThostFtdcQryCFMMCTradingAccountKeyField^, CThostFtdcQryCFMMCTradingAccountKeyField>::M2N(pQryCFMMCTradingAccountKey, &native);
		return m_pApi->ReqQryCFMMCTradingAccountKey(&native, nRequestID);
	}
	///请求查询仓单折抵信息
	int CTPTraderAdapter::ReqQryEWarrantOffset(ThostFtdcQryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID)
	{
		CThostFtdcQryEWarrantOffsetField native;
		MNConv<ThostFtdcQryEWarrantOffsetField^, CThostFtdcQryEWarrantOffsetField>::M2N(pQryEWarrantOffset, &native);
		return m_pApi->ReqQryEWarrantOffset(&native, nRequestID);
	}
	/// 请求查询投资者品种/跨品种保证金
	int CTPTraderAdapter::ReqQryInvestorProductGroupMargin(ThostFtdcQryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID)
	{
		CThostFtdcQryInvestorProductGroupMarginField native;
		MNConv<ThostFtdcQryInvestorProductGroupMarginField^, CThostFtdcQryInvestorProductGroupMarginField>::M2N(pQryInvestorProductGroupMargin, &native);
		return m_pApi->ReqQryInvestorProductGroupMargin(&native, nRequestID);
	}
	/// 请求查询交易所保证金率
	int CTPTraderAdapter::ReqQryExchangeMarginRate(ThostFtdcQryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID)
	{
		CThostFtdcQryExchangeMarginRateField native;
		MNConv<ThostFtdcQryExchangeMarginRateField^, CThostFtdcQryExchangeMarginRateField>::M2N(pQryExchangeMarginRate, &native);
		return m_pApi->ReqQryExchangeMarginRate(&native, nRequestID);
	}
	/// 请求查询交易所调整保证金率
	int CTPTraderAdapter::ReqQryExchangeMarginRateAdjust(ThostFtdcQryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID)
	{
		CThostFtdcQryExchangeMarginRateAdjustField native;
		MNConv<ThostFtdcQryExchangeMarginRateAdjustField^, CThostFtdcQryExchangeMarginRateAdjustField>::M2N(pQryExchangeMarginRateAdjust, &native);
		return m_pApi->ReqQryExchangeMarginRateAdjust(&native, nRequestID);
	}
	/// 请求查询汇率
	int CTPTraderAdapter::ReqQryExchangeRate(ThostFtdcQryExchangeRateField^ pQryExchangeRate, int nRequestID)
	{
		CThostFtdcQryExchangeRateField native;
		MNConv<ThostFtdcQryExchangeRateField^, CThostFtdcQryExchangeRateField>::M2N(pQryExchangeRate, &native);
		return m_pApi->ReqQryExchangeRate(&native, nRequestID);
	}
	/// 请求查询二级代理操作员银期权限
	int CTPTraderAdapter::ReqQrySecAgentACIDMap(ThostFtdcQrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID)
	{
		CThostFtdcQrySecAgentACIDMapField native;
		MNConv<ThostFtdcQrySecAgentACIDMapField^, CThostFtdcQrySecAgentACIDMapField>::M2N(pQrySecAgentACIDMap, &native);
		return m_pApi->ReqQrySecAgentACIDMap(&native, nRequestID);
	}
	///请求查询期权交易成本
	int CTPTraderAdapter::ReqQryOptionInstrTradeCost(ThostFtdcQryOptionInstrTradeCostField^ pQryOptionInstrTradeCost, int nRequestID)
	{
		CThostFtdcQryOptionInstrTradeCostField native;
		MNConv<ThostFtdcQryOptionInstrTradeCostField^, CThostFtdcQryOptionInstrTradeCostField>::M2N(pQryOptionInstrTradeCost, &native);
		return m_pApi->ReqQryOptionInstrTradeCost(&native, nRequestID);
	};

	///请求查询期权合约手续费
	int CTPTraderAdapter::ReqQryOptionInstrCommRate(ThostFtdcQryOptionInstrCommRateField^ pQryOptionInstrCommRate, int nRequestID)
	{
		CThostFtdcQryOptionInstrCommRateField native;
		MNConv<ThostFtdcQryOptionInstrCommRateField^, CThostFtdcQryOptionInstrCommRateField>::M2N(pQryOptionInstrCommRate, &native);
		return m_pApi->ReqQryOptionInstrCommRate(&native, nRequestID);
	};

	///请求查询执行宣告
	int CTPTraderAdapter::ReqQryExecOrder(ThostFtdcQryExecOrderField^ pQryExecOrder, int nRequestID)
	{
		CThostFtdcQryExecOrderField native;
		MNConv<ThostFtdcQryExecOrderField^, CThostFtdcQryExecOrderField>::M2N(pQryExecOrder, &native);
		return m_pApi->ReqQryExecOrder(&native, nRequestID);
	};

	///请求查询询价
	int CTPTraderAdapter::ReqQryForQuote(ThostFtdcQryForQuoteField^ pQryForQuote, int nRequestID)
	{
		CThostFtdcQryForQuoteField native;
		MNConv<ThostFtdcQryForQuoteField^, CThostFtdcQryForQuoteField>::M2N(pQryForQuote, &native);
		return m_pApi->ReqQryForQuote(&native, nRequestID);
	};

	///请求查询报价
	int CTPTraderAdapter::ReqQryQuote(ThostFtdcQryQuoteField^ pQryQuote, int nRequestID)
	{
		CThostFtdcQryQuoteField native;
		MNConv<ThostFtdcQryQuoteField^, CThostFtdcQryQuoteField>::M2N(pQryQuote, &native);
		return m_pApi->ReqQryQuote(&native, nRequestID);
	};

	///请求查询转帐流水
	int CTPTraderAdapter::ReqQryTransferSerial(ThostFtdcQryTransferSerialField^ pQryTransferSerial, int nRequestID)
	{
		CThostFtdcQryTransferSerialField native;
		MNConv<ThostFtdcQryTransferSerialField^, CThostFtdcQryTransferSerialField>::M2N(pQryTransferSerial, &native);
		return m_pApi->ReqQryTransferSerial(&native, nRequestID);
	}
	///请求查询银期签约关系
	int CTPTraderAdapter::ReqQryAccountregister(ThostFtdcQryAccountregisterField^ pQryAccountregister, int nRequestID)
	{
		CThostFtdcQryAccountregisterField native;
		MNConv<ThostFtdcQryAccountregisterField^, CThostFtdcQryAccountregisterField>::M2N(pQryAccountregister, &native);
		return m_pApi->ReqQryAccountregister(&native, nRequestID);
	}
	///请求查询签约银行
	int CTPTraderAdapter::ReqQryContractBank(ThostFtdcQryContractBankField^ pQryContractBank, int nRequestID)
	{
		CThostFtdcQryContractBankField native;
		MNConv<ThostFtdcQryContractBankField^, CThostFtdcQryContractBankField>::M2N(pQryContractBank, &native);
		return m_pApi->ReqQryContractBank(&native, nRequestID);
	}
	///请求查询预埋单
	int CTPTraderAdapter::ReqQryParkedOrder(ThostFtdcQryParkedOrderField^ pQryParkedOrder, int nRequestID)
	{
		CThostFtdcQryParkedOrderField native;
		MNConv<ThostFtdcQryParkedOrderField^, CThostFtdcQryParkedOrderField>::M2N(pQryParkedOrder, &native);
		return m_pApi->ReqQryParkedOrder(&native, nRequestID);
	}
	///请求查询预埋撤单
	int CTPTraderAdapter::ReqQryParkedOrderAction(ThostFtdcQryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID)
	{
		CThostFtdcQryParkedOrderActionField native;
		MNConv<ThostFtdcQryParkedOrderActionField^, CThostFtdcQryParkedOrderActionField>::M2N(pQryParkedOrderAction, &native);
		return m_pApi->ReqQryParkedOrderAction(&native, nRequestID);
	}
	///请求查询交易通知
	int CTPTraderAdapter::ReqQryTradingNotice(ThostFtdcQryTradingNoticeField^ pQryTradingNotice, int nRequestID)
	{
		CThostFtdcQryTradingNoticeField native;
		MNConv<ThostFtdcQryTradingNoticeField^, CThostFtdcQryTradingNoticeField>::M2N(pQryTradingNotice, &native);
		return m_pApi->ReqQryTradingNotice(&native, nRequestID);
	}
	///请求查询经纪公司交易参数
	int CTPTraderAdapter::ReqQryBrokerTradingParams(ThostFtdcQryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID)
	{
		CThostFtdcQryBrokerTradingParamsField native;
		MNConv<ThostFtdcQryBrokerTradingParamsField^, CThostFtdcQryBrokerTradingParamsField>::M2N(pQryBrokerTradingParams, &native);
		return m_pApi->ReqQryBrokerTradingParams(&native, nRequestID);
	}
	///请求查询经纪公司交易算法
	int CTPTraderAdapter::ReqQryBrokerTradingAlgos(ThostFtdcQryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID)
	{
		CThostFtdcQryBrokerTradingAlgosField native;
		MNConv<ThostFtdcQryBrokerTradingAlgosField^, CThostFtdcQryBrokerTradingAlgosField>::M2N(pQryBrokerTradingAlgos, &native);
		return m_pApi->ReqQryBrokerTradingAlgos(&native, nRequestID);
	}
	///期货发起银行资金转期货请求
	int CTPTraderAdapter::ReqFromBankToFutureByFuture(ThostFtdcReqTransferField^ pReqTransfer, int nRequestID)
	{
		CThostFtdcReqTransferField native;
		MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::M2N(pReqTransfer, &native);
		return m_pApi->ReqFromBankToFutureByFuture(&native, nRequestID);
	}
	///期货发起期货资金转银行请求
	int CTPTraderAdapter::ReqFromFutureToBankByFuture(ThostFtdcReqTransferField^ pReqTransfer, int nRequestID)
	{
		CThostFtdcReqTransferField native;
		MNConv<ThostFtdcReqTransferField^, CThostFtdcReqTransferField>::M2N(pReqTransfer, &native);
		return m_pApi->ReqFromFutureToBankByFuture(&native, nRequestID);
	}
	///期货发起查询银行余额请求
	int CTPTraderAdapter::ReqQueryBankAccountMoneyByFuture(ThostFtdcReqQueryAccountField^ pReqQueryAccount, int nRequestID)
	{
		CThostFtdcReqQueryAccountField native;
		MNConv<ThostFtdcReqQueryAccountField^, CThostFtdcReqQueryAccountField>::M2N(pReqQueryAccount, &native);
		return m_pApi->ReqQueryBankAccountMoneyByFuture(&native, nRequestID);
	}
}