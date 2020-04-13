#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//c++支持函数重载
//
//实现原理：名字改编（name mangling）
//操作步骤：当函数的名字相同时，根据函数参数的类型、个数、顺序不同进行改编

int add(int x,int y)
{
    return x+y;
}

int add(int x,int y,int z)
{
    return x+y+z;
}

double add(double x,double y,double z)
{
    return x+y+z;
}

int main()
{
    int a=3,b=4,c=5;
    printf("a+b=%d\n",add(a,b));
    printf("a+b+c=%d\n",add(a,b,c));

    double d1=1.1,d2=2.2,d3=3.3;
    cout<<"d1+d2+d3="<<add(d1,d2,d3)<<endl;

    return 0;
}
