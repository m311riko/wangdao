#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	//默认构造函数
#if 0
	Computer()
	{
		cout<<"Computer()"<<endl;
		strcpy(_brand,"lenovo");
		_fprice=4000;
	}
#endif

	Computer()
	{
		cout<<"Computer()"<<endl;
	}

	//构造函数可以重载
	//当提供有参构造函数时，系统不会提供默认构造函数
	Computer(const char *brand,float fprice)
	{
		cout<<"Computer(const char*,float)"<<endl;
		strcpy(_brand,brand);
		_fprice=fprice;
	}

	void setBrand(char *brand);
	void setPrice(float fprice);
	void print();

private:
	char _brand[30];
	float _fprice;
};

//类之外实现成员函数
void Computer::setBrand(char *brand)
{
	strcpy(_brand,brand);
}

void Computer::setPrice(float fprice)
{
	_fprice=fprice;
}

void Computer::print()
{
	cout<<"品牌："<<_brand<<endl;
	cout<<"价格："<<_fprice<<endl;
}

int main()
{
	int a;
	Computer pc1;	//会调用默认构造函数
	pc1.print();
	cout<<endl;

	Computer pc2("DELL",6000);	//调用有参构造函数
	pc2.print();

	return 0;
}
