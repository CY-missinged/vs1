#include<stdio.h>
float pn(float x,int n);
int main()
{
    float x,a;
    int n;
    scanf("%f %d",&x,&n);
    a=pn(x,n);
    printf("%.4f",a);
    return 0;
}
float pn(float x,int n)
{
    float a;
    if(n==0) a=1;
    if(n==1) a=x;
    if(n>1) a=((2*n-1)*x-pn(x,n-1)-(n-1)*pn(x,n-2))/n*1.0;
    //应为x*pn(x,n-1)
    return a;
}