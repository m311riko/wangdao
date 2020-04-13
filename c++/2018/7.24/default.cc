#include <iostream>

using std::cout;
using std::endl;

//默认参数只能按照从右向左的顺序进行设置
//注意不要产生二义性
int add(int x=10,int y=0)
{
    return x+y;
}

int add(int x,int y,int z)
{
    return x+y+z;
}

int main()
{
    int a=3,b=4;

    cout<<"a+b="<<add(a,b)<<endl;
    cout<<add(a)<<endl;
    cout<<add()<<endl;

    return 0;
}
