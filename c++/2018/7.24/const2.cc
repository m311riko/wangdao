#include <iostream>

using std::cout;
using std::endl;

//int (*p)[] vs int *p[]
//数组指针  vs  指针数组
//int (*p)() vs int *pfunc()
//函数指针  vs  指针函数
//const int *pa vs int *const pa
//常量指针 vs 指针常量

void test0()
{
    int num1=10;
    int num2=11;
    const int *pa=&num1;    //常量指针(pointer to const)
    //*pa=20;   error,不能通过指针pa更改所指变量的值
    pa=&num2;   //可以改变指针pa的指向

    int const *pb=&num1;
    //*pb=20;   error,不能通过指针pb改变所指向变量的值
    pb=&num2;

    int * const pc=&num1;   //指针常量(const pointer)
    //pc=&num2;     error,不能改变指针pc的指向
    *pc=20;     //可以通过指针pc更改所指变量的值

    const int * const pd=&num1;
}

int main()
{
    test0();

    return 0;
}
