#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3);

    //创建socket套接字
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");
    
    //socket绑定ip地址
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_port=htons(atoi(argv[2]));
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    int ret=bind(socketFd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    ERROR_CHECK(ret,-1,"bind");

    //开始监听
    ret=listen(socketFd,10);
    ERROR_CHECK(ret,-1,"listen");

    //接受连接
    struct sockaddr_in client;
    bzero(&client,sizeof(client));
    socklen_t len=sizeof(client);
    int new_fd=accept(socketFd,(struct sockaddr*)&client,&len);
    ERROR_CHECK(new_fd,-1,"accept");

    //打印客户端的ip和端口信息
    printf("I am server, ip=%s, port=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));

    //读取客户端发送的信息
    char buf[128]={0};
    recv(new_fd,buf,sizeof(buf),0);
    printf("%s\n",buf);

    //向客户端发送信息
    sleep(2);
    const char *buf1="world";
    send(new_fd,buf1,strlen(buf1),0);

    //关闭描述符
    close(socketFd);
    close(new_fd);

    return 0;
}

