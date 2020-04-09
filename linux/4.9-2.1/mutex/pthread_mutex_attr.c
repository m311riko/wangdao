#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

pthread_mutex_t mutex;

void* p_func(void *p)
{
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    printf("I am child\n");
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    //设置锁属性
    int ret;
    pthread_mutexattr_t attr;
    int i;
    i=PTHREAD_MUTEX_RECURSIVE_NP;
    memcpy(&attr,&i,4);

    //初始化锁
    ret=pthread_mutex_init(&mutex,&attr);
    if(0!=ret)
    {
        printf("pthread_mutex_init ret=%d\n",ret);
        return -1;
    }

    //创建子线程
    pthread_t pthid;
    pthread_create(&pthid,NULL,p_func,NULL);
    
    //主线程等待回收子线程
    ret=pthread_join(pthid,NULL);
    if(0!=ret)
    {
        printf("pthread_join ret=%d\n",ret);
        return -1;
    }

    //回收锁
    ret=pthread_mutex_destroy(&mutex);
    if(0!=ret)
    {
        printf("pthread_mutex_destroy ret=%d\n",ret);
        return -1;
    }

    return 0;
}
