#include<stdio.h>
float fun(int a);
int main()
{
    int n,i;
    float s;
    s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    s=s+float(1/fun(i));
    printf("%.2f\n",s);
    return 0;
}
float fun(int a)
{
    int i,sum;
    sum=0;
    for(i=1;i<=a;i++)
    sum=sum+i;
    return (sum);
}