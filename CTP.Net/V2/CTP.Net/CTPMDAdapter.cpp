#include "stdafx.h"
#include "MdSpi.h"
#include "CTPMDAdapter.h"

namespace CTP
{

	CTPMDAdapter::CTPMDAdapter()
		: CTPMDAdapterBase("", false, false)
	{
	}
	CTPMDAdapter::CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp)
		: CTPMDAdapterBase(pszFlowPath, bIsUsingUdp, false)
	{
	}
	CTPMDAdapter::CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast)
		: CTPMDAdapterBase(pszFlowPath, bIsUsingUdp, bIsMulticast)
	{
	}

#ifdef __CTP_MA__

	// 将所有回调函数地址传递给SPI，并保存对delegate的引用
	void CTPMDAdapter::RegisterCallbacks()
	{
		m_pSpi->d_FrontConnEvent = gcnew Internal_FrontEvent(this, &CTPMDAdapter::cbk_OnFrontEvent);
		m_pSpi->p_OnFrontConnEvent = (Callback_OnFrontConnEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_FrontConnEvent).ToPointer();

		m_pSpi->d_RspEvent = gcnew Internal_RspEvent(this, &CTPMDAdapter::cbk_OnRspEvent);
		m_pSpi->p_OnRspEvent = (Callback_OnRspEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RspEvent).ToPointer();

		m_pSpi->d_RtnEvent = gcnew Internal_RtnEvent(this, &CTPMDAdapter::cbk_OnRtnEvent);
		m_pSpi->p_OnRtnEvent = (Callback_OnRtnEvent)Marshal::GetFunctionPointerForDelegate(m_pSpi->d_RtnEvent).ToPointer();
	}

	// ------------------------------------ Callbacks ------------------------------------
	void CTPMDAdapter::cbk_OnFrontEvent(CtpEnumFrontType EventType, int nReason){
		OnCtpFrontEvent(this, gcnew CtpFrontEventArgs(EventType, nReason));
	}
	void CTPMDAdapter::cbk_OnRspEvent(CtpEnumRspType EventType, void *pParam, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
		switch (EventType)
		{
		case CTP::CtpEnumRspType::RspError:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(CtpEnumRspType::RspError, nullptr, RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUserLogin:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogin, MNConv<ThostFtdcRspUserLoginField^, CThostFtdcRspUserLoginField>::N2M((CThostFtdcRspUserLoginField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUserLogout:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(CtpEnumRspType::RspUserLogout, MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::N2M((CThostFtdcUserLogoutField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspSubMarketData:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(CtpEnumRspType::RspSubMarketData, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M((CThostFtdcSpecificInstrumentField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		case CTP::CtpEnumRspType::RspUnSubMarketData:
			OnCtpRspEvent(this, gcnew CtpRspEventArgs(CtpEnumRspType::RspUnSubMarketData, MNConv<ThostFtdcSpecificInstrumentField^, CThostFtdcSpecificInstrumentField>::N2M((CThostFtdcSpecificInstrumentField*)pParam), RspInfoField(pRspInfo), nRequestID, bIsLast));
			break;
		default:
			break;
		}
	}

	void CTPMDAdapter::cbk_OnRtnEvent(CtpEnumRtnType EventType, void *pParam){
		// 行情接口目前仅有一个Rtn事件，即深度行情通知，此处不用switch判断以提高效率
		//switch (EventType)
		//{
		//case CTP::CtpEnumRtnType::RtnDepthMarketData:
		ThostFtdcDepthMarketDataField^ field = safe_cast<ThostFtdcDepthMarketDataField^>(Marshal::PtrToStructure(IntPtr(pParam), ThostFtdcDepthMarketDataField::typeid));
		OnCtpRtnEvent(this, gcnew CtpRtnEventArgs(EventType, field));
		//break;
		//default:
		//	break;
		//}
	}

#endif
}
