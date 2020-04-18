#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using namespace std;

class Mylogger
{
public:
    static Mylogger* getInstance()
    {
        if(NULL==_pInstance)
        {
            _pInstance=new Mylogger();
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }

    void warn(const char* msg)
    {
        _category.warn(msg);
        _category.warn("可变参数 %d %d %s\n",10,11,"hello,world");
    }

    void error(const char* msg)
    {
        _category.error(msg);
    }

    void debug(const char* msg)
    {
        _category.info(msg);
    }

    void info(const char* msg)
    {
        _category.debug(msg);
    }

private:
    Mylogger()
    :_category(log4cpp::Category::getRoot())
    {
        using namespace log4cpp;

        cout<<"Mylogger()"<<endl;

        PatternLayout *ptnLayout1=new PatternLayout();
        ptnLayout1->setConversionPattern("%d [%p] %m%n");

        PatternLayout *ptnLayout2=new PatternLayout();
        ptnLayout2->setConversionPattern("%d [%p] %m%n");

        OstreamAppender *pOstreamAppender=new OstreamAppender("pOstreamAppender",&cout);
        pOstreamAppender->setLayout(ptnLayout1);

        FileAppender *pFileAppender=new FileAppender("pFileAppender","wangdao.log");
        pFileAppender->setLayout(ptnLayout2);

        _category.addAppender(pOstreamAppender);
        _category.addAppender(pFileAppender);
        _category.setPriority(Priority::DEBUG);
    }

    ~Mylogger()
    {
        cout<<"~Mylogger()"<<endl;
        log4cpp::Category::shutdown();
    }

    static Mylogger *_pInstance;
    log4cpp::Category& _category;
};

int main()
{
    Mylogger* log=Mylogger::getInstance();
    log->warn("hello warn");
    log->error("hello error");
    log->info("hello info");
    log->debug("hello debug");

    cout<<"hello,world"<<endl;

    return 0;
}
