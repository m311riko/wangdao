#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    explicit    //禁止隐式转换
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
            <<")"<<endl;
    }

private:
    int _ix;
    int _iy;
};

int main()
{
    //Point pt=1; //隐式转换
    Point pt(1,2);
    pt.print();

    return 0;
}
