#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

int main()
{
	pid_t pidchi,pid;
	int i;
	for(i=0;i<5;i++)
	{
		pid=fork();
		if(pid==0)
		{
			break;
		}
		if(i==2)
		{
			pidchi=pid;
		}
	}

	if(i<5)
	{
		while(1)
		{	
			printf("I am children %d\n",getpid());
			sleep(3);
		}
	}
	else if(i==5)
	{
		printf("I am father,I will kill 3 after 5s\n");
		sleep(5);
		kill(pidchi,SIGKILL);
		while(1)
		{
			sleep(1);
		}
	}

	return 0;
}
