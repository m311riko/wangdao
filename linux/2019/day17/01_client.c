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
    ser.sin_family=AF_INET;
    ser.sin_addr.s_addr=inet_addr(argv[1]);
    ser.sin_port=htons(atoi(argv[2]));

    //连接服务器
    int ret=connect(socketFd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
    ERROR_CHECK(ret,-1,"connect");

    fd_set rdset;
    int readyFd;
    char buf[128]={0};
    while(1)
    {
        //清空描述符集合
        FD_ZERO(&rdset);

        //将待监测的描述符加入描述符集合
        FD_SET(socketFd,&rdset);
        FD_SET(0,&rdset);

        //select开始监测
        readyFd=select(socketFd+1,&rdset,NULL,NULL,NULL);

        //描述符有效
        if(readyFd>0)
        {
            //socketFd有效
            if(FD_ISSET(socketFd,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret=recv(socketFd,buf,sizeof(buf),0);
                
                if(ret==0)
                {
                    printf("bye\n");
                    break;
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
                    printf("bye");
                    break;
                }

                send(socketFd,buf,strlen(buf)-1,0);
            }
        }
    }

    close(socketFd);

    return 0;
}

