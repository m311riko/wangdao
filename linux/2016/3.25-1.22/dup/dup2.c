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
	if(argc!=3)
	{
		printf("args error\n");
		return -1;
	}

	//打开第一个文件
	int fd;
	fd=open(argv[1],O_RDWR,0600);
	if(-1==fd)
	{
		perror("open1");
		printf("errno is %d\n",errno);
		return -1;
	}

	//打开第二个文件
	int fd1;
	fd1=open(argv[2],O_RDWR,0666);
	if(-1==fd1)
	{
		perror("open2");
		printf("errno is %d\n",errno);
		return -1;
	}
	printf("fd:%d fd1:%d\n",fd,fd1);

	//使用dup2复制文件描述符
	int fd2=dup2(fd,fd1);
	printf("fd2:%d\n",fd2);

	//从文件读入buf
	char buf[128];
	bzero(buf,sizeof(buf));
	read(fd1,buf,sizeof(buf));
	printf("the buf is %s\n",buf);

	close(fd);
	
	return 0;
}
