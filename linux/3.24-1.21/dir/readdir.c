#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	DIR* dir;
	dir=opendir(argv[1]);
	if(NULL == dir)
	{
		perror("opendir1");
		return -1;
	}
	
	//输出指定目录下的所有目录，但是不输入指定目录
	struct dirent* pd;
	while(pd=readdir(dir))
	{
		printf("inode=%lu,filelength=%hu,type=%d,name=%s\n",pd->d_ino,pd->d_reclen,pd->d_type,pd->d_name);
	}

	closedir(dir);
}
