#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
    //有参构造函数
    Computer(const char *brand,float price)
    :_brand(new char[strlen(brand)+1]())
    ,_price(price)
    {
        cout<<"Computer(const char*,float)"<<endl;
        strcpy(_brand,brand);
    }

    //默认复制构造函数
#if 0
    Computer(const Computer &rhs)
    :_brand(rhs._brand) //浅拷贝：只拷贝指针地址
    ,_price(rhs._price)
    {
        cout<<"Computer(const Computer &)"<<endl;
    }
#endif

    //自定义复制构造函数
    Computer(const Computer &rhs)
    :_brand(new char[strlen(rhs._brand)+1]())
    ,_price(rhs._price)
    {
        cout<<"Computer(const Computer &)"<<endl;
        strcpy(_brand,rhs._brand);  //深拷贝：先开空间，再复制
    }

    //默认赋值运算符函数
#if 0
    Computer & operator=(const Computer &rhs)
    {
        this->_brand=rhs._brand;
        this->_price=rhs._price;

        return *this;
    }
#endif

    //自定义赋值运算符函数
    Computer & operator=(const Computer &rhs)
    {
        if(this!=&rhs)  //1、考虑自复制问题
        {
            delete []_brand;    //2、回收已经开辟的空间

            _brand=new char[strlen(rhs._brand)+1]();    //3、进行深拷贝
            strcpy(_brand,rhs._brand);
            _price=rhs._price;
        }

        return *this;
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

int main()
{
    Computer c1("xiaomi",6666); //调用有参构造函数
    cout<<"c1=";
    c1.print();
    cout<<endl;

    Computer c2=c1; //调用复制构造函数
    cout<<"c2=";
    c2.print();
    cout<<endl;

    Computer c3("Mac",10000);
    cout<<"c3=";
    c3.print();
    cout<<endl;

    Computer c4("Thinkpad",8888);
    c4=c3;  //调用赋值运算符函数
    c4.print();
    cout<<endl;

    return 0;
}
