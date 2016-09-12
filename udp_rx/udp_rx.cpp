#include <stdio.h>
#include <winsock2.h>


#pragma comment(lib,"wsock32.lib")

int main(void)
{
	WSAData wsaData;

	SOCKET sock;
	struct sockaddr_in addr;

	char buf[2048];

	WSAStartup(MAKEWORD(2, 0), &wsaData);

	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(sock, (struct sockaddr *)&addr, sizeof(addr));


	while (1) {
		memset(buf, 0, sizeof(buf));
		recv(sock, buf, sizeof(buf), 0);
		if (buf[0] == EOF) break;

		printf("%s", buf);
	}

	closesocket(sock);

	WSACleanup();

	return 0;
}


