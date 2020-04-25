#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>

void sig(int s)
{
	time_t tn;
	time(&tn);
	printf("%s\n",ctime(&tn));
}

int main()
{
	signal(SIGPROF,sig);	//设置实用计时器信号
	kill(getpid(),SIGPROF);	//发送实用计时器信号

	struct itimerval it;
	bzero(&it,sizeof(it));
	it.it_value.tv_sec=5;	//初始间隔
	it.it_interval.tv_sec=2;	//重复间隔
	int ret=setitimer(ITIMER_PROF,&it,NULL);	//设置定时器
	if(-1==ret)
	{
		perror("setitimer");
		return -1;
	}

	sleep(10);
	while(1);
	
	return 0;
}
