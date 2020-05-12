#include "pro_pool_server.h"
int exitFds[2];
void sigfunc(int signum)
{
    write(exitFds[1],&signum,1);
}

int main(int argc,char** argv)
{
    args_check(argc,4);//./server IP PORT PROCESS_NUM 
    pipe(exitFds);
    signal(SIGUSR1,sigfunc);
    int createProcessNum=atoi(argv[3]);
    proData *pManage=(proData*)calloc(createProcessNum,sizeof(proData));
    makeChild(pManage,createProcessNum);
    int socketfd;
    tcpInit(&socketfd,argv[1],argv[2]);
    struct epoll_event event,*evs;
    evs=(struct epoll_event*)calloc(createProcessNum+2,sizeof(struct epoll_event));
    int epfd=epoll_create(1);
    event.events=EPOLLIN;
    event.data.fd=socketfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,socketfd,&event);
    event.data.fd=exitFds[0];//监控是否可读，如果可读代表要退出了
    epoll_ctl(epfd,EPOLL_CTL_ADD,exitFds[0],&event);
    int i;
    for(i=0;i<createProcessNum;i++)
    {
        event.data.fd=pManage[i].fds;
        epoll_ctl(epfd,EPOLL_CTL_ADD,pManage[i].fds,&event);//每个子进程的管道对端监控起来
    }
    int fdReadyNum;
    int new_fd;
    int j;
    char flag;
    while(1)
    {
        memset(evs,0,(createProcessNum+2)*sizeof(struct epoll_event));
        fdReadyNum=epoll_wait(epfd,evs,createProcessNum+2,-1);
        for(i=0;i<fdReadyNum;i++)
        {
            if(evs[i].data.fd==socketfd)
            {
                new_fd=accept(socketfd,NULL,NULL);
                for(j=0;j<createProcessNum;j++)
                {
                    if(0==pManage[j].busy)
                    {
                        send_fd(pManage[j].fds,new_fd);
                        pManage[j].busy=1;//发送任务给子进程后，把对应子进程标识为忙碌
                        printf("%d is busy\n",pManage[j].pid);
                        break;
                    }
                }
                close(new_fd);
            }
            for(j=0;j<createProcessNum;j++)
            {
                if(pManage[j].fds==evs[i].data.fd)
                {
                    pManage[j].busy=0;
                    read(pManage[j].fds,&flag,sizeof(char));
                    printf("%d is not busy\n",pManage[j].pid);
                    break;
                }
            }
            //当进入后，代表要退出了
            if(exitFds[0]==evs[i].data.fd)
            {
                event.events=EPOLLIN;
                event.data.fd=socketfd;
                epoll_ctl(epfd,EPOLL_CTL_DEL,socketfd,&event);
                close(socketfd);
                for(j=0;j<createProcessNum;j++)
                {
                    send_fd(pManage[j].fds,-1);
                }
                for(j=0;j<createProcessNum;j++)
                {
                    wait(NULL);
                    printf("child exit success\n");
                }
                exit(0);
            }
        }
    }
    return 0;
}

