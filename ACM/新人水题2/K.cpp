#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    char a[10000];
    scanf("%d\n",&n);
    while(n--)
    {
        j=i=0;
        gets(a);
        for(i=0;i<strlen(a);i++)
        if((int)a[i]<0) j++;
        printf("%d\n",j/2);
    }
    return 0;
}