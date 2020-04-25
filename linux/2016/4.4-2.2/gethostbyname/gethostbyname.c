#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <strings.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("args error\n");
		return -1;
	}

	//获取正式主机名
	struct hostent* hptr;
	hptr=gethostbyname(argv[1]);
	if(hptr==NULL)
	{
		perror("gethostbyname");
		return -1;
	}
	printf("the host name is %s\n",hptr->h_name);

	//获取主机别名
	char** pptr;
	pptr=hptr->h_aliases;
	int i;
	for(i=0;pptr[i]!=NULL;i++)
	{
		printf("h_aliases is %s\n",pptr[i]);
	}

	//获取IP类型、IP地址长度
	printf("AF_INET is %d,h_addrtype is %d\n",AF_INET,hptr->h_addrtype);
	printf("h_length is %d\n",hptr->h_length);

	//获取IP地址列表
	char str[32];
	pptr=hptr->h_addr_list;
	for(i=0;pptr[i]!=NULL;i++)
	{
		bzero(str,sizeof(str));
		printf("%s\n",inet_ntop(hptr->h_addrtype,pptr[i],str,sizeof(str)));
	}

	return 0;
}
