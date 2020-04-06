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

	//explicit:该函数要显式调用
	Point(int ix,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
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
	cout<<endl;

	Point p2=3;		//隐式转换，通过相应的构造函数创建一个临时对象
					//再将这个临时对象通过复制构造函数来初始化p2
	p2.print();

	return 0;
}
