#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

class MutexLock
{
public:
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();

private:
    pthread_mutex_t mutex;
};

MutexLock::MutexLock()
{
    pthread_mutex_init(&mutex,NULL);
}

MutexLock::~MutexLock()
{
    pthread_mutex_destroy(&mutex);
}

void MutexLock::lock()
{
    pthread_mutex_lock(&mutex);
}

void MutexLock::unlock()
{
    pthread_mutex_unlock(&mutex);
}

int main()
{
    MutexLock mutex;    //初始化锁

    mutex.lock();   //加锁
    cout<<"hello world"<<endl;
    mutex.unlock(); //解锁

    //自动调用构造函数销毁锁

    return 0;
}
