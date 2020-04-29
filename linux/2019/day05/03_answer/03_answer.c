#include <func.h>

int main(int argc,char *argv[])
{
    //错误检测
    ARGS_CHECK(argc,3);

    //打开log1
    int fd1=open(argv[1],O_RDWR);
    ERROR_CHECK(fd1,-1,"open");

    //打开log2
    int fd2=open(argv[2],O_RDWR);
    ERROR_CHECK(fd2,-1,"open");

    //重定向
    int ret=dup2(fd1,1);
    ERROR_CHECK(ret,-1,"dup2");
    ret=dup2(fd2,2);
    ERROR_CHECK(ret,-1,"dup2");

    //重定向完了以后关闭oldfd
    close(fd1);
    close(fd2);

    printf("hello,world\n");
    perror("hello,world,error\n");

    return 0;
}
