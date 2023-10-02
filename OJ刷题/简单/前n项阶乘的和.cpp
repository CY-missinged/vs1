#include<stdio.h>
long fac(int a);
int main()
{
   int i,m,sum;
   sum=0;
   scanf("%d",&m);
   for(i=1;i<=m;i++)
   sum=sum+fac(i);
   printf("sum=%d",sum);
   return 0;
}
long  fac(int a)
{
   int i;
   int x=1;
   for(i=1;i<=a;i++)
   x=x*i;
   return (x);
}