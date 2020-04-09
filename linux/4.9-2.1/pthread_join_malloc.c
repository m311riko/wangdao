#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *p1;
void* thread_func(void *p)
{
    printf("I am child\n");
    p1=(char*)malloc(10);
    free(p1);   //子线程中申请的空间，必须free掉
    //p1=NULL;    //必须把p1置为NULL，因为这里没有及时回收，所以下面才能写入
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    pthread_create(&thid,NULL,thread_func,NULL);    //创建子线程
    int ret;
    ret=pthread_join(thid,NULL);    //等待子线程退出，回收资源
    if(0!=ret)
    {
        printf("res is %d\n",ret);
        return -1;
    }

    //因为子线程没有置NULL，所以这里才可以写入
    strcpy(p1,"hello");
    printf("the p1 is %s\n",p1);

    return 0;
}
