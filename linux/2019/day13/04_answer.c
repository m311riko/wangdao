#include <func.h>

void *threadFunc(void *p)
{
    //获取时间并打印
    time_t t;
    time(&t);   //获取当前时间
    struct tm *t1=gmtime(&t);   //线程不安全接口
    printf("thread1:%d.%d.%d %d:%d%d\n",t1->tm_year+1900,
                                t1->tm_mon+1,
                                t1->tm_mday,
                                t1->tm_hour+1,
                                t1->tm_min+1,
                                t1->tm_sec);

    //睡眠5秒
    sleep(5);

    //获取时间并打印
    printf("thread2:%d.%d.%d %d:%d%d\n",t1->tm_year+1900,
                                t1->tm_mon+1,
                                t1->tm_mday,
                                t1->tm_hour+1,
                                t1->tm_min+1,
                                t1->tm_sec);

    //子线程退出
    pthread_exit(NULL);
}

int main()
{
    //创建子线程
    pthread_t pthid;
    int ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");

    //睡眠2秒
    sleep(2);
    
    //获取时间并打印
    time_t t=time(NULL);
    struct tm *t1=gmtime(&t);
    printf("main:%d.%d.%d %d:%d%d\n",t1->tm_year+1900,
                                t1->tm_mon+1,
                                t1->tm_mday,
                                t1->tm_hour+1,
                                t1->tm_min+1,
                                t1->tm_sec);

    //回收子线程
    ret=pthread_join(pthid,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_join");

    return 0;
}

