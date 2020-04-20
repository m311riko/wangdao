#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
    string word;
    int freq;

    bool operator<(const Record &rhs) const
    {
        return freq>rhs.freq;
    }
};

class Dictionary
{
public:
    Dictionary()
    {
        _dict.reserve(10000);
    }

    void read(const string &filename);
    void store(const string &filename);

private:
    string preprocessWord(string &word);
    void statistic(const string &word);

private:
    vector<Record> _dict;
};

void Dictionary::read(const string &filename)
{
    //文件输入流
    ifstream ifs(filename);
    if(!ifs)
    {
        cout<<"ifstream open error"<<endl;
        return;
    }

    string line;
    while(getline(ifs,line))
    {
        //字符串输入流
        istringstream iss(line);
        string preword;
        while(iss>>preword)
        {
            string word=preprocessWord(preword);
            if(word!=string())
            {
                statistic(word);
            }
        }
    }

    std::sort(_dict.begin(),_dict.end());
}

string Dictionary::preprocessWord(string &word)
{
    for(size_t idx=0;idx!=word.size();++idx)
    {
        if(isdigit(word[idx]))
        {
            return string();    //如果单词中有数字，返回空字符串
        }
        else if(isupper(word[idx]))
        {
            word[idx]=tolower(word[idx]);   //如果单词中有大写字母，转换成小写字母
        }
    }

    return word;
}

void Dictionary::statistic(const string &word)
{
    size_t idx;
    for(idx=0;idx!=_dict.size();++idx)
    {
        if(word==_dict[idx].word)
        {
            ++_dict[idx].freq;  //在字典中找到
            break;
        }
    }

    if(idx==_dict.size())   //没有在字典中找到
    {
        Record record;
        record.word=word;
        record.freq=1;
        _dict.push_back(record);
    }
}

void Dictionary::store(const string &filename)
{
    //文件输出流
    ofstream ofs(filename);
    if(!ofs)
    {
        cout<<"ofstream open error"<<endl;
        return;
    }

    //输出到文件
    for(auto &record:_dict)
    {
        ofs<<record.word<<"\t"<<record.freq<<"\n";
    }
}

int main()
{
    Dictionary dictionary;
    dictionary.read("The_Holy_Bible.txt");
    dictionary.store("dict.txt");

    return 0;
}
