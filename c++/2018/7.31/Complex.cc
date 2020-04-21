#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;

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
            cout<<"-"<<(-1)*_dimag<<"i"<<endl;
        }
        else
        {
            cout<<endl;
        }
    }

    double getReal() const
    {
        return _dreal;
    }

    double getImag() const
    {
        return _dimag;
    }

    //重载运算符+=，以成员函数形式
    Complex &operator+=(const Complex &rhs)
    {
        _dreal+=rhs._dreal;
        _dimag+=rhs._dimag;
        return *this;
    }

    //重载前置++，以成员函数形式
    Complex &operator++()
    {
        ++_dreal;
        ++_dimag;
        return *this;
    }

    //重载后置++，以成员函数形式
    Complex operator++(int)
    {
        Complex temp(*this);    //调用复制构造函数
        ++_dreal;
        ++_dimag;
        return temp;
    }

    //重载<<，以友元函数形式
    //如果以成员函数形式重载<<，左操作数必然是对象本身
    //而<<左操作数要求是流对象，所以输出流运算符不能以成员函数形式重载
    friend std::ostream &operator<<(std::ostream &os,const Complex &rhs);
    friend std::istream &operator>>(std::istream &is,Complex &rhs);

private:
    double _dreal;
    double _dimag;
};

//error
//运算符重载时，参数必须是自定义类型或者枚举类型
#if 0
int operator+(int x,int y)
{
    return x+y;
}
#endif

//重载运算符+，以普通函数形式
#if 0
Complex operator+(const Complex &lhs,const Complex &rhs)
{
    return Complex((lhs.getReal()+rhs.getReal()),
                    lhs.getImag()+rhs.getImag());
}
#endif

//利用+=实现+
Complex operator+(const Complex &lhs,const Complex &rhs)
{
    Complex temp(lhs);
    temp+=rhs;
    return temp;
}

//重载<<，以友元函数形式
std::ostream &operator<<(std::ostream &os,const Complex &rhs)
{
    os<<rhs._dreal;
    if(rhs._dimag>0)
    {
        os<<"+"<<rhs._dimag<<"i";
    }
    else if(rhs._dimag<0)
    {
        os<<"-"<<(-1)*rhs._dimag<<"i";
    }

    return os;
}

void readDouble(std::istream &is,double &num)
{
    cout<<"pls input a number:"<<endl;
    while(is>>num,!is.eof())
    {
        if(is.bad())
        {
            cout<<"istream is breaken"<<endl;
            return;
        }
        else if(is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"pls input a number:"<<endl;
            continue;
        }
        break;
    }
}

//重载>>，以友元函数形式
std::istream &operator>>(std::istream &is,Complex &rhs)
{
    readDouble(is,rhs._dreal);
    readDouble(is,rhs._dimag);
    return is;
}

//测试+、+=
void test0()
{
    Complex c1(1,2);
    Complex c2(3,4);

    cout<<"c1:";
    c1.display();
    cout<<"c2:";
    c2.display();

    Complex c3=c1+c2;
    cout<<"c3:";
    c3.display();

    cout<<"c1:";
    c1+=c2;
    c1.display();
}

//测试++
void test1()
{
    Complex c1(1,2);
    Complex c2(1,2);

    cout<<"c1的值：";
    c1.display();
    cout<<"c2的值：";
    c2.display();

    cout<<"前置++：";
    (++c1).display();
    cout<<"c1的值：";
    c1.display();

    cout<<"后置++：";
    (c2++).display();
    cout<<"c2的值：";
    c2.display();
}

//重载>>、<<
void test2()
{
    Complex c1(1,2);
    cout<<"c1:"<<c1<<endl;

    Complex c2(3,4);
    cout<<"c2:"<<c2<<endl;

    Complex c3(5,6);
    cout<<"c3:"<<c3<<endl;

    cout<<"通过终端输入："<<endl;
    cin>>c3;
    cout<<"c3:"<<c3<<endl;
}

int main()
{
    //test0();
    //test1();
    test2();

    return 0;
}
