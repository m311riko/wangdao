#include <func.h>

int main()
{
    //创建无名管道
    //0是读端、1是写端
    int fd[2];
    int ret=pipe(fd);
    ERROR_CHECK(ret,-1,"pipe");

    //创建子进程
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        printf("I am child\n");

        //子进程关闭读端
        close(fd[0]);

        //写管道
        char buf[128]="hello";
        int ret=write(fd[1],buf,strlen(buf));
        ERROR_CHECK(ret,-1,"write");

        //子进程退出
        return 0;
    }
    else
    {
        printf("I am parent\n");

        //父进程关闭写端
        close(fd[1]);

        //读管道
        char buf[128]={0};
        int ret=read(fd[0],buf,sizeof(buf));
        ERROR_CHECK(ret,-1,"read");

        //打印内容
        printf("buf is %s\n",buf);

        //等待子进程退出
        wait(NULL);

        //父进程退出
        return 0;
    }

    return 0;
}

