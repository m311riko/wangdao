#include <string>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

//打印流的状态
void printCin()
{
    cout<<"bad="<<cin.bad()<<endl;
    cout<<"fail="<<cin.fail()<<endl;
    cout<<"eof="<<cin.eof()<<endl;
    cout<<"good="<<cin.good()<<endl;
}

int test0()
{
    printCin();

    int inum;
    while(cin>>inum)
    {
        cout<<inum<<endl;
    }
    printCin();

    cin.clear();
    cout<<"重置流的状态"<<endl;
    printCin();

    //从输入流舍弃字符，直到遇到\n
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::string s;
    cin>>s;
    cout<<s<<endl;

    return 0;
}

int main()
{
    int ival;
    while(cin>>ival,!cin.eof())
    {
        if(cin.bad())
        {
            cout<<"IO stream corrupted!"<<endl;
            return -1;
        }
        else if(cin.fail())
        {
            cout<<"data illegal,please try again!"<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        cout<<"ival="<<ival<<endl;
    }

    return 0;
}
