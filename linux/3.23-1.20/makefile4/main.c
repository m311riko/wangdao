#include "head.h"

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("argc error\n");
		return -1;
	}

	int a,b;
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	printf("the a*b*(a+b) is %d\n",mul(a,b)*add(a,b));
	return 0;
}
