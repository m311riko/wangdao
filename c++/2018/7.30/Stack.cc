#include <iostream>

using std::cout;
using std::endl;

class Stack
{
public:
    //栈空间为10
    //栈顶指针初始在-1处
    Stack(int size=10)
    :_top(-1)
    ,_size(size)
    ,_array(new int[_size]())
    {
        cout<<"Stack()"<<endl;
    }

    bool full() const
    {
        return _top==_size-1;
    }

    bool empty() const
    {
        return _top==-1;
    }

    int top() const
    {
        return _array[_top];
    }

    //先向上移动栈顶指针
    //再向栈顶指针处添加元素
    void push(int number)
    {
        if(!full())
        {
            _array[++_top]=number;
        }
        else
        {
            cout<<"Stack has full, can't push any element"<<endl;
        }
    }

    //栈顶指针向下移动
    void pop()
    {
        if(!empty())
        {
            --_top;
        }
        else
        {
            cout<<"Stack has empty"<<endl;
        }
    }

    ~Stack()
    {
        delete [] _array;
    }

private:
    int _top;
    int _size;
    int *_array;
};

int main()
{
    Stack stack;
    cout<<"此时栈为空?"<<stack.empty()<<endl;

    stack.push(1);
    cout<<"此时栈为空?"<<stack.empty()<<endl;

    for(int idx=2;idx<11;idx++)
    {
        stack.push(idx);
    }
    cout<<"此时栈为满?"<<stack.full()<<endl;

    while(!stack.empty())
    {
        cout<<stack.top()<<endl;
        stack.pop();
    }
    cout<<"此时栈为空?"<<stack.empty()<<endl;

    return 0;
}
