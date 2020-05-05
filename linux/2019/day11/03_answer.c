#include <func.h>

void sigFunc(int signum,siginfo_t *siginfo,void *old)
{
    printf("the signum is %d\n",signum);
    sleep(3);

    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);   //存储挂起信号
    if(sigismember(&pending,SIGQUIT))
    {
        printf("sigquit is pending\n");
    }
    else
    {
        printf("sigquit is not pending\n");
    }
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigFunc;
    act.sa_flags=SA_SIGINFO;
    sigaddset(&act.sa_mask,SIGQUIT);

    sigaction(SIGINT,&act,NULL);

    while(1);

    return 0;
}

