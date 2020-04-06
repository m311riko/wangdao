#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PROJ_ID 1

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	key_t skey;
	skey=ftok(argv[1],PROJ_ID);
	if(-1==skey)
	{
		perror("ftok");
		return -1;
	}
	printf("the key is %d\n",skey);

	int shmid;
	shmid=shmget(skey,1<<12,0600|IPC_CREAT);
	if(-1==shmid)
	{
		perror("shmget1");
		return -1;
	}
	printf("the shmid is %d\n",shmid);

	int ret;
	ret=shmctl(shmid,IPC_RMID,NULL);
	if(-1==ret)
	{
		perror("shmctl");
		return -1;
	}

	return 0;
}
