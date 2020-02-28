#include <stdio.h>
#include <unistd.h>

int main() 
{
	printf("\nThe process id is %d", (int)getpid());
	printf("\nThe Parent process id is %d", (int)getppid());
	return 0;
}
