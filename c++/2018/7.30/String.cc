#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
    String()
    :_pstr(new char[1]())
    {
        cout<<"String()"<<endl;
    }

    String(const char * pstr)
    :_pstr(new char[strlen(pstr)+1]())
    {
        cout<<"String(const char *)"<<endl;
        strcpy(_pstr,pstr);
    }

    String(const String &rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
    }

    String & operator=(const String &rhs)
    {
        if(this!=&rhs)  //自复制
        {
            delete [] _pstr;    //回收操作数空间

            _pstr=new char[strlen(rhs._pstr)+1]();  //深拷贝
            strcpy(_pstr,rhs._pstr);
        }

        return *this;
    }

    ~String()
    {
        cout<<"~String()"<<endl;
        delete _pstr;
    }

    void print() const
    {
        cout<<_pstr<<endl;
    }

private:
    char *_pstr;
};

int main()
{
    String s1;
    s1.print();

    String s2("hello,world");
    s2.print();

    return 0;
}
