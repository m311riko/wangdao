#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //创建套接字
    int socketFd=socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(socketFd,-1,"socket");

    //定义服务器地址
    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    ser.sin_port=htons(atoi(argv[2]));

    //连接服务器
    int ret=connect(socketFd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    ERROR_CHECK(ret,-1,"connect");

    //创建epoll句柄
    int epfd=epoll_create(1);

    //注册事件
    struct epoll_event event,evs[2];
    event.data.fd=0;
    event.events=EPOLLIN;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,0,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    event.data.fd=socketFd;
    ret=epoll_ctl(epfd,EPOLL_CTL_ADD,socketFd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    char buf[128]={0};
    int readyFd;
    while(1)
    {
        //等待事件发生
        readyFd=epoll_wait(epfd,evs,2,-1);

        //遍历描述符
        for(int i=0;i<readyFd;i++)
        {
            //服务器端描述符
            if(evs[i].data.fd==socketFd)
            {
                bzero(buf,sizeof(buf));
                ret=recv(socketFd,buf,sizeof(buf),0);
    
                if(ret==0)
                {
                    printf("bye\n");
                    goto end;
                }

                printf("%s\n",buf);
            }

            //标准输入
            if(evs[i].data.fd==0)
            {
                bzero(buf,sizeof(buf));
                ret=read(0,buf,sizeof(buf));

                if(ret==0)
                {
                    printf("bye\n");
                    goto end;
                }

                send(socketFd,buf,strlen(buf)-1,0);
            }
        }

    }
end:

    close(socketFd);

    return 0;
}

