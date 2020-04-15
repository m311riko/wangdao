#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix=0,int iy=0)    //构造函数设置默认参数
    :_ix(ix)    //const数据成员初始化必须在初始化列表进行
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
    const int _ix;  //加上const关键字，一旦对象创建完毕，该成员变量就不能再修改
    const int _iy;
};

int main()
{
    Point pt;
    pt.print();

    Point pt2(1,2);
    pt2.print();

    return 0;
}
