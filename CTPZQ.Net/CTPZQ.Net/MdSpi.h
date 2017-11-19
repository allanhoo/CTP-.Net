/////////////////////////////////////////////////////////////////////////
/// CTP证券 C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20140906
/////////////////////////////////////////////////////////////////////////
#pragma once

#include <vcclr.h>

#include "ThostFtdcMdApiSSE.h"
#include "CTPMDAdapter.h"

namespace Native
{
	using namespace CTPZQ;

	class CMdSpi : public CZQThostFtdcMdSpi
	{
	public:
		/// 构造函数
		CMdSpi(CTPMDAdapter^ pAdapter);

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

		///登录请求响应
		virtual void OnRspUserLogin(CZQThostFtdcRspUserLoginField *pRspUserLogin, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///登出请求响应
		virtual void OnRspUserLogout(CZQThostFtdcUserLogoutField *pUserLogout, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///错误应答
		virtual void OnRspError(CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///订阅行情应答
		virtual void OnRspSubMarketData(CZQThostFtdcSpecificInstrumentField *pSpecificInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///取消订阅行情应答
		virtual void OnRspUnSubMarketData(CZQThostFtdcSpecificInstrumentField *pSpecificInstrument, CZQThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		///深度行情通知
		virtual void OnRtnDepthMarketData(CZQThostFtdcDepthMarketDataField *pDepthMarketData);
	protected:
		gcroot<CTPMDAdapter^> m_pAdapter;
	};// end of class

};// end of namespace

