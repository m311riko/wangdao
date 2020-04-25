#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	int fd=open(argv[1],O_RDWR);
	if(fd==-1)
	{
		perror("open1");
		return -1;
	}

	char *mem=mmap(NULL,8,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(mem==MAP_FAILED)
	{
		perror("mmap1");
		return -1;
	}

	strcpy(mem,"hello");

	munmap(mem,8);

	close(fd);

	return 0;
}
