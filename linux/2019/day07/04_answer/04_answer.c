#include <func.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        printf("I am child,pid=%d\n",getpid());
        while(1);
    }
    else
    {
        printf("I am parent,pid=%d\n",getpid());
        while(1);
    }

    return 0;
}

