#include <func.h>

int main()
{
    pid_t pid;
    pid=fork();
    
    if(0==pid)
    {
        printf("I am child\n");
        //sleep(10);
        char *p=NULL;
        *p=10;
        return 0;
    }
    else
    {
        printf("I am parent\n");

        int status;
        pid_t childpid;
        childpid=wait(&status);
        if(childpid>0)
        {
            //判断子进程是否正常结束
            if(WIFEXITED(status))
            {
                printf("normal,exit code=%d\n",WEXITSTATUS(status));
            }
            else
            {
                printf("unormal\n");
            }
        }

        return 0;
    }

    return 0;
}

