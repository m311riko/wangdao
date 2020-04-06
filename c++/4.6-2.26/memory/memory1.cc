//c++内存布局：
//栈区、堆区、全局/静态区、文字常量区；

#include <stdio.h>
#include <string.h>
#include <iostream>

int a=0;
char *p1;

int main()
{
	int b;
	char s[]="123456";
	char *p2;
	char *p3="123456";
	static int c=0;
	p1=new char[10];
	strcpy(p1,"123456");

	//p3[0]='x';	//非法操作，文字常量区的内容不能修改

	printf("&a=%x\n",&a);	//全局区
	printf("&p1=%x\n",&p1);
	printf("&c=%x\n",&c);	//静态区
	printf("----------\n");

	printf("p1=%x\n",p1);	//堆区
	printf("----------\n");

	printf("&b=%x\n",&b);	//栈区
	printf("s=%x\n",s);		//栈区
	printf("&p2=%x\n",&p2);	//栈区
	printf("&p3=%x\n",&p3);	//栈区
	printf("----------\n");

	printf("p3=%x\n",p3);	//文字常量区
	printf("----------\n");

	return 0;
}
