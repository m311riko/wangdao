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

private:
    //可以生成栈对象，不能生成堆对象
    //方法：将operator new/delete放在private区域
    void *operator new(size_t sz);
    void operator delete(void *ret);

    int _id;
    char *_name;
};

int main()
{
    Student s(101,"Alice");
    s.print();

    //Student *pstu=new Student(100,"Mike");
    //pstu->print();

    //delete pstu;

    return 0;
}
