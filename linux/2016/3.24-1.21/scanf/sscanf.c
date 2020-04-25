#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	//单个数字
	int a;
	char c[30];
	strcpy(c,"123");
	int ret;
	ret=sscanf(c,"%d",&a);
	printf("the ret is %d\n",ret);
	printf("a is %d\n",a);

	//多个数字
	printf("--------------\n");
	float f;
	strcpy(c,"123 45.6");
	ret=sscanf(c,"%d    %f",&a,&f);
	printf("the ret is %d\n",ret);
	printf("a,b is %d %f\n",a,f);

	//单个数字和字符串
	printf("-------------\n");
	char c1[30];
	strcpy(c,"123  hello");
	ret=sscanf(c,"%d     %s",&a,c1);
	printf("the ret is %d\n",ret);
	printf("a c1 is %d %s\n",a,c1);

	//多个字符串（注意格式要一致）
	printf("---------------\n");
	char c2[30];
	char c3[30];
	memset(c2,0,sizeof(c2));
	memset(c3,0,sizeof(c3));
	strcpy(c,"123 456");
	ret=sscanf(c,"%s %s",c1,c2);
	printf("the ret is %d\n",ret);
	printf("c1,c2 is %s %s\n",c1,c2);

	return 0;
}
