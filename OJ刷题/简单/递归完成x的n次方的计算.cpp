#include<stdio.h>
double xdncf(int x,int n);
int main()
{
    int x,n;
    double m;
    scanf("%d %d",&x,&n);
    m=xdncf(x,n);
    printf("%.0lf",m);
    return 0;
}
double xdncf(int x,int n)
{
    if(n==1) return x;
    double a;
    a=1;
    a=a*xdncf(x,n-1)*x;
    return a;
}