#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    //默认构造函数
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout<<"Point()"<<endl;
    }

    //有参构造函数
    Point(int ix,int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    //默认复制构造函数
    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout<<"Point(const Point &)"<<endl;
    }

    //默认赋值运算符
    Point & operator=(const Point &rhs)
    {
        cout<<"operator=(const Point &)"<<endl;

        _ix=rhs._ix;
        _iy=rhs._iy;

        return *this; //this代表当前对象本身
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
    Point pt(1,2);
    pt.print();

    Point pt2=pt;     //复制构造函数
    pt2.print();

    return 0;
}

int test1()
{
    Point pt(3,4);
    pt.print();

    Point pt2(1,2);
    pt2=pt;     //赋值运算符
    pt2.print();
    return 0;
}

int main()
{
    test0();
    test1();

    return 0;
}
