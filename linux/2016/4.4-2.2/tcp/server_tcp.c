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

	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);
	int newfd;
	char buf[128];
	while(1)
	{
		//接受连接
		newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
		if(-1==newfd)
		{
			perror("accept");
			close(sfd);
			return -1;
		}
		printf("connect success...\n");
		printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

		//通信
		//接收数据
		bzero(buf,sizeof(buf));
		ret=recv(newfd,buf,sizeof(buf),0);
		if(-1==ret)
		{
			perror("recv");
			close(sfd);
			close(newfd);
			return -1;
		}
		printf("the message is %s\n",buf);
		
		//发送数据
		bzero(buf,sizeof(buf));
		strcpy(buf,"hello");
		ret=send(newfd,buf,strlen(buf),0);
		if(-1==ret)
		{
			perror("send");
			close(sfd);
			close(newfd);
			return -1;
		}
	}

	close(sfd);
	close(newfd);
	return 0;
}
