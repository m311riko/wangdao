#include "func.h"

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("args error\n");
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

	//连接
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	
	int ret;
	ret=connect(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connetc");
		close(sfd);
		return -1;
	}
	printf("connect succuss...\n");

	//通信
	//发送数据
	char buf[128];
	bzero(buf,sizeof(buf));
	while(1)
	{
		//发送数据
		char buf[512];
		fgets(buf,sizeof(buf),stdin);
		write(sfd,buf,strlen(buf)+1);

		//接收数据
		ret=read(sfd,buf,sizeof(buf));
		if(ret==0)
		{
			printf("server disconnect...\n");
			break;
		}
		else if(ret==-1)
		{
			perror("read");
			close(sfd);
			return -1;
		}
		else if(ret>0)
		{
			printf("from server: %s\n",buf);
		}
	}

	close(sfd);
	return 0;
}
