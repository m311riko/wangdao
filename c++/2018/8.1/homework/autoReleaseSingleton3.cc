#include <stdio.h>
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

//单例对象的自动释放：
//方法二：
//1、atexit()；
//2、pthread_once()保证线程安全；

class Singleton
{
public:
    static Singleton *getInstance()
    {
        pthread_once(&_once,init);  //只调用一次，线程安全
        return _pInstance;
    }

    static void init()
    {
        _pInstance=new Singleton();
        atexit(destroy);    //进程退出时调用display()回收空间
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
    static pthread_once_t _once;
};

Singleton *Singleton::_pInstance=NULL;
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();

    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);

    return 0;
}
