#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	//子进程
	if(!fork())
	{
		printf("I am child\n");
		while(1);
	}
	else
	{
		exit(0);
	}
}
