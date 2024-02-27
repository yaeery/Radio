using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Radio_OOP_Kursovay
{
    static class Program
    {
        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void Create();

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void Sort_Name();

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void Sort_Vedushi();

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void Sort_Reiting_Rize();

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void Sort_Reiting_Drop();

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern int Get_Size();


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Name(int index);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Vedushi(int index);


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Reiting(int index);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Days(int index);


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Get_Time(int index);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool Is_Day([MarshalAs(UnmanagedType.LPTStr)] string stroka, int index);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public static extern void File([MarshalAs(UnmanagedType.LPTStr)] string stroka);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Programm_Days([MarshalAs(UnmanagedType.LPTStr)] string stroka);

        [DllImport("DLL.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string Leaders();


        [DllImport("DLL.dll", CharSet = CharSet.Ansi)]
        public static extern void Delete();


        [DllImport("DLL.dll", CharSet = CharSet.Unicode)]
        public extern static Int64 Memory(ref IntPtr names);


        public static List<string> Name = new List<string>();
        public static List<string> Vedushi = new List<string>();
        public static List<string> Reiting = new List<string>();
        public static List<string> Days = new List<string>();
        public static List<string> Times = new List<string>();
        public static DataGridView ObshidataGridView;
        public static string Stroka ="";

        [STAThread]
        static void Main()
        {
            Create();
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }

        public static void Zapolnenie_Daanymi()
        {
            Name.Clear();
            Vedushi.Clear();
            Reiting.Clear();
            Days.Clear();
            Times.Clear();
            
                for (int i = 0; i < Get_Size(); i++)
                {
                    if (Stroka.Length == 0)
                    {
                        Name.Add(Get_Name(i));
                        Vedushi.Add(Get_Vedushi(i));
                        Reiting.Add(Get_Reiting(i));
                        Times.Add(Get_Time(i));
                        Days.Add(Get_Days(i));
                    }
                    else if (Is_Day(Stroka, i) == true)
                    {
                        Name.Add(Get_Name(i));
                        Vedushi.Add(Get_Vedushi(i));
                        Reiting.Add(Get_Reiting(i));
                        Times.Add(Get_Time(i));
                        Days.Add(Get_Days(i));
                    }
                }
            
        }
    }
}
