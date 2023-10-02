#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char a[100],b[100];
    gets(a);
    for(i=strlen(a)-1,j=0;i>=0;i--,j++)
    {
        b[i]=a[j];
    }
    puts(b);
    return 0;
}