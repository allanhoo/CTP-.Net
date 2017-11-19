#include "stdafx.h"
#include "CTPMDAdapter.h"
#include "Util.h"
#include "MdSpi.h"

namespace CTPQQ
{
	CTPMDAdapter::CTPMDAdapter()
		: CTPMDAdapter("", false, false)
	{
	}
	CTPMDAdapter::CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp)
		: CTPMDAdapter(pszFlowPath, bIsUsingUdp, false)
	{
	}
	CTPMDAdapter::CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast)
	{
		CAutoStrPtr asp(pszFlowPath);
		m_pApi = CThostFtdcMdApi::CreateFtdcMdApi(asp.m_pChar, bIsUsingUdp, bIsMulticast);
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

	void CTPMDAdapter::RegisterNameServer(String^  pszNsAddress)
	{
		CAutoStrPtr asp = CAutoStrPtr(pszNsAddress);
		m_pApi->RegisterNameServer(asp.m_pChar);
	}

	void CTPMDAdapter::RegisterFensUserInfo(ThostFtdcFensUserInfoField^ pFensUserInfo)
	{
		CThostFtdcFensUserInfoField native;
		MNConv<ThostFtdcFensUserInfoField^, CThostFtdcFensUserInfoField>::M2N(pFensUserInfo, &native);
		m_pApi->RegisterFensUserInfo(&native);
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
		CThostFtdcReqUserLoginField native;
		MNConv<ThostFtdcReqUserLoginField^, CThostFtdcReqUserLoginField>::M2N(pReqUserLoginField, &native);
		return m_pApi->ReqUserLogin(&native, nRequestID);
	}

	int CTPMDAdapter::ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID)
	{
		CThostFtdcUserLogoutField native;
		MNConv<ThostFtdcUserLogoutField^, CThostFtdcUserLogoutField>::M2N(pUserLogout, &native);
		return m_pApi->ReqUserLogout(&native, nRequestID);
	}

	int CTPMDAdapter::SubscribeMarketData(array<String^>^ ppInstrumentID)
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

	int CTPMDAdapter::UnSubscribeMarketData(array<String^>^ ppInstrumentID)
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

	int CTPMDAdapter::SubscribeForQuoteRsp(array<String^>^ ppInstrumentID)
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

		int result = m_pApi->SubscribeForQuoteRsp(pp, count);

		// 释放所有分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}

	int CTPMDAdapter::UnSubscribeForQuoteRsp(array<String^>^ ppInstrumentID)
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

		int result = m_pApi->UnSubscribeForQuoteRsp(pp, count);

		// 释放所分配的字符串内存
		for (int i = 0; i < count; i++)
			delete asp[i];
		delete[] asp;
		delete[] pp;

		return result;
	}
}