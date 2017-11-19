/////////////////////////////////////////////////////////////////////////
/// CTP证券 C++ => .Net Framework Adapter
/// 初始版本修改自QuantBox,非常感谢
/// https://github.com/QuantBox/CTPZQ
/// Date: 20140906
/////////////////////////////////////////////////////////////////////////


#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;


namespace CTPZQ
{
	public enum struct EnumTeResumeType : Byte	//THOST_TE_RESUME_TYPE
	{
		THOST_TERT_RESTART = 0,
		THOST_TERT_RESUME,
		THOST_TERT_QUICK
	};

	/// <summary>
	/// TFtdcExchangePropertyType是一个交易所属性类型
	/// </summary>
	public enum struct EnumExchangePropertyType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// 根据成交生成报单
		/// </summary>
		GenOrderByTrade = (Byte)'1'
	};

	/// <summary>
	/// TFtdcIdCardTypeType是一个证件类型类型
	/// </summary>
	public enum struct EnumIdCardTypeType : Byte
	{
		/// <summary>
		/// 组织机构代码
		/// </summary>
		EID = (Byte)'0',

		/// <summary>
		/// 身份证
		/// </summary>
		IDCard = (Byte)'1',

		/// <summary>
		/// 军官证
		/// </summary>
		OfficerIDCard = (Byte)'2',

		/// <summary>
		/// 警官证
		/// </summary>
		PoliceIDCard = (Byte)'3',

		/// <summary>
		/// 士兵证
		/// </summary>
		SoldierIDCard = (Byte)'4',

		/// <summary>
		/// 户口簿
		/// </summary>
		HouseholdRegister = (Byte)'5',

		/// <summary>
		/// 护照
		/// </summary>
		Passport = (Byte)'6',

		/// <summary>
		/// 台胞证
		/// </summary>
		TaiwanCompatriotIDCard = (Byte)'7',

		/// <summary>
		/// 回乡证
		/// </summary>
		HomeComingCard = (Byte)'8',

		/// <summary>
		/// 营业执照号
		/// </summary>
		LicenseNo = (Byte)'9',

		/// <summary>
		/// 其他证件
		/// </summary>
		OtherCard = (Byte)'x'
	};

	/// <summary>
	/// TFtdcInvestorRangeType是一个投资者范围类型
	/// </summary>
	public enum struct EnumInvestorRangeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 投资者组
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// 单一投资者
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDepartmentRangeType是一个投资者范围类型
	/// </summary>
	public enum struct EnumDepartmentRangeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 组织架构
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// 单一投资者
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDataSyncStatusType是一个数据同步状态类型
	/// </summary>
	public enum struct EnumDataSyncStatusType : Byte
	{
		/// <summary>
		/// 未同步
		/// </summary>
		Asynchronous = (Byte)'1',

		/// <summary>
		/// 同步中
		/// </summary>
		Synchronizing = (Byte)'2',

		/// <summary>
		/// 已同步
		/// </summary>
		Synchronized = (Byte)'3'
	};

	/// <summary>
	/// TFtdcBrokerDataSyncStatusType是一个经纪公司数据同步状态类型
	/// </summary>
	public enum struct EnumBrokerDataSyncStatusType : Byte
	{
		/// <summary>
		/// 已同步
		/// </summary>
		Synchronized = (Byte)'1',

		/// <summary>
		/// 同步中
		/// </summary>
		Synchronizing = (Byte)'2'
	};

	/// <summary>
	/// TFtdcExchangeConnectStatusType是一个交易所连接状态类型
	/// </summary>
	public enum struct EnumExchangeConnectStatusType : Byte
	{
		/// <summary>
		/// 没有任何连接
		/// </summary>
		NoConnection = (Byte)'1',

		/// <summary>
		/// 已经发出合约查询请求
		/// </summary>
		QryInstrumentSent = (Byte)'2',

		/// <summary>
		/// 已经获取信息
		/// </summary>
		GotInformation = (Byte)'9'
	};

	/// <summary>
	/// TFtdcTraderConnectStatusType是一个交易所交易员连接状态类型
	/// </summary>
	public enum struct EnumTraderConnectStatusType : Byte
	{
		/// <summary>
		/// 没有任何连接
		/// </summary>
		NotConnected = (Byte)'1',

		/// <summary>
		/// 已经连接
		/// </summary>
		Connected = (Byte)'2',

		/// <summary>
		/// 已经发出合约查询请求
		/// </summary>
		QryInstrumentSent = (Byte)'3',

		/// <summary>
		/// 订阅私有流
		/// </summary>
		SubPrivateFlow = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFunctionCodeType是一个功能代码类型
	/// </summary>
	public enum struct EnumFunctionCodeType : Byte
	{
		/// <summary>
		/// 数据异步化
		/// </summary>
		DataAsync = (Byte)'1',

		/// <summary>
		/// 强制用户登出
		/// </summary>
		ForceUserLogout = (Byte)'2',

		/// <summary>
		/// 变更管理用户口令
		/// </summary>
		UserPasswordUpdate = (Byte)'3',

		/// <summary>
		/// 变更经纪公司口令
		/// </summary>
		BrokerPasswordUpdate = (Byte)'4',

		/// <summary>
		/// 变更投资者口令
		/// </summary>
		InvestorPasswordUpdate = (Byte)'5',

		/// <summary>
		/// 报单插入
		/// </summary>
		OrderInsert = (Byte)'6',

		/// <summary>
		/// 报单操作
		/// </summary>
		OrderAction = (Byte)'7',

		/// <summary>
		/// 同步系统数据
		/// </summary>
		SyncSystemData = (Byte)'8',

		/// <summary>
		/// 同步经纪公司数据
		/// </summary>
		SyncBrokerData = (Byte)'9',

		/// <summary>
		/// 批量同步经纪公司数据
		/// </summary>
		BachSyncBrokerData = (Byte)'A',

		/// <summary>
		/// 超级查询
		/// </summary>
		SuperQuery = (Byte)'B',

		/// <summary>
		/// 报单插入
		/// </summary>
		ParkedOrderInsert = (Byte)'C',

		/// <summary>
		/// 报单操作
		/// </summary>
		ParkedOrderAction = (Byte)'D',

		/// <summary>
		/// 同步动态令牌
		/// </summary>
		SyncOTP = (Byte)'E'
	};

	/// <summary>
	/// TFtdcBrokerFunctionCodeType是一个经纪公司功能代码类型
	/// </summary>
	public enum struct EnumBrokerFunctionCodeType : Byte
	{
		/// <summary>
		/// 强制用户登出
		/// </summary>
		ForceUserLogout = (Byte)'1',

		/// <summary>
		/// 变更用户口令
		/// </summary>
		UserPasswordUpdate = (Byte)'2',

		/// <summary>
		/// 同步经纪公司数据
		/// </summary>
		SyncBrokerData = (Byte)'3',

		/// <summary>
		/// 批量同步经纪公司数据
		/// </summary>
		BachSyncBrokerData = (Byte)'4',

		/// <summary>
		/// 报单插入
		/// </summary>
		OrderInsert = (Byte)'5',

		/// <summary>
		/// 报单操作
		/// </summary>
		OrderAction = (Byte)'6',

		/// <summary>
		/// 全部查询
		/// </summary>
		AllQuery = (Byte)'7',

		/// <summary>
		/// 系统功能：登入/登出/修改密码等
		/// </summary>
		log = (Byte)'a',

		/// <summary>
		/// 基本查询：查询基础数据，如合约，交易所等常量
		/// </summary>
		BaseQry = (Byte)'b',

		/// <summary>
		/// 交易查询：如查成交，委托
		/// </summary>
		TradeQry = (Byte)'c',

		/// <summary>
		/// 交易功能：报单，撤单
		/// </summary>
		Trade = (Byte)'d',

		/// <summary>
		/// 银期转账
		/// </summary>
		Virement = (Byte)'e',

		/// <summary>
		/// 风险监控
		/// </summary>
		Risk = (Byte)'f',

		/// <summary>
		/// 查询/管理：查询会话，踢人等
		/// </summary>
		Session = (Byte)'g',

		/// <summary>
		/// 风控通知控制
		/// </summary>
		RiskNoticeCtl = (Byte)'h',

		/// <summary>
		/// 风控通知发送
		/// </summary>
		RiskNotice = (Byte)'i',

		/// <summary>
		/// 察看经纪公司资金权限
		/// </summary>
		BrokerDeposit = (Byte)'j',

		/// <summary>
		/// 资金查询
		/// </summary>
		QueryFund = (Byte)'k',

		/// <summary>
		/// 报单查询
		/// </summary>
		QueryOrder = (Byte)'l',

		/// <summary>
		/// 成交查询
		/// </summary>
		QueryTrade = (Byte)'m',

		/// <summary>
		/// 持仓查询
		/// </summary>
		QueryPosition = (Byte)'n',

		/// <summary>
		/// 行情查询
		/// </summary>
		QueryMarketData = (Byte)'o',

		/// <summary>
		/// 用户事件查询
		/// </summary>
		QueryUserEvent = (Byte)'p',

		/// <summary>
		/// 风险通知查询
		/// </summary>
		QueryRiskNotify = (Byte)'q',

		/// <summary>
		/// 出入金查询
		/// </summary>
		QueryFundChange = (Byte)'r',

		/// <summary>
		/// 投资者信息查询
		/// </summary>
		QueryInvestor = (Byte)'s',

		/// <summary>
		/// 交易编码查询
		/// </summary>
		QueryTradingCode = (Byte)'t',

		/// <summary>
		/// 强平
		/// </summary>
		ForceClose = (Byte)'u',

		/// <summary>
		/// 压力测试
		/// </summary>
		PressTest = (Byte)'v',

		/// <summary>
		/// 权益反算
		/// </summary>
		RemainCalc = (Byte)'w',

		/// <summary>
		/// 净持仓保证金指标
		/// </summary>
		NetPositionInd = (Byte)'x',

		/// <summary>
		/// 风险预算
		/// </summary>
		RiskPredict = (Byte)'y',

		/// <summary>
		/// 数据导出
		/// </summary>
		DataExport = (Byte)'z',

		/// <summary>
		/// 风控指标设置
		/// </summary>
		RiskTargetSetup = (Byte)'A',

		/// <summary>
		/// 同步动态令牌
		/// </summary>
		SyncOTP = (Byte)'E'
	};

	/// <summary>
	/// TFtdcOrderActionStatusType是一个报单操作状态类型
	/// </summary>
	public enum struct EnumOrderActionStatusType : Byte
	{
		/// <summary>
		/// 已经提交
		/// </summary>
		Submitted = (Byte)'a',

		/// <summary>
		/// 已经接受
		/// </summary>
		Accepted = (Byte)'b',

		/// <summary>
		/// 已经被拒绝
		/// </summary>
		Rejected = (Byte)'c'
	};

	/// <summary>
	/// TFtdcOrderStatusType是一个报单状态类型
	/// </summary>
	public enum struct EnumOrderStatusType : Byte
	{
		/// <summary>
		/// 全部成交
		/// </summary>
		AllTraded = (Byte)'0',

		/// <summary>
		/// 部分成交还在队列中
		/// </summary>
		PartTradedQueueing = (Byte)'1',

		/// <summary>
		/// 部分成交不在队列中
		/// </summary>
		PartTradedNotQueueing = (Byte)'2',

		/// <summary>
		/// 未成交还在队列中
		/// </summary>
		NoTradeQueueing = (Byte)'3',

		/// <summary>
		/// 未成交不在队列中
		/// </summary>
		NoTradeNotQueueing = (Byte)'4',

		/// <summary>
		/// 撤单
		/// </summary>
		Canceled = (Byte)'5',

		/// <summary>
		/// 未知
		/// </summary>
		Unknown = (Byte)'a',

		/// <summary>
		/// 尚未触发
		/// </summary>
		NotTouched = (Byte)'b',

		/// <summary>
		/// 已触发
		/// </summary>
		Touched = (Byte)'c'
	};

	/// <summary>
	/// TFtdcOrderSubmitStatusType是一个报单提交状态类型
	/// </summary>
	public enum struct EnumOrderSubmitStatusType : Byte
	{
		/// <summary>
		/// 已经提交
		/// </summary>
		InsertSubmitted = (Byte)'0',

		/// <summary>
		/// 撤单已经提交
		/// </summary>
		CancelSubmitted = (Byte)'1',

		/// <summary>
		/// 修改已经提交
		/// </summary>
		ModifySubmitted = (Byte)'2',

		/// <summary>
		/// 已经接受
		/// </summary>
		Accepted = (Byte)'3',

		/// <summary>
		/// 报单已经被拒绝
		/// </summary>
		InsertRejected = (Byte)'4',

		/// <summary>
		/// 撤单已经被拒绝
		/// </summary>
		CancelRejected = (Byte)'5',

		/// <summary>
		/// 改单已经被拒绝
		/// </summary>
		ModifyRejected = (Byte)'6'
	};

	/// <summary>
	/// TFtdcPositionDateType是一个持仓日期类型
	/// </summary>
	public enum struct EnumPositionDateType : Byte
	{
		/// <summary>
		/// 今日持仓
		/// </summary>
		Today = (Byte)'1',

		/// <summary>
		/// 历史持仓
		/// </summary>
		History = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPositionDateTypeType是一个持仓日期类型类型
	/// </summary>
	public enum struct EnumPositionDateTypeType : Byte
	{
		/// <summary>
		/// 使用历史持仓
		/// </summary>
		UseHistory = (Byte)'1',

		/// <summary>
		/// 不使用历史持仓
		/// </summary>
		NoUseHistory = (Byte)'2'
	};

	/// <summary>
	/// TFtdcTradingRoleType是一个交易角色类型
	/// </summary>
	public enum struct EnumTradingRoleType : Byte
	{
		/// <summary>
		/// 代理
		/// </summary>
		Broker = (Byte)'1',

		/// <summary>
		/// 自营
		/// </summary>
		Host = (Byte)'2',

		/// <summary>
		/// 做市商
		/// </summary>
		Maker = (Byte)'3'
	};

	/// <summary>
	/// TFtdcProductClassType是一个产品类型类型
	/// </summary>
	public enum struct EnumProductClassType : Byte
	{
		/// <summary>
		/// 期货
		/// </summary>
		Futures = (Byte)'1',

		/// <summary>
		/// 期权
		/// </summary>
		Options = (Byte)'2',

		/// <summary>
		/// 组合
		/// </summary>
		Combination = (Byte)'3',

		/// <summary>
		/// 即期
		/// </summary>
		Spot = (Byte)'4',

		/// <summary>
		/// 期转现
		/// </summary>
		EFP = (Byte)'5',

		/// <summary>
		/// 证券A股
		/// </summary>
		StockA = (Byte)'6',

		/// <summary>
		/// 证券B股
		/// </summary>
		StockB = (Byte)'7',

		/// <summary>
		/// ETF
		/// </summary>
		ETF = (Byte)'8',

		/// <summary>
		/// ETF申赎
		/// </summary>
		ETFPurRed = (Byte)'9'
	};

	/// <summary>
	/// TFtdcInstLifePhaseType是一个合约生命周期状态类型
	/// </summary>
	public enum struct EnumInstLifePhaseType : Byte
	{
		/// <summary>
		/// 未上市
		/// </summary>
		NotStart = (Byte)'0',

		/// <summary>
		/// 上市
		/// </summary>
		Started = (Byte)'1',

		/// <summary>
		/// 停牌
		/// </summary>
		Pause = (Byte)'2',

		/// <summary>
		/// 到期
		/// </summary>
		Expired = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDirectionType是一个买卖方向类型
	/// </summary>
	public enum struct EnumDirectionType : Byte
	{
		/// <summary>
		/// 买
		/// </summary>
		Buy = (Byte)'0',

		/// <summary>
		/// 卖
		/// </summary>
		Sell = (Byte)'1',

		/// <summary>
		/// ETF申购
		/// </summary>
		ETFPur = (Byte)'2',

		/// <summary>
		/// ETF赎回
		/// </summary>
		ETFRed = (Byte)'3',

		/// <summary>
		/// 融资买入
		/// </summary>
		MarginTrade = (Byte)'4',

		/// <summary>
		/// 融券卖出
		/// </summary>
		ShortSell = (Byte)'5',

		/// <summary>
		/// 卖券还款
		/// </summary>
		RepayMargin = (Byte)'6',

		/// <summary>
		/// 买券还券
		/// </summary>
		RepayStock = (Byte)'7',

		/// <summary>
		/// 直接还款
		/// </summary>
		DirectRepayMargin = (Byte)'8',

		/// <summary>
		/// 直接还券
		/// </summary>
		DirectRepayStock = (Byte)'9',

		/// <summary>
		/// 担保品划转入信用账户
		/// </summary>
		TransferSecuritiesIn = (Byte)'a',

		/// <summary>
		/// 担保品划转出信用账户
		/// </summary>
		TransferSecuritiesOut = (Byte)'b',

		/// <summary>
		/// 现金替代，只用作回报
		/// </summary>
		CashIn = (Byte)'c',

		/// <summary>
		/// 债券质押入库,深圳无质押代码,以此区分是质押入库
		/// </summary>
		PledgeBondIn = (Byte)'d',

		/// <summary>
		/// 债券质押出库,深圳无质押代码,以此区分是质押入库
		/// </summary>
		PledgeBondOut = (Byte)'e',

		/// <summary>
		/// 配股
		/// </summary>
		Rationed = (Byte)'f'
	};

	/// <summary>
	/// TFtdcPositionTypeType是一个持仓类型类型
	/// </summary>
	public enum struct EnumPositionTypeType : Byte
	{
		/// <summary>
		/// 净持仓
		/// </summary>
		Net = (Byte)'1',

		/// <summary>
		/// 综合持仓
		/// </summary>
		Gross = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPosiDirectionType是一个持仓多空方向类型
	/// </summary>
	public enum struct EnumPosiDirectionType : Byte
	{
		/// <summary>
		/// 净
		/// </summary>
		Net = (Byte)'1',

		/// <summary>
		/// 多头
		/// </summary>
		Long = (Byte)'2',

		/// <summary>
		/// 空头
		/// </summary>
		Short = (Byte)'3',

		/// <summary>
		/// 融资
		/// </summary>
		MarginTrade = (Byte)'4',

		/// <summary>
		/// 融券
		/// </summary>
		ShortSell = (Byte)'5'
	};

	/// <summary>
	/// TFtdcSysSettlementStatusType是一个系统结算状态类型
	/// </summary>
	public enum struct EnumSysSettlementStatusType : Byte
	{
		/// <summary>
		/// 不活跃
		/// </summary>
		NonActive = (Byte)'1',

		/// <summary>
		/// 启动
		/// </summary>
		Startup = (Byte)'2',

		/// <summary>
		/// 操作
		/// </summary>
		Operating = (Byte)'3',

		/// <summary>
		/// 结算
		/// </summary>
		Settlement = (Byte)'4',

		/// <summary>
		/// 结算完成
		/// </summary>
		SettlementFinished = (Byte)'5'
	};

	/// <summary>
	/// TFtdcRatioAttrType是一个费率属性类型
	/// </summary>
	public enum struct EnumRatioAttrType : Byte
	{
		/// <summary>
		/// 交易费率
		/// </summary>
		Trade = (Byte)'0',

		/// <summary>
		/// 结算费率
		/// </summary>
		Settlement = (Byte)'1'
	};

	/// <summary>
	/// TFtdcHedgeFlagType是一个投机套保标志类型
	/// </summary>
	public enum struct EnumHedgeFlagType : Byte
	{
		/// <summary>
		/// 投机
		/// </summary>
		Speculation = (Byte)'1',

		/// <summary>
		/// 套保
		/// </summary>
		Hedge = (Byte)'3'
	};

	/// <summary>
	/// TFtdcOrderPriceTypeType是一个报单价格条件类型
	/// </summary>
	public enum struct EnumOrderPriceTypeType : Byte
	{
		/// <summary>
		/// 任意价
		/// </summary>
		AnyPrice = (Byte)'1',

		/// <summary>
		/// 限价
		/// </summary>
		LimitPrice = (Byte)'2',

		/// <summary>
		/// 最优价
		/// </summary>
		BestPrice = (Byte)'3',

		/// <summary>
		/// 最新价
		/// </summary>
		LastPrice = (Byte)'4',

		/// <summary>
		/// 最新价浮动上浮1个ticks
		/// </summary>
		LastPricePlusOneTicks = (Byte)'5',

		/// <summary>
		/// 最新价浮动上浮2个ticks
		/// </summary>
		LastPricePlusTwoTicks = (Byte)'6',

		/// <summary>
		/// 最新价浮动上浮3个ticks
		/// </summary>
		LastPricePlusThreeTicks = (Byte)'7',

		/// <summary>
		/// 卖一价
		/// </summary>
		AskPrice1 = (Byte)'8',

		/// <summary>
		/// 卖一价浮动上浮1个ticks
		/// </summary>
		AskPrice1PlusOneTicks = (Byte)'9',

		/// <summary>
		/// 卖一价浮动上浮2个ticks
		/// </summary>
		AskPrice1PlusTwoTicks = (Byte)'A',

		/// <summary>
		/// 卖一价浮动上浮3个ticks
		/// </summary>
		AskPrice1PlusThreeTicks = (Byte)'B',

		/// <summary>
		/// 买一价
		/// </summary>
		BidPrice1 = (Byte)'C',

		/// <summary>
		/// 买一价浮动上浮1个ticks
		/// </summary>
		BidPrice1PlusOneTicks = (Byte)'D',

		/// <summary>
		/// 买一价浮动上浮2个ticks
		/// </summary>
		BidPrice1PlusTwoTicks = (Byte)'E',

		/// <summary>
		/// 买一价浮动上浮3个ticks
		/// </summary>
		BidPrice1PlusThreeTicks = (Byte)'F',

		/// <summary>
		/// 激活A股网络密码服务代码
		/// </summary>
		ActiveANetPassSvrCode = (Byte)'G',

		/// <summary>
		/// 注销A股网络密码服务代码
		/// </summary>
		InactiveANetPassSvrCode = (Byte)'H',

		/// <summary>
		/// 激活B股网络密码服务代码
		/// </summary>
		ActiveBNetPassSvrCode = (Byte)'I',

		/// <summary>
		/// 注销B股网络密码服务代码
		/// </summary>
		InactiveBNetPassSvrCode = (Byte)'J',

		/// <summary>
		/// 回购注销
		/// </summary>
		Repurchase = (Byte)'K',

		/// <summary>
		/// 指定撤销
		/// </summary>
		DesignatedCancel = (Byte)'L',

		/// <summary>
		/// 指定登记
		/// </summary>
		Designated = (Byte)'M',

		/// <summary>
		/// 证券参与申购
		/// </summary>
		SubscribingShares = (Byte)'N',

		/// <summary>
		/// 证券参与配股
		/// </summary>
		Split = (Byte)'O',

		/// <summary>
		/// 要约收购登记
		/// </summary>
		TenderOffer = (Byte)'P',

		/// <summary>
		/// 要约收购撤销
		/// </summary>
		TenderOfferCancel = (Byte)'Q',

		/// <summary>
		/// 证券投票
		/// </summary>
		Ballot = (Byte)'R',

		/// <summary>
		/// 可转债转换登记
		/// </summary>
		ConvertibleBondsConvet = (Byte)'S',

		/// <summary>
		/// 可转债回售登记
		/// </summary>
		ConvertibleBondsRepurchase = (Byte)'T',

		/// <summary>
		/// 权证行权
		/// </summary>
		Exercise = (Byte)'U',

		/// <summary>
		/// 开放式基金申购
		/// </summary>
		PurchasingFunds = (Byte)'V',

		/// <summary>
		/// 开放式基金赎回
		/// </summary>
		RedemingFunds = (Byte)'W',

		/// <summary>
		/// 开放式基金认购
		/// </summary>
		SubscribingFunds = (Byte)'X',

		/// <summary>
		/// 开放式基金转托管转出
		/// </summary>
		LOFIssue = (Byte)'Y',

		/// <summary>
		/// 开放式基金设置分红方式
		/// </summary>
		LOFSetBonusType = (Byte)'Z',

		/// <summary>
		/// 开放式基金转换为其他基金
		/// </summary>
		LOFConvert = (Byte)'a',

		/// <summary>
		/// 债券入库
		/// </summary>
		DebentureStockIn = (Byte)'b',

		/// <summary>
		/// 债券出库
		/// </summary>
		DebentureStockOut = (Byte)'c',

		/// <summary>
		/// ETF申购
		/// </summary>
		PurchasesETF = (Byte)'d',

		/// <summary>
		/// ETF赎回
		/// </summary>
		RedeemETF = (Byte)'e',

		/// <summary>
		/// 证券公司融券专用账户过户到证券公司信用交易担保证券账户
		/// </summary>
		ShortAccToCreditAcc = (Byte)'f',

		/// <summary>
		/// 证券公司信用交易担保证券账户过户到证券公司融券专用账户
		/// </summary>
		CreditAccToShortAcc = (Byte)'g',

		/// <summary>
		/// 投资者普通证券账户过户到证券公司信用交易担保证券账户
		/// </summary>
		InvAccToCreditAcc = (Byte)'h',

		/// <summary>
		/// 证券公司融券专用账户过户到证券公司自营账户
		/// </summary>
		ShortAccToHostAcc = (Byte)'i'
	};

	/// <summary>
	/// TFtdcOffsetFlagType是一个开平标志类型
	/// </summary>
	public enum struct EnumOffsetFlagType : Byte
	{
		/// <summary>
		/// 开仓
		/// </summary>
		Open = (Byte)'0',

		/// <summary>
		/// 平仓
		/// </summary>
		Close = (Byte)'1',

		/// <summary>
		/// 强平
		/// </summary>
		ForceClose = (Byte)'2',

		/// <summary>
		/// 平今
		/// </summary>
		CloseToday = (Byte)'3',

		/// <summary>
		/// 平昨
		/// </summary>
		CloseYesterday = (Byte)'4',

		/// <summary>
		/// 强减
		/// </summary>
		ForceOff = (Byte)'5',

		/// <summary>
		/// 本地强平
		/// </summary>
		LocalForceClose = (Byte)'6'
	};

	/// <summary>
	/// TFtdcForceCloseReasonType是一个强平原因类型
	/// </summary>
	public enum struct EnumForceCloseReasonType : Byte
	{
		/// <summary>
		/// 非强平
		/// </summary>
		NotForceClose = (Byte)'0',

		/// <summary>
		/// 资金不足
		/// </summary>
		LackDeposit = (Byte)'1',

		/// <summary>
		/// 客户超仓
		/// </summary>
		ClientOverPositionLimit = (Byte)'2',

		/// <summary>
		/// 会员超仓
		/// </summary>
		MemberOverPositionLimit = (Byte)'3',

		/// <summary>
		/// 持仓非整数倍
		/// </summary>
		NotMultiple = (Byte)'4',

		/// <summary>
		/// 违规
		/// </summary>
		Violation = (Byte)'5',

		/// <summary>
		/// 其它
		/// </summary>
		Other = (Byte)'6'
	};

	/// <summary>
	/// TFtdcOrderTypeType是一个报单类型类型
	/// </summary>
	public enum struct EnumOrderTypeType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// 报价衍生
		/// </summary>
		DeriveFromQuote = (Byte)'1',

		/// <summary>
		/// 组合衍生
		/// </summary>
		DeriveFromCombination = (Byte)'2',

		/// <summary>
		/// 组合报单
		/// </summary>
		Combination = (Byte)'3',

		/// <summary>
		/// 条件单
		/// </summary>
		ConditionalOrder = (Byte)'4',

		/// <summary>
		/// 互换单
		/// </summary>
		Swap = (Byte)'5'
	};

	/// <summary>
	/// TFtdcTimeConditionType是一个有效期类型类型
	/// </summary>
	public enum struct EnumTimeConditionType : Byte
	{
		/// <summary>
		/// 立即完成，否则撤销
		/// </summary>
		IOC = (Byte)'1',

		/// <summary>
		/// 本节有效
		/// </summary>
		GFS = (Byte)'2',

		/// <summary>
		/// 当日有效
		/// </summary>
		GFD = (Byte)'3',

		/// <summary>
		/// 指定日期前有效
		/// </summary>
		GTD = (Byte)'4',

		/// <summary>
		/// 撤销前有效
		/// </summary>
		GTC = (Byte)'5',

		/// <summary>
		/// 集合竞价有效
		/// </summary>
		GFA = (Byte)'6'
	};

	/// <summary>
	/// TFtdcVolumeConditionType是一个成交量类型类型
	/// </summary>
	public enum struct EnumVolumeConditionType : Byte
	{
		/// <summary>
		/// 任何数量
		/// </summary>
		AV = (Byte)'1',

		/// <summary>
		/// 最小数量
		/// </summary>
		MV = (Byte)'2',

		/// <summary>
		/// 全部数量
		/// </summary>
		CV = (Byte)'3'
	};

	/// <summary>
	/// TFtdcContingentConditionType是一个触发条件类型
	/// </summary>
	public enum struct EnumContingentConditionType : Byte
	{
		/// <summary>
		/// 立即
		/// </summary>
		Immediately = (Byte)'1',

		/// <summary>
		/// 止损
		/// </summary>
		Touch = (Byte)'2',

		/// <summary>
		/// 止赢
		/// </summary>
		TouchProfit = (Byte)'3',

		/// <summary>
		/// 预埋单
		/// </summary>
		ParkedOrder = (Byte)'4',

		/// <summary>
		/// 最新价大于条件价
		/// </summary>
		LastPriceGreaterThanStopPrice = (Byte)'5',

		/// <summary>
		/// 最新价大于等于条件价
		/// </summary>
		LastPriceGreaterEqualStopPrice = (Byte)'6',

		/// <summary>
		/// 最新价小于条件价
		/// </summary>
		LastPriceLesserThanStopPrice = (Byte)'7',

		/// <summary>
		/// 最新价小于等于条件价
		/// </summary>
		LastPriceLesserEqualStopPrice = (Byte)'8',

		/// <summary>
		/// 卖一价大于条件价
		/// </summary>
		AskPriceGreaterThanStopPrice = (Byte)'9',

		/// <summary>
		/// 卖一价大于等于条件价
		/// </summary>
		AskPriceGreaterEqualStopPrice = (Byte)'A',

		/// <summary>
		/// 卖一价小于条件价
		/// </summary>
		AskPriceLesserThanStopPrice = (Byte)'B',

		/// <summary>
		/// 卖一价小于等于条件价
		/// </summary>
		AskPriceLesserEqualStopPrice = (Byte)'C',

		/// <summary>
		/// 买一价大于条件价
		/// </summary>
		BidPriceGreaterThanStopPrice = (Byte)'D',

		/// <summary>
		/// 买一价大于等于条件价
		/// </summary>
		BidPriceGreaterEqualStopPrice = (Byte)'E',

		/// <summary>
		/// 买一价小于条件价
		/// </summary>
		BidPriceLesserThanStopPrice = (Byte)'F',

		/// <summary>
		/// 买一价小于等于条件价
		/// </summary>
		BidPriceLesserEqualStopPrice = (Byte)'H'
	};

	/// <summary>
	/// TFtdcActionFlagType是一个操作标志类型
	/// </summary>
	public enum struct EnumActionFlagType : Byte
	{
		/// <summary>
		/// 删除
		/// </summary>
		Delete = (Byte)'0',

		/// <summary>
		/// 修改
		/// </summary>
		Modify = (Byte)'3'
	};

	/// <summary>
	/// TFtdcTradingRightType是一个交易权限类型
	/// </summary>
	public enum struct EnumTradingRightType : Byte
	{
		/// <summary>
		/// 可以交易
		/// </summary>
		Allow = (Byte)'0',

		/// <summary>
		/// 不能交易
		/// </summary>
		Forbidden = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrderSourceType是一个报单来源类型
	/// </summary>
	public enum struct EnumOrderSourceType : Byte
	{
		/// <summary>
		/// 来自参与者
		/// </summary>
		Participant = (Byte)'0',

		/// <summary>
		/// 来自管理员
		/// </summary>
		Administrator = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTradeTypeType是一个成交类型类型
	/// </summary>
	public enum struct EnumTradeTypeType : Byte
	{
		/// <summary>
		/// 普通成交
		/// </summary>
		Common = (Byte)'0',

		/// <summary>
		/// 期权执行
		/// </summary>
		OptionsExecution = (Byte)'1',

		/// <summary>
		/// OTC成交
		/// </summary>
		OTC = (Byte)'2',

		/// <summary>
		/// 期转现衍生成交
		/// </summary>
		EFPDerived = (Byte)'3',

		/// <summary>
		/// 组合衍生成交
		/// </summary>
		CombinationDerived = (Byte)'4',

		/// <summary>
		/// ETF申购
		/// </summary>
		EFTPurchase = (Byte)'5',

		/// <summary>
		/// ETF赎回
		/// </summary>
		EFTRedem = (Byte)'6'
	};

	/// <summary>
	/// TFtdcPriceSourceType是一个成交价来源类型
	/// </summary>
	public enum struct EnumPriceSourceType : Byte
	{
		/// <summary>
		/// 前成交价
		/// </summary>
		LastPrice = (Byte)'0',

		/// <summary>
		/// 买委托价
		/// </summary>
		Buy = (Byte)'1',

		/// <summary>
		/// 卖委托价
		/// </summary>
		Sell = (Byte)'2'
	};

	/// <summary>
	/// TFtdcInstrumentStatusType是一个合约交易状态类型
	/// </summary>
	public enum struct EnumInstrumentStatusType : Byte
	{
		/// <summary>
		/// 开盘前
		/// </summary>
		BeforeTrading = (Byte)'0',

		/// <summary>
		/// 非交易
		/// </summary>
		NoTrading = (Byte)'1',

		/// <summary>
		/// 连续交易
		/// </summary>
		Continous = (Byte)'2',

		/// <summary>
		/// 集合竞价报单
		/// </summary>
		AuctionOrdering = (Byte)'3',

		/// <summary>
		/// 集合竞价价格平衡
		/// </summary>
		AuctionBalance = (Byte)'4',

		/// <summary>
		/// 集合竞价撮合
		/// </summary>
		AuctionMatch = (Byte)'5',

		/// <summary>
		/// 收盘
		/// </summary>
		Closed = (Byte)'6'
	};

	/// <summary>
	/// TFtdcInstStatusEnterReasonType是一个品种进入交易状态原因类型
	/// </summary>
	public enum struct EnumInstStatusEnterReasonType : Byte
	{
		/// <summary>
		/// 自动切换
		/// </summary>
		Automatic = (Byte)'1',

		/// <summary>
		/// 手动切换
		/// </summary>
		Manual = (Byte)'2',

		/// <summary>
		/// 熔断
		/// </summary>
		Fuse = (Byte)'3'
	};

	/// <summary>
	/// TFtdcBatchStatusType是一个处理状态类型
	/// </summary>
	public enum struct EnumBatchStatusType : Byte
	{
		/// <summary>
		/// 未上传
		/// </summary>
		NoUpload = (Byte)'1',

		/// <summary>
		/// 已上传
		/// </summary>
		Uploaded = (Byte)'2',

		/// <summary>
		/// 审核失败
		/// </summary>
		Failed = (Byte)'3'
	};

	/// <summary>
	/// TFtdcReturnStyleType是一个按品种返还方式类型
	/// </summary>
	public enum struct EnumReturnStyleType : Byte
	{
		/// <summary>
		/// 按所有品种
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 按品种
		/// </summary>
		ByProduct = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReturnPatternType是一个返还模式类型
	/// </summary>
	public enum struct EnumReturnPatternType : Byte
	{
		/// <summary>
		/// 按成交手数
		/// </summary>
		ByVolume = (Byte)'1',

		/// <summary>
		/// 按留存手续费
		/// </summary>
		ByFeeOnHand = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReturnLevelType是一个返还级别类型
	/// </summary>
	public enum struct EnumReturnLevelType : Byte
	{
		/// <summary>
		/// 级别1
		/// </summary>
		Level1 = (Byte)'1',

		/// <summary>
		/// 级别2
		/// </summary>
		Level2 = (Byte)'2',

		/// <summary>
		/// 级别3
		/// </summary>
		Level3 = (Byte)'3',

		/// <summary>
		/// 级别4
		/// </summary>
		Level4 = (Byte)'4',

		/// <summary>
		/// 级别5
		/// </summary>
		Level5 = (Byte)'5',

		/// <summary>
		/// 级别6
		/// </summary>
		Level6 = (Byte)'6',

		/// <summary>
		/// 级别7
		/// </summary>
		Level7 = (Byte)'7',

		/// <summary>
		/// 级别8
		/// </summary>
		Level8 = (Byte)'8',

		/// <summary>
		/// 级别9
		/// </summary>
		Level9 = (Byte)'9'
	};

	/// <summary>
	/// TFtdcReturnStandardType是一个返还标准类型
	/// </summary>
	public enum struct EnumReturnStandardType : Byte
	{
		/// <summary>
		/// 分阶段返还
		/// </summary>
		ByPeriod = (Byte)'1',

		/// <summary>
		/// 按某一标准
		/// </summary>
		ByStandard = (Byte)'2'
	};

	/// <summary>
	/// TFtdcMortgageTypeType是一个质押类型类型
	/// </summary>
	public enum struct EnumMortgageTypeType : Byte
	{
		/// <summary>
		/// 质出
		/// </summary>
		Out = (Byte)'0',

		/// <summary>
		/// 质入
		/// </summary>
		In = (Byte)'1'
	};

	/// <summary>
	/// TFtdcInvestorSettlementParamIDType是一个投资者结算参数代码类型
	/// </summary>
	public enum struct EnumInvestorSettlementParamIDType : Byte
	{
		/// <summary>
		/// 基础保证金
		/// </summary>
		BaseMargin = (Byte)'1',

		/// <summary>
		/// 最低权益标准
		/// </summary>
		LowestInterest = (Byte)'2',

		/// <summary>
		/// 质押比例
		/// </summary>
		MortgageRatio = (Byte)'4',

		/// <summary>
		/// 保证金算法
		/// </summary>
		MarginWay = (Byte)'5',

		/// <summary>
		/// 结算单(盯市)权益等于结存
		/// </summary>
		BillDeposit = (Byte)'9'
	};

	/// <summary>
	/// TFtdcExchangeSettlementParamIDType是一个交易所结算参数代码类型
	/// </summary>
	public enum struct EnumExchangeSettlementParamIDType : Byte
	{
		/// <summary>
		/// 质押比例
		/// </summary>
		MortgageRatio = (Byte)'1',

		/// <summary>
		/// 分项资金导入项
		/// </summary>
		OtherFundItem = (Byte)'2',

		/// <summary>
		/// 分项资金入交易所出入金
		/// </summary>
		OtherFundImport = (Byte)'3',

		/// <summary>
		/// 上期所交割手续费收取方式
		/// </summary>
		SHFEDelivFee = (Byte)'4',

		/// <summary>
		/// 大商所交割手续费收取方式
		/// </summary>
		DCEDelivFee = (Byte)'5',

		/// <summary>
		/// 中金所开户最低可用金额
		/// </summary>
		CFFEXMinPrepa = (Byte)'6'
	};

	/// <summary>
	/// TFtdcSystemParamIDType是一个系统参数代码类型
	/// </summary>
	public enum struct EnumSystemParamIDType : Byte
	{
		/// <summary>
		/// 投资者代码最小长度
		/// </summary>
		InvestorIDMinLength = (Byte)'1',

		/// <summary>
		/// 投资者帐号代码最小长度
		/// </summary>
		AccountIDMinLength = (Byte)'2',

		/// <summary>
		/// 投资者开户默认登录权限
		/// </summary>
		UserRightLogon = (Byte)'3',

		/// <summary>
		/// 投资者交易结算单成交汇总方式
		/// </summary>
		SettlementBillTrade = (Byte)'4',

		/// <summary>
		/// 统一开户更新交易编码方式
		/// </summary>
		TradingCode = (Byte)'5',

		/// <summary>
		/// 结算是否判断存在未复核的出入金和分项资金
		/// </summary>
		CheckFund = (Byte)'6',

		/// <summary>
		/// 上传的结算文件标识
		/// </summary>
		UploadSettlementFile = (Byte)'U',

		/// <summary>
		/// 下载的保证金存管文件
		/// </summary>
		DownloadCSRCFile = (Byte)'D',

		/// <summary>
		/// 结算单文件标识
		/// </summary>
		SettlementBillFile = (Byte)'S',

		/// <summary>
		/// 证监会文件标识
		/// </summary>
		CSRCOthersFile = (Byte)'C',

		/// <summary>
		/// 投资者照片路径
		/// </summary>
		InvestorPhoto = (Byte)'P'
	};

	/// <summary>
	/// TFtdcTradeParamIDType是一个交易系统参数代码类型
	/// </summary>
	public enum struct EnumTradeParamIDType : Byte
	{
		/// <summary>
		/// 系统加密算法
		/// </summary>
		EncryptionStandard = (Byte)'E',

		/// <summary>
		/// 系统风险算法
		/// </summary>
		RiskMode = (Byte)'R',

		/// <summary>
		/// 系统风险算法是否全局 0-否 1-是
		/// </summary>
		RiskModeGlobal = (Byte)'G',

		/// <summary>
		/// 融资融券买券还券算法
		/// </summary>
		RepayShortSellAlgo = (Byte)'S'
	};

	/// <summary>
	/// TFtdcFileIDType是一个文件标识类型
	/// </summary>
	public enum struct EnumFileIDType : Byte
	{
		/// <summary>
		/// 资金数据
		/// </summary>
		SettlementFund = (Byte)'F',

		/// <summary>
		/// 成交数据
		/// </summary>
		Trade = (Byte)'T',

		/// <summary>
		/// 投资者持仓数据
		/// </summary>
		InvestorPosition = (Byte)'P',

		/// <summary>
		/// 投资者分项资金数据
		/// </summary>
		SubEntryFund = (Byte)'O'
	};

	/// <summary>
	/// TFtdcFileTypeType是一个文件上传类型类型
	/// </summary>
	public enum struct EnumFileTypeType : Byte
	{
		/// <summary>
		/// 结算
		/// </summary>
		Settlement = (Byte)'0',

		/// <summary>
		/// 核对
		/// </summary>
		Check = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFileFormatType是一个文件格式类型
	/// </summary>
	public enum struct EnumFileFormatType : Byte
	{
		/// <summary>
		/// 文本文件(.txt)
		/// </summary>
		Txt = (Byte)'0',

		/// <summary>
		/// 压缩文件(.zip)
		/// </summary>
		Zip = (Byte)'1',

		/// <summary>
		/// DBF文件(.dbf)
		/// </summary>
		DBF = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFileUploadStatusType是一个文件状态类型
	/// </summary>
	public enum struct EnumFileUploadStatusType : Byte
	{
		/// <summary>
		/// 上传成功
		/// </summary>
		SucceedUpload = (Byte)'1',

		/// <summary>
		/// 上传失败
		/// </summary>
		FailedUpload = (Byte)'2',

		/// <summary>
		/// 导入成功
		/// </summary>
		SucceedLoad = (Byte)'3',

		/// <summary>
		/// 导入部分成功
		/// </summary>
		PartSucceedLoad = (Byte)'4',

		/// <summary>
		/// 导入失败
		/// </summary>
		FailedLoad = (Byte)'5'
	};

	/// <summary>
	/// TFtdcTransferDirectionType是一个移仓方向类型
	/// </summary>
	public enum struct EnumTransferDirectionType : Byte
	{
		/// <summary>
		/// 移出
		/// </summary>
		Out = (Byte)'0',

		/// <summary>
		/// 移入
		/// </summary>
		In = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankFlagType是一个银行统一标识类型类型
	/// </summary>
	public enum struct EnumBankFlagType : Byte
	{
		/// <summary>
		/// 工商银行
		/// </summary>
		ICBC = (Byte)'1',

		/// <summary>
		/// 农业银行
		/// </summary>
		ABC = (Byte)'2',

		/// <summary>
		/// 中国银行
		/// </summary>
		BC = (Byte)'3',

		/// <summary>
		/// 建设银行
		/// </summary>
		CBC = (Byte)'4',

		/// <summary>
		/// 交通银行
		/// </summary>
		BOC = (Byte)'5',

		/// <summary>
		/// 其他银行
		/// </summary>
		Other = (Byte)'Z'
	};

	/// <summary>
	/// TFtdcSpecialCreateRuleType是一个特殊的创建规则类型
	/// </summary>
	public enum struct EnumSpecialCreateRuleType : Byte
	{
		/// <summary>
		/// 没有特殊创建规则
		/// </summary>
		NoSpecialRule = (Byte)'0',

		/// <summary>
		/// 不包含春节
		/// </summary>
		NoSpringFestival = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBasisPriceTypeType是一个挂牌基准价类型类型
	/// </summary>
	public enum struct EnumBasisPriceTypeType : Byte
	{
		/// <summary>
		/// 上一合约结算价
		/// </summary>
		LastSettlement = (Byte)'1',

		/// <summary>
		/// 上一合约收盘价
		/// </summary>
		LaseClose = (Byte)'2'
	};

	/// <summary>
	/// TFtdcProductLifePhaseType是一个产品生命周期状态类型
	/// </summary>
	public enum struct EnumProductLifePhaseType : Byte
	{
		/// <summary>
		/// 活跃
		/// </summary>
		Active = (Byte)'1',

		/// <summary>
		/// 不活跃
		/// </summary>
		NonActive = (Byte)'2',

		/// <summary>
		/// 注销
		/// </summary>
		Canceled = (Byte)'3'
	};

	/// <summary>
	/// TFtdcDeliveryModeType是一个交割方式类型
	/// </summary>
	public enum struct EnumDeliveryModeType : Byte
	{
		/// <summary>
		/// 现金交割
		/// </summary>
		CashDeliv = (Byte)'1',

		/// <summary>
		/// 实物交割
		/// </summary>
		CommodityDeliv = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundIOTypeType是一个出入金类型类型
	/// </summary>
	public enum struct EnumFundIOTypeType : Byte
	{
		/// <summary>
		/// 出入金
		/// </summary>
		FundIO = (Byte)'1',

		/// <summary>
		/// 银期转帐
		/// </summary>
		Transfer = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundTypeType是一个资金类型类型
	/// </summary>
	public enum struct EnumFundTypeType : Byte
	{
		/// <summary>
		/// 银行存款
		/// </summary>
		Deposite = (Byte)'1',

		/// <summary>
		/// 分项资金
		/// </summary>
		ItemFund = (Byte)'2',

		/// <summary>
		/// 公司调整
		/// </summary>
		Company = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFundDirectionType是一个出入金方向类型
	/// </summary>
	public enum struct EnumFundDirectionType : Byte
	{
		/// <summary>
		/// 入金
		/// </summary>
		In = (Byte)'1',

		/// <summary>
		/// 出金
		/// </summary>
		Out = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundStatusType是一个资金状态类型
	/// </summary>
	public enum struct EnumFundStatusType : Byte
	{
		/// <summary>
		/// 已录入
		/// </summary>
		Record = (Byte)'1',

		/// <summary>
		/// 已复核
		/// </summary>
		Check = (Byte)'2',

		/// <summary>
		/// 已冲销
		/// </summary>
		Charge = (Byte)'3'
	};

	/// <summary>
	/// TFtdcPublishStatusType是一个发布状态类型
	/// </summary>
	public enum struct EnumPublishStatusType : Byte
	{
		/// <summary>
		/// 未发布
		/// </summary>
		None = (Byte)'1',

		/// <summary>
		/// 正在发布
		/// </summary>
		Publishing = (Byte)'2',

		/// <summary>
		/// 已发布
		/// </summary>
		Published = (Byte)'3'
	};

	/// <summary>
	/// TFtdcSystemStatusType是一个系统状态类型
	/// </summary>
	public enum struct EnumSystemStatusType : Byte
	{
		/// <summary>
		/// 不活跃
		/// </summary>
		NonActive = (Byte)'1',

		/// <summary>
		/// 启动
		/// </summary>
		Startup = (Byte)'2',

		/// <summary>
		/// 交易开始初始化
		/// </summary>
		Initialize = (Byte)'3',

		/// <summary>
		/// 交易完成初始化
		/// </summary>
		Initialized = (Byte)'4',

		/// <summary>
		/// 收市开始
		/// </summary>
		Close = (Byte)'5',

		/// <summary>
		/// 收市完成
		/// </summary>
		Closed = (Byte)'6',

		/// <summary>
		/// 结算
		/// </summary>
		Settlement = (Byte)'7'
	};

	/// <summary>
	/// TFtdcSettlementStatusType是一个结算状态类型
	/// </summary>
	public enum struct EnumSettlementStatusType : Byte
	{
		/// <summary>
		/// 初始
		/// </summary>
		Initialize = (Byte)'0',

		/// <summary>
		/// 结算中
		/// </summary>
		Settlementing = (Byte)'1',

		/// <summary>
		/// 已结算
		/// </summary>
		Settlemented = (Byte)'2',

		/// <summary>
		/// 结算完成
		/// </summary>
		Finished = (Byte)'3'
	};

	/// <summary>
	/// TFtdcInvestorTypeType是一个投资者类型类型
	/// </summary>
	public enum struct EnumInvestorTypeType : Byte
	{
		/// <summary>
		/// 自然人
		/// </summary>
		Person = (Byte)'0',

		/// <summary>
		/// 法人
		/// </summary>
		Company = (Byte)'1',

		/// <summary>
		/// 投资基金
		/// </summary>
		Fund = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerTypeType是一个经纪公司类型类型
	/// </summary>
	public enum struct EnumBrokerTypeType : Byte
	{
		/// <summary>
		/// 交易会员
		/// </summary>
		Trade = (Byte)'0',

		/// <summary>
		/// 交易结算会员
		/// </summary>
		TradeSettle = (Byte)'1'
	};

	/// <summary>
	/// TFtdcRiskLevelType是一个风险等级类型
	/// </summary>
	public enum struct EnumRiskLevelType : Byte
	{
		/// <summary>
		/// 低风险客户
		/// </summary>
		Low = (Byte)'1',

		/// <summary>
		/// 普通客户
		/// </summary>
		Normal = (Byte)'2',

		/// <summary>
		/// 关注客户
		/// </summary>
		Focus = (Byte)'3',

		/// <summary>
		/// 风险客户
		/// </summary>
		Risk = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFeeAcceptStyleType是一个手续费收取方式类型
	/// </summary>
	public enum struct EnumFeeAcceptStyleType : Byte
	{
		/// <summary>
		/// 按交易收取
		/// </summary>
		ByTrade = (Byte)'1',

		/// <summary>
		/// 按交割收取
		/// </summary>
		ByDeliv = (Byte)'2',

		/// <summary>
		/// 不收
		/// </summary>
		None = (Byte)'3',

		/// <summary>
		/// 按指定手续费收取
		/// </summary>
		FixFee = (Byte)'4'
	};

	/// <summary>
	/// TFtdcPasswordTypeType是一个密码类型类型
	/// </summary>
	public enum struct EnumPasswordTypeType : Byte
	{
		/// <summary>
		/// 交易密码
		/// </summary>
		Trade = (Byte)'1',

		/// <summary>
		/// 资金密码
		/// </summary>
		Account = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAlgorithmType是一个盈亏算法类型
	/// </summary>
	public enum struct EnumAlgorithmType : Byte
	{
		/// <summary>
		/// 浮盈浮亏都计算
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 浮盈不计，浮亏计
		/// </summary>
		OnlyLost = (Byte)'2',

		/// <summary>
		/// 浮盈计，浮亏不计
		/// </summary>
		OnlyGain = (Byte)'3',

		/// <summary>
		/// 浮盈浮亏都不计算
		/// </summary>
		None = (Byte)'4'
	};

	/// <summary>
	/// TFtdcIncludeCloseProfitType是一个是否包含平仓盈利类型
	/// </summary>
	public enum struct EnumIncludeCloseProfitType : Byte
	{
		/// <summary>
		/// 包含平仓盈利
		/// </summary>
		Include = (Byte)'0',

		/// <summary>
		/// 不包含平仓盈利
		/// </summary>
		NotInclude = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAllWithoutTradeType是一个是否受可提比例限制类型
	/// </summary>
	public enum struct EnumAllWithoutTradeType : Byte
	{
		/// <summary>
		/// 不受可提比例限制
		/// </summary>
		Enable = (Byte)'0',

		/// <summary>
		/// 受可提比例限制
		/// </summary>
		Disable = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFuturePwdFlagType是一个资金密码核对标志类型
	/// </summary>
	public enum struct EnumFuturePwdFlagType : Byte
	{
		/// <summary>
		/// 不核对
		/// </summary>
		UnCheck = (Byte)'0',

		/// <summary>
		/// 核对
		/// </summary>
		Check = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTransferTypeType是一个银期转账类型类型
	/// </summary>
	public enum struct EnumTransferTypeType : Byte
	{
		/// <summary>
		/// 银行转期货
		/// </summary>
		BankToFuture = (Byte)'0',

		/// <summary>
		/// 期货转银行
		/// </summary>
		FutureToBank = (Byte)'1'
	};

	/// <summary>
	/// TFtdcTransferValidFlagType是一个转账有效标志类型
	/// </summary>
	public enum struct EnumTransferValidFlagType : Byte
	{
		/// <summary>
		/// 无效或失败
		/// </summary>
		Invalid = (Byte)'0',

		/// <summary>
		/// 有效
		/// </summary>
		Valid = (Byte)'1',

		/// <summary>
		/// 冲正
		/// </summary>
		Reverse = (Byte)'2'
	};

	/// <summary>
	/// TFtdcReasonType是一个事由类型
	/// </summary>
	public enum struct EnumReasonType : Byte
	{
		/// <summary>
		/// 错单
		/// </summary>
		CD = (Byte)'0',

		/// <summary>
		/// 资金在途
		/// </summary>
		ZT = (Byte)'1',

		/// <summary>
		/// 其它
		/// </summary>
		QT = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSexType是一个性别类型
	/// </summary>
	public enum struct EnumSexType : Byte
	{
		/// <summary>
		/// 未知
		/// </summary>
		None = (Byte)'0',

		/// <summary>
		/// 男
		/// </summary>
		Man = (Byte)'1',

		/// <summary>
		/// 女
		/// </summary>
		Woman = (Byte)'2'
	};

	/// <summary>
	/// TFtdcUserTypeType是一个用户类型类型
	/// </summary>
	public enum struct EnumUserTypeType : Byte
	{
		/// <summary>
		/// 投资者
		/// </summary>
		Investor = (Byte)'0',

		/// <summary>
		/// 操作员
		/// </summary>
		Operator = (Byte)'1',

		/// <summary>
		/// 管理员
		/// </summary>
		SuperUser = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRateTypeType是一个费率类型类型
	/// </summary>
	public enum struct EnumRateTypeType : Byte
	{
		/// <summary>
		/// 保证金率
		/// </summary>
		MarginRate = (Byte)'2',

		/// <summary>
		/// 手续费率
		/// </summary>
		CommRate = (Byte)'1',

		/// <summary>
		/// 所有
		/// </summary>
		AllRate = (Byte)'0'
	};

	/// <summary>
	/// TFtdcNoteTypeType是一个通知类型类型
	/// </summary>
	public enum struct EnumNoteTypeType : Byte
	{
		/// <summary>
		/// 交易结算单
		/// </summary>
		TradeSettleBill = (Byte)'1',

		/// <summary>
		/// 交易结算月报
		/// </summary>
		TradeSettleMonth = (Byte)'2',

		/// <summary>
		/// 追加保证金通知书
		/// </summary>
		CallMarginNotes = (Byte)'3',

		/// <summary>
		/// 强行平仓通知书
		/// </summary>
		ForceCloseNotes = (Byte)'4',

		/// <summary>
		/// 成交通知书
		/// </summary>
		TradeNotes = (Byte)'5',

		/// <summary>
		/// 交割通知书
		/// </summary>
		DelivNotes = (Byte)'6'
	};

	/// <summary>
	/// TFtdcSettlementStyleType是一个结算单方式类型
	/// </summary>
	public enum struct EnumSettlementStyleType : Byte
	{
		/// <summary>
		/// 逐日盯市
		/// </summary>
		Day = (Byte)'1',

		/// <summary>
		/// 逐笔对冲
		/// </summary>
		Volume = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSettlementBillTypeType是一个结算单类型类型
	/// </summary>
	public enum struct EnumSettlementBillTypeType : Byte
	{
		/// <summary>
		/// 日报
		/// </summary>
		Day = (Byte)'0',

		/// <summary>
		/// 月报
		/// </summary>
		Month = (Byte)'1'
	};

	/// <summary>
	/// TFtdcUserRightTypeType是一个客户权限类型类型
	/// </summary>
	public enum struct EnumUserRightTypeType : Byte
	{
		/// <summary>
		/// 登录
		/// </summary>
		Logon = (Byte)'1',

		/// <summary>
		/// 银期转帐
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// 邮寄结算单
		/// </summary>
		EMail = (Byte)'3',

		/// <summary>
		/// 传真结算单
		/// </summary>
		Fax = (Byte)'4',

		/// <summary>
		/// 条件单
		/// </summary>
		ConditionOrder = (Byte)'5'
	};

	/// <summary>
	/// TFtdcMarginPriceTypeType是一个保证金价格类型类型
	/// </summary>
	public enum struct EnumMarginPriceTypeType : Byte
	{
		/// <summary>
		/// 昨结算价
		/// </summary>
		PreSettlementPrice = (Byte)'1',

		/// <summary>
		/// 最新价
		/// </summary>
		SettlementPrice = (Byte)'2',

		/// <summary>
		/// 成交均价
		/// </summary>
		AveragePrice = (Byte)'3',

		/// <summary>
		/// 开仓价
		/// </summary>
		OpenPrice = (Byte)'4'
	};

	/// <summary>
	/// TFtdcBillGenStatusType是一个结算单生成状态类型
	/// </summary>
	public enum struct EnumBillGenStatusType : Byte
	{
		/// <summary>
		/// 不生成
		/// </summary>
		None = (Byte)'0',

		/// <summary>
		/// 未生成
		/// </summary>
		NoGenerated = (Byte)'1',

		/// <summary>
		/// 已生成
		/// </summary>
		Generated = (Byte)'2'
	};

	/// <summary>
	/// TFtdcAlgoTypeType是一个算法类型类型
	/// </summary>
	public enum struct EnumAlgoTypeType : Byte
	{
		/// <summary>
		/// 持仓处理算法
		/// </summary>
		HandlePositionAlgo = (Byte)'1',

		/// <summary>
		/// 寻找保证金率算法
		/// </summary>
		FindMarginRateAlgo = (Byte)'2'
	};

	/// <summary>
	/// TFtdcHandlePositionAlgoIDType是一个持仓处理算法编号类型
	/// </summary>
	public enum struct EnumHandlePositionAlgoIDType : Byte
	{
		/// <summary>
		/// 基本
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// 大连商品交易所
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// 郑州商品交易所
		/// </summary>
		CZCE = (Byte)'3',

		/// <summary>
		/// 非交易
		/// </summary>
		NoneTrade = (Byte)'4',

		/// <summary>
		/// 证券
		/// </summary>
		Stock = (Byte)'5'
	};

	/// <summary>
	/// TFtdcFindMarginRateAlgoIDType是一个寻找保证金率算法编号类型
	/// </summary>
	public enum struct EnumFindMarginRateAlgoIDType : Byte
	{
		/// <summary>
		/// 基本
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// 大连商品交易所
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// 郑州商品交易所
		/// </summary>
		CZCE = (Byte)'3'
	};

	/// <summary>
	/// TFtdcHandleTradingAccountAlgoIDType是一个资金处理算法编号类型
	/// </summary>
	public enum struct EnumHandleTradingAccountAlgoIDType : Byte
	{
		/// <summary>
		/// 基本
		/// </summary>
		Base = (Byte)'1',

		/// <summary>
		/// 大连商品交易所
		/// </summary>
		DCE = (Byte)'2',

		/// <summary>
		/// 郑州商品交易所
		/// </summary>
		CZCE = (Byte)'3'
	};

	/// <summary>
	/// TFtdcPersonTypeType是一个联系人类型类型
	/// </summary>
	public enum struct EnumPersonTypeType : Byte
	{
		/// <summary>
		/// 指定下单人
		/// </summary>
		Order = (Byte)'1',

		/// <summary>
		/// 开户授权人
		/// </summary>
		Open = (Byte)'2',

		/// <summary>
		/// 资金调拨人
		/// </summary>
		Fund = (Byte)'3',

		/// <summary>
		/// 结算单确认人
		/// </summary>
		Settlement = (Byte)'4'
	};

	/// <summary>
	/// TFtdcQueryInvestorRangeType是一个查询范围类型
	/// </summary>
	public enum struct EnumQueryInvestorRangeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 查询分类
		/// </summary>
		Group = (Byte)'2',

		/// <summary>
		/// 单一投资者
		/// </summary>
		Single = (Byte)'3'
	};

	/// <summary>
	/// TFtdcInvestorRiskStatusType是一个投资者风险状态类型
	/// </summary>
	public enum struct EnumInvestorRiskStatusType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'1',

		/// <summary>
		/// 警告
		/// </summary>
		Warn = (Byte)'2',

		/// <summary>
		/// 追保
		/// </summary>
		Call = (Byte)'3',

		/// <summary>
		/// 强平
		/// </summary>
		Force = (Byte)'4',

		/// <summary>
		/// 异常
		/// </summary>
		Exception = (Byte)'5'
	};

	/// <summary>
	/// TFtdcUserEventTypeType是一个用户事件类型类型
	/// </summary>
	public enum struct EnumUserEventTypeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)' ',

		/// <summary>
		/// 登录
		/// </summary>
		Login = (Byte)'1',

		/// <summary>
		/// 登出
		/// </summary>
		Logout = (Byte)'2',

		/// <summary>
		/// 交易成功
		/// </summary>
		Trading = (Byte)'3',

		/// <summary>
		/// 交易失败
		/// </summary>
		TradingError = (Byte)'4',

		/// <summary>
		/// 修改密码
		/// </summary>
		UpdatePassword = (Byte)'5',

		/// <summary>
		/// 其他
		/// </summary>
		Other = (Byte)'9'
	};

	/// <summary>
	/// TFtdcCloseStyleType是一个平仓方式类型
	/// </summary>
	public enum struct EnumCloseStyleType : Byte
	{
		/// <summary>
		/// 先开先平
		/// </summary>
		Close = (Byte)'0',

		/// <summary>
		/// 先平今再平昨
		/// </summary>
		CloseToday = (Byte)'1'
	};

	/// <summary>
	/// TFtdcStatModeType是一个统计方式类型
	/// </summary>
	public enum struct EnumStatModeType : Byte
	{
		/// <summary>
		/// ----
		/// </summary>
		Non = (Byte)'0',

		/// <summary>
		/// 按合约统计
		/// </summary>
		Instrument = (Byte)'1',

		/// <summary>
		/// 按产品统计
		/// </summary>
		Product = (Byte)'2',

		/// <summary>
		/// 按投资者统计
		/// </summary>
		Investor = (Byte)'3'
	};

	/// <summary>
	/// TFtdcParkedOrderStatusType是一个预埋单状态类型
	/// </summary>
	public enum struct EnumParkedOrderStatusType : Byte
	{
		/// <summary>
		/// 未发送
		/// </summary>
		NotSend = (Byte)'1',

		/// <summary>
		/// 已发送
		/// </summary>
		Send = (Byte)'2',

		/// <summary>
		/// 已删除
		/// </summary>
		Deleted = (Byte)'3'
	};

	/// <summary>
	/// TFtdcVirDealStatusType是一个处理状态类型
	/// </summary>
	public enum struct EnumVirDealStatusType : Byte
	{
		/// <summary>
		/// 正在处理
		/// </summary>
		Dealing = (Byte)'1',

		/// <summary>
		/// 处理成功
		/// </summary>
		DeaclSucceed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrgSystemIDType是一个原有系统代码类型
	/// </summary>
	public enum struct EnumOrgSystemIDType : Byte
	{
		/// <summary>
		/// 综合交易平台
		/// </summary>
		Standard = (Byte)'0',

		/// <summary>
		/// 易盛系统
		/// </summary>
		ESunny = (Byte)'1',

		/// <summary>
		/// 金仕达V6系统
		/// </summary>
		KingStarV6 = (Byte)'2'
	};

	/// <summary>
	/// TFtdcVirTradeStatusType是一个交易状态类型
	/// </summary>
	public enum struct EnumVirTradeStatusType : Byte
	{
		/// <summary>
		/// 正常处理中
		/// </summary>
		NaturalDeal = (Byte)'0',

		/// <summary>
		/// 成功结束
		/// </summary>
		SucceedEnd = (Byte)'1',

		/// <summary>
		/// 失败结束
		/// </summary>
		FailedEND = (Byte)'2',

		/// <summary>
		/// 异常中
		/// </summary>
		Exception = (Byte)'3',

		/// <summary>
		/// 已人工异常处理
		/// </summary>
		ManualDeal = (Byte)'4',

		/// <summary>
		/// 通讯异常 ，请人工处理
		/// </summary>
		MesException = (Byte)'5',

		/// <summary>
		/// 系统出错，请人工处理
		/// </summary>
		SysException = (Byte)'6'
	};

	/// <summary>
	/// TFtdcVirBankAccTypeType是一个银行帐户类型类型
	/// </summary>
	public enum struct EnumVirBankAccTypeType : Byte
	{
		/// <summary>
		/// 存折
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// 储蓄卡
		/// </summary>
		BankCard = (Byte)'2',

		/// <summary>
		/// 信用卡
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcVirementStatusType是一个银行帐户类型类型
	/// </summary>
	public enum struct EnumVirementStatusType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Natural = (Byte)'0',

		/// <summary>
		/// 销户
		/// </summary>
		Canceled = (Byte)'9'
	};

	/// <summary>
	/// TFtdcVirementAvailAbilityType是一个有效标志类型
	/// </summary>
	public enum struct EnumVirementAvailAbilityType : Byte
	{
		/// <summary>
		/// 未确认
		/// </summary>
		NoAvailAbility = (Byte)'0',

		/// <summary>
		/// 有效
		/// </summary>
		AvailAbility = (Byte)'1',

		/// <summary>
		/// 冲正
		/// </summary>
		Repeal = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCFMMCKeyKindType是一个动态密钥类别(保证金监管)类型
	/// </summary>
	public enum struct EnumCFMMCKeyKindType : Byte
	{
		/// <summary>
		/// 主动请求更新
		/// </summary>
		REQUEST = (Byte)'R',

		/// <summary>
		/// CFMMC自动更新
		/// </summary>
		AUTO = (Byte)'A',

		/// <summary>
		/// CFMMC手动更新
		/// </summary>
		MANUAL = (Byte)'M'
	};

	/// <summary>
	/// TFtdcCertificationTypeType是一个证件类型类型
	/// </summary>
	public enum struct EnumCertificationTypeType : Byte
	{
		/// <summary>
		/// 身份证
		/// </summary>
		IDCard = (Byte)'0',

		/// <summary>
		/// 护照
		/// </summary>
		Passport = (Byte)'1',

		/// <summary>
		/// 军官证
		/// </summary>
		OfficerIDCard = (Byte)'2',

		/// <summary>
		/// 士兵证
		/// </summary>
		SoldierIDCard = (Byte)'3',

		/// <summary>
		/// 回乡证
		/// </summary>
		HomeComingCard = (Byte)'4',

		/// <summary>
		/// 户口簿
		/// </summary>
		HouseholdRegister = (Byte)'5',

		/// <summary>
		/// 营业执照号
		/// </summary>
		LicenseNo = (Byte)'6',

		/// <summary>
		/// 组织机构代码证
		/// </summary>
		InstitutionCodeCard = (Byte)'7',

		/// <summary>
		/// 临时营业执照号
		/// </summary>
		TempLicenseNo = (Byte)'8',

		/// <summary>
		/// 民办非企业登记证书
		/// </summary>
		NoEnterpriseLicenseNo = (Byte)'9',

		/// <summary>
		/// 其他证件
		/// </summary>
		OtherCard = (Byte)'x',

		/// <summary>
		/// 主管部门批文
		/// </summary>
		SuperDepAgree = (Byte)'a'
	};

	/// <summary>
	/// TFtdcFileBusinessCodeType是一个文件业务功能类型
	/// </summary>
	public enum struct EnumFileBusinessCodeType : Byte
	{
		/// <summary>
		/// 其他
		/// </summary>
		Others = (Byte)'0',

		/// <summary>
		/// 转账交易明细对账
		/// </summary>
		TransferDetails = (Byte)'1',

		/// <summary>
		/// 客户账户状态对账
		/// </summary>
		CustAccStatus = (Byte)'2',

		/// <summary>
		/// 账户类交易明细对账
		/// </summary>
		AccountTradeDetails = (Byte)'3',

		/// <summary>
		/// 期货账户信息变更明细对账
		/// </summary>
		FutureAccountChangeInfoDetails = (Byte)'4',

		/// <summary>
		/// 客户资金台账余额明细对账
		/// </summary>
		CustMoneyDetail = (Byte)'5',

		/// <summary>
		/// 客户销户结息明细对账
		/// </summary>
		CustCancelAccountInfo = (Byte)'6',

		/// <summary>
		/// 客户资金余额对账结果
		/// </summary>
		CustMoneyResult = (Byte)'7',

		/// <summary>
		/// 其它对账异常结果文件
		/// </summary>
		OthersExceptionResult = (Byte)'8',

		/// <summary>
		/// 客户结息净额明细
		/// </summary>
		CustInterestNetMoneyDetails = (Byte)'9',

		/// <summary>
		/// 客户资金交收明细
		/// </summary>
		CustMoneySendAndReceiveDetails = (Byte)'a',

		/// <summary>
		/// 法人存管银行资金交收汇总
		/// </summary>
		CorporationMoneyTotal = (Byte)'b',

		/// <summary>
		/// 主体间资金交收汇总
		/// </summary>
		MainbodyMoneyTotal = (Byte)'c',

		/// <summary>
		/// 总分平衡监管数据
		/// </summary>
		MainPartMonitorData = (Byte)'d',

		/// <summary>
		/// 存管银行备付金余额
		/// </summary>
		PreparationMoney = (Byte)'e',

		/// <summary>
		/// 协办存管银行资金监管数据
		/// </summary>
		BankMoneyMonitorData = (Byte)'f'
	};

	/// <summary>
	/// TFtdcCashExchangeCodeType是一个汇钞标志类型
	/// </summary>
	public enum struct EnumCashExchangeCodeType : Byte
	{
		/// <summary>
		/// 汇
		/// </summary>
		Exchange = (Byte)'1',

		/// <summary>
		/// 钞
		/// </summary>
		Cash = (Byte)'2'
	};

	/// <summary>
	/// TFtdcYesNoIndicatorType是一个是或否标识类型
	/// </summary>
	public enum struct EnumYesNoIndicatorType : Byte
	{
		/// <summary>
		/// 是
		/// </summary>
		Yes = (Byte)'0',

		/// <summary>
		/// 否
		/// </summary>
		No = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBanlanceTypeType是一个余额类型类型
	/// </summary>
	public enum struct EnumBanlanceTypeType : Byte
	{
		/// <summary>
		/// 当前余额
		/// </summary>
		CurrentMoney = (Byte)'0',

		/// <summary>
		/// 可用余额
		/// </summary>
		UsableMoney = (Byte)'1',

		/// <summary>
		/// 可取余额
		/// </summary>
		FetchableMoney = (Byte)'2',

		/// <summary>
		/// 冻结余额
		/// </summary>
		FreezeMoney = (Byte)'3'
	};

	/// <summary>
	/// TFtdcGenderType是一个性别类型
	/// </summary>
	public enum struct EnumGenderType : Byte
	{
		/// <summary>
		/// 未知状态
		/// </summary>
		Unknown = (Byte)'0',

		/// <summary>
		/// 男
		/// </summary>
		Male = (Byte)'1',

		/// <summary>
		/// 女
		/// </summary>
		Female = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFeePayFlagType是一个费用支付标志类型
	/// </summary>
	public enum struct EnumFeePayFlagType : Byte
	{
		/// <summary>
		/// 由受益方支付费用
		/// </summary>
		BEN = (Byte)'0',

		/// <summary>
		/// 由发送方支付费用
		/// </summary>
		OUR = (Byte)'1',

		/// <summary>
		/// 由发送方支付发起的费用，受益方支付接受的费用
		/// </summary>
		SHA = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPassWordKeyTypeType是一个密钥类型类型
	/// </summary>
	public enum struct EnumPassWordKeyTypeType : Byte
	{
		/// <summary>
		/// 交换密钥
		/// </summary>
		ExchangeKey = (Byte)'0',

		/// <summary>
		/// 密码密钥
		/// </summary>
		PassWordKey = (Byte)'1',

		/// <summary>
		/// MAC密钥
		/// </summary>
		MACKey = (Byte)'2',

		/// <summary>
		/// 报文密钥
		/// </summary>
		MessageKey = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFBTPassWordTypeType是一个密码类型类型
	/// </summary>
	public enum struct EnumFBTPassWordTypeType : Byte
	{
		/// <summary>
		/// 查询
		/// </summary>
		Query = (Byte)'0',

		/// <summary>
		/// 取款
		/// </summary>
		Fetch = (Byte)'1',

		/// <summary>
		/// 转帐
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// 交易
		/// </summary>
		Trade = (Byte)'3'
	};

	/// <summary>
	/// TFtdcBankRepealFlagType是一个银行冲正标志类型
	/// </summary>
	public enum struct EnumBankRepealFlagType : Byte
	{
		/// <summary>
		/// 银行无需自动冲正
		/// </summary>
		BankNotNeedRepeal = (Byte)'0',

		/// <summary>
		/// 银行待自动冲正
		/// </summary>
		BankWaitingRepeal = (Byte)'1',

		/// <summary>
		/// 银行已自动冲正
		/// </summary>
		BankBeenRepealed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerRepealFlagType是一个期商冲正标志类型
	/// </summary>
	public enum struct EnumBrokerRepealFlagType : Byte
	{
		/// <summary>
		/// 期商无需自动冲正
		/// </summary>
		BrokerNotNeedRepeal = (Byte)'0',

		/// <summary>
		/// 期商待自动冲正
		/// </summary>
		BrokerWaitingRepeal = (Byte)'1',

		/// <summary>
		/// 期商已自动冲正
		/// </summary>
		BrokerBeenRepealed = (Byte)'2'
	};

	/// <summary>
	/// TFtdcInstitutionTypeType是一个机构类别类型
	/// </summary>
	public enum struct EnumInstitutionTypeType : Byte
	{
		/// <summary>
		/// 银行
		/// </summary>
		Bank = (Byte)'0',

		/// <summary>
		/// 期商
		/// </summary>
		Future = (Byte)'1',

		/// <summary>
		/// 券商
		/// </summary>
		Store = (Byte)'2'
	};

	/// <summary>
	/// TFtdcLastFragmentType是一个最后分片标志类型
	/// </summary>
	public enum struct EnumLastFragmentType : Byte
	{
		/// <summary>
		/// 是最后分片
		/// </summary>
		Yes = (Byte)'0',

		/// <summary>
		/// 不是最后分片
		/// </summary>
		No = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankAccStatusType是一个银行账户状态类型
	/// </summary>
	public enum struct EnumBankAccStatusType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// 冻结
		/// </summary>
		Freeze = (Byte)'1',

		/// <summary>
		/// 挂失
		/// </summary>
		ReportLoss = (Byte)'2'
	};

	/// <summary>
	/// TFtdcMoneyAccountStatusType是一个资金账户状态类型
	/// </summary>
	public enum struct EnumMoneyAccountStatusType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// 销户
		/// </summary>
		Cancel = (Byte)'1'
	};

	/// <summary>
	/// TFtdcManageStatusType是一个存管状态类型
	/// </summary>
	public enum struct EnumManageStatusType : Byte
	{
		/// <summary>
		/// 指定存管
		/// </summary>
		Point = (Byte)'0',

		/// <summary>
		/// 预指定
		/// </summary>
		PrePoint = (Byte)'1',

		/// <summary>
		/// 撤销指定
		/// </summary>
		CancelPoint = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSystemTypeType是一个应用系统类型类型
	/// </summary>
	public enum struct EnumSystemTypeType : Byte
	{
		/// <summary>
		/// 银期转帐
		/// </summary>
		FutureBankTransfer = (Byte)'0',

		/// <summary>
		/// 银证转帐
		/// </summary>
		StockBankTransfer = (Byte)'1',

		/// <summary>
		/// 第三方存管
		/// </summary>
		TheThirdPartStore = (Byte)'2'
	};

	/// <summary>
	/// TFtdcTxnEndFlagType是一个银期转帐划转结果标志类型
	/// </summary>
	public enum struct EnumTxnEndFlagType : Byte
	{
		/// <summary>
		/// 正常处理中
		/// </summary>
		NormalProcessing = (Byte)'0',

		/// <summary>
		/// 成功结束
		/// </summary>
		Success = (Byte)'1',

		/// <summary>
		/// 失败结束
		/// </summary>
		Failed = (Byte)'2',

		/// <summary>
		/// 异常中
		/// </summary>
		Abnormal = (Byte)'3',

		/// <summary>
		/// 已人工异常处理
		/// </summary>
		ManualProcessedForException = (Byte)'4',

		/// <summary>
		/// 通讯异常 ，请人工处理
		/// </summary>
		CommuFailedNeedManualProcess = (Byte)'5',

		/// <summary>
		/// 系统出错，请人工处理
		/// </summary>
		SysErrorNeedManualProcess = (Byte)'6'
	};

	/// <summary>
	/// TFtdcProcessStatusType是一个银期转帐服务处理状态类型
	/// </summary>
	public enum struct EnumProcessStatusType : Byte
	{
		/// <summary>
		/// 未处理
		/// </summary>
		NotProcess = (Byte)'0',

		/// <summary>
		/// 开始处理
		/// </summary>
		StartProcess = (Byte)'1',

		/// <summary>
		/// 处理完成
		/// </summary>
		Finished = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCustTypeType是一个客户类型类型
	/// </summary>
	public enum struct EnumCustTypeType : Byte
	{
		/// <summary>
		/// 自然人
		/// </summary>
		Person = (Byte)'0',

		/// <summary>
		/// 机构户
		/// </summary>
		Institution = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFBTTransferDirectionType是一个银期转帐方向类型
	/// </summary>
	public enum struct EnumFBTTransferDirectionType : Byte
	{
		/// <summary>
		/// 入金，银行转期货
		/// </summary>
		FromBankToFuture = (Byte)'1',

		/// <summary>
		/// 出金，期货转银行
		/// </summary>
		FromFutureToBank = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOpenOrDestroyType是一个开销户类别类型
	/// </summary>
	public enum struct EnumOpenOrDestroyType : Byte
	{
		/// <summary>
		/// 开户
		/// </summary>
		Open = (Byte)'1',

		/// <summary>
		/// 销户
		/// </summary>
		Destroy = (Byte)'0'
	};

	/// <summary>
	/// TFtdcAvailabilityFlagType是一个有效标志类型
	/// </summary>
	public enum struct EnumAvailabilityFlagType : Byte
	{
		/// <summary>
		/// 未确认
		/// </summary>
		Invalid = (Byte)'0',

		/// <summary>
		/// 有效
		/// </summary>
		Valid = (Byte)'1',

		/// <summary>
		/// 冲正
		/// </summary>
		Repeal = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOrganTypeType是一个机构类型类型
	/// </summary>
	public enum struct EnumOrganTypeType : Byte
	{
		/// <summary>
		/// 银行代理
		/// </summary>
		Bank = (Byte)'1',

		/// <summary>
		/// 交易前置
		/// </summary>
		Future = (Byte)'2',

		/// <summary>
		/// 银期转帐平台管理
		/// </summary>
		PlateForm = (Byte)'9'
	};

	/// <summary>
	/// TFtdcOrganLevelType是一个机构级别类型
	/// </summary>
	public enum struct EnumOrganLevelType : Byte
	{
		/// <summary>
		/// 银行总行或期商总部
		/// </summary>
		HeadQuarters = (Byte)'1',

		/// <summary>
		/// 银行分中心或期货公司营业部
		/// </summary>
		Branch = (Byte)'2'
	};

	/// <summary>
	/// TFtdcProtocalIDType是一个协议类型类型
	/// </summary>
	public enum struct EnumProtocalIDType : Byte
	{
		/// <summary>
		/// 期商协议
		/// </summary>
		FutureProtocal = (Byte)'0',

		/// <summary>
		/// 工行协议
		/// </summary>
		ICBCProtocal = (Byte)'1',

		/// <summary>
		/// 农行协议
		/// </summary>
		ABCProtocal = (Byte)'2',

		/// <summary>
		/// 中国银行协议
		/// </summary>
		CBCProtocal = (Byte)'3',

		/// <summary>
		/// 建行协议
		/// </summary>
		CCBProtocal = (Byte)'4',

		/// <summary>
		/// 交行协议
		/// </summary>
		BOCOMProtocal = (Byte)'5',

		/// <summary>
		/// 银期转帐平台协议
		/// </summary>
		FBTPlateFormProtocal = (Byte)'X'
	};

	/// <summary>
	/// TFtdcConnectModeType是一个套接字连接方式类型
	/// </summary>
	public enum struct EnumConnectModeType : Byte
	{
		/// <summary>
		/// 短连接
		/// </summary>
		ShortConnect = (Byte)'0',

		/// <summary>
		/// 长连接
		/// </summary>
		LongConnect = (Byte)'1'
	};

	/// <summary>
	/// TFtdcSyncModeType是一个套接字通信方式类型
	/// </summary>
	public enum struct EnumSyncModeType : Byte
	{
		/// <summary>
		/// 异步
		/// </summary>
		ASync = (Byte)'0',

		/// <summary>
		/// 同步
		/// </summary>
		Sync = (Byte)'1'
	};

	/// <summary>
	/// TFtdcBankAccTypeType是一个银行帐号类型类型
	/// </summary>
	public enum struct EnumBankAccTypeType : Byte
	{
		/// <summary>
		/// 银行存折
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// 储蓄卡
		/// </summary>
		SavingCard = (Byte)'2',

		/// <summary>
		/// 信用卡
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcFutureAccTypeType是一个期货公司帐号类型类型
	/// </summary>
	public enum struct EnumFutureAccTypeType : Byte
	{
		/// <summary>
		/// 银行存折
		/// </summary>
		BankBook = (Byte)'1',

		/// <summary>
		/// 储蓄卡
		/// </summary>
		SavingCard = (Byte)'2',

		/// <summary>
		/// 信用卡
		/// </summary>
		CreditCard = (Byte)'3'
	};

	/// <summary>
	/// TFtdcOrganStatusType是一个接入机构状态类型
	/// </summary>
	public enum struct EnumOrganStatusType : Byte
	{
		/// <summary>
		/// 启用
		/// </summary>
		Ready = (Byte)'0',

		/// <summary>
		/// 签到
		/// </summary>
		CheckIn = (Byte)'1',

		/// <summary>
		/// 签退
		/// </summary>
		CheckOut = (Byte)'2',

		/// <summary>
		/// 对帐文件到达
		/// </summary>
		CheckFileArrived = (Byte)'3',

		/// <summary>
		/// 对帐
		/// </summary>
		CheckDetail = (Byte)'4',

		/// <summary>
		/// 日终清理
		/// </summary>
		DayEndClean = (Byte)'5',

		/// <summary>
		/// 注销
		/// </summary>
		Invalid = (Byte)'9'
	};

	/// <summary>
	/// TFtdcCCBFeeModeType是一个建行收费模式类型
	/// </summary>
	public enum struct EnumCCBFeeModeType : Byte
	{
		/// <summary>
		/// 按金额扣收
		/// </summary>
		ByAmount = (Byte)'1',

		/// <summary>
		/// 按月扣收
		/// </summary>
		ByMonth = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCommApiTypeType是一个通讯API类型类型
	/// </summary>
	public enum struct EnumCommApiTypeType : Byte
	{
		/// <summary>
		/// 客户端
		/// </summary>
		Client = (Byte)'1',

		/// <summary>
		/// 服务端
		/// </summary>
		Server = (Byte)'2',

		/// <summary>
		/// 交易系统的UserApi
		/// </summary>
		UserApi = (Byte)'3'
	};

	/// <summary>
	/// TFtdcLinkStatusType是一个连接状态类型
	/// </summary>
	public enum struct EnumLinkStatusType : Byte
	{
		/// <summary>
		/// 已经连接
		/// </summary>
		Connected = (Byte)'1',

		/// <summary>
		/// 没有连接
		/// </summary>
		Disconnected = (Byte)'2'
	};

	/// <summary>
	/// TFtdcPwdFlagType是一个密码核对标志类型
	/// </summary>
	public enum struct EnumPwdFlagType : Byte
	{
		/// <summary>
		/// 不核对
		/// </summary>
		NoCheck = (Byte)'0',

		/// <summary>
		/// 明文核对
		/// </summary>
		BlankCheck = (Byte)'1',

		/// <summary>
		/// 密文核对
		/// </summary>
		EncryptCheck = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSecuAccTypeType是一个期货帐号类型类型
	/// </summary>
	public enum struct EnumSecuAccTypeType : Byte
	{
		/// <summary>
		/// 资金帐号
		/// </summary>
		AccountID = (Byte)'1',

		/// <summary>
		/// 资金卡号
		/// </summary>
		CardID = (Byte)'2',

		/// <summary>
		/// 上海股东帐号
		/// </summary>
		SHStockholderID = (Byte)'3',

		/// <summary>
		/// 深圳股东帐号
		/// </summary>
		SZStockholderID = (Byte)'4'
	};

	/// <summary>
	/// TFtdcTransferStatusType是一个转账交易状态类型
	/// </summary>
	public enum struct EnumTransferStatusType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		Normal = (Byte)'0',

		/// <summary>
		/// 被冲正
		/// </summary>
		Repealed = (Byte)'1'
	};

	/// <summary>
	/// TFtdcSponsorTypeType是一个发起方类型
	/// </summary>
	public enum struct EnumSponsorTypeType : Byte
	{
		/// <summary>
		/// 期商
		/// </summary>
		Broker = (Byte)'0',

		/// <summary>
		/// 银行
		/// </summary>
		Bank = (Byte)'1'
	};

	/// <summary>
	/// TFtdcReqRspTypeType是一个请求响应类别类型
	/// </summary>
	public enum struct EnumReqRspTypeType : Byte
	{
		/// <summary>
		/// 请求
		/// </summary>
		Request = (Byte)'0',

		/// <summary>
		/// 响应
		/// </summary>
		Response = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFBTUserEventTypeType是一个银期转帐用户事件类型类型
	/// </summary>
	public enum struct EnumFBTUserEventTypeType : Byte
	{
		/// <summary>
		/// 签到
		/// </summary>
		SignIn = (Byte)'0',

		/// <summary>
		/// 银行转期货
		/// </summary>
		FromBankToFuture = (Byte)'1',

		/// <summary>
		/// 期货转银行
		/// </summary>
		FromFutureToBank = (Byte)'2',

		/// <summary>
		/// 开户
		/// </summary>
		OpenAccount = (Byte)'3',

		/// <summary>
		/// 销户
		/// </summary>
		CancelAccount = (Byte)'4',

		/// <summary>
		/// 变更银行账户
		/// </summary>
		ChangeAccount = (Byte)'5',

		/// <summary>
		/// 冲正银行转期货
		/// </summary>
		RepealFromBankToFuture = (Byte)'6',

		/// <summary>
		/// 冲正期货转银行
		/// </summary>
		RepealFromFutureToBank = (Byte)'7',

		/// <summary>
		/// 查询银行账户
		/// </summary>
		QueryBankAccount = (Byte)'8',

		/// <summary>
		/// 查询期货账户
		/// </summary>
		QueryFutureAccount = (Byte)'9',

		/// <summary>
		/// 签退
		/// </summary>
		SignOut = (Byte)'A',

		/// <summary>
		/// 密钥同步
		/// </summary>
		SyncKey = (Byte)'B',

		/// <summary>
		/// 其他
		/// </summary>
		Other = (Byte)'Z'
	};

	/// <summary>
	/// TFtdcNotifyClassType是一个风险通知类型类型
	/// </summary>
	public enum struct EnumNotifyClassType : Byte
	{
		/// <summary>
		/// 正常
		/// </summary>
		NOERROR = (Byte)'0',

		/// <summary>
		/// 警示
		/// </summary>
		Warn = (Byte)'1',

		/// <summary>
		/// 追保
		/// </summary>
		Call = (Byte)'2',

		/// <summary>
		/// 强平
		/// </summary>
		Force = (Byte)'3',

		/// <summary>
		/// 穿仓
		/// </summary>
		CHUANCANG = (Byte)'4',

		/// <summary>
		/// 异常
		/// </summary>
		Exception = (Byte)'5'
	};

	/// <summary>
	/// TFtdcForceCloseTypeType是一个强平单类型类型
	/// </summary>
	public enum struct EnumForceCloseTypeType : Byte
	{
		/// <summary>
		/// 手工强平
		/// </summary>
		Manual = (Byte)'0',

		/// <summary>
		/// 单一投资者辅助强平
		/// </summary>
		Single = (Byte)'1',

		/// <summary>
		/// 批量投资者辅助强平
		/// </summary>
		Group = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRiskNotifyMethodType是一个风险通知途径类型
	/// </summary>
	public enum struct EnumRiskNotifyMethodType : Byte
	{
		/// <summary>
		/// 系统通知
		/// </summary>
		System = (Byte)'0',

		/// <summary>
		/// 短信通知
		/// </summary>
		SMS = (Byte)'1',

		/// <summary>
		/// 邮件通知
		/// </summary>
		EMail = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRiskNotifyStatusType是一个风险通知状态类型
	/// </summary>
	public enum struct EnumRiskNotifyStatusType : Byte
	{
		/// <summary>
		/// 未生成
		/// </summary>
		NotGen = (Byte)'0',

		/// <summary>
		/// 已生成未发送
		/// </summary>
		Generated = (Byte)'1',

		/// <summary>
		/// 发送失败
		/// </summary>
		SendError = (Byte)'2',

		/// <summary>
		/// 已发送未接收
		/// </summary>
		SendOk = (Byte)'3',

		/// <summary>
		/// 已接收未确认
		/// </summary>
		Received = (Byte)'4',

		/// <summary>
		/// 已确认
		/// </summary>
		Confirmed = (Byte)'5'
	};

	/// <summary>
	/// TFtdcRiskUserEventType是一个风控用户操作事件类型
	/// </summary>
	public enum struct EnumRiskUserEventType : Byte
	{
		/// <summary>
		/// 导出数据
		/// </summary>
		ExportData = (Byte)'0'
	};

	/// <summary>
	/// TFtdcConditionalOrderSortTypeType是一个条件单索引条件类型
	/// </summary>
	public enum struct EnumConditionalOrderSortTypeType : Byte
	{
		/// <summary>
		/// 使用最新价升序
		/// </summary>
		LastPriceAsc = (Byte)'0',

		/// <summary>
		/// 使用最新价降序
		/// </summary>
		LastPriceDesc = (Byte)'1',

		/// <summary>
		/// 使用卖价升序
		/// </summary>
		AskPriceAsc = (Byte)'2',

		/// <summary>
		/// 使用卖价降序
		/// </summary>
		AskPriceDesc = (Byte)'3',

		/// <summary>
		/// 使用买价升序
		/// </summary>
		BidPriceAsc = (Byte)'4',

		/// <summary>
		/// 使用买价降序
		/// </summary>
		BidPriceDesc = (Byte)'5'
	};

	/// <summary>
	/// TFtdcSendTypeType是一个报送状态类型
	/// </summary>
	public enum struct EnumSendTypeType : Byte
	{
		/// <summary>
		/// 未发送
		/// </summary>
		NoSend = (Byte)'0',

		/// <summary>
		/// 已发送
		/// </summary>
		Sended = (Byte)'1',

		/// <summary>
		/// 已生成
		/// </summary>
		Generated = (Byte)'2',

		/// <summary>
		/// 报送失败
		/// </summary>
		SendFail = (Byte)'3',

		/// <summary>
		/// 接收成功
		/// </summary>
		Success = (Byte)'4',

		/// <summary>
		/// 接收失败
		/// </summary>
		Fail = (Byte)'5',

		/// <summary>
		/// 取消报送
		/// </summary>
		Cancel = (Byte)'6'
	};

	/// <summary>
	/// TFtdcClientIDStatusType是一个交易编码状态类型
	/// </summary>
	public enum struct EnumClientIDStatusType : Byte
	{
		/// <summary>
		/// 未申请
		/// </summary>
		NoApply = (Byte)'1',

		/// <summary>
		/// 已提交申请
		/// </summary>
		Submited = (Byte)'2',

		/// <summary>
		/// 已发送申请
		/// </summary>
		Sended = (Byte)'3',

		/// <summary>
		/// 完成
		/// </summary>
		Success = (Byte)'4',

		/// <summary>
		/// 拒绝
		/// </summary>
		Refuse = (Byte)'5',

		/// <summary>
		/// 已撤销编码
		/// </summary>
		Cancel = (Byte)'6'
	};

	/// <summary>
	/// TFtdcQuestionTypeType是一个特有信息类型类型
	/// </summary>
	public enum struct EnumQuestionTypeType : Byte
	{
		/// <summary>
		/// 单选
		/// </summary>
		Radio = (Byte)'1',

		/// <summary>
		/// 多选
		/// </summary>
		Option = (Byte)'2',

		/// <summary>
		/// 填空
		/// </summary>
		Blank = (Byte)'3'
	};

	/// <summary>
	/// TFtdcProcessTypeType是一个流程功能类型类型
	/// </summary>
	public enum struct EnumProcessTypeType : Byte
	{
		/// <summary>
		/// 申请交易编码
		/// </summary>
		ApplyTradingCode = (Byte)'1',

		/// <summary>
		/// 撤销交易编码
		/// </summary>
		CancelTradingCode = (Byte)'2',

		/// <summary>
		/// 修改身份信息
		/// </summary>
		ModifyIDCard = (Byte)'3',

		/// <summary>
		/// 修改一般信息
		/// </summary>
		ModifyNoIDCard = (Byte)'4',

		/// <summary>
		/// 交易所开户报备
		/// </summary>
		ExchOpenBak = (Byte)'5',

		/// <summary>
		/// 交易所销户报备
		/// </summary>
		ExchCancelBak = (Byte)'6'
	};

	/// <summary>
	/// TFtdcBusinessTypeType是一个业务类型类型
	/// </summary>
	public enum struct EnumBusinessTypeType : Byte
	{
		/// <summary>
		/// 请求
		/// </summary>
		Request = (Byte)'1',

		/// <summary>
		/// 应答
		/// </summary>
		Response = (Byte)'2',

		/// <summary>
		/// 通知
		/// </summary>
		Notice = (Byte)'3'
	};

	/// <summary>
	/// TFtdcCfmmcReturnCodeType是一个监控中心返回码类型
	/// </summary>
	public enum struct EnumCfmmcReturnCodeType : Byte
	{
		/// <summary>
		/// 成功
		/// </summary>
		Success = (Byte)'0',

		/// <summary>
		/// 该客户已经有流程在处理中
		/// </summary>
		Working = (Byte)'1',

		/// <summary>
		/// 监控中客户资料检查失败
		/// </summary>
		InfoFail = (Byte)'2',

		/// <summary>
		/// 监控中实名制检查失败
		/// </summary>
		IDCardFail = (Byte)'3',

		/// <summary>
		/// 其他错误
		/// </summary>
		OtherFail = (Byte)'4'
	};

	/// <summary>
	/// TFtdcClientTypeType是一个客户类型类型
	/// </summary>
	public enum struct EnumClientTypeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'0',

		/// <summary>
		/// 个人
		/// </summary>
		Person = (Byte)'1',

		/// <summary>
		/// 单位
		/// </summary>
		Company = (Byte)'2'
	};

	/// <summary>
	/// TFtdcExchangeIDTypeType是一个交易所编号类型
	/// </summary>
	public enum struct EnumExchangeIDTypeType : Byte
	{
		/// <summary>
		/// 上海期货交易所
		/// </summary>
		SHFE = (Byte)'S',

		/// <summary>
		/// 郑州商品交易所
		/// </summary>
		CZCE = (Byte)'Z',

		/// <summary>
		/// 大连商品交易所
		/// </summary>
		DCE = (Byte)'D',

		/// <summary>
		/// 中国金融期货交易所
		/// </summary>
		CFFEX = (Byte)'J'
	};

	/// <summary>
	/// TFtdcExClientIDTypeType是一个交易编码类型类型
	/// </summary>
	public enum struct EnumExClientIDTypeType : Byte
	{
		/// <summary>
		/// 套保
		/// </summary>
		Hedge = (Byte)'1',

		/// <summary>
		/// 套利
		/// </summary>
		Arbitrage = (Byte)'2',

		/// <summary>
		/// 投机
		/// </summary>
		Speculation = (Byte)'3'
	};

	/// <summary>
	/// TFtdcUpdateFlagType是一个更新状态类型
	/// </summary>
	public enum struct EnumUpdateFlagType : Byte
	{
		/// <summary>
		/// 未更新
		/// </summary>
		NoUpdate = (Byte)'0',

		/// <summary>
		/// 更新全部信息成功
		/// </summary>
		Success = (Byte)'1',

		/// <summary>
		/// 更新全部信息失败
		/// </summary>
		Fail = (Byte)'2',

		/// <summary>
		/// 更新交易编码成功
		/// </summary>
		TCSuccess = (Byte)'3',

		/// <summary>
		/// 更新交易编码失败
		/// </summary>
		TCFail = (Byte)'4',

		/// <summary>
		/// 已丢弃
		/// </summary>
		Cancel = (Byte)'5'
	};

	/// <summary>
	/// TFtdcApplyOperateIDType是一个申请动作类型
	/// </summary>
	public enum struct EnumApplyOperateIDType : Byte
	{
		/// <summary>
		/// 开户
		/// </summary>
		OpenInvestor = (Byte)'1',

		/// <summary>
		/// 修改身份信息
		/// </summary>
		ModifyIDCard = (Byte)'2',

		/// <summary>
		/// 修改一般信息
		/// </summary>
		ModifyNoIDCard = (Byte)'3',

		/// <summary>
		/// 申请交易编码
		/// </summary>
		ApplyTradingCode = (Byte)'4',

		/// <summary>
		/// 撤销交易编码
		/// </summary>
		CancelTradingCode = (Byte)'5',

		/// <summary>
		/// 销户
		/// </summary>
		CancelInvestor = (Byte)'6'
	};

	/// <summary>
	/// TFtdcApplyStatusIDType是一个申请状态类型
	/// </summary>
	public enum struct EnumApplyStatusIDType : Byte
	{
		/// <summary>
		/// 未补全
		/// </summary>
		NoComplete = (Byte)'1',

		/// <summary>
		/// 已提交
		/// </summary>
		Submited = (Byte)'2',

		/// <summary>
		/// 已审核
		/// </summary>
		Checked = (Byte)'3',

		/// <summary>
		/// 已拒绝
		/// </summary>
		Refused = (Byte)'4',

		/// <summary>
		/// 已删除
		/// </summary>
		Deleted = (Byte)'5'
	};

	/// <summary>
	/// TFtdcSendMethodType是一个发送方式类型
	/// </summary>
	public enum struct EnumSendMethodType : Byte
	{
		/// <summary>
		/// 电子发送
		/// </summary>
		ByAPI = (Byte)'1',

		/// <summary>
		/// 文件发送
		/// </summary>
		ByFile = (Byte)'2'
	};

	/// <summary>
	/// TFtdcEventModeType是一个操作方法类型
	/// </summary>
	public enum struct EnumEventModeType : Byte
	{
		/// <summary>
		/// 增加
		/// </summary>
		ADD = (Byte)'1',

		/// <summary>
		/// 修改
		/// </summary>
		UPDATE = (Byte)'2',

		/// <summary>
		/// 删除
		/// </summary>
		DELETE = (Byte)'3',

		/// <summary>
		/// 复核
		/// </summary>
		CHECK = (Byte)'4',

		/// <summary>
		/// 冲销
		/// </summary>
		Reverse = (Byte)'7'
	};

	/// <summary>
	/// TFtdcUOAAutoSendType是一个统一开户申请自动发送类型
	/// </summary>
	public enum struct EnumUOAAutoSendType : Byte
	{
		/// <summary>
		/// 自动发送并接收
		/// </summary>
		ASR = (Byte)'1',

		/// <summary>
		/// 自动发送，不自动接收
		/// </summary>
		ASNR = (Byte)'2',

		/// <summary>
		/// 不自动发送，自动接收
		/// </summary>
		NSAR = (Byte)'3',

		/// <summary>
		/// 不自动发送，也不自动接收
		/// </summary>
		NSR = (Byte)'4'
	};

	/// <summary>
	/// TFtdcFlowIDType是一个流程ID类型
	/// </summary>
	public enum struct EnumFlowIDType : Byte
	{
		/// <summary>
		/// 投资者对应投资者组设置
		/// </summary>
		InvestorGroupFlow = (Byte)'1'
	};

	/// <summary>
	/// TFtdcCheckLevelType是一个复核级别类型
	/// </summary>
	public enum struct EnumCheckLevelType : Byte
	{
		/// <summary>
		/// 零级复核
		/// </summary>
		Zero = (Byte)'0',

		/// <summary>
		/// 一级复核
		/// </summary>
		One = (Byte)'1',

		/// <summary>
		/// 二级复核
		/// </summary>
		Two = (Byte)'2'
	};

	/// <summary>
	/// TFtdcCheckStatusType是一个复核级别类型
	/// </summary>
	public enum struct EnumCheckStatusType : Byte
	{
		/// <summary>
		/// 未复核
		/// </summary>
		Init = (Byte)'0',

		/// <summary>
		/// 复核中
		/// </summary>
		Checking = (Byte)'1',

		/// <summary>
		/// 已复核
		/// </summary>
		Checked = (Byte)'2',

		/// <summary>
		/// 拒绝
		/// </summary>
		Refuse = (Byte)'3',

		/// <summary>
		/// 作废
		/// </summary>
		Cancel = (Byte)'4'
	};

	/// <summary>
	/// TFtdcUsedStatusType是一个生效状态类型
	/// </summary>
	public enum struct EnumUsedStatusType : Byte
	{
		/// <summary>
		/// 未生效
		/// </summary>
		Unused = (Byte)'0',

		/// <summary>
		/// 已生效
		/// </summary>
		Used = (Byte)'1',

		/// <summary>
		/// 生效失败
		/// </summary>
		Fail = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBankAcountOriginType是一个账户来源类型
	/// </summary>
	public enum struct EnumBankAcountOriginType : Byte
	{
		/// <summary>
		/// 手工录入
		/// </summary>
		ByAccProperty = (Byte)'0',

		/// <summary>
		/// 银期转账
		/// </summary>
		ByFBTransfer = (Byte)'1'
	};

	/// <summary>
	/// TFtdcMonthBillTradeSumType是一个结算单月报成交汇总方式类型
	/// </summary>
	public enum struct EnumMonthBillTradeSumType : Byte
	{
		/// <summary>
		/// 同日同合约
		/// </summary>
		ByInstrument = (Byte)'0',

		/// <summary>
		/// 同日同合约同价格
		/// </summary>
		ByDayInsPrc = (Byte)'1',

		/// <summary>
		/// 同合约
		/// </summary>
		ByDayIns = (Byte)'2'
	};

	/// <summary>
	/// TFtdcOTPTypeType是一个动态令牌类型类型
	/// </summary>
	public enum struct EnumOTPTypeType : Byte
	{
		/// <summary>
		/// 无动态令牌
		/// </summary>
		NONE = (Byte)'0',

		/// <summary>
		/// 时间令牌
		/// </summary>
		TOTP = (Byte)'1'
	};

	/// <summary>
	/// TFtdcOTPStatusType是一个动态令牌状态类型
	/// </summary>
	public enum struct EnumOTPStatusType : Byte
	{
		/// <summary>
		/// 未使用
		/// </summary>
		Unused = (Byte)'0',

		/// <summary>
		/// 已使用
		/// </summary>
		Used = (Byte)'1',

		/// <summary>
		/// 注销
		/// </summary>
		Disuse = (Byte)'2'
	};

	/// <summary>
	/// TFtdcBrokerUserTypeType是一个经济公司用户类型类型
	/// </summary>
	public enum struct EnumBrokerUserTypeType : Byte
	{
		/// <summary>
		/// 投资者
		/// </summary>
		Investor = (Byte)'1'
	};

	/// <summary>
	/// TFtdcFutureTypeType是一个期货类型类型
	/// </summary>
	public enum struct EnumFutureTypeType : Byte
	{
		/// <summary>
		/// 商品期货
		/// </summary>
		Commodity = (Byte)'1',

		/// <summary>
		/// 金融期货
		/// </summary>
		Financial = (Byte)'2'
	};

	/// <summary>
	/// TFtdcFundEventTypeType是一个资金管理操作类型类型
	/// </summary>
	public enum struct EnumFundEventTypeType : Byte
	{
		/// <summary>
		/// 转账限额
		/// </summary>
		Restriction = (Byte)'0',

		/// <summary>
		/// 当日转账限额
		/// </summary>
		TodayRestriction = (Byte)'1',

		/// <summary>
		/// 期商流水
		/// </summary>
		Transfer = (Byte)'2',

		/// <summary>
		/// 资金冻结
		/// </summary>
		Credit = (Byte)'3',

		/// <summary>
		/// 投资者可提资金比例
		/// </summary>
		InvestorWithdrawAlm = (Byte)'4',

		/// <summary>
		/// 投资者出入金
		/// </summary>
		InvestorFundIO = (Byte)'8'
	};

	/// <summary>
	/// TFtdcAccountSourceTypeType是一个资金账户来源类型
	/// </summary>
	public enum struct EnumAccountSourceTypeType : Byte
	{
		/// <summary>
		/// 银期同步
		/// </summary>
		FBTransfer = (Byte)'0',

		/// <summary>
		/// 手工录入
		/// </summary>
		ManualEntry = (Byte)'1'
	};

	/// <summary>
	/// TFtdcCodeSourceTypeType是一个交易编码来源类型
	/// </summary>
	public enum struct EnumCodeSourceTypeType : Byte
	{
		/// <summary>
		/// 统一开户
		/// </summary>
		UnifyAccount = (Byte)'0',

		/// <summary>
		/// 手工录入
		/// </summary>
		ManualEntry = (Byte)'1'
	};

	/// <summary>
	/// TFtdcUserRangeType是一个操作员范围类型
	/// </summary>
	public enum struct EnumUserRangeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'0',

		/// <summary>
		/// 单一操作员
		/// </summary>
		Single = (Byte)'1'
	};

	/// <summary>
	/// TFtdcStockTradeTypeType是一个证券交易类型类型
	/// </summary>
	public enum struct EnumStockTradeTypeType : Byte
	{
		/// <summary>
		/// 可交易证券
		/// </summary>
		Stock = (Byte)'0',

		/// <summary>
		/// 买入网络密码服务
		/// </summary>
		BuyNetService = (Byte)'1',

		/// <summary>
		/// 回购注销
		/// </summary>
		CancelRepurchase = (Byte)'2',

		/// <summary>
		/// 指定撤销
		/// </summary>
		CancelRegister = (Byte)'3',

		/// <summary>
		/// 指定登记
		/// </summary>
		Register = (Byte)'4',

		/// <summary>
		/// 买入发行申购
		/// </summary>
		PurchaseIssue = (Byte)'5',

		/// <summary>
		/// 卖出配股
		/// </summary>
		Allotment = (Byte)'6',

		/// <summary>
		/// 卖出要约收购
		/// </summary>
		SellTender = (Byte)'7',

		/// <summary>
		/// 买入要约收购
		/// </summary>
		BuyTender = (Byte)'8',

		/// <summary>
		/// 网上投票
		/// </summary>
		NetVote = (Byte)'9',

		/// <summary>
		/// 卖出可转债回售
		/// </summary>
		SellConvertibleBonds = (Byte)'a',

		/// <summary>
		/// 权证行权代码
		/// </summary>
		OptionExecute = (Byte)'b',

		/// <summary>
		/// 开放式基金申购
		/// </summary>
		PurchaseOF = (Byte)'c',

		/// <summary>
		/// 开放式基金赎回
		/// </summary>
		RedeemOF = (Byte)'d',

		/// <summary>
		/// 开放式基金认购
		/// </summary>
		SubscribeOF = (Byte)'e',

		/// <summary>
		/// 开放式基金转托管转出
		/// </summary>
		OFCustodianTranfer = (Byte)'f',

		/// <summary>
		/// 开放式基金分红设置
		/// </summary>
		OFDividendConfig = (Byte)'g',

		/// <summary>
		/// 开放式基金转成其他基金
		/// </summary>
		OFTransfer = (Byte)'h',

		/// <summary>
		/// 债券入库
		/// </summary>
		BondsIn = (Byte)'i',

		/// <summary>
		/// 债券出库
		/// </summary>
		BondsOut = (Byte)'j',

		/// <summary>
		/// EFT申购
		/// </summary>
		PurchaseETF = (Byte)'k',

		/// <summary>
		/// EFT赎回
		/// </summary>
		RedeemETF = (Byte)'l',

		/// <summary>
		/// 可转债回售登记
		/// </summary>
		ConvertibleRegister = (Byte)'m'
	};

	/// <summary>
	/// TFtdcCreationredemptionStatusType是一个基金当天申购赎回状态类型
	/// </summary>
	public enum struct EnumCreationredemptionStatusType : Byte
	{
		/// <summary>
		/// 不允许申购赎回
		/// </summary>
		Forbidden = (Byte)'0',

		/// <summary>
		/// 表示允许申购和赎回
		/// </summary>
		Allow = (Byte)'1',

		/// <summary>
		/// 允许申购、不允许赎回
		/// </summary>
		OnlyPurchase = (Byte)'2',

		/// <summary>
		/// 不允许申购、允许赎回
		/// </summary>
		OnlyRedeem = (Byte)'3'
	};

	/// <summary>
	/// TFtdcETFCurrenceReplaceStatusType是一个ETF现金替代标志类型
	/// </summary>
	public enum struct EnumETFCurrenceReplaceStatusType : Byte
	{
		/// <summary>
		/// 禁止现金替代
		/// </summary>
		Forbidden = (Byte)'0',

		/// <summary>
		/// 可以现金替代
		/// </summary>
		Allow = (Byte)'1',

		/// <summary>
		/// 必须现金替代
		/// </summary>
		Force = (Byte)'2'
	};

	/// <summary>
	/// TFtdcRepayShortSellAlgoType是一个买券还券算法类型
	/// </summary>
	public enum struct EnumRepayShortSellAlgoType : Byte
	{
		/// <summary>
		/// 默认算法
		/// </summary>
		Original = (Byte)'0',

		/// <summary>
		/// 按还券比例计算
		/// </summary>
		Ratio = (Byte)'1',

		/// <summary>
		/// Min[1,2]
		/// </summary>
		Min = (Byte)'2'
	};

	/// <summary>
	/// TFtdcSysOperTypeType是一个系统日志操作类型类型
	/// </summary>
	public enum struct EnumSysOperTypeType : Byte
	{
		/// <summary>
		/// 修改操作员密码
		/// </summary>
		UpdatePassword = (Byte)'0',

		/// <summary>
		/// 操作员组织架构关系
		/// </summary>
		UserDepartment = (Byte)'1',

		/// <summary>
		/// 角色管理
		/// </summary>
		RoleManager = (Byte)'2',

		/// <summary>
		/// 角色功能设置
		/// </summary>
		RoleFunction = (Byte)'3',

		/// <summary>
		/// 基础参数设置
		/// </summary>
		BaseParam = (Byte)'4',

		/// <summary>
		/// 设置操作员
		/// </summary>
		SetUserID = (Byte)'5',

		/// <summary>
		/// 用户角色设置
		/// </summary>
		SetUserRole = (Byte)'6',

		/// <summary>
		/// 用户IP限制
		/// </summary>
		UserIpRestriction = (Byte)'7',

		/// <summary>
		/// 组织架构管理
		/// </summary>
		DepartmentManager = (Byte)'8',

		/// <summary>
		/// 组织架构向查询分类复制
		/// </summary>
		DepartmentCopy = (Byte)'9',

		/// <summary>
		/// 交易编码管理
		/// </summary>
		Tradingcode = (Byte)'A',

		/// <summary>
		/// 投资者状态维护
		/// </summary>
		InvestorStatus = (Byte)'B',

		/// <summary>
		/// 投资者权限管理
		/// </summary>
		InvestorAuthority = (Byte)'C',

		/// <summary>
		/// 属性设置
		/// </summary>
		PropertySet = (Byte)'D',

		/// <summary>
		/// 重置投资者密码
		/// </summary>
		ReSetInvestorPasswd = (Byte)'E',

		/// <summary>
		/// 投资者个性信息维护
		/// </summary>
		InvestorPersonalityInfo = (Byte)'F'
	};

	/// <summary>
	/// TFtdcSysOperModeType是一个系统日志操作方法类型
	/// </summary>
	public enum struct EnumSysOperModeType : Byte
	{
		/// <summary>
		/// 增加
		/// </summary>
		Add = (Byte)'1',

		/// <summary>
		/// 修改
		/// </summary>
		Update = (Byte)'2',

		/// <summary>
		/// 删除
		/// </summary>
		Delete = (Byte)'3',

		/// <summary>
		/// 复制
		/// </summary>
		Copy = (Byte)'4',

		/// <summary>
		/// 激活
		/// </summary>
		AcTive = (Byte)'5',

		/// <summary>
		/// 注销
		/// </summary>
		CanCel = (Byte)'6',

		/// <summary>
		/// 重置
		/// </summary>
		ReSet = (Byte)'7'
	};

	/// <summary>
	/// TFtdcInstrumentRangeType是一个股票权限分类类型
	/// </summary>
	public enum struct EnumInstrumentRangeType : Byte
	{
		/// <summary>
		/// 所有
		/// </summary>
		All = (Byte)'1',

		/// <summary>
		/// 产品
		/// </summary>
		Product = (Byte)'2',

		/// <summary>
		/// 股票权限模版
		/// </summary>
		Model = (Byte)'3',

		/// <summary>
		/// 股票
		/// </summary>
		Stock = (Byte)'4'
	};

	/// <summary>
	/// TFtdcCapitalStockTypeType是一个股本类型类型
	/// </summary>
	public enum struct EnumCapitalStockTypeType : Byte
	{
		/// <summary>
		/// 总通股本
		/// </summary>
		TOTALSTOCK = (Byte)'1',

		/// <summary>
		/// 流通股本
		/// </summary>
		CIRCULATION = (Byte)'2'
	};

}; // end of name space
