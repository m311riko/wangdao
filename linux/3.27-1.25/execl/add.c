#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
		return -1;
	}

	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=a+b;
	printf("the sum is %d\n",c);

	return 0;
}
