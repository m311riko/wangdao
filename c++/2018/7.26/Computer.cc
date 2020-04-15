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

        _totalPrice+=_price;
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

    //静态成员函数没有this指针
    //所以不能访问非静态的数据成员和成员函数
    //只能访问静态数据成员和成员函数
    static void printTotalPrice()
    {
        cout<<"totalPrice: "<<_totalPrice<<endl;
    }

    ~Computer()
    {
        cout<<"~Computer()"<<endl;
        delete []_brand;

        _totalPrice-=_price;
    }

private:
    char *_brand;
    float _price;
    static double _totalPrice;  //静态数据成员被该类的所有对象共享，存储在全局静态区，并不占据对象的存储空间
};

double Computer::_totalPrice=0; //静态数据成员必须在类外面进行初始化

int main()
{
    Computer c1("xiaomi",6666);
    cout<<"c1=";
    c1.print();
    c1.printTotalPrice();
    cout<<endl;

    Computer c3("Mac",10000);
    cout<<"c3=";
    c3.print();
    Computer::printTotalPrice();    //静态成员函数可以通过类名直接调用
    cout<<endl;

    return 0;
}
