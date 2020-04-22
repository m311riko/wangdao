#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(_pInstance==NULL)
        {
            _pInstance=new Singleton();
            atexit(destroy);    //进程退出时调用display()回收空间，但是不是线程安全的
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

private:
    static Singleton *_pInstance;
};

Singleton *Singleton::_pInstance=NULL;

int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();

    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);

    return 0;
}
