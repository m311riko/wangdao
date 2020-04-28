#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define ARGS_CHECK(argc,num)\
{\
    if(argc!=num)\
    {\
        printf("error args!\n");\
        return -1;\
    }\
}

#define RET_CHECK(ret,num,msg)\
{\
    if(ret==num)\
    {\
        perror(msg);\
        return -1;\
    }\
}
