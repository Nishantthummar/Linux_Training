				//////////////TCP Server/////////
///////////////////////////////////////////////////////////////////////////////
//This is code of TCP server which accept data from client by 1kB string and
//convert it into upper case than transmitt at again to client side
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 1024

FILE *fp;
int check(); // Function to convert upper case

int main(int argc, char *argv[]) 
{
	fflush(stdin);
	fflush(stdout);
	///////////////////////////////////////////////////////////////////////
	//variables for store socket id, types of protocol, method of 
	//transmission
	///////////////////////////////////////////////////////////////////////
	int sockfd;
	struct sockaddr_in serverAddr;
	int i_loop;
	socklen_t  addr_size;
	int newsocket;
	struct sockaddr_in newAddr;
	char c_buf[MAX];
	char c_send_c_msg[MAX];
	char c_msg[100];
	pid_t pid;

	if(argc < 3) {
		printf("\nEnter valid arguments\n\tExample => ./file PORT IP_address \n");
		exit(1);
	}
	int port;
	port= atoi(argv[1]);
	printf("\nListening at Port number is %d", port);

	sockfd = socket(PF_INET, SOCK_STREAM, 0); // created new socket
	serverAddr.sin_family = AF_INET; // type of transmission
	serverAddr.sin_port = htons(port); // port number where server listen
	serverAddr.sin_addr.s_addr = inet_addr(argv[2]);	
	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); // bind the socket

	int a;
	a=listen(sockfd, 5); // listen request from client at time 5
	addr_size = sizeof(newAddr);
	pid = fork();
	newsocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size); // accept connection request
	strcpy(c_msg, "Connected");
	int sflag;
	sflag =	send(newsocket, c_msg, strlen(c_msg), 0); // Send acknowledgment 
	
	/*********************************************//*
	*Receive from client
	************************************************/
	int flag, count, exit;
	while(recv(newsocket, c_buf, MAX, 0) != 0){
		printf("\nReceiving data...");	
		exit = check(c_buf, c_send_c_msg); // if particular sign is found then exit from loop
		flag = send(newsocket, c_send_c_msg, MAX, 0); // send converted data
		printf("\nSending data...");
	} //end while
	/***********************************************/
	close(sockfd); // close connection
	close(newsocket);
	printf("\nfinish");
	bzero(c_send_c_msg, MAX);
	bzero(c_buf, MAX);
	return 0;
	

}


/***************************************************************************//*
*function for check end file
*@paramin char from[] source array
*@paramin char to[] destination array
******************************************************************************/
int check(char from[], char to[] ) {
	int i_loop;
	for(i_loop=0; i_loop< MAX; i_loop++) {
		if(from[i_loop] == '$') {
			return -1;
		}
		to[i_loop] = toupper(from[i_loop]);
		//printf("%c", to[i_loop]);
	}
	return 0;
}

/***************************************************************************//*
*				END
******************************************************************************/
