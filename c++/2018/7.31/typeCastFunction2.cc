#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;

class Complex
{
public:
    Complex(double dreal=0,double dimag=0)
    :_dreal(dreal)
    ,_dimag(dimag)
    {
        cout<<"Complex(double,double)"<<endl;
    }

    friend std::ostream &operator<<(std::ostream &os,const Complex &rhs);

private:
    double _dreal;
    double _dimag;
};

std::ostream &operator<<(std::ostream &os,const Complex &rhs)
{
    os<<rhs._dreal;
    if(rhs._dimag>0)
    {
        os<<"+"<<rhs._dimag<<"i";
    }
    else if(rhs._dimag<0)
    {
        os<<"-"<<(-1)*rhs._dimag<<"i";
    }

    return os;
}

class Point
{
public:
    Point(int ix=0,int iy=0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    void print() const
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")";
    }

    friend std::ostream &operator<<(std::ostream &os,const Point &rhs);

    //类型转换函数：
    //（1）成员函数形式；
    //（2）没有参数；
    //（3）没有返回值，但是函数体内必须以传值的方式返回一个目标类型的变量
    //（4）建议不使用
    operator int()
    {
        cout<<"operator int()"<<endl;
        return _ix*_iy;
    }

#if 0
    operator Complex()
    {
        return Complex(_ix,_iy);
    }
#endif

private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os,const Point &rhs)
{
    os<<"("<<rhs._ix
      <<","<<rhs._iy
      <<")";

    return os;
}

int main()
{
    Point pt1(1,2);
    cout<<"pt1:"<<pt1<<endl;    //自动将Point对象转换成int型对象

    return 0;
}
