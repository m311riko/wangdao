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

	//定义select相关变量
	int maxfd=sfd;
	fd_set reads,temp;
	FD_ZERO(&reads);
	FD_SET(sfd,&reads);

	while(1)
	{
		//委托内核做IO检测
		temp=reads;
		int ret=select(maxfd+1,&temp,NULL,NULL,NULL);
		if(-1==ret)
		{
			perror("select error");
			close(sfd);
			return -1;
		}

		//内核检测到客户端IO操作
		//客户端发起新连接
		if(FD_ISSET(sfd,&temp))
		{
			//接受连接请求
			int cfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
			if(-1==cfd)
			{
				perror("accept error");
				close(sfd);
				return -1;
			}

			printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

			//将cfd加入待检测的读集合，下一次可以检测到
			FD_SET(cfd,&reads);

			//更新最大的文件描述符
			maxfd=maxfd<cfd?cfd:maxfd;
		}

		//已经连接上的客户端有数据到达
		int i;
		for(i=sfd+1;i<=maxfd;i++)
		{
			if(FD_ISSET(i,&temp))
			{
				char buf[1024];
				bzero(buf,sizeof(buf));

				//接收数据
				int len=recv(i,buf,sizeof(buf),0);
				if(-1==len)
				{
					perror("recv error");
					close(sfd);
					close(i);
					return -1;
				}
				else if(len==0)
				{
					printf("client disconnetc...\n");
					close(i);
					FD_CLR(i,&reads);
				}
				else if(len>0)
				{
					printf("recv buf:%s\n",buf);

					//发送数据
					send(i,buf,strlen(buf)+1,0);
				}
			}
		}
	}

	close(sfd);
	return 0;
}
