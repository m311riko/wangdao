#include <iostream>

using std::cout;
using std::endl;

const int NUM=10;

class Stack
{
public:
    Stack()
    {
        cout<<"Stack()"<<endl;
        for(int i=0;i<NUM;i++)
        {
            _arr[i]=-1;
        }

        _pos=0;
    }

    ~Stack()
    {
        cout<<"~Stack()"<<endl;
    }

    void push(int num)
    {
        cout<<"push("<<num<<")"<<endl;
        _arr[_pos]=num;
        ++_pos;
    }

    void pop()
    {
        cout<<"pop()"<<endl;
        --_pos;
    }

    int top()
    {
        cout<<"top()"<<endl;
        return _arr[_pos-1];
    }

    bool empty()
    {
        cout<<"empty()"<<endl;
        if(_pos<=0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool full()
    {
        cout<<"full()"<<endl;
        if(_pos>10)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void print()
    {
        for(int i=0;i<NUM;i++)
        {
            cout<<_arr[i]<<", ";
        }
        cout<<endl;
    }

private:
    int _arr[NUM];
    int _pos;
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(10);
    stack.push(12);
    stack.push(14);
    stack.print();

    cout<<stack.top()<<endl;

    stack.pop();
    stack.print();

    cout<<stack.top()<<endl;

    return 0;
}
