#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 10000000
pthread_mutex_t mutex;
int sum=0;

void* p_func(void *p)
{
    pthread_mutex_lock(&mutex);
    printf("I am child\n");
    while(1);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    //初始化锁
    int ret;
    ret=pthread_mutex_init(&mutex,NULL);
    if(0!=ret)
    {
        printf("pthread_mutex_init ret=%d\n",ret);
        return -1;
    }

    //创建子线程
    pthread_t pthid;
    pthread_create(&pthid,NULL,p_func,NULL);

    sleep(1);   //主线程等子线程执行
    ret=pthread_mutex_trylock(&mutex);  //主线程尝试加锁
    printf("pthread_mutex_trylock ret=%d\n",ret);

    //主线程等待回收子线程
    ret=pthread_join(pthid,NULL);
    if(0!=ret)
    {
        printf("pthread_join ret=%d\n",ret);
        return -1;
    }

    //销毁锁
    ret=pthread_mutex_destroy(&mutex);
    if(0!=ret)
    {
        printf("pthread_mutex_destroy ret=%d\n",ret);
        return -1;
    }

    return 0;
}
