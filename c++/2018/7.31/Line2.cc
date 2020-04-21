#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

class Point;    //类的前向声明

class Line
{
public:
    float distance(const Point &,const Point &);
    void setPoint(Point *pt,int ix,int iy);

private:
    int _iz;
};

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

#if 0
    void setLine(Line *line,int iz)
    {
        line->_iz=iz;
    }
#endif

    //友元在一定程度上破坏了类的封装性，但是提高了灵活性
    //
    //友元不能乱用
    //
    //友元使用上是有限制的：
    //  （1）只能单向使用，在Point类中不能访问Line类的成员变量；
    //  （2）不具有传递性（A->B,B->C,A->C）；
    //  （3）不能继承；
    friend Line;

private:
    int _ix;
    int _iy;
};

float Line::distance(const Point &lhs,const Point &rhs)
{
    return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix)+
                (lhs._iy-rhs._iy)*(lhs._iy-rhs._iy));
}

void Line::setPoint(Point *pt,int ix,int iy)
{
    pt->_ix=ix;
    pt->_iy=iy;
}

int main()
{
    Line line;
    Point pt1(1,2);
    Point pt2(3,4);

    pt1.print();
    cout<<"到";
    pt2.print();
    cout<<"距离是："<<line.distance(pt1,pt2)<<endl;

    line.setPoint(&pt1,5,6);
    cout<<"pt1=";
    pt1.print();
    cout<<endl;

    return 0;
}
