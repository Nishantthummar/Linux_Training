#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX 100
int main() {
	pid_t i_pid;
	int i_fd[2];
	char c_send[MAX];
	char c_recv[MAX];
	//int a = pipe(i_fd);

	i_pid=fork();
	int a;
	if(i_pid < 0) {
		//child process
		printf("\nEnter to child:");
		scanf("%s", c_send);
		write(i_fd[1], c_send, strlen(c_send));

	} else {
		// perent process
		wait(&i_pid); // wait for finish child process
		read(i_fd[0], c_recv, MAX);
		printf("\nFrom child msg: %s", c_recv);
		

	}
	
}
		


