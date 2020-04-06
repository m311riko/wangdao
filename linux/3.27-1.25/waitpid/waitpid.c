#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(0==pid)
	{
		printf("I am child\n");
		while(1);
	}
	else
	{
		int status;
		int ret;
		ret=waitpid(pid,&status,WNOHANG);
		printf("ret is %d\n",ret);
		if(ret<0)
		{
			perror("waitpid1");
			return -1;
		}

		printf("the WIFEXITED vlaue is %d\n",WIFEXITED(status));

		if(WIFEXITED(status))
		{
			printf("the WIFEXITED vlaue is %d\n",WIFEXITED(status));
			printf("the exit value is %d\n",WEXITSTATUS(status));
		}

		return 0;
	}
}
