#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//全局静态区
int a=0;
char *p1;

//文字常量区
const int x=100;

int test0()
{
    //栈区
    int b;
    char s[]="123456";
    char *p2;
    const int y=10;

    //文字常量区
    const char *p3="123456";
    //*p3='x';  error，文字常量区是只读
    
    //全局静态区
    static int c=0;
    c++;
    
    //堆区
    p1=new char[10];
    p2=new char[5];
    strcpy(p1,"123456");

    printf("全局静态区\n");
    printf("&a=%p\n",&a);
    printf("&p1=%p\n",&p1);
    printf("&c=%p\n",&c);

    printf("堆区\n");
    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);

    printf("栈区\n");
    printf("&b=%p\n",&b);
    printf("s=%p\n",s);
    printf("&p2=%p\n",&p2);
    printf("&p3=%p\n",&p3);
    printf("&y=%p\n",&y);

    printf("文字常量区\n");
    printf("p3=%p\n",p3);
    printf("&x=%p\n",&x);

    printf("代码区\n");
    printf("&test0=%p\n",&test0);

    return 0;
}

int main()
{
    test0();

    return 0;
}
