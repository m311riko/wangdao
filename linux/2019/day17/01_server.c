#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //创建套接字
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //套接字bind地址
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=inet_addr(argv[1]); //主机序转网络序
    ser.sin_port=htons(atoi(argv[2]));  //主机端口号转网络端口号
    int ret=bind(socketFd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    ERROR_CHECK(ret,-1,"bind");

    //监听
    ret=listen(socketFd,10);
    ERROR_CHECK(ret,-1,"listen");

    //套接字与客户端连接
    struct sockaddr_in client;
    bzero(&client,sizeof(client));
    socklen_t len;
    int new_fd;

    //永久监测的描述符集合
    fd_set tmpset;
    FD_ZERO(&tmpset);
    FD_SET(socketFd,&tmpset);
    FD_SET(0,&tmpset);

    //实际监测的描述符集合
    fd_set rdset;

    int readyFd;
    char buf[128]={0};
    while(1)
    {
        //要监测的描述符集合
        FD_ZERO(&rdset);
        memcpy(&rdset,&tmpset,sizeof(fd_set));

        //select开始监测
        readyFd=select(14,&rdset,NULL,NULL,NULL);

        //有效的描述符数量
        if(readyFd>0)
        {
            //socketFd描述符有效
            if(FD_ISSET(socketFd,&rdset))
            {
                //与客户端连接
                bzero(&client,sizeof(client));
                len=sizeof(client);
                new_fd=accept(socketFd,(struct sockaddr*)&client,&len);
                ERROR_CHECK(new_fd,-1,"accept");

                //打印客户端ip地址、端口号
                printf("ip:%s port:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

                FD_SET(new_fd,&tmpset);   
            }

            //new_fd有效
            if(FD_ISSET(new_fd,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=recv(new_fd,buf,sizeof(buf),0);

                //客户端断开连接
                if(ret==0)
                {
                    printf("bye\n");
                    
                    //清空描述符
                    FD_CLR(new_fd,&tmpset);
                    continue;
                }

                printf("%s\n",buf);
            }

            //标准输入有效
            if(FD_ISSET(0,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=read(0,buf,sizeof(buf));

                if(ret==0)
                {
                    printf("bye\n");
                    break;
                }

                send(new_fd,buf,strlen(buf)-1,0);
            }
        }
    }

    //关闭描述符
    close(new_fd);
    close(socketFd);

    return 0;
}

