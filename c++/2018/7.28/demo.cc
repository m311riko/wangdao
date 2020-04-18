#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
int main(int argc, char* argv[]) {
    // 1 ��ȡ���������ļ�
    // ��ȡ����, ��ȫ���Ժ��ԣ����Զ���һ��ȱʡ���Ի���ʹ��ϵͳȱʡ����
    // BasicLayout����������ȼ���־��ConsoleAppender
    try
    {
        log4cpp::PropertyConfigurator::configure("./log4cpp.conf");
    }
    catch (log4cpp::ConfigureFailure& f)
    {
        std::cout << "Configure Problem " << f.what() << std::endl;
        return -1;
    }

    //2    ʵ����category����
    //    ��Щ����ʹ�����ļ�û�ж���Ҳ����ʹ�ã����������Լ̳��丸category
    //    ͨ��ʹ�����ÿ��ܲ�̫���㣬����ʹ��ָ�룬�Ժ���ָ��ʹ��
    log4cpp::Category& root = log4cpp::Category::getRoot();
    log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
    log4cpp::Category& sub2 = log4cpp::Category::getInstance(std::string("sub2"));
    log4cpp::Category& sub3 = log4cpp::Category::getInstance(std::string("sub3"));
    log4cpp::Category& sub4 = log4cpp::Category::getInstance(std::string("sub4"));

    //    ����ʹ����Щcategory���������־����
    root.fatal("root's log");

    //    sub1 has appender A1 and rootappender. since the additivity property is set true by default
    sub1.info("sub1's log");

    //    sub2 has appender A2 appender. since the additivity property is set to false
    sub2.alert("sub2's log");

    //    sub3 only has A3 appender. since the additivity property is set to false
    sub3.debug("sub3's log");
    sub3.alert("sub3's log");

    //    sub4 can not be found in the config file, so the root category's appender and layout are used
    sub4.warn("sub4's log");

    return 0;
}