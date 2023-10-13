namespace serverTest1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button1 = new Button();
            textBox = new RichTextBox();
            textBox1 = new TextBox();
            button2 = new Button();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Location = new Point(12, 344);
            button1.Name = "button1";
            button1.Size = new Size(776, 23);
            button1.TabIndex = 0;
            button1.Text = "Listen";
            button1.UseVisualStyleBackColor = true;
            button1.Click += clientListen;
            // 
            // textBox
            // 
            textBox.Location = new Point(12, 12);
            textBox.Name = "textBox";
            textBox.Size = new Size(776, 312);
            textBox.TabIndex = 1;
            textBox.Text = "";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(15, 387);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(620, 23);
            textBox1.TabIndex = 2;
            // 
            // button2
            // 
            button2.Location = new Point(666, 387);
            button2.Name = "button2";
            button2.Size = new Size(122, 23);
            button2.TabIndex = 3;
            button2.Text = "SendtoClient";
            button2.UseVisualStyleBackColor = true;
            button2.Click += sendTextTo;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button2);
            Controls.Add(textBox1);
            Controls.Add(textBox);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Server";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private RichTextBox textBox;
        private TextBox textBox1;
        private Button button2;
    }
}