#include <iostream>

using std::cout;
using std::endl;

class NullPointerCaller
{
public:
    static void test1()
    {
        cout<<"static int _iy="<<_iy<<endl;
    }

    void test2()
    {
        cout<<"very cool"<<endl;
    }

    void test3(int num)
    {
        cout<<"形参num="<<num<<endl;
    }

    void test4()
    {
        cout<<"非静态数据成员="<<this->_ix<<endl;   //this指针指向NULL，所以这里会发生段错误
    }

private:
    int _ix;
    static int _iy;
};

int NullPointerCaller::_iy=0;

int main()
{
    NullPointerCaller *p=NULL;
    p->test1();
    p->test2();
    p->test3(10);
    p->test4();

    return 0;
}
