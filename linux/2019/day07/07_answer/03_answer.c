#include <func.h>

int main()
{
    int ret=execl("./add","add","3","4",NULL);
    ERROR_CHECK(ret,-1,"execl");

    return 0;
}

