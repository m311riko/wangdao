#include "func.h"

int main(int argc,char* argv[])
{
	//创建套接字
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if(-1==fd)
	{
		perror("socket");
		return -1;
	}

	//绑定本地IP和端口
	struct sockaddr_in serv;
	memset(&serv,0,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(8765);
	serv.sin_addr.s_addr=htonl(INADDR_ANY);

	int ret=bind(fd,(struct sockaddr*)&serv,sizeof(serv));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}

	//通信
	char buf[1024];
	bzero(buf,sizeof(buf));
	struct sockaddr_in client_addr;
	int length=sizeof(client_addr);
	while(1)
	{
		//接收数据
		int len=recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&client_addr,&length);
		if(-1==len)
		{
			perror("recvfrom");
			return -1;
		}
		printf("recv buf is %s\n",buf);

		//发送数据
		sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&client_addr,sizeof(client_addr));
	}

	close(fd);
	return 0;
}
