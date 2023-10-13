using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace serverTest1
{
    public partial class Form1 : Form
    {
        server Server = new server();
        private string sendText;
        public Form1()
        {
            InitializeComponent();
            Server.receiveData_S += execute_receiveDataS;
        }

        // 버튼 1
        private async void clientListen(object sender, EventArgs e)
        {
            await Server.readyListen();
            textBox.AppendText("서버시작\n");
            await Server.clientAccept();
        }

        // 버튼 2
        private async void sendTextTo(object sender, EventArgs e)
        {
            if (Server.client == null || !Server.client.Connected)
            {
                textBox.AppendText("클라이언트가 연결되어 있지 않습니다.\n");
                return;
            }


            sendText = "서버 : " + textBox1.Text;
            await Server.sendAsync(Server.client, sendText);
            textBox.AppendText("클라이언트로 전송 성공!\n");
        }

        private void execute_receiveDataS(string data)
        {
            textBox.AppendText(data + "\n");
        }
    }
}