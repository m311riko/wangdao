#include <func.h>

#if 0
1.执行fork()以后子进程复制父进程的进程地址空间，包括堆空间；
2.堆空间实现写时复制原理；
#endif

int main()
{
    char *p=(char*)malloc(20);
    strcpy(p,"hello");

    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        printf("I am child,p is %s\n",p);
        return 0;
    }
    else
    {
        printf("I am parent,p is %s\n",p);
        sleep(1);
        return 0;
    }

    return 0;
}

