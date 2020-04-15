#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix=0,int iy=0)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    void print()
    {
        cout<<"print()"<<endl;
        setX(100);
        cout<<"("<<this->_ix
            <<","<<this->_iy
            <<")"<<endl;
    }

    void setX(int ix)
    {
        _ix=ix;
    }

    //一旦某个函数不会修改数据成员的值，都应该将其设为const成员
    //const成员函数的作用：用来读取数据成员的值，不做修改
    void print() const
    {
        cout<<"print() const"<<endl;
        //setX(100);    //const成员函数不能调用非const成员函数
        //this->_ix=100;    //const成员函数不能修改成员变量
        cout<<"("<<this->_ix
            <<","<<this->_iy
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

int main()
{
    const Point pt(1,2);    //const对象只能调用const成员函数
    pt.print();

    Point pt2(3,4); //非const对象可以调用const成员函数
    pt2.print();

    return 0;
}
