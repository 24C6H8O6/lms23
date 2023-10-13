using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace ClientTest1
{
    public partial class client
    {
        public event Action<string> receiveData_C;
        public Socket clientSocket;
        private string sendText;
        public async Task connectServer(string serverIP)
        {
            clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            // string serverIP = "10.10.21.116";
            try
            {
                await clientSocket.ConnectAsync(new IPEndPoint(IPAddress.Parse(serverIP), 8080));
                if (clientSocket.Connected)
                {
                    receiveData_C?.Invoke("서버 연결 성공!");
                    await serverAsync(clientSocket);
                }
                else
                {
                    receiveData_C?.Invoke("서버 연결 실패!");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error1 : {ex.Message}\n");
            }
        }

        public async Task serverAsync(Socket clientSocket)
        {
            try
            {
                await receiveAsync(clientSocket);
            }
            catch (Exception ex)
            {
                receiveData_C?.Invoke($"Error2 : {ex.Message}");
            }
            finally
            {
                if (clientSocket != null)
                {
                    clientSocket.Close();
                }
            }
        }

        public async Task sendAsync(Socket clientSocket, string sendText)
        {

            byte[] data = Encoding.UTF8.GetBytes(sendText);
            await clientSocket.SendAsync(data, SocketFlags.None);
        }

        public async Task receiveAsync(Socket clientSocket)
        {
            byte[] buffer = new byte[1024];
            while (true)
            {
                
                int bytesRead = await clientSocket.ReceiveAsync(buffer, SocketFlags.None);
                // 데이터를 받지 않은 경우 루프 종료
                if (bytesRead == 0)
                {
                    break;
                }


                string res = Encoding.UTF8.GetString(buffer, 0, bytesRead);
                if (!string.IsNullOrEmpty(res))
                {
                    Console.WriteLine($"서버로부터 받은 데이터: {res}");
                    // ?. : 조건부 연산자
                    // 왼쪽 피연산자가 null이 아닐 경우에 오른쪽 연산자 실행
                    //
                    // Invoke : 등록된 대리자 또는 이벤트 호출
                    receiveData_C?.Invoke(res);
                }
                else
                {
                    Console.WriteLine("받은 데이터가 null 또는 빈 문자열입니다.");
                }
            }
        }
    }
}
