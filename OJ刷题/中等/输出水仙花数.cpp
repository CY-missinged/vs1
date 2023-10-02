#include<stdio.h>
void abc(int x);
int main()
{
    int m,n,i,x,y,z,a;
    scanf("%d %d",&m,&n);
        for(i=m;i<=n;i++)
        {
            abc(i);
        }
    return 0;
}
void abc(int i)
{
    int x,y,z,a;
    x=i%10;
    y=(i%100)/10;
    z=i/100;
    a=x*x*x+y*y*y+z*z*z;
    if(i==a) printf("%d ",i);
}