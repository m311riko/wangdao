#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned int myalarm(unsigned int seconds)
{
	struct itimerval myit={{0,0},{0,0}};
	myit.it_value.tv_sec=seconds;
	setitimer(ITIMER_REAL,&myit,NULL);
	return 0;
}

int main()
{
	myalarm(5);

	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
