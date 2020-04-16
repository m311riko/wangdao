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

    void destroy()
    {
        cout<<"destroy()"<<endl;
        delete this;
    }

    void print()
    {
        cout<<"("<<_ix
            <<","<<_iy
            <<")"<<endl;
    }

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

private:
    ~Point()
    {
        cout<<"~Point()"<<endl;
    }

    int _ix;
    int _iy;
};

int main()
{
    //Point p(1,2); 不能生成栈对象
    //p.print();

    Point *p1=new Point(2,3);
    p1->print();

    p1->destroy();

    return 0;
}
