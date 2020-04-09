#include <iostream>

using std::cout;
using std::endl;

//单例模式的对象：
//1、不能是栈对象；
//2、应该是一个堆对象；
//3、不能直接通过new创建堆对象；
//4、需要把构造函数放在private区域；
//5、用静态成员函数来创建对象；
//6、创建好的对象需要用静态数据成员保存；

class Singleton
{
public:
    //2、提供一个静态的成员函数
    static Singleton *getInstance()
    {
        if(NULL==_pInstance)
        {
            _pInstance=new Singleton;
        }

        return _pInstance;
    }

private:
    //1、将构造函数放在private区域
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }

    //3、提供一个指向对象的静态数据成员指针
    static Singleton *_pInstance;
};

Singleton* Singleton::_pInstance=NULL;  //静态变量必须在类外定义

int main()
{
    Singleton *p1=Singleton::getInstance();
    printf("p1=%p\n",p1);

    Singleton *p2=Singleton::getInstance();
    printf("p2=%p\n",p2);

    Singleton *p3=Singleton::getInstance();
    printf("p3=%p\n",p3);

    return 0;
}
