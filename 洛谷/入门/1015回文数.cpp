// ON
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k;
    char a[105],b[105],c[105];
    scanf("%d",&n);
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]<'A') a[i]=a[i]-46;
        else a[i]=a[i]-54;
    }
    if(i<=30) printf("STEP=%d",i);
    else printf("Impossible!");
    return 0;
}