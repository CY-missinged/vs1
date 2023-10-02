#include<stdio.h>
long long int zh(long long int a,long long int n);
int main()
{
    long long int x,y,N;
    while(scanf("%lld%lld%lld",&N,&x,&y)!=EOF)
    {
        x=zh(x,N);
        y=zh(y,N);
        printf("%lld\n",x*y);
    }
    return 0;
}
long long int zh(long long int a,long long int n)
{
    long long int sum=0,t=1;
    while(1)
        {
            sum=sum+(a%10)*t;
            a=a/10;
            t=n*t;
            if(a==0) break;
        }
    return sum;
}