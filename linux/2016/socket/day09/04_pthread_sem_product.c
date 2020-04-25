#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#define COUNT 5

sem_t blank,xfull;
int queue[COUNT];
int beginnum=100;

void *thr_producter(void *arg)
{
	int i=0;
	while(1)
	{
		//申请信号量
		sem_wait(&blank);
		
		//生产
		printf("producter,tid:%lu,num:%d\n",pthread_self(),beginnum);
		queue[(i++)%COUNT]=beginnum++;
		
		//释放信号量
		sem_post(&xfull);
		sleep(rand()%3);
	}
	return NULL;
}

void *thr_customer(void *arg)
{
	int i=0;
	int num=0;
	while(1)
	{
		//申请信号量
		sem_wait(&xfull);

		//消费
		num=queue[(i++)%COUNT];
		printf("customer,tid:%lu,num:%d\n",pthread_self(),num);

		//释放信号量
		sem_post(&blank);
		sleep(rand()%3);
	}
	return NULL;
}

int main()
{
	//初始化信号量
	sem_init(&blank,0,COUNT);
	sem_init(&xfull,0,0);

	//创建生产者、消费者线程
	pthread_t tid[2];
	pthread_create(&tid[0],NULL,thr_producter,NULL);
	pthread_create(&tid[1],NULL,thr_customer,NULL);

	//回收线程资源
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	//销毁信号量
	sem_destroy(&blank);
	sem_destroy(&xfull);

	return 0;
}
