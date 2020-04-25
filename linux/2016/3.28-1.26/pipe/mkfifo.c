#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		exit(-1);
	}

	int ret;
	ret=mkfifo(argv[1],0666);	//创建一个命名管道
	if(-1==ret)
	{
		perror("mkfifo");
		return -1;
	}

	ret=unlink(argv[1]);
	if(-1==ret)
	{
		perror("unlink1");
		return -1;
	}

	return 0;
}
