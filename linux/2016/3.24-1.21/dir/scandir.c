#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <strings.h>

void myscandir(char* path,int width)
{
	DIR* dir;
	dir=opendir(path);
	if(NULL==dir)
	{
		perror("opendir1");
		return;
	}

	struct dirent* pt;
	char buf[128];
	while(pt=readdir(dir))
	{
		//打印设备文件和普通文件
		if(strcmp(pt->d_name,".")!=0 && strcmp(pt->d_name,"..")!=0)
		{
			printf("%*s%s\n",width," ",pt->d_name);
		}

		//设备文件
		if(pt->d_type==4)
		{
			if(strcmp(pt->d_name,".")!=0 && strcmp(pt->d_name,"..")!=0)
			{
				bzero(buf,sizeof(buf));
				sprintf(buf,"%s%s%s",path,"/",pt->d_name);
				myscandir(buf,width+4);
			}
		}
	}

	closedir(dir);
}

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	printf("%s\n",argv[1]);
	myscandir(argv[1],0);

	return 0;
}
