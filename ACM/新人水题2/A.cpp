#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,k,l,a[105];
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(j=1;j<=n-1;j++)
        {
            for(k=0;k<n-1;k++)
                if(fabs(a[k])<fabs(a[k+1]))
                {
                    a[k]=a[k]+a[k+1];
                    a[k+1]=a[k]-a[k+1];
                    a[k]=a[k]-a[k+1];
                    l++;
                }
            if(l==0) break;
        }
        for(j=0;j<n;j++)
        {
            if(j==0) printf("%d",a[j]);
            else printf(" %d",a[j]);
        }
        printf("\n");
    }
    return 0;
}