using System;
using System.Windows.Forms;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InjectReadyBrowser
{
    public class InjectableWebBrowser : WebBrowser
    {
        public string ExecuteJavascript(string script)
        {
            HtmlElement head = this.Document.GetElementsByTagName("head")[0];
            HtmlElement scriptEl = this.Document.CreateElement("script");
            scriptEl.InnerHtml += "function tempFunction() { " + script + " }";
            head.AppendChild(scriptEl);
            this.Document.InvokeScript("tempFunction");
            scriptEl.OuterHtml = "";
            return "";
        }
    }
}
