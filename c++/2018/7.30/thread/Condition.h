#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__

#include <pthread.h>

namespace wd
{
class MutexLock;    //类的前向声明
class Condition
{
public:
    Condition(MutexLock & mutex);
    ~Condition();
    Condition(const Condition &rhs) = delete;
    Condition & operator=(const Condition &rhs) = delete;

    void wait();
    void notify();
    void notifyall();

private:
    pthread_cond_t _cond;
    MutexLock & _mutex;     //关联关系
};
}
#endif
