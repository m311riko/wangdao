#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//信号特点：
//1、使用sa_mask设置屏蔽信号；
//2、XXX信号捕捉函数执行期间，XXX信号自动被屏蔽；
//3、阻塞的常规信号不支持排队，产生多次只记录一次；
void catch_sig(int num)
{
	printf("begin,catch %d\n",num);
	sleep(5);
	printf("end,catch %d\n",num);
}

int main()
{
	//设置动作
	struct sigaction act;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler=catch_sig;

	//注册捕捉
	sigaction(SIGINT,&act,NULL);
	
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
