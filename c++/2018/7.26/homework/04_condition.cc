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
    cout<<"MutexLock()"<<endl;
    pthread_mutex_init(&mutex,NULL);
}

MutexLock::~MutexLock()
{
    cout<<"~MutexLock()"<<endl;
    pthread_mutex_destroy(&mutex);
}

void MutexLock::lock()
{
    cout<<"lock()"<<endl;
    pthread_mutex_lock(&mutex);
}

void MutexLock::unlock()
{
    cout<<"unlock()"<<endl;
    pthread_mutex_unlock(&mutex);
}

class Condition
{
public:
    Condition();
    ~Condition();
    void wait();
    void notify();
    void notifyall();

private:
    pthread_cond_t cond;
    pthread_mutex_t mutex;
};

Condition::Condition()
{
    cout<<"Condition()"<<endl;
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
}

Condition::~Condition()
{
    cout<<"~Condition()"<<endl;
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
}

void Condition::wait()
{
    cout<<"wait()"<<endl;
    pthread_cond_wait(&cond,&mutex);
}

void Condition::notify()
{
    cout<<"notify()"<<endl;
    pthread_cond_signal(&cond);
}

void Condition::notifyall()
{
    cout<<"notifyall()"<<endl;
    pthread_cond_broadcast(&cond);
}

int main()
{
    Condition cond;
    cond.wait();
    cond.notify();
    cond.notifyall();

    return 0;
}
