#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

class Empty
{

};

int main()
{
    cout<<"sizeof(Empyt)="<<sizeof(Empty)<<endl;
    Empty e1;   //调用默认构造函数
    Empty e2;

    printf("&e1=%p\n",&e1);
    printf("&e2=%p\n",&e2);

    Empty e3=e1;    //调用复制构造函数
    e3=e2;  //调用赋值运算符函数

    //对象销毁时，调用析构函数

    return 0;
}
