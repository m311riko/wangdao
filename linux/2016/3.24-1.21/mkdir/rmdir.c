#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	int ret;
	ret=rmdir(argv[1]);
	if(-1==ret)
	{
		perror("rmdir1");
		return -1;
	}

	return 0;
}
