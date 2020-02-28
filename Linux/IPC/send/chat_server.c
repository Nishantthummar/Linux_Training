///////////////////////////////////////////////////////////////////////////////
//					Server
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#define MAX 1024

int main(int argc, char *argv[])
{
	
	if(argc < 2) {
		printf("\nEnter your name ");
		exit(1);
	}
	fflush(stdin);
	fflush(stdout);
	int sockfd;
	struct sockaddr_in serverAddr;
	socklen_t  addr_size;        
	int newsocket;
        struct sockaddr_in newAddr;
	char c_send_data[MAX];
	char c_my_data[MAX];
	char c_name[MAX];
	int flag;
	int pid = fork();	
	 sockfd = socket(PF_INET, SOCK_STREAM, 0); // to create new socket

	 serverAddr.sin_family = AF_INET;
	 serverAddr.sin_port = htons(8080);
         serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
         bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); // bind the socket
	 int a;
         a=listen(sockfd, 5); // listen request from client at time 5
	 addr_size = sizeof(newAddr);
    	 newsocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size); // accept connection request
	 write(newsocket, argv[1], strlen(argv[1])); // send name of server
	 read(newsocket, c_name, MAX); // receive name of client
	 printf("\nConnected with %s", c_name);
	//int pid = fork();	
	 while(1) {
			do {
		 	printf("\nMe: ");
			fgets(c_my_data, MAX, stdin);
			a  = write(newsocket, c_my_data, strlen(c_my_data));
			if (a < 0) {
				printf("\nerror while writing");
				}
			}while(read(newsocket, c_my_data, MAX) ==0);
			char temp[MAX] ="";
			write(newsocket, temp, strlen(temp));
			fputs(c_my_data, stdout);
	}
//	 interrupt();
	 close(newsocket);
	 close(sockfd);
}
