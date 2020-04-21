#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class String
{
public:
    //默认构造函数
    String()
    :_pstr(new char[1]())
    {
        cout<<"String()"<<endl;
    }

    //有参构造函数
    String(const char *pstr)
    :_pstr(new char[strlen(pstr)+1]())
    {
        cout<<"String(const char*)"<<endl;
        strcpy(_pstr,pstr);
    }

    //复制构造函数
    String(const String &rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        cout<<"String(const String&)"<<endl;
        strcpy(_pstr,rhs._pstr);
    }

    //析构函数
    ~String()
    {
        cout<<"~String()"<<endl;
        delete _pstr;
    }

    //赋值运算符函数
    String &operator=(const String &rhs)
    {
        cout<<"String &operatro=(const String &)"<<endl;

        if(this!=&rhs)
        {
            delete _pstr;

            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }

    void print() const
    {
        cout<<_pstr<<endl;
    }

    //重载=
    String &operator=(const char *pstr)
    {
        cout<<"String &operator=(const char *)"<<endl;

        delete _pstr;
        _pstr=new char[strlen(pstr)+1]();
        strcpy(_pstr,pstr);

        return *this;
    }

    //重载+=
    String &operator+=(const String &rhs)
    {
        cout<<"operator+=(const String &rhs)"<<endl;

        strcat(_pstr,rhs._pstr);
        return *this;
    }

    //重载+=
    String &operator+=(const char *pstr)
    {
        cout<<"operator+=(const char *pstr)"<<endl;

        strcat(_pstr,pstr);
        return *this;
    }

    //重载[]
    char &operator[](std::size_t index)
    {
        cout<<"operator[](std::size_t index)"<<endl;

        return _pstr[index];
    }

    //重载[]
    const char &operator[](std::size_t index) const
    {
        cout<<"operator[](std::size_t index) const"<<endl;

        return _pstr[index];
    }

    std::size_t size() const
    {
        cout<<"size()"<<endl;

        int idx=0;
        while(_pstr[idx]!='\0')
        {
            ++idx;
        }

        return idx;
    }

    const char *c_str() const
    {
        cout<<"c_str()"<<endl;

        return _pstr;
    }

    friend bool operator==(const String &,const String &);
    friend bool operator!=(const String &,const String &);

    friend bool operator<(const String &,const String &);
    friend bool operator>(const String &,const String &);
    friend bool operator<=(const String &,const String &);
    friend bool operator>=(const String &,const String &);

    friend std::ostream &operator<<(std::ostream &os,const String &s);
    friend std::istream &operator>>(std::istream &is,String &s);

    char *getPstr() const
    {
        return _pstr;
    }

private:
    char *_pstr;
};

bool operator==(const String &lhs,const String &rhs)
{
    cout<<"operator==(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!=(const String &lhs,const String &rhs)
{
    cout<<"operator!=(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<(const String &lhs,const String &rhs)
{
    cout<<"operator<(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>(const String &lhs,const String &rhs)
{
    cout<<"operator>(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(const String &lhs,const String &rhs)
{
    cout<<"operator<=(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(const String &lhs,const String &rhs)
{
    cout<<"operator>=(const String &,const String &)"<<endl;

    if(strcmp(lhs._pstr,rhs._pstr)>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream &operator<<(std::ostream &os,const String &s)
{
    cout<<"operator<<(ostream &,String &)"<<endl;

    os<<s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is,String &s)
{
    cout<<"operator>>(istream &,String &)"<<endl;

    is>>s._pstr;
    return is;
}

String operator+(const String &lhs,const String &rhs)
{
    cout<<"operator+(const String &,const String &)"<<endl;

    return String(strcat(lhs.getPstr(),rhs.getPstr()));
}

String operator+(const String &lhs,const char *ptr)
{
    cout<<"operator+(const String &,const char *)"<<endl;

    return String(strcat(lhs.getPstr(),ptr));
}

//有错误
#if 0
String operator+(const char *ptr,const String &rhs)
{
    cout<<"operator+(const char *,const String &)"<<endl;

    return String(strcat(ptr,rhs.getPstr()));
}
#endif

int main()
{
    String s1;
    s1.print();

    String s2("hello");
    s2.print();

    String s3(s2);
    s3.print();

    String s4;
    s4=s3;
    s4.print();

    String s5;
    s5="world";
    s5.print();

    String s6("hello");
    s6+=s5;
    s6.print();

    String s7("hello");
    s7+="world";
    s7.print();

    cout<<s7[1]<<endl;

    String s8("hello");
    cout<<s8.size()<<endl;

    String s9("hello");
    cout<<s9.c_str()<<endl;

    String s10("hello");
    String s11("hell");
    cout<<(s10==s11)<<endl;

    String s12;
    cout<<"pls input string:";
    cin>>s12;
    cout<<"s12:";
    cout<<s12;

    cout<<"-------"<<endl;

    String s13("hello");
    String s14("world");
    String s15=s13+s14;
    s15.print();

    String s16("hi");
    String s17=s16+"how are you";
    s17.print();

#if 0
    String s18("world");
    char *msg="hello";
    String s19=msg+s18;
    s19.print();
#endif

    return 0;
}
