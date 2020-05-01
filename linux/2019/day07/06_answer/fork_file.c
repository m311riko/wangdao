#include <func.h>

#if 0
为什么父进程读hello，子进程能读world？

1.文件和堆栈不同，当fork()以后父子进程指向同一个文件对象；
2.文件对象包括以下内容：
    位置地址；
    起始地址；
    引用计数；
3.因为父子进程指向同一个文件对象，所以共享同一个位置地址，
  所以父进程读了hello以后，子进程能读到world；



为什么父进程close以后，子进程还能读到内容？

1.文件对象中的引用计数起作用；
2.父进程close以后只是文件对象引用计数减一，变为1；
3.当引用计数为0时，文件对象才会被销毁；
4.所以父进程close以后文件并没有被销毁，因此子进程还能读到内容；
#endif

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);

    int fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    pid_t pid;
    pid=fork();

    char buf[128]={0};
    int ret;
    if(0==pid)
    {
        ret=read(fd,buf,5);
        ERROR_CHECK(ret,-1,"read");
        printf("I am child,buf is %s\n",buf);
    }
    else
    {
        ret=read(fd,buf,5);
        ERROR_CHECK(ret,-1,"open");
        printf("I am parent,buf is %s\n",buf);
        close(fd);
        sleep(1);
    }

    return 0;
}

