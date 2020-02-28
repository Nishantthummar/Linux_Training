#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t child_pid;

	child_pid = fork();
	if(child_pid > 0) {
		wait();
		sleep(60);
	}
	else {
		exit(0);
	}
	return 0;
}
