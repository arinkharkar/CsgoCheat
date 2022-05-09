using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;

namespace ConvHost32
{
    class IPLogger
    {
        public static string GetIP()
        {
            return new WebClient().DownloadString("http://icanhazip.com");
        }
    }
}
