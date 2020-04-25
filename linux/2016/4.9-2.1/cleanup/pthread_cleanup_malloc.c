#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup(void *p)
{
    free(p);    //清理堆空间
    p=NULL;
    printf("the memory is free\n");
}

void* pthread_func(void *p)
{
    char *p1=(char*)malloc(10);
    pthread_cleanup_push(cleanup,p1);   //清理函数压栈
    sleep(5);
    pthread_exit(NULL);
    pthread_cleanup_pop(0);
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
