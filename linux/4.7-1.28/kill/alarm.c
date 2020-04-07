#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void sig(int s)
{
	printf("the sig num is %d\n",s);
}

int main()
{
	signal(SIGALRM,sig);
	alarm(5);	//5秒后发送AIGALRM信号
	while(1);
	return 0;
}
