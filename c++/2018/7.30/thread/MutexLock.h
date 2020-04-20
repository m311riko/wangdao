#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include <pthread.h>

namespace wd
{
class MutexLock
{
public:
    MutexLock();
    ~MutexLock();

    void lock();
    void unlock();

    //Condition与MutexLock是关联关系
    pthread_mutex_t * getMutexLockPtr()
    {
        return &_mutex;
    }

    //c++11，禁止复制
    MutexLock(const MutexLock &rhs) = delete;
    MutexLock & operator=(const MutexLock &rhs) = delete;

private:
    //c++11以前，禁止复制
    //MutexLock(const MutexLock &rhs);
    //MutexLock & operator=(const MutexLock &rhs);
    pthread_mutex_t _mutex;
};

//防止死锁的类
class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex)
    :_mutex(mutex)
    {
        _mutex.lock();
    }

    ~MutexLockGuard()
    {
        _mutex.unlock();
    }

private:
    MutexLock &_mutex;
};
}

#endif
