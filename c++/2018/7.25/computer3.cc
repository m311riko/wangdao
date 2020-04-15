#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
    Computer(const char *brand,float price)
    :_brand(new char[strlen(brand)+1]())
    ,_price(price)
    {
        cout<<"Computer(const char*,float)"<<endl;
        strcpy(_brand,brand);
    }

    void print()
    {
        cout<<"brand: "<<_brand<<endl;
        cout<<"price: "<<_price<<endl;
    }

    ~Computer()
    {
        cout<<"~Computer()"<<endl;
        delete []_brand;
    }

private:
    char *_brand;
    float _price;
};

Computer gComputer("Thinkpad",8888);    //全局对象自动调用析构函数

int main()
{
    gComputer.print();

    Computer c1("xiaomi",6666); //栈对象自动调用析构函数释放空间
    c1.print();

    Computer *pc=new Computer("Mac",10000); //堆对象要手动delete
    pc->print();
    delete pc;  //delete时自动调用析构函数

    return 0;
}
