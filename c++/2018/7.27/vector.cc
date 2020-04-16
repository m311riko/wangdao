#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void printCapacity(vector<int> &vec)
{
    cout<<"vec's size: "<<vec.size()<<endl;
    cout<<"vec's capacity: "<<vec.capacity()<<endl;
}

int main()
{
    //动态数组扩容策略：
    //当数组的元素个数与能容纳元素的个数相等时：
    //1、先申请原来2倍大小的空间；
    //2、把原来空间的数据复制到新空间上；
    //3、回收原来申请的空间；
    //4、添加新的元素
    vector<int> numbers;
    cout<<"sizeof(numbers): "<<sizeof(numbers)<<endl;
    numbers.reserve(100);   //vector应用技巧

    numbers.push_back(1);
    printCapacity(numbers);
    numbers.push_back(2);
    printCapacity(numbers);
    numbers.push_back(3);
    printCapacity(numbers);
    numbers.push_back(4);
    printCapacity(numbers);
    numbers.push_back(5);
    printCapacity(numbers);
    numbers.push_back(6);
    printCapacity(numbers);
    numbers.push_back(7);
    printCapacity(numbers);
    numbers.push_back(8);
    printCapacity(numbers);
    numbers.push_back(9);
    printCapacity(numbers);
    numbers.push_back(10);
    printCapacity(numbers);
    cout<<"sizeof(numbers): "<<sizeof(numbers)<<endl;

    //遍历vector
    for(size_t idx=0;idx!=numbers.size();++idx)
    {
        cout<<numbers[idx]<<" ";
    }
    cout<<endl;

    //c++11遍历方法
    for(auto &number:numbers)
    {
        cout<<number<<" ";
    }
    cout<<endl;

    return 0;
}
