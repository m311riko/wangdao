#include <iostream>

using std::cout;
using std::endl;

const int NUM = 10;

class Stack
{
public:
    Stack()
    {
        cout << "Stack()" << endl;
        for (int i = 0; i < NUM; i++)
        {
            _arr[i] = -1;
        }

        _pos = 0;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
    }

    void push(int);
    void pop();
    int top();
    bool empty();
    bool full();
    void print();

    void getPos()
    {
        cout<<_pos<<endl;
    }

private:
    int _arr[NUM];
    int _pos;
};

void Stack::push(int num)
{
    if(!full())
    {
        cout << "push(" << num << ")" << endl;
        _arr[_pos] = num;
        ++_pos;
    }
    else
    {
        cout<<"stack full"<<endl;
    }
}

void Stack::pop()
{
    cout << "pop()" << endl;
    if(!empty())
    {
        --_pos;
    }
    else
    {
        cout<<"stack empty"<<endl;
    }
}

int Stack::top()
{
    cout<<"top()"<<endl;
    if(!empty() && !full())
    {
        return _arr[_pos - 1];
    }
    else
    {
        if(empty())
        {
            cout<<"stack empty"<<endl;
            return -1;

        }else if(full())
        {
            return _arr[_pos-1];
        }
    }

    return 0;
}

bool Stack::empty()
{
    if (_pos <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::full()
{
    if (_pos >= 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::print()
{
    for (int i = 0; i < NUM; i++)
    {
        cout << _arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(12);
    stack.push(14);
    cout<<endl;

    cout << stack.top() << endl;
    cout<<endl;

    stack.pop();
    cout<<endl;

    cout << stack.top() << endl;

    return 0;
}
