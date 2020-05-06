#include <func.h>

void *threadFunc(void *p)
{
    //打印参数
    long num=(long)p;
    printf("the p is %ld\n",num);

    //子线程退出
    p=(void*)2;
    pthread_exit(p);
}

int main()
{
    //创建子线程
    pthread_t pthid;
    long i=1;
    int ret=pthread_create(&pthid,NULL,threadFunc,(void*)i);
    THREAD_ERROR_CHECK(ret,"pthread_create");

    //等待子线程退出
    long retValue;
    ret=pthread_join(pthid,(void**)&retValue);
    THREAD_ERROR_CHECK(ret,"pthread_join");

    printf("the ret is %ld\n",retValue);

    return 0;
}

