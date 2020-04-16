#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printCin()
{
    cout<<"cin' badbit: "<<cin.bad()<<endl;
    cout<<"cin' failbit: "<<cin.fail()<<endl;
    cout<<"cin' eofbit: "<<cin.eof()<<endl;
    cout<<"cin' goodbit: "<<cin.good()<<endl;
}

int test0()
{
    cout<<"sizeof(cout): "<<sizeof(cout)<<endl;
    cout<<"sizeof(cin): "<<sizeof(cin)<<endl;

    printCin();
    int number;
    while(cin>>number)
    {
        cout<<"number: "<<number<<endl;
    }
    printCin();

    cout<<endl;
    cout<<"重置流的状态："<<endl;
    cin.clear();    //重置流的状态
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');   //清空缓冲区
    printCin();

    string s;
    cin>>s;
    cout<<"s: "<<s<<endl;

    return 0;
}

void test1()
{
    int number;
    cout<<"please input an interger: ";
    while(cin>>number,!cin.eof())
    {
        if(cin.bad())
        {
            cout<<"bad!"<<endl;
            return;
        }
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"please input an interger: ";
            continue;
        }
        cout<<"number: "<<number<<endl;
    }

    printCin();
    cout<<"end"<<endl;
}

int main()
{
    //test0();
    test1();

    return 0;
}
