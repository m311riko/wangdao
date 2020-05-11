#include "process_pool.h"

int makeChild(process_data_t *p,int processNum)
{
    pid_t pid;
    int fds[2];
    for(int i=0;i<processNum;i++)
    {
        //创建全双工管道
        socketpair(AF_LOCAL,SOCK_STREAM,0,fds);

        //创建子进程
        pid=fork();

        //子进程处理任务
        if(0==pid)
        {
            //关闭管道一端
            close(fds[0]);

            //使用管道另一端
            childHandle(fds[1]);
        }
        else
        {
            //关闭管道一端
            close(fds[1]);

            //初始化管理子进程的结构体
            p[i].pid=pid;
            p[i].fd=fds[0];
            p[i].busy=0;
        }
    }

    return 0;
}

int childHandle(int pipeFd)
{
    int newFd;
    char finish;
    while(1)
    {
        recvFd(pipeFd,&newFd);
        tranFile(newFd);
        close(newFd);
        write(pipeFd,&finish,1);
    }
    exit(0);
}

