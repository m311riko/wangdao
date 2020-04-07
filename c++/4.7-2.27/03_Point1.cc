#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//有参构造函数
	Point(int ix,int iy);

	//复制构造函数
	Point(const Point &rhs);

	void print();

private:
	const int _ix;	//const成员的初始化必须放到初始化成员列表里进行
	const int _iy;
};

Point::Point(int ix,int iy)
:_ix(ix)	//初始化语句
,_iy(iy)
{
	//_ix=ix;	//赋值语句
	cout<<"Point(int,int)"<<endl;
}

Point::Point(const Point &rhs)
:_ix(rhs._ix)
,_iy(rhs._iy)
{
	cout<<"Point(const Point &rhs)"<<endl;
}

void Point::print()
{
	cout<<"("<<_ix
		<<","<<_iy
		<<")"<<endl;
}

int main()
{
	Point p1(3,4);
	p1.print();

	return 0;
}
