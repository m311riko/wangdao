#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int ix,int iy)
    :_ix(ix)
    ,_iy(iy)
    {
        cout<<"Point(int,int)"<<endl;
    }

    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

private:
    void * operator new(size_t sz)
    {
        cout<<"operator new()"<<endl;
        void *ret=malloc(sz);
        return ret;
    }

    void operator delete(void *ret)
    {
        cout<<"operator delete()"<<endl;
        free(ret);
    }

    int _ix;
    int _iy;
};

int main()
{
    Point p(1,2);
    p.print();

    //Point *p1=new Point(2,3); 不能生成堆对象
    //p1->print();

    return 0;
}
