#include "func.h"

//信号处理函数
void siga(int signum,siginfo_t *p,void *p1)
{
	printf("I get the sig %d\n",signum);
	sleep(5);
	printf("after sleep,sig is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=siga;
	act.sa_flags=SA_SIGINFO;
	
	sigemptyset(&act.sa_mask);
	int ret;
	ret=sigaddset(&act.sa_mask,SIGQUIT);	//将SIGQUIT信号屏蔽
	if(-1==ret)
	{
		perror("sigaddset");
		return -1;
	}

	ret=sigaction(SIGINT,&act,NULL);	//设置信号处理方式
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	while(1);
	return 0;
}
