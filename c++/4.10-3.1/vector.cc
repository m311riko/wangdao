#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

void printVector(std::vector<int> &vecInt)
{
    cout<<"vecInt's size:"<<vecInt.size()<<endl;
    cout<<"vecInt's capacity:"<<vecInt.capacity()<<endl;
}

int main()
{
    std::vector<int> vecInt;    //存储空间是动态增长的，每次都乘以2
    printVector(vecInt);
    
    vecInt.push_back(1);
    printVector(vecInt);

    vecInt.push_back(2);
    printVector(vecInt);

    vecInt.push_back(3);
    printVector(vecInt);

    vecInt.push_back(4);
    printVector(vecInt);

    vecInt.push_back(5);
    printVector(vecInt);

    cout<<endl;
    std::vector<int>::iterator it=vecInt.begin();
    for(;it!=vecInt.end();++it)
    {
        cout<<*it<<endl;
    }

    cout<<endl;
    for(int i=0;i<vecInt.size();++i)
    {
        cout<<vecInt[i]<<endl;
    }

    //C++11
    cout<<endl;
    for(auto elem:vecInt)
    {
        cout<<elem<<endl;
    }

    return 0;
}
