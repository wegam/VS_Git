using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;

namespace Serial
{
    public partial class Usart : Form
    {
        public Usart()
        {
            InitializeComponent();
            System.Windows.Forms.Control.CheckForIllegalCrossThreadCalls = false;//关闭跨线程检测
        }

    
        private void comboBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for (int i = 1; i < 256; i++)
            {
                comport.Items.Add("COM"+i.ToString());

            }
            comport.Text = "COM3";
            baud.Text = "19200";
            
            serialPort.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(Port_DataReceived);
        }
        private void Port_DataReceived(object sender,SerialDataReceivedEventArgs e)
        {//串口接收代码
            if (rxascmode.Checked)
            {
                int bufferlen = serialPort.BytesToRead;
                byte[] bytes = new byte[bufferlen];
                serialPort.Read(bytes, 0, bufferlen);
                string gb = System.Text.Encoding.Default.GetString(bytes);
                textBox.AppendText(gb);
            }
            else if (rxhexmode.Checked)
            {
                string str = Convert.ToString((byte)serialPort.ReadByte(), 16).ToUpper();
                textBox.AppendText("0x" + (str.Length == 1 ? "0" + str : str) + " ");
            }
            else {
                ;
            }
        }
        private void comboBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {//打开串口助手按钮
            try
            {
                serialPort.PortName = comport.Text;
                serialPort.BaudRate = Convert.ToInt32(baud.Text);
                serialPort.DataBits = Convert.ToInt32(DataBitcomboBox.Text);
                if (1 == Convert.ToInt32(StopBitcomboBox.Text))
                {
                    serialPort.StopBits = StopBits.One;
                }
                else if (2 == Convert.ToInt32(StopBitcomboBox.Text))
                {
                    serialPort.StopBits = StopBits.Two;
                }
                else
                {
                    serialPort.StopBits = StopBits.OnePointFive;
                }

                if ("None" == ParitycomboBox.Text)
                {
                    serialPort.Parity = Parity.None;
                }
                else if ("Odd" == ParitycomboBox.Text)
                {
                    serialPort.Parity = Parity.Odd;
                }
                else if ("Even" == ParitycomboBox.Text)
                {
                    serialPort.Parity = Parity.Even;
                }
                else if ("Mark" == ParitycomboBox.Text)
                {
                    serialPort.Parity = Parity.Mark;
                }
                else if ("Space" == ParitycomboBox.Text)
                {
                    serialPort.Parity = Parity.Space;
                }
                
                    serialPort.Open();
                
               opencom.Enabled=false;
               closecom.Enabled=true;
            }
            catch
                {
                    MessageBox.Show("串口打开失败！！！");
                }
            }

        private void button2_Click(object sender, EventArgs e)
        {//关闭串口助手按钮
            try{
                
                   serialPort.Close();
                   opencom.Enabled = true;
                   closecom.Enabled = false;
               
            }
            catch 
            {
                MessageBox.Show("串口关闭失败！！！");
            }
        }

        private void baud_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void clearrxbutton_Click(object sender, EventArgs e)
        {
            //清空接收区
            textBox.Clear();
        }

        private void cleartxbutton_Click(object sender, EventArgs e)
        {//清空发送区
            TXtextBox.Clear();

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void txdata_Click(object sender, EventArgs e)
        {//选择发送字符还是HEX格式的数据
            byte[] ch = new byte[1];
            if (serialPort.IsOpen)
            {
                if (TXtextBox.Text != "")
                {
                    if (txascmode.Checked)
                    {
                        try
                        {
                            Encoding gb = System.Text.Encoding.GetEncoding("gb2312");
                            byte[] bytes = gb.GetBytes(TXtextBox.Text);
                            serialPort.Write(bytes,0,bytes.Length); //发送字符


                          
                        }
                        catch 
                        {
                            MessageBox.Show("发送数据过程中产生错误！！！");
                            serialPort.Close();
                            opencom.Enabled = true;
                            closecom.Enabled = false; 
                        }
                    }
                    else if (txhexmode.Checked)
                    {
                        int errCount = 0;
                      
                        
                        for (int j = 0; j < TXtextBox.Text.Length; j++)
                        {
                            if ((Convert.ToChar(TXtextBox.Text.Substring(j * 1, 1).ToUpper()) > 'F'))
                            {
                                errCount++;
                                
                            } 
                        }
                        if (errCount != 0)
                        {

                            goto Error;
                        }
                        else {
                            goto eeof;
                        }

                            Error: MessageBox.Show("输入了非法十六进制数！！！");
                            if (errCount == 0)
                            {
                                goto eeof;
                            }
                            else {
                                errCount = 0;
                                goto err;
                            }
                            

                            
                        eeof:
                            for (int i = 0; i < (TXtextBox.Text.Length - TXtextBox.Text.Length % 2) / 2; i++)
                            {
                                ch[0] = Convert.ToByte(TXtextBox.Text.Substring(i * 2, 2), 16);
                                serialPort.Write(ch, 0, 1);
                            }
                        if (TXtextBox.Text.Length % 2 != 0)
                        {
                           ch[0] = Convert.ToByte(TXtextBox.Text.Substring(TXtextBox.Text.Length - TXtextBox.Text.Length % 2, TXtextBox.Text.Length % 2), 16);
                            serialPort.Write(ch, 0, 1);
                        }

                    err: ;
                    }
                    else {
                        ;
                    }
                }
            }
        }

        private void TXtextBox_TextChanged(object sender, EventArgs e)
        {//窗口内容大于窗口显示容量时自动出现滚动条
            TXtextBox.ScrollToCaret();
        }

        private void txascmode_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        private void textbox_TextChanged(object sender, EventArgs e)
        {//窗口内容大于窗口显示容量时自动出现滚动条
            textBox.ScrollToCaret();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void StopBitcomboBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Paritylabel_Click(object sender, EventArgs e)
        {

        }

        private void ParitycomboBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void rxascmode_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void rxhexmode_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void txhexmode_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void zuozhebutton1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("学院：保定职业技术学院\n专业：应用技术专业\n年级：大二\n软件版本：v1.01\n功能说明：支持中英文收发\n        支持十六进制收发\n        支持ASCII码和中文\n        以十六进制方式显示。\n联系QQ：547336083\n软件运行需要\n.NET framework 4.0\n支持库。");
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        
    }

}
