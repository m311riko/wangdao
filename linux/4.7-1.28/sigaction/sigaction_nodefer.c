#include "func.h"

//信号处理函数
void siga(int signum,siginfo_t *p,void *p1)
{
	printf("I get the sig %d\n",signum);
	sleep(3);
	printf("after sleep,the signum is %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=siga;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO|SA_NODEFER;	//递归处理信号
	
	int ret;
	ret=sigaction(SIGINT,&act,NULL);	//设置信号处理方式
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	ret=sigaction(SIGQUIT,&act,NULL);
	if(-1==ret)
	{
		perror("sigaction1");
		return -1;
	}

	while(1);
	return 0;
}
