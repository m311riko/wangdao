#include "process_pool.h"

int tcpInit(int *sfd,char *ip,char *port)
{
    //创建套接字描述符
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //初始化服务器地址
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(port));
    ser.sin_addr.s_addr=inet_addr(ip);

    //绑定
    int ret=bind(socketFd,(struct sockaddr*)&ser,sizeof(ser));
    ERROR_CHECK(ret,-1,"bind");

    //监听
    listen(socketFd,10);
    *sfd=socketFd;

    return 0;
}

