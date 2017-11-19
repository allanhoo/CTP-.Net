
// V1,V2共享此文件


#include "StdAfx.h"
#include "MdSpi.h"
#include "CTPMDAdapterBase.h"

namespace CTP
{

	CTPMDAdapterBase::CTPMDAdapterBase(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast)
	{
		CAutoStrPtr asp(pszFlowPath);
		m_pApi = CThostFtdcMdApi::CreateFtdcMdApi(asp.m_pChar, bIsUsingUdp, bIsMulticast);
		m_pSpi = new CMdSpi((CTPMDAdapter^)this);
#ifdef __CTP_MA__
		RegisterCallbacks();
#endif	
		m_pApi->RegisterSpi(m_pSpi);
	}

	CTPMDAdapterBase::~CTPMDAdapterBase(void)
	{
		Release();
	}

	String^ CTPMDAdapterBase::GetCtpVersionDate()
	{
		return CTPMDAdapterBase::_CTPVersionDate;
	}

	void CTPMDAdapterBase::Release(void)
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

	void CTPMDAdapterBase::RegisterFront(String^  pszFrontAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszFrontAddress);
		m_pApi->RegisterFront(asp.m_pChar);
	}

	void CTPMDAdapterBase::RegisterNameServer(String^  pszNsAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszNsAddress);
		m_pApi->RegisterNameServer(asp.m_pChar);
	}

	void CTPMDAdapterBase::RegisterFensUserInfo(ThostFtdcFensUserInfoField^ pFensUserInfo)
	{
		CThostFtdcFensUserInfoField native;
		MNConv<ThostFtdcFensUserInfoField^, CThostFtdcFensUserInfoField>::M2N(pFensUserInfo, &native);
		m_pApi->RegisterFensUserInfo(&native);
	}

	void CTPMDAdapterBase::Init(void)
	{
		m_pApi->Init();
	}

	void CTPMDAdapterBase::Join(void)
	{
		m_pApi->Join();
	}

	String^ CTPMDAdapterBase::GetTradingDay()
	{
		return gcnew String(m_pApi->GetTradingDay());
	}

	int CTPMDAdapterBase::ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		CThostFtdcReqUserLoginField native;
		MNConv<ThostFtdcReqUserLoginField^, CThostFtdcReqUserLoginField>::M2N(pReqUserLoginField, &native);
		return m_pApi->ReqUserLogin(&native, nRequestID);
	}

	int CTPMDAdapterBase::ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID)
	{
		CThostFtdcUserLogoutField native;
		MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::M2N(pUserLogout, &native);
		return m_pApi->ReqUserLogout(&native, nRequestID);
	}

	int CTPMDAdapterBase::SubscribeMarketData(array<String^>^ ppInstrumentID)
	{
		if (ppInstrumentID == nullptr || ppInstrumentID->Length <= 0)
			return -1;

		int count = ppInstrumentID->Length;
		char** pp = new char*[count];
		CAutoStrPtr** asp = new CAutoStrPtr*[count];
		for (int i = 0; i < count; i++)
		{
			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
			asp[i] = ptr;
			pp[i] = ptr->m_pChar;
		}

		int result = m_pApi->SubscribeMarketData(pp, count);

		// 释放所有分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}

	int CTPMDAdapterBase::UnSubscribeMarketData(array<String^>^ ppInstrumentID)
	{
		if (ppInstrumentID == nullptr || ppInstrumentID->Length <= 0)
			return -1;

		int count = ppInstrumentID->Length;
		char** pp = new char*[count];
		CAutoStrPtr** asp = new CAutoStrPtr*[count];
		for (int i = 0; i < count; i++)
		{
			CAutoStrPtr* ptr = new CAutoStrPtr(ppInstrumentID[i]);
			asp[i] = ptr;
			pp[i] = ptr->m_pChar;
		}

		int result = m_pApi->UnSubscribeMarketData(pp, count);

		// 释放所分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}



}// end of namespace