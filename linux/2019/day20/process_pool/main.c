#include "process_pool.h"

#define DEBUG

int main(int argc,char** argv)
{
    ARGS_CHECK(argc,4);

    int processNum=atoi(argv[3]);
    process_data_t *pData=(process_data_t*)calloc(processNum,sizeof(process_data_t));
    makeChild(pData,processNum);

#ifdef DEBUG
    for(int i=0;i<processNum;i++)
    {
        printf("%d,%d\n",pData[i].pid,pData[i].fd);
    }
#endif

    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);

    struct epoll_event *evs;
    evs=(struct epoll_event*)calloc(processNum+1,sizeof(struct epoll_event));
    int epfd=epoll_create(1);
    epollInAdd(epfd,socketFd);
    for(int i=0;i<processNum;i++)
    {
        epollInAdd(epfd,pData[i].fd);
    }

    int readyNum;
    int newFd;
    char flag;
    while(1)
    {
        readyNum=epoll_wait(epfd,evs,processNum+1,-1);

        for(int i=0;i<readyNum;i++)
        {
            if(evs[i].data.fd==socketFd)
            {
                newFd=accept(socketFd,NULL,NULL);

                //找到不忙碌的子进程
                for(int j=0;j<processNum;j++)
                {
                    if(0==pData[j].busy)
                    {
                        sendFd(pData[j].fd,newFd);
                        close(newFd);
                        pData[j].busy=1;//发送任务给子进程后，把对应子进程标识为忙碌
                        printf("%d is busy\n",pData[j].pid);
                        break;
                    }
                }
            }

            for(int j=0;j<processNum;j++)
            {
                if(pData[j].fd==evs[i].data.fd)
                {
                    pData[j].busy=0;
                    read(pData[j].fd,&flag,sizeof(char));
                    printf("%d is not busy\n",pData[j].pid);
                    break;
                }
            }
        }
    }
    return 0;
}

