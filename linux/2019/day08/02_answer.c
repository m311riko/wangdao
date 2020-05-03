#include <func.h>

#define N 10000000

int main()
{
    //创建共享内存
    int shmid=shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmget");

    //连接
    int *p;
    p=(int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=0;
    
    //创建子进程
    pid_t pid;
    pid=fork();

    if(0==pid)
    {
        for(int i=0;i<N;i++)
        {
            p[0]=p[0]+1;
        }
        return 0;
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            p[0]=p[0]+1;
        }
        wait(NULL);
        printf("%d\n",p[0]);
        return 0;
    }

    return 0;
}

