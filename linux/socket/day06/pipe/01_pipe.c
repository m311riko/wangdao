#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid;
	pid=fork();

	if(pid==0)	//子进程
	{
		sleep(2);
		write(fd[1],"hello\n",6);	//写管道
	}
	else if(pid>0)	//父进程
	{
		char buf[10]={0};
		int ret=read(fd[0],buf,sizeof(buf));	//读管道
		if(ret>0)
		{
			write(STDOUT_FILENO,buf,ret);	//写标准输出
		}
	}

	return 0;
}
