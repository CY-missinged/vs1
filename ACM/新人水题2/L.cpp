#include<stdio.h>
int main()
{
    int n,a[30][30],i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            a[i][i]=1;
            a[i][0]=1;
        }
        for(i=0;i<n;i++)
            for(j=1;j<i;j++)
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
                if(i!=j) printf("%d ",a[i][j]);
                else printf("%d",a[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}