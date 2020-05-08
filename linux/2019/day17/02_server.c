#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //创建套接字
    int socketFd=socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //套接字与服务器地址绑定
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    ser.sin_port=htons(atoi(argv[2]));
    int ret=bind(socketFd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    ERROR_CHECK(ret,-1,"bind");

    //定义客户端地址
    struct sockaddr_in client;
    bzero(&client,sizeof(client));
    socklen_t len=sizeof(struct sockaddr);

    //服务器一定要先recvfrom
    char buf[128]={0};
    recvfrom(socketFd,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
    printf("ip:%s port:%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
    printf("%s\n",buf);

    fd_set rdset;
    int readyFd;
    while(1)
    {
        //处理描述符集合
        FD_ZERO(&rdset);
        FD_SET(socketFd,&rdset);
        FD_SET(0,&rdset);

        //select监测
        readyFd=select(socketFd+1,&rdset,NULL,NULL,NULL);
        if(readyFd>0)
        {
            //客户端有效
            if(FD_ISSET(socketFd,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=recvfrom(socketFd,buf,sizeof(buf)-1,0,(struct sockaddr*)&client,&len);
                ERROR_CHECK(ret,-1,"recvfrom");
                printf("%s\n",buf);
            }

            //标准输入有效
            if(FD_ISSET(0,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=read(0,buf,sizeof(buf)-1);
                ERROR_CHECK(ret,-1,"read");
                
                if(ret==0)
                {
                    printf("bye\n");
                    break;
                }
                sendto(socketFd,buf,strlen(buf)-1,0,(struct sockaddr*)&client,len);
            }
        }
    }
    
    //关闭描述符
    close(socketFd);

    return 0;
}

