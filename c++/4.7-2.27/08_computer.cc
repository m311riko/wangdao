#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char *brand,float fprice);
	~Computer();

	//静态成员函数不包含this指针，因此不能使用非静态成员变量
	//静态成员函数可以直接通过类名进行调用
	static void print(Computer &com);
	static void print_total();

private:
	char *_brand;
	float _fprice;
	static float _ftotalPrice;
};

float Computer::_ftotalPrice=0.0f;	//静态成员变量必须在类外进行初始化

Computer::Computer(const char *brand,float fprice)
:_fprice(fprice)
{
	cout<<"Computer(float)"<<endl;
	_brand=new char[strlen(brand)+1];
	strcpy(_brand,brand);
	_ftotalPrice+=_fprice;
}

Computer::~Computer()
{
	cout<<"~Computer()"<<endl;
	if(_brand)
	{
		delete []_brand;
	}
	_ftotalPrice-=_fprice;
}

void Computer::print(Computer &com)
{
	cout<<"价格："<<com._fprice<<endl;
	cout<<"总价："<<com._ftotalPrice<<endl;
}

void Computer::print_total()
{
	//cout<<_fprice<<endl;	//静态成员函数不能调用普通成员变量
	cout<<"总价："<<_ftotalPrice<<endl;
}

int main()
{
	Computer pc1("IBM",7000);
	Computer::print(pc1);	//静态成员函数可以通过类名直接调用
	Computer::print_total();
	cout<<endl;

	Computer pc2("ASUS",5000);
	pc2.print(pc2);		//静态成员函数可以通过对象直接调用
	pc2.print_total();
	cout<<endl;

	pc2.~Computer();
	pc2.print_total();

	return 0;
}
