#include <stdio.h>

int add(int x,int y)
{
    return x+y;
}

//c不支持函数重载，但是使用g++编译可以运行
int add(int x,int y,int z)
{
    return x+y+z;
}

int main()
{
    int a=3,b=4,c=5;
    printf("a+b=%d\n",add(a,b));
    printf("a+b+c=%d\n",add(a,b,c));

    return 0;
}
