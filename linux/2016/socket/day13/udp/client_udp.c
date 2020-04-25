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

	//初始化服务器IP和端口
	struct sockaddr_in serv;
	memset(&serv,0,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(8765);
	inet_pton(AF_INET,"127.0.0.1",&serv.sin_addr.s_addr);

	//通信
	while(1)
	{
		//发送数据		
		char buf[1024];
		bzero(buf,sizeof(buf));
		fgets(buf,sizeof(buf),stdin);

		sendto(fd,buf,strlen(buf)+1,0,(struct sockaddr*)&serv,sizeof(serv));

		//接收数据
		recvfrom(fd,buf,sizeof(buf),0,NULL,NULL);
		printf("recv buf is %s\n",buf);
	}

	close(fd);
	return 0;
}
