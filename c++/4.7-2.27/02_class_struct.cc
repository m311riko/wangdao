#include <iostream>

class A
{
	int _ia;	//默认情况下的访问权限是private
};

struct B
{
	int _ia;	//默认情况下的访问权限是public
};

int main()
{
	A a;
	//a._ia=10;

	B b;
	b._ia=10;

	return 0;
}
