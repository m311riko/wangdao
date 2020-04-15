#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//struct默认访问权限为public
struct Computer
{
    void setBrand(const char *brand)
    {
        strcpy(_brand,brand);
    }

    void setPrice(float price)
    {
        _price=price;
    }

    void print()
    {
        cout<<"brand: "<<_brand<<endl;
        cout<<"price: "<<_price<<endl;
    }

    char _brand[20];
    float _price;
};

int main()
{
    Computer com;
    com.setBrand("lenovo");
    com.setPrice(10000);
    com._price=11000;
    com.print();

    return 0;
}
