using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CTPZQ;

namespace Demo
{
    
    public partial class Form2 : Form
    {
        CTPTraderAdapter api = new CTPTraderAdapter();
        
        string FRONT_ADDR = "tcp://ctp24-front2.financial-trading-platform.com:41205";  // 前置地址
        string BrokerID = "2222";                       // 经纪公司代码
        string UserID = "1000001";                   // 投资者代码
        string Password = "1";                      // 用户密码
        string ExchangeID = "SSE";      // 上期所
        int iRequestID = 0;

        public Form2()
        {
            InitializeComponent();

            this.Disposed += Form2_Disposed;

            api.OnCtpFrontEvent += api_OnCtpFrontEvent;
            api.OnCtpRspEvent += api_OnCtpRspEvent;
            api.OnCtpRspQryEvent += api_OnCtpRspQryEvent;
            api.OnCtpRtnEvent += api_OnCtpRtnEvent;
        }

        void Form2_Disposed(object sender, EventArgs e)
        {
            api.Release();
        }

        void api_OnCtpRtnEvent(object sender, CtpRtnEventArgs e)
        {
            Console.WriteLine(e.EventType.ToString());
        }

        void api_OnCtpRspQryEvent(object sender, CtpRspQryEventArgs e)
        {
            Console.WriteLine(e.EventType.ToString());

            switch (e.EventType)
            {
                case CtpEnumRspQryType.RspQryInstrument:
                    {
                        ThostFtdcInstrumentField f = e.Param as ThostFtdcInstrumentField;
                        if (f != null)
                        {
                            Console.WriteLine("{0}, {1}, {2}", f.InstrumentID, f.InstrumentName, f.PriceTick);
                        }
                    }
                    break;
            }
        }

        void api_OnCtpRspEvent(object sender, CtpRspEventArgs e)
        {
            bool err = IsErrorRspInfo(e.RspInfo);

            Console.WriteLine(e.EventType.ToString());

            switch (e.EventType)
            {
                case CtpEnumRspType.RspUserLogin:
                    if(e.IsLast && !err)
                    Console.WriteLine("登录成功");
                    break;
                default:
                    break;
            }
        }

        void api_OnCtpFrontEvent(object sender, CtpFrontEventArgs e)
        {
            Console.WriteLine(e.EventType.ToString());

            switch (e.EventType)
            {
                case CtpEnumFrontType.FrontConnected:
                    {
                        ThostFtdcReqUserLoginField req = new ThostFtdcReqUserLoginField();
                        req.BrokerID = BrokerID;
                        req.UserID = UserID;
                        req.Password = Password;
                        int iResult = api.ReqUserLogin(req, ++iRequestID);
                        break;
                    }
                default:
                    break;
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            api.SubscribePublicTopic(EnumTeResumeType.THOST_TERT_RESTART);
            api.SubscribePrivateTopic(EnumTeResumeType.THOST_TERT_RESTART);

            api.RegisterFront(FRONT_ADDR);
            api.Init();
        }

        bool IsErrorRspInfo(ThostFtdcRspInfoField pRspInfo)
        {
            // 如果ErrorID != 0, 说明收到了错误的响应
            bool bResult = ((pRspInfo != null) && (pRspInfo.ErrorID != 0));
            if (bResult)
                Console.WriteLine("--->>> ErrorID={0}, ErrorMsg={1}", pRspInfo.ErrorID, pRspInfo.ErrorMsg);
            return bResult;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ThostFtdcQryInstrumentField f = new ThostFtdcQryInstrumentField();
            f.ExchangeID = ExchangeID;
            f.InstrumentID = "";
            api.ReqQryInstrument(f, ++iRequestID);
        }
    }
}
