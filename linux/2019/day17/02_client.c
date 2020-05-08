#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //创建套接字
    int socketFd=socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //定义服务器端地址
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    ser.sin_port=htons(atoi(argv[2]));
    socklen_t len=sizeof(struct sockaddr);

    //要先发送信息
    sendto(socketFd,"I am client",11,0,(struct sockaddr*)&ser,len);
    
    fd_set rdset;
    int readyFd;
    int ret;
    char buf[128]={0};
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(socketFd,&rdset);
        FD_SET(0,&rdset);

        readyFd=select(socketFd+1,&rdset,NULL,NULL,NULL);
        if(readyFd>0)
        {
            if(FD_ISSET(socketFd,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=recvfrom(socketFd,buf,sizeof(buf),0,(struct sockaddr*)&ser,&len);
                ERROR_CHECK(ret,-1,"recvfrom");
                printf("%s\n",buf);
            }

            if(FD_ISSET(0,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=read(0,buf,sizeof(buf));
                
                if(ret==0)
                {
                    printf("bye\n");
                    break;
                }
                sendto(socketFd,buf,strlen(buf)-1,0,(struct sockaddr*)&ser,len);
            }
        }
    }

    close(socketFd);

    return 0;
}

