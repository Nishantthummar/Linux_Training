#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h> 
#include <fcntl.h> 

#include <sys/wait.h>
#include <unistd.h> 
#include <string.h>
#define MAX 7

int main() {
	char *path = "/home/nishant/Training/Linux/IPC/fif";
	char c_send[MAX];
	char c_recv[MAX];
	int fd;
	int a;
	a = mkfifo(path, 0777);	
	printf("\nvalue of a is %d", a);
	printf("\nEnter ");
	fgets(c_send, 80, stdin);
	//scanf("%s", c_send);
	printf("\n print your data %s", c_send);
	open(path, O_WRONLY);
	write(fd, c_send, MAX);
	close(fd);

	open(path, O_RDONLY);
	read(fd, c_recv, MAX);
	printf("\nfrom child: %s", c_recv);
	close(fd);
	return 0;

}


