#include <iostream>

using std::cout;
using std::endl;

class Demo
{
public:
    Demo(int iy)
    :_iy(iy)    //数据成员在初始化列表中的顺序并不是初始化的顺序
    ,_ix(_iy)   //数据成员初始化的顺序是由其声明的顺序决定的
    {
       cout<<"Demo()"<<endl;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

private:
    int _ix;
    int _iy;
};

int main()
{
    Demo demo(10);
    demo.print();

    return 0;
}
