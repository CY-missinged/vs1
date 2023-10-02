#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,l,d[100];
    j=k=l=i=0;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
        char a[200],b[100];
        gets(a);
        k=strlen(a);
        for(l=0,j=k-1;j>=0;j--,l++)
        {
            b[l]=a[j];
        }
        puts(b);
        if(strcmp(a,b)==0) d[i]=1;
        else d[i]=0;
        strcpy(b,"");
        puts(b);
    }
    for(i=1;i<=n;i++)
    {
        if(d[i]==1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}