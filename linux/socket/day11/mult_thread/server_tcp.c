#include "func.h"

#define NUM 10

typedef struct SockInfo
{
	int fd;	//套接字描述符
	struct sockaddr_in addr;	//套接字地址
	pthread_t id;	//线程ID
}SockInfo;

//子线程处理函数
void* worker(void *arg)
{
	SockInfo* info=(SockInfo*)arg;

	//打印每个线程处理的套接字IP、端口信息
	printf("client ip:%s,client port:%d\n",inet_ntoa((info->addr).sin_addr),ntohs((info->addr).sin_port));
	
	//通信
	char buf[1024];
	int ret;
	while(1)
	{
		ret=read(info->fd,buf,sizeof(buf));
		if(-1==ret)
		{
			perror("read");
			pthread_exit(NULL);	//只退出子线程，不退出主线程
		}
		else if(0==ret)
		{
			printf("tid %ld,client disconnect...\n",info->id);
			close(info->fd);
			break;
		}
		else if(ret>0)
		{
			printf("recv buf is %s\n",buf);
			write(info->fd,buf,ret);
		}
	}

	return NULL;
}

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("arg error\n");
		return -1;
	}

	//创建套接字
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}

	//绑定IP、端口
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	
	int ret;
	ret=bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind");
		close(sfd);
		return -1;
	}

	//监听
	ret=listen(sfd,NUM);
	if(-1==ret)
	{
		perror("listen");
		close(sfd);
		return -1;
	}

	//int newfd;
	//newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
	//if(-1==newfd)
	//{
	//	perror("accept");
	//	close(sfd);
	//	return -1;
	//}
	printf("start accept...\n");
	//printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

	SockInfo info[256];	//最多创建256个线程
	int i;
	for(i=0;i<sizeof(info)/sizeof(info[0]);i++)
	{
		info[i].fd=-1;
	}

	int length=sizeof(struct sockaddr_in);
	while(1)
	{
		//选一个没有被使用的，最小的数组元素
		for(i=0;i<256;i++)
		{
			if(info[i].fd==-1)
			{
				break;
			}
		}
		if(i==256)
		{
			break;
		}

		//主线程，等待接收连接请求
		info[i].fd=accept(sfd,(struct sockaddr*)&info[i].addr,&length);	
		if(info[i].fd==-1)
		{
			perror("accept");
			close(sfd);
			close(info[i].fd);
			return -1;
		}

		//创建子线程，用来通信
		pthread_create(&info[i].id,NULL,worker,&info[i]);

		//设置线程分离
		//子线程死亡不需要主线程管理
		pthread_detach(info[i].id);
	}

	close(sfd);
	
	//线程退出时只退出主线程
	pthread_exit(NULL);
	return 0;
}
