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
	int fd=open(argv[1],O_WRONLY);
	if(fd==-1)
	{
		perror("open1");
		return -1;
	}

	//向fifo写内容
	write(fd,"hello",5);	

	//关闭fifo文件
	close(fd);

	return 0;
}
