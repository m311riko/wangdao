#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

void main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
	}

	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=sub(a,b);
	printf("the c is %d\n",c);
}
