#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

vector<string> file;

void test0()
{
    ifstream ifs("io2.cc"); //文件输入流要求打开的文件必须存在
    if(!ifs)
    {
        cout<<"ifstream open error!"<<endl;
        return;
    }

    string line;
    //while(ifs>>line)  以空格为分隔符输入内容
    while(std::getline(ifs,line))   //从输入流获得一行数据
    {
        file.push_back(line);
    }

    for(auto &line:file)
    {
        cout<<line<<"\n";
    }

    ifs.close();
}

void test1()
{
    test0();
    string filename="test.txt";

    //如果文件不存在，就创建一个；
    //如果文件已经存在，就清空文件内容，再重新写入。
    ofstream ofs(filename);
    if(!ofs.good())
    {
        cout<<"ofstream open error"<<endl;
        return;
    }

    for(auto &line:file)
    {
        ofs<<line<<"\n";
    }

    ofs.close();
}

void test2()
{
    string filename="test.txt";

    ofstream ofs(filename,std::ios::app);   //在文件末尾添加新的内容
    if(!ofs.good())
    {
        cout<<"ofstream open error"<<endl;
        return;
    }

    cout<<"pos="<<ofs.tellp()<<endl;

    string line="this is a new line";
    ofs<<line;

    ofs.close();
}

void test3()
{
    fstream fs;
    fs.open("test2.txt");
    if(!fs)
    {
        cout<<"fstream open error"<<endl;
        return;
    }

    int number;
    for(int idx=0;idx!=5;++idx)
    {
        cin>>number;
        fs<<number<<" ";
    }

    cout<<"pos="<<fs.tellp()<<endl;
    fs.seekg(std::ios::beg);

    for(int idx=0;idx!=5;++idx)
    {
        fs>>number;
        cout<<"number: "<<number<<endl;
    }

    fs.close();
}

void test4()
{
    ifstream ifs("test2.txt",std::ios::ate);
    if(!ifs)
    {
        cout<<"ifstream open error"<<endl;
        return;
    }

    //一次性拿到一个文件全部信息
    size_t len=ifs.tellg();
    cout<<"len="<<len<<endl;
    ifs.seekg(std::ios::beg);

    char buf[len+1];
    memset(buf,0,len+1);
    ifs.read(buf,len+1);    //使用read方法读取一个文件所有内容

    string s(buf);
    cout<<buf<<endl;

    ifs.close();
}

int main()
{
    //test0();
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}
