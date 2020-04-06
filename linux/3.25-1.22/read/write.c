#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

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

	//从buf中写入文件
	char buf[128]="world";
	int ret;
	ret=write(fd,buf,strlen(buf));
	if(-1==ret)
	{
		perror("write1");
		close(fd);
		return -1;
	}

	close(fd);

	return 0;
}
