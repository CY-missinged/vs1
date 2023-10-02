//32整数用double或long long int
#include<stdio.h>
int zxgbs(int x,int y);
int main()
{
    int i;
    long long int n,a[100000],x,y;
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        x=a[0];
        for(i=1;i<n;i++)
        {
            x=x*a[i]/zxgbs(x,a[i]);
        }
        printf("%lld\n",x);
    }
    return 0;
}
int zxgbs(int x,int y)
{ int r;
    do
    {
    r=x%y;
    x=y;
    y=r;
    }while(r!=0);
    return x;
}