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

	printf("start connect...\n");
	//printf("client ip:%s,client port:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

	//创建epoll树根节点
	int epfd=epoll_create(2000);
	
	//初始化epoll树
	//设置边沿触发模式
	struct epoll_event ev;
	ev.events=EPOLLIN | EPOLLET;
	ev.data.fd=sfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);

	//数组传出参数
	struct epoll_event all[2000];
	while(1)
	{
		//使用epoll通知内核对文件IO做检测
		ret=epoll_wait(epfd,all,sizeof(all)/sizeof(all[0]),-1);
		printf("-----epoll_wait-----\n");

		//遍历all数组中的前ret个元素
		for(int i=0;i<ret;i++)
		{
			int fd=all[i].data.fd;

			//判断是否有新连接
			if(fd==sfd)
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

				//将新得到的cfd挂到树上
				//设置边沿触发模式
				struct epoll_event temp;
				temp.events=EPOLLIN | EPOLLET;
				temp.data.fd=cfd;
				epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&temp);
			}
			else
			{
				//处理已经连接的客户端发过来的数据
				//不处理读操作以外的操作
				if(!all[i].events & EPOLLIN)
				{
					continue;
				}

				//读数据
				char buf[5];
				bzero(buf,sizeof(buf));
				ret=recv(fd,buf,sizeof(buf),0);
				if(ret==-1)
				{
					perror("recv error");
					close(sfd);
					return -1;
				}
				else if(ret==0)
				{
					printf("client disconnect...\n");

					//将fd从树上删除
					epoll_ctl(epfd,EPOLL_CTL_DEL,fd,NULL);
					close(fd);
					break;
				}
				else if(ret>0)
				{
					//printf("recv buf is %s\n",buf);
					write(STDOUT_FILENO,buf,ret);
					send(fd,buf,ret,0);
				}
			}
		}
	}

	close(sfd);
	return 0;
}
