#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//c类型转换
void test0()
{
    int a=10;
    double d1=(double)a;
    double d2=double(a);
    cout<<"d1="<<d1<<endl;
    cout<<"d2="<<d2<<endl;
}

//c++类型转换
void test1()
{
    int a=10;
    double d1=static_cast<double>(a);
    cout<<"d1="<<d1<<endl;

    int *p=static_cast<int*>(malloc(sizeof(int)));
    *p=10;      //static_cast/const_cast/dynamic_cast/reinterpret_cast
    cout<<"*p="<<*p<<endl;
}

int main()
{
    test1();

    return 0;
}
