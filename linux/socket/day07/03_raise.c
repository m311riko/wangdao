#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	printf("I will kill myself\n");
	raise(SIGKILL);
	sleep(2);

	return 0;
}
