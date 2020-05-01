#include <func.h>

#if 0
1.fork()以后，子进程继承父进程的进程地址空间，继承的空间中包括栈空
  间；
2.继承的栈空间实行写时复制机制，当读取栈空间内容时从同一个物理地址
  读取，当写入栈空间内容时执行写时复制；
3.写时复制：
  （1）申请空间；
  （2）内容拷贝；
  （3）映射地址；
  （4）更改内容；
#endif

int main()
{
    pid_t pid;
    int i=10;
    pid=fork();
    if(0==pid)
    {
        printf("I am child,i is %d,add is %p\n",i,&i);
        return 0;
    }
    else
    {
        printf("I am parent,i is %d,add is %p\n",i,&i);
        i=5;
        printf("I am parent,i is %d,add is %p\n",i,&i);
        return 0;
    }

    return 0;
}

