#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	key_t key = ftok("shm", 65); // generate unique key
	int shmid = shmget(key, 1024, 0666|IPC_CREAT); // create memory block
	char *str = (char *)shmat(shmid, (void *)0, 0); // attached memory 
	printf("\nsize of data is %ld", strlen(str));
	printf("\nData from shared memory is %s", str);
	shmdt(str); // deattached memory block
	shmctl(shmid,IPC_RMID,NULL); // to clear memory block
	return 0;
}

