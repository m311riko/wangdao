#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>

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
	printf("the fd value is %d\n",fd);

	//复制文件描述符
	int fd1;
	fd1=dup(fd);
	if(-1==fd1)
	{
		perror("dup1");
		close(fd);
		return -1;
	}
	close(fd);

	//从文件中读到buf
	char buf[128];
	bzero(buf,sizeof(buf));
	read(fd1,buf,sizeof(buf));
	printf("the buf is %s\n",buf);

	close(fd1);

	return 0;
}
