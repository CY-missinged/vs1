#include<stdio.h>
int main()
{
    long long int nn,a[10005],b,sum;
    long long int x,m,n,i;
    while(scanf("%lld",&nn)!=EOF)
    {
        x=0;
        for(i=0;i<nn;i++)
        {
            scanf("%lld",&a[i]);
            x=x+a[i];
        }
        scanf("%lld",&b);
        i=0;
        m=b%x;
        n=(b/x)*nn;
        if(m==0) n=n+1;
        else for(i=0;i<nn;i++)
            {
                m=m-a[i];
                if(m<0)
                {
                    i++;
                    break;
                }
            }
        n=n+i;
        printf("%lld\n",n);
    }
    return 0;
}