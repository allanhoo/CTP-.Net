/////////////////////////////////////////////////////////////////////////
/// CTP证券 C++ => .Net Framework Adapter
/// 初始版本修改自QuantBox,非常感谢
/// https://github.com/QuantBox/CTPZQ
/// Date: 20140906
/////////////////////////////////////////////////////////////////////////

#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

#include "Enum.h"

namespace CTPZQ
{
	/// <summary>
	/// 信息分发
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcDisseminationField
	{
		/// <summary>
		/// 序列系列号
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// 序列号
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// 用户登录请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqUserLoginField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 接口端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ InterfaceProductInfo;
		/// <summary>
		/// 协议信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ProtocolInfo;
		/// <summary>
		/// Mac地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MacAddress;
		/// <summary>
		/// 动态密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ OneTimePassword;
		/// <summary>
		/// 终端IP地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ ClientIPAddress;
	};

	/// <summary>
	/// 用户登录应答
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspUserLoginField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 登录成功时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LoginTime;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易系统名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ SystemName;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 最大报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ MaxOrderRef;
		/// <summary>
		/// 上期所时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SHFETime;
		/// <summary>
		/// 大商所时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ DCETime;
		/// <summary>
		/// 郑商所时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CZCETime;
		/// <summary>
		/// 中金所时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ FFEXTime;
	};

	/// <summary>
	/// 用户登出请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcUserLogoutField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 强制交易员退出
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcForceUserLogoutField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 客户端认证请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqAuthenticateField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 认证码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ AuthCode;
	};

	/// <summary>
	/// 客户端认证响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspAuthenticateField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
	};

	/// <summary>
	/// 客户端认证信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcAuthenticationInfoField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 认证信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ AuthInfo;
		/// <summary>
		/// 是否为认证结果
		/// </summary>
		int IsResult;
	};

	/// <summary>
	/// 银期转帐报文头
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferHeaderField
	{
		/// <summary>
		/// 版本号，常量，1.0
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ Version;
		/// <summary>
		/// 交易代码，必填
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 交易日期，必填，格式：yyyymmdd
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间，必填，格式：hhmmss
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 发起方流水号，N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeSerial;
		/// <summary>
		/// 期货公司代码，必填
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ FutureID;
		/// <summary>
		/// 银行代码，根据查询银行得到，必填
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码，根据查询银行得到，必填
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
		/// <summary>
		/// 操作员，N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 交易设备类型，N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 记录数，N/A
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ RecordNum;
		/// <summary>
		/// 会话编号，N/A
		/// </summary>
		int SessionID;
		/// <summary>
		/// 请求编号，N/A
		/// </summary>
		int RequestID;
	};

	/// <summary>
	/// 银行资金转期货请求，TradeCode=202001
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferBankToFutureReqField
	{
		/// <summary>
		/// 期货资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 密码标志
		/// </summary>
		EnumFuturePwdFlagType FuturePwdFlag;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ FutureAccPwd;
		/// <summary>
		/// 转账金额
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// 客户手续费
		/// </summary>
		double CustFee;
		/// <summary>
		/// 币种：RMB-人民币 USD-美圆 HKD-港元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 银行资金转期货请求响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferBankToFutureRspField
	{
		/// <summary>
		/// 响应代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ RetCode;
		/// <summary>
		/// 响应信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ RetInfo;
		/// <summary>
		/// 资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// 应收客户手续费
		/// </summary>
		double CustFee;
		/// <summary>
		/// 币种
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 期货资金转银行请求，TradeCode=202002
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferFutureToBankReqField
	{
		/// <summary>
		/// 期货资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 密码标志
		/// </summary>
		EnumFuturePwdFlagType FuturePwdFlag;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ FutureAccPwd;
		/// <summary>
		/// 转账金额
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// 客户手续费
		/// </summary>
		double CustFee;
		/// <summary>
		/// 币种：RMB-人民币 USD-美圆 HKD-港元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 期货资金转银行请求响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferFutureToBankRspField
	{
		/// <summary>
		/// 响应代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ RetCode;
		/// <summary>
		/// 响应信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ RetInfo;
		/// <summary>
		/// 资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// 应收客户手续费
		/// </summary>
		double CustFee;
		/// <summary>
		/// 币种
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 查询银行资金请求，TradeCode=204002
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferQryBankReqField
	{
		/// <summary>
		/// 期货资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 密码标志
		/// </summary>
		EnumFuturePwdFlagType FuturePwdFlag;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ FutureAccPwd;
		/// <summary>
		/// 币种：RMB-人民币 USD-美圆 HKD-港元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 查询银行资金请求响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferQryBankRspField
	{
		/// <summary>
		/// 响应代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ RetCode;
		/// <summary>
		/// 响应信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ RetInfo;
		/// <summary>
		/// 资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
		/// <summary>
		/// 银行余额
		/// </summary>
		double TradeAmt;
		/// <summary>
		/// 银行可用余额
		/// </summary>
		double UseAmt;
		/// <summary>
		/// 银行可取余额
		/// </summary>
		double FetchAmt;
		/// <summary>
		/// 币种
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
	};

	/// <summary>
	/// 查询银行交易明细请求，TradeCode=204999
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferQryDetailReqField
	{
		/// <summary>
		/// 期货资金账户
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ FutureAccount;
	};

	/// <summary>
	/// 查询银行交易明细请求响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferQryDetailRspField
	{
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 交易代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 期货流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 期货公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ FutureID;
		/// <summary>
		/// 资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 22)]
		String^ FutureAccount;
		/// <summary>
		/// 银行流水号
		/// </summary>
		int BankSerial;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
		/// <summary>
		/// 银行账号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CertCode;
		/// <summary>
		/// 货币代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyCode;
		/// <summary>
		/// 发生金额
		/// </summary>
		double TxAmount;
		/// <summary>
		/// 有效标志
		/// </summary>
		EnumTransferValidFlagType Flag;
	};

	/// <summary>
	/// 响应信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspInfoField
	{
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 交易所
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeName;
		/// <summary>
		/// 交易所属性
		/// </summary>
		EnumExchangePropertyType ExchangeProperty;
	};

	/// <summary>
	/// 产品
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcProductField
	{
		/// <summary>
		/// 产品代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ProductID;
		/// <summary>
		/// 产品名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ProductName;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 产品类型
		/// </summary>
		EnumProductClassType ProductClass;
		/// <summary>
		/// 合约数量乘数
		/// </summary>
		int VolumeMultiple;
		/// <summary>
		/// 最小变动价位
		/// </summary>
		double PriceTick;
		/// <summary>
		/// 市价单最大下单量
		/// </summary>
		int MaxMarketOrderVolume;
		/// <summary>
		/// 市价单最小下单量
		/// </summary>
		int MinMarketOrderVolume;
		/// <summary>
		/// 限价单最大下单量
		/// </summary>
		int MaxLimitOrderVolume;
		/// <summary>
		/// 限价单最小下单量
		/// </summary>
		int MinLimitOrderVolume;
		/// <summary>
		/// 持仓类型
		/// </summary>
		EnumPositionTypeType PositionType;
		/// <summary>
		/// 持仓日期类型
		/// </summary>
		EnumPositionDateTypeType PositionDateType;
		/// <summary>
		/// ETF最小交易单位
		/// </summary>
		int EFTMinTradeVolume;
	};

	/// <summary>
	/// 合约
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ InstrumentName;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 产品代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ProductID;
		/// <summary>
		/// 产品类型
		/// </summary>
		EnumProductClassType ProductClass;
		/// <summary>
		/// 交割年份
		/// </summary>
		int DeliveryYear;
		/// <summary>
		/// 交割月
		/// </summary>
		int DeliveryMonth;
		/// <summary>
		/// 市价单最大下单量
		/// </summary>
		int MaxMarketOrderVolume;
		/// <summary>
		/// 市价单最小下单量
		/// </summary>
		int MinMarketOrderVolume;
		/// <summary>
		/// 限价单最大下单量
		/// </summary>
		int MaxLimitOrderVolume;
		/// <summary>
		/// 限价单最小下单量
		/// </summary>
		int MinLimitOrderVolume;
		/// <summary>
		/// 合约数量乘数
		/// </summary>
		int VolumeMultiple;
		/// <summary>
		/// 最小变动价位
		/// </summary>
		double PriceTick;
		/// <summary>
		/// 创建日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CreateDate;
		/// <summary>
		/// 上市日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ OpenDate;
		/// <summary>
		/// 到期日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExpireDate;
		/// <summary>
		/// 开始交割日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ StartDelivDate;
		/// <summary>
		/// 结束交割日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ EndDelivDate;
		/// <summary>
		/// 合约生命周期状态
		/// </summary>
		EnumInstLifePhaseType InstLifePhase;
		/// <summary>
		/// 当前是否交易
		/// </summary>
		int IsTrading;
		/// <summary>
		/// 持仓类型
		/// </summary>
		EnumPositionTypeType PositionType;
		/// <summary>
		/// 持仓日期类型
		/// </summary>
		EnumPositionDateTypeType PositionDateType;
		/// <summary>
		/// 报单能否撤单
		/// </summary>
		int OrderCanBeWithdraw;
		/// <summary>
		/// 最小买下单单位
		/// </summary>
		int MinBuyVolume;
		/// <summary>
		/// 最小卖下单单位
		/// </summary>
		int MinSellVolume;
		/// <summary>
		/// 股票权限模版代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ RightModelID;
	};

	/// <summary>
	/// 经纪公司
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 经纪公司简称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BrokerAbbr;
		/// <summary>
		/// 经纪公司名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ BrokerName;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 交易所交易员
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTraderField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装数量
		/// </summary>
		int InstallCount;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
	};

	/// <summary>
	/// 投资者
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorField
	{
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者分组代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorGroupID;
		/// <summary>
		/// 投资者名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ InvestorName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdentifiedCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
		/// <summary>
		/// 联系电话
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 通讯地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 开户日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ OpenDate;
		/// <summary>
		/// 手机
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Mobile;
		/// <summary>
		/// 上海营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SHBranchID;
		/// <summary>
		/// 深圳营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SZBranchID;
		/// <summary>
		/// 是否信用账户
		/// </summary>
		int IsCreditAccount;
	};

	/// <summary>
	/// 交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingCodeField
	{
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 会员编码和经纪公司编码对照表
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcPartBrokerField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 管理用户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSuperUserField
	{
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ UserName;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 管理用户功能权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSuperUserFunctionField
	{
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 功能代码
		/// </summary>
		EnumFunctionCodeType FunctionCode;
	};

	/// <summary>
	/// 投资者组
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorGroupField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者分组代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorGroupID;
		/// <summary>
		/// 投资者分组名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ InvestorGroupName;
	};

	/// <summary>
	/// 资金账户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingAccountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 上次质押金额
		/// </summary>
		double PreMortgage;
		/// <summary>
		/// 上次信用额度
		/// </summary>
		double PreCredit;
		/// <summary>
		/// 上次存款额
		/// </summary>
		double PreDeposit;
		/// <summary>
		/// 上次结算准备金
		/// </summary>
		double PreBalance;
		/// <summary>
		/// 上次占用的保证金
		/// </summary>
		double PreMargin;
		/// <summary>
		/// 利息基数
		/// </summary>
		double InterestBase;
		/// <summary>
		/// 利息收入
		/// </summary>
		double Interest;
		/// <summary>
		/// 入金金额
		/// </summary>
		double Deposit;
		/// <summary>
		/// 出金金额
		/// </summary>
		double Withdraw;
		/// <summary>
		/// 冻结的保证金
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// 冻结的资金
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// 冻结的手续费
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// 当前保证金总额
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// 资金差额
		/// </summary>
		double CashIn;
		/// <summary>
		/// 手续费
		/// </summary>
		double Commission;
		/// <summary>
		/// 融券持仓盈亏
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// 融资持仓盈亏
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// 期货结算准备金
		/// </summary>
		double Balance;
		/// <summary>
		/// 现金
		/// </summary>
		double Available;
		/// <summary>
		/// 可取资金
		/// </summary>
		double WithdrawQuota;
		/// <summary>
		/// 基本准备金
		/// </summary>
		double Reserve;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 保证金可用余额
		/// </summary>
		double Credit;
		/// <summary>
		/// 质押金额
		/// </summary>
		double Mortgage;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// 投资者交割保证金
		/// </summary>
		double DeliveryMargin;
		/// <summary>
		/// 交易所交割保证金
		/// </summary>
		double ExchangeDeliveryMargin;
		/// <summary>
		/// 冻结的过户费
		/// </summary>
		double FrozenTransferFee;
		/// <summary>
		/// 冻结的印花税
		/// </summary>
		double FrozenStampTax;
		/// <summary>
		/// 过户费
		/// </summary>
		double TransferFee;
		/// <summary>
		/// 印花税
		/// </summary>
		double StampTax;
		/// <summary>
		/// 折算金额
		/// </summary>
		double ConversionAmount;
		/// <summary>
		/// 授信额度
		/// </summary>
		double CreditAmount;
		/// <summary>
		/// 最低维持担保比例
		/// </summary>
		double LowLimitRatio;
		/// <summary>
		/// 融资买入金额
		/// </summary>
		double MarginTradingAmount;
		/// <summary>
		/// 融券卖出金额
		/// </summary>
		double ShortSellingAmount;
		/// <summary>
		/// 融资买入可用金额
		/// </summary>
		double MarginTradingAvail;
		/// <summary>
		/// 融券卖出可用金额
		/// </summary>
		double ShortSellingAvail;
		/// <summary>
		/// 维持担保比例
		/// </summary>
		double CreditRatio;
		/// <summary>
		/// 证券总价值
		/// </summary>
		double StockValue;
		/// <summary>
		/// 融券总市值
		/// </summary>
		double SSStockValue;
		/// <summary>
		/// 债券正回购资金
		/// </summary>
		double BondRepurchaseAmount;
		/// <summary>
		/// 债券逆回购占用资金
		/// </summary>
		double ReverseRepurchaseAmount;
	};

	/// <summary>
	/// 投资者持仓
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorPositionField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 持仓多空方向
		/// </summary>
		EnumPosiDirectionType PosiDirection;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 持仓日期
		/// </summary>
		EnumPositionDateType PositionDate;
		/// <summary>
		/// 上日持仓
		/// </summary>
		int YdPosition;
		/// <summary>
		/// 今日持仓
		/// </summary>
		int Position;
		/// <summary>
		/// 多头冻结
		/// </summary>
		int LongFrozen;
		/// <summary>
		/// 空头冻结
		/// </summary>
		int ShortFrozen;
		/// <summary>
		/// 开仓冻结金额
		/// </summary>
		double LongFrozenAmount;
		/// <summary>
		/// 开仓冻结金额
		/// </summary>
		double ShortFrozenAmount;
		/// <summary>
		/// 开仓量
		/// </summary>
		int OpenVolume;
		/// <summary>
		/// 平仓量
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// 开仓金额
		/// </summary>
		double OpenAmount;
		/// <summary>
		/// 平仓金额
		/// </summary>
		double CloseAmount;
		/// <summary>
		/// 持仓成本
		/// </summary>
		double PositionCost;
		/// <summary>
		/// 冻结的资金
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// 资金差额
		/// </summary>
		double CashIn;
		/// <summary>
		/// 手续费
		/// </summary>
		double Commission;
		/// <summary>
		/// 平仓盈亏
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// 持仓盈亏
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 开仓成本
		/// </summary>
		double OpenCost;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// 今日持仓
		/// </summary>
		int TodayPosition;
		/// <summary>
		/// 过户费
		/// </summary>
		double TransferFee;
		/// <summary>
		/// 印花税
		/// </summary>
		double StampTax;
		/// <summary>
		/// 今日申购赎回数量
		/// </summary>
		int TodayPurRedVolume;
		/// <summary>
		/// 折算率
		/// </summary>
		double ConversionRate;
		/// <summary>
		/// 折算金额
		/// </summary>
		double ConversionAmount;
		/// <summary>
		/// 融资买入出数量
		/// </summary>
		int MarginTradeVolume;
		/// <summary>
		/// 融资买入金额
		/// </summary>
		double MarginTradeAmount;
		/// <summary>
		/// 融资买入冻结数量
		/// </summary>
		int MarginTradeFrozenVolume;
		/// <summary>
		/// 融资买入冻结金额
		/// </summary>
		double MarginTradeFrozenAmount;
		/// <summary>
		/// 融资买入盈亏
		/// </summary>
		double MarginTradeConversionAmount;
		/// <summary>
		/// 融券卖出数量
		/// </summary>
		int ShortSellVolume;
		/// <summary>
		/// 融券卖出金额
		/// </summary>
		double ShortSellAmount;
		/// <summary>
		/// 融券卖出盈亏
		/// </summary>
		double ShortSellConversionAmount;
		/// <summary>
		/// 融券卖出冻结数量
		/// </summary>
		int ShortSellFrozenVolume;
		/// <summary>
		/// 融券卖出冻结金额
		/// </summary>
		double ShortSellFrozenAmount;
		/// <summary>
		/// 证券价值
		/// </summary>
		double StockValue;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 今日融资持仓
		/// </summary>
		int TodayMTPosition;
		/// <summary>
		/// 今日融券持仓
		/// </summary>
		int TodaySSPosition;
		/// <summary>
		/// 融券总市值
		/// </summary>
		double SSStockValue;
		/// <summary>
		/// 质押入库数量
		/// </summary>
		int PledgeInPosition;
		/// <summary>
		/// 今日质押入库冻结数量
		/// </summary>
		int PledgeInFrozenPosition;
		/// <summary>
		/// 正回购使用的标准券数量
		/// </summary>
		int RepurchasePosition;
	};

	/// <summary>
	/// 合约保证金率
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentMarginRateField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 多头保证金率
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// 多头保证金费
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// 空头保证金率
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// 空头保证金费
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// 是否相对交易所收取
		/// </summary>
		int IsRelative;
	};

	/// <summary>
	/// 合约手续费率
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentCommissionRateField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 印花税率
		/// </summary>
		double StampTaxRateByMoney;
		/// <summary>
		/// 印花税率(按手数)
		/// </summary>
		double StampTaxRateByVolume;
		/// <summary>
		/// 过户费率
		/// </summary>
		double TransferFeeRateByMoney;
		/// <summary>
		/// 过户费率(按手数)
		/// </summary>
		double TransferFeeRateByVolume;
		/// <summary>
		/// 交易费
		/// </summary>
		double TradeFeeByMoney;
		/// <summary>
		/// 交易费(按手数)
		/// </summary>
		double TradeFeeByVolume;
		/// <summary>
		/// 交易附加费率
		/// </summary>
		double MarginByMoney;
		/// <summary>
		/// 最小过户费
		/// </summary>
		double MinTradeFee;
	};

	/// <summary>
	/// 深度行情
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcDepthMarketDataField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 最新价
		/// </summary>
		double LastPrice;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 昨收盘
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// 昨持仓量
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// 今开盘
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// 最高价
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// 最低价
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交金额
		/// </summary>
		double Turnover;
		/// <summary>
		/// 持仓量
		/// </summary>
		double OpenInterest;
		/// <summary>
		/// 今收盘
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 涨停板价
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// 跌停板价
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// 昨虚实度
		/// </summary>
		double PreDelta;
		/// <summary>
		/// 今虚实度
		/// </summary>
		double CurrDelta;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 最后修改毫秒
		/// </summary>
		int UpdateMillisec;
		/// <summary>
		/// 申买价一
		/// </summary>
		double BidPrice1;
		/// <summary>
		/// 申买量一
		/// </summary>
		int BidVolume1;
		/// <summary>
		/// 申卖价一
		/// </summary>
		double AskPrice1;
		/// <summary>
		/// 申卖量一
		/// </summary>
		int AskVolume1;
		/// <summary>
		/// 申买价二
		/// </summary>
		double BidPrice2;
		/// <summary>
		/// 申买量二
		/// </summary>
		int BidVolume2;
		/// <summary>
		/// 申卖价二
		/// </summary>
		double AskPrice2;
		/// <summary>
		/// 申卖量二
		/// </summary>
		int AskVolume2;
		/// <summary>
		/// 申买价三
		/// </summary>
		double BidPrice3;
		/// <summary>
		/// 申买量三
		/// </summary>
		int BidVolume3;
		/// <summary>
		/// 申卖价三
		/// </summary>
		double AskPrice3;
		/// <summary>
		/// 申卖量三
		/// </summary>
		int AskVolume3;
		/// <summary>
		/// 申买价四
		/// </summary>
		double BidPrice4;
		/// <summary>
		/// 申买量四
		/// </summary>
		int BidVolume4;
		/// <summary>
		/// 申卖价四
		/// </summary>
		double AskPrice4;
		/// <summary>
		/// 申卖量四
		/// </summary>
		int AskVolume4;
		/// <summary>
		/// 申买价五
		/// </summary>
		double BidPrice5;
		/// <summary>
		/// 申买量五
		/// </summary>
		int BidVolume5;
		/// <summary>
		/// 申卖价五
		/// </summary>
		double AskPrice5;
		/// <summary>
		/// 申卖量五
		/// </summary>
		int AskVolume5;
		/// <summary>
		/// 当日均价
		/// </summary>
		double AveragePrice;
	};

	/// <summary>
	/// 投资者合约交易权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentTradingRightField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 买卖
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 交易权限
		/// </summary>
		EnumTradingRightType TradingRight;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 股票权限分类
		/// </summary>
		EnumInstrumentRangeType InstrumentRange;
	};

	/// <summary>
	/// 经纪公司用户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerUserField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ UserName;
		/// <summary>
		/// 用户类型
		/// </summary>
		EnumUserTypeType UserType;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
		/// <summary>
		/// 是否使用令牌
		/// </summary>
		int IsUsingOTP;
	};

	/// <summary>
	/// 经纪公司用户口令
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerUserPasswordField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
	};

	/// <summary>
	/// 经纪公司用户功能权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerUserFunctionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 经纪公司功能代码
		/// </summary>
		EnumBrokerFunctionCodeType BrokerFunctionCode;
	};

	/// <summary>
	/// 交易所交易员报盘机
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTraderOfferField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 交易所交易员连接状态
		/// </summary>
		EnumTraderConnectStatusType TraderConnectStatus;
		/// <summary>
		/// 发出连接请求的日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectRequestDate;
		/// <summary>
		/// 发出连接请求的时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectRequestTime;
		/// <summary>
		/// 上次报告日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportDate;
		/// <summary>
		/// 上次报告时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportTime;
		/// <summary>
		/// 完成连接日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectDate;
		/// <summary>
		/// 完成连接时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectTime;
		/// <summary>
		/// 启动日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ StartDate;
		/// <summary>
		/// 启动时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ StartTime;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
	};

	/// <summary>
	/// 投资者结算结果
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSettlementInfoField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 消息正文
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		String^ Content;
	};

	/// <summary>
	/// 合约保证金率调整
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentMarginRateAdjustField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 多头保证金率
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// 多头保证金费
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// 空头保证金率
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// 空头保证金费
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// 是否相对交易所收取
		/// </summary>
		int IsRelative;
	};

	/// <summary>
	/// 交易所保证金率
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeMarginRateField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 多头保证金率
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// 多头保证金费
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// 空头保证金率
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// 空头保证金费
		/// </summary>
		double ShortMarginRatioByVolume;
	};

	/// <summary>
	/// 交易所保证金率调整
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeMarginRateAdjustField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 跟随交易所投资者多头保证金率
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// 跟随交易所投资者多头保证金费
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// 跟随交易所投资者空头保证金率
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// 跟随交易所投资者空头保证金费
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// 交易所多头保证金率
		/// </summary>
		double ExchLongMarginRatioByMoney;
		/// <summary>
		/// 交易所多头保证金费
		/// </summary>
		double ExchLongMarginRatioByVolume;
		/// <summary>
		/// 交易所空头保证金率
		/// </summary>
		double ExchShortMarginRatioByMoney;
		/// <summary>
		/// 交易所空头保证金费
		/// </summary>
		double ExchShortMarginRatioByVolume;
		/// <summary>
		/// 不跟随交易所投资者多头保证金率
		/// </summary>
		double NoLongMarginRatioByMoney;
		/// <summary>
		/// 不跟随交易所投资者多头保证金费
		/// </summary>
		double NoLongMarginRatioByVolume;
		/// <summary>
		/// 不跟随交易所投资者空头保证金率
		/// </summary>
		double NoShortMarginRatioByMoney;
		/// <summary>
		/// 不跟随交易所投资者空头保证金费
		/// </summary>
		double NoShortMarginRatioByVolume;
	};

	/// <summary>
	/// 结算引用
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSettlementRefField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
	};

	/// <summary>
	/// 当前时间
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcCurrentTimeField
	{
		/// <summary>
		/// 当前日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CurrDate;
		/// <summary>
		/// 当前时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CurrTime;
		/// <summary>
		/// 当前时间（毫秒）
		/// </summary>
		int CurrMillisec;
	};

	/// <summary>
	/// 通讯阶段
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcCommPhaseField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 通讯时段编号
		/// </summary>
		short CommPhaseNo;
	};

	/// <summary>
	/// 登录信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcLoginInfoField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 登录日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LoginDate;
		/// <summary>
		/// 登录时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LoginTime;
		/// <summary>
		/// IP地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ IPAddress;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 接口端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ InterfaceProductInfo;
		/// <summary>
		/// 协议信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ProtocolInfo;
		/// <summary>
		/// 系统名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ SystemName;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 最大报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ MaxOrderRef;
		/// <summary>
		/// Mac地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MacAddress;
		/// <summary>
		/// 动态密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ OneTimePassword;
	};

	/// <summary>
	/// 登录信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcLogoutAllField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 系统名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ SystemName;
	};

	/// <summary>
	/// 前置状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcFrontStatusField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 上次报告日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportDate;
		/// <summary>
		/// 上次报告时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportTime;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 用户口令变更
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcUserPasswordUpdateField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 原来的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ OldPassword;
		/// <summary>
		/// 新的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ NewPassword;
	};

	/// <summary>
	/// 输入报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInputOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 用户强评标志
		/// </summary>
		int UserForceClose;
	};

	/// <summary>
	/// 报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 报单提交状态
		/// </summary>
		EnumOrderSubmitStatusType OrderSubmitStatus;
		/// <summary>
		/// 报单提示序号
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 报单来源
		/// </summary>
		EnumOrderSourceType OrderSource;
		/// <summary>
		/// 报单状态
		/// </summary>
		EnumOrderStatusType OrderStatus;
		/// <summary>
		/// 报单类型
		/// </summary>
		EnumOrderTypeType OrderType;
		/// <summary>
		/// 今成交数量
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// 剩余数量
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// 报单日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertDate;
		/// <summary>
		/// 委托时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTime;
		/// <summary>
		/// 激活时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActiveTime;
		/// <summary>
		/// 挂起时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SuspendTime;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 撤销时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CancelTime;
		/// <summary>
		/// 最后修改交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ActiveTraderID;
		/// <summary>
		/// 结算会员编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClearingPartID;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 状态信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ StatusMsg;
		/// <summary>
		/// 用户强评标志
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// 操作用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ ActiveUserID;
		/// <summary>
		/// 经纪公司报单编号
		/// </summary>
		int BrokerOrderSeq;
		/// <summary>
		/// 相关报单
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ RelativeOrderSysID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
		/// <summary>
		/// 成交数量
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 是否ETF
		/// </summary>
		int IsETF;
		/// <summary>
		/// 资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
	};

	/// <summary>
	/// 交易所报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeOrderField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 报单提交状态
		/// </summary>
		EnumOrderSubmitStatusType OrderSubmitStatus;
		/// <summary>
		/// 报单提示序号
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 报单来源
		/// </summary>
		EnumOrderSourceType OrderSource;
		/// <summary>
		/// 报单状态
		/// </summary>
		EnumOrderStatusType OrderStatus;
		/// <summary>
		/// 报单类型
		/// </summary>
		EnumOrderTypeType OrderType;
		/// <summary>
		/// 今成交数量
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// 剩余数量
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// 报单日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertDate;
		/// <summary>
		/// 委托时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTime;
		/// <summary>
		/// 激活时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActiveTime;
		/// <summary>
		/// 挂起时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SuspendTime;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 撤销时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CancelTime;
		/// <summary>
		/// 最后修改交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ActiveTraderID;
		/// <summary>
		/// 结算会员编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClearingPartID;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
	};

	/// <summary>
	/// 交易所报单插入失败
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeOrderInsertErrorField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 输入报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInputOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 报单操作引用
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 操作标志
		/// </summary>
		EnumActionFlagType ActionFlag;
		/// <summary>
		/// 价格
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// 数量变化
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
	};

	/// <summary>
	/// 报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 报单操作引用
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 操作标志
		/// </summary>
		EnumActionFlagType ActionFlag;
		/// <summary>
		/// 价格
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// 数量变化
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// 操作日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionDate;
		/// <summary>
		/// 操作时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionTime;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 操作本地编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ActionLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 报单操作状态
		/// </summary>
		EnumOrderActionStatusType OrderActionStatus;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
		/// <summary>
		/// 状态信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ StatusMsg;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 交易所报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeOrderActionField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 操作标志
		/// </summary>
		EnumActionFlagType ActionFlag;
		/// <summary>
		/// 价格
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// 数量变化
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// 操作日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionDate;
		/// <summary>
		/// 操作时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionTime;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 操作本地编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ActionLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 报单操作状态
		/// </summary>
		EnumOrderActionStatusType OrderActionStatus;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
	};

	/// <summary>
	/// 交易所报单操作失败
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeOrderActionErrorField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 操作本地编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ActionLocalID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 交易所成交
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeTradeField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 成交编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TradeID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 交易角色
		/// </summary>
		EnumTradingRoleType TradingRole;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 开平标志
		/// </summary>
		EnumOffsetFlagType OffsetFlag;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ Price;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交时期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 成交时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 成交类型
		/// </summary>
		EnumTradeTypeType TradeType;
		/// <summary>
		/// 成交价来源
		/// </summary>
		EnumPriceSourceType PriceSource;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 结算会员编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClearingPartID;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// 成交
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 成交编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TradeID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 交易角色
		/// </summary>
		EnumTradingRoleType TradingRole;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 开平标志
		/// </summary>
		EnumOffsetFlagType OffsetFlag;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ Price;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交时期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 成交时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 成交类型
		/// </summary>
		EnumTradeTypeType TradeType;
		/// <summary>
		/// 成交价来源
		/// </summary>
		EnumPriceSourceType PriceSource;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 结算会员编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClearingPartID;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 经纪公司报单编号
		/// </summary>
		int BrokerOrderSeq;
	};

	/// <summary>
	/// 用户会话
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcUserSessionField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 登录日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LoginDate;
		/// <summary>
		/// 登录时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LoginTime;
		/// <summary>
		/// IP地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ IPAddress;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 接口端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ InterfaceProductInfo;
		/// <summary>
		/// 协议信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ProtocolInfo;
		/// <summary>
		/// Mac地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MacAddress;
	};

	/// <summary>
	/// 查询最大报单数量
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQueryMaxOrderVolumeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 开平标志
		/// </summary>
		EnumOffsetFlagType OffsetFlag;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 最大允许报单数量
		/// </summary>
		int MaxVolume;
	};

	/// <summary>
	/// 投资者结算结果确认信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSettlementInfoConfirmField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 确认日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConfirmDate;
		/// <summary>
		/// 确认时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConfirmTime;
	};

	/// <summary>
	/// 出入金同步
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncDepositField
	{
		/// <summary>
		/// 出入金流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ DepositSeqNo;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 入金金额
		/// </summary>
		double Deposit;
		/// <summary>
		/// 是否强制进行
		/// </summary>
		int IsForce;
	};

	/// <summary>
	/// 经纪公司同步
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerSyncField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 正在同步中的投资者
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInvestorField
	{
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者分组代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorGroupID;
		/// <summary>
		/// 投资者名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ InvestorName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdentifiedCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
		/// <summary>
		/// 联系电话
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 通讯地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 开户日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ OpenDate;
		/// <summary>
		/// 手机
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Mobile;
		/// <summary>
		/// 上海营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SHBranchID;
		/// <summary>
		/// 深圳营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SZBranchID;
		/// <summary>
		/// 是否信用账户
		/// </summary>
		int IsCreditAccount;
	};

	/// <summary>
	/// 正在同步中的交易代码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingTradingCodeField
	{
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 正在同步中的投资者分组
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInvestorGroupField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者分组代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorGroupID;
		/// <summary>
		/// 投资者分组名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ InvestorGroupName;
	};

	/// <summary>
	/// 正在同步中的交易账号
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingTradingAccountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 上次质押金额
		/// </summary>
		double PreMortgage;
		/// <summary>
		/// 上次信用额度
		/// </summary>
		double PreCredit;
		/// <summary>
		/// 上次存款额
		/// </summary>
		double PreDeposit;
		/// <summary>
		/// 上次结算准备金
		/// </summary>
		double PreBalance;
		/// <summary>
		/// 上次占用的保证金
		/// </summary>
		double PreMargin;
		/// <summary>
		/// 利息基数
		/// </summary>
		double InterestBase;
		/// <summary>
		/// 利息收入
		/// </summary>
		double Interest;
		/// <summary>
		/// 入金金额
		/// </summary>
		double Deposit;
		/// <summary>
		/// 出金金额
		/// </summary>
		double Withdraw;
		/// <summary>
		/// 冻结的保证金
		/// </summary>
		double FrozenMargin;
		/// <summary>
		/// 冻结的资金
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// 冻结的手续费
		/// </summary>
		double FrozenCommission;
		/// <summary>
		/// 当前保证金总额
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// 资金差额
		/// </summary>
		double CashIn;
		/// <summary>
		/// 手续费
		/// </summary>
		double Commission;
		/// <summary>
		/// 融券持仓盈亏
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// 融资持仓盈亏
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// 期货结算准备金
		/// </summary>
		double Balance;
		/// <summary>
		/// 现金
		/// </summary>
		double Available;
		/// <summary>
		/// 可取资金
		/// </summary>
		double WithdrawQuota;
		/// <summary>
		/// 基本准备金
		/// </summary>
		double Reserve;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 保证金可用余额
		/// </summary>
		double Credit;
		/// <summary>
		/// 质押金额
		/// </summary>
		double Mortgage;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// 投资者交割保证金
		/// </summary>
		double DeliveryMargin;
		/// <summary>
		/// 交易所交割保证金
		/// </summary>
		double ExchangeDeliveryMargin;
		/// <summary>
		/// 冻结的过户费
		/// </summary>
		double FrozenTransferFee;
		/// <summary>
		/// 冻结的印花税
		/// </summary>
		double FrozenStampTax;
		/// <summary>
		/// 过户费
		/// </summary>
		double TransferFee;
		/// <summary>
		/// 印花税
		/// </summary>
		double StampTax;
		/// <summary>
		/// 折算金额
		/// </summary>
		double ConversionAmount;
		/// <summary>
		/// 授信额度
		/// </summary>
		double CreditAmount;
		/// <summary>
		/// 最低维持担保比例
		/// </summary>
		double LowLimitRatio;
		/// <summary>
		/// 融资买入金额
		/// </summary>
		double MarginTradingAmount;
		/// <summary>
		/// 融券卖出金额
		/// </summary>
		double ShortSellingAmount;
		/// <summary>
		/// 融资买入可用金额
		/// </summary>
		double MarginTradingAvail;
		/// <summary>
		/// 融券卖出可用金额
		/// </summary>
		double ShortSellingAvail;
		/// <summary>
		/// 维持担保比例
		/// </summary>
		double CreditRatio;
		/// <summary>
		/// 证券总价值
		/// </summary>
		double StockValue;
		/// <summary>
		/// 融券总市值
		/// </summary>
		double SSStockValue;
		/// <summary>
		/// 债券正回购资金
		/// </summary>
		double BondRepurchaseAmount;
		/// <summary>
		/// 债券逆回购占用资金
		/// </summary>
		double ReverseRepurchaseAmount;
	};

	/// <summary>
	/// 正在同步中的投资者持仓
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInvestorPositionField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 持仓多空方向
		/// </summary>
		EnumPosiDirectionType PosiDirection;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 持仓日期
		/// </summary>
		EnumPositionDateType PositionDate;
		/// <summary>
		/// 上日持仓
		/// </summary>
		int YdPosition;
		/// <summary>
		/// 今日持仓
		/// </summary>
		int Position;
		/// <summary>
		/// 多头冻结
		/// </summary>
		int LongFrozen;
		/// <summary>
		/// 空头冻结
		/// </summary>
		int ShortFrozen;
		/// <summary>
		/// 开仓冻结金额
		/// </summary>
		double LongFrozenAmount;
		/// <summary>
		/// 开仓冻结金额
		/// </summary>
		double ShortFrozenAmount;
		/// <summary>
		/// 开仓量
		/// </summary>
		int OpenVolume;
		/// <summary>
		/// 平仓量
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// 开仓金额
		/// </summary>
		double OpenAmount;
		/// <summary>
		/// 平仓金额
		/// </summary>
		double CloseAmount;
		/// <summary>
		/// 持仓成本
		/// </summary>
		double PositionCost;
		/// <summary>
		/// 冻结的资金
		/// </summary>
		double FrozenCash;
		/// <summary>
		/// 资金差额
		/// </summary>
		double CashIn;
		/// <summary>
		/// 手续费
		/// </summary>
		double Commission;
		/// <summary>
		/// 平仓盈亏
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// 持仓盈亏
		/// </summary>
		double PositionProfit;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 开仓成本
		/// </summary>
		double OpenCost;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchangeMargin;
		/// <summary>
		/// 今日持仓
		/// </summary>
		int TodayPosition;
		/// <summary>
		/// 过户费
		/// </summary>
		double TransferFee;
		/// <summary>
		/// 印花税
		/// </summary>
		double StampTax;
		/// <summary>
		/// 今日申购赎回数量
		/// </summary>
		int TodayPurRedVolume;
		/// <summary>
		/// 折算率
		/// </summary>
		double ConversionRate;
		/// <summary>
		/// 折算金额
		/// </summary>
		double ConversionAmount;
		/// <summary>
		/// 融资买入出数量
		/// </summary>
		int MarginTradeVolume;
		/// <summary>
		/// 融资买入金额
		/// </summary>
		double MarginTradeAmount;
		/// <summary>
		/// 融资买入冻结数量
		/// </summary>
		int MarginTradeFrozenVolume;
		/// <summary>
		/// 融资买入冻结金额
		/// </summary>
		double MarginTradeFrozenAmount;
		/// <summary>
		/// 融资买入盈亏
		/// </summary>
		double MarginTradeConversionAmount;
		/// <summary>
		/// 融券卖出数量
		/// </summary>
		int ShortSellVolume;
		/// <summary>
		/// 融券卖出金额
		/// </summary>
		double ShortSellAmount;
		/// <summary>
		/// 融券卖出盈亏
		/// </summary>
		double ShortSellConversionAmount;
		/// <summary>
		/// 融券卖出冻结数量
		/// </summary>
		int ShortSellFrozenVolume;
		/// <summary>
		/// 融券卖出冻结金额
		/// </summary>
		double ShortSellFrozenAmount;
		/// <summary>
		/// 证券价值
		/// </summary>
		double StockValue;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 今日融资持仓
		/// </summary>
		int TodayMTPosition;
		/// <summary>
		/// 今日融券持仓
		/// </summary>
		int TodaySSPosition;
		/// <summary>
		/// 融券总市值
		/// </summary>
		double SSStockValue;
		/// <summary>
		/// 质押入库数量
		/// </summary>
		int PledgeInPosition;
		/// <summary>
		/// 今日质押入库冻结数量
		/// </summary>
		int PledgeInFrozenPosition;
		/// <summary>
		/// 正回购使用的标准券数量
		/// </summary>
		int RepurchasePosition;
	};

	/// <summary>
	/// 正在同步中的合约保证金率
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInstrumentMarginRateField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 多头保证金率
		/// </summary>
		double LongMarginRatioByMoney;
		/// <summary>
		/// 多头保证金费
		/// </summary>
		double LongMarginRatioByVolume;
		/// <summary>
		/// 空头保证金率
		/// </summary>
		double ShortMarginRatioByMoney;
		/// <summary>
		/// 空头保证金费
		/// </summary>
		double ShortMarginRatioByVolume;
		/// <summary>
		/// 是否相对交易所收取
		/// </summary>
		int IsRelative;
	};

	/// <summary>
	/// 正在同步中的合约手续费率
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInstrumentCommissionRateField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 印花税率
		/// </summary>
		double StampTaxRateByMoney;
		/// <summary>
		/// 印花税率(按手数)
		/// </summary>
		double StampTaxRateByVolume;
		/// <summary>
		/// 过户费率
		/// </summary>
		double TransferFeeRateByMoney;
		/// <summary>
		/// 过户费率(按手数)
		/// </summary>
		double TransferFeeRateByVolume;
		/// <summary>
		/// 交易费
		/// </summary>
		double TradeFeeByMoney;
		/// <summary>
		/// 交易费(按手数)
		/// </summary>
		double TradeFeeByVolume;
		/// <summary>
		/// 交易附加费率
		/// </summary>
		double MarginByMoney;
		/// <summary>
		/// 最小过户费
		/// </summary>
		double MinTradeFee;
	};

	/// <summary>
	/// 正在同步中的合约交易权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncingInstrumentTradingRightField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 买卖
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 交易权限
		/// </summary>
		EnumTradingRightType TradingRight;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 股票权限分类
		/// </summary>
		EnumInstrumentRangeType InstrumentRange;
	};

	/// <summary>
	/// 查询报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 开始时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTimeStart;
		/// <summary>
		/// 结束时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTimeEnd;
	};

	/// <summary>
	/// 查询成交
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTradeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 成交编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TradeID;
		/// <summary>
		/// 开始时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTimeStart;
		/// <summary>
		/// 结束时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTimeEnd;
	};

	/// <summary>
	/// 查询投资者持仓
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInvestorPositionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询资金账户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTradingAccountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 查询投资者
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInvestorField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 查询交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTradingCodeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
	};

	/// <summary>
	/// 查询交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInvestorGroupField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 查询交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInstrumentMarginRateField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
	};

	/// <summary>
	/// 查询交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInstrumentCommissionRateField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询交易编码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInstrumentTradingRightField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询经纪公司
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 查询交易员
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTraderField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
	};

	/// <summary>
	/// 查询经纪公司会员代码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryPartBrokerField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
	};

	/// <summary>
	/// 查询管理用户功能权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySuperUserFunctionField
	{
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 查询用户会话
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryUserSessionField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 查询前置状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryFrontStatusField
	{
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
	};

	/// <summary>
	/// 查询交易所报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryExchangeOrderField
	{
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
	};

	/// <summary>
	/// 查询报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 查询交易所报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryExchangeOrderActionField
	{
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
	};

	/// <summary>
	/// 查询管理用户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySuperUserField
	{
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 查询交易所
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryExchangeField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 查询产品
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryProductField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 产品代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ProductID;
	};

	/// <summary>
	/// 查询合约
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInstrumentField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 产品代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ProductID;
	};

	/// <summary>
	/// 查询行情
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryDepthMarketDataField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询经纪公司用户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerUserField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 查询经纪公司用户权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerUserFunctionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
	};

	/// <summary>
	/// 查询交易员报盘机
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTraderOfferField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
	};

	/// <summary>
	/// 查询出入金流水
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySyncDepositField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 出入金流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ DepositSeqNo;
	};

	/// <summary>
	/// 查询投资者结算结果
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySettlementInfoField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
	};

	/// <summary>
	/// 查询报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryHisOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 开始时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTimeStart;
		/// <summary>
		/// 结束时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTimeEnd;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
	};

	/// <summary>
	/// 市场行情
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 最新价
		/// </summary>
		double LastPrice;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 昨收盘
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// 昨持仓量
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// 今开盘
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// 最高价
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// 最低价
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交金额
		/// </summary>
		double Turnover;
		/// <summary>
		/// 持仓量
		/// </summary>
		double OpenInterest;
		/// <summary>
		/// 今收盘
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 涨停板价
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// 跌停板价
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// 昨虚实度
		/// </summary>
		double PreDelta;
		/// <summary>
		/// 今虚实度
		/// </summary>
		double CurrDelta;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 最后修改毫秒
		/// </summary>
		int UpdateMillisec;
	};

	/// <summary>
	/// 行情交易所代码属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataExchangeField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 行情基础属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataBaseField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 上次结算价
		/// </summary>
		double PreSettlementPrice;
		/// <summary>
		/// 昨收盘
		/// </summary>
		double PreClosePrice;
		/// <summary>
		/// 昨持仓量
		/// </summary>
		double PreOpenInterest;
		/// <summary>
		/// 昨虚实度
		/// </summary>
		double PreDelta;
	};

	/// <summary>
	/// 行情静态属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataStaticField
	{
		/// <summary>
		/// 今开盘
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// 最高价
		/// </summary>
		double HighestPrice;
		/// <summary>
		/// 最低价
		/// </summary>
		double LowestPrice;
		/// <summary>
		/// 今收盘
		/// </summary>
		double ClosePrice;
		/// <summary>
		/// 涨停板价
		/// </summary>
		double UpperLimitPrice;
		/// <summary>
		/// 跌停板价
		/// </summary>
		double LowerLimitPrice;
		/// <summary>
		/// 本次结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 今虚实度
		/// </summary>
		double CurrDelta;
	};

	/// <summary>
	/// 行情最新成交属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataLastMatchField
	{
		/// <summary>
		/// 最新价
		/// </summary>
		double LastPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 成交金额
		/// </summary>
		double Turnover;
		/// <summary>
		/// 持仓量
		/// </summary>
		double OpenInterest;
	};

	/// <summary>
	/// 行情最优价属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataBestPriceField
	{
		/// <summary>
		/// 申买价一
		/// </summary>
		double BidPrice1;
		/// <summary>
		/// 申买量一
		/// </summary>
		int BidVolume1;
		/// <summary>
		/// 申卖价一
		/// </summary>
		double AskPrice1;
		/// <summary>
		/// 申卖量一
		/// </summary>
		int AskVolume1;
	};

	/// <summary>
	/// 行情申买二、三属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataBid23Field
	{
		/// <summary>
		/// 申买价二
		/// </summary>
		double BidPrice2;
		/// <summary>
		/// 申买量二
		/// </summary>
		int BidVolume2;
		/// <summary>
		/// 申买价三
		/// </summary>
		double BidPrice3;
		/// <summary>
		/// 申买量三
		/// </summary>
		int BidVolume3;
	};

	/// <summary>
	/// 行情申卖二、三属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataAsk23Field
	{
		/// <summary>
		/// 申卖价二
		/// </summary>
		double AskPrice2;
		/// <summary>
		/// 申卖量二
		/// </summary>
		int AskVolume2;
		/// <summary>
		/// 申卖价三
		/// </summary>
		double AskPrice3;
		/// <summary>
		/// 申卖量三
		/// </summary>
		int AskVolume3;
	};

	/// <summary>
	/// 行情申买四、五属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataBid45Field
	{
		/// <summary>
		/// 申买价四
		/// </summary>
		double BidPrice4;
		/// <summary>
		/// 申买量四
		/// </summary>
		int BidVolume4;
		/// <summary>
		/// 申买价五
		/// </summary>
		double BidPrice5;
		/// <summary>
		/// 申买量五
		/// </summary>
		int BidVolume5;
	};

	/// <summary>
	/// 行情申卖四、五属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataAsk45Field
	{
		/// <summary>
		/// 申卖价四
		/// </summary>
		double AskPrice4;
		/// <summary>
		/// 申卖量四
		/// </summary>
		int AskVolume4;
		/// <summary>
		/// 申卖价五
		/// </summary>
		double AskPrice5;
		/// <summary>
		/// 申卖量五
		/// </summary>
		int AskVolume5;
	};

	/// <summary>
	/// 行情更新时间属性
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataUpdateTimeField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 最后修改毫秒
		/// </summary>
		int UpdateMillisec;
	};

	/// <summary>
	/// 指定的合约
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSpecificInstrumentField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 合约状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInstrumentStatusField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 结算组代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SettlementGroupID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 合约交易状态
		/// </summary>
		EnumInstrumentStatusType InstrumentStatus;
		/// <summary>
		/// 交易阶段编号
		/// </summary>
		int TradingSegmentSN;
		/// <summary>
		/// 进入本状态时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ EnterTime;
		/// <summary>
		/// 进入本状态原因
		/// </summary>
		EnumInstStatusEnterReasonType EnterReason;
	};

	/// <summary>
	/// 查询合约状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInstrumentStatusField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
	};

	/// <summary>
	/// 投资者账户
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorAccountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
	};

	/// <summary>
	/// 浮动盈亏算法
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcPositionProfitAlgorithmField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 盈亏算法
		/// </summary>
		EnumAlgorithmType Algorithm;
		/// <summary>
		/// 备注
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 161)]
		String^ Memo;
	};

	/// <summary>
	/// 会员资金折扣
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcDiscountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 资金折扣比例
		/// </summary>
		double Discount;
	};

	/// <summary>
	/// 查询转帐银行
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTransferBankField
	{
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
	};

	/// <summary>
	/// 转帐银行
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferBankField
	{
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
		/// <summary>
		/// 银行名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ BankName;
		/// <summary>
		/// 是否活跃
		/// </summary>
		int IsActive;
	};

	/// <summary>
	/// 查询投资者持仓明细
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInvestorPositionDetailField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 投资者持仓明细
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorPositionDetailField
	{
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 买卖
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 开仓日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ OpenDate;
		/// <summary>
		/// 成交编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TradeID;
		/// <summary>
		/// 数量
		/// </summary>
		int Volume;
		/// <summary>
		/// 开仓价
		/// </summary>
		double OpenPrice;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 成交类型
		/// </summary>
		EnumTradeTypeType TradeType;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 投资者保证金
		/// </summary>
		double Margin;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchMargin;
		/// <summary>
		/// 昨结算价
		/// </summary>
		double LastSettlementPrice;
		/// <summary>
		/// 结算价
		/// </summary>
		double SettlementPrice;
		/// <summary>
		/// 平仓量
		/// </summary>
		int CloseVolume;
		/// <summary>
		/// 平仓金额
		/// </summary>
		double CloseAmount;
		/// <summary>
		/// 过户费
		/// </summary>
		double TransferFee;
		/// <summary>
		/// 印花税
		/// </summary>
		double StampTax;
		/// <summary>
		/// 手续费
		/// </summary>
		double Commission;
		/// <summary>
		/// 融资融券金额
		/// </summary>
		double Amount;
		/// <summary>
		/// 质押入库数量
		/// </summary>
		int PledgeInPosition;
		/// <summary>
		/// 今日质押入库冻结数量
		/// </summary>
		int PledgeInFrozenPosition;
		/// <summary>
		/// 正回购使用的标准券数量
		/// </summary>
		int RepurchasePosition;
	};

	/// <summary>
	/// 资金账户口令域
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingAccountPasswordField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
	};

	/// <summary>
	/// 交易所行情报盘机
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMDTraderOfferField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 交易所交易员连接状态
		/// </summary>
		EnumTraderConnectStatusType TraderConnectStatus;
		/// <summary>
		/// 发出连接请求的日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectRequestDate;
		/// <summary>
		/// 发出连接请求的时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectRequestTime;
		/// <summary>
		/// 上次报告日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportDate;
		/// <summary>
		/// 上次报告时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LastReportTime;
		/// <summary>
		/// 完成连接日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectDate;
		/// <summary>
		/// 完成连接时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ConnectTime;
		/// <summary>
		/// 启动日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ StartDate;
		/// <summary>
		/// 启动时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ StartTime;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
	};

	/// <summary>
	/// 查询行情报盘机
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryMDTraderOfferField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
	};

	/// <summary>
	/// 查询客户通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryNoticeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 客户通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcNoticeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 消息正文
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		String^ Content;
		/// <summary>
		/// 经纪公司通知内容序列号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
		String^ SequenceLabel;
	};

	/// <summary>
	/// 用户权限
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcUserRightField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 客户权限类型
		/// </summary>
		EnumUserRightTypeType UserRightType;
		/// <summary>
		/// 是否禁止
		/// </summary>
		int IsForbidden;
	};

	/// <summary>
	/// 查询结算信息确认域
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySettlementInfoConfirmField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 装载结算信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcLoadSettlementInfoField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 经纪公司可提资金算法表
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerWithdrawAlgorithmField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 可提资金算法
		/// </summary>
		EnumAlgorithmType WithdrawAlgorithm;
		/// <summary>
		/// 资金使用率
		/// </summary>
		double UsingRatio;
		/// <summary>
		/// 可提是否包含平仓盈利
		/// </summary>
		EnumIncludeCloseProfitType IncludeCloseProfit;
		/// <summary>
		/// 本日无仓且无成交客户是否受可提比例限制
		/// </summary>
		EnumAllWithoutTradeType AllWithoutTrade;
		/// <summary>
		/// 可用是否包含平仓盈利
		/// </summary>
		EnumIncludeCloseProfitType AvailIncludeCloseProfit;
		/// <summary>
		/// 是否启用用户事件
		/// </summary>
		int IsBrokerUserEvent;
	};

	/// <summary>
	/// 资金账户口令变更域
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingAccountPasswordUpdateV1Field
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 原来的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ OldPassword;
		/// <summary>
		/// 新的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ NewPassword;
	};

	/// <summary>
	/// 资金账户口令变更域
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingAccountPasswordUpdateField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 原来的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ OldPassword;
		/// <summary>
		/// 新的口令
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ NewPassword;
	};

	/// <summary>
	/// 查询组合合约分腿
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryCombinationLegField
	{
		/// <summary>
		/// 组合合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ CombInstrumentID;
		/// <summary>
		/// 单腿编号
		/// </summary>
		int LegID;
		/// <summary>
		/// 单腿合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ LegInstrumentID;
	};

	/// <summary>
	/// 查询组合合约分腿
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQrySyncStatusField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
	};

	/// <summary>
	/// 组合交易合约的单腿
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcCombinationLegField
	{
		/// <summary>
		/// 组合合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ CombInstrumentID;
		/// <summary>
		/// 单腿编号
		/// </summary>
		int LegID;
		/// <summary>
		/// 单腿合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ LegInstrumentID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 单腿乘数
		/// </summary>
		int LegMultiple;
		/// <summary>
		/// 派生层数
		/// </summary>
		int ImplyLevel;
	};

	/// <summary>
	/// 数据同步状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcSyncStatusField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 数据同步状态
		/// </summary>
		EnumDataSyncStatusType DataSyncStatus;
	};

	/// <summary>
	/// 查询联系人
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryLinkManField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 联系人
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcLinkManField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 联系人类型
		/// </summary>
		EnumPersonTypeType PersonType;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdentifiedCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ PersonName;
		/// <summary>
		/// 联系电话
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 通讯地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 邮政编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ZipCode;
		/// <summary>
		/// 优先级
		/// </summary>
		int Priority;
	};

	/// <summary>
	/// 查询经纪公司用户事件
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerUserEventField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户事件类型
		/// </summary>
		EnumUserEventTypeType UserEventType;
	};

	/// <summary>
	/// 查询经纪公司用户事件
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerUserEventField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 用户事件类型
		/// </summary>
		EnumUserEventTypeType UserEventType;
		/// <summary>
		/// 用户事件序号
		/// </summary>
		int EventSequenceNo;
		/// <summary>
		/// 事件发生日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ EventDate;
		/// <summary>
		/// 事件发生时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ EventTime;
		/// <summary>
		/// 用户事件信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1025)]
		String^ UserEventInfo;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询签约银行请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryContractBankField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
	};

	/// <summary>
	/// 查询签约银行响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcContractBankField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分中心代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBrchID;
		/// <summary>
		/// 银行名称
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ BankName;
	};

	/// <summary>
	/// 投资者组合持仓明细
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorPositionCombineDetailField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 开仓日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ OpenDate;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 组合编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ComTradeID;
		/// <summary>
		/// 撮合编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TradeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 买卖
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 持仓量
		/// </summary>
		int TotalAmt;
		/// <summary>
		/// 投资者保证金
		/// </summary>
		double Margin;
		/// <summary>
		/// 交易所保证金
		/// </summary>
		double ExchMargin;
		/// <summary>
		/// 保证金率
		/// </summary>
		double MarginRateByMoney;
		/// <summary>
		/// 保证金率(按手数)
		/// </summary>
		double MarginRateByVolume;
		/// <summary>
		/// 单腿编号
		/// </summary>
		int LegID;
		/// <summary>
		/// 单腿乘数
		/// </summary>
		int LegMultiple;
		/// <summary>
		/// 组合持仓合约编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ CombInstrumentID;
	};

	/// <summary>
	/// 预埋单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcParkedOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 用户强评标志
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// 预埋报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ParkedOrderID;
		/// <summary>
		/// 用户类型
		/// </summary>
		EnumUserTypeType UserType;
		/// <summary>
		/// 预埋单状态
		/// </summary>
		EnumParkedOrderStatusType Status;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 输入预埋单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcParkedOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 报单操作引用
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 操作标志
		/// </summary>
		EnumActionFlagType ActionFlag;
		/// <summary>
		/// 价格
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// 数量变化
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 预埋撤单单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ParkedOrderActionID;
		/// <summary>
		/// 用户类型
		/// </summary>
		EnumUserTypeType UserType;
		/// <summary>
		/// 预埋撤单状态
		/// </summary>
		EnumParkedOrderStatusType Status;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询预埋单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryParkedOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 查询预埋撤单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryParkedOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 删除预埋单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRemoveParkedOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 预埋报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ParkedOrderID;
	};

	/// <summary>
	/// 删除预埋撤单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRemoveParkedOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 预埋撤单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ParkedOrderActionID;
	};

	/// <summary>
	/// 经纪公司可提资金算法表
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorWithdrawAlgorithmField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 可提资金比例
		/// </summary>
		double UsingRatio;
	};

	/// <summary>
	/// 查询组合持仓明细
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryInvestorPositionCombineDetailField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 组合持仓合约编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ CombInstrumentID;
	};

	/// <summary>
	/// 成交均价
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMarketDataAveragePriceField
	{
		/// <summary>
		/// 当日均价
		/// </summary>
		double AveragePrice;
	};

	/// <summary>
	/// 校验投资者密码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcVerifyInvestorPasswordField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
	};

	/// <summary>
	/// 用户IP
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcUserIPField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// IP地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ IPAddress;
		/// <summary>
		/// IP地址掩码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ IPMask;
		/// <summary>
		/// Mac地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MacAddress;
	};

	/// <summary>
	/// 用户事件通知信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingNoticeInfoField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 发送时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SendTime;
		/// <summary>
		/// 消息正文
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		String^ FieldContent;
		/// <summary>
		/// 序列系列号
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// 序列号
		/// </summary>
		int SequenceNo;
	};

	/// <summary>
	/// 用户事件通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTradingNoticeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者范围
		/// </summary>
		EnumInvestorRangeType InvestorRange;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 序列系列号
		/// </summary>
		short SequenceSeries;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 发送时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SendTime;
		/// <summary>
		/// 序列号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 消息正文
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]
		String^ FieldContent;
	};

	/// <summary>
	/// 查询交易事件通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTradingNoticeField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 查询错误报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryErrOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 错误报单
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcErrOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 用户强评标志
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询错误报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcErrorConditionalOrderField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 报单价格条件
		/// </summary>
		EnumOrderPriceTypeType OrderPriceType;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 组合开平标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombOffsetFlag;
		/// <summary>
		/// 组合投机套保标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ CombHedgeFlag;
		/// <summary>
		/// 价格
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ LimitPrice;
		/// <summary>
		/// 数量
		/// </summary>
		int VolumeTotalOriginal;
		/// <summary>
		/// 有效期类型
		/// </summary>
		EnumTimeConditionType TimeCondition;
		/// <summary>
		/// GTD日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ GTDDate;
		/// <summary>
		/// 成交量类型
		/// </summary>
		EnumVolumeConditionType VolumeCondition;
		/// <summary>
		/// 最小成交量
		/// </summary>
		int MinVolume;
		/// <summary>
		/// 触发条件
		/// </summary>
		EnumContingentConditionType ContingentCondition;
		/// <summary>
		/// 止损价
		/// </summary>
		double StopPrice;
		/// <summary>
		/// 强平原因
		/// </summary>
		EnumForceCloseReasonType ForceCloseReason;
		/// <summary>
		/// 自动挂起标志
		/// </summary>
		int IsAutoSuspend;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 合约在交易所的代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ ExchangeInstID;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 报单提交状态
		/// </summary>
		EnumOrderSubmitStatusType OrderSubmitStatus;
		/// <summary>
		/// 报单提示序号
		/// </summary>
		int NotifySequence;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 结算编号
		/// </summary>
		int SettlementID;
		/// <summary>
		/// 报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ OrderSysID;
		/// <summary>
		/// 报单来源
		/// </summary>
		EnumOrderSourceType OrderSource;
		/// <summary>
		/// 报单状态
		/// </summary>
		EnumOrderStatusType OrderStatus;
		/// <summary>
		/// 报单类型
		/// </summary>
		EnumOrderTypeType OrderType;
		/// <summary>
		/// 今成交数量
		/// </summary>
		int VolumeTraded;
		/// <summary>
		/// 剩余数量
		/// </summary>
		int VolumeTotal;
		/// <summary>
		/// 报单日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertDate;
		/// <summary>
		/// 委托时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ InsertTime;
		/// <summary>
		/// 激活时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActiveTime;
		/// <summary>
		/// 挂起时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ SuspendTime;
		/// <summary>
		/// 最后修改时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ UpdateTime;
		/// <summary>
		/// 撤销时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CancelTime;
		/// <summary>
		/// 最后修改交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ ActiveTraderID;
		/// <summary>
		/// 结算会员编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClearingPartID;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 用户端产品信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ UserProductInfo;
		/// <summary>
		/// 状态信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ StatusMsg;
		/// <summary>
		/// 用户强评标志
		/// </summary>
		int UserForceClose;
		/// <summary>
		/// 操作用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ ActiveUserID;
		/// <summary>
		/// 经纪公司报单编号
		/// </summary>
		int BrokerOrderSeq;
		/// <summary>
		/// 相关报单
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ RelativeOrderSysID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
		/// <summary>
		/// 成交数量
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 是否ETF
		/// </summary>
		int IsETF;
		/// <summary>
		/// 资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询错误报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryErrOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 错误报单操作
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcErrOrderActionField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 报单操作引用
		/// </summary>
		int OrderActionRef;
		/// <summary>
		/// 报单引用
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderRef;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 前置编号
		/// </summary>
		int FrontID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 操作标志
		/// </summary>
		EnumActionFlagType ActionFlag;
		/// <summary>
		/// 价格
		/// </summary>
		double LimitPrice;
		/// <summary>
		/// 数量变化
		/// </summary>
		int VolumeChange;
		/// <summary>
		/// 操作日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionDate;
		/// <summary>
		/// 操作时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ActionTime;
		/// <summary>
		/// 交易所交易员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ TraderID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 本地报单编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ OrderLocalID;
		/// <summary>
		/// 操作本地编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ ActionLocalID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 客户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ClientID;
		/// <summary>
		/// 业务单元
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ BusinessUnit;
		/// <summary>
		/// 报单操作状态
		/// </summary>
		EnumOrderActionStatusType OrderActionStatus;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 营业部编号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ BranchID;
		/// <summary>
		/// 状态信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ StatusMsg;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询交易所状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryExchangeSequenceField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 交易所状态
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcExchangeSequenceField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 序号
		/// </summary>
		int SequenceNo;
		/// <summary>
		/// 合约交易状态
		/// </summary>
		EnumInstrumentStatusType MarketStatus;
	};

	/// <summary>
	/// 根据价格查询最大报单数量
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQueryMaxOrderVolumeWithPriceField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 买卖方向
		/// </summary>
		EnumDirectionType Direction;
		/// <summary>
		/// 开平标志
		/// </summary>
		EnumOffsetFlagType OffsetFlag;
		/// <summary>
		/// 投机套保标志
		/// </summary>
		EnumHedgeFlagType HedgeFlag;
		/// <summary>
		/// 最大允许报单数量
		/// </summary>
		int MaxVolume;
		/// <summary>
		/// 报单价格
		/// </summary>
		double Price;
	};

	/// <summary>
	/// 查询经纪公司交易参数
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerTradingParamsField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 经纪公司交易参数
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerTradingParamsField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 保证金价格类型
		/// </summary>
		EnumMarginPriceTypeType MarginPriceType;
		/// <summary>
		/// 盈亏算法
		/// </summary>
		EnumAlgorithmType Algorithm;
		/// <summary>
		/// 可用是否包含平仓盈利
		/// </summary>
		EnumIncludeCloseProfitType AvailIncludeCloseProfit;
	};

	/// <summary>
	/// 查询经纪公司交易算法
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBrokerTradingAlgosField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 经纪公司交易算法
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerTradingAlgosField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 持仓处理算法编号
		/// </summary>
		EnumHandlePositionAlgoIDType HandlePositionAlgoID;
		/// <summary>
		/// 寻找保证金率算法编号
		/// </summary>
		EnumFindMarginRateAlgoIDType FindMarginRateAlgoID;
		/// <summary>
		/// 资金处理算法编号
		/// </summary>
		EnumHandleTradingAccountAlgoIDType HandleTradingAccountAlgoID;
	};

	/// <summary>
	/// 查询经纪公司资金
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQueryBrokerDepositField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
	};

	/// <summary>
	/// 经纪公司资金
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerDepositField
	{
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 会员代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 上次结算准备金
		/// </summary>
		double PreBalance;
		/// <summary>
		/// 当前保证金总额
		/// </summary>
		double CurrMargin;
		/// <summary>
		/// 平仓盈亏
		/// </summary>
		double CloseProfit;
		/// <summary>
		/// 期货结算准备金
		/// </summary>
		double Balance;
		/// <summary>
		/// 入金金额
		/// </summary>
		double Deposit;
		/// <summary>
		/// 出金金额
		/// </summary>
		double Withdraw;
		/// <summary>
		/// 可提资金
		/// </summary>
		double Available;
		/// <summary>
		/// 基本准备金
		/// </summary>
		double Reserve;
		/// <summary>
		/// 冻结的保证金
		/// </summary>
		double FrozenMargin;
	};

	/// <summary>
	/// 查询保证金监管系统经纪公司密钥
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryCFMMCBrokerKeyField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
	};

	/// <summary>
	/// 保证金监管系统经纪公司密钥
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcCFMMCBrokerKeyField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 经纪公司统一编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 密钥生成日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CreateDate;
		/// <summary>
		/// 密钥生成时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ CreateTime;
		/// <summary>
		/// 密钥编号
		/// </summary>
		int KeyID;
		/// <summary>
		/// 动态密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CurrentKey;
		/// <summary>
		/// 动态密钥类型
		/// </summary>
		EnumCFMMCKeyKindType KeyKind;
	};

	/// <summary>
	/// 保证金监管系统经纪公司资金账户密钥
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcCFMMCTradingAccountKeyField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 经纪公司统一编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ ParticipantID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 密钥编号
		/// </summary>
		int KeyID;
		/// <summary>
		/// 动态密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CurrentKey;
	};

	/// <summary>
	/// 请求查询保证金监管系统经纪公司资金账户密钥
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryCFMMCTradingAccountKeyField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
	};

	/// <summary>
	/// 用户动态令牌参数
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBrokerUserOTPParamField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 动态令牌提供商
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]
		String^ OTPVendorsID;
		/// <summary>
		/// 动态令牌序列号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ SerialNumber;
		/// <summary>
		/// 令牌密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ AuthKey;
		/// <summary>
		/// 漂移值
		/// </summary>
		int LastDrift;
		/// <summary>
		/// 成功值
		/// </summary>
		int LastSuccess;
		/// <summary>
		/// 动态令牌类型
		/// </summary>
		EnumOTPTypeType OTPType;
	};

	/// <summary>
	/// 手工同步用户动态令牌
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcManualSyncBrokerUserOTPField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 动态令牌类型
		/// </summary>
		EnumOTPTypeType OTPType;
		/// <summary>
		/// 第一个动态密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ FirstOTP;
		/// <summary>
		/// 第二个动态密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ SecondOTP;
	};

	/// <summary>
	/// 转帐开户请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqOpenAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 性别
		/// </summary>
		EnumGenderType Gender;
		/// <summary>
		/// 国家代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CountryCode;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 邮编
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ZipCode;
		/// <summary>
		/// 电话号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 手机
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MobilePhone;
		/// <summary>
		/// 传真
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Fax;
		/// <summary>
		/// 电子邮件
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ EMail;
		/// <summary>
		/// 资金账户状态
		/// </summary>
		EnumMoneyAccountStatusType MoneyAccountStatus;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 汇钞标志
		/// </summary>
		EnumCashExchangeCodeType CashExchangeCode;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 转帐销户请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqCancelAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 性别
		/// </summary>
		EnumGenderType Gender;
		/// <summary>
		/// 国家代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CountryCode;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 邮编
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ZipCode;
		/// <summary>
		/// 电话号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 手机
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MobilePhone;
		/// <summary>
		/// 传真
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Fax;
		/// <summary>
		/// 电子邮件
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ EMail;
		/// <summary>
		/// 资金账户状态
		/// </summary>
		EnumMoneyAccountStatusType MoneyAccountStatus;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 汇钞标志
		/// </summary>
		EnumCashExchangeCodeType CashExchangeCode;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 变更银行账户请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqChangeAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 性别
		/// </summary>
		EnumGenderType Gender;
		/// <summary>
		/// 国家代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ CountryCode;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 地址
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 101)]
		String^ Address;
		/// <summary>
		/// 邮编
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ZipCode;
		/// <summary>
		/// 电话号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Telephone;
		/// <summary>
		/// 手机
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]
		String^ MobilePhone;
		/// <summary>
		/// 传真
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Fax;
		/// <summary>
		/// 电子邮件
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ EMail;
		/// <summary>
		/// 资金账户状态
		/// </summary>
		EnumMoneyAccountStatusType MoneyAccountStatus;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 新银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ NewBankAccount;
		/// <summary>
		/// 新银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ NewBankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
	};

	/// <summary>
	/// 转账请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqTransferField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 期货可取金额
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// 费用支付标志
		/// </summary>
		EnumFeePayFlagType FeePayFlag;
		/// <summary>
		/// 应收客户费用
		/// </summary>
		double CustFee;
		/// <summary>
		/// 应收期货公司费用
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// 发送方给接收方的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 转账交易状态
		/// </summary>
		EnumTransferStatusType TransferStatus;
	};

	/// <summary>
	/// 银行发起银行资金转期货响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspTransferField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 期货可取金额
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// 费用支付标志
		/// </summary>
		EnumFeePayFlagType FeePayFlag;
		/// <summary>
		/// 应收客户费用
		/// </summary>
		double CustFee;
		/// <summary>
		/// 应收期货公司费用
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// 发送方给接收方的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 转账交易状态
		/// </summary>
		EnumTransferStatusType TransferStatus;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 冲正请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqRepealField
	{
		/// <summary>
		/// 冲正时间间隔
		/// </summary>
		int RepealTimeInterval;
		/// <summary>
		/// 已经冲正次数
		/// </summary>
		int RepealedTimes;
		/// <summary>
		/// 银行冲正标志
		/// </summary>
		EnumBankRepealFlagType BankRepealFlag;
		/// <summary>
		/// 期商冲正标志
		/// </summary>
		EnumBrokerRepealFlagType BrokerRepealFlag;
		/// <summary>
		/// 被冲正平台流水号
		/// </summary>
		int PlateRepealSerial;
		/// <summary>
		/// 被冲正银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankRepealSerial;
		/// <summary>
		/// 被冲正期货流水号
		/// </summary>
		int FutureRepealSerial;
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 期货可取金额
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// 费用支付标志
		/// </summary>
		EnumFeePayFlagType FeePayFlag;
		/// <summary>
		/// 应收客户费用
		/// </summary>
		double CustFee;
		/// <summary>
		/// 应收期货公司费用
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// 发送方给接收方的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 转账交易状态
		/// </summary>
		EnumTransferStatusType TransferStatus;
	};

	/// <summary>
	/// 冲正响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspRepealField
	{
		/// <summary>
		/// 冲正时间间隔
		/// </summary>
		int RepealTimeInterval;
		/// <summary>
		/// 已经冲正次数
		/// </summary>
		int RepealedTimes;
		/// <summary>
		/// 银行冲正标志
		/// </summary>
		EnumBankRepealFlagType BankRepealFlag;
		/// <summary>
		/// 期商冲正标志
		/// </summary>
		EnumBrokerRepealFlagType BrokerRepealFlag;
		/// <summary>
		/// 被冲正平台流水号
		/// </summary>
		int PlateRepealSerial;
		/// <summary>
		/// 被冲正银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankRepealSerial;
		/// <summary>
		/// 被冲正期货流水号
		/// </summary>
		int FutureRepealSerial;
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 期货可取金额
		/// </summary>
		double FutureFetchAmount;
		/// <summary>
		/// 费用支付标志
		/// </summary>
		EnumFeePayFlagType FeePayFlag;
		/// <summary>
		/// 应收客户费用
		/// </summary>
		double CustFee;
		/// <summary>
		/// 应收期货公司费用
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// 发送方给接收方的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 转账交易状态
		/// </summary>
		EnumTransferStatusType TransferStatus;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询账户信息请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqQueryAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 查询账户信息响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspQueryAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 银行可用金额
		/// </summary>
		double BankUseAmount;
		/// <summary>
		/// 银行可取金额
		/// </summary>
		double BankFetchAmount;
	};

	/// <summary>
	/// 期商签到签退
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcFutureSignIOField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 期商签到响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspFutureSignInField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
		/// <summary>
		/// PIN密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ PinKey;
		/// <summary>
		/// MAC密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ MacKey;
	};

	/// <summary>
	/// 期商签退请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqFutureSignOutField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 期商签退响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspFutureSignOutField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询指定流水号的交易结果请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqQueryTradeResultBySerialField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 流水号
		/// </summary>
		int Reference;
		/// <summary>
		/// 本流水号发布者的机构类型
		/// </summary>
		EnumInstitutionTypeType RefrenceIssureType;
		/// <summary>
		/// 本流水号发布者机构编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ RefrenceIssure;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
	};

	/// <summary>
	/// 查询指定流水号的交易结果响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspQueryTradeResultBySerialField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
		/// <summary>
		/// 流水号
		/// </summary>
		int Reference;
		/// <summary>
		/// 本流水号发布者的机构类型
		/// </summary>
		EnumInstitutionTypeType RefrenceIssureType;
		/// <summary>
		/// 本流水号发布者机构编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ RefrenceIssure;
		/// <summary>
		/// 原始返回代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ OriginReturnCode;
		/// <summary>
		/// 原始返回码描述
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ OriginDescrInfoForReturnCode;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 转帐金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
	};

	/// <summary>
	/// 日终文件就绪请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqDayEndFileReadyField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 文件业务功能
		/// </summary>
		EnumFileBusinessCodeType FileBusinessCode;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
	};

	/// <summary>
	/// 返回结果
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReturnResultField
	{
		/// <summary>
		/// 返回代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ReturnCode;
		/// <summary>
		/// 返回码描述
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ DescrInfoForReturnCode;
	};

	/// <summary>
	/// 验证期货资金密码
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcVerifyFuturePasswordField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 验证客户信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcVerifyCustInfoField
	{
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
	};

	/// <summary>
	/// 验证期货资金密码和客户信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcVerifyFuturePasswordAndCustInfoField
	{
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
	};

	/// <summary>
	/// 验证期货资金密码和客户信息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcDepositResultInformField
	{
		/// <summary>
		/// 出入金流水号，该流水号为银期报盘返回的流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ DepositSeqNo;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 入金金额
		/// </summary>
		double Deposit;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 返回代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ ReturnCode;
		/// <summary>
		/// 返回码描述
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ DescrInfoForReturnCode;
	};

	/// <summary>
	/// 交易核心向银期报盘发出密钥同步请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqSyncKeyField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易核心给银期报盘的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
	};

	/// <summary>
	/// 交易核心向银期报盘发出密钥同步响应
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspSyncKeyField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易核心给银期报盘的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 查询账户信息通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcNotifyQueryAccountField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 客户姓名
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ CustomerName;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 客户类型
		/// </summary>
		EnumCustTypeType CustType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankPassWord;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 期货密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 验证客户证件号码标志
		/// </summary>
		EnumYesNoIndicatorType VerifyCertNoFlag;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货单位帐号类型
		/// </summary>
		EnumBankAccTypeType BankSecuAccType;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 期货单位帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankSecuAcc;
		/// <summary>
		/// 银行密码标志
		/// </summary>
		EnumPwdFlagType BankPwdFlag;
		/// <summary>
		/// 期货资金密码核对标志
		/// </summary>
		EnumPwdFlagType SecuPwdFlag;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 银行可用金额
		/// </summary>
		double BankUseAmount;
		/// <summary>
		/// 银行可取金额
		/// </summary>
		double BankFetchAmount;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 银期转账交易流水表
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcTransferSerialField
	{
		/// <summary>
		/// 平台流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 交易发起方日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 交易代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 银行帐号类型
		/// </summary>
		EnumBankAccTypeType BankAccType;
		/// <summary>
		/// 银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankAccount;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 期货公司编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 期货公司帐号类型
		/// </summary>
		EnumFutureAccTypeType FutureAccType;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 期货公司流水号
		/// </summary>
		int FutureSerial;
		/// <summary>
		/// 证件类型
		/// </summary>
		EnumIdCardTypeType IdCardType;
		/// <summary>
		/// 证件号码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 51)]
		String^ IdentifiedCardNo;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 交易金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 应收客户费用
		/// </summary>
		double CustFee;
		/// <summary>
		/// 应收期货公司费用
		/// </summary>
		double BrokerFee;
		/// <summary>
		/// 有效标志
		/// </summary>
		EnumAvailabilityFlagType AvailabilityFlag;
		/// <summary>
		/// 操作员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperatorCode;
		/// <summary>
		/// 新银行帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ BankNewAccount;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 请求查询转帐流水
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryTransferSerialField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
	};

	/// <summary>
	/// 期商签到通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcNotifyFutureSignInField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
		/// <summary>
		/// PIN密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ PinKey;
		/// <summary>
		/// MAC密钥
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ MacKey;
	};

	/// <summary>
	/// 期商签退通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcNotifyFutureSignOutField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 币种代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ CurrencyID;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 交易核心向银期报盘发出密钥同步处理结果的通知
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcNotifySyncKeyField
	{
		/// <summary>
		/// 业务功能码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]
		String^ TradeCode;
		/// <summary>
		/// 银行代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]
		String^ BankID;
		/// <summary>
		/// 银行分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]
		String^ BankBranchID;
		/// <summary>
		/// 期商代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 期商分支机构代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ BrokerBranchID;
		/// <summary>
		/// 交易日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeDate;
		/// <summary>
		/// 交易时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 银行流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ BankSerial;
		/// <summary>
		/// 交易系统日期
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 银期平台消息流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 最后分片标志
		/// </summary>
		EnumLastFragmentType LastFragment;
		/// <summary>
		/// 会话号
		/// </summary>
		int SessionID;
		/// <summary>
		/// 安装编号
		/// </summary>
		int InstallID;
		/// <summary>
		/// 用户标识
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易核心给银期报盘的消息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 129)]
		String^ Message;
		/// <summary>
		/// 渠道标志
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 3)]
		String^ DeviceID;
		/// <summary>
		/// 期货公司银行编码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]
		String^ BrokerIDByBank;
		/// <summary>
		/// 交易柜员
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 17)]
		String^ OperNo;
		/// <summary>
		/// 请求编号
		/// </summary>
		int RequestID;
		/// <summary>
		/// 交易ID
		/// </summary>
		int TID;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 客户最大持仓限制
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcMaxStockPositionLimitField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 股本类型
		/// </summary>
		EnumCapitalStockTypeType CapitalStockType;
		/// <summary>
		/// 最大持仓数量占股本的比例
		/// </summary>
		double Ratio;
	};

	/// <summary>
	/// 资金转入转出请求
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcReqFundIOCTPAccountField
	{
		/// <summary>
		/// 证券公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投资者资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 资金帐户密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// CTP核心流水号
		/// </summary>
		int CTPSerial;
		/// <summary>
		/// 转账平台流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 第三方流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ SettlementSerial;
		/// <summary>
		/// 交易金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 转账时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
	};

	/// <summary>
	/// 资金转入转出应答
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcRspFundIOCTPAccountField
	{
		/// <summary>
		/// 证券公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投资者资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 资金帐户密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// CTP核心流水号
		/// </summary>
		int CTPSerial;
		/// <summary>
		/// 转账平台流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 第三方流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ SettlementSerial;
		/// <summary>
		/// 交易金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 转账时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 出入金方向
		/// </summary>
		EnumFundDirectionType FundDirection;
	};

	/// <summary>
	/// 债券利息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcBondInterestField
	{
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		/// <summary>
		/// 利息
		/// </summary>
		double Interest;
	};

	/// <summary>
	/// 查询债券利息
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryBondInterestField
	{
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
	};

	/// <summary>
	/// 查询资金转入转出CTP
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcQryFundIOCTPAccountField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
	};

	/// <summary>
	/// 资金转入转出CTP
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcFundIOCTPAccountField
	{
		/// <summary>
		/// 证券公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 投资者资金帐号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ AccountID;
		/// <summary>
		/// 资金帐户密码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]
		String^ Password;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 会话编号
		/// </summary>
		int SessionID;
		/// <summary>
		/// CTP核心流水号
		/// </summary>
		int CTPSerial;
		/// <summary>
		/// 转账平台流水号
		/// </summary>
		int PlateSerial;
		/// <summary>
		/// 第三方流水号
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]
		String^ SettlementSerial;
		/// <summary>
		/// 交易金额
		/// </summary>
		double TradeAmount;
		/// <summary>
		/// 交易日
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradingDay;
		/// <summary>
		/// 转账时间
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ TradeTime;
		/// <summary>
		/// 摘要
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 36)]
		String^ Digest;
		/// <summary>
		/// 出入金方向
		/// </summary>
		EnumFundDirectionType FundDirection;
		/// <summary>
		/// 错误代码
		/// </summary>
		int ErrorID;
		/// <summary>
		/// 错误信息
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]
		String^ ErrorMsg;
	};

	/// <summary>
	/// 投资者新股申购额度
	/// </summary>
	[StructLayout(LayoutKind::Sequential)]
	public ref struct ThostFtdcInvestorSubscribingSharesQuotaField
	{
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]
		String^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 15)]
		String^ InvestorID;
		/// <summary>
		/// 用户代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]
		String^ UserID;
		/// <summary>
		/// 交易所代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]
		String^ ExchangeID;
		/// <summary>
		/// 合约代码
		/// </summary>
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]
		String^ InstrumentID;
		///最大允许申购数量
		int	MaxVolume;
	};
};
