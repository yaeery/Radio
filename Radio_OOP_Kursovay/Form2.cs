using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Radio_OOP_Kursovay
{
    public partial class Form2 : Form
    {

        List<int> Using_Days = new List<int>();
        public Form2()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
            {
                Using_Days.Add(checkedListBox1.CheckedIndices[i] + 1);
            }
            if (Using_Days.Count == 0)
            {
                for (int i = 0; i < 7; i++)
                {
                    Using_Days.Add(i + 1);
                }
            }
            for (int i = 0; i < Using_Days.Count; i++)
            {
                Program.Stroka += Using_Days[i].ToString();
            }
            Program.ObshidataGridView.Rows.Clear();
            Form1.Vivod();
            Program.Stroka = "";
            Using_Days.Clear();
            checkedListBox1.Items.Clear();
            this.Close();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
