#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student()
    {
        cout<<"Student()"<<endl;
    }

    //可以生成堆对象，堆对象释放时delete不调用析构函数
    void destroy()
    {
        delete this;
    }

private:
    int _iId;
    char _name[20];

    //不能生成栈对象
    ~Student()
    {
        cout<<"~Student()"<<endl;
    }
};

int main()
{
    Student *pStu=new Student;
    pStu->destroy();
    //delete pStu;
    //Student std;
    
    return 0;
}
