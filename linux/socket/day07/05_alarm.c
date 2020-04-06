#include <stdio.h>
#include <unistd.h>

int main()
{
	int ret;
	ret=alarm(6);
	printf("the ret is %d\n",ret);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}

	return 0;
}
