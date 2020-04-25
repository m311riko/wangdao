#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int a=123;
	char c[30];
	int ret;
	char* p;

	printf("the argv[0] is %s\n",argv[0]);
	memset(c,0,sizeof(c));
	ret=sprintf(c,"%d",a);
	printf("the ret is %d\n",ret);
	printf("the c is %s\n",c);

	memset(c,0,sizeof(c));
	sprintf(c,"%s%s",argv[1],argv[0]);
	printf("the c is %s\n",c);

	return 0;
}
