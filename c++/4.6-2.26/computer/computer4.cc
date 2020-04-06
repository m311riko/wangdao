#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	//虚构函数中使用delete销毁堆空间
	//构造函数必须使用new开辟空间
	Computer()
	{
		cout<<"Computer()"<<endl;
		int len=strlen("lenovo");
		_brand=new char[len+1];
		strcpy(_brand,"lenovo");
		_fprice=4000;
	}

	//构造函数中有new出来的堆内存空间
	//必须用虚构函数delete
	Computer(const char *brand,float fprice)
	{
		cout<<"Computer(const char*,float)"<<endl;
		int len=strlen(brand);
		_brand=new char[len+1];
		strcpy(_brand,brand);
		_fprice=fprice;
	}

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

//会调用构造函数和析构函数
Computer p2;

int main()
{
	Computer *p1=new Computer;	//调用Computer()构造函数
	p1->print();
	p1->~Computer();	//析构函数可以显式调用，但是一般不这样使用

	delete p1;	//new出来的堆内存空间必须释放掉

	return 0;
}
