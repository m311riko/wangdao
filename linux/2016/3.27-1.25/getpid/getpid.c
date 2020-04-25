#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid,ppid;
	pid=getpid();	//获取自己的id
	ppid=getppid();	//获取父进程id
	printf("pid=%d ppid=%d\n",pid,ppid);
	while(1);
	return 0;
}
