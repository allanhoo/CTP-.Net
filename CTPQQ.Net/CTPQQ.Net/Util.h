/////////////////////////////////////////////////////////////////////////
/// CTP期权 C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20140907
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "Struct.h"
#include "ThostFtdcUserApiStruct.h"


namespace Native
{
	using namespace CTPQQ;

	/// 非托管类,自动释放字符串指针内存
	class CAutoStrPtr
	{
	public:
		char* m_pChar;
		CAutoStrPtr(String^ str);
		~CAutoStrPtr();
	};


	/// 非托管类, 自动转换 Managed <==> Native 
	// M: managed
	// N: native
	template<typename M, typename N> 
	class MNConv
	{
	public:
		// 模版类的实现部分必须放在头文件里，否则链接会出错
		/// Native to Managed
		static M N2M(N* pNative){
			return safe_cast<M>(Marshal::PtrToStructure(IntPtr(pNative), M::typeid));
		};
		// Managed to Native
		static void M2N(M managed, N* pNative){
			Marshal::StructureToPtr(managed, IntPtr(pNative), true);
		};
	};

	/// 全局函数
	ThostFtdcRspInfoField^ RspInfoField(CThostFtdcRspInfoField *pRspInfo);

};