using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Demo
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Console.WriteLine("注意：\r\n请记得将thostmduserapiSSE.dll和thosttraderapiSSE.dll拷贝到exe所在目录。\r\n否则会提示：未能加载文件或程序集“CTPZQ.Net.dll”或它的某一个依赖项。找不到指定的模块。\r\n");
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
