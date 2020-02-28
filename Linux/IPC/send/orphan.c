#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
	int pid;
	pid = fork();

	if(pid == 0) {
		//child process
		printf("\nThis is child process ");
		printf("\npid is %d, \nppid is %d", getpid(), getppid());
		sleep(10);
		printf("\nThis is orphan child process ");
		printf("\npid is %d, \nppid is %d", getpid(), getppid());


	}
	else if(pid >0 ) {
		//parent process
		printf("\nThis is parent process ");
		printf("\npid is %d, \nppid is %d", getpid(), getppid());
	}
	else {
		printf("\nunable to create child process");
	}
	return 0;
}




