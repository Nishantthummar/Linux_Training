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
	int a = pipe(i_fd);
	int pid = fork();
	if(pid == 0) {

		//child process (write)
		printf("\nEnter msg to child : ");
		fgets (c_send, MAX, stdin);
		write(i_fd[1], c_send, MAX);
	} else {

		// perent process (read)
		wait(&i_pid); // wait for finish child process
		read(i_fd[0], c_recv, MAX);
		printf("\nFrom child Msg.: %s", c_recv);

	}
}


