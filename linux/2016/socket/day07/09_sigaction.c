#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

void catch_sig(int num)
{
	printf("catch %d\n",num);
}

int main()
{
	//注册捕捉函数
	struct sigaction act;
	act.sa_flags=0;
	act.sa_handler=catch_sig;
	sigemptyset(&act.sa_mask);
	sigaction(SIGALRM,&act,NULL);

	//setitimer，第一次5s发送信号，之后每隔3s发送SIGALRM信号
	struct itimerval myit={{3,0},{5,0}};
	setitimer(ITIMER_REAL,&myit,NULL);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
