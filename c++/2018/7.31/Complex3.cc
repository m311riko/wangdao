#include <iostream>

using std::cout;
using std::endl;

class Complex
{
public:
    Complex(double dreal=0,double dimag=0)
    :_dreal(dreal)
    ,_dimag(dimag)
    {
        cout<<"Complex(double,double)"<<endl;
    }

    void display() const
    {
        cout<<_dreal;
        if(_dimag>0)
        {
            cout<<"+"<<_dimag<<"i"<<endl;
        }
        else if(_dimag<0)
        {
            cout<<"-"<<(-1)*_dimag<<endl;
        }
        else
        {
            cout<<endl;
        }
    }

    //重载+，以成员函数形式
    Complex operator+(const Complex &rhs)
    {
        return Complex(_dreal+rhs._dreal,_dimag+rhs._dimag);
    }

private:
    double _dreal;
    double _dimag;
};

int main()
{
    Complex c1(1,2);
    c1.display();

    Complex c2(3,4);
    c2.display();

    Complex c3=c1+c2;
    c3.display();

    Complex c4=c3+5;
    c4.display();

    //Complex c4=5+c3;  error，成员函数不能进行隐式转换
    //c4.display();

    return 0;
}
