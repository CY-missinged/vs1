#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int a=123456789;
    char b[100];
    sprintf(b,"%d",a);
    puts(b);
    return 0;
}
