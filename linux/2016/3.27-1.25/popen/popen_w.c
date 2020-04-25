#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int main()
{
	FILE* fp;
	fp=popen("./scanf","w");	//打开标准流管道，向管道中写入数据
	if(NULL==fp)
	{
		perror("open1");
		return -1;
	}

	char buf[512];
	bzero(buf,sizeof(buf));
	strcpy(buf,"123");
	int ret;
	ret=fwrite(buf,1,strlen(buf),fp);
	if(ret<0)
	{
		perror("write1");
		return -1;
	}

	pclose(fp);

	return 0;
}
