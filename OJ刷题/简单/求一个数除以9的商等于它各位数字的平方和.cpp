#include<stdio.h>
int main()
{
    int n,m,i,s,x,y,z;
    if(n>m) {n=n+m;m=n-m;n=n-m;}
    scanf("%d %d",&n,&m);
    for(i=n;i<=m;i++) 
    {
        s=i/9;
        x=i%10;
        y=i%100/10;
        z=i/100;
        if(s==x*x+y*y+z*z) printf("%d\n",i);
    } 
    return 0;
}