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

    //默认复制构造函数
    //1、复制构造函数中的引用符号不能删掉：
    //     如果删除，根据肤质构造函数的调用时机的第一种情况，接着会
    //     无限调用复制构造函数本身，进入到无穷递归的情况，知道栈溢出
    //2、赋值构造函数参数中的const不能删除：
    //     如果删除，当传递过来的参数是一个右值，
    //     非const对象不能绑定到右值上，编译会出错
    Point(const Point &rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout<<"Point(const Point &rhs)"<<endl;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

private:
    int _ix;
    int _iy;
};

//复制构造函数第一个调用时机：
//把一个已经存在的对象赋值给另一个新的对象时
int test0()
{
    Point pt1(1,2); //调用有参构造函数
    cout<<"pt1=";
    pt1.print();
    cout<<endl;

    Point pt2=pt1;  //调用复制构造函数
    cout<<"pt2=";
    pt2.print();

    return 0;
}

void func1(Point p)
{
    p.print();
}

//复制构造函数第二个调用时机：
//当实参和形参都是对象，进行形参和实参的结合
void test1()
{
    Point pt(1,2);
    func1(pt);  //调用复制构造函数
}

Point func2()
{
    Point p(3,4);
    p.print();
    return p;   //调用复制构造函数
}

//复制构造函数第三个调用时机：
//当函数的返回值是对象，函数调用完成返回时
void test2()
{
    Point pt=func2();
}

int main()
{
    test0();
    test1();
    test2();

    return 0;
}
