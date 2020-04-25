#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	int fd;
	fd=open(argv[1],O_RDWR);
	if(-1==fd)
	{
		perror("open1");
		return -1;
	}

	//使用mmap将文件映射到内存
	char *p;
	p=mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if((void*)p==(void*)-1)
	{
		perror("mmap");
		return -1;
	}

	//向文件写入内容
	*p='h';
	*(p+1)='e';
	
	//解除映射
	int ret;
	ret=munmap(p,10);
	if(ret<0)
	{
		perror("munmap1");
		return -1;
	}

	close(fd);

	return 0;
}
