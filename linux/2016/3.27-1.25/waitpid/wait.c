#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	//子进程
	if(!fork())
	{
		printf("I am child\n");
		exit(0);
	}
	else	//父进程
	{
		//父进程清理子进程
		int status;
		int ret;
		ret=wait(&status);
		if(ret<0)
		{
			perror("wait1");
			return -1;
		}
		
		//成功退出
		if(WIFEXITED(status))
		{
			printf("the WIFEXITED value is %d\n",WIFEXITED(status));
			printf("the exit value is %d\n",WEXITSTATUS(status));
		}

		return 0;
	}
}
