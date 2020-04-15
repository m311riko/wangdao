#include "computer2.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Computer com;
    com.setBrand("外星人");
    com.setPrice(10000);
    com.print();

    return 0;
}
