#include <iostream>

using std::cout;
using std::endl;

class Computer
{
public:
	Computer(float fprice);
	~Computer();
	void print();

private:
	float _fprice;
	static float _ftotalPrice;
};

float Computer::_ftotalPrice=0.0f;	//静态成员变量必须在类外进行初始化

Computer::Computer(float fprice)
:_fprice(fprice)
{
	cout<<"Computer(float)"<<endl;
	_ftotalPrice+=_fprice;
}

Computer::~Computer()
{
	_ftotalPrice-=_fprice;
}

void Computer::print()
{
	cout<<"价格："<<this->_fprice<<endl;	//this代表对象本身，它是一个隐藏的参数
	cout<<"总价："<<_ftotalPrice<<endl;
}

int main()
{
	Computer pc1(7000);
	cout<<"after buy pc1"<<endl;
	pc1.print();

	Computer pc2(5000);
	cout<<"after buy pc2"<<endl;
	pc2.print();

	cout<<"pc1的存储空间："<<sizeof(pc1)<<endl;
	cout<<"Computer的存储空间："<<sizeof(Computer)<<endl;

	return 0;
}
