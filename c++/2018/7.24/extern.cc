#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//按c语言的方式调用
//c和c++混合编程，c++兼容c的方式
#ifdef __cplusplus
extern "C"
{
#endif

    int add(int x,int y)
    {
        return x+y;
    }

#ifdef __cplusplus
}
#endif

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
