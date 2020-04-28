#include "func.h"

int main(int argc,char *argv[])
{
    //参数检测
    ARGS_CHECK(argc,3);

    //打开目录
    DIR *dir=opendir(argv[1]);
    RET_CHECK(dir,NULL,"opendir");

    //循环读取目录项
    struct dirent *dirent;
    while((dirent=readdir(dir))!=NULL)
    {
        //找到文件，打印文件信息
        if(strcmp(dirent->d_name,argv[2])==0)
        {
            printf("%s\n",dirent->d_name);
            printf("%s\n",getcwd(NULL,0));
        }
    }

    //关闭目录
    closedir(dir);

    return 0;
}
