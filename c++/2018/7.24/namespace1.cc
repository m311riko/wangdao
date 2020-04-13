#include <iostream>

using namespace std;    //using编译指令，会把命名空间std中的所有实体一次性全部引进来，有可能会造成二义性问题

namespace A
{
    void displayA()
    {
        cout<<"A::displayA()"<<endl;
    }
}

using namespace A;

void cout()
{

}

int main()
{
    displayA();
    //cout();

    return 0;
}
