#include<stdio.h>
int main() 
{
    int n,m,sum,i,j,k,l,a[55][10];
    double b[60],c[60];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<m+n;i++)
        b[i]=c[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                b[i]=b[i]+a[i][j];
                c[j]=c[j]+a[i][j];
            }
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            k=m;
            for(j=0;j<m;j++)
            {
                if(a[i][j]>=c[j]/n) k--; 
            }
            if(k==0) sum++;
        }
        for(i=0;i<n;i++)    
            if(i==0) printf("%.2lf",b[i]/m);
            else printf(" %.2lf",b[i]/m);
        printf("\n");
        for(i=0;i<m;i++)
            if(i==0) printf("%.2lf",c[i]/n);
            else printf(" %.2lf",c[i]/n);
        printf("\n");
        printf("%d\n\n",sum);
    }
    return 0;
}