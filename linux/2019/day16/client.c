#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3);

    //创建socket套接字
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //要连接的ip地址和端口
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(argv[2]));  //主机转网络
    ser.sin_addr.s_addr=inet_addr(argv[1]);

    //连接服务器
    int ret=connect(socketFd,(struct sockaddr*)&ser,sizeof(ser));
    ERROR_CHECK(ret,-1,"connect");

    //向客户端发送信息
    const char *buf="hello";
    send(socketFd,buf,strlen(buf),0);

    //从客户端读取信息
    char buf1[128]={0};
    recv(socketFd,buf1,sizeof(buf),0);
    printf("%s\n",buf1);

    return 0;
}

