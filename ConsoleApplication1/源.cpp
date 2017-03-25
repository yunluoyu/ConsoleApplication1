# include <iostream>
# include <winsock2.h>
# pragma comment (lib,"ws2_32.lib")
using namespace std;

int main()
{
	WSADATA ws;
	WSAStartup(0x0202,&ws);

	SOCKET sock = socket(AF_INET,SOCK_DGRAM,0);

	sockaddr_in sa = {2};
	sa.sin_addr.S_un.S_addr = 0;
	sa.sin_port = 0;
	bind(sock,(sockaddr*)&sa,sizeof(sa));

	char s[1024];

	sockaddr_in to = {2};
	to.sin_addr.S_un.S_addr = inet_addr("172.19.216.88");
	to.sin_port = htons(55555);
	while (true)
	{
		cin >> s;
		sendto(sock,s,strlen(s),0,(sockaddr*)&to,sizeof(to));
	}
	return 0;
}