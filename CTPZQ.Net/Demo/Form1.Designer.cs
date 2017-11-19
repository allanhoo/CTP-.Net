namespace Demo
{
    partial class Form1
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
            this.button1 = new System.Windows.Forms.Button();
            this.btnRelease = new System.Windows.Forms.Button();
            this.btnSubInst = new System.Windows.Forms.Button();
            this.btnTrader = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(381, 29);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Connect";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnRelease
            // 
            this.btnRelease.Location = new System.Drawing.Point(381, 151);
            this.btnRelease.Name = "btnRelease";
            this.btnRelease.Size = new System.Drawing.Size(75, 23);
            this.btnRelease.TabIndex = 1;
            this.btnRelease.Text = "Release";
            this.btnRelease.UseVisualStyleBackColor = true;
            this.btnRelease.Click += new System.EventHandler(this.btnRelease_Click);
            // 
            // btnSubInst
            // 
            this.btnSubInst.Location = new System.Drawing.Point(381, 87);
            this.btnSubInst.Name = "btnSubInst";
            this.btnSubInst.Size = new System.Drawing.Size(75, 23);
            this.btnSubInst.TabIndex = 2;
            this.btnSubInst.Text = "SubInst";
            this.btnSubInst.UseVisualStyleBackColor = true;
            this.btnSubInst.Click += new System.EventHandler(this.btnSubInst_Click);
            // 
            // btnTrader
            // 
            this.btnTrader.Location = new System.Drawing.Point(12, 29);
            this.btnTrader.Name = "btnTrader";
            this.btnTrader.Size = new System.Drawing.Size(118, 23);
            this.btnTrader.TabIndex = 3;
            this.btnTrader.Text = "交易接口测试";
            this.btnTrader.UseVisualStyleBackColor = true;
            this.btnTrader.Click += new System.EventHandler(this.btnTrader_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(526, 235);
            this.Controls.Add(this.btnTrader);
            this.Controls.Add(this.btnSubInst);
            this.Controls.Add(this.btnRelease);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button btnRelease;
        private System.Windows.Forms.Button btnSubInst;
        private System.Windows.Forms.Button btnTrader;
    }
}

