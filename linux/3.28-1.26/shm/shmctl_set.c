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

	struct shmid_ds buf;
	int ret;
	ret=shmctl(shmid,IPC_STAT,&buf);
	if(-1==ret)
	{
		perror("shmctl1");
		return -1;
	}

	printf("euid=%d cuid=%d mode=%d\n",buf.shm_perm.uid,buf.shm_perm.cuid,buf.shm_perm.mode);
	printf("size=%ld cpid=%d nattch=%lu\n",buf.shm_segsz,buf.shm_cpid,buf.shm_nattch);

	buf.shm_perm.mode=0640;
	ret=shmctl(shmid,IPC_SET,&buf);
	if(-1==ret)
	{
		perror("shmctl1");
		return -1;
	}

	return 0;
}
