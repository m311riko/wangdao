#include "student.h"

Student::Student(int id,const char *name,int course_id,double course_score)
:_id(id)
,_course_id(course_id)
,_course_score(course_score)
{
	cout<<"Student(int,char*,int,double)"<<endl;
	int len=strlen(name);
	_name=new char[len+1];
	strcpy(_name,name);
}

Student::~Student()
{
	cout<<"~Student()"<<endl;
	delete []_name;
}

void Student::print1()
{
	cout<<"print1:"<<endl;
	cout<<"id:"<<_id<<" name:"<<_name<<" course_id:"<<_course_id<<" course_score:"<<_course_score<<endl;
}

#if 0
//不能调用类的成员变量
void print2()
{
	cout<<"print2"<<endl;
	cout<<"course_score:"<<_course_score<<endl;
}
#endif

int main()
{
	Student s1(1000,"wang",0001,100);
	s1.print1();

	//print2();

	return 0;
}
