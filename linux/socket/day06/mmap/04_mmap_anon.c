#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	//进行匿名映射
	int *mem=mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANON,-1,0);
	if(mem==MAP_FAILED)
	{
		perror("mmap1");
		return -1;
	}

	pid_t pid=fork();
	if(pid==0)
	{
		*mem=100;
		printf("child:%d\n",*mem);
		sleep(3);
		printf("child:%d\n",*mem);
	}
	else if(pid>0)
	{
		sleep(1);
		printf("parent:%d\n",*mem);
		*mem=1001;
		printf("parent:%d\n",*mem);
		wait(NULL);
	}

	munmap(mem,4);

	return 0;
}
