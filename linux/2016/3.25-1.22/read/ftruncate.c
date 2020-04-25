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

	int fd;
	fd=open(argv[1],O_RDWR,0600);
	if(-1==fd)
	{
		perror("open1");
		printf("errno is %d\n",errno);
		return -1;
	}

	//改变文件大小
	int ret;
	ret=ftruncate(fd,1);
	if(-1==ret)
	{
		perror("ftruncate1");
		close(fd);
		return -1;
	}

	close(fd);

	return 0;
}
