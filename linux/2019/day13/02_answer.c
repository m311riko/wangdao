#include <func.h>

void *threadFunc(void *p)
{
    printf("before sleep\n");
    sleep(3);
    printf("after sleep\n");

    //子线程退出
    p=(void*)2;
    pthread_exit(p);
}

int main()
{
    //创建子线程
    pthread_t pthid;
    int ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");

    //线程取消
    ret=pthread_cancel(pthid);
    THREAD_ERROR_CHECK(ret,"pthread_cancel");

    //回收子线程
    long retValue;
    ret=pthread_join(pthid,(void**)&retValue);
    THREAD_ERROR_CHECK(ret,"pthread_join");

    //打印子线程返回值
    printf("the retvalue is %ld\n",retValue);

    return 0;
}

