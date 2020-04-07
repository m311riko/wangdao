#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//有参构造函数
	Point(int ix,int iy,double &z);

	//复制构造函数
	Point(const Point &rhs);

	void print();
	void setX(int ix);

private:
	int _ix;
	int _iy;
	int &_ref1;		//引用的初始化必须在成员初始化列表进行
	double &_ref2;
};

Point::Point(int ix,int iy,double &z)
:_ix(ix)	//初始化语句
,_iy(iy)
,_ref1(_ix)
,_ref2(z)
{
	//_ix=ix;	//赋值语句
	cout<<"Point(int,int)"<<endl;
}

Point::Point(const Point &rhs)
:_ix(rhs._ix)
,_iy(rhs._iy)
,_ref1(rhs._ref1)
,_ref2(rhs._ref2)
{
	cout<<"Point(const Point &rhs)"<<endl;
}

void Point::print()
{
	cout<<"("<<_ix
		<<","<<_iy
		<<","<<_ref1
		<<","<<_ref2
		<<")"<<endl;
}

void Point::setX(int ix)
{
	_ix=ix;
}

int main()
{
	double d1=5.0;
	Point p1(3,4,d1);
	p1.print();

	Point p2(p1);
	p2.print();

	cout<<endl;
	p1.setX(7);
	p1.print();
	p2.print();

	return 0;
}
