#include <iostream>

using std::cout;
using std::endl;

//一个程序经历的阶段：
//编辑-预处理-编译-汇编-链接-执行
//
//define与const区别：
//1、宏定义发生的时机：预处理，只是简单的字符串替换；
//（在使用宏定义的过程中，有很大的概率会出现问题）
//
//2、const关键字发生的时机：编译，有类型检查；
//（使用const关键字可以减少犯错的概率）
//
//尽量使用const关键字替换宏定义

#define MAX 1000

void test0()
{
    int num=2;
    cout<<num*MAX<<endl;
}

void test1()
{
    //const int num;    error,常量必须进行初始化
    const int value=1;
    //value=2;  error,常量的值不能修改
    cout<<"value="<<value<<endl;
}

int main()
{
    test0();
    test1();

    return 0;
}
