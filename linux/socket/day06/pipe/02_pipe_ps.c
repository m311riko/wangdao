#include <stdio.h>
#include <unistd.h>

//实现ps aux | grep bash功能
int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid = fork();

	if(pid==0)	//子进程
	{
		//关闭子进程管道读端
		close(fd[0]);

		//将标准输出重定向到管道写端
		dup2(fd[1],STDOUT_FILENO);

		//execlp
		execlp("ps","ps","aux",NULL);
	}
	else if(pid>0)
	{
		//关闭父进程管道写端
		close(fd[1]);

		//将标准输入重定向到管道读端
		dup2(fd[0],STDIN_FILENO);

		//execlp
		execlp("grep","grep","bash",NULL);
	}

	return 0;
}
