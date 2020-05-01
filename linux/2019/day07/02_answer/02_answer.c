#include <func.h>

int main()
{
    printf("pid=%d,ppid=%d,euid=%d,egid=%d,uid=%d,gid=%d\n",
            getpid(),
            getppid(),
            geteuid(),
            getegid(),
            getuid(),
            getgid()
          );

    return 0;
}

