#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

//单例对象的自动释放：
//方法一：
//1、嵌套类+静态对象；
//2、注意线程安全；

class Singleton
{
    class AutoRelease   //嵌套类，只为Singleton服务
    {
    public:
        AutoRelease()
        {
            cout<<"AutoRelease()"<<endl;
        }

        //全局/静态对象在程序退出时自动调用析构函数
        ~AutoRelease()
        {
            if(_pInstance)
            {
                cout<<"~AutoRelease()"<<endl;
                delete _pInstance;
            }
        }
    };

public:
    static Singleton *getInstance()
    {
        //在多线程环境下并不是线程安全的
        //解决方案：
        //1、懒汉模式+加锁mutex.lock()；
        //2、饱汉模式；
        if(_pInstance==NULL)
        {
            _pInstance=new Singleton();
        }
        return _pInstance;
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
    static AutoRelease _ar;
};

//Singleton *Singleton::_pInstance=NULL;  //懒汉模式->懒加载，只在需要的时候创建单例对象
Singleton *Singleton::_pInstance=getInstance(); //饱汉模式，多线程安全
Singleton::AutoRelease Singleton::_ar;

int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();

    printf("p1=%p\n",p1);
    printf("p2=%p\n",p2);

    return 0;
}
