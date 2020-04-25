#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thr(void* arg)
{
	printf("I am thread, pid=%d, tid=%ld\n",getpid(),pthread_self());
	return (void*)100;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,thr,NULL);

	void *ret;
	pthread_join(tid,&ret);
	printf("ret is %d\n",(int)ret);

	return 0;
}
