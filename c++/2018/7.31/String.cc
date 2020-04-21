#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1="hello";
    string s2="world";
    string s3=s1+s2;    //string类重载了+
    cout<<s3<<endl;

    return 0;
}
