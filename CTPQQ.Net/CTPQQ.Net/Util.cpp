
#include "StdAfx.h"
#include "Util.h"


using namespace System::Runtime::InteropServices;

namespace Native
{
	CAutoStrPtr::CAutoStrPtr(String^ str)
	{
		if(str != nullptr)
			m_pChar = (char*) Marshal::StringToHGlobalAnsi(str).ToPointer();
		else
			 m_pChar = nullptr;
	}

	CAutoStrPtr::~CAutoStrPtr()
	{
		if(m_pChar != nullptr)
			Marshal::FreeHGlobal(IntPtr(m_pChar));
	}


	ThostFtdcRspInfoField^ RspInfoField(CThostFtdcRspInfoField *pRspInfo)
	{
		return safe_cast<ThostFtdcRspInfoField^>(Marshal::PtrToStructure(IntPtr(pRspInfo), ThostFtdcRspInfoField::typeid));
	}

}