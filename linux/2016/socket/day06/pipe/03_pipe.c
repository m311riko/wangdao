#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//关闭部分写端，read阻塞
//关闭全部写端，read读到0，相当于读到结尾
int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid;
	pid=fork();

	if(pid==0)	//子进程
	{
		sleep(2);
		close(fd[0]);	//关闭读端
		write(fd[1],"hello\n",6);	//写管道
		close(fd[1]);	//关闭写端
		while(1)
		{
			sleep(1);
		}
	}
	else if(pid>0)	//父进程
	{
		char buf[10]={0};
		while(1)
		{
			close(fd[1]);	//关闭写端
			int ret=read(fd[0],buf,sizeof(buf));	//读管道
			if(ret==0)
			{
				printf("read over\n");
				break;
			}
			if(ret>0)
			{
				write(STDOUT_FILENO,buf,ret);	//写标准输出
			}
		}
	}

	return 0;
}
