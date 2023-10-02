#include<stdio.h>
int main()
{
    int m,n,a[1000],b[1000],i,j,k,t;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<m+n;i++)
    {
        for(j=0;j<n;j++)
        
            if(a[i]<b[j]&&b[j]<=a[i+1]) 
            {
                for(k=m+n-1;k>i+1;k--)
                {
                    a[k]=a[k-1];
                }
                a[i+1]=b[j];
            }
    }
    for(i=0;i<m+n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}