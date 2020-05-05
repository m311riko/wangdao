#include <func.h>

int main()
{
    //设置阻塞信号集
    sigset_t mask;

    //清空阻塞信号集
    sigemptyset(&mask);

    //填入2号信号
    sigaddset(&mask,SIGINT);

    //全程阻塞2号信号
    sigprocmask(SIG_BLOCK,&mask,NULL);

    //打印
    printf("before,sigprocmask\n");

    //睡眠5秒
    sleep(5);

    //检测是否挂起
    sigset_t pending;
    sigemptyset(&pending);
    sigpending(&pending);
    if(sigismember(&pending,SIGINT))
    {
        printf("SIGINT is pending\n");
    }
    else
    {
        printf("SIGINT is not pending\n");
    }

    //打印
    printf("after,sigprocmask\n");

    //解除全程阻塞
    sigprocmask(SIG_UNBLOCK,&mask,NULL);

    return 0;
}

