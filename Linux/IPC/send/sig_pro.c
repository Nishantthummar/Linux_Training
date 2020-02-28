#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void sigint();
void sigusr1();
int main() {
	int pid = fork();
	if(pid == 0) {
		//child process
	signal(SIGUSR1, sigusr1);
		while(1) {
	signal(SIGINT,sigint);
			sleep(1);
			printf(" * ");
		}
	} else {
		//parent process
	//	wait(NULL);
		sleep(10);
		//printf("\ncalling user1 signal"); 
		kill(pid, SIGINT);
		kill(pid, SIGINT);
		kill(pid, SIGINT);
		kill(pid, SIGUSR1);
	}
}

void sigint() {
	printf("\nnot working this key");
}

void sigusr1() {
	printf("\nkill the child process ");
	exit(1);
}



