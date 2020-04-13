#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test0()
{
    char str1[]="hello,world";
    char str2[100]="shenzhen";
    const char *str3="wangdao";     //c风格字符串类型

    cout<<sizeof(str1)<<endl;
    //strcat(str1,str2);
    cout<<"str1="<<str1<<endl;

    //字符串拼接
    int len=strlen(str1)+strlen(str2)+1;
    char *pstr=(char*)malloc(len);
    strcpy(pstr,str1);
    strcat(pstr,str2);
    cout<<"pstr="<<pstr<<endl;

    free(pstr);
}

void test1()
{
    string s1="hello,world";    //c++风格字符串
    string s2="shenzhen";
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;

    //字符串拼接
    string s3=s1+s2;
    cout<<"s3="<<s3<<endl;

    string s4=s1+"shenzhen";
    cout<<"s4="<<s4<<endl;

    string s5="hello,world"+s2;
    cout<<"s5="<<s5<<endl;

    string s6=s1+'A';
    cout<<"s6="<<s6<<endl;

    cout<<endl;

    s1.append(s2);
    cout<<"s1="<<s1<<endl;
}

int main()
{
    test0();
    cout<<endl;
    test1();

    return 0;
}
