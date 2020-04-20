#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

//系统资源禁止复制
wd::MutexLock gMutex;
wd::Condition gCondition(gMutex);

int gFlag=true;
int gCounter=0;

void *threadFunc1(void *arg)
{
    int count=10;
    while(count--)
    {
        //gMutex.lock();  //可能产生死锁
        wd::MutexLockGuard autolock(gMutex);    //防止死锁

        //gFlag为false就阻塞
        while(gFlag==false)
        {
            gCondition.wait();  //阻塞，使用while防止wait被异常唤醒
        }

        //gFlag为true就++
        gCounter++;
        cout<<"threadFunc1: gCounter="<<gCounter<<endl;
        sleep(1);
        if(gFlag)
        {
            gFlag=false;
        }

        gCondition.notify();
    }

    return NULL;
}

void *threadFunc2(void *arg)
{
    int count=10;
    while(count--)
    {
        wd::MutexLockGuard autolock(gMutex);

        while(gFlag)
        {
            gCondition.wait();
        }

        gCounter++;
        cout<<"threadFunc2: gCounter="<<gCounter<<endl;
        sleep(1);
        if(gFlag==false)
        {
            gFlag=true;
        }

        gCondition.notify();
    }

    return NULL;
}

int main()
{
    pthread_t pth1,pth2;

    pthread_create(&pth1,NULL,threadFunc1,NULL);
    pthread_create(&pth2,NULL,threadFunc2,NULL);

    pthread_join(pth1,NULL);
    pthread_join(pth2,NULL);

    return 0;
}
