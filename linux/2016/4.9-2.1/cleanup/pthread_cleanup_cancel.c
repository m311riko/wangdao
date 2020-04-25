#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void *p)
{
    printf("the p is %d\n",(int)p);
}

void* pthread_func(void *p)
{
    pthread_cleanup_push(cleanup,(void*)1);
    pthread_cleanup_push(cleanup,(void*)2);
    sleep(5);
    pthread_cleanup_pop(0); //使用pthread_cancel函数
    pthread_cleanup_pop(0); //即使参数是0也执行
}

int main()
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,pthread_func,NULL);
    int ret;
    ret=pthread_cancel(pthid);
    if(0!=ret)
    {
        printf("pthread_cancel ret=%d\n",ret);
    }
    ret=pthread_join(pthid,NULL);
    if(0!=ret)
    {
        printf("pthread_join ret is %d\n",ret);
        return -1;
    }

    return 0;
}
