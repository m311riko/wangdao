#include <stdio.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//没有使用写时复制，
//使用深拷贝

int main()
{
    string s1="hello,world";
    string s2=s1;
    string s3=s2;

    cout<<"sizeof(string)="<<sizeof(string)<<endl;
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    printf("s1'address=%p\n",s1.c_str());
    printf("s2'address=%p\n",s2.c_str());
    printf("s3'address=%p\n",s3.c_str());

    cout<<endl;
    cout<<"执行修改操作："<<endl;
    s1[0]='X';
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
    cout<<"s3="<<s3<<endl;
    printf("s1'address=%p\n",s1.c_str());
    printf("s2'address=%p\n",s2.c_str());
    printf("s3'address=%p\n",s3.c_str());

    return 0;
}
