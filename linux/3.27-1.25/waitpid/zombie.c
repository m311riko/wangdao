#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	if(!fork())
	{
		printf("I am child\n");
		exit(0);
	}
	else
	{
		while(1);
		return 0;
	}
}
