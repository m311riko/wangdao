#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class CharArray
{
public:
    CharArray(int size)
    :_size(size)
    ,_pdata(new char[_size]())
    {
        cout<<"CharArray(int)"<<endl;
    }

    //重载[]，以成员函数形式
    char &operator[](size_t idx)
    {
        cout<<"char &operator[](size_t)"<<endl;
        if(idx<_size)
        {
            return _pdata[idx];
        }
        else
        {
            static char nullchar='\0';
            cout<<"index out of range"<<endl;
            return nullchar;
        }
    }

    size_t size() const
    {
        return _size;
    }

    ~CharArray()
    {
        delete [] _pdata;
    }

private:
    char *_pdata;
    size_t _size;
};

int main()
{
    const char *pstr="hello,world";
    CharArray ca(strlen(pstr)+1);

    for(size_t idx=0;idx!=ca.size();++idx)
    {
        ca[idx]=pstr[idx];
    }

    for(size_t idx=0;idx!=ca.size();++idx)
    {
        cout<<ca[idx]<<endl;
    }

    return 0;
}
