#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid=fork();	//创建子进程

	//子进程
	if(0==pid)
	{
		printf("pid=%d ppid=%d\n",getpid(),getppid());
		exit(0);
	}
	else	//父进程
	{
		printf("pid=%d ppid=%d\n",getpid(),getppid());
		while(1);
		return 0;
	}
}
