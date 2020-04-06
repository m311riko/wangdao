#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
		return -1;
	}
	
	//读文件描述符
	int fdr;
	fdr=open(argv[1],O_RDONLY);
	if(-1==fdr)
	{
		perror("open1");
		printf("errno is %d\n",errno);
		return -1;
	}

	//写文件描述符
	int fdw;
	fdw=open(argv[2],O_WRONLY);
	if(-1==fdw)
	{
		perror("open2");
		printf("errno is %d\n",errno);
		return -1;
	}

	char buf[128];
	int ret;
	while(bzero(buf,sizeof(buf)),read(fdr,buf,sizeof(buf))>0)
	{
		printf("%s\n",buf);

		bzero(buf,sizeof(buf));
		if((ret=read(STDIN_FILENO,buf,sizeof(buf)))>0)
		{
			write(fdw,buf,ret-1);
		}
		else
		{
			write(fdw,"bye",3);
			break;
		}
	}
	
	close(fdr);
	close(fdw);

	return 0;
}
