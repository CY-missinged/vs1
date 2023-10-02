#include<stdio.h>
#include<string.h>
int main()
{
    int i,j;
    char a[10][10],b[1][10];
    for(i=0;i<10;i++)
    {
            scanf("%s",a[i]);
    }
    for(i=0;i<9;i++)
    {
        if(strcmp(a[i],a[i+1])>0) j=i;
    }
    printf("%s",a[j]);
    return 0;
}