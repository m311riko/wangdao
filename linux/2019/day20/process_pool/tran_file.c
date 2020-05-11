#include "process_pool.h"

int tranFile(int newFd)
{
    train_t train;
    train.dataLen=strlen(FILENAME);
    strcpy(train.buf,FILENAME);

    //第一次发车
    send(newFd,&train,4+train.dataLen,0);

    //第二次发车
    int fd=open(FILENAME,O_RDWR);
    while((train.dataLen=read(fd,train.buf,sizeof(train.buf))))
    {
        send(newFd,&train,4+train.dataLen,0);
    }

    //最后一次发车
    send(newFd,&train,4+train.dataLen,0);

    return 0;
}

