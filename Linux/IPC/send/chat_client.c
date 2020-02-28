#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024
int main(int argc, char *argv[]) 
{

	if(argc < 2) {
		printf("\nEnter your name ");
		exit(1);
	}
	int sockfd;
	int clientSocket, serverSocket;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	socklen_t addr_size;
	char c_receive[MAX];
	char c_send[MAX];
	char name[MAX];
	clientSocket = socket(PF_INET, SOCK_STREAM, 0); // create new socket	
	if(clientSocket < 0) {
		printf("\nError creating socket");
		clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	}
	serverAddr.sin_family = AF_INET; // types of transmission
	serverAddr.sin_port = htons(8080); // port number
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip address

	addr_size = sizeof(serverAddr);
	// connect to server with specify parameter
	if(connect(clientSocket, (struct sockaddr*)&serverAddr, addr_size) < 0) {
		printf("\nConnection failed");
		exit(1);
	}
	read(clientSocket, name, MAX); // receive name of server
	printf("\nconnected with %s", name);	
	write(clientSocket, argv[1], strlen(argv[1])); // send name of client

	while(1) {
	int flag;
			do {
			printf("\nMe:");
		        bzero(c_send, MAX);
			fgets(c_send, MAX, stdin);
			flag = write(clientSocket, c_send, MAX);	
			if(flag<0) {
        	        	         printf("\nnot send any data");
                	        	 exit(1);
				}
			
			}while(read(clientSocket, c_receive, MAX) ==0);
			char temp[MAX] = "";
			write(clientSocket, temp, strlen(temp)); 
			fputs(c_receive, stdout);
	}
}	
