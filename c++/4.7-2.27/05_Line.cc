#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix,int iy);
	Point(const Point &rhs);
	void print();

private:
	int _ix;
	int _iy;
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


class Line
{
public:
	Line(int x1,int y1,int x2,int y2);
	Line(const Line &rhs);
	void draw();

private:
	Point _pt1;
	Point _pt2;
};

//如果不显式初始化Point对象_pt1、_pt2，系统会自动调用
//Point默认构造函数去创建_pt1、_pt2
Line::Line(int x1,int y1,int x2,int y2)
:_pt1(x1,y1)
,_pt2(x2,y2)
{
	cout<<"Line(int,int,int,int)"<<endl;
}

Line::Line(const Line &rhs)
:_pt1(rhs._pt1)	//显式调用对象的复制构造函数
,_pt2(rhs._pt2)
{
	cout<<"Line(const Line &rhs)"<<endl;
}

void Line::draw()
{
	_pt1.print();
	cout<<"to";
	_pt2.print();
}

int main()
{
	Line line(1,2,3,4);
	line.draw();

	Line line2(line);
	line2.draw();

	return 0;
}
