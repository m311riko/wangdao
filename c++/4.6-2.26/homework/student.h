#include <stdio.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
	Student(int id,const char *name,int course_id,double course_score);
	void print1();
	~Student();

private:
	int _id;
	char *_name;
protected:
	int _course_id;
public:
	double _course_score;
};

//不能调用类的成员变量
//void print2();
