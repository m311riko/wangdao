#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
#if 1
    Point()
    {
        cout<<"Point()"<<endl;
        ++iCount;
        cout<<"调用"<<iCount<<"次构造函数"<<endl;
    }
#endif

    Point(int ix,int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
        ++iCount;   //相比于iCount++效率更高
        cout<<"调用"<<iCount<<"次构造函数"<<endl;
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
    static int iCount;
};

int Point::iCount=0;    //静态成员初始化不要加static关键字

int main()
{
    Point ptArr[2]; //调用默认构造函数初始化数组
    Point pt1(1,2); //调用有参构造函数初始化对象

    Point ptArr2[2]={Point(1,2),Point(3,4)};    //匿名对象
    Point ptArr3[]={Point(1,2),Point(3,4)};
    Point ptArr4[5]={Point(1,2),Point(3,4)};    //只调用有参构造函数初始化前两个对象
                                                //后面的对象调用默认构造函数初始化

    return 0;
}
