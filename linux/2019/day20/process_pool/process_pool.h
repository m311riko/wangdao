#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define ARGS_CHECK(argc,num)\
{\
    if(argc!=num)\
    {\
        printf("error args!\n");\
        return -1;\
    }\
}

#define ERROR_CHECK(ret,retVal,msg)\
{\
    if(ret==retVal)\
    {\
        perror(msg);\
        return -1;\
    }\
}

#define THREAD_ERROR_CHECK(ret,funcName)\
{\
    if(ret!=0)\
    {\
        printf("%s:%s\n",funcName,strerror(ret));\
        return -1;\
    }\
}\

typedef struct
{
    pid_t pid;
    int fd;
    short busy;
}process_data_t;

typedef struct
{
    int dataLen;
    char buf[1000];
}train_t;

int makeChild(process_data_t *p,int processNum);
int childHandle(int pipeFd);
void sendFd(int socketpipew,int fd);
void recvFd(int socketpair,int *fd);
int tcpInit(int *sfd,char *ip,char *port);
int epollInAdd(int epfd,int fd);
int tranFile(int newFd);

#define FILENAME "file"
