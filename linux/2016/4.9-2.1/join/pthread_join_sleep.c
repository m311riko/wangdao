#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void *p)
{
    printf("I am child\n");
    sleep(3);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    pthread_create(&thid,NULL,thread_func,NULL);    //创建子线程
    int ret;
    ret=pthread_join(thid,NULL);    //等待3秒后子线程退出，回收资源
    if(0!=ret)
    {
        printf("res is %d\n",ret);
        return -1;
    }

    return 0;
}
