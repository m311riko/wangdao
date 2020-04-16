#include <iostream>

using std::cout;
using std::endl;

const int NUM=10;

class Queue
{
public:
    Queue()
    {
        cout<<"Queue()"<<endl;
        for(int i=0;i<NUM;i++)
        {
            _arr[i]=-1;
        }

        _begin=0;
        _end=0;
    }

    ~Queue()
    {
        cout<<"~Queue()"<<endl;
    }

    void push(int num);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
    void print();

private:
    int _arr[NUM];
    int _end;
    int _begin;
};

bool Queue::empty()
{
    if(_begin==_end)    //尾指针是否与头指针重合
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Queue::full()
{
    if((_end+1)%NUM==(_begin))  //尾指针加一后是否与头指针重合
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Queue::push(int num)
{
    if(!full())
    {
        cout<<"push("<<num<<")"<<endl;
        _end=(_end+1)%NUM;  //尾指针加一
        _arr[_end]=num; //放入元素
    }
    else
    {
        cout<<"queue full"<<endl;
    }
}

void Queue::pop()
{
    if(!empty())
    {
        cout<<"pop()"<<endl;
        _begin=(_begin+1)%NUM;  //头指针加一
    }
    else
    {
        cout<<"queue empty"<<endl;
    }
}

int Queue::front()
{
    cout<<"front()"<<endl;
    return _arr[_begin+1];
}

int Queue::back()
{
    cout<<"back()"<<endl;
    return _arr[_end];
}

void Queue::print()
{
    for(int i=0;i<NUM;i++)
    {
        cout<<_arr[i]<<", ";
    }
    cout<<endl;
}

int main()
{
    Queue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    queue.push(7);
    queue.push(8);
    queue.push(9);
    queue.push(10);
    queue.push(11);

    queue.pop();

    cout<<queue.front()<<endl;
    cout<<queue.back()<<endl;

    return 0;
}
