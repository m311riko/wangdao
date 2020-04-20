#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main()
{
    //流对象不能复制
    ifstream ifs("String.cc");
    ifstream ifs2(ifs);

    return 0;
}
