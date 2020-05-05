#include <func.h>

int main()
{
    //创建信号量集合
    int semid=semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semid,-1,"semget");

    //定义仓库位置、产品个数信息
    unsigned short arr[2]={10,0};

    //使用上述信息初始化信号量集合
    int ret=semctl(semid,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl");

    //定义信号量集合中的信号量操作
    struct sembuf sopp,sopv;

    //创建子进程
    if(!fork())
    {
        //定义信号量的操作
        //产品数减1
        sopp.sem_num=1;
        sopp.sem_op=-1;
        sopp.sem_flg=SEM_UNDO;

        //仓库数加1
        sopv.sem_num=0;
        sopv.sem_op=1;
        sopv.sem_flg=SEM_UNDO;

        //子进程一直消费
        while(1)
        {
            printf("I am cumtomer,space num=%d,producer num=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            semop(semid,&sopp,1);
            semop(semid,&sopv,1);
            printf("I am cumtomer,space num=%d,producer num=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            sleep(2);
        }
    }
    else
    {
        //定义信号量的操作
        //仓库数减1
        sopp.sem_num=0;
        sopp.sem_op=-1;
        sopp.sem_flg=SEM_UNDO;

        //产品数加1
        sopv.sem_num=1;
        sopv.sem_op=1;
        sopv.sem_flg=SEM_UNDO;
        
        while(1)
        {
            printf("I am producer,space num=%d,producer num=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            semop(semid,&sopp,1);
            semop(semid,&sopv,1);
            printf("I am producer,space num=%d,producer num=%d\n",semctl(semid,0,GETVAL),semctl(semid,1,GETVAL));
            sleep(1);
        }
    }
    return 0;
}

