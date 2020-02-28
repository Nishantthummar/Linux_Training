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
///Handler function for int signal event
void handler(int sig_num) {
	printf("\ncan not terminate using ctrl+c");
	fflush(stdout);

}
///Handler function for user1 signal event
void user_handler(int signum) {
	printf("\nuser signal");
}
