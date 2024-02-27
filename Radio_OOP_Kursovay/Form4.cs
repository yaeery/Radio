using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Radio_OOP_Kursovay
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            Application.Exit();
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void button1_Click(object sender, EventArgs e)
        {
            Program.Name.Clear();
            Program.Vedushi.Clear();
            Program.Reiting.Clear();
            Program.Days.Clear();
            Program.Times.Clear();
            Program.ObshidataGridView.Rows.Clear();
            Program.Delete();
            richTextBox1.Text = " ";

            string[] inputStrArray = new string[0];

            IntPtr pNames = StringArrayToIntPtr<char>(inputStrArray);



            Int64 result = Program.Memory(ref pNames);

            string[] names;

            names = null;

            names = IntPtrToStringArray<char>(1, pNames);

            richTextBox1.Text += names[0] + '\n';
        }

        public static IntPtr StringArrayToIntPtr<GenChar>(string[] inputStrArray)

        {

            int size = inputStrArray.Length;

            IntPtr[] inPointers = new IntPtr[size];

            int dim = IntPtr.Size * size;

            IntPtr rRoot = Marshal.AllocCoTaskMem(dim);

            for (int i = 0; i < size; i++)

            {

                if (typeof(GenChar) == typeof(char))

                    inPointers[i] = Marshal.StringToCoTaskMemUni(inputStrArray[i]);

                else if (typeof(GenChar) == typeof(byte))

                    inPointers[i] = Marshal.StringToCoTaskMemAnsi(inputStrArray[i]);

                else if (typeof(GenChar) == typeof(IntPtr))

                    inPointers[i] = Marshal.StringToBSTR(inputStrArray[i]);

            }

            Marshal.Copy(inPointers, 0, rRoot, size);

            return rRoot;

        }



        public static string[] IntPtrToStringArray<GenChar>(int size, IntPtr rRoot)

        {

            IntPtr[] outPointers = new IntPtr[size];

            Marshal.Copy(rRoot, outPointers, 0, size);

            string[] outputStrArray = new string[size];



            for (int i = 0; i < size; i++)

            {

                if (typeof(GenChar) == typeof(char))

                    outputStrArray[i] = Marshal.PtrToStringUni(outPointers[i]);

                else if (typeof(GenChar) == typeof(byte))

                    outputStrArray[i] = Marshal.PtrToStringAnsi(outPointers[i]);

                else if (typeof(GenChar) == typeof(IntPtr))

                    outputStrArray[i] = Marshal.PtrToStringBSTR(outPointers[i]);



                Marshal.FreeCoTaskMem(outPointers[i]);

            }

            Marshal.FreeCoTaskMem(rRoot);

            return outputStrArray;

        }

    } 
}
