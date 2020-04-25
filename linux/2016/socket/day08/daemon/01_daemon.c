#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>

void touchfile(int num)
{
	char *home=getenv("HOME");
	char filename[256]={0};
	sprintf(filename,"%s/log/deamon%ld",home,time(NULL));
	int fd=open(filename,O_RDWR|O_CREAT,0666);
	if(fd<0)
	{
		perror("open1");
		exit(1);
	}
	close(fd);
}

int main()
{
	//创建子进程
	pid_t pid=fork();

	//父进程退出
	if(pid>0)
	{
		exit(1);
	}

	//子进程成为会长
	setsid();

	//切换工作路径
	chdir(getenv("HOME"));
	//设置掩码
	umask(0);
	//关闭文件描述符
	//close(0);close(1);close(2);
	//执行核心逻辑
	struct itimerval myit={{60,0},{1,0}};
	setitimer(ITIMER_REAL,&myit,NULL);
	
	struct sigaction act;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	act.sa_handler=touchfile;

	sigaction(SIGALRM,&act,NULL);
	while(1)
	{
		sleep(1);
	}
	//退出

	return 0;
}
