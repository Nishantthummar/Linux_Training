#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *thread_function1(void *arg);
void *thread_function2(void *arg);
int main() {
	pthread_t thread_id1, thread_id2;
	printf("\ncreating......");
	pthread_create(&thread_id1, NULL, thread_function1, NULL);
	pthread_create(&thread_id2, NULL, thread_function2, NULL);
	pthread_exit(NULL);
	return 0;
}

void *thread_function1(void *arg) {
	int c=100;
	while(c>0) {
//	sleep(1);
	printf(" *");
	c--;
	}
	return NULL;
}

void *thread_function2(void *arg) {
	int c=100;
	while(c>0) {
//	sleep(1);
	printf(" #");
	c--;
	}
	return NULL;
}

