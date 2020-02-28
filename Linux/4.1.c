#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
/* Prints x’s to stderr.
The parameter is unused.
Does not return.
*/
void* print_xs (void* unused)
{
while (1) {
fputc ('x', stdout);
//sleep(10);
}
return NULL;
}
/* The main program.
*/
int main ()
{
pthread_t thread_id;
/* Create a new thread. The new thread will run the print_xs
function. */
pthread_create (&thread_id, NULL, &print_xs, NULL);
/* Print o’s continuously to stderr. */
while (1) {
fputc ('o', stdout);
//sleep(1);
}
return 0;
}
