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

class Line
{
public:
    //默认构造函数
    Line()
    :_pt1() //即使没有显式调用，系统也会调用相应的默认构造函数
    ,_pt2()
    {
        cout<<"Line()"<<endl;
    }

    //有参构造函数
    Line(int x1,int y1,int x2,int y2)
    :_pt1(x1,y1)    //对象数据成员初始化必须放在初始化列表中进行
    ,_pt2(x2,y2)
    {
        cout<<"Line(int,int,int,int)"<<endl;
    }

    void printLine()
    {
        _pt1.print();
        cout<<"--->";
        _pt2.print();
        cout<<endl;
    }

private:
    Point _pt1;
    Point _pt2;
};

int main()
{
    Line line(1,2,3,4);
    line.printLine();

    return 0;
}
