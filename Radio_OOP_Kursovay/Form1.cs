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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Sozdanie_Kolonok();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        void Sozdanie_Kolonok()
        {
            var colum1 = new DataGridViewTextBoxColumn();
            colum1.Width = 120;
            colum1.HeaderText = "Название";
            var colum2 = new DataGridViewTextBoxColumn();
            colum2.Width = 120;
            colum2.HeaderText = "Ведущий";
            var colum3 = new DataGridViewTextBoxColumn();
            colum3.Width = 80;
            colum3.HeaderText = "Время";
            var colum4 = new DataGridViewTextBoxColumn();
            colum4.Width = 160;
            colum4.HeaderText = "День недели";
            var colum5 = new DataGridViewTextBoxColumn();
            colum5.Width = 60;
            colum5.HeaderText = "Рейтинг";
            dataGridView1.Columns.AddRange(colum1);
            dataGridView1.Columns.AddRange(colum2);
            dataGridView1.Columns.AddRange(colum3);
            dataGridView1.Columns.AddRange(colum4);
            dataGridView1.Columns.AddRange(colum5);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Program.Sort_Reiting_Rize();
            Program.Zapolnenie_Daanymi();
            string s =  Program.Leaders();
            dataGridView1.Rows.Clear();
            if (Program.Name.Count > 0)
            {
                for (int i = 0; i < s.Length; i++)
                {
                    Program.ObshidataGridView.Rows.Insert(i, Program.Name[s[i]-'0'], Program.Vedushi[s[i] - '0'], Program.Times[s[i] - '0'], Program.Days[s[i] - '0'], Program.Reiting[s[i] - '0']);// Функцию в длл с которая с equal_range и поимк индекса и строкой отправить в с№
                }
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Program.Sort_Reiting_Drop();
            dataGridView1.Rows.Clear();
            Vivod();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Program.Sort_Reiting_Rize();
            dataGridView1.Rows.Clear();
            Vivod();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Program.Sort_Name();
            dataGridView1.Rows.Clear();
            Vivod();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Program.Sort_Vedushi();
            dataGridView1.Rows.Clear();
            Vivod();
        }
        public static void Vivod ()
        {
            Program.Zapolnenie_Daanymi();
            if (Program.Name.Count > 0)
            {
                for (int i = 0; i<Program.Name.Count; i++)
                {
                    Program.ObshidataGridView.Rows.Insert(i, Program.Name[i], Program.Vedushi[i], Program.Times[i], Program.Days[i], Program.Reiting[i]);
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Program.ObshidataGridView = dataGridView1;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form4 form4 = new Form4();
            form4.Show();
        }
    }
}
