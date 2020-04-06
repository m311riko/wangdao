#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thr(void* arg)
{
	printf("I am thread, pid=%d, tid=%ld\n",getpid(),pthread_self());
	printf("I will die\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,thr,NULL);
	printf("I am main thread, pid=%d, tid=%lu\n",getpid(),pthread_self());
	sleep(10);

	printf("I will die\n");
	pthread_exit(NULL);
	return 0;
}
