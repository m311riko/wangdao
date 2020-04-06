#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PROJ_ID 1

int main()
{
	int shmid;
	shmid=shmget((key_t)123,1<<12,0600|IPC_CREAT);
	if(-1==shmid)
	{
		perror("shmget1");
		return -1;
	}

	printf("the shmid is %d\n",shmid);

	return 0;
}
