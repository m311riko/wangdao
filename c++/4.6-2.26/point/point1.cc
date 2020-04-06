#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//成员初始化列表
	//初始化顺序是由数据成员在声明时的顺序决定的
	Point()
	:_iy(0)
	,_ix(_iy)
	{
		cout<<"Point()"<<endl;
	}

	//如果不显式定义析构函数，系统会为我们自动提供一个析构函数
	//当对象销毁时，会自动调用析构函数
	~Point()
	{
		cout<<"~Point()"<<endl;
	}

	void print()
	{
		cout<<"("<<_ix<<", "<<_iy<<")"<<endl;
	}

private:
	int _ix;
	int _iy;
};

int main()
{
	Point p1;
	p1.print();

	return 0;
}
