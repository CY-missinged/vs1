#include<stdio.h>
#include<string.h>
int main()
{
    char a[25];
    int l=0;
    gets(a);
    l=strlen(a);
    if(a[l-1]=='t') printf("ist");
    else printf("er");
    return 0;
}