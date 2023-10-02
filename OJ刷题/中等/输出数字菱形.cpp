#include<stdio.h>
int main()
{
    int n,i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++) printf("%d ",j);
        for(j=i-1;j>0;j--) 
        {
            if(j==1) printf("%d",j);
            else printf("%d ",j);
        }
        printf("\n");
    }
    for(i=n-1;i>0;i--)
    {
        for(j=1;j<=i;j++) printf("%d ",j);
        for(j=i-1;j>0;j--) 
        {
            if(i==1) printf("%d",j);
            else printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}