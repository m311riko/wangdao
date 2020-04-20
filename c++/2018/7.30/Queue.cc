#include <iostream>

using std::cout;
using std::endl;

class Queue
{
public:
    Queue(int size=10)
    :_size(size)
    ,_head(0)
    ,_tail(0)
    ,_array(new int[_size]())
    {
        cout<<"Queue()"<<endl;
    }

    bool empty() const
    {
        return _head==_tail;
    }

    bool full() const
    {
        return _head==((_tail+1)%_size);
    }

    void push(int number)
    {
        if(!full())
        {
            _tail=(_tail+1)%_size;
            _array[_tail]=number;
        }
        else
        {
            cout<<"Queue is full"<<endl;
        }
    }

    void pop()
    {
        if(!empty())
        {
            _head=(_head+1)%_size;
        }
        else
        {
            cout<<"Queue is empty"<<endl;
        }
    }

    int front() const
    {
        return _array[(_head+1)%_size];
    }

    int back() const
    {
        return _array[_tail];
    }

    ~Queue()
    {
        delete [] _array;
    }

private:
    int *_array;
    int _size;
    int _head;
    int _tail;
};

int main()
{
    Queue queue;
    cout<<"此时队列是否为空?"<<queue.empty()<<endl;

    queue.push(1);
    cout<<"此时队列是否为空?"<<queue.empty()<<endl;

    for(int idx=2;idx<10;++idx)
    {
        queue.push(idx);
    }
    cout<<"队头元素为："<<queue.front()<<endl;
    cout<<"队尾元素为："<<queue.back()<<endl;

    while(!queue.empty())
    {
        cout<<queue.front()<<endl;
        queue.pop();
    }
    cout<<"此时队列是否为空?"<<queue.empty()<<endl;

    return 0;
}
