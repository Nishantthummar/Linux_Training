#include <stdio.h>
#include <unistd.h>

int main() {
	char *arg[] = {"./exec", NULL};
	execv(arg[0], arg);
	printf("\nEnd of program");
}	
