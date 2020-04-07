#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
public:
	String();
	String(const char *pstr);
	String(const String &rhs);
	String & operator=(const String &rhs);
	~String();

	void print();

private:
	char *pStr_;
};

String::String()
{
	cout<<"String()"<<endl;
	int len=strlen("\0");
	pStr_=new char[len];
	strcpy(pStr_,"\0");
}

String::String(const char *pstr)
{
	cout<<"String(char*)"<<endl;
	int len=strlen(pstr);
	pStr_=new char[len+1];
	strcpy(pStr_,pstr);
}

String::String(const String &rhs)
{
	cout<<"String(String&)"<<endl;
	int len=strlen(rhs.pStr_);
	pStr_=new char[len+1];
	strcpy(pStr_,rhs.pStr_);
}

String & String::operator=(const String &rhs)
{
	if(this==&rhs)
	{
		return *this;
	}
	
	delete []pStr_;
	cout<<"operator=(String&)"<<endl;
	int len=strlen(rhs.pStr_);
	pStr_=new char[len+1];
	strcpy(pStr_,rhs.pStr_);

	return *this;
}

void String::print()
{
	cout<<"char: "<<pStr_<<endl;
}

String::~String()
{
	delete []pStr_;
}

int main()
{
	String str1;
	str1.print();

	String str2="Hello,world";
	str2.print();

	String str3="wangdao";
	str3.print();

	str2=str3;
	str2.print();

	String str4=str3;
	str4.print();

	return 0;
}
