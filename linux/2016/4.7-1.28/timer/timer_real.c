#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <strings.h>

void sig(int s)
{
	time_t tp;
	time(&tp);
	printf("%s\n",ctime(&tp));
}

int main()
{
	signal(SIGALRM,sig);
	struct itimerval it;
	bzero(&it,sizeof(it));
	it.it_value.tv_sec=3;	//第一次间隔3秒
	it.it_interval.tv_sec=2;	//之后每次间隔2秒
	int ret;
	ret=setitimer(ITIMER_REAL,&it,NULL);
	if(-1==ret)
	{
		perror("setitimer");
		return -1;
	}

	while(1);
	return 0;
}
