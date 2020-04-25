#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void catch_sig(int num)
{
	printf("catch %d\n",num);
}

int main()
{
	signal(SIGALRM,catch_sig);
	struct itimerval myit={{3,0},{5,0}};
	setitimer(ITIMER_REAL,&myit,NULL);	//第一次5秒以后发送，以后每隔3秒发送一次

	while(1)
	{
		printf("who can kill me\n");
		sleep(1);
	}

	return 0;
}
