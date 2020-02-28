#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void handler();
int main() {
	signal(SIGINT, handler);
	while(1) {
		sleep(1);
		printf("*");
	}
	return 0;
}

void handler(int sig_num) {
	printf("\nnot working");
}
