#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;

int main(int argc,char* argv[])
{
    //创建一个Appender
    log4cpp::OstreamAppender* osAppender=new log4cpp::OstreamAppender("osAppender",&cout);

    //指定包含的Layout
    osAppender->setLayout(new log4cpp::BasicLayout());

    //从系统中得到Category的根
    log4cpp::Category& root=log4cpp::Category::getRoot();

    //将Appender添加到Category中
    root.addAppender(osAppender);

    //设置Category优先级
    root.setPriority(log4cpp::Priority::DEBUG);

    //记录日志
    root.error("hello error message");
    root.warn("hello warn message");

    //关闭Category
    log4cpp::Category::shutdown();

    return 0;
}
