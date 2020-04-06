#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
		return -1;
	}
	
	//写文件描述符
	int fdw;
	fdw=open(argv[1],O_WRONLY);
	if(-1==fdw)
	{
		perror("open2\n");
		printf("errno is %d\n",errno);
		return -1;
	}

	//读文件描述符
	int fdr;
	fdr=open(argv[2],O_RDONLY);
	if(-1==fdr)
	{
		perror("open1\n");
		printf("errno is %d\n",errno);
		return -1;
	}
	
	char buf[128];
	int ret;
	while(bzero(buf,sizeof(buf)),(ret=read(STDIN_FILENO,buf,sizeof(buf)))>0)
	{
		write(fdw,buf,ret-1);
		
		bzero(buf,sizeof(buf));
		if((ret=read(fdr,buf,sizeof(buf)))>0)
		{
			printf("%s\n",buf);
			if(strcmp(buf,"bye")==0)
			{
				break;
			}
		}
	}

	close(fdw);
	close(fdr);

	return 0;
}
