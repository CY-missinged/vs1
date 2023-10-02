#include<stdio.h>
int fib(int x);
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    m=fib(i);
    printf("%d ",m);
    }
    return 0;
}
int fib(int x)
{
    int a;
    if(x>=3) a=fib(x-1)+fib(x-2);
    else a=1;
    return a;
}