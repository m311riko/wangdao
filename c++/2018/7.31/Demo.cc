#include <iostream>

using std::cout;
using std::endl;

void display()
{
    static int counter=0;
    cout<<"display()"<<endl;
    ++counter;
}

struct Foo
{
    Foo()
    :counter(0)
    {
        cout<<"Foo()"<<endl;
    }

    //重载()
    int operator()(int x,int y)
    {
        ++counter;
        return x*y;
    }

    //重载()
    int operator()(int x,int y,int z)
    {
        return x+y+z;
    }

    int counter;
};

int main()
{
    display();  //函数调用

    Foo foo;
    cout<<foo(3,4)<<endl;   //重载了()运算符的类创建的对象，称为函数对象
                            //函数对象携带了状态->闭包->lambda表达式（匿名函数对象）
    cout<<foo.counter<<endl;
    cout<<foo(3,4,5)<<endl;

    Foo fool;
    return 0;
}
