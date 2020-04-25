#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define PROJ_ID 1

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("argc error\n");
		return 0;
	}
	
	//生成key
	key_t skey;
	skey=ftok(argv[1],PROJ_ID);
	if(-1==skey)
	{
		perror("ftok");
		return -1;
	}
	printf("the key is %d\n",skey);

	//创建信号量
	int semid;
	semid=semget(skey,1,0600|IPC_CREAT);
	if(-1==semid)
	{
		perror("semget");
		return -1;
	}
	printf("the semid is %d\n",semid);

	return 0;
}
