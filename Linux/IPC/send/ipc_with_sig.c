#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char c_send[MAX];
int i_fd[2];
void handler(int sig_num);
int main() {
		signal(SIGUSR1, handler);
		char c_recv[MAX];
		int p = pipe(i_fd);
		int pid = fork();

		if(pid == 0) {
			//child process
			printf("\nEnter msg to child : ");
			int i=0;
			do{
			c_send[i] = fgetc(stdin);
			i++;
			}while(i != MAX);
			raise(SIGUSR1);

		
		} else {
			//parent process
			read(i_fd[0], c_recv, MAX); //read from pipe
			printf("\nFrom child msg is %s", c_recv);
		}
		return 0;
}

void handler(int sig_num ) {
	printf("\nsending data to the parent process");
	write(i_fd[1], c_send, MAX); // write into pipe
	
	exit(1);
}

