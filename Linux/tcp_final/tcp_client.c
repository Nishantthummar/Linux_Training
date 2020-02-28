						/////TCP_Client Code//////
///////////////////////////////////////////////////////////////////////////////
//This is code of TCP Client which send data to the server by 1kB string and
//receive the converted data back from server
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 1024
#define MAXI 1000000

int main(int argc, char *argv[])
{	
	if(argc <3) {
		printf("\nEnter valid argument");
		exit(1);
	}
	int port= atoi(argv[1]);
	printf("\nport no is %d",port);
	printf("\nIP is %s", argv[2]);
	

	fflush(stdin);
	fflush(stdout);
	///////////////////////////////////////////////////////////////////////
	//variables for store socket id, types of protocol, method of 
	//transmission
	///////////////////////////////////////////////////////////////////////
	int clientSocket, serverSocket;
	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;
	socklen_t addr_size;
	char c_receiv[100];
	char c_buf[MAXI];
	char c_fbuf[MAX];
	FILE *fin, *fout;
	char c_data;
	int i_ar=0;

	clientSocket = socket(PF_INET, SOCK_STREAM, 0); // create new socket
	if(clientSocket < 0) {
		printf("\nError creating socket");
		clientSocket = socket(PF_INET, SOCK_STREAM, 0);
	}
	serverAddr.sin_family = AF_INET; // types of transmission
	serverAddr.sin_port = htons(port); // port number
	serverAddr.sin_addr.s_addr = inet_addr(argv[2]); // ip address

	addr_size = sizeof(serverAddr);
	// connect to server with specify parameter
	if(connect(clientSocket, (struct sockaddr*)&serverAddr, addr_size) < 0) {
		printf("\nConnection failed");
		exit(1);
	}
	
	int flag;
	flag = recv(clientSocket, c_receiv, 9, 0); // receive acknowlegment from server
	if(flag < 0) {
		printf("\nnot receive any response from server");
		exit(1);
	}

	fin = fopen("input.txt", "r"); // open input file for readonly
	fout = fopen("output.txt", "w+"); // open output file for write
	// to check if input file is opened or not
	if(fin == NULL) {
		printf("\nfile is not open");
		exit(1);
	}

	int size; // to store size of input file
	c_data = fgetc(fin); // get character from file
	// get each from file and check EOf condition
	while(c_data != EOF) {
		c_fbuf[i_ar] = c_data;
		c_data = fgetc(fin);
		if(i_ar == MAX-1) { // to check array full or not
			flag = send(clientSocket, c_fbuf, MAX, 0); // send 1024 kB data	
			if(flag < 0) {
				printf("\nunable to send any data");
				exit(1);
			}
			flag = recv(clientSocket, c_buf, MAX, 0); //new
			fputs(c_buf, fout);
			bzero(c_fbuf, MAX); // to clear fbuf array with zero or NULL
			i_ar=-1;
		} // endif 
	i_ar++;
	} //end while
	flag = send(clientSocket, c_fbuf, MAX, 0); // send remaining data which is not equal to 1024 kB
	if(flag < 0) {
		printf("\nunable to send remaining  data");
		exit(1);
	}
	fclose(fin);
	bzero(c_buf, MAX);
	flag = recv(clientSocket, c_buf, MAX, 0); // receive remaining data
	close(serverSocket);
	close(clientSocket);
	fputs(c_buf, fout);
	fclose(fout);
	return 0;
}
/***************************************************************************/
//				END
/***************************************************************************/


