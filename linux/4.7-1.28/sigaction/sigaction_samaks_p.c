#include "func.h"

//信号处理函数
void siga(int signum,siginfo_t *p,void *p1)
{
	printf("I get the sig %d\n",signum);
	sleep(5);
	sigset_t set;
	sigemptyset(&set);
	int ret;
	ret=sigpending(&set);	//获取被阻塞信号
	if(-1==ret)
	{
		perror("sigpending");
		return;
	}
	if(1==sigismember(&set,SIGINT))
	{
		printf("the SIGINT is pending\n");
	}
	if(1==sigismember(&set,SIGQUIT))
	{
		printf("the SIGQUIT is pending\n");
	}
	printf("after sleep,sig is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=siga;
	act.sa_flags=SA_SIGINFO|SA_NODEFER;
	
	sigemptyset(&act.sa_mask);
	int ret;
	ret=sigfillset(&act.sa_mask);	//屏蔽所有信号
	if(-1==ret)
	{
		perror("sigfillset");
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
