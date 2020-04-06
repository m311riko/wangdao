#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{
	FILE* fp;
	fp=popen("ls -l","r");	//打开标准流管道，从管道中读数据
	if(NULL==fp)
	{
		perror("popen");
		return -1;
	}

	char buf[512];
	bzero(buf,sizeof(buf));
	int ret;
	ret=fread(buf,1,512,fp);
	if(ret>0)
	{
		printf("%s\n",buf);
	}

	pclose(fp);

	return 0;
}
