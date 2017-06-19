namespace Serial
{
    partial class Usart
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Usart));
            this.opencom = new System.Windows.Forms.Button();
            this.closecom = new System.Windows.Forms.Button();
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.comport = new System.Windows.Forms.ComboBox();
            this.baud = new System.Windows.Forms.ComboBox();
            this.COMlabel = new System.Windows.Forms.Label();
            this.BAUDlabel = new System.Windows.Forms.Label();
            this.textBox = new System.Windows.Forms.TextBox();
            this.TXlabel = new System.Windows.Forms.Label();
            this.RXlabel = new System.Windows.Forms.Label();
            this.txascmode = new System.Windows.Forms.RadioButton();
            this.txhexmode = new System.Windows.Forms.RadioButton();
            this.rxascmode = new System.Windows.Forms.RadioButton();
            this.rxhexmode = new System.Windows.Forms.RadioButton();
            this.TXtextBox = new System.Windows.Forms.TextBox();
            this.txdata = new System.Windows.Forms.Button();
            this.clearrxbutton = new System.Windows.Forms.Button();
            this.cleartxbutton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.DataBitcomboBox = new System.Windows.Forms.ComboBox();
            this.DataBitlabel = new System.Windows.Forms.Label();
            this.StopBitcomboBox = new System.Windows.Forms.ComboBox();
            this.StopBitlabel = new System.Windows.Forms.Label();
            this.ParitycomboBox = new System.Windows.Forms.ComboBox();
            this.Paritylabel = new System.Windows.Forms.Label();
            this.zuozhebutton1 = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // opencom
            // 
            this.opencom.Location = new System.Drawing.Point(485, 270);
            this.opencom.Name = "opencom";
            this.opencom.Size = new System.Drawing.Size(75, 23);
            this.opencom.TabIndex = 0;
            this.opencom.Text = "打开串口";
            this.opencom.UseVisualStyleBackColor = true;
            this.opencom.Click += new System.EventHandler(this.button1_Click);
            // 
            // closecom
            // 
            this.closecom.Enabled = false;
            this.closecom.Location = new System.Drawing.Point(578, 270);
            this.closecom.Name = "closecom";
            this.closecom.Size = new System.Drawing.Size(75, 23);
            this.closecom.TabIndex = 1;
            this.closecom.Text = "关闭串口";
            this.closecom.UseVisualStyleBackColor = true;
            this.closecom.Click += new System.EventHandler(this.button2_Click);
            // 
            // comport
            // 
            this.comport.FormattingEnabled = true;
            this.comport.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.comport.Location = new System.Drawing.Point(532, 26);
            this.comport.Name = "comport";
            this.comport.Size = new System.Drawing.Size(121, 20);
            this.comport.TabIndex = 2;
            this.comport.Text = "COM1";
            this.comport.SelectedIndexChanged += new System.EventHandler(this.comboBox_SelectedIndexChanged);
            // 
            // baud
            // 
            this.baud.AutoCompleteCustomSource.AddRange(new string[] {
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "28800",
            "38400",
            "57600",
            "115200",
            "230400",
            "460800"});
            this.baud.FormattingEnabled = true;
            this.baud.Items.AddRange(new object[] {
            "1200",
            "2400",
            "4800",
            "9600",
            "14400",
            "19200",
            "28800",
            "38400",
            "57600",
            "115200"});
            this.baud.Location = new System.Drawing.Point(532, 52);
            this.baud.Name = "baud";
            this.baud.Size = new System.Drawing.Size(121, 20);
            this.baud.TabIndex = 3;
            this.baud.Text = "9600";
            this.baud.SelectedIndexChanged += new System.EventHandler(this.baud_SelectedIndexChanged);
            // 
            // COMlabel
            // 
            this.COMlabel.AutoSize = true;
            this.COMlabel.Location = new System.Drawing.Point(489, 29);
            this.COMlabel.Name = "COMlabel";
            this.COMlabel.Size = new System.Drawing.Size(35, 12);
            this.COMlabel.TabIndex = 4;
            this.COMlabel.Text = "COM口";
            // 
            // BAUDlabel
            // 
            this.BAUDlabel.AutoSize = true;
            this.BAUDlabel.Location = new System.Drawing.Point(485, 55);
            this.BAUDlabel.Name = "BAUDlabel";
            this.BAUDlabel.Size = new System.Drawing.Size(41, 12);
            this.BAUDlabel.TabIndex = 5;
            this.BAUDlabel.Text = "波特率";
            // 
            // textBox
            // 
            this.textBox.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.textBox.Location = new System.Drawing.Point(20, 28);
            this.textBox.Multiline = true;
            this.textBox.Name = "textBox";
            this.textBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox.Size = new System.Drawing.Size(436, 236);
            this.textBox.TabIndex = 6;
            this.textBox.TextChanged += new System.EventHandler(this.textBox_TextChanged_1);
            // 
            // TXlabel
            // 
            this.TXlabel.AutoSize = true;
            this.TXlabel.Location = new System.Drawing.Point(5, 14);
            this.TXlabel.Name = "TXlabel";
            this.TXlabel.Size = new System.Drawing.Size(53, 12);
            this.TXlabel.TabIndex = 7;
            this.TXlabel.Text = "发送格式";
            this.TXlabel.Click += new System.EventHandler(this.label3_Click);
            // 
            // RXlabel
            // 
            this.RXlabel.AutoSize = true;
            this.RXlabel.Location = new System.Drawing.Point(3, 5);
            this.RXlabel.Name = "RXlabel";
            this.RXlabel.Size = new System.Drawing.Size(53, 12);
            this.RXlabel.TabIndex = 8;
            this.RXlabel.Text = "接收格式";
            // 
            // txascmode
            // 
            this.txascmode.AutoSize = true;
            this.txascmode.Checked = true;
            this.txascmode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.txascmode.Location = new System.Drawing.Point(83, 12);
            this.txascmode.Name = "txascmode";
            this.txascmode.Size = new System.Drawing.Size(71, 16);
            this.txascmode.TabIndex = 9;
            this.txascmode.TabStop = true;
            this.txascmode.Text = "字符模式";
            this.txascmode.UseVisualStyleBackColor = true;
            this.txascmode.CheckedChanged += new System.EventHandler(this.txascmode_CheckedChanged);
            // 
            // txhexmode
            // 
            this.txhexmode.AutoSize = true;
            this.txhexmode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.txhexmode.Location = new System.Drawing.Point(83, 34);
            this.txhexmode.Name = "txhexmode";
            this.txhexmode.Size = new System.Drawing.Size(65, 16);
            this.txhexmode.TabIndex = 10;
            this.txhexmode.TabStop = true;
            this.txhexmode.Text = "HEX模式";
            this.txhexmode.UseVisualStyleBackColor = true;
            this.txhexmode.CheckedChanged += new System.EventHandler(this.txhexmode_CheckedChanged);
            // 
            // rxascmode
            // 
            this.rxascmode.AutoSize = true;
            this.rxascmode.Checked = true;
            this.rxascmode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rxascmode.Location = new System.Drawing.Point(83, 3);
            this.rxascmode.Name = "rxascmode";
            this.rxascmode.Size = new System.Drawing.Size(71, 16);
            this.rxascmode.TabIndex = 11;
            this.rxascmode.TabStop = true;
            this.rxascmode.Text = "字符模式";
            this.rxascmode.UseVisualStyleBackColor = true;
            this.rxascmode.CheckedChanged += new System.EventHandler(this.rxascmode_CheckedChanged);
            // 
            // rxhexmode
            // 
            this.rxhexmode.AutoSize = true;
            this.rxhexmode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rxhexmode.Location = new System.Drawing.Point(83, 25);
            this.rxhexmode.Name = "rxhexmode";
            this.rxhexmode.Size = new System.Drawing.Size(65, 16);
            this.rxhexmode.TabIndex = 12;
            this.rxhexmode.Text = "HEX模式";
            this.rxhexmode.UseVisualStyleBackColor = true;
            this.rxhexmode.CheckedChanged += new System.EventHandler(this.rxhexmode_CheckedChanged);
            // 
            // TXtextBox
            // 
            this.TXtextBox.AllowDrop = true;
            this.TXtextBox.Location = new System.Drawing.Point(20, 299);
            this.TXtextBox.Multiline = true;
            this.TXtextBox.Name = "TXtextBox";
            this.TXtextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.TXtextBox.Size = new System.Drawing.Size(436, 55);
            this.TXtextBox.TabIndex = 13;
            this.TXtextBox.TextChanged += new System.EventHandler(this.TXtextBox_TextChanged);
            // 
            // txdata
            // 
            this.txdata.Location = new System.Drawing.Point(485, 328);
            this.txdata.Name = "txdata";
            this.txdata.Size = new System.Drawing.Size(75, 26);
            this.txdata.TabIndex = 14;
            this.txdata.Text = "发送数据";
            this.txdata.UseVisualStyleBackColor = true;
            this.txdata.Click += new System.EventHandler(this.txdata_Click);
            // 
            // clearrxbutton
            // 
            this.clearrxbutton.Location = new System.Drawing.Point(485, 299);
            this.clearrxbutton.Name = "clearrxbutton";
            this.clearrxbutton.Size = new System.Drawing.Size(75, 23);
            this.clearrxbutton.TabIndex = 15;
            this.clearrxbutton.Text = "清空接收区";
            this.clearrxbutton.UseVisualStyleBackColor = true;
            this.clearrxbutton.Click += new System.EventHandler(this.clearrxbutton_Click);
            // 
            // cleartxbutton
            // 
            this.cleartxbutton.Location = new System.Drawing.Point(578, 299);
            this.cleartxbutton.Name = "cleartxbutton";
            this.cleartxbutton.Size = new System.Drawing.Size(75, 23);
            this.cleartxbutton.TabIndex = 16;
            this.cleartxbutton.Text = "清空发送区";
            this.cleartxbutton.UseVisualStyleBackColor = true;
            this.cleartxbutton.Click += new System.EventHandler(this.cleartxbutton_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.TXlabel);
            this.panel1.Controls.Add(this.txascmode);
            this.panel1.Controls.Add(this.txhexmode);
            this.panel1.Location = new System.Drawing.Point(485, 159);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(180, 53);
            this.panel1.TabIndex = 17;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // panel2
            // 
            this.panel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panel2.BackColor = System.Drawing.SystemColors.Control;
            this.panel2.Controls.Add(this.RXlabel);
            this.panel2.Controls.Add(this.rxascmode);
            this.panel2.Controls.Add(this.rxhexmode);
            this.panel2.ForeColor = System.Drawing.SystemColors.ControlText;
            this.panel2.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.panel2.Location = new System.Drawing.Point(485, 218);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(180, 46);
            this.panel2.TabIndex = 18;
            this.panel2.Paint += new System.Windows.Forms.PaintEventHandler(this.panel2_Paint);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(18, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 19;
            this.label1.Text = "数据接收区";
            // 
            // DataBitcomboBox
            // 
            this.DataBitcomboBox.FormattingEnabled = true;
            this.DataBitcomboBox.Items.AddRange(new object[] {
            "8",
            "7"});
            this.DataBitcomboBox.Location = new System.Drawing.Point(532, 78);
            this.DataBitcomboBox.Name = "DataBitcomboBox";
            this.DataBitcomboBox.Size = new System.Drawing.Size(121, 20);
            this.DataBitcomboBox.TabIndex = 20;
            this.DataBitcomboBox.Text = "8";
            this.DataBitcomboBox.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // DataBitlabel
            // 
            this.DataBitlabel.AutoSize = true;
            this.DataBitlabel.Location = new System.Drawing.Point(488, 81);
            this.DataBitlabel.Name = "DataBitlabel";
            this.DataBitlabel.Size = new System.Drawing.Size(41, 12);
            this.DataBitlabel.TabIndex = 21;
            this.DataBitlabel.Text = "数据位";
            // 
            // StopBitcomboBox
            // 
            this.StopBitcomboBox.FormattingEnabled = true;
            this.StopBitcomboBox.Items.AddRange(new object[] {
            "1",
            "2",
            "1.5"});
            this.StopBitcomboBox.Location = new System.Drawing.Point(532, 104);
            this.StopBitcomboBox.Name = "StopBitcomboBox";
            this.StopBitcomboBox.Size = new System.Drawing.Size(121, 20);
            this.StopBitcomboBox.TabIndex = 22;
            this.StopBitcomboBox.Text = "1";
            this.StopBitcomboBox.SelectedIndexChanged += new System.EventHandler(this.StopBitcomboBox_SelectedIndexChanged);
            // 
            // StopBitlabel
            // 
            this.StopBitlabel.AutoSize = true;
            this.StopBitlabel.Location = new System.Drawing.Point(489, 107);
            this.StopBitlabel.Name = "StopBitlabel";
            this.StopBitlabel.Size = new System.Drawing.Size(41, 12);
            this.StopBitlabel.TabIndex = 23;
            this.StopBitlabel.Text = "停止位";
            // 
            // ParitycomboBox
            // 
            this.ParitycomboBox.FormattingEnabled = true;
            this.ParitycomboBox.Items.AddRange(new object[] {
            "None",
            "Odd",
            "Even",
            "Mark",
            "Space"});
            this.ParitycomboBox.Location = new System.Drawing.Point(532, 130);
            this.ParitycomboBox.Name = "ParitycomboBox";
            this.ParitycomboBox.Size = new System.Drawing.Size(121, 20);
            this.ParitycomboBox.TabIndex = 24;
            this.ParitycomboBox.Text = "None";
            this.ParitycomboBox.SelectedIndexChanged += new System.EventHandler(this.ParitycomboBox_SelectedIndexChanged);
            // 
            // Paritylabel
            // 
            this.Paritylabel.AutoSize = true;
            this.Paritylabel.Location = new System.Drawing.Point(490, 133);
            this.Paritylabel.Name = "Paritylabel";
            this.Paritylabel.Size = new System.Drawing.Size(41, 12);
            this.Paritylabel.TabIndex = 25;
            this.Paritylabel.Text = "校验位";
            this.Paritylabel.Click += new System.EventHandler(this.Paritylabel_Click);
            // 
            // zuozhebutton1
            // 
            this.zuozhebutton1.Location = new System.Drawing.Point(578, 330);
            this.zuozhebutton1.Name = "zuozhebutton1";
            this.zuozhebutton1.Size = new System.Drawing.Size(75, 23);
            this.zuozhebutton1.TabIndex = 26;
            this.zuozhebutton1.Text = "关于";
            this.zuozhebutton1.UseVisualStyleBackColor = true;
            this.zuozhebutton1.Click += new System.EventHandler(this.zuozhebutton1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 284);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(65, 12);
            this.label2.TabIndex = 27;
            this.label2.Text = "数据发送区";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // Usart
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.AutoScroll = true;
            this.AutoSize = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.AutoValidate = System.Windows.Forms.AutoValidate.Disable;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(705, 370);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comport);
            this.Controls.Add(this.zuozhebutton1);
            this.Controls.Add(this.Paritylabel);
            this.Controls.Add(this.ParitycomboBox);
            this.Controls.Add(this.StopBitlabel);
            this.Controls.Add(this.StopBitcomboBox);
            this.Controls.Add(this.DataBitlabel);
            this.Controls.Add(this.DataBitcomboBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.cleartxbutton);
            this.Controls.Add(this.clearrxbutton);
            this.Controls.Add(this.txdata);
            this.Controls.Add(this.TXtextBox);
            this.Controls.Add(this.textBox);
            this.Controls.Add(this.BAUDlabel);
            this.Controls.Add(this.COMlabel);
            this.Controls.Add(this.baud);
            this.Controls.Add(this.closecom);
            this.Controls.Add(this.opencom);
            this.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.HelpButton = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "Usart";
            this.Text = "Serial Assistant By 547336083 ";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button opencom;
        private System.Windows.Forms.Button closecom;
        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.ComboBox baud;
        private System.Windows.Forms.Label COMlabel;
        private System.Windows.Forms.Label BAUDlabel;
        private System.Windows.Forms.TextBox textBox;
        private System.Windows.Forms.Label TXlabel;
        private System.Windows.Forms.Label RXlabel;
        private System.Windows.Forms.RadioButton txascmode;
        private System.Windows.Forms.RadioButton txhexmode;
        private System.Windows.Forms.RadioButton rxascmode;
        private System.Windows.Forms.RadioButton rxhexmode;
        private System.Windows.Forms.TextBox TXtextBox;
        private System.Windows.Forms.Button txdata;
        private System.Windows.Forms.Button clearrxbutton;
        private System.Windows.Forms.Button cleartxbutton;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox DataBitcomboBox;
        private System.Windows.Forms.Label DataBitlabel;
        private System.Windows.Forms.ComboBox StopBitcomboBox;
        private System.Windows.Forms.Label StopBitlabel;
        private System.Windows.Forms.ComboBox ParitycomboBox;
        private System.Windows.Forms.Label Paritylabel;
        private System.Windows.Forms.Button zuozhebutton1;
        private System.Windows.Forms.ComboBox comport;
        private System.Windows.Forms.Label label2;
    }
}

