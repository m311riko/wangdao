//1、namespace最好使用using声明机制；
//2、类的public部分相当于对外提供接口；
//3、类的实现（也就是成员函数）可以在类里面定义，也可以在类外面定义；
//4、类的成员函数可以使用类的私有成员变量、私有成员函数；
//5、注意类声明后面有个分号，与结构体定义保持一致。

#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Computer
{
//对外提供接口
public:
	void setBrand(char *brand)
	{
		strcpy(_brand,brand);
		print();	//在类里面使用私有的成员函数
	}

	void setPrice(float fprice)
	{
		_fprice=fprice;
	}
	
private:
	char _brand[20];
	float _fprice;

	void print()
	{
		cout<<"品牌："<<_brand<<endl;	//在类里面使用私有的成员变量
		cout<<"价格："<<_fprice<<endl;
	}
};

int main()
{
	int a;
	Computer pc1;	//类的实例化
	//pc1._fprice=10;	//信息隐藏
	pc1.setPrice(5000);
	pc1.setBrand("Thinkpad");
	//pc1.print();

	return 0;
}
