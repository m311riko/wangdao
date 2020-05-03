#include <func.h>

int main()
{
    //创建共享内存
    int shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");

    //进程与共享内存连接
    char *p;
    p=(char*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,NULL,"shmat");
    
    //向共享内存写入
    strcpy(p,"hello");
    
    //进程与共享内存解除连接
    int ret=shmdt(p);
    ERROR_CHECK(ret,-1,"shmdt");

    return 0;
}

