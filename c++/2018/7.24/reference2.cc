#include <iostream>

using std::cout;
using std::endl;

int arr[5]={0,1,2,3,4};

int &func(int idx)  //返回值是引用，返回的变量生命周期一定要大于函数本身
{
    return arr[idx];
}

int func1()
{
    int num=10;
    return num;     //一旦执行return语句，就会被复制
}

int &func2()
{
    int num=10;
    return num;     //不要返回局部变量的引用
                    //会引发段错误
}

int *func3()
{
    int num=10;
    return &num;
}

int &func4()
{
    int *p=new int(11);
    return *p;      //不要轻易返回一个堆空间变量的引用
                    //除非有一个回收空间的策略
}

int main()
{
    cout<<func(0)<<endl;
    func(0)=10;
    cout<<"arr[0]="<<arr[0]<<endl;

    cout<<func1()<<endl;

    //cout<<func2()<<endl;

    cout<<func3()<<endl;

    int a=3;
    int b=4;
    int c=a+b+func4();      //每调用一次func4()，就会产生一次内容泄漏
    cout<<"c="<<c<<endl;

    int &ref=func4();
    cout<<"ref="<<ref<<endl;
    delete &ref;

    return 0;
}
