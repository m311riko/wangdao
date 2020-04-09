#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void *p)
{
    printf("I am child\n");
    while(1);   //子线程陷入死循环
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    pthread_create(&thid,NULL,thread_func,NULL);    //创建子线程
    sleep(3);   //等待进入子线程
    int ret;
    ret=pthread_cancel(thid);   //主线程杀死子线程
    if(0!=ret)
    {
        printf("res is %d\n",ret);
        return -1;
    }

    return 0;
}
