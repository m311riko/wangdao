#include <func.h>

void sigFunc(int signum)
{
    printf("before,the signum is %d\n",signum);
    sleep(3);
    printf("after,the signum is %d\n",signum);
}

int main()
{
    signal(SIGINT,sigFunc);
    signal(SIGQUIT,sigFunc);
    while(1);

    return 0;
}

