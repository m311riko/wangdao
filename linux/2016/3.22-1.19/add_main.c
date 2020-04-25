#include <stdio.h>
#include <stdlib.h>
#include "add.h"

void main(int argc, char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
		return;
	}

	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=add(a,b);
	printf("the result is %d\n",c);
}
