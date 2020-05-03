#include <func.h>

int main()
{
    //获取共享内存
    int shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");

    //连接、获取内容
    char *p;
    p=(char*)shmat(shmid,NULL,0);
    printf("buf is %s\n",p);
    
    //解除连接
    int ret=shmdt(p);
    ERROR_CHECK(ret,-1,"shmdt");

    //删除共享内存
    ret=shmctl(shmid,IPC_RMID,NULL);
    ERROR_CHECK(ret,-1,"shmctl");

    return 0;
}

