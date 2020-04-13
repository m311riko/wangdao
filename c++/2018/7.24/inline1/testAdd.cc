//一个.cc文件就是一个单独的模块

#include "add.h"
#include "add.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int a=3,b=4;
    cout<<add(a,b)<<endl;

    return 0;
}
