using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using CTPZQ;
using System.Diagnostics;
using System.Reflection;

namespace Demo
{
    public partial class Form1 : Form
    {
        CTPZQ.CTPMDAdapter md;

        Form2 form = null;

        string FRONT_ADDR = "tcp://ctp24-front4.financial-trading-platform.com:41213";  // 前置地址
        string BrokerID = "2222";                       // 经纪公司代码
        string UserID = "1000001";                       // 投资者代码
        string Password = "1";                          // 用户密码
        string ExchangeID = "SSE";                      // 上交所
        int iRequestID = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (md != null)
                md.Release();
            if (form != null)
                form.Dispose();
        }

        void md_OnCtpRtnEvent(object sender, CtpRtnEventArgs e)
        {
            ThostFtdcDepthMarketDataField fld = e.Param as ThostFtdcDepthMarketDataField;

            Console.WriteLine(ToString(fld));
        }

        void md_OnCtpRspEvent(object sender, CtpRspEventArgs e)
        {
            bool err = IsErrorRspInfo(e.RspInfo);

            __DEBUGPF__();
            Console.WriteLine(e.EventType.ToString());

            switch (e.EventType)
            {
                case CtpEnumRspType.RspUserLogin:
                    if (e.IsLast && !err)
                        Console.WriteLine("登录成功");
                    break;
                case CtpEnumRspType.RspSubMarketData:
                    {
                        ThostFtdcSpecificInstrumentField f = e.Param as ThostFtdcSpecificInstrumentField;
                        Console.WriteLine("订阅成功:" + f.InstrumentID);
                        break;
                    }
                default:
                    break;
            }
        }

        void md_OnCtpFrontEvent(object sender, CtpFrontEventArgs e)
        {
            __DEBUGPF__();
            Console.WriteLine(e.EventType.ToString());

            switch (e.EventType)
            {
                case CtpEnumFrontType.FrontConnected:
                    {
                        ThostFtdcReqUserLoginField req = new ThostFtdcReqUserLoginField();
                        req.BrokerID = BrokerID;
                        req.UserID = UserID;
                        req.Password = Password;
                        int iResult = md.ReqUserLogin(req, ++iRequestID);
                        break;
                    }
                default:
                    break;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (md == null)
            {
                md = new CTPZQ.CTPMDAdapter();
                md.OnCtpFrontEvent += md_OnCtpFrontEvent;
                md.OnCtpRspEvent += md_OnCtpRspEvent;
                md.OnCtpRtnEvent += md_OnCtpRtnEvent;

                md.RegisterFront(FRONT_ADDR);
                md.Init();
            }
        }

        bool IsErrorRspInfo(ThostFtdcRspInfoField pRspInfo)
        {
            // 如果ErrorID != 0, 说明收到了错误的响应
            bool bResult = ((pRspInfo != null) && (pRspInfo.ErrorID != 0));
            if (bResult)
                Console.WriteLine("--->>> ErrorID={0}, ErrorMsg={1}", pRspInfo.ErrorID, pRspInfo.ErrorMsg);
            return bResult;
        }

        public static string ToString(ThostFtdcDepthMarketDataField pDepthMarketData)
        {
            return string.Format("行情: {0,-6}, 时{1}.{2:D3}, 价{3,6}, 量{4}, 仓{5}", pDepthMarketData.InstrumentID, pDepthMarketData.UpdateTime, pDepthMarketData.UpdateMillisec, pDepthMarketData.LastPrice, pDepthMarketData.Volume, pDepthMarketData.OpenInterest);
        }

        void __DEBUGPF__()
        {
            StackTrace ss = new StackTrace(false);
            MethodBase mb = ss.GetFrame(1).GetMethod();
            string str = "--->>> " + mb.DeclaringType.Name + "." + mb.Name + "()";
            Debug.WriteLine(str);
            Console.WriteLine(str);
        }

        private void btnRelease_Click(object sender, EventArgs e)
        {
            if (md != null)
            {
                md.Dispose();
                md = null;
            }
        }

        private void btnSubInst_Click(object sender, EventArgs e)
        {
            List<string> inst = new List<string>();
            inst.Add("601857");
            inst.Add("601398");
            if (md != null)
                md.SubscribeMarketData(inst.ToArray(), ExchangeID);
        }

        private void btnTrader_Click(object sender, EventArgs e)
        {
            if (form == null)
            {
                form = new Form2();
                form.Disposed += new EventHandler((s, evt) =>
                {
                    form = null;
                });
            }
            form.Show(this);
        }
    }
}
