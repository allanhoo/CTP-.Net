/////////////////////////////////////////////////////////////////////////
/// CTP期权 C++ => .Net Framework Adapter
/// Author:	shawn666.liu@hotmail.com
/// Date: 20140907
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "Delegates.h"
#include "Struct.h"
#include "ThostFtdcMdApi.h"

namespace  Native{
	class CMdSpi;
};

namespace CTPQQ
{
	using namespace Native;

	public ref class CTPMDAdapter
	{
	internal:
		static String^ _CTPVersionDate = gcnew String("20140521");
	public:
		/// <summary>
		///创建CTPMDAdapter
		///存贮订阅信息文件的目录，默认为当前目录
		/// </summary>
		CTPMDAdapter();
		/// <summary>
		///创建CTPMDAdapter
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp">是否使用UDP协议</param>
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp);
		/// <summary>
		///创建CTPMDAdapter
		/// </summary>
		/// <param name="pszFlowPath">存贮订阅信息文件的目录，默认为当前目录</param>
		/// <param name="bIsUsingUdp">是否使用UDP协议</param>
		/// <param name="bIsMulticast">20130402版增加此参数</param>
		CTPMDAdapter(String^ pszFlowPath, bool bIsUsingUdp, bool bIsMulticast);
		~CTPMDAdapter();
		/// <summary>
		/// 获取对应的CTP官方C++库的版本发布日期，如20140811等
		/// </summary>
		String^ GetCtpVersionDate();
	public:
		/// <summary>
		///删除接口对象本身
		///@remark 不再使用本接口对象时,调用该函数删除接口对象
		/// </summary>
		void Release(void);
		/// <summary>
		///初始化
		///@remark 初始化运行环境,只有调用后,接口才开始工作
		/// </summary>
		void Init(void);
		/// <summary>
		///等待接口线程结束运行
		///@return 线程退出代码
		/// </summary>
		void Join(void);
		/// <summary>
		///获取当前交易日
		///@remark 只有登录成功后,才能得到正确的交易日
		/// </summary>
		/// <returns>获取到的交易日</returns>
		String^ GetTradingDay();
		/// <summary>
		///注册前置机网络地址
		/// </summary>
		/// <param name="pszFrontAddress">
		/// 前置机网络地址
		/// 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。
		/// “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
		/// </param>
		void RegisterFront(String^  pszFrontAddress);
		/// <summary>
		///注册名字服务器网络地址
		/// </summary>
		/// <param name="pszNsAddress">名字服务器网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
		///@remark RegisterNameServer优先于RegisterFront
		/// </param>
		void RegisterNameServer(String^ pszNsAddress);

		/// <summary>
		/// 注册名字服务器用户信息
		/// </summary>
		/// <param name="pFensUserInfo">
		/// 用户信息。
		/// </param>
		void RegisterFensUserInfo(ThostFtdcFensUserInfoField^ pFensUserInfo);

		/// <summary>
		///订阅行情。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID</param>
		int SubscribeMarketData(array<String^>^ ppInstrumentID);
		/// <summary>
		///	退订行情。
		/// </summary>
		/// <param name="ppInstrumentID">合约ID</param>
		int UnSubscribeMarketData(array<String^>^ ppInstrumentID);
		/// <summary>
		/// 订阅询价
		/// </summary>
		/// <param name="ppInstrumentID">合约ID</param>
		int SubscribeForQuoteRsp(array<String^>^ ppInstrumentID);
		/// <summary>
		///	退订询价
		/// </summary>
		/// <param name="ppInstrumentID">合约ID</param>
		int UnSubscribeForQuoteRsp(array<String^>^ ppInstrumentID);
		/// <summary>
		/// 用户登录请求
		/// </summary>
		int ReqUserLogin(ThostFtdcReqUserLoginField^ pReqUserLoginField, int nRequestID);
		/// <summary>
		/// 登出请求
		/// </summary>
		int ReqUserLogout(ThostFtdcUserLogoutField^ pUserLogout, int nRequestID);
		// Events
	public:
		/// <summary>
		/// 处理所有的OnFront****回调事件
		/// </summary>
		event CtpFrontEventHandler^ OnCtpFrontEvent {
			void add(CtpFrontEventHandler^ handler) {
				CtpFrontConnEvent_delegate += handler;
			}
			void remove(CtpFrontEventHandler^ handler) {
				CtpFrontConnEvent_delegate -= handler;
			}
			void raise(Object^ sender, CtpFrontEventArgs^ e) {
				if (CtpFrontConnEvent_delegate)
					CtpFrontConnEvent_delegate(sender, e);
			}
		}
		/// <summary>
		/// 处理所有的OnRsp****回调事件
		/// </summary>
		event CtpRspEventHandler^ OnCtpRspEvent {
			void add(CtpRspEventHandler^ handler) {
				CtpRspEvent_delegate += handler;
			}
			void remove(CtpRspEventHandler^ handler) {
				CtpRspEvent_delegate -= handler;
			}
			void raise(Object^ sender, CtpRspEventArgs^ e) {
				if (CtpRspEvent_delegate)
					CtpRspEvent_delegate(sender, e);
			}
		}

		/// <summary>
		/// 处理所有的OnRtn****回调事件，行情接口仅RtnDepthMarketData
		/// </summary>
		event CtpRtnEventHandler^ OnCtpRtnEvent{
			void add(CtpRtnEventHandler^ handler) { CtpRtn_delegate += handler; }
			void remove(CtpRtnEventHandler^ handler) { CtpRtn_delegate -= handler; }
			void raise(Object^ sender, CtpRtnEventArgs^ e) {
				if (CtpRtn_delegate) CtpRtn_delegate(sender, e);
			}
		}
		// delegates
	private:
		CtpFrontEventHandler^ CtpFrontConnEvent_delegate;
		CtpRspEventHandler^ CtpRspEvent_delegate;
		CtpRtnEventHandler^ CtpRtn_delegate;

		CThostFtdcMdApi* m_pApi;
		CMdSpi* m_pSpi;
	}; // end of class

};// end of namespace