#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::ostream;
using std::fstream;
using std::string;

int main()
{
    ifstream ifs("io1.cc");
    if(!ifs.good())
    {
        cout<<"ifstream open error"<<endl;
        return -1;
    }

    string s;
#if 0
    //逐单词打印
    while(ifs>>s)
    {
        cout<<s<<endl;
    }
#endif

    //逐行打印
    while(getline(ifs,s))
    {
        cout<<s<<endl;
    }

    cout<<"execute"<<endl;
    return 0;
}
