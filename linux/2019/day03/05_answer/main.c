#include <stdio.h>

int main()
{
    int i;
    i=1;
    i=2;

    for(int j=0;j<8;++j)
    {
        ++i;
    }
    printf("i=%d\n",i);

    return 0;
}
