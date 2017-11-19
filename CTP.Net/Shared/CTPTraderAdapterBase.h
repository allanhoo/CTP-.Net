/////////////////////////////////////////////////////////////////////////
/// 上期技术 CTP C++ ==> .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20120422
/////////////////////////////////////////////////////////////////////////

// V1,V2共享此文件

#pragma once

#include "Util.h"
#include "ThostFtdcTraderApi.h"

using namespace Native;

namespace  Native{
	class CTraderSpi;
};

namespace CTP 
{
	/// <summary>
	/// 内部使用，不能实例化
	/// </summary>
	public ref class CTPTraderAdapterBase abstract
	{
	protected:
		CTPTraderAdapterBase(String^ pszFlowPath);
			
		~CTPTraderAdapterBase(void);
		CThostFtdcTraderApi* m_pApi;
		CTraderSpi* m_pSpi;
#ifdef __CTP_MA__
	protected:
		// 将所有回调函数地址传递给SPI
		virtual void RegisterCallbacks() {};
#endif
	public:
		/// <summary>
		/// 获取对应的CTP官方C++库的版本发布日期，如20140811等
		/// </summary>
		String^ GetCtpVersionDate();

		/// <summary>
		///删除接口对象本身
		///@remark 不再使用本接口对象时,调用该函数删除接口对象
		/// </summary>
		void Release();

		/// <summary>
		///初始化
		///@remark 初始化运行环境,只有调用后,接口才开始工作
		/// </summary>
		void Init();

		/// <summary>
		///等待接口线程结束运行
		///@return 线程退出代码
		/// </summary>
		int Join();

		/// <summary>
		///获取当前交易日
		///@remark 只有登录成功后,才能得到正确的交易日
		/// </summary>
		/// <returns>获取到的交易日</returns>
		String^ GetTradingDay();

		/// <summary>
		///注册前置机网络地址
		///@param pszFrontAddress：前置机网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
		/// </summary>
		void RegisterFront(String^ pszFrontAddress);

		/// <summary>
		///注册名字服务器网络地址
		///@param pszNsAddress：名字服务器网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
		///@remark RegisterNameServer优先于RegisterFront
		/// </summary>
		void RegisterNameServer(String^ pszNsAddress);

		/// <summary>
		///注册名字服务器用户信息
		///@param pFensUserInfo：用户信息。
		/// </summary>
		void RegisterFensUserInfo(ThostFtdcFensUserInfoField^  pFensUserInfo);
	

		///注册回调接口
		///@param pSpi 派生自回调接口类的实例
		/// void RegisterSpi(ThostFtdcTraderSpi^ pSpi);

		/// <summary>
		///订阅私有流。
		///@param nResumeType 私有流重传方式  
		///        THOST_TERT_RESTART:从本交易日开始重传
		///        THOST_TERT_RESUME:从上次收到的续传
		///        THOST_TERT_QUICK:只传送登录后私有流的内容
		///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
		/// </summary>
		void SubscribePrivateTopic(EnumTeResumeType nResumeType);

		/// <summary>
		///订阅公共流。
		///@param nResumeType 公共流重传方式  
		///        THOST_TERT_RESTART:从本交易日开始重传
		///        THOST_TERT_RESUME:从上次收到的续传
		///        THOST_TERT_QUICK:只传送登录后公共流的内容
		///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
		/// </summary>
		void SubscribePublicTopic(EnumTeResumeType nResumeType);

		/// <summary>
		///客户端认证请求
		/// </summary>
		int ReqAuthenticate(ThostFtdcReqAuthenticateField^ pReqAuthenticateField, int nRequestID);

		/// <summary>
		///用户登录请求
		/// </summary>
		int ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID);

