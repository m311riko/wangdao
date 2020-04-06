#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

int main()
{
	int fds[2];
	int ret;
	ret=pipe(fds);	//创建管道
	if(-1==ret)
	{
		perror("pipe1");
		return -1;
	}

	//子进程
	if(!fork())
	{
		close(fds[0]);	//关闭读端
		write(fds[1],"hello",5);
		exit(0);
	}
	else	//父进程
	{
		close(fds[1]);	//关闭写端
		char buf[10];
		bzero(buf,sizeof(buf));
		read(fds[0],buf,sizeof(buf));
		printf("the buf is %s\n",buf);
		exit(0);
	}
}
