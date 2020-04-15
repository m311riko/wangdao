#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout<<"Point()"<<endl;
    }

    Point(int ix,int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

    //默认析构函数
    //栈对象自动调用析构函数
    //析构函数的作用：用来做清理工作，不建议显式调用
    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

private:
    int _ix;
    int _iy;
};

int test0()
{
    Point pt;
    pt.print();

    Point pt2(1,2);     //栈上的对象被销毁时自动调用析构函数
    pt2.print();

    return 0;
}

int main()
{
    test0();

    return 0;
}
