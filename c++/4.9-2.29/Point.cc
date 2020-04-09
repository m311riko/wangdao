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

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

    void setX(int ix)
    {
        _ix=ix;
    }

    void setY(int iy)
    {
        _iy=iy;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

    void print() const
    {
        cout<<"const->("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

private:
    int _ix;
    int _iy;
};

int main()
{
    Point pt(3,4);
    pt.setX(5);
    pt.setY(6);
    pt.print(); //非const对象可以调用const成员函数
                //但优先调用非const成员函数
    cout<<endl;

    const Point pt2(1,2);
    pt2.print();    //const对象只能调用const成员函数
                    //不能调用非const成员函数
}
