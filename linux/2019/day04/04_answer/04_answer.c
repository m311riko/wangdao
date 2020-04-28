#include "func.h"

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,2);

    //打开目录
    DIR *dir=opendir(argv[1]);
    RET_CHECK(dir,NULL,"opendir");

    //循环读取目录项
    struct dirent *dirent=NULL;
    struct stat buf;
    char path[1024]={0};
    int ret;
    while((dirent=readdir(dir))!=NULL)
    {
        //拼接路径
        memset(&buf,0,sizeof(buf));
        sprintf(path,"%s%s%s",argv[1],"/",dirent->d_name);

        //获取文件状态
        //stat()需要文件名
        ret=stat(path,&buf);
        RET_CHECK(ret,-1,"stat");

        //打印文件信息
        printf("%x %2ld %s %s %5ld %d %d %d:%d %s\n",
                buf.st_mode,
                buf.st_nlink,
                getpwuid(buf.st_uid)->pw_name,
                getgrgid(buf.st_gid)->gr_name,
                buf.st_size,
                gmtime(&buf.st_mtime)->tm_mon+1,
                gmtime(&buf.st_mtime)->tm_mday,
                gmtime(&buf.st_mtime)->tm_hour,
                gmtime(&buf.st_mtime)->tm_min,
                dirent->d_name
                );
    }

    //关闭目录
    closedir(dir);
}
