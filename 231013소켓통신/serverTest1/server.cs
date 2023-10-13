using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace serverTest1
{
    public partial class server
    {
        private Dictionary<Socket, string> clientIPs = new Dictionary<Socket, string>();
        // private List<Socket> socketList = new List<Socket>();
        // private List<string> IPList = new List<string>();
        public event Action<string> receiveData_S;
        public Socket client;
        // public string client_IP;
        private byte[] receiveBuffer = new byte[1024];
        private string sendText;
        private Socket socket;
        private string receiveText;

        public async Task readyListen()
        {
            // First
            socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, 8080);
            socket.Bind(endPoint);
            socket.Listen(10);
        }

        public async Task clientAccept()
        {
            // Second
            while (true)
            {
                client = await socket.AcceptAsync();
                IPEndPoint clientIP = (IPEndPoint)client.RemoteEndPoint;
                string client_IP = $"{clientIP.Address}:{clientIP.Port}";
                receiveData_S?.Invoke($"{client_IP} 연결 성공!");
                clientIPs[client] = client_IP;
                // 연결된 클라이언트에게 환영 메시지 전송
                sendAsync(client, $"환영합니다, {client_IP}!");

                Task.Run(() => receiveAsync(client, client_IP));
                // await clientAsync(client);
            }
        }

        public async Task receiveAsync(Socket client, string client_IP)
        {
            byte[] buffer = new byte[1024];
            while (true)
            {
                int bytesRead = await client.ReceiveAsync(buffer);
                // 데이터를 받지 않은 경우 루프 종료
                if (bytesRead == 0)
                {
                    break;
                }


                string data = Encoding.UTF8.GetString(buffer, 0, bytesRead);

                if (!string.IsNullOrEmpty(data))
                {
                    Console.WriteLine($"서버로부터 받은 데이터: {data}");
                    // MessageBox.Show($"서버로부터 받은 데이터: {data}");
                    string cl_ip_data = $"{client_IP} - {data}";

                    receiveData_S?.Invoke(cl_ip_data);
                    sendToAll(client_IP, data);
                }
                else
                {
                    Console.WriteLine("받은 데이터가 null 또는 빈 문자열입니다.");
                }
            }
        }

        public async Task sendAsync(Socket client, string sendText)
        {
            byte[] data = Encoding.UTF8.GetBytes(sendText);
            await client.SendAsync(data, SocketFlags.None);
        }
        public async Task sendToAll(string client_IP, string message)
        {
            foreach (var clientSocket in clientIPs)
            {
                Socket socket = clientSocket.Key; // Socket에 접근
                string clientIP = clientSocket.Value; // IP 주소에 접근
                if (socket.Connected)
                {
                    string fullMessage = $"{client_IP} - {message}";
                    await sendAsync(socket, fullMessage);
                }
            }
        }
    }
}
