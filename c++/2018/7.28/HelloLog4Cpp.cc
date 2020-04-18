#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
using namespace std;

int main(int argc, char* argv[])
{
    //创建一个Appender，指定包含的Layout
    log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
    osAppender->setLayout(new log4cpp::BasicLayout());

    //从系统中得到Category的根，将Appender添加到Category中，设置Category的优先级
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.addAppender(osAppender);
    root.setPriority(log4cpp::Priority::DEBUG);

    //记录日志
    root.error("Hello log4cpp in a Error Message!");
    root.warn("Hello log4cpp in a Warning Message!");

    //关闭Category
    log4cpp::Category::shutdown();
    return 0;
}
