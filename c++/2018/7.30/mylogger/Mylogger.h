#ifndef _MYLOGGER_H__
#define _MYLOGGER_H__

#include <log4cpp/Category.hh>
#include <string>

using std::string;

class Mylogger
{
public:
    static Mylogger * getInstance();
    static void destroy();

    void warn(const char *msg);
    void error(const char *msg);
    void info(const char *msg);
    void debug(const char *msg);

private:
    Mylogger();
    ~Mylogger();

    static Mylogger * _pInstance;
    log4cpp::Category &_category;
};

#define prefix(msg) string("[")\
        .append(__FILE__).append(":")\
        .append(__FUNCTION__).append(":")\
        .append(std::to_string(__LINE__))\
        .append("]")\
        .append(msg).c_str()

#define LogWarn(msg) Mylogger::getInstance()->warn(prefix(msg));
#define LogError(msg) Mylogger::getInstance()->error(prefix(msg));
#define LogInfo(msg) Mylogger::getInstance()->info(prefix(msg));
#define LogDebug(msg) Mylogger::getInstance()->debug(prefix(msg));

#endif
