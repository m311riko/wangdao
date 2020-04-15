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
    Point(1,2).print(); //匿名对象

    Point points[5]=    //对象数组
    {
        Point(1,2),
        Point(2,3),
        Point(3,4)
    };

    points[0].print();

    return 0;
}
