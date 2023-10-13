using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace ClientTest1
{
    public partial class Form1 : Form
    {
        client Client = new client();
        private string sendText;
        public Form1()
        {
            InitializeComponent();
            Client.receiveData_C += execute_receiveDataC;
        }

        private void connectToServer(object sender, EventArgs e)
        {
            string serverIP = textBox1.Text;
            Client.connectServer(serverIP);
        }

        private void sendToServer(object sender, EventArgs e)
        {
            sendText = textBox2.Text;
            Client.sendAsync(Client.clientSocket, sendText);
            // MessageBox.Show($"서버로 : {sendText}");
        }

        private void AppendTextToTextBox(string text)
        {
            textBox.AppendText(text);
        }

        // 이벤트에 대한 핸들러
        private void execute_receiveDataC(string data)
        {
            textBox.AppendText(data + "\n");
        }

    }
}