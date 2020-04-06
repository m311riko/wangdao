#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	int fd;
	fd=open(argv[1],O_RDWR);
	if(fd<0)
	{
		perror("open1");
		return -1;
	}

	//给文件加锁
	struct flock lk;
	lk.l_type=F_WRLCK;
	lk.l_whence=SEEK_SET;
	lk.l_start=0;
	lk.l_len=0;

	int ret;
	ret=fcntl(fd,F_SETLK,&lk);
	if(ret<0)
	{
		perror("fcntl1");
		return -1;
	}

	//核心逻辑
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
