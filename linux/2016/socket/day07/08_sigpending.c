#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	//获取阻塞信号集
	sigset_t sigproc;
	sigemptyset(&sigproc);

	//将SIGINT加入阻塞信号集中,设置阻塞信号集
	sigaddset(&sigproc,SIGINT);
	sigprocmask(SIG_BLOCK,&sigproc,NULL);

	sigset_t pend;
	while(1)
	{	
		//加入未决信号集
		sigpending(&pend);

		//打印信号
		int i;
		for(i=1;i<32;i++)
		{
			if(sigismember(&pend,i)==1)
			{
				printf("1");	//未决信号
			}
			else
			{
				printf("0");	//非未决信号
			}
		}
		printf("\n");
		sleep(1);
	}

	return 0;
}
