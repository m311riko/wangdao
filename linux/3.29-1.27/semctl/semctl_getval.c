#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//生成信号量
	int semid;
	semid=semget((key_t)1234,1,0600|IPC_CREAT);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}

	//获取信号量
	int ret=semctl(semid,0,GETVAL);
	if(-1==ret)
	{
		perror("semctl");
		return -1;
	}
	printf("the ret is %d\n",ret);

	return 0;
}
