#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void catch_sig(int num)
{
	pid_t pid;
	while((pid=waitpid(-1,NULL,WNOHANG))>0)
	{
		printf("wait child %d\n",pid);
	}
}

int main()
{
	//在创建子进程之前屏蔽SIGCHLD信号
	sigset_t myset,oldset;
	sigemptyset(&myset);
	sigaddset(&myset,SIGCHLD);
	sigprocmask(SIG_BLOCK,&myset,&oldset);
	
	//生成5个子进程
	int i;
	pid_t pid;
	for(i=0;i<5;i++)
	{
		pid=fork();
		if(pid==0)
		{
			break;
		}
	}

	if(i==5)
	{
		sleep(2);
		struct sigaction act;
		act.sa_flags=0;
		sigemptyset(&act.sa_mask);
		act.sa_handler=catch_sig;

		//注册捕捉处理
		sigaction(SIGCHLD,&act,NULL);

		//解除屏蔽现场
		sigprocmask(SIG_SETMASK,&oldset,NULL);

		while(1)
		{
			sleep(1);
		}
	}
	else if(i<5)
	{
		printf("I am %d child,pid=%d\n",i,getpid());
	}

	return 0;
}
