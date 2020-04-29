#include <func.h>
#include <stdio.h>

//定义学生结构体
struct student
{
    int id;
    char name[20];
    double score;
};

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,2);

    //打开文件
    int fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    //定义结构体数组，赋初值
    struct student s[3]={
        {0001,"wang",100},
        {0002,"li",90},
        {0003,"zhang",80}
    };

    //将结构体数组写入文件
    int ret=write(fd,s,sizeof(s));
    ERROR_CHECK(ret,-1,"write");

    //lseek偏移到开头
    ret=lseek(fd,0,SEEK_SET);
    ERROR_CHECK(ret,-1,"lseek");

    //读取文件，打印输出
    char buf[128]={0};
    ret=read(fd,buf,sizeof(s));
    ERROR_CHECK(ret,-1,"read");

    //关闭文件
    close(fd);
    return 0;
}
