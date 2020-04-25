#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

int beginnum=1000;

typedef struct _ProdInfo
{
	int num;
	struct _ProdInfo *next;
}ProdInfo;

ProdInfo *Head=NULL;

void *thr_producter(void *arg)
{
	while(1)
	{
		//产生节点
		ProdInfo *prod=malloc(sizeof(ProdInfo));
		prod->num=beginnum++;
		printf("producter,tid:%lu,num:%d\n",pthread_self(),prod->num);

		//生产者加锁
		pthread_mutex_lock(&mutex);
		
		//将节点放入链表
		prod->next=Head;
		Head=prod;

		pthread_mutex_unlock(&mutex);

		//生产者唤醒线程
		pthread_cond_signal(&cond);

		//生产者生产速度加快
		sleep(rand()%2);
	}

	return NULL;
}

void *thr_customer(void *arg)
{
	ProdInfo *prod=NULL;
	while(1)
	{
		//消费者加锁
		pthread_mutex_lock(&mutex);

		//循环判断链表为空就阻塞
		//if(Head==NULL)
		while(Head==NULL)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		
		//从链表中取数据
		prod=Head;
		Head=Head->next;
		printf("customer,tid:%lu,num:%d\n",pthread_self(),prod->num);

		//消费者解锁
		pthread_mutex_unlock(&mutex);
		sleep(rand()%4);
		free(prod);
	}
}

int main()
{
	//一个生产者，两个消费者
	pthread_t tid[3];
	pthread_create(&tid[0],NULL,thr_producter,NULL);
	pthread_create(&tid[1],NULL,thr_customer,NULL);
	pthread_create(&tid[2],NULL,thr_customer,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	pthread_join(tid[2],NULL);
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);

	return 0;
}
