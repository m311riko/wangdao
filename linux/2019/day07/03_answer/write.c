#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,2);

    //打开文件
    int fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    
    //写入内容
    char buf[10]="hello";
    int ret=write(fd,buf,strlen(buf));
    ERROR_CHECK(ret,-1,"write");

    //关闭文件
    close(fd);

    return 0;
}

