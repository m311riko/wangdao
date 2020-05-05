#include <func.h>

void sigFunc(int signum)
{
    printf("the signum is %d\n",signum);
}

int main()
{
    signal(SIGINT,sigFunc);
    while(1);

    return 0;
}

