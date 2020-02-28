#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

int main() {
	key_t key;
	key = ftok("shm", 65); // to create unique key
	int shmid = shmget(key, 1024, 0666|IPC_CREAT); // create memory block
	char *str  = (char *) shmat(shmid, (void*)0, 0); // attached created block
	printf("\nshared memoery attached at address %p", str);
	printf("\nEnter the data :");
	scanf("%s", str);
	printf("\nyour data is %s", str);
	return 0;
}
