#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	char buf[50];	//注意buf不能太小
	bzero(buf,sizeof(buf));
	//chdir(argv[1]);
	printf("the path is %s\n",getcwd(buf,sizeof(buf)));
	printf("the buf is %s\n",buf);

	return 0;
}
