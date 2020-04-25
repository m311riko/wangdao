#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
		return -1;
	}

	int fdr;
	fdr=open(argv[1],O_RDONLY);
	if(-1==fdr)
	{
		perror("open1");
		return -1;
	}

	int fdw;
	fdw=open(argv[2],O_WRONLY);
	if(-1==fdw)
	{
		perror("open2");
		return -1;
	}
	printf("fdr:%d,fdw:%d\n",fdr,fdw);

	char buf[128];
	int ret;
	fd_set readset;
	while(1)
	{
		FD_ZERO(&readset);
		FD_SET(STDIN_FILENO,&readset);
		FD_SET(fdr,&readset);
		ret=select(fdr+1,&readset,NULL,NULL,NULL);
		if(ret>0)
		{
			//从fdr读到buf
			if(FD_ISSET(fdr,&readset))
			{
				bzero(buf,sizeof(buf));
				if(read(fdr,buf,sizeof(buf))>0)
				{
					printf("%s\n",buf);
				}
			}
			
			//从标准输入读到buf
			if(FD_ISSET(STDIN_FILENO,&readset))
			{
				bzero(buf,sizeof(buf));
				//从标准输入读入buf，然后写入fdw
				if((ret=read(STDIN_FILENO,buf,sizeof(buf)))>0)
				{
					write(fdw,buf,ret-1);
				}
				else	//输入ctr+d结束，自动向对方发送bye
				{
					write(fdw,"bye",3);
					break;
				}
			}
		}
	}

	close(fdr);
	close(fdw);

	return 0;
}
