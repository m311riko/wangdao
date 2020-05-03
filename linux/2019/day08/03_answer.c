#include <func.h>

#define N 1000000

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
    
    //获取信号量集合id
    int semid=semget(1000,1,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");

    //初始化信号量集合
    int ret=semctl(semid,0,SETVAL,1);
    ERROR_CHECK(ret,-1,"semctl");

    //创建信号量pv
    struct sembuf sopp,sopv;
    sopp.sem_num=0;
    sopp.sem_op=-1;
    sopp.sem_flg=SEM_UNDO;

    sopv.sem_num=0;
    sopv.sem_op=1;
    sopv.sem_flg=SEM_UNDO;

    if(!fork())
    {
        for(int i=0;i<N;i++)
        {
            semop(semid,&sopp,1);   //加锁
            p[0]=p[0]+1;
            semop(semid,&sopv,1);   //解锁
        }
        return 0;
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            semop(semid,&sopp,1);   //加锁
            p[0]=p[0]+1;
            semop(semid,&sopv,1);   //解锁
        }
        wait(NULL);
        printf("%d\n",p[0]);
        return 0;
    }

    return 0;
}

