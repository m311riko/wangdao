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
    pthread_exit(NULL);
    pthread_cleanup_pop(0); //在cleanup之前exit
    pthread_cleanup_pop(0); //即使参数是0，cleanup函数也会执行
}

int main()
{
    pthread_t pthid;
    pthread_create(&pthid,NULL,pthread_func,NULL);
    int ret=pthread_join(pthid,NULL);
    if(0!=ret)
    {
        printf("ret is %d\n",ret);
        return -1;
    }

    return 0;
}
