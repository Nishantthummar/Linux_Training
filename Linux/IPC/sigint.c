#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void handler(int sig_num);
void user_handler(int sig_num);
int main() {
	signal(SIGUSR1, user_handler);
	signal(SIGINT, handler);
	while(1) {
		sleep(1);
		raise(SIGUSR1);
	}
	return 0;
}

void handler(int sig_num) {
	printf("\ncan not terminate using ctrl+c");
	fflush(stdout);

}

void user_handler(int signum) {
	printf("\nuser signal");
}
