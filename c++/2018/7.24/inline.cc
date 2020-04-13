#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//带参数的宏定义
//执行的时机：预处理，进行的是字符串替换，没有函数调用的开销，可以提高程序的执行效率
//
//对于简短的语句，定义为函数之后，函数的执行会有开销
//但是在使用带参数的宏定义后，容易产生错误
#define Max(x,y) ((x)>(y)?(x):(y))
#define Mul(x,y) x*y

//inline函数：内联函数
//也会在函数调用时，进行字符串替换，没有函数调用的开销
//相比于带参数的宏定义的优势：有类型检查，不容易产生错误
inline int max(int x,int y)
{
    return x>y?x:y;
}

inline int mul(int x,int y)
{
    return x*y;
}

int main()
{
    int a=3,b=4,c=5;
    printf("Max(a,b)=%d\n",Max(a,b));
    printf("Mul(a,b)=%d\n",Mul(a+b,c));     //a+b*c
    cout<<max(a,b)<<endl;
    cout<<mul(a+b,c)<<endl;

    return 0;
}
