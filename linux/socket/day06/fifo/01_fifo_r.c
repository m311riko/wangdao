#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	//打开fifo文件
	int fd=open(argv[1],O_RDONLY);

	//从fifo读内容
	char buf[10];
	memset(buf,0,sizeof(buf));
	int ret;
	ret=read(fd,buf,sizeof(buf));
	if(ret<0)
	{
		perror("read1");
		return -1;
	}
	printf("the buf is %s\n",buf);

	close(fd);

	return 0;
}
