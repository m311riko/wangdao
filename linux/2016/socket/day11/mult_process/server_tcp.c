#include "func.h"

#define NUM 10

//信号回调函数
void recycle(int num)
{
	pid_t pid;
	while((pid=waitpid(-1,NULL,WNOHANG))>0)
	{
		printf("child died,pid=%d\n",pid);
	}
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

	//使用信号回收子进程PCB
	struct sigaction act;
	act.sa_handler=recycle;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGCHLD,&act,NULL);

	//接受连接
	struct sockaddr_in client_addr;
	bzero(&client_addr,sizeof(client_addr));
	int length=sizeof(client_addr);

	printf("start accept...\n");
	//printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

	int newfd;
	while(1)
	{	
		//父进程接收连接
		//accept阻塞的时候被信号中断，
		//处理完信号对应的操作之后，回来以后就不阻塞了，直接返回-1，
		//这时候errno被设置为EINTR
		newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
		while(-1==newfd && errno==EINTR)
		{	
			newfd=accept(sfd,(struct sockaddr*)&client_addr,&length);
		}

		printf("connect success...\n");
		printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		
		//创建子进程
		pid_t pid=fork();
		if(pid==0)
		{
			//关闭资源
			close(sfd);

			//通信
			while(1)
			{
				char buf[1024];
				bzero(buf,sizeof(buf));
				
				//读数据
				ret=read(newfd,buf,sizeof(buf));
				if(ret==-1)
				{
					perror("read");
					close(newfd);
					return -1;
				}
				else if(ret==0)
				{
					printf("client disconnect...\n");
					close(newfd);
					break;
				}
				else if(ret>0)
				{
					printf("recv buf is %s\n",buf);
					write(newfd,buf,ret);
				}
			}
			//子进程退出
			return 0;
		}
		else if(pid>0)
		{
			close(newfd);
		}
	}

	close(sfd);
	close(newfd);
	return 0;
}
