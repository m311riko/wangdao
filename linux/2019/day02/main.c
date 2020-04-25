#include <stdio.h>

int main(int argc,char *argv[])
{
    char str[50]={0};
    scanf("%s",str);
    printf("%s\n",str);
    fprintf(stderr,"%s\n",str);

    return 0;
}
