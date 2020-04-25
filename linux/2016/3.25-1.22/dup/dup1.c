#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	int fd;
	fd=open(argv[1],O_WRONLY,0600);
	if(-1==fd)
	{
		perror("open1");
		printf("errno is %d\n",errno);
		return -1;
	}
	printf("the fd is %d\n",fd);
	
	//重定向标准输出
	close(STDOUT_FILENO);
	int fd1;
	fd1=dup(fd);
	if(-1==fd1)
	{
		perror("dup1");
		close(fd);
		return -1;
	}
	printf("the fd1 is %d\n",fd1);
	close(fd);

	printf("hello world\n");

	close(fd1);

	return 0;
}
