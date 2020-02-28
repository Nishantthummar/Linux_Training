#include <stdio.h>
#include <assert.h>
#define MAX 50;

int main()
{
	int a;
	char name[30];

	printf("\nEnter int value: ");
	scanf("%d", &a);
	assert(a>=10);
	printf("\nvalue is %d", a);

	printf("\nEnter string");
	scanf("%s", name);
	assert(name != NULL);
	printf("\n string is %s", name);
}
