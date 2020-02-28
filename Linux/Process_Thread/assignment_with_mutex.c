#include <stdio.h>
#include <pthread.h>
#define COUNT 1000000

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
long int n = 0;
/***************************************************************************//*
*function for increment value of global variable
******************************************************************************/
void *increment (void *var) {
	while (1) {

		// if value of global variable is greter then COUNT
		if (n>COUNT) { 
			return NULL; // return from function with NULL
		}
		pthread_mutex_lock (&mutex); // mutex lock critical region
			n++;   // critical region
			printf("\nvalue of n is %ld", n);
		pthread_mutex_unlock (&mutex); // mutex unlock critical region
	}
}


int main()
{	
	pthread_t thread1_id; // to store thread id of 1
	pthread_t thread2_id; // to store thread id of 2
	pthread_t thread3_id; // to store thread id of 3

	pthread_create (&thread1_id, NULL, increment, NULL); // create thread 
	pthread_create (&thread2_id, NULL, increment, NULL); // create thread
	pthread_create (&thread3_id, NULL, increment, NULL); // create thread
	
	pthread_exit(NULL); // exit from pthread
	return 0;
}
