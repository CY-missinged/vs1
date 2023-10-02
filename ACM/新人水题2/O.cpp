#include<stdio.h>
int sum(int a);
int main()
{
    int n,a,i,b[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        b[i]=sum(a);
    }
    for(i=0;i<n;i++)
    printf("%d\n",b[i]);
    return 0;
}
int sum(int a)
{
    int x=3,i;
    for(i=1;i<=a;i++)
    x=(x-1)*2;
    return x;
}