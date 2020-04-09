#include <stdio.h>
#include <pthread.h>

#define NUM 10000000
pthread_mutex_t mutex;
int sum=0;

void* p_func(void *p)
{
    int i;
    for(i=0;i<NUM;i++)
    {
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
    printf("child sum is %d\n",sum);
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

    //主线程执行任务
    int i;
    for(i=0;i<NUM;i++)
    {
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
    printf("the sum is %d\n",sum);

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
