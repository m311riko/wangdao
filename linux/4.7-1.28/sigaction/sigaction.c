#include "func.h"

//信号处理函数
void siga(int signum,siginfo_t *p,void *p1)
{
	printf("I get the sig %d\n",signum);
}

int main()
{
	struct sigaction act;
	bzero(&act,sizeof(act));
	act.sa_sigaction=siga;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO;
	
	int ret;
	ret=sigaction(SIGINT,&act,NULL);	//设置信号处理方式
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	while(1);
	return 0;
}
