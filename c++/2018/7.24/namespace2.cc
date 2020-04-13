#include <iostream>

namespace A
{
    void displayA()
    {
        std::cout<<"A::displayA()"<<std::endl;  //作用域限定符
    }
}

using namespace A;

void cout()
{
    std::cout<<"cout()"<<std::endl;
}

int main()
{
    displayA();
    cout();

    return 0;
}
