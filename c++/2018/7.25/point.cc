#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    //如果没有定义任何构造函数，系统会提供一个默认构造函数
    //构造函数的作用：就是初始化数据成员
    //初始化列表：这才是真正的对数据进行初始化，赋值操作不是对数据进行初始化
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout<<"Point()"<<endl;
    }

    //如果一旦定义了自己的构造函数，系统就不会再提供默认构造函数
    //如果还想使用默认构造函数创建对象，就必须手动提供默认构造函数
    //如此说明，构造函数可以重载
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

private:
    int _ix;
    int _iy;
};

int main()
{
    int a=3;
    int b(4);   //初始化
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    Point pt;   //调用默认构造函数
    //Point pt();   //不能这样写，这是一个函数声明，不是创建对象
    pt.print();

    Point pt2(1,2); //调用自己定义的构造函数
    pt2.print();

    return 0;
}
