#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	printf("uid=%d gid=%d euid=%d egid=%d\n",getuid(),getgid(),geteuid(),getegid());
	if(argc!=2)
	{
		printf("args errof\n");
		return -1;
	}

	int fd;
	fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("open1");
		return -1;
	}

	int ret;
	ret=write(fd,"world",5);
	if(ret<0)
	{
		perror("write1");
		return -1;
	}

	close(fd);
	
	return 0;
}
