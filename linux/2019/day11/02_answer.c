#include <func.h>

void sigFunc(int signum,siginfo_t *siginfo,void *old)
{
    printf("before,the signum is %d\n",signum);
    sleep(3);
    printf("after,the signum is %d\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));
    act.sa_sigaction=sigFunc;
    act.sa_flags=SA_SIGINFO;

    sigaction(SIGINT,&act,NULL);
    sigaction(SIGQUIT,&act,NULL);

    while(1);

    return 0;
}

