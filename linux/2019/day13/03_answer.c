#include <func.h>

typedef struct 
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    long tickets;
}thData;

void *threadFunc1(void *p)
{
    thData *p1=(thData*)p;
    long count=0;

    //循环卖票
    while(1)
    {
        //加锁
        pthread_mutex_lock(&p1->mutex);

        //判断票数
        if(p1->tickets>0)
        {
            //卖票
            printf("I am window1, I will sale tickets %ld\n",p1->tickets);
            p1->tickets--;
            count++;

            //条件满足，发信号
            if(0==p1->tickets)
            {
                pthread_cond_signal(&p1->cond);
            }

            printf("I am window1, sale ok %ld\n",p1->tickets);

            //解锁
            pthread_mutex_unlock(&p1->mutex);
        }
        else
        {
            pthread_mutex_unlock(&p1->mutex);
            break;
        }

        sleep(1);
    }

    pthread_exit((void*)count);
}

void *threadFunc2(void *p)
{
    thData *p1=(thData*)p;
    long count=0;

    //循环卖票
    while(1)
    {
        //加锁
        pthread_mutex_lock(&p1->mutex);

        //判断票数
        if(p1->tickets>0)
        {
            //卖票
            printf("I am window2, I will sale tickets %ld\n",p1->tickets);
            p1->tickets--;
            count++;

            //条件满足，发信号
            if(0==p1->tickets)
            {
                pthread_cond_signal(&p1->cond);
            }

            printf("I am window2, sale ok %ld\n",p1->tickets);
            
            //解锁
            pthread_mutex_unlock(&p1->mutex);
        }
        else
        {
            pthread_mutex_unlock(&p1->mutex);
            break;
        }

        sleep(1);
    }

    pthread_exit((void*)count);
}

void *threadFunc3(void *p)
{
    thData *p1=(thData*)p;

    //加锁
    pthread_mutex_lock(&p1->mutex);
    if(p1->tickets>0)
    {
        //等待在条件变量上
        pthread_cond_wait(&p1->cond,&p1->mutex);
        p1->tickets=10;
        pthread_mutex_unlock(&p1->mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    //初始化锁
    thData threadInfo;
    int ret=pthread_mutex_init(&threadInfo.mutex,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_mutex_init");

    //初始化条件变量
    ret=pthread_cond_init(&threadInfo.cond,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_cond_init");

    //创建子线程
    pthread_t pthid1;
    pthread_t pthid2;
    pthread_t pthid3;
    threadInfo.tickets=20;
    ret=pthread_create(&pthid1,NULL,threadFunc1,(void*)&threadInfo);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    ret=pthread_create(&pthid2,NULL,threadFunc2,(void*)&threadInfo);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    ret=pthread_create(&pthid3,NULL,threadFunc3,(void*)&threadInfo);
    THREAD_ERROR_CHECK(ret,"pthread_create");

    //回收子线程
    long count1;
    ret=pthread_join(pthid1,(void**)&count1);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    long count2;
    ret=pthread_join(pthid2,(void**)&count2);
    THREAD_ERROR_CHECK(ret,"pthread_join");
    ret=pthread_join(pthid3,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");

    //打印票数
    printf("the count is %ld\n",count1+count2);

    return 0;
}

