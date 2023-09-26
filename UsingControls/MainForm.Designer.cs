namespace UsingControls
{
    partial class MainForm
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
            grpFont = new GroupBox();
            txtSampleText = new TextBox();
            chkItalic = new CheckBox();
            chkBold = new CheckBox();
            cboFont = new ComboBox();
            lblFont = new Label();
            grpBar = new GroupBox();
            pgDummy = new ProgressBar();
            tbDummy = new TrackBar();
            grpForm = new GroupBox();
            btnMsgBox = new Button();
            btnModaless = new Button();
            btnModal = new Button();
            grpTreeList = new GroupBox();
            btnAddChild = new Button();
            btnAddRoot = new Button();
            lvDummy = new ListView();
            tvDummy = new TreeView();
            grpFont.SuspendLayout();
            grpBar.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)tbDummy).BeginInit();
            grpForm.SuspendLayout();
            grpTreeList.SuspendLayout();
            SuspendLayout();
            // 
            // grpFont
            // 
            grpFont.Controls.Add(txtSampleText);
            grpFont.Controls.Add(chkItalic);
            grpFont.Controls.Add(chkBold);
            grpFont.Controls.Add(cboFont);
            grpFont.Controls.Add(lblFont);
            grpFont.Location = new Point(34, 30);
            grpFont.Name = "grpFont";
            grpFont.Size = new Size(491, 124);
            grpFont.TabIndex = 0;
            grpFont.TabStop = false;
            grpFont.Text = "ComboBox, CheckBox, TextBox";
            grpFont.Enter += groupBox1_Enter;
            // 
            // txtSampleText
            // 
            txtSampleText.Location = new Point(33, 82);
            txtSampleText.Name = "txtSampleText";
            txtSampleText.Size = new Size(408, 23);
            txtSampleText.TabIndex = 3;
            txtSampleText.Text = "Hello, C#";
            // 
            // chkItalic
            // 
            chkItalic.AutoSize = true;
            chkItalic.Location = new Point(379, 43);
            chkItalic.Name = "chkItalic";
            chkItalic.Size = new Size(62, 19);
            chkItalic.TabIndex = 2;
            chkItalic.Text = "이탤릭";
            chkItalic.UseVisualStyleBackColor = true;
            chkItalic.CheckedChanged += chkItalic_CheckedChanged;
            // 
            // chkBold
            // 
            chkBold.AutoSize = true;
            chkBold.Location = new Point(260, 44);
            chkBold.Name = "chkBold";
            chkBold.Size = new Size(50, 19);
            chkBold.TabIndex = 2;
            chkBold.Text = "굵게";
            chkBold.UseVisualStyleBackColor = true;
            chkBold.CheckedChanged += chkBold_CheckedChanged;
            // 
            // cboFont
            // 
            cboFont.FormattingEnabled = true;
            cboFont.Location = new Point(104, 40);
            cboFont.Name = "cboFont";
            cboFont.Size = new Size(121, 23);
            cboFont.TabIndex = 1;
            cboFont.SelectedIndexChanged += cboFont_SelectedIndexChanged;
            // 
            // lblFont
            // 
            lblFont.AutoSize = true;
            lblFont.Location = new Point(33, 43);
            lblFont.Name = "lblFont";
            lblFont.Size = new Size(31, 15);
            lblFont.TabIndex = 0;
            lblFont.Text = "Font";
            lblFont.Click += label1_Click;
            // 
            // grpBar
            // 
            grpBar.Controls.Add(pgDummy);
            grpBar.Controls.Add(tbDummy);
            grpBar.Location = new Point(34, 160);
            grpBar.Name = "grpBar";
            grpBar.Size = new Size(491, 143);
            grpBar.TabIndex = 1;
            grpBar.TabStop = false;
            grpBar.Text = "TrackBar && ProgressBar";
            // 
            // pgDummy
            // 
            pgDummy.Location = new Point(45, 89);
            pgDummy.Maximum = 20;
            pgDummy.Name = "pgDummy";
            pgDummy.Size = new Size(425, 26);
            pgDummy.TabIndex = 1;
            // 
            // tbDummy
            // 
            tbDummy.Location = new Point(45, 38);
            tbDummy.Maximum = 20;
            tbDummy.Name = "tbDummy";
            tbDummy.Size = new Size(425, 45);
            tbDummy.TabIndex = 0;
            tbDummy.Scroll += tbDummy_Scroll;
            // 
            // grpForm
            // 
            grpForm.Controls.Add(btnMsgBox);
            grpForm.Controls.Add(btnModaless);
            grpForm.Controls.Add(btnModal);
            grpForm.Location = new Point(34, 318);
            grpForm.Name = "grpForm";
            grpForm.Size = new Size(491, 84);
            grpForm.TabIndex = 2;
            grpForm.TabStop = false;
            grpForm.Text = "Modal && Modaless";
            // 
            // btnMsgBox
            // 
            btnMsgBox.Location = new Point(296, 32);
            btnMsgBox.Name = "btnMsgBox";
            btnMsgBox.Size = new Size(164, 33);
            btnMsgBox.TabIndex = 0;
            btnMsgBox.Text = "MessageBox";
            btnMsgBox.UseVisualStyleBackColor = true;
            btnMsgBox.Click += btnMsgBox_Click;
            // 
            // btnModaless
            // 
            btnModaless.Location = new Point(161, 32);
            btnModaless.Name = "btnModaless";
            btnModaless.Size = new Size(113, 33);
            btnModaless.TabIndex = 0;
            btnModaless.Text = "Modaless";
            btnModaless.UseVisualStyleBackColor = true;
            btnModaless.Click += btnModaless_Click;
            // 
            // btnModal
            // 
            btnModal.Location = new Point(33, 32);
            btnModal.Name = "btnModal";
            btnModal.Size = new Size(104, 33);
            btnModal.TabIndex = 0;
            btnModal.Text = "Modal";
            btnModal.UseVisualStyleBackColor = true;
            btnModal.Click += btnModal_Click;
            // 
            // grpTreeList
            // 
            grpTreeList.Controls.Add(btnAddChild);
            grpTreeList.Controls.Add(btnAddRoot);
            grpTreeList.Controls.Add(lvDummy);
            grpTreeList.Controls.Add(tvDummy);
            grpTreeList.Location = new Point(34, 418);
            grpTreeList.Name = "grpTreeList";
            grpTreeList.Size = new Size(491, 210);
            grpTreeList.TabIndex = 3;
            grpTreeList.TabStop = false;
            grpTreeList.Text = "TreeView && ListView";
            // 
            // btnAddChild
            // 
            btnAddChild.Location = new Point(183, 167);
            btnAddChild.Name = "btnAddChild";
            btnAddChild.Size = new Size(127, 26);
            btnAddChild.TabIndex = 2;
            btnAddChild.Text = "자식 추가";
            btnAddChild.UseVisualStyleBackColor = true;
            btnAddChild.Click += btnAddChild_Click;
            // 
            // btnAddRoot
            // 
            btnAddRoot.Location = new Point(31, 167);
            btnAddRoot.Name = "btnAddRoot";
            btnAddRoot.Size = new Size(127, 26);
            btnAddRoot.TabIndex = 2;
            btnAddRoot.Text = "루트 추가";
            btnAddRoot.UseVisualStyleBackColor = true;
            btnAddRoot.Click += btnAddRoot_Click;
            // 
            // lvDummy
            // 
            lvDummy.Location = new Point(258, 40);
            lvDummy.Name = "lvDummy";
            lvDummy.Size = new Size(212, 111);
            lvDummy.TabIndex = 1;
            lvDummy.UseCompatibleStateImageBehavior = false;
            lvDummy.View = View.Details;
            // 
            // tvDummy
            // 
            tvDummy.Location = new Point(29, 37);
            tvDummy.Name = "tvDummy";
            tvDummy.Size = new Size(207, 114);
            tvDummy.TabIndex = 0;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(609, 652);
            Controls.Add(grpTreeList);
            Controls.Add(grpForm);
            Controls.Add(grpBar);
            Controls.Add(grpFont);
            Name = "MainForm";
            Text = "Control Test";
            Load += Form1_Load;
            grpFont.ResumeLayout(false);
            grpFont.PerformLayout();
            grpBar.ResumeLayout(false);
            grpBar.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)tbDummy).EndInit();
            grpForm.ResumeLayout(false);
            grpTreeList.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion

        private GroupBox grpFont;
        private Label lblFont;
        private CheckBox chkItalic;
        private CheckBox chkBold;
        private ComboBox cboFont;
        private TextBox txtSampleText;
        private GroupBox grpBar;
        private TrackBar tbDummy;
        private ProgressBar pgDummy;
        private GroupBox grpForm;
        private Button btnMsgBox;
        private Button btnModaless;
        private Button btnModal;
        private GroupBox grpTreeList;
        private Button btnAddChild;
        private Button btnAddRoot;
        private ListView lvDummy;
        private TreeView tvDummy;
    }
}