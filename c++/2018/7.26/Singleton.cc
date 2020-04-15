#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//单例模式：
//要求：在内存中只能创建一个对象
//
//应用场景：
//1、直接替换任意的全局对象；
//2、配置文件；
//3、词典类

class Singleton
{
public:
    static Singleton * getInstance()
    {
        if(NULL==_pInstance)
        {
            _pInstance=new Singleton(); //在类内部调用构造函数
        }

        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

private:
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }

    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }

    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance=NULL;

int main()
{
    Singleton * p1=Singleton::getInstance();
    Singleton * p2=Singleton::getInstance();

    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);

    Singleton::destroy();

    return 0;
}
