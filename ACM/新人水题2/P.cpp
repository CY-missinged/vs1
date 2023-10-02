#include<stdio.h>
#include<string.h>
int main()
{
    char a[32],b[32]={1};
    int i,j;
    while(1)
    {
        for(i=1;a[i]>=48&&a[i]<=57;i++)
        {
            scanf("%d",&a[i]);
        }
        if(strcmp(a,b)==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}