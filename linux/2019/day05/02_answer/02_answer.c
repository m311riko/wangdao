#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,2);

    //打开文件
    int fd=open(argv[1],O_RDWR|O_TRUNC);
    ERROR_CHECK(fd,-1,"open");

    //改变文件大小
    int ret=ftruncate(fd,5);
    ERROR_CHECK(ret,-1,"ftruncate");

    //内存映射
    char *buf=(char*)mmap(NULL,5,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(buf,(void*)-1,"mmap");

    //改变文件内容
    buf[0]='w';
    buf[1]='o';
    buf[2]='r';
    buf[3]='l';
    buf[4]='d';

    //解除映射
    munmap(buf,5);

    //关闭文件
    close(fd);

    return 0;
}
