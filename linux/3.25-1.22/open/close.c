#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	//打开文件
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0600);
	if(-1==fd)
	{
		perror("open1");
		printf("errno is %d\n",errno);
		return -1;
	}
	
	//关闭文件
	close(fd);

	return 0;
}
