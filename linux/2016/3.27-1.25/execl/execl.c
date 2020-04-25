#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("I am start\n");
	execl("./add","add","1","2",NULL);
	printf("I am not here\n");

	return 0;
}
