#include <iostream>

using std::cout;
using std::endl;

class Data
{
public:
    Data()
    :_ix(10)
    {
        cout<<"Data()"<<endl;
    }

    int getX() const
    {
        return _ix;
    }

    ~Data()
    {
        cout<<"~Data()"<<endl;
    }

private:
    int _ix;
};

class MiddleLayer
{
public:
    MiddleLayer()
    :_pdata(new Data)
    {
        cout<<"MiddleLayer()"<<endl;
    }

    ~MiddleLayer()
    {
        cout<<"~MiddleLayer()"<<endl;
        delete _pdata;
    }

    //指针运算符返回值是一个指针
    Data *operator->()
    {
        return _pdata;
    }

    //解引用运算符
    Data &operator*()
    {
        return *_pdata;
    }

private:
    Data *_pdata;
};

class ThirdLayer
{
public:
    ThirdLayer()
    :_pMiddleLayer(new MiddleLayer())
    {
        cout<<"ThirdLayer()"<<endl;
    }

    //指针运算符返回一个重载了指针运算符的对象
    MiddleLayer &operator->()
    {
        return *_pMiddleLayer;
    }

    ~ThirdLayer()
    {
        cout<<"~ThirdLayer()"<<endl;
    }

private:
    MiddleLayer *_pMiddleLayer;
};

int main()
{
    MiddleLayer ml; //ml本身是对象，智能指针的雏形
    cout<<(*ml).getX()<<endl;
    cout<<ml->getX()<<endl;

    cout<<(ml.operator->())->getX()<<endl;
    cout<<endl;

    ThirdLayer tl;
    cout<<tl->getX()<<endl;
    cout<<((tl.operator->()).operator->())->getX()<<endl;

    return 0;
}
