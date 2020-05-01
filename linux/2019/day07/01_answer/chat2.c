#include <func.h>

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //打开写管道
    int fdw=open(argv[1],O_WRONLY);
    ERROR_CHECK(fdw,-1,"open write");

    //打开读管道
    int fdr=open(argv[2],O_RDONLY);
    ERROR_CHECK(fdr,-1,"open read");

    //打印信息
    printf("this is chat2\n");

    //定义描述符集合
    fd_set rdset;

    //循环检测描述符信息
    int ret;
    char buf[128]={0};
    while(1)
    {
        //清空描述符集合
        FD_ZERO(&rdset);

        //将标准输入描述符、读管道描述符放入描述符集合
        FD_SET(0,&rdset);
        FD_SET(fdr,&rdset);

        //select
        select(fdr+1,&rdset,NULL,NULL,NULL);

        //标准输入可读
        if(FD_ISSET(0,&rdset))
        {
            //读标准输入
            memset(buf,0,sizeof(buf));
            ret=read(STDIN_FILENO,buf,sizeof(buf));           
            ERROR_CHECK(ret,-1,"read stdin");

            //检测写端是否关闭
            if(0==ret)
            {
                printf("byebye\n");
                break;
            }

            //写入管道
            ret=write(fdw,buf,strlen(buf)-1);
            ERROR_CHECK(ret,-1,"write stdin");
        }

        //读管道可读
        if(FD_ISSET(fdr,&rdset))
        {
            //读管道
            memset(buf,0,sizeof(buf));
            ret=read(fdr,buf,sizeof(buf));
            ERROR_CHECK(ret,-1,"read fdr");

            //检测写端是否关闭
            if(0==ret)
            {
                printf("byebye\n");
                break;
            }

            //打印读取信息
            printf("%s\n",buf);
        }
    }

    close(fdr);
    close(fdw);
    return 0;
}

