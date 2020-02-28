#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define COUNT 1000000

sem_t sema;
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
		sem_wait (&sema); // semaphore wait function 

			n++; // critical region
			printf("\nvalue of n is %ld", n); // critical region
		
		sem_post (&sema); // semaphore post function
	}
}


int main()
{	
	sem_init (&sema, 0, 1); // semaphore initialize with value 1
	pthread_t thread1_id; // to store thread id of 1
	pthread_t thread2_id; // to store thread id of 2
	pthread_t thread3_id; // to store thread id of 3

	pthread_create (&thread1_id, NULL, increment, NULL); // create thread 
	pthread_create (&thread2_id, NULL, increment, NULL); // create thread
	pthread_create (&thread3_id, NULL, increment, NULL); // create thread
	
	pthread_exit(NULL); // exit from pthread
	sem_destroy(&sema); // remove semaphore from memory
	return 0;
}
