#include <iostream>

using std::cout;
using std::endl;

class Cell
{
};

class CellX
{
public:
    int a;  //4
    char b; //1
    float c;//4
    double d;//8
    short e[5];//10
    char &f; //1
    double &g;//8
    static int h;   //sizeof不统计static变量大小
};

int main()
{
    Cell c1;
    cout<<"Cell: "<<sizeof(Cell)<<endl;    //虽然类为空，但是也有1字节空间
    Cell c2;                              //是为了区别c1与c2是不同对象，所以还是会开辟1个字节空间
    
    cout<<"int: "<<sizeof(int)<<endl;
    cout<<"char: "<<sizeof(char)<<endl;
    cout<<"float: "<<sizeof(float)<<endl;
    cout<<"double: "<<sizeof(double)<<endl;
    cout<<"short: "<<sizeof(short)<<endl;
    cout<<"char&: "<<sizeof(char&)<<endl;
    cout<<"double&: "<<sizeof(double&)<<endl;
    cout<<"CellX: "<<sizeof(CellX)<<endl;
}
