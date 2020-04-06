//1、在类外面实现类
//2、注意：类声明结尾要加一个小分号

#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
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
	Computer pc1;	//类的实例化
	pc1.setPrice(5000);
	pc1.setBrand("Thinkpad");
	pc1.print();

	return 0;
}
