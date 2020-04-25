#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <string.h>
#include <strings.h>

void mymode(char buf[],mode_t mode)
{
	//文件类型
	if(S_ISREG(mode))
	{
		buf[0]='-';
	}
	if(S_ISDIR(mode))
	{
		buf[0]='d';
	}
	if(S_ISCHR(mode))
	{
		buf[0]='c';
	}
	if(S_ISBLK(mode))
	{
		buf[0]='b';
	}
	if(S_ISFIFO(mode))
	{
		buf[0]='p';
	}
	if(S_ISLNK(mode))
	{
		buf[0]='l';
	}
	if(S_ISSOCK(mode))
	{
		buf[0]='s';
	}

	//文件权限
	if(mode & S_IRUSR)
	{
		buf[1]='r';
	}
	if(mode & S_IWUSR)
	{
		buf[2]='w';
	}
	if(mode & S_IXUSR)
	{
		buf[3]='x';
	}

	if(mode & S_IRGRP)
	{
		buf[4]='r';
	}
	if(mode & S_IWGRP)
	{
		buf[5]='w';
	}
	if(mode & S_IXGRP)
	{
		buf[6]='x';
	}

	if(mode & S_IROTH)
	{
		buf[7]='r';
	}
	if(mode & S_IWOTH)
	{
		buf[8]='w';
	}
	if(mode & S_IXOTH)
	{
		buf[9]='x';
	}
}

void myls(char* path)
{
	DIR* dir;
	dir=opendir(path);
	if(NULL==dir)
	{
		perror("opendir1");
		return;
	}
	
	char buf[256];
	struct dirent* pt;
	struct stat st1;
	int ret;
	while(pt=readdir(dir))
	{
		if(strcmp(pt->d_name,".")!=0 && strcmp(pt->d_name,"..")!=0)
		{
			//拼接路径
			bzero(buf,sizeof(buf));
			sprintf(buf,"%s%s%s",path,"/",pt->d_name);
		
			//打印文件信息
			ret=stat(buf,&st1);
			if(-1==ret)
			{
				perror("stat1");
				return;
			}
			char mode[11];
			memset(mode,'-',sizeof(mode)-1);
			mymode(mode,st1.st_mode);

			char *uid=getpwuid(st1.st_uid)->pw_name;
			char *gid=getgrgid(st1.st_gid)->gr_name;

			//char *time=ctime(&st1.st_atime);
			char time[20]={0};
			bzero(time,sizeof(time));
			struct tm *stm=localtime(&st1.st_atime);
			sprintf(time,"%d月 %d %d:%d",(stm->tm_mon)+1,stm->tm_mday,stm->tm_hour,stm->tm_min);
			printf("%s %ld %s %s %ld %s %s\n",mode,st1.st_nlink,uid,gid,st1.st_size,time,pt->d_name);
		}
	}
}

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	myls(argv[1]);

	return 0;
}
