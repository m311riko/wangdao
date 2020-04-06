#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
	//成员初始化列表
	Point()
	:_ix(0)
	,_iy(0)
	{
		cout<<"Point()"<<endl;
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
