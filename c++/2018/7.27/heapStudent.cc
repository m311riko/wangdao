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

    //用来销毁堆对象
    void destroy()
    {
        delete this;
    }

    void print() const
    {
        cout<<"id: "<<_id<<endl;
        cout<<"name: "<<_name<<endl;
    }

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
    //可以生成堆对象，不能生成栈对象
    //方法：将析构函数放到private区域
    ~Student()
    {
        cout<<"~Stuent()"<<endl;
        delete []_name;
    }

    int _id;
    char *_name;
};

int main()
{
    //Student s(101,"Alice");   不能生成栈对象
    //s.print();

    Student *pstu=new Student(100,"Mike");
    pstu->print();

    pstu->destroy();

    return 0;
}
