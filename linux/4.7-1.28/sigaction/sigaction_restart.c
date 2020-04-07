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
	act.sa_flags=SA_SIGINFO|SA_RESTART;	//处理完信号以后，继续阻塞在系统调用上
										//否则处理完信号以后，read读取失败
	
	int ret;
	ret=sigaction(SIGINT,&act,NULL);	//设置信号处理方式
	if(-1==ret)
	{
		perror("sigaction");
		return -1;
	}

	char buf[10];
	bzero(buf,sizeof(buf));
	ret=read(0,buf,sizeof(buf));	//阻塞在read上
	printf("the buf is %s\n",buf);

	return 0;
}
