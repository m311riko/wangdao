#include <func.h>

int main()
{
    pid_t pid;
    pid=fork();
    if(0==pid)
    {
        //成为守护进程
        setsid();
        chdir("/");
        umask(0);
        close(0);
        close(1);
        close(2);

        //修改syslog
        int fd=open("/var/log/syslog",O_RDWR);
        ERROR_CHECK(fd,-1,"open");

        char buf[20]="wohenshuai";
        int ret=write(fd,buf,strlen(buf));
        ERROR_CHECK(ret,-1,"write");
    }
    else
    {
        exit(0);
    }

    return 0;
}

