#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pause();	//将进程挂起，等待信号唤醒
	return 0;
}
