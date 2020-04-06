#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>


int main()
{
	printf("I will die\n");
	abort();
	sleep(3);

	return 0;
}
