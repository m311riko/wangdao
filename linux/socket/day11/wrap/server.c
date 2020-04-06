#include "func.h"
#include "wrap.c"

#define SERV_PORT 6666

int main()
{
	//创建socket
	int sfd;
	sfd=Socket(AF_INET,SOCK_STREAM,0);

	//绑定
	struct sockaddr_in serv_addr;
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(SERV_PORT);
	Bind(sfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	//监听
	Listen(sfd,2);

	//接收连接
	struct sockaddr_in clie_addr;
	int clie_addr_len;
	clie_addr_len=sizeof(clie_addr);
	int cfd;
	cfd=Accept(sfd,(struct sockaddr*)&clie_addr,&clie_addr_len);

	printf("connect success...\n");
    printf("client IP=%s,client port=%d\n",inet_ntoa(clie_addr.sin_addr),ntohs(clie_addr.sin_port));

	//通信
	char buf[128];
	bzero(buf,sizeof(buf));
	int ret;
	while(1)
	{
		ret=Read(cfd,buf,sizeof(buf));
		Write(STDOUT_FILENO,buf,ret);

		int i;
		for(i=0;i<ret;i++)
		{
			buf[i]=toupper(buf[i]);
		}
		Write(cfd,buf,ret);
	}

	Close(sfd);
	Close(cfd);
	return 0;
}
