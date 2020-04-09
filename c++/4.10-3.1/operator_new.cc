#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    //能生成栈对象
    Student()
    {
        cout<<"Student()"<<endl;
    }

    ~Student()
    {
        cout<<"~Student()"<<endl;
    }

private:
    int _iId;
    char _name[20];

    //不能生成堆对象
    static void* operator new(size_t);
    static void operator delete(void*);
#if 0
    static void* operator new(size_t sz)
    {
        cout<<"operator new()"<<endl;
        void *pRet=malloc(sz);
        return pRet;
    }

    static void* operator delete(void *pRet)
    {
        cout<<"operator delete()"<<endl;
        free(pRet);
    }
#endif
};

int main()
{
    //Student *pStu=new Student();
    //delete pStu;
    Student std;

    return 0;
}
