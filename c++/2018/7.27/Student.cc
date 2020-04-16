#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student(int id,const char *name)
    :_id(id)
    ,_name(new char[strlen(name)+1]())
    {
        cout<<"Stuent(int,const char*)"<<endl;
        strcpy(_name,name);
    }

    void print() const
    {
        cout<<"id: "<<_id<<endl;
        cout<<"name: "<<_name<<endl;
    }

    ~Student()
    {
        cout<<"~Stuent()"<<endl;
        delete []_name;
    }

    //重定义开辟空间的方式
    //只针对自定义类型Student起作用
    void *operator new(size_t sz)
    {
        cout<<"operator new(size_t)"<<endl;
        void *ret=malloc(sz);
        return ret;
    }

    void operator delete(void *ret)
    {
        cout<<"operator delete(void*)"<<endl;
        free(ret);
    }

private:
    int _id;
    char *_name;
};

int main()
{
    //new表达式工作机制：
    //1、调用operator new函数开辟空间；
    //2、调用构造函数初始化开辟的空间；
    //3、将开辟的空间赋给指针。
    Student *pstu=new Student(100,"Mike");
    pstu->print();

    //delete表达式工作机制：
    //1、调用析构函数回收开辟的空间；
    //2、调用operator delete函数回收开辟的空间。
    delete pstu;

    return 0;
}
