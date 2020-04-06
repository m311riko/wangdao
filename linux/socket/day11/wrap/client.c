#include "func.h"
#include "wrap.c"

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666

int main()
{
	//创建套接字
	int sfd;
	sfd=Socket(AF_INET,SOCK_STREAM,0);

	//连接
	struct sockaddr_in serv_addr;
	bzero(&serv_addr,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERV_PORT);
	inet_pton(AF_INET,SERV_IP,&serv_addr.sin_addr.s_addr);

	Connect(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	printf("connect success...\n");

	//通信
	char buf[128];
	bzero(buf,sizeof(buf));
	while(1)
	{
		fgets(buf,sizeof(buf),stdin);
		int ret;
		ret=Write(sfd,buf,strlen(buf));

		ret=Read(sfd,buf,sizeof(buf));
		Write(STDOUT_FILENO,buf,ret);
	}

	Close(sfd);
	return 0;
}
