#include "func.h"

#define NUM 10

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

	//接受连接
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);

	printf("start accept...\n");
	//printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

	//定义poll相关变量
	struct pollfd allfd[1024];
	int max_index=0;
	int i;
	for(i=0;i<1024;i++)
	{
		allfd[i].fd=-1;
	}
	allfd[0].fd=sfd;
	allfd[0].events=POLLIN;

	while(1)
	{
		//委托内核做IO检测
		int i=0;
		int ret=poll(allfd,max_index+1,-1);
		if(ret==-1)
		{
			perror("poll error");
			close(sfd);
			return -1;
		}

		//判断是否有连接请求
		if(allfd[0].revents & POLLIN)
		{
			int cfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
			
			//将cfd添加到allfd数组
			for(i=0;i<1024;i++)
			{
				if(allfd[i].fd==-1)
				{
					allfd[i].fd=cfd;
					break;
				}
			}

			//更新数组最后一个元素下标
			max_index=max_index<i?i:max_index;
		}

		//已经连接的客户端有数据到达
		for(i=1;i<=max_index;i++)
		{
			int fd=allfd[i].fd;
			if(fd==-1)
			{
				continue;
			}

			if(allfd[i].revents & POLLIN)
			{
				char buf[1024];
				bzero(buf,sizeof(buf));

				//读数据
				int len=recv(fd,buf,sizeof(buf),0);
				if(-1==len)
				{
					perror("recv error");
					return -1;
				}
				else if(0==len)
				{
					allfd[i].fd=-1;
					close(fd);
					printf("client disconnect...\n");
				}
				else if(len>0)
				{
					printf("recv buf is %s\n",buf);
					
					for(i=0;i<len;i++)
					{
						buf[i]=toupper(buf[i]);
					}
					printf("buf toupper is %s\n",buf);
					
					//写数据
					send(fd,buf,strlen(buf)+1,0);
				}
			}
		}
	}

	close(sfd);
	return 0;
}
