#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
	struct itimerval myit={{0,0},{3,0}};
	setitimer(ITIMER_REAL,&myit,NULL);	//实现alarm功能
	while(1)
	{
		printf("who can kill me\n");
		sleep(1);
	}

	return 0;
}
