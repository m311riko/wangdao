#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	//创建子进程，父进程退出
	if(fork()>0)
	{
		exit(0);
	}

	//在子进程中创建新会话，并让自己成为会话组组长
	setsid();

	//改变当前路径为根目录
	chdir("/");

	//重设文件权限掩码为0
	umask(0);

	//关闭不需要的文件描述符
	int i;
	for(i=0;i<3;i++)
	{
		close(i);
	}

	while(1);

	return 0;
}
