#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void* thr(void *arg)
{
	printf("I am a thread\n");
	return NULL;
}

int main()
{
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	//设置属性分离，线程执行完了以后不需要回收
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_t tid;
	pthread_create(&tid,&attr,thr,NULL);
	int ret;
	if((ret=pthread_join(tid,NULL))>0)
	{
		printf("join error:%d,%s\n",ret,strerror(ret));
	}

	pthread_attr_destroy(&attr);

	return 0;
}