		/// <summary>
		///登出请求
		/// </summary>
		int ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID);

		/// <summary>
		///用户口令更新请求
		/// </summary>
		int ReqUserPasswordUpdate(ThostFtdcUserPasswordUpdateField^ pUserPasswordUpdate, int nRequestID);

		/// <summary>
		///资金账户口令更新请求
		/// </summary>
		int ReqTradingAccountPasswordUpdate(ThostFtdcTradingAccountPasswordUpdateField^ pTradingAccountPasswordUpdate, int nRequestID);

		/// <summary>
		///报单录入请求
		/// </summary>
		int ReqOrderInsert(ThostFtdcInputOrderField^ pInputOrder, int nRequestID);

		/// <summary>
		///预埋单录入请求
		/// </summary>
		int ReqParkedOrderInsert(ThostFtdcParkedOrderField^ pParkedOrder, int nRequestID);

		/// <summary>
		///预埋撤单录入请求
		/// </summary>
		int ReqParkedOrderAction(ThostFtdcParkedOrderActionField^ pParkedOrderAction, int nRequestID);

		/// <summary>
		///报单操作请求
		/// </summary>
		int ReqOrderAction(ThostFtdcInputOrderActionField^ pInputOrderAction, int nRequestID);

		/// <summary>
		///查询最大报单数量请求
		/// </summary>
		int ReqQueryMaxOrderVolume(ThostFtdcQueryMaxOrderVolumeField^ pQueryMaxOrderVolume, int nRequestID);

		/// <summary>
		///投资者结算结果确认
		/// </summary>
		int ReqSettlementInfoConfirm(ThostFtdcSettlementInfoConfirmField^ pSettlementInfoConfirm, int nRequestID);

		/// <summary>
		///请求删除预埋单
		/// </summary>
		int ReqRemoveParkedOrder(ThostFtdcRemoveParkedOrderField^ pRemoveParkedOrder, int nRequestID);

		/// <summary>
		///请求删除预埋撤单
		/// </summary>
		int ReqRemoveParkedOrderAction(ThostFtdcRemoveParkedOrderActionField^ pRemoveParkedOrderAction, int nRequestID);

		/// <summary>
		///请求查询报单
		/// </summary>
		int ReqQryOrder(ThostFtdcQryOrderField^ pQryOrder, int nRequestID);

		/// <summary>
		///请求查询成交
		/// </summary>
		int ReqQryTrade(ThostFtdcQryTradeField^ pQryTrade, int nRequestID);

		/// <summary>
		///请求查询投资者持仓
		/// </summary>
		int ReqQryInvestorPosition(ThostFtdcQryInvestorPositionField^ pQryInvestorPosition, int nRequestID);

		/// <summary>
		///请求查询资金账户
		/// </summary>
		int ReqQryTradingAccount(ThostFtdcQryTradingAccountField^ pQryTradingAccount, int nRequestID);

		/// <summary>
		///请求查询投资者
		/// </summary>
		int ReqQryInvestor(ThostFtdcQryInvestorField^ pQryInvestor, int nRequestID);

		/// <summary>
		///请求查询交易编码
		/// </summary>
		int ReqQryTradingCode(ThostFtdcQryTradingCodeField^ pQryTradingCode, int nRequestID);

		/// <summary>
		///请求查询合约保证金率
		/// </summary>
		int ReqQryInstrumentMarginRate(ThostFtdcQryInstrumentMarginRateField^ pQryInstrumentMarginRate, int nRequestID);

		/// <summary>
		///请求查询合约手续费率
		/// </summary>
		int ReqQryInstrumentCommissionRate(ThostFtdcQryInstrumentCommissionRateField^ pQryInstrumentCommissionRate, int nRequestID);

		/// <summary>
		///请求查询交易所
		/// </summary>
		int ReqQryExchange(ThostFtdcQryExchangeField^ pQryExchange, int nRequestID);

		/// <summary>
		/// 请求查询产品
		/// </summary>
		int ReqQryProduct(ThostFtdcQryProductField ^pQryProduct, int nRequestID);

		/// <summary>
		///请求查询合约
		/// </summary>
		int ReqQryInstrument(ThostFtdcQryInstrumentField^ pQryInstrument, int nRequestID);

		/// <summary>
		///请求查询行情
		/// </summary>
		int ReqQryDepthMarketData(ThostFtdcQryDepthMarketDataField^ pQryDepthMarketData, int nRequestID);

		/// <summary>
		///请求查询投资者结算结果
		/// </summary>
		int ReqQrySettlementInfo(ThostFtdcQrySettlementInfoField^ pQrySettlementInfo, int nRequestID);

		/// <summary>
		///请求查询转帐银行
		/// </summary>
		int ReqQryTransferBank(ThostFtdcQryTransferBankField^ pQryTransferBank, int nRequestID);

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		int ReqQryInvestorPositionDetail(ThostFtdcQryInvestorPositionDetailField^ pQryInvestorPositionDetail, int nRequestID);

		/// <summary>
		///请求查询客户通知
		/// </summary>
		int ReqQryNotice(ThostFtdcQryNoticeField^ pQryNotice, int nRequestID);

		/// <summary>
		///请求查询结算信息确认
		/// </summary>
		int ReqQrySettlementInfoConfirm(ThostFtdcQrySettlementInfoConfirmField^ pQrySettlementInfoConfirm, int nRequestID);

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		int ReqQryInvestorPositionCombineDetail(ThostFtdcQryInvestorPositionCombineDetailField^ pQryInvestorPositionCombineDetail, int nRequestID);

		/// <summary>
		///请求查询保证金监管系统经纪公司资金账户密钥
		/// </summary>
		int ReqQryCFMMCTradingAccountKey(ThostFtdcQryCFMMCTradingAccountKeyField^ pQryCFMMCTradingAccountKey, int nRequestID);

		/// <summary>
		///请求查询仓单折抵信息
		/// </summary>
		int ReqQryEWarrantOffset(ThostFtdcQryEWarrantOffsetField^ pQryEWarrantOffset, int nRequestID);

		/// <summary>
		/// 请求查询投资者品种/跨品种保证金
		/// </summary>
		int ReqQryInvestorProductGroupMargin(ThostFtdcQryInvestorProductGroupMarginField^ pQryInvestorProductGroupMargin, int nRequestID);

		/// <summary>
		/// 请求查询交易所保证金率
		/// </summary>
		int ReqQryExchangeMarginRate(ThostFtdcQryExchangeMarginRateField^ pQryExchangeMarginRate, int nRequestID);

		/// <summary>
		/// 请求查询交易所调整保证金率
		/// </summary>
		int ReqQryExchangeMarginRateAdjust(ThostFtdcQryExchangeMarginRateAdjustField^ pQryExchangeMarginRateAdjust, int nRequestID);

		/// <summary>
		/// 请求查询汇率
		/// </summary>
		int ReqQryExchangeRate(ThostFtdcQryExchangeRateField^ pQryExchangeRate, int nRequestID);

		/// <summary>
		/// 请求查询二级代理操作员银期权限
		/// </summary>
		int ReqQrySecAgentACIDMap(ThostFtdcQrySecAgentACIDMapField^ pQrySecAgentACIDMap, int nRequestID);


		/// <summary>
		///请求查询转帐流水
		/// </summary>
		int ReqQryTransferSerial(ThostFtdcQryTransferSerialField^ pQryTransferSerial, int nRequestID);

		/// <summary>
		///请求查询银期签约关系
		/// </summary>
		int ReqQryAccountregister(ThostFtdcQryAccountregisterField^ pQryAccountregister, int nRequestID);

		/// <summary>
		///请求查询签约银行
		/// </summary>
		int ReqQryContractBank(ThostFtdcQryContractBankField^ pQryContractBank, int nRequestID);

		/// <summary>
		///请求查询预埋单
		/// </summary>
		int ReqQryParkedOrder(ThostFtdcQryParkedOrderField^ pQryParkedOrder, int nRequestID);

		/// <summary>
		///请求查询预埋撤单
		/// </summary>
		int ReqQryParkedOrderAction(ThostFtdcQryParkedOrderActionField^ pQryParkedOrderAction, int nRequestID);

		/// <summary>
		///请求查询交易通知
		/// </summary>
		int ReqQryTradingNotice(ThostFtdcQryTradingNoticeField^ pQryTradingNotice, int nRequestID);

		/// <summary>
		///请求查询经纪公司交易参数
		/// </summary>
		int ReqQryBrokerTradingParams(ThostFtdcQryBrokerTradingParamsField^ pQryBrokerTradingParams, int nRequestID);

		/// <summary>
		///请求查询经纪公司交易算法
		/// </summary>
		int ReqQryBrokerTradingAlgos(ThostFtdcQryBrokerTradingAlgosField^ pQryBrokerTradingAlgos, int nRequestID);

		/// <summary>
		/// 请求查询监控中心用户令牌
		/// </summary>
		int ReqQueryCFMMCTradingAccountToken(ThostFtdcQueryCFMMCTradingAccountTokenField^ pQueryCFMMCTradingAccountToken, int nRequestID);
		/// <summary>
		///期货发起银行资金转期货请求
		/// </summary>
		int ReqFromBankToFutureByFuture(ThostFtdcReqTransferField^ pReqTransfer, int nRequestID);

		/// <summary>
		///期货发起期货资金转银行请求
		/// </summary>
		int ReqFromFutureToBankByFuture(ThostFtdcReqTransferField^ pReqTransfer, int nRequestID);

		/// <summary>
		///期货发起查询银行余额请求
		/// </summary>
		int ReqQueryBankAccountMoneyByFuture(ThostFtdcReqQueryAccountField^ pReqQueryAccount, int nRequestID);

	};
};