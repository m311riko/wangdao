#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

void display()
{
    cout<<"display()"<<endl;
}

int main()
{
    cout<<"main start"<<endl;
    atexit(display);    //在进程退出时调用display()函数

    cout<<"main exit"<<endl;
    return 0;
}
