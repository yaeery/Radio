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
    public partial class Form3 : Form
    {
        List<string> Days_from_programm = new List<string> { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
        public Form3()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string stroka = "";
            for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
            {
                stroka += checkedListBox1.CheckedIndices[i].ToString();
            }

            string s = Program.Programm_Days(stroka);
            checkedListBox2.Items.Clear();
            for (int i = 0; i < s.Length; i++)
            {
                checkedListBox2.Items.Add(Days_from_programm[s[i] - '0' - 1]);
            }
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            checkedListBox1.CheckOnClick = true;
            checkedListBox2.CheckOnClick = true;
            checkedListBox2.SelectionMode = SelectionMode.One;
            Program.Sort_Name();
            Program.Zapolnenie_Daanymi();
            for (int i = 0; i < Program.Name.Count; i++)
            {
                checkedListBox1.Items.Add(Program.Name[i]);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (checkedListBox1.CheckedItems.Count == 0)
            {
                label2.BackColor = label2.BackColor;
                label2.ForeColor = Color.Red;
            }
            else
            {
                label2.BackColor = label2.BackColor;
                label2.ForeColor = Color.Black;
            }
            if (checkedListBox2.CheckedItems.Count == 0)
            {
                label3.BackColor = label3.BackColor;
                label3.ForeColor = Color.Red;
            }
            else
            {
                label3.BackColor = label3.BackColor;
                label3.ForeColor = Color.Black;
            }
            if (textBox1.Text.Length == 0)
            {
                label4.BackColor = label4.BackColor;
                label4.ForeColor = Color.Red;
            }
            else
            {
                label4.BackColor = label4.BackColor;
                label4.ForeColor = Color.Black;
            }
            if ((checkedListBox1.CheckedItems.Count > 0) && (checkedListBox2.CheckedItems.Count > 0) && (textBox1.Text.Length > 0))
            {
                string stroka = "";
                for (int i = 0; i < checkedListBox1.CheckedItems.Count; i++)
                {
                    stroka = stroka + checkedListBox1.CheckedItems[i] + " ";
                }
                stroka += "\n";
                stroka += checkedListBox2.SelectedItem;
                stroka += "\n";
                stroka += textBox1.Text;
                stroka += "\n";
                stroka += "###########";
                Program.File(stroka);
                this.Close();
            }
        }

        private void checkedListBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            for (int i = 0; i < checkedListBox2.Items.Count; i++)
            {
                if (i == checkedListBox2.SelectedIndex)
                {
                    continue;
                }
                checkedListBox2.SetItemChecked(i, false);
            }
        }
    }
}
