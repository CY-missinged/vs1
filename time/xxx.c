#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>

int main()
{
    char a[20];
    int i;
    char *b=(char*)malloc(30*sizeof(char));
    for (i = 0; i < 2; i++)
    {
        printf("%s", "mysql > ");
        read(0, a, 10);
    }
    free(b);
    *b=0;
    return 0;
}