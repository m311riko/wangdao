#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

typedef struct student
{
	int id;
	char name[20];
}std;

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

	int length=sizeof(std);
	std *student=mmap(NULL,length,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(student==MAP_FAILED)
	{
		perror("mmap1");
		return -1;
	}
	
	printf("id:%d\nname:%s\n",student->id,student->name);

	munmap(student,length);
	close(fd);

	return 0;
}
