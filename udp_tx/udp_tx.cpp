#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")

int main(void)
{
	WSAData wsaData;

	SOCKET sock;
	struct sockaddr_in addr;

	WSAStartup(MAKEWORD(2, 0), &wsaData);

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	char ch;
	while (1) {
		ch = getchar();
		sendto(sock, &ch, 1, 0, (struct sockaddr *)&addr, sizeof(addr));
		if (ch == EOF) break;

//		sendto(sock, "HELLO", 5, 0, (struct sockaddr *)&addr, sizeof(addr));

	}


	closesocket(sock);

	WSACleanup();

	return 0;
}

