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

	//如果不显式定义，系统会自动提供一个赋值运算符函数
	//赋值运算符函数的返回值是引用
	//如果换成对象，会调用复制构造函数，相当于多做了一次冗余操作，降低效率
	Computer& operator=(const Computer &rhs)
	{
		cout<<"Computer& operator=(const Computer&)"<<endl;

		if(this==&rhs)
		{
			return *this;	//自复制
		}
		
		delete []_brand;	//先释放掉原来_brand所指的空间
		int len=strlen(rhs._brand);
		_brand=new char[len+1];		//再创建新的空间
		strcpy(_brand,rhs._brand);
		_fprice=rhs._fprice;

		return *this;
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
	int a=3;
	int b;
	b=a;

	Computer pc1;	//调用默认构造函数
	Computer pc2("Mac",10000);	//调用有参构造函数
	pc1.print();

	pc1=pc1;	//自复制

	pc2=pc1;	//调用赋值运算符函数
	pc2.print();

	Computer pc3=pc2;	//调用复制构造函数
	pc3.print();

	return 0;
}
