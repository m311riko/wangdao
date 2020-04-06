#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid=getpid();
	pid_t pgid;
	pgid=getpgid(pid);
	printf("mypid:%d mypgid:%d\n",pid,pgid);

	return 0;
}
