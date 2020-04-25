#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

//使用常量初始化mutex
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

int sum=0;

void *thr1(void *arg)
{
	while(1)
	{
		//加锁
		pthread_mutex_lock(&mutex);

		printf("hello");
		sleep(rand()%3);
		printf("world\n");

		//解锁
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

void *thr2(void *arg)
{
	while(1)
	{
		//加锁
		pthread_mutex_lock(&mutex);

		printf("HELLO");
		sleep(rand()%3);
		printf("WORLD\n");

		//解锁
		pthread_mutex_unlock(&mutex);
		sleep(rand()%3);
	}
}

int main()
{
	//创建线程
	pthread_t tid[2];
	pthread_create(&tid[0],NULL,thr1,NULL);
	pthread_create(&tid[1],NULL,thr2,NULL);

	//回收线程
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	return 0;
}
