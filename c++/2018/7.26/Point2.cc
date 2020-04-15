#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix=0,int iy=0)
    :_ix(ix)
    ,_iy(iy)
    ,_ref(_ix)  //引用数据成员初始化必须在初始化列表中进行
    {
        cout<<"Point(int,int)"<<endl;
    }

    void print()
    {
        cout<<"("<<this->_ix
            <<","<<this->_iy
            <<","<<this->_ref
            <<")"<<endl;
    }

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

private:
    int _ix;
    int _iy;
    int &_ref;
};

int main()
{
    Point pt2(1,2);
    pt2.print();

    return 0;
}
