#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	//默认构造函数
	Computer()
	{
		cout<<"Computer()"<<endl;
		int len=strlen("lenovo");
		_brand=new char[len+1];
		strcpy(_brand,"lenovo");
		_fprice=4000;
	}

	//有参构造函数
	Computer(const char *brand,float fprice)
	{
		cout<<"Computer(const char*,float)"<<endl;
		int len=strlen(brand);
		_brand=new char[len+1];
		strcpy(_brand,brand);
		_fprice=fprice;
	}

	//默认复制构造函数
#if 0
	Computer(const Computer &rhs)
	:_brand(rhs._brand)		//浅拷贝
	,_fprice(fhs._fprice)
	{
		
	}
#endif

	//复制构造函数
	Computer(const Computer &rhs)
	:_fprice(rhs._fprice)
	{
		cout<<"Computer(const Computer &)"<<endl;
		int len=strlen(rhs._brand);
		_brand=new char[len+1];
		strcpy(_brand,rhs._brand);	//深拷贝
	}

	//析构函数
	~Computer()
	{
		delete []_brand;
		cout<<"~Computer()"<<endl;
	}

	void setBrand(char *brand);
	void setPrice(float fprice);
	void print();

private:
	char *_brand;
	float _fprice;
};

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
	Computer pc1;
	pc1.print();

	Computer pc2=pc1;	//调用复制构造函数
	pc2.print();

	return 0;
}
