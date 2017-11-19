#include "stdafx.h"
#include "CTPMDAdapter.h"
#include "MdSpi.h"
#include "Util.h"



namespace CTPZQ
{
	using namespace Native;

	CTPMDAdapter::CTPMDAdapter()
		: CTPMDAdapter("", false)
	{
	}

	CTPMDAdapter::CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp)
	{
		CAutoStrPtr asp(pszFlowPath);
		m_pApi = CZQThostFtdcMdApi::CreateFtdcMdApi(asp.m_pChar, bIsUsingUdp);
		m_pSpi = new CMdSpi(this);
		m_pApi->RegisterSpi(m_pSpi);
	}

	CTPMDAdapter::~CTPMDAdapter(void)
	{
		Release();
	}

	String^ CTPMDAdapter::GetCtpVersionDate()
	{
		return CTPMDAdapter::_CTPVersionDate;
	}

	void CTPMDAdapter::Release(void)
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

	void CTPMDAdapter::RegisterFront(String^  pszFrontAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszFrontAddress);
		m_pApi->RegisterFront(asp.m_pChar);
	}

	void CTPMDAdapter::Init(void)
	{
		m_pApi->Init();
	}

	void CTPMDAdapter::Join(void)
	{
		m_pApi->Join();
	}

	String^ CTPMDAdapter::GetTradingDay()
	{
		return gcnew String(m_pApi->GetTradingDay());
	}

	int CTPMDAdapter::ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID)
	{
		CZQThostFtdcReqUserLoginField native;
		MNConv<ThostFtdcReqUserLoginField^, CZQThostFtdcReqUserLoginField>::M2N(pReqUserLoginField, &native);
		return m_pApi->ReqUserLogin(&native, nRequestID);
	}

	int CTPMDAdapter::ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID)
	{
		CZQThostFtdcUserLogoutField native;
		MNConv<ThostFtdcUserLogoutField^, CZQThostFtdcUserLogoutField>::M2N(pUserLogout, &native);
		return m_pApi->ReqUserLogout(&native, nRequestID);
	}

	int CTPMDAdapter::SubscribeMarketData(array<String^>^ ppInstrumentID, String^ pExchageID)
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

		CAutoStrPtr exch(pExchageID);

		int result = m_pApi->SubscribeMarketData(pp, count, exch.m_pChar);

		// 释放所有分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}

	int CTPMDAdapter::UnSubscribeMarketData(array<String^>^ ppInstrumentID, String^ pExchageID)
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

		CAutoStrPtr exch(pExchageID);

		int result = m_pApi->UnSubscribeMarketData(pp, count, exch.m_pChar);

		// 释放所分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}


}
