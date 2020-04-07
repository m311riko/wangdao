#include <iostream>

using std::cout;
using std::endl;

class NullPointerCall
{
public:
	static void test1();
	void test2();
	void test3(int ix);
	void test4();

private:
	static int _istatic;
	int _ix;
};

int NullPointerCall::_istatic=0;

//对于静态成员函数而言，没有this指针，所以只能使用静态成员变量
void NullPointerCall::test1()
{
	cout<<"test1() static:"<<_istatic<<endl;
}

void NullPointerCall::test2()
{
	cout<<"test2()"<<endl;
}

void NullPointerCall::test3(int ix)
{
	cout<<"test3()"<<ix<<endl;
}

//对于非静态成员函数而言，第一个参数是隐藏的this指针
void NullPointerCall::test4()
{
	cout<<"test4()"<<this->_ix<<endl;
}

int main()
{
	NullPointerCall *npc=NULL;
	npc->test1();
	npc->test2();
	npc->test3(5);
	npc->test4();	//报错，因为this指针指向的对象为NULL
}
