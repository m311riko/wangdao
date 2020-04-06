#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("ls -l");
	printf("I am main process\n");
	while(1);

	return 0;
}
