#include "Mylogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int test0()
{
    cout<<__FUNCTION__<<endl;
    cout<<__FILE__<<endl;
    cout<<__LINE__<<endl;

    return 0;
}

void test1()
{
    Mylogger::getInstance()->warn("this is warn message");
    Mylogger::getInstance()->error("this is error message");
    Mylogger::getInstance()->info("this is info message");
    Mylogger::getInstance()->debug("this is debug message");
}

void test2()
{
    Mylogger::getInstance()->warn(prefix("this is warn message"));
    Mylogger::getInstance()->error(prefix("this is error message"));
    Mylogger::getInstance()->info(prefix("this is info message"));
    Mylogger::getInstance()->debug(prefix("this is debug message"));
}

void test3()
{
    LogWarn("this is warn message");
    LogError("this is error message");
    LogInfo("this is info message");
    LogDebug("this is debug message");
}

int main()
{
    test0();
    cout<<endl;
    test1();
    cout<<endl;
    test2();
    cout<<endl;
    test3();

    return 0;
}
